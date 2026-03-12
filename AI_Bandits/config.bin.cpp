class CfgMods
{
	class AI_Bandits
	{
		dir="AI_Bandits";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="DayZ AI_Bandits";
		credits="MarioE, Kamo, Sajid_Alfa, Nazzgy, Waltari";
		author="Hunterz";
		overview="$STR_dayzcat_overview";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		defines[]=
		{
			"AI_BANDITS"
		};
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
				files[]=
				{
					"AI_Bandits/Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				files[]=
				{
					"AI_Bandits/Scripts/4_World"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"AI_Bandits/scripts/5_Mission"
				};
			};
		};
	};
};
class CfgPatches
{
	class AI_Bandits
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Sounds_Effects",
			"DZ_Weapons_Explosives",
			"DZ_Characters",
			"DZ_Characters_Heads",
			"DZ_Characters_Zombies"
		};
	};
};
class CfgSlots
{
	class Slot_BanditHead
	{
		name="BanditHead";
		displayName="";
		ghostIcon="";
		show="false";
	};
	class Slot_BanditHands
	{
		name="BanditHands";
		displayName="";
		ghostIcon="set:dayz_inventory image:hands";
		boneName="RightHand";
		show="false";
	};
	class Slot_BanditBody
	{
		name="BanditBody";
		displayName="#STR_CfgBody0";
		ghostIcon="set:dayz_inventory image:body";
		show="false";
	};
	class Slot_BanditLegs
	{
		name="BanditLegs";
		displayName="#STR_CfgLegs0";
		ghostIcon="set:dayz_inventory image:legs";
		show="false";
	};
	class Slot_BanditFeet
	{
		name="BanditFeet";
		displayName="#STR_CfgFeet0";
		ghostIcon="set:dayz_inventory image:feet";
		show="false";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBanditBody
	{
		scope=2;
		simulation="ProxyInventory";
		inventorySlot="BanditBody";
		autocenter=0;
		animated=0;
		model="";
		shadow=1;
		reversed=1;
	};
	class ProxyBanditFeet
	{
		scope=2;
		simulation="ProxyInventory";
		inventorySlot="BanditFeet";
		autocenter=0;
		animated=0;
		model="";
		shadow=1;
		reversed=1;
	};
	class ProxyBanditHands
	{
		scope=2;
		simulation="ProxyInventory";
		inventorySlot="BanditHands";
		autocenter=0;
		animated=0;
		model="";
		shadow=1;
		reversed=1;
	};
	class ProxyBanditHead
	{
		scope=2;
		simulation="ProxyInventory";
		inventorySlot="BanditHead";
		autocenter=0;
		animated=0;
		model="";
		shadow=1;
		reversed=1;
	};
	class ProxyBanditLegs
	{
		scope=2;
		simulation="ProxyInventory";
		inventorySlot="BanditLegs";
		autocenter=0;
		animated=0;
		model="";
		shadow=1;
		reversed=1;
	};
	class ProxyBanditBody_DZ: ProxyBanditBody
	{
		model="AI_Bandits\models\proxy\BanditBody_DZ.p3d";
	};
	class ProxyBanditFeet_DZ: ProxyBanditFeet
	{
		model="AI_Bandits\models\proxy\BanditFeet_DZ.p3d";
	};
	class ProxyBanditHands_DZ: ProxyBanditHands
	{
		model="AI_Bandits\models\proxy\BanditHands_DZ.p3d";
	};
	class ProxyBanditHead_DZ: ProxyBanditHead
	{
		model="AI_Bandits\models\proxy\BanditHead_DZ.p3d";
	};
	class ProxyBanditLegs_DZ: ProxyBanditLegs
	{
		model="AI_Bandits\models\proxy\BanditLegs_DZ.p3d";
	};
};
class cfgWeapons
{
	class RifleCore;
	class Rifle_Base: RifleCore
	{
		forceFarBubble="true";
	};
	class Pistol_Base;
	class FNX45_Base: Pistol_Base
	{
		forceFarBubble="true";
	};
};
class CfgVehicles
{
	class Clothing;
	class Inventory_Base;
	class DayZInfected;
	class HouseNoDestruct;
	class AIBox100x80x20: HouseNoDestruct
	{
		scope=1;
		model="AI_Bandits\models\helpers\box100x80x20.p3d";
		overrideDrawArea="6.0";
		forceFarBubble="true";
	};
	class AIBox1x1x1: HouseNoDestruct
	{
		scope=1;
		model="AI_Bandits\models\helpers\box1x1x1.p3d";
		overrideDrawArea="6.0";
		forceFarBubble="true";
	};
	class InfectedBanditBase: DayZInfected
	{
		scope=0;
		faction="dz_Civ_US";
		rarityUrban=-1;
		displayWeight=0;
		simulation="dayzinfected";
		class enfanimsys
		{
			meshObject="AI_Bandits\anims\bandit.xob";
			graphname="AI_Bandits\anims\animgraph\bandits.agr";
			defaultinstance="AI_Bandits\anims\animgraph\bandits.asi";
			startnode="Master_SM";
			skeletonName="bandit.xob";
		};
		class InputController
		{
			movementSpeedMapping[]={0,1.5,2.9000001,8.8999996};
			lookAtFilterTimeout=0.5;
			lookAtFilterSpeed=1.5700001;
		};
		accuracy=0;
		threat[]={1,0.050000001,0.050000001};
		displayName="$STR_cfgvehicles_survivor0";
		descriptionShort="$STR_cfgvehicles_survivor1";
		vehicleClass="Zombie";
		zombieLoot="civilian";
		storageCategory=3;
		attackSounds="zombie_attack";
		spottedSounds="zombie_spotted";
		chaseSounds="zombie_chase";
		idleSounds="zombie_idle";
		hiddenSelections[]=
		{
			"camo"
		};
		languages[]={};
		htMin=60;
		htMax=1800;
		afMax=30;
		mfMax=0;
		mFact=1;
		tBody=37;
		selectionPersonality="personality";
		faceType="MaleWhiteHeadNew";
		launcherBone="launcher";
		handGunBone="RightHand";
		weaponBone="weapon";
		selectionHeadWound="injury_head";
		selectionBodyWound="injury_body";
		selectionLArmWound="injury_hands";
		selectionRArmWound="injury_hands";
		selectionLLegWound="injury_legs";
		selectionRLegWound="injury_legs";
		memoryPointLStep="footstepL";
		memoryPointRStep="footstepR";
		memoryPointAim="aimPoint";
		memoryPointCameraTarget="camera";
		memoryPointCommonDamage="l_femur_hit";
		memoryPointLeaningAxis="leaning_axis";
		memoryPointAimingAxis="aiming_axis";
		memoryPointHeadAxis="head_axis";
		selectionLBrow="lBrow";
		selectionMBrow="mBrow";
		selectionRBrow="rBrow";
		selectionLMouth="lMouth";
		selectionMMouth="mMouth";
		selectionRMouth="rMouth";
		selectionEyelid="Eyelids";
		selectionLip="LLip";
		class P3DAttachments
		{
			P3DProxies[]=
			{
				"righthand"
			};
			BoneNames[]=
			{
				"righthand"
			};
		};
		class InventoryEquipment
		{
			playerSlots[]=
			{
				"Slot_BanditHands2"
			};
		};
		class Wounds
		{
			tex[]={};
			mat[]=
			{
				"dz\characters\zombies\data\coveralls.rvmat",
				"dz\characters\zombies\data\coveralls_injury.rvmat",
				"dz\characters\zombies\data\coveralls_injury.rvmat"
			};
		};
		aiAgentTemplate="Bandit";
		class NoiseTemplates
		{
			class StepNoise
			{
				strength=10;
				type="sound";
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=30;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1.5;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.69999999;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
						};
					};
					componentNames[]=
					{
						"Head",
						"Neck"
					};
					fatalInjuryCoef=0.1;
					inventorySlots[]=
					{
						"Headgear",
						"Mask"
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=1.2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"Spine1",
						"Spine3"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
				};
				class LeftArm: Torso
				{
					componentNames[]=
					{
						"LeftArm",
						"LeftForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class RightArm: LeftArm
				{
					componentNames[]=
					{
						"RightArm",
						"RightForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftLeg",
						"LeftUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class RightLeg: LeftLeg
				{
					componentNames[]=
					{
						"RightLeg",
						"RightUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"LeftLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"LeftFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
				class RightFoot: LeftFoot
				{
					transferToZonesNames[]=
					{
						"RightLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"RightFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
			};
		};
		class AnimEvents
		{
			class Steps
			{
				class walkErc_L
				{
					soundLookupTable="walkErc_Char_LookupTable";
					id=1;
				};
				class walkErc_R
				{
					soundLookupTable="walkErc_Char_LookupTable";
					id=2;
				};
				class runErc_L
				{
					soundLookupTable="runErc_Char_LookupTable";
					id=3;
				};
				class runErc_R
				{
					soundLookupTable="runErc_Char_LookupTable";
					id=4;
				};
				class sprintErc_L
				{
					soundLookupTable="sprintErc_Char_LookupTable";
					id=5;
				};
				class sprintErc_R
				{
					soundLookupTable="sprintErc_Char_LookupTable";
					id=6;
				};
				class scuffErc_L
				{
					soundLookupTable="scuffErc_Char_LookupTable";
					id=7;
				};
				class scuffErc_R
				{
					soundLookupTable="scuffErc_Char_LookupTable";
					id=8;
				};
				class HandStep
				{
					soundLookupTable="handstepSound_Char_LookupTable";
					id=11;
				};
				class stepfall_DeleteLater
				{
					soundLookupTable="bodyfallSound_Char_LookupTable";
					id=14;
				};
				class Bodyfall_hand_DeleteLater
				{
					soundLookupTable="bodyfall_handSound_Char_LookupTable";
					id=15;
				};
				class Bodyfall_slide_DeleteLater
				{
					soundLookupTable="bodyfall_slideSound_Char_LookupTable";
					id=16;
				};
				class Bodyfall_rollHard
				{
					soundLookupTable="bodyfall_rollHardSound_Char_LookupTable";
					id=101;
				};
				class Bodyfall_roll
				{
					soundLookupTable="bodyfall_rollSound_Char_LookupTable";
					id=17;
				};
				class walkCro_L
				{
					soundLookupTable="walkCro_Char_LookupTable";
					id=21;
				};
				class walkCro_R
				{
					soundLookupTable="walkCro_Char_LookupTable";
					id=22;
				};
				class runCro_L
				{
					soundLookupTable="runCro_Char_LookupTable";
					id=23;
				};
				class runCro_R
				{
					soundLookupTable="runCro_Char_LookupTable";
					id=24;
				};
				class walkProne_L
				{
					soundLookupTable="walkProne_Char_LookupTable";
					id=31;
				};
				class walkProne_R
				{
					soundLookupTable="walkProne_Char_LookupTable";
					id=32;
				};
				class runProne_L
				{
					soundLookupTable="runProne_Char_LookupTable";
					id=33;
				};
				class runProne_R
				{
					soundLookupTable="runProne_Char_LookupTable";
					id=34;
				};
				class walkProneElbow_L
				{
					soundLookupTable="walkProneElbow_Char_LookupTable";
					id=41;
				};
				class walkProneElbow_R
				{
					soundLookupTable="walkProneElbow_Char_LookupTable";
					id=42;
				};
				class runProneElbow_L
				{
					soundLookupTable="runProneElbow_Char_LookupTable";
					id=43;
				};
				class runProneElbow_R
				{
					soundLookupTable="runProneElbow_Char_LookupTable";
					id=44;
				};
				class jumpErc_L
				{
					soundLookupTable="jumpErc_Char_LookupTable";
					id=35;
				};
				class jumpErc_R
				{
					soundLookupTable="jumpErc_Char_LookupTable";
					id=36;
				};
				class landFootErc_L
				{
					soundLookupTable="landFootErc_Char_LookupTable";
					id=37;
				};
				class landFootErc_R
				{
					soundLookupTable="landFootErc_Char_LookupTable";
					id=38;
				};
				class walkRasErc_L
				{
					soundLookupTable="walkRasErc_Char_LookupTable";
					id=51;
				};
				class walkRasErc_R
				{
					soundLookupTable="walkRasErc_Char_LookupTable";
					id=52;
				};
				class runRasErc_L
				{
					soundLookupTable="runRasErc_Char_LookupTable";
					id=53;
				};
				class runRasErc_R
				{
					soundLookupTable="runRasErc_Char_LookupTable";
					id=54;
				};
				class HandStep_L
				{
					soundLookupTable="handstepSound_Char_LookupTable";
					id=61;
				};
				class HandStep_R
				{
					soundLookupTable="handstepSound_Char_LookupTable";
					id=62;
				};
				class HandStep_Hard_L
				{
					soundLookupTable="handstepSound_Hard_Char_LookupTable";
					id=63;
				};
				class HandStep_Hard_R
				{
					soundLookupTable="handstepSound_Hard_Char_LookupTable";
					id=64;
				};
				class landFeetErc
				{
					soundLookupTable="landFeetErc_Char_LookupTable";
					id=100;
				};
				class Bodyfall
				{
					soundLookupTable="bodyfallSound_Char_LookupTable";
					id=110;
				};
				class Bodyfall_hand
				{
					soundLookupTable="bodyfall_handSound_Char_LookupTable";
					id=111;
				};
				class Bodyfall_slide
				{
					soundLookupTable="bodyfall_slideSound_Char_LookupTable";
					id=112;
				};
				class Bodyfall_slide_light
				{
					soundLookupTable="bodyfall_slide_lightSound_Char_LookupTable";
					id=113;
				};
				class Bodyfall_hand_light
				{
					soundLookupTable="bodyfall_hand_lightSound_Char_LookupTable";
					id=114;
				};
				class walkProne_noHS
				{
					soundLookupTable="walkProne_noHS_Char_LookupTable";
					id=131;
				};
				class walkProneLong_noHS
				{
					soundLookupTable="walkProneLong_noHS_Char_LookupTable";
					id=132;
				};
				class HandsStep
				{
					soundLookupTable="handsstepSound_Char_LookupTable";
					id=161;
				};
				class Dropitem
				{
					soundLookupTable="drop_item_LookupTable";
					id=201;
				};
				class step_ladder
				{
					soundLookupTable="step_ladder_Char_LookupTable";
					id=1026;
				};
				class step_ladder_run
				{
					soundLookupTable="step_ladder_run_Char_LookupTable";
					id=1027;
				};
			};
			class Sounds
			{
				class Dig_Hoe_SoundSet
				{
					soundset="Dig_Hoe_Soundset";
					id=1;
				};
				class Hack_Bush_Leaf
				{
					soundSet="Hack_Bush_Leaf_SoundSet";
					id=3;
				};
				class putItemInventory
				{
					soundSet="putItemInventory_SoundSet";
					id=5;
				};
				class tuneRadio
				{
					soundSet="tuneRadio_SoundSet";
					id=8;
				};
				class mapIn
				{
					soundSet="mapIn_SoundSet";
					id=9;
				};
				class mapOut
				{
					soundSet="mapOut_SoundSet";
					id=10;
				};
				class noteIn
				{
					soundSet="noteIn_SoundSet";
					id=11;
				};
				class noteOut
				{
					soundSet="noteOut_SoundSet";
					id=12;
				};
				class minePickAxe
				{
					soundSet="minePickAxe_SoundSet";
					id=13;
				};
				class Dig_PickAxe_End
				{
					soundSet="Dig_PickAxe_End_SoundSet";
					id=14;
				};
				class Dig_PickAxe
				{
					soundSet="Dig_PickAxe_SoundSet";
					id=15;
				};
				class cutBarkLoop
				{
					soundSet="cutBarkLoop_SoundSet";
					id=16;
				};
				class cutBarkEnd
				{
					soundSet="cutBarkEnd_SoundSet";
					id=17;
				};
				class RiverWater_in_A
				{
					soundSet="RiverWater_in_A_SoundSet";
					id=21;
				};
				class pickUpCanisterGasolineLight
				{
					soundSet="pickUpCanisterGasolineLight_SoundSet";
					id=22;
				};
				class pickUpCanisterGasoline
				{
					soundSet="pickUpCanisterGasoline_SoundSet";
					id=23;
				};
				class flip_GasolineCanister
				{
					soundSet="flip_GasolineCanister_SoundSet";
					id=24;
				};
				class Pot_Shake
				{
					soundSet="Pot_Shake_SoundSet";
					id=25;
				};
				class step_ladder
				{
					soundSet="step_ladder_Char_Soundset";
					id=26;
				};
				class step_ladder_run
				{
					soundSet="step_ladder_run_Char_Soundset";
					id=27;
				};
				class Flashlight_TurnOn
				{
					soundSet="Flashlight_TurnOn_SoundSet";
					id=28;
				};
				class Flashlight_TurnOff
				{
					soundSet="Flashlight_TurnOff_SoundSet";
					id=29;
				};
				class turnOnMegaphone
				{
					soundSet="turnOnMegaphone_SoundSet";
					id=30;
				};
				class turnOffMegaphone
				{
					soundSet="turnOffMegaphone_SoundSet";
					id=31;
				};
				class seedpack_open
				{
					soundSet="seedpack_open_SoundSet";
					id=32;
				};
				class seedpack_empty
				{
					soundSet="seedpack_empty_SoundSet";
					id=33;
				};
				class Morphine_spear
				{
					soundSet="Morphine_spear_SoundSet";
					id=34;
				};
				class Morphine_out
				{
					soundSet="Morphine_out_Soundset";
					id=35;
				};
				class Hanckuff_Close_1
				{
					soundSet="handcuff_close_1_SoundSet";
					id=36;
				};
				class Hanckuff_Close_2
				{
					soundSet="handcuff_close_2_SoundSet";
					id=37;
				};
				class rope_tieup
				{
					soundSet="rope_tieup_SoundSet";
					id=38;
				};
				class rope_tieup_end
				{
					soundSet="rope_tieup_end_SoundSet";
					id=39;
				};
				class rope_tieup_back
				{
					soundSet="rope_tieup_back_SoundSet";
					id=40;
				};
				class mineBushHand
				{
					soundSet="mineBushHand_SoundSet";
					id=41;
				};
				class EatCandy
				{
					soundSet="EatingCandy_SoundSet";
					id=42;
				};
				class AlarmClock_SetUp_Loop
				{
					soundSet="AlarmClock_SetUp_Loop_SoundSet";
					id=1545;
				};
				class KitchenTimer_SetUp_Loop
				{
					soundSet="KitchenTimer_SetUp_Loop_SoundSet";
					id=1570;
				};
				class KitchenTimer_TurningOff
				{
					soundSet="KitchenTimer_TurningOff_SoundSet";
					id=1571;
				};
				class GPSReceiver_TurnOn
				{
					soundSet="GPSReceiver_TurnOn_SoundSet";
					id=1575;
				};
				class BlowTorch_TurnOn
				{
					soundSet="BlowTorch_TurnOn_SoundSet";
					id=1580;
				};
				class BlowTorch_TurnOff
				{
					soundSet="BlowTorch_TurnOff_SoundSet";
					id=1581;
				};
				class BlowTorch_Loop
				{
					soundSet="BlowTorch_Loop_SoundSet";
					id=1582;
				};
				class Flag_in
				{
					soundSet="Flag_in_SoundSet";
					id=50;
				};
				class Flag_out
				{
					soundSet="Flag_out_SoundSet";
					id=51;
				};
				class Flag_raise_loop
				{
					soundSet="Flag_raise_loop_SoundSet";
					id=52;
				};
				class Flag_lower_loop
				{
					soundSet="Flag_lower_loop_SoundSet";
					id=53;
				};
				class Pill_consuming_bottle
				{
					soundSet="Pill_consuming_bottle_SoundSet";
					id=1800;
				};
				class Pill_consuming_pack
				{
					soundSet="Pill_consuming_pack_SoundSet";
					id=1801;
				};
				class Clean_hands_bottle_in
				{
					soundSet="Clean_hands_bottle_in_SoundSet";
					id=1802;
				};
				class Clean_hands_bottle_loop
				{
					soundSet="Clean_hands_bottle_loop_SoundSet";
					id=1803;
				};
				class Clean_hands_bottle_out
				{
					soundSet="Clean_hands_bottle_out_SoundSet";
					id=1804;
				};
				class CleanHands_pond_loop
				{
					soundSet="CleanHands_pond_loop_SoundSet";
					id=1806;
				};
				class CleanHands_pond_in
				{
					soundSet="CleanHands_pond_in_SoundSet";
					id=1807;
				};
				class CleanHands_pump_in
				{
					soundSet="CleanHands_pump_in_SoundSet";
					id=1808;
				};
				class Heatpack
				{
					soundSet="Heatpack_SoundSet";
					id=1805;
				};
				class HandClap
				{
					soundSet="Char_Gestures_HandClap_SoundSet";
					id=1809;
				};
				class BloodTest
				{
					soundSet="BloodTest_SoundSet";
					id=1810;
				};
				class BloodTest_other
				{
					soundSet="BloodTest_other_SoundSet";
					id=1811;
				};
				class WringClothes
				{
					soundSet="WringClothes_SoundSet";
					id=1812;
				};
				class Axe_firewood
				{
					soundSet="Axe_Firewood_SoundSet";
					id=1813;
				};
				class Saw_Firewood
				{
					soundSet="Saw_Firewood_SoundSet";
					id=1814;
				};
				class Hatchet_Firewood
				{
					soundSet="Hatchet_Firewood_SoundSet";
					id=1815;
				};
				class DuctTape_patching_start
				{
					soundSet="DuctTape_patching_start_SoundSet";
					id=1816;
				};
				class DuctTape_patching_end
				{
					soundSet="DuctTape_patching_end_SoundSet";
					id=1817;
				};
				class CZ75_charge_open
				{
					soundSet="CZ75_charge_open_SoundSet";
					id=101;
				};
				class CZ75_charge_open_release
				{
					soundSet="CZ75_charge_open_release_SoundSet";
					id=102;
				};
				class CZ75_charge_close
				{
					soundSet="CZ75_charge_close_SoundSet";
					id=103;
				};
				class CZ75_charge_close_release
				{
					soundSet="CZ75_charge_close_release_SoundSet";
					id=104;
				};
				class CZ75_chamber_load
				{
					soundSet="CZ75_chamber_load_SoundSet";
					id=105;
				};
				class CZ75_mag_in
				{
					soundSet="CZ75_mag_in_SoundSet";
					id=106;
				};
				class CZ75_mag_load
				{
					soundSet="CZ75_mag_load_SoundSet";
					id=107;
				};
				class CZ75_mag_remove
				{
					soundSet="CZ75_mag_remove_SoundSet";
					id=108;
				};
				class CZ75_dry
				{
					soundSet="CZ75_dry_SoundSet";
					id=110;
				};
				class CZ75_pullout
				{
					soundSet="CZ75_pullout_SoundSet";
					id=111;
				};
				class CZ75_dry_uncock
				{
					soundSet="CZ75_dry_uncock_SoundSet";
					id=113;
				};
				class CZ75_jamming1
				{
					soundSet="CZ75_jamming1_SoundSet";
					id=1001;
				};
				class CZ75_jamming2
				{
					soundSet="CZ75_jamming2_SoundSet";
					id=1002;
				};
				class CZ75_jamming3
				{
					soundSet="CZ75_jamming3_SoundSet";
					id=1003;
				};
				class CZ75_jamming4
				{
					soundSet="CZ75_jamming4_SoundSet";
					id=1004;
				};
				class CZ75_jamming5
				{
					soundSet="CZ75_jamming5_SoundSet";
					id=1005;
				};
				class CZ75_jamming6
				{
					soundSet="CZ75_jamming6_SoundSet";
					id=1006;
				};
				class CZ75_jamming7
				{
					soundSet="CZ75_jamming7_SoundSet";
					id=1007;
				};
				class CZ75_jamming8
				{
					soundSet="CZ75_jamming8_SoundSet";
					id=1008;
				};
				class CZ75_jamming9
				{
					soundSet="CZ75_jamming9_SoundSet";
					id=1009;
				};
				class CZ75_jamming10
				{
					soundSet="CZ75_jamming10_SoundSet";
					id=1010;
				};
				class CZ75_jamming11
				{
					soundSet="CZ75_jamming11_SoundSet";
					id=1011;
				};
				class CZ75_jamming12
				{
					soundSet="CZ75_jamming12_SoundSet";
					id=1012;
				};
				class CZ75_jamming13
				{
					soundSet="CZ75_jamming13_SoundSet";
					id=1013;
				};
				class CZ75_jam
				{
					soundSet="CZ75_jam_SoundSet";
					id=115;
				};
				class FNX45_charge_open
				{
					soundSet="FNX45_charge_open_SoundSet";
					id=121;
				};
				class FNX45_charge_open_release
				{
					soundSet="FNX45_charge_open_release_SoundSet";
					id=122;
				};
				class FNX45_charge_close
				{
					soundSet="FNX45_charge_close_SoundSet";
					id=123;
				};
				class FNX45_charge_close_release
				{
					soundSet="FNX45_charge_close_release_SoundSet";
					id=124;
				};
				class FNX45_chamber_load
				{
					soundSet="FNX45_chamber_load_SoundSet";
					id=125;
				};
				class FNX45_mag_in
				{
					soundSet="FNX45_mag_in_SoundSet";
					id=126;
				};
				class FNX45_mag_load
				{
					soundSet="FNX45_mag_load_SoundSet";
					id=127;
				};
				class FNX45_mag_remove
				{
					soundSet="FNX45_mag_remove_SoundSet";
					id=128;
				};
				class FNX45_dry
				{
					soundSet="FNX45_dry_SoundSet";
					id=130;
				};
				class FNX45_pullout
				{
					soundSet="FNX45_pullout_SoundSet";
					id=131;
				};
				class FNX45_dry_uncock
				{
					soundSet="FNX45_dry_uncock_SoundSet";
					id=132;
				};
				class FNX45_jamming1
				{
					soundSet="FNX45_jamming1_SoundSet";
					id=133;
				};
				class FNX45_jamming2
				{
					soundSet="FNX45_jamming2_SoundSet";
					id=134;
				};
				class FNX45_jamming3
				{
					soundSet="FNX45_jamming3_SoundSet";
					id=135;
				};
				class FNX45_jamming4
				{
					soundSet="FNX45_jamming4_SoundSet";
					id=136;
				};
				class FNX45_jamming5
				{
					soundSet="FNX45_jamming5_SoundSet";
					id=137;
				};
				class FNX45_jamming6
				{
					soundSet="FNX45_jamming6_SoundSet";
					id=138;
				};
				class FNX45_jamming7
				{
					soundSet="FNX45_jamming7_SoundSet";
					id=139;
				};
				class FNX45_jamming8
				{
					soundSet="FNX45_jamming8_SoundSet";
					id=140;
				};
				class FNX45_jamming9
				{
					soundSet="FNX45_jamming9_SoundSet";
					id=141;
				};
				class FNX45_jamming10
				{
					soundSet="FNX45_jamming10_SoundSet";
					id=142;
				};
				class FNX45_jamming11
				{
					soundSet="FNX45_jamming11_SoundSet";
					id=143;
				};
				class FNX45_jamming12
				{
					soundSet="FNX45_jamming12_SoundSet";
					id=144;
				};
				class FNX45_jamming13
				{
					soundSet="FNX45_jamming13_SoundSet";
					id=145;
				};
				class FNX45_jam
				{
					soundSet="FNX45_jam_SoundSet";
					id=146;
				};
				class IJ70_charge_open
				{
					soundSet="IJ70_charge_open_SoundSet";
					id=151;
				};
				class IJ70_charge_open_release
				{
					soundSet="IJ70_charge_open_release_SoundSet";
					id=152;
				};
				class IJ70_charge_close
				{
					soundSet="IJ70_charge_close_SoundSet";
					id=153;
				};
				class IJ70_charge_close_release
				{
					soundSet="IJ70_charge_close_release_SoundSet";
					id=154;
				};
				class IJ70_chamber_load
				{
					soundSet="IJ70_chamber_load_SoundSet";
					id=155;
				};
				class IJ70_mag_in
				{
					soundSet="IJ70_mag_in_SoundSet";
					id=156;
				};
				class IJ70_mag_load
				{
					soundSet="IJ70_mag_load_SoundSet";
					id=157;
				};
				class IJ70_mag_remove
				{
					soundSet="IJ70_mag_remove_SoundSet";
					id=158;
				};
				class IJ70_dry
				{
					soundSet="IJ70_dry_SoundSet";
					id=160;
				};
				class IJ70_pullout
				{
					soundSet="IJ70_pullout_SoundSet";
					id=161;
				};
				class IJ70_mag_push
				{
					soundSet="IJ70_mag_push_SoundSet";
					id=162;
				};
				class IJ70_dry_uncock
				{
					soundSet="IJ70_dry_uncock_SoundSet";
					id=163;
				};
				class IJ70_jamming1
				{
					soundSet="IJ70_jamming1_SoundSet";
					id=1014;
				};
				class IJ70_jamming2
				{
					soundSet="IJ70_jamming2_SoundSet";
					id=1015;
				};
				class IJ70_jamming3
				{
					soundSet="IJ70_jamming3_SoundSet";
					id=1016;
				};
				class IJ70_jamming4
				{
					soundSet="IJ70_jamming4_SoundSet";
					id=1017;
				};
				class IJ70_jamming5
				{
					soundSet="IJ70_jamming5_SoundSet";
					id=1018;
				};
				class IJ70_jamming6
				{
					soundSet="IJ70_jamming6_SoundSet";
					id=1019;
				};
				class IJ70_jamming7
				{
					soundSet="IJ70_jamming7_SoundSet";
					id=1020;
				};
				class IJ70_jamming8
				{
					soundSet="IJ70_jamming8_SoundSet";
					id=1021;
				};
				class IJ70_jamming9
				{
					soundSet="IJ70_jamming9_SoundSet";
					id=1022;
				};
				class IJ70_jamming10
				{
					soundSet="IJ70_jamming10_SoundSet";
					id=1023;
				};
				class IJ70_jamming11
				{
					soundSet="IJ70_jamming11_SoundSet";
					id=1024;
				};
				class IJ70_jamming12
				{
					soundSet="IJ70_jamming12_SoundSet";
					id=1025;
				};
				class IJ70_jamming13
				{
					soundSet="IJ70_jamming13_SoundSet";
					id=1026;
				};
				class IJ70_jam
				{
					soundSet="IJ70_jam_SoundSet";
					id=114;
				};
				class CZ61_charge_open
				{
					soundSet="CZ61_charge_open_SoundSet";
					id=171;
				};
				class CZ61_charge_open_release
				{
					soundSet="CZ61_charge_open_release_SoundSet";
					id=172;
				};
				class CZ61_charge_close
				{
					soundSet="CZ61_charge_close_SoundSet";
					id=173;
				};
				class CZ61_charge_close_release
				{
					soundSet="CZ61_charge_close_release_SoundSet";
					id=174;
				};
				class CZ61_chamber_load
				{
					soundSet="CZ61_chamber_load_SoundSet";
					id=175;
				};
				class CZ61_mag_in
				{
					soundSet="CZ61_mag_in_SoundSet";
					id=176;
				};
				class CZ61_mag_load
				{
					soundSet="CZ61_mag_load_SoundSet";
					id=177;
				};
				class CZ61_mag_remove
				{
					soundSet="CZ61_mag_remove_SoundSet";
					id=178;
				};
				class CZ61_dry
				{
					soundSet="CZ61_dry_SoundSet";
					id=180;
				};
				class CZ61_pullout
				{
					soundSet="CZ61_pullout_SoundSet";
					id=181;
				};
				class CZ61_mag_out
				{
					soundSet="CZ61_mag_out_SoundSet";
					id=182;
				};
				class CZ61_hand
				{
					soundSet="CZ61_hand_SoundSet";
					id=183;
				};
				class CZ61_jamming1
				{
					soundSet="CZ61_jamming1_SoundSet";
					id=1027;
				};
				class CZ61_jamming2
				{
					soundSet="CZ61_jamming2_SoundSet";
					id=1028;
				};
				class CZ61_jamming3
				{
					soundSet="CZ61_jamming3_SoundSet";
					id=1029;
				};
				class CZ61_jamming4
				{
					soundSet="CZ61_jamming4_SoundSet";
					id=1030;
				};
				class CZ61_jamming5
				{
					soundSet="CZ61_jamming5_SoundSet";
					id=1031;
				};
				class CZ61_jamming6
				{
					soundSet="CZ61_jamming6_SoundSet";
					id=1032;
				};
				class CZ61_jamming7
				{
					soundSet="CZ61_jamming7_SoundSet";
					id=1033;
				};
				class CZ61_jamming8
				{
					soundSet="CZ61_jamming8_SoundSet";
					id=1034;
				};
				class CZ61_jamming9
				{
					soundSet="CZ61_jamming9_SoundSet";
					id=1035;
				};
				class CZ61_jamming10
				{
					soundSet="CZ61_jamming10_SoundSet";
					id=1036;
				};
				class CZ61_jamming11
				{
					soundSet="CZ61_jamming11_SoundSet";
					id=1037;
				};
				class CZ61_jamming12
				{
					soundSet="CZ61_jamming12_SoundSet";
					id=1038;
				};
				class CZ61_jamming13
				{
					soundSet="CZ61_jamming13_SoundSet";
					id=1039;
				};
				class CZ61_jam
				{
					soundSet="CZ61_jam_SoundSet";
					id=116;
				};
				class ump45_charge_open
				{
					soundSet="ump45_charge_open_SoundSet";
					id=191;
				};
				class ump45_charge_open_release
				{
					soundSet="ump45_charge_open_release_SoundSet";
					id=192;
				};
				class ump45_charge_close
				{
					soundSet="ump45_charge_close_SoundSet";
					id=193;
				};
				class ump45_charge_close_release
				{
					soundSet="ump45_charge_close_release_SoundSet";
					id=194;
				};
				class ump45_chamber_load
				{
					soundSet="ump45_chamber_load_SoundSet";
					id=195;
				};
				class ump45_mag_in
				{
					soundSet="ump45_mag_in_SoundSet";
					id=196;
				};
				class ump45_mag_load
				{
					soundSet="ump45_mag_load_SoundSet";
					id=197;
				};
				class ump45_mag_remove
				{
					soundSet="ump45_mag_remove_SoundSet";
					id=198;
				};
				class ump45_dry
				{
					soundSet="ump45_dry_SoundSet";
					id=200;
				};
				class ump45_pullout
				{
					soundSet="ump45_pullout_SoundSet";
					id=201;
				};
				class ump45_mag_out
				{
					soundSet="ump45_mag_out_SoundSet";
					id=202;
				};
				class ump45_jamming1
				{
					soundSet="ump45_jamming1_SoundSet";
					id=1051;
				};
				class ump45_jamming2
				{
					soundSet="ump45_jamming2_SoundSet";
					id=1052;
				};
				class ump45_jamming3
				{
					soundSet="ump45_jamming3_SoundSet";
					id=1053;
				};
				class ump45_jamming4
				{
					soundSet="ump45_jamming4_SoundSet";
					id=1054;
				};
				class ump45_jamming5
				{
					soundSet="ump45_jamming5_SoundSet";
					id=1055;
				};
				class ump45_jamming6
				{
					soundSet="ump45_jamming6_SoundSet";
					id=1056;
				};
				class ump45_jamming7
				{
					soundSet="ump45_jamming7_SoundSet";
					id=1057;
				};
				class ump45_jamming8
				{
					soundSet="ump45_jamming8_SoundSet";
					id=1058;
				};
				class ump45_jamming9
				{
					soundSet="ump45_jamming9_SoundSet";
					id=1059;
				};
				class ump45_jamming10
				{
					soundSet="ump45_jamming10_SoundSet";
					id=1060;
				};
				class ump45_jamming11
				{
					soundSet="ump45_jamming11_SoundSet";
					id=1061;
				};
				class ump45_jamming12
				{
					soundSet="ump45_jamming12_SoundSet";
					id=1062;
				};
				class ump45_jam
				{
					soundSet="ump45_jam_SoundSet";
					id=117;
				};
				class MP5K_hand
				{
					soundSet="MP5K_hand_SoundSet";
					id=210;
				};
				class MP5K_charge_open
				{
					soundSet="MP5K_charge_open_SoundSet";
					id=211;
				};
				class MP5K_charge_open_release
				{
					soundSet="MP5K_charge_open_release_SoundSet";
					id=212;
				};
				class MP5K_charge_close
				{
					soundSet="MP5K_charge_close_SoundSet";
					id=213;
				};
				class MP5K_charge_close_release
				{
					soundSet="MP5K_charge_close_release_SoundSet";
					id=214;
				};
				class MP5K_chamber_load
				{
					soundSet="MP5K_chamber_load_SoundSet";
					id=215;
				};
				class MP5K_mag_in
				{
					soundSet="MP5K_mag_in_SoundSet";
					id=216;
				};
				class MP5K_mag_load
				{
					soundSet="MP5K_mag_load_SoundSet";
					id=217;
				};
				class MP5K_mag_out
				{
					soundSet="MP5K_mag_out_SoundSet";
					id=222;
				};
				class MP5K_mag_remove
				{
					soundSet="MP5K_mag_remove_SoundSet";
					id=218;
				};
				class MP5K_dry
				{
					soundSet="MP5K_dry_SoundSet";
					id=220;
				};
				class MP5K_pullout
				{
					soundSet="MP5K_pullout_SoundSet";
					id=221;
				};
				class MP5_jamming1
				{
					soundSet="MP5_jamming1_SoundSet";
					id=223;
				};
				class MP5_jamming2
				{
					soundSet="MP5_jamming2_SoundSet";
					id=1040;
				};
				class MP5_jamming3
				{
					soundSet="MP5_jamming3_SoundSet";
					id=1041;
				};
				class MP5_jamming4
				{
					soundSet="MP5_jamming4_SoundSet";
					id=1042;
				};
				class MP5_jamming5
				{
					soundSet="MP5_jamming5_SoundSet";
					id=1043;
				};
				class MP5_jamming6
				{
					soundSet="MP5_jamming6_SoundSet";
					id=1044;
				};
				class MP5_jamming7
				{
					soundSet="MP5_jamming7_SoundSet";
					id=1045;
				};
				class MP5_jamming8
				{
					soundSet="MP5_jamming8_SoundSet";
					id=1046;
				};
				class MP5_jamming9
				{
					soundSet="MP5_jamming9_SoundSet";
					id=1047;
				};
				class MP5_jamming10
				{
					soundSet="MP5_jamming10_SoundSet";
					id=1048;
				};
				class MP5_jamming11
				{
					soundSet="MP5_jamming11_SoundSet";
					id=1049;
				};
				class MP5_jamming12
				{
					soundSet="MP5_jamming12_SoundSet";
					id=1050;
				};
				class MP5_jamming13
				{
					soundSet="MP5_jamming13_SoundSet";
					id=204;
				};
				class MP5_jam
				{
					soundSet="MP5_jam_SoundSet";
					id=203;
				};
				class IZH18_charge_open
				{
					soundSet="IZH18_charge_open_SoundSet";
					id=231;
				};
				class IZH18_charge_close
				{
					soundSet="IZH18_charge_close_SoundSet";
					id=233;
				};
				class IZH18_charge_close_release
				{
					soundSet="IZH18_charge_close_release_SoundSet";
					id=234;
				};
				class IZH18_chamber_load
				{
					soundSet="IZH18_chamber_load_SoundSet";
					id=235;
				};
				class IZH18_dry
				{
					soundSet="IZH18_dry_SoundSet";
					id=240;
				};
				class IZH18_pullout
				{
					soundSet="IZH18_pullout_SoundSet";
					id=241;
				};
				class IZH18_jamming1
				{
					soundSet="IZH18_jamming1_SoundSet";
					id=242;
				};
				class IZH18_jamming2
				{
					soundSet="IZH18_jamming2_SoundSet";
					id=243;
				};
				class IZH18_jamming3
				{
					soundSet="IZH18_jamming3_SoundSet";
					id=244;
				};
				class IZH18_jamming4
				{
					soundSet="IZH18_jamming4_SoundSet";
					id=245;
				};
				class IZH18_jamming5
				{
					soundSet="IZH18_jamming5_SoundSet";
					id=246;
				};
				class IZH18_jamming6
				{
					soundSet="IZH18_jamming6_SoundSet";
					id=247;
				};
				class IZH18_jamming7
				{
					soundSet="IZH18_jamming7_SoundSet";
					id=248;
				};
				class IZH18_jamming8
				{
					soundSet="IZH18_jamming8_SoundSet";
					id=249;
				};
				class IZH18_jam
				{
					soundSet="IZH18_jam_SoundSet";
					id=250;
				};
				class AK_charge_open
				{
					soundSet="AK_charge_open_SoundSet";
					id=251;
				};
				class AK_charge_open_release
				{
					soundSet="AK_charge_open_release_SoundSet";
					id=252;
				};
				class AK_charge_close
				{
					soundSet="AK_charge_close_SoundSet";
					id=253;
				};
				class AK_charge_close_release
				{
					soundSet="AK_charge_close_release_SoundSet";
					id=254;
				};
				class AK_charge_open_47
				{
					soundSet="AK_charge_open_47_SoundSet";
					id=267;
				};
				class AK_charge_open_release_47
				{
					soundSet="AK_charge_open_release_47_SoundSet";
					id=268;
				};
				class AK_charge_close_47
				{
					soundSet="AK_charge_close_47_SoundSet";
					id=269;
				};
				class AK_charge_close_release_47
				{
					soundSet="AK_charge_close_release_47_SoundSet";
					id=270;
				};
				class AK_chamber_load2
				{
					soundSet="AK_chamber_load2_SoundSet";
					id=255;
				};
				class AK_mag_in
				{
					soundSet="AK_mag_in_SoundSet";
					id=256;
				};
				class AK_mag_load
				{
					soundSet="AK_mag_load_SoundSet";
					id=257;
				};
				class AK_mag_remove
				{
					soundSet="AK_mag_remove_SoundSet";
					id=258;
				};
				class AK_mag_load_47
				{
					soundSet="AK_mag_load_47_SoundSet";
					id=229;
				};
				class AK_mag_remove_47
				{
					soundSet="AK_mag_remove_47_SoundSet";
					id=230;
				};
				class AK_jamming
				{
					soundSet="AK_jamming_SoundSet";
					id=259;
				};
				class AK_dry
				{
					soundSet="AK_dry_SoundSet";
					id=260;
				};
				class AK_pullout
				{
					soundSet="AK_pullout_SoundSet";
					id=261;
				};
				class AK_dry_uncock
				{
					soundSet="AK_dry_uncock_SoundSet";
					id=262;
				};
				class AK_hand
				{
					soundSet="AK_hand_SoundSet";
					id=264;
				};
				class AK_hand3
				{
					soundSet="AK_hand3_SoundSet";
					id=266;
				};
				class AK_weapon_down
				{
					soundSet="AK_weapon_down_SoundSet";
					id=265;
				};
				class AK_jamming1
				{
					soundSet="AK_jamming1_SoundSet";
					id=1063;
				};
				class AK_jamming2
				{
					soundSet="AK_jamming2_SoundSet";
					id=1064;
				};
				class AK_jamming3
				{
					soundSet="AK_jamming3_SoundSet";
					id=1065;
				};
				class AK_jamming4
				{
					soundSet="AK_jamming4_SoundSet";
					id=1066;
				};
				class AK_jamming5
				{
					soundSet="AK_jamming5_SoundSet";
					id=1067;
				};
				class AK_jamming6
				{
					soundSet="AK_jamming6_SoundSet";
					id=1068;
				};
				class AK_jamming7
				{
					soundSet="AK_jamming7_SoundSet";
					id=1069;
				};
				class AK_jamming8
				{
					soundSet="AK_jamming8_SoundSet";
					id=1070;
				};
				class AK_jamming9
				{
					soundSet="AK_jamming9_SoundSet";
					id=1071;
				};
				class AK_jam
				{
					soundSet="AK_jam_SoundSet";
					id=1072;
				};
				class SVD_charge_open
				{
					soundSet="SVD_charge_open_SoundSet";
					id=271;
				};
				class SVD_charge_open_release
				{
					soundSet="SVD_charge_open_release_SoundSet";
					id=272;
				};
				class SVD_charge_close
				{
					soundSet="SVD_charge_close_SoundSet";
					id=273;
				};
				class SVD_charge_close_release
				{
					soundSet="SVD_charge_close_release_SoundSet";
					id=274;
				};
				class SVD_chamber_load
				{
					soundSet="SVD_chamber_load_SoundSet";
					id=275;
				};
				class SVD_mag_in
				{
					soundSet="SVD_mag_in_SoundSet";
					id=276;
				};
				class SVD_mag_load
				{
					soundSet="SVD_mag_load_SoundSet";
					id=277;
				};
				class SVD_mag_out
				{
					soundSet="SVD_mag_out_SoundSet";
					id=282;
				};
				class SVD_mag_remove
				{
					soundSet="SVD_mag_remove_SoundSet";
					id=278;
				};
				class SVD_dry
				{
					soundSet="SVD_dry_SoundSet";
					id=280;
				};
				class SVD_pullout
				{
					soundSet="SVD_pullout_SoundSet";
					id=281;
				};
				class SVD_chamber_load2
				{
					soundSet="SVD_chamber_load2_SoundSet";
					id=283;
				};
				class SVD_hand
				{
					soundSet="SVD_hand_SoundSet";
					id=284;
				};
				class SVD_weapon_down
				{
					soundSet="SVD_weapon_down_SoundSet";
					id=285;
				};
				class SVD_jamming1
				{
					soundSet="SVD_jamming1_SoundSet";
					id=290;
				};
				class SVD_jamming2
				{
					soundSet="SVD_jamming2_SoundSet";
					id=291;
				};
				class SVD_jamming3
				{
					soundSet="SVD_jamming3_SoundSet";
					id=292;
				};
				class SVD_jamming4
				{
					soundSet="SVD_jamming4_SoundSet";
					id=293;
				};
				class SVD_jamming5
				{
					soundSet="SVD_jamming5_SoundSet";
					id=294;
				};
				class SVD_jamming6
				{
					soundSet="SVD_jamming6_SoundSet";
					id=295;
				};
				class SVD_jamming7
				{
					soundSet="SVD_jamming7_SoundSet";
					id=296;
				};
				class SVD_jamming8
				{
					soundSet="SVD_jamming8_SoundSet";
					id=297;
				};
				class SVD_jamming9
				{
					soundSet="SVD_jamming9_SoundSet";
					id=298;
				};
				class SVD_jam
				{
					soundSet="SVD_jam_SoundSet";
					id=299;
				};
				class M14_charge_open
				{
					soundSet="M14_charge_open_SoundSet";
					id=3271;
				};
				class M14_charge_open_release
				{
					soundSet="M14_charge_open_release_SoundSet";
					id=3272;
				};
				class M14_charge_close
				{
					soundSet="M14_charge_close_SoundSet";
					id=3273;
				};
				class M14_charge_close_release
				{
					soundSet="M14_charge_close_release_SoundSet";
					id=3274;
				};
				class M14_chamber_load
				{
					soundSet="M14_chamber_load_SoundSet";
					id=3275;
				};
				class M14_mag_in
				{
					soundSet="M14_mag_in_SoundSet";
					id=3276;
				};
				class M14_mag_load
				{
					soundSet="M14_mag_load_SoundSet";
					id=3277;
				};
				class M14_mag_out
				{
					soundSet="M14_mag_out_SoundSet";
					id=3282;
				};
				class M14_mag_remove
				{
					soundSet="M14_mag_remove_SoundSet";
					id=3278;
				};
				class M14_dry
				{
					soundSet="M14_dry_SoundSet";
					id=3280;
				};
				class M14_pullout
				{
					soundSet="M14_pullout_SoundSet";
					id=3281;
				};
				class M14_chamber_load2
				{
					soundSet="M14_chamber_load2_SoundSet";
					id=3283;
				};
				class M14_hand
				{
					soundSet="M14_hand_SoundSet";
					id=3284;
				};
				class M14_weapon_down
				{
					soundSet="M14_weapon_down_SoundSet";
					id=3285;
				};
				class M14_jamming1
				{
					soundSet="M14_jamming1_SoundSet";
					id=3290;
				};
				class M14_jamming2
				{
					soundSet="M14_jamming2_SoundSet";
					id=3291;
				};
				class M14_jamming3
				{
					soundSet="M14_jamming3_SoundSet";
					id=3292;
				};
				class M14_jamming4
				{
					soundSet="M14_jamming4_SoundSet";
					id=3293;
				};
				class M14_jamming5
				{
					soundSet="M14_jamming5_SoundSet";
					id=3294;
				};
				class M14_jamming6
				{
					soundSet="M14_jamming6_SoundSet";
					id=3295;
				};
				class M14_jamming7
				{
					soundSet="M14_jamming7_SoundSet";
					id=3296;
				};
				class M14_jamming8
				{
					soundSet="M14_jamming8_SoundSet";
					id=3297;
				};
				class M14_jamming9
				{
					soundSet="M14_jamming9_SoundSet";
					id=3298;
				};
				class M14_jam
				{
					soundSet="M14_jam_SoundSet";
					id=3299;
				};
				class Mosin_charge_open
				{
					soundSet="Mosin_charge_open_SoundSet";
					id=301;
				};
				class Mosin_chamber_load
				{
					soundSet="Mosin_chamber_load_SoundSet";
					id=302;
				};
				class Mosin_charge_close
				{
					soundSet="Mosin_charge_close_SoundSet";
					id=303;
				};
				class Mosin_dry
				{
					soundSet="Mosin_dry_SoundSet";
					id=307;
				};
				class Mosin_pullout
				{
					soundSet="mosin_pullout_SoundSet";
					id=308;
				};
				class Mosin_jamming1
				{
					soundSet="Mosin_jamming1_SoundSet";
					id=309;
				};
				class Mosin_jamming2
				{
					soundSet="Mosin_jamming2_SoundSet";
					id=310;
				};
				class Mosin_jamming3
				{
					soundSet="Mosin_jamming3_SoundSet";
					id=311;
				};
				class Mosin_jamming4
				{
					soundSet="Mosin_jamming4_SoundSet";
					id=312;
				};
				class Mosin_jamming5
				{
					soundSet="Mosin_jamming5_SoundSet";
					id=313;
				};
				class Mosin_jamming6
				{
					soundSet="Mosin_jamming6_SoundSet";
					id=314;
				};
				class Mosin_jamming7
				{
					soundSet="Mosin_jamming7_SoundSet";
					id=315;
				};
				class Mosin_jamming8
				{
					soundSet="Mosin_jamming8_SoundSet";
					id=316;
				};
				class Mosin_jamming9
				{
					soundSet="Mosin_jamming9_SoundSet";
					id=317;
				};
				class Mosin_jamming10
				{
					soundSet="Mosin_jamming10_SoundSet";
					id=318;
				};
				class Mosin_jamming11
				{
					soundSet="Mosin_jamming11_SoundSet";
					id=319;
				};
				class Mosin_jam
				{
					soundSet="Mosin_jam_SoundSet";
					id=320;
				};
				class M4_charge_open
				{
					soundSet="M4_charge_open_SoundSet";
					id=321;
				};
				class M4_charge_open_release
				{
					soundSet="M4_charge_open_release_SoundSet";
					id=322;
				};
				class M4_charge_close
				{
					soundSet="M4_charge_close_SoundSet";
					id=323;
				};
				class M4_charge_close_release
				{
					soundSet="M4_charge_close_release_SoundSet";
					id=324;
				};
				class M4_charge_close_release2
				{
					soundSet="M4_charge_close_release2_SoundSet";
					id=382;
				};
				class M4_chamber_load
				{
					soundSet="M4_chamber_load_SoundSet";
					id=325;
				};
				class M4_mag_in
				{
					soundSet="M4_mag_in_SoundSet";
					id=326;
				};
				class M4_mag_load
				{
					soundSet="M4_mag_load_SoundSet";
					id=327;
				};
				class M4_mag_out
				{
					soundSet="M4_mag_out_SoundSet";
					id=328;
				};
				class M4_mag_remove
				{
					soundSet="M4_mag_remove_SoundSet";
					id=329;
				};
				class M4_dry
				{
					soundSet="M4_dry_SoundSet";
					id=331;
				};
				class M4_pullout
				{
					soundSet="M4_pullout_SoundSet";
					id=332;
				};
				class M4_hand
				{
					soundSet="M4_hand_SoundSet";
					id=333;
				};
				class M4_weapon_down
				{
					soundSet="M4_weapon_down_SoundSet";
					id=334;
				};
				class M4_jamming1
				{
					soundSet="M4_jamming1_SoundSet";
					id=335;
				};
				class M4_jamming2
				{
					soundSet="M4_jamming2_SoundSet";
					id=336;
				};
				class M4_jamming3
				{
					soundSet="M4_jamming3_SoundSet";
					id=337;
				};
				class M4_jamming4
				{
					soundSet="M4_jamming4_SoundSet";
					id=338;
				};
				class M4_jamming5
				{
					soundSet="M4_jamming5_SoundSet";
					id=339;
				};
				class M4_jamming6
				{
					soundSet="M4_jamming6_SoundSet";
					id=340;
				};
				class M4_jamming7
				{
					soundSet="M4_jamming7_SoundSet";
					id=341;
				};
				class M4_jamming8
				{
					soundSet="M4_jamming8_SoundSet";
					id=383;
				};
				class M4_jamming9
				{
					soundSet="M4_jamming9_SoundSet";
					id=384;
				};
				class M4_jamming10
				{
					soundSet="M4_jamming10_SoundSet";
					id=385;
				};
				class M4_jamming11
				{
					soundSet="M4_jamming11_SoundSet";
					id=386;
				};
				class M4_jamming12
				{
					soundSet="M4_jamming12_SoundSet";
					id=387;
				};
				class M4_jamming13
				{
					soundSet="M4_jamming13_SoundSet";
					id=388;
				};
				class M4_jam
				{
					soundSet="M4_jam_SoundSet";
					id=300;
				};
				class MP133_charge_open
				{
					soundSet="MP133_charge_open_SoundSet";
					id=342;
				};
				class MP133_charge_close
				{
					soundSet="MP133_charge_close_SoundSet";
					id=343;
				};
				class MP133_chamber_load1
				{
					soundSet="MP133_chamber_load1_SoundSet";
					id=345;
				};
				class MP133_chamber_load2
				{
					soundSet="MP133_chamber_load2_SoundSet";
					id=346;
				};
				class MP133_weapon_down
				{
					soundSet="MP133_weapon_down_SoundSet";
					id=347;
				};
				class MP133_hand
				{
					soundSet="MP133_hand_SoundSet";
					id=348;
				};
				class MP133_dry
				{
					soundSet="MP133_dry_SoundSet";
					id=349;
				};
				class MP133_pullout
				{
					soundSet="MP133_pullout_SoundSet";
					id=350;
				};
				class MP133_jamming1
				{
					soundSet="MP133_jamming1_SoundSet";
					id=351;
				};
				class MP133_jamming2
				{
					soundSet="MP133_jamming2_SoundSet";
					id=352;
				};
				class MP133_jamming3
				{
					soundSet="MP133_jamming3_SoundSet";
					id=353;
				};
				class MP133_jamming4
				{
					soundSet="MP133_jamming4_SoundSet";
					id=354;
				};
				class MP133_jamming5
				{
					soundSet="MP133_jamming5_SoundSet";
					id=355;
				};
				class MP133_jamming6
				{
					soundSet="MP133_jamming6_SoundSet";
					id=356;
				};
				class MP133_jamming7
				{
					soundSet="MP133_jamming7_SoundSet";
					id=357;
				};
				class MP133_jamming8
				{
					soundSet="MP133_jamming8_SoundSet";
					id=358;
				};
				class MP133_jamming9
				{
					soundSet="MP133_jamming9_SoundSet";
					id=359;
				};
				class MP133_jamming10
				{
					soundSet="MP133_jamming10_SoundSet";
					id=360;
				};
				class MP133_jam
				{
					soundSet="MP133_jam_SoundSet";
					id=380;
				};
				class IZH43_charge_open
				{
					soundSet="IZH43_charge_open_SoundSet";
					id=361;
				};
				class IZH43_charge_open_release
				{
					soundSet="IZH43_charge_open_release_SoundSet";
					id=362;
				};
				class IZH43_charge_close
				{
					soundSet="IZH43_charge_close_SoundSet";
					id=363;
				};
				class IZH43_chamber_load
				{
					soundSet="IZH43_chamber_load_SoundSet";
					id=364;
				};
				class IZH43_chamber_fast_load
				{
					soundSet="IZH43_chamber_fast_load_SoundSet";
					id=365;
				};
				class IZH43_chamber_fast_in
				{
					soundSet="IZH43_chamber_fast_in_SoundSet";
					id=366;
				};
				class IZH43_chamber_fast_out
				{
					soundSet="IZH43_chamber_fast_out_SoundSet";
					id=367;
				};
				class IZH43_weapon_down
				{
					soundSet="IZH43_weapon_down_SoundSet";
					id=368;
				};
				class IZH43_hand
				{
					soundSet="IZH43_hand_SoundSet";
					id=369;
				};
				class IZH43_dry
				{
					soundSet="IZH43_dry_SoundSet";
					id=370;
				};
				class IZH43_pullout
				{
					soundSet="IZH43_pullout_SoundSet";
					id=371;
				};
				class IZH43_jamming1
				{
					soundSet="IZH43_jamming1_SoundSet";
					id=372;
				};
				class IZH43_jamming2
				{
					soundSet="IZH43_jamming2_SoundSet";
					id=373;
				};
				class IZH43_jamming3
				{
					soundSet="IZH43_jamming3_SoundSet";
					id=374;
				};
				class IZH43_jamming4
				{
					soundSet="IZH43_jamming4_SoundSet";
					id=375;
				};
				class IZH43_jamming5
				{
					soundSet="IZH43_jamming5_SoundSet";
					id=376;
				};
				class IZH43_jamming5b
				{
					soundSet="IZH43_jamming5b_SoundSet";
					id=1285;
				};
				class IZH43_jamming6
				{
					soundSet="IZH43_jamming6_SoundSet";
					id=377;
				};
				class IZH43_jamming7
				{
					soundSet="IZH43_jamming7_SoundSet";
					id=378;
				};
				class IZH43_jamming7b
				{
					soundSet="IZH43_jamming7b_SoundSet";
					id=1286;
				};
				class IZH43_jamming7c
				{
					soundSet="IZH43_jamming7c_SoundSet";
					id=1287;
				};
				class IZH43_jamming8
				{
					soundSet="IZH43_jamming8_SoundSet";
					id=379;
				};
				class IZH43_jam
				{
					soundSet="IZH43_jam_SoundSet";
					id=381;
				};
				class B95_charge_open
				{
					soundSet="B95_charge_open_SoundSet";
					id=1290;
				};
				class B95_charge_open_release
				{
					soundSet="B95_charge_open_release_SoundSet";
					id=1291;
				};
				class B95_charge_close
				{
					soundSet="B95_charge_close_SoundSet";
					id=1292;
				};
				class B95_chamber_load
				{
					soundSet="B95_chamber_load_SoundSet";
					id=1293;
				};
				class B95_chamber_fast_load
				{
					soundSet="B95_chamber_fast_load_SoundSet";
					id=1294;
				};
				class B95_chamber_fast_in
				{
					soundSet="B95_chamber_fast_in_SoundSet";
					id=1295;
				};
				class B95_chamber_fast_out
				{
					soundSet="B95_chamber_fast_out_SoundSet";
					id=1296;
				};
				class B95_weapon_down
				{
					soundSet="B95_weapon_down_SoundSet";
					id=1297;
				};
				class B95_hand
				{
					soundSet="B95_hand_SoundSet";
					id=1298;
				};
				class B95_dry
				{
					soundSet="B95_dry_SoundSet";
					id=1299;
				};
				class B95_pullout
				{
					soundSet="B95_pullout_SoundSet";
					id=1300;
				};
				class B95_jamming1
				{
					soundSet="B95_jamming1_SoundSet";
					id=1301;
				};
				class B95_jamming2
				{
					soundSet="B95_jamming2_SoundSet";
					id=1302;
				};
				class B95_jamming3
				{
					soundSet="B95_jamming3_SoundSet";
					id=1303;
				};
				class B95_jamming4
				{
					soundSet="B95_jamming4_SoundSet";
					id=1304;
				};
				class B95_jamming5
				{
					soundSet="B95_jamming5_SoundSet";
					id=1305;
				};
				class B95_jamming5b
				{
					soundSet="B95_jamming5b_SoundSet";
					id=1306;
				};
				class B95_jamming6
				{
					soundSet="B95_jamming6_SoundSet";
					id=1307;
				};
				class B95_jamming7
				{
					soundSet="B95_jamming7_SoundSet";
					id=1308;
				};
				class B95_jamming7b
				{
					soundSet="B95_jamming7b_SoundSet";
					id=1309;
				};
				class B95_jamming7c
				{
					soundSet="B95_jamming7c_SoundSet";
					id=1310;
				};
				class B95_jamming8
				{
					soundSet="B95_jamming8_SoundSet";
					id=1311;
				};
				class B95_jam
				{
					soundSet="B95_jam_SoundSet";
					id=1312;
				};
				class CR527_charge_open
				{
					soundSet="CR527_charge_open_SoundSet";
					id=501;
				};
				class CR527_charge_open_release
				{
					soundSet="CR527_charge_open_release_SoundSet";
					id=502;
				};
				class CR527_charge_close
				{
					soundSet="CR527_charge_close_SoundSet";
					id=503;
				};
				class CR527_charge_close_release
				{
					soundSet="CR527_charge_close_release_SoundSet";
					id=504;
				};
				class CR527_chamber_load
				{
					soundSet="CR527_chamber_load_SoundSet";
					id=505;
				};
				class CR527_mag_in
				{
					soundSet="CR527_mag_in_SoundSet";
					id=506;
				};
				class CR527_mag_load
				{
					soundSet="CR527_mag_load_SoundSet";
					id=507;
				};
				class CR527_mag_out
				{
					soundSet="CR527_mag_out_SoundSet";
					id=509;
				};
				class CR527_mag_remove
				{
					soundSet="CR527_mag_remove_SoundSet";
					id=508;
				};
				class CR527_dry
				{
					soundSet="CR527_dry_SoundSet";
					id=510;
				};
				class CR527_pullout
				{
					soundSet="CR527_pullout_SoundSet";
					id=511;
				};
				class CR527_hand1
				{
					soundSet="CR527_hand1_SoundSet";
					id=512;
				};
				class CR527_hand2
				{
					soundSet="CR527_hand2_SoundSet";
					id=513;
				};
				class CR527_hand3
				{
					soundSet="CR527_hand3_SoundSet";
					id=514;
				};
				class CR527_hand4
				{
					soundSet="CR527_hand4_SoundSet";
					id=527;
				};
				class CR527_jamming1
				{
					soundSet="CR527_jamming1_SoundSet";
					id=515;
				};
				class CR527_jamming2
				{
					soundSet="CR527_jamming2_SoundSet";
					id=516;
				};
				class CR527_jamming3
				{
					soundSet="CR527_jamming3_SoundSet";
					id=517;
				};
				class CR527_jamming4
				{
					soundSet="CR527_jamming4_SoundSet";
					id=518;
				};
				class CR527_jamming5
				{
					soundSet="CR527_jamming5_SoundSet";
					id=519;
				};
				class CR527_jamming6
				{
					soundSet="CR527_jamming6_SoundSet";
					id=520;
				};
				class CR527_jamming7
				{
					soundSet="CR527_jamming7_SoundSet";
					id=521;
				};
				class CR527_jamming8
				{
					soundSet="CR527_jamming8_SoundSet";
					id=522;
				};
				class CR527_jamming9
				{
					soundSet="CR527_jamming9_SoundSet";
					id=523;
				};
				class CR527_jamming10
				{
					soundSet="CR527_jamming10_SoundSet";
					id=524;
				};
				class CR527_jamming11
				{
					soundSet="CR527_jamming11_SoundSet";
					id=525;
				};
				class CR527_jam
				{
					soundSet="CR527_jam_SoundSet";
					id=526;
				};
				class SKS_charge_open
				{
					soundSet="SKS_charge_open_SoundSet";
					id=541;
				};
				class SKS_charge_open_release
				{
					soundSet="SKS_charge_open_release_SoundSet";
					id=542;
				};
				class SKS_chamber_load
				{
					soundSet="SKS_chamber_load_SoundSet";
					id=543;
				};
				class SKS_charge_close
				{
					soundSet="SKS_charge_close_SoundSet";
					id=544;
				};
				class SKS_charge_close_release
				{
					soundSet="SKS_charge_close_release_SoundSet";
					id=545;
				};
				class SKS_dry
				{
					soundSet="SKS_dry_SoundSet";
					id=546;
				};
				class SKS_pullout
				{
					soundSet="SKS_pullout_SoundSet";
					id=547;
				};
				class SKS_jamming1
				{
					soundSet="SKS_jamming1_SoundSet";
					id=548;
				};
				class SKS_jamming2
				{
					soundSet="SKS_jamming2_SoundSet";
					id=549;
				};
				class SKS_jamming3
				{
					soundSet="SKS_jamming3_SoundSet";
					id=550;
				};
				class SKS_jamming4
				{
					soundSet="SKS_jamming4_SoundSet";
					id=551;
				};
				class SKS_jamming5
				{
					soundSet="SKS_jamming5_SoundSet";
					id=552;
				};
				class SKS_jamming6
				{
					soundSet="SKS_jamming6_SoundSet";
					id=553;
				};
				class SKS_jamming7
				{
					soundSet="SKS_jamming7_SoundSet";
					id=554;
				};
				class SKS_jam
				{
					soundSet="SKS_jam_SoundSet";
					id=559;
				};
				class SKS_hand2
				{
					soundSet="SKS_hand2_SoundSet";
					id=560;
				};
				class SKS_hand3
				{
					soundSet="SKS_hand3_SoundSet";
					id=561;
				};
				class SKS_hand4
				{
					soundSet="SKS_hand4_SoundSet";
					id=562;
				};
				class SKS_last
				{
					soundSet="SKS_last_SoundSet";
					id=563;
				};
				class SKS_clip_in
				{
					soundSet="SKS_clip_in_SoundSet";
					id=564;
				};
				class SKS_clip_out
				{
					soundSet="SKS_clip_out_SoundSet";
					id=565;
				};
				class SKS_clip_shell
				{
					soundSet="SKS_clip_shell_SoundSet";
					id=566;
				};
				class SKS_clip_shell2
				{
					soundSet="SKS_clip_shell_SoundSet";
					id=567;
				};
				class SKS_clip_shell3
				{
					soundSet="SKS_clip_shell_SoundSet";
					id=568;
				};
				class SKS_clip_shell4
				{
					soundSet="SKS_clip_shell_SoundSet";
					id=569;
				};
				class Win_charge_open
				{
					soundSet="Win_charge_open_SoundSet";
					id=570;
				};
				class Win_charge_open_release
				{
					soundSet="Win_charge_open_release_SoundSet";
					id=571;
				};
				class Win_charge_close
				{
					soundSet="Win_charge_close_SoundSet";
					id=572;
				};
				class Win_charge_close_release
				{
					soundSet="Win_charge_close_release_SoundSet";
					id=573;
				};
				class Win_chamber_load
				{
					soundSet="Win_chamber_load_SoundSet";
					id=574;
				};
				class Win_dry
				{
					soundSet="Win_dry_SoundSet";
					id=575;
				};
				class Win_pullout
				{
					soundSet="Win_pullout_SoundSet";
					id=576;
				};
				class Win_hand
				{
					soundSet="Win_hand_SoundSet";
					id=577;
				};
				class Win_jam
				{
					soundSet="Win_jam_SoundSet";
					id=578;
				};
				class Win_jamming1
				{
					soundSet="Win_jamming1_SoundSet";
					id=579;
				};
				class Win_jamming2
				{
					soundSet="Win_jamming2_SoundSet";
					id=580;
				};
				class Win_jamming3
				{
					soundSet="Win_jamming3_SoundSet";
					id=581;
				};
				class Win_jamming4
				{
					soundSet="Win_jamming4_SoundSet";
					id=582;
				};
				class Win_jamming5
				{
					soundSet="Win_jamming5_SoundSet";
					id=583;
				};
				class Win_jamming6
				{
					soundSet="Win_jamming6_SoundSet";
					id=584;
				};
				class Win_jamming7
				{
					soundSet="Win_jamming7_SoundSet";
					id=585;
				};
				class Win_jamming8
				{
					soundSet="Win_jamming8_SoundSet";
					id=586;
				};
				class Win_jamming9
				{
					soundSet="Win_jamming9_SoundSet";
					id=587;
				};
				class Win_jamming10
				{
					soundSet="Win_jamming10_SoundSet";
					id=588;
				};
				class FNFAL_charge_open
				{
					soundSet="FNFAL_charge_open_SoundSet";
					id=601;
				};
				class FNFAL_charge_open_release
				{
					soundSet="FNFAL_charge_open_release_SoundSet";
					id=602;
				};
				class FNFAL_charge_close
				{
					soundSet="FNFAL_charge_close_SoundSet";
					id=603;
				};
				class FNFAL_charge_close_release
				{
					soundSet="FNFAL_charge_close_release_SoundSet";
					id=604;
				};
				class FNFAL_chamber_load
				{
					soundSet="FNFAL_chamber_load_SoundSet";
					id=605;
				};
				class FNFAL_mag_in
				{
					soundSet="FNFAL_mag_in_SoundSet";
					id=606;
				};
				class FNFAL_mag_load
				{
					soundSet="FNFAL_mag_load_SoundSet";
					id=607;
				};
				class FNFAL_mag_out
				{
					soundSet="FNFAL_mag_out_SoundSet";
					id=608;
				};
				class FNFAL_mag_remove
				{
					soundSet="FNFAL_mag_remove_SoundSet";
					id=609;
				};
				class FNFAL_dry
				{
					soundSet="FNFAL_dry_SoundSet";
					id=610;
				};
				class FNFAL_pullout
				{
					soundSet="FNFAL_pullout_SoundSet";
					id=611;
				};
				class FNFAL_hand
				{
					soundSet="FNFAL_hand_SoundSet";
					id=612;
				};
				class FNFAL_weapon_down
				{
					soundSet="FNFAL_weapon_down_SoundSet";
					id=613;
				};
				class FNFAL_jam
				{
					soundSet="FNFAL_jam_SoundSet";
					id=614;
				};
				class FNFAL_jamming1
				{
					soundSet="FNFAL_jamming1_SoundSet";
					id=615;
				};
				class FNFAL_jamming2
				{
					soundSet="FNFAL_jamming2_SoundSet";
					id=616;
				};
				class FNFAL_jamming3
				{
					soundSet="FNFAL_jamming3_SoundSet";
					id=617;
				};
				class FNFAL_jamming4
				{
					soundSet="FNFAL_jamming4_SoundSet";
					id=618;
				};
				class FNFAL_jamming5
				{
					soundSet="FNFAL_jamming5_SoundSet";
					id=619;
				};
				class FNFAL_jamming6
				{
					soundSet="FNFAL_jamming6_SoundSet";
					id=620;
				};
				class FNFAL_jamming7
				{
					soundSet="FNFAL_jamming7_SoundSet";
					id=621;
				};
				class FNFAL_jamming8
				{
					soundSet="FNFAL_jamming8_SoundSet";
					id=622;
				};
				class FNFAL_jamming9
				{
					soundSet="FNFAL_jamming9_SoundSet";
					id=623;
				};
				class FNFAL_jamming10
				{
					soundSet="FNFAL_jamming10_SoundSet";
					id=624;
				};
				class FNFAL_jamming11
				{
					soundSet="FNFAL_jamming11_SoundSet";
					id=625;
				};
				class FNFAL_jamming12
				{
					soundSet="FNFAL_jamming12_SoundSet";
					id=626;
				};
				class FNFAL_jamming13
				{
					soundSet="FNFAL_jamming13_SoundSet";
					id=627;
				};
				class Vikhr_mag_remove
				{
					soundSet="Vikhr_mag_out_SoundSet";
					id=1637;
				};
				class Vikhr_mag_load
				{
					soundSet="Vikhr_mag_load_SoundSet";
					id=1636;
				};
				class Vikhr_pullout
				{
					soundSet="Vikhr_pullout_SoundSet";
					id=1640;
				};
				class Vikhr_charge_open
				{
					soundSet="Vikhr_charge_open_SoundSet";
					id=1630;
				};
				class Vikhr_charge_close
				{
					soundSet="Vikhr_charge_close_SoundSet";
					id=1632;
				};
				class Vikhr_chamber_load2
				{
					soundSet="Vikhr_chamber_load2_SoundSet";
					id=2634;
				};
				class Vikhr_jamming2
				{
					soundSet="Vikhr_jamming2_SoundSet";
					id=2646;
				};
				class VVikhr_jamming3
				{
					soundSet="Vikhr_jamming3_SoundSet";
					id=2647;
				};
				class Vikhr_jamming4
				{
					soundSet="Vikhr_jamming4_SoundSet";
					id=2648;
				};
				class Vikhr_jamming5
				{
					soundSet="Vikhr_jamming5_SoundSet";
					id=2649;
				};
				class Vikhr_jamming6
				{
					soundSet="Vikhr_jamming6_SoundSet";
					id=2650;
				};
				class Vikhr_jamming7
				{
					soundSet="Vikhr_jamming7_SoundSet";
					id=2651;
				};
				class Vikhr_jamming8
				{
					soundSet="Vikhr_jamming8_SoundSet";
					id=2652;
				};
				class VSS_charge_open
				{
					soundSet="VSS_charge_open_SoundSet";
					id=630;
				};
				class VSS_charge_open_release
				{
					soundSet="VSS_charge_open_release_SoundSet";
					id=631;
				};
				class VSS_charge_close
				{
					soundSet="VSS_charge_close_SoundSet";
					id=632;
				};
				class VSS_charge_close_release
				{
					soundSet="VSS_charge_close_release_SoundSet";
					id=633;
				};
				class VSS_chamber_load2
				{
					soundSet="VSS_chamber_load2_SoundSet";
					id=634;
				};
				class VSS_mag_in
				{
					soundSet="VSS_mag_in_SoundSet";
					id=635;
				};
				class VSS_mag_load
				{
					soundSet="VSS_mag_load_SoundSet";
					id=636;
				};
				class VSS_mag_remove
				{
					soundSet="VSS_mag_remove_SoundSet";
					id=637;
				};
				class VSS_jamming
				{
					soundSet="VSS_jamming_SoundSet";
					id=638;
				};
				class VSS_dry
				{
					soundSet="VSS_dry_SoundSet";
					id=639;
				};
				class VSS_pullout
				{
					soundSet="VSS_pullout_SoundSet";
					id=640;
				};
				class VSS_dry_uncock
				{
					soundSet="VSS_dry_uncock_SoundSet";
					id=641;
				};
				class VSS_hand
				{
					soundSet="VSS_hand_SoundSet";
					id=642;
				};
				class VSS_hand2
				{
					soundSet="VSS_hand2_SoundSet";
					id=643;
				};
				class VSS_hand3
				{
					soundSet="VSS_hand3_SoundSet";
					id=644;
				};
				class VSS_hand4
				{
					soundSet="VSS_hand4_SoundSet";
					id=655;
				};
				class VSS_hand5
				{
					soundSet="VSS_hand5_SoundSet";
					id=656;
				};
				class VSS_hand6
				{
					soundSet="VSS_hand6_SoundSet";
					id=657;
				};
				class VSS_hand7
				{
					soundSet="VSS_hand7_SoundSet";
					id=658;
				};
				class VSS_hand8
				{
					soundSet="VSS_hand8_SoundSet";
					id=659;
				};
				class VSS_jamming1
				{
					soundSet="VSS_jamming1_SoundSet";
					id=645;
				};
				class VSS_jamming2
				{
					soundSet="VSS_jamming2_SoundSet";
					id=646;
				};
				class VSS_jamming3
				{
					soundSet="VSS_jamming3_SoundSet";
					id=647;
				};
				class VSS_jamming4
				{
					soundSet="VSS_jamming4_SoundSet";
					id=648;
				};
				class VSS_jamming5
				{
					soundSet="VSS_jamming5_SoundSet";
					id=649;
				};
				class VSS_jamming6
				{
					soundSet="VSS_jamming6_SoundSet";
					id=650;
				};
				class VSS_jamming7
				{
					soundSet="VSS_jamming7_SoundSet";
					id=651;
				};
				class VSS_jamming8
				{
					soundSet="VSS_jamming8_SoundSet";
					id=652;
				};
				class VSS_jamming9
				{
					soundSet="VSS_jamming9_SoundSet";
					id=653;
				};
				class VSS_jam
				{
					soundSet="VSS_jam_SoundSet";
					id=654;
				};
				class AmphibianS_charge_open
				{
					soundSet="AmphibianS_charge_open_SoundSet";
					id=1121;
				};
				class AmphibianS_charge_open_release
				{
					soundSet="AmphibianS_charge_open_release_SoundSet";
					id=1122;
				};
				class AmphibianS_charge_close
				{
					soundSet="AmphibianS_charge_close_SoundSet";
					id=1123;
				};
				class AmphibianS_charge_close_release
				{
					soundSet="AmphibianS_charge_close_release_SoundSet";
					id=1124;
				};
				class AmphibianS_chamber_load
				{
					soundSet="AmphibianS_chamber_load_SoundSet";
					id=1125;
				};
				class AmphibianS_mag_in
				{
					soundSet="AmphibianS_mag_in_SoundSet";
					id=1126;
				};
				class AmphibianS_mag_load
				{
					soundSet="AmphibianS_mag_load_SoundSet";
					id=1127;
				};
				class AmphibianS_mag_remove
				{
					soundSet="AmphibianS_mag_remove_SoundSet";
					id=1128;
				};
				class AmphibianS_dry
				{
					soundSet="AmphibianS_dry_SoundSet";
					id=1130;
				};
				class AmphibianS_pullout
				{
					soundSet="AmphibianS_pullout_SoundSet";
					id=1131;
				};
				class AmphibianS_dry_uncock
				{
					soundSet="AmphibianS_dry_uncock_SoundSet";
					id=1132;
				};
				class AmphibianS_jamming1
				{
					soundSet="AmphibianS_jamming1_SoundSet";
					id=1133;
				};
				class AmphibianS_jamming2
				{
					soundSet="AmphibianS_jamming2_SoundSet";
					id=1134;
				};
				class AmphibianS_jamming3
				{
					soundSet="AmphibianS_jamming3_SoundSet";
					id=1135;
				};
				class AmphibianS_jamming4
				{
					soundSet="AmphibianS_jamming4_SoundSet";
					id=1136;
				};
				class AmphibianS_jamming5
				{
					soundSet="AmphibianS_jamming5_SoundSet";
					id=1137;
				};
				class AmphibianS_jamming6
				{
					soundSet="AmphibianS_jamming6_SoundSet";
					id=1138;
				};
				class AmphibianS_jamming7
				{
					soundSet="AmphibianS_jamming7_SoundSet";
					id=1139;
				};
				class AmphibianS_jamming8
				{
					soundSet="AmphibianS_jamming8_SoundSet";
					id=1140;
				};
				class AmphibianS_jamming9
				{
					soundSet="AmphibianS_jamming9_SoundSet";
					id=1141;
				};
				class AmphibianS_jamming10
				{
					soundSet="AmphibianS_jamming10_SoundSet";
					id=1142;
				};
				class AmphibianS_jamming11
				{
					soundSet="AmphibianS_jamming11_SoundSet";
					id=1143;
				};
				class AmphibianS_jamming12
				{
					soundSet="AmphibianS_jamming12_SoundSet";
					id=1144;
				};
				class AmphibianS_jamming13
				{
					soundSet="AmphibianS_jamming13_SoundSet";
					id=1145;
				};
				class AmphibianS_jam
				{
					soundSet="AmphibianS_jam_SoundSet";
					id=1146;
				};
				class Glock19_charge_open
				{
					soundSet="Glock19_charge_open_SoundSet";
					id=12211;
				};
				class Glock19_charge_open_release
				{
					soundSet="Glock19_charge_open_release_SoundSet";
					id=12221;
				};
				class Glock19_charge_close
				{
					soundSet="Glock19_charge_close_SoundSet";
					id=12231;
				};
				class Glock19_charge_close_release
				{
					soundSet="Glock19_charge_close_release_SoundSet";
					id=12241;
				};
				class Glock19_chamber_load
				{
					soundSet="Glock19_chamber_load_SoundSet";
					id=12251;
				};
				class Glock19_mag_in
				{
					soundSet="Glock19_mag_in_SoundSet";
					id=1226;
				};
				class Glock19_mag_load
				{
					soundSet="Glock19_mag_load_SoundSet";
					id=1227;
				};
				class Glock19_mag_remove
				{
					soundSet="Glock19_mag_remove_SoundSet";
					id=1228;
				};
				class Glock19_dry
				{
					soundSet="Glock19_dry_SoundSet";
					id=1230;
				};
				class Glock19_pullout
				{
					soundSet="Glock19_pullout_SoundSet";
					id=1231;
				};
				class Glock19_dry_uncock
				{
					soundSet="Glock19_dry_uncock_SoundSet";
					id=1232;
				};
				class Glock19_jamming1
				{
					soundSet="Glock19_jamming1_SoundSet";
					id=1233;
				};
				class Glock19_jamming2
				{
					soundSet="Glock19_jamming2_SoundSet";
					id=1234;
				};
				class Glock19_jamming3
				{
					soundSet="Glock19_jamming3_SoundSet";
					id=1235;
				};
				class Glock19_jamming4
				{
					soundSet="Glock19_jamming4_SoundSet";
					id=1236;
				};
				class Glock19_jamming5
				{
					soundSet="Glock19_jamming5_SoundSet";
					id=1237;
				};
				class Glock19_jamming6
				{
					soundSet="Glock19_jamming6_SoundSet";
					id=1238;
				};
				class Glock19_jamming7
				{
					soundSet="Glock19_jamming7_SoundSet";
					id=1239;
				};
				class Glock19_jamming8
				{
					soundSet="Glock19_jamming8_SoundSet";
					id=1240;
				};
				class Glock19_jamming9
				{
					soundSet="Glock19_jamming9_SoundSet";
					id=1241;
				};
				class Glock19_jamming10
				{
					soundSet="Glock19_jamming10_SoundSet";
					id=1242;
				};
				class Glock19_jamming11
				{
					soundSet="Glock19_jamming11_SoundSet";
					id=1243;
				};
				class Glock19_jamming12
				{
					soundSet="Glock19_jamming12_SoundSet";
					id=1244;
				};
				class Glock19_jamming13
				{
					soundSet="Glock19_jamming13_SoundSet";
					id=1245;
				};
				class Glock19_jam
				{
					soundSet="Glock19_jam_SoundSet";
					id=1246;
				};
				class Saiga12_charge_open
				{
					soundSet="Saiga12_charge_open_SoundSet";
					id=1254;
				};
				class Saiga12_charge_open_release
				{
					soundSet="Saiga12_charge_open_release_SoundSet";
					id=1255;
				};
				class Saiga12_charge_close
				{
					soundSet="Saiga12_charge_close_SoundSet";
					id=1256;
				};
				class Saiga12_charge_close_release
				{
					soundSet="Saiga12_charge_close_release_SoundSet";
					id=1257;
				};
				class Saiga12_chamber_load2
				{
					soundSet="Saiga12_chamber_load2_SoundSet";
					id=1258;
				};
				class Saiga12_mag_in
				{
					soundSet="Saiga12_mag_in_SoundSet";
					id=1259;
				};
				class Saiga12_drum_load
				{
					soundSet="Saiga12_drum_load_SoundSet";
					id=1260;
				};
				class Saiga12_drum_remove
				{
					soundSet="Saiga12_drum_remove_SoundSet";
					id=1261;
				};
				class Saiga12_mag_load
				{
					soundSet="Saiga12_mag_load_SoundSet";
					id=1262;
				};
				class Saiga12_mag_remove
				{
					soundSet="Saiga12_mag_remove_SoundSet";
					id=1263;
				};
				class Saiga12_dry
				{
					soundSet="Saiga12_dry_SoundSet";
					id=1265;
				};
				class Saiga12_pullout
				{
					soundSet="Saiga12_pullout_SoundSet";
					id=1266;
				};
				class Saiga12_dry_uncock
				{
					soundSet="Saiga12_dry_uncock_SoundSet";
					id=1267;
				};
				class Saiga12_hand
				{
					soundSet="Saiga12_hand_SoundSet";
					id=1268;
				};
				class Saiga12_hand3
				{
					soundSet="Saiga12_hand3_SoundSet";
					id=1269;
				};
				class Saiga12_weapon_down
				{
					soundSet="Saiga12_weapon_down_SoundSet";
					id=1270;
				};
				class Saiga12_jamming1
				{
					soundSet="Saiga12_jamming1_SoundSet";
					id=1271;
				};
				class Saiga12_jamming2
				{
					soundSet="Saiga12_jamming2_SoundSet";
					id=1272;
				};
				class Saiga12_jamming3
				{
					soundSet="Saiga12_jamming3_SoundSet";
					id=1273;
				};
				class Saiga12_jamming4
				{
					soundSet="Saiga12_jamming4_SoundSet";
					id=1274;
				};
				class Saiga12_jamming5
				{
					soundSet="Saiga12_jamming5_SoundSet";
					id="1067 - 1275";
				};
				class Saiga12_jamming6
				{
					soundSet="Saiga12_jamming6_SoundSet";
					id=1276;
				};
				class Saiga12_jamming7
				{
					soundSet="Saiga12_jamming7_SoundSet";
					id=1277;
				};
				class Saiga12_jamming8
				{
					soundSet="Saiga12_jamming8_SoundSet";
					id=1278;
				};
				class Saiga12_jamming9
				{
					soundSet="Saiga12_jamming9_SoundSet";
					id=1279;
				};
				class Saiga12_jam
				{
					soundSet="Saiga12_jam_SoundSet";
					id=1280;
				};
				class Magnum_cilinder_in
				{
					soundSet="Magnum_cilinder_in_SoundSet";
					id=1820;
				};
				class Magnum_cilinder_out
				{
					soundSet="Magnum_cilinder_out_SoundSet";
					id=1821;
				};
				class Magnum_bullet_in
				{
					soundSet="Magnum_bullet_in_SoundSet";
					id=1822;
				};
				class Magnum_bullet_out
				{
					soundSet="Magnum_bullet_out_SoundSet";
					id=1823;
				};
				class Magnum_dry
				{
					soundSet="Magnum_dry_SoundSet";
					id=1824;
				};
				class Colt1911_charge_open
				{
					soundSet="Colt1911_charge_open_SoundSet";
					id=1320;
				};
				class Colt1911_charge_open_release
				{
					soundSet="Colt1911_charge_open_release_SoundSet";
					id=1321;
				};
				class Colt1911_charge_close
				{
					soundSet="Colt1911_charge_close_SoundSet";
					id=1322;
				};
				class Colt1911_charge_close_release
				{
					soundSet="Colt1911_charge_close_release_SoundSet";
					id=1323;
				};
				class Colt1911_chamber_load
				{
					soundSet="Colt1911_chamber_load_SoundSet";
					id=1324;
				};
				class Colt1911_mag_in
				{
					soundSet="Colt1911_mag_in_SoundSet";
					id=1325;
				};
				class Colt1911_mag_load
				{
					soundSet="Colt1911_mag_load_SoundSet";
					id=1326;
				};
				class Colt1911_mag_remove
				{
					soundSet="Colt1911_mag_remove_SoundSet";
					id=1327;
				};
				class Colt1911_dry
				{
					soundSet="Colt1911_dry_SoundSet";
					id=1328;
				};
				class Colt1911_pullout
				{
					soundSet="Colt1911_pullout_SoundSet";
					id=1329;
				};
				class Colt1911_dry_uncock
				{
					soundSet="Colt1911_dry_uncock_SoundSet";
					id=1330;
				};
				class Colt1911_jamming1
				{
					soundSet="Colt1911_jamming1_SoundSet";
					id=1331;
				};
				class Colt1911_jamming2
				{
					soundSet="Colt1911_jamming2_SoundSet";
					id=1332;
				};
				class Colt1911_jamming3
				{
					soundSet="Colt1911_jamming3_SoundSet";
					id=1333;
				};
				class Colt1911_jamming4
				{
					soundSet="Colt1911_jamming4_SoundSet";
					id=1334;
				};
				class Colt1911_jamming5
				{
					soundSet="Colt1911_jamming5_SoundSet";
					id=1335;
				};
				class Colt1911_jamming6
				{
					soundSet="Colt1911_jamming6_SoundSet";
					id=1336;
				};
				class Colt1911_jamming7
				{
					soundSet="Colt1911_jamming7_SoundSet";
					id=1337;
				};
				class Colt1911_jamming8
				{
					soundSet="Colt1911_jamming8_SoundSet";
					id=1338;
				};
				class Colt1911_jamming9
				{
					soundSet="Colt1911_jamming9_SoundSet";
					id=1339;
				};
				class Colt1911_jamming10
				{
					soundSet="Colt1911_jamming10_SoundSet";
					id=1340;
				};
				class Colt1911_jamming11
				{
					soundSet="Colt1911_jamming11_SoundSet";
					id=1341;
				};
				class Colt1911_jamming12
				{
					soundSet="Colt1911_jamming12_SoundSet";
					id=1342;
				};
				class Colt1911_jamming13
				{
					soundSet="Colt1911_jamming13_SoundSet";
					id=1343;
				};
				class Colt1911_jam
				{
					soundSet="Colt1911_jam_SoundSet";
					id=1344;
				};
				class repeater_charge_open
				{
					soundSet="repeater_charge_open_SoundSet";
					id=1350;
				};
				class repeater_charge_close
				{
					soundSet="repeater_charge_close_SoundSet";
					id=1351;
				};
				class repeater_empty
				{
					soundSet="repeater_empty_SoundSet";
					id=1352;
				};
				class repeater_chamber_load
				{
					soundSet="repeater_chamber_load_SoundSet";
					id=1353;
				};
				class repeater_dry
				{
					soundSet="repeater_dry_SoundSet";
					id=1354;
				};
				class repeater_pullout
				{
					soundSet="repeater_pullout_SoundSet";
					id=1355;
				};
				class repeater_hand
				{
					soundSet="repeater_hand_SoundSet";
					id=1356;
				};
				class repeater_jam
				{
					soundSet="repeater_jam_SoundSet";
					id=1357;
				};
				class repeater_jamming1
				{
					soundSet="repeater_jamming1_SoundSet";
					id=1358;
				};
				class repeater_jamming2
				{
					soundSet="repeater_jamming2_SoundSet";
					id=1359;
				};
				class repeater_jamming3
				{
					soundSet="repeater_jamming3_SoundSet";
					id=1360;
				};
				class repeater_jamming4
				{
					soundSet="repeater_jamming4_SoundSet";
					id=1361;
				};
				class repeater_jamming5
				{
					soundSet="repeater_jamming5_SoundSet";
					id=1362;
				};
				class repeater_jamming6
				{
					soundSet="repeater_jamming6_SoundSet";
					id=1363;
				};
				class repeater_jamming7
				{
					soundSet="repeater_jamming7_SoundSet";
					id=1364;
				};
				class repeater_jamming8
				{
					soundSet="repeater_jamming8_SoundSet";
					id=1365;
				};
				class repeater_jamming9
				{
					soundSet="repeater_jamming9_SoundSet";
					id=1366;
				};
				class repeater_jamming10
				{
					soundSet="repeater_jamming10_SoundSet";
					id=1367;
				};
				class Ruger1022_charge_open
				{
					soundSet="Ruger1022_charge_open_SoundSet";
					id=1373;
				};
				class Ruger1022_charge_open_release
				{
					soundSet="Ruger1022_charge_open_release_SoundSet";
					id=1374;
				};
				class Ruger1022_charge_close
				{
					soundSet="Ruger1022_charge_close_SoundSet";
					id=1375;
				};
				class Ruger1022_charge_close_release
				{
					soundSet="Ruger1022_charge_close_release_SoundSet";
					id=1376;
				};
				class Ruger1022_chamber_load
				{
					soundSet="Ruger1022_chamber_load_SoundSet";
					id=1377;
				};
				class Ruger1022_mag_in
				{
					soundSet="Ruger1022_mag_in_SoundSet";
					id=1378;
				};
				class Ruger1022_mag_load
				{
					soundSet="Ruger1022_mag_load_SoundSet";
					id=1379;
				};
				class Ruger1022_mag_out
				{
					soundSet="Ruger1022_mag_out_SoundSet";
					id=1380;
				};
				class Ruger1022_mag_remove
				{
					soundSet="Ruger1022_mag_remove_SoundSet";
					id=1381;
				};
				class Ruger1022_dry
				{
					soundSet="Ruger1022_dry_SoundSet";
					id=1382;
				};
				class Ruger1022_pullout
				{
					soundSet="Ruger1022_pullout_SoundSet";
					id=1383;
				};
				class Ruger1022_chamber_load2
				{
					soundSet="Ruger1022_chamber_load_SoundSet";
					id=1384;
				};
				class Ruger1022_hand
				{
					soundSet="Ruger1022_hand_SoundSet";
					id=1385;
				};
				class Ruger1022_weapon_down
				{
					soundSet="Ruger1022_weapon_down_SoundSet";
					id=1386;
				};
				class Ruger1022_jamming1
				{
					soundSet="Ruger1022_jamming1_SoundSet";
					id=1387;
				};
				class Ruger1022_jamming2
				{
					soundSet="Ruger1022_jamming2_SoundSet";
					id=1388;
				};
				class Ruger1022_jamming3
				{
					soundSet="Ruger1022_jamming3_SoundSet";
					id=1389;
				};
				class Ruger1022_jamming4
				{
					soundSet="Ruger1022_jamming4_SoundSet";
					id=1390;
				};
				class Ruger1022_jamming5
				{
					soundSet="Ruger1022_jamming5_SoundSet";
					id=1391;
				};
				class Ruger1022_jamming6
				{
					soundSet="Ruger1022_jamming6_SoundSet";
					id=1392;
				};
				class Ruger1022_jamming7
				{
					soundSet="Ruger1022_jamming7_SoundSet";
					id=1393;
				};
				class Ruger1022_jamming8
				{
					soundSet="Ruger1022_jamming8_SoundSet";
					id=1394;
				};
				class Ruger1022_jamming9
				{
					soundSet="Ruger1022_jamming9_SoundSet";
					id=1395;
				};
				class Ruger1022_jamming10
				{
					soundSet="Ruger1022_jamming10_SoundSet";
					id=1396;
				};
				class Ruger1022_jam
				{
					soundSet="Ruger1022_jam_SoundSet";
					id=1397;
				};
				class Flare_Gun_charge_open
				{
					soundSet="Flare_Gun_charge_open_SoundSet";
					id=1398;
				};
				class Flare_Gun_charge_close
				{
					soundSet="Flare_Gun_charge_close_SoundSet";
					id=1399;
				};
				class Flare_Gun_chamber_load
				{
					soundSet="Flare_Gun_chamber_load_SoundSet";
					id=1400;
				};
				class Flare_Gun_cocked
				{
					soundSet="Flare_Gun_cocked_SoundSet";
					id=1402;
				};
				class Flare_Gun_dry
				{
					soundSet="Flare_Gun_dry_SoundSet";
					id=1401;
				};
				class SCOUT_charge_open
				{
					soundSet="SCOUT_charge_open_SoundSet";
					id=1403;
				};
				class SCOUT_charge_open_release
				{
					soundSet="SCOUT_charge_open_release_SoundSet";
					id=1404;
				};
				class SCOUT_charge_close
				{
					soundSet="SCOUT_charge_close_SoundSet";
					id=1405;
				};
				class SCOUT_charge_close_release
				{
					soundSet="SCOUT_charge_close_release_SoundSet";
					id=1406;
				};
				class SCOUT_chamber_load
				{
					soundSet="SCOUT_chamber_load_SoundSet";
					id=1407;
				};
				class SCOUT_mag_in
				{
					soundSet="SCOUT_mag_in_SoundSet";
					id=1408;
				};
				class SCOUT_mag_load
				{
					soundSet="SCOUT_mag_load_SoundSet";
					id=1409;
				};
				class SCOUT_mag_out
				{
					soundSet="SCOUT_mag_out_SoundSet";
					id=1410;
				};
				class SCOUT_mag_remove
				{
					soundSet="SCOUT_mag_remove_SoundSet";
					id=1411;
				};
				class SCOUT_dry
				{
					soundSet="SCOUT_dry_SoundSet";
					id=1412;
				};
				class SCOUT_pullout
				{
					soundSet="SCOUT_pullout_SoundSet";
					id=1413;
				};
				class SCOUT_hand1
				{
					soundSet="SCOUT_hand1_SoundSet";
					id=1414;
				};
				class SCOUT_hand2
				{
					soundSet="SCOUT_hand2_SoundSet";
					id=1415;
				};
				class SCOUT_hand3
				{
					soundSet="SCOUT_hand3_SoundSet";
					id=1416;
				};
				class SCOUT_hand4
				{
					soundSet="SCOUT_hand4_SoundSet";
					id=1417;
				};
				class SCOUT_jamming1
				{
					soundSet="SCOUT_jamming1_SoundSet";
					id=1418;
				};
				class SCOUT_jamming2
				{
					soundSet="SCOUT_jamming2_SoundSet";
					id=1419;
				};
				class SCOUT_jamming3
				{
					soundSet="SCOUT_jamming3_SoundSet";
					id=1420;
				};
				class SCOUT_jamming4
				{
					soundSet="SCOUT_jamming4_SoundSet";
					id=1421;
				};
				class SCOUT_jamming5
				{
					soundSet="SCOUT_jamming5_SoundSet";
					id=1422;
				};
				class SCOUT_jamming6
				{
					soundSet="SCOUT_jamming6_SoundSet";
					id=1423;
				};
				class SCOUT_jamming7
				{
					soundSet="SCOUT_jamming7_SoundSet";
					id=1424;
				};
				class SCOUT_jamming8
				{
					soundSet="SCOUT_jamming8_SoundSet";
					id=1425;
				};
				class SCOUT_jamming9
				{
					soundSet="SCOUT_jamming9_SoundSet";
					id=1426;
				};
				class SCOUT_jamming10
				{
					soundSet="SCOUT_jamming10_SoundSet";
					id=1427;
				};
				class SCOUT_jamming11
				{
					soundSet="SCOUT_jamming11_SoundSet";
					id=1428;
				};
				class SCOUT_jam
				{
					soundSet="SCOUT_jam_SoundSet";
					id=1429;
				};
				class M16_charge_open
				{
					soundSet="M16_charge_open_SoundSet";
					id=1430;
				};
				class M16_charge_open_release
				{
					soundSet="M16_charge_open_release_SoundSet";
					id=1431;
				};
				class M16_charge_close
				{
					soundSet="M16_charge_close_SoundSet";
					id=1432;
				};
				class M16_charge_close_release
				{
					soundSet="M16_charge_close_release_SoundSet";
					id=1433;
				};
				class M16_charge_close_release2
				{
					soundSet="M16_charge_close_release2_SoundSet";
					id=1434;
				};
				class M16_chamber_load
				{
					soundSet="M16_chamber_load_SoundSet";
					id=1435;
				};
				class M16_mag_in
				{
					soundSet="M16_mag_in_SoundSet";
					id=1436;
				};
				class M16_mag_load
				{
					soundSet="M16_mag_load_SoundSet";
					id=1437;
				};
				class M16_mag_out
				{
					soundSet="M16_mag_out_SoundSet";
					id=1438;
				};
				class M16_mag_remove
				{
					soundSet="M16_mag_remove_SoundSet";
					id=1439;
				};
				class M16_dry
				{
					soundSet="M16_dry_SoundSet";
					id=1440;
				};
				class M16_pullout
				{
					soundSet="M16_pullout_SoundSet";
					id=1441;
				};
				class M16_hand
				{
					soundSet="M16_hand_SoundSet";
					id=1442;
				};
				class M16_weapon_down
				{
					soundSet="M16_weapon_down_SoundSet";
					id=1443;
				};
				class M16_jamming1
				{
					soundSet="M16_jamming1_SoundSet";
					id=1444;
				};
				class M16_jamming2
				{
					soundSet="M16_jamming2_SoundSet";
					id=1445;
				};
				class M16_jamming3
				{
					soundSet="M16_jamming3_SoundSet";
					id=1446;
				};
				class M16_jamming4
				{
					soundSet="M16_jamming4_SoundSet";
					id=1447;
				};
				class M16_jamming5
				{
					soundSet="M16_jamming5_SoundSet";
					id=1448;
				};
				class M16_jamming6
				{
					soundSet="M16_jamming6_SoundSet";
					id=1449;
				};
				class M16_jamming7
				{
					soundSet="M16_jamming7_SoundSet";
					id=1450;
				};
				class M16_jamming8
				{
					soundSet="M16_jamming8_SoundSet";
					id=1451;
				};
				class M16_jamming9
				{
					soundSet="M16_jamming9_SoundSet";
					id=1452;
				};
				class M16_jamming10
				{
					soundSet="M16_jamming10_SoundSet";
					id=1453;
				};
				class M16_jamming11
				{
					soundSet="M16_jamming11_SoundSet";
					id=1454;
				};
				class M16_jamming12
				{
					soundSet="M16_jamming12_SoundSet";
					id=1455;
				};
				class M16_jamming13
				{
					soundSet="M16_jamming13_SoundSet";
					id=1456;
				};
				class M16_jam
				{
					soundSet="M16_jam_SoundSet";
					id=1457;
				};
				class Famas_charge_open
				{
					soundSet="Famas_charge_open_SoundSet";
					id=1458;
				};
				class Famas_charge_open_release
				{
					soundSet="Famas_charge_open_release_SoundSet";
					id=1459;
				};
				class Famas_charge_close
				{
					soundSet="Famas_charge_close_SoundSet";
					id=1460;
				};
				class Famas_charge_close_release
				{
					soundSet="Famas_charge_close_release_SoundSet";
					id=1461;
				};
				class Famas_charge_close_release2
				{
					soundSet="Famas_charge_close_release2_SoundSet";
					id=1462;
				};
				class Famas_chamber_load
				{
					soundSet="Famas_chamber_load_SoundSet";
					id=1463;
				};
				class Famas_mag_in
				{
					soundSet="Famas_mag_in_SoundSet";
					id=1464;
				};
				class Famas_mag_load
				{
					soundSet="Famas_mag_load_SoundSet";
					id=1465;
				};
				class Famas_mag_out
				{
					soundSet="Famas_mag_out_SoundSet";
					id=1466;
				};
				class Famas_mag_remove
				{
					soundSet="Famas_mag_remove_SoundSet";
					id=1467;
				};
				class Famas_dry
				{
					soundSet="Famas_dry_SoundSet";
					id=1468;
				};
				class Famas_pullout
				{
					soundSet="Famas_pullout_SoundSet";
					id=1469;
				};
				class Famas_hand
				{
					soundSet="Famas_hand_SoundSet";
					id=1470;
				};
				class Famas_weapon_down
				{
					soundSet="Famas_weapon_down_SoundSet";
					id=1471;
				};
				class Famas_jamming1
				{
					soundSet="Famas_jamming1_SoundSet";
					id=1472;
				};
				class Famas_jamming2
				{
					soundSet="Famas_jamming2_SoundSet";
					id=1473;
				};
				class Famas_jamming3
				{
					soundSet="Famas_jamming3_SoundSet";
					id=1474;
				};
				class Famas_jamming4
				{
					soundSet="Famas_jamming4_SoundSet";
					id=1475;
				};
				class Famas_jamming5
				{
					soundSet="Famas_jamming5_SoundSet";
					id=1476;
				};
				class Famas_jamming6
				{
					soundSet="Famas_jamming6_SoundSet";
					id=1477;
				};
				class Famas_jamming7
				{
					soundSet="Famas_jamming7_SoundSet";
					id=1478;
				};
				class Famas_jamming8
				{
					soundSet="Famas_jamming8_SoundSet";
					id=1479;
				};
				class Famas_jamming9
				{
					soundSet="Famas_jamming9_SoundSet";
					id=1480;
				};
				class Famas_jamming10
				{
					soundSet="Famas_jamming10_SoundSet";
					id=1481;
				};
				class Famas_jamming11
				{
					soundSet="Famas_jamming11_SoundSet";
					id=1482;
				};
				class Famas_jamming12
				{
					soundSet="Famas_jamming12_SoundSet";
					id=1483;
				};
				class Famas_jamming13
				{
					soundSet="Famas_jamming13_SoundSet";
					id=1484;
				};
				class Famas_jam
				{
					soundSet="Famas_jam_SoundSet";
					id=1485;
				};
				class AUG_charge_open
				{
					soundSet="AUG_charge_open_SoundSet";
					id=1490;
				};
				class AUG_charge_open_release
				{
					soundSet="AUG_charge_open_release_SoundSet";
					id=1491;
				};
				class AUG_charge_close
				{
					soundSet="AUG_charge_close_SoundSet";
					id=1492;
				};
				class AUG_charge_close_release
				{
					soundSet="AUG_charge_close_release_SoundSet";
					id=1493;
				};
				class AUG_charge_close_release2
				{
					soundSet="AUG_charge_close_release2_SoundSet";
					id=1494;
				};
				class AUG_chamber_load
				{
					soundSet="AUG_chamber_load_SoundSet";
					id=1495;
				};
				class AUG_mag_in
				{
					soundSet="AUG_mag_in_SoundSet";
					id=1496;
				};
				class AUG_mag_load
				{
					soundSet="AUG_mag_load_SoundSet";
					id=1497;
				};
				class AUG_mag_out
				{
					soundSet="AUG_mag_out_SoundSet";
					id=1498;
				};
				class AUG_mag_remove
				{
					soundSet="AUG_mag_remove_SoundSet";
					id=1499;
				};
				class AUG_dry
				{
					soundSet="AUG_dry_SoundSet";
					id=1500;
				};
				class AUG_pullout
				{
					soundSet="AUG_pullout_SoundSet";
					id=1501;
				};
				class AUG_hand
				{
					soundSet="AUG_hand_SoundSet";
					id=1502;
				};
				class AUG_weapon_down
				{
					soundSet="AUG_weapon_down_SoundSet";
					id=1503;
				};
				class AUG_jamming1
				{
					soundSet="AUG_jamming1_SoundSet";
					id=1504;
				};
				class AUG_jamming2
				{
					soundSet="AUG_jamming2_SoundSet";
					id=1505;
				};
				class AUG_jamming3
				{
					soundSet="AUG_jamming3_SoundSet";
					id=1506;
				};
				class AUG_jamming4
				{
					soundSet="AUG_jamming4_SoundSet";
					id=1507;
				};
				class AUG_jamming5
				{
					soundSet="AUG_jamming5_SoundSet";
					id=1508;
				};
				class AUG_jamming6
				{
					soundSet="AUG_jamming6_SoundSet";
					id=1509;
				};
				class AUG_jamming7
				{
					soundSet="AUG_jamming7_SoundSet";
					id=1510;
				};
				class AUG_jamming8
				{
					soundSet="AUG_jamming8_SoundSet";
					id=1511;
				};
				class AUG_jamming9
				{
					soundSet="AUG_jamming9_SoundSet";
					id=1512;
				};
				class AUG_jamming10
				{
					soundSet="AUG_jamming10_SoundSet";
					id=1513;
				};
				class AUG_jamming11
				{
					soundSet="AUG_jamming11_SoundSet";
					id=1514;
				};
				class AUG_jamming12
				{
					soundSet="AUG_jamming12_SoundSet";
					id=1515;
				};
				class AUG_jamming13
				{
					soundSet="AUG_jamming13_SoundSet";
					id=1516;
				};
				class AUG_jam
				{
					soundSet="AUG_jam_SoundSet";
					id=1517;
				};
				class Bizon_charge_open
				{
					soundSet="Bizon_charge_open_SoundSet";
					id=1518;
				};
				class Bizon_charge_open_release
				{
					soundSet="Bizon_charge_open_release_SoundSet";
					id=1519;
				};
				class Bizon_charge_close
				{
					soundSet="Bizon_charge_close_SoundSet";
					id=1520;
				};
				class Bizon_charge_close_release
				{
					soundSet="Bizon_charge_close_release_SoundSet";
					id=1521;
				};
				class Bizon_chamber_load
				{
					soundSet="Bizon_chamber_load_SoundSet";
					id=1522;
				};
				class Bizon_mag_in
				{
					soundSet="Bizon_mag_in_SoundSet";
					id=1523;
				};
				class Bizon_mag_load
				{
					soundSet="Bizon_mag_load_SoundSet";
					id=1524;
				};
				class Bizon_mag_remove
				{
					soundSet="Bizon_mag_remove_SoundSet";
					id=1525;
				};
				class Bizon_dry
				{
					soundSet="Bizon_dry_SoundSet";
					id=1526;
				};
				class Bizon_pullout
				{
					soundSet="Bizon_pullout_SoundSet";
					id=1527;
				};
				class Bizon_mag_out
				{
					soundSet="Bizon_mag_out_SoundSet";
					id=1528;
				};
				class Bizon_hand
				{
					soundSet="Bizon_hand_SoundSet";
					id=1529;
				};
				class Bizon_jamming1
				{
					soundSet="Bizon_jamming1_SoundSet";
					id=1530;
				};
				class Bizon_jamming2
				{
					soundSet="Bizon_jamming2_SoundSet";
					id=1531;
				};
				class Bizon_jamming3
				{
					soundSet="Bizon_jamming3_SoundSet";
					id=1532;
				};
				class Bizon_jamming4
				{
					soundSet="Bizon_jamming4_SoundSet";
					id=1533;
				};
				class Bizon_jamming5
				{
					soundSet="Bizon_jamming5_SoundSet";
					id=1534;
				};
				class Bizon_jamming6
				{
					soundSet="Bizon_jamming6_SoundSet";
					id=1535;
				};
				class Bizon_jamming7
				{
					soundSet="Bizon_jamming7_SoundSet";
					id=1536;
				};
				class Bizon_jamming8
				{
					soundSet="Bizon_jamming8_SoundSet";
					id=1537;
				};
				class Bizon_jamming9
				{
					soundSet="Bizon_jamming9_SoundSet";
					id=1538;
				};
				class Bizon_jamming10
				{
					soundSet="Bizon_jamming10_SoundSet";
					id=1539;
				};
				class Bizon_jamming11
				{
					soundSet="Bizon_jamming11_SoundSet";
					id=1540;
				};
				class Bizon_jamming12
				{
					soundSet="Bizon_jamming12_SoundSet";
					id=1541;
				};
				class Bizon_jamming13
				{
					soundSet="Bizon_jamming13_SoundSet";
					id=1542;
				};
				class Bizon_jam
				{
					soundSet="Bizon_jam_SoundSet";
					id=1543;
				};
				class LongHorn_charge_open
				{
					soundSet="LongHorn_charge_open_SoundSet";
					id=1546;
				};
				class LongHorn_charge_close
				{
					soundSet="LongHorn_charge_close_SoundSet";
					id=1547;
				};
				class LongHorn_chamber_load
				{
					soundSet="LongHorn_chamber_load_SoundSet";
					id=1548;
				};
				class LongHorn_Hand1
				{
					soundSet="LongHorn_hand1_SoundSet";
					id=1549;
				};
				class LongHorn_Hand2
				{
					soundSet="LongHorn_hand2_SoundSet";
					id=1550;
				};
				class LongHorn_jamming1
				{
					soundSet="LongHorn_jamming1_SoundSet";
					id=1551;
				};
				class LongHorn_jamming2
				{
					soundSet="LongHorn_jamming2_SoundSet";
					id=1552;
				};
				class LongHorn_jamming3
				{
					soundSet="LongHorn_jamming3_SoundSet";
					id=1553;
				};
				class LongHorn_jamming4
				{
					soundSet="LongHorn_jamming4_SoundSet";
					id=1554;
				};
				class LongHorn_jamming5
				{
					soundSet="LongHorn_jamming5_SoundSet";
					id=1555;
				};
				class LongHorn_jamming6
				{
					soundSet="LongHorn_jamming6_SoundSet";
					id=1556;
				};
				class LongHorn_jamming7
				{
					soundSet="LongHorn_jamming7_SoundSet";
					id=1557;
				};
				class LongHorn_jamming8
				{
					soundSet="LongHorn_jamming8_SoundSet";
					id=1558;
				};
				class LongHorn_jamming9
				{
					soundSet="LongHorn_jamming9_SoundSet";
					id=1559;
				};
				class LongHorn_jamming10
				{
					soundSet="LongHorn_jamming10_SoundSet";
					id=1560;
				};
				class LongHorn_jamming11
				{
					soundSet="LongHorn_jamming11_SoundSet";
					id=1561;
				};
				class LongHorn_jamming12
				{
					soundSet="LongHorn_jamming12_SoundSet";
					id=1562;
				};
				class LongHorn_jamming13
				{
					soundSet="LongHorn_jamming13_SoundSet";
					id=1563;
				};
				class LongHorn_cocked
				{
					soundSet="LongHorn_cocked_SoundSet";
					id=1564;
				};
				class CZ550_charge_open
				{
					soundSet="CZ550_charge_open_SoundSet";
					id=1600;
				};
				class CZ550_charge_close
				{
					soundSet="CZ550_charge_close_SoundSet";
					id=1602;
				};
				class CZ550_chamber_load
				{
					soundSet="CZ550_chamber_load_SoundSet";
					id=1604;
				};
				class CZ550_mag_in
				{
					soundSet="CZ550_mag_in_SoundSet";
					id=1605;
				};
				class CZ550_mag_out
				{
					soundSet="CZ550_mag_out_SoundSet";
					id=1606;
				};
				class CZ550_mag_remove
				{
					soundSet="CZ550_mag_remove_SoundSet";
					id=1607;
				};
				class CZ550_dry
				{
					soundSet="CZ550_dry_SoundSet";
					id=1608;
				};
				class CZ550_pullout
				{
					soundSet="CZ550_pullout_SoundSet";
					id=1609;
				};
				class CZ550_hand1
				{
					soundSet="CZ550_hand1_SoundSet";
					id=1610;
				};
				class CZ550_hand2
				{
					soundSet="CZ550_hand2_SoundSet";
					id=1611;
				};
				class CZ550_hand3
				{
					soundSet="CZ550_hand3_SoundSet";
					id=1612;
				};
				class CZ550_hand4
				{
					soundSet="CZ550_hand4_SoundSet";
					id=1613;
				};
				class CZ550_jamming1
				{
					soundSet="CZ550_jamming1_SoundSet";
					id=1614;
				};
				class CZ550_jamming2
				{
					soundSet="CZ550_jamming2_SoundSet";
					id=1615;
				};
				class CZ550_jamming3
				{
					soundSet="CZ550_jamming3_SoundSet";
					id=1616;
				};
				class CZ550_jamming4
				{
					soundSet="CZ550_jamming4_SoundSet";
					id=1617;
				};
				class CZ550_jamming5
				{
					soundSet="CZ550_jamming5_SoundSet";
					id=1618;
				};
				class CZ550_jamming6
				{
					soundSet="CZ550_jamming6_SoundSet";
					id=1619;
				};
				class CZ550_jamming7
				{
					soundSet="CZ550_jamming7_SoundSet";
					id=1620;
				};
				class CZ550_jamming8
				{
					soundSet="CZ550_jamming8_SoundSet";
					id=1621;
				};
				class CZ550_jamming9
				{
					soundSet="CZ550_jamming9_SoundSet";
					id=1622;
				};
				class CZ550_jamming10
				{
					soundSet="CZ550_jamming10_SoundSet";
					id=1623;
				};
				class CZ550_jamming11
				{
					soundSet="CZ550_jamming11_SoundSet";
					id=1624;
				};
				class CZ550_jam
				{
					soundSet="CZ550_jam_SoundSet";
					id=1625;
				};
				class WaltherP1_charge_open
				{
					soundSet="WaltherP1_charge_open_SoundSet";
					id=1631;
				};
				class WaltherP1_charge_close
				{
					soundSet="WaltherP1_charge_close_SoundSet";
					id=1633;
				};
				class WaltherP1_charge_close_release
				{
					soundSet="WaltherP1_charge_close_release_SoundSet";
					id=1634;
				};
				class WaltherP1_pullout
				{
					soundSet="WaltherP1_pullout_SoundSet";
					id=1641;
				};
				class WaltherP1_mag_in
				{
					soundSet="WaltherP1_mag_in_SoundSet";
					id=1651;
				};
				class WaltherP1_mag_load
				{
					soundSet="WaltherP1_mag_load_SoundSet";
					id=1652;
				};
				class WaltherP1_mag_out
				{
					soundSet="WaltherP1_mag_out_SoundSet";
					id=1653;
				};
				class WaltherP1_mag_remove
				{
					soundSet="WaltherP1_mag_remove_SoundSet";
					id=1654;
				};
				class M79_charge_open
				{
					soundSet="M79_charge_open_SoundSet";
					id=1651;
				};
				class M79_charge_close
				{
					soundSet="M79_charge_close_SoundSet";
					id=1652;
				};
				class M79_grenade_in
				{
					soundSet="M79_grenade_in_SoundSet";
					id=1653;
				};
				class M79_grenade_out
				{
					soundSet="M79_grenade_out_SoundSet";
					id=1654;
				};
				class M79_grenade_load
				{
					soundSet="M79_grenade_load_SoundSet";
					id=1655;
				};
				class M79_dry
				{
					soundSet="M79_dry_SoundSet";
					id=1656;
				};
				class Derringer_charge_open
				{
					soundSet="Derringer_charge_open_SoundSet";
					id=1700;
				};
				class Derringer_charge_close
				{
					soundSet="Derringer_charge_close_SoundSet";
					id=1701;
				};
				class Derringer_bullet_in
				{
					soundSet="Derringer_bullet_in_SoundSet";
					id=1702;
				};
				class Derringer_chamber_load
				{
					soundSet="Derringer_chamber_load_SoundSet";
					id=1703;
				};
				class Derringer_cocked
				{
					soundSet="Derringer_cocked_SoundSet";
					id=1704;
				};
				class Derringer_dry
				{
					soundSet="Derringer_dry_SoundSet";
					id=1705;
				};
				class SSG82_charge_open
				{
					soundSet="SSG82_charge_open_SoundSet";
					id=1710;
				};
				class SSG82_charge_close
				{
					soundSet="SSG82_charge_close_SoundSet";
					id=1711;
				};
				class SSG82_mag_in
				{
					soundSet="SSG82_mag_in_SoundSet";
					id=1713;
				};
				class SSG82_mag_load
				{
					soundSet="SSG82_mag_load_SoundSet";
					id=1734;
				};
				class SSG82_mag_out
				{
					soundSet="SSG82_mag_out_SoundSet";
					id=1714;
				};
				class SSG82_mag_remove
				{
					soundSet="SSG82_mag_remove_SoundSet";
					id=1715;
				};
				class SSG82_dry
				{
					soundSet="SSG82_dry_SoundSet";
					id=1716;
				};
				class SSG82_pullout
				{
					soundSet="SSG82_pullout_SoundSet";
					id=1717;
				};
				class SSG82_hand1
				{
					soundSet="SSG82_hand1_SoundSet";
					id=1718;
				};
				class SSG82_hand2
				{
					soundSet="SSG82_hand2_SoundSet";
					id=1719;
				};
				class SSG82_hand3
				{
					soundSet="SSG82_hand3_SoundSet";
					id=1720;
				};
				class SSG82_hand4
				{
					soundSet="SSG82_hand4_SoundSet";
					id=1721;
				};
				class SSG82_jamming1
				{
					soundSet="SSG82_jamming1_SoundSet";
					id=1722;
				};
				class SSG82_jamming2
				{
					soundSet="SSG82_jamming2_SoundSet";
					id=1723;
				};
				class SSG82_jamming3
				{
					soundSet="SSG82_jamming3_SoundSet";
					id=1724;
				};
				class SSG82_jamming4
				{
					soundSet="SSG82_jamming4_SoundSet";
					id=1725;
				};
				class SSG82_jamming5
				{
					soundSet="SSG82_jamming5_SoundSet";
					id=1726;
				};
				class SSG82_jamming6
				{
					soundSet="SSG82_jamming6_SoundSet";
					id=1727;
				};
				class SSG82_jamming7
				{
					soundSet="SSG82_jamming7_SoundSet";
					id=1728;
				};
				class SSG82_jamming8
				{
					soundSet="SSG82_jamming8_SoundSet";
					id=1729;
				};
				class SSG82_jamming9
				{
					soundSet="SSG82_jamming9_SoundSet";
					id=1730;
				};
				class SSG82_jamming10
				{
					soundSet="SSG82_jamming10_SoundSet";
					id=1731;
				};
				class SSG82_jamming11
				{
					soundSet="SSG82_jamming11_SoundSet";
					id=1732;
				};
				class SSG82_jam
				{
					soundSet="SSG82_jam_SoundSet";
					id=1733;
				};
				class Crossbow_arrow_in
				{
					soundSet="Crossbow_arrow_in_SoundSet";
					id=1750;
				};
				class Crossbow_arrow_out
				{
					soundSet="Crossbow_arrow_out_SoundSet";
					id=1751;
				};
				class Crossbow_pullout
				{
					soundSet="Crossbow_pullout_SoundSet";
					id=1753;
				};
				class Crossbow_dry
				{
					soundSet="Crossbow_dry_SoundSet";
					id=1754;
				};
				class Crossbow_hand
				{
					soundSet="Crossbow_hand_SoundSet";
					id=1755;
				};
				class Crossbow_shot
				{
					soundSet="Crossbow_Shot_SoundSet";
					id=1756;
				};
				class Crossbow_shot_interiorTail
				{
					soundSet="Crossbow_InteriorTail_SoundSet";
					id=1757;
				};
				class Crossbow_string_pullin_1
				{
					soundSet="Crossbow_string_pullin_1_SoundSet";
					id=1758;
				};
				class Crossbow_string_pullin_2
				{
					soundSet="Crossbow_string_pullin_2_SoundSet";
					id=1759;
				};
				class Crossbow_string_pullin_3
				{
					soundSet="Crossbow_string_pullin_3_SoundSet";
					id=1760;
				};
				class MagRifle_fill_loop
				{
					soundSet="MagRifle_fill_loop_SoundSet";
					id=402;
				};
				class MagRifle_fill_out
				{
					soundSet="MagRifle_fill_out_SoundSet";
					id=403;
				};
				class MagRifle_empty_loop
				{
					soundSet="MagRifle_empty_loop_SoundSet";
					id=405;
				};
				class MagPistol_fill_loop
				{
					soundSet="MagPistol_fill_loop_SoundSet";
					id=408;
				};
				class MagPistol_fill_out
				{
					soundSet="MagPistol_fill_out_SoundSet";
					id=409;
				};
				class MagPistol_empty_loop
				{
					soundSet="MagPistol_empty_loop_SoundSet";
					id=411;
				};
				class ChoppingTree
				{
					soundSet="ChoppingTree_SoundSet";
					id=415;
				};
				class pickUpRifleLight
				{
					soundSet="pickUpRifleLight_SoundSet";
					id=798;
				};
				class Char_HiddenStash_Dig_Shovel_Shot
				{
					soundset="Char_HiddenStash_Dig_Shovel_Shot_SoundSet";
					id=886;
				};
				class Char_HiddenStash_Dig_Dirt
				{
					soundset="Char_HiddenStash_Dig_Dirt_SoundSet";
					id=887;
				};
				class Char_HiddenStash_Dig_Shovel_In
				{
					soundset="Char_HiddenStash_Dig_Shovel_In_SoundSet";
					id=888;
				};
				class Char_HiddenStash_Dig_Find
				{
					soundset="Char_HiddenStash_Dig_Find_SoundSet";
					id=889;
				};
				class Char_Unconscious_Hand_Move_Water
				{
					soundset="Char_Unconscious_Hand_Move_Water_SoundSet";
					id=890;
				};
				class Char_Gestures_Hand_Clap_Head
				{
					soundset="Char_Gestures_Hand_Clap_Head_SoundSet";
					id=891;
				};
				class Char_Gestures_Hand_Grab_Fabric
				{
					soundset="Char_Gestures_Hand_Grab_Fabric_SoundSet";
					id=892;
				};
				class pickUpRifle
				{
					soundset="pickUpRifle_SoundSet";
					id=893;
				};
				class hand_ladder
				{
					soundset="hand_ladder_Char_Soundset";
					id=898;
				};
				class slide_ladder
				{
					soundset="slide_ladder_Char_Soundset";
					id=899;
				};
				class ShoulderL_Hide_Rifle
				{
					soundset="ShoulderL_Hide_Rifle_SoundSet";
					id=1200;
				};
				class ShoulderL_Show_Rifle
				{
					soundset="ShoulderL_Show_Rifle_SoundSet";
					id=1201;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class Inventory_Hide
				{
					soundset="Inventory_Hide_SoundSet";
					id=1220;
				};
				class Inventory_Show
				{
					soundset="Inventory_Show_SoundSet";
					id=1221;
				};
				class Chest_Pistol_Hide
				{
					soundset="Chest_Pistol_Hide_SoundSet";
					id=1222;
				};
				class Chest_Pistol_Show
				{
					soundset="Chest_Pistol_Show_SoundSet";
					id=1223;
				};
				class Back_Knife_Hide
				{
					soundset="Back_Knife_Hide_SoundSet";
					id=1224;
				};
				class Back_Knife_Show
				{
					soundset="Back_Knife_Show_SoundSet";
					id=1225;
				};
				class offroad_Gear
				{
					soundset="offroad_Gear_SoundSet";
					id=2000;
				};
				class Offroad_Key_On
				{
					soundset="Offroad_Key_On_SoundSet";
					id=2001;
				};
				class Offroad_Key_Off
				{
					soundset="Offroad_Key_Off_SoundSet";
					id=2002;
				};
				class Offroad_lights
				{
					soundset="Offroad_lights_SoundSet";
					id=2003;
				};
				class Offroad_DriverGetIn
				{
					soundset="Offroad_DriverGetIn_SoundSet";
					id=2004;
				};
				class Offroad_DriverGetOut
				{
					soundset="Offroad_DriverGetOut_SoundSet";
					id=2005;
				};
				class Offroad_DriverJumpOut
				{
					soundset="Offroad_DriverJumpOut_SoundSet";
					id=2006;
				};
				class Offroad_CoDriverGetIn
				{
					soundset="Offroad_CoDriverGetIn_SoundSet";
					id=2007;
				};
				class Offroad_CoDriverGetOut
				{
					soundset="Offroad_CoDriverGetOut_SoundSet";
					id=2008;
				};
				class Offroad_CoDriverJumpOut
				{
					soundset="Offroad_CoDriverJumpOut_SoundSet";
					id=2009;
				};
				class Offroad_PassengerGetIn
				{
					soundset="Offroad_PassengerGetIn_SoundSet";
					id=2010;
				};
				class Offroad_PassengerGetOut
				{
					soundset="Offroad_PassengerGetOut_SoundSet";
					id=2011;
				};
				class Offroad_driver_switchSeat
				{
					soundset="Offroad_driver_switchSeat_SoundSet";
					id=2020;
				};
				class Offroad_passanger_switchSeat
				{
					soundset="Offroad_passanger_switchSeat_SoundSet";
					id=2021;
				};
				class Offroad_switchSeat_hand
				{
					soundset="Offroad_switchSeat_hand_SoundSet";
					id=2022;
				};
				class Offroad_hit_character
				{
					soundset="offroad_hit_character_SoundSet";
					id=2040;
				};
				class Offroad_Horn_Start
				{
					soundset="Offroad_Horn_Start_SoundSet";
					id=2041;
				};
				class Offroad_Horn_End
				{
					soundset="Offroad_Horn_End_SoundSet";
					id=2042;
				};
				class Offroad_Starting
				{
					soundset="Offroad_Starting_SoundSet";
					id=2043;
				};
				class Offroad_SeatShiftIn
				{
					soundset="Offroad_SeatShiftIn_SoundSet";
					id=2044;
				};
				class Offroad_SeatShiftOut
				{
					soundset="Offroad_SeatShiftOut_SoundSet";
					id=2045;
				};
				class Passenger_death_DragOut
				{
					soundset="Passenger_death_DragOut_SoundSet";
					id=2046;
				};
				class Truck_01_Gear
				{
					soundset="Truck_01_Gear_SoundSet";
					id=2100;
				};
				class Truck_01_Key_On
				{
					soundset="Truck_01_Key_On_SoundSet";
					id=2101;
				};
				class Truck_01_Key_Off
				{
					soundset="Truck_01_Key_Off_SoundSet";
					id=2102;
				};
				class Truck_01_lights
				{
					soundset="Truck_01_lights_SoundSet";
					id=2103;
				};
				class Truck_01_DriverGetIn
				{
					soundset="Truck_01_DriverGetIn_SoundSet";
					id=2104;
				};
				class Truck_01_DriverGetOut
				{
					soundset="Truck_01_DriverGetOut_SoundSet";
					id=2105;
				};
				class Truck_01_CoDriverGetIn
				{
					soundset="Truck_01_CoDriverGetIn_SoundSet";
					id=2106;
				};
				class Truck_01_CoDriverGetOut
				{
					soundset="Truck_01_CoDriverGetOut_SoundSet";
					id=2107;
				};
				class Truck_01_DriverJumpOut
				{
					soundset="Offroad_DriverJumpOut_SoundSet";
					id=2110;
				};
				class Truck_01_CodriverJumpOut
				{
					soundset="Offroad_DriverJumpOut_SoundSet";
					id=2111;
				};
				class Truck_01_driver_switchSeat
				{
					soundset="Truck_01_driver_switchSeat_SoundSet";
					id=2120;
				};
				class Truck_01_codriver_switchSeat
				{
					soundset="Truck_01_driver_switchSeat_SoundSet";
					id=2121;
				};
				class Truck_01_Horn_Start
				{
					soundset="Truck_01_Horn_Start_SoundSet";
					id=2122;
				};
				class Truck_01_Horn_End
				{
					soundset="Truck_01_Horn_End_SoundSet";
					id=2123;
				};
				class CivilianSedan_Gear
				{
					soundset="CivilianSedan_Gear_SoundSet";
					id=2200;
				};
				class CivilianSedan_Key_On
				{
					soundset="CivilianSedan_Key_On_SoundSet";
					id=2201;
				};
				class CivilianSedan_Key_Off
				{
					soundset="CivilianSedan_Key_Off_SoundSet";
					id=2202;
				};
				class CivilianSedan_lights
				{
					soundset="CivilianSedan_lights_SoundSet";
					id=2203;
				};
				class CivilianSedan_DriverGetIn
				{
					soundset="CivilianSedan_DriverGetIn_SoundSet";
					id=2204;
				};
				class CivilianSedan_DriverGetOut
				{
					soundset="CivilianSedan_DriverGetOut_SoundSet";
					id=2205;
				};
				class CivilianSedan_DriverJumpOut
				{
					soundset="CivilianSedan_DriverJumpOut_SoundSet";
					id=2206;
				};
				class CivilianSedan_CoDriverGetIn
				{
					soundset="CivilianSedan_CoDriverGetIn_SoundSet";
					id=2207;
				};
				class CivilianSedan_CoDriverGetOut
				{
					soundset="CivilianSedan_CoDriverGetOut_SoundSet";
					id=2208;
				};
				class CivilianSedan_CoDriverJumpOut
				{
					soundset="CivilianSedan_CoDriverJumpOut_SoundSet";
					id=2209;
				};
				class CivilianSedan_PassengerGetIn
				{
					soundset="CivilianSedan_PassengerGetIn_SoundSet";
					id=2210;
				};
				class CivilianSedan_PassengerGetOut
				{
					soundset="CivilianSedan_PassengerGetOut_SoundSet";
					id=2211;
				};
				class CivilianSedan_driver_switchSeat
				{
					soundset="CivilianSedan_driver_switchSeat_SoundSet";
					id=2220;
				};
				class CivilianSedan_passanger_switchSeat
				{
					soundset="CivilianSedan_passanger_switchSeat_SoundSet";
					id=2221;
				};
				class CivilianSedan_switchSeat_hand
				{
					soundset="CivilianSedan_switchSeat_hand_SoundSet";
					id=2222;
				};
				class CivilianSedan_Horn_Start
				{
					soundset="CivilianSedan_Horn_Start_SoundSet";
					id=2223;
				};
				class CivilianSedan_Horn_End
				{
					soundset="CivilianSedan_Horn_End_SoundSet";
					id=2224;
				};
				class Hatchback_02_Gear
				{
					soundset="Hatchback_02_Gear_SoundSet";
					id=2300;
				};
				class Hatchback_02_Key_On
				{
					soundset="Hatchback_02_Key_On_SoundSet";
					id=2301;
				};
				class Hatchback_02_Key_Off
				{
					soundset="Hatchback_02_Key_Off_SoundSet";
					id=2302;
				};
				class Hatchback_02_lights
				{
					soundset="Hatchback_02_lights_SoundSet";
					id=2303;
				};
				class Hatchback_02_DriverGetIn
				{
					soundset="Hatchback_02_DriverGetIn_SoundSet";
					id=2304;
				};
				class Hatchback_02_DriverGetOut
				{
					soundset="Hatchback_02_DriverGetOut_SoundSet";
					id=2305;
				};
				class Hatchback_02_DriverJumpOut
				{
					soundset="Hatchback_02_DriverJumpOut_SoundSet";
					id=2306;
				};
				class Hatchback_02_CoDriverGetIn
				{
					soundset="Hatchback_02_CoDriverGetIn_SoundSet";
					id=2307;
				};
				class Hatchback_02_CoDriverGetOut
				{
					soundset="Hatchback_02_CoDriverGetOut_SoundSet";
					id=2308;
				};
				class Hatchback_02_CoDriverJumpOut
				{
					soundset="Hatchback_02_CoDriverJumpOut_SoundSet";
					id=2309;
				};
				class Hatchback_02_PassengerGetIn
				{
					soundset="Hatchback_02_PassengerGetIn_SoundSet";
					id=2310;
				};
				class Hatchback_02_PassengerGetOut
				{
					soundset="Hatchback_02_PassengerGetOut_SoundSet";
					id=2311;
				};
				class Hatchback_02_driver_switchSeat
				{
					soundset="Hatchback_02_driver_switchSeat_SoundSet";
					id=2320;
				};
				class Hatchback_02_passanger_switchSeat
				{
					soundset="Hatchback_02_passanger_switchSeat_SoundSet";
					id=2321;
				};
				class Hatchback_02_switchSeat_hand
				{
					soundset="Hatchback_02_switchSeat_hand_SoundSet";
					id=2322;
				};
				class Hatchback_02_Horn_Start
				{
					soundset="Hatchback_02_Horn_Start_SoundSet";
					id=2323;
				};
				class Hatchback_02_Horn_End
				{
					soundset="Hatchback_02_Horn_End_SoundSet";
					id=2324;
				};
				class Sedan_02_Gear
				{
					soundset="Sedan_02_Gear_SoundSet";
					id=2400;
				};
				class Sedan_02_Key_On
				{
					soundset="Sedan_02_Key_On_SoundSet";
					id=2401;
				};
				class Sedan_02_Key_Off
				{
					soundset="Sedan_02_Key_Off_SoundSet";
					id=2402;
				};
				class Sedan_02_lights
				{
					soundset="Sedan_02_lights_SoundSet";
					id=2403;
				};
				class Sedan_02_DriverGetIn
				{
					soundset="Sedan_02_DriverGetIn_SoundSet";
					id=2404;
				};
				class Sedan_02_DriverGetOut
				{
					soundset="Sedan_02_DriverGetOut_SoundSet";
					id=2405;
				};
				class Sedan_02_DriverJumpOut
				{
					soundset="Sedan_02_DriverJumpOut_SoundSet";
					id=2406;
				};
				class Sedan_02_CoDriverGetIn
				{
					soundset="Sedan_02_CoDriverGetIn_SoundSet";
					id=2407;
				};
				class Sedan_02_CoDriverGetOut
				{
					soundset="Sedan_02_CoDriverGetOut_SoundSet";
					id=2408;
				};
				class Sedan_02_CoDriverJumpOut
				{
					soundset="Sedan_02_CoDriverJumpOut_SoundSet";
					id=2409;
				};
				class Sedan_02_PassengerGetIn
				{
					soundset="Sedan_02_PassengerGetIn_SoundSet";
					id=2410;
				};
				class Sedan_02_PassengerGetOut
				{
					soundset="Sedan_02_PassengerGetOut_SoundSet";
					id=2411;
				};
				class Sedan_02_driver_switchSeat
				{
					soundset="Sedan_02_driver_switchSeat_SoundSet";
					id=2420;
				};
				class Sedan_02_passanger_switchSeat
				{
					soundset="Sedan_02_passanger_switchSeat_SoundSet";
					id=2421;
				};
				class Sedan_02_switchSeat_hand
				{
					soundset="Sedan_02_switchSeat_hand_SoundSet";
					id=2422;
				};
				class Sedan_02_Horn_Start
				{
					soundset="Sedan_02_Horn_Start_SoundSet";
					id=2423;
				};
				class Sedan_02_Horn_End
				{
					soundset="Sedan_02_Horn_End_SoundSet";
					id=2424;
				};
				class offroad_02_Gear
				{
					soundset="offroad_02_Gear_SoundSet";
					id=2450;
				};
				class Offroad_02_Key_On
				{
					soundset="Offroad_02_Key_On_SoundSet";
					id=2451;
				};
				class Offroad_02_Key_Off
				{
					soundset="Offroad_02_Key_Off_SoundSet";
					id=2452;
				};
				class Offroad_02_lights
				{
					soundset="Offroad_02_lights_SoundSet";
					id=2453;
				};
				class Offroad_02_DriverGetIn
				{
					soundset="Offroad_02_DriverGetIn_SoundSet";
					id=2454;
				};
				class Offroad_02_DriverGetOut
				{
					soundset="Offroad_02_DriverGetOut_SoundSet";
					id=2455;
				};
				class Offroad_02_DriverJumpOut
				{
					soundset="Offroad_02_DriverJumpOut_SoundSet";
					id=2456;
				};
				class Offroad_02_CoDriverGetIn
				{
					soundset="Offroad_02_CoDriverGetIn_SoundSet";
					id=2457;
				};
				class Offroad_02_CoDriverGetOut
				{
					soundset="Offroad_02_CoDriverGetOut_SoundSet";
					id=2458;
				};
				class Offroad_02_CoDriverJumpOut
				{
					soundset="Offroad_02_CoDriverJumpOut_SoundSet";
					id=2459;
				};
				class Offroad_02_PassengerGetIn
				{
					soundset="Offroad_02_PassengerGetIn_SoundSet";
					id=2460;
				};
				class Offroad_02_PassengerGetOut
				{
					soundset="Offroad_02_PassengerGetOut_SoundSet";
					id=2461;
				};
				class Offroad_02_driver_switchSeat
				{
					soundset="Offroad_02_driver_switchSeat_SoundSet";
					id=2462;
				};
				class Offroad_02_passanger_switchSeat
				{
					soundset="Offroad_02_passanger_switchSeat_SoundSet";
					id=2463;
				};
				class Offroad_02_switchSeat_hand
				{
					soundset="Offroad_02_switchSeat_hand_SoundSet";
					id=2464;
				};
				class Offroad_02_hit_character
				{
					soundset="offroad_02_hit_character_SoundSet";
					id=2465;
				};
				class Offroad_02_horn
				{
					soundset="Offroad_02_Horn_SoundSet";
					id=2466;
				};
				class Offroad_02_Horn_Start
				{
					soundset="Offroad_02_Horn_Start_SoundSet";
					id=2467;
				};
				class Offroad_02_Horn_End
				{
					soundset="Offroad_02_Horn_End_SoundSet";
					id=2468;
				};
				class p_1hd_cro_suicide_out
				{
					soundset="p_1hd_cro_suicide_out_SoundSet";
					id=3001;
				};
				class p_2hd_erc_fireaxe_suicide_in
				{
					soundset="p_2hd_erc_fireaxe_suicide_in_SoundSet";
					id=3003;
				};
				class p_2hd_erc_fireaxe_suicide_out_A
				{
					soundset="p_2hd_erc_fireaxe_suicide_out_A_SoundSet";
					id=3002;
				};
				class p_2hd_erc_fireaxe_suicide_out_B
				{
					soundset="p_2hd_erc_fireaxe_suicide_out_B_SoundSet";
					id=3004;
				};
				class p_2hd_erc_fireaxe_suicide_out_C
				{
					soundset="p_2hd_erc_fireaxe_suicide_out_C_SoundSet";
					id=3008;
				};
				class p_2hd_erc_fireaxe_suicide_out_D
				{
					soundset="p_2hd_erc_fireaxe_suicide_out_D_SoundSet";
					id=3009;
				};
				class p_2hd_erc_medievalsword_suicide_cancelled_A
				{
					soundset="p_2hd_erc_medievalsword_suicide_cancelled_A_SoundSet";
					id=3005;
				};
				class p_2hd_erc_medievalsword_suicide_cancelled_B
				{
					soundset="p_2hd_erc_medievalsword_suicide_cancelled_B_SoundSet";
					id=3011;
				};
				class p_2hd_erc_medievalsword_suicide_cancelled_C
				{
					soundset="p_2hd_erc_medievalsword_suicide_cancelled_C_SoundSet";
					id=3014;
				};
				class p_2hd_erc_medievalsword_suicide_in_A
				{
					soundset="p_2hd_erc_medievalsword_suicide_in_A_SoundSet";
					id=3006;
				};
				class p_2hd_erc_medievalsword_suicide_in_B
				{
					soundset="p_2hd_erc_medievalsword_suicide_in_B_SoundSet";
					id=3021;
				};
				class p_2hd_erc_medievalsword_suicide_in_C
				{
					soundset="p_2hd_erc_medievalsword_suicide_in_C_SoundSet";
					id=3022;
				};
				class p_2hd_erc_medievalsword_suicide_out
				{
					soundset="p_2hd_erc_medievalsword_suicide_out_SoundSet";
					id=3007;
				};
				class p_2hd_erc_pitchfork_suicide_out
				{
					soundset="p_2hd_erc_pitchfork_suicide_out_SoundSet";
					id=3010;
				};
				class p_2hd_erc_spear_suicide_in
				{
					soundset="p_2hd_erc_spear_suicide_in_SoundSet";
					id=3012;
				};
				class p_2hd_erc_spear_suicide_out
				{
					soundset="p_2hd_erc_spear_suicide_out_SoundSet";
					id=3013;
				};
				class p_2hd_erc_woodaxe_suicide_in
				{
					soundset="p_2hd_erc_woodaxe_suicide_in_SoundSet";
					id=3015;
				};
				class p_2hd_erc_woodaxe_suicide_out_A
				{
					soundset="p_2hd_erc_woodaxe_suicide_out_A_SoundSet";
					id=3016;
				};
				class p_2hd_erc_woodaxe_suicide_out_B
				{
					soundset="p_2hd_erc_woodaxe_suicide_out_B_SoundSet";
					id=3023;
				};
				class p_2hd_erc_woodaxe_suicide_out_C
				{
					soundset="p_2hd_erc_woodaxe_suicide_out_C_SoundSet";
					id=3024;
				};
				class p_2hd_erc_woodaxe_suicide_out_D
				{
					soundset="p_2hd_erc_woodaxe_suicide_out_D_SoundSet";
					id=3025;
				};
				class p_pst_cro_suicide_out
				{
					soundset="p_pst_cro_suicide_out_SoundSet";
					id=3017;
				};
				class p_rfl_cro_suicide_cancelled_A
				{
					soundset="p_rfl_cro_suicide_cancelled_A_SoundSet";
					id=3018;
				};
				class p_rfl_cro_suicide_cancelled_B
				{
					soundset="p_rfl_cro_suicide_cancelled_B_SoundSet";
					id=3026;
				};
				class p_rfl_cro_suicide_cancelled_C
				{
					soundset="p_rfl_cro_suicide_cancelled_C_SoundSet";
					id=3027;
				};
				class p_rfl_cro_suicide_in_A
				{
					soundset="p_rfl_cro_suicide_in_A_SoundSet";
					id=3019;
				};
				class p_rfl_cro_suicide_in_B
				{
					soundset="p_rfl_cro_suicide_in_B_SoundSet";
					id=3028;
				};
				class p_rfl_cro_suicide_in_C
				{
					soundset="p_rfl_cro_suicide_in_C_SoundSet";
					id=3029;
				};
				class p_rfl_cro_suicide_in_D
				{
					soundset="p_rfl_cro_suicide_in_D_SoundSet";
					id=3030;
				};
				class p_rfl_cro_suicide_out
				{
					soundset="p_rfl_cro_suicide_out_SoundSet";
					id=3020;
				};
				class RemoteDetonator_Trigger
				{
					soundset="RemoteDetonator_Trigger_SoundSet";
					id=3100;
				};
				class Clean_hands_Cauldron_In
				{
					soundSet="Clean_hands_Cauldron_In_SoundSet";
					id=3101;
				};
				class Clean_hands_Cauldron_loop
				{
					soundSet="Clean_hands_Cauldron_loop_SoundSet";
					id=3102;
				};
				class Clean_hands_Cauldron_Out
				{
					soundSet="Clean_hands_Cauldron_Out_SoundSet";
					id=3103;
				};
				class Clean_hands_Canister_In
				{
					soundSet="Clean_hands_Canister_In_SoundSet";
					id=3104;
				};
				class Clean_hands_Canister_Out
				{
					soundSet="Clean_hands_Canister_Out_SoundSet";
					id=3105;
				};
			};
			class Attachments
			{
				class SoundShoulderWalk_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkErc_L_LookupTable";
					id=1;
				};
				class SoundShoulderWalk_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkErc_R_LookupTable";
					id=2;
				};
				class SoundShoulderRun_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_runErc_L_LookupTable";
					id=3;
				};
				class SoundShoulderRun_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_runErc_R_LookupTable";
					id=4;
				};
				class SoundShoulderSprint_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_sprintErc_L_LookupTable";
					id=5;
				};
				class SoundShoulderSprint_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_sprintErc_R_LookupTable";
					id=6;
				};
				class SoundShoulderWalk_Cro_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkCro_L_LookupTable";
					id=21;
				};
				class SoundShoulderWalk_Cro_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkCro_R_LookupTable";
					id=22;
				};
				class SoundShoulderRun_Cro_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_runCro_L_LookupTable";
					id=23;
				};
				class SoundShoulderRun_Cro_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_runCro_R_LookupTable";
					id=24;
				};
				class SoundShoulderProne_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkProne_L_LookupTable";
					id=31;
				};
				class SoundShoulderProne_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkProne_R_LookupTable";
					id=32;
				};
				class SoundShoulderProne_Run_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkProne_L_LookupTable";
					id=33;
				};
				class SoundShoulderProne_Run_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkProne_R_LookupTable";
					id=34;
				};
				class SoundShoulderRunJump_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_runErc_L_LookupTable";
					id=35;
				};
				class SoundShoulderRunJump_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_runErc_R_LookupTable";
					id=36;
				};
				class shoulder_landFootErc_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_sprintErc_R_LookupTable";
					id=37;
				};
				class shoulder_landFootErc_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_sprintErc_R_LookupTable";
					id=38;
				};
				class SoundShoulderWalkErcRas_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkErc_L_LookupTable";
					id=51;
				};
				class SoundShoulderWalkErcRas_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_walkErc_R_LookupTable";
					id=52;
				};
				class SoundShoulderRunErcRas_L
				{
					slot="shoulder";
					soundLookupTable="shoulder_runErc_L_LookupTable";
					id=53;
				};
				class SoundShoulderRunErcRas_R
				{
					slot="shoulder";
					soundLookupTable="shoulder_runErc_R_LookupTable";
					id=54;
				};
				class shoulder_landFeetErc
				{
					slot="shoulder";
					soundLookupTable="shoulder_sprintErc_R_LookupTable";
					id=100;
				};
				class SoundBodyWalk_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkErc_LookupTable";
					id=1;
				};
				class SoundBodyWalk_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkErc_LookupTable";
					id=2;
				};
				class SoundBodyRun_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_runErc_LookupTable";
					id=3;
				};
				class SoundBodyRun_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_runErc_LookupTable";
					id=4;
				};
				class SoundBodySprint_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_sprintErc_LookupTable";
					id=5;
				};
				class SoundBodySprint_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_sprintErc_LookupTable";
					id=6;
				};
				class SoundBodyShortmove_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_Shortmove_LookupTable";
					id=7;
				};
				class SoundBodyShortmove_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_Shortmove_LookupTable";
					id=8;
				};
				class SoundBodyLongmove_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_Longmove_LookupTable";
					id=9;
				};
				class SoundBodyLongmove_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_Longmove_LookupTable";
					id=10;
				};
				class SoundBodyWalk_Cro_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkCro_LookupTable";
					id=21;
				};
				class SoundBodyWalk_Cro_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkCro_LookupTable";
					id=22;
				};
				class SoundBodyRun_Cro_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_runCro_LookupTable";
					id=23;
				};
				class SoundBodyRun_Cro_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_runCro_LookupTable";
					id=24;
				};
				class SoundBodyProne_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkProne_LookupTable";
					id=31;
				};
				class SoundBodyProne_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkProne_LookupTable";
					id=32;
				};
				class SoundBodyProne_Run_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_runProne_LookupTable";
					id=33;
				};
				class SoundBodyProne_Run_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_runProne_LookupTable";
					id=34;
				};
				class SoundBodyRunJump_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_jumpErc_LookupTable";
					id=35;
				};
				class SoundBodyRunJump_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_jumpErc_LookupTable";
					id=36;
				};
				class body_landFootErc_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_landFootErc_LookupTable";
					id=37;
				};
				class body_landFootErc_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_landFootErc_LookupTable";
					id=38;
				};
				class SoundBodyAttackLight
				{
					slot="body";
					soundLookupTable="Cloth_Body_attack_light_LookupTable";
					id=41;
				};
				class SoundBodyAttackHeavy
				{
					slot="body";
					soundLookupTable="Cloth_Body_attack_heavy_LookupTable";
					id=42;
				};
				class SoundBodyWalkErcWalk_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkRasErc_LookupTable";
					id=51;
				};
				class SoundBodyWalkErcWalk_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_walkRasErc_LookupTable";
					id=52;
				};
				class SoundBodyRunErcWalk_L
				{
					slot="body";
					soundLookupTable="Cloth_Body_runRasErc_LookupTable";
					id=53;
				};
				class SoundBodyRunErcWalk_R
				{
					slot="body";
					soundLookupTable="Cloth_Body_runRasErc_LookupTable";
					id=54;
				};
				class body_landFeetErc
				{
					slot="body";
					soundLookupTable="Cloth_Body_landFeetErc_LookupTable";
					id=100;
				};
				class SoundBodyShortmove_L_NoFilter
				{
					slot="body";
					soundLookupTable="Cloth_Body_Shortmove_LookupTable";
					id=10007;
				};
				class SoundBodyShortmove_R_NoFilter
				{
					slot="body";
					soundLookupTable="Cloth_Body_Shortmove_LookupTable";
					id=10008;
				};
				class SoundBodyLongmove_L_NoFilter
				{
					slot="body";
					soundLookupTable="Cloth_Body_Longmove_LookupTable";
					id=10009;
				};
				class SoundBodyLongmove_R_NoFilter
				{
					slot="body";
					soundLookupTable="Cloth_Body_Longmove_LookupTable";
					id=10010;
				};
				class Cloth_Body_Freezing
				{
					slot="body";
					soundLookupTable="Cloth_Body_Freezing_LookupTable";
					id=10200;
				};
				class Cloth_Body_Freezing_2hd_Erc
				{
					slot="body";
					soundLookupTable="Cloth_Body_Freezing_2hd_Erc_LookupTable";
					id=10201;
				};
				class SoundbackWalk_L
				{
					slot="back";
					soundLookupTable="Cloth_back_walkErc_LookupTable";
					id=1;
				};
				class SoundbackWalk_R
				{
					slot="back";
					soundLookupTable="Cloth_back_walkErc_LookupTable";
					id=2;
				};
				class SoundbackRun_L
				{
					slot="back";
					soundLookupTable="Cloth_back_runErc_LookupTable";
					id=3;
				};
				class SoundbackRun_R
				{
					slot="back";
					soundLookupTable="Cloth_back_runErc_LookupTable";
					id=4;
				};
				class SoundbackSprint_L
				{
					slot="back";
					soundLookupTable="Cloth_back_sprintErc_LookupTable";
					id=5;
				};
				class SoundbackSprint_R
				{
					slot="back";
					soundLookupTable="Cloth_back_sprintErc_LookupTable";
					id=6;
				};
				class SoundbackShorrtmove_L
				{
					slot="back";
					soundLookupTable="Cloth_back_Shortmove_LookupTable";
					id=7;
				};
				class SoundbackShortmove_R
				{
					slot="back";
					soundLookupTable="Cloth_back_Shortmove_LookupTable";
					id=8;
				};
				class SoundbackLongmove_L
				{
					slot="back";
					soundLookupTable="Cloth_back_Longmove_LookupTable";
					id=9;
				};
				class SoundbackLongmove_R
				{
					slot="back";
					soundLookupTable="Cloth_back_Longmove_LookupTable";
					id=10;
				};
				class SoundbackWalk_Cro_L
				{
					slot="back";
					soundLookupTable="Cloth_back_walkCro_LookupTable";
					id=21;
				};
				class SoundbackWalk_Cro_R
				{
					slot="back";
					soundLookupTable="Cloth_back_walkCro_LookupTable";
					id=22;
				};
				class SoundbackRun_Cro_L
				{
					slot="back";
					soundLookupTable="Cloth_back_runCro_LookupTable";
					id=23;
				};
				class SoundbackRun_Cro_R
				{
					slot="back";
					soundLookupTable="Cloth_back_runCro_LookupTable";
					id=24;
				};
				class SoundbackProne_L
				{
					slot="back";
					soundLookupTable="Cloth_back_walkProne_LookupTable";
					id=31;
				};
				class SoundbackProne_R
				{
					slot="back";
					soundLookupTable="Cloth_back_walkProne_LookupTable";
					id=32;
				};
				class SoundbackProne_Run_L
				{
					slot="back";
					soundLookupTable="Cloth_back_runProne_LookupTable";
					id=33;
				};
				class SoundbackProne_Run_R
				{
					slot="back";
					soundLookupTable="Cloth_back_runProne_LookupTable";
					id=34;
				};
				class SoundbackRunJump_L
				{
					slot="back";
					soundLookupTable="Cloth_back_jumpErc_LookupTable";
					id=35;
				};
				class SoundbackRunJump_R
				{
					slot="back";
					soundLookupTable="Cloth_back_jumpErc_LookupTable";
					id=36;
				};
				class back_landFootErc_L
				{
					slot="back";
					soundLookupTable="Cloth_back_landFootErc_LookupTable";
					id=37;
				};
				class back_landFootErc_R
				{
					slot="back";
					soundLookupTable="Cloth_back_landFootErc_LookupTable";
					id=38;
				};
				class SoundbackAttackLight
				{
					slot="back";
					soundLookupTable="Cloth_back_attack_light_LookupTable";
					id=41;
				};
				class SoundbackAttackHeavy
				{
					slot="back";
					soundLookupTable="Cloth_back_attack_heavy_LookupTable";
					id=42;
				};
				class SoundbackWalkErcWalk_L
				{
					slot="back";
					soundLookupTable="Cloth_back_walkRasErc_LookupTable";
					id=51;
				};
				class SoundbackWalkErcWalk_R
				{
					slot="back";
					soundLookupTable="Cloth_back_walkRasErc_LookupTable";
					id=52;
				};
				class SoundbackRunErcWalk_L
				{
					slot="back";
					soundLookupTable="Cloth_back_runRasErc_LookupTable";
					id=53;
				};
				class SoundbackRunErcWalk_R
				{
					slot="back";
					soundLookupTable="Cloth_back_runRasErc_LookupTable";
					id=54;
				};
				class back_landFeetErc
				{
					slot="back";
					soundLookupTable="Cloth_back_landFeetErc_LookupTable";
					id=100;
				};
			};
			class SoundVoiceEvent
			{
				noise="NoiseStepStand";
			};
			class SoundVoice
			{
				class staminaDownLight: SoundVoiceEvent
				{
					soundLookupTable="staminaDownLight_SoundVoice_Char_LookupTable";
					id=1;
				};
				class staminaDownHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="staminaDownHeavy_SoundVoice_Char_LookupTable";
					id=2;
				};
				class staminaUpHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="staminaUpHeavy_SoundVoice_Char_LookupTable";
					id=3;
				};
				class staminaUpLight_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="staminaUpLight_SoundVoice_Char_LookupTable";
					id=4;
				};
				class gaspingForAirEmpty_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="gaspingForAirEmpty_SoundVoice_Char_LookupTable";
					id=31;
				};
				class gaspingForAir5perIdle_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="gaspingForAir5perIdle_SoundVoice_Char_LookupTable";
					id=32;
				};
				class gaspingForAir10perIdle_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="gaspingForAir10perIdle_SoundVoice_Char_LookupTable";
					id=33;
				};
				class cough_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="cough_SoundVoice_Char_LookupTable";
					id=8;
				};
				class sneez_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="sneez_SoundVoice_Char_LookupTable";
					id=9;
				};
				class laugh_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="laugh_SoundVoice_Char_LookupTable";
					id=10;
				};
				class freezing_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="freezing_SoundVoice_Char_LookupTable";
					id=11;
				};
				class takingDamageLight_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="takingDamageLight_SoundVoice_Char_LookupTable";
					id=12;
				};
				class takingDamageHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="takingDamageHeavy_SoundVoice_Char_LookupTable";
					id=13;
				};
				class meleeAttackLight_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="meleeAttack_SoundVoice_Char_LookupTable";
					id=16;
				};
				class meleeAttackHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="meleeAttackHeavy_SoundVoice_Char_LookupTable";
					id=17;
				};
				class jump_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="jump_SoundVoice_Char_LookupTable";
					id=18;
				};
				class pickUpHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="pickUpHeavy_SoundVoice_Char_LookupTable";
					id=19;
				};
				class holdBreath_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="holdBreath_SoundVoice_Char_LookupTable";
					id=20;
				};
				class releaseBreath_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="releaseBreath_SoundVoice_Char_LookupTable";
					id=21;
				};
				class exhaustedBreath_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="exhaustedBreath_SoundVoice_Char_LookupTable";
					id=22;
				};
				class vomit_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="vomit_SoundVoice_Char_LookupTable";
					id=23;
				};
				class vomitShort_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="vomitShort_SoundVoice_Char_LookupTable";
					id=23333;
				};
				class blow_fireplace_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="blow_fireplace_SoundVoice_Char_LookupTable";
					id=24;
				};
				class inhale_fireplace_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="inhale_fireplace_SoundVoice_Char_LookupTable";
					id=25;
				};
				class staminaUpEnd_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="staminaUpEnd_SoundVoice_Char_LookupTable";
					id=26;
				};
				class generalgrunt_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="generalgrunt_SoundVoice_Char_LookupTable";
					id=27;
				};
				class pain_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="pain_SoundVoice_Char_LookupTable";
					id=28;
				};
				class hot_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="hot_SoundVoice_Char_LookupTable";
					id=30;
				};
				class drinking: SoundVoiceEvent
				{
					soundLookupTable="drinking_SoundVoice_Char_LookupTable";
					id=200;
				};
				class takeASip_sip: SoundVoiceEvent
				{
					soundLookupTable="takeASip_sip_SoundVoice_Char_LookupTable";
					id=201;
				};
				class takeASip_swallow: SoundVoiceEvent
				{
					soundLookupTable="takeASip_swallow_SoundVoice_Char_LookupTable";
					id=202;
				};
				class welldrinking: SoundVoiceEvent
				{
					soundLookupTable="welldrinking_SoundVoice_Char_LookupTable";
					id=203;
				};
				class riverdrinking: SoundVoiceEvent
				{
					soundLookupTable="riverdrinking_SoundVoice_Char_LookupTable";
					id=204;
				};
				class eating: SoundVoiceEvent
				{
					soundLookupTable="eating_SoundVoice_Char_LookupTable";
					id=888;
				};
				class eating_fruit: SoundVoiceEvent
				{
					soundLookupTable="eating_fruit_SoundVoice_Char_LookupTable";
					id=889;
				};
				class eating_boxfood: SoundVoiceEvent
				{
					soundLookupTable="eating_boxfood_SoundVoice_Char_LookupTable";
					id=890;
				};
				class eating_tablets: SoundVoiceEvent
				{
					soundLookupTable="eating_tablets_SoundVoice_Char_LookupTable";
					id=891;
				};
				class drowning: SoundVoiceEvent
				{
					soundLookupTable="Drowning_SoundVoice_Char_LookupTable";
					id=900;
				};
				class underwater_breath_hold: SoundVoiceEvent
				{
					soundLookupTable="UnderwaterBreathHold_SoundVoice_Char_LookupTable";
					id=901;
				};
				class thirsty_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="Thirst_SoundVoice_Char_LookupTable";
					id=902;
				};
				class pushHeavy_SoundVoice: SoundVoiceEvent
				{
					soundLookupTable="pushHeavy_SoundVoice_Char_LookupTable";
					id=903;
				};
			};
			class SoundWeapon
			{
				class swim_run
				{
					soundset="swim_run_Char_Soundset";
					id=71;
				};
				class swim_sprint
				{
					soundset="swim_sprint_Char_Soundset";
					id=72;
				};
				class CPR
				{
					soundset="CPR_Soundset";
					id=73;
				};
				class pickUpItem_Light
				{
					soundSet="pickUpItem_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpItem_SoundSet";
					id=797;
				};
				class pickUpRifleLight
				{
					soundSet="pickUpRifleLight_SoundSet";
					id=798;
				};
				class Attack_1hdDefault_Light1
				{
					soundSet="Char_Attack_unarmed_light1_SoundSet";
					id=801;
				};
				class Attack_1hdDefault_Light2
				{
					soundSet="Char_Attack_unarmed_light2_SoundSet";
					id=802;
				};
				class Attack_1hdDefault_Heavy1
				{
					soundSet="Char_Attack_unarmed_heavy1_SoundSet";
					id=803;
				};
				class Attack_1hdDefault_Heavy2
				{
					soundSet="Char_Attack_unarmed_heavy2_SoundSet";
					id=804;
				};
				class Attack_knife_Light1
				{
					soundSet="Char_Attack_knife_light1_SoundSet";
					id=806;
				};
				class Attack_knife_Light2
				{
					soundSet="Char_Attack_knife_light2_SoundSet";
					id=807;
				};
				class Attack_knife_Heavy1
				{
					soundSet="Char_Attack_knife_heavy1_SoundSet";
					id=808;
				};
				class Attack_knife_Heavy2
				{
					soundSet="Char_Attack_knife_heavy2_SoundSet";
					id=809;
				};
				class Attack_knife_StealthPt1
				{
					soundSet="Char_Attack_knife_StealthPt1_SoundSet";
					id=14000;
				};
				class Attack_knife_StealthPt2
				{
					soundSet="Char_Attack_knife_StealthPt2_SoundSet";
					id=14001;
				};
				class Attack_knife_StealthNeckPt3
				{
					soundSet="Char_Attack_knife_StealthPt3_SoundSet";
					id=14006;
				};
				class Attack_knife_StealthPt3
				{
					soundSet="Char_Attack_knife_StealthPt3_SoundSet";
					id=14002;
				};
				class Attack_knife_StealthPt4
				{
					soundSet="Char_Attack_knife_StealthPt4_SoundSet";
					id=14003;
				};
				class Attack_pipemetal_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=811;
				};
				class Attack_pipemetal_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=812;
				};
				class Attack_pipemetal_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=813;
				};
				class Attack_pipemetal_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=814;
				};
				class Attack_2hddefault_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=16;
				};
				class Attack_2hddefault_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=17;
				};
				class Attack_2hddefault_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=18;
				};
				class Attack_2hddefault_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=19;
				};
				class Attack_2hdlight_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=21;
				};
				class Attack_2hdlight_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=22;
				};
				class Attack_2hdlight_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=23;
				};
				class Attack_2hdlight_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=24;
				};
				class Attack_bat_Light1
				{
					soundSet="Char_Attack_fireaxe_light1_SoundSet";
					id=826;
				};
				class Attack_bat_Light2
				{
					soundSet="Char_Attack_fireaxe_light2_SoundSet";
					id=827;
				};
				class Attack_bat_Heavy1
				{
					soundSet="Char_Attack_fireaxe_heavy1_SoundSet";
					id=828;
				};
				class Attack_bat_Heavy2
				{
					soundSet="Char_Attack_fireaxe_heavy2_SoundSet";
					id=829;
				};
				class Attack_fireaxe_Light1
				{
					soundSet="Char_Attack_fireaxe_light1_SoundSet";
					id=831;
				};
				class Attack_fireaxe_Light2
				{
					soundSet="Char_Attack_fireaxe_light2_SoundSet";
					id=832;
				};
				class Attack_fireaxe_Heavy1
				{
					soundSet="Char_Attack_fireaxe_heavy1_SoundSet";
					id=833;
				};
				class Attack_fireaxe_Heavy2
				{
					soundSet="Char_Attack_fireaxe_heavy2_SoundSet";
					id=834;
				};
				class Attack_extinguisher_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=836;
				};
				class Attack_extinguisher_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=837;
				};
				class Attack_extinguisher_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=838;
				};
				class Attack_extinguisher_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=839;
				};
				class Attack_pistol_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=841;
				};
				class Attack_pistol_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=842;
				};
				class Attack_pistol_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=843;
				};
				class Attack_pistol_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=844;
				};
				class Attack_rifle_Light1
				{
					soundSet="Char_Attack_pipemetal_light1_SoundSet";
					id=846;
				};
				class Attack_rifle_Light2
				{
					soundSet="Char_Attack_pipemetal_light2_SoundSet";
					id=847;
				};
				class Attack_rifle_Heavy1
				{
					soundSet="Char_Attack_pipemetal_heavy1_SoundSet";
					id=848;
				};
				class Attack_rifle_Heavy2
				{
					soundSet="Char_Attack_pipemetal_heavy2_SoundSet";
					id=849;
				};
				class Attack_unarmed_Light1
				{
					soundSet="Char_Attack_unarmed_light1_SoundSet";
					id=851;
				};
				class Attack_unarmed_Light2
				{
					soundSet="Char_Attack_unarmed_light2_SoundSet";
					id=852;
				};
				class Attack_unarmed_Heavy1
				{
					soundSet="Char_Attack_unarmed_heavy1_SoundSet";
					id=853;
				};
				class Attack_unarmed_Heavy2
				{
					soundSet="Char_Attack_unarmed_heavy2_SoundSet";
					id=854;
				};
				class Attack_spear_Light1
				{
					soundSet="Char_Attack_spear_light1_SoundSet";
					id=15000;
				};
				class Attack_spear_Light2
				{
					soundSet="Char_Attack_spear_light2_SoundSet";
					id=15001;
				};
				class Attack_spear_Heavy1
				{
					soundSet="Char_Attack_spear_light1_SoundSet";
					id=15002;
				};
				class Attack_spear_Heavy2
				{
					soundSet="Char_Attack_spear_light2_SoundSet";
					id=15003;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Char_Gestures_Hand_Clap_Head
				{
					soundset="Char_Gestures_Hand_Clap_Head_SoundSet";
					id=891;
				};
				class Char_Gestures_Hand_Grab_Fabric
				{
					soundset="Char_Gestures_Hand_Grab_Fabric_SoundSet";
					id=892;
				};
				class pickUpRifle
				{
					soundset="pickUpRifle_SoundSet";
					id=893;
				};
				class vomit_Char
				{
					soundset="vomit_Char_SoundSet";
					id=897;
				};
				class Crafting
				{
					soundLookupTable="Craft_LookupTable";
					id=901;
				};
				class turnOnRadio
				{
					soundSet="turnOnRadio_SoundSet";
					id=1006;
				};
				class turnOffRadio
				{
					soundSet="turnOffRadio_SoundSet";
					id=1007;
				};
				class ShoulderL_Hide_Rifle
				{
					soundset="ShoulderL_Hide_Rifle_SoundSet";
					id=1200;
				};
				class ShoulderL_Show_Rifle
				{
					soundset="ShoulderL_Show_Rifle_SoundSet";
					id=1201;
				};
				class ShoulderR_Hide
				{
					soundset="ShoulderR_Hide_SoundSet";
					id=1210;
				};
				class ShoulderR_Show
				{
					soundset="ShoulderR_Show_SoundSet";
					id=1211;
				};
				class Inventory_Hide
				{
					soundset="Inventory_Hide_SoundSet";
					id=1220;
				};
				class Inventory_Show
				{
					soundset="Inventory_Show_SoundSet";
					id=1221;
				};
				class Chest_Pistol_Hide
				{
					soundset="Chest_Pistol_Hide_SoundSet";
					id=1222;
				};
				class Chest_Pistol_Show
				{
					soundset="Chest_Pistol_Show_SoundSet";
					id=1223;
				};
				class Back_Knife_Hide
				{
					soundset="Back_Knife_Hide_SoundSet";
					id=1224;
				};
				class Back_Knife_Show
				{
					soundset="Back_Knife_Show_SoundSet";
					id=1225;
				};
				class rope_tieup
				{
					soundSet="rope_tieup_SoundSet";
					id=13338;
				};
				class rope_tieup_end
				{
					soundSet="rope_tieup_end_SoundSet";
					id=13339;
				};
				class rope_tieup_back
				{
					soundSet="rope_tieup_back_SoundSet";
					id=13340;
				};
				class HackSaw_loop
				{
					soundSet="HackSaw_loop_SoundSet";
					id=1123;
				};
				class HackSaw_end
				{
					soundSet="HackSaw_end_SoundSet";
					id=1124;
				};
			};
		};
	};
	class BanditAI_Base: InfectedBanditBase
	{
		scope=0;
		model="AI_Bandits\models\Bandit.p3d";
		attachments[]=
		{
			"BanditHead",
			"BanditBody",
			"BanditLegs",
			"BanditHands",
			"BanditFeet",
			"Headgear",
			"Mask",
			"Eyewear",
			"LeftHand",
			"Gloves",
			"Armband",
			"Vest",
			"Body",
			"Back",
			"Hips",
			"Legs",
			"Feet",
			"Splint_Right"
		};
		hiddenSelections[]=
		{
			"beard",
			"hair",
			"personality"
		};
		simpleHiddenSelections[]=
		{
			"slot_melee_rifle",
			"slot_melee_melee",
			"slot_shoulder_rifle",
			"slot_shoulder_melee"
		};
		class InventoryEquipment
		{
			playerSlots[]=
			{
				"Slot_Vest",
				"Slot_Body",
				"Slot_Hips",
				"Slot_Legs",
				"Slot_Back",
				"Slot_Headgear",
				"Slot_Mask",
				"Slot_Eyewear",
				"Slot_Gloves",
				"Slot_Feet",
				"Slot_Armband"
			};
		};
		class GUIInventoryAttachmentsProps
		{
			class Body
			{
				attachmentSlots[]=
				{
					"Headgear",
					"Mask",
					"Eyewear",
					"Gloves",
					"Armband",
					"Vest",
					"Body",
					"Back",
					"Hips",
					"Legs",
					"Feet"
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
			class DamageZones
			{
				class Head
				{
					class Health
					{
						hitpoints=30;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Projectile
						{
							class Health
							{
								damage=1.5;
							};
						};
						class Melee
						{
							class Health
							{
								damage=0.69999999;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=3;
							};
						};
					};
					componentNames[]=
					{
						"Head",
						"Neck"
					};
					fatalInjuryCoef=0.1;
					inventorySlots[]=
					{
						"Headgear",
						"Mask"
					};
				};
				class Torso
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=1;
					};
					class ArmorType
					{
						class Melee
						{
							class Health
							{
								damage=1.2;
							};
						};
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"Spine1",
						"Spine3"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
				};
				class LeftArm: Torso
				{
					componentNames[]=
					{
						"LeftArm",
						"LeftForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class RightArm: LeftArm
				{
					componentNames[]=
					{
						"RightArm",
						"RightForeArm"
					};
					inventorySlots[]=
					{
						"Vest",
						"Body",
						"Back"
					};
					inventorySlotsCoefs[]={1,1,1};
					fatalInjuryCoef=-1;
				};
				class LeftLeg
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.33000001;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					componentNames[]=
					{
						"LeftLeg",
						"LeftUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class RightLeg: LeftLeg
				{
					componentNames[]=
					{
						"RightLeg",
						"RightUpLeg"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Legs"
					};
				};
				class LeftFoot
				{
					class Health
					{
						hitpoints=100;
						transferToGlobalCoef=0.1;
					};
					class ArmorType
					{
						class FragGrenade
						{
							class Health
							{
								damage=2;
							};
						};
					};
					transferToZonesNames[]=
					{
						"LeftLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"LeftFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
				class RightFoot: LeftFoot
				{
					transferToZonesNames[]=
					{
						"RightLeg"
					};
					transferToZonesCoefs[]={0.1};
					componentNames[]=
					{
						"RightFoot"
					};
					fatalInjuryCoef=-1;
					inventorySlots[]=
					{
						"Feet"
					};
				};
			};
		};
		class Skinning
		{
			class ObtainedGuts
			{
				item="SmallGuts";
				count=0;
				quantityMinMaxCoef[]={0.5,0.80000001};
			};
			class ObtainedSteaks
			{
				item="HumanSteakMeat";
				count=2;
				quantityMinMaxCoef[]={0.5,1};
			};
			class ObtainedBones
			{
				item="Bone";
				count=1;
				quantityMinMaxCoef[]={0.2,0.30000001};
				transferToolDamageCoef=1;
			};
		};
	};
	class BanditAI_MaleBase: BanditAI_Base
	{
		scope=0;
		woman=0;
		clothingType="male";
	};
	class BanditAI_FemaleBase: BanditAI_Base
	{
		scope=0;
		woman=1;
		clothingType="female";
	};
	class BanditBody_Base: Clothing
	{
		scope=1;
		displayName="Bandit Body";
		model="SimpleSurvivors\bandits\proxies\Cube_G.p3d";
		inventorySlot[]=
		{
			"BanditBody"
		};
		hiddenSelections[]=
		{
			"personality"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"
		};
		class ClothingTypes
		{
			male="DZ\characters\tops\torso3_m.p3d";
			female="DZ\characters\tops\torso3_f.p3d";
		};
	};
	class BanditFeet_Base: Clothing
	{
		scope=1;
		displayName="Bandit Feet";
		model="SimpleSurvivors\bandits\proxies\Cube_G.p3d";
		inventorySlot[]=
		{
			"BanditFeet"
		};
		hiddenSelections[]=
		{
			"personality"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"
		};
		hiddenSelectionsMaterials[]=
		{
			"DZ\characters\heads\data\hhl_dummy_skin_material.rvmat"
		};
		class ClothingTypes
		{
			male="DZ\characters\shoes\feet3_m.p3d";
			female="DZ\characters\shoes\feet3_m.p3d";
		};
	};
	class BanditHands_Base: Clothing
	{
		scope=1;
		displayName="Bare hands";
		model="SimpleSurvivors\bandits\proxies\Cube_G.p3d";
		inventorySlot[]=
		{
			"BanditHands"
		};
		hiddenSelections[]=
		{
			"personality"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\hhl_dummy_skin_material.rvmat"
		};
		class ClothingTypes
		{
			male="DZ\characters\gloves\hands3_m.p3d";
			female="DZ\characters\gloves\hands3_f.p3d";
		};
	};
	class BanditLegs_Base: Clothing
	{
		scope=1;
		displayName="Bandit Legs";
		model="SimpleSurvivors\bandits\proxies\Cube_G.p3d";
		inventorySlot[]=
		{
			"BanditLegs"
		};
		hiddenSelections[]=
		{
			"personality"
		};
		hiddenSelectionsTextures[]=
		{
			"#(argb,8,8,3)color(0.843137,0.768627,0.658824,1.0,CO)"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\hhl_dummy_skin_material.rvmat"
		};
		class ClothingTypes
		{
			male="DZ\characters\pants\legs3_m.p3d";
			female="DZ\characters\pants\legs3_f.p3d";
		};
	};
	class BanditHead_Base: Inventory_Base
	{
		scope=1;
		displayName="Bandit Head";
		descriptionShort="Base class for AI bandit heads";
		model="\dz\characters\heads\m_adam.p3d";
		simulation="head";
		inventorySlot[]=
		{
			"BanditHead"
		};
		hiddenSelections[]=
		{
			"beard",
			"hair",
			"personality"
		};
		simpleHiddenSelections[]=
		{
			"beard",
			"hair",
			"Clipping_GhillieHood",
			"Clipping_grathelm",
			"Clipping_ConstructionHelmet",
			"Clipping_Hockey_hekmet",
			"Clipping_Maska",
			"Clipping_ProtecSkateHelmet2",
			"Clipping_BandanaFace",
			"Clipping_NioshFaceMask",
			"Clipping_NBC_Hood",
			"Clipping_MotoHelmet",
			"Clipping_FireHelmet",
			"Clipping_ushanka",
			"Clipping_TankerHelmet",
			"Clipping_SantasBeard",
			"Clipping_Surgical_mask",
			"Clipping_PumpkinHelmet",
			"Clipping_Balaclava_3holes",
			"Clipping_Balaclava",
			"Clipping_GP5GasMask",
			"Clipping_AirborneMask",
			"Clipping_BoonieHat",
			"Clipping_prison_cap",
			"Clipping_MilitaryBeret_xx",
			"Clipping_Policecap",
			"Clipping_OfficerHat",
			"Clipping_Hat_leather",
			"Clipping_CowboyHat",
			"Clipping_BandanaHead",
			"Clipping_SantasHat",
			"Clipping_FlatCap",
			"Clipping_MxHelmet",
			"Clipping_baseballcap",
			"Clipping_BeanieHat",
			"Clipping_MedicalScrubs_Hat",
			"Clipping_RadarCap",
			"Clipping_ZmijovkaCap",
			"Clipping_HeadTorch",
			"Clipping_pilotka",
			"Clipping_HeloHelmet",
			"Clipping_HelmetMich",
			"Clipping_Ssh68Helmet",
			"Clipping_Mich2001",
			"Clipping_Welding_Mask",
			"Clipping_VintageHockeyMask",
			"Clipping_mouth_rags",
			"Clipping_Gasmask",
			"Clipping_WitchHood",
			"Clipping_WitchHat",
			"Clipping_NVGHeadstrap",
			"Clipping_headCover_improvised",
			"Clipping_BurlapSack"
		};
	};
	class BanditHead_Adam: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_adam.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_adam\hhl_m_adam_beard_ca.paa",
			"dz\characters\heads\data\m_adam\hhl_m_adam_hair_ca.paa",
			"dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_adam\hhl_m_adam_beard.rvmat",
			"dz\characters\heads\data\m_adam\hhl_m_adam_hair.rvmat",
			"dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded.rvmat"
		};
	};
	class BanditHead_Boris: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_boris.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_boris\hhl_m_boris_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_boris\hhl_m_boris_beard.rvmat",
			"",
			"dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded.rvmat"
		};
	};
	class BanditHead_Cyril: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_cyril.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_beard.rvmat",
			"",
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded.rvmat"
		};
	};
	class BanditHead_Denis: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_denis_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Denis_2\hhl_m_Denis_body_bearded.rvmat"
		};
	};
	class BanditHead_Elias: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_elias.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_bearded.rvmat"
		};
	};
	class BanditHead_Francis: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_francis.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_bearded.rvmat"
		};
	};
	class BanditHead_Guo: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_guo.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_bearded.rvmat"
		};
	};
	class BanditHead_Hassan: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_hassan.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_bearded.rvmat"
		};
	};
	class BanditHead_Indar: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_indar.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_bearded.rvmat"
		};
	};
	class BanditHead_Jose: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_jose.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_bearded.rvmat"
		};
	};
	class BanditHead_Kaito: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_kaito.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_bearded.rvmat"
		};
	};
	class BanditHead_Lewis: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Lewis.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_beard_ca.paa",
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_hair_ca.paa",
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_beard.rvmat",
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_hair.rvmat",
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded.rvmat"
		};
	};
	class BanditHead_Manua: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Manua.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_beard_ca.paa",
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_hair_ca.paa",
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_beard.rvmat",
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_hair.rvmat",
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded.rvmat"
		};
	};
	class BanditHead_Niki: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Niki_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_beard_ca.paa",
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_hair_ca.paa",
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_beard.rvmat",
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_hair.rvmat",
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded.rvmat"
		};
	};
	class BanditHead_Oliver: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Oliver.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_beard_ca.paa",
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_hair_ca.paa",
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_beard.rvmat",
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_hair.rvmat",
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded.rvmat"
		};
	};
	class BanditHead_Peter: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Peter.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_beard_ca.paa",
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_hair_ca.paa",
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_beard.rvmat",
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_hair.rvmat",
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_bearded.rvmat"
		};
	};
	class BanditHead_Quinn: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Quinn.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_beard_ca.paa",
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_hair_ca.paa",
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_beard.rvmat",
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_hair.rvmat",
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded.rvmat"
		};
	};
	class BanditHead_Rolf: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Rolf.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_beard_ca.paa",
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_hair_ca.paa",
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_beard.rvmat",
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_hair.rvmat",
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded.rvmat"
		};
	};
	class BanditHead_Seth: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Seth.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_beard_ca.paa",
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_hair_ca.paa",
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_beard.rvmat",
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_hair.rvmat",
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded.rvmat"
		};
	};
	class BanditHead_Taiki: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\m_Taiki.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_beard_ca.paa",
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_hair_ca.paa",
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_beard.rvmat",
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_hair.rvmat",
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded.rvmat"
		};
	};
	class BanditHead_Eva: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Eva_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_hair_ca.paa",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_hair.rvmat",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat"
		};
	};
	class BanditHead_Frida: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Frida_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_hair_ca.paa",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_hair.rvmat",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body.rvmat"
		};
	};
	class BanditHead_Gabi: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Gabi_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_hair_ca.paa",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_hair.rvmat",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat"
		};
	};
	class BanditHead_Helga: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Helga.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_hair_ca.paa",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_hair.rvmat",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat"
		};
	};
	class BanditHead_Irena: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Irena_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_hair_ca.paa",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_hair.rvmat",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat"
		};
	};
	class BanditHead_Judy: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Judy.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_hair_ca.paa",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_hair.rvmat",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat"
		};
	};
	class BanditHead_Keiko: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Keiko.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_hair_ca.paa",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_hair.rvmat",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat"
		};
	};
	class BanditHead_Linda: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Linda_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_hair_ca.paa",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_hair.rvmat",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat"
		};
	};
	class BanditHead_Maria: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Maria_2.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_hair_ca.paa",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_hair.rvmat",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat"
		};
	};
	class BanditHead_Naomi: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Naomi.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_hair_ca.paa",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_hair.rvmat",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat"
		};
	};
	class BanditHead_Baty: BanditHead_Base
	{
		scope=1;
		model="dz\characters\heads\f_Baty.p3d";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_baty\hhl_f_baty_hair_ca.paa",
			"dz\characters\heads\data\f_baty\hhl_f_baty_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_baty\hhl_f_baty_hair.rvmat",
			"dz\characters\heads\data\f_baty\hhl_f_baty_body.rvmat"
		};
	};
	class BanditAI_Adam: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Adam";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_adam\hhl_m_adam_beard_ca.paa",
			"dz\characters\heads\data\m_adam\hhl_m_adam_hair_ca.paa",
			"dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_adam\hhl_m_adam_beard.rvmat",
			"dz\characters\heads\data\m_adam\hhl_m_adam_hair.rvmat",
			"dz\characters\heads\data\m_adam\hhl_m_adam_body_bearded.rvmat"
		};
	};
	class BanditAI_Boris: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Boris";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_boris\hhl_m_boris_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_boris\hhl_m_boris_beard.rvmat",
			"",
			"dz\characters\heads\data\m_boris\hhl_m_boris_body_bearded.rvmat"
		};
	};
	class BanditAI_Cyril: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Cyril";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_beard.rvmat",
			"",
			"dz\characters\heads\data\m_cyril\hhl_m_cyril_body_bearded.rvmat"
		};
	};
	class BanditAI_Denis: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Denis";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Denis_2\hhl_m_denis_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Denis_2\hhl_m_denis_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Denis_2\hhl_m_denis_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Denis_2\hhl_m_denis_body_bearded.rvmat"
		};
	};
	class BanditAI_Elias: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Elias";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Elias\hhl_m_Elias_body_bearded.rvmat"
		};
	};
	class BanditAI_Francis: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Francis";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Francis\hhl_m_Francis_body_bearded.rvmat"
		};
	};
	class BanditAI_Guo: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Guo";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Guo\hhl_m_Guo_body_bearded.rvmat"
		};
	};
	class BanditAI_Hassan: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Hassan";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Hassan\hhl_m_Hassan_body_bearded.rvmat"
		};
	};
	class BanditAI_Indar: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Indar";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Indar\hhl_m_Indar_body_bearded.rvmat"
		};
	};
	class BanditAI_Jose: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Jose";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Jose\hhl_m_Jose_body_bearded.rvmat"
		};
	};
	class BanditAI_Kaito: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Kaito";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Kaito\hhl_m_Kaito_body_bearded.rvmat"
		};
	};
	class BanditAI_Lewis: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Lewis";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Lewis\hhl_m_Lewis_body_bearded.rvmat"
		};
	};
	class BanditAI_Manua: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Manua";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Manua\hhl_m_Manua_body_bearded.rvmat"
		};
	};
	class BanditAI_Niki: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Niki";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Niki_2\hhl_m_Niki_body_bearded.rvmat"
		};
	};
	class BanditAI_Oliver: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Oliver";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Oliver\hhl_m_Oliver_body_bearded.rvmat"
		};
	};
	class BanditAI_Peter: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Peter";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Peter\hhl_m_Peter_body_bearded.rvmat"
		};
	};
	class BanditAI_Quinn: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Quinn";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Quinn\hhl_m_Quinn_body_bearded.rvmat"
		};
	};
	class BanditAI_Rolf: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Rolf";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Rolf\hhl_m_Rolf_body_bearded.rvmat"
		};
	};
	class BanditAI_Seth: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Seth";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Seth\hhl_m_Seth_body_bearded.rvmat"
		};
	};
	class BanditAI_Taiki: BanditAI_MaleBase
	{
		scope=2;
		head="BanditHead_Taiki";
		hiddenSelectionsTextures[]=
		{
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_beard_ca.paa",
			"",
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_beard.rvmat",
			"",
			"dz\characters\heads\data\m_Taiki\hhl_m_Taiki_body_bearded.rvmat"
		};
	};
	class BanditAI_Eva: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Eva";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_hair_ca.paa",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_hair.rvmat",
			"dz\characters\heads\data\f_Eva_2\hhl_f_Eva_body.rvmat"
		};
	};
	class BanditAI_Frida: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Frida";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_hair_ca.paa",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_hair.rvmat",
			"dz\characters\heads\data\f_Frida_2\hhl_f_Frida_body.rvmat"
		};
	};
	class BanditAI_Gabi: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Gabi";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_hair_ca.paa",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_hair.rvmat",
			"dz\characters\heads\data\f_Gabi_2\hhl_f_Gabi_body.rvmat"
		};
	};
	class BanditAI_Helga: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Helga";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_hair_ca.paa",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_hair.rvmat",
			"dz\characters\heads\data\f_Helga\hhl_f_Helga_body.rvmat"
		};
	};
	class BanditAI_Irena: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Irena";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_hair_ca.paa",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_hair.rvmat",
			"dz\characters\heads\data\f_Irena_2\hhl_f_Irena_body.rvmat"
		};
	};
	class BanditAI_Judy: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Judy";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_hair_ca.paa",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_hair.rvmat",
			"dz\characters\heads\data\f_Judy\hhl_f_Judy_body.rvmat"
		};
	};
	class BanditAI_Keiko: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Keiko";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_hair_ca.paa",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_hair.rvmat",
			"dz\characters\heads\data\f_Keiko\hhl_f_Keiko_body.rvmat"
		};
	};
	class BanditAI_Linda: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Linda";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_hair_ca.paa",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_hair.rvmat",
			"dz\characters\heads\data\f_Linda_2\hhl_f_Linda_body.rvmat"
		};
	};
	class BanditAI_Maria: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Maria";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_hair_ca.paa",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_hair.rvmat",
			"dz\characters\heads\data\f_Maria_2\hhl_f_Maria_body.rvmat"
		};
	};
	class BanditAI_Naomi: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Naomi";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_hair_ca.paa",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_hair.rvmat",
			"dz\characters\heads\data\f_Naomi\hhl_f_Naomi_body.rvmat"
		};
	};
	class BanditAI_Baty: BanditAI_FemaleBase
	{
		scope=2;
		head="BanditHead_Baty";
		hiddenSelectionsTextures[]=
		{
			"",
			"dz\characters\heads\data\f_baty\hhl_f_baty_hair_ca.paa",
			"dz\characters\heads\data\f_baty\hhl_f_baty_body_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"dz\characters\heads\data\f_baty\hhl_f_baty_hair.rvmat",
			"dz\characters\heads\data\f_baty\hhl_f_baty_body.rvmat"
		};
	};
	class Bandit_Heather_Blonde: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\heather.p3d";
		hiddenSelections[]=
		{
			"vlasy"
		};
		hiddenSelectionsTextures[]=
		{
			"AI_Bandits\models\data\heather\T_Player_Heather_Hair_blonde.paa"
		};
	};
	class Bandit_Heather_LightRed: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\heather.p3d";
		hiddenSelections[]=
		{
			"vlasy"
		};
		hiddenSelectionsTextures[]=
		{
			"AI_Bandits\models\data\heather\T_Player_Heather_Hair_lightred.paa"
		};
	};
	class Bandit_Heather_Brunette: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\heather.p3d";
		hiddenSelections[]=
		{
			"vlasy"
		};
		hiddenSelectionsTextures[]=
		{
			"AI_Bandits\models\data\heather\T_Player_Heather_Hair_brunette.paa"
		};
	};
	class Bandit_Heather_Black: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\heather.p3d";
		hiddenSelections[]=
		{
			"vlasy"
		};
		hiddenSelectionsTextures[]=
		{
			"AI_Bandits\models\data\heather\T_Player_Heather_Hair_black.paa"
		};
	};
	class Bandit_Heather_Redhead: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\heather.p3d";
		hiddenSelections[]=
		{
			"vlasy"
		};
		hiddenSelectionsTextures[]=
		{
			"AI_Bandits\models\data\heather\T_Player_Heather_Hair_red.paa"
		};
	};
	class Bandit_1: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\bandits.p3d";
	};
	class Bandit_ArmyGirl: InfectedBanditBase
	{
		scope=2;
		model="AI_Bandits\models\armygirl.p3d";
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class Talking_SoundShader1: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\cumis_na_me",
				1
			}
		};
		volume=0.001;
		range=0.02;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\joke_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader3: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader6: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader7: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader8: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader9: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_7",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader10: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_8",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader11: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_9",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader12: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor\trader_greet_10",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader13: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader14: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader15: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader16: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader17: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader18: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader19: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman\bar_barman_hello_7",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader20: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ekolog\yan_sakharov_meet_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader21: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ekolog\yan_sakharov_meet_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader22: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ekolog\yan_sakharov_meet_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader23: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ClearSky\mar_csky_trader_meet_greet_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader24: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ClearSky\mar_csky_trader_meet_greet_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader25: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ClearSky\mar_csky_trader_meet_greet_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader26: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader27: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader28: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader29: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader30: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader31: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader32: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader33: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\1-7",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader34: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader35: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader36: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader37: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader38: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader39: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\7",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader40: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\8",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader41: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\2-2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader42: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\2-3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader43: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\2-4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader44: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\2-5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader45: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\2-6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader46: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3-1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader47: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3-2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader48: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3-3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader49: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3-4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader50: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3-5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader51: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\3-6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader52: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4-1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader53: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4-2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader54: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4-3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader55: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4-4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader56: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4-5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader57: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\RusGamer_RU\4-6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader501: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader3c",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader502: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader3a",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader503: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader_tutorial_anomalies_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader504: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader_script1b_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader505: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader_script1a_6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader506: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader_script1a_5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader507: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader_script1a_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader508: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Sidor_CZ\trader_script1a_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader509: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman_CZ\bar_bar_barmen_start_121",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader510: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman_CZ\bar_bar_barmen_start_1314",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader511: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman_CZ\bar_barman_hello_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader512: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman_CZ\bar_barman_hello_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader513: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman_CZ\bar_barman_wait_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader514: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Barman_CZ\barman_hello1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader515: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_idle_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader516: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_idle_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader517: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_idle_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader518: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_idle_5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader519: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_radiation_quest_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader520: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_talk_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader521: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Doctor_CZ\professor_to_kruglov_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader522: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\hele_kamo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader523: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\ze_se_ti_po_me_stejskalo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader524: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\nazdar_kamo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader525: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\mam_tady_pro_tebe_poradny_outfit",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader526: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\u_me_si_urcite_vyberes",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader527: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\schanis_kver",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader528: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\dobrej_matros_ale_nebude_to_levny",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader529: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\dobrej_matros",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader530: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Kamelie_CZ\copak_mi_neses",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader531: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_a_budes_i_nakupovat_nebo_jenom_ocumujes",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader532: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_deti_rozhazovali_rukama",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader533: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_chtel_bych_jednou_zemrit_jako_muj_stryc",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader534: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_chuck_norris_naucil_zabijet_cigarety",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader535: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_chuck_norris_vi_jak_vypada_pani_columbova",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader536: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_jdes_prodavat_nebo_nakupovat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader537: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_jestli_nemas_prachy_tak_sem_ani_nelez",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader538: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_jestli_ses_zhulenej_tak_sem_ani_nechod",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader539: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_jezisi_zase_on",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader540: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_kurvam_a_na_dluh_nedavame",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader541: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_mam_cislo_na_admina",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader542: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_mam_slusny_novy_kvery_jen_si_vyber",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader543: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_mam_tady_samy_dobry_veci_tak_se_mrkni",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader544: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_mame_tu_i_zbozi_v_akci_treba_tenhle_odjisteny_granat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader545: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_moje_holka_rekla_ze_jsem_pedofil",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader546: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_na_nasem_kvalitnim_nabytku_si_muzete_strihnout_i_svedskou_trojku",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader547: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_nazdar_co_si_prejes",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader548: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_ne_tady_zelezne_kovy_nevykupujeme",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader549: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_penez_mam_dost_neses_travu",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader550: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_poznal_jsem_te_dej_si_odchod",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader551: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_prave_prisly_novy_zasoby_no_omrkni_to",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader552: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_rodice_jsou_jako_tousty",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader553: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_sechno_za_sotopadesat_pane",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader554: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_to_ses_zase_ty_co_mi_neses",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader555: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_ty_jeste_nemas_bmw",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader556: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_vsechny_nase_auta_jsou_se_servisni_knizkou",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader557: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_vtip_rus_american_a_cech",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader558: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Spreyeers_CZ\spreyeers_zadnou_paniku_tuto_operaci_jsme_delali_tricetkrat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader559: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_bebinko",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader560: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_dobra_zasoba_leku",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader561: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_dost_reci",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader562: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_hehehe",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader563: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_hlavne_zadnou_paniku",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader564: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_hledam_darce_krve",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader565: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_chces-li_miti_hezci_den",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader566: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_chodis_me_ocumovat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader567: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_ja_moc_na_recicky_nejsem",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader568: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_jeden_dva_balicky",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader569: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_jestli_jsi_infikovany",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader570: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_kompletni_prohlidka",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader571: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_mrda_mi_v_hlave",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader572: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_nebyl_jsi_tu_pred_chvili",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader573: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_nemas_nejaky_sladky_kolacek",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader574: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_nevideli_jsme_se_uz_nekdy",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader575: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_nevim_kde_jsi_sehnal_tuto_informaci",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader576: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_nezapomen_tu_svoji_milovanou_vybavu",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader577: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_problemy_hafiku",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader578: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_prosle_leky_vracejte_do_lekarny",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader579: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_se_mnou_se_da_vzdycky_dohodnout",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader580: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_slusne_mnozstvi",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader581: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_to_mi_jako_chces_prodat_tento_stary_krap",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader582: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_ty_jeste_zijes",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader583: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_u_me_najdes",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader584: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_ukaz_se",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader585: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_vidim_ze_tu_mam_noveho_zakaznika",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader586: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_vitejte",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader587: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_vzdycky_jsem_mela_slabost",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader589: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_zase_cholera",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader590: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Violet_CZ\Violet_zmerim_ti_tlak",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1001: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Weapon_UK",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1002: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\UK_Medical",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1003: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\UK_Food",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1004: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Yiddy_Weapon",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1005: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Yiddy_Joke_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1006: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Yiddy_Joke_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1007: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Yiddy_Joke_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1008: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Yiddy_Food",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1009: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Yiddy_Medical",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1010: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Food_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1011: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Ammunition_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1012: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Weapon_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1013: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Food_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1014: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Medical_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1015: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Ammunition_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1016: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Weapon_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1017: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Food_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1018: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Medical_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1019: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Tim_Ammunition_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1020: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Food_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1021: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Medical_Robust_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1022: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Medical_Robust_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1023: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Weapon_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1024: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Food_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1025: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Medical_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1026: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Ammunition_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1027: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Hotel_Weapon_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1028: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Medical_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1029: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Ammunition_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1030: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Weapons_Robust",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1031: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Food_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1032: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Medical_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1033: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Ammunition_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1034: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\McDoogan_Weapon_Generic",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1035: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\myeyesareuphere",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1036: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\excusesmewhatareyoulookingat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1037: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Listenlove",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1038: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Apicturewouldlastlonger",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1039: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Timeismoney",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1040: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\doyounothaveanythingbettertodo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1041: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Hellowhatcanigetforyou",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1042: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Hi_Loveyourjacket",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1043: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Hellohowcanihelp",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1044: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Welcome3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1045: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Pleasedtomeetyou",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1046: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Muttering_Hi",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1047: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Suprised_Hi",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1048: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\Bad_day_whatyoulookingfor",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1049: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\I_have_just_the_thing",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1050: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\MagicMuggle_EN\looking_for_anything_special",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1051: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Bandit\bandit1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1052: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Bandit\bandit2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1053: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Duty\Greet1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1054: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Duty\Greet2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1055: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Duty\Greet3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1056: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Duty\Greet4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1057: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greet1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1058: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greet2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1059: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greet3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1060: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greet4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1061: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greet5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1062: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greet6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1063: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greetv2_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1064: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greetv2_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1065: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\Greetv2_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1066: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Extras\HeyBro",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1067: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Freedom\greet",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1068: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Freedom\greet2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1069: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Freedom\GreetHQ",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1070: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Freedom\Greet2HQ",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1071: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Red_forester\Greet1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1072: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Red_forester\Greet2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1073: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Red_forester\Greet3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1074: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Red_forester\Mercenarygreet",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1075: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\bar_barman_hello_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1076: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\bar_barman_hello_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1077: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\bar_barman_hello_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1078: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\bar_barman_hello_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1079: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\bar_barman_hello_5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1080: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\barman_hello_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1081: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\barman_hello_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1082: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\Mega_quest1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1083: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Rostok\Radbarad",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1084: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1085: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1086: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1087: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1088: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_5",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1089: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_6",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1090: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_7",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1091: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_8",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1092: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_9",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1093: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Sidor\trader_greet_10",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1094: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Yantar\yan_sakharov_meet_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1095: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Yantar\yan_sakharov_meet_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1096: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Yantar\yan_sakharov_meet_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1097: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Yantar\yan_sakharov_meet_4",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1098: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Zaton\greet",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1099: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Zaton\greet2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1100: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Zaton\Greetv2_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1101: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Stalker_EN\Zaton\Greetv2_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1102: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Food",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1103: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Human_Fat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1104: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Medical",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1105: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Medical2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1106: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Melee",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1107: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Shovel",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1108: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Weapon_Quote_Make_A_Deal",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1109: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\PCBandit100_EN\Advice1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1110: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-Weapons",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1111: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-Parts",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1112: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-Hardware",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1113: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-Dickweasle",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1114: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-BlackMarket1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1115: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-BlackMarket2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1116: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Weyland_EN\Whistles-Automotive",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1501: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\dashu1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1502: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\dashu2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1503: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\dashu3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1504: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\fuzhuang1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1505: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\fuzhuang2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1506: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\gongju1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1507: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\gongju2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1508: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\laofuren1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1509: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\laofuren2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1510: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\laofuren3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1511: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\nianqingzhanshi1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1512: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\nianqingzhanshi2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1513: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\renwu1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1514: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\renwu2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1515: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\shiwu1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1516: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\shiwu2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1517: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\wuqi1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1518: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\wuqi2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1519: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\zaiju1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader1520: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\ZHUBOWULA_CN\zaiju2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2001: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\agru_warning",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2002: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\air_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2003: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\air_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2004: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\ambience03",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2005: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\battle_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2006: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\blowout_rumble",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2007: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dogs_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2008: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dropinpool1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2009: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dropinpool2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2010: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\fan_squeaks_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2011: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\fan1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2012: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\h_or_metal_large",
				1
			}
		};
		volume=1;
		range=35;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2013: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\heartbeat",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2014: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\horror_notify_02",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2015: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\iron_moaning1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2016: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\labx8_crying",
				1
			}
		};
		volume=1;
		range=40;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2017: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\lamp_squeaks_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2018: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\lamp_squeaks_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2019: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\metal_noise_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2020: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\metal_noise_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2021: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\metal_squeak_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2022: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\metal_squeak_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2023: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine_squeak_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2024: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\monolith_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2025: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\new_drops1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2026: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\new_drops2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2027: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\new_flies1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2028: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\noos_tunnel_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2029: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\os_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2030: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\pas_b400_gates_wreck",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2031: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rats_panic_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2032: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rats_panic_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2033: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rats_panic_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2034: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rnd_giant",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2035: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rnd_metal1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2036: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rt_ambient1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2037: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rt_ambient2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2038: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\squeak_metal1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2039: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\squeak_metal2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2040: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\switch_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2041: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\switch_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2042: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\waterdropspower",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2043: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16_brain_death",
				1
			}
		};
		volume=1;
		range=37;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2044: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16_grate_fall",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2045: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18_footsteps",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2046: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18_gunfire",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2047: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18_move_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2048: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18_wind_1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2049: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18_wind_2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2050: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18_wind_3",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2051: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\zat_b38_elevator_door",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2052: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2053: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2054: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2055: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_4",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2056: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_5",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2057: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_6",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2058: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_7",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2059: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_8",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2060: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_9",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2061: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_10",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2062: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_11",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2063: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_12",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2064: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\NPC_Joke\jokes\joke_13",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2065: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\arena\crowd_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2066: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\arena\crowd_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2067: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\arena\crowd_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2068: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\arena\crowd_wave_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2069: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\arena\crowd_wave_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2070: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\arena\crowd_wave_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2071: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\jupiter\jup_b16_oasis_noise",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2072: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\jupiter\jup_b41_steam",
				1
			}
		};
		volume=1;
		range=35;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2073: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\jupiter\jup_b219_underpass_opening",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2074: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\mine_falldown",
				1
			}
		};
		volume=1;
		range=35;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2075: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\mine_hit_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2076: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\mine_hit_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2077: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\mine_squeak_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2078: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\mine_squeak_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2079: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\wind_mine_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2080: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\wind_mine_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2081: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\mine\wind_mine_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2082: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_brain_death",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2083: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_brain_run",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2084: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_brain_stop",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2085: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_engine1_run",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2086: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_engine1_stop",
				1
			}
		};
		volume=1;
		range=35;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2087: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_engine2_run",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2088: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_engine2_stop",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2089: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_grate_fall",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2090: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_hum_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2091: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_psy_hit",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2092: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x16\x16_psy_r",
				1
			}
		};
		volume=1;
		range=45;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2093: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\fan1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2094: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_am_hit1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2095: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_am_hit4",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2096: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_or_metal_large",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2097: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_or_metal_rusty",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2098: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_otsteps_wood1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2099: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_tal_grate_impact_hard2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2100: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_tal_grate_impact_hard3",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2101: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\h_tal5",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2102: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\waterdrops2",
				1
			}
		};
		volume=1;
		range=35;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2103: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_creak_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2104: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_creak_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2105: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_footsteps",
				1
			}
		};
		volume=1;
		range=45;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2106: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_footsteps_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2107: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_gunfire",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2108: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2109: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2110: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_3",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2111: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_4",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2112: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_5",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2113: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_6",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2114: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_7",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2115: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_hit_8",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2116: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_metal_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2117: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_metal_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2118: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_metal_3",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2119: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_metal_4",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2120: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_metal_5",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2121: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_move_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2122: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_move_2",
				1
			}
		};
		volume=1;
		range=35;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2123: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_move_3",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2124: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_move_4",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2125: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_move_5",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2126: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_noise_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2127: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_noise_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2128: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_wind_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2129: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_wind_2",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2130: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\x18\x18_wind_3",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2131: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_death_truck_1",
				1
			}
		};
		volume=1;
		range=25;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2132: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_chernobyl_crush_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2133: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_osoznanie_start_11",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2134: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_osoznanie_start_21",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2135: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_stalker_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2136: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_what_about_me_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2137: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_what_is_the_zone_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2138: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_what_next_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2139: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_who_are_you_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2140: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\dialogs\oso_why_chernobyl_1",
				1
			}
		};
		volume=1;
		range=55;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2141: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\jupiter\jup_b219_underpass_opening",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2142: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2143: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2144: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2145: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_4",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2146: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_5",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2147: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_6",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2148: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_7",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2149: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ambient_8",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2150: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\barking",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2151: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\Beep",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2152: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\Crow",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2153: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\Crow_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2154: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\Crow_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2155: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\Crow_4",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2156: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\dead",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2157: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\dog_howl",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2158: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\dog_howl_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2159: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\dog_howl_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2160: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\dogs",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2161: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\dogs_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2162: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\fog_night_scream_1",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2163: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\fog_night_scream_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2164: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\fog_night_scream_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2165: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ghost",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2166: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ghost_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2167: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ghost_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2168: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\ghost_4",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2169: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\helicopter",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2170: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\helicopter_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2171: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\howl_and_roar",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2172: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\hum",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2173: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\Krik",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2174: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\machine_gun_shots",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2175: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\machine_gun_shots_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2176: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\owl",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2177: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\owl_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2178: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\owl_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2179: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\pistol_shots",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2180: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\pistol_shots_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2181: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\pistol_shots_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2182: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\poltergeist",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2183: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\poltergeist_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2184: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\poltergeist_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2185: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2186: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2187: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2188: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar_4",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2189: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar_5",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2190: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar_6",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2191: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\roar_7",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2192: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\shots",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2193: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\shots_and_screams",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2194: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\shots_and_screams_2",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2195: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\shots_and_screams_3",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader2196: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Ambient\rusgamer\zombi",
				1
			}
		};
		volume=1;
		range=30;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4501: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\ayudarte",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4502: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\bostezobuenosdias",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4503: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\Buenosdiassuperviviente",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4504: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\comprameami",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4505: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\dinero",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4506: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\disparos",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4507: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\eltiempoesdinero",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4508: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\enquepuedoayudarte2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4509: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\esperoquetraigasdinero",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4510: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\estasbuscandoalgoespecial",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4511: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\megustatuchaqueta",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4512: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\miraalsuelo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4513: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\nadamejorquehacer",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4514: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\nodisparesenelmercado",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4515: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\quehorassonestas",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4516: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\quetipodeobjetoeselqueestasbuscando",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4517: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\susurrohola",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4518: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishGirl\tencuidadoconeldeatras",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4519: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\buen_dia",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4520: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\Comida",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4521: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\Confiar",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4522: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\Delirio",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4523: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\Devoluccion",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4524: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\dia_libre",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4525: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\hola_Que_Tal",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4526: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\MejorProducto",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4527: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\oportunidad",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4528: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\PatadasEnElCulo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4529: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\pedo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4530: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\Pensar",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4531: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\Producto",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4532: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\QueTeDebo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4533: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\satisfecho",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4534: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz1\todopagado",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4535: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenas_tardes_como_le_puedo_ayudar",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4536: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenas_tardes_no_lo_encontras_a_un_precio_mejor",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4537: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenas_tardes_si_no_te_convence_lo_devuelves",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4538: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenas_tardes_superviviente_muchas_personas_ya_lo_han_comprado",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4539: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenos_dias_no_lo_encontraras_a_mejor_precio_en_otro_lugar",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4540: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenos_dias_que_es_lo_que_estabas_buscando",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4541: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenos_dias_si_no_hay_lo_que_encuentras_vuelve_por_la_misma_puerta_que_entraste",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4542: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenos_dias_superviviente_si_compras_dos_el_tercero_te_sale_gratis......",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4543: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Buenos_dias_todo_lo_que_encontraras_en_este_mercado_es_algo_diferente_original_y_unicoc",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4544: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Hay_alguna_razon_por_la_que_si_le_damos_el_producto_a_este_precio_no_nos_siga_comprando_a_nosotros",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4545: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Hola_superviviente_si_fuera_tu_no_me_lo_pensaria_dos_veces",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4546: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Si_lo_encuentras_en_otro_lugar_mas_barato_te_devuelvo_tu_dinero",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4547: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Sin_duda_esta_es_la_mejor_compra_que_vas_a_poder_hacer",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4548: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Tengo_cosas_en_la_trastienda_que_solo_son_para_ti",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4549: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Tengo_todos_los_productos_a_precio_regalado",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4550: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\acercate",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4551: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\Buena_Mierda",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4552: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\CerraPuerta",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4553: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\golosinas",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4554: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\HaciaTiempo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4555: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\otra_vez",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4556: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\perro",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4557: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz3\primo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4558: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Dog_amigo_fiel",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4559: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Dog_Cuando_yo_era_joven",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader4560: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Fenwichs456_ESP\spanishMan\Voz2\Dog_de_quien_es_ese_perro",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5001: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\01_Amunicja_i_magazynki",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5002: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\02_Bezpieczna_strefa",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5003: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\03_Bede_strzelal",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5004: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\04_Bron_magazynek",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5005: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\05_Budujesz",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5006: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\06_Chleb",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5007: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\07_Ciuchy",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5008: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\08_Czesc",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5009: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\09_Czesci_do_samochodu",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5010: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\10_czym_lecisz",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5011: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\11_Dawno_cie_u_nas_nie_bylo",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5012: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\12_Dobre_Helikoptery",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5013: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\13_Dostawa_broni",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5014: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\14_Haha_nie_wierze_przezyles",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5015: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\15_Jak_nic_nie_kupujesz_spierdalaj",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5016: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\16_Kiepsko_wygladasz_EVA",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5017: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\17_Kotku_EVA",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5018: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\18_Lodzie",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5019: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\19_Mam_dobry_towar",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5020: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\20_Namioty",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5021: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\21_Nowe_auta",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5022: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\22_Pomalujesz",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5023: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\23_Rozerwac",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5024: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\24_Ryby",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5025: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\25_Ryby2",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5026: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\26_Siekiery",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5027: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\27_Skarbonka",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5028: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\28_Spierdalaj",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5029: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\29_Smiglowce_nisko_i_powoli",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5030: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\30_Smiglowce",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5031: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\31_Witaj_w_pumkcie_wymiany",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5032: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\32_Witaj_wedrowcze",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5033: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\33_Witaj_wedrowcze1",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5034: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\34_Wymiana",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5035: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\35_Zjadlbys_cos",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5036: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\36_Zarcie",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
	class Talking_SoundShader5037: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"AI_Bandits\sounds\Andrzej_PL\37_Zyjesz_dobrze_cie_widziec",
				1
			}
		};
		volume=1;
		range=20;
		rangeCurve[]=
		{
			{0,1},
			{0.5,0.69999999},
			{1,0}
		};
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class NPC_VoiceFX_Base_SoundSet
	{
		volumeFactor=1;
		frequencyRandomizer=2;
		spatial=1;
		doppler=0;
		loop=0;
	};
	class Talking_SoundSet1: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1"
		};
	};
	class Talking_SoundSet2: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2"
		};
	};
	class Talking_SoundSet3: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader3"
		};
	};
	class Talking_SoundSet4: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4"
		};
	};
	class Talking_SoundSet5: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5"
		};
	};
	class Talking_SoundSet6: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader6"
		};
	};
	class Talking_SoundSet7: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader7"
		};
	};
	class Talking_SoundSet8: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader8"
		};
	};
	class Talking_SoundSet9: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader9"
		};
	};
	class Talking_SoundSet10: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader10"
		};
	};
	class Talking_SoundSet11: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader11"
		};
	};
	class Talking_SoundSet12: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader12"
		};
	};
	class Talking_SoundSet13: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader13"
		};
	};
	class Talking_SoundSet14: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader14"
		};
	};
	class Talking_SoundSet15: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader15"
		};
	};
	class Talking_SoundSet16: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader16"
		};
	};
	class Talking_SoundSet17: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader17"
		};
	};
	class Talking_SoundSet18: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader18"
		};
	};
	class Talking_SoundSet19: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader19"
		};
	};
	class Talking_SoundSet20: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader20"
		};
	};
	class Talking_SoundSet21: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader21"
		};
	};
	class Talking_SoundSet22: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader22"
		};
	};
	class Talking_SoundSet23: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader23"
		};
	};
	class Talking_SoundSet24: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader24"
		};
	};
	class Talking_SoundSet25: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader25"
		};
	};
	class Talking_SoundSet26: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader26"
		};
	};
	class Talking_SoundSet27: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader27"
		};
	};
	class Talking_SoundSet28: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader28"
		};
	};
	class Talking_SoundSet29: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader29"
		};
	};
	class Talking_SoundSet30: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader30"
		};
	};
	class Talking_SoundSet31: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader31"
		};
	};
	class Talking_SoundSet32: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader32"
		};
	};
	class Talking_SoundSet33: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader33"
		};
	};
	class Talking_SoundSet34: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader34"
		};
	};
	class Talking_SoundSet35: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader35"
		};
	};
	class Talking_SoundSet36: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader36"
		};
	};
	class Talking_SoundSet37: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader37"
		};
	};
	class Talking_SoundSet38: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader38"
		};
	};
	class Talking_SoundSet39: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader39"
		};
	};
	class Talking_SoundSet40: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader40"
		};
	};
	class Talking_SoundSet41: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader41"
		};
	};
	class Talking_SoundSet42: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader42"
		};
	};
	class Talking_SoundSet43: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader43"
		};
	};
	class Talking_SoundSet44: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader44"
		};
	};
	class Talking_SoundSet45: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader45"
		};
	};
	class Talking_SoundSet46: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader46"
		};
	};
	class Talking_SoundSet47: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader47"
		};
	};
	class Talking_SoundSet48: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader48"
		};
	};
	class Talking_SoundSet49: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader49"
		};
	};
	class Talking_SoundSet50: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader50"
		};
	};
	class Talking_SoundSet51: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader51"
		};
	};
	class Talking_SoundSet52: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader52"
		};
	};
	class Talking_SoundSet53: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader53"
		};
	};
	class Talking_SoundSet54: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader54"
		};
	};
	class Talking_SoundSet55: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader55"
		};
	};
	class Talking_SoundSet56: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader56"
		};
	};
	class Talking_SoundSet57: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader57"
		};
	};
	class Talking_SoundSet501: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader501"
		};
	};
	class Talking_SoundSet502: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader502"
		};
	};
	class Talking_SoundSet503: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader503"
		};
	};
	class Talking_SoundSet504: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader504"
		};
	};
	class Talking_SoundSet505: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader505"
		};
	};
	class Talking_SoundSet506: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader506"
		};
	};
	class Talking_SoundSet507: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader507"
		};
	};
	class Talking_SoundSet508: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader508"
		};
	};
	class Talking_SoundSet509: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader509"
		};
	};
	class Talking_SoundSet510: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader510"
		};
	};
	class Talking_SoundSet511: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader511"
		};
	};
	class Talking_SoundSet512: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader512"
		};
	};
	class Talking_SoundSet513: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader513"
		};
	};
	class Talking_SoundSet514: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader514"
		};
	};
	class Talking_SoundSet515: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader515"
		};
	};
	class Talking_SoundSet516: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader516"
		};
	};
	class Talking_SoundSet517: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader517"
		};
	};
	class Talking_SoundSet518: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader518"
		};
	};
	class Talking_SoundSet519: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader519"
		};
	};
	class Talking_SoundSet520: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader520"
		};
	};
	class Talking_SoundSet521: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader521"
		};
	};
	class Talking_SoundSet522: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader522"
		};
	};
	class Talking_SoundSet523: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader523"
		};
	};
	class Talking_SoundSet524: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader524"
		};
	};
	class Talking_SoundSet525: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader525"
		};
	};
	class Talking_SoundSet526: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader526"
		};
	};
	class Talking_SoundSet527: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader527"
		};
	};
	class Talking_SoundSet528: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader528"
		};
	};
	class Talking_SoundSet529: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader529"
		};
	};
	class Talking_SoundSet530: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader530"
		};
	};
	class Talking_SoundSet531: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader531"
		};
	};
	class Talking_SoundSet532: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader532"
		};
	};
	class Talking_SoundSet533: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader533"
		};
	};
	class Talking_SoundSet534: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader534"
		};
	};
	class Talking_SoundSet535: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader535"
		};
	};
	class Talking_SoundSet536: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader536"
		};
	};
	class Talking_SoundSet537: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader537"
		};
	};
	class Talking_SoundSet538: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader538"
		};
	};
	class Talking_SoundSet539: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader539"
		};
	};
	class Talking_SoundSet540: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader539"
		};
	};
	class Talking_SoundSet541: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader541"
		};
	};
	class Talking_SoundSet542: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader542"
		};
	};
	class Talking_SoundSet543: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader543"
		};
	};
	class Talking_SoundSet544: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader544"
		};
	};
	class Talking_SoundSet545: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader545"
		};
	};
	class Talking_SoundSet546: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader546"
		};
	};
	class Talking_SoundSet547: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader547"
		};
	};
	class Talking_SoundSet548: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader548"
		};
	};
	class Talking_SoundSet549: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader549"
		};
	};
	class Talking_SoundSet550: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader550"
		};
	};
	class Talking_SoundSet551: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader551"
		};
	};
	class Talking_SoundSet552: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader552"
		};
	};
	class Talking_SoundSet553: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader553"
		};
	};
	class Talking_SoundSet554: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader554"
		};
	};
	class Talking_SoundSet555: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader555"
		};
	};
	class Talking_SoundSet556: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader556"
		};
	};
	class Talking_SoundSet557: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader557"
		};
	};
	class Talking_SoundSet558: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader558"
		};
	};
	class Talking_SoundSet559: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader559"
		};
	};
	class Talking_SoundSet560: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader560"
		};
	};
	class Talking_SoundSet561: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader561"
		};
	};
	class Talking_SoundSet562: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader562"
		};
	};
	class Talking_SoundSet563: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader563"
		};
	};
	class Talking_SoundSet564: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader564"
		};
	};
	class Talking_SoundSet565: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader565"
		};
	};
	class Talking_SoundSet566: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader566"
		};
	};
	class Talking_SoundSet567: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader567"
		};
	};
	class Talking_SoundSet568: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader568"
		};
	};
	class Talking_SoundSet569: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader569"
		};
	};
	class Talking_SoundSet570: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader570"
		};
	};
	class Talking_SoundSet571: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader571"
		};
	};
	class Talking_SoundSet572: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader572"
		};
	};
	class Talking_SoundSet573: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader573"
		};
	};
	class Talking_SoundSet574: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader574"
		};
	};
	class Talking_SoundSet575: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader575"
		};
	};
	class Talking_SoundSet576: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader576"
		};
	};
	class Talking_SoundSet577: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader577"
		};
	};
	class Talking_SoundSet578: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader578"
		};
	};
	class Talking_SoundSet579: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader579"
		};
	};
	class Talking_SoundSet580: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader580"
		};
	};
	class Talking_SoundSet581: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader581"
		};
	};
	class Talking_SoundSet582: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader582"
		};
	};
	class Talking_SoundSet583: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader583"
		};
	};
	class Talking_SoundSet584: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader584"
		};
	};
	class Talking_SoundSet585: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader585"
		};
	};
	class Talking_SoundSet586: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader586"
		};
	};
	class Talking_SoundSet587: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader587"
		};
	};
	class Talking_SoundSet588: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader588"
		};
	};
	class Talking_SoundSet589: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader589"
		};
	};
	class Talking_SoundSet590: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader590"
		};
	};
	class Talking_SoundSet1001: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1001"
		};
	};
	class Talking_SoundSet1002: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1002"
		};
	};
	class Talking_SoundSet1003: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1003"
		};
	};
	class Talking_SoundSet1004: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1004"
		};
	};
	class Talking_SoundSet1005: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1005"
		};
	};
	class Talking_SoundSet1006: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1006"
		};
	};
	class Talking_SoundSet1007: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1007"
		};
	};
	class Talking_SoundSet1008: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1008"
		};
	};
	class Talking_SoundSet1009: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1009"
		};
	};
	class Talking_SoundSet1010: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1010"
		};
	};
	class Talking_SoundSet1011: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1011"
		};
	};
	class Talking_SoundSet1012: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1012"
		};
	};
	class Talking_SoundSet1013: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1013"
		};
	};
	class Talking_SoundSet1014: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1014"
		};
	};
	class Talking_SoundSet1015: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1015"
		};
	};
	class Talking_SoundSet1016: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1016"
		};
	};
	class Talking_SoundSet1017: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1017"
		};
	};
	class Talking_SoundSet1018: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1018"
		};
	};
	class Talking_SoundSet1019: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1019"
		};
	};
	class Talking_SoundSet1020: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1020"
		};
	};
	class Talking_SoundSet1021: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1021"
		};
	};
	class Talking_SoundSet1022: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1022"
		};
	};
	class Talking_SoundSet1023: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1023"
		};
	};
	class Talking_SoundSet1024: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1024"
		};
	};
	class Talking_SoundSet1025: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1025"
		};
	};
	class Talking_SoundSet1026: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1026"
		};
	};
	class Talking_SoundSet1027: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1027"
		};
	};
	class Talking_SoundSet1028: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1028"
		};
	};
	class Talking_SoundSet1029: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1029"
		};
	};
	class Talking_SoundSet1030: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1030"
		};
	};
	class Talking_SoundSet1031: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1031"
		};
	};
	class Talking_SoundSet1032: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1032"
		};
	};
	class Talking_SoundSet1033: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1033"
		};
	};
	class Talking_SoundSet1034: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1034"
		};
	};
	class Talking_SoundSet1035: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1035"
		};
	};
	class Talking_SoundSet1036: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1036"
		};
	};
	class Talking_SoundSet1037: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1037"
		};
	};
	class Talking_SoundSet1038: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1038"
		};
	};
	class Talking_SoundSet1039: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1039"
		};
	};
	class Talking_SoundSet1040: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1040"
		};
	};
	class Talking_SoundSet1041: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1041"
		};
	};
	class Talking_SoundSet1042: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1042"
		};
	};
	class Talking_SoundSet1043: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1043"
		};
	};
	class Talking_SoundSet1044: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1044"
		};
	};
	class Talking_SoundSet1045: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1045"
		};
	};
	class Talking_SoundSet1046: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1046"
		};
	};
	class Talking_SoundSet1047: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1047"
		};
	};
	class Talking_SoundSet1048: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1048"
		};
	};
	class Talking_SoundSet1049: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1049"
		};
	};
	class Talking_SoundSet1050: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1050"
		};
	};
	class Talking_SoundSet1051: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1051"
		};
	};
	class Talking_SoundSet1052: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1052"
		};
	};
	class Talking_SoundSet1053: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1053"
		};
	};
	class Talking_SoundSet1054: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1054"
		};
	};
	class Talking_SoundSet1055: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1055"
		};
	};
	class Talking_SoundSet1056: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1056"
		};
	};
	class Talking_SoundSet1057: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1057"
		};
	};
	class Talking_SoundSet1058: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1058"
		};
	};
	class Talking_SoundSet1059: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1059"
		};
	};
	class Talking_SoundSet1060: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1060"
		};
	};
	class Talking_SoundSet1061: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1062"
		};
	};
	class Talking_SoundSet1063: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1063"
		};
	};
	class Talking_SoundSet1064: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1064"
		};
	};
	class Talking_SoundSet1065: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1065"
		};
	};
	class Talking_SoundSet1066: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1066"
		};
	};
	class Talking_SoundSet1067: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1067"
		};
	};
	class Talking_SoundSet1068: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1068"
		};
	};
	class Talking_SoundSet1069: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1069"
		};
	};
	class Talking_SoundSet1070: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1070"
		};
	};
	class Talking_SoundSet1071: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1071"
		};
	};
	class Talking_SoundSet1072: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1072"
		};
	};
	class Talking_SoundSet1073: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1073"
		};
	};
	class Talking_SoundSet1074: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1074"
		};
	};
	class Talking_SoundSet1075: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1075"
		};
	};
	class Talking_SoundSet1076: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1076"
		};
	};
	class Talking_SoundSet1077: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1077"
		};
	};
	class Talking_SoundSet1078: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1078"
		};
	};
	class Talking_SoundSet1079: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1079"
		};
	};
	class Talking_SoundSet1080: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1080"
		};
	};
	class Talking_SoundSet1081: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1081"
		};
	};
	class Talking_SoundSet1082: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1082"
		};
	};
	class Talking_SoundSet1083: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1083"
		};
	};
	class Talking_SoundSet1084: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1084"
		};
	};
	class Talking_SoundSet1085: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1085"
		};
	};
	class Talking_SoundSet1086: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1086"
		};
	};
	class Talking_SoundSet1087: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1087"
		};
	};
	class Talking_SoundSet1088: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1088"
		};
	};
	class Talking_SoundSet1089: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1089"
		};
	};
	class Talking_SoundSet1090: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1090"
		};
	};
	class Talking_SoundSet1091: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1091"
		};
	};
	class Talking_SoundSet1092: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1092"
		};
	};
	class Talking_SoundSet1093: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1093"
		};
	};
	class Talking_SoundSet1094: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1094"
		};
	};
	class Talking_SoundSet1095: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1095"
		};
	};
	class Talking_SoundSet1096: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1096"
		};
	};
	class Talking_SoundSet1097: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1097"
		};
	};
	class Talking_SoundSet1098: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1098"
		};
	};
	class Talking_SoundSet1099: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1099"
		};
	};
	class Talking_SoundSet1100: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1100"
		};
	};
	class Talking_SoundSet1101: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1101"
		};
	};
	class Talking_SoundSet1102: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1102"
		};
	};
	class Talking_SoundSet1103: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1103"
		};
	};
	class Talking_SoundSet1104: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1104"
		};
	};
	class Talking_SoundSet1105: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1105"
		};
	};
	class Talking_SoundSet1106: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1106"
		};
	};
	class Talking_SoundSet1107: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1107"
		};
	};
	class Talking_SoundSet1108: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1108"
		};
	};
	class Talking_SoundSet1109: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1109"
		};
	};
	class Talking_SoundSet1110: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1110"
		};
	};
	class Talking_SoundSet1111: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1111"
		};
	};
	class Talking_SoundSet1112: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1112"
		};
	};
	class Talking_SoundSet1113: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1113"
		};
	};
	class Talking_SoundSet1114: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1114"
		};
	};
	class Talking_SoundSet1115: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1115"
		};
	};
	class Talking_SoundSet1116: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1116"
		};
	};
	class Talking_SoundSet1501: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1501"
		};
	};
	class Talking_SoundSet1502: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1502"
		};
	};
	class Talking_SoundSet1503: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1503"
		};
	};
	class Talking_SoundSet1504: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1504"
		};
	};
	class Talking_SoundSet1505: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1505"
		};
	};
	class Talking_SoundSet1506: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1506"
		};
	};
	class Talking_SoundSet1507: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1507"
		};
	};
	class Talking_SoundSet1508: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1508"
		};
	};
	class Talking_SoundSet1509: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1509"
		};
	};
	class Talking_SoundSet1510: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1510"
		};
	};
	class Talking_SoundSet1511: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1511"
		};
	};
	class Talking_SoundSet1512: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1512"
		};
	};
	class Talking_SoundSet1513: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1513"
		};
	};
	class Talking_SoundSet1514: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1514"
		};
	};
	class Talking_SoundSet1515: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1515"
		};
	};
	class Talking_SoundSet1516: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1516"
		};
	};
	class Talking_SoundSet1517: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1517"
		};
	};
	class Talking_SoundSet1518: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1518"
		};
	};
	class Talking_SoundSet1519: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader1519"
		};
	};
	class Talking_SoundSet2001: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2001"
		};
	};
	class Talking_SoundSet2002: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2002"
		};
	};
	class Talking_SoundSet2003: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2003"
		};
	};
	class Talking_SoundSet2004: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2004"
		};
	};
	class Talking_SoundSet2005: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2005"
		};
	};
	class Talking_SoundSet2006: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2006"
		};
	};
	class Talking_SoundSet2007: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2007"
		};
	};
	class Talking_SoundSet2008: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2008"
		};
	};
	class Talking_SoundSet2009: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2009"
		};
	};
	class Talking_SoundSet2010: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2010"
		};
	};
	class Talking_SoundSet2011: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2011"
		};
	};
	class Talking_SoundSet2012: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2012"
		};
	};
	class Talking_SoundSet2013: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2013"
		};
	};
	class Talking_SoundSet2014: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2014"
		};
	};
	class Talking_SoundSet2015: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2015"
		};
	};
	class Talking_SoundSet2016: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2016"
		};
	};
	class Talking_SoundSet2017: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader52017"
		};
	};
	class Talking_SoundSet2018: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2018"
		};
	};
	class Talking_SoundSet219: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2019"
		};
	};
	class Talking_SoundSet2020: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2020"
		};
	};
	class Talking_SoundSet2021: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2021"
		};
	};
	class Talking_SoundSet2022: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2022"
		};
	};
	class Talking_SoundSet2023: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2023"
		};
	};
	class Talking_SoundSet2024: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2024"
		};
	};
	class Talking_SoundSet2025: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2025"
		};
	};
	class Talking_SoundSet2026: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2026"
		};
	};
	class Talking_SoundSet2027: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2027"
		};
	};
	class Talking_SoundSet2028: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2028"
		};
	};
	class Talking_SoundSet2029: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2029"
		};
	};
	class Talking_SoundSet2030: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2030"
		};
	};
	class Talking_SoundSet2031: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2031"
		};
	};
	class Talking_SoundSet2032: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2032"
		};
	};
	class Talking_SoundSet2033: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2033"
		};
	};
	class Talking_SoundSet2034: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2034"
		};
	};
	class Talking_SoundSet2035: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2035"
		};
	};
	class Talking_SoundSet2036: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2036"
		};
	};
	class Talking_SoundSet2037: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2037"
		};
	};
	class Talking_SoundSet2038: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2038"
		};
	};
	class Talking_SoundSet2039: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2039"
		};
	};
	class Talking_SoundSet2040: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2040"
		};
	};
	class Talking_SoundSet2041: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2041"
		};
	};
	class Talking_SoundSet2042: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2042"
		};
	};
	class Talking_SoundSet2043: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2043"
		};
	};
	class Talking_SoundSet2044: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2044"
		};
	};
	class Talking_SoundSet2045: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2045"
		};
	};
	class Talking_SoundSet2046: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2046"
		};
	};
	class Talking_SoundSet2047: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2047"
		};
	};
	class Talking_SoundSet2048: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2048"
		};
	};
	class Talking_SoundSet2049: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2049"
		};
	};
	class Talking_SoundSet2050: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2050"
		};
	};
	class Talking_SoundSet2051: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2051"
		};
	};
	class Talking_SoundSet2052: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2052"
		};
	};
	class Talking_SoundSet2053: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2053"
		};
	};
	class Talking_SoundSet2054: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2054"
		};
	};
	class Talking_SoundSet2055: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2055"
		};
	};
	class Talking_SoundSet2056: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2056"
		};
	};
	class Talking_SoundSet2057: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2057"
		};
	};
	class Talking_SoundSet2058: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2058"
		};
	};
	class Talking_SoundSet2059: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2059"
		};
	};
	class Talking_SoundSet2060: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2060"
		};
	};
	class Talking_SoundSet2061: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2061"
		};
	};
	class Talking_SoundSet2062: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2062"
		};
	};
	class Talking_SoundSet2063: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2063"
		};
	};
	class Talking_SoundSet2064: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2064"
		};
	};
	class Talking_SoundSet2065: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2065"
		};
	};
	class Talking_SoundSet2066: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2066"
		};
	};
	class Talking_SoundSet2067: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2067"
		};
	};
	class Talking_SoundSet2068: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2068"
		};
	};
	class Talking_SoundSet2069: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2069"
		};
	};
	class Talking_SoundSet2070: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2070"
		};
	};
	class Talking_SoundSet2071: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2071"
		};
	};
	class Talking_SoundSet2072: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2072"
		};
	};
	class Talking_SoundSet2073: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2073"
		};
	};
	class Talking_SoundSet2074: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2074"
		};
	};
	class Talking_SoundSet2075: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2075"
		};
	};
	class Talking_SoundSet2076: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2076"
		};
	};
	class Talking_SoundSet2077: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2077"
		};
	};
	class Talking_SoundSet2078: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2078"
		};
	};
	class Talking_SoundSet2079: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2079"
		};
	};
	class Talking_SoundSet2080: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2080"
		};
	};
	class Talking_SoundSet2081: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2081"
		};
	};
	class Talking_SoundSet2082: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2082"
		};
	};
	class Talking_SoundSet2083: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2083"
		};
	};
	class Talking_SoundSet2084: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2084"
		};
	};
	class Talking_SoundSet2085: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2085"
		};
	};
	class Talking_SoundSet2086: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2086"
		};
	};
	class Talking_SoundSet2087: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2087"
		};
	};
	class Talking_SoundSet2088: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2088"
		};
	};
	class Talking_SoundSet2089: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2089"
		};
	};
	class Talking_SoundSet2090: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2090"
		};
	};
	class Talking_SoundSet2091: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2091"
		};
	};
	class Talking_SoundSet2092: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2092"
		};
	};
	class Talking_SoundSet2093: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2093"
		};
	};
	class Talking_SoundSet2094: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2094"
		};
	};
	class Talking_SoundSet2095: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2095"
		};
	};
	class Talking_SoundSet2096: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2096"
		};
	};
	class Talking_SoundSet2097: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2097"
		};
	};
	class Talking_SoundSet2098: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2098"
		};
	};
	class Talking_SoundSet2099: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2099"
		};
	};
	class Talking_SoundSet2100: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2100"
		};
	};
	class Talking_SoundSet2101: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2101"
		};
	};
	class Talking_SoundSet2102: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2102"
		};
	};
	class Talking_SoundSet2103: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2103"
		};
	};
	class Talking_SoundSet2104: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2104"
		};
	};
	class Talking_SoundSet2105: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2105"
		};
	};
	class Talking_SoundSet2106: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2106"
		};
	};
	class Talking_SoundSet2107: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2107"
		};
	};
	class Talking_SoundSet2108: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2108"
		};
	};
	class Talking_SoundSet2109: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2109"
		};
	};
	class Talking_SoundSet2110: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2110"
		};
	};
	class Talking_SoundSet2111: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2111"
		};
	};
	class Talking_SoundSet2112: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2112"
		};
	};
	class Talking_SoundSet2113: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2113"
		};
	};
	class Talking_SoundSet2114: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2114"
		};
	};
	class Talking_SoundSet2115: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2115"
		};
	};
	class Talking_SoundSet2116: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2116"
		};
	};
	class Talking_SoundSet2117: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2117"
		};
	};
	class Talking_SoundSet2118: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2118"
		};
	};
	class Talking_SoundSet2119: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2119"
		};
	};
	class Talking_SoundSet2120: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2120"
		};
	};
	class Talking_SoundSet2121: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2121"
		};
	};
	class Talking_SoundSet2122: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2122"
		};
	};
	class Talking_SoundSet2123: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2123"
		};
	};
	class Talking_SoundSet2124: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2124"
		};
	};
	class Talking_SoundSet2125: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2125"
		};
	};
	class Talking_SoundSet2126: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2126"
		};
	};
	class Talking_SoundSet2127: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2127"
		};
	};
	class Talking_SoundSet2128: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2128"
		};
	};
	class Talking_SoundSet2129: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2129"
		};
	};
	class Talking_SoundSet2130: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2130"
		};
	};
	class Talking_SoundSet2131: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2131"
		};
	};
	class Talking_SoundSet2132: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2132"
		};
	};
	class Talking_SoundSet2133: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2133"
		};
	};
	class Talking_SoundSet2134: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2134"
		};
	};
	class Talking_SoundSet2135: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2135"
		};
	};
	class Talking_SoundSet2136: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2136"
		};
	};
	class Talking_SoundSet2137: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2137"
		};
	};
	class Talking_SoundSet2138: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2138"
		};
	};
	class Talking_SoundSet2139: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2139"
		};
	};
	class Talking_SoundSet2140: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2140"
		};
	};
	class Talking_SoundSet2141: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2141"
		};
	};
	class Talking_SoundSet2142: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2142"
		};
	};
	class Talking_SoundSet2143: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2143"
		};
	};
	class Talking_SoundSet2144: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2144"
		};
	};
	class Talking_SoundSet2145: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2145"
		};
	};
	class Talking_SoundSet2146: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2146"
		};
	};
	class Talking_SoundSet2147: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2147"
		};
	};
	class Talking_SoundSet2148: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2148"
		};
	};
	class Talking_SoundSet2149: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2149"
		};
	};
	class Talking_SoundSet2150: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2150"
		};
	};
	class Talking_SoundSet2151: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2151"
		};
	};
	class Talking_SoundSet2152: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2152"
		};
	};
	class Talking_SoundSet2153: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2153"
		};
	};
	class Talking_SoundSet2154: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2154"
		};
	};
	class Talking_SoundSet2155: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2155"
		};
	};
	class Talking_SoundSet2156: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2156"
		};
	};
	class Talking_SoundSet2157: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2157"
		};
	};
	class Talking_SoundSet2158: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2158"
		};
	};
	class Talking_SoundSet2159: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2159"
		};
	};
	class Talking_SoundSet2160: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2160"
		};
	};
	class Talking_SoundSet2161: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2161"
		};
	};
	class Talking_SoundSet2162: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2162"
		};
	};
	class Talking_SoundSet2163: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2163"
		};
	};
	class Talking_SoundSet2164: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2164"
		};
	};
	class Talking_SoundSet2165: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2165"
		};
	};
	class Talking_SoundSet2166: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2166"
		};
	};
	class Talking_SoundSet2167: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2167"
		};
	};
	class Talking_SoundSet2168: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2168"
		};
	};
	class Talking_SoundSet2169: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2169"
		};
	};
	class Talking_SoundSet2170: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2170"
		};
	};
	class Talking_SoundSet2171: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2171"
		};
	};
	class Talking_SoundSet2172: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2172"
		};
	};
	class Talking_SoundSet2173: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2173"
		};
	};
	class Talking_SoundSet2174: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2174"
		};
	};
	class Talking_SoundSet2175: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2175"
		};
	};
	class Talking_SoundSet2176: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2176"
		};
	};
	class Talking_SoundSet2177: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2177"
		};
	};
	class Talking_SoundSet2178: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2178"
		};
	};
	class Talking_SoundSet2179: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2179"
		};
	};
	class Talking_SoundSet2180: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2180"
		};
	};
	class Talking_SoundSet2181: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2181"
		};
	};
	class Talking_SoundSet2182: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2182"
		};
	};
	class Talking_SoundSet2183: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2183"
		};
	};
	class Talking_SoundSet2184: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2184"
		};
	};
	class Talking_SoundSet2185: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2185"
		};
	};
	class Talking_SoundSet2186: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2186"
		};
	};
	class Talking_SoundSet2187: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2187"
		};
	};
	class Talking_SoundSet2188: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2188"
		};
	};
	class Talking_SoundSet2189: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2189"
		};
	};
	class Talking_SoundSet2190: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2190"
		};
	};
	class Talking_SoundSet2191: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2191"
		};
	};
	class Talking_SoundSet2192: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2192"
		};
	};
	class Talking_SoundSet2193: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2193"
		};
	};
	class Talking_SoundSet2194: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2194"
		};
	};
	class Talking_SoundSet2195: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2195"
		};
	};
	class Talking_SoundSet2196: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader2196"
		};
	};
	class Talking_SoundSet4501: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4501"
		};
	};
	class Talking_SoundSet4502: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4502"
		};
	};
	class Talking_SoundSet4503: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4503"
		};
	};
	class Talking_SoundSet4504: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4504"
		};
	};
	class Talking_SoundSet4505: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4505"
		};
	};
	class Talking_SoundSet4506: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4506"
		};
	};
	class Talking_SoundSet4507: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4507"
		};
	};
	class Talking_SoundSet4508: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4508"
		};
	};
	class Talking_SoundSet4509: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4509"
		};
	};
	class Talking_SoundSet4510: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4510"
		};
	};
	class Talking_SoundSet4511: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4511"
		};
	};
	class Talking_SoundSet4512: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4512"
		};
	};
	class Talking_SoundSet4513: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4513"
		};
	};
	class Talking_SoundSet4514: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4514"
		};
	};
	class Talking_SoundSet4515: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4515"
		};
	};
	class Talking_SoundSet4516: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4516"
		};
	};
	class Talking_SoundSet4517: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4517"
		};
	};
	class Talking_SoundSet4518: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4518"
		};
	};
	class Talking_SoundSet4519: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4519"
		};
	};
	class Talking_SoundSet4520: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4520"
		};
	};
	class Talking_SoundSet4521: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4521"
		};
	};
	class Talking_SoundSet4522: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4522"
		};
	};
	class Talking_SoundSet4523: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4523"
		};
	};
	class Talking_SoundSet4524: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4524"
		};
	};
	class Talking_SoundSet4525: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4525"
		};
	};
	class Talking_SoundSet4526: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4526"
		};
	};
	class Talking_SoundSet4527: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4527"
		};
	};
	class Talking_SoundSet4528: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4528"
		};
	};
	class Talking_SoundSet4529: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4529"
		};
	};
	class Talking_SoundSet4530: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4530"
		};
	};
	class Talking_SoundSet4531: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4531"
		};
	};
	class Talking_SoundSet4532: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4532"
		};
	};
	class Talking_SoundSet4533: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4533"
		};
	};
	class Talking_SoundSet4534: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4534"
		};
	};
	class Talking_SoundSet4535: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4535"
		};
	};
	class Talking_SoundSet4536: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4536"
		};
	};
	class Talking_SoundSet4537: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4537"
		};
	};
	class Talking_SoundSet4538: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4535"
		};
	};
	class Talking_SoundSet4539: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4536"
		};
	};
	class Talking_SoundSet4540: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4537"
		};
	};
	class Talking_SoundSet4550: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4550"
		};
	};
	class Talking_SoundSet4551: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4551"
		};
	};
	class Talking_SoundSet4552: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4552"
		};
	};
	class Talking_SoundSet4553: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4553"
		};
	};
	class Talking_SoundSet4554: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4554"
		};
	};
	class Talking_SoundSet4555: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4555"
		};
	};
	class Talking_SoundSet4556: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4556"
		};
	};
	class Talking_SoundSet4557: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4557"
		};
	};
	class Talking_SoundSet4558: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4558"
		};
	};
	class Talking_SoundSet4559: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4559"
		};
	};
	class Talking_SoundSet4560: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader4560"
		};
	};
	class Talking_SoundSet5001: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5001"
		};
	};
	class Talking_SoundSet5002: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5002"
		};
	};
	class Talking_SoundSet5003: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5003"
		};
	};
	class Talking_SoundSet5004: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5004"
		};
	};
	class Talking_SoundSet5005: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5005"
		};
	};
	class Talking_SoundSet5006: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5006"
		};
	};
	class Talking_SoundSet5007: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5007"
		};
	};
	class Talking_SoundSet5008: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5008"
		};
	};
	class Talking_SoundSet5009: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5009"
		};
	};
	class Talking_SoundSet5010: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5010"
		};
	};
	class Talking_SoundSet5011: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5011"
		};
	};
	class Talking_SoundSet5012: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5012"
		};
	};
	class Talking_SoundSet5013: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5013"
		};
	};
	class Talking_SoundSet5014: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5014"
		};
	};
	class Talking_SoundSet5015: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5015"
		};
	};
	class Talking_SoundSet5016: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5016"
		};
	};
	class Talking_SoundSet5017: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5017"
		};
	};
	class Talking_SoundSet5018: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5018"
		};
	};
	class Talking_SoundSet5019: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5019"
		};
	};
	class Talking_SoundSet5020: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5020"
		};
	};
	class Talking_SoundSet5021: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5021"
		};
	};
	class Talking_SoundSet5022: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5022"
		};
	};
	class Talking_SoundSet5023: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5023"
		};
	};
	class Talking_SoundSet5024: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5024"
		};
	};
	class Talking_SoundSet5025: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5025"
		};
	};
	class Talking_SoundSet5026: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5026"
		};
	};
	class Talking_SoundSet5027: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5027"
		};
	};
	class Talking_SoundSet5028: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5028"
		};
	};
	class Talking_SoundSet5029: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5029"
		};
	};
	class Talking_SoundSet5030: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5030"
		};
	};
	class Talking_SoundSet5031: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5031"
		};
	};
	class Talking_SoundSet5032: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5032"
		};
	};
	class Talking_SoundSet5033: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5033"
		};
	};
	class Talking_SoundSet5034: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5034"
		};
	};
	class Talking_SoundSet5035: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5035"
		};
	};
	class Talking_SoundSet5036: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5036"
		};
	};
	class Talking_SoundSet5037: baseCharacter_SoundSet
	{
		soundShaders[]=
		{
			"Talking_SoundShader5037"
		};
	};
};
