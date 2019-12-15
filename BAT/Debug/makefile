################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Libraries/XMCLib/src/subdir.mk
-include Libraries/Newlib/subdir.mk
-include Dave/Generated/UART_CONFIG/subdir.mk
-include Dave/Generated/UART/subdir.mk
-include Dave/Generated/SYSTIMER/subdir.mk
-include Dave/Generated/PWM_SVM/subdir.mk
-include Dave/Generated/PWM_CCU4/subdir.mk
-include Dave/Generated/MOTOR_LIB/subdir.mk
-include Dave/Generated/I2C_MASTER/subdir.mk
-include Dave/Generated/GLOBAL_CCU8/subdir.mk
-include Dave/Generated/GLOBAL_CCU4/subdir.mk
-include Dave/Generated/GLOBAL_ADC/subdir.mk
-include Dave/Generated/DIGITAL_IO/subdir.mk
-include Dave/Generated/CPU_CTRL_XMC4/subdir.mk
-include Dave/Generated/CLOCK_XMC4/subdir.mk
-include Dave/Generated/CCU8_SLICE_CONFIG/subdir.mk
-include Dave/Generated/AUTOMATION/subdir.mk
-include Dave/Generated/ANALOG_IO/subdir.mk
-include Dave/Generated/ADC_MEASUREMENT/subdir.mk
-include Dave/Generated/ACIM_FREQ_CTRL/subdir.mk
-include Dave/Generated/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
BAT.hex \

SECONDARY_LIST += \
BAT.lst \

SECONDARY_SIZE += \
BAT.siz \


LIST_FILES = $(addsuffix .o.lst, $(basename $(OBJS))) 
MAP_FILE = "BAT.map"

TOOLCHAIN_ROOT=C:/Users/Pescatore/switchdrive/Private/Konzept/MCU for Gate driver/DAVE_4-4-2_64bit_2018-02-23/DAVE-IDE-4.4.2-64Bit/eclipse/ARM-GCC-49
PROJECT_LOC=F:/GitHub Projects/FH Luzern/BAT/BAT

# All Target
all: BAT.elf secondary-outputs

# Tool invocations
BAT.elf: $(OBJS) ../linker_script.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	$(file >objects.rsp,$(OBJS))
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-gcc" -T"../linker_script.ld" -nostartfiles -Xlinker --gc-sections -specs=nano.specs -specs=nosys.specs -Wl,-Map,$(MAP_FILE) -mfloat-abi=softfp -mfpu=fpv4-sp-d16 -mcpu=cortex-m4 -mthumb -g -gdwarf-2 -o "BAT.elf" "@objects.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo.
BAT.hex: BAT.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objcopy" -O ihex "BAT.elf" "BAT.hex"
	@echo 'Finished building: $@'
	@echo.
BAT.lst: BAT.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-objdump" -h -S "BAT.elf" > "BAT.lst"
	@echo 'Finished building: $@'
	@echo.
BAT.siz: BAT.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"$(TOOLCHAIN_ROOT)/bin/arm-none-eabi-size" --format=berkeley "BAT.elf"
	@echo 'Finished building: $@'
	@echo.
# Other Targets
clean:
	-$(RM) $(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS)
	-$(RM) Dave/Generated/ACIM_FREQ_CTRL/acim_freq_ctrl.o Dave/Generated/ACIM_FREQ_CTRL/acim_freq_ctrl_conf.o Dave/Generated/ACIM_FREQ_CTRL/acim_freq_ctrl_control.o Dave/Generated/ADC_MEASUREMENT/adc_measurement.o Dave/Generated/ADC_MEASUREMENT/adc_measurement_conf.o Dave/Generated/ANALOG_IO/analog_io.o Dave/Generated/ANALOG_IO/analog_io_conf.o Dave/Generated/AUTOMATION/automation.o Dave/Generated/AUTOMATION/automation_conf.o Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config.o Dave/Generated/CCU8_SLICE_CONFIG/ccu8_slice_config_conf.o Dave/Generated/CLOCK_XMC4/clock_xmc4.o Dave/Generated/CLOCK_XMC4/clock_xmc4_conf.o Dave/Generated/CPU_CTRL_XMC4/cpu_ctrl_xmc4.o Dave/Generated/CPU_CTRL_XMC4/cpu_ctrl_xmc4_conf.o Dave/Generated/DAVE.o Dave/Generated/DIGITAL_IO/digital_io.o Dave/Generated/DIGITAL_IO/digital_io_conf.o Dave/Generated/GLOBAL_ADC/global_adc.o Dave/Generated/GLOBAL_ADC/global_adc_conf.o Dave/Generated/GLOBAL_CCU4/global_ccu4.o Dave/Generated/GLOBAL_CCU4/global_ccu4_conf.o Dave/Generated/GLOBAL_CCU8/global_ccu8.o Dave/Generated/GLOBAL_CCU8/global_ccu8_conf.o Dave/Generated/I2C_MASTER/i2c_master.o Dave/Generated/I2C_MASTER/i2c_master_conf.o Dave/Generated/MOTOR_LIB/motor_lib.o Dave/Generated/PWM_CCU4/pwm_ccu4.o Dave/Generated/PWM_CCU4/pwm_ccu4_conf.o Dave/Generated/PWM_SVM/pwm_svm.o Dave/Generated/PWM_SVM/pwm_svm_conf.o Dave/Generated/PWM_SVM/pwm_svm_table.o Dave/Generated/SYSTIMER/systimer.o Dave/Generated/SYSTIMER/systimer_conf.o Dave/Generated/UART/uart.o Dave/Generated/UART/uart_conf.o Dave/Generated/UART_CONFIG/uart_config.o Dave/Generated/UART_CONFIG/uart_config_conf.o Libraries/Newlib/syscalls.o Libraries/XMCLib/src/xmc4_eru.o Libraries/XMCLib/src/xmc4_flash.o Libraries/XMCLib/src/xmc4_gpio.o Libraries/XMCLib/src/xmc4_rtc.o Libraries/XMCLib/src/xmc4_scu.o Libraries/XMCLib/src/xmc_can.o Libraries/XMCLib/src/xmc_ccu4.o Libraries/XMCLib/src/xmc_ccu8.o Libraries/XMCLib/src/xmc_common.o Libraries/XMCLib/src/xmc_dac.o 
	-$(RM) Libraries/XMCLib/src/xmc_dma.o Libraries/XMCLib/src/xmc_dsd.o Libraries/XMCLib/src/xmc_ebu.o Libraries/XMCLib/src/xmc_ecat.o Libraries/XMCLib/src/xmc_eru.o Libraries/XMCLib/src/xmc_eth_mac.o Libraries/XMCLib/src/xmc_eth_phy_dp83848.o Libraries/XMCLib/src/xmc_eth_phy_ksz8031rnl.o Libraries/XMCLib/src/xmc_eth_phy_ksz8081rnb.o Libraries/XMCLib/src/xmc_fce.o Libraries/XMCLib/src/xmc_gpio.o Libraries/XMCLib/src/xmc_hrpwm.o Libraries/XMCLib/src/xmc_i2c.o Libraries/XMCLib/src/xmc_i2s.o Libraries/XMCLib/src/xmc_ledts.o Libraries/XMCLib/src/xmc_posif.o Libraries/XMCLib/src/xmc_rtc.o Libraries/XMCLib/src/xmc_sdmmc.o Libraries/XMCLib/src/xmc_spi.o Libraries/XMCLib/src/xmc_uart.o Libraries/XMCLib/src/xmc_usbd.o Libraries/XMCLib/src/xmc_usbh.o Libraries/XMCLib/src/xmc_usic.o Libraries/XMCLib/src/xmc_vadc.o Libraries/XMCLib/src/xmc_wdt.o Startup/startup_XMC4400.o Startup/system_XMC4400.o main.o  BAT.elf $(LIST_FILES) $(MAP_FILE) objects.rsp
	-@echo.
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
