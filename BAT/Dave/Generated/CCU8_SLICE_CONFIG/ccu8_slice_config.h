/**
 * @file ccu8_slice_config.h
 * @date 2016-07-12
 *
 * NOTE:
 * This file is generated by DAVE-4. Any manual modification done to this file will be lost when the code is regenerated
 *
 * @cond
 ***********************************************************************************************************************
 * CCU8_SLICE_CONFIG v4.0.22 - Configures the properties of CCU8 timer.
 * Copyright (c) 2016-2018, Infineon Technologies AG
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

#ifndef CCU8_SLICE_CONFIG_H
#define CCU8_SLICE_CONFIG_H

#include "ccu8_slice_config_conf.h"
#include "xmc_ccu8.h"

#if (!((XMC_LIB_MAJOR_VERSION == 2U) && \
       (XMC_LIB_MINOR_VERSION >= 1U) && \
       (XMC_LIB_PATCH_VERSION >= 0U)))
#error "CCU8_SLICE_CONFIG requires XMC Peripheral Library v2.1.0 or higher"
#endif
/**********************************************************************************************************************
* ENUMS
**********************************************************************************************************************/
 /**
  * @ingroup CCU8_SLICE_CONFIG_enumerations
  * @{
  */

/**
 *   @brief The type identifies the APP status.
 */
typedef enum CCU8_SLICE_CONFIG_STATUS
{
  /**
  * STATUS SUCCESS
  */
	CCU8_SLICE_CONFIG_STATUS_SUCCESS = 0,
  /**
  * STATUS FAILURE
  */
	CCU8_SLICE_CONFIG_STATUS_FAILURE
} CCU8_SLICE_CONFIG_STATUS_t;

/**
 * @}
 */



/**********************************************************************************************************************
* DATA STRUCTURES
**********************************************************************************************************************/
/**
  * @ingroup CCU8_SLICE_CONFIG_datastructures
  * @{
  */
/**
 * @brief Instance CCU4_SLICE_CONFIG_t
 */
typedef struct CCU8_SLICE_CONFIG
{
  CCU8_SLICE_CONFIG_STATUS_t (*init)(void); /**< Defines the local initialization function for the instance */
  GLOBAL_CCU8_t *global; /**< Pointer to required GLOBAL_CCU4 APP */
  XMC_CCU8_SLICE_t *slice_ptr; /**< CCU4x_CC4y slice pointer */
  uint8_t slice_num; /**< slice number */
} CCU8_SLICE_CONFIG_t;

/**
 * @}
 */

/**
 * @ingroup CCU8_SLICE_CONFIG_apidoc
 * @{
 */

/***********************************************************************************************************************
 * API Prototypes
 **********************************************************************************************************************/
/* Support for C++ */

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Retrieves the version of the CCU8_SLICE_CONFIG APP.
 * @param None
 * @return DAVE_APP_VERSION_t APP version information (major, minor and patch number)
 *
 * \par<b>Description: </b><br>
 * The function can be used to check application software compatibility with a specific version of the APP.
 *
 *Example Usage:
 *
 * @code
  #include <DAVE.h>

  int main(void)
  {
    DAVE_APP_VERSION_t version;
    version = CCU8_SLICE_CONFIG_GetAppVersion();
    while(1);
    return 0;
  }
 * @endcode
 */
DAVE_APP_VERSION_t CCU8_SLICE_CONFIG_GetAppVersion(void);



/**
 * @brief Initializes the CCU8_SLICE_CONFIG APP.
 * @param  handle_ptr Pointer to CCU8_SLICE_CONFIG_t structure containing APP parameters.
 * @return CCU8_SLICE_CONFIG_STATUS_t
 *
 * \par<b>Description: </b><br>
 * Configures the CCU8 slice registers with the selected CCU8_SLICE_CONFIG parameters.
 *
 * Example Usage:
 * @code
  #include <DAVE.h>

  int main(void)
  {
   DAVE_Init(); //CCU8_SLICE_CONFIG_Init() is called by DAVE_Init().
    while(1);
    return 0;
  }
 * @endcode
 */
CCU8_SLICE_CONFIG_STATUS_t CCU8_SLICE_CONFIG_Init(const CCU8_SLICE_CONFIG_t *const handle_ptr);




/* Include App extern declaration file */
#include "ccu8_slice_config_extern.h"

/**
 * @}
 */
#ifdef __cplusplus
}
#endif



#endif /* CCU8_SLICE_CONFIG_H */

