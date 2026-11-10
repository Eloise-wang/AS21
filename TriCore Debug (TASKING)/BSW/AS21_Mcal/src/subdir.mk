################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/AS21_Mcal/src/AS21_McalInit.c" 

COMPILED_SRCS += \
"BSW/AS21_Mcal/src/AS21_McalInit.src" 

C_DEPS += \
"./BSW/AS21_Mcal/src/AS21_McalInit.d" 

OBJS += \
"BSW/AS21_Mcal/src/AS21_McalInit.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/AS21_Mcal/src/AS21_McalInit.src":"../BSW/AS21_Mcal/src/AS21_McalInit.c" "BSW/AS21_Mcal/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/AS21_Mcal/src/AS21_McalInit.o":"BSW/AS21_Mcal/src/AS21_McalInit.src" "BSW/AS21_Mcal/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-AS21_Mcal-2f-src

clean-BSW-2f-AS21_Mcal-2f-src:
	-$(RM) ./BSW/AS21_Mcal/src/AS21_McalInit.d ./BSW/AS21_Mcal/src/AS21_McalInit.o ./BSW/AS21_Mcal/src/AS21_McalInit.src

.PHONY: clean-BSW-2f-AS21_Mcal-2f-src

