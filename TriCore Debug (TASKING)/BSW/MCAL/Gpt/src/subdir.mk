################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/MCAL/Gpt/src/Gpt.c" 

COMPILED_SRCS += \
"BSW/MCAL/Gpt/src/Gpt.src" 

C_DEPS += \
"./BSW/MCAL/Gpt/src/Gpt.d" 

OBJS += \
"BSW/MCAL/Gpt/src/Gpt.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/MCAL/Gpt/src/Gpt.src":"../BSW/MCAL/Gpt/src/Gpt.c" "BSW/MCAL/Gpt/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/MCAL/Gpt/src/Gpt.o":"BSW/MCAL/Gpt/src/Gpt.src" "BSW/MCAL/Gpt/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-MCAL-2f-Gpt-2f-src

clean-BSW-2f-MCAL-2f-Gpt-2f-src:
	-$(RM) ./BSW/MCAL/Gpt/src/Gpt.d ./BSW/MCAL/Gpt/src/Gpt.o ./BSW/MCAL/Gpt/src/Gpt.src

.PHONY: clean-BSW-2f-MCAL-2f-Gpt-2f-src

