class CfgPatches
{
	class PNH_Missions_data_AntiRadSpray
	{
		units[]=
		{
			"alp_DecontaminationSpray"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"PNH_Missions"
		};
	};
};
class CfgVehicles
{
	class DisinfectantSpray;
	class alp_DecontaminationSpray: DisinfectantSpray
	{
		displayName="#STR_alp_decontaminationspray";
		descriptionShort="#STR_alp_decontaminationspray_desc";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"PNH_Missions\data\AntiRadSpray\antiradspray_co.paa"
		};
	};
};
