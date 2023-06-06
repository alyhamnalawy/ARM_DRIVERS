################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/DotMatrix_main.c \
../src/DotMatrix_program.c \
../src/EXTI_main.c \
../src/EXTI_program.c \
../src/GPIO_main.c \
../src/GPIO_program.c \
../src/IR.c \
../src/MUART_program.c \
../src/NVIC_program.c \
../src/RCC_program.c \
../src/SPI_program.c \
../src/SSD_main.c \
../src/SSD_program.c \
../src/SysTick_main.c \
../src/SysTick_program.c \
../src/TFT_program.c \
../src/_initialize_hardware.c \
../src/stm32f4xx_hal_msp.c 

OBJS += \
./src/DotMatrix_main.o \
./src/DotMatrix_program.o \
./src/EXTI_main.o \
./src/EXTI_program.o \
./src/GPIO_main.o \
./src/GPIO_program.o \
./src/IR.o \
./src/MUART_program.o \
./src/NVIC_program.o \
./src/RCC_program.o \
./src/SPI_program.o \
./src/SSD_main.o \
./src/SSD_program.o \
./src/SysTick_main.o \
./src/SysTick_program.o \
./src/TFT_program.o \
./src/_initialize_hardware.o \
./src/stm32f4xx_hal_msp.o 

C_DEPS += \
./src/DotMatrix_main.d \
./src/DotMatrix_program.d \
./src/EXTI_main.d \
./src/EXTI_program.d \
./src/GPIO_main.d \
./src/GPIO_program.d \
./src/IR.d \
./src/MUART_program.d \
./src/NVIC_program.d \
./src/RCC_program.d \
./src/SPI_program.d \
./src/SSD_main.d \
./src/SSD_program.d \
./src/SysTick_main.d \
./src/SysTick_program.d \
./src/TFT_program.d \
./src/_initialize_hardware.d \
./src/stm32f4xx_hal_msp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/stm32f4xx_hal_msp.o: ../src/stm32f4xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xC -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -std=gnu11 -Wno-missing-prototypes -Wno-missing-declarations -MMD -MP -MF"$(@:%.o=%.d)" -MT"src/stm32f4xx_hal_msp.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


