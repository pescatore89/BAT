/*********************************************************************************************************************
* DAVE APP Name : ACIM_FREQ_CTRL       APP Version: 4.0.8
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes
 * with Infineon Technologies AG (dave@infineon.com).
 ***********************************************************************************************************************
 *
 * Change History
 * --------------
 *
 * 2015-02-16:
 *     - Initial version
 * 2015-10-08:
 *     - Amplitude scaling is matched with PWM_SVM APP amplitude scaling
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "acim_freq_ctrl.h"

void ACIM_FREQ_CTRL_0_PrimaryControlLoop(ACIM_FREQ_CTRL_t*const HandlePtr);  
void ACIM_FREQ_CTRL_0_SetValueProcessing(ACIM_FREQ_CTRL_t*const HandlePtr);

void ACIM_FREQ_CTRL_0_FastControlLoop_ISR()
{  
  int32_t temp_angle;

  /************************* Trap ***************************/
  if(XMC_CCU8_SLICE_GetEvent(ACIM_FREQ_CTRL_0.pwm_svm_ptr->phase_ptr[0]->slice_ptr,XMC_CCU8_SLICE_IRQ_ID_EVENT2) == (uint32_t)true)
  {
    ACIM_FREQ_CTRL_0.operational_error |= (uint32_t)1<<(uint32_t)ACIM_FREQ_CTRL_EID_TRAP_ERROR;
	ACIM_FREQ_CTRL_0.error_table_ptr[ACIM_FREQ_CTRL_EID_TRAP_ERROR].error_status = (uint8_t)ACIM_FREQ_CTRL_ERROR_SET;
    /* Stop the motor */
    if(ACIM_FREQ_CTRL_0.error_table_ptr[ACIM_FREQ_CTRL_EID_TRAP_ERROR].error_handler_ptr_t != NULL)
    {
      (ACIM_FREQ_CTRL_0.error_table_ptr[ACIM_FREQ_CTRL_EID_TRAP_ERROR].error_handler_ptr_t)(&ACIM_FREQ_CTRL_0);
    }
  }
  else
  {
/************************* Fast Control Loop ***************************/

    if(ACIM_FREQ_CTRL_0.fcl_div_value == ACIM_FREQ_CTRL_0.acim_config_ptr->fcl_divider)
    {
      ACIM_FREQ_CTRL_0.fcl_div_value = 1;

      if(ACIM_FREQ_CTRL_0.msm_state != ACIM_FREQ_CTRL_MSM_BOOTSTRAP)
      {

        /*Current is 0 because current measurement is disabled.*/
        ACIM_FREQ_CTRL_0.motor_current = 0U;

        /*Updating input of v/f control*/
        ACIM_FREQ_CTRL_0.vf_control_ptr->input = (int32_t)*ACIM_FREQ_CTRL_0.speed_set_ptr;

        /*amplitude calculation*/
        ACIM_FREQ_CTRL_Amplitude_Calculation(&ACIM_FREQ_CTRL_0);

        /*angle calculation*/
        ACIM_FREQ_CTRL_AngleRamp(&ACIM_FREQ_CTRL_0);


        /*Update Modulation Angle and Amplitude before calling svm*/
        temp_angle = ACIM_FREQ_CTRL_0.vf_control_ptr->output_angle + (ACIM_FREQ_CTRL_0.angle_offset * ACIM_FREQ_CTRL_0.motor_direction);
        ACIM_FREQ_CTRL_0.angle     = (uint32_t)(temp_angle);
        ACIM_FREQ_CTRL_0.amplitude = ACIM_FREQ_CTRL_0.vf_control_ptr->output_amplitude;

        /*Call SVM*/
        PWM_SVM_SVMUpdate(ACIM_FREQ_CTRL_0.pwm_svm_ptr,(uint16_t)ACIM_FREQ_CTRL_0.amplitude,ACIM_FREQ_CTRL_0.angle);
      }

    }
    else
    {
      ACIM_FREQ_CTRL_0.fcl_div_value++;
    }

/************************* calling control loops ***************************/

    if(ACIM_FREQ_CTRL_0.pcl_div_value == ACIM_FREQ_CTRL_0.acim_config_ptr->pcl_divider)
    {
      ACIM_FREQ_CTRL_0_SetValueProcessing(&ACIM_FREQ_CTRL_0);

	  ACIM_FREQ_CTRL_0_PrimaryControlLoop(&ACIM_FREQ_CTRL_0); 
      ACIM_FREQ_CTRL_0.pcl_div_value =(uint8_t)1;
    }
    else
    {
      ACIM_FREQ_CTRL_0.pcl_div_value++;
    }

  }

}

/*************** Primary control loop Functions ****************************/
 /* This Function execute primary control loop functionality*/
void ACIM_FREQ_CTRL_0_PrimaryControlLoop(ACIM_FREQ_CTRL_t*const HandlePtr)
{
  if(HandlePtr->msm_state != ACIM_FREQ_CTRL_MSM_BOOTSTRAP)
  {

  }
  /* Call motor control state machine */
  ACIM_FREQ_CTRL_MSM(HandlePtr);
}

/*************** Set Value Processing Function ****************************/
/* This Function execute set value processing control loop functionality*/
void ACIM_FREQ_CTRL_0_SetValueProcessing(ACIM_FREQ_CTRL_t*const HandlePtr)
{

}

void ACIM_FREQ_CTRL_1_PrimaryControlLoop(ACIM_FREQ_CTRL_t*const HandlePtr);  
void ACIM_FREQ_CTRL_1_SetValueProcessing(ACIM_FREQ_CTRL_t*const HandlePtr);

void ACIM_FREQ_CTRL_1_FastControlLoop_ISR()
{  
  int32_t temp_angle;

  /************************* Trap ***************************/
  if(XMC_CCU8_SLICE_GetEvent(ACIM_FREQ_CTRL_1.pwm_svm_ptr->phase_ptr[0]->slice_ptr,XMC_CCU8_SLICE_IRQ_ID_EVENT2) == (uint32_t)true)
  {
    ACIM_FREQ_CTRL_1.operational_error |= (uint32_t)1<<(uint32_t)ACIM_FREQ_CTRL_EID_TRAP_ERROR;
	ACIM_FREQ_CTRL_1.error_table_ptr[ACIM_FREQ_CTRL_EID_TRAP_ERROR].error_status = (uint8_t)ACIM_FREQ_CTRL_ERROR_SET;
    /* Stop the motor */
    if(ACIM_FREQ_CTRL_1.error_table_ptr[ACIM_FREQ_CTRL_EID_TRAP_ERROR].error_handler_ptr_t != NULL)
    {
      (ACIM_FREQ_CTRL_1.error_table_ptr[ACIM_FREQ_CTRL_EID_TRAP_ERROR].error_handler_ptr_t)(&ACIM_FREQ_CTRL_1);
    }
  }
  else
  {
/************************* Fast Control Loop ***************************/

      if(ACIM_FREQ_CTRL_1.msm_state != ACIM_FREQ_CTRL_MSM_BOOTSTRAP)
      {

        /*Current is 0 because current measurement is disabled.*/
        ACIM_FREQ_CTRL_1.motor_current = 0U;

        /*Updating input of v/f control*/
        ACIM_FREQ_CTRL_1.vf_control_ptr->input = (int32_t)*ACIM_FREQ_CTRL_1.speed_set_ptr;

        /*amplitude calculation*/
        ACIM_FREQ_CTRL_Amplitude_Calculation(&ACIM_FREQ_CTRL_1);

        /*angle calculation*/
        ACIM_FREQ_CTRL_AngleRamp(&ACIM_FREQ_CTRL_1);


        /*Update Modulation Angle and Amplitude before calling svm*/
        temp_angle = ACIM_FREQ_CTRL_1.vf_control_ptr->output_angle + (ACIM_FREQ_CTRL_1.angle_offset * ACIM_FREQ_CTRL_1.motor_direction);
        ACIM_FREQ_CTRL_1.angle     = (uint32_t)(temp_angle);
        ACIM_FREQ_CTRL_1.amplitude = ACIM_FREQ_CTRL_1.vf_control_ptr->output_amplitude;

        /*Call SVM*/
        PWM_SVM_SVMUpdate(ACIM_FREQ_CTRL_1.pwm_svm_ptr,(uint16_t)ACIM_FREQ_CTRL_1.amplitude,ACIM_FREQ_CTRL_1.angle);
      }
/************************* calling control loops ***************************/

    if(ACIM_FREQ_CTRL_1.pcl_div_value == ACIM_FREQ_CTRL_1.acim_config_ptr->pcl_divider)
    {
      ACIM_FREQ_CTRL_1_SetValueProcessing(&ACIM_FREQ_CTRL_1);

	  ACIM_FREQ_CTRL_1_PrimaryControlLoop(&ACIM_FREQ_CTRL_1); 
      ACIM_FREQ_CTRL_1.pcl_div_value =(uint8_t)1;
    }
    else
    {
      ACIM_FREQ_CTRL_1.pcl_div_value++;
    }

  }

}

/*************** Primary control loop Functions ****************************/
 /* This Function execute primary control loop functionality*/
void ACIM_FREQ_CTRL_1_PrimaryControlLoop(ACIM_FREQ_CTRL_t*const HandlePtr)
{
  if(HandlePtr->msm_state != ACIM_FREQ_CTRL_MSM_BOOTSTRAP)
  {

  }
  /* Call motor control state machine */
  ACIM_FREQ_CTRL_MSM(HandlePtr);
}

/*************** Set Value Processing Function ****************************/
/* This Function execute set value processing control loop functionality*/
void ACIM_FREQ_CTRL_1_SetValueProcessing(ACIM_FREQ_CTRL_t*const HandlePtr)
{

}

