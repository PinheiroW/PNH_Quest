class CfgPatches
{
	class PNH_Notifications
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"PNH_Core" 
		};
		author="Pinheiro";
		authorID="";
		name="PNH_Notifications";
		url="";
	};
};
class CfgMods
{
	class PNH_Notifications
	{
		type="mod";
		name="PNH - Notifications and Info";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"PNH_Notifications/scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"PNH_Notifications/scripts/5_Mission"};
			};
		};
	};
};