################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../BSW/Services/ComSrv/Com/src/Com.c" \
"../BSW/Services/ComSrv/Com/src/Com_Com.c" \
"../BSW/Services/ComSrv/Com/src/Com_Sched.c" \
"../BSW/Services/ComSrv/Com/src/Com_misc.c" 

COMPILED_SRCS += \
"BSW/Services/ComSrv/Com/src/Com.src" \
"BSW/Services/ComSrv/Com/src/Com_Com.src" \
"BSW/Services/ComSrv/Com/src/Com_Sched.src" \
"BSW/Services/ComSrv/Com/src/Com_misc.src" 

C_DEPS += \
"./BSW/Services/ComSrv/Com/src/Com.d" \
"./BSW/Services/ComSrv/Com/src/Com_Com.d" \
"./BSW/Services/ComSrv/Com/src/Com_Sched.d" \
"./BSW/Services/ComSrv/Com/src/Com_misc.d" 

OBJS += \
"BSW/Services/ComSrv/Com/src/Com.o" \
"BSW/Services/ComSrv/Com/src/Com_Com.o" \
"BSW/Services/ComSrv/Com/src/Com_Sched.o" \
"BSW/Services/ComSrv/Com/src/Com_misc.o" 


# Each subdirectory must supply rules for building sources it contributes
"BSW/Services/ComSrv/Com/src/Com.src":"../BSW/Services/ComSrv/Com/src/Com.c" "BSW/Services/ComSrv/Com/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com.o":"BSW/Services/ComSrv/Com/src/Com.src" "BSW/Services/ComSrv/Com/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com_Com.src":"../BSW/Services/ComSrv/Com/src/Com_Com.c" "BSW/Services/ComSrv/Com/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com_Com.o":"BSW/Services/ComSrv/Com/src/Com_Com.src" "BSW/Services/ComSrv/Com/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com_Sched.src":"../BSW/Services/ComSrv/Com/src/Com_Sched.c" "BSW/Services/ComSrv/Com/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com_Sched.o":"BSW/Services/ComSrv/Com/src/Com_Sched.src" "BSW/Services/ComSrv/Com/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com_misc.src":"../BSW/Services/ComSrv/Com/src/Com_misc.c" "BSW/Services/ComSrv/Com/src/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"BSW/Services/ComSrv/Com/src/Com_misc.o":"BSW/Services/ComSrv/Com/src/Com_misc.src" "BSW/Services/ComSrv/Com/src/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-BSW-2f-Services-2f-ComSrv-2f-Com-2f-src

clean-BSW-2f-Services-2f-ComSrv-2f-Com-2f-src:
	-$(RM) ./BSW/Services/ComSrv/Com/src/Com.d ./BSW/Services/ComSrv/Com/src/Com.o ./BSW/Services/ComSrv/Com/src/Com.src ./BSW/Services/ComSrv/Com/src/Com_Com.d ./BSW/Services/ComSrv/Com/src/Com_Com.o ./BSW/Services/ComSrv/Com/src/Com_Com.src ./BSW/Services/ComSrv/Com/src/Com_Sched.d ./BSW/Services/ComSrv/Com/src/Com_Sched.o ./BSW/Services/ComSrv/Com/src/Com_Sched.src ./BSW/Services/ComSrv/Com/src/Com_misc.d ./BSW/Services/ComSrv/Com/src/Com_misc.o ./BSW/Services/ComSrv/Com/src/Com_misc.src

.PHONY: clean-BSW-2f-Services-2f-ComSrv-2f-Com-2f-src

