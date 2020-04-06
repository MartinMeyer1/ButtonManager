################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evbuttonirq.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evbuttonpressed.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evbuttonreleased.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evlongpress.cpp \
C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evshortpress.cpp 

OBJS += \
./event/evbuttonirq.o \
./event/evbuttonpressed.o \
./event/evbuttonreleased.o \
./event/evlongpress.o \
./event/evshortpress.o 

CPP_DEPS += \
./event/evbuttonirq.d \
./event/evbuttonpressed.d \
./event/evbuttonreleased.d \
./event/evlongpress.d \
./event/evshortpress.d 


# Each subdirectory must supply rules for building sources it contributes
event/evbuttonirq.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evbuttonirq.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

event/evbuttonpressed.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evbuttonpressed.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

event/evbuttonreleased.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evbuttonreleased.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

event/evlongpress.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evlongpress.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

event/evshortpress.o: C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/src/event/evshortpress.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F746xx -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/STM32F7xx_HAL_Driver/Inc/Legacy" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Device/ST/STM32F7xx/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/Drivers/CMSIS/Include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/include" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/xf/port/default-idf" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/platform/f7-disco-gcc/mcu" -I"C:/Users/meyer/Saved/Hes/PTR/02-laboratory/work/ButtonManager/ide-sw4stm32/ButtonManager/../../src/mdw"  -O2 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


