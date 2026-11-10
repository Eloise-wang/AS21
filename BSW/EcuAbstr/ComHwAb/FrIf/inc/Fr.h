#ifndef AS21_FRIF_DRIVER_ADAPTER_H
#define AS21_FRIF_DRIVER_ADAPTER_H
#include "Fr_17_Eray.h"
/* The core uses the configured driver API table. This service is called directly. */
#define Fr_GetChannelStatus Fr_17_Eray_GetChannelStatus
#define Fr_ReadCCConfig Fr_17_Eray_ReadCCConfig
#endif
