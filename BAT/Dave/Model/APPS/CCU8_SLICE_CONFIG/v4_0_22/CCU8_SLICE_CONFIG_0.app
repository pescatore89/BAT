<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="CCU8_SLICE_CONFIG" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0" description="The CCU8_SLICE_CONFIG configures and initializes a CCU8 timer slice.&#xA;The Capture/Compare Unit 8 (CCU8) peripheral functions play a major role in applications that need complex Pulse Width Modulation (PWM) signal generation, with complementary high side and low side switches or multi phase control." mode="NOTSHARABLE" version="4.0.22" minDaveVersion="4.3.2" instanceLabel="CCU8_SLICE_CONFIG_0" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="global_signal" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_config_global" hwSignal="global_signal" hwResource="//@hwResources.0"/>
  <virtualSignals name="event_period_match" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_period_match_interrupt" hwSignal="pmus_omds" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_ch1_cmp_match" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_ch1_compare_match_interrupt" hwSignal="cmd1s_cmu1s" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_ch2_cmp_match" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_ch2_compare_match_interrupt" hwSignal="cmd2s_cmu2s" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_in0" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_event0_interrupt" hwSignal="e0as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_in1" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_event1_interrupt" hwSignal="e1as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="event_in2" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_event2_interrupt" hwSignal="e2as" hwResource="//@hwResources.0" required="false"/>
  <virtualSignals name="st" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_st" hwSignal="st" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="st1" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_sta" hwSignal="sta" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="st2" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_stb" hwSignal="stb" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="out0" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_ch1_out_0" hwSignal="out0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="out1" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_ch1_out_1" hwSignal="out1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="out2" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_ch2_out_2" hwSignal="out2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="out3" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_ch2_out_3" hwSignal="out3" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="in0" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_gp0_unsync" hwSignal="gp0_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="in1" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_gp1_unsync" hwSignal="gp1_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="in2" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_gp2_unsync" hwSignal="gp2_unsync" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="gp0" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_gp0" hwSignal="gp0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="gp1" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_gp1" hwSignal="gp1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="gp2" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_gp2" hwSignal="gp2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mci0" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_mci00" hwSignal="mci0" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mci1" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_mci10" hwSignal="mci1" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mci2" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_mci20" hwSignal="mci2" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mci3" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_mci30" hwSignal="mci3" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="mcss" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_mcss" hwSignal="mcss" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="link_out" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_concat_bus_out" hwSignal="concat_bus_out" hwResource="//@hwResources.0" visible="true"/>
  <virtualSignals name="link_in" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_concat_bus_in" hwSignal="concat_bus_in" hwResource="//@hwResources.0" visible="true"/>
  <requiredApps URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/app_global_ccu8" requiredAppName="GLOBAL_CCU8" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#/0"/>
  </requiredApps>
  <hwResources name="CCU80 Config" URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/hwres_ccu8_cc8_slice" resourceGroupUri="peripheral/ccu8/*/cc8/*" mResGrpUri="peripheral/ccu8/*/cc8/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/CCU80/CCU80_0.dd#//@provided.43"/>
  </hwResources>
  <connections URI="http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_global/http://resources/4.0.22/app/CCU8_SLICE_CONFIG/0/vs_ccu8_cc8_config_global" systemDefined="true" sourceSignal="ccu8_global" targetSignal="global_signal" targetVirtualSignal="//@virtualSignals.0" proxySrcVirtualSignalUri="http://resources/4.1.12/app/GLOBAL_CCU8/0/vs_global_ccu8_globalsignal" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#/0/@virtualSignals.0"/>
    <srcVirtualSignal href="../../GLOBAL_CCU8/v4_1_12/GLOBAL_CCU8_0.app#/0/@virtualSignals.0"/>
  </connections>
</ResourceModel:App>
