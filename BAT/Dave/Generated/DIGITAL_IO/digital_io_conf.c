/*********************************************************************************************************************
* DAVE APP Name : DIGITAL_IO       APP Version: 4.0.16
*
* NOTE:
* This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
*********************************************************************************************************************/

/**
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
 * 2015-02-16:
 *     - Initial version<br>
 * 2015-12-22
 *     - Added hardware controlled IO feature.
 * 2016-07-08:
 *     - Fixed incorrect case for an included header.<br>
 *
 * @endcond
 *
 */
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "digital_io.h"

const DIGITAL_IO_t DIGITAL_IO_0 =
{
  .gpio_port = XMC_GPIO_PORT0,
  .gpio_pin = 10U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_1 =
{
  .gpio_port = XMC_GPIO_PORT0,
  .gpio_pin = 11U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_2 =
{
  .gpio_port = XMC_GPIO_PORT0,
  .gpio_pin = 9U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_3 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 1U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_4 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 13U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_5 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 14U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_6 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 2U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_7 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 3U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_8 =
{
  .gpio_port = XMC_GPIO_PORT2,
  .gpio_pin = 0U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_9 =
{
  .gpio_port = XMC_GPIO_PORT2,
  .gpio_pin = 10U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_OUTPUT_PUSH_PULL,
    .output_level = XMC_GPIO_OUTPUT_LEVEL_LOW,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_10 =
{
  .gpio_port = XMC_GPIO_PORT2,
  .gpio_pin = 2U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_11 =
{
  .gpio_port = XMC_GPIO_PORT2,
  .gpio_pin = 3U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_12 =
{
  .gpio_port = XMC_GPIO_PORT2,
  .gpio_pin = 6U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_13 =
{
  .gpio_port = XMC_GPIO_PORT2,
  .gpio_pin = 7U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_14 =
{
  .gpio_port = XMC_GPIO_PORT3,
  .gpio_pin = 1U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_15 =
{
  .gpio_port = XMC_GPIO_PORT3,
  .gpio_pin = 2U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_16 =
{
  .gpio_port = XMC_GPIO_PORT3,
  .gpio_pin = 3U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_17 =
{
  .gpio_port = XMC_GPIO_PORT3,
  .gpio_pin = 4U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_18 =
{
  .gpio_port = XMC_GPIO_PORT3,
  .gpio_pin = 5U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_19 =
{
  .gpio_port = XMC_GPIO_PORT4,
  .gpio_pin = 0U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_20 =
{
  .gpio_port = XMC_GPIO_PORT4,
  .gpio_pin = 1U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_21 =
{
  .gpio_port = XMC_GPIO_PORT5,
  .gpio_pin = 1U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_22 =
{
  .gpio_port = XMC_GPIO_PORT5,
  .gpio_pin = 2U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_23 =
{
  .gpio_port = XMC_GPIO_PORT5,
  .gpio_pin = 7U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_24 =
{
  .gpio_port = XMC_GPIO_PORT15,
  .gpio_pin = 8U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_25 =
{
  .gpio_port = XMC_GPIO_PORT15,
  .gpio_pin = 9U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_26 =
{
  .gpio_port = XMC_GPIO_PORT15,
  .gpio_pin = 2U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_27 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 0U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_28 =
{
  .gpio_port = XMC_GPIO_PORT15,
  .gpio_pin = 3U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
const DIGITAL_IO_t DIGITAL_IO_29 =
{
  .gpio_port = XMC_GPIO_PORT1,
  .gpio_pin = 9U,
  .gpio_config = {
    .mode = XMC_GPIO_MODE_INPUT_TRISTATE,

  },
  .hwctrl = XMC_GPIO_HWCTRL_DISABLED
};
		
