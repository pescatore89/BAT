/**
 * @file usbd_winusb.c
 * @date 2015-10-08
 * NOTE:
 * This file is generated by DAVE. Any manual modification done to this file will be lost when the code is regenerated.
 *
 * @cond
 ***********************************************************************************************************************
 * USBD_WINUSB v4.0.10 - The USBD_WINUSB is the Windows winusb.sys driver interface to the XMC4000 family of controllers.
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
 *     - Initial version.      
 * 2015-03-18:
 *     - Guidelines updated.
 * 2015-04-23:
 *     - Updated the review comments from AEs.
 * 2015-06-20:
 *     - Updated the file header.
 *     
 * @endcond 
 *
 */


/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
#include "usbd_winusb.h"

/**********************************************************************************************************************
 * MACROS                                                                                                            
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * LOCAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * GLOBAL DATA
 **********************************************************************************************************************/
/**
 * Buffer to hold transmit and receive data
 **/
uint8_t tx_buf[TX_BUF_SIZE];
uint8_t rx_buf[RX_BUF_SIZE];

/**
 * USB device maximum number of endpoints
 * Will get update according to USBD app UI.
 **/
uint8_t usbd_max_eps = 0U;

/**
 * @ingroup USBD_WINUSB_datastructures
 * @{
 */


/**
 * USBD_WINUSB events.Define the event callbacks which are really required.
 * All other unwanted events can be made 0.
 * To add any of the USB event:\n
 * 1) In the event callback structure add the required event callback handler name.\n
 * 2) Define the callback handler in usbd_winusb.c file.\n
 * 3) Declare the callback handler in usbd_winusb.h file.\n
 *
 * The following events are supported in USBD_WINUSB APP:\n
 * USB connect:\n
 * Event for USB device connection. This event fires when the microcontroller is in USB device mode and the device is
 * connected to a USB host, beginning the enumeration process measured by a rising level on the microcontroller's VBUS sense pin.
 * This event is time-critical; exceeding OS-specific delays within this event handler (typically of around two seconds) will
 * prevent the device from enumerating correctly.\n\n
 *
 * USB Disconnect:\n
 * Event for USB device disconnection. This event fires when the microcontroller is in USB device mode and the device is
 * disconnected from a host, measured by a falling level on the microcontroller's VBUS sense pin.\n\n
 *
 * Configuration Changed:\n
 * Event for USB configuration number changed. This event fires when a the USB host changes the selected configuration number.
 * This event should be hooked in device applications to create the endpoints and configure the device for the selected configuration.
 * This event is time-critical; exceeding OS-specific delays within this event handler (typically of around one second) will prevent
 * the device from enumerating correctly.\n\n
 *
 * Control Request:\n
 * Event for control requests. This event fires when a the USB host issues a control request to the mandatory device control
 * endpoint (of address 0). This may either be a standard request that the library may have a handler code for internally,
 * or a class specific request issued to the device which must be handled appropriately. If a request is not processed in the
 * user application via this event, it will be passed to the library for processing internally if a suitable handler exists.\n
 *
 * This event is time-critical; each packet within the request transaction must be acknowledged or sent within 50ms or the host
 * will abort the transfer.\n
 *
 * The library internally handles all standard control requests with the exceptions of SYNC FRAME,  SET DESCRIPTOR and
 * SET INTERFACE. These and all other non-standard control requests will be left for the user to process via this event if desired.
 * If not handled in the user application or by the library internally, unknown requests are automatically STALLed.\n\n
 *
 * Set Address:\n
 * USB set address event. This event gets fired when USB host requests the device to set the address.\n\n
 *
 * Get Descriptor:\n
 * USB Get descriptor event handler. This function is called by the library when in device mode. When the device receives a
 * Get Descriptor request on the control endpoint, this function is called so that the descriptor details can be passed back
 * and the appropriate descriptor sent back to the USB host.
 * The user has to send proper descriptor(device,configuration and string) and should return the size of the descriptor data.\n\n
 *
 * Wakeup Event:\n
 * Event for USB wake up. This event fires when a the USB interface is suspended while in device mode, and the host wakes up the
 * device by supplying Start Of Frame pulses. This is generally hooked to pull the user application out of a low power state and
 * back into normal operating mode.\n\n
 *
 * Suspend Event:\n
 * Event for USB suspend. This event fires when a the USB host suspends the device by halting its transmission of Start Of Frame
 * pulses to the device. This is generally hooked in order to move the device over to a low power state until the host wakes up the
 * device.\n\n
 *
 * SOF(Start Of Frame) Event:\n
 * Event for USB Start Of Frame detection, when enabled. This event fires at the start of each USB frame, once per millisecond, and
 * is synchronized to the USB bus. This can be used as an accurate millisecond timer source when the USB bus is enumerated in
 * device mode. This event is time-critical; it is run once per millisecond and thus will significantly degrade device performance.
 * This event should only be enabled when needed to reduce device wake-ups.\n\n
 *
 * Reset event:\n
 * Event for USB interface reset. This event fires when the USB interface is in device mode, and  the USB host requests that the
 * device reset its interface.
 * This event is time-critical; exceeding OS-specific delays within this event handler (typically of around  two seconds)
 * will prevent the device from enumerating correctly.
 **/
USBD_Event_CB_t USBD_WINUSB_event_callback = {
  /*WINUSB device connect event callback*/
  0,
  /*WINUSB device disconnect event callback*/
  0,
  /*WINUSB device configuration change event callback*/
  USBD_WINUSB_Event_ConfigurationChanged,
  /*WINUSB device control request event callback*/
  USBD_WINUSB_Event_ControlRequest,
  /*WINUSB device set address event callback*/
  0,
  /*WINUSB device get descriptor request event callback*/
  USBD_WINUSB_Event_GetDescriptor,
  /*WINUSB device Wake up event callback*/
  0,
  /*WINUSB device suspend event callback*/
  0,
  0,/*start of frame event callback*/
  USBD_WINUSB_Event_Reset/*USB reset event callback*/
};
/**
 * @}
 */
 
 /***********************************************************************************************************************
 * LOCAL ROUTINES 
 **********************************************************************************************************************/


/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/

/*
 * API to retrieve the version of the USBD_WINUSB
 */
DAVE_APP_VERSION_t USBD_WINUSB_GetAppVersion(void)
{
  DAVE_APP_VERSION_t version;

  version.major = USBD_WINUSB_MAJOR_VERSION;
  version.minor = USBD_WINUSB_MINOR_VERSION;
  version.patch = USBD_WINUSB_PATCH_VERSION;

  return version;
}

/*The WinUSB API to initialize the USB core*/
USBD_WINUSB_Status_t USBD_WINUSB_Init(USBD_WINUSB_t *winusb_handle)
{
  USBD_WINUSB_Status_t status = USBD_WINUSB_STATUS_SUCCESS;

  XMC_ASSERT("USBD_WINUSB_Init: winusb_handle not valid", (winusb_handle != NULL));

  usbd_max_eps = (uint8_t)USBD_handle->usb_init.usbd_max_num_eps;
  /*Register the required USB events*/
  if (USBD_WINUSB_STATUS_SUCCESS == USBD_WINUSB_Register_USBEvent_CB(&USBD_WINUSB_event_callback))
  {
    if (USBD_WINUSB_STATUS_SUCCESS != (USBD_WINUSB_Status_t)USBD_Init(USBD_handle))
    {
      status = USBD_WINUSB_STATUS_FAILURE;
    }
  }
  else
  {
    status = USBD_WINUSB_STATUS_FAILURE;
  }
  (void)winusb_handle;
  return status;
}

/*The WinUSB API to write data to USB host*/
USBD_WINUSB_Status_t USBD_WINUSB_WriteData(uint8_t ep_addr, const void *buffer, uint16_t length)
{
  USBD_WINUSB_Status_t status = USBD_WINUSB_STATUS_SUCCESS;

  /*make sure it is IN endpoint*/
  ep_addr |= (uint8_t)ENDPOINT_DIR_MASK;

  if ((length > 0U) && (buffer != NULL))
  {		
    /* leave if device is not configured */
    if (USB_DeviceState != (uint8_t)DEVICE_STATE_Configured)
    {
      status =  USBD_WINUSB_STATUS_NOT_READY;				
    }
    else
    {
      /* Selecet winusb in endpoint */
      Endpoint_SelectEndpoint(ep_addr);
      
      /* Leave if endpoint is not ready */
      if (!Endpoint_IsINReady())
      {
        status = USBD_WINUSB_STATUS_NOT_READY;					
      }
      else
      {

        /* write data to endpoint and then flush the data */
        if ((uint8_t)ENDPOINT_RWSTREAM_NoError != Endpoint_Write_Stream_LE(buffer,length,NULL))
        {
          status = USBD_WINUSB_STATUS_FAILURE;						
        }
        else
        {
          Endpoint_ClearIN();
        }
      }
    }
    
  }
  else
  {
    status = USBD_WINUSB_STATUS_FAILURE;
  }
  return status;
}

/*The WinUSB API to read data from USB host*/
USBD_WINUSB_Status_t USBD_WINUSB_ReadData(uint8_t ep_addr, void *buffer, uint16_t length)
{
  USBD_WINUSB_Status_t status = USBD_WINUSB_STATUS_SUCCESS;

  if ((length > 0U) && (buffer != NULL))
  {		
    /* Leave if device is not configured */
    if (USB_DeviceState != (uint8_t)DEVICE_STATE_Configured)
    {
      status = (USBD_WINUSB_Status_t)ENDPOINT_RWSTREAM_DeviceDisconnected;				
    }
    else
    {
      /* Select the winusb out endpoint */
      Endpoint_SelectEndpoint(ep_addr);

      /* leave if no out is received */
      if (true != Endpoint_IsOUTReceived())
      {
        status = USBD_WINUSB_STATUS_NOT_READY;					
      }
      else
      {
        /* read data from endpoint and start new read operation */
        if ((uint8_t)ENDPOINT_RWSTREAM_NoError != Endpoint_Read_Stream_LE(buffer,length,NULL))
        {
          status = USBD_WINUSB_STATUS_FAILURE;						
        }
        else
        {
          Endpoint_ClearOUT();
        }
      }
    }		
  }
  else
  {
    status = USBD_WINUSB_STATUS_FAILURE;
  }
  return status;
}

/*The WinUSB API to check the data reception from USB host*/
uint16_t USBD_WINUSB_BytesReceived(uint8_t ep_addr)
{
  uint16_t bytes = 0U;
  /* Leave if device is not configured */
  if (USB_DeviceState == (uint8_t)DEVICE_STATE_Configured)
  {
    /* Select the winusb out endpoint */
    Endpoint_SelectEndpoint(ep_addr);

    /* check if we have out received and if we have data. if is empty out
     * packet, flush */
    if (true == Endpoint_IsOUTReceived())
    {
      if (0U == Endpoint_BytesInEndpoint())
      {
        Endpoint_ClearOUT();
        bytes = 0U;
      }
      else
      {
        bytes = Endpoint_BytesInEndpoint();
      }
    }

  }

  return bytes;
}

/*The API to configure the USB end points*/
uint8_t USBD_WINUSB_ConfigureEndpoints(USBD_WINUSB_Info_t* const winusb_interface)
{
  uint8_t status;
  /* configure in endpoint */
  status = (uint8_t)Endpoint_ConfigureEndpointTable(&winusb_interface->config.in_endpoint,1U);

  if (1U == status)
  {
    /* configure out endpoint */
    status = (uint8_t)Endpoint_ConfigureEndpointTable(&winusb_interface->config.out_endpoint,1U);
  }

  return status;
}

/*The USB device control request callback.
 * This can be used by the customers to handle the class/vendor specific
 * USB requests
 * */
void USBD_WINUSB_Event_ControlRequest()
{
  uint16_t length = 0U;
  uint8_t status;
  uint16_t index = USB_ControlRequest.wIndex;


  /* Serve Microsoft vendor control request */
  if (MS_GET_DESCRIPTOR == ((USB_ControlRequest.bmRequestType & REQTYPE_VENDOR) && (USB_ControlRequest.bRequest)))
  {
    /* Send comapt_ID descriptor for automatic winusb detection */
    if ((uint16_t)EXTENDED_COMPAT_ID == index)
    {
      Endpoint_ClearSETUP();

      if ((uint32_t)USB_ControlRequest.wLength < compat_id.dw_length)
      {
        length = USB_ControlRequest.wLength;
      }
      else
      {
        length = (uint16_t)compat_id.dw_length;
      }

      status = Endpoint_Write_Control_Stream_LE(&compat_id, length);
    }
    /* Send Extended properties to get always the same device GUID */
    if ((USB_ControlRequest.bmRequestType & REQREC_INTERFACE) && ((uint16_t)EXTENDED_PROPERTIES == index))
    {
      Endpoint_ClearSETUP();

      if ((uint32_t)USB_ControlRequest.wLength < properties.dw_length)
      {
        length = USB_ControlRequest.wLength;
      }
      else
      {
        length = (uint16_t)properties.dw_length;
      }
      status = Endpoint_Write_Control_Stream_LE(&properties, length);
    }
  }
  (void)status;
}


/*
 * USB device configuration changed event callback.
 * Here we reconfigure the USB end points.
 * */
void USBD_WINUSB_Event_ConfigurationChanged()
{
  uint32_t i;
  uint8_t status;
  /* Clear configured flag */
  for (i = ((uint32_t)usbd_max_eps - 1); i > 0U; i--)
  {
    device.Endpoints[((uint32_t)usbd_max_eps - i)].IsConfigured = 0U;
  }
  USBD_SetEndpointBuffer(winusb_info.config.in_endpoint.Address,tx_buf,(uint16_t)TX_BUF_SIZE);
  USBD_SetEndpointBuffer(winusb_info.config.out_endpoint.Address,rx_buf,(uint16_t)RX_BUF_SIZE);
  if (USBD_WINUSB_ConfigureEndpoints(&winusb_info))
  {
    /* Unconfigure all enabled but not used endpoints */
    for (i = ((uint32_t)usbd_max_eps - 1); i > 0U; i--)
    {
      USBD_Endpoint_t *ep = &device.Endpoints[(((uint32_t)usbd_max_eps - i))];
      if ((0U == ep->IsConfigured) && (1U == ep->IsEnabled))
      {
        status = (uint8_t)device.Driver->EndpointUnconfigure(ep->Number);
        (void)status;
      }
    }
    device.IsConfigured = 1U;
    USB_DeviceState = (uint8_t)DEVICE_STATE_Configured;
  }
}

/**
 * Register the USB event callbacks.
 **/
USBD_WINUSB_Status_t USBD_WINUSB_Register_USBEvent_CB(USBD_Event_CB_t *event_callback)
{
  USBD_WINUSB_Status_t status = USBD_WINUSB_STATUS_SUCCESS;

  if (NULL != event_callback)
  {
    /*NULL checks for the event callbacks are done in the low level APP USBD*/
    USBD_handle->event_cb->set_address = event_callback->set_address;
    USBD_handle->event_cb->config_changed = event_callback->config_changed;
    USBD_handle->event_cb->connect = event_callback->connect;
    USBD_handle->event_cb->control_request = event_callback->control_request;
    USBD_handle->event_cb->disconnect = event_callback->disconnect;
    USBD_handle->event_cb->get_descriptor = event_callback->get_descriptor;
    USBD_handle->event_cb->suspend = event_callback->suspend;
    USBD_handle->event_cb->wakeup = event_callback->wakeup;
    USBD_handle->event_cb->start_of_frame = event_callback->start_of_frame;
    USBD_handle->event_cb->reset = event_callback->reset;
  }
  else
  {
    status = USBD_WINUSB_STATUS_FAILURE;
  }

  return status;

}

/* Event handler for the USB reset event. */
void USBD_WINUSB_Event_Reset(void)
{
  /*For self powered devices, reinitialize USB*/
  if (device.IsConfigured)
  {
    device.IsConfigured = 0U;
    if (USBD_WINUSB_STATUS_SUCCESS == USBD_WINUSB_Init(USBD_WINUSB_handle))
    {
      if (USBD_WINUSB_STATUS_SUCCESS != USBD_WINUSB_Connect())
      {
      }
    }
  }
}

/*The API to connect the WINUSB device to USB host*/
USBD_WINUSB_Status_t USBD_WINUSB_Connect(void)
{
  return (USBD_WINUSB_Status_t)USBD_Connect();
}

/*The API to disconnect the WINUSB device from USB host*/
USBD_WINUSB_Status_t USBD_WINUSB_Disconnect(void)
{
  return (USBD_WINUSB_Status_t)USBD_Disconnect();
}

/*The function check if the enumeration has been done already. */
uint32_t USBD_WINUSB_IsEnumDone(void)
{
  return (uint32_t)(USBD_IsEnumDone() && (USB_DeviceState == (uint8_t)DEVICE_STATE_Configured));
}


