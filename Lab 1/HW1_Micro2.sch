<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="Microchip_By_element14_Batch_1">
<description>Developed by element14 :&lt;br&gt;
element14 CAD Library consolidation.ulp
at 30/07/2012 11:22:31</description>
<packages>
<package name="DIP254P724X406-28">
<pad name="1" x="-7.62" y="33.02" drill="0.9906" shape="square"/>
<pad name="2" x="-7.62" y="30.48" drill="0.9906"/>
<pad name="3" x="-7.62" y="27.94" drill="0.9906"/>
<pad name="4" x="-7.62" y="25.4" drill="0.9906"/>
<pad name="5" x="-7.62" y="22.86" drill="0.9906"/>
<pad name="6" x="-7.62" y="20.32" drill="0.9906"/>
<pad name="7" x="-7.62" y="17.78" drill="0.9906"/>
<pad name="8" x="-7.62" y="15.24" drill="0.9906"/>
<pad name="9" x="-7.62" y="12.7" drill="0.9906"/>
<pad name="10" x="-7.62" y="10.16" drill="0.9906"/>
<pad name="11" x="-7.62" y="7.62" drill="0.9906"/>
<pad name="12" x="-7.62" y="5.08" drill="0.9906"/>
<pad name="13" x="-7.62" y="2.54" drill="0.9906"/>
<pad name="14" x="-7.62" y="0" drill="0.9906"/>
<pad name="15" x="0" y="0" drill="0.9906"/>
<pad name="16" x="0" y="2.54" drill="0.9906"/>
<pad name="17" x="0" y="5.08" drill="0.9906"/>
<pad name="18" x="0" y="7.62" drill="0.9906"/>
<pad name="19" x="0" y="10.16" drill="0.9906"/>
<pad name="20" x="0" y="12.7" drill="0.9906"/>
<pad name="21" x="0" y="15.24" drill="0.9906"/>
<pad name="22" x="0" y="17.78" drill="0.9906"/>
<pad name="23" x="0" y="20.32" drill="0.9906"/>
<pad name="24" x="0" y="22.86" drill="0.9906"/>
<pad name="25" x="0" y="25.4" drill="0.9906"/>
<pad name="26" x="0" y="27.94" drill="0.9906"/>
<pad name="27" x="0" y="30.48" drill="0.9906"/>
<pad name="28" x="0" y="33.02" drill="0.9906"/>
<wire x1="-0.0508" y1="34.1122" x2="-0.0508" y2="34.29" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="31.5722" x2="-0.0508" y2="31.9278" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="29.0322" x2="-0.0508" y2="29.3878" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="26.4922" x2="-0.0508" y2="26.8478" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="23.9522" x2="-0.0508" y2="24.3078" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="-1.27" x2="-0.0508" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="-1.27" x2="-0.0508" y2="-1.0922" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="34.29" x2="-3.5052" y2="34.29" width="0.1524" layer="21"/>
<wire x1="-3.5052" y1="34.29" x2="-4.1148" y2="34.29" width="0.1524" layer="21"/>
<wire x1="-4.1148" y1="34.29" x2="-7.5692" y2="34.29" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="34.29" x2="-7.5692" y2="34.1122" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="31.9278" x2="-7.5692" y2="31.5722" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="29.3878" x2="-7.5692" y2="29.0322" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="26.8478" x2="-7.5692" y2="26.4922" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="24.3078" x2="-7.5692" y2="23.9522" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="21.7678" x2="-7.5692" y2="21.4122" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="19.2278" x2="-7.5692" y2="18.8722" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="16.6878" x2="-7.5692" y2="16.3322" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="14.1478" x2="-7.5692" y2="13.7922" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="11.6078" x2="-7.5692" y2="11.2522" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="9.0678" x2="-7.5692" y2="8.7122" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="6.5278" x2="-7.5692" y2="6.1722" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="3.9878" x2="-7.5692" y2="3.6322" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="1.4478" x2="-7.5692" y2="1.0922" width="0.1524" layer="21"/>
<wire x1="-7.5692" y1="-1.0922" x2="-7.5692" y2="-1.27" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="1.0922" x2="-0.0508" y2="1.4478" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="3.6322" x2="-0.0508" y2="3.9878" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="6.1722" x2="-0.0508" y2="6.5278" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="8.7122" x2="-0.0508" y2="9.0678" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="11.2522" x2="-0.0508" y2="11.6078" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="13.7922" x2="-0.0508" y2="14.1478" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="16.3322" x2="-0.0508" y2="16.6878" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="18.8722" x2="-0.0508" y2="19.2278" width="0.1524" layer="21"/>
<wire x1="-0.0508" y1="21.4122" x2="-0.0508" y2="21.7678" width="0.1524" layer="21"/>
<wire x1="-3.5052" y1="34.29" x2="-4.1148" y2="34.29" width="0" layer="21" curve="-180"/>
<text x="-8.2042" y="33.8836" size="1.27" layer="21" ratio="6" rot="SR0">*</text>
<wire x1="-7.5692" y1="32.512" x2="-7.5692" y2="33.528" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="33.528" x2="-8.128" y2="33.528" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="33.528" x2="-8.128" y2="32.512" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="32.512" x2="-7.5692" y2="32.512" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="29.972" x2="-7.5692" y2="30.988" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="30.988" x2="-8.128" y2="30.988" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="30.988" x2="-8.128" y2="29.972" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="29.972" x2="-7.5692" y2="29.972" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="27.432" x2="-7.5692" y2="28.448" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="28.448" x2="-8.128" y2="28.448" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="28.448" x2="-8.128" y2="27.432" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="27.432" x2="-7.5692" y2="27.432" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="24.892" x2="-7.5692" y2="25.908" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="25.908" x2="-8.128" y2="25.908" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="25.908" x2="-8.128" y2="24.892" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="24.892" x2="-7.5692" y2="24.892" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="22.352" x2="-7.5692" y2="23.368" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="23.368" x2="-8.128" y2="23.368" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="23.368" x2="-8.128" y2="22.352" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="22.352" x2="-7.5692" y2="22.352" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="19.812" x2="-7.5692" y2="20.828" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="20.828" x2="-8.128" y2="20.828" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="20.828" x2="-8.128" y2="19.812" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="19.812" x2="-7.5692" y2="19.812" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="17.272" x2="-7.5692" y2="18.288" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="18.288" x2="-8.128" y2="18.288" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="18.288" x2="-8.128" y2="17.272" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="17.272" x2="-7.5692" y2="17.272" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="14.732" x2="-7.5692" y2="15.748" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="15.748" x2="-8.128" y2="15.748" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="15.748" x2="-8.128" y2="14.732" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="14.732" x2="-7.5692" y2="14.732" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="12.192" x2="-7.5692" y2="13.208" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="13.208" x2="-8.128" y2="13.208" width="0.1524" layer="51"/>
<wire x1="-8.128" y1="13.208" x2="-8.1026" y2="12.192" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="12.192" x2="-7.5438" y2="12.192" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="9.652" x2="-7.5438" y2="10.668" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="10.668" x2="-8.1026" y2="10.668" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="10.668" x2="-8.1026" y2="9.652" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="9.652" x2="-7.5438" y2="9.652" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="7.112" x2="-7.5438" y2="8.128" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="8.128" x2="-8.1026" y2="8.128" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="8.128" x2="-8.1026" y2="7.112" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="7.112" x2="-7.5438" y2="7.112" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="4.572" x2="-7.5438" y2="5.588" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="5.588" x2="-8.1026" y2="5.588" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="5.588" x2="-8.1026" y2="4.572" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="4.572" x2="-7.5438" y2="4.572" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="2.032" x2="-7.5438" y2="3.048" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="3.048" x2="-8.1026" y2="3.048" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="3.048" x2="-8.1026" y2="2.032" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="2.032" x2="-7.5438" y2="2.032" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="-0.508" x2="-7.5438" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-7.5438" y1="0.508" x2="-8.1026" y2="0.4826" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="0.4826" x2="-8.1026" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-8.1026" y1="-0.508" x2="-7.5438" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="0.508" x2="-0.0508" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="-0.0508" y1="-0.508" x2="0.508" y2="-0.508" width="0.1524" layer="51"/>
<wire x1="0.508" y1="-0.508" x2="0.4826" y2="0.508" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="0.508" x2="-0.0762" y2="0.508" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="3.048" x2="-0.0508" y2="2.032" width="0.1524" layer="51"/>
<wire x1="-0.0508" y1="2.032" x2="0.508" y2="2.032" width="0.1524" layer="51"/>
<wire x1="0.508" y1="2.032" x2="0.4826" y2="3.048" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="3.048" x2="-0.0762" y2="3.048" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="5.588" x2="-0.0762" y2="4.572" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="4.572" x2="0.4826" y2="4.572" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="4.572" x2="0.4826" y2="5.588" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="5.588" x2="-0.0762" y2="5.588" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="8.128" x2="-0.0762" y2="7.112" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="7.112" x2="0.4826" y2="7.112" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="7.112" x2="0.4826" y2="8.128" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="8.128" x2="-0.0762" y2="8.128" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="10.668" x2="-0.0762" y2="9.652" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="9.652" x2="0.4826" y2="9.652" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="9.652" x2="0.4826" y2="10.668" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="10.668" x2="-0.0762" y2="10.668" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="13.208" x2="-0.0762" y2="12.192" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="12.192" x2="0.4826" y2="12.192" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="12.192" x2="0.4826" y2="13.208" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="13.208" x2="-0.0762" y2="13.208" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="15.748" x2="-0.0762" y2="14.732" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="14.732" x2="0.4826" y2="14.732" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="14.732" x2="0.4826" y2="15.748" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="15.748" x2="-0.0762" y2="15.748" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="18.288" x2="-0.0762" y2="17.272" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="17.272" x2="0.4826" y2="17.272" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="17.272" x2="0.4826" y2="18.288" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="18.288" x2="-0.0762" y2="18.288" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="20.828" x2="-0.0762" y2="19.812" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="19.812" x2="0.4826" y2="19.812" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="19.812" x2="0.4826" y2="20.828" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="20.828" x2="-0.0762" y2="20.828" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="23.368" x2="-0.0762" y2="22.352" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="22.352" x2="0.4826" y2="22.352" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="22.352" x2="0.4826" y2="23.368" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="23.368" x2="-0.0762" y2="23.368" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="25.908" x2="-0.0762" y2="24.892" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="24.892" x2="0.4826" y2="24.892" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="24.892" x2="0.4826" y2="25.908" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="25.908" x2="-0.0762" y2="25.908" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="28.448" x2="-0.0762" y2="27.432" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="27.432" x2="0.4826" y2="27.432" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="27.432" x2="0.4826" y2="28.448" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="28.448" x2="-0.0762" y2="28.448" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="30.988" x2="-0.0762" y2="29.972" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="29.972" x2="0.4826" y2="29.972" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="29.972" x2="0.4826" y2="30.988" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="30.988" x2="-0.0762" y2="30.988" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="33.528" x2="-0.0762" y2="32.512" width="0.1524" layer="51"/>
<wire x1="-0.0762" y1="32.512" x2="0.4826" y2="32.512" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="32.512" x2="0.4826" y2="33.528" width="0.1524" layer="51"/>
<wire x1="0.4826" y1="33.528" x2="-0.0762" y2="33.528" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="-1.27" x2="-0.0508" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-0.0508" y1="-1.27" x2="-0.0508" y2="34.29" width="0.1524" layer="51"/>
<wire x1="-0.0508" y1="34.29" x2="-3.5052" y2="34.29" width="0.1524" layer="51"/>
<wire x1="-3.5052" y1="34.29" x2="-4.1148" y2="34.29" width="0.1524" layer="51"/>
<wire x1="-4.1148" y1="34.29" x2="-7.5692" y2="34.29" width="0.1524" layer="51"/>
<wire x1="-7.5692" y1="34.29" x2="-7.5692" y2="-1.27" width="0.1524" layer="51"/>
<wire x1="-3.5052" y1="34.29" x2="-4.1148" y2="34.29" width="0" layer="51" curve="-180"/>
<text x="-8.2042" y="33.8836" size="1.27" layer="51" ratio="6" rot="SR0">*</text>
<text x="-8.4836" y="35.1028" size="2.0828" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-8.7122" y="-4.2164" size="2.0828" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="PIC16LF76-I/SP">
<pin name="*MCLR/VPP" x="-30.48" y="20.32" length="middle" direction="in"/>
<pin name="RA0/AN0" x="-30.48" y="17.78" length="middle"/>
<pin name="RA1/AN1" x="-30.48" y="15.24" length="middle"/>
<pin name="RA2/AN2" x="-30.48" y="12.7" length="middle"/>
<pin name="RA3/AN3/VREF" x="-30.48" y="10.16" length="middle"/>
<pin name="RA4/T0CKI" x="-30.48" y="7.62" length="middle"/>
<pin name="RA5/AN4/*SS" x="-30.48" y="5.08" length="middle"/>
<pin name="OSC1/CLKI" x="-30.48" y="-2.54" length="middle" direction="in"/>
<pin name="VDD" x="-30.48" y="-12.7" length="middle" direction="pwr"/>
<pin name="VSS_2" x="-30.48" y="-17.78" length="middle" direction="pas"/>
<pin name="VSS" x="-30.48" y="-20.32" length="middle" direction="pas"/>
<pin name="RC0/T1OSO/T1CKI" x="30.48" y="-25.4" length="middle" rot="R180"/>
<pin name="RC1/T1OSI/CCP2" x="30.48" y="-22.86" length="middle" rot="R180"/>
<pin name="RC2/CCP1" x="30.48" y="-20.32" length="middle" rot="R180"/>
<pin name="RC3/SCK/SCL" x="30.48" y="-17.78" length="middle" rot="R180"/>
<pin name="RC4/SDI/SDA" x="30.48" y="-15.24" length="middle" rot="R180"/>
<pin name="RC5/SDO" x="30.48" y="-12.7" length="middle" rot="R180"/>
<pin name="RC6/TX/CK" x="30.48" y="-10.16" length="middle" rot="R180"/>
<pin name="RC7/RX/DT" x="30.48" y="-7.62" length="middle" rot="R180"/>
<pin name="RB0/INT" x="30.48" y="-2.54" length="middle" rot="R180"/>
<pin name="RB1" x="30.48" y="0" length="middle" rot="R180"/>
<pin name="RB2" x="30.48" y="2.54" length="middle" rot="R180"/>
<pin name="RB3/PGM" x="30.48" y="5.08" length="middle" rot="R180"/>
<pin name="RB4" x="30.48" y="7.62" length="middle" rot="R180"/>
<pin name="RB5" x="30.48" y="10.16" length="middle" rot="R180"/>
<pin name="RB6/PGC" x="30.48" y="12.7" length="middle" rot="R180"/>
<pin name="RB7/PGD" x="30.48" y="15.24" length="middle" rot="R180"/>
<pin name="OSC2/CLKOUT" x="30.48" y="20.32" length="middle" direction="out" rot="R180"/>
<wire x1="-25.4" y1="25.4" x2="-25.4" y2="-30.48" width="0.4064" layer="94"/>
<wire x1="-25.4" y1="-30.48" x2="25.4" y2="-30.48" width="0.4064" layer="94"/>
<wire x1="25.4" y1="-30.48" x2="25.4" y2="25.4" width="0.4064" layer="94"/>
<wire x1="25.4" y1="25.4" x2="-25.4" y2="25.4" width="0.4064" layer="94"/>
<text x="-4.7244" y="29.4386" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.6642" y="26.8986" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="PIC16LF76-I/SP" prefix="U">
<description>IC PIC MCU FLASH 8KX14</description>
<gates>
<gate name="A" symbol="PIC16LF76-I/SP" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DIP254P724X406-28">
<connects>
<connect gate="A" pin="*MCLR/VPP" pad="1"/>
<connect gate="A" pin="OSC1/CLKI" pad="9"/>
<connect gate="A" pin="OSC2/CLKOUT" pad="10"/>
<connect gate="A" pin="RA0/AN0" pad="2"/>
<connect gate="A" pin="RA1/AN1" pad="3"/>
<connect gate="A" pin="RA2/AN2" pad="4"/>
<connect gate="A" pin="RA3/AN3/VREF" pad="5"/>
<connect gate="A" pin="RA4/T0CKI" pad="6"/>
<connect gate="A" pin="RA5/AN4/*SS" pad="7"/>
<connect gate="A" pin="RB0/INT" pad="21"/>
<connect gate="A" pin="RB1" pad="22"/>
<connect gate="A" pin="RB2" pad="23"/>
<connect gate="A" pin="RB3/PGM" pad="24"/>
<connect gate="A" pin="RB4" pad="25"/>
<connect gate="A" pin="RB5" pad="26"/>
<connect gate="A" pin="RB6/PGC" pad="27"/>
<connect gate="A" pin="RB7/PGD" pad="28"/>
<connect gate="A" pin="RC0/T1OSO/T1CKI" pad="11"/>
<connect gate="A" pin="RC1/T1OSI/CCP2" pad="12"/>
<connect gate="A" pin="RC2/CCP1" pad="13"/>
<connect gate="A" pin="RC3/SCK/SCL" pad="14"/>
<connect gate="A" pin="RC4/SDI/SDA" pad="15"/>
<connect gate="A" pin="RC5/SDO" pad="16"/>
<connect gate="A" pin="RC6/TX/CK" pad="17"/>
<connect gate="A" pin="RC7/RX/DT" pad="18"/>
<connect gate="A" pin="VDD" pad="20"/>
<connect gate="A" pin="VSS" pad="8"/>
<connect gate="A" pin="VSS_2" pad="19"/>
</connects>
<technologies>
<technology name="">
<attribute name="MPN" value="PIC16LF76-I/SP" constant="no"/>
<attribute name="OC_FARNELL" value="9761640" constant="no"/>
<attribute name="OC_NEWARK" value="97K7479" constant="no"/>
<attribute name="PACKAGE" value="28-DIP" constant="no"/>
<attribute name="SUPPLIER" value="Microchip" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="photo-elements">
<description>&lt;b&gt;Photocells&lt;/b&gt;&lt;p&gt;
Manufakturer: PerkinElmer Optoelektronics&lt;br&gt;
www.perkinelmer.com/opto</description>
<packages>
<package name="D11XX_H">
<description>&lt;b&gt;Photo Sensor&lt;/b&gt; Oil Burner Control Applications&lt;p&gt;
Source: http://optoelectronics.perkinelmer.com/content/Datasheets/DTS_PhotocellsD1160.pdf</description>
<wire x1="-3.05" y1="0" x2="-4.05" y2="1" width="0.2032" layer="21" curve="-90"/>
<wire x1="-4.05" y1="1" x2="-4.05" y2="19.95" width="0.2032" layer="21"/>
<wire x1="-4.05" y1="19.95" x2="4.05" y2="19.95" width="0.2032" layer="21" curve="-180"/>
<wire x1="4.05" y1="19.95" x2="4.05" y2="1" width="0.2032" layer="21"/>
<wire x1="4.05" y1="1" x2="3.05" y2="0" width="0.2032" layer="21" curve="-90"/>
<wire x1="3.05" y1="0" x2="-3.05" y2="0" width="0.2032" layer="21"/>
<wire x1="-2.5" y1="-5" x2="-2.5" y2="-4.125" width="0.4" layer="51"/>
<wire x1="-2.5" y1="-4.125" x2="-2.5" y2="-0.15" width="0.4" layer="21"/>
<wire x1="2.5" y1="-5" x2="2.5" y2="-4.125" width="0.4" layer="51"/>
<wire x1="2.5" y1="-4.125" x2="2.5" y2="-0.15" width="0.4" layer="21"/>
<pad name="1" x="-2.5" y="-5" drill="0.7" diameter="1.4"/>
<pad name="2" x="2.5" y="-5" drill="0.7" diameter="1.4"/>
<text x="-4.445" y="0.635" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="0" y="2.54" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
<rectangle x1="-3.25" y1="16" x2="3.25" y2="22.25" layer="21"/>
</package>
<package name="W55XX_H">
<description>&lt;b&gt;Photo Sensor&lt;/b&gt; Oil Burner Control Applications&lt;p&gt;
Source: http://optoelectronics.perkinelmer.com/content/Datasheets/DTS_PhotocellsD1160.pdf</description>
<wire x1="-5.925" y1="24.9" x2="-3.925" y2="26.9" width="0.2032" layer="21" curve="-90"/>
<wire x1="-3.925" y1="26.9" x2="3.925" y2="26.9" width="0.2032" layer="21"/>
<wire x1="3.925" y1="26.9" x2="5.925" y2="24.9" width="0.2032" layer="21" curve="-90"/>
<wire x1="-5.925" y1="24.9" x2="-5.925" y2="2" width="0.2032" layer="21"/>
<wire x1="-5.925" y1="2" x2="-3.925" y2="0" width="0.2032" layer="21" curve="90"/>
<wire x1="-3.925" y1="0" x2="3.925" y2="0" width="0.2032" layer="21"/>
<wire x1="3.925" y1="0" x2="5.925" y2="2" width="0.2032" layer="21" curve="90"/>
<wire x1="5.925" y1="2" x2="5.925" y2="24.9" width="0.2032" layer="21"/>
<wire x1="-3.81" y1="-5.08" x2="-3.81" y2="-0.145" width="0.4" layer="21"/>
<wire x1="-3.81" y1="-5.08" x2="-3.81" y2="-6" width="0.4" layer="51"/>
<wire x1="3.81" y1="-5.08" x2="3.81" y2="-0.145" width="0.4" layer="21"/>
<wire x1="3.81" y1="-5.08" x2="3.81" y2="-6" width="0.4" layer="51"/>
<pad name="1" x="-3.81" y="-6" drill="0.7" diameter="1.4"/>
<pad name="2" x="3.81" y="-6" drill="0.7" diameter="1.4"/>
<text x="-6.35" y="1.27" size="1.27" layer="25" rot="R90">&gt;NAME</text>
<text x="-3.81" y="3.175" size="1.27" layer="27">&gt;VALUE</text>
<rectangle x1="-4.5" y1="9" x2="4.5" y2="25" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="PHOTOCELL">
<wire x1="-3.048" y1="2.413" x2="-1.651" y2="1.016" width="0.1524" layer="94"/>
<wire x1="-3.175" y1="1.27" x2="-1.778" y2="-0.127" width="0.1524" layer="94"/>
<wire x1="0" y1="-2.54" x2="-1.016" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.016" y1="-1.143" x2="-1.016" y2="-0.381" width="0.254" layer="94"/>
<wire x1="-1.016" y1="-0.381" x2="1.016" y2="0.381" width="0.254" layer="94"/>
<wire x1="1.016" y1="0.381" x2="-1.016" y2="1.143" width="0.254" layer="94"/>
<wire x1="-1.016" y1="1.143" x2="1.016" y2="1.905" width="0.254" layer="94"/>
<wire x1="0" y1="2.54" x2="1.016" y2="1.905" width="0.254" layer="94"/>
<wire x1="-1.016" y1="-1.905" x2="1.016" y2="-1.143" width="0.254" layer="94"/>
<text x="2.54" y="0" size="1.778" layer="95">&gt;NAME</text>
<text x="2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="1" x="0" y="5.08" visible="off" length="short" direction="pas" swaplevel="1" rot="R270"/>
<pin name="2" x="0" y="-5.08" visible="off" length="short" direction="pas" swaplevel="1" rot="R90"/>
<polygon width="0.1524" layer="94">
<vertex x="-1.778" y="-0.127"/>
<vertex x="-2.667" y="0.254"/>
<vertex x="-2.159" y="0.762"/>
</polygon>
<polygon width="0.1524" layer="94">
<vertex x="-1.651" y="1.016"/>
<vertex x="-2.54" y="1.397"/>
<vertex x="-2.032" y="1.905"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="PHOTOCELL" prefix="PH">
<description>&lt;b&gt;Photo Sensor&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="PHOTOCELL" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="D11" package="D11XX_H">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
<device name="W55" package="W55XX_H">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Vishay_By_element14_Batch_1">
<description>Developed by element14 :&lt;br&gt;
element14 CAD Library consolidation.ulp
at 30/07/2012 16:36:08</description>
<packages>
<package name="RESC1608X60N">
<smd name="1" x="-0.8382" y="0" dx="0.762" dy="0.9398" layer="1"/>
<smd name="2" x="0.8382" y="0" dx="0.762" dy="0.9398" layer="1"/>
<wire x1="-0.127" y1="-0.4826" x2="0.127" y2="-0.4826" width="0.1524" layer="21"/>
<wire x1="0.127" y1="0.4826" x2="-0.127" y2="0.4826" width="0.1524" layer="21"/>
<wire x1="-0.4572" y1="-0.4826" x2="-0.4572" y2="0.4826" width="0" layer="51"/>
<wire x1="-0.4572" y1="0.4826" x2="-0.8382" y2="0.4826" width="0" layer="51"/>
<wire x1="-0.8382" y1="-0.4826" x2="-0.4572" y2="-0.4826" width="0" layer="51"/>
<wire x1="0.4572" y1="0.4826" x2="0.4572" y2="-0.4826" width="0" layer="51"/>
<wire x1="0.4572" y1="-0.4826" x2="0.8382" y2="-0.4826" width="0" layer="51"/>
<wire x1="0.8382" y1="0.4826" x2="0.4572" y2="0.4826" width="0" layer="51"/>
<wire x1="-0.4572" y1="-0.4826" x2="0.4572" y2="-0.4826" width="0" layer="51"/>
<wire x1="0.8382" y1="-0.4826" x2="0.8382" y2="0.4826" width="0" layer="51"/>
<wire x1="0.4572" y1="0.4826" x2="-0.4572" y2="0.4826" width="0" layer="51"/>
<wire x1="-0.8382" y1="0.4826" x2="-0.8382" y2="-0.4826" width="0" layer="51"/>
<text x="-3.4544" y="1.27" size="2.0828" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-3.4544" y="-3.175" size="2.0828" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="RESH">
<pin name="2" x="0" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="1" x="12.7" y="0" visible="off" length="short" direction="pas" rot="R180"/>
<wire x1="3.175" y1="1.27" x2="4.445" y2="-1.27" width="0.2032" layer="94"/>
<wire x1="4.445" y1="-1.27" x2="5.715" y2="1.27" width="0.2032" layer="94"/>
<wire x1="5.715" y1="1.27" x2="6.985" y2="-1.27" width="0.2032" layer="94"/>
<wire x1="6.985" y1="-1.27" x2="8.255" y2="1.27" width="0.2032" layer="94"/>
<wire x1="8.255" y1="1.27" x2="9.525" y2="-1.27" width="0.2032" layer="94"/>
<wire x1="2.54" y1="0" x2="3.175" y2="1.27" width="0.2032" layer="94"/>
<wire x1="9.525" y1="-1.27" x2="10.16" y2="0" width="0.2032" layer="94"/>
<text x="-3.1242" y="-8.7376" size="3.4798" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
<text x="0.9906" y="2.7686" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CRCW060312K4FKEA" prefix="R">
<description>RESISTOR, 0603</description>
<gates>
<gate name="A" symbol="RESH" x="0" y="0" swaplevel="1"/>
</gates>
<devices>
<device name="" package="RESC1608X60N">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MPN" value="CRCW060312K4FKEA" constant="no"/>
<attribute name="OC_FARNELL" value="1652836" constant="no"/>
<attribute name="OC_NEWARK" value="52K8106" constant="no"/>
<attribute name="SUPPLIER" value="Vishay" constant="no"/>
<attribute name="TOLERANCE" value="± 1.0 %" constant="no"/>
<attribute name="VALUE" value="12.4K Ohms" constant="no"/>
<attribute name="WATTAGE" value="0.1W" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Chicago Miniature Lighting_By_element14_Batch_1">
<description>Developed by element14 :&lt;br&gt;
element14 CAD Library consolidation.ulp
at 25/07/2012 10:00:40</description>
<packages>
<package name="LED_CMD17-21VYC_TR8">
<smd name="1" x="-1.0668" y="0" dx="0.762" dy="1.4478" layer="1"/>
<smd name="2" x="1.0668" y="0" dx="0.762" dy="1.4478" layer="1"/>
<wire x1="-3.3782" y1="0.0254" x2="-2.4384" y2="0.0254" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-2.1844" y2="0.0254" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="-0.6096" x2="-2.4384" y2="0.0254" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-2.4384" y2="0.6604" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.6096" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.4826" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.3556" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.2286" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.1016" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.6604" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.5334" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.4064" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.2794" width="0.1524" layer="21"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.1524" width="0.1524" layer="21"/>
<wire x1="-3.2004" y1="-0.6096" x2="-3.2004" y2="0.6604" width="0.1524" layer="21"/>
<wire x1="-0.3556" y1="-0.7366" x2="0.3556" y2="-0.7366" width="0.1524" layer="21"/>
<wire x1="0.3556" y1="0.7366" x2="-0.3556" y2="0.7366" width="0.1524" layer="21"/>
<wire x1="-3.4544" y1="0.0254" x2="-2.4384" y2="0.0254" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-2.1844" y2="0.0254" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="-0.6096" x2="-2.4384" y2="0.0254" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-2.4384" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.6096" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.4826" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.3556" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.2286" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="-0.1016" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.5334" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.4064" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.2794" width="0.1524" layer="51"/>
<wire x1="-2.4384" y1="0.0254" x2="-3.2004" y2="0.1524" width="0.1524" layer="51"/>
<wire x1="-3.2004" y1="-0.6096" x2="-3.2004" y2="0.6604" width="0.1524" layer="51"/>
<wire x1="-0.7112" y1="-0.7366" x2="-0.7112" y2="0.7366" width="0.1524" layer="51"/>
<wire x1="-0.7112" y1="0.7366" x2="-1.0922" y2="0.7366" width="0.1524" layer="51"/>
<wire x1="-1.0922" y1="-0.7366" x2="-0.7112" y2="-0.7366" width="0.1524" layer="51"/>
<wire x1="0.7112" y1="0.7366" x2="0.7112" y2="-0.7366" width="0.1524" layer="51"/>
<wire x1="0.7112" y1="-0.7366" x2="1.0922" y2="-0.7366" width="0.1524" layer="51"/>
<wire x1="1.0922" y1="0.7366" x2="0.7112" y2="0.7366" width="0.1524" layer="51"/>
<wire x1="-0.7112" y1="-0.7366" x2="0.7112" y2="-0.7366" width="0.1524" layer="51"/>
<wire x1="1.0922" y1="-0.7366" x2="1.0922" y2="0.7366" width="0.1524" layer="51"/>
<wire x1="0.7112" y1="0.7366" x2="-0.7112" y2="0.7366" width="0.1524" layer="51"/>
<wire x1="-1.0922" y1="0.7366" x2="-1.0922" y2="-0.7366" width="0.1524" layer="51"/>
<text x="-4.699" y="1.2954" size="2.0828" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-5.6896" y="-3.5052" size="2.0828" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="CMD17-21VYC_TR8">
<pin name="1" x="0" y="0" visible="off" length="short" direction="pas" swaplevel="1"/>
<pin name="2" x="10.16" y="0" visible="off" length="short" direction="pas" swaplevel="1" rot="R180"/>
<wire x1="3.81" y1="1.905" x2="3.81" y2="0" width="0.2032" layer="94"/>
<wire x1="3.81" y1="0" x2="3.81" y2="-1.905" width="0.2032" layer="94"/>
<wire x1="2.54" y1="0" x2="3.81" y2="0" width="0.2032" layer="94"/>
<wire x1="6.35" y1="-1.905" x2="6.35" y2="0" width="0.2032" layer="94"/>
<wire x1="6.35" y1="0" x2="6.35" y2="1.905" width="0.2032" layer="94"/>
<wire x1="6.35" y1="0" x2="7.62" y2="0" width="0.2032" layer="94"/>
<wire x1="6.35" y1="4.445" x2="6.985" y2="3.81" width="0.2032" layer="94"/>
<wire x1="6.985" y1="3.81" x2="8.255" y2="5.08" width="0.2032" layer="94"/>
<wire x1="8.255" y1="3.81" x2="8.89" y2="3.175" width="0.2032" layer="94"/>
<wire x1="8.89" y1="3.175" x2="10.16" y2="4.445" width="0.2032" layer="94"/>
<wire x1="8.255" y1="5.08" x2="7.62" y2="5.08" width="0.2032" layer="94"/>
<wire x1="7.62" y1="5.08" x2="8.255" y2="4.445" width="0.2032" layer="94"/>
<wire x1="8.255" y1="4.445" x2="8.255" y2="5.08" width="0.2032" layer="94"/>
<wire x1="10.16" y1="4.445" x2="9.525" y2="4.445" width="0.2032" layer="94"/>
<wire x1="9.525" y1="4.445" x2="10.16" y2="3.81" width="0.2032" layer="94"/>
<wire x1="10.16" y1="3.81" x2="10.16" y2="4.445" width="0.2032" layer="94"/>
<wire x1="6.985" y1="2.54" x2="8.255" y2="3.81" width="0.2032" layer="94"/>
<wire x1="6.35" y1="0" x2="3.81" y2="1.905" width="0.2032" layer="94"/>
<wire x1="3.81" y1="-1.905" x2="6.35" y2="0" width="0.2032" layer="94"/>
<wire x1="5.08" y1="3.175" x2="6.35" y2="4.445" width="0.2032" layer="94"/>
<text x="-4.3942" y="-9.3472" size="3.4798" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
<text x="-2.7432" y="3.1496" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CMD17-21VYC_TR8" prefix="LED">
<description>LED, YELLOW, 12MCD, 585NM</description>
<gates>
<gate name="A" symbol="CMD17-21VYC_TR8" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LED_CMD17-21VYC_TR8">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="LEDCOLOR" value="YELLOW" constant="no"/>
<attribute name="MPN" value="CMD17-21VYC_TR8" constant="no"/>
<attribute name="OC_FARNELL" value="-" constant="no"/>
<attribute name="OC_NEWARK" value="34C8665" constant="no"/>
<attribute name="PACKAGE" value="2 -PIN LED" constant="no"/>
<attribute name="SUPPLIER" value="CHICAGO MINIATURE LIGHTING" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="VDD">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="0" y1="1.27" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<wire x1="1.27" y1="-1.905" x2="0" y2="1.27" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="VDD" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" prefix="GND">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="VDD" prefix="VDD">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="G$1" symbol="VDD" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="SAMTEC-Txx_By_element14_Batch_1">
<description>Developed by element14 :&lt;br&gt;
element14 CAD Library consolidation.ulp
at 09/08/2012 16:12:58</description>
<packages>
<package name="SAMTEC_TLW-107-06-T-S">
<pad name="1" x="-15.24" y="0" drill="0.9652" shape="square"/>
<pad name="2" x="-12.7" y="0" drill="0.9652"/>
<pad name="3" x="-10.16" y="0" drill="0.9652"/>
<pad name="4" x="-7.62" y="0" drill="0.9652"/>
<pad name="5" x="-5.08" y="0" drill="0.9652"/>
<pad name="6" x="-2.54" y="0" drill="0.9652"/>
<pad name="7" x="0" y="0" drill="0.9652"/>
<wire x1="-16.51" y1="-1.2446" x2="1.27" y2="-1.2446" width="0.1524" layer="21"/>
<wire x1="1.27" y1="-1.2446" x2="1.27" y2="1.2446" width="0.1524" layer="21"/>
<wire x1="1.27" y1="1.2446" x2="-16.51" y2="1.2446" width="0.1524" layer="21"/>
<wire x1="-16.51" y1="1.2446" x2="-16.51" y2="-1.2446" width="0.1524" layer="21"/>
<wire x1="-14.986" y1="2.2098" x2="-15.494" y2="2.2098" width="0.508" layer="21" curve="-180"/>
<wire x1="-15.494" y1="2.2098" x2="-14.986" y2="2.2098" width="0.508" layer="21" curve="-180"/>
<wire x1="-16.51" y1="-1.2446" x2="1.27" y2="-1.2446" width="0.1524" layer="51"/>
<wire x1="1.27" y1="-1.2446" x2="1.27" y2="1.2446" width="0.1524" layer="51"/>
<wire x1="1.27" y1="1.2446" x2="-16.51" y2="1.2446" width="0.1524" layer="51"/>
<wire x1="-16.51" y1="1.2446" x2="-16.51" y2="-1.2446" width="0.1524" layer="51"/>
<wire x1="-14.986" y1="2.2098" x2="-15.494" y2="2.2098" width="0.508" layer="51" curve="-180"/>
<wire x1="-15.494" y1="2.2098" x2="-14.986" y2="2.2098" width="0.508" layer="51" curve="-180"/>
<text x="-12.319" y="1.6002" size="2.0828" layer="25" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-13.2334" y="-4.1402" size="2.0828" layer="27" ratio="10" rot="SR0">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="TLW-107-06-T-S">
<pin name="1" x="-12.7" y="5.08" length="middle" direction="pas"/>
<pin name="2" x="-12.7" y="2.54" length="middle" direction="pas"/>
<pin name="3" x="-12.7" y="0" length="middle" direction="pas"/>
<pin name="4" x="-12.7" y="-2.54" length="middle" direction="pas"/>
<pin name="5" x="-12.7" y="-5.08" length="middle" direction="pas"/>
<pin name="6" x="-12.7" y="-7.62" length="middle" direction="pas"/>
<pin name="7" x="-12.7" y="-10.16" length="middle" direction="pas"/>
<wire x1="-7.62" y1="10.16" x2="-7.62" y2="-15.24" width="0.4064" layer="94"/>
<wire x1="-7.62" y1="-15.24" x2="17.78" y2="-15.24" width="0.4064" layer="94"/>
<wire x1="17.78" y1="-15.24" x2="17.78" y2="10.16" width="0.4064" layer="94"/>
<wire x1="17.78" y1="10.16" x2="-7.62" y2="10.16" width="0.4064" layer="94"/>
<text x="0.2794" y="11.811" size="2.0828" layer="95" ratio="10" rot="SR0">&gt;NAME</text>
<text x="-0.2286" y="-18.1102" size="2.0828" layer="96" ratio="10" rot="SR0">&gt;VALUE</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="TLW-107-06-T-S" prefix="J">
<description>CONNECTOR HEADER, 7 WAY, 1ROW</description>
<gates>
<gate name="A" symbol="TLW-107-06-T-S" x="0" y="0"/>
</gates>
<devices>
<device name="" package="SAMTEC_TLW-107-06-T-S">
<connects>
<connect gate="A" pin="1" pad="1"/>
<connect gate="A" pin="2" pad="2"/>
<connect gate="A" pin="3" pad="3"/>
<connect gate="A" pin="4" pad="4"/>
<connect gate="A" pin="5" pad="5"/>
<connect gate="A" pin="6" pad="6"/>
<connect gate="A" pin="7" pad="7"/>
</connects>
<technologies>
<technology name="">
<attribute name="MPN" value="TLW-107-06-T-S" constant="no"/>
<attribute name="OC_FARNELL" value="-" constant="no"/>
<attribute name="OC_NEWARK" value="12P0419" constant="no"/>
<attribute name="PACKAGE" value="CONN HEADER 7 POS .100 inch" constant="no"/>
<attribute name="SUPPLIER" value="SAMTEC" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="." library="Microchip_By_element14_Batch_1" deviceset="PIC16LF76-I/SP" device="" value="PIC16F18857"/>
<part name="PH2" library="photo-elements" deviceset="PHOTOCELL" device="D11"/>
<part name="R1" library="Vishay_By_element14_Batch_1" deviceset="CRCW060312K4FKEA" device="" value="10K Ohms"/>
<part name="LED1" library="Chicago Miniature Lighting_By_element14_Batch_1" deviceset="CMD17-21VYC_TR8" device="" value=""/>
<part name="GND1" library="supply1" deviceset="GND" device=""/>
<part name="R2" library="Vishay_By_element14_Batch_1" deviceset="CRCW060312K4FKEA" device="" value="220 Ohms"/>
<part name="VDD1" library="supply1" deviceset="VDD" device=""/>
<part name="VDD2" library="supply1" deviceset="VDD" device=""/>
<part name="VDD3" library="supply1" deviceset="VDD" device=""/>
<part name="VDD5" library="supply1" deviceset="VDD" device=""/>
<part name="GND2" library="supply1" deviceset="GND" device=""/>
<part name="PIC_KIT_3" library="SAMTEC-Txx_By_element14_Batch_1" deviceset="TLW-107-06-T-S" device="" value=""/>
<part name="VDD6" library="supply1" deviceset="VDD" device="" value="VPP"/>
<part name="VDD7" library="supply1" deviceset="VDD" device="" value="VPP"/>
<part name="GND3" library="supply1" deviceset="GND" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="." gate="A" x="66.04" y="45.72"/>
<instance part="PH2" gate="G$1" x="12.7" y="48.26"/>
<instance part="R1" gate="A" x="12.7" y="66.04" rot="R90"/>
<instance part="LED1" gate="A" x="106.68" y="30.48" rot="R270"/>
<instance part="GND1" gate="1" x="12.7" y="10.16"/>
<instance part="R2" gate="A" x="106.68" y="43.18" rot="R90"/>
<instance part="VDD1" gate="G$1" x="22.86" y="38.1"/>
<instance part="VDD2" gate="G$1" x="22.86" y="38.1"/>
<instance part="VDD3" gate="G$1" x="12.7" y="91.44"/>
<instance part="VDD5" gate="G$1" x="121.92" y="91.44"/>
<instance part="GND2" gate="1" x="121.92" y="10.16"/>
<instance part="PIC_KIT_3" gate="A" x="147.32" y="38.1"/>
<instance part="VDD6" gate="G$1" x="129.54" y="91.44"/>
<instance part="VDD7" gate="G$1" x="30.48" y="91.44"/>
<instance part="GND3" gate="1" x="106.68" y="10.16"/>
</instances>
<busses>
</busses>
<nets>
<net name="N$1" class="0">
<segment>
<pinref part="R1" gate="A" pin="2"/>
<pinref part="PH2" gate="G$1" pin="1"/>
<wire x1="12.7" y1="66.04" x2="12.7" y2="63.5" width="0.1524" layer="91"/>
<pinref part="." gate="A" pin="RA0/AN0"/>
<wire x1="12.7" y1="63.5" x2="12.7" y2="53.34" width="0.1524" layer="91"/>
<wire x1="35.56" y1="63.5" x2="12.7" y2="63.5" width="0.1524" layer="91"/>
<junction x="12.7" y="63.5"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="PH2" gate="G$1" pin="2"/>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="12.7" y1="43.18" x2="12.7" y2="25.4" width="0.1524" layer="91"/>
<pinref part="." gate="A" pin="VSS"/>
<wire x1="12.7" y1="25.4" x2="12.7" y2="12.7" width="0.1524" layer="91"/>
<wire x1="35.56" y1="25.4" x2="12.7" y2="25.4" width="0.1524" layer="91"/>
<junction x="12.7" y="25.4"/>
</segment>
<segment>
<pinref part="PIC_KIT_3" gate="A" pin="3"/>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="134.62" y1="38.1" x2="121.92" y2="38.1" width="0.1524" layer="91"/>
<wire x1="121.92" y1="38.1" x2="121.92" y2="12.7" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="LED1" gate="A" pin="2"/>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="106.68" y1="20.32" x2="106.68" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="." gate="A" pin="RB5"/>
<wire x1="96.52" y1="55.88" x2="106.68" y2="55.88" width="0.1524" layer="91"/>
<pinref part="R2" gate="A" pin="1"/>
</segment>
</net>
<net name="VDD" class="0">
<segment>
<pinref part="VDD1" gate="G$1" pin="VDD"/>
<pinref part="VDD2" gate="G$1" pin="VDD"/>
<pinref part="." gate="A" pin="VDD"/>
<wire x1="35.56" y1="33.02" x2="22.86" y2="33.02" width="0.1524" layer="91"/>
<wire x1="22.86" y1="33.02" x2="22.86" y2="35.56" width="0.1524" layer="91"/>
<junction x="22.86" y="35.56"/>
</segment>
<segment>
<pinref part="R1" gate="A" pin="1"/>
<wire x1="12.7" y1="78.74" x2="12.7" y2="88.9" width="0.1524" layer="91"/>
<junction x="12.7" y="88.9"/>
<pinref part="VDD3" gate="G$1" pin="VDD"/>
</segment>
<segment>
<pinref part="VDD5" gate="G$1" pin="VDD"/>
<wire x1="121.92" y1="88.9" x2="121.92" y2="40.64" width="0.1524" layer="91"/>
<wire x1="134.62" y1="40.64" x2="121.92" y2="40.64" width="0.1524" layer="91"/>
<pinref part="PIC_KIT_3" gate="A" pin="2"/>
</segment>
<segment>
<pinref part="VDD7" gate="G$1" pin="VDD"/>
<wire x1="30.48" y1="88.9" x2="30.48" y2="66.04" width="0.1524" layer="91"/>
<pinref part="." gate="A" pin="*MCLR/VPP"/>
<wire x1="30.48" y1="66.04" x2="35.56" y2="66.04" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="VDD6" gate="G$1" pin="VDD"/>
<wire x1="129.54" y1="88.9" x2="129.54" y2="43.18" width="0.1524" layer="91"/>
<pinref part="PIC_KIT_3" gate="A" pin="1"/>
<wire x1="134.62" y1="43.18" x2="129.54" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<wire x1="101.6" y1="35.56" x2="101.6" y2="60.96" width="0.1524" layer="91"/>
<pinref part="." gate="A" pin="RB7/PGD"/>
<wire x1="101.6" y1="60.96" x2="96.52" y2="60.96" width="0.1524" layer="91"/>
<pinref part="PIC_KIT_3" gate="A" pin="4"/>
<wire x1="134.62" y1="35.56" x2="101.6" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<wire x1="99.06" y1="33.02" x2="99.06" y2="58.42" width="0.1524" layer="91"/>
<pinref part="." gate="A" pin="RB6/PGC"/>
<wire x1="99.06" y1="58.42" x2="96.52" y2="58.42" width="0.1524" layer="91"/>
<wire x1="99.06" y1="33.02" x2="134.62" y2="33.02" width="0.1524" layer="91"/>
<pinref part="PIC_KIT_3" gate="A" pin="5"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="LED1" gate="A" pin="1"/>
<pinref part="R2" gate="A" pin="2"/>
<wire x1="106.68" y1="30.48" x2="106.68" y2="43.18" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>
