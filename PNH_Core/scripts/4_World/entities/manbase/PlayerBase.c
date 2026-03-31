// PNH_Core/scripts/4_World/entities/manbase/PlayerBase.c

enum alpEntityType
{
    SUICIDE, PLAYER, ZOMBIE, ANIMAL, GRENADE,
}

class alpLastHit
{
    int alp_EntityType;
    int alp_HitTime;
    int alp_DamageType;
    string alp_Source;
    string alp_Name;
    
    void alpLastHit() { alp_DamageType = DT_CUSTOM; }
    
    void RegisterHit(int entity, int time, int type, string source = "", string name = "")
    {
        alp_EntityType = entity;
        alp_HitTime = time;
        alp_DamageType = type;
        alp_Source = source;
        alp_Name = name;
    }
    
    bool IsSuicide()
    {
        int time = GetGame().GetTime();
        int lasthit = alp_HitTime + 30000;
        
        if ( lasthit < time || alp_EntityType == alpEntityType.SUICIDE ) return true;
        return false;
    }   
}

modded class PlayerBase extends ManBase
{
    bool alp_IsEventOnRunActive;
    int alp_PlayerID;
    
    // --- VARIÁVEIS DO CORE ---
    ref alpSync alp_Sync;
    ref alpRP alp_RP;
    ref alpPlayerHive alp_Hive;
    ref PlayerStatsALP  alp_PlayerStats;
    ref alpLastHit  alp_LastHitData;
    bool alp_IsPlayerSpawn;
    bool alp_BrainWasDamaged;
    ref array<int> m_ContaminedItems;
    bool m_HasContaminedItems;

    // --- VARIÁVEIS INJETADAS DO CLÃ ---
    ref alpAuthorize alp_Authorize;  
    alp_PlotPole alp_PlotPoleManage;
    int alp_ClanID = -1;
    float alp_Time;
    const float ALP_TIMEFORCHECKMESSAGES = 1.0;     
    vector alp_LastKnownPosition = "0 0 0";     
    
    override void Init()
    {
        super.Init();
        
        // Registro Variáveis Core
        RegisterNetSyncVariableBool("m_HasContaminedItems");    
        m_ContaminedItems = new array<int>;
        alp_LastHitData = new alpLastHit();
        alp_PlayerStats = new PlayerStatsALP( this );
        alp_Sync = new alpSync( this );
        alp_RP = new alpRP( this );
        
        // Registro Variáveis Clã
        RegisterNetSyncVariableInt("alp_PlayerID"); 
        RegisterNetSyncVariableInt("alp_ClanID");   
        alp_Authorize = new alpAuthorize(this);
        
        if ( GetGame().IsClient() )
        {
            LoadPlayerHive();       
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater( this.ClientOnConnect  , 0 );
        }
        
        InitALP();
    }
    
    // --- MÉTODOS DO CORE MANTIDOS (Hotfixes de Contaminação) ---
    void AddContaminedItem(int id){
        if ( m_ContaminedItems.Find(id) == -1 ) m_ContaminedItems.Insert(id);
        m_HasContaminedItems = m_ContaminedItems.Count();
    }
    void RemoveContaminedItem(int id){
        m_ContaminedItems.RemoveItem(id);
        m_HasContaminedItems = m_ContaminedItems.Count();
    }
    bool HasContaminedItems(){ return m_HasContaminedItems; }
    bool IsPlayerSpawn() { return alp_IsPlayerSpawn; }
    void SetPlayerSpawn(bool state ) { alp_IsPlayerSpawn = state; } 
    void ClientOnConnect() { if ( GetGame().GetPlayer() == this ) GetPlayerHive().OnConnect(); }
    void InitALP(){}

    override void OnStoreSave( ParamsWriteContext ctx )
    {
        super.OnStoreSave( ctx );
        if ( GetDayZGame().IsServer() && GetDayZGame().IsMultiplayer() ) GetPlayerStatsALP().SaveStats(ctx);       
    }   

    override bool OnStoreLoad( ParamsReadContext ctx, int version )
    {
        if ( super.OnStoreLoad( ctx, version ) )
        {
            if ( GetDayZGame().IsServer() && GetDayZGame().IsMultiplayer() )
            {
                if (!GetPlayerStatsALP().LoadStats(ctx, version)) return false;
            }                           
            return true;
        }
        return false;
    }       
    
    PlayerStatsALP GetPlayerStatsALP() { return alp_PlayerStats; }
    
    override void AfterStoreLoad()
    {
        super.AfterStoreLoad();
        
        array<EntityAI> itemsArray = new array<EntityAI>;
        ItemBase item;

        GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, itemsArray);
        for (int i = 0; i < itemsArray.Count(); i++)
        {               
            item = ItemBase.Cast(itemsArray.Get(i));
            if ( item && item != this && ( item.GetAgents() & alpeAgents.RADIATION ) ) {
                AddContaminedItem(item.GetID());
            }
        }
    }

    void LoadPlayerHive() { alp_Hive = new alpPlayerHive( this ); }
    alpPlayerHive GetPlayerHive() { return alp_Hive; }
    alpRP GetRP() { return alp_RP; }
    alpSync GetSyncData() { return alp_Sync; }  
    
    // --- TICK OTIMIZADO (CORE + CLÃ) ---
    override void OnScheduledTick(float deltaTime)
    {
        super.OnScheduledTick( deltaTime );
        
        if( !IsPlayerSelected() || !IsAlive() ) return;
        
        if ( GetGame().IsClient() && GetGame().IsMultiplayer() && GetGame().GetPlayer() == this )
        {
            GetND().OnUpdate( deltaTime );  
            if( GetSyncData() ) GetSyncData().OnScheduledTick(deltaTime);

            // TICK DO CLÃ (Check de Zona)
            if (IsControlledPlayer())
            {
                alp_Time += deltaTime;
                if (alp_Time >= ALP_TIMEFORCHECKMESSAGES)
                {
                    CheckPlotPole();
                    alp_Time = 0; // Otimização: Reset do tempo para evitar estouro
                }       
            }
        }
        
        if ( GetGame().IsServer() && GetIdentity() )
        {
            if( GetSyncData() ) GetSyncData().OnScheduledTick(deltaTime);           
        }
    }

    // --- MÉTODOS INJETADOS DO CLÃ ---
    override int GetClanID(){ return alp_ClanID; }
    int GetPlayerID(){ return alp_PlayerID; }
    void SetClanID(int id ){ alp_ClanID = id; }
    bool IsAuthorized(ItemBase item){ return alp_Authorize.IsAuthorized(item); }
    bool IsAuthorized(){ return alp_Authorize.IsAuthorized(); } 

    // --- RPCs DO CORE MANTIDOS ---
    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);
        
        int type;
        switch(rpc_type)
        {
            case ALP_RPC_PLAYER:
            {
                ctx.Read(type);
                switch (type)
                {
                    case ALP_RPC_PLAYER_TYPE.SYNC_REGISTER_ENHANCEDSTATS:
                    {
                        bool state; ctx.Read(state);
                        GetSyncData().RegisterToStats(state);               
                        break;
                    }                   
                    case ALP_RPC_PLAYER_TYPE.HIVE_SYNC_ALL:
                    {
                        if( GetPlayerHive() ) GetPlayerHive().SyncAllRPC(ctx);                      
                        break;
                    }
                    case ALP_RPC_PLAYER_TYPE.HIVE_SYNC_SMALL:
                    {
                        if( GetPlayerHive() ) GetPlayerHive().SyncSmallRPC(ctx);                        
                        break;
                    }               
                }
                break;  
            }
            case ALP_RPC_PLAYER_SYNC_BIT:
            {
                if( GetSyncData() ) GetSyncData().OnRPC_RP_STATS(ctx);
                break;          
            }
            case ALP_RPC_PLAYER_SYNC_VALUE:
            {
                if( GetSyncData() && IsAlive() ) GetSyncData().OnRPC_RP_STATS_ENHANCED(ctx);
                break;                      
            }                   
        }   
    }   
    
    // --- LÓGICA DE DANO, EQUIPAMENTO E MORTE DO CORE MANTIDA ---
    override void EEItemAttached(EntityAI item, string slot_name)
    {
        super.EEItemAttached(item,slot_name);
        GetRP().GetProtection().ItemAttached(item,slot_name);
    }   
    override void EEItemDetached(EntityAI item, string slot_name)
    {
        super.EEItemDetached(item,slot_name);
        GetRP().GetProtection().ItemDetached(item,slot_name);   
    }   
    
    override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
    {
        super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef); 
        
        if ( !IsAlive() && damageResult && dmgZone == "Head" && damageResult.GetHighestDamage( "Health" ) >= 20 ) alp_BrainWasDamaged = true;

        if (GetGame().IsServer() && GetND().GetNotf().GetOptions().EnableDeathNotification && GetIdentity() &&  ( IsUnconscious() || !IsAlive() )  )
        {   
            if ( source )
            {
                if ( source.IsZombie() ) alp_LastHitData.RegisterHit( alpEntityType.ZOMBIE , GetGame().GetTime(), damageType , ammo , "#alp_dead_by_infected" );
                else if ( source.IsAnimal() ) alp_LastHitData.RegisterHit( alpEntityType.ANIMAL , GetGame().GetTime(), damageType , ammo , "#alp_dead_by_beast" );    
                else alp_LastHitData.RegisterHit( alpEntityType.SUICIDE, GetGame().GetTime(), damageType , ammo );  
            }
            else alp_LastHitData.RegisterHit( alpEntityType.SUICIDE, GetGame().GetTime(), damageType , ammo );                  
        }       

        Grenade_Base grenade;
        TrapBase trap;
        if (GetGame().IsServer() && !IsAlive() && ( Class.CastTo( grenade, source ) || Class.CastTo( trap, source )  ) )
        {
            if ( grenade && grenade.alp_LastOwner && this != grenade.alp_LastOwner ) KilledByPlayerALP(grenade.alp_LastOwner, trap.GetDisplayName() );  
            if ( trap && trap.alp_LastOwner && this != trap.alp_LastOwner ) KilledByPlayerALP(trap.alp_LastOwner, trap.GetDisplayName() );
        }   
    }   
    
    override void EEKilled(Object killer)
    {   
        super.EEKilled(killer);         
        if (GetGame().IsServer()  ) 
        {   
            if ( GetIdentity() )
            {
                PlayerBase player;
                if (m_KillerData && Class.CastTo(player,m_KillerData.m_Killer) && this != player && player.GetIdentity() ) KilledByPlayerALP(player, "" );            

                if ( IsPlayer() && GetPlayerHive() )
                {
                    GetND().OnDeath( this );
                    GetPlayerHive().OnDeath();          
                }
                
                if ( GetND().GetNotf().GetOptions().EnableDeathNotification  ) GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.DeathNotificationALP,500);
            }
            
            if ( GetND().GetRP().GetPlayerOptions().RaiseZombieAfterDeath ) 
            {
                if ( !GetND().GetRP().GetPlayerOptions().RaiseZombieFromPlayersBodyOnly || GetIdentity() )
                {
                    int raiseTime = Math.RandomInt( GetND().GetRP().GetPlayerOptions().RaiseZombieTime[0] ,  GetND().GetRP().GetPlayerOptions().RaiseZombieTime[1] ) * 1000;
                    GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.RaiseZombie,raiseTime);          
                }
            }
        }   
    }   
    
    void DeathNotificationALP()
    {
        EntityAI weapon;
        PlayerBase killedby;
        bool headshot = false;
        if ( m_KillerData )
        {
            killedby = PlayerBase.Cast( m_KillerData.m_Killer );
            weapon = m_KillerData.m_MurderWeapon;       
            headshot = m_KillerData.m_KillerHiTheBrain;     
        }
        
        if ( !killedby || killedby == this )
        {
            if ( !alp_LastHitData.IsSuicide() ) GetND().GetNotf().SendGlobalMessage( ALPMSTYPE.SMDEATH, GetIdentity().GetName() + " " + alp_LastHitData.alp_Name ); 
            else GetND().GetNotf().SendGlobalMessage( ALPMSTYPE.SMDEATH, GetIdentity().GetName() + " #alp_dead_by_unr"); 
        }
        else
        {
            string killerName = "NPC";
            if ( killedby.GetIdentity() ) killerName = killedby.GetIdentity().GetName();
                
            if (!weapon) GetND().GetNotf().SendGlobalMessage( ALPMSTYPE.SMDEATH,  killerName + " #alp_dead_by_killed " + GetIdentity().GetName() + " #alp_dead_by_combat" ); 
            else
            {   
                float distance = vector.Distance( killedby.GetPosition(), GetPosition() );
                if ( headshot ) GetND().GetNotf().SendGlobalMessage( ALPMSTYPE.SMHEADSHOT,  killerName + " #alp_dead_by_killed " + GetIdentity().GetName() + " #alp_dead_by " +  weapon.GetDisplayName() + " (" + alpUF.NumberToString( distance, 1 ) + "m)" );
                else GetND().GetNotf().SendGlobalMessage( ALPMSTYPE.SMDEATH,  killerName + " #alp_dead_by_killed " + GetIdentity().GetName() + " #alp_dead_by " +  weapon.GetDisplayName() + " (" + alpUF.NumberToString( distance, 1 ) + "m)" );                                                                
            }                   
        }   
    }
    
    void RaiseZombie()
    {   
        bool head_shot = false;;
        if ( m_KillerData ) head_shot = m_KillerData.m_KillerHiTheBrain;        
        
        if ( !head_shot && !alp_BrainWasDamaged )
        {
            EntityAI infected = EntityAI.Cast( GetGame().CreateObject(GetZombieClass(),GetPosition(),false,true) );
            if ( infected )
            {
                foreach ( int i : DefaultCharacterCreationMethods.m_AttachmentSlots )
                {
                    EntityAI item = GetInventory().FindAttachment( i );
                    if ( item )
                    {
                        if (  GetInventory().DropEntity( InventoryMode.SERVER, this, item) )
                        {
                            if (! infected.GetInventory().TakeEntityToInventory( InventoryMode.SERVER,FindInventoryLocationType.ANY, item ) )
                            {
                                float damageToAttch = GetND().GetRP().GetPlayerOptions().RuinDroppedAttch;
                                if ( damageToAttch )
                                {
                                    damageToAttch *= item.GetMaxHealth("","health");
                                    item.AddHealth("","",-damageToAttch);       
                                }
                                item.GetInventory().UnlockInventory( HIDE_INV_FROM_SCRIPT );
                                float attLifeTime = GetND().GetRP().GetPlayerOptions().AttchLifeTime;
                                if ( !item.IsRuined() && attLifeTime ) item.SetLifetime( attLifeTime );
                                item.PlaceOnSurface();
                            }                       
                        }   
                    }
                }               
                int zedLifeTime = GetND().GetRP().GetPlayerOptions().ZombieLifeTime;
                if ( zedLifeTime ){
                    ZombieBase zed = ZombieBase.Cast( infected );
                    if ( zed ) zed.SetLifeTimeZed( zedLifeTime );
                }
                DeleteBodyAlp();
            }
        }
        else
        {
            int deleteBody = GetND().GetRP().GetPlayerOptions().DeadBodyLifeTime;
            if ( deleteBody )
            {
                deleteBody *= 1000;
                GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.DeleteBodyAlp,deleteBody);    
            }
        }           
    }
    
    void DeleteBodyAlp() { GetGame().ObjectDelete( this ); }
    
    string GetZombieClass()
    {
        if ( IsMale() )
        {
            if ( GetND().GetRP().GetPlayerOptions().MaleZombies &&  GetND().GetRP().GetPlayerOptions().MaleZombies.Count() > 0 ) return GetND().GetRP().GetPlayerOptions().MaleZombies.GetRandomElement();
            return "ZmbM_NBC_Yellow";
        }
        else
        {
            if ( GetND().GetRP().GetPlayerOptions().FemaleZombies &&  GetND().GetRP().GetPlayerOptions().FemaleZombies.Count() > 0 ) return GetND().GetRP().GetPlayerOptions().FemaleZombies.GetRandomElement();                     
            return "ZmbM_NBC_Yellow";
        }
    }
    
    override void OnDisconnect()
    {
        GetPlayerHive().OnDisconnect();
        super.OnDisconnect();
    }   
    
    void KilledByPlayerALP(PlayerBase player, string source )   
    {
        if ( GetND().GetNotf().GetOptions().EnableDeathNotification  ) alp_LastHitData.RegisterHit( alpEntityType.PLAYER, GetGame().GetTime(), DT_EXPLOSION, source, player.GetIdentity().GetName() );        
        if ( GetRP().IsDebtor() ) RewardForKillingMostWanted( player );     
    }
    
    void RewardForKillingMostWanted(PlayerBase player)
    {
        int currency = GetRP().alp_RewardForKill[0];
        int reward = GetRP().alp_RewardForKill[1];
        if ( reward )
        {
            alpBANK.AddBalanceToAccount( player.GetPlayerHive().GetPlayerID(), currency, reward, player );
            alpBANK.AddExtraLoanFee( GetPlayerHive().GetPlayerID(), currency, reward );
        }
    }   

    override bool Consume(ItemBase source, float amount, EConsumeType consume_type )
    {
        if ( ! super.Consume( source, amount, consume_type) )
        {
            int agents;
            if( consume_type == alpeConsumeType.ENVIRO_POND_CONTAMINED || consume_type == alpeConsumeType.ENVIRO_WELL_CONTAMINED )
            {
                if ( consume_type == alpeConsumeType.ENVIRO_POND_CONTAMINED ) agents = agents | eAgents.CHOLERA;
                m_PlayerStomach.AddToStomach(Liquid.GetLiquidClassname(LIQUID_RADIOACTIVEWATER), amount, 0 , agents );
                ConsumeBonusesALP( source,  amount,  consume_type);
                return true;
            }               
            return false;           
        }
        ConsumeBonusesALP( source,  amount,  consume_type);
        return true;
    }   
    
    void ConsumeBonusesALP(ItemBase source, float amount, EConsumeType consume_type = EConsumeType.ITEM_SINGLE_TIME){}

    // --- AÇÕES DO JOGADOR (CORE + CLÃ) ---
    override void SetActionsRemoteTarget( out TInputActionMap InputActionMap)
    {       
        super.SetActionsRemoteTarget(InputActionMap);
        AddAction(alpActionBuy);
        AddAction(alpActionSell);
        AddAction(alpActionQuestBringMe);
        AddAction(alpActionStartMission);
        
        // Ações do Clã injetadas aqui:
        AddAction(alpAddFriendAction);
        AddAction(alpActionClaimBed);
        AddAction(alpActionReleaseBed);
    }
    
    override bool CanBeRestrained()
    {
        if ( !GetRP().IsAllowedDamage() ) return false;
        return super.CanBeRestrained();
    }   

    override bool IsWeaponRaiseCompleted()
    {               
        if (GetRP().IsInTradeZone() && !GetRP().IsAllowedDamage() ) return false;
        return super.IsWeaponRaiseCompleted();
    }   
    
    override void TogglePlacingLocal(ItemBase item = null)
    {       
        super.TogglePlacingLocal(item);
        if ( GetRP().IsInTradeZone() ) PlacingCancelLocal();
    }           
    
    bool IsErectedALP(){
        HumanMovementState state = new HumanMovementState();
        GetMovementState(state);
        int player_stance = state.m_iStanceIdx;
        if ( player_stance == DayZPlayerConstants.STANCEIDX_ERECT ) return true;
        return false;
    }
    
    void ForceStanceALP(int id)
    {
        if ( id >= 0 )
        {           
            HumanCommandMove cm = GetCommand_Move();
            if (cm)
            {
                switch(id){
                    case 0: cm.ForceStance( DayZPlayerConstants.STANCEIDX_ERECT ); break;
                    case 1: cm.ForceStance(DayZPlayerConstants.STANCEIDX_CROUCH); break;
                    case 2: cm.ForceStance(DayZPlayerConstants.STANCEIDX_PRONE); break;                  
                }
            }           
        }
    }   
    
    string GetArmBandType() {
        string name = "";       
        EntityAI item = FindAttachmentBySlotName("Armband");
        if ( item ) name = item.GetType();      
        return name;
    }
    
    float GetReputationMltp(int action ) { return 0; }

    // --- CHECK PLOTPOLE (LÓGICA DO CLÃ INJETADA) ---
    void CheckPlotPole(){

        float dist;
        int pID = GetPlayerID();
        int cID = GetClanID();      
        int id = GetPlayerID();     
        int r;
        bool home;
        
        foreach (EntityAI ent : ClientData.PlotPoleList){
            alp_PlotPole pp = alp_PlotPole.Cast(ent);
                                
            if (pp){
                if (pp.alp_Radius ){
                    dist = alpUF.VectorDistance(pp.GetPosition(), GetPosition());                   
                    r = pp.GetRadius();                 
                    
                    if ( pp.IsAuthorized(pID,cID) && dist <= r ){
                        home = true;
                    }
                    
                    if ( dist <= r && !pp.alp_AlertMessage ) {
                        if ( pp.IsAuthorized(pID,cID) ) GetHudALP().SendMessageALP(ALPMSTYPE.SMPERSONAL,"#pp_welcome_home");
                        if ( !pp.IsAuthorized(pID,cID)  && !GetND().GetClans().GetBases().DisableNotfYouAreInEnemyTerritory ){
                            GetHudALP().SendMessageALP(ALPMSTYPE.SMPERSONAL,"#pp_you_are_in_enemy_territory");
                        }                       
                        pp.alp_AlertMessage = true; 
                    }
                    if ( dist > r && pp.alp_AlertMessage) {
                        if ( pp.IsAuthorized(pID,cID) && pp.alp_OwnerID > 0) GetHudALP().SendMessageALP(ALPMSTYPE.SMPERSONAL,"#pp_you_left_home");                            
                        if ( !pp.IsAuthorized(pID,cID) && pp.alp_OwnerID > 0 && !GetND().GetClans().GetBases().DisableNotfYouAreInEnemyTerritory) {
                            GetHudALP().SendMessageALP(ALPMSTYPE.SMPERSONAL,"#pp_you_left_enemy_territory");
                        }                       
                        pp.alp_AlertMessage = false;                        
                    }
                }
            }
        }   
        if (home) {           
            if ( GetND().GetClans().GetOptions().Enable3rdPersonCameraAtHome ) {
                GetRP().SetHome( true , true );                                 
            } else {
                if ( IsInVehicle() ) GetRP().SetHome( true , true ); 
                else GetRP().SetHome( true , false );   
            }           
        } else {
            if ( GetND().GetClans().GetOptions().Enable3rdPersonCameraAtSafeZone ) {
                if ( IsInVehicle() ) GetRP().SetHome( false , true );   
                else GetRP().SetHome( false , GetSyncData().GetElement( alpRPelements.ISINTRADERZONE ).GetValue() );                                            
            } else {
                if ( IsInVehicle() ) GetRP().SetHome( false , true );   
                else GetRP().SetHome( false , false );  
            }                       
        }
    }           
    
    Hud GetHudALP()
    {
        PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
        if (player) return player.m_Hud;
        return null;
    }           
    
    bool IsPossibleFillBottle()
    {
        if (m_Environment && m_Environment.IsInShelter() ) return false;
        return true;
    }
}