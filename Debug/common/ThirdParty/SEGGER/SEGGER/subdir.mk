################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c \
D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c \
D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o: D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c common/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS/include" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/Config" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/OS" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S common/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/Config" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o: D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c common/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS/include" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/Config" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/OS" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o: D:/STM32/C\ Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c common/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS/include" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS/portable/GCC/ARM_CM4F" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/Config" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/OS" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/SEGGER/SEGGER" -I"D:/STM32/C Embedded/RTOS_workspace/common/ThirdParty/FreeRTOS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-common-2f-ThirdParty-2f-SEGGER-2f-SEGGER

clean-common-2f-ThirdParty-2f-SEGGER-2f-SEGGER:
	-$(RM) ./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d ./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o ./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d ./common/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o ./common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./common/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o

.PHONY: clean-common-2f-ThirdParty-2f-SEGGER-2f-SEGGER

