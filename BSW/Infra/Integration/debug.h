#ifndef AS21_DEBUG_COMPAT_H
#define AS21_DEBUG_COMPAT_H
/* Optional upstream text logging is disabled. Arguments are not evaluated. */
#define DEBUG_LOW 0U
#define DEBUG(_level, ...) ((void)0)
#define LDEBUG_PRINTF(...) ((void)0)
#endif
