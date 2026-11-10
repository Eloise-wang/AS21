---
ssat_md: "2.0.0"
id: "SSAT-GDE-AS21-0001"
id_status: "proposed"
title: "AS21 双 E-Ray 调试器观察与测试操作指南"
description: "说明双 E-Ray 实验中如何观察 RAM 变量、手动发送请求、判断收发结果，并在异常时检查必要寄存器。"
doc_class: "knowledge"
doc_type: "guide"
status: "draft"
owner: "TBD"
owner_status: "unconfirmed"
classification: "internal"
language: "zh-CN"
created_date: "2026-11-09"
updated_date: "2026-11-09"
source_refs:
  - "BSW/Infra/Integration/AS21_Communication.h"
  - "BSW/Infra/Integration/AS21_Communication.inc"
  - "APPS/main/AS21_FlexRayPeer.h"
  - "APPS/main/AS21_FlexRayPeer.inc"
  - "APPS/main/AS21_FlexRayLab.h"
tags:
  - "project/as21"
  - "type/debugging"
---

# AS21 双 E-Ray 调试器观察与测试操作指南

## 1. 先记住这三件事

1. **正常测试先看变量，不需要盯着一堆寄存器。** 调试器按变量名显示的内容，就是程序保存在 RAM 里的数据。
2. **先手动发送一笔，再查看保留的结果。** 最近一次收发值不会像周期计数那样一直变化；不要一开始就打开自动模式。
3. **只有启动失败或收发异常时，才展开对应诊断和寄存器。** 不需要逐层打断点。

本指南对应当前无 VN7610 的双 E-Ray 软件：E-Ray1 发 Slot11 请求，E-Ray0 经过完整通信栈处理，通过 Slot17 返回；两端分别用 Slot5、Slot20 启动/同步。

> **测试前提：** 固件已在 ADS 编译、下载，且两端实际收发器、引脚和总线连接满足实验条件。当前 Port 与接线仍待确认；本指南不是实板已经跑通的证明。若没有形成有效总线，不应期待 Stage 自动进入3。

## 2. 打开哪个窗口，怎么看 RAM

### 2.1 三类窗口的用途

| 窗口或功能 | 你要做什么 | 本次使用顺序 |
|---|---|---|
| Variables / Expressions，全局变量或表达式观察 | 输入变量名、展开结构体、查看数值；支持时可以修改指定控制变量 | 首先使用 |
| Registers / SFR，寄存器观察 | 选择 E-Ray0、E-Ray1，查看控制器状态 | 启动异常时使用 |
| Memory，内存观察 | 按地址显示原始字节 | 初次测试不需要 |
| FSS，调试器文本输出 | 查看已配置的调试器打印 | 当前代码未配置，不作为本指南前提 |

ADS中的具体窗口名称和按钮取决于所选调试器。常见入口是 `Window → Show View → Other`；在实际会话中寻找变量、表达式或寄存器窗口，不要把普通构建 Console 当成固件运行日志。

### 2.2 添加两个结构体即可

在变量或表达式观察窗口添加：

```text
g_AS21_Communication
g_AS21_FlexRayPeer
```

通过展开符号查看其中的成员。如果当前变量窗口只显示局部变量，使用该调试器的“添加全局变量”或“添加表达式”功能。**不需要知道变量的 RAM 地址。**

请使用与当前板上固件匹配的 ELF 调试符号。若提示变量不存在或无法求值，先检查符号是否加载、是否选中了正确调试目标；不能把“无法读取”当作数值0。

### 2.3 保持程序运行

确认当前调试器支持并已开启运行中读取，例如 Live Variables 或相应实时刷新功能。刷新周期可先使用200～500 ms，避免过度刷新大量数据。

**不能假定普通 Watch 窗口一定能无暂停读取。** 若只有暂停后才能读写，先确认工具能力，不要为观察和触发请求反复停住 CPU。此时可另行改用程序自动触发或日志方案，本指南不要求强行暂停。

数值显示可设置为十六进制。`0x12`等于十进制18，`0xED`等于十进制237；显示成18或237并不是数据错误。

## 3. 正常测试时只看这几项

### 3.1 先确认具备发送条件

| 完整变量名 | 发送前应观察到的值 | 含义 |
|---|---|---|
| `g_AS21_Communication.Stage` | 3 | 软件处于正常通信阶段 |
| `g_AS21_FlexRayPeer.Online` | 1 | E-Ray1测试端已允许工作 |
| `g_AS21_FlexRayPeer.Pending` | 0 | 没有尚未完成的请求 |

这里只观察，**不要手工把 Stage、Online 或 Pending 改成期望值**。它们是程序的真实状态，强改会掩盖问题。

`Initialized=1`只说明软件初始化路径已执行，不等于网络已启动。

### 3.2 收发结果观察表

| 完整变量名 | 怎么看 |
|---|---|
| `g_AS21_FlexRayPeer.LastRequest` | 最近一次提交的请求值 |
| `g_AS21_FlexRayPeer.LastResponse[0]` | 最近一次收到的响应第一个字节 |
| `g_AS21_FlexRayPeer.MatchCount` | 正确响应累计次数；一笔成功应比发送前增加1 |
| `g_AS21_FlexRayPeer.TimeoutCount` | 超时累计次数；本笔正常测试不应增加 |
| `g_AS21_FlexRayPeer.MismatchCount` | 响应内容或长度不符的累计次数；本笔不应增加 |
| `g_AS21_FlexRayPeer.ApiErrorCount` | 测试端MCAL接口错误累计次数；本笔不应增加 |

**计数看增量，不只看是否为0。** 之前发生过错误，恢复后旧错误计数仍保留；应比较本次发送前后是否增加。

正常时不必一直展开整个结构体，更不需要持续刷新64个响应字节。

## 4. 手动发送第一笔请求

### 4.1 发送前记录基线

确认第3.1节三个状态满足条件，再记下当前 MatchCount、TimeoutCount、MismatchCount、ApiErrorCount。可以截图，不需要抄下所有变量。

### 4.2 只修改三个控制变量

在变量的 Value 列修改，下表是变量写入操作，**不是在串口或构建控制台输入命令**。

| 顺序 | 完整变量名 | 写入值 | 说明 |
|---|---|---|---|
| 1 | `g_AS21_FlexRayPeer.AutoMode` | 0 | 保持手动模式 |
| 2 | `g_AS21_FlexRayPeer.RequestValue` | `0x12`，或十进制18 | 设置请求信号 |
| 3 | `g_AS21_FlexRayPeer.SendRequest` | 1 | 通知程序提交一次请求 |

`SendRequest`会被程序迅速清回0，**这是正常行为，不是没有发送**。下一笔请求也通过重新写1触发。

### 4.3 等待一次刷新，判断结果

正常结果如下，计数以发送前的值为基线：

| 观察项 | 预期 |
|---|---|
| LastRequest | `0x12` |
| LastResponse[0] | `0xED` |
| MatchCount | 增加1 |
| TimeoutCount / MismatchCount / ApiErrorCount | 均不增加 |
| Pending | 最终回到0 |

软件请求期限为100 ms，界面200～500 ms才刷新一次也可以看到保留的最终结果。界面刷新慢，不表示通信耗时这么长。

**只看到 `0xED` 不足以证明本次成功。** 它可能是上一次保留的内容；需要MatchCount本次确实增加。失败恢复期间，Pending也可能回到0，因此Pending为0不能单独作为成功证据。

如果需要进一步确认完整栈，本笔成功后再展开：

```text
g_AS21_FlexRayLab.ReadCount
g_AS21_FlexRayLab.WriteCount
g_AS21_Communication.TxTriggerCount
g_AS21_Communication.TxConfirmationCount
```

在隔离的单笔正常实验中，这些计数应相应增加；发送确认可能晚于Peer收到响应，到下一次调度后再观察。不要要求所有窗口在同一次刷新中同时变化。

## 5. 启动不成功时才查看这些寄存器

### 5.1 先看软件启动阶段

| Stage值 | 含义 | 优先展开的诊断 |
|---|---|---|
| 0 | 等待重试 | LastFailureStage、LastFailureController、RecoveryCount |
| 1 | 等待两个启动帧预装载完成 | Controller[0/1].PrimeResult、StartupTimeoutCount |
| 2 | 已请求启动，等待网络正常 | Controller[0/1].PocState、ColdstartResult、StartResult |
| 3 | 正常运行 | 按第4节测试 |

Stage1可能非常短，界面没有捕捉到它也正常；失败原因可看保留下来的LastFailureStage。

`Controller[0]`表示E-Ray0，`Controller[1]`表示E-Ray1。接口返回值0表示E_OK；1表示E_NOT_OK，但初始化时尚未尝试的接口也会先显示1，须结合Stage判断。

LastFailureController为0或1表示对应控制器，为2表示双方预装载检查或启动等待超时。LastFailureStage=0也可能是恢复过程中再次失败，不应把它解释为某个具体驱动接口编号。

### 5.2 两个优先查看的硬件状态字段

在调试器寄存器树中找到ERAY0、ERAY1，展开CCSV，查看POCS。若表达式支持SFR宏，也可使用下列名字；无法求值时请改用寄存器树，不要猜地址。

| 硬件字段 | 正常通信的值 |
|---|---|
| `ERAY0_CCSV.B.POCS` | 2，即NORMAL_ACTIVE |
| `ERAY1_CCSV.B.POCS` | 2，即NORMAL_ACTIVE |

**硬件POCS正常值为2，软件Controller[].PocState正常值为3，二者编码不同。**

软件PocState常见值：3=正常活动、4=正常被动、5=READY、6=STARTUP、2=HALT。不要拿软件值直接套用到寄存器。

### 5.3 必要时再看周期计数

```text
ERAY0_MTCCV.B.CCV
ERAY1_MTCCV.B.CCV
```

它们是0～63的循环计数，一直变化是正常现象，不需要记住每个值。人工只用于辅助判断周期是否在运行；两端的读取时间不同，截图中的数值不完全相同也不能单独判为不同步。

不需要手动操作输入/输出缓冲区寄存器来取信号，不写控制寄存器、不清中断或新数据标志，避免干扰MCAL。

## 6. 收发异常时按层展开

| 现象 | 下一步只看这些项目 | 如何缩小范围 |
|---|---|---|
| 写了SendRequest但没有请求 | Peer.RequestCount、SendResult、Online、Pending | RequestCount是否增加；接口提交失败会计ApiError |
| 请求已提交但对端没收到 | Peer.TxCompletedCount；Communication.RxCount、RxRejectedCount | 提交成功不等于线上发送，先区分发送完成与E-Ray0接收 |
| E-Ray0收到但应用没有处理 | Lab.RxNotificationCount、ReadCount、ApiErrorCount | 检查PduR/Com通知和应用读信号 |
| 应用处理后没有响应 | Lab.WriteCount；Communication.TxTriggerCount、TxTriggerErrorCount、TxConfirmationCount | 区分Com写入、FrIf取数据和发送确认 |
| 有响应但MatchCount不增加 | Peer.LastLength、LastResponse[0]、MismatchCount、TimeoutCount | 长度应64，Byte0应取反，其余63字节为0；100 ms后不算成功 |
| 运行后反复掉线 | Communication.RecoveryCount、LastFailureStage、LastFailureController；两端PocState | 先记录故障阶段和端，不在实时通信中逐层打断点 |

表中的Peer、Lab、Communication分别是前文三个 `g_AS21_...` 结构体的简称。只有排查相应现象时才展开，不要求把整张表同时加入观察窗口。

遇到重复同值请求，可以再次发送 `0x12`。它仍应触发新的一笔请求，以本次MatchCount增量判断，不能只看响应字节是否变化。

## 7. 自动模式、打印和提供现场信息

### 7.1 第一笔成功后再自动测试

将 `g_AS21_FlexRayPeer.AutoMode` 设为1。程序按不小于100 ms的间隔，依次使用 `0x12`、`0x00`、`0x80`、`0xFF`，最多保持一个未完成请求。

此时只需关注Stage稳定为3、MatchCount持续增长、三个错误计数没有新增长。界面一次刷新可能跳过多个结果，属于正常现象。

设回AutoMode=0后，不再自动提交新请求，已经提交的一笔仍会完成或超时。需要稳定截图时先关闭自动模式、等待当前请求结束，**不要为了冻结画面停CPU**。

### 7.2 当前不用控制台打印也能测试

当前固件没有加入FSS输出。普通Console中的编译成功信息不是固件运行日志；RAM结果查看不需要printf，也不需要串口配置。

若后续增加调试器文本打印，必须先确认调试器支持FSS，并验证输出对执行时间的影响；不在E-Ray ISR、通信临界区或每周期调度中直接打印。本指南不要求先实现打印才能开始测试。

### 7.3 给助手看什么

正常单笔测试，提供一张包含以下内容的截图即可：

```text
Communication.Stage
Peer.LastRequest
Peer.LastResponse[0]
Peer.MatchCount
Peer.TimeoutCount
Peer.MismatchCount
Peer.ApiErrorCount
```

同时说明发送前MatchCount是多少、是否使用自动模式。上面是缩写清单，实际变量名按第3节输入。

若启动不成功，改为截图Stage、LastFailureStage、LastFailureController，以及Controller[0]和[1]，说明是否已经接好实验总线。不需要录下每一次周期计数变化。

调试器运行中读取多个变量不是一次原子快照；手动单笔结束后查看更稳定。不要把一次跨时刻刷新的小差异直接当成通信异常。

## 8. 适用性和来源

本指南是待实板核对的知识草案。Document ID为提议值，Owner未确认；没有宣称企业注册、正式审批或完整SSAT发布验收通过。格式参照 [SSAT-STD-DOC-0001](ssat_md_mermaid_standard_v2.0.0.md)。

变量名称、状态和操作依据当前源码：

- [通信状态与诊断定义](../BSW/Infra/Integration/AS21_Communication.h)、[启动及调度实现](../BSW/Infra/Integration/AS21_Communication.inc)。
- [测试端变量定义](../APPS/main/AS21_FlexRayPeer.h)、[请求及响应处理](../APPS/main/AS21_FlexRayPeer.inc)。
- [应用层诊断定义](../APPS/main/AS21_FlexRayLab.h)。
- [软件POC枚举](../BSW/Infra/Platform/Fr_GeneralTypes.h)、[MCAL硬件POC编码](../BSW/MCAL/Fr/src/Fr_17_Eray.c)。
- [双E-Ray软件实施记录](as21_dual_eray_implementation_plan.md)。

本文件仅新增操作说明，没有修改固件、寄存器或调试会话。
