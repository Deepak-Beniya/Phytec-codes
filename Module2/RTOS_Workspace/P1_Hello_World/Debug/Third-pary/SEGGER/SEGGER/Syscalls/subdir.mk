################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c 

OBJS += \
./Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o 

C_DEPS += \
./Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d 


# Each subdirectory must supply rules for building sources it contributes
Third-pary/SEGGER/SEGGER/Syscalls/%.o Third-pary/SEGGER/SEGGER/Syscalls/%.su Third-pary/SEGGER/SEGGER/Syscalls/%.cyclo: ../Third-pary/SEGGER/SEGGER/Syscalls/%.c Third-pary/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER/Syscalls" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Third-2d-pary-2f-SEGGER-2f-SEGGER-2f-Syscalls

clean-Third-2d-pary-2f-SEGGER-2f-SEGGER-2f-Syscalls:
	-$(RM) ./Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.cyclo ./Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d ./Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o ./Third-pary/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.su

.PHONY: clean-Third-2d-pary-2f-SEGGER-2f-SEGGER-2f-Syscalls

