################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Infra/Irq/src/Irq.c" 

COMPILED_SRCS += \
"BSW/Infra/Irq/src/Irq.src" 

C_DEPS += \
"./BSW/Infra/Irq/src/Irq.d" 

OBJS += \
"BSW/Infra/Irq/src/Irq.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Infra/Irq/src/Irq.src":"../BSW/Infra/Irq/src/Irq.c" "BSW/Infra/Irq/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Irq/src/Irq.o":"BSW/Infra/Irq/src/Irq.src" "BSW/Infra/Irq/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Infra-2f-Irq-2f-src

clean-BSW-2f-Infra-2f-Irq-2f-src:
	-$(RM) ./BSW/Infra/Irq/src/Irq.d ./BSW/Infra/Irq/src/Irq.o ./BSW/Infra/Irq/src/Irq.src

.PHONY: clean-BSW-2f-Infra-2f-Irq-2f-src

