<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="23008000">
	<Property Name="NI.LV.All.SourceOnly" Type="Bool">true</Property>
	<Property Name="varPersistentID:{0D32433D-28F0-45FE-A1F5-B284EDC48427}" Type="Ref">/My Computer/Zmienne_9.lvlib/DaneGen</Property>
	<Property Name="varPersistentID:{6140E12F-BF79-4E70-99B1-3B957E2016DA}" Type="Ref">/My Computer/Zmienne_9.lvlib/STOP</Property>
	<Property Name="varPersistentID:{8BB713DD-80F6-4DAF-8398-D488BC476E2D}" Type="Ref">/My Computer/Zmienne_9.lvlib/DaneGenNet</Property>
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="Host_9.vi" Type="VI" URL="../Host_9.vi"/>
		<Item Name="Target_9.vi" Type="VI" URL="../Target_9.vi"/>
		<Item Name="Zmienne_9.lvlib" Type="Library" URL="../Zmienne_9.lvlib"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="NI_AALBase.lvlib" Type="Library" URL="/&lt;vilib&gt;/Analysis/NI_AALBase.lvlib"/>
				<Item Name="NI_MABase.lvlib" Type="Library" URL="/&lt;vilib&gt;/measure/NI_MABase.lvlib"/>
			</Item>
			<Item Name="lvanlys.dll" Type="Document" URL="/&lt;resource&gt;/lvanlys.dll"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
