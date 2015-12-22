################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Actor.cpp \
../src/Director.cpp \
../src/Movie.cpp \
../src/MoviesSystem.cpp \
../src/Producer.cpp \
../src/Professional.cpp \
../src/ScreenWriter.cpp \
../src/SortStaffByAge.cpp \
../src/SortStaffById.cpp \
../src/SortStaffByMoviesQuantity.cpp \
../src/SortingStaffType.cpp \
../src/StaffComparator.cpp \
../src/Type.cpp 

OBJS += \
./src/Actor.o \
./src/Director.o \
./src/Movie.o \
./src/MoviesSystem.o \
./src/Producer.o \
./src/Professional.o \
./src/ScreenWriter.o \
./src/SortStaffByAge.o \
./src/SortStaffById.o \
./src/SortStaffByMoviesQuantity.o \
./src/SortingStaffType.o \
./src/StaffComparator.o \
./src/Type.o 

CPP_DEPS += \
./src/Actor.d \
./src/Director.d \
./src/Movie.d \
./src/MoviesSystem.d \
./src/Producer.d \
./src/Professional.d \
./src/ScreenWriter.d \
./src/SortStaffByAge.d \
./src/SortStaffById.d \
./src/SortStaffByMoviesQuantity.d \
./src/SortingStaffType.d \
./src/StaffComparator.d \
./src/Type.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/home/roi/workspace/ex4/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


