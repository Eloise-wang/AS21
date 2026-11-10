#ifndef AS21_COMMUNICATION_H
#define AS21_COMMUNICATION_H
#include "Std_Types.h"
#include "ComStack_Types.h"

/* Values exposed to the debugger; hardware POC codes use a different enum. */
#define AS21_COMM_RETRY 0U
#define AS21_COMM_PRIMING 1U
#define AS21_COMM_STARTING 2U
#define AS21_COMM_RUNNING 3U
typedef struct {
    uint8 PocState;
    Std_ReturnType InitResult;
    Std_ReturnType PrimeResult;
    Std_ReturnType ColdstartResult;
    Std_ReturnType StartResult;
    Std_ReturnType PocResult;
    Std_ReturnType AbortResult;
} AS21_CommunicationControllerDiagType;

typedef struct {
    uint32 SupervisorCount;
    uint32 ControllerInitCount;
    uint32 StartAttemptCount;
    uint32 PocErrorCount;
    uint32 TimerIrqCount;
    uint32 JobCallCount;
    uint32 RxCount;
    uint32 RxRejectedCount;
    uint32 TxTriggerCount;
    uint32 TxTriggerErrorCount;
    uint32 TxConfirmationCount;
    uint8 Initialized;
    uint8 Online;
    uint8 PocState;
    Std_ReturnType ControllerInitResult;
    Std_ReturnType StartResult;
    Std_ReturnType PocResult;
    Std_ReturnType StateResult;
    uint8 LastRxData[64];
    AS21_CommunicationControllerDiagType Controller[2];
    uint32 RecoveryCount;
    uint32 StartupTimeoutCount;
    uint32 SessionCount;
    uint8 Stage;
    uint8 LastFailureStage;
    uint8 LastFailureController;
} AS21_CommunicationDiagType;

extern volatile AS21_CommunicationDiagType g_AS21_Communication;
/* CPU0 only: Init once after AS21_McalInit, Process from the main loop. */
void AS21_Communication_Init(void);
void AS21_Communication_Process(void);
void AS21_Communication_TimerIsr(void);
/* FrIf-to-PduR bindings, with payload validation and RAM observation. */
void AS21_Communication_RxIndication(PduIdType pduId, PduInfoType *pduInfo);
Std_ReturnType AS21_Communication_TriggerTransmit(PduIdType pduId, PduInfoType *pduInfo);
void AS21_Communication_TxConfirmation(PduIdType pduId);
#endif
