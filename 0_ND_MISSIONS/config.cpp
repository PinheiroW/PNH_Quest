class CfgPatches
{
	class 0_ND_MISSIONS
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"DZ_Data"};
	};
};

class CfgMods
{
	class 0_ND_MISSIONS
	{
		type="mod";
		name="ND - Missions";
		dependencies[] = {"Game", "World", "Mission"};
		class defs	    
		{	
			// Carregamos as constantes apenas aqui. 
			// O World e o Mission herdam-nas automaticamente.
			class gameScriptModule
            {
                value = "";
				files[] = {"0_ND_MISSIONS/scripts/Common"};
            };			
			class worldScriptModule
            {
                value = "";
				files[] = {"0_ND_MISSIONS/scripts/4_World"};
            };
			class missionScriptModule
            {
                value = "";
				files[] = {"0_ND_MISSIONS/scripts/5_Mission"};
            };
        };
    };
};