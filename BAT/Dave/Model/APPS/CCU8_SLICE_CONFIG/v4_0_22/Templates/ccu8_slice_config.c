/**
 * @file ccu8_slice_config.c
 * @date 2016-07-12
 *
 * NOTE:
 * This file is generated by DAVE-4. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * CCU8_SLICE_CONFIG v4.0.22 - Configures the properties of CCU8 timer.
 * Copyright (c) 2015-2018, Infineon Technologies AG
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
 * 2016-02-05:
 *     - Initial version<br>
 *
 * 2016-06-30:
 *     - First productive version
 *
 * @endcond
 *
 */


/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
#include "ccu8_slice_config.h"

/***********************************************************************************************************************
 * PRIVATE FUNCTION PROTOTYPES
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/* API to retrieve App version info */
DAVE_APP_VERSION_t CCU8_SLICE_CONFIG_GetAppVersion(void)
{
  DAVE_APP_VERSION_t version;

  version.major = CCU8_SLICE_CONFIG_MAJOR_VERSION;
  version.minor = CCU8_SLICE_CONFIG_MINOR_VERSION;
  version.patch = CCU8_SLICE_CONFIG_PATCH_VERSION;

  return (version);
}
/* This function initializes the CCU8 slice */
CCU8_SLICE_CONFIG_STATUS_t CCU8_SLICE_CONFIG_Init(const CCU8_SLICE_CONFIG_t *const handle_ptr)
{
  return handle_ptr->init();
}

/* end of CCU8_SLICE_CONFIG function definitions */
