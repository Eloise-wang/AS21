/* Included once by IFX_Os.c, following the existing ADS integration convention. */
#include "AS21_Communication.h"
#include "AS21_ComPlatform.h"
#include "FrIf.h"
#include "PduR.h"
#include "Com.h"
#include "APPS/main/AS21_FlexRayLab.h"
#include "APPS/main/AS21_FlexRayPeer.h"
#include "IfxScuCcu.h"
#include "IfxStm_reg.h"
#include "IfxEray_reg.h"
#include <string.h>

extern void IrqFr_17_Eray_Init(void);
volatile AS21_CommunicationDiagType g_AS21_Communication;
static uint32 AS21_CommTicksPerMs;
static uint32 AS21_CommLastTick;
static uint32 AS21_CommNowMs;
static uint32 AS21_CommStageSinceMs;
static uint8 AS21_CommControllerMask;
static const uint8 AS21_CommStartupData[64] = {0U};

static boolean AS21_CommInputIdle(uint8 ctrl)
{
    if (ctrl == 0U) return ((MODULE_ERAY0.IBCR.B.IBSYH == 0U) &&
                            (MODULE_ERAY0.IBCR.B.IBSYS == 0U));
    return ((MODULE_ERAY1.IBCR.B.IBSYH == 0U) &&
            (MODULE_ERAY1.IBCR.B.IBSYS == 0U));
}

static void AS21_CommOffline(void)
{
    AS21_FlexRayPeer_SetOnline(FALSE, AS21_CommNowMs);
    if ((AS21_CommControllerMask & 1U) != 0U) {
        (void)FrIf_CancelAbsoluteTimer(0U, 0U);
    }
    if (g_AS21_Communication.Online != 0U) {
        AS21_FlexRayLab_SetOnline(FALSE);
        g_AS21_Communication.StateResult = FrIf_SetState(0U, FRIF_GOTO_OFFLINE);
        g_AS21_Communication.Online = 0U;
    }
    /* Drop software TX/confirmations; ControllerInit clears hardware pending
     * requests before a new session is admitted. Keep the Fr driver initialized. */
    FrIf_Init(&FrIf_Config);
}

static void AS21_CommFail(uint8 ctrl)
{
    g_AS21_Communication.LastFailureStage = g_AS21_Communication.Stage;
    g_AS21_Communication.LastFailureController = ctrl;
    g_AS21_Communication.RecoveryCount++;
    AS21_CommOffline();
    g_AS21_Communication.Stage = AS21_COMM_RETRY;
    AS21_CommStageSinceMs = AS21_CommNowMs;
}

static void AS21_CommInitializeControllers(void)
{
    uint8 ctrl;
    Std_ReturnType result;
    for (ctrl = 0U; ctrl < 2U; ctrl++) {
        /* Abort is synchronous. Never reinitialize a previously active
         * controller unless FREEZE succeeded and input transfers are idle. */
        if ((AS21_CommControllerMask & (uint8)(1U << ctrl)) != 0U) {
            result = Fr_17_Eray_AbortCommunication(ctrl);
            g_AS21_Communication.Controller[ctrl].AbortResult = result;
            if ((result != E_OK) || !AS21_CommInputIdle(ctrl)) {
                AS21_CommFail(ctrl);
                return;
            }
        }
    }
    for (ctrl = 0U; ctrl < 2U; ctrl++) {
        g_AS21_Communication.ControllerInitCount++;
        result = (ctrl == 0U) ? FrIf_ControllerInit(0U) : Fr_17_Eray_ControllerInit(1U);
        g_AS21_Communication.Controller[ctrl].InitResult = result;
        if (ctrl == 0U) g_AS21_Communication.ControllerInitResult = result;
        if (result != E_OK) { AS21_CommFail(ctrl); return; }
        AS21_CommControllerMask |= (uint8)(1U << ctrl);
    }
    IrqFr_17_Eray_Init();
    for (ctrl = 0U; ctrl < 2U; ctrl++) {
        Fr_POCStatusType poc;
        result = (ctrl == 0U) ? FrIf_GetPOCStatus(0U, &poc) :
                                Fr_17_Eray_GetPOCStatus(1U, &poc);
        g_AS21_Communication.Controller[ctrl].PocResult = result;
        if ((result != E_OK) || (poc.State != FR_POCSTATE_READY) ||
            !AS21_CommInputIdle(ctrl)) { AS21_CommFail(ctrl); return; }
        g_AS21_Communication.Controller[ctrl].PocState = (uint8)poc.State;
        result = Fr_17_Eray_TransmitTxLPdu(ctrl, 0U, AS21_CommStartupData, 64U);
        g_AS21_Communication.Controller[ctrl].PrimeResult = result;
        if (result != E_OK) { AS21_CommFail(ctrl); return; }
    }
    g_AS21_Communication.Stage = AS21_COMM_PRIMING;
    AS21_CommStageSinceMs = AS21_CommNowMs;
}

void AS21_Communication_Init(void)
{
    uint8 ctrl;
    memset((void *)&g_AS21_Communication, 0, sizeof(AS21_CommunicationDiagType));
    g_AS21_Communication.ControllerInitResult = E_NOT_OK;
    g_AS21_Communication.StartResult = E_NOT_OK;
    g_AS21_Communication.PocResult = E_NOT_OK;
    g_AS21_Communication.StateResult = E_NOT_OK;
    for (ctrl = 0U; ctrl < 2U; ctrl++) {
        g_AS21_Communication.Controller[ctrl].InitResult = E_NOT_OK;
        g_AS21_Communication.Controller[ctrl].PrimeResult = E_NOT_OK;
        g_AS21_Communication.Controller[ctrl].ColdstartResult = E_NOT_OK;
        g_AS21_Communication.Controller[ctrl].StartResult = E_NOT_OK;
        g_AS21_Communication.Controller[ctrl].PocResult = E_NOT_OK;
        g_AS21_Communication.Controller[ctrl].AbortResult = E_NOT_OK;
    }
    AS21_CommControllerMask = 0U;
    AS21_CommNowMs = 0U;
    AS21_CommStageSinceMs = 0U;
    AS21_CommTicksPerMs = (uint32)(IfxScuCcu_getStmFrequency() / 1000.0F);
    AS21_CommLastTick = MODULE_STM0.TIM0.U;
    if (AS21_CommTicksPerMs == 0U) return;
    PduR_Init(&AS21_PduR_Config);
    Com_Init(&AS21_Com_Config);
    if ((PduRState != PDUR_ONLINE) || (Com_GetStatus() != COM_INIT)) return;
    AS21_FlexRayLab_Init();
    AS21_FlexRayPeer_Init();
    FrIf_Init(&FrIf_Config);
    g_AS21_Communication.Initialized = 1U;
    AS21_ComPlatform_Enter();
    AS21_CommInitializeControllers();
    AS21_ComPlatform_Exit();
}

static void AS21_CommStartControllers(void)
{
    uint8 ctrl;
    Std_ReturnType result;
    /* Both startup payload transfers must finish before ALLOW_COLDSTART/RUN. */
    if (!AS21_CommInputIdle(0U) || !AS21_CommInputIdle(1U) ||
        ((MODULE_ERAY0.TXRQ1.U & 1U) == 0U) ||
        ((MODULE_ERAY1.TXRQ1.U & 1U) == 0U)) {
        if ((uint32)(AS21_CommNowMs - AS21_CommStageSinceMs) >= 10U) {
            g_AS21_Communication.StartupTimeoutCount++;
            AS21_CommFail(2U);
        }
        return;
    }
    for (ctrl = 0U; ctrl < 2U; ctrl++) {
        result = (ctrl == 0U) ? FrIf_AllowColdstart(0U) : Fr_17_Eray_AllowColdstart(1U);
        g_AS21_Communication.Controller[ctrl].ColdstartResult = result;
        if (result != E_OK) { AS21_CommFail(ctrl); return; }
    }
    for (ctrl = 0U; ctrl < 2U; ctrl++) {
        g_AS21_Communication.StartAttemptCount++;
        result = (ctrl == 0U) ? FrIf_StartCommunication(0U) :
                               Fr_17_Eray_StartCommunication(1U);
        g_AS21_Communication.Controller[ctrl].StartResult = result;
        if (ctrl == 0U) g_AS21_Communication.StartResult = result;
        if (result != E_OK) { AS21_CommFail(ctrl); return; }
    }
    g_AS21_Communication.Stage = AS21_COMM_STARTING;
    AS21_CommStageSinceMs = AS21_CommNowMs;
}

void AS21_Communication_Process(void)
{
    uint32 now;
    uint32 elapsedMs;
    uint8 ctrl;
    Fr_POCStatusType poc[2];
    boolean bothActive = TRUE;
    if (g_AS21_Communication.Initialized == 0U) return;
    now = MODULE_STM0.TIM0.U;
    elapsedMs = (uint32)(now - AS21_CommLastTick) / AS21_CommTicksPerMs;
    if (elapsedMs == 0U) return;
    AS21_CommLastTick += elapsedMs * AS21_CommTicksPerMs;
    AS21_CommNowMs += elapsedMs;
    g_AS21_Communication.SupervisorCount++;
    AS21_ComPlatform_Enter();
    if (g_AS21_Communication.Stage == AS21_COMM_RETRY) {
        if ((uint32)(AS21_CommNowMs - AS21_CommStageSinceMs) >= 200U)
            AS21_CommInitializeControllers();
    } else if (g_AS21_Communication.Stage == AS21_COMM_PRIMING) {
        AS21_CommStartControllers();
    } else {
        for (ctrl = 0U; ctrl < 2U; ctrl++) {
            Std_ReturnType result = (ctrl == 0U) ? FrIf_GetPOCStatus(0U, &poc[0]) :
                                      Fr_17_Eray_GetPOCStatus(1U, &poc[1]);
            g_AS21_Communication.Controller[ctrl].PocResult = result;
            if (ctrl == 0U) g_AS21_Communication.PocResult = result;
            if (result != E_OK) {
                g_AS21_Communication.PocErrorCount++;
                AS21_CommFail(ctrl);
                break;
            }
            g_AS21_Communication.Controller[ctrl].PocState = (uint8)poc[ctrl].State;
            if (ctrl == 0U) g_AS21_Communication.PocState = (uint8)poc[ctrl].State;
            if (poc[ctrl].State != FR_POCSTATE_NORMAL_ACTIVE) bothActive = FALSE;
            if ((g_AS21_Communication.Stage == AS21_COMM_RUNNING) && !bothActive) {
                AS21_CommFail(ctrl);
                break;
            }
            if ((poc[ctrl].State == FR_POCSTATE_HALT) ||
                (poc[ctrl].State == FR_POCSTATE_DEFAULT_CONFIG)) {
                AS21_CommFail(ctrl);
                break;
            }
        }
        if (g_AS21_Communication.Stage != AS21_COMM_RETRY) {
            if (bothActive) {
                if (g_AS21_Communication.Online == 0U) {
                    g_AS21_Communication.StateResult = FrIf_SetState(0U, FRIF_GOTO_ONLINE);
                    if (g_AS21_Communication.StateResult == E_OK) {
                        AS21_FlexRayLab_SetOnline(TRUE);
                        g_AS21_Communication.Online = 1U;
                        g_AS21_Communication.Stage = AS21_COMM_RUNNING;
                        g_AS21_Communication.SessionCount++;
                        AS21_FlexRayPeer_SetOnline(TRUE, AS21_CommNowMs);
                    } else AS21_CommFail(0U);
                }
                if (g_AS21_Communication.Online != 0U) {
                    Com_MainFunctionRx();
                    AS21_FlexRayLab_Process();
                    Com_MainFunctionTx();
                    FrIf_MainFunction(0U);
                    AS21_FlexRayPeer_Process(AS21_CommNowMs);
                    if (g_AS21_FlexRayPeer.RecoveryRequested != 0U) AS21_CommFail(1U);
                }
            } else if ((uint32)(AS21_CommNowMs - AS21_CommStageSinceMs) >= 500U) {
                g_AS21_Communication.StartupTimeoutCount++;
                AS21_CommFail(2U);
            }
        }
    }
    AS21_ComPlatform_Exit();
}

void AS21_Communication_TimerIsr(void)
{
    g_AS21_Communication.TimerIrqCount++;
    if ((g_AS21_Communication.Initialized != 0U) &&
        (g_AS21_Communication.Online != 0U)) {
        g_AS21_Communication.JobCallCount++;
        FrIf_JobListExec(0U);
    }
}

void AS21_Communication_RxIndication(PduIdType pduId, PduInfoType *pduInfo)
{
    uint8 i;
    if ((g_AS21_Communication.Online == 0U) ||
        (pduId != AS21_PDUR_REQUEST_ROUTE) || (pduInfo == NULL_PTR) ||
        (pduInfo->SduDataPtr == NULL_PTR) || (pduInfo->SduLength != 64U)) {
        g_AS21_Communication.RxRejectedCount++;
        return;
    }
    for (i = 0U; i < 64U; i++)
        g_AS21_Communication.LastRxData[i] = pduInfo->SduDataPtr[i];
    g_AS21_Communication.RxCount++;
    PduR_FrIfRxIndication(pduId, pduInfo);
}

Std_ReturnType AS21_Communication_TriggerTransmit(PduIdType pduId, PduInfoType *pduInfo)
{
    Std_ReturnType result;
    if ((g_AS21_Communication.Online == 0U) || (g_AS21_FlexRayLab.TxReady == 0U) ||
        (pduId != AS21_PDUR_ECHO_ROUTE) || (pduInfo == NULL_PTR) ||
        (pduInfo->SduDataPtr == NULL_PTR) || (pduInfo->SduLength < 64U)) return E_NOT_OK;
    g_AS21_Communication.TxTriggerCount++;
    result = PduR_FrIfTriggerTransmit(pduId, pduInfo);
    if (result != E_OK) g_AS21_Communication.TxTriggerErrorCount++;
    return result;
}

void AS21_Communication_TxConfirmation(PduIdType pduId)
{
    if (pduId == AS21_PDUR_ECHO_ROUTE) {
        g_AS21_Communication.TxConfirmationCount++;
        PduR_FrIfTxConfirmation(pduId);
    }
}
