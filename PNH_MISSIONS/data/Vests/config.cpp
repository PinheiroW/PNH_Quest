class CfgPatches
{
	class PNH_Missions_data_Vests
	{
		units[]=
		{
			"alp_UKAssVest_White",
			"alp_HighCapacityVest_White"
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
	class Clothing_Base;
	class Clothing;
	class HighCapacityVest_Black;
	class UKAssVest_Camo;
	class alp_UKAssVest_White: UKAssVest_Camo
	{
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"PNH_Missions\data\Vests\alp_UKAssVest_White_co.paa",
			"PNH_Missions\data\Vests\alp_UKAssVest_White_co.paa",
			"PNH_Missions\data\Vests\alp_UKAssVest_White_co.paa"
		};
	};
	class alp_HighCapacityVest_White: HighCapacityVest_Black
	{
		visibilityModifier=0.55000001;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"PNH_Missions\data\Vests\alp_HighCapacityVest_White_co.paa",
			"PNH_Missions\data\Vests\alp_HighCapacityVest_White_co.paa",
			"PNH_Missions\data\Vests\alp_HighCapacityVest_White_co.paa"
		};
	};
};
