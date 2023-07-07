################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third-pary/SEGGER/SEGGER/SEGGER_RTT.c \
../Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.c \
../Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
../Third-pary/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./Third-pary/SEGGER/SEGGER/SEGGER_RTT.o \
./Third-pary/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./Third-pary/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./Third-pary/SEGGER/SEGGER/SEGGER_RTT.d \
./Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
Third-pary/SEGGER/SEGGER/%.o Third-pary/SEGGER/SEGGER/%.su Third-pary/SEGGER/SEGGER/%.cyclo: ../Third-pary/SEGGER/SEGGER/%.c Third-pary/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/OS" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/SEGGER/SEGGER/Syscalls" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/Config" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/include" -I"/home/vasundhra/deepak/Workspace/Module2/RTOS_Workspace/P1_Hello_World/Third-pary/FreeRTOS/org/Source/portable/GCC/ARM_CM4F" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Third-pary/SEGGER/SEGGER/%.o: ../Third-pary/SEGGER/SEGGER/%.S Third-pary/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Third-2d-pary-2f-SEGGER-2f-SEGGER

clean-Third-2d-pary-2f-SEGGER-2f-SEGGER:
	-$(RM) ./Third-pary/SEGGER/SEGGER/SEGGER_RTT.cyclo ./Third-pary/SEGGER/SEGGER/SEGGER_RTT.d ./Third-pary/SEGGER/SEGGER/SEGGER_RTT.o ./Third-pary/SEGGER/SEGGER/SEGGER_RTT.su ./Third-pary/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./Third-pary/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.cyclo ./Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.d ./Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.o ./Third-pary/SEGGER/SEGGER/SEGGER_RTT_printf.su ./Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.cyclo ./Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./Third-pary/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-Third-2d-pary-2f-SEGGER-2f-SEGGER

