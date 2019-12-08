/*
 * main.c
 *
 *  Created on: 2019 Oct 12 16:21:53
 *  Author: Pescatore
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

XMC_VADC_RESULT_SIZE_t result;
 void Adc_Measurement_Handler(){
#if(UC_SERIES != XMC11)
    result = ADC_MEASUREMENT_GetResult(&ADC_MEASUREMENT_Channel_A);
#else
    result = ADC_MEASUREMENT_GetGlobalResult();
#endif

    if(result >= 2048)
    {
     //   DIGITAL_IO_SetOutputLow(&DIGITAL_IO_0);
    }
    else
    {
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

int main(void)
{
  DAVE_STATUS_t status;
  uint32_t pin_status;
  uint32_t delay_count;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {



    }
  }

  //DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_0); // Power up cooling fan
  //DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_4); // Power up Main heating
  //DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_5); // Power up aux heating

  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_17); // Set Output enable for IO Pin 0
  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_16); // Set Output enable for IO Pin 1
  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_19); // Set Output enable for IO Pin 3
  DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_20); // Set Output enable for IO Pin 2
 // DIGITAL_IO_SetOutputHigh(&DIGITAL_IO_23); // Set Output Pin 0 high

  delay_count=0;

  //ADC_MEASUREMENT_StartConversion(&ADC_MEASUREMENT_0);
  //ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_0);
  //ACIM_FREQ_CTRL_SetSpeed(&ACIM_FREQ_CTRL_0, 50);
   ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_1);
  //ACIM_FREQ_CTRL_SetSpeed(&ACIM_FREQ_CTRL_1, 10);
   ACIM_FREQ_CTRL_MotorStop(&ACIM_FREQ_CTRL_1);
  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
   int outputBit0 = 0;
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

	     if(pin_status == 1)
	     {
	       outputBit0 = outputBit0+1;

	     }
	     else
	     {
	       // Add application code here
	     }




  }
}
