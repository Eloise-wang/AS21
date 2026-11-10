################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Infra/Autosar_Srv/Dem.c" \
"../BSW/Infra/Autosar_Srv/Det.c" \
"../BSW/Infra/Autosar_Srv/Mcal_SafetyError.c" 

COMPILED_SRCS += \
"BSW/Infra/Autosar_Srv/Dem.src" \
"BSW/Infra/Autosar_Srv/Det.src" \
"BSW/Infra/Autosar_Srv/Mcal_SafetyError.src" 

C_DEPS += \
"./BSW/Infra/Autosar_Srv/Dem.d" \
"./BSW/Infra/Autosar_Srv/Det.d" \
"./BSW/Infra/Autosar_Srv/Mcal_SafetyError.d" 

OBJS += \
"BSW/Infra/Autosar_Srv/Dem.o" \
"BSW/Infra/Autosar_Srv/Det.o" \
"BSW/Infra/Autosar_Srv/Mcal_SafetyError.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Infra/Autosar_Srv/Dem.src":"../BSW/Infra/Autosar_Srv/Dem.c" "BSW/Infra/Autosar_Srv/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Autosar_Srv/Dem.o":"BSW/Infra/Autosar_Srv/Dem.src" "BSW/Infra/Autosar_Srv/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Infra/Autosar_Srv/Det.src":"../BSW/Infra/Autosar_Srv/Det.c" "BSW/Infra/Autosar_Srv/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Autosar_Srv/Det.o":"BSW/Infra/Autosar_Srv/Det.src" "BSW/Infra/Autosar_Srv/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Infra/Autosar_Srv/Mcal_SafetyError.src":"../BSW/Infra/Autosar_Srv/Mcal_SafetyError.c" "BSW/Infra/Autosar_Srv/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Autosar_Srv/Mcal_SafetyError.o":"BSW/Infra/Autosar_Srv/Mcal_SafetyError.src" "BSW/Infra/Autosar_Srv/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Infra-2f-Autosar_Srv

clean-BSW-2f-Infra-2f-Autosar_Srv:
	-$(RM) ./BSW/Infra/Autosar_Srv/Dem.d ./BSW/Infra/Autosar_Srv/Dem.o ./BSW/Infra/Autosar_Srv/Dem.src ./BSW/Infra/Autosar_Srv/Det.d ./BSW/Infra/Autosar_Srv/Det.o ./BSW/Infra/Autosar_Srv/Det.src ./BSW/Infra/Autosar_Srv/Mcal_SafetyError.d ./BSW/Infra/Autosar_Srv/Mcal_SafetyError.o ./BSW/Infra/Autosar_Srv/Mcal_SafetyError.src

.PHONY: clean-BSW-2f-Infra-2f-Autosar_Srv

