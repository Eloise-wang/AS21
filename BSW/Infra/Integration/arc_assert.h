#ifndef AS21_ARC_ASSERT_H
#define AS21_ARC_ASSERT_H
#include "AS21_ComPlatform.h"
#define ASSERT(_condition) do { if (!(_condition)) { AS21_ComPlatform_Assert(#_condition, __FILE__, (uint32)__LINE__); } } while (0)
#define CONFIG_ASSERT(_condition) ASSERT(_condition)
#endif
