################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/dsp/cr_dsplib_biquad32.s \
../src/dsp/cr_dsplib_blockfir32.s \
../src/dsp/cr_dsplib_dotproduct.s \
../src/dsp/cr_dsplib_pid.s \
../src/dsp/cr_dsplib_random.s \
../src/dsp/cr_dsplib_resonator.s \
../src/dsp/cr_dsplib_vectoradd.s \
../src/dsp/cr_dsplib_vectoraddconst.s \
../src/dsp/cr_dsplib_vectormulconst.s \
../src/dsp/cr_dsplib_vectormulelement.s \
../src/dsp/cr_dsplib_vectorsub.s \
../src/dsp/cr_dsplib_vectsumofsquares.s 

C_SRCS += \
../src/dsp/cr_dsplib_testbench_biquad32_main.c \
../src/dsp/cr_dsplib_testbench_blockfir32_main.c \
../src/dsp/cr_dsplib_testbench_random_main.c \
../src/dsp/dsplib_testbench_fft_main.c \
../src/dsp/testbench_resonator_main.c 

OBJS += \
./src/dsp/cr_dsplib_biquad32.o \
./src/dsp/cr_dsplib_blockfir32.o \
./src/dsp/cr_dsplib_dotproduct.o \
./src/dsp/cr_dsplib_pid.o \
./src/dsp/cr_dsplib_random.o \
./src/dsp/cr_dsplib_resonator.o \
./src/dsp/cr_dsplib_testbench_biquad32_main.o \
./src/dsp/cr_dsplib_testbench_blockfir32_main.o \
./src/dsp/cr_dsplib_testbench_random_main.o \
./src/dsp/cr_dsplib_vectoradd.o \
./src/dsp/cr_dsplib_vectoraddconst.o \
./src/dsp/cr_dsplib_vectormulconst.o \
./src/dsp/cr_dsplib_vectormulelement.o \
./src/dsp/cr_dsplib_vectorsub.o \
./src/dsp/cr_dsplib_vectsumofsquares.o \
./src/dsp/dsplib_testbench_fft_main.o \
./src/dsp/testbench_resonator_main.o 

C_DEPS += \
./src/dsp/cr_dsplib_testbench_biquad32_main.d \
./src/dsp/cr_dsplib_testbench_blockfir32_main.d \
./src/dsp/cr_dsplib_testbench_random_main.d \
./src/dsp/dsplib_testbench_fft_main.d \
./src/dsp/testbench_resonator_main.d 


# Each subdirectory must supply rules for building sources it contributes
src/dsp/%.o: ../src/dsp/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU Assembler'
	arm-none-eabi-gcc -c -x assembler-with-cpp -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -D__LPC17XX__ -D__REDLIB__ -I"D:\Develop\LPC1769\ws\lpc_board_nxp_lpcxpresso_1769\inc" -I"D:\Develop\LPC1769\ws\lpc_chip_175x_6x\inc" -g3 -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/dsp/%.o: ../src/dsp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_LPCOPEN -D__LPC17XX__ -D__REDLIB__ -I"D:\Develop\LPC1769\ws\lpc_board_nxp_lpcxpresso_1769\inc" -I"D:\Develop\LPC1769\ws\lpc_chip_175x_6x\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


