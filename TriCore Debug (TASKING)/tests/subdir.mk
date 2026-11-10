################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../tests/dual_eray_runtime.c" 

COMPILED_SRCS += \
"tests/dual_eray_runtime.src" 

C_DEPS += \
"./tests/dual_eray_runtime.d" 

OBJS += \
"tests/dual_eray_runtime.o" 


# Each subdirectory must supply rules for building sources it contributes
"tests/dual_eray_runtime.src":"../tests/dual_eray_runtime.c" "tests/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"tests/dual_eray_runtime.o":"tests/dual_eray_runtime.src" "tests/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-tests

clean-tests:
	-$(RM) ./tests/dual_eray_runtime.d ./tests/dual_eray_runtime.o ./tests/dual_eray_runtime.src

.PHONY: clean-tests

