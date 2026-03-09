class CfgPatches
{
	class BXD_Missions
	{
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};
class CfgMods
{
	class BXD_Missions
	{
		name = "Survivor Missions";
		author = "clonacartao";
		authorID = "0";
		version = "1.0";
		credits = "";
		type = "mod";
		dir = "BXD_Missions";
		hideName = 0;
		hidePicture = 0;
		extra = 0;
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BXD_Missions/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BXD_Missions/scripts/5_Mission"};
			};
		};
	};
};
