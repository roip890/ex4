################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ClientConnection.cpp \
../src/TcpConnection.cpp \
../src/UdpConnection.cpp \
../src/main.cpp 

OBJS += \
./src/ClientConnection.o \
./src/TcpConnection.o \
./src/UdpConnection.o \
./src/main.o 

CPP_DEPS += \
./src/ClientConnection.d \
./src/TcpConnection.d \
./src/UdpConnection.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
<<<<<<< HEAD
	g++ -I"/home/tomericko/git/ex4/ex4Client/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
=======
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
>>>>>>> branch 'master' of https://github.com/roip890/ex4.git
	@echo 'Finished building: $<'
	@echo ' '


