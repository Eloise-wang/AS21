################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
"../Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.c" 

COMPILED_SRCS += \
"Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.src" 

C_DEPS += \
"./Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.d" 

OBJS += \
"Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.o" 


# Each subdirectory must supply rules for building sources it contributes
"Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.src":"../Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.c" "Libraries/iLLD/TC3xx/Tricore/Smu/Smu/subdir.mk"
	cctc -cs --dep-file="$*.d" --misrac-version=2012 -D__CPU__=tc38x "-fD:/AURIX-v1.10.40-workspace/AS21_COM_Test/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Wc-w508 -Ctc38x -Y0 -N0 -Z0 -o "$@" "$<"
"Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.o":"Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.src" "Libraries/iLLD/TC3xx/Tricore/Smu/Smu/subdir.mk"
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC3xx-2f-Tricore-2f-Smu-2f-Smu

clean-Libraries-2f-iLLD-2f-TC3xx-2f-Tricore-2f-Smu-2f-Smu:
	-$(RM) ./Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.d ./Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.o ./Libraries/iLLD/TC3xx/Tricore/Smu/Smu/IfxSmu_Smu.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC3xx-2f-Tricore-2f-Smu-2f-Smu

