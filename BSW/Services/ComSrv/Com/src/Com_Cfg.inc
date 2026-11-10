/* Experimental UINT8 signals at Byte0 of the two 64-byte I-PDUs. */
#include "APPS/main/AS21_FlexRayLab.h"
const ComNotificationCalloutType ComNotificationCallouts[] = {
    AS21_FlexRayLab_RxNotification, AS21_FlexRayLab_TxNotification
};
const ComRxIPduCalloutType ComRxIPduCallouts[] = {NULL_PTR};
const ComTxIPduCalloutType ComTxIPduCallouts[] = {NULL_PTR};
const ComTxIPduCalloutType ComTriggerTransmitIPduCallouts[] = {NULL_PTR};
static const uint8 AS21_Com_InitialValue = 0U;
static const ComSignal_type AS21_Com_Signals[] = {
    {.ComBitPosition = 0U, .ComBitSize = 8U, .ComHandleId = AS21_COM_REQUEST_VALUE,
     .ComErrorNotification = COM_NO_FUNCTION_CALLOUT, .ComNotification = 0U,
     .ComTimeoutNotification = COM_NO_FUNCTION_CALLOUT, .ComSignalEndianess = COM_LITTLE_ENDIAN,
     .ComSignalInitValue = &AS21_Com_InitialValue, .ComSignalType = COM_UINT8,
     .ComTransferProperty = COM_PENDING, .ComIPduHandleId = AS21_COM_REQUEST_PDU},
    {.ComBitPosition = 0U, .ComBitSize = 8U, .ComHandleId = AS21_COM_ECHO_VALUE,
     .ComErrorNotification = COM_NO_FUNCTION_CALLOUT, .ComNotification = 1U,
     .ComTimeoutNotification = COM_NO_FUNCTION_CALLOUT, .ComSignalEndianess = COM_LITTLE_ENDIAN,
     .ComSignalInitValue = &AS21_Com_InitialValue, .ComSignalType = COM_UINT8,
     .ComTransferProperty = COM_TRIGGERED_WITHOUT_REPETITION, .ComIPduHandleId = AS21_COM_ECHO_PDU},
    {.Com_Arc_EOL = 1U}
};
static const ComSignal_type * const AS21_Com_RxSignals[] = {&AS21_Com_Signals[0], NULL_PTR};
static const ComSignal_type * const AS21_Com_TxSignals[] = {&AS21_Com_Signals[1], NULL_PTR};
static const ComIPduGroup_type AS21_Com_Groups[] = {
    {.ComIPduGroupHandleId = AS21_COM_RX_GROUP},
    {.ComIPduGroupHandleId = AS21_COM_TX_GROUP}, {.Com_Arc_EOL = 1U}
};
static const ComIPduGroup_type AS21_Com_RxGroups[] = {
    {.ComIPduGroupHandleId = AS21_COM_RX_GROUP}, {.Com_Arc_EOL = 1U}
};
static const ComIPduGroup_type AS21_Com_TxGroups[] = {
    {.ComIPduGroupHandleId = AS21_COM_TX_GROUP}, {.Com_Arc_EOL = 1U}
};
static const ComIPdu_type AS21_Com_Pdus[] = {
    {.ComRxIPduCallout = COM_NO_FUNCTION_CALLOUT, .ComTxIPduCallout = COM_NO_FUNCTION_CALLOUT,
     .ComTriggerTransmitIPduCallout = COM_NO_FUNCTION_CALLOUT,
     .ComIPduSignalProcessing = COM_IMMEDIATE, .ComIPduSize = 64U, .ComIPduDirection = COM_RECEIVE,
     .ComIPduGroupRefs = AS21_Com_RxGroups, .ComIPduSignalRef = AS21_Com_RxSignals},
    {.ComRxIPduCallout = COM_NO_FUNCTION_CALLOUT, .ComTxIPduCallout = COM_NO_FUNCTION_CALLOUT,
     .ComTriggerTransmitIPduCallout = COM_NO_FUNCTION_CALLOUT, .ArcIPduOutgoingId = 1U,
     .ComIPduSignalProcessing = COM_IMMEDIATE, .ComIPduSize = 64U, .ComIPduDirection = COM_SEND,
     .ComIPduGroupRefs = AS21_Com_TxGroups, .ComIPduSignalRef = AS21_Com_TxSignals,
     .ComTxIPdu = {.ComTxIPduUnusedAreasDefault = 0U, .ComTxIPduClearUpdateBit = CONFIRMATION,
                  .ComTxModeTrue = {.ComTxModeMode = COM_DIRECT},
                  .ComTxModeFalse = {.ComTxModeMode = COM_DIRECT}}},
    {.Com_Arc_EOL = 1U}
};
const Com_ConfigType AS21_Com_Config = {
    .ComConfigurationId = 1U, .ComNofIPdus = 2U, .ComNofSignals = 2U,
    .ComIPdu = AS21_Com_Pdus, .ComSignal = AS21_Com_Signals, .ComIPduGroup = AS21_Com_Groups
};
