class CfgPatches
{
	class PNH_Missions_data_Items
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"PNH_Missions",
			"PNH_Missions_data",
			"DZ_Gear_Navigation"
		};
	};
};
class MapDefaults;
class CfgVehicles
{
	class ItemMap;
	class ChernarusMap: ItemMap
	{
		itemSize[]={1,1};
		class MapProperties: MapDefaults
		{
			scaleMin=0.0099999998;
			scaleMax=0.75;
		};
	};
};
