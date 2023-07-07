################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-pary/FreeRTOS/org/Source/croutine.c \
../Third-pary/FreeRTOS/org/Source/event_groups.c \
../Third-pary/FreeRTOS/org/Source/list.c \
../Third-pary/FreeRTOS/org/Source/queue.c \
../Third-pary/FreeRTOS/org/Source/stream_buffer.c \
../Third-pary/FreeRTOS/org/Source/tasks.c \
../Third-pary/FreeRTOS/org/Source/timers.c 

OBJS += \
./Third-pary/FreeRTOS/org/Source/croutine.o \
./Third-pary/FreeRTOS/org/Source/event_groups.o \
./Third-pary/FreeRTOS/org/Source/list.o \
./Third-pary/FreeRTOS/org/Source/queue.o \
./Third-pary/FreeRTOS/org/Source/stream_buffer.o \
./Third-pary/FreeRTOS/org/Source/tasks.o \
./Third-pary/FreeRTOS/org/Source/timers.o 

C_DEPS += \
./Third-pary/FreeRTOS/org/Source/croutine.d \
./Third-pary/FreeRTOS/org/Source/event_groups.d \
./Third-pary/FreeRTOS/org/Source/list.d \
./Third-pary/FreeRTOS/org/Source/queue.d \
./Third-pary/FreeRTOS/org/Source/stream_buffer.d \
./Third-pary/FreeRTOS/org/Source/tasks.d \
./Third-pary/FreeRTOS/org/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third-pary/FreeRTOS/org/Source/%.o Third-pary/FreeRTOS/org/Source/%.su Third-pary/FreeRTOS/org/Source/%.cyclo: ../Third-pary/FreeRTOS/org/Source/%.c Third-pary/FreeRTOS/org/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER/Syscalls" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-pary-2f-FreeRTOS-2f-org-2f-Source

clean-Third-2d-pary-2f-FreeRTOS-2f-org-2f-Source:
	-$(RM) ./Third-pary/FreeRTOS/org/Source/croutine.cyclo ./Third-pary/FreeRTOS/org/Source/croutine.d ./Third-pary/FreeRTOS/org/Source/croutine.o ./Third-pary/FreeRTOS/org/Source/croutine.su ./Third-pary/FreeRTOS/org/Source/event_groups.cyclo ./Third-pary/FreeRTOS/org/Source/event_groups.d ./Third-pary/FreeRTOS/org/Source/event_groups.o ./Third-pary/FreeRTOS/org/Source/event_groups.su ./Third-pary/FreeRTOS/org/Source/list.cyclo ./Third-pary/FreeRTOS/org/Source/list.d ./Third-pary/FreeRTOS/org/Source/list.o ./Third-pary/FreeRTOS/org/Source/list.su ./Third-pary/FreeRTOS/org/Source/queue.cyclo ./Third-pary/FreeRTOS/org/Source/queue.d ./Third-pary/FreeRTOS/org/Source/queue.o ./Third-pary/FreeRTOS/org/Source/queue.su ./Third-pary/FreeRTOS/org/Source/stream_buffer.cyclo ./Third-pary/FreeRTOS/org/Source/stream_buffer.d ./Third-pary/FreeRTOS/org/Source/stream_buffer.o ./Third-pary/FreeRTOS/org/Source/stream_buffer.su ./Third-pary/FreeRTOS/org/Source/tasks.cyclo ./Third-pary/FreeRTOS/org/Source/tasks.d ./Third-pary/FreeRTOS/org/Source/tasks.o ./Third-pary/FreeRTOS/org/Source/tasks.su ./Third-pary/FreeRTOS/org/Source/timers.cyclo ./Third-pary/FreeRTOS/org/Source/timers.d ./Third-pary/FreeRTOS/org/Source/timers.o ./Third-pary/FreeRTOS/org/Source/timers.su

.PHONY: clean-Third-2d-pary-2f-FreeRTOS-2f-org-2f-Source

