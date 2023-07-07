################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/FreeRTOS/croutine.c \
../Third_Party/FreeRTOS/event_groups.c \
../Third_Party/FreeRTOS/list.c \
../Third_Party/FreeRTOS/queue.c \
../Third_Party/FreeRTOS/stream_buffer.c \
../Third_Party/FreeRTOS/tasks.c \
../Third_Party/FreeRTOS/timers.c 

OBJS += \
./Third_Party/FreeRTOS/croutine.o \
./Third_Party/FreeRTOS/event_groups.o \
./Third_Party/FreeRTOS/list.o \
./Third_Party/FreeRTOS/queue.o \
./Third_Party/FreeRTOS/stream_buffer.o \
./Third_Party/FreeRTOS/tasks.o \
./Third_Party/FreeRTOS/timers.o 

C_DEPS += \
./Third_Party/FreeRTOS/croutine.d \
./Third_Party/FreeRTOS/event_groups.d \
./Third_Party/FreeRTOS/list.d \
./Third_Party/FreeRTOS/queue.d \
./Third_Party/FreeRTOS/stream_buffer.d \
./Third_Party/FreeRTOS/tasks.d \
./Third_Party/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/FreeRTOS/%.o Third_Party/FreeRTOS/%.su Third_Party/FreeRTOS/%.cyclo: ../Third_Party/FreeRTOS/%.c Third_Party/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/FreeRTOS/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/FreeRTOS/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party-2f-FreeRTOS

clean-Third_Party-2f-FreeRTOS:
	-$(RM) ./Third_Party/FreeRTOS/croutine.cyclo ./Third_Party/FreeRTOS/croutine.d ./Third_Party/FreeRTOS/croutine.o ./Third_Party/FreeRTOS/croutine.su ./Third_Party/FreeRTOS/event_groups.cyclo ./Third_Party/FreeRTOS/event_groups.d ./Third_Party/FreeRTOS/event_groups.o ./Third_Party/FreeRTOS/event_groups.su ./Third_Party/FreeRTOS/list.cyclo ./Third_Party/FreeRTOS/list.d ./Third_Party/FreeRTOS/list.o ./Third_Party/FreeRTOS/list.su ./Third_Party/FreeRTOS/queue.cyclo ./Third_Party/FreeRTOS/queue.d ./Third_Party/FreeRTOS/queue.o ./Third_Party/FreeRTOS/queue.su ./Third_Party/FreeRTOS/stream_buffer.cyclo ./Third_Party/FreeRTOS/stream_buffer.d ./Third_Party/FreeRTOS/stream_buffer.o ./Third_Party/FreeRTOS/stream_buffer.su ./Third_Party/FreeRTOS/tasks.cyclo ./Third_Party/FreeRTOS/tasks.d ./Third_Party/FreeRTOS/tasks.o ./Third_Party/FreeRTOS/tasks.su ./Third_Party/FreeRTOS/timers.cyclo ./Third_Party/FreeRTOS/timers.d ./Third_Party/FreeRTOS/timers.o ./Third_Party/FreeRTOS/timers.su

.PHONY: clean-Third_Party-2f-FreeRTOS

