class CfgPatches
{
	class ND_VPPM
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"VanillaPlusPlus"
		};
		author="AlPepino";
		authorID="76561198077747785";
		name="ND_VPPM";
		url="";
	};
};
class CfgMods
{
	class ND_VPPM
	{
		type="mod";
		dependencies[]=
		{
			"Mission"
		};
		class defs
		{
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"ND_CORE/scripts/Common",
					"ND_MISSIONS/scripts/Common",
					"ND_VPPM/scripts/5_Mission"
				};
			};
		};
	};
};
