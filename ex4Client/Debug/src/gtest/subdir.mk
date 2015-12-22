################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/gtest/gtest-all.cc 

OBJS += \
./src/gtest/gtest-all.o 

CC_DEPS += \
./src/gtest/gtest-all.d 


# Each subdirectory must supply rules for building sources it contributes
src/gtest/%.o: ../src/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/roi/workspace/targ2/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


