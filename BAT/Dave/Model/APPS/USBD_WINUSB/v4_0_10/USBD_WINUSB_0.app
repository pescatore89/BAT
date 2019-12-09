<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="USBD_WINUSB" URI="http://resources/4.0.10/app/USBD_WINUSB/0" description="WinUSB device APP allows the user to interface XMC4000 devices with Windows USB driver (winusb.sys).&#xA;The user doesn't have to implement a custom driver on the Windows host side." mode="NOTSHARABLE" version="4.0.10" minDaveVersion="4.0.0" instanceLabel="USBD_WINUSB_0" appLabel="">
  <properties singleton="true" provideInit="true"/>
  <requiredApps URI="http://resources/4.0.10/app/USBD_WINUSB/0/ra_usbd" requiredAppName="USBD">
    <downwardMapList xsi:type="ResourceModel:App" href="../../USBD/v4_0_14/USBD_0.app#/"/>
  </requiredApps>
</ResourceModel:App>
