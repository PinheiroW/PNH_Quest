class BXD_Missions
{
	//Mission constants
	const string SMM_MISSION_SAVEFILE = "$profile:\\SurvivorMissions\\Cleanup\\MissionSave.txt";
	const string SMM_MISSION_VEHICLE = "$profile:\\SurvivorMissions\\Cleanup\\MissionVehicle.txt";
	const float SMM_RADIO_FREQUENCY = MissionSettings.GetRadioFrequency();		
	
	//changed by current mission
	static int m_MissionTimeout = 60;
	protected static float m_MissionZoneInnerRadius = 2.0;			
	protected static float m_MissionZoneOuterRadius = 200.0;
	protected static string m_MissionInformant;
	protected static string m_MissionMessage1;
	protected static string m_MissionMessage2;
	protected static string m_MissionMessage3;
	protected static bool m_MissionExtended = false;

	//Mission runtime & timers  
	private static int m_MissionStartTime;
	static int m_MissionTime;
	private static int m_MissionCountdown;	

	//Mission preselection & description							
	protected static int m_selectedMission;
	private static string m_selectedMissionType;
	private static string m_selectedMissionLoc;
	private static string m_oldMissionType;
	private static string m_oldoldMissionType;
	private static string m_oldMissionLoc;
	private static string m_oldoldMissionLoc;
	protected static vector m_MissionPosition;
	protected static string m_MissionName;
	protected static string m_MissionDescription[4];
	protected static string m_MissionType;
	protected static string m_MissionLocation;
	protected static string m_MissionLocationDir;
	protected static string m_MissionSecondaryLoc;
	protected static int m_actualRPMission = 0;
	
	//Mission initialization
	static bool m_MissionActiv = false;
	private static bool m_ZoneIsTriggered = false;
	private static bool m_InitCompleted = false;
	static bool m_MissionFinished = false;
	static bool m_MissionTimedOut = false;
	static bool m_RewardsSpawned = false;
	protected static bool m_ContainerWasTaken = false;
	static int m_MsgChkTime = 0;
	static int m_MsgNum = 0;
	static bool m_MsgStart = false;
	static bool MsgCutoff = false;
	static bool FinishMsgSentAll = false;
	static bool TimeOutMsgSentAll = false;
	private static bool m_MissionTargetFound = false;
			
	//Mission containers
	static ref array<string> m_MissionEvents = new array<string>;
	static ref array<vector> m_MissionPositions = new array<vector>;
	protected static ref array<Object> m_MissionObjects = new array<Object>;
	protected static ref array<Object> m_MissionAIs = new array<Object>;
	protected static ref array<string> m_PlayersInZone = new array<string>;
	ref array<Object> m_ObjectList = new array<Object>; 
	ref array<CargoBase> m_ObjectCargoList = new array<CargoBase>;
	
	//Mission instance
	static ref BXD_Missions m_MissionInstance;
	
	void BXD_Missions()
	{	
		//OPTION: Clean up last mission position after server restart
		if ( !m_InitCompleted && MissionSettings.Opt_OnStartCleanUp )
		{
			int OSCUDelay = MissionSettings.CleanUpDlyTime * 1000;
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.OnStartCleanUp, OSCUDelay , false );
			m_InitCompleted = true;
		}

		if ( m_MissionActiv )
		{
			//calculate mission runtime & countdown
			m_MissionTime = GetGame().GetTime() * 0.001 - m_MissionStartTime;
			m_MissionCountdown = ( m_MissionTimeout - m_MissionTime )/60;
			
			//check if mission timed out
			if ( m_MissionTime >= m_MissionTimeout && !m_MissionTimedOut ) 
			{
				m_MsgNum = -2;
				m_MsgChkTime = m_MissionTime;
				m_MissionTimedOut = true;
			}			
			
			//deactivate mission & despawn mission main object after mission timeout or mission finishing of a player
			if (( m_MissionTimedOut && TimeOutMsgSentAll ) || ( m_RewardsSpawned && FinishMsgSentAll ))
			{
				m_MissionFinished = true;		//Mission finished, sending no further radio messages for this mission 
				m_MissionActiv = false;			//deactivate mission
				
				//Call Despawner
				if ( m_ZoneIsTriggered ) MissionObjDespawner();
				
				//Init mission switches				
				m_MissionTimedOut = false;
				m_ZoneIsTriggered = false;				
				m_RewardsSpawned = false;
				
				//Init Messenger
				TimeOutMsgSentAll = false;
				FinishMsgSentAll = false;				
				m_MissionTime = 0;				
				m_MsgNum = 0;
				m_MsgChkTime = 0;
			}
		} 
	}
	
	void OnStartCleanUp()
	{	//This function has to be executed some time AFTER the server restart (when CE is already loaded!)
		//Delete items at old mission position after server restart, every item gets deleted not only mission objects
		float CleanUpRadius = 30.0;			//! DO NOT CHANGE RADIUS ! (30m is the max. radius a mission can spawn mission objects)
		string ReadData;
		vector CleanupPos;

		FileHandle MsaveBckUp = OpenFile( SMM_MISSION_SAVEFILE , FileMode.READ );
		if ( FileExist( SMM_MISSION_SAVEFILE ) )
		{	
			while ( FGets( MsaveBckUp, ReadData ) > -1 )
			{				
				CleanupPos = ReadData.ToVector();
				GetGame().GetObjectsAtPosition( CleanupPos , CleanUpRadius , m_ObjectList , m_ObjectCargoList );
				for ( int i = 0 ; i < m_ObjectList.Count() ; i++ )
				{ 
					Object FoundObject = m_ObjectList.Get(i);
					Print( FoundObject );
					if ( FoundObject.IsItemBase() || FoundObject.GetType() == "Wreck_UH1Y" )
					{
						GetGame().ObjectDelete( FoundObject );
						Print("[SMM] OnStartCleanUp :: Object  "+ FoundObject.ToString() +" from abborted mission at last server session was deleted.");
					}
				}
			}
			CloseFile( MsaveBckUp );
			DeleteFile( SMM_MISSION_SAVEFILE );
		}
		else Print("[SMM] OnStartCleanUp :: No mission save file was found, no items to delete.");
		
		//Delete mission car from old mission after server restart 
		if ( FileExist( SMM_MISSION_VEHICLE ) ) 
		{
			Print("[SMM] OnStartCleanUp :: No mission vehicle was found, deleting mission vehicle save file.");
			DeleteFile( SMM_MISSION_VEHICLE );			
		}
		else Print("[SMM] OnStartCleanUp :: No mission vehicle save file was found.");
	}
		
	void StartNewMission()
	{
		//rem last 2 missions to exclude in new mission selection
		m_oldoldMissionType = m_oldMissionType;
		m_oldMissionType = m_selectedMissionType;
		m_oldoldMissionLoc = m_oldMissionLoc;
		m_oldMissionLoc = m_selectedMissionLoc;
		
		//set mission start time & init checktime
		m_MissionStartTime = GetGame().GetTime() * 0.001;
		m_MsgChkTime = 0;
		
		//select & activate mission
		m_MissionActiv = true;
		m_MissionTargetFound = false;
		m_MissionFinished = false;
		MsgCutoff = false;
		m_ZoneIsTriggered = false;
		m_MissionExtended = false;
		
		SelectMission();
		
		Print("[SMM] Mission zone is active. Waiting for trigger...");
		
		//Get mission type from description 
		m_MissionType = m_MissionDescription[0];		
	}
		
	void SelectMission()
	{
		if ( MissionSettings.Opt_RPmode )
		{	
			if ( MissionSettings.Opt_RPlist.Count() < 1 ) Print("[SMM] ERROR : Can't select RP mission, no missions are defined in RPList!");
			else
			{
				//RP mode mission selection
				if ( m_actualRPMission >= MissionSettings.Opt_RPlist.Count() ) m_actualRPMission = 0;
				m_selectedMission = MissionSettings.Opt_RPlist.Get( m_actualRPMission );
				m_actualRPMission++;
				
				//Get description by parsing the name 
		        m_MissionName = m_MissionEvents.Get( m_selectedMission );
				m_MissionName.ParseString( m_MissionDescription );
				m_selectedMissionType = m_MissionDescription[0];
				m_selectedMissionLoc = m_MissionDescription[1];								
			}
		}
		else
		{
			//Count Events in EWD list
			int MissionCount  = m_MissionEvents.Count();
	        m_selectedMission = Math.RandomIntInclusive( 0, MissionCount - 1 );
			
			//Mission override in debug mode, adjust in MissionSettings 
			if ( MissionSettings.DebugMode && MissionSettings.DebugMission <= MissionCount - 1 && MissionSettings.DebugMission >= 0 )
			{
				m_selectedMission = MissionSettings.DebugMission;
				m_oldMissionType 	= "";
				m_oldoldMissionType = "";
				m_oldMissionLoc 	= "";
				m_oldoldMissionLoc 	= "";
			}
			
			//Get description by parsing the name 
	        m_MissionName = m_MissionEvents.Get( m_selectedMission );
			m_MissionName.ParseString( m_MissionDescription );
			m_selectedMissionType = m_MissionDescription[0];
			m_selectedMissionLoc = m_MissionDescription[1];
					
			//check if choosen mission type and location is equal to the last 2 missions & get new event in case		
			if ( MissionCount > 10 )
			{
				while ( m_selectedMissionType == m_oldMissionType || m_selectedMissionType == m_oldoldMissionType || m_selectedMissionLoc == m_oldMissionLoc || m_selectedMissionLoc == m_oldoldMissionLoc )
				{
					m_selectedMission = Math.RandomIntInclusive( 0, MissionCount - 1 );
	       			m_MissionName = m_MissionEvents.Get( m_selectedMission );
					m_MissionName.ParseString( m_MissionDescription );
					m_selectedMissionType = m_MissionDescription[0];
					m_selectedMissionLoc = m_MissionDescription[1];		
				}
			}
		}
		//get MissionPosition from List 
        m_MissionPosition = m_MissionPositions.Get( m_selectedMission );
		
		//Get mission type from description 
		m_MissionType = m_MissionDescription[0];
		
		//Get mission location & direction from description
		array<string> ReplaceString = new array<string>;
		int i;
		
		m_MissionLocation = m_MissionDescription[1];
		m_MissionLocationDir = m_MissionDescription[2];
		m_MissionSecondaryLoc = m_MissionDescription[3];
		
		//convert to notification format	
		m_MissionLocation.Split("_", ReplaceString );
		m_MissionLocation = "";
		
		for (i = 0; i < ReplaceString.Count(); i++)
		{
			if ( i < ReplaceString.Count() - 1 ) m_MissionLocation += ReplaceString.Get(i) + " ";
			else m_MissionLocation += ReplaceString.Get(i);
		}
		
		ReplaceString = new array<string>;
		m_MissionSecondaryLoc.Split("_", ReplaceString );
		m_MissionSecondaryLoc = "";
		
		for (i = 0; i < ReplaceString.Count(); i++)
		{
			if ( i < ReplaceString.Count() - 1 ) m_MissionSecondaryLoc += ReplaceString.Get(i) + " ";
			else m_MissionSecondaryLoc += ReplaceString.Get(i);
		}
		
		
		Print("[SMM] New selected mission is "+ m_MissionType +" mission "+ m_selectedMission +" @ "+ m_MissionPosition +" : "+ m_MissionLocationDir +" of "+ m_MissionLocation );	
		
		//Instantiate mission
		EventsWorldData.BuildInstance();
	}

	void MissionZoneTrigger( PlayerBase player )
	{		
		string SurvivorID = player.GetIdentity().GetPlainId(); //GetPlayerId(); // GetId(); //GetPlainId();
		string ZoneEntryMsg = "I am almost here! ..."+ m_MissionCountdown +" minutes left before the mission ends!";
		string TargetFoundMsg = "I have found it.";
		Param1<string> Msg;		
		float SurvivorDistance;
		int PlayerListPosition = m_PlayersInZone.Find( SurvivorID );
		bool PlayerIsInList = false;

		if ( PlayerListPosition > -1 ) PlayerIsInList = true;

		SurvivorDistance = vector.Distance( player.GetPosition(), m_MissionPosition );

		if ( SurvivorDistance <= m_MissionZoneInnerRadius && m_ZoneIsTriggered && !m_MissionTargetFound )
		{
			Print("[SMM] Survivor with SteamID64: " + SurvivorID + " has found the mission target.");
			if ( MissionSettings.Opt_MsgTypeRadio )
			NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 15.0, MissionSettings.TargetFoundMsg, "", "set:ccgui_enforce image:MapShieldBooster");
			else
			{
				Msg = new Param1<string>( TargetFoundMsg );
				GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
			}
			
			if ( !m_MissionExtended )
			{
				if ( MissionSettings.DebugMode ) Print("[SMM] Finishing mission...");
				m_MissionTargetFound = true;
				MissionFinal();
			}
			else
			{
				if ( MissionSettings.DebugMode ) Print("[SMM] Extending Mission...");

				MsgCutoff = false;
				m_MissionExtended = false;
				m_ZoneIsTriggered = false;
				m_PlayersInZone.Clear();
				PlayerIsInList = false;
				ExtendMission();
				SurvivorDistance = vector.Distance( player.GetPosition(), m_MissionPosition );				
			}
		}		
		
		if ( SurvivorDistance <= m_MissionZoneOuterRadius )
		{				
			if ( !PlayerIsInList )
			{
				m_PlayersInZone.Insert( SurvivorID );
					
				if ( MissionSettings.Opt_MsgTypeRadio )
				NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 15.0, MissionSettings.ZoneEnterMsg, m_MissionCountdown.ToString() + MissionSettings.TimeLeftMsg, "set:ccgui_enforce image:HudMove");
				else
				{
					Msg = new Param1<string>( ZoneEntryMsg );
					GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );				
				}
								
				Print("[SMM] Player with SteamID64: "+ SurvivorID +" has entered the mission zone and was added to the PlayersInZone list.");
				Print("[SMM] Current players count in mission zone : "+ m_PlayersInZone.Count() );
			}
			
			if ( !m_ZoneIsTriggered )
			{
				m_ZoneIsTriggered = true;

				Print("[SMM] Mission zone was triggered by player, deploying mission...");
				MissionObjSpawner();
			}
		}
		else 
		{
			if ( PlayerIsInList && SurvivorDistance >= m_MissionZoneOuterRadius + 10.0 )
			{
				m_PlayersInZone.RemoveItem( SurvivorID );
				
				if ( MissionSettings.Opt_MsgTypeRadio )
				NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 15.0, MissionSettings.ZoneLeaveMsg, "", "set:ccgui_enforce image:HudLeave");
				else
				{
					Msg = new Param1<string>("You have left the mission zone!");
					GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );				
				}
								
				Print("[SMM] Player with SteamID64: " + SurvivorID + " has left the mission zone and was removed from the PlayersInZone list.");
				Print("[SMM] PlayersInZone count: "+ m_PlayersInZone.Count() );
				PlayerIsInList = false;
			}
		}
		
		//execute checks for mission objects manipulated by player
		if ( m_ZoneIsTriggered && PlayerIsInList )	PlayerChecks( player );			
	}
	
	void MissionObjSpawner()
	{				
		//Deploy mission
		if ( DeployMission() )	GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( m_MissionInstance.MissionSave, 2000 );
		else Print("[SMM] WARNING :: Mission couldn't be deployed. Mission rejected!");
	}

	void MissionSave()
	{
		//Backup mission positions to file for OnStartCleanup after server crash / shutdown
		FileHandle MsaveStore;
		string strPos;

		if ( m_MissionExtended ) Print("[SMM] MISSONSAVE : Saving primary mission position to file.");
		else Print("[SMM] MISSIONSAVE : Saving mission position to file.");
		
		if ( !IsExtended() || ( IsExtended() && m_MissionExtended ))
		{
			if ( FileExist( SMM_MISSION_SAVEFILE ))	DeleteFile( SMM_MISSION_SAVEFILE );
			
			MsaveStore = OpenFile( SMM_MISSION_SAVEFILE , FileMode.WRITE );
			if ( MsaveStore )
			{
				strPos = m_MissionPosition[0].ToString() +" "+ m_MissionPosition[1].ToString() +" "+ m_MissionPosition[2].ToString();
				FPrint( MsaveStore, strPos );
				CloseFile( MsaveStore );
			}
			else
			{
				Print("[SMM] WARNING :: Mission save file is unwriteable, check server launch option: -profiles and destination folder $profile:\\SurvovorMissions\\CleanUp\\");
			}
		}
		else
		{
			MsaveStore = OpenFile( SMM_MISSION_SAVEFILE , FileMode.APPEND );
			if ( MsaveStore )
			{
				strPos = "\n"+ m_MissionPosition[0].ToString() +" "+ m_MissionPosition[1].ToString() +" "+ m_MissionPosition[2].ToString();
				FPrintln( MsaveStore, strPos );
				CloseFile( MsaveStore );
			}
			else
			{
				Print("[SMM] WARNING :: Mission save file is unwriteable, check server launch option: -profiles and destination folder $profile:\\SurvovorMissions\\CleanUp\\");
			}								
		}
		
		//Backup mission cars as central economy entities to file for OnStartCleanup after server crash / shutdown
		if ( m_MissionObjects[0] && m_MissionObjects[0].IsTransport() )
		{
			if ( FileExist( SMM_MISSION_VEHICLE )) 
			{
				if ( DeleteFile( SMM_MISSION_VEHICLE ))
				Print("[SMM] Mission vehicle save file was deleted.");
				else Print("[SMM] WARNING :: Mission vehicle save file can't be deleted. Check Permissions!");
			}
			else Print("[SMM] Vehicle from new mission gets saved to file.");
						
			int b1, b2, b3, b4;
			string strVeh;
			Car MissionVehicle = Car.Cast( m_MissionObjects[0] );
			MissionVehicle.GetPersistentID( b1, b2, b3, b4);
			
			FileHandle MsaveVehicle = OpenFile( SMM_MISSION_VEHICLE, FileMode.WRITE );
			if ( MsaveVehicle )
			{
				strVeh = b1.ToString() +" "+ b2.ToString() +" "+ b3.ToString() +" "+ b4.ToString();
				FPrint( MsaveVehicle, strVeh );
				CloseFile( MsaveVehicle );
			}
		}	
	}
	
	void MissionObjDespawner()
	{
		//Pre-despawner function 
		
		Print("[SMM] Despawning mission objects from actual mission...");
		ObjDespawn();
	}

	void MissionMessenger( PlayerBase player )
	{		
		//Messaging sequence
		m_MissionCountdown = ( m_MissionTimeout - m_MissionTime )/60; 	//refresh countdown
		int MsgDelayTime = 20;
		Param1<string> Msg;
		string message;
		string icon;
			
		if ( m_MissionCountdown <= MissionSettings.MsgCutoffTime && !MsgCutoff )
		{
			MsgCutoff = true;
			if ( MissionSettings.DebugMode )
			Print("[SMM] MissionCountdown = "+ m_MissionCountdown +" minutes. Messaging Cutoff activated. Sending no further radio messages to players!"); 
		}	
		
		if ( !MsgCutoff )
		{			
			if ( m_MsgNum > 4 || ( m_MsgChkTime - m_MissionTime > MsgDelayTime && m_MsgNum > -1 ))
			{
				m_MsgNum = 0;
				m_MsgChkTime = 0;
			}

			if ( m_MsgNum == 0 && m_MissionTime >= m_MsgChkTime + MsgDelayTime )
			{
				if ( MissionSettings.Opt_MsgTypeRadio )
				{
					if ( RadioCheck( player ))
					{
						message = MissionSettings.StartingMsg;
						icon = "set:dayz_inventory image:walkietalkie";			
						NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 8.0, m_MissionInformant + ":", message, icon );				
					}
				}
				else
				{				
					Msg = new Param1<string> ("I have found a message!");
					GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
				}		

				m_MsgStart = true;
			}
		
			if ( m_MsgNum == 1 && m_MissionTime >= m_MsgChkTime + 15 )
			{
				if ( MissionSettings.Opt_MsgTypeRadio )
				{
					if ( RadioCheck( player ))
					{
						icon = "set:dayz_inventory image:walkietalkie";		
						NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 20.0, m_MissionInformant + ":", m_MissionMessage1, icon );				
					}
				}	
				else
				{			
					Msg = new Param1<string> ( "I should go to "+ m_MissionLocationDir +" of "+ m_MissionLocation +"." );
					GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
				}

				m_MsgStart = true;
			}
			
			if ( m_MsgNum == 2 && m_MissionTime >= m_MsgChkTime + 27 )
			{
				if ( MissionSettings.Opt_MsgTypeRadio )
				{
					if ( RadioCheck( player ))
					{
						icon = "set:dayz_inventory image:walkietalkie";			
						NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 20.0, m_MissionInformant + ":", m_MissionMessage2, icon );
					}
				}	
				else
				{				
					Msg = new Param1<string> ( "There is a "+ m_MissionType +" mission with some good survival equipment." );
					GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
				}

				m_MsgStart = true;
			}
			
			if ( m_MsgNum == 3 && m_MissionTime >= m_MsgChkTime + 27 )
			{
				if ( MissionSettings.Opt_MsgTypeRadio )
				{
					if ( RadioCheck( player ))
					{
						message = m_MissionMessage3 +"\n\n"+ m_MissionCountdown + MissionSettings.Message3Ext;
						icon = "set:dayz_inventory image:walkietalkie";					
						NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 20.0, m_MissionInformant + ":", message, icon);
					}
				}
				else
				{
					Msg = new Param1<string> ( "I have to be careful. Only "+ m_MissionCountdown +" minutes remaining. Let's get it!" );
					GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
				}

				m_MsgStart = true;
			}
			
			if ( m_MsgNum == 4 && m_MissionTime >= m_MsgChkTime + MissionSettings.MsgWaitTime )	m_MsgNum++;					
		}
		
		//send mission finished message
		if ( m_MsgNum == -1 && m_MissionTime >= m_MsgChkTime ) //PlayerCanRecieve && TEST Radio check!!!
		{
			if ( MissionSettings.Opt_MsgTypeRadio )
			{
				if ( RadioCheck( player ))
				{
					message = MissionSettings.FinishingMsg;
					icon = "set:dayz_inventory image:walkietalkie";
					NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 10.0, m_MissionInformant + ":", message, icon );
				}
			}
			else
			{
				Msg = new Param1<string> ( "Somebody has finished the mission!" );
				GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
			}

			m_MsgStart = true;
		}
		
		if ( m_MsgNum == -2 && m_MissionTime >= m_MsgChkTime )
		{
			if ( MissionSettings.Opt_MsgTypeRadio )
			{
				if ( RadioCheck( player ))
				{
					message = MissionSettings.TimeoutMsg;
					icon = "set:dayz_inventory image:walkietalkie";
					NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity() , 10.0, m_MissionInformant + ":", message, icon );
				}
			}
			else
			{
				Msg = new Param1<string> ( "Mission timed out. You are too late!" );
				GetGame().RPCSingleParam( player, ERPCs.RPC_USER_ACTION_MESSAGE, Msg, true, player.GetIdentity() );
			}

			m_MsgStart = true;
		}						
	}
		
	bool RadioCheck( PlayerBase player )
	{
		return true; 
	}
	
	bool OldRadioCheck( PlayerBase player )
	{
		ref array<EntityAI> PlayerItems = new array<EntityAI>;
		
		if ( player.GetInventory().EnumerateInventory( InventoryTraversalType.PREORDER, PlayerItems ) ) //LEVELORDER, PREORDER, INORDER, POSTORDER
		{		
			for ( int i=0; i < PlayerItems.Count(); i++ )
			{
				EntityAI entity_item = PlayerItems.Get(i);
				ItemBase item;
				Class.CastTo(item, entity_item);
				
				if ( item && item.IsTransmitter() )
				{
					ItemTransmitter Transmitter;
					InventoryItem inv_item;
				
					Class.CastTo(Transmitter, item);
					Class.CastTo(inv_item, entity_item);
				
					if ( inv_item.IsOn() && Transmitter.IsReceiving() && Transmitter.GetTunedFrequency() == SMM_RADIO_FREQUENCY ) return true;
				}
			}
			return false;
		}
		else return false; 
	}
	
	//Module interfaces declaration
	
	bool IsExtended() return m_MissionInstance.IsExtended();
	
	bool DeployMission()
	{
		if ( m_MissionInstance )
		{
			if ( !m_MissionInstance.DeployMission() )
			{
				Print("[SMM] ERROR :: Mission couldn't be deployed!");
				return false;
			}
			else return true;
		}
		else 
		{
			Print("[SMM] ERROR :: Mission instance doesn't exist. Can't deploy mission!");
			return false;
		}
	}
	
	void ObjDespawn()
	{
		if ( m_MissionInstance != null )	m_MissionInstance.ObjDespawn();
		else Print("[SMM] ERROR :: Mission instance doesn't exist. Can't despawn mission objects!");
	}
	
	void MissionFinal()
	{
		if ( m_MissionInstance != null )	m_MissionInstance.MissionFinal();
		else Print("[SMM] ERROR :: Mission instance doesn't exist. Can't finalize mission!");	
	}
	void ExtendMission()
	{
		if ( m_MissionInstance != null )	m_MissionInstance.ExtendMission();
		else Print("[SMM] ERROR :: Mission instance doesn't exist. Can't extend mission!");
	}
	void PlayerChecks( PlayerBase player )
	{
		if ( m_MissionInstance != null )	m_MissionInstance.PlayerChecks( player );
		else Print("[SMM] ERROR :: Mission instance doesn't exist. Can't execute player checks!");	
	}
}

