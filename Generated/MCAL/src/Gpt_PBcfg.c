/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2019)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Gpt_PBcfg.c                                                   **
**                                                                            **
**  VERSION   : 1.30.0_11.0.0                                                 **
**                                                                            **
**  DATE, TIME: 2025-07-23, 15:59:31      !!!IGNORE-LINE!!!                   **
**                                                                            **
**  GENERATOR : Build b191017-0938          !!!IGNORE-LINE!!!                 **
**                                                                            **
**  BSW MODULE DECRIPTION : Gpt.bmd                                           **
**                                                                            **
**  VARIANT   : Variant PB                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : GPT configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of GPT Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Include module header File */
#include "Gpt.h"

/*******************************************************************************
**                      Inclusion File Check                                  **
*******************************************************************************/


/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/


/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
/*
Channel Notification Function Declarations
*/
/*    
GptChannelConfiguration_Tom0_Ch0
channel notification function(s) declaration 
*/
extern void IoHwAb_Tom0_Ch0_GptNotification(void);

/*    
GptChannelConfiguration_GPT12
channel notification function(s) declaration 
*/
extern void IoHwAb_GptT3_GptNotification_1ms(void);

/*    
GptChannelConfiguration_Tom0_Ch1
channel notification function(s) declaration 
*/
extern void IoHwAb_Tom0_Ch1_GptNotification(void);

/*******************************************************************************
**                      Global Constant Definitions                           **
*******************************************************************************/

/*
 Channel Configuration Instance
*/

/* Memory mapping for configuration data */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/*MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"

/*
  Channel Symbolic Name(ChannelId) : GptChannelConfiguration_Tom0_Ch0
  GTM TOM/ATOM/GPT12 Channel : GTM_TOM0_CHANNEL0 in GPT_MODE_CONTINUOUS
*/
static const Mcu_17_Gtm_TomAtomChConfigType GptGtmTimerInfo_Core0_Ch0= 
{
  MCU_GTM_TIMER_TOM, /* Timer Type (TOM/ATOM)*/
  0x0, /* Timer Number Module No | Timer Channel No */
  0x1800U, /* Channel Control Register */
  0x0U, /* CN0 in ticks */
  0x0U, /* CM0 in ticks */
  0x0U, /* CM1 in ticks */
  0x0U, /* SR0 in ticks */
  0x0U, /* SR1 in ticks */
  0x0U, /* Port Out     */
  0x80U  /* Interrupt status and mode*/
};
/*
  Channel Symbolic Name(ChannelId) : GptChannelConfiguration_GPT12
  GTM TOM/ATOM/GPT12 Channel : MCU_GPT12_TIMER2 in GPT_MODE_CONTINUOUS
*/
static const Mcu_17_Gpt12_TimerConfigType GptGpt12TimerInfo_Core0_Ch1[ ]= 
{

  {
    MCU_GPT12_TIMER3,      /* Timer Type (GPT1/GPT2)*/
    0x280U, /* Channel Control Register */
    0x0U,
    0x0U
  },
  {
    MCU_GPT12_TIMER2,      /* Timer Type (GPT1/GPT2)*/
    0x227U, /* Channel Control Register */
    0x0U,
    0x0U
  }
};
/*
  Channel Symbolic Name(ChannelId) : GptChannelConfiguration_Tom0_Ch1
  GTM TOM/ATOM/GPT12 Channel : GTM_TOM0_CHANNEL1 in GPT_MODE_CONTINUOUS
*/
static const Mcu_17_Gtm_TomAtomChConfigType GptGtmTimerInfo_Core0_Ch2= 
{
  MCU_GTM_TIMER_TOM, /* Timer Type (TOM/ATOM)*/
  0x1, /* Timer Number Module No | Timer Channel No */
  0x1800U, /* Channel Control Register */
  0x0U, /* CN0 in ticks */
  0x0U, /* CM0 in ticks */
  0x0U, /* CM1 in ticks */
  0x0U, /* SR0 in ticks */
  0x0U, /* SR1 in ticks */
  0x0U, /* Port Out     */
  0x80U  /* Interrupt status and mode*/
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"


/* Memory mapping for configuration data */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/*MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"

static const Gpt_ChannelConfigType Gpt_kChannelConfig_Core0[ ] =
{
  /*
    Channel Symbolic Name(ChannelId) : GptChannelConfiguration_Tom0_Ch0
    GTM TOM/ATOM/GPT12 Channel : GTM_TOM0_CHANNEL0 in GPT_MODE_CONTINUOUS
  */
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    &IoHwAb_Tom0_Ch0_GptNotification, /* Notification Function */
    #endif
    
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
    && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    
    #if ((GPT_ATOM_USED == STD_ON) || (GPT_TOM_USED == STD_ON))
    &GptGtmTimerInfo_Core0_Ch0,
    #endif
    #if (GPT_GPT12_USED == STD_ON)
    NULL_PTR
    #endif
  },

  /*
    Channel Symbolic Name(ChannelId) : GptChannelConfiguration_GPT12
    GTM TOM/ATOM/GPT12 Channel : MCU_GPT12_TIMER2 in GPT_MODE_CONTINUOUS
  */
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    &IoHwAb_GptT3_GptNotification_1ms, /* Notification Function */
    #endif
    
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
    && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    
    #if ((GPT_ATOM_USED == STD_ON) || (GPT_TOM_USED == STD_ON))
    NULL_PTR,
    #endif
    #if (GPT_GPT12_USED == STD_ON)
    GptGpt12TimerInfo_Core0_Ch1
    #endif
  },

  /*
    Channel Symbolic Name(ChannelId) : GptChannelConfiguration_Tom0_Ch1
    GTM TOM/ATOM/GPT12 Channel : GTM_TOM0_CHANNEL1 in GPT_MODE_CONTINUOUS
  */
  {
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    &IoHwAb_Tom0_Ch1_GptNotification, /* Notification Function */
    #endif
    
    #if ( (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
    && (GPT_REPORT_WAKEUP_SOURCE == STD_ON) )
    0U, /* Wakeup Info */
    #endif
    
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    (boolean)FALSE, /* Wakeup Capability */
    #endif
    
    GPT_MODE_CONTINUOUS, /* Channel Mode */
    
    #if ((GPT_ATOM_USED == STD_ON) || (GPT_TOM_USED == STD_ON))
    &GptGtmTimerInfo_Core0_Ch2,
    #endif
    #if (GPT_GPT12_USED == STD_ON)
    NULL_PTR
    #endif
  }
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"

/*
  Configuration: Gpt Driver Configuration for each Core
*/

/* Memory Mapping the configuration constant */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define GPT_START_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/*MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"

static const Gpt_CoreConfigType Gpt_kConfig_Core0 =
{
  /* Pointer to channel configuration of Core0 */
  Gpt_kChannelConfig_Core0,

  /* Channel configerd for 1us Predef Timer in Core 0 */
  #if ((GPT_PREDEF_TIMER_1US_16BIT_EN == STD_ON)    || \
  (GPT_PREDEF_TIMER_1US_24BIT_EN == STD_ON)    || \
  (GPT_PREDEF_TIMER_1US_32BIT_EN == STD_ON))
  &Gpt_k1UsPredefTimerChannelConfig_Core0,
  #endif
  
  /* Channel configerd for 100us Predef Timer in Core 0 */
  #if (GPT_PREDEF_TIMER_100US_32BIT_EN == STD_ON)
  &Gpt_k100UsPredefTimerChannelConfig_Core0,
  #endif
  
  /* Maximum Normal Channels allocated to core 0 */
  GPT_MAX_CHANNELS_CORE0
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
in generated code due to Autosar Naming constraints.*/
#define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_CORE0_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"

/* Memory Mapping the configuration constant */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define GPT_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
   directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"

/*
  Configuration: Configuration
  Definition of Gpt_ConfigType structure
*/
/* MISRA2012_RULE_8_7_JUSTIFICATION: Module configuration data structure
   declaration as per Autosar guidelines. This data structure may be needed
   by SW units using Gpt Driver APIs */
/* MISRA2012_RULE_8_4_JUSTIFICATION: Definition is as per Autosar guidelines */
const Gpt_ConfigType Gpt_Config =
{
  /* Pointer to Gpt Core Specific Config Set */
  {
    &Gpt_kConfig_Core0, /* CORE 0 */
    NULL_PTR,           /* CORE 1 */
    NULL_PTR,           /* CORE 2 */
    NULL_PTR,           /* CORE 3 */
  }
};

/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers going beyond 32 chars.
   in generated code due to Autosar Naming constraints.*/
#define GPT_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_20_1_JUSTIFICATION: File inclusion after pre-processor
directives is allowed only for MemMap.h*/
/* MISRA2012_RULE_4_10_JUSTIFICATION: Memmap header is repeatedly included
   without safegaurd. It complies to Autosar guidelines. */
#include "Gpt_MemMap.h"


/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/


/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/* End Of File */
