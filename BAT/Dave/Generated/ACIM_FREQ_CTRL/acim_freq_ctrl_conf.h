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
 *
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/
#ifndef ACIM_FREQ_CTRL_CONF_H_
#define ACIM_FREQ_CTRL_CONF_H_

/* Fast Control Loop ISR mapped to IRQ Handler*/
#define  ACIM_FREQ_CTRL_0_FastControlLoop_ISR  IRQ_Hdlr_63

/* Fast Control Loop ISR mapped to IRQ Handler*/
#define  ACIM_FREQ_CTRL_1_FastControlLoop_ISR  IRQ_Hdlr_64

/* Macro to extract MAJOR, MINOR and PATCH version */
#define ACIM_FREQ_CTRL_MAJOR_VERSION (4U)
#define ACIM_FREQ_CTRL_MINOR_VERSION (0U)
#define ACIM_FREQ_CTRL_PATCH_VERSION (8U)


/*Macro specify the presence of ADC resource*/
#define ACIM_FREQ_CTRL_IS_ADC_AVAILABLE   (0U)

/*Macro to specify the presence of Automation Framework */
#define ACIM_FREQ_CTRL_IS_AUTOMATION_AVAILABLE  (0U)

/*Macro to specify the presence of DSM Framework */
#define ACIM_FREQ_CTRL_IS_DSM_AVAILABLE  (0U)

/*Macro to specify the presence of user defined callback function during error */
#define ACIM_FREQ_CTRL_IS_ERROR_USER_CALLBACK_ENABLE (0U)

/* ADC calibration is disabled */
#define ACIM_FREQ_CTRL_ADC_CALIBRATION    (0U)


#endif


