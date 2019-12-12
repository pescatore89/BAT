/*
 * main.c
 *
 *  Created on: 2019 Oct 12 16:21:53
 *  Author: Pescatore
 */

#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

XMC_VADC_RESULT_SIZE_t result;
void Adc_Measurement_Handler() {
#if(UC_SERIES != XMC11)
	result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A);
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
	if(value='a'){
    	DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_21);
    }
	UART_Transmit(&UART_0, rec_data, sizeof(rec_data));
}



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
UART_Transmit(&UART_0, data, sizeof(data) - 1); //Transmit the string "Infineon Technologies".


//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0); // Power up cooling fan
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_4); // Power up Main heating
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_5); // Power up aux heating

DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_17);// Set Output enable for IO Pin 0
DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_16);// Set Output enable for IO Pin 1
DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_19);// Set Output enable for IO Pin 3
DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_20);// Set Output enable for IO Pin 2

DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_23);// Set Output Pin 0 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_21); // Set Output Pin 2 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_22); // Set Output Pin 1 high
//DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_24); // Set Output Pin 3 high

// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_23); // toggle PIN 0

delay_count = 0;




//ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_1);

/* Placeholder for user application code. The while loop below can be replaced with user application code. */

DIGITAL_IO_SetOutputHigh(&Disable_Gate_Driver_M1_M2);// Set Output Pin 0 high
DIGITAL_IO_SetOutputHigh(&Disable_Gate_Driver_M3);// Set Output Pin 0 high

//ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_0);

while(1U)
{

	// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_0);
	// for(delay_count = 0;delay_count<0xfffff;delay_count++);
	//    delay_count = delay_count + 10;
	// pin_status = DIGITAL_IO_GetInput(&DIGITAL_IO_23);

	// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_23); // toggle PIN 0
	// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_22); // toggle PIN 1
	// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_21); // toggle PIN 2
	// DIGITAL_IO_ToggleOutput(&DIGITAL_IO_24); // toggle PIN 3

}
}
