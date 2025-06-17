################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := "C:\HIGHTEC\toolchains\powerpc\v4.9.3.0/bin/rm" -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(I_DEPS)),)
-include $(I_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPCP_DEPS)),)
-include $(CPCP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ppc
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# Rebuild target
rebuild: clean all

# All Target
all: main-build

# Main-build Target
main-build: ppc.elf

# Tool invocations
ppc.elf: $(OBJS) $(USER_OBJS) $(ASM) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: PowerPC C++ Linker'
	"C:\HIGHTEC\toolchains\powerpc\v4.9.3.0/bin/ppc-vle-g++" -o  "ppc.elf" -nocrt0 -Wl,--gc-sections -mcpu=e200zx -Wl,--mem-holes -Wl,--warn-orphan -Wl,@objectlist.optfile -Wl,@libpathlist.optfile -Wl,-Map="$(basename $(notdir $@)).map" -Wl,--cref -fshort-double -Wl,-n -msoft-float -mvle -mspe -Wl,--extmap=a
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	$(foreach __cleandir__,${SUBDIRS},$(call do-clean-dir,$(__cleandir__)))
	@echo 'Cleaning: ppc.elf'
	@$(RM) ppc.elf
	@echo ' '

define do-clean-dir
	@echo 'Cleaning: $1/*.o *.d *.rel'
	@$(RM) $1/*.o $1/*.d $1/*.rel

endef

legacy-clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(I_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS)$(CPCP_DEPS) ppc.elf
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
