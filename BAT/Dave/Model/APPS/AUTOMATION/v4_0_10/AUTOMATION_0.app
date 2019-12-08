<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="AUTOMATION" URI="http://resources/4.0.10/app/AUTOMATION/0" description="Provides mechanism to connect two APPs using &#xA; function block processor. This supports online parameter update and &#xA; error logging.  This consumes System Timer APP and provides task &#xA; registration feature. It also provides state machine." version="4.0.10" minDaveVersion="4.0.0" instanceLabel="AUTOMATION_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../ACIM_FREQ_CTRL/v4_0_8/ACIM_FREQ_CTRL_1.app#//@requiredApps.7"/>
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../ACIM_FREQ_CTRL/v4_0_8/ACIM_FREQ_CTRL_0.app#//@requiredApps.7"/>
  <properties singleton="true" provideInit="true" sharable="true"/>
  <requiredApps URI="http://resources/4.0.10/app/AUTOMATION/0/appres_systimer_0" requiredAppName="SYSTIMER" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../SYSTIMER/v4_1_16/SYSTIMER_0.app#/"/>
  </requiredApps>
</ResourceModel:App>
