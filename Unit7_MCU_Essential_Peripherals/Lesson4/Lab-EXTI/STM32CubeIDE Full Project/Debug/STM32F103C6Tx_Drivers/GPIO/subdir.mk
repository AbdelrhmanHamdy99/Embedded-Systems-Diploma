################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6Tx_Drivers/GPIO/stm32f103c6_GPIO_Driver.c 

OBJS += \
./STM32F103C6Tx_Drivers/GPIO/stm32f103c6_GPIO_Driver.o 

C_DEPS += \
./STM32F103C6Tx_Drivers/GPIO/stm32f103c6_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6Tx_Drivers/GPIO/stm32f103c6_GPIO_Driver.o: ../STM32F103C6Tx_Drivers/GPIO/stm32f103c6_GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/courses/embeded systems/Embeded System Diploma/workspace/stm32/Unit7_Lesson4_2/HAL_Drivers/Inc" -I"D:/courses/embeded systems/Embeded System Diploma/workspace/stm32/Unit7_Lesson4_2/STM32F103C6Tx_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6Tx_Drivers/GPIO/stm32f103c6_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

