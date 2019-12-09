/**
 * @file descriptors.c
 * @date 2015-10-08 
 *
 * @cond
 ***********************************************************************************************************************
 * USBD_WINUSB v4.0.8 - The USBD_WINUSB is the Windows winusb.sys driver interface to the XMC4000 family of controllers.
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
 *     - Updated USB supported version to USB1.1
 * 2015-06-20:
 *     - Updated the file header.
 *     
 * @endcond 
 *
 */
/*
  Copyright 2014  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


/***********************************************************************************************************************
 * HEADER FILES                                                                                                      
 **********************************************************************************************************************/
#include "descriptors.h"

/***********************************************************************************************************************
 * GLOBAL DATA
 **********************************************************************************************************************/
/*WinUSB endpoint info data structure*/
USBD_WINUSB_Info_t winusb_info = {
		.config = {
				.in_endpoint = {
						.Address = ENDPOINT_DIR_IN | WINUSB_TX_EPNUM,
						.Size = WINUSB_TXRX_EPSIZE,
						.Type = EP_TYPE_BULK
				},
				.out_endpoint = {
						.Address = ENDPOINT_DIR_OUT | WINUSB_RX_EPNUM,
						.Size = WINUSB_TXRX_EPSIZE,
						.Type = EP_TYPE_BULK
				}
		}
};

/** Device descriptor structure. This descriptor, located in FLASH memory,
 * describes the overall device characteristics, including the supported USB
 * version, control end point size and the number of device configurations.
 * The descriptor is read out by the USB host when the enumeration process
 * begins.
 */
const USB_Descriptor_Device_t device_descriptor =
{
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t),
											.Type = DTYPE_Device},

	.USBSpecification       = 0x0110,
	.Class                  = USB_CSCP_NoDeviceClass,
	.SubClass               = USB_CSCP_NoDeviceSubclass,
	.Protocol               = USB_CSCP_NoDeviceProtocol,

	.Endpoint0Size          = 64,

	.VendorID               = 0x058b,
	.ProductID              = 0x0050,
	.ReleaseNumber          = 0x0001,

	.ManufacturerStrIndex   = 0x01,
	.ProductStrIndex        = 0x02,
	.SerialNumStrIndex      = NO_DESCRIPTOR,

	.NumberOfConfigurations = 1
};

/** Configuration descriptor structure. This descriptor, located in FLASH
 * memory, describes the usage of the device in one of its supported
 * configurations, including information about any device interfaces and
 * end points. The descriptor is read out by the USB host during the enumeration
 * process when selecting a configuration so that the host may correctly
 * communicate with the USB device.
 */
const USB_Descriptor_Configuration_t configuration_descriptor =
{
	.config =
		{
			.Header                 =
					{.Size = sizeof(USB_Descriptor_Configuration_Header_t),
							.Type = DTYPE_Configuration},

			.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t),
			.TotalInterfaces        = 1,

			.ConfigurationNumber    = 1,
			.ConfigurationStrIndex  = NO_DESCRIPTOR,

			.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED),

			.MaxPowerConsumption    = USB_CONFIG_POWER_MA(100)
		},

	.winusb_interface =
		{
			.Header                 =
					{.Size = sizeof(USB_Descriptor_Interface_t),
							.Type = DTYPE_Interface},

			.InterfaceNumber        = 0,
			.AlternateSetting       = 0,

			.TotalEndpoints         = 2,

			.Class                  = USB_CSCP_VendorSpecificClass,
			.SubClass               = USB_CSCP_NoDeviceSubclass,
			.Protocol               = USB_CSCP_NoDeviceProtocol,

			.InterfaceStrIndex      = NO_DESCRIPTOR
		},
	.winusb_data_out_endpoint =
		{
			.Header                 =
						{.Size = sizeof(USB_Descriptor_Endpoint_t),
								.Type = DTYPE_Endpoint},

			.EndpointAddress        = (ENDPOINT_DIR_OUT | WINUSB_RX_EPNUM),
			.Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC |
														ENDPOINT_USAGE_DATA),
			.EndpointSize           = WINUSB_TXRX_EPSIZE,
			.PollingIntervalMS      = 0x00
		},

	.winusb_data_in_endpoint =
		{
			.Header                 =
						{.Size = sizeof(USB_Descriptor_Endpoint_t),
								.Type = DTYPE_Endpoint},

			.EndpointAddress        = (ENDPOINT_DIR_IN | WINUSB_TX_EPNUM),
			.Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC |
														ENDPOINT_USAGE_DATA),
			.EndpointSize           = WINUSB_TXRX_EPSIZE,
			.PollingIntervalMS      = 0x00
		}
};

/** Language descriptor structure. This descriptor, located in FLASH memory,
 * is returned when the host requests the string descriptor with index
 * 0 (the first index). It is actually an array of 16-bit integers, which
 * indicate via the language ID table available at USB.org what languages the
 * device supports for its string descriptors.
 */
const USB_Descriptor_String_t language_string =
{
	.Header                 = {.Size = USB_STRING_LEN(1), .Type = DTYPE_String},

	.UnicodeString          = {LANGUAGE_ID_ENG}
};

/** Manufacturer descriptor string. This is a Unicode string containing the
 * manufacturer's details in human readable form, and is read out upon request
 * by the host when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t manufacturer_string =
{
	.Header                 = {.Size = USB_STRING_LEN(21),
										.Type = DTYPE_String},

	.UnicodeString          = { 'I','n','f','i','n','e','o','n',' ','T','e',
								'c','h','n','o','l','o','g','i','e','s'}
};

/** Product descriptor string. This is a Unicode string containing the product's
 *  details in human readable form, and is read out upon request by the host
 *  when the appropriate string ID is requested, listed in the Device
 *  Descriptor.
 */
const USB_Descriptor_String_t product_string =
{
	.Header                 = {.Size = USB_STRING_LEN(22),
										.Type = DTYPE_String},

	.UnicodeString          = {'I','n','f','i','n','e','o','n',' ','W','i','n',
								'U','S','B',' ','D','e','v','i','c','e'}
};

const MS_String_Descriptor_t ms_string = {
		.length = 0x12,
		.descriptor_type = DTYPE_String,
		.signature = {
				0x4D ,0x00, 0x53, 0x00, 0x46, 0x00, 0x54, 0x00, 0x31, 0x00,
				0x30, 0x00, 0x30, 0x00
		},/*MSFT100*/
		.ms_vendor_code = 0x1,
		.pad = 0x1
};

const MS_Extended_Compat_ID_Descriptor_t compat_id = {
		.dw_length = 0x0028,
		.bcd_version = 0x0100,
		.w_index = EXTENDED_COMPAT_ID,
		.count = 0x1,
		.functions = {
				{
						.first_interface_number = 0x0,
						.reserved0 = 0x1,
						.compatible_id = { 0x57, 0x49, 0x4E, 0x55, 0x53, 0x42,
								0x00, 0x00 },/*WINUSB*/
				}
		}
};

const MS_Extended_Properties_Descriptor_t properties = {
		.dw_length = 0x8E,
		.bcd_version = 0x0100,
		.w_index = EXTENDED_PROPERTIES,
		.w_count = 0x1,
		.properties = {
				132,0x0,0x0,0x0, /* over all length */
				0x1,0x0,0x0,0x0, /* data type: unicode null-terminated string */
				40, 0x0, /* name length */
				'D',0x0,'e',0x0,'v',0x0,'i',0x0,'c',0x0,'e',0x0,'I',0x0,'n',0x0,
				't',0x0,'e',0x0,'r',0x0,'f',0x0,'a',0x0,'c',0x0,'e',0x0,'G',0x0,
				'U',0x0,'I',0x0,'D',0x0,0x0,0x0,
				78,0x0,0x0,0x0, /* data length */
				'{',0x0,'4',0x0,'0',0x0,'E',0x0,'E',0x0,'A',0x0,'1',0x0,'E',0x0,
				'B',0x0,'-',0x0,
				'E',0x0,'F',0x0,'6',0x0,'7',0x0,'-',0x0,
				'4',0x0,'D',0x0,'6',0x0,'A',0x0,'-',0x0,
				'A',0x0,'B',0x0,'0',0x0,'B',0x0,'-',0x0,
				'8',0x0,'B',0x0,'B',0x0,'5',0x0,'8',0x0,'8',0x0,'5',0x0,'9',0x0,
				'8',0x0,'7',0x0,'0',0x0,'4',0x0,'}',0x0,0x0,0x0
		}
};

/**********************************************************************************************************************
 * API IMPLEMENTATION
 **********************************************************************************************************************/
/** This function is called by the library when in device mode, and must be
 * overridden (see library "USB Descriptors" documentation) by the application
 * code so that the address and size of a requested descriptor can be given
 *  to the USB library. When the device receives a Get Descriptor request on
 *  the control end point, this function is called so that the descriptor
 *  details can be passed back and the appropriate descriptor sent back to the
 *  USB host.
 */
uint16_t USBD_WINUSB_Event_GetDescriptor(const uint16_t w_value,
                                    const uint16_t w_index,
                                    const void** const descriptor_address)
{
	const uint8_t  descriptor_type   = (w_value >> 8);
	const uint8_t  descriptor_number = (w_value & 0xFF);

	const void* address = NULL;
	uint16_t    size    = NO_DESCRIPTOR;

	switch (descriptor_type)
	{
		case DTYPE_Device:
			address = &device_descriptor;
			size    = sizeof(USB_Descriptor_Device_t);
			break;
		case DTYPE_Configuration:
			address = &configuration_descriptor;
			size    = sizeof(USB_Descriptor_Configuration_t);
			break;
		case DTYPE_String:
			switch (descriptor_number)
			{
				case 0x00:
					address = &language_string;
					size    = language_string.Header.Size;
					break;
				case 0x01:
					address = &manufacturer_string;
					size    = manufacturer_string.Header.Size;
					break;
				case 0x02:
					address = &product_string;
					size    = product_string.Header.Size;
					break;
				case 0xEE:
					address = &ms_string;
					size    = ms_string.length;
					break;
			}
			break;
	}

	(void)w_index;
	*descriptor_address = address;
	return size;
}

