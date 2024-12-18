################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/PLL/PLL.c 

C_DEPS += \
./Core/Src/PLL/PLL.d 

OBJS += \
./Core/Src/PLL/PLL.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/PLL/%.o Core/Src/PLL/%.su Core/Src/PLL/%.cyclo: ../Core/Src/PLL/%.c Core/Src/PLL/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-PLL

clean-Core-2f-Src-2f-PLL:
	-$(RM) ./Core/Src/PLL/PLL.cyclo ./Core/Src/PLL/PLL.d ./Core/Src/PLL/PLL.o ./Core/Src/PLL/PLL.su

.PHONY: clean-Core-2f-Src-2f-PLL

