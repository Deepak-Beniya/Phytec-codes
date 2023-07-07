################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/mqtt/Base64.c \
../Core/mqtt/Clients.c \
../Core/mqtt/Heap.c \
../Core/mqtt/LinkedList.c \
../Core/mqtt/Log.c \
../Core/mqtt/MQTTAsync.c \
../Core/mqtt/MQTTAsyncUtils.c \
../Core/mqtt/MQTTClient.c \
../Core/mqtt/MQTTPacket.c \
../Core/mqtt/MQTTPacketOut.c \
../Core/mqtt/MQTTPersistence.c \
../Core/mqtt/MQTTPersistenceDefault.c \
../Core/mqtt/MQTTProperties.c \
../Core/mqtt/MQTTProtocolClient.c \
../Core/mqtt/MQTTProtocolOut.c \
../Core/mqtt/MQTTReasonCodes.c \
../Core/mqtt/MQTTTime.c \
../Core/mqtt/MQTTVersion.c \
../Core/mqtt/Messages.c \
../Core/mqtt/OsWrapper.c \
../Core/mqtt/Proxy.c \
../Core/mqtt/SHA1.c \
../Core/mqtt/SSLSocket.c \
../Core/mqtt/Socket.c \
../Core/mqtt/SocketBuffer.c \
../Core/mqtt/StackTrace.c \
../Core/mqtt/Thread.c \
../Core/mqtt/Tree.c \
../Core/mqtt/WebSocket.c \
../Core/mqtt/utf-8.c 

OBJS += \
./Core/mqtt/Base64.o \
./Core/mqtt/Clients.o \
./Core/mqtt/Heap.o \
./Core/mqtt/LinkedList.o \
./Core/mqtt/Log.o \
./Core/mqtt/MQTTAsync.o \
./Core/mqtt/MQTTAsyncUtils.o \
./Core/mqtt/MQTTClient.o \
./Core/mqtt/MQTTPacket.o \
./Core/mqtt/MQTTPacketOut.o \
./Core/mqtt/MQTTPersistence.o \
./Core/mqtt/MQTTPersistenceDefault.o \
./Core/mqtt/MQTTProperties.o \
./Core/mqtt/MQTTProtocolClient.o \
./Core/mqtt/MQTTProtocolOut.o \
./Core/mqtt/MQTTReasonCodes.o \
./Core/mqtt/MQTTTime.o \
./Core/mqtt/MQTTVersion.o \
./Core/mqtt/Messages.o \
./Core/mqtt/OsWrapper.o \
./Core/mqtt/Proxy.o \
./Core/mqtt/SHA1.o \
./Core/mqtt/SSLSocket.o \
./Core/mqtt/Socket.o \
./Core/mqtt/SocketBuffer.o \
./Core/mqtt/StackTrace.o \
./Core/mqtt/Thread.o \
./Core/mqtt/Tree.o \
./Core/mqtt/WebSocket.o \
./Core/mqtt/utf-8.o 

C_DEPS += \
./Core/mqtt/Base64.d \
./Core/mqtt/Clients.d \
./Core/mqtt/Heap.d \
./Core/mqtt/LinkedList.d \
./Core/mqtt/Log.d \
./Core/mqtt/MQTTAsync.d \
./Core/mqtt/MQTTAsyncUtils.d \
./Core/mqtt/MQTTClient.d \
./Core/mqtt/MQTTPacket.d \
./Core/mqtt/MQTTPacketOut.d \
./Core/mqtt/MQTTPersistence.d \
./Core/mqtt/MQTTPersistenceDefault.d \
./Core/mqtt/MQTTProperties.d \
./Core/mqtt/MQTTProtocolClient.d \
./Core/mqtt/MQTTProtocolOut.d \
./Core/mqtt/MQTTReasonCodes.d \
./Core/mqtt/MQTTTime.d \
./Core/mqtt/MQTTVersion.d \
./Core/mqtt/Messages.d \
./Core/mqtt/OsWrapper.d \
./Core/mqtt/Proxy.d \
./Core/mqtt/SHA1.d \
./Core/mqtt/SSLSocket.d \
./Core/mqtt/Socket.d \
./Core/mqtt/SocketBuffer.d \
./Core/mqtt/StackTrace.d \
./Core/mqtt/Thread.d \
./Core/mqtt/Tree.d \
./Core/mqtt/WebSocket.d \
./Core/mqtt/utf-8.d 


# Each subdirectory must supply rules for building sources it contributes
Core/mqtt/%.o Core/mqtt/%.su Core/mqtt/%.cyclo: ../Core/mqtt/%.c Core/mqtt/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-mqtt

clean-Core-2f-mqtt:
	-$(RM) ./Core/mqtt/Base64.cyclo ./Core/mqtt/Base64.d ./Core/mqtt/Base64.o ./Core/mqtt/Base64.su ./Core/mqtt/Clients.cyclo ./Core/mqtt/Clients.d ./Core/mqtt/Clients.o ./Core/mqtt/Clients.su ./Core/mqtt/Heap.cyclo ./Core/mqtt/Heap.d ./Core/mqtt/Heap.o ./Core/mqtt/Heap.su ./Core/mqtt/LinkedList.cyclo ./Core/mqtt/LinkedList.d ./Core/mqtt/LinkedList.o ./Core/mqtt/LinkedList.su ./Core/mqtt/Log.cyclo ./Core/mqtt/Log.d ./Core/mqtt/Log.o ./Core/mqtt/Log.su ./Core/mqtt/MQTTAsync.cyclo ./Core/mqtt/MQTTAsync.d ./Core/mqtt/MQTTAsync.o ./Core/mqtt/MQTTAsync.su ./Core/mqtt/MQTTAsyncUtils.cyclo ./Core/mqtt/MQTTAsyncUtils.d ./Core/mqtt/MQTTAsyncUtils.o ./Core/mqtt/MQTTAsyncUtils.su ./Core/mqtt/MQTTClient.cyclo ./Core/mqtt/MQTTClient.d ./Core/mqtt/MQTTClient.o ./Core/mqtt/MQTTClient.su ./Core/mqtt/MQTTPacket.cyclo ./Core/mqtt/MQTTPacket.d ./Core/mqtt/MQTTPacket.o ./Core/mqtt/MQTTPacket.su ./Core/mqtt/MQTTPacketOut.cyclo ./Core/mqtt/MQTTPacketOut.d ./Core/mqtt/MQTTPacketOut.o ./Core/mqtt/MQTTPacketOut.su ./Core/mqtt/MQTTPersistence.cyclo ./Core/mqtt/MQTTPersistence.d ./Core/mqtt/MQTTPersistence.o ./Core/mqtt/MQTTPersistence.su ./Core/mqtt/MQTTPersistenceDefault.cyclo ./Core/mqtt/MQTTPersistenceDefault.d ./Core/mqtt/MQTTPersistenceDefault.o ./Core/mqtt/MQTTPersistenceDefault.su ./Core/mqtt/MQTTProperties.cyclo ./Core/mqtt/MQTTProperties.d ./Core/mqtt/MQTTProperties.o ./Core/mqtt/MQTTProperties.su ./Core/mqtt/MQTTProtocolClient.cyclo ./Core/mqtt/MQTTProtocolClient.d ./Core/mqtt/MQTTProtocolClient.o ./Core/mqtt/MQTTProtocolClient.su ./Core/mqtt/MQTTProtocolOut.cyclo ./Core/mqtt/MQTTProtocolOut.d ./Core/mqtt/MQTTProtocolOut.o ./Core/mqtt/MQTTProtocolOut.su ./Core/mqtt/MQTTReasonCodes.cyclo ./Core/mqtt/MQTTReasonCodes.d ./Core/mqtt/MQTTReasonCodes.o ./Core/mqtt/MQTTReasonCodes.su ./Core/mqtt/MQTTTime.cyclo ./Core/mqtt/MQTTTime.d ./Core/mqtt/MQTTTime.o ./Core/mqtt/MQTTTime.su ./Core/mqtt/MQTTVersion.cyclo ./Core/mqtt/MQTTVersion.d ./Core/mqtt/MQTTVersion.o ./Core/mqtt/MQTTVersion.su ./Core/mqtt/Messages.cyclo ./Core/mqtt/Messages.d ./Core/mqtt/Messages.o ./Core/mqtt/Messages.su ./Core/mqtt/OsWrapper.cyclo ./Core/mqtt/OsWrapper.d ./Core/mqtt/OsWrapper.o ./Core/mqtt/OsWrapper.su ./Core/mqtt/Proxy.cyclo ./Core/mqtt/Proxy.d ./Core/mqtt/Proxy.o ./Core/mqtt/Proxy.su ./Core/mqtt/SHA1.cyclo ./Core/mqtt/SHA1.d ./Core/mqtt/SHA1.o ./Core/mqtt/SHA1.su ./Core/mqtt/SSLSocket.cyclo ./Core/mqtt/SSLSocket.d ./Core/mqtt/SSLSocket.o ./Core/mqtt/SSLSocket.su ./Core/mqtt/Socket.cyclo ./Core/mqtt/Socket.d ./Core/mqtt/Socket.o ./Core/mqtt/Socket.su ./Core/mqtt/SocketBuffer.cyclo ./Core/mqtt/SocketBuffer.d ./Core/mqtt/SocketBuffer.o ./Core/mqtt/SocketBuffer.su ./Core/mqtt/StackTrace.cyclo ./Core/mqtt/StackTrace.d ./Core/mqtt/StackTrace.o ./Core/mqtt/StackTrace.su ./Core/mqtt/Thread.cyclo ./Core/mqtt/Thread.d ./Core/mqtt/Thread.o ./Core/mqtt/Thread.su ./Core/mqtt/Tree.cyclo ./Core/mqtt/Tree.d ./Core/mqtt/Tree.o ./Core/mqtt/Tree.su ./Core/mqtt/WebSocket.cyclo ./Core/mqtt/WebSocket.d ./Core/mqtt/WebSocket.o ./Core/mqtt/WebSocket.su ./Core/mqtt/utf-8.cyclo ./Core/mqtt/utf-8.d ./Core/mqtt/utf-8.o ./Core/mqtt/utf-8.su

.PHONY: clean-Core-2f-mqtt

