################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../tmp/dual_eray_before/Cpu0_Main.c" 

COMPILED_SRCS += \
"tmp/dual_eray_before/Cpu0_Main.src" 

C_DEPS += \
"./tmp/dual_eray_before/Cpu0_Main.d" 

OBJS += \
"tmp/dual_eray_before/Cpu0_Main.o" 


# Each subdirectory must supply rules for building sources it contributes
"tmp/dual_eray_before/Cpu0_Main.src":"../tmp/dual_eray_before/Cpu0_Main.c" "tmp/dual_eray_before/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"tmp/dual_eray_before/Cpu0_Main.o":"tmp/dual_eray_before/Cpu0_Main.src" "tmp/dual_eray_before/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-tmp-2f-dual_eray_before

clean-tmp-2f-dual_eray_before:
	-$(RM) ./tmp/dual_eray_before/Cpu0_Main.d ./tmp/dual_eray_before/Cpu0_Main.o ./tmp/dual_eray_before/Cpu0_Main.src

.PHONY: clean-tmp-2f-dual_eray_before

