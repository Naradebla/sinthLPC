################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: lpc1769_sinthFFT.axf

# Tool invocations
lpc1769_sinthFFT.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"C:\nxp\DSPLib\IAR" -L"D:\Develop\LPC1769\ws\lpc_board_nxp_lpcxpresso_1769\Debug" -L"D:\Develop\LPC1769\ws\lpc_chip_175x_6x\Debug" -Xlinker -Map="lpc1769_sinthFFT.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "lpc1769_sinthFFT_Debug.ld" -o "lpc1769_sinthFFT.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) lpc1769_sinthFFT.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "lpc1769_sinthFFT.axf"; # arm-none-eabi-objcopy -v -O binary "lpc1769_sinthFFT.axf" "lpc1769_sinthFFT.bin" ; # checksum -p LPC1769 -d "lpc1769_sinthFFT.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
