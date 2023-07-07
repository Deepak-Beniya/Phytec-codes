################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Third_Party/SEGGER/OS/%.o Third_Party/SEGGER/OS/%.su Third_Party/SEGGER/OS/%.cyclo: ../Third_Party/SEGGER/OS/%.c Third_Party/SEGGER/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/FreeRTOS/portable/MemMang" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/FreeRTOS/portable/GCC/ARM_CM4F" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/p2/Third_Party/SEGGER/SEGGER" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third_Party-2f-SEGGER-2f-OS

clean-Third_Party-2f-SEGGER-2f-OS:
	-$(RM) ./Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.cyclo ./Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d ./Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o ./Third_Party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-Third_Party-2f-SEGGER-2f-OS

