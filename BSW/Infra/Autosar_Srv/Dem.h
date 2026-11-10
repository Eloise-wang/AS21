/*******************************************************************************
**                                                                            **
**  FILENAME     : Dem.h                                                      **
**                                                                            **
**  DESCRIPTION  : Dem Driver header definition file (stub for Fr module)     **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dem, AUTOSAR Release 4.2.2            **
**                                                                            **
**  MAY BE CHANGED BY USER : yes                                              **
**                                                                            **
*******************************************************************************/

#ifndef _DEM_H
#define _DEM_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define DEM_AR_RELEASE_MAJOR_VERSION 4U
#define DEM_AR_RELEASE_MINOR_VERSION 2U

#define DEM_EVENT_STATUS_PASSED    ((Dem_EventStatusType)0x00U)
#define DEM_EVENT_STATUS_FAILED    ((Dem_EventStatusType)0x01U)
#define DEM_EVENT_STATUS_PREPASSED ((Dem_EventStatusType)0x02U)
#define DEM_EVENT_STATUS_PREFAILED ((Dem_EventStatusType)0x03U)

/* Dem 配置事件 ID 符号（参照官方 Dem_cfg.h，工程未集成完整 Dem 模块时提供 stub）。
 * Fr_17_Eray_PBcfg.c 结构体 Fr_17_Eray_CCType 的 DemEventParamCtrlTestResult
 * 字段引用此符号；值取官方 TEST_APP/DEMO_APP 分支定义的 15U。 */
#define DemConf_DemEventParameter_FR_CTRL_TESTRESULT_ERROR          (15U)
#define DemConf_DemEventParameter_FR_CTRL_TIMEOUT_ERROR             (16U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef uint16 Dem_EventIdType;
typedef uint8  Dem_EventStatusType;

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern void Dem_ReportErrorStatus(Dem_EventIdType EventId,
                                  Dem_EventStatusType EventStatus);

#endif /* End of _DEM_H */
