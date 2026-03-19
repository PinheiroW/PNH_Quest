class CfgPatches
{
	class PNH_Economy
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
		name="PNH_Economy";
		url="";
	};
};
class CfgMods
{
	class PNH_Economy
	{
		type="mod";
		name="PNH - Economy Scripts";
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
				files[]={"PNH_Economy/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value="";
				files[]={"PNH_Economy/scripts/4_World"};
			};
			class missionScriptModule
			{
				value="";
				files[]={"PNH_Economy/scripts/5_Mission"};
			};
		};
	};
};