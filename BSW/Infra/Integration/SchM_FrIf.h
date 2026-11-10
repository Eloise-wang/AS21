#ifndef AS21_SCHM_FRIF_H
#define AS21_SCHM_FRIF_H
/* MCAL defines NOP() unconditionally; iLLD defines NOP only if absent.
 * Load MCAL first, as the existing AS21_McalInit.c integration does. */
#include "Mcal_Compiler.h"
#include "IfxCpu.h"
/* CPU0-only FrIf integration; preserve the caller interrupt state. */
static boolean AS21_FrIf_IrqState;
static uint32 AS21_FrIf_LockDepth;
static inline void SchM_Enter_FrIf_EA_0(void)
{
    boolean previous = IfxCpu_disableInterrupts();
    if (AS21_FrIf_LockDepth == 0U) AS21_FrIf_IrqState = previous;
    AS21_FrIf_LockDepth++;
}
static inline void SchM_Exit_FrIf_EA_0(void)
{
    if (AS21_FrIf_LockDepth != 0U) {
        AS21_FrIf_LockDepth--;
        if (AS21_FrIf_LockDepth == 0U) IfxCpu_restoreInterrupts(AS21_FrIf_IrqState);
    }
}
#endif
