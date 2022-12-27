################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Prog.c \
../DC_Motor.c \
../DIO_Prog.c \
../KPD_Prog.c \
../LCD_Prog.c \
../main.c 

OBJS += \
./ADC_Prog.o \
./DC_Motor.o \
./DIO_Prog.o \
./KPD_Prog.o \
./LCD_Prog.o \
./main.o 

C_DEPS += \
./ADC_Prog.d \
./DC_Motor.d \
./DIO_Prog.d \
./KPD_Prog.d \
./LCD_Prog.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


