#ifndef AS21_COM_PLATFORM_H
#define AS21_COM_PLATFORM_H
#include "Std_Types.h"
extern volatile uint32 g_ComPlatform_AssertCount;
extern volatile uint32 g_ComPlatform_AssertLine;
extern const char * volatile g_ComPlatform_AssertFile;
extern const char * volatile g_ComPlatform_AssertExpression;
extern volatile uint32 g_ComPlatform_LockErrorCount;
/* CPU0 only; one shared nesting state for Com and PduR across source files. */
void AS21_ComPlatform_Enter(void);
void AS21_ComPlatform_Exit(void);
void AS21_ComPlatform_Assert(const char *expression, const char *file, uint32 line);
#endif
