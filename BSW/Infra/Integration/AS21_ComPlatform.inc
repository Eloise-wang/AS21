/* Compiled once by the existing IFX_Os.c integration translation unit. */
#include "AS21_ComPlatform.h"
#include "Mcal_Compiler.h"
#include "IfxCpu.h"
volatile uint32 g_ComPlatform_AssertCount;
volatile uint32 g_ComPlatform_AssertLine;
const char * volatile g_ComPlatform_AssertFile;
const char * volatile g_ComPlatform_AssertExpression;
volatile uint32 g_ComPlatform_LockErrorCount;
static uint32 AS21_ComPlatform_Depth;
static boolean AS21_ComPlatform_PreviousIrq;
void AS21_ComPlatform_Enter(void)
{
    boolean previous = IfxCpu_disableInterrupts();
    if (AS21_ComPlatform_Depth == 0U) AS21_ComPlatform_PreviousIrq = previous;
    AS21_ComPlatform_Depth++;
}
void AS21_ComPlatform_Exit(void)
{
    if (AS21_ComPlatform_Depth == 0U) {
        g_ComPlatform_LockErrorCount++;
        return;
    }
    AS21_ComPlatform_Depth--;
    if (AS21_ComPlatform_Depth == 0U) IfxCpu_restoreInterrupts(AS21_ComPlatform_PreviousIrq);
}
void AS21_ComPlatform_Assert(const char *expression, const char *file, uint32 line)
{
    (void)IfxCpu_disableInterrupts();
    g_ComPlatform_AssertExpression = expression;
    g_ComPlatform_AssertFile = file;
    g_ComPlatform_AssertLine = line;
    g_ComPlatform_AssertCount++;
    /* Fail-stop: retain the failed invariant for the debugger, never continue. */
    for (;;) { __nop(); }
}
