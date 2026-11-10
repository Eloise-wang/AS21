---
ssat_md: "2.0.0"
id: "SSAT-OVW-AS21-0002"
id_status: "proposed"
title: "AS21 双 E-Ray 软件实施计划"
description: "记录无 VN7610 实验的软件实现步骤、验证方法和暂缓处理的硬件适配边界。"
doc_class: "knowledge"
doc_type: "overview"
status: "draft"
owner: "TBD"
owner_status: "unconfirmed"
classification: "internal"
language: "zh-CN"
created_date: "2026-11-09"
updated_date: "2026-11-09"
---

# AS21 双 E-Ray 软件实施计划

## 1. 目标与边界

依据 [双 E-Ray 方案](as21_dual_eray_test_design.md)，实施 Slot5/20 独立启动同步、Slot11 请求和 Slot17 完整栈响应。用户已要求先完成软件；本轮不修改 Port 引脚配置、不确定物理接线、不宣称实板已通过。

使用 writing-plans、executing-plans 和测试驱动流程。工程没有 Git 仓库，在当前工程定点修改，修改前文件保存在 `tmp/dual_eray_before`；不创建或提交 Git 历史。

## 2. 实施任务与验证

- [x] 编写失败用例：启动帧配置、双控制器初始化与预装载、允许冷启动失败、状态异常、超时和新响应校验。验证：先在现有代码上出现预期失败。
- [x] 修改 `Generated/MCAL/src/Fr_17_Eray_PBcfg.c`：E-Ray0 LPDU0 改为 Slot20，交换 LPDU0/40 的 MB0/1 映射，更新控制器参数和 CRC；两端启动帧持续模式。验证：独立 CRC 算法、数组与消息 RAM 检查。
- [x] 修改 `AS21_Communication.h/.inc`：双节点启动状态、有限等待、500 ms 启动超时、200 ms 恢复退避、离线清理和控制器重新初始化。保留 E-Ray0 的 FrIf/PduR/Com 路径。验证：真实集成代码配模拟 MCAL，测试成功与错误路径。
- [x] 新增 `APPS/main/AS21_FlexRayPeer.h/.inc`，接入 `Cpu0_Main.c`：默认手动单笔请求，可选自动请求；仅控制器1直接使用 MCAL；100 ms 响应超时，校验新数据、长度和全负载。验证：正常值、重复值、错误长度、错值、提交失败、超时及会话切换。
- [x] 新建 `docs/AS21_DualEray_Lab.xml`：两个实验节点和四个静态帧，沿用现有集群参数、PDU 和信号布局。验证：XML 引用完整性及与 C 配置一致性。
- [x] 执行目标 GCC 语法和接口检查、主机行为测试及独立代码审阅；记录结果和未完成的 TASKING/实板验证。

## 3. 重点检查

- 启动 LPDU 独立于应用发送和确认，持续模式在 ControllerInit 前确定。
- 预装载必须等 MCAL 输入缓冲区完成，不能只检查接口 E_OK。
- 任一端异常时清除会话、停止业务和旧硬件请求，恢复不能误认旧响应。
- 主循环驱动调用与 FrIf Job 串行化；硬件等待使用有界轮询或分步检查。
- 首笔请求同时依赖双方 NORMAL_ACTIVE 和 E-Ray0 FrIf/Com 在线。
- E-Ray1 未处理的 IRQ 保持关闭，E-Ray0 Timer0 重启后可重新调度。

## 4. 决策与结果记录

按用户最新指示，硬件前提不再阻止软件实现；原方案中的 Pin/Port 与实际接线仍待后续讨论。Slot1 接收配置仅复用当前通信栈未引用的 LPDU0，不恢复 gateway。

本文件是知识草案，不表示正式注册、批准或发布。

已执行的结果：3项软件测试通过，覆盖配置、独立实验 FIBEX 以及真实 FrIf/PduR/Com 接模拟 MCAL 的行为；16个编译单元通过目标 GCC 语法和接口检查。独立代码审阅未发现需立即修正的确定性缺陷。

上述为删除前的验证记录；电脑端回归测试文件随后按用户要求删除，固件不依赖这些文件。当前不能直接重跑已删除的测试。

TASKING 命令行编译返回 F104，许可证要求通过 IDE 使用；完整 TASKING 编译链接待 ADS 验证。主机测试未模拟真实静态时隙的线速时序、异步输入缓冲区和真实中断；实板冷启动与总线闭环未验证。
