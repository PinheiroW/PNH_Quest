class CfgPatches
{
	class 0_PNH_Missions
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
	};
};

class CfgMods
{
	class 0_PNH_Missions
	{
		type="mod";
		name="ND - Missions";
	    dependencies[] = {"GameLib","Game", "World", "Mission"};
	    class defs	    
		{	
			class gameLibScriptModule
			{
				value = "";
				files[] = {"0_PNH_Missions/scripts/Common"};
			};		
			class gameScriptModule
            {
                value = "";
				files[] = {"0_PNH_Missions/scripts/Common"};
            };			
			class worldScriptModule
            {
                value = "";
				files[] = {"0_PNH_Missions/scripts/Common"};
            };
			class missionScriptModule
            {
                value = "";
				files[] = {"0_PNH_Missions/scripts/Common"};
            };
        };
    };
};
