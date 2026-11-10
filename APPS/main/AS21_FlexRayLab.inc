/* Included once by Cpu0_Main.c; application data is accessed only via Com. */
#include "APPS/main/AS21_FlexRayLab.h"
#include "Com.h"

volatile AS21_FlexRayLabDiagType g_AS21_FlexRayLab;
static Com_IpduGroupVector AS21_LabGroups;
static boolean AS21_LabRxPending;

void AS21_FlexRayLab_Init(void)
{
    AS21_LabRxPending = FALSE;
    g_AS21_FlexRayLab.Online = 0U;
    g_AS21_FlexRayLab.TxReady = 0U;
    g_AS21_FlexRayLab.ReceiveResult = COM_SERVICE_NOT_AVAILABLE;
    g_AS21_FlexRayLab.SendResult = COM_SERVICE_NOT_AVAILABLE;
    Com_ClearIpduGroupVector(AS21_LabGroups);
    Com_IpduGroupControl(AS21_LabGroups, FALSE);
}

void AS21_FlexRayLab_SetOnline(boolean online)
{
    /* Called with CPU0 communication lock held, only on state transitions. */
    AS21_LabRxPending = FALSE;
    g_AS21_FlexRayLab.Online = (uint8)online;
    g_AS21_FlexRayLab.TxReady = 0U;
    Com_ClearIpduGroupVector(AS21_LabGroups);
    if (online) Com_SetIpduGroup(AS21_LabGroups, AS21_COM_RX_GROUP, TRUE);
    Com_IpduGroupControl(AS21_LabGroups, FALSE);
}

void AS21_FlexRayLab_RxNotification(void)
{
    /* Com calls this after accepting and storing the receive signal. */
    if (g_AS21_FlexRayLab.Online != 0U) {
        AS21_LabRxPending = TRUE;
        g_AS21_FlexRayLab.RxNotificationCount++;
    }
}

void AS21_FlexRayLab_Process(void)
{
    uint8 request;
    uint8 response;
    if ((g_AS21_FlexRayLab.Online == 0U) || !AS21_LabRxPending) return;
    g_AS21_FlexRayLab.ReceiveResult = Com_ReceiveSignal(AS21_COM_REQUEST_VALUE, &request);
    if (g_AS21_FlexRayLab.ReceiveResult != E_OK) {
        g_AS21_FlexRayLab.ApiErrorCount++;
        return;
    }
    g_AS21_FlexRayLab.ReadCount++;
    response = (uint8)(request ^ 0xFFU);
    /* Start TX before SendSignal so COM_DIRECT can submit the PDU request. */
    if (g_AS21_FlexRayLab.TxReady == 0U) {
        Com_SetIpduGroup(AS21_LabGroups, AS21_COM_TX_GROUP, TRUE);
        Com_IpduGroupControl(AS21_LabGroups, FALSE);
    }
    g_AS21_FlexRayLab.SendResult = Com_SendSignal(AS21_COM_ECHO_VALUE, &response);
    if (g_AS21_FlexRayLab.SendResult == E_OK) {
        g_AS21_FlexRayLab.LastRequest = request;
        g_AS21_FlexRayLab.LastResponse = response;
        g_AS21_FlexRayLab.TxReady = 1U;
        g_AS21_FlexRayLab.WriteCount++;
        AS21_LabRxPending = FALSE;
    } else {
        g_AS21_FlexRayLab.ApiErrorCount++;
    }
}

void AS21_FlexRayLab_TxNotification(void)
{
    g_AS21_FlexRayLab.TxConfirmedCount++;
}
