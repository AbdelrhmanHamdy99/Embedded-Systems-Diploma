################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_Drivers/KeyPad/KeyPad.c 

OBJS += \
./HAL_Drivers/KeyPad/KeyPad.o 

C_DEPS += \
./HAL_Drivers/KeyPad/KeyPad.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_Drivers/KeyPad/KeyPad.o: ../HAL_Drivers/KeyPad/KeyPad.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/courses/embeded systems/Embeded System Diploma/workspace/stm32/Unit7_Lesson3_Section/STM32F103C6Tx_Drivers/Inc" -I"D:/courses/embeded systems/Embeded System Diploma/workspace/stm32/Unit7_Lesson3_Section/HAL_Drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_Drivers/KeyPad/KeyPad.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

