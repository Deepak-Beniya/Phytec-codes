################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Third-pary/SEGGER/OS/%.o Third-pary/SEGGER/OS/%.su Third-pary/SEGGER/OS/%.cyclo: ../Third-pary/SEGGER/OS/%.c Third-pary/SEGGER/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER/Syscalls" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-pary-2f-SEGGER-2f-OS

clean-Third-2d-pary-2f-SEGGER-2f-OS:
	-$(RM) ./Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.cyclo ./Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d ./Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o ./Third-pary/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-Third-2d-pary-2f-SEGGER-2f-OS

