class CfgPatches
{
	class ND_MISSIONS
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
		author="Pinheiro";
		authorID="";
		name="ND_MISSIONS - Assets Pack";
		url="";
	};
};

class CfgMods
{
	class ND_MISSIONS
	{
		type="mod";
		name="ND - Missions Assets";
		dependencies[]={};
		class defs
		{
			class imageSets
			{
				files[]=
				{
					"ND_MISSIONS/gui/imagesets/nd_dayz_gui.imageset"
				};
			};
		};
	};
};