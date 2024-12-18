################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Core/Src/Display/SSH1106.cpp 

C_SRCS += \
../Core/Src/Display/fonts.c \
../Core/Src/Display/ssd1306.c 

C_DEPS += \
./Core/Src/Display/fonts.d \
./Core/Src/Display/ssd1306.d 

OBJS += \
./Core/Src/Display/SSH1106.o \
./Core/Src/Display/fonts.o \
./Core/Src/Display/ssd1306.o 

CPP_DEPS += \
./Core/Src/Display/SSH1106.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Display/%.o Core/Src/Display/%.su Core/Src/Display/%.cyclo: ../Core/Src/Display/%.cpp Core/Src/Display/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/Display/%.o Core/Src/Display/%.su Core/Src/Display/%.cyclo: ../Core/Src/Display/%.c Core/Src/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32L432xx -DUSE_HAL_DRIVER -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Display

clean-Core-2f-Src-2f-Display:
	-$(RM) ./Core/Src/Display/SSH1106.cyclo ./Core/Src/Display/SSH1106.d ./Core/Src/Display/SSH1106.o ./Core/Src/Display/SSH1106.su ./Core/Src/Display/fonts.cyclo ./Core/Src/Display/fonts.d ./Core/Src/Display/fonts.o ./Core/Src/Display/fonts.su ./Core/Src/Display/ssd1306.cyclo ./Core/Src/Display/ssd1306.d ./Core/Src/Display/ssd1306.o ./Core/Src/Display/ssd1306.su

.PHONY: clean-Core-2f-Src-2f-Display

