class CfgPatches
{
	class PNH_Core
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"VanillaPlusPlus"
		};
		author="Pinheiro";
		authorID="";
		name="PNH_Core";
		url="";
	};
};
class CfgMods
{
	class PNH_Core
	{
		type="mod";
		name="PNH - Core Scripts";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		inputs="PNH_Core/scripts/inputs/nd_info_inputs.xml";
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"BasicMapDefine/scripts/Common",
					"VPPAdminTools/Definitions",
					"DayZExpansion/Scripts/Common",
					"nst/namalsk/scripts/Common",
					"nst/ns_dayz/scripts/Common",
					"PNH_Core/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BasicMapDefine/scripts/Common",
					"VPPAdminTools/Definitions",
					"DayZExpansion/Scripts/Common",
					"nst/namalsk/scripts/Common",
					"nst/ns_dayz/scripts/Common",
					"PNH_Core/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"BasicMapDefine/scripts/Common",
					"VPPAdminTools/Definitions",
					"DayZExpansion/Scripts/Common",
					"nst/namalsk/scripts/Common",
					"nst/ns_dayz/scripts/Common",
					"PNH_Core/scripts/5_Mission"
				};
			};
		};
	};
};