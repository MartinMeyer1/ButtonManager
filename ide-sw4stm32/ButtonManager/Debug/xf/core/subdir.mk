################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/behavior.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/customevent.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/initialevent.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/nulltransition.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/timeout.cpp 

OBJS += \
./xf/core/behavior.o \
./xf/core/customevent.o \
./xf/core/initialevent.o \
./xf/core/nulltransition.o \
./xf/core/timeout.o 

CPP_DEPS += \
./xf/core/behavior.d \
./xf/core/customevent.d \
./xf/core/initialevent.d \
./xf/core/nulltransition.d \
./xf/core/timeout.d 


# Each subdirectory must supply rules for building sources it contributes
xf/core/behavior.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/behavior.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/core/customevent.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/customevent.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/core/initialevent.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/initialevent.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/core/nulltransition.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/nulltransition.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xf/core/timeout.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/xf/core/timeout.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


