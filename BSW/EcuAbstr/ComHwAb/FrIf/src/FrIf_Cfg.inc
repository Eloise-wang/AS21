/* Experimental FIBEX: controller0, Channel A, Slot11 RX / Slot17 TX. */
#include "FrIf.h"
#include "AS21_Communication.h"
#if (FR_17_ERAY_PREPARE_LPDU != STD_ON)
#error FrIf_driver_table_requires_PrepareLPdu
#endif
const FrIf_FrAPIType AS21_FrIf_DriverApi = {
    .Fr_ControllerInit = Fr_17_Eray_ControllerInit,
    .Fr_StartCommunication = Fr_17_Eray_StartCommunication,
    .Fr_AllowColdstart = Fr_17_Eray_AllowColdstart,
    .Fr_TransmitTxLPdu = Fr_17_Eray_TransmitTxLPdu,
    .Fr_ReceiveRxLPdu = Fr_17_Eray_ReceiveRxLPdu,
    .Fr_CheckTxLPduStatus = Fr_17_Eray_CheckTxLPduStatus,
    .Fr_PrepareLPdu = Fr_17_Eray_PrepareLPdu,
    .Fr_SetAbsoluteTimer = Fr_17_Eray_SetAbsoluteTimer,
    .Fr_EnableAbsoluteTimerIRQ = Fr_17_Eray_EnableAbsoluteTimerIRQ,
    .Fr_AckAbsoluteTimerIRQ = Fr_17_Eray_AckAbsoluteTimerIRQ,
    .Fr_DisableAbsoluteTimerIRQ = Fr_17_Eray_DisableAbsoluteTimerIRQ,
    .Fr_CancelAbsoluteTimer = Fr_17_Eray_CancelAbsoluteTimer,
    .Fr_GetAbsoluteTimerIRQStatus = Fr_17_Eray_GetAbsoluteTimerIRQStatus,
    .Fr_GetGlobalTime = Fr_17_Eray_GetGlobalTime,
    .Fr_SetWakeupChannel = Fr_17_Eray_SetWakeupChannel,
    .Fr_GetPOCStatus = Fr_17_Eray_GetPOCStatus,
    .Fr_HaltCommunication = Fr_17_Eray_HaltCommunication,
    .Fr_AbortCommunication = Fr_17_Eray_AbortCommunication,
    .Fr_SendWUP = Fr_17_Eray_SendWUP
};

static const FrIf_RxPduType AS21_FrIf_RxPdus[] = {
    {.FrIf_RxIndicationHandle = 0U, .RxPduLength = 64U}
};
static const FrIf_TxPduType AS21_FrIf_TxPdus[] = {
    {.FrIf_UserTriggerTransmitHandle = 0U, .FrIf_TxConfirmationHandle = 0U,
     .FrIf_TxLength = 64U, .FrIf_CounterLimit = 1U, .FrIf_Confirm = TRUE,
     .FrIf_Immediate = FALSE, .FrIf_NoneMode = FALSE}
};
static const FrIf_PduDirectionType AS21_FrIf_Directions[] = {
    {.FrIf_RxPduPtr = &AS21_FrIf_RxPdus[0]},
    {.FrIf_TxPduPtr = &AS21_FrIf_TxPdus[0]}
};
/* RX and TX PDU IDs have separate namespaces; both are 0. */
static const FrIf_PduType AS21_FrIf_Pdus[] = {
    {.FrIf_PduDirectionPtr = &AS21_FrIf_Directions[0], .FrIf_PduId = 0U, .FrIf_UpperLayerPduId = 0U},
    {.FrIf_PduDirectionPtr = &AS21_FrIf_Directions[1], .FrIf_PduId = 0U, .FrIf_UpperLayerPduId = 1U}
};
static const FrIf_PdusIn_FrameType AS21_FrIf_Payloads[] = {
    {.FrIf_Pdu = &AS21_FrIf_Pdus[0], .FrIf_PduUpdateBitOffset = -1, .FrIf_PduOffset = 0U},
    {.FrIf_Pdu = &AS21_FrIf_Pdus[1], .FrIf_PduUpdateBitOffset = -1, .FrIf_PduOffset = 0U}
};
static const FrIf_FrameStructureType AS21_FrIf_Structures[] = {
    {.FrIf_PdusInFramePtr = &AS21_FrIf_Payloads[0], .FrIf_ByteOrder = FRIF_LITTLE_ENDIAN},
    {.FrIf_PdusInFramePtr = &AS21_FrIf_Payloads[1], .FrIf_ByteOrder = FRIF_LITTLE_ENDIAN}
};
static const FrIf_FrameTriggeringType AS21_FrIf_Frames[] = {
    {.FrIf_FrameStructureRef = &AS21_FrIf_Structures[0], .FrIf_SlotId = 11U,
     .FrIf_NumberPdusInFrame = 1U, .FrIf_LPduIdx = 0U, .FrIf_LSduLength = 64U,
     .FrIf_BaseCycle = 0U, .FrIf_CycleRepetition = 1U, .FrIf_FrameStructureIdx = 0U,
     .FrIf_Channel = FRIF_CHANNEL_A, .FrIf_AlwaysTransmit = FALSE},
    {.FrIf_FrameStructureRef = &AS21_FrIf_Structures[1], .FrIf_SlotId = 17U,
     .FrIf_NumberPdusInFrame = 1U, .FrIf_LPduIdx = 1U, .FrIf_LSduLength = 64U,
     .FrIf_BaseCycle = 0U, .FrIf_CycleRepetition = 1U, .FrIf_FrameStructureIdx = 1U,
     .FrIf_Channel = FRIF_CHANNEL_A, .FrIf_AlwaysTransmit = FALSE}
};
/* Fr_Buffer is the MCAL LPduIdx, NOT the physical message buffer index. */
static const FrIf_LPduType AS21_FrIf_Lpdus[] = {
    {.FrIf_VBTriggeringRef = &AS21_FrIf_Frames[0], .Fr_Buffer = 4U, .FrIf_Reconfigurable = FALSE},
    {.FrIf_VBTriggeringRef = &AS21_FrIf_Frames[1], .Fr_Buffer = 40U, .FrIf_Reconfigurable = FALSE}
};
static const FrIf_ControllerType AS21_FrIf_Controllers[] = {
    {.FrIf_LpduPtr = AS21_FrIf_Lpdus, .FrIf_FrameTriggeringPtr = AS21_FrIf_Frames,
     .FrIf_FrCtrlIdx = 0U, .FrIf_LPduCount = 2U, .FrIf_CtrlIdx = 0U, .FrIf_ClstrRefIdx = 0U}
};
static const FrIf_ControllerType * const AS21_FrIf_ClusterControllers[] = {&AS21_FrIf_Controllers[0]};
static const FrIf_CommunicationOperationType AS21_FrIf_Operations[] = {
    {.FrIf_LPduIdxRef = &AS21_FrIf_Lpdus[0], .FrIf_CommunicationAction = RECEIVE_AND_INDICATE,
     .FrIf_RxComOpMaxLoop = 1U, .FrIf_CtrlIdx = 0U, .FrIf_FrameConfigIdx = 0U, .FrIf_CommunicationOperationIdx = 0U},
    {.FrIf_LPduIdxRef = &AS21_FrIf_Lpdus[1], .FrIf_CommunicationAction = TX_CONFIRMATION,
     .FrIf_CtrlIdx = 0U, .FrIf_FrameConfigIdx = 1U, .FrIf_CommunicationOperationIdx = 1U},
    {.FrIf_LPduIdxRef = &AS21_FrIf_Lpdus[1], .FrIf_CommunicationAction = DECOUPLED_TRANSMISSION,
     .FrIf_CtrlIdx = 0U, .FrIf_FrameConfigIdx = 1U, .FrIf_CommunicationOperationIdx = 2U}
};
/* Slot11 ends at 1012MT; Slot17 action point is 1480MT. The 1200MT job
 * reads RX and prepares TX; confirmations refer to the preceding cycle.
 * All 64 cycle-counter values must be present, including the 63 -> 0 wrap. */
#define AS21_FRIF_JOB(cycle) {AS21_FrIf_Operations, 1200U, 3U, (cycle)}
#define AS21_FRIF_EIGHT_JOBS(base) \
    AS21_FRIF_JOB((base)), AS21_FRIF_JOB((base)+1U), \
    AS21_FRIF_JOB((base)+2U), AS21_FRIF_JOB((base)+3U), \
    AS21_FRIF_JOB((base)+4U), AS21_FRIF_JOB((base)+5U), \
    AS21_FRIF_JOB((base)+6U), AS21_FRIF_JOB((base)+7U)
static const FrIf_JobType AS21_FrIf_Jobs[] = {
    AS21_FRIF_EIGHT_JOBS(0U), AS21_FRIF_EIGHT_JOBS(8U),
    AS21_FRIF_EIGHT_JOBS(16U), AS21_FRIF_EIGHT_JOBS(24U),
    AS21_FRIF_EIGHT_JOBS(32U), AS21_FRIF_EIGHT_JOBS(40U),
    AS21_FRIF_EIGHT_JOBS(48U), AS21_FRIF_EIGHT_JOBS(56U)
};
#undef AS21_FRIF_EIGHT_JOBS
#undef AS21_FRIF_JOB
static const FrIf_JobListType AS21_FrIf_JobList = {
    .FrIf_JobPtr = AS21_FrIf_Jobs, .FrIf_NbrOfJobs = 64U,
    .FrIf_FrAbsTimerIdx = 0U, .FrIf_AbsTimerIdx = 0U
};
static const FrIf_ClusterType AS21_FrIf_Clusters[] = {
    {.FrIf_ControllerPtr = AS21_FrIf_ClusterControllers, .FrIf_JobListPtr = &AS21_FrIf_JobList,
     .FrIf_GMacroPerCycle = 4900U, .FrIf_MainFunctionPeriod = 1000000U,
     .FrIf_MaxIsrDelay = 50U, .FrIf_GdCycle = 4900000U, .FrIf_GdMacrotick = 1000U,
     .FrIf_GNumberOfStaticSlots = 38U, .FrIf_ClstIdx = 0U,
     .FrIf_ControllerCount = 1U, .FrIf_GdStaticSlots = 92U}
};
static const FrIf_DriverConfigType AS21_FrIf_Drivers[] = {
    {.FrIf_FrAPIPtr = &AS21_FrIf_DriverApi, .FrIf_CCPerDriver = 1U}
};
static const FrIf_RxIndicationType AS21_FrIf_RxCallbacks[] = {AS21_Communication_RxIndication};
static const FrIf_TriggerTransmitType AS21_FrIf_TxCallbacks[] = {AS21_Communication_TriggerTransmit};
static const FrIf_TxConfirmationType AS21_FrIf_ConfirmCallbacks[] = {AS21_Communication_TxConfirmation};
const FrIf_ConfigType FrIf_Config = {
    .FrIf_ClusterPtr = AS21_FrIf_Clusters, .FrIf_CtrlPtr = AS21_FrIf_Controllers,
    .Fr_Driver_ConfigPtr = AS21_FrIf_Drivers, .FrIf_TxPduCfgPtr = AS21_FrIf_TxPdus,
    .FrIf_RxPduCfgPtr = AS21_FrIf_RxPdus, .FrIf_RxIndicationFncs = AS21_FrIf_RxCallbacks,
    .FrIf_TriggerTransmitFncs = AS21_FrIf_TxCallbacks, .FrIf_TxConfirmationFncs = AS21_FrIf_ConfirmCallbacks,
    .FrIf_ClusterCount = 1U, .FrIf_CtrlCount = 1U, .FrIf_TxPduCount = 1U, .FrIf_RxPduCount = 1U
};
