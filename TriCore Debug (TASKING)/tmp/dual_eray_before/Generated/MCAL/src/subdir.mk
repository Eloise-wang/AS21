################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.c" 

COMPILED_SRCS += \
"tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.src" 

C_DEPS += \
"./tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.d" 

OBJS += \
"tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.o" 


# Each subdirectory must supply rules for building sources it contributes
"tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.src":"../tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.c" "tmp/dual_eray_before/Generated/MCAL/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.o":"tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.src" "tmp/dual_eray_before/Generated/MCAL/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-tmp-2f-dual_eray_before-2f-Generated-2f-MCAL-2f-src

clean-tmp-2f-dual_eray_before-2f-Generated-2f-MCAL-2f-src:
	-$(RM) ./tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.d ./tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.o ./tmp/dual_eray_before/Generated/MCAL/src/Fr_17_Eray_PBcfg.src

.PHONY: clean-tmp-2f-dual_eray_before-2f-Generated-2f-MCAL-2f-src

