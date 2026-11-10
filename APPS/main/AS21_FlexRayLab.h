#ifndef AS21_FLEXRAY_LAB_H
#define AS21_FLEXRAY_LAB_H
#include "Std_Types.h"

typedef struct {
    uint32 RxNotificationCount;
    uint32 ReadCount;
    uint32 WriteCount;
    uint32 ApiErrorCount;
    uint32 TxConfirmedCount;
    uint8 LastRequest;
    uint8 LastResponse;
    uint8 Online;
    uint8 TxReady;
    uint8 ReceiveResult;
    uint8 SendResult;
} AS21_FlexRayLabDiagType;
extern volatile AS21_FlexRayLabDiagType g_AS21_FlexRayLab;

void AS21_FlexRayLab_Init(void);
void AS21_FlexRayLab_SetOnline(boolean online);
void AS21_FlexRayLab_Process(void);
void AS21_FlexRayLab_RxNotification(void);
void AS21_FlexRayLab_TxNotification(void);
#endif
