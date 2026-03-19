class CfgPatches
{
	class ND_Clans
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"PNH_Core" // [CORREÇÃO] Garante que as constantes do PNH_Core carreguem ANTES deste mod
		};
		author="AlPepino / Pinheiro";
		authorID="76561198077747785";
		name="ND_Clans";
		url="";
	};
};

class CfgMods
{
	class ND_Clans
	{
		type="mod";
		name="ND - Clans";
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
				files[]=
				{
					"ND_Clans/scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"ND_Clans/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"ND_Clans/scripts/5_Mission"
				};
			};
		};
	};
};