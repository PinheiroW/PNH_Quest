class alpOptionsNotf 
{	
	bool EnableGameInfo									= true;
	bool EnableCharacterInfo							= true;	
	bool EnableNotification								= true;
	int NotificationAlign								= 0; //0/1/2
	bool EnableDeathNotification						= false;
	int ShownMessagesAtOnce	= 3;
	float MessageDisplayedMinimalFor = 5;
	float MessageProlong	=	0.5;  //each 10 char increase displayed time by 0.5 second
}


enum ALPMSTYPE
{
	SMINFO,
	SMIMPORTANT,
	SMPERSONAL,
	SMTRADERIN,
	SMTRADEROUT,
	SMRADIATIONIN,
	SMRADIATIONOUT,
	SMLEVELUP,
	SMLEVELDOWN,
	SMGAINEDEXPUP,
	SMGAINEDEXPDOWN,	
	SMDEATH,
	SMHEADSHOT,
	SMACTIVATE,	
	SMEND,//just ending server messages
	MMCOUNTDOWN,
	MMCONQUER,
	MMDEFEND,
	MMCAPTURE,
	MMPERSONAL,
	MMTRADERSTART,
	MMTRADEREND,
	MMRADIATIONSTART,
	MMRADIATIONEND,
	MMMISSIONCARSTART,
	MMMISSIONCAREND,	
	MMMISSIONSTART,	//non-radiation mission
	MMMISSIONEND,	//non-radiation mission	
	COUNT,
};

autoptr TStringArray ALPMSICON = {
	"PNH_Missions/gui/images/smInfo.paa",
	"PNH_Missions/gui/images/smInfo.paa",
	"PNH_Missions/gui/images/smInfo.paa",
	"PNH_Missions/gui/images/smTrader.paa",
	"PNH_Missions/gui/images/smTrader.paa",
	"PNH_Missions/gui/images/smRadiation.paa",
	"PNH_Missions/gui/images/smRadiation.paa",
	"PNH_Missions/gui/images/levelup.paa",
	"PNH_Missions/gui/images/leveldown.paa",
	"PNH_Missions/gui/images/levelup.paa",
	"PNH_Missions/gui/images/leveldown.paa",	
	"PNH_Missions/gui/images/death.paa",  
	"PNH_Missions/gui/images/headshot.paa", 	
	"PNH_Missions/gui/images/enter.paa",	 	
	"PNH_Missions/gui/images/smInfo.paa", //just for sure, ending SM, from thah point it is required walkie-talkie
	"PNH_Missions/gui/images/time.paa",	
	"PNH_Missions/gui/images/fight.paa", 	 	
	"PNH_Missions/gui/images/flag.paa", 	
	"PNH_Missions/gui/images/flag.paa",
	"PNH_Missions/gui/images/smInfo.paa",
	"PNH_Missions/gui/images/smTrader.paa",
	"PNH_Missions/gui/images/smTrader.paa",
	"PNH_Missions/gui/images/smRadiation.paa",
	"PNH_Missions/gui/images/smRadiation.paa",
	"PNH_Missions/gui/images/mmMissionCar.paa",
	"PNH_Missions/gui/images/mmMissionCar.paa",		
	"PNH_Missions/gui/images/mmMission.paa",
	"PNH_Missions/gui/images/mmMission.paa"
};


autoptr array<int> ALPMSCOLOR = {
	FadeColors.WHITE,
	COLOR_RED,
	COLOR_GREEN,
	COLOR_YELLOW,
	COLOR_YELLOW,
	COLOR_YELLOW,
	COLOR_YELLOW,
	COLOR_GREEN,
	COLOR_GREEN,
	COLOR_GREEN,
	COLOR_RED,	
	COLOR_RED,//ARGB(0,80,80,80),
	COLOR_RED,//ARGB(0,80,80,80),	
	COLOR_GREEN,//ARGB(0,80,80,80),
	FadeColors.WHITE, //just for sure, ending SM, from thah point it is required walkie-talkie
	COLOR_YELLOW,
	COLOR_RED,	
	COLOR_GREEN,
	COLOR_GREEN,
	COLOR_RED,
	FadeColors.WHITE,
	ARGB(255,160,160,160),
	FadeColors.WHITE,
	ARGB(255,160,160,160),
	FadeColors.WHITE,
	ARGB(255,160,160,160),
	FadeColors.WHITE,
	ARGB(255,160,160,160),
};

