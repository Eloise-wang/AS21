/* RX route0: FrIf -> Com PDU0. TX route1: Com PDU1 -> FrIf TX PDU0. */
static const PduRDestPdu_type AS21_PduR_RxDestination = {
    .DataProvision = PDUR_DIRECT, .DestPduId = 0U, .DestModule = ARC_PDUR_COM
};
static const PduRDestPdu_type AS21_PduR_TxDestination = {
    .DataProvision = PDUR_TRIGGER_TRANSMIT, .DestPduId = 0U, .DestModule = ARC_PDUR_FRIF
};
static const PduRDestPdu_type * const AS21_PduR_RxDestinations[] = {&AS21_PduR_RxDestination, NULL_PTR};
static const PduRDestPdu_type * const AS21_PduR_TxDestinations[] = {&AS21_PduR_TxDestination, NULL_PTR};
static const PduRRoutingPath_type AS21_PduR_RxRoute = {
    .SrcPduId = 0U, .SrcModule = ARC_PDUR_FRIF, .PduRDestPdus = AS21_PduR_RxDestinations,
    .PduRDestinatnNum = 1U
};
static const PduRRoutingPath_type AS21_PduR_TxRoute = {
    .SrcPduId = 1U, .SrcModule = ARC_PDUR_COM, .PduRDestPdus = AS21_PduR_TxDestinations,
    .PduRDestinatnNum = 1U
};
static const PduRRoutingPath_type * const AS21_PduR_Routes[] = {&AS21_PduR_RxRoute, &AS21_PduR_TxRoute};
const PduR_PBConfigType AS21_PduR_Config = {
    .RoutingPaths = AS21_PduR_Routes, .NRoutingPaths = 2U, .PduRConfigurationId = 1U
};
const PduR_RamBufCfgType PduR_RamBufCfg = {0};
