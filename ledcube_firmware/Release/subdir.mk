################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Effect.cpp \
../LedSquare.cpp \
../Main.cpp \
../TimerOne.cpp \
../ledcube.cpp 

OBJS += \
./Effect.o \
./LedSquare.o \
./Main.o \
./TimerOne.o \
./ledcube.o 

CPP_DEPS += \
./Effect.d \
./LedSquare.d \
./Main.d \
./TimerOne.d \
./ledcube.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\apps\devel\arduino-1.0\hardware\arduino\cores\arduino" -I"C:\apps\devel\arduino-1.0\hardware\arduino\variants\eightanaloginputs" -I"C:\Users\pueppi\workspace\ledcube\ledcube_firmware" -D__IN_ECLIPSE__=1 -DARDUINO=100 -Wall -Os -ffunction-sections -fdata-sections -fno-exceptions -g -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" -x c++ "$<"
	@echo 'Finished building: $<'
	@echo ' '


