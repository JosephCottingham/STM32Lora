################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../RA01/ra01.cpp 

OBJS += \
./RA01/ra01.o 

CPP_DEPS += \
./RA01/ra01.d 


# Each subdirectory must supply rules for building sources it contributes
RA01/%.o RA01/%.su: ../RA01/%.cpp RA01/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G431xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/josep/Projects/STM32Lora/STM32Lora/RA01" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RA01

clean-RA01:
	-$(RM) ./RA01/ra01.d ./RA01/ra01.o ./RA01/ra01.su

.PHONY: clean-RA01

