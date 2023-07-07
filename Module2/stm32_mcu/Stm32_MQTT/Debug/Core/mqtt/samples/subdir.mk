################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/mqtt/samples/MQTTAsync_publish_time.c \
../Core/mqtt/samples/MQTTClient_publish.c \
../Core/mqtt/samples/MQTTClient_publish_async.c \
../Core/mqtt/samples/MQTTClient_subscribe.c \
../Core/mqtt/samples/paho_c_pub.c \
../Core/mqtt/samples/paho_c_sub.c \
../Core/mqtt/samples/paho_cs_pub.c \
../Core/mqtt/samples/paho_cs_sub.c \
../Core/mqtt/samples/pubsub_opts.c 

OBJS += \
./Core/mqtt/samples/MQTTAsync_publish_time.o \
./Core/mqtt/samples/MQTTClient_publish.o \
./Core/mqtt/samples/MQTTClient_publish_async.o \
./Core/mqtt/samples/MQTTClient_subscribe.o \
./Core/mqtt/samples/paho_c_pub.o \
./Core/mqtt/samples/paho_c_sub.o \
./Core/mqtt/samples/paho_cs_pub.o \
./Core/mqtt/samples/paho_cs_sub.o \
./Core/mqtt/samples/pubsub_opts.o 

C_DEPS += \
./Core/mqtt/samples/MQTTAsync_publish_time.d \
./Core/mqtt/samples/MQTTClient_publish.d \
./Core/mqtt/samples/MQTTClient_publish_async.d \
./Core/mqtt/samples/MQTTClient_subscribe.d \
./Core/mqtt/samples/paho_c_pub.d \
./Core/mqtt/samples/paho_c_sub.d \
./Core/mqtt/samples/paho_cs_pub.d \
./Core/mqtt/samples/paho_cs_sub.d \
./Core/mqtt/samples/pubsub_opts.d 


# Each subdirectory must supply rules for building sources it contributes
Core/mqtt/samples/%.o Core/mqtt/samples/%.su Core/mqtt/samples/%.cyclo: ../Core/mqtt/samples/%.c Core/mqtt/samples/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-mqtt-2f-samples

clean-Core-2f-mqtt-2f-samples:
	-$(RM) ./Core/mqtt/samples/MQTTAsync_publish_time.cyclo ./Core/mqtt/samples/MQTTAsync_publish_time.d ./Core/mqtt/samples/MQTTAsync_publish_time.o ./Core/mqtt/samples/MQTTAsync_publish_time.su ./Core/mqtt/samples/MQTTClient_publish.cyclo ./Core/mqtt/samples/MQTTClient_publish.d ./Core/mqtt/samples/MQTTClient_publish.o ./Core/mqtt/samples/MQTTClient_publish.su ./Core/mqtt/samples/MQTTClient_publish_async.cyclo ./Core/mqtt/samples/MQTTClient_publish_async.d ./Core/mqtt/samples/MQTTClient_publish_async.o ./Core/mqtt/samples/MQTTClient_publish_async.su ./Core/mqtt/samples/MQTTClient_subscribe.cyclo ./Core/mqtt/samples/MQTTClient_subscribe.d ./Core/mqtt/samples/MQTTClient_subscribe.o ./Core/mqtt/samples/MQTTClient_subscribe.su ./Core/mqtt/samples/paho_c_pub.cyclo ./Core/mqtt/samples/paho_c_pub.d ./Core/mqtt/samples/paho_c_pub.o ./Core/mqtt/samples/paho_c_pub.su ./Core/mqtt/samples/paho_c_sub.cyclo ./Core/mqtt/samples/paho_c_sub.d ./Core/mqtt/samples/paho_c_sub.o ./Core/mqtt/samples/paho_c_sub.su ./Core/mqtt/samples/paho_cs_pub.cyclo ./Core/mqtt/samples/paho_cs_pub.d ./Core/mqtt/samples/paho_cs_pub.o ./Core/mqtt/samples/paho_cs_pub.su ./Core/mqtt/samples/paho_cs_sub.cyclo ./Core/mqtt/samples/paho_cs_sub.d ./Core/mqtt/samples/paho_cs_sub.o ./Core/mqtt/samples/paho_cs_sub.su ./Core/mqtt/samples/pubsub_opts.cyclo ./Core/mqtt/samples/pubsub_opts.d ./Core/mqtt/samples/pubsub_opts.o ./Core/mqtt/samples/pubsub_opts.su

.PHONY: clean-Core-2f-mqtt-2f-samples

