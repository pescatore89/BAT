/*
 * main.c
 *
 *  Created on: 2019 Oct 12 16:21:53
 *  Author: Pescatore
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

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


  delay_count=0;

  ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_0);
  ACIM_FREQ_CTRL_SetSpeed(&ACIM_FREQ_CTRL_0, 50);
 // ACIM_FREQ_CTRL_MotorStart(&ACIM_FREQ_CTRL_1);
  //ACIM_FREQ_CTRL_SetSpeed(&ACIM_FREQ_CTRL_1, 10);

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
     // DIGITAL_IO_ToggleOutput(&DIGITAL_IO_9); //toggles level at pin
     // for(delay_count = 0;delay_count<0xfffff;delay_count++);
   //    delay_count = delay_count + 10;

  }
}
