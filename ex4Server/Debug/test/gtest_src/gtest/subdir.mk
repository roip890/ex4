################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../test/gtest_src/gtest/gtest-all.cc 

OBJS += \
./test/gtest_src/gtest/gtest-all.o 

CC_DEPS += \
./test/gtest_src/gtest/gtest-all.d 


# Each subdirectory must supply rules for building sources it contributes
test/gtest_src/gtest/%.o: ../test/gtest_src/gtest/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


