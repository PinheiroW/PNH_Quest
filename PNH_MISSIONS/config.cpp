class CfgPatches
{
	class PNH_Missions
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
		author="AlPepino";
		authorID="76561198077747785";
		name="PNH_Missions";
		url="";
	};
};
class CfgMods
{
	class PNH_Missions
	{
		type="mod";
		name="ND - Missions";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		inputs="PNH_Missions\scripts\inputs\nd_info_inputs.xml";
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"PNH_Missions/gui/imagesets/nd_dayz_gui.imageset"
				};
			};
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
					"PNH_Missions/scripts/3_Game"
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
					"PNH_Missions/scripts/4_World"
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
					"PNH_Missions/scripts/5_Mission"
				};
			};
		};
	};
};
