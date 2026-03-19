class CfgPatches
{
	class PNH_Roleplay
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
		name="PNH_Roleplay";
		url="";
	};
};
class CfgMods
{
	class PNH_Roleplay
	{
		type="mod";
		name="PNH - Roleplay and Stats";
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
				files[]={"PNH_Roleplay/scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"PNH_Roleplay/scripts/5_Mission"};
			};
		};
	};
};