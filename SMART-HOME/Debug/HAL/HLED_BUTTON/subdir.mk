################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/HLED_BUTTON/BUTTON_PROGRAM.c \
../HAL/HLED_BUTTON/LED_PROGRAM.c 

OBJS += \
./HAL/HLED_BUTTON/BUTTON_PROGRAM.o \
./HAL/HLED_BUTTON/LED_PROGRAM.o 

C_DEPS += \
./HAL/HLED_BUTTON/BUTTON_PROGRAM.d \
./HAL/HLED_BUTTON/LED_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/HLED_BUTTON/%.o: ../HAL/HLED_BUTTON/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


