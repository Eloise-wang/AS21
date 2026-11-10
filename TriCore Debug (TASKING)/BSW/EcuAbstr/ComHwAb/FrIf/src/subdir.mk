################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.c" \
"../BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.c" \
"../BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.c" 

COMPILED_SRCS += \
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.src" \
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.src" \
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.src" 

C_DEPS += \
"./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.d" \
"./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.d" \
"./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.d" 

OBJS += \
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.o" \
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.o" \
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.src":"../BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.c" "BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.o":"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.src" "BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.src":"../BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.c" "BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.o":"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.src" "BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.src":"../BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.c" "BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.o":"BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.src" "BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-EcuAbstr-2f-ComHwAb-2f-FrIf-2f-src

clean-BSW-2f-EcuAbstr-2f-ComHwAb-2f-FrIf-2f-src:
	-$(RM) ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.d ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.o ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf.src ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.d ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.o ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Cfg.src ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.d ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.o ./BSW/EcuAbstr/ComHwAb/FrIf/src/FrIf_Internal.src

.PHONY: clean-BSW-2f-EcuAbstr-2f-ComHwAb-2f-FrIf-2f-src

