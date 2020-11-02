################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/CS20_CustomerLinkedList.cpp \
../source/Customer.cpp \
../source/LinkedList.cpp 

OBJS += \
./source/CS20_CustomerLinkedList.o \
./source/Customer.o \
./source/LinkedList.o 

CPP_DEPS += \
./source/CS20_CustomerLinkedList.d \
./source/Customer.d \
./source/LinkedList.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


