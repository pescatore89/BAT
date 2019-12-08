/*********************************************************************************************************************
* DAVE APP Name : AUTOMATION       APP Version: 4.0.10
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
 * 2015-02-20:
 *     - Initial version
 *
 * @endcond
 *
 */
 
 #ifndef AUTOMATION_EXTERN_H_
 #define AUTOMATION_EXTERN_H_
 
/***********************************************************************************************************************
 * HEADER FILES
 **********************************************************************************************************************/
 
/**********************************************************************************************************************
 * MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * EXTERN DECLARATIONS
***********************************************************************************************************************/ 


extern AUTOMATION_t AUTOMATION_0;
extern AUTOMATION_APP_TABLE_t AUTOMATION_App_Table[AUTOMATION_NUM_APPS];
extern AUTOMATION_TASK_TABLE_t AUTOMATION_Task_Table[AUTOMATION_NUM_TASKS];
extern AUTOMATION_SM_t* AUTOMATION_SM_Table[AUTOMATION_NUM_APPS];

extern AUTOMATION_FB_HANDLE_t* AUTOMATION_FB_ExecutionOrderList[AUTOMATION_FB_EXECUTED_FUNCTION_BLOCKS];
extern AUTOMATION_FB_CONNECTION_TABLE_t AUTOMATION_FB_Connect_Table[AUTOMATION_FB_CONNECT_TABLE_SIZE];
extern AUTOMATION_FB_HANDLE_t* AUTOMATION_FB_Table[AUTOMATION_FB_APP_FUNCTION_BLOCKS + 
													AUTOMATION_FB_ENABLED_FUNCTION_BLOCKS];

extern AUTOMATION_FB_HANDLE_t AUTOMATION_FB_RAMP_0;
extern AUTOMATION_FB_RAMPGEN_t AUTOMATION_Ramp0_Handle;

extern AUTOMATION_FB_HANDLE_t AUTOMATION_FB_RAMP_1;
extern AUTOMATION_FB_RAMPGEN_t AUTOMATION_Ramp1_Handle;

#if (AUTOMATION_PH_ENABLE == 1U)
extern AUTOMATION_PH_PARAM_ENTRY_t* AUTOMATION_PH_Param_Table[AUTOMATION_NUM_APPS];
extern AUTOMATION_PH_PARAMETER_t AUTOMATION_PH_Parameter_Buf[AUTOMATION_NUM_INTERFACES];
#endif

#if (AUTOMATION_EH_ENABLE == 1U)
extern AUTOMATION_EH_LOGBOOK_t AUTOMATION_EH_ErrorLogbook;
extern AUTOMATION_EH_BIT_ERROR_TABLE_t AUTOMATION_EH_BitErrorTable[AUTOMATION_NUM_INTERFACES][AUTOMATION_EH_BITINTERFACE_MAX_ERRORS];
extern AUTOMATION_EH_ERROR_TABLE_t AUTOMATION_EH_ErrorTable;
extern AUTOMATION_EH_APPERROR_BUFFER_t AUTOMATION_EH_AppErrorBuf;
#endif
  
 

 
 #endif  /* ifndef AUTOMATION_EXTERN_H_ */


