/* MCAL initialization only; communication startup belongs to Integration. */
#include "Mcu.h"
#include "Port.h"
#include "Gpt.h"
#include "Gpt_PBcfg.h"
#include "Fr_17_Eray.h"
#include "Fr_17_Eray_PBcfg.h"
#include "Mcal_Compiler.h"
#include "IfxScu_reg.h"
#include "IfxSrc_reg.h"
#include "IfxScuWdt.h"
#include "Irq.h"
#include "AS21_McalInit.h"
void AS21_McalInit_ReissueCcucon0Up(void)
{
    Ifx_SCU_CCUCON0 ccucon0;
    uint16 safetyPwd = IfxScuWdt_getSafetyWatchdogPassword();
    uint32 timeout   = 1500U;

    /* 确认 System PLL 已稳定锁定（根因消失后才允许重配置，UM §10.6 Note） */
    timeout = 150000U;
    while ((SCU_SYSPLLSTAT.B.LOCK == 0U) && (timeout != 0U))
    {
        timeout--;
    }

    /* 等 CCUCON0 可更新（LCK==0） */
    timeout = 1500U;
    while ((SCU_CCUCON0.B.LCK != 0U) && (timeout != 0U))
    {
        timeout--;
    }

    ccucon0.U        = SCU_CCUCON0.U;   /* 当前分频参数（EB 配置值） */
    ccucon0.B.GTMDIV = 1U;              /* UM 要求 GTMDIV 保持 0001B（part2 GTM 章） */
    ccucon0.B.CLKSEL = 1U;              /* fPLL0（按 UM Note 重写 CLKSEL） */
    ccucon0.B.UP     = 1U;              /* 重传参数集，清除紧急状态 */

    /* CCUCON0 受 Safety-ENDINIT 保护：解锁-整字写入-重新上锁 */
    IfxScuWdt_clearSafetyEndinit(safetyPwd);
    SCU_CCUCON0.U = ccucon0.U;
    IfxScuWdt_setSafetyEndinit(safetyPwd);

    /* 等 UP 传输完成（LCK 置位后释放） */
    timeout = 1500U;
    while ((SCU_CCUCON0.B.LCK != 0U) && (timeout != 0U))
    {
        timeout--;
    }
}

void AS21_McalInit_Mcu(void)
{
    volatile Mcu_ClockType ClockID = 0U;
    Std_ReturnType InitClockRetVal;
    Mcu_PllStatusType PllStatus = MCU_PLL_STATUS_UNDEFINED;

    Mcu_Init(&Mcu_Config);

    InitClockRetVal = Mcu_InitClock(ClockID);

    if (InitClockRetVal == E_OK)
    {
        do
        {
            PllStatus = Mcu_GetPllStatus();
        } while (PllStatus != MCU_PLL_LOCKED);

#if (MCU_DISTRIBUTE_PLL_CLOCK_API == STD_ON)
        (void)Mcu_DistributePllClock();
        AS21_McalInit_ReissueCcucon0Up();
#endif
    }
}

void AS21_McalInit_Port(void)
{
    Port_Init(&Port_Config);
}

void AS21_McalInit_Gpt(void)
{
    /* GTM 服务请求节点（SRC）优先级与目标核配置（TOM0 SR0: CPU0, PRIO 0x12） */
    IrqGtm_Init();

    /* 使能 GTM TOM0 通道0 中断（CPU 级，Demo 同款手动置位） */
    SRC_GTMTOM00.B.SRE = 1U;

    /* GPT12 服务请求节点配置（若 EB 启用） */
    IrqGpt_Init();

    /* 初始化 GPT 驱动 */
    Gpt_Init(&Gpt_Config);

    /* Communication supervision uses STM; no GPT channels are started here. */
}

void AS21_McalInit_Fr(void)
{
    Fr_17_Eray_Init(&Fr_17_Eray_Config);
}

void AS21_McalInit(void)
{
    AS21_McalInit_Mcu();
    AS21_McalInit_Port();
    AS21_McalInit_Gpt();
    AS21_McalInit_Fr();
}
