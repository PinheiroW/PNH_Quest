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
			"DZ_Scripts",
			"PNH_Core" 
		};
		author="Pinheiro";
		authorID="";
		name="PNH_Missions";
		url="";
	};
};
class CfgMods
{
	class PNH_Missions
	{
		type="mod";
		name="PNH - Missions Events";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]={"PNH_Missions/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"PNH_Missions/scripts/4_World"};
			};
		};
	};
};