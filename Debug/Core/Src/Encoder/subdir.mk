################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Encoder/RotaryEncoder.cpp 

OBJS += \
./Core/Src/Encoder/RotaryEncoder.o 

CPP_DEPS += \
./Core/Src/Encoder/RotaryEncoder.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Encoder/%.o Core/Src/Encoder/%.su Core/Src/Encoder/%.cyclo: ../Core/Src/Encoder/%.cpp Core/Src/Encoder/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Encoder

clean-Core-2f-Src-2f-Encoder:
	-$(RM) ./Core/Src/Encoder/RotaryEncoder.cyclo ./Core/Src/Encoder/RotaryEncoder.d ./Core/Src/Encoder/RotaryEncoder.o ./Core/Src/Encoder/RotaryEncoder.su

.PHONY: clean-Core-2f-Src-2f-Encoder

