################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc175x_6x.c \
../src/dma.c \
../src/filter.c \
../src/lpc1769.c \
../src/oscillators.c \
../src/sysinit.c \
../src/uihelper.c \
../src/utils.c 

OBJS += \
./src/cr_startup_lpc175x_6x.o \
./src/dma.o \
./src/filter.o \
./src/lpc1769.o \
./src/oscillators.o \
./src/sysinit.o \
./src/uihelper.o \
./src/utils.o 

C_DEPS += \
./src/cr_startup_lpc175x_6x.d \
./src/dma.d \
./src/filter.d \
./src/lpc1769.d \
./src/oscillators.d \
./src/sysinit.d \
./src/uihelper.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -D__LPC17XX__ -D__REDLIB__ -I"D:\Develop\LPC1769\ws\lpc_board_nxp_lpcxpresso_1769\inc" -I"C:\nxp\DSPLib\IAR" -I"D:\Develop\LPC1769\ws\lpc_chip_175x_6x\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


