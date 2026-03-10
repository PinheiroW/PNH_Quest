class CfgPatches
{
	class PNH_Missions_data_ATM
	{
		units[]=
		{
			"alp_ATM"
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
	class HouseNoDestruct;
	class alp_ATM: HouseNoDestruct
	{
		scope=1;
		model="PNH_Missions\data\ATM\ATM.p3d";
	};
};
