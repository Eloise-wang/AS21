################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/MCAL/Mcu/src/Mcu.c" \
"../BSW/MCAL/Mcu/src/Mcu_17_TimerIp.c" 

COMPILED_SRCS += \
"BSW/MCAL/Mcu/src/Mcu.src" \
"BSW/MCAL/Mcu/src/Mcu_17_TimerIp.src" 

C_DEPS += \
"./BSW/MCAL/Mcu/src/Mcu.d" \
"./BSW/MCAL/Mcu/src/Mcu_17_TimerIp.d" 

OBJS += \
"BSW/MCAL/Mcu/src/Mcu.o" \
"BSW/MCAL/Mcu/src/Mcu_17_TimerIp.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/MCAL/Mcu/src/Mcu.src":"../BSW/MCAL/Mcu/src/Mcu.c" "BSW/MCAL/Mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/MCAL/Mcu/src/Mcu.o":"BSW/MCAL/Mcu/src/Mcu.src" "BSW/MCAL/Mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/MCAL/Mcu/src/Mcu_17_TimerIp.src":"../BSW/MCAL/Mcu/src/Mcu_17_TimerIp.c" "BSW/MCAL/Mcu/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/MCAL/Mcu/src/Mcu_17_TimerIp.o":"BSW/MCAL/Mcu/src/Mcu_17_TimerIp.src" "BSW/MCAL/Mcu/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-MCAL-2f-Mcu-2f-src

clean-BSW-2f-MCAL-2f-Mcu-2f-src:
	-$(RM) ./BSW/MCAL/Mcu/src/Mcu.d ./BSW/MCAL/Mcu/src/Mcu.o ./BSW/MCAL/Mcu/src/Mcu.src ./BSW/MCAL/Mcu/src/Mcu_17_TimerIp.d ./BSW/MCAL/Mcu/src/Mcu_17_TimerIp.o ./BSW/MCAL/Mcu/src/Mcu_17_TimerIp.src

.PHONY: clean-BSW-2f-MCAL-2f-Mcu-2f-src

