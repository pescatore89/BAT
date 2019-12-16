/*
 * main.c
 *
 *  Created on: 2019 Oct 12 16:21:53
 *  Author: Pescatore
 */

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <math.h>
#include <stdio.h>
XMC_VADC_RESULT_SIZE_t result;
void Adc_Measurement_Handler() {
#if(UC_SERIES != XMC11)
	result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A);
	float resistor = 10000 * (pow(2, 12) / result - 1);
	float beta = 601.3;
	float T = (((float)(beta * 298.15)) / (((float)(298.15 * log(resistor / 10000))) + beta))-273.15;

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
	DIGITAL_IO_SetOutputLow(&IO_Bit3_DIR); // Set Input enable for IO Pin 3
	DIGITAL_IO_SetOutputLow(&IO_Bit2_DIR); // Set Input enable for IO Pin 2

//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_23);// Set Output Pin 0 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_22); // Set Output Pin 1 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_21); // Set Output Pin 2 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_24); // Set Output Pin 3 high

	delay_count = 0;

//ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_1);

	/* Placeholder for user application code. The while loop below can be replaced with user application code. */

	DIGITAL_IO_SetOutputHigh(&Disable_Gate_Driver_M1_M2); // Set Output Pin 0 high
	DIGITAL_IO_SetOutputHigh(&Disable_Gate_Driver_M3); // Set Output Pin 0 high




//ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_0);

	while (1U) {

		// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
		// for(delay_count = 0;delay_count<0xfffff;delay_count++);
		//    delay_count = delay_count + 10;
		// pin_status = DIGITAL_IO_GetInput(&DIGITAL_IO_23);

		if (((!fan_flag) && DIGITAL_IO_GetInput(&IO_Bit0))||(DIGITAL_IO_GetInput(&HS_Overtemp))) {
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
