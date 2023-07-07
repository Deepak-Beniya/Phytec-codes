################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/FreeRTOS/portable/MemMang/heap_4.c 

OBJS += \
./Third_Party/FreeRTOS/portable/MemMang/heap_4.o 

C_DEPS += \
./Third_Party/FreeRTOS/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/FreeRTOS/portable/MemMang/%.o Third_Party/FreeRTOS/portable/MemMang/%.su Third_Party/FreeRTOS/portable/MemMang/%.cyclo: ../Third_Party/FreeRTOS/portable/MemMang/%.c Third_Party/FreeRTOS/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/FreeRTOS/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/FreeRTOS/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/RTOS_Segger/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang

clean-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang:
	-$(RM) ./Third_Party/FreeRTOS/portable/MemMang/heap_4.cyclo ./Third_Party/FreeRTOS/portable/MemMang/heap_4.d ./Third_Party/FreeRTOS/portable/MemMang/heap_4.o ./Third_Party/FreeRTOS/portable/MemMang/heap_4.su

.PHONY: clean-Third_Party-2f-FreeRTOS-2f-portable-2f-MemMang

