/*
 * main.c
 *
 *  Created on: 2019 Oct 12 16:21:53
 *  Author: Pescatore
 */

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <math.h>
#include <stdio.h>
#include <xmc_ccu4.h>
#include <xmc_gpio.h>
#include <xmc_scu.h>

#define MODULE_PTR CCU42
#define MODULE_NUMBER (2U)
#define SLICE0_PTR CCU42_CC40
#define SLICE0_NUMBER (0U)
#define SLICE0_OUTPUT P3_0

volatile uint8_t count = 0;
uint16_t comparevalue[24] = /* sine table for duty cycle*/
{ 1333U, 988U, 667U, 390U, 179U, 45U, 0U, 45U, 179U, 390U, 667U, 988U, 1333U,
		1678U, 2000U, 2276U, 2487U, 2621U, 2666U, 2621U, 2487U, 2276U, 2000U,
		1678U, };





XMC_CCU4_SLICE_COMPARE_CONFIG_t SLICE0_config = { .timer_mode =
		(uint32_t) XMC_CCU4_SLICE_TIMER_COUNT_MODE_EA, .monoshot =
		(uint32_t) false, .shadow_xfer_clear = (uint32_t) 0,
		.dither_timer_period = (uint32_t) 0, .dither_duty_cycle = (uint32_t) 0,
		.prescaler_mode = (uint32_t) XMC_CCU4_SLICE_PRESCALER_MODE_NORMAL,
		.mcm_enable = (uint32_t) 0, .prescaler_initval = (uint32_t) 0, /* in this case, prescaler = 2^0 = 1 */
		.float_limit = (uint32_t) 0, .dither_limit = (uint32_t) 0,
		.passive_level = (uint32_t) XMC_CCU4_SLICE_OUTPUT_PASSIVE_LEVEL_LOW,
		.timer_concatenation = (uint32_t) 0 };

XMC_CCU4_SLICE_EVENT_CONFIG_t SLICE0_event0_config = { .mapped_input =
		XMC_CCU4_SLICE_INPUT_I, /* mapped to SCU.GSC40 */
.edge = XMC_CCU4_SLICE_EVENT_EDGE_SENSITIVITY_RISING_EDGE, .level =
		XMC_CCU4_SLICE_EVENT_LEVEL_SENSITIVITY_ACTIVE_HIGH, .duration =
		XMC_CCU4_SLICE_EVENT_FILTER_3_CYCLES };


XMC_GPIO_CONFIG_t SLICE0_OUTPUT_config =
{
.mode                = XMC_GPIO_MODE_OUTPUT_PUSH_PULL_ALT3,
.output_level        = XMC_GPIO_OUTPUT_LEVEL_LOW,
.output_strength     = XMC_GPIO_OUTPUT_STRENGTH_MEDIUM
};

void CCU42_0_IRQHandler(void) {
	/* Clear pending interrupt */
	XMC_CCU4_SLICE_ClearEvent(SLICE0_PTR,
			XMC_CCU4_SLICE_IRQ_ID_COMPARE_MATCH_UP);
	/* Set new duty cycle value */
	XMC_CCU4_SLICE_SetTimerCompareMatch(SLICE0_PTR, comparevalue[count]);
	count++;
	if (count == 24) {
		count = 0;
		DIGITAL_IO_ToggleOutput(&IO_Bit3);
		DIGITAL_IO_ToggleOutput(&IO_Bit2);
	}
	/* Enable shadow transfer for the new PWM value update */
	XMC_CCU4_EnableShadowTransfer(MODULE_PTR, XMC_CCU4_SHADOW_TRANSFER_SLICE_0);
}






XMC_VADC_RESULT_SIZE_t result;
void Adc_Measurement_Handler() {
#if(UC_SERIES != XMC11)
	result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A);
	float resistor = 10000 * (pow(2, 12) / result - 1);
	float beta = 601.3;
	float T = (((float) (beta * 298.15))
			/ (((float) (298.15 * log(resistor / 10000))) + beta)) - 273.15;

//	printf("T_Ambient is %f\n", T);
#else
	result = ADC_MEASUREMENT_GetGlobalResult();
#endif

	if (result >= 2048) {
		//   DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);
	} else {
		// DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0);
	}
}

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

uint8_t data[] = "BDA Andy Fischer";

uint8_t rec_data[10];

void EndofTransmit() //Callback function for "End of transmit" event.

{
	UART_Receive(&UART_0, rec_data, sizeof(rec_data));
	DIGITAL_IO_SetOutputLow(&RS485_DIR); // ready to receive
}

void EndofReceive() //Callback function for "End of receive" event.

{
	DIGITAL_IO_SetOutputHigh(&RS485_DIR);
	char value = rec_data[0];
	if (value = 'a') {
		DIGITAL_IO_SetOutputHigh(&IO_Bit2);
	}
	UART_Transmit(&UART_0, rec_data, sizeof(rec_data));
}

float calculate_T_Amb() {

}

float temp;
int fan_flag = 0;
int io_status = -1;
int main(void) {
	DAVE_STATUS_t status;
	uint32_t pin_status;
	uint32_t delay_count;

	status = DAVE_Init(); /* Initialization of DAVE APPs  */

	if (status != DAVE_STATUS_SUCCESS) {
		/* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
		XMC_DEBUG("DAVE APPs initialization failed\n");

		while (1U) {

		}
	}

	DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_6); // Enable RS485 Pin
	DIGITAL_IO_SetOutputHigh(&RS485_DIR); // Direction RS485 Pin set to High to indicate that MCU wants to send data
//UART_Transmit(&UART_0, data, sizeof(data) - 1); //Transmit the string "Infineon Technologies".

//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_4); // Power up Main heating
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_5); // Power up aux heating

	DIGITAL_IO_SetOutputLow(&IO_Bit0_DIR); // Set Input enable for IO Pin 0
	DIGITAL_IO_SetOutputLow(&IO_Bit1_DIR); // Set Input enable for IO Pin 1
	DIGITAL_IO_SetOutputHigh(&IO_Bit3_DIR); // Set Input enable for IO Pin 3
	DIGITAL_IO_SetOutputHigh(&IO_Bit2_DIR); // Set Input enable for IO Pin 2

//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_23);// Set Output Pin 0 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_22); // Set Output Pin 1 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_21); // Set Output Pin 2 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_24); // Set Output Pin 3 high

	delay_count = 0;

//ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_1);

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */

	DIGITAL_IO_SetOutputHigh(&Disable_Gate_Driver_M1_M2); // Set Output Pin 0 high
	DIGITAL_IO_SetOutputHigh(&Disable_Gate_Driver_M3); // Set Output Pin 0 high


	XMC_CCU4_SLICE_EnableEvent(SLICE0_PTR, XMC_CCU4_SLICE_IRQ_ID_PERIOD_MATCH);
		/* Connect compare match event to SR0 */
	XMC_CCU4_SLICE_SetInterruptNode(SLICE0_PTR, \
			XMC_CCU4_SLICE_IRQ_ID_PERIOD_MATCH, XMC_CCU4_SLICE_SR_ID_0);

	/* Set NVIC priority */
	NVIC_SetPriority(CCU42_0_IRQn, 3U);
	/* Enable IRQ */
	NVIC_EnableIRQ(CCU42_0_IRQn);
	/* Enable CCU4 PWM output */
	//XMC_GPIO_Init((XMC_GPIO_PORT_t *) PORT0_BASE,12U, &SLICE0_OUTPUT_config);
	/* Get the slice out of idle mode */
	//XMC_CCU4_EnableClock(MODULE_PTR, SLICE0_NUMBER);

	/* Start the TImer*/
	//XMC_CCU4_SLICE_StartTimer(SLICE0_PTR);

//ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_0);

	while (1U) {

		// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
		// for(delay_count = 0;delay_count<0xfffff;delay_count++);
		//    delay_count = delay_count + 10;
		// pin_status = DIGITAL_IO_GetInput(&DIGITAL_IO_23);

		if (((!fan_flag) && DIGITAL_IO_GetInput(&IO_Bit0))
				|| (DIGITAL_IO_GetInput(&HS_Overtemp))) {
			fan_flag = 1;
			DIGITAL_IO_SetOutputHigh(&Cooling_FAN); // Power up cooling fan
		}

		else if (fan_flag && DIGITAL_IO_GetInput(&IO_Bit1)) {
			fan_flag = 0;
			DIGITAL_IO_SetOutputLow(&Cooling_FAN); // Power down cooling fan
		}

		// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_23); // toggle PIN 0
		// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_22); // toggle PIN 1
		// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_21); // toggle PIN 2
		// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_24); // toggle PIN 3

		//ADC_MEASUREMENT_StartConversion(&ADC_MEASUREMENT_0);

		//temp = calculate_T_Amb();

	}
}
