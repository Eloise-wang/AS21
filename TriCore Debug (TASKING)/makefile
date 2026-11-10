################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/iLLD/TC3xx/Tricore/_PinMap/TC38x/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC3xx/Tricore/Cpu/Irq/subdir.mk
-include Libraries/Infra/Ssw/TC3xx/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Generated/MCAL/src/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include BSW/Services/ComSrv/PduR/src/subdir.mk
-include BSW/Services/ComSrv/Com/src/subdir.mk
-include BSW/MCAL/Port/src/subdir.mk
-include BSW/MCAL/Mcu/src/subdir.mk
-include BSW/MCAL/McalLib/src/subdir.mk
-include BSW/MCAL/Irq/Gtm_Irq/subdir.mk
-include BSW/MCAL/Irq/Gpt12_Irq/subdir.mk
-include BSW/MCAL/Irq/Fr_17_Eray_Irq/subdir.mk
-include BSW/MCAL/Gpt/src/subdir.mk
-include BSW/MCAL/Fr/src/subdir.mk
-include BSW/MCAL/Dio/src/subdir.mk
-include BSW/Infra/Irq/src/subdir.mk
-include BSW/Infra/Integration/subdir.mk
-include BSW/Infra/Autosar_Srv/subdir.mk
-include BSW/EcuAbstr/ComHwAb/FrIf/src/subdir.mk
-include BSW/AS21_Mcal/src/subdir.mk
-include subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++M_DEPS)),)
-include $(C++M_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CCM_DEPS)),)
-include $(CCM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXXM_DEPS)),)
-include $(CXXM_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := AS21
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
AS21.siz \


# All Target
all: main-build

# Main-build Target
main-build: AS21.elf secondary-outputs

# Tool invocations
AS21.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS) .AS21.elf.opt
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc -f .AS21.elf.opt
	@echo 'Finished building target: $@'
	@echo ' '

.AS21.elf.opt:
	@argfile .AS21.elf.opt --lsl-file="../Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="AS21.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc38x -o"AS21.elf" -Wl-o"AS21.hex:IHEX" $(OBJS)

.PHONY: .AS21.elf.opt

AS21.siz: AS21.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "AS21.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) AS21.siz AS21.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
