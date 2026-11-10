################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Generated/MCAL/src/Dio_Lcfg.c" \
"../Generated/MCAL/src/Fr_17_Eray_PBcfg.c" \
"../Generated/MCAL/src/Gpt_PBcfg.c" \
"../Generated/MCAL/src/Mcu_17_TimerIp_Cfg.c" \
"../Generated/MCAL/src/Mcu_PBcfg.c" \
"../Generated/MCAL/src/Port_PBcfg.c" 

COMPILED_SRCS += \
"Generated/MCAL/src/Dio_Lcfg.src" \
"Generated/MCAL/src/Fr_17_Eray_PBcfg.src" \
"Generated/MCAL/src/Gpt_PBcfg.src" \
"Generated/MCAL/src/Mcu_17_TimerIp_Cfg.src" \
"Generated/MCAL/src/Mcu_PBcfg.src" \
"Generated/MCAL/src/Port_PBcfg.src" 

C_DEPS += \
"./Generated/MCAL/src/Dio_Lcfg.d" \
"./Generated/MCAL/src/Fr_17_Eray_PBcfg.d" \
"./Generated/MCAL/src/Gpt_PBcfg.d" \
"./Generated/MCAL/src/Mcu_17_TimerIp_Cfg.d" \
"./Generated/MCAL/src/Mcu_PBcfg.d" \
"./Generated/MCAL/src/Port_PBcfg.d" 

OBJS += \
"Generated/MCAL/src/Dio_Lcfg.o" \
"Generated/MCAL/src/Fr_17_Eray_PBcfg.o" \
"Generated/MCAL/src/Gpt_PBcfg.o" \
"Generated/MCAL/src/Mcu_17_TimerIp_Cfg.o" \
"Generated/MCAL/src/Mcu_PBcfg.o" \
"Generated/MCAL/src/Port_PBcfg.o" 


# Each subdirectory must supply rules for building sources it contributes
"Generated/MCAL/src/Dio_Lcfg.src":"../Generated/MCAL/src/Dio_Lcfg.c" "Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Generated/MCAL/src/Dio_Lcfg.o":"Generated/MCAL/src/Dio_Lcfg.src" "Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Generated/MCAL/src/Fr_17_Eray_PBcfg.src":"../Generated/MCAL/src/Fr_17_Eray_PBcfg.c" "Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Generated/MCAL/src/Fr_17_Eray_PBcfg.o":"Generated/MCAL/src/Fr_17_Eray_PBcfg.src" "Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Generated/MCAL/src/Gpt_PBcfg.src":"../Generated/MCAL/src/Gpt_PBcfg.c" "Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Generated/MCAL/src/Gpt_PBcfg.o":"Generated/MCAL/src/Gpt_PBcfg.src" "Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Generated/MCAL/src/Mcu_17_TimerIp_Cfg.src":"../Generated/MCAL/src/Mcu_17_TimerIp_Cfg.c" "Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Generated/MCAL/src/Mcu_17_TimerIp_Cfg.o":"Generated/MCAL/src/Mcu_17_TimerIp_Cfg.src" "Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Generated/MCAL/src/Mcu_PBcfg.src":"../Generated/MCAL/src/Mcu_PBcfg.c" "Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Generated/MCAL/src/Mcu_PBcfg.o":"Generated/MCAL/src/Mcu_PBcfg.src" "Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"Generated/MCAL/src/Port_PBcfg.src":"../Generated/MCAL/src/Port_PBcfg.c" "Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Generated/MCAL/src/Port_PBcfg.o":"Generated/MCAL/src/Port_PBcfg.src" "Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Generated-2f-MCAL-2f-src

clean-Generated-2f-MCAL-2f-src:
	-$(RM) ./Generated/MCAL/src/Dio_Lcfg.d ./Generated/MCAL/src/Dio_Lcfg.o ./Generated/MCAL/src/Dio_Lcfg.src ./Generated/MCAL/src/Fr_17_Eray_PBcfg.d ./Generated/MCAL/src/Fr_17_Eray_PBcfg.o ./Generated/MCAL/src/Fr_17_Eray_PBcfg.src ./Generated/MCAL/src/Gpt_PBcfg.d ./Generated/MCAL/src/Gpt_PBcfg.o ./Generated/MCAL/src/Gpt_PBcfg.src ./Generated/MCAL/src/Mcu_17_TimerIp_Cfg.d ./Generated/MCAL/src/Mcu_17_TimerIp_Cfg.o ./Generated/MCAL/src/Mcu_17_TimerIp_Cfg.src ./Generated/MCAL/src/Mcu_PBcfg.d ./Generated/MCAL/src/Mcu_PBcfg.o ./Generated/MCAL/src/Mcu_PBcfg.src ./Generated/MCAL/src/Port_PBcfg.d ./Generated/MCAL/src/Port_PBcfg.o ./Generated/MCAL/src/Port_PBcfg.src

.PHONY: clean-Generated-2f-MCAL-2f-src

