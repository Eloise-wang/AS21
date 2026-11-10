################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Services/ComSrv/PduR/src/PduR.c" \
"../BSW/Services/ComSrv/PduR/src/PduR_Com.c" \
"../BSW/Services/ComSrv/PduR/src/PduR_FrIf.c" \
"../BSW/Services/ComSrv/PduR/src/PduR_Logic.c" \
"../BSW/Services/ComSrv/PduR/src/PduR_Routing.c" 

COMPILED_SRCS += \
"BSW/Services/ComSrv/PduR/src/PduR.src" \
"BSW/Services/ComSrv/PduR/src/PduR_Com.src" \
"BSW/Services/ComSrv/PduR/src/PduR_FrIf.src" \
"BSW/Services/ComSrv/PduR/src/PduR_Logic.src" \
"BSW/Services/ComSrv/PduR/src/PduR_Routing.src" 

C_DEPS += \
"./BSW/Services/ComSrv/PduR/src/PduR.d" \
"./BSW/Services/ComSrv/PduR/src/PduR_Com.d" \
"./BSW/Services/ComSrv/PduR/src/PduR_FrIf.d" \
"./BSW/Services/ComSrv/PduR/src/PduR_Logic.d" \
"./BSW/Services/ComSrv/PduR/src/PduR_Routing.d" 

OBJS += \
"BSW/Services/ComSrv/PduR/src/PduR.o" \
"BSW/Services/ComSrv/PduR/src/PduR_Com.o" \
"BSW/Services/ComSrv/PduR/src/PduR_FrIf.o" \
"BSW/Services/ComSrv/PduR/src/PduR_Logic.o" \
"BSW/Services/ComSrv/PduR/src/PduR_Routing.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Services/ComSrv/PduR/src/PduR.src":"../BSW/Services/ComSrv/PduR/src/PduR.c" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR.o":"BSW/Services/ComSrv/PduR/src/PduR.src" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_Com.src":"../BSW/Services/ComSrv/PduR/src/PduR_Com.c" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_Com.o":"BSW/Services/ComSrv/PduR/src/PduR_Com.src" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_FrIf.src":"../BSW/Services/ComSrv/PduR/src/PduR_FrIf.c" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_FrIf.o":"BSW/Services/ComSrv/PduR/src/PduR_FrIf.src" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_Logic.src":"../BSW/Services/ComSrv/PduR/src/PduR_Logic.c" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_Logic.o":"BSW/Services/ComSrv/PduR/src/PduR_Logic.src" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_Routing.src":"../BSW/Services/ComSrv/PduR/src/PduR_Routing.c" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/PduR/src/PduR_Routing.o":"BSW/Services/ComSrv/PduR/src/PduR_Routing.src" "BSW/Services/ComSrv/PduR/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Services-2f-ComSrv-2f-PduR-2f-src

clean-BSW-2f-Services-2f-ComSrv-2f-PduR-2f-src:
	-$(RM) ./BSW/Services/ComSrv/PduR/src/PduR.d ./BSW/Services/ComSrv/PduR/src/PduR.o ./BSW/Services/ComSrv/PduR/src/PduR.src ./BSW/Services/ComSrv/PduR/src/PduR_Com.d ./BSW/Services/ComSrv/PduR/src/PduR_Com.o ./BSW/Services/ComSrv/PduR/src/PduR_Com.src ./BSW/Services/ComSrv/PduR/src/PduR_FrIf.d ./BSW/Services/ComSrv/PduR/src/PduR_FrIf.o ./BSW/Services/ComSrv/PduR/src/PduR_FrIf.src ./BSW/Services/ComSrv/PduR/src/PduR_Logic.d ./BSW/Services/ComSrv/PduR/src/PduR_Logic.o ./BSW/Services/ComSrv/PduR/src/PduR_Logic.src ./BSW/Services/ComSrv/PduR/src/PduR_Routing.d ./BSW/Services/ComSrv/PduR/src/PduR_Routing.o ./BSW/Services/ComSrv/PduR/src/PduR_Routing.src

.PHONY: clean-BSW-2f-Services-2f-ComSrv-2f-PduR-2f-src

