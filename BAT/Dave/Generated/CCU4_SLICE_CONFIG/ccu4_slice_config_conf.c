/*********************************************************************************************************************
* DAVE APP Name : CCU4_SLICE_CONFIG       APP Version: 4.0.20
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
 * @file ccu4_slice_config_conf.c
 * @date 2018-05-24
 *
 * NOTE:
 * This file is generated by DAVE-4. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015-2016, Infineon Technologies AG
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
 * 2015-08-30:
 *     - Initial version<br>
 *
 * 2016-04-18:
 *     - Missing code generation for external event configuration is fixed.<br>
 * 
 * 2016-06-21:
 *     - First productive version
 *
 * 2017-04-05:
 *     - Add initial timer value
 *
 * 2017-04-11:
 *     - Generate initialization of input event independently of whether they are used for any timer function
 *
 * 2017-11-10:
 *     - Fix C++ compilation issues
 *
 * 2018-05-24:
 *     - Fix: setTimerValue() is only effective if it is called after enabling clk. 
 * @endcond
 *
 */

/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "ccu4_slice_config.h"


static CCU4_SLICE_CONFIG_STATUS_t CCU4_SLICE_CONFIG_0_lInit(void);
        
const CCU4_SLICE_CONFIG_t CCU4_SLICE_CONFIG_0 =
{
  .init = CCU4_SLICE_CONFIG_0_lInit,
  .global = &GLOBAL_CCU4_2,
  .slice_ptr = CCU43_CC43,
  .slice_num = (uint8_t)3
};
        
const XMC_CCU4_SLICE_COMPARE_CONFIG_t CCU4_SLICE_CONFIG_0_compare_config     =
{
  .timer_mode            = (uint32_t)XMC_CCU4_SLICE_TIMER_COUNT_MODE_EA,
  .monoshot              = (uint32_t)XMC_CCU4_SLICE_TIMER_REPEAT_MODE_REPEAT,
  .shadow_xfer_clear     = false,
  .dither_timer_period   = false,
  .dither_duty_cycle     = false,
  .prescaler_mode        = (uint32_t)XMC_CCU4_SLICE_PRESCALER_MODE_NORMAL,  
  .mcm_enable            = false,        
  .prescaler_initval     = XMC_CCU4_SLICE_PRESCALER_1,
  .float_limit           = XMC_CCU4_SLICE_PRESCALER_32768,
  .dither_limit          = 0,
  .passive_level         = XMC_CCU4_SLICE_OUTPUT_PASSIVE_LEVEL_LOW,  
  .timer_concatenation   = false
};
            
const XMC_CCU4_SLICE_EVENT_CONFIG_t CCU4_SLICE_CONFIG_0_event0_config = 
{
  .mapped_input        = XMC_CCU4_SLICE_INPUT_A,
  .edge                = XMC_CCU4_SLICE_EVENT_EDGE_SENSITIVITY_NONE,
  .level               = XMC_CCU4_SLICE_EVENT_LEVEL_SENSITIVITY_ACTIVE_HIGH,
  .duration            = XMC_CCU4_SLICE_EVENT_FILTER_DISABLED                               
 };
            
const XMC_CCU4_SLICE_EVENT_CONFIG_t CCU4_SLICE_CONFIG_0_event1_config = 
{
  .mapped_input        = XMC_CCU4_SLICE_INPUT_A,
  .edge                = XMC_CCU4_SLICE_EVENT_EDGE_SENSITIVITY_NONE,
  .level               = XMC_CCU4_SLICE_EVENT_LEVEL_SENSITIVITY_ACTIVE_HIGH,
  .duration            = XMC_CCU4_SLICE_EVENT_FILTER_DISABLED                               
 };
            
const XMC_CCU4_SLICE_EVENT_CONFIG_t CCU4_SLICE_CONFIG_0_event2_config = 
{
  .mapped_input        = XMC_CCU4_SLICE_INPUT_A,
  .edge                = XMC_CCU4_SLICE_EVENT_EDGE_SENSITIVITY_NONE,
  .level               = XMC_CCU4_SLICE_EVENT_LEVEL_SENSITIVITY_ACTIVE_HIGH,
  .duration            = XMC_CCU4_SLICE_EVENT_FILTER_DISABLED                               
 };
            /* Channel initialization function */
CCU4_SLICE_CONFIG_STATUS_t CCU4_SLICE_CONFIG_0_lInit(void)
{
  GLOBAL_CCU4_Init(&GLOBAL_CCU4_2);
  /* Configure CCU4x_CC4y slice as timer unit */
  XMC_CCU4_SLICE_CompareInit(CCU43_CC43, &CCU4_SLICE_CONFIG_0_compare_config);
  /* Set timer compare register value */
  XMC_CCU4_SLICE_SetTimerCompareMatch(CCU43_CC43, (uint16_t)32768U);
  /* Set timer period register value */
  XMC_CCU4_SLICE_SetTimerPeriodMatch(CCU43_CC43, (uint16_t)65535U);	
  /* Register value update settings */
  XMC_CCU4_SetMultiChannelShadowTransferMode(CCU43, (uint32_t)XMC_CCU4_MULTI_CHANNEL_SHADOW_TRANSFER_SW_SLICE3);
  /* Transfer value from shadow registers to actual timer registers */
  XMC_CCU4_EnableShadowTransfer(CCU43, (uint32_t)XMC_CCU4_SHADOW_TRANSFER_SLICE_3 |
                                               (uint32_t)XMC_CCU4_SHADOW_TRANSFER_DITHER_SLICE_3 |
                                               (uint32_t)XMC_CCU4_SHADOW_TRANSFER_PRESCALER_SLICE_3);
  /* Events and function settings */
  XMC_CCU4_SLICE_ConfigureEvent(CCU43_CC43, XMC_CCU4_SLICE_EVENT_0, &CCU4_SLICE_CONFIG_0_event0_config);
  XMC_CCU4_SLICE_ConfigureEvent(CCU43_CC43, XMC_CCU4_SLICE_EVENT_1, &CCU4_SLICE_CONFIG_0_event1_config);
  XMC_CCU4_SLICE_ConfigureEvent(CCU43_CC43, XMC_CCU4_SLICE_EVENT_2, &CCU4_SLICE_CONFIG_0_event2_config);
  /* clear IDLE mode for the slice*/
  XMC_CCU4_EnableClock(CCU43, (uint8_t)3);	
  /* Set initial value of timer */
  XMC_CCU4_SLICE_SetTimerValue(CCU43_CC43, (uint16_t)0U);
  return CCU4_SLICE_CONFIG_STATUS_SUCCESS;
}
	
