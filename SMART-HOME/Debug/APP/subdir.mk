################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/AC_APP.c \
../APP/DEVICES_APP.c \
../APP/LCD_APP.c 

OBJS += \
./APP/AC_APP.o \
./APP/DEVICES_APP.o \
./APP/LCD_APP.o 

C_DEPS += \
./APP/AC_APP.d \
./APP/DEVICES_APP.d \
./APP/LCD_APP.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


