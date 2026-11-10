/* Included once by Cpu0_Main.c. Test peer owns only controller1 app LPDUs. */
#include "APPS/main/AS21_FlexRayPeer.h"
#include "Fr_17_Eray.h"
#include <string.h>

volatile AS21_FlexRayPeerDiagType g_AS21_FlexRayPeer;
static uint32 AS21_PeerLastRequestMs;
static uint8 AS21_PeerSequence;
static boolean AS21_PeerTxDone;
static boolean AS21_PeerRxDone;
static boolean AS21_PeerRxMatches;

void AS21_FlexRayPeer_Init(void)
{
    memset((void *)&g_AS21_FlexRayPeer, 0, sizeof(AS21_FlexRayPeerDiagType));
    g_AS21_FlexRayPeer.RequestValue = 0x12U;
    g_AS21_FlexRayPeer.SendResult = E_NOT_OK;
    g_AS21_FlexRayPeer.ReceiveResult = E_NOT_OK;
    g_AS21_FlexRayPeer.TxStatusResult = E_NOT_OK;
    AS21_PeerSequence = 0U;
    AS21_FlexRayPeer_SetOnline(FALSE, 0U);
}

void AS21_FlexRayPeer_SetOnline(boolean online, uint32 nowMs)
{
    g_AS21_FlexRayPeer.Online = (uint8)online;
    g_AS21_FlexRayPeer.Pending = 0U;
    g_AS21_FlexRayPeer.RecoveryRequested = 0U;
    g_AS21_FlexRayPeer.SendRequest = 0U;
    AS21_PeerLastRequestMs = nowMs;
    AS21_PeerTxDone = FALSE;
    AS21_PeerRxDone = FALSE;
    AS21_PeerRxMatches = FALSE;
}

void AS21_FlexRayPeer_Process(uint32 nowMs)
{
    static const uint8 values[] = {0x12U, 0x00U, 0x80U, 0xFFU};
    uint8 data[64];
    uint8 length = 0U;
    uint8 i;
    Fr_RxLPduStatusType rxStatus = FR_NOT_RECEIVED;
    Fr_TxLPduStatusType txStatus = FR_NOT_TRANSMITTED;
    boolean matches;
    if ((g_AS21_FlexRayPeer.Online == 0U) ||
        (g_AS21_FlexRayPeer.RecoveryRequested != 0U)) return;
    /* MCAL provides no receive timestamp. Once this request has expired,
     * a newly polled payload cannot establish an on-time response. */
    if ((g_AS21_FlexRayPeer.Pending != 0U) &&
        ((uint32)(nowMs - AS21_PeerLastRequestMs) >= 100U)) {
        g_AS21_FlexRayPeer.TimeoutCount++;
        g_AS21_FlexRayPeer.RecoveryRequested = 1U;
        return;
    }

    g_AS21_FlexRayPeer.ReceiveResult =
        Fr_17_Eray_ReceiveRxLPdu(1U, 41U, data, &rxStatus, &length);
    if (g_AS21_FlexRayPeer.ReceiveResult != E_OK) {
        g_AS21_FlexRayPeer.ApiErrorCount++;
        g_AS21_FlexRayPeer.RecoveryRequested = 1U;
        return;
    }
    if (rxStatus != FR_NOT_RECEIVED) {
        if (g_AS21_FlexRayPeer.Pending == 0U) {
            /* Drain old data before a new submission, even if values repeat. */
            g_AS21_FlexRayPeer.StaleRxCount++;
            return;
        }
        if (!AS21_PeerRxDone) {
            g_AS21_FlexRayPeer.RxCount++;
            g_AS21_FlexRayPeer.LastLength = length;
            matches = (length == 64U);
            for (i = 0U; i < 64U; i++) {
                g_AS21_FlexRayPeer.LastResponse[i] = (i < length) ? data[i] : 0U;
                if ((i < length) && (data[i] != ((i == 0U) ?
                    g_AS21_FlexRayPeer.ExpectedResponse : 0U))) matches = FALSE;
            }
            AS21_PeerRxDone = TRUE;
            AS21_PeerRxMatches = matches;
        }
    }
    if (g_AS21_FlexRayPeer.Pending != 0U) {
        if (!AS21_PeerTxDone) {
            g_AS21_FlexRayPeer.TxStatusResult =
                Fr_17_Eray_CheckTxLPduStatus(1U, 5U, &txStatus);
            if ((g_AS21_FlexRayPeer.TxStatusResult != E_OK) ||
                (txStatus == FR_TRANSMITTED_CONFLICT)) {
                g_AS21_FlexRayPeer.ApiErrorCount++;
                g_AS21_FlexRayPeer.RecoveryRequested = 1U;
                return;
            }
            if (txStatus == FR_TRANSMITTED) {
                AS21_PeerTxDone = TRUE;
                g_AS21_FlexRayPeer.TxCompletedCount++;
            }
        }
        if (AS21_PeerTxDone && AS21_PeerRxDone) {
            g_AS21_FlexRayPeer.Pending = 0U;
            if (AS21_PeerRxMatches) g_AS21_FlexRayPeer.MatchCount++;
            else {
                g_AS21_FlexRayPeer.MismatchCount++;
                g_AS21_FlexRayPeer.RecoveryRequested = 1U;
            }
        }
        return;
    }
    if ((g_AS21_FlexRayPeer.SendRequest == 0U) &&
        ((g_AS21_FlexRayPeer.AutoMode == 0U) ||
         ((uint32)(nowMs - AS21_PeerLastRequestMs) < 100U))) return;
    memset(data, 0, sizeof(data));
    data[0] = (g_AS21_FlexRayPeer.SendRequest != 0U) ?
        g_AS21_FlexRayPeer.RequestValue : values[AS21_PeerSequence];
    g_AS21_FlexRayPeer.SendRequest = 0U;
    g_AS21_FlexRayPeer.LastRequest = data[0];
    g_AS21_FlexRayPeer.ExpectedResponse = (uint8)(data[0] ^ 0xFFU);
    g_AS21_FlexRayPeer.SendResult = Fr_17_Eray_TransmitTxLPdu(1U, 5U, data, 64U);
    if (g_AS21_FlexRayPeer.SendResult != E_OK) {
        g_AS21_FlexRayPeer.ApiErrorCount++;
        g_AS21_FlexRayPeer.RecoveryRequested = 1U;
        return;
    }
    g_AS21_FlexRayPeer.RequestCount++;
    g_AS21_FlexRayPeer.Pending = 1U;
    AS21_PeerLastRequestMs = nowMs;
    AS21_PeerTxDone = FALSE;
    AS21_PeerRxDone = FALSE;
    AS21_PeerSequence = (uint8)((AS21_PeerSequence + 1U) % 4U);
}
