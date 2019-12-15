################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config.c \
../Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config_conf.c 

OBJS += \
./Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config.o \
./Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config_conf.o 

C_DEPS += \
./Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config.d \
./Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config_conf.d 


# Each subdirectory must supply rules for building sources it contributes
Dave/Generated/CCU8_SLICE_CONFIG/%.o: ../Dave/Generated/CCU8_SLICE_CONFIG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM-GCC C Compiler'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -MMD -MT "$@" -DXMC4400_F100x512 -I"$(PROJECT_LOC)/Libraries/XMCLib/inc" -I"$(PROJECT_LOC)/Libraries/CMSIS/Include" -I"$(PROJECT_LOC)/Libraries/CMSIS/Infineon/XMC4400_series/Include" -I"$(PROJECT_LOC)" -I"$(PROJECT_LOC)/Dave/Generated" -I"$(PROJECT_LOC)/Libraries" -O0 -ffunction-sections -fdata-sections -Wall -std=gnu99 -mfloat-abi=softfp -Wa,-adhlns="$@.lst" -pipe -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d) $@" -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb -g -gdwarf-2 -o "$@" "$<" 
	@echo 'Finished building: $<'
	@echo.

