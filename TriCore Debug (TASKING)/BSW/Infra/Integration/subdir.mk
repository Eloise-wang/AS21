################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Infra/Integration/IFX_Os.c" \
"../BSW/Infra/Integration/SchM_Fr_17_Eray.c" \
"../BSW/Infra/Integration/SchM_Gpt.c" \
"../BSW/Infra/Integration/SchM_McalLib.c" \
"../BSW/Infra/Integration/SchM_Mcu.c" 

COMPILED_SRCS += \
"BSW/Infra/Integration/IFX_Os.src" \
"BSW/Infra/Integration/SchM_Fr_17_Eray.src" \
"BSW/Infra/Integration/SchM_Gpt.src" \
"BSW/Infra/Integration/SchM_McalLib.src" \
"BSW/Infra/Integration/SchM_Mcu.src" 

C_DEPS += \
"./BSW/Infra/Integration/IFX_Os.d" \
"./BSW/Infra/Integration/SchM_Fr_17_Eray.d" \
"./BSW/Infra/Integration/SchM_Gpt.d" \
"./BSW/Infra/Integration/SchM_McalLib.d" \
"./BSW/Infra/Integration/SchM_Mcu.d" 

OBJS += \
"BSW/Infra/Integration/IFX_Os.o" \
"BSW/Infra/Integration/SchM_Fr_17_Eray.o" \
"BSW/Infra/Integration/SchM_Gpt.o" \
"BSW/Infra/Integration/SchM_McalLib.o" \
"BSW/Infra/Integration/SchM_Mcu.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Infra/Integration/IFX_Os.src":"../BSW/Infra/Integration/IFX_Os.c" "BSW/Infra/Integration/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Integration/IFX_Os.o":"BSW/Infra/Integration/IFX_Os.src" "BSW/Infra/Integration/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Infra/Integration/SchM_Fr_17_Eray.src":"../BSW/Infra/Integration/SchM_Fr_17_Eray.c" "BSW/Infra/Integration/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Integration/SchM_Fr_17_Eray.o":"BSW/Infra/Integration/SchM_Fr_17_Eray.src" "BSW/Infra/Integration/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Infra/Integration/SchM_Gpt.src":"../BSW/Infra/Integration/SchM_Gpt.c" "BSW/Infra/Integration/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Integration/SchM_Gpt.o":"BSW/Infra/Integration/SchM_Gpt.src" "BSW/Infra/Integration/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Infra/Integration/SchM_McalLib.src":"../BSW/Infra/Integration/SchM_McalLib.c" "BSW/Infra/Integration/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Integration/SchM_McalLib.o":"BSW/Infra/Integration/SchM_McalLib.src" "BSW/Infra/Integration/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Infra/Integration/SchM_Mcu.src":"../BSW/Infra/Integration/SchM_Mcu.c" "BSW/Infra/Integration/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Infra/Integration/SchM_Mcu.o":"BSW/Infra/Integration/SchM_Mcu.src" "BSW/Infra/Integration/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Infra-2f-Integration

clean-BSW-2f-Infra-2f-Integration:
	-$(RM) ./BSW/Infra/Integration/IFX_Os.d ./BSW/Infra/Integration/IFX_Os.o ./BSW/Infra/Integration/IFX_Os.src ./BSW/Infra/Integration/SchM_Fr_17_Eray.d ./BSW/Infra/Integration/SchM_Fr_17_Eray.o ./BSW/Infra/Integration/SchM_Fr_17_Eray.src ./BSW/Infra/Integration/SchM_Gpt.d ./BSW/Infra/Integration/SchM_Gpt.o ./BSW/Infra/Integration/SchM_Gpt.src ./BSW/Infra/Integration/SchM_McalLib.d ./BSW/Infra/Integration/SchM_McalLib.o ./BSW/Infra/Integration/SchM_McalLib.src ./BSW/Infra/Integration/SchM_Mcu.d ./BSW/Infra/Integration/SchM_Mcu.o ./BSW/Infra/Integration/SchM_Mcu.src

.PHONY: clean-BSW-2f-Infra-2f-Integration

