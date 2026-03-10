class CfgPatches
{
	class PNH_Missions_data_ServerConsole
	{
		units[]=
		{
			"alp_ServerConsole",
			"alp_OldControlPanel"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"PNH_Missions"
		};
	};
};
class CfgModels
{
	class Default;
	class ServerConsole: Default
	{
		sections[]=
		{
			"racks",
			"notebook"
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class alp_OldControlPanel: HouseNoDestruct
	{
		scope=1;
		model="\DZ\structures\industrial\CementWorks\Proxy\CementWorks_RotFurnace_Controlpanel.p3d";
	};
	class alp_ServerConsole: HouseNoDestruct
	{
		scope=1;
		model="PNH_Missions\data\ServerConsole\ServerConsole.p3d";
		hiddenSelections[]=
		{
			"notebook"
		};
		hiddenSelectionsTextures[]=
		{
			"PNH_Missions\data\ServerConsole\data\console.paa",
			"PNH_Missions\data\ServerConsole\data\console_broken.paa"
		};
		destrType="DestructBuilding";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10000;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=1;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class Melee
				{
					class Health
					{
						damage=1;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=1;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
};
