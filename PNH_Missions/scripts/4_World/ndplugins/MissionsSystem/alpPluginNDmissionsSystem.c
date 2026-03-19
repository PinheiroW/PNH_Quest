class alpPluginNDmissionsSystem extends alpPlugin
{
	// options
	static ref map<string,int>							m_MissionGroup = new map<string,int>;
	static int CarsCount = 0;
	static ref map<string, int>  						VehicleTypes = new map<string, int>;
	static ref array<FuelStation>	                    FuelStations = new array< FuelStation>;
	
	ref array<ref alpProtectionItem>					alp_ProtectionBonuses;
	ref map<string, ref alpProtectionItem>				alp_ProtectionBonusesMaped;
	
	ref alpOptionsMSradiation 							alp_optionsMSradiation; 
	ref alpOptionsMStrader 								alp_optionsMStrader; 
	
	protected ref alpMissionList						alp_List;
	
	ref map<int, ref alpMission>						alp_Missions;
	ref map<string, ref array<ref alpMission>>			alp_MissionsByName;
		
	ref alpMissionPosition								alp_MissionRegistr; 

	ref map<string,ref alpLoot>							alp_LootMap;
	ref map<string,ref alpVehicles>						alp_VehiclesMap;	
	
	ref map<string,autoptr Param3<int,string,int>>		alp_AllItemsByTag;
	
	// TRADER
	ref alpTraderCore 									alp_TraderCore;

	ref array<string>									alp_HideItems;
	ref array<string>									alp_HideItemsType;	
	
	ref map<string, ref array<ref array<float>>>		m_RegisteredPositions;
	
	// quests
	ref array<int>										alp_ActiveQuestsID;	
	
	// time stamp
	static int alp_Hour;
	static int alp_Minute;
	static int alp_Second;

	void ~alpPluginNDmissionsSystem()
	{
		delete FuelStations;
		delete alp_ProtectionBonuses;
		delete alp_ProtectionBonusesMaped;
		delete alp_optionsMSradiation;					
		delete alp_optionsMStrader; 
		delete alp_List;					
		delete alp_Missions;	
		delete alp_MissionsByName;	
		delete alp_MissionRegistr;	
		delete alp_LootMap; 
		delete alp_VehiclesMap; 
		delete alp_AllItemsByTag;	
		delete alp_TraderCore;	
		delete alp_HideItems;	
		delete alp_HideItemsType;	
		delete m_RegisteredPositions;
	}	
	
	override void Init() 
	{
		alp_Missions 		= new map<int, ref alpMission>;
		alp_MissionsByName 	= new map<string, ref array<ref alpMission>>;
		alp_HideItems 		= new array<string>;
		alp_HideItemsType 	= new array<string>;
	
		if (GetGame().IsServer() && GetGame().IsMultiplayer())
		{
			alp_ActiveQuestsID = new array<int>;	
			m_RegisteredPositions = new map<string, ref array<ref array<float>>>; 

			JsonFileLoader< autoptr alpOptionsMSradiation>.JsonLoadFile(ALP_MISSIONS_RADIATION_FILE, alp_optionsMSradiation );  
			if (!alp_optionsMSradiation)
			{
				alp_optionsMSradiation 	= new alpOptionsMSradiation();
				JsonFileLoader< autoptr alpOptionsMSradiation>.JsonSaveFile(ALP_MISSIONS_RADIATION_FILE,  alp_optionsMSradiation);
			}

			if ( !FileExist ( ALP_MISSIONSYSTEM_PROTECTION ) )
				JsonFileLoader< array<ref alpProtectionItem> >.JsonSaveFile( ALP_MISSIONSYSTEM_PROTECTION, alp_ProtectionBonuses );
			else
				JsonFileLoader< array<ref alpProtectionItem> >.JsonLoadFile( ALP_MISSIONSYSTEM_PROTECTION, alp_ProtectionBonuses );
				
			MapProtectionConfig( alp_ProtectionBonuses );							
			
			if (!FileExist(ALP_MISSIONS_FOLDER)) MakeDirectory(ALP_MISSIONS_FOLDER);
			
			alp_List = new alpMissionList();
			JsonFileLoader<autoptr alpMissionList>.JsonLoadFile( ALP_MISSIONSYSTEM_FILE , alp_List );	
			
			alp_MissionRegistr = new alpMissionPosition;
			
			array<ref alpLoot> loots;			
			JsonFileLoader<array<ref alpLoot>>.JsonLoadFile( ALP_MISSIONSYSTEM_LOOT, loots );	
			
			alp_LootMap = new map<string,ref alpLoot>;	
			if (loots)
			{
				foreach (alpLoot loot : loots)
					alp_LootMap.Insert(loot.title, loot);
			}
			
			array<ref alpVehicles> vehicles;	
			JsonFileLoader<array<ref alpVehicles>>.JsonLoadFile( ALP_MISSIONSYSTEM_VEHICLES, vehicles );		
			
			alp_VehiclesMap = new map<string,ref alpVehicles>;	
			if ( vehicles )
			{
				foreach (alpVehicles vehicle : vehicles)
					alp_VehiclesMap.Insert(vehicle.title, vehicle);
			}
			
			if (!FileExist(ALP_MISSIONS_TRADER_FOLDER)) MakeDirectory(ALP_MISSIONS_TRADER_FOLDER);
				
			JsonFileLoader< autoptr alpOptionsMStrader>.JsonLoadFile(ALP_MISSIONS_TRADER_FILE, alp_optionsMStrader );	
			if (!alp_optionsMStrader)
			{
				alp_optionsMStrader = new alpOptionsMStrader();	
				JsonFileLoader< autoptr alpOptionsMStrader>.JsonSaveFile(ALP_MISSIONS_TRADER_FILE, alp_optionsMStrader);
			}
		}	
		
		if (GetGame().IsClient())
		{
			alp_optionsMSradiation 	= new alpOptionsMSradiation();
			alp_optionsMStrader 	= new alpOptionsMStrader();			
		}

		// [OTIMIZAÇÃO] Inicia os loops visuais no Cliente
		if (GetGame().IsClient())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ClientMissionTick, 1000, false);
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ClientRadiationTick, 200, false);
		}
	}

	// [OTIMIZAÇÃO] Ciclo do Servidor (Gerir Missões - 3s)
	void ServerMissionTick()
	{
		if (!GetGame() || !GetGame().IsServer()) return;

		int hour, minute, second;
		GetHourMinuteSecondUTC(hour, minute, second);
		alp_Hour = hour;
		alp_Minute = minute;
		alp_Second = second;

		foreach (alpMission mission : alp_Missions)
		{
			if (mission)
			{
				mission.ManageMission(3.0); // Delta fixo de 3s
			}
		}
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ServerMissionTick, 3000, false);
	}

	// [OTIMIZAÇÃO] Ciclo do Cliente (Interface - 1s)
	void ClientMissionTick()
	{
		if (!GetGame() || !GetGame().IsClient()) return;

		foreach (alpMission missionClient : alp_Missions)
		{
			if (missionClient)
				missionClient.ClientTouch(1.0);
		}
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ClientMissionTick, 1000, false);
	}

	// [OTIMIZAÇÃO] Ciclo de Radiação (Cliente - 200ms)
	void ClientRadiationTick()
	{
		if (!GetGame() || !GetGame().IsClient()) return;

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());           
		if (player && player.GetRP())
		{
			player.GetRP().SetLocalRadiation();
		}
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ClientRadiationTick, 200, false);
	}

	// Funções de Utilidade (Preservadas)
	static int GetCurrentTime() {
		return (alp_Hour * 3600 + alp_Minute * 60 + alp_Second);
	}

	bool HasGroupPermission( string group ) {
		if ( group != "" ){
			int limit = GetGroupLimit( group);
			int actual = GetActualCount( group );
			if ( actual >= limit ) return false;
		}	
		return true;
	}
	
	protected int GetGroupLimit( string group ) {
		int limit;
		if ( alp_List && alp_List.MissionGroupLimit ) {
			if ( alp_List.MissionGroupLimit.Find(group, limit ) ) return limit;			
		}
		return 9999;
	}
	
	protected int GetActualCount( string group ) {
		int actual;
		if ( !m_MissionGroup.Find(group, actual) ){
			actual = 0;
			m_MissionGroup.Set( group, actual );
		} 
		return actual;
	}
	
	void ChangeGroupLimit( string group, int change ) {
		if ( group != "" ) {
			int limit;
			if ( m_MissionGroup.Find(group, limit) ){
				limit += change;	
				limit = Math.Clamp(limit,0,9999);
				m_MissionGroup.Set(group, limit );
			}				
		}	
	}

	static void AddVehicleToStat(string name ){
		CarsCount++;
		int count;
		if ( VehicleTypes.Find( name, count ) ) count+=1;
		else count=1;	
		VehicleTypes.Set( name, count );
	}

	static void RemoveVehicleFromStat(string name ){
		CarsCount--;
		int count;
		if ( VehicleTypes.Find( name, count ) ) {
			count--; 
			VehicleTypes.Set( name, count );					
		} 
	}
	
	static bool CanSpawnVehicleInMission(int limit, array<string> cars ){
		int countCars = CarsCount;
		if ( cars && cars.Count() > 0 ) {
			countCars=0;
			for(int i = 0; i < cars.Count(); i++ ) {
				int count;
				if ( VehicleTypes.Find( cars.Get(i) , count ) ) countCars += count;				
			}			
		}	
		return (limit > countCars);
	}
	
	bool IsItemHidden( string type ) {
		if ( alp_HideItems.Find( type ) != -1 ) return true;
		for (int i = 0; i < alp_HideItemsType.Count();i++) {
			if ( GetGame().IsKindOf(type, alp_HideItemsType.Get(i) ) ) return true;
		}
		return false;
	}
				
	bool IsPossibleSetQuest() {
		int active = 0;
		if (GetND() && GetND().alp_ActiveQuests) active = GetND().alp_ActiveQuests.Count();
		return alp_optionsMStrader.QuestNominal > active;
	}
	
	bool IsActiveQuest(int id){
		if ( alp_ActiveQuestsID && alp_ActiveQuestsID.Find(id) == -1) return false;
		return true;
	}
	
	bool RegisterQuest(int trader, int quest , vector pos, int currency) {
		if ( IsPossibleSetQuest() ) {
			alp_ActiveQuestsID.Insert( quest );
			GetND().alp_ActiveQuests.Insert( new alpRegisteredQuest( trader, quest, pos, currency ) );
			SendRPC_QuestsUpdate();
			return true;
		}
		return false;
	}
	
	void UnRegisterQuest( int trader, int id ) {
		if ( GetND().alp_ActiveQuests ) {
			for ( int i = 0; i < GetND().alp_ActiveQuests.Count() ; i++) {
				alpRegisteredQuest quest = GetND().alp_ActiveQuests.Get(i);
				if ( quest.NPC == trader && quest.Quest == id) {
					alp_ActiveQuestsID.RemoveItem( id );
					GetND().alp_ActiveQuests.Remove( i );
					break;
				}
			}
			SendRPC_QuestsUpdate();
		}		
	}
	
	array< int> GetMappedQuests(int id ) {
		array< int> questsID = new array< int>;
		if ( GetND().alp_Quests ) {
			for ( int i = 0 ; i < GetND().alp_Quests.Count(); i++ ) {
				alpTraderQuest quest = GetND().alp_Quests.Get(i);
				if ( quest.AssociatedTraders.Find( id ) != -1 ) questsID.Insert( i );	
			}	
		}						
		return questsID;
	}

	alpTraderQuest GetQuest(int id ) {
		return GetND().GetQuest( id );
	}
	
	override void OnConnectManaged( PlayerBase player ) {	
		ScriptRPC rpc = GetND().GetInitRPC( GetID() );		
		rpc.Write( GetND().alp_OptionsMS ); 		
		rpc.Write( alp_optionsMSradiation );	
		rpc.Write( alp_ProtectionBonuses );
		rpc.Write( alp_optionsMStrader );
		rpc.Write( alpTraderCoreBase.alp_CategoriesOverride );
		rpc.Write( alpTraderCoreBase.alp_ItemsOverride );
		
		array<autoptr alpNPCtraderStock> stocks = new array<autoptr alpNPCtraderStock> ;	
		array<int> stockID = new array<int>;
		for (int i = 0; i < alpTraderCoreBase.alp_TraderStockMapped.Count() ; i++) {
			stockID.Insert( alpTraderCoreBase.alp_TraderStockMapped.GetKey( i ) );
			stocks.Insert( alpTraderCoreBase.alp_TraderStockMapped.GetElement( i ) );
		}
		rpc.Write( stockID );
		rpc.Write( stocks );	
		rpc.Write( GetND().alp_Quests );	
		GetND().SendGameRPC( rpc, player );
		SendRPC_Update( null, player , true ); 
	}	
	
	override void OnSpawnManaged( PlayerBase player ) {	
		SendRPC_ServerTime(player);
		SendRPC_Update( null, player );		
		SendRPC_QuestsUpdate( player );
	}

	override void ReadInitRPC( PlayerIdentity sender, Object target, ParamsReadContext ctx) {	
		ctx.Read( GetND().alp_OptionsMS ); 
		ctx.Read( alp_optionsMSradiation );	
		ctx.Read( alp_ProtectionBonuses );	
		ctx.Read( alp_optionsMStrader );
		ctx.Read( alpTraderCoreBase.alp_CategoriesOverride );
		ctx.Read( alpTraderCoreBase.alp_ItemsOverride );
		
		array<int> stockID;
		array<autoptr alpNPCtraderStock> stocks;
		ctx.Read( stockID );
		ctx.Read( stocks );
		ctx.Read( GetND().alp_Quests );	

		for( int i = 0; i < stockID.Count() ;i++) {
			int index = stockID.Get(i);
			alpNPCtraderStock stock = stocks.Get(i);
			alpTraderCoreBase.SortMap( stock );
			alpTraderCoreBase.alp_TraderStockMapped.Set( index, stock );

			for ( int x = 0; x < stock.Stock.Count(); x++) {
				string name = stock.Stock.GetKey(x);
				if ( alpTraderCoreBase.alp_AllowedItems.Find( name ) < 0 )
					alpTraderCoreBase.alp_AllowedItems.Insert( name );			
			}
		}
		alp_TraderCore = new alpTraderCore( null );		
		MapProtectionConfig( alp_ProtectionBonuses );
	}	

	void MapProtectionConfig(array<ref alpProtectionItem> config ) {
		alp_ProtectionBonusesMaped = new map<string, ref alpProtectionItem>;
		if ( config && config.Count() > 0) {
			foreach ( alpProtectionItem item : config )
				alp_ProtectionBonusesMaped.Set( item.type, item );			
		}
	}

	alpProtectionItem GetProtectionBonuses(string type) {
		if (alp_ProtectionBonusesMaped) {
			alpProtectionItem item = alp_ProtectionBonusesMaped.Get(type);
			if (item) return item;
		}		
		return null;
	}		
	
	float GetNBCefficiency(int state) {
		if ( GetOptionsRadiation() && GetOptionsRadiation().EfficiencyNBCbyState && GetOptionsRadiation().EfficiencyNBCbyState.Count() == 5 && state < 5) {
			return GetOptionsRadiation().EfficiencyNBCbyState.Get( state );
		}
		return 1;
	}

	alpMSoptions GetOptions() { return GetND().alp_OptionsMS; }		
	alpOptionsMSradiation GetOptionsRadiation() { return alp_optionsMSradiation; }
	alpOptionsMStrader GetOptoinsTrader() { return alp_optionsMStrader; }
		
	override void OnStart() 
	{
		if ( GetGame().IsServer() )
		{
			InitMissionServerSide();
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(alpMHIVE.InitHive,1000);
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.StartMissions,3000);
			
			// [OTIMIZAÇÃO] Inicia o motor de missões no Servidor apenas quando tudo estiver pronto
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ServerMissionTick, 3000, false);
		}
	}

	void StartMissions(){
		array<int> loaded = new array<int>;
		foreach (alpMission m : alp_Missions) {
			if ( m.GetTemplate().saveMissionStage ) {
				int id = m.GetID();
				string name = m.GetName();
				alpMissionStore s = alpMHIVE.Get(id,name);
				if ( s ) {	
					loaded.Insert(id);	
					int timeOffset = m.GetTemplate().timeOffset;
					if ( timeOffset ) {
						timeOffset *= 1000;
						GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( m.LoadMission,timeOffset,false,s);
					} else m.LoadMission(s);
				}															
			}
		}			
		foreach (alpMission mission : alp_Missions) {
			if ( loaded.Find( mission.GetID() ) < 0 ) mission.CreateMission();			
		}			
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.InitTrader,200);		
	}
	 
	void InitTrader() {
		alp_TraderCore = new alpTraderCore( GetMissions() );
	}
		
	void InitMissionServerSide() {
		int id = 0;
		foreach (alpMissionListItem template : alp_List.MissionList ) {
			alpMissionTemplate mission;
			JsonFileLoader<alpMissionTemplate>.JsonLoadFile( ALP_MISSIONS_FOLDER + template.name + ".json", mission );			
			int missionID = alpMissionType.GetMissionID(template.type);
			if ( mission && missionID > 0) {
				if (mission.active) CreateNewMission( mission, missionID, template.name, id);						
			}	
		}		
	}	
	
	protected void RegisterPositions( string name ) {
		array<ref array<float>> positions = new array<ref array<float>>;
		m_RegisteredPositions.Set(name, positions );
	}
	
	array<ref array<float>> GetPositions(string name ){
		return m_RegisteredPositions.Get( name );
	}
	
	protected bool CreateNewMission(alpMissionTemplate mission, int type, string name, out int id)
	{
		int idLast = id;
		int i;
		switch (type)
		{				
			case ALP_MISSIONTYPEID.noradiation:
				for (i = 0; i < mission.nominal;i++) {	
					alpNoRadiationZone norad = new alpNoRadiationZone(id, name , ALP_MISSIONTYPEID.noradiation , mission ); 
					alp_Missions.Insert( id, norad);		
					AddMissionByName( name, norad);	
					id += 1;				
				}
				RegisterPositions(name);
				break;

			case ALP_MISSIONTYPEID.noradiationMission:
				for (i = 0; i < mission.nominal;i++) {	
					alpNoRadiationZoneMission noradm = new alpNoRadiationZoneMission(id, name , ALP_MISSIONTYPEID.noradiationMission , mission ); 
					alp_Missions.Insert( id, noradm );	
					AddMissionByName( name, noradm);	
					id += 1;
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.carAccident:
				for (i = 0; i < mission.nominal;i++) {	
					alpCarAccidentMission carm = new alpCarAccidentMission(id, name , ALP_MISSIONTYPEID.carAccident , mission ); 
					alp_Missions.Insert( id, carm );	
					AddMissionByName( name, carm);	
					id += 1;
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.radiation:
				for (i = 0; i < mission.nominal;i++) {	
					alpRadiationZone rad = new alpRadiationZone(id, name , ALP_MISSIONTYPEID.radiation , mission ); 
					alp_Missions.Insert( id, rad ); 
					AddMissionByName( name, rad);	
					id += 1;					
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.radiationMission:
				for (i = 0; i < mission.nominal;i++) {	
					alpRadiationZoneMission radm = new alpRadiationZoneMission(id, name , ALP_MISSIONTYPEID.radiationMission , mission ); 
					alp_Missions.Insert( id, radm );	
					AddMissionByName( name, radm);	
					id += 1;					
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.trader:
				for (i = 0; i < mission.nominal;i++) {	
					alpTraderMission traderm = new alpTraderMission(id, name , ALP_MISSIONTYPEID.trader , mission ); 
					alp_Missions.Insert( id, traderm ); 
					AddMissionByName( name, traderm);	
					id += 1;					
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.fuelstation:
				for (i = 0; i < mission.nominal;i++) {	
					alpFuelStationMission fsm = new alpFuelStationMission(id, name , ALP_MISSIONTYPEID.fuelstation , mission ); 
					alp_Missions.Insert( id, fsm ); 
					AddMissionByName( name, fsm);	
					id += 1;
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.savesurvivors:
				for (i = 0; i < mission.nominal;i++) {	
					alpSaveSurvivorMission ssm = new alpSaveSurvivorMission(id, name , ALP_MISSIONTYPEID.savesurvivors , mission ); 
					alp_Missions.Insert( id, ssm ); 
					AddMissionByName( name, ssm);	
					id += 1;					
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.conquerdefend:
				for (i = 0; i < mission.nominal;i++) {	
					alpConquerDefendMission cdm = new alpConquerDefendMission(id, name , ALP_MISSIONTYPEID.conquerdefend , mission ); 
					alp_Missions.Insert( id, cdm ); 
					AddMissionByName( name, cdm);	
					id += 1;
				}
				RegisterPositions(name);				
				break;

			case ALP_MISSIONTYPEID.savemerchants:
				for (i = 0; i < mission.nominal;i++) {	
					alpSaveMerchantsMission savemerch = new alpSaveMerchantsMission(id, name , ALP_MISSIONTYPEID.savemerchants , mission ); 
					alp_Missions.Insert( id, savemerch );	
					AddMissionByName( name, savemerch);	
					id += 1;					
				}
				RegisterPositions(name);				
				break;										
		}		
		return !(idLast == id);
	}	

	void AddMissionByName(string name, alpMission mission) {
		array<ref alpMission> missions = alp_MissionsByName.Get( name );
		if ( missions ) missions.Insert( mission ); 
		else {
			missions = new array<ref alpMission>;
			missions.Insert( mission ); 
			alp_MissionsByName.Set( name, missions );
		}
	}
	
	map<int, ref alpMission> GetMissions() { return alp_Missions; }		
	alpMissionPosition GetFreePlace() { return alp_MissionRegistr; }	
	
	override void ReadSyncRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		int rpc;
		ctx.Read( rpc );
		switch ( rpc ) {
			case ALP_RPC_PLUGIN_MS.VERIFY_CLIENT:
				VerifyClientData( PlayerBase.Cast( target) );
				break;
			case ALP_RPC_PLUGIN_MS.MISSIONS_TO_CLIENT:
				array<ref alpMissionTemplateClient> missionTemplateData;
				ctx.Read( missionTemplateData );
				InitMissionServerClient( missionTemplateData ); 
				break;
			case ALP_RPC_PLUGIN_MS.UPDATE_ALL:
				array<ref alpMissionData> missionsData;
				ctx.Read( missionsData );
				if (missionsData) {
					foreach ( alpMissionData md : missionsData) UpdateMission( md );
				}
				break;
			case ALP_RPC_PLUGIN_MS.UPDATE:
				alpMissionData data;
				ctx.Read( data );				
				UpdateMission( data );
				break;
			case ALP_RPC_PLUGIN_MS.UPDATE_SETTING:
				int misID,misSet;
				ctx.Read( misID );	
				ctx.Read( misSet );					
				UpdateMissionSetting( misID , misSet );
				break;					
			case ALP_RPC_PLUGIN_MS.INOUT:
				int idMission;
				ctx.Read( idMission );
				EventInOut( idMission , PlayerBase.Cast( target) );
				break;		
			case ALP_RPC_PLUGIN_MS.TRADER:
				if ( GetTrader() ) GetTrader().OnRPC( PlayerBase.Cast( target) , ctx );
				break;
			case ALP_RPC_PLUGIN_MS.NPC_QUESTS:
				if (GetND()) ctx.Read( GetND().alp_ActiveQuests );				
				HideItems();
				break;	
			case ALP_RPC_PLUGIN_MS.REGISTER_MISSION:
				int mID,mTime;
				ctx.Read( mID );	
				ctx.Read( mTime );		
				GetND().RegisterPrivateMission( mID, mTime );
				break;		
			case ALP_RPC_PLUGIN_MS.SERVER_TIME:
				int servertime;
				ctx.Read( servertime );			
				GetND().SetServerTimeDelta( servertime );
				break;			
		}
	}			

	void HideItems() {
		alp_HideItems.Clear();
		alp_HideItemsType.Clear();
		if (GetND() && GetND().alp_ActiveQuests) {
			for(int i = 0 ; i < GetND().alp_ActiveQuests.Count();i++) {
				int questID = GetND().alp_ActiveQuests.Get(i).Quest;
				alpTraderQuest quest = GetND().GetQuest( questID);
				if ( quest && quest.HideWantedItems ) {
					alp_HideItems.Insert( quest.WantedItem );
					if ( quest.WantedItemAllowedType != STRING_EMPTY )
						alp_HideItemsType.Insert( quest.WantedItemAllowedType );
				}
			}
		}
	}
	
	void UpdateMissionSetting( int id, int setting ) {
		alpMission mission = GetMission( id );
		if ( mission ) mission.alp_Setting = setting;			
	}	
	
	void UpdateMission( alpMissionData data ) {
		if ( data ) {
			alpMission mission = GetMission( data.id );
			if ( mission ) {	
				mission.alp_Active = data.active;
				mission.alp_Setting = data.setting;
				mission.alp_Position = data.position;
				mission.alp_DamageRadius = data.missionRadius;
				mission.alp_Radiation = data.strengthOfRadiation;
				mission.alp_MissionStarted = data.missionStarted;			
				mission.alp_StartAt = data.startAt;
				mission.alp_EndAt = data.endAt;				
				mission.alp_Touched = false;
				mission.alp_WasTouched = false;				
				mission.EstimateSides();
			}	
		}
	}
	
	void SendRPC_RegisterMission( PlayerBase player, int id, int time) {
		ScriptRPC rpc = GetND().GetSyncRPC( GetID() );
		rpc.Write( ALP_RPC_PLUGIN_MS.REGISTER_MISSION );		
		rpc.Write( id );
		rpc.Write( time );
		if ( player ) GetND().SendGameRPC( rpc, player );
	}	

	void SendRPC_ServerTime( PlayerBase player) {
		ScriptRPC rpc = GetND().GetSyncRPC( GetID() );
		rpc.Write( ALP_RPC_PLUGIN_MS.SERVER_TIME );		
		rpc.Write( GetGame().GetTime() );
		GetND().SendGameRPC( rpc, player ); 
	}
	
	void SendRPC_QuestsUpdate( PlayerBase player = null) {
		ScriptRPC rpc = GetND().GetSyncRPC( GetID() );
		rpc.Write( ALP_RPC_PLUGIN_MS.NPC_QUESTS );		
		rpc.Write( GetND().alp_ActiveQuests );
		if ( !player ) GetND().SendGameRPC( rpc, player , true,true,true );	
		else GetND().SendGameRPC( rpc, player ); 
	}

	void SendRPC_Update(alpMission mission = null, PlayerBase player = null, bool sendTemplate = false, bool justSetting = false ) {
		ScriptRPC rpc = GetND().GetSyncRPC( GetID() );
		alpMissionData data;
		if ( mission ) {
			if (!justSetting) {
				rpc.Write( ALP_RPC_PLUGIN_MS.UPDATE );				
				data = alpMissionData.CompileDataToClient( mission );
				rpc.Write( data );			
			} else {
				rpc.Write( ALP_RPC_PLUGIN_MS.UPDATE_SETTING );
				rpc.Write( mission.alp_Id );	
				rpc.Write( mission.alp_Setting );			
			}
			GetND().SendGameRPC( rpc, player , true,true,true );	
		} else {
			if ( player ) {
				if ( sendTemplate ) {
					rpc.Write( ALP_RPC_PLUGIN_MS.MISSIONS_TO_CLIENT );	
					array<ref alpMissionTemplateClient> missionTemplateData = new array<ref alpMissionTemplateClient>;
					foreach (alpMission mission2 : alp_Missions) {
						missionTemplateData.Insert( alpMissionTemplateClient.Cast( alpMissionTemplateClient.CompileDataToClient(mission2) ) );		
					}
					rpc.Write( missionTemplateData );			
					GetND().SendGameRPC( rpc, player ); 
				} else {
					rpc.Write( ALP_RPC_PLUGIN_MS.UPDATE_ALL );	
					array<ref alpMissionData> missionDataToPlayer = new array<ref alpMissionData>;
					foreach (alpMission mission3 : alp_Missions) {
						missionDataToPlayer.Insert( alpMissionData.CompileDataToClient( mission3 ) );		
					}
					rpc.Write( missionDataToPlayer );			
					GetND().SendGameRPC( rpc, player ); 												
				}
			} else {
				rpc.Write( ALP_RPC_PLUGIN_MS.UPDATE_ALL );	
				array<ref alpMissionData> missionData = new array<ref alpMissionData>;
				foreach (alpMission mission4 : alp_Missions) {
					missionData.Insert( alpMissionData.CompileDataToClient( mission4 ) );		
				}
				rpc.Write( missionData );			
				GetND().SendGameRPC( rpc, player, true,true,true );				
			}
		}
	}	

	void SendRPC_VerifyClientData(PlayerBase player ) {
		ScriptRPC rpc = GetND().GetSyncRPC( GetID() );
		rpc.Write( ALP_RPC_PLUGIN_MS.VERIFY_CLIENT );	
		GetND().SendGameRPC( rpc, player ); 
	}	

	void VerifyClientData(PlayerBase player ) {
		if (GetGame().IsServer()) GetND().OnConnect( player );		
		if (GetGame().IsClient() && !GetOptions()) GetND().GetMS().SendRPC_VerifyClientData( player ); 	
	}	
		
	void SendRPC_INOUT(PlayerBase player, int idMission ) {
		ScriptRPC rpc = GetND().GetSyncRPC( GetID() );
		rpc.Write( ALP_RPC_PLUGIN_MS.INOUT );
		rpc.Write( idMission ); 
		GetND().SendGameRPC( rpc, player ); 
	}	
	
	void EventInOut(int id, PlayerBase player ) {
		if (GetGame().IsServer()) {
			alpMission mission = GetMission( id );
			if (mission && mission.IsActive()) mission.AddInsider( player);			
		}
		if (GetGame().IsClient()) {
			alpMission missionClient = GetMission( id );
			if (missionClient) missionClient.alp_Touched = false;			
		}	
	}	
	
	alpMission GetMission(int id) {
		alpMission mission;
		if ( alp_Missions && alp_Missions.Find(id, mission)) return mission;
		return null;
	}	
	
	array<ref alpMission> GetMissionByName(string name) {
		array<ref alpMission> mission;
		if ( alp_MissionsByName.Find(name, mission)) return mission;
		return null;
	}		
	
	void InitMissionServerClient( array<ref alpMissionTemplateClient> missionsData ) {	
		alp_Missions = new map<int, ref alpMission>; 
		foreach ( alpMissionTemplateClient data : missionsData ) {
			alpMissionTemplate template = new alpMissionTemplate();
			template.requiredLevel = data.requiredLevel;	
			template.active = false; 
			template.cleanRadius = data.cleanRadius;						 
			template.radiusOfRadiation = { data.missionRadius , data.missionRadius };
			template.strengthOfRadiation = { data.strengthOfRadiation, data.strengthOfRadiation };			
			template.strengthOfRadiationOffset = data.strengthOfRadiationOffset;
			template.enableSineFunction = data.enableSineFunction;			
			template.rainingMultiplyRadiation = data.rainingMultiplyRadiation;	
			template.mapTitle = data.title;
			template.sendInfo = data.sendInfo;
			template.showInMap = data.showInMap;
			template.showInMapWhenEnter = data.showInMapWhenEnter;
			template.heightOfRadiationArea = data.heightOfRadiationArea;
			template.aspectRatioB = data.aspectRatioB;
			template.countdownBeforeDespawn = data.countdownBeforeDespawn;
			template.timeToFullRadiation = data.timeToFullRadiation;		

			alpMission mission = new alpMission(data.id, data.name , data.type, template );
			mission.alp_CountdownDespawn = mission.GetTemplate().countdownBeforeDespawn * 1000;
			mission.alp_TimeToFullRadiation = mission.GetTemplate().timeToFullRadiation * 1000;			
			alp_Missions.Insert( data.id, mission );											
			UpdateMission(data);
		}
		if (GetND()) GetND().LoadRegisteredPrivateMissions();
	}	
	
	alpTraderCore GetTrader() { return alp_TraderCore; }
}