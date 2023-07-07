################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.c 

OBJS += \
./Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Third-pary/FreeRTOS/org/Source/portable/MemMang/%.o Third-pary/FreeRTOS/org/Source/portable/MemMang/%.su Third-pary/FreeRTOS/org/Source/portable/MemMang/%.cyclo: ../Third-pary/FreeRTOS/org/Source/portable/MemMang/%.c Third-pary/FreeRTOS/org/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER/Syscalls" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-pary-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-MemMang

clean-Third-2d-pary-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.cyclo ./Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.d ./Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.o ./Third-pary/FreeRTOS/org/Source/portable/MemMang/heap_4.su

.PHONY: clean-Third-2d-pary-2f-FreeRTOS-2f-org-2f-Source-2f-portable-2f-MemMang

