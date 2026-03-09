#include "$profile:\\SurvivorMissions\\MissionSettings.c"

modded class MissionServer
{
	const string SMM_LOG_DIR = "$profile:\\SurvivorMissions";
	const string SMM_SURVIVORSTORIES_FILE = MissionSettings.GetStoriesFilePath() + GetGame().GetWorldName() +".txt";
	const string SEM_SCRIPT_VERSION = "0.85";
	
	//Survivor stories containers
	ref array<PlayerBase> DisconStoryPlayers = new array<PlayerBase>;
	ref array<string> m_Story = new array<string>;
	
	//Scheduler initialization
	int PlayerAtMsgStart = -1;
	int PlayerAtCrntTick = 0;
	
	//EventsWorldData container
	ref EventsWorldData CacheEvents;
	
	static bool MapChkOK = false;

	void MissionServer()
	{
		//OPTION: Debug mode 
		if ( MissionSettings.DebugMode )
		Print("[SEM] DEBUG MODE is enabled!. Printing advanced logs and executing additional functions for debugging.");
		
		//OPTION: Raycast map for building type, prints found building positions to script log (this will take some time!)
		if ( MissionSettings.DebugMode && MissionSettings.DebugRCbuild )
		EventsWorldData.RCMapByBuilding( MissionSettings.RCbuildType );
			
		Print("[SEM] Initializing SurvivorMissions MOD...");
		
		//Check & create folders
		if ( !FileExist( SMM_LOG_DIR +"\\Cleanup") )
		{
			Print("[SEM] WARNING: Couldn't find Cleanup folder!");
			if ( MakeDirectory( SMM_LOG_DIR +"\\Cleanup") ) Print("[SEM] ...Folder \\Cleanup created.");
			else
			{
				Print("[SEM] ERROR: "+ SMM_LOG_DIR +"\\Cleanup\\ folder couldn't be created. Check permissions!");
				return;				
			}			 
		}
		
		Print("[SEM] Folder check...OK");
	
		//Version & Map check and events chaching		
		if ( EventsWorldData.EWD_SCRIPT_VERSION != SEM_SCRIPT_VERSION )
		{
			Print("[SEM] ERROR: Bad script version. Check file EventsWorldData.c if its up to date! Copy serverfiles from mod folder or download from GitHub!");
			return;
		}
		else Print("[SEM] Version check...OK");
		
		if ( CacheEvents.EWD_MAP_NAME == GetGame().GetWorldName() )
		{
			Print("[SEM] Map check...OK");
			MapChkOK = true;
			CacheEvents = new EventsWorldData();
			if ( MissionSettings.Opt_BuildStatics )	CacheEvents.BuildStatics();
		}
		else
		{
			Print("[SEM] ERROR: Wrong EventsWorldData file for map "+ GetGame().GetWorldName() +" detected. WorldDatafile is for map "+ CacheEvents.EWD_MAP_NAME );
			return;					
		}
		
		//OPTION: Performs MissionBuilding checks on EventsWorldData. Run only once on new EW Data. Enable CheckEWD in MissionSettings! 
		if ( MissionSettings.CheckEWD )		EventsWorldData.CheckEWD();
				
		//OPTION: Prepare SurvivorStories
		if ( MissionSettings.Opt_SendStoryOnDisconn )
		{
			if ( FileExist( SMM_SURVIVORSTORIES_FILE ) ) 
			{			
				FileHandle SurvivorStories = OpenFile( SMM_SURVIVORSTORIES_FILE, FileMode.READ);
				string StoriesText;
			
				while ( FGets( SurvivorStories, StoriesText) > 0) m_Story.Insert( StoriesText ); 
				CloseFile( SurvivorStories );
				if ( m_Story.Count() > 0 )
				Print("[SEM] SurvivorStories file parsed successfully. "+ m_Story.Count() +" stories imported.");
				else Print("[SEM] WARNING: SurvivorStories file contains no story text. No stories will be sent to players.");
			}
			else Print("[SEM] WARNING: SurvivorStories file doesn't exist. No stories will be sent to players.");
		}
		
		Print("[SEM] SURVIVOR EVENTS MANAGER version "+ SEM_SCRIPT_VERSION +" successfully loaded.");
		Print("[SEM] Starting [SURVIVOR MISSION MODULE]...");
		
		if ( GetGame().GetWorldName() == "deerisle" && MapChkOK )
		{
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.MissionExec,10,true);
		}
	}

	override void TickScheduler( float timeslice )
	{
		super.TickScheduler( timeslice );
		
		MissionExec();
	}
	
	void MissionExec()
	{				
		int crntTime = GetGame().GetTime() * 0.001;
		int dlyTime = MissionSettings.DelayTime ;	
		static int chkTime = 0;
		static int chkTimeMsgFreq = 0;
		static int chkTimeDebug = 0;
		static bool CachingDone = false;
		
		BXD_Missions RunningMission = new BXD_Missions();
		if ( MapChkOK && !CachingDone )
		{
			RunningMission.m_MissionEvents.Copy( CacheEvents.MissionEvents );
			RunningMission.m_MissionPositions.Copy( CacheEvents.MissionPositions );
			CachingDone = true;
			
			if ( RunningMission.m_MissionEvents.Count() > 0 )
			Print("[SMM] "+ RunningMission.m_MissionEvents.Count() +" SurvivorEvents successfully cached from EventsWorldData.");
			else Print("[SEM] ERROR :: No Events were chached from SMM! Check variable EWD_MAP_NAME in EventsWorldData.c to match the mpmissions map name! (case sensitive)\n!!! SURVIOR MISSIONS MOD TURNED OFF !!!");		
		}				

		
		//Cyclic player checks and executions
		GetGame().GetWorld().GetPlayerList( m_Players );
		if ( m_Players.Count() > 0 )
		{
			for (int i = 0; i < 1 ; i++) //SCHEDULER_PLAYERS_PER_TICK 
			{
				if ( PlayerAtCrntTick >= m_Players.Count() ) PlayerAtCrntTick = 0;
				PlayerBase currentPlayer = PlayerBase.Cast( m_Players.Get( PlayerAtCrntTick ) );
				
				if ( currentPlayer && RunningMission.m_MissionActiv )
				{
					RunningMission.MissionZoneTrigger( currentPlayer );
					if ( !RunningMission.m_MissionFinished )
					{
						if ( PlayerAtCrntTick != PlayerAtMsgStart )
						{
							RunningMission.MissionMessenger( currentPlayer );
							
							if ( RunningMission.m_MsgStart && PlayerAtMsgStart == -1 )
							{
								PlayerAtMsgStart = PlayerAtCrntTick;

								//if ( MissionSettings.DebugMode )
								//Print("[SMM] Messenger starts messaging at player with index "+ PlayerAtMsgStart );							
							}
							
							//if ( MissionSettings.DebugMode && PlayerAtMsgStart > -1 )
							//Print("[SMM] Sending message "+ RunningMission.m_MsgNum +" to client "+ PlayerAtCrntTick +".");
						}
						else
						{
							RunningMission.m_MsgStart = false;
							RunningMission.m_MsgChkTime = RunningMission.m_MissionTime;
							RunningMission.m_MsgNum++;
							PlayerAtMsgStart = -1;
							
							//if ( MissionSettings.DebugMode ) Print("[SMM] Message was sent to all clients.");
							if ( RunningMission.m_MissionTimedOut )
							{
								Print("[SMM] Mission timed out. MISSION DEACTIVATED !");
								RunningMission.TimeOutMsgSentAll = true;
								RunningMission.m_MsgNum = 0;
							}
							if ( RunningMission.m_RewardsSpawned )
							{
								Print("[SMM] Mission was finished by player and rewards spawned. MISSION DEACTIVATED !");
								RunningMission.FinishMsgSentAll = true;
								RunningMission.m_MsgNum = 0;
							}
						}
					}	
				}
				
				//OPTION: Send SurvivorStories to player on disconnect if no early disconnect or logout cancelation
				if ( MissionSettings.Opt_SendStoryOnDisconn )
				{
					if ( m_LogoutPlayers.Contains( currentPlayer ))
					{
						if ( DisconStoryPlayers.Find( currentPlayer ) == -1 )
						{
							if ( MissionSettings.DebugMode ) 
							Print("[SMM] PlayerLogout : Player trying to log out... sending Story. PlayerLogoutCount : "+ DisconStoryPlayers.Count() );
														
							DisconStoryPlayers.Insert( currentPlayer );
							//int ListPos = DisconStoryPlayers.Count() - 1;
							string Story = m_Story.GetRandomElement();
							string Headline = "Survivor Stories";
							string Picture = "set:dayz_inventory image:paper";
							NotificationSystem.SendNotificationToPlayerIdentityExtended( currentPlayer.GetIdentity() , 60.0, Headline , Story, Picture );
							//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( NotificationSystem.SendNotificationToPlayerIdentityExtended , 13000, false, LogoutPlayer.GetIdentity() , 40.0, Headline , Story, Picture );					
							//GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( DisconStoryPlayers.RemoveItem, 15020, false, DisconStoryPlayers.Get( ListPos ));					 
						}
					}
/*					else
					{
							
						if ( DisconStoryPlayers.Find( currentPlayer ) > -1 )
						{
							if ( MissionSettings.DebugMode ) Print("[SMM] PlayerLogout : Player canceled logout. Sending no Survivor story.");
							GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater( this.QuitMessage, 1000, false );
							DisconStoryPlayers.RemoveItem( currentPlayer );
							
							
						}
											
					}
*/							
					if ( m_LogoutPlayers.Count() == 0 && DisconStoryPlayers.Count() > 0 ) 
					{
						if ( MissionSettings.DebugMode )
						Print("[SMM] PlayerLogout : Player(s) left the server or canceled logout. Deleting DisconStoryPlayer list...");
						DisconStoryPlayers.Clear();
					}
				}
				
				//OPTION: Debug mode + showInfo prints advanced logging information and shows current player position or specific building position 
				//		  and model vector to player pos
				if ( MissionSettings.DebugMode && MissionSettings.DebugShowInfo )
				{
					if ( crntTime >= chkTimeDebug + 33 && currentPlayer != NULL )
					{				
						EventsWorldData.ShowDebugInfo( currentPlayer );
						chkTimeDebug = crntTime;
					}
				}
				
				//NEXT Player
				PlayerAtCrntTick++;
			}
		}
				
		dlyTime += RunningMission.m_MissionTimeout;
		
		//Start new mission
		if ( crntTime >= chkTime + dlyTime )
		{
			RunningMission.StartNewMission();
			chkTime = crntTime;
		}
		
		//OPTION: Inform clients with server chat message of mission radio frequency (this is separated from MissionMessenger!)
		Param1<string> Msg;	
		if ( MissionSettings.Opt_ServerMsgFreq )
		{
			if ( crntTime >= chkTimeMsgFreq )
			{
				if ( m_Players.Count() > 0 )
				{
					Print("[SMM] Sending mission radio frequency info to all clients.");
					for ( int k = 0; k < m_Players.Count(); k++ )
					{
						if ( PlayerAtCrntTick >= m_Players.Count() ) PlayerAtCrntTick = 0;
						PlayerBase player = PlayerBase.Cast( m_Players.Get( PlayerAtCrntTick ) );
						player.OnTick();
						Msg = new Param1<string> ("INFO: A survivor is transmitting via radio on "+ RunningMission.SMM_RADIO_FREQUENCY +" Mhz. Stay tuned for incoming calls!");
						GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity());
						PlayerAtCrntTick++;
					}
				}
				chkTimeMsgFreq = crntTime + MissionSettings.MsgFreqDlyTime;
			}
		}
	}
		
	void QuitMessage()
	{
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).Remove( NotificationSystem.SendNotificationToPlayerIdentityExtended );
	}

}

