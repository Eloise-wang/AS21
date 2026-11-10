#ifndef AS21_FLEXRAY_PEER_H
#define AS21_FLEXRAY_PEER_H
#include "Std_Types.h"

typedef struct {
    uint32 RequestCount;
    uint32 TxCompletedCount;
    uint32 RxCount;
    uint32 MatchCount;
    uint32 MismatchCount;
    uint32 TimeoutCount;
    uint32 ApiErrorCount;
    uint32 StaleRxCount;
    uint8 Online;
    uint8 Pending;
    uint8 RecoveryRequested;
    uint8 SendRequest; /* Debugger: set RequestValue, then write 1. */
    uint8 RequestValue;
    uint8 AutoMode; /* Debugger: 0=manual (default), 1=100ms test sequence. */
    uint8 LastRequest;
    uint8 ExpectedResponse;
    uint8 LastLength;
    uint8 LastResponse[64];
    Std_ReturnType SendResult;
    Std_ReturnType ReceiveResult;
    Std_ReturnType TxStatusResult;
} AS21_FlexRayPeerDiagType;
extern volatile AS21_FlexRayPeerDiagType g_AS21_FlexRayPeer;

void AS21_FlexRayPeer_Init(void);
/* CPU0, under the shared communication lock; nowMs is monotonic modulo 2^32. */
void AS21_FlexRayPeer_SetOnline(boolean online, uint32 nowMs);
void AS21_FlexRayPeer_Process(uint32 nowMs);
#endif
