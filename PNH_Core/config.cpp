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
			"DZ_Scripts"
		};
		author="AlPepino";
		authorID="76561198077747785";
		name="PNH_Core";
		url="";
	};
};
class CfgMods
{
	class PNH_Core
	{
		type="mod";
		name="ND - Missions";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		inputs="PNH_Core\scripts\inputs\nd_info_inputs.xml";
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"PNH_Core/gui/imagesets/nd_dayz_gui.imageset"
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
