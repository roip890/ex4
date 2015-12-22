################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/ActorCheck.cpp \
../test/DirectorCheck.cpp \
../test/MovieCheck.cpp \
../test/MovieSystemCheck.cpp \
../test/ProducerCheck.cpp \
../test/ProfessionalCheck.cpp \
../test/ScreenWriterCheck.cpp \
../test/SortStaffByAgeCheck.cpp \
../test/SortStaffByIdCheck.cpp \
../test/SortStaffByMoviesQuantityCheck.cpp \
../test/StaffComparatorCheck.cpp \
../test/main.cpp 

OBJS += \
./test/ActorCheck.o \
./test/DirectorCheck.o \
./test/MovieCheck.o \
./test/MovieSystemCheck.o \
./test/ProducerCheck.o \
./test/ProfessionalCheck.o \
./test/ScreenWriterCheck.o \
./test/SortStaffByAgeCheck.o \
./test/SortStaffByIdCheck.o \
./test/SortStaffByMoviesQuantityCheck.o \
./test/StaffComparatorCheck.o \
./test/main.o 

CPP_DEPS += \
./test/ActorCheck.d \
./test/DirectorCheck.d \
./test/MovieCheck.d \
./test/MovieSystemCheck.d \
./test/ProducerCheck.d \
./test/ProfessionalCheck.d \
./test/ScreenWriterCheck.d \
./test/SortStaffByAgeCheck.d \
./test/SortStaffByIdCheck.d \
./test/SortStaffByMoviesQuantityCheck.d \
./test/StaffComparatorCheck.d \
./test/main.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/roi/workspace/ex4/include" -I"/home/roi/workspace/ex4/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


