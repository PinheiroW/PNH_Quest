class CfgPatches
{
	class PNH_Missions_data_LifeInsurance
	{
		units[]=
		{
			"alp_LifeInsuranceExclusive",
			"alp_Debitcard"
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
	class LifeInsurance
	{
		sections[]=
		{
			"zbytek"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Switchable_Base;
	class Powered_Base;
	class alp_Card: Inventory_Base
	{
		model="PNH_Missions\data\LifeInsurance\LifeInsurance.p3d";
		weight=10;
		itemSize[]={1,1};
		rotationFlags=16;
		lootCategory="Tools";
		varEnergyInit=1000;
		varEnergyMin=0;
		varEnergyMax=1000;
		class EnergyManager
		{
			energyAtSpawn=1000;
			energyUsagePerSecond=0.001653439;
			updateInterval=60;
		};
		lootTag[]=
		{
			"Civilian",
			"Office"
		};
		hiddenSelections[]=
		{
			"zbytek"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpPaper_SoundSet";
					id=797;
				};
			};
		};
	};
	class alp_LifeInsuranceExclusive: alp_Card
	{
		scope=2;
		displayName="$STR_alp_lifeinsurance";
		descriptionShort="$STR_alp_lifeinsurance_desc";
		hiddenSelectionsTextures[]=
		{
			"PNH_Missions\data\LifeInsurance\data\LifeInsurance_co.paa"
		};
	};
	class alp_Debitcard: Inventory_Base
	{
		scope=2;
		model="PNH_Missions\data\LifeInsurance\LifeInsurance.p3d";
		displayName="$STR_alp_debitcard";
		descriptionShort="$STR_alp_debitcard_desc";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"PNH_Missions\data\LifeInsurance\data\creditcard_co.paa"
		};
		weight=10;
		itemSize[]={1,1};
		rotationFlags=16;
		lootCategory="Tools";
		lootTag[]=
		{
			"Civilian",
			"Office"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=30;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"PNH_Missions\data\LifeInsurance\data\LifeInsurance_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet="pickUpPaper_SoundSet";
					id=797;
				};
			};
		};
	};
};
