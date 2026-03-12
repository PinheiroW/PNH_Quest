enum IBAnimInstance
{
	EMPTYHANDS = 0,
	KNIFE = 1,
	PISTOL = 2,
	RIFLE = 3
}

enum IBStance
{
	ERECTED = 0,
	CROUCH = 1,
	PRONE = 2
}

enum IBAnimScriptEvent
{
	WEAPONFIRE = 800
}

//! an extendable data container
class InfectedBanditHitData
{
	int m_Component;
	string m_DamageZone;
	string m_AmmoType;
}

class InfectedBanditBase extends DayZInfected
{

	static const autoptr TStringArray VALID_DMG_ZONES = {};

	const float TARGET_CONE_ANGLE_CHASE = 20;
	const float TARGET_CONE_ANGLE_FIGHT = 30;
	const float ORIENTATION_SYNC_THRESHOLD = 30; // threshold for local heading/orientation sync

	const float SHOCK_TO_STUN_MULTIPLIER = 2.82;

	//! server / singleplayer properties
	protected int m_StanceVariation = 0;
	protected int m_LastMindState = -1;
	protected float m_LastMovementSpeed = -1;

	protected bool m_KnuckleLand = false;
	protected float m_KnuckleOutTimer = 0;

	protected int m_MindState = -1;
	protected int m_OrientationLocal = -1; // local 'companion' value for sync checking
	protected int m_OrientationSynced = -1;
	protected float m_OrientationTimer;
	protected float m_MovementSpeed = -1;
	protected float m_MovementDirection;

	protected vector m_DefaultHitPosition;

	protected AbstractWave m_LastSoundVoiceAW;
	protected ref InfectedBanditSoundEventHandler m_InfectedBanditSoundEventHandler;

	protected ref array<Object> m_AllTargetObjects;
	protected ref array<typename> m_TargetableObjects;

	// static ref map<int,ref array<string>> 	m_FinisherSelectionMap; //! which selections in the FireGeometry trigger which finisher on hit (when applicable)

	protected bool m_IsCrawling; //'DayZInfectedCommandCrawl' is transition to crawl only, 'DayZInfectedCommandMove' used after that, hence this variable

	protected AIAgent m_AIAgent;
	private ref BanditST m_AnimST;
	protected int m_Pose = 0;
	protected int m_AnimInstance;
	protected int m_Stance;
	private BanditCommandStay m_CommandStay;

	protected ref array<ref BehaviourGroupInfectedPackWaypointParams> m_WaypointParams = new array<ref BehaviourGroupInfectedPackWaypointParams>();
	protected ref ref TStringArray m_Waypoints = new TStringArray;
	protected int m_WaypointIndex = 0;
	private autoptr BanditAIGroup m_Group = new BanditAIGroup();
	protected int m_GroupID;

	protected bool m_ShouldTalkNPC;
	protected int m_TalkingNPC_ID = -1;
	protected int m_ShouldPlayEmoteID = 0;
	protected bool m_GroupLeader;

	protected BanditSniperTrigger m_SniperTrigger;
	protected Man m_SniperTarget;

	protected PlayerBase _targetPlayer;
	protected DayZCreature _targetCreature;
	protected CarScript _targetCar;

	protected EntityAI m_WeaponEntity;
	protected string m_ConfigWeaponType = "";
	protected ref TStringArray m_ConfigAttachments = new TStringArray;
	protected ref TStringArray m_Loadout = new TStringArray;
	protected ref TStringArray m_Loot = new TStringArray;
	protected bool m_Raised;
	protected float m_AimY;
	protected float m_LookX = 0;
	protected float m_LookY = 0;
	protected bool m_ForcePos = false;
	protected vector m_ForcedPosition;
	protected float m_BanditAccuracy;
	protected float m_GrenadeChance;

	private autoptr PGFilter m_PathFilter;

	// Attack with Firearm logic

	private bool _isAttacking = false;
	private int _attackCount = 1;
	private float _attackTimer = 0.0;
	private float _attackInterval = 0.2;

	//-------------------------------------------------------------

	void InfectedBanditBase()
	{
		Init();
	}

	void ~InfectedBanditBase()
	{
		if (GetGame() && GetGame().IsServer())
		{
			if (m_WeaponEntity)
			{
				GetGame().ObjectDelete(m_WeaponEntity);
			}
		}
	}

	void Init()
	{
		SetEventMask(EntityEvent.INIT | EntityEvent.SIMULATE);

		m_IsCrawling = false;

		RegisterNetSyncVariableInt("m_MindState", -1, 4);
		RegisterNetSyncVariableInt("m_OrientationSynced", 0, 359);
		RegisterNetSyncVariableFloat("m_MovementSpeed", -1, 3);
		RegisterNetSyncVariableBool("m_IsCrawling");

		RegisterNetSyncVariableBool("m_ShouldTalkNPC");
		RegisterNetSyncVariableInt("m_TalkingNPC_ID");
		RegisterNetSyncVariableInt("m_ShouldPlayEmoteID");
		RegisterNetSyncVariableBool("m_Raised");

		//! sets default hit position and cache it here (mainly for impact particles)
		m_DefaultHitPosition = SetDefaultHitPosition(GetDayZInfectedType().GetDefaultHitPositionComponent());

		//! client only
		if (!GetGame().IsDedicatedServer())
		{
			m_LastSoundVoiceAW = null;
			m_InfectedBanditSoundEventHandler = new InfectedBanditSoundEventHandler(this);
		}

		m_AllTargetObjects = new array<Object>;
		m_TargetableObjects = new array<typename>;
		m_TargetableObjects.Insert(PlayerBase);
		m_TargetableObjects.Insert(AnimalBase);
		m_TargetableObjects.Insert(ZombieBase);
		m_TargetableObjects.Insert(InfectedBanditBase);
		m_TargetableObjects.Insert(CarScript);

		m_OrientationTimer = 0;

		if (GetGame().IsServer())
		{
			if (!m_AnimST)
			{
				m_AnimST = new BanditST(this);
			}
		}

		SetFlags(EntityFlags.TOUCHTRIGGERS, true);
	}

	// some missing sounds producing nullpointers...
	override void ProcessStepEvent(AnimStepEvent step_event)
	{
		SoundObjectBuilder soundBuilder = step_event.GetSoundBuilder(GetSurfaceType().Hash());
		if (soundBuilder == NULL)
			return;

		soundBuilder.AddEnvSoundVariables(GetPosition());
		SoundObject soundObject = soundBuilder.BuildSoundObject();
		if (soundObject)
		{
			AttenuateSoundIfNecessary(soundObject);
			PlaySound(soundObject, soundBuilder);
		}

		// TODO effects
	}

	BanditST GetAnimST()
	{
		return m_AnimST;
	}

	Weapon_Base GetFirearm()
	{
		// musime zmenit
		return Weapon_Base.Cast(m_WeaponEntity);
		/*
		EntityAI hands = FindAttachmentBySlotName("BanditHands2");
		if (hands)
		{
			Weapon_Base wpn = Weapon_Base.Cast(hands);
			if (wpn)
			{
				return wpn;
			}
		}
		return null;
		*/
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		if (!GetGame().IsDedicatedServer())
		{
			if (rpc_type == 8832135811)
			{
				m_WeaponEntity = EntityAI.Cast(GetChildren());
				m_WeaponEntity.SetInvisible(true);
				Print(m_WeaponEntity.GetType());
			}
		}
	}

	override void RegisterAnimEvents()
	{
		super.RegisterAnimEvents();

		if (GetGame().IsServer())
		{
			RegisterAnimationEvent("WeaponFire", "OnScriptServerEvent");
			// RegisterAnimationEvent("Item_LeaveHands", "OnScriptServerEvent");
		}
	}

	void OnScriptServerEvent(int event_id, string event_user_string)
	{
		switch (event_id)
		{
		case IBAnimScriptEvent.WEAPONFIRE:
		{
			PrepareWeaponFire();
			break;
		}
		}
	}

	void PrepareWeaponFire()
	{
		_attackCount = Math.RandomIntInclusive(1, 3);
		if (IsSniper())
		{
			_attackCount = 1;
		}
		// Spocitat vzdalenost k aktivnimu target (m_actual_target)
		// Podle vzdalenosti nastavit m_attackInterval + samozrejme brat v potaz i typ zbrane
		// _attackInterva = ******
		// _attackCount = ***
		_isAttacking = true; // Tohle se musi setnout vzdy az na konci
	}

	BanditCommandStay StartCommand_BanditStay()
	{
		if (!m_AnimST)
			m_AnimST = new BanditST(this);

		m_CommandStay = BanditCommandStay.Cast(StartCommand_Script(new BanditCommandStay(this)));

		return m_CommandStay;
	}

	//! synced variable(s) handler
	override void OnVariablesSynchronized()
	{
		DebugSound("[Infected @ " + this + "][OnVariablesSynchronized]");
		HandleSoundEvents();

		if (m_OrientationLocal != m_OrientationSynced)
		{
			m_OrientationLocal = m_OrientationSynced;
		}
	}

	//-------------------------------------------------------------
	override void EOnInit(IEntity other, int extra)
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			m_StanceVariation = Math.RandomInt(0, 4);

			DayZInfectedCommandMove moveCommand = GetCommand_Move();
			moveCommand.SetStanceVariation(m_StanceVariation);

			/*
			Weapon_Base oWpn = Weapon_Base.Cast(GetGame().CreateObject( "AKM" , "0 0 0" ));
			if (oWpn)
			{
				oWpn.SpawnAmmo("Mag_AKM_30Rnd");
				oWpn.GetInventory().CreateAttachment("AK_WoodHndgrd");
				oWpn.GetInventory().CreateAttachment("AK_WoodBttstck");
				this.GetInventory().AddEntityToInventory(oWpn);
				this.SetAnimInstance(IBAnimInstance.RIFLE);
			}
			*/
			// m_ConfigWeaponType = "AKM";
			// m_ConfigAttachments = {"Mag_AKM_30Rnd", "AK_WoodHndgrd", "AK_WoodBttstck"};

			EquipWeapon(m_ConfigWeaponType, m_ConfigAttachments);

			// TStringArray waypoints = {"5237.821777 9.568775 2157.804199", "4887.835449 9.560701 2578.265625", "4917.622559 9.539299 2599.980469"};
			// SetWaypoints(waypoints);
			// m_ForcePosition = GetPosition();
		}
	}

	// ** SNIPER AND TRIGGERS ** //

	void AttachTrigger(BanditSniperTrigger trigger)
	{
		m_SniperTrigger = trigger;
	}

	BanditSniperTrigger GetTrigger()
	{
		return m_SniperTrigger;
	}

	bool IsSniper()
	{
		return m_SniperTrigger != null;
	}

	void SetSniperTarget(Man target)
	{
		m_SniperTarget = target;
	}

	Man GetSniperTarget()
	{
		return m_SniperTarget;
	}

	void ForcePosition(vector position)
	{
		m_ForcePos = true;
		m_ForcedPosition = position;
	}

	// ** ACCURACY ** //

	float GetAccuracy()
	{
		return m_BanditAccuracy;
	}

	void SetAccuracy(float accuracy)
	{
		m_BanditAccuracy = accuracy / 100;
	}

	// ** GRANADE INSTANCE ** //

	float GetGrenadeChance()
	{
		return m_GrenadeChance;
	}

	void SetGrenadeChance(float grchance)
	{
		m_GrenadeChance = grchance / 100;
	}

	// ** WEAPON TRANSFORM ** //

	void SetupWeapon(string weapon, TStringArray attachments)
	{
		m_ConfigWeaponType = weapon;
		m_ConfigAttachments = attachments;
	}

	void EquipWeapon(string itemhands, TStringArray attachments)
	{
		if (!GetGame().IsServer())
			return;
		// DeleteHeldItems();
		// EntityAI weaponEntity = EntityAI.Cast(GetGame().CreateObject(itemhands, GetPosition()));
		EntityAI weaponEntity, attachment;
		int i;
		string attachmentName;
		if (itemhands)
		{
			weaponEntity = EntityAI.Cast(GetGame().CreateObjectEx(itemhands, "0 0 0", ECE_CREATEPHYSICS | ECE_DYNAMIC_PERSISTENCY | ECE_NOPERSISTENCY_WORLD));
		}
		ChangeAnimInstance(weaponEntity);
		if (weaponEntity)
		{
			// weaponEntity.SetTakeable(false);

			Weapon_Base oWpn = Weapon_Base.Cast(weaponEntity);
			if (oWpn)
			{
				// tady nastaveni animinstance podle typu zbrane

				// this.SetAnimInstance(IBAnimInstance.RIFLE);

				if (attachments)
				{
					for (i = 0; i < attachments.Count(); i++)
					{
						attachmentName = attachments.Get(i);
						attachment = EntityAI.Cast(GetGame().CreateObjectEx(attachmentName, "0 0 0", ECE_CREATEPHYSICS | ECE_DYNAMIC_PERSISTENCY | ECE_NOPERSISTENCY_WORLD));

						if (attachment)
						{
							if (Magazine_Base.Cast(attachment)) // Ověření, zda je to zásobník
							{
								oWpn.SpawnAmmo(attachmentName);
							}
							else
							{
								oWpn.GetInventory().CreateAttachment(attachmentName);
							}
						}
					}
				}
			}
			else
			{
				if (attachments)
				{
					for (i = 0; i < attachments.Count(); i++)
					{
						attachmentName = attachments.Get(i);
						attachment = EntityAI.Cast(GetGame().CreateObjectEx(attachmentName, "0 0 0", ECE_CREATEPHYSICS | ECE_DYNAMIC_PERSISTENCY | ECE_NOPERSISTENCY_WORLD));

						if (attachment)
						{

							weaponEntity.GetInventory().CreateAttachment(attachmentName);
						}
					}
				}
			}

			int handBone = GetBoneIndexByName("righthand");
			m_WeaponEntity = weaponEntity;
			if (handBone != -1)
			{
				// weaponEntity.SetOrientation("0 -180 0") ;
				HandleWeaponTransform();
				// dodelat jeste posuny
				this.AddChild(m_WeaponEntity, handBone);

				// Print("weapon " + weaponEntity + " attached");
			}

			// SetupStartingAmmo();
			m_WeaponEntity.SetTakeable(false);
			// m_WeaponSpawnTime = GetGame().GetTime();

			GetGame().RemoteObjectTreeDelete(weaponEntity);
			GetGame().RemoteObjectTreeCreate(weaponEntity);
		}
		GetGame().RemoteObjectTreeDelete(this);
		GetGame().RemoteObjectTreeCreate(this);
	}

	void HandleWeaponTransform()
	{
		if (!m_WeaponEntity)
			return;

		vector pos;
		vector ori;
		vector mat[4];
		Math3D.MatrixIdentity4(mat);
		switch (GetAnimInstance())
		{
		case IBAnimInstance.PISTOL:
			pos = Vector(0, 0.0, 0);
			ori = Vector(10, 170, 6);
			break;

		case IBAnimInstance.RIFLE:
			pos = Vector(-0.2, -0.01, 0.02);
			ori = Vector(10, 170, 6);
			break;

		case IBAnimInstance.KNIFE:
			pos = Vector(-0.1, 0, 0.03);
			ori = Vector(190, 170, 6);
			break;

		case IBAnimInstance.EMPTYHANDS:
		default:
			pos = Vector(-0.08, -0.3, 0);
			ori = Vector(0, 170, 0);
			break;
		}

		mat[3] = pos;
		m_WeaponEntity.SetTransform(mat);
		m_WeaponEntity.SetOrientation(ori);
	}

	// ** ANIMATION INSTANCES ** //

	void ChangeAnimInstance(EntityAI iteminhands)
	{

		if (iteminhands == null)
		{
			SetAnimInstance(IBAnimInstance.EMPTYHANDS);
		}
		Rifle_Base rifle = Rifle_Base.Cast(iteminhands);
		BoltRifle_Base boltrifle = BoltRifle_Base.Cast(iteminhands);
		BoltActionRifle_Base boltactionrifle = BoltActionRifle_Base.Cast(iteminhands);
		Pistol_Base pistol = Pistol_Base.Cast(iteminhands);
		ToolBase knife = ToolBase.Cast(iteminhands);
		LongHorn_Base longhorn = LongHorn_Base.Cast(iteminhands);
		Magnum_Base magnum = Magnum_Base.Cast(iteminhands);
		Derringer_Base derringer = Derringer_Base.Cast(iteminhands);

		if (rifle || boltrifle || boltactionrifle)
		{
			SetAnimInstance(IBAnimInstance.RIFLE);
		}
		else if (pistol || longhorn || magnum || derringer)
		{
			SetAnimInstance(IBAnimInstance.PISTOL);
		}
		else if (knife)
		{
			SetAnimInstance(IBAnimInstance.KNIFE);
		}
		else
		{
			SetAnimInstance(IBAnimInstance.EMPTYHANDS);
		}
	}

	void SetAnimInstance(int animinstance)
	{
		m_AnimInstance = animinstance;
	}

	int GetAnimInstance()
	{
		return m_AnimInstance;
	}

	void SetStance(int stance)
	{
		m_Stance = stance;
	}

	int GetStance()
	{
		return m_Stance;
	}
	
	void SetMovementDirection(float dir)
	{
		m_MovementDirection = dir;
	}
	
	float GetMovementDirection()
	{
		return m_MovementDirection;
	}
	
	void SetLookX (float lookx)
	{
		m_LookX = lookx;
	}
	
	float GetLookX()
	{
		return m_LookX;
		
	}
	
	void SetLookY (float looky)
	{
		m_LookY = looky;
	}
	
	float GetLookY()
	{
		return m_LookY;
		
	}
	

	// ** GROUPS ** //

	void SetGroup(BanditAIGroup group)
	{
		m_Group = group;
	}

	BanditAIGroup GetGroup()
	{
		return m_Group;
	}

	void SetGroupID(int groupid)
	{
		m_GroupID = groupid;
	}

	int GetGroupID()
	{
		return m_GroupID;
	}

	bool IsGroupLeader()
	{
		return m_GroupLeader;
	}

	void SetGroupLeader(bool leader)
	{
		m_GroupLeader = leader;
	}

	void ShouldPlayEmoteID(int emoteid)
	{
		m_ShouldPlayEmoteID = emoteid;
		SetSynchDirty();
	}

	int GetEmotetoPlay()
	{
		if (m_ShouldPlayEmoteID)
		{
			return m_ShouldPlayEmoteID;
		}
		return 0;
	}

	void SetNPCID(int id)
	{
		m_TalkingNPC_ID = id;
		SetSynchDirty();
	}

	int GetNPCID()
	{
		return m_TalkingNPC_ID;
	}

	void SetTalkNPC(bool talk)
	{
		m_ShouldTalkNPC = talk;
		SetSynchDirty();
	}

	bool ShouldTalkNPC()
	{
		return m_ShouldTalkNPC;
	}

	override bool IsMan()
	{
		return true;
	}

	bool IsMale()
	{
		return true;
	}

	override bool IsZombie()
	{
		return false;
	}

	override bool IsDanger()
	{
		return true;
	}

	override bool ResistContaminatedEffect()
	{
		EntityAI mask_ent = FindAttachmentBySlotName("Mask");
		// jeste dodat inherovanou classu (gasmaska)
		//GasMask gasmask = GasMask.Cast(mask_ent);
		MaskBase mask = MaskBase.Cast(mask_ent);
		if (mask && mask.IsGasMask())
		{
			return true;
		}
		return false;
	}

	override bool IsInventoryVisible()
	{
		return !IsAlive();
	}

	override bool IsZombieMilitary()
	{
		return false;
	}

	override bool CanBeBackstabbed()
	{
		return false;
	}

	override AnimBootsType GetBootsType()
	{
		return AnimBootsType.Boots;
	}

	override bool CanBeSkinned()
	{
		return false;
	}

	override bool IsHealthVisible()
	{
		return false;
	}

	override bool IsRefresherSignalingViable()
	{
		return false;
	}

	//! returns hit component for attacking AI
	override string GetHitComponentForAI()
	{
		return GetDayZInfectedType().GetHitComponentForAI();
	}

	//! returns default hit component (fallback)
	override string GetDefaultHitComponent()
	{
		return GetDayZInfectedType().GetDefaultHitComponent();
	}

	override vector GetDefaultHitPosition()
	{
		return m_DefaultHitPosition;
	}

	protected vector SetDefaultHitPosition(string pSelection)
	{
		return GetSelectionPositionMS(pSelection);
	}

	//! returns suitable hit components for finisher attacks; DEPRECATED
	override array<string> GetSuitableFinisherHitComponents()
	{
		return GetDayZInfectedType().GetSuitableFinisherHitComponents();
	}

	int GetMindStateSynced()
	{
		return m_MindState;
	}

	//! returns rounded zombie yaw for sync purposes
	int GetOrientationSynced()
	{
		return m_OrientationSynced;
	}

	int GetPose()
	{
		return m_Pose;
	}

	void SetPose(int pose)
	{
		m_Pose = pose;
	}

	void Raise()
	{
		m_Raised = true;
	}

	void SetRaised(bool raised)
	{
		m_Raised = raised;
		SetSynchDirty();
	}

	bool GetRaised()
	{
		return m_Raised;
	}

	float ComputeAimY(vector npc, vector target)
	{
		float aimy = 0;
		float height = target[1] - npc[1];
		float distance = vector.Distance(npc, target);
		aimy = Math.RAD2DEG * Math.Asin(height / distance);
		return aimy;
	}

	float ComputeYaw(vector npc, vector target)
	{

		float yaw = 0;
		float xdiff = target[0] - npc[0];
		float zdiff = target[2] - npc[2];
		yaw = Math.RAD2DEG * Math.Atan2(xdiff, zdiff);

		return yaw;
	}

	void SetAimY(float angle)
	{
		m_AimY = angle;
	}

	float GetAimY()
	{
		return m_AimY;
	}

	void SetWaypointIndex(int index)
	{
		m_WaypointIndex = index;
	}

	int GetWaypointIndex()
	{
		return m_WaypointIndex;
	}

	void SetWaypoints(TStringArray waypoints)
	{
		if (!waypoints)
		{
			return;
		}

		m_Waypoints = waypoints;
		m_AIAgent = this.GetAIAgent();
		BehaviourGroupInfectedPack bgip;
		if (m_AIAgent && m_AIAgent.GetGroup() && m_AIAgent.GetGroup().GetBehaviour())
		{
			Class.CastTo(bgip, m_AIAgent.GetGroup().GetBehaviour());
		}
		if (bgip)
		{
			m_WaypointParams.Clear();
			for (int i = 0; i < waypoints.Count(); i++)
			{
				if (waypoints.Count() > 1)
				{
					m_WaypointParams.Insert(BehaviourGroupInfectedPackWaypointParams(waypoints.Get(i).ToVector(), 1));
				}
				else
				{
					m_WaypointParams.Insert(BehaviourGroupInfectedPackWaypointParams(waypoints.Get(i).ToVector(), 0.5));
				}
			}
			AIBLogger.Debug("Waypoints set " + waypoints.Get(0) + " npc " + GetType());

			if (waypoints.Count() > 1)
			{
				bgip.SetWaypoints(m_WaypointParams, m_WaypointIndex, true, true);
			}
			else
			{
				bgip.SetWaypoints(m_WaypointParams, 0, true, false);
			}

			/*
			if (IsGroupLeader())
			{
				bgip.SetWaypoints( m_WaypointParams, 0, true, true );
			}
			else
			{
				bgip.SetWaypoints( m_WaypointParams, 0, true, false );
			}
			*/
		}
	}

	// ** COMMAND HANDLER ** //

	// StartCommand_BanditStay
	override bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		if (super.ModCommandHandlerBefore(pDt, pCurrentCommandID, pCurrentCommandFinished))
		{
			return true;
		}
		m_AIAgent = this.GetAIAgent();
		DayZInfectedInputController inputController = GetInputController();
		// inputController.OverrideAlertLevel(true, true,3, 3);
		//SetMovementDirection(90);
		if (pCurrentCommandID == DayZInfectedConstants.COMMANDID_SCRIPT)
		{
			DayZInfectedCommandScript ics = GetCommand_Script();
			if (BanditCommandStay.Cast(ics) != null)
			{
				return true;
			}
		}
		if (GetPose() > 0)
		{
			inputController.OverrideMovementSpeed(true, 0);
			StartCommand_BanditStay();
			m_AIAgent.SetKeepInIdle(true);
		}
		if (IsSniper())
		{
			// StartCommand_BanditStay();
			// inputController.OverrideMovementSpeed(true, 0);
			// m_WeaponEntity.SetInvisible(true);
		}
		if (m_Waypoints.Count() == 1)
		{
			SetWaypoints(m_Waypoints);
			// inputController.OverrideAlertLevel(true, true, 2, 2);
		}
		// Print("alert level " + this + " " + inputController.GetAlertLevel());
		return false;
	}

	override bool ModCommandHandlerAfter(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		if (super.ModCommandHandlerAfter(pDt, pCurrentCommandID, pCurrentCommandFinished))
			return true;
		vector from = ModelToWorld("0 1 0.1");
		vector to = ModelToWorld("0 1 2.0");
		vector to100 = ModelToWorld("0 1 100.0");
		SearchAndOpenDoors(from, to);
		EntityAI ent = SearchTargetByRaycastVector(from,to100,this);
		// Každých X sekund nebo jen pokud předtím fix nebyl
		if (GetGame().IsServer() /*&& !m_WeaponFixAttempted*/)
		{
			// Print("bandit " + this + " " + m_WeaponEntity);
			if (m_ConfigWeaponType && (!m_WeaponEntity || vector.DistanceSq(m_WeaponEntity.GetPosition(), "0 0 0") < 1.0))
			{
				// Print("[NPC_AUTO_FIX] NPC " + this.ToString() + " má chybějící/špatnou zbraň, provádím opravu!");

				// Získáme data z configu (ulož si je jako member proměnné při initu, ať nemusíš znova hledat v JSON!)
				string weaponType = m_ConfigWeaponType;			// Nastav si při EOnInit
				TStringArray attachments = m_ConfigAttachments; // Nastav si při EOnInit

				// Znovu přivolej pouze tuto rutinu, NE celý setup

				EquipWeapon(weaponType, attachments);

				// m_WeaponFixAttempted = true; // Zabrání opakovanému fixu – případně nastav timer pro další pokus
			}
		}
		return false;
	}

	//-------------------------------------------------------------
	//!
	//! CommandHandler
	//!

	void CommandHandler(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		//! for mods
		if (ModCommandHandlerBefore(pDt, pCurrentCommandID, pCurrentCommandFinished))
		{
			return;
		}

		//! handle death
		if (HandleDeath(pCurrentCommandID))
		{
			return;
		}
		if (!IsGroupLeader() && GetGroup())
		{
			// nastavit waypoint podle formace
			/*
			vector waypoint = GetGroup().GetFormation().LocalFormPos(GetGroup().GetMemberID(this));
			TStringArray wps = new TStringArray();
			//Print("waypoint member " + waypoint + " world " + GetGroup().GetLeader().ModelToWorld(waypoint));
			string wp = (GetGroup().GetLeader().ModelToWorld(waypoint)).ToString();
			wps.Insert(wp);
			SetWaypoints(wps);
			*/
		}
		//! movement handler (just for sync now)
		HandleMove(pCurrentCommandID);
		HandleOrientation(pDt, pCurrentCommandID);

		//! handle finished commands
		if (pCurrentCommandFinished)
		{
			//! default behaviour after finish is to start move
			DayZInfectedCommandMove moveCommand = StartCommand_Move();
			moveCommand.SetStanceVariation(m_StanceVariation);

			return;
		}

		//! for mods
		if (ModCommandHandlerInside(pDt, pCurrentCommandID, pCurrentCommandFinished))
		{
			return;
		}

		//! crawl transition
		if (HandleCrawlTransition(pCurrentCommandID))
		{
			return;
		}

		//! damage hits
		if (HandleDamageHit(pCurrentCommandID))
		{
			return;
		}

		DayZInfectedInputController inputController = GetInputController();
		if (inputController)
		{
			if (HandleVault(pCurrentCommandID, inputController, pDt))
			{
				return;
			}

			if (HandleMindStateChange(pCurrentCommandID, inputController, pDt))
			{
				return;
			}

			if (FightLogic(pCurrentCommandID, inputController, pDt))
			{
				return;
			}
		}

		//!
		if (ModCommandHandlerAfter(pDt, pCurrentCommandID, pCurrentCommandFinished))
		{
			return;
		}
	}

	//-------------------------------------------------------------
	//!
	//! CommandHandlerDebug
	//!

	void CommandHandlerDebug(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		if (GetPluginManager())
		{
			PluginDayZInfectedDebug infectedDebug = PluginDayZInfectedDebug.Cast(GetPluginManager().GetPluginByType(PluginDayZInfectedDebug));
			if (infectedDebug)
				infectedDebug.CommandHandler(this);
		}
	}
	//-------------------------------------------------------------
	//!
	//! HandleMove
	//!

	void HandleMove(int pCurrentCommandID)
	{
		DayZInfectedInputController ic = GetInputController();
		m_MovementSpeed = ic.GetMovementSpeed();
		/*
		Print("behaviour slot " + ic.GetBehaviourSlot());
		Print("calm " + DayZAnimalBehaviourSlot.CALM);
		Print("alert level " + ic.GetAlertLevel());
		Print("target " + ic.GetTargetEntity());
		*/
		if (Math.AbsFloat(m_LastMovementSpeed - m_MovementSpeed) >= 0.9 && m_LastMovementSpeed != m_MovementSpeed)
		{
			SetSynchDirty();
		}
		m_LastMovementSpeed = m_MovementSpeed;
	}

	//-------------------------------------------------------------
	//!
	//! HandleOrientation
	//!

	void HandleOrientation(float pDt, int pCurrentCommandID)
	{
		// DayZInfectedInputController ic = GetInputController();
		// ic.GetLookAtDirectionWS(); //TODO: implement actual look direction check??

		m_OrientationTimer += pDt;

		int yaw;
		yaw = Math.Round(GetOrientation()[0]);
		yaw = Math.NormalizeAngle(yaw);

		// atan2(sin(x-y), cos(x-y))
		float rad_src = m_OrientationSynced * Math.DEG2RAD;
		float rad_tgt = yaw * Math.DEG2RAD;

		float diff = Math.Atan2(Math.Sin(rad_tgt - rad_src), Math.Cos(rad_src - rad_tgt));
		//Print( "diff  :" + diff);
		diff *= Math.RAD2DEG;
		//Print("diff 1: " + diff);
		diff = Math.Round(diff);
		//Print("diff 2: " + diff);
		
		if (m_OrientationTimer >= 2.0 || m_OrientationSynced == -1 || Math.AbsInt(diff) > ORIENTATION_SYNC_THRESHOLD)
		{
			m_OrientationTimer = 0.0;
			if (GetCommand_Move())
			{
				GetCommand_Move().StartTurn(diff*1.3,0);
			}
			if (m_OrientationSynced == -1 || Math.AbsInt(diff) > 5)
			{
				// Print("DbgSyncOrientation | HandleMove | original: " + m_OrientationSynced + " | target: " + yaw + " | diff: " + diff);
				SetSynchDirty();
				m_OrientationSynced = yaw;
			}
		}
	}

	//-------------------------------------------------------------
	//!
	//! HandleDeath
	//!

	float m_DamageHitDirection = 0;
	int m_DeathType = 0;

	bool HandleDeath(int pCurrentCommandID)
	{
		if (pCurrentCommandID == DayZInfectedConstants.COMMANDID_DEATH)
		{
			return true;
		}

		if (!IsAlive())
		{

			StartCommand_Death(m_DeathType, m_DamageHitDirection);
			m_MovementSpeed = -1;
			m_MindState = -1;
			SetSynchDirty();
			AI_ApplyDamageToGear(this, m_WeaponEntity);
			return true;
		}

		return false;
	}

	// Overrid ethis method if you want to handle the damage/equipment after death differently
	void AI_ApplyDamageToGear(EntityAI owner, EntityAI weapon)
	{
		if (!weapon || !owner)
			return;

		EntityAI zbran = m_WeaponEntity;
		if (zbran)
		{

			vector m4[4];
			zbran.GetTransform(m4);
			// this.GetInventory().DropEntityWithTransform(InventoryMode.SERVER, this, zbran, m4);
			this.RemoveChild(zbran, true);

			vector position = zbran.GetPosition();

			vector rotation_matrix[3];
			Math3D.YawPitchRollMatrix(zbran.GetOrientation(), rotation_matrix);
			float direction[4];
			Math3D.MatrixToQuat(rotation_matrix, direction);

			MiscGameplayFunctions.ThrowEntityFromInventory(zbran, position, direction, "0 0 0", ThrowEntityFlags.NONE);

			m_WeaponEntity = null;
			float rndnum = Math.RandomFloat(-0.15, 0.20);
			if (rndnum < 0)
			{
				rndnum = 0;
			}
			zbran.SetHealth("", "", zbran.GetMaxHealth("", "") * rndnum);
			/*
			array<EntityAI> attachmenty = zbran.GetAttachmentsWithAttachments();
			for ( int i = 0; i < attachmenty.Count(); ++i )
			{
				Print("ATT " + attachmenty.Get(i));
			}
			*/

			array<EntityAI> children = new array<EntityAI>;
			zbran.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
			int count = children.Count();
			for (int i = 0; i < count; i++)
			{
				EntityAI child = children.Get(i);
				if (child)
				{
					child.SetHealth("", "", child.GetMaxHealth("", "") * rndnum);
				}
			}
		}

		// iterace nad sloty
		// znicit obleceni
		TStringArray slotsnames = {"HeadGear", "Mask", "Eyewear", "Vest", "ArmBand", "Gloves", "Body", "Back", "Hips", "Legs", "Feet"};
		for (int j = 0; j < slotsnames.Count(); j++)
		{
			EntityAI clothing = FindAttachmentBySlotName(slotsnames.Get(j));
			if (clothing)
			{
				float rndnum1 = Math.RandomFloat(-0.15, 0.20);
				if (rndnum1 < 0)
				{
					rndnum1 = 0;
				}
				clothing.SetHealth("", "", clothing.GetMaxHealth("", "") * rndnum1);
			}
		}
	}

	bool EvaluateDeathAnimation(EntityAI pSource, string pComponent, string pAmmoType, out int pAnimType, out float pAnimHitDir)
	{
		//!
		bool doPhxImpulse = GetGame().ConfigGetInt("cfgAmmo " + pAmmoType + " doPhxImpulse") > 0;

		//! anim type
		pAnimType = doPhxImpulse;

		//! direction
		pAnimHitDir = ComputeHitDirectionAngle(pSource);

		//! add some impulse if needed
		if (doPhxImpulse)
		{
			vector impulse = 80 * m_TransportHitVelocity;
			impulse[1] = 80 * 1.5;
			// Print("Impulse: " + impulse.ToString());

			dBodyApplyImpulse(this, impulse);
		}

		return true;
	}

	bool EvaluateDeathAnimationEx(EntityAI pSource, InfectedBanditHitData data, out int pAnimType, out float pAnimHitDir)
	{
		bool ret = EvaluateDeathAnimation(pSource, data.m_DamageZone, data.m_AmmoType, pAnimType, pAnimHitDir);

		// TODO - finisher animation start must be evaluated on comman start
		int finisher_type = GetGame().ConfigGetInt("cfgAmmo " + data.m_AmmoType + " finisherType");
		if (finisher_type > 0)
		{
			// pAnimType = DetermineFinisherDeathAnimation(DetermineFinisherHitType(pSource,data.m_Component));
			// pAnimType = DetermineFinisherDeathAnimation(finisher_type);
			ret = true;
		}

		return ret;
	}

	//-------------------------------------------------------------
	//!
	//! HandleVault
	//!

	int m_ActiveVaultType = -1;

	int GetVaultType(float height)
	{
		if (height <= 0.6)
			return 0;
		else if (height <= 1.1)
			return 1;
		else if (height <= 1.6)
			return 2;
		else
			return 3;
	}

	bool HandleVault(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		if (pCurrentCommandID == DayZInfectedConstants.COMMANDID_VAULT)
		{
			DayZInfectedCommandVault vaultCmd = GetCommand_Vault();
			if (vaultCmd && vaultCmd.WasLand())
			{
				m_KnuckleOutTimer = 0;
				m_KnuckleLand = true;
			}
			if (m_KnuckleLand)
			{
				m_KnuckleOutTimer += pDt;
				if (m_KnuckleOutTimer > 2.0)
					StartCommand_Vault(-1);
			}

			return true;
		}

		if (pInputController.IsVault())
		{
			float vaultHeight = pInputController.GetVaultHeight();
			int vaultType = GetVaultType(vaultHeight);
			m_KnuckleLand = false;
			StartCommand_Vault(vaultType);
			return true;
		}

		return false;
	}

	//-------------------------------------------------------------
	//!
	//! Mind state change
	//!

	bool HandleMindStateChange(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		DayZInfectedCommandMove moveCommand = GetCommand_Move();

		m_MindState = pInputController.GetMindState();
		// DoggoLogger.Log("MINDSTATE CHANGE " + m_MindState );
		if (m_LastMindState != m_MindState)
		{
			switch (m_MindState)
			{
			case DayZInfectedConstants.MINDSTATE_CALM:
				if (moveCommand && !moveCommand.IsTurning())
					moveCommand.SetIdleState(0);
				break;

			case DayZInfectedConstants.MINDSTATE_DISTURBED:
				if (moveCommand && !moveCommand.IsTurning())
					moveCommand.SetIdleState(1);
				break;

			case DayZInfectedConstants.MINDSTATE_CHASE:
				if (moveCommand && !moveCommand.IsTurning() && (m_LastMindState < DayZInfectedConstants.MINDSTATE_CHASE))
					moveCommand.SetIdleState(2);
				break;
			}
			// DoggoLogger.Log("MINDSTATE " + m_MindState);
			m_LastMindState = m_MindState;
			m_AttackCooldownTime = 0.0;
			SetSynchDirty();
		}
		return false;
	}

	//-------------------------------------------------------------
	//!
	//! Sound (client only)
	//!

	protected void HandleSoundEvents()
	{
		//! no sound handler - bail out
		if (!m_InfectedBanditSoundEventHandler)
		{
			return;
		}

		//! infected is dead
		if (!IsAlive())
		{
			//! stop all sounds
			m_InfectedBanditSoundEventHandler.Stop();
			return;
		}

		switch (m_MindState)
		{
		case DayZInfectedConstants.MINDSTATE_CALM:
			m_InfectedBanditSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_CALM_MOVE);
			break;
		case DayZInfectedConstants.MINDSTATE_ALERTED:
			m_InfectedBanditSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_ALERTED_MOVE);
			break;
		case DayZInfectedConstants.MINDSTATE_DISTURBED:
			m_InfectedBanditSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_DISTURBED_IDLE);
			break;
		case DayZInfectedConstants.MINDSTATE_CHASE:
			m_InfectedBanditSoundEventHandler.PlayRequest(EInfectedSoundEventID.MINDSTATE_CHASE_MOVE);
			break;
		default:
			m_InfectedBanditSoundEventHandler.Stop();
			break;
		}

		DebugSound("[Infected @ " + this + "][MindState]" + typename.EnumToString(DayZInfectedConstants, m_MindState));
		DebugSound("[Infected @ " + this + "][SoundEventID]" + typename.EnumToString(EInfectedSoundEventID, m_InfectedBanditSoundEventHandler.GetCurrentStateEventID()));
	}

	AbstractWave ProcessVoiceFX(string pSoundSetName)
	{
		ref SoundParams soundParams;
		ref SoundObjectBuilder soundObjectBuilder;
		ref SoundObject soundObject;
		if (!GetGame().IsDedicatedServer())
		{
			soundParams = new SoundParams(pSoundSetName);
			if (!soundParams.IsValid())
			{
				// SoundError("Invalid sound set.");
				return null;
			}

			soundObjectBuilder = new SoundObjectBuilder(soundParams);
			soundObject = soundObjectBuilder.BuildSoundObject();
			AttenuateSoundIfNecessary(soundObject);

			return PlaySound(soundObject, soundObjectBuilder);
		}

		return null;
	}

	override void OnSoundVoiceEvent(int event_id, string event_user_string)
	{
		// super.OnSoundVoiceEvent(event_id, event_user_string);
		AnimSoundVoiceEvent voice_event = GetCreatureAIType().GetSoundVoiceEvent(event_id);
		if (voice_event != null)
		{
			//! stop state sound when playing anim SoundVoice
			if (m_InfectedBanditSoundEventHandler) // && m_InfectedBanditSoundEventHandler.IsPlaying())
			{
				m_InfectedBanditSoundEventHandler.Stop();
				DebugSound("[Infected @ " + this + "][SoundEvent] InfectedBanditSoundEventHandler - stop all");
			}

			//! stop playing of old SoundVoice from anim (if any)
			if (m_LastSoundVoiceAW != null)
			{
				DebugSound("[Infected @ " + this + "][AnimVoiceEvent] Stopping LastAW");
				m_LastSoundVoiceAW.Stop();
			}

			//! play new SoundVoice from anim
			ProcessSoundVoiceEvent(voice_event, m_LastSoundVoiceAW);

			HandleSoundEvents();
		}
	}

	protected void ProcessSoundVoiceEvent(AnimSoundVoiceEvent sound_event, out AbstractWave aw)
	{
		if (!GetGame().IsDedicatedServer())
		{
			SoundObjectBuilder objectBuilder = sound_event.GetSoundBuilder();
			if (NULL != objectBuilder)
			{
				objectBuilder.UpdateEnvSoundControllers(GetPosition());
				SoundObject soundObject = objectBuilder.BuildSoundObject();
				AttenuateSoundIfNecessary(soundObject);
				aw = PlaySound(soundObject, objectBuilder);
			}
		}

		if (GetGame().IsServer())
		{
			if (sound_event.m_NoiseParams != NULL)
				GetGame().GetNoiseSystem().AddNoise(this, sound_event.m_NoiseParams);
		}
	}

	//-------------------------------------------------------------
	//!
	//! Combat
	//!

	EntityAI m_ActualTarget = NULL;
	float m_AttackCooldownTime = 0;
	DayZInfectedAttackType m_ActualAttackType = NULL;

	// ** TARGET HELPERS ** //

	bool IsTargetValid(EntityAI target)
	{
		if (!target)
		{
			return false;
		}

		if (!target.IsAlive())
		{
			return false;
		}

		// Guards should only consider players with raised weapon as valid threats (unless acting as sniper)
		PlayerBase playerTarget = PlayerBase.Cast(target);
		if (playerTarget && GetGroup() && GetGroup().GetFaction() == "Guards" && !IsSniper())
		{
			if (!playerTarget.IsRaised())
			{
				return false;
			}
		}

		return true;
	}

	void ClearTarget()
	{
		m_ActualTarget = NULL;
		_targetPlayer = NULL;
		_targetCreature = NULL;
		_targetCar = NULL;
		_isAttacking = false;
		_attackTimer = 0.0;
		_attackCount = 0;
	}

	bool IsViewOccludedFor(vector end, EntityAI entity)
	{
		vector start = GetBonePositionWS(GetBoneIndexByName("Head")); // GetPosition() + "0 1.5 0";
		// vector head = GetBonePositionMS(GetBoneIndexByName("Head"));
		// vector start = ModelToWorld(head+Vector(0,0,0.3));
		vector hitPos, hitNormal;
		Object hitObject;
		float hitFraction;

		set<Object> objects = new set<Object>;
		vector contact_dir;
		int contact_component;

		PhxInteractionLayers layerMask = PhxInteractionLayers.BUILDING | PhxInteractionLayers.CHARACTER | PhxInteractionLayers.BUILDING | PhxInteractionLayers.VEHICLE | PhxInteractionLayers.TERRAIN;
		// should do raycast but no navmesh raycast
		bool raycast = DayZPhysics.RayCastBullet(start, end, layerMask, null, hitObject, hitPos, hitNormal, hitFraction);

		// bool raycast = DayZPhysics.RaycastRV( start, end, hitPos, contact_dir, contact_component, objects, this, this, false, false, ObjIntersectView, 0.005 );

		// Print("RAYCAST " + raycast + " start " + start + " end " + end + " hitpos " + hitPos + " hitObject " + hitObject);
		// GetGame().ChatPlayer("raycast hit " + hitObject);
		if (hitObject == entity)
		{
			// Print("car hit occluded");
			return false;
		}
		if (raycast)
		{
			float dist = vector.Distance(end, hitPos);
			// GetGame().ChatPlayer("raycast dist " + dist);
			if (dist < 0.8)
			{
				// Print("eAI RAYCAST HIT");
				// GetGame().ChatPlayer("raycast false " );
				return false;
			}
			// GetGame().ChatPlayer("raycast true " );
			return true;
			// Print("RAYCAST TRUE");
		}
		else
		{
			// GetGame().ChatPlayer("raycast false 2 " );
			return false;
		}
		// return true;
		// Print("eAI Path Blocked " + PathBlocked(start, end, hitPos, hitNormal));
		return PathBlocked(start, end, hitPos, hitNormal);
	}

	bool IsViewOccluded(vector end)
	{
		vector start = GetBonePositionWS(GetBoneIndexByName("Head")); // GetPosition() + "0 1.5 0";
		// vector head = GetBonePositionMS(GetBoneIndexByName("Head"));
		// vector start = ModelToWorld(head+Vector(0,0,0.3));
		vector hitPos, hitNormal;
		Object hitObject;
		float hitFraction;

		set<Object> objects = new set<Object>;
		vector contact_dir;
		int contact_component;

		PhxInteractionLayers layerMask = PhxInteractionLayers.BUILDING | PhxInteractionLayers.CHARACTER | PhxInteractionLayers.BUILDING | PhxInteractionLayers.VEHICLE | PhxInteractionLayers.TERRAIN;
		// should do raycast but no navmesh raycast
		bool raycast = DayZPhysics.RayCastBullet(start, end, layerMask, null, hitObject, hitPos, hitNormal, hitFraction);

		// bool raycast = DayZPhysics.RaycastRV( start, end, hitPos, contact_dir, contact_component, objects, this, this, false, false, ObjIntersectView, 0.005 );

		// Print("RAYCAST " + raycast + " start " + start + " end " + end + " hitpos " + hitPos + " hitObject " + hitObject);
		// GetGame().ChatPlayer("raycast hit " + hitObject);
		if (raycast)
		{
			float dist = vector.Distance(end, hitPos);
			// GetGame().ChatPlayer("raycast dist " + dist);
			if (dist < 0.8)
			{
				// Print("eAI RAYCAST HIT");
				// GetGame().ChatPlayer("raycast false " );
				return false;
			}
			// GetGame().ChatPlayer("raycast true " );
			return true;
			// Print("RAYCAST TRUE");
		}
		else
		{
			// GetGame().ChatPlayer("raycast false 2 " );
			return false;
		}
		// return true;
		// Print("eAI Path Blocked " + PathBlocked(start, end, hitPos, hitNormal));
		return PathBlocked(start, end, hitPos, hitNormal);
	}

	bool PathBlocked(vector start, vector end, out vector hitPos, out vector hitNormal)
	{
		AIWorld world = GetGame().GetWorld().GetAIWorld();

		bool blocked = world.RaycastNavMesh(start, end, m_PathFilter, hitPos, hitNormal);
		// GetGame().ChatPlayer("raycast blocked " + blocked );
		return blocked;
	}
	/*
	void GetEntitesInTriangle( array<typename> targetableObjects, out array<EntityAI> entList)
	{
		vector min = this.ModelToWorld("0 -100 -400");
		vector max = this.ModelToWorld("900 100 400");
		array<EntityAI> foundEntities = new array<EntityAI>();
		DayZPlayerUtils.PhysicsGetEntitiesInBox(min,max,foundEntities);
		//entList = foundEntities;
		Object obj 		= NULL;
		foreach(auto ent: foundEntities)
		{
			Class.CastTo(obj, ent);
			if(obj)
			{
				// check for targetable objects
				if( !obj.IsAnyInherited(targetableObjects) )
					{ continue; }

				if( !obj.IsAlive() )
					{ continue; }
			}
			entList.Insert(ent);
			Print("entity "+ ent.GetType());
			bool inside = IsPointInsideTriangle(ent.GetPosition(), this.GetPosition(), this.ModelToWorld("900 0 -400"), this.ModelToWorld("900 0 400"));
			Print("is inside triangle " + inside);
		}
		Print("Count " + entList.Count());
		//sem pridat detecki uvnitr trojuhelniku pro nalezene entity

	}

	 bool IsPointInsideTriangle(vector p, vector p1, vector p2, vector p3) {
		// Calculate the area of the triangle
		float area = Area(p1, p2, p3);

		// Calculate the areas of the triangles formed with point p
		float area1 = Area(Vector(p[0], 0, p[2]), Vector(p2[0], 0, p2[2]), Vector(p3[0], 0, p3[2]));
		float area2 = Area(Vector(p1[0], 0, p[2]), Vector(p[0], 0, p[2]), Vector(p3[0], 0, p[2]));
		float area3 = Area(Vector(p1[0], 0, p2[2]), Vector(p2[0], 0, p2[2]), Vector(p[0], 0, p[2]));

		// The point is inside the triangle if the sum of the areas of the smaller triangles equals the area of the original triangle
		return area == area1 + area2 + area3;
	}

	float Area(vector p1, vector p2, vector p3) {
		return Math.AbsFloat((p1[0] * (p2[2] - p3[2]) + p2[0] * (p3[2] - p1[2]) + p3[0] * (p1[2] - p2[2])) / 2.0);
	}
	*/

	void SearchAndOpenDoors(vector from, vector to, Object ignore = NULL, float radius = 0.1, Object with = NULL)
	{
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		set<Object> geom = new set<Object>;
		set<Object> view = new set<Object>;
		// set< Object > fire = new set< Object >;
		DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, geom, with, ignore, false, false, ObjIntersectGeom, radius, CollisionFlags.ALLOBJECTS);

		DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius, CollisionFlags.ALLOBJECTS);
		// DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, fire, with, ignore, false, false, ObjIntersectFire, radius, CollisionFlags.ALLOBJECTS );
		for (int i = 0; i < geom.Count(); i++)
		{
			view.Insert(geom[i]);
		}
		if (view.Count() > 0)
		{
			// Print("view " + view.Get(0));
			// Print("component " + contact_component);

			Building building;
			if (Class.CastTo(building, view.Get(0)))
			{
				int doorIndex = building.GetDoorIndex(contact_component);
				if (doorIndex != -1)
				{
					if (building.CanDoorBeOpened(doorIndex, true)) // otevre i odemcene dvere :P
					{
						building.OpenDoor(doorIndex);
					}
				}
			}
		}
	}
	
	EntityAI SearchTargetByRaycastVector(vector from, vector to, Object ignore = NULL, float radius = 0.05, Object with = NULL)
	{
		vector contact_pos;
		vector contact_dir;
		int contact_component;
		set<Object> geom = new set<Object>;
		set<Object> view = new set<Object>;
		// set< Object > fire = new set< Object >;
		DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, geom, with, ignore, false, false, ObjIntersectGeom, radius, CollisionFlags.ALLOBJECTS);

		DayZPhysics.RaycastRV(from, to, contact_pos, contact_dir, contact_component, view, with, ignore, false, false, ObjIntersectView, radius, CollisionFlags.ALLOBJECTS);
		// DayZPhysics.RaycastRV( from, to, contact_pos, contact_dir, contact_component, fire, with, ignore, false, false, ObjIntersectFire, radius, CollisionFlags.ALLOBJECTS );
		for (int i = 0; i < geom.Count(); i++)
		{
			view.Insert(geom[i]);
		}
		if (view.Count() > 0)
		{
			for (int j = 0; j < view.Count(); j++)
			{
				ZombieBase zmb = ZombieBase.Cast(view.Get(j));
				if (zmb && zmb.IsAlive())
				{
					//Print( "I see zombie at distance " + vector.Distance(from,contact_pos) + " m");
					if (vector.Distance(from,contact_pos) < 2 && GetGroup().GetFaction() == "Guards")
					{
						m_ActualTarget = zmb;
						StartCommand_Attack(m_ActualTarget, 1, 0);
					}
					else if (vector.Distance(from,contact_pos) >= 2 && GetGroup().GetFaction() == "Guards" && (GetAnimInstance() == IBAnimInstance.RIFLE || GetAnimInstance() == IBAnimInstance.PISTOL))
					{
						m_ActualTarget = zmb;
						Raise();
						SetAimY(ComputeAimY(GetBonePositionWS(GetBoneIndexByName("Head")), zmb.GetBonePositionWS(zmb.GetBoneIndexByName("Head"))));
						StartCommand_Attack(m_ActualTarget, 16, 0);
					}
				}
			}
		}
		return NULL;
	}

	bool FightLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		if (pCurrentCommandID == DayZInfectedConstants.COMMANDID_MOVE)
		{
			// we attack only in chase & fight state
			int mindState = pInputController.GetMindState();
			// pInputController.OverrideAlertLevel(true, true, 200, 100);

			/*
			Print("CALM " + DayZInfectedConstants.MINDSTATE_CALM);
			Print("ALERTED " + DayZInfectedConstants.MINDSTATE_ALERTED);
			Print("DISTURBED " + DayZInfectedConstants.MINDSTATE_DISTURBED);
			Print("FIGHT " + DayZInfectedConstants.MINDSTATE_FIGHT);
			Print("CHASE " +  DayZInfectedConstants.MINDSTATE_CHASE);
			
			Print("MINDSTATE " + mindState);
			*/
			if (mindState == DayZInfectedConstants.MINDSTATE_CHASE)
			{
				return ChaseAttackLogic(pCurrentCommandID, pInputController, pDt);
			}
			else if (mindState == DayZInfectedConstants.MINDSTATE_FIGHT)
			{
				return FightAttackLogic(pCurrentCommandID, pInputController, pDt);
			}
			else
			{
				return ChaseAttackLogic(pCurrentCommandID, pInputController, pDt);
			}
		}
		else if (pCurrentCommandID == DayZInfectedConstants.COMMANDID_ATTACK)
		{
			DayZInfectedCommandAttack attackCommand = GetCommand_Attack();

			if (attackCommand && attackCommand.WasHit())
			{
				// Print("ACTUAL TARGET " + m_ActualTarget);
				if (m_ActualTarget != NULL)
				{
					if (m_ActualTarget.GetMeleeTargetType() == EMeleeTargetType.NONALIGNABLE)
					{
						return false;
					}
					bool playerInBlockStance = false;
					vector targetPos = m_ActualTarget.GetPosition();
					vector hitPosWS = targetPos;
					vector zombiePos = GetPosition();

					PlayerBase playerTarget = PlayerBase.Cast(m_ActualTarget);
					if (playerTarget)
					{
						playerInBlockStance = playerTarget.GetMeleeFightLogic() && playerTarget.GetMeleeFightLogic().IsInBlock();
					}
					// Print("PLAYERTARGET " + playerTarget);
					if (vector.DistanceSq(targetPos, zombiePos) <= 2 * 2)
					{
						//! player is in block stance and facing the infected
						if (playerInBlockStance && (Math.RAD2DEG * Math.AbsFloat(Math3D.AngleFromPosition(targetPos, MiscGameplayFunctions.GetHeadingVector(playerTarget), zombiePos))) <= GameConstants.AI_MAX_BLOCKABLE_ANGLE)
						{
							//! infected is playing heavy attack - decrease the dmg to light
							if (m_ActualAttackType && m_ActualAttackType.m_IsHeavy != 0)
							{
								// Print("HEAVY");
								hitPosWS = m_ActualTarget.ModelToWorld(m_ActualTarget.GetDefaultHitPosition()); //! override hit pos by pos defined in type
								DamageSystem.CloseCombatDamageName(this, m_ActualTarget, m_ActualTarget.GetHitComponentForAI(), "MeleeZombie", hitPosWS);
							}
							else
							{
								//! infected is playing light attack - do not send damage, play animation instead
								if (GetGame().IsServer())
								{
									// Print("LIGHT");
									hitPosWS = m_ActualTarget.GetDefaultHitPosition(); //! override hit pos by pos defined in type
									m_ActualTarget.EEHitBy(null, 0, this, -1, m_ActualTarget.GetDefaultHitComponent(), "Dummy_Light", hitPosWS, 1.0);
								}
							}
						}
						else
						{
							// Print("ELSE");
							hitPosWS = m_ActualTarget.ModelToWorld(m_ActualTarget.GetDefaultHitPosition()); //! override hit pos by pos defined in type
							DamageSystem.CloseCombatDamageName(this, m_ActualTarget, m_ActualTarget.GetHitComponentForAI(), "MeleeZombie" /*m_ActualAttackType.m_AmmoType*/, hitPosWS);
						}
					}
				}
			}

			return true;
		}

		return false;
	}

	bool ChaseAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		// always update target - it can be destroyed
		m_ActualTarget = pInputController.GetTargetEntity();
		// Print("ACTUAL TARGET " + m_ActualTarget);
		//! do not attack players in vehicle - hotfix
		m_AIAgent = this.GetAIAgent();

		PlayerBase pb = PlayerBase.Cast(m_ActualTarget);
		/*
		if ( pb && pb.GetCommand_Vehicle() )
		{
			return false;
		}
		*/
		// inputController.OverrideLookAt(true, "180 0 0");

		if (m_AttackCooldownTime > 0)
		{
			m_AttackCooldownTime -= pDt * GameConstants.AI_ATTACKSPEED;

			if (IsSniper())
			{
				// ref array<ref TriggerInsider> targetsidle = GetTrigger().GetInsiders();
				// Print ("sniper 0 " );
				if (GetSniperTarget())
				{
					EntityAI snipertarget1 = GetSniperTarget();
					PlayerBase snipedplayer1 = PlayerBase.Cast(snipertarget1);

					// Print ("sniper 1 " + snipedplayer1);
					// GetGame().ChatPlayer("sniper pred otacenim " );
					if ((GetAnimInstance() == IBAnimInstance.RIFLE || GetAnimInstance() == IBAnimInstance.PISTOL) && snipertarget1 && snipertarget1.IsAlive() && snipedplayer1 && (!IsViewOccluded(snipedplayer1.GetBonePositionWS(snipedplayer1.GetBoneIndexByName("Head"))) || !IsViewOccluded(snipedplayer1.GetBonePositionWS(snipedplayer1.GetBoneIndexByName("Pelvis")))))
					// Print ("Sniper target " + snipertarget);
					{
						vector ori = GetOrientation();
						// Print("sniper orientation " + GetOrientation());
						float yaw = ComputeYaw(this.GetPosition(), snipertarget1.GetPosition());
						// Print("smer k targetu " + yaw);
						// SetOrientation(ori);
						if (Math.AbsFloat(yaw - ori[0]) > 5)
						{
							pInputController.OverrideTurnSpeed(true, 4);
							pInputController.OverrideHeading(true, yaw - ori[0]);
							//GetCommand_Move().StartTurn(yaw-ori[0],0);
						}
						else
						{
							pInputController.OverrideHeading(true, 0);
							pInputController.OverrideTurnSpeed(true, 0);
						}
						m_AIAgent.SetKeepInIdle(true);
					}
				}
			}

			return false;
		}

		/*
		if ( m_ActualTarget == NULL )
			return false;
		*/
		/*
		vector targetPos = m_ActualTarget.GetPosition();
		if ( !CanAttackToPosition(targetPos) )
			return false;

		float targetDist = vector.Distance(targetPos, this.GetPosition());
		int pitch = GetAttackPitch(m_ActualTarget);

		m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.CHASE, targetDist, pitch);
		Print("ACTUAL ATTACK TYPE " + m_ActualAttackType);
		*/
		// if ( m_ActualAttackType )
		//{
		Object target;
		target = DayZPlayerUtils.GetMeleeTarget(this.GetPosition(), this.GetDirection(), 45, 1.5, -1.0, 2.0, this, m_TargetableObjects, m_AllTargetObjects); // byl cone CHASE
		//! target is outside the targeting cone; skip attack
		/*
		if (m_ActualTarget != target)
		{
			m_AllTargetObjects.Clear();
			return false;
		}
		*/
		
		//Print("target " + target + " actual " + m_ActualTarget);

		if (target )
		{
			// PlayerBase plb = PlayerBase.Cast(target);
			// if ( GetGroup().GetFaction() == "Bandits" || (GetGroup().GetFaction() == "Guards"  && plb && plb.IsRaised() ) || (GetGroup().GetFaction() == "Guards"  && !plb) )
			//{
			
			InfectedBanditBase meleebandit = InfectedBanditBase.Cast(target);
			if (!IsSniper() && meleebandit && !meleebandit.IsSniper() && meleebandit.GetGroup().GetFaction() == this.GetGroup().GetFaction())
			{ 
				return false;
			}
			m_ActualTarget = EntityAI.Cast(target);
			
#ifdef DAYZ_DOG
			Dayz_Doggo dog = Dayz_Doggo.Cast(m_ActualTarget);
			if (dog)
			{
				return false;
			}
#endif
			
			#ifdef VPPADMINTOOLS
			PlayerBase hrac = PlayerBase.Cast(m_ActualTarget);
			if (hrac && hrac.InvisibilityStatus())
			{
				return false;
			}
			#endif
			#ifdef JM_COT
			PlayerBase hrac1 = PlayerBase.Cast(m_ActualTarget);
			if (hrac1 && hrac1.COTGetCannotBeTargetedByAI())
			{
				return false;
			}
			#endif
	
			StartCommand_Attack(m_ActualTarget, 1, 0);
			m_AttackCooldownTime = 0;
			return true;
			//}
		}
		//}

		if (IsSniper())
		{
			// ref array<ref TriggerInsider> targets = GetTrigger().GetInsiders();

			// Print ("sniper 2 " );
			if (GetSniperTarget())
			{
				EntityAI snipertarget = GetSniperTarget();
				PlayerBase snipedplayer = PlayerBase.Cast(snipertarget);
				// Print ("sniper 3 " + snipedplayer);
				// GetGame().ChatPlayer("sniper pred vystrelem " );
				// GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams(CCDirect, "", "sniper 3", ""));
				if ((GetAnimInstance() == IBAnimInstance.RIFLE || GetAnimInstance() == IBAnimInstance.PISTOL) && snipertarget && snipertarget.IsAlive() && snipedplayer && (!IsViewOccluded(snipedplayer.GetBonePositionWS(snipedplayer.GetBoneIndexByName("Head"))) || !IsViewOccluded(snipedplayer.GetBonePositionWS(snipedplayer.GetBoneIndexByName("Pelvis")))))
				// Print ("Sniper target " + snipertarget);
				{
					m_ActualTarget = EntityAI.Cast(snipertarget);
					#ifdef VPPADMINTOOLS
					if (snipedplayer && snipedplayer.InvisibilityStatus())
					{
						return false;
					}
					#endif
					#ifdef JM_COT
					if (snipedplayer && snipedplayer.COTGetCannotBeTargetedByAI())
					{
						return false;
					}
					#endif
					
					// Print("sniper 4 ");
					// jeste orotovat
					// Print ("orientace pri vystrelu " + GetOrientation());

					Raise();
					SetAimY(ComputeAimY(GetBonePositionWS(GetBoneIndexByName("Head")), snipedplayer.GetBonePositionWS(snipedplayer.GetBoneIndexByName("Head")))); // player
					StartCommand_Attack(m_ActualTarget, 16, 0);
					m_AttackCooldownTime = 4;

					return true;
				}
				else
				{
					// pInputController.OverrideHeading(false, 0);
					// m_AIAgent.SetKeepInIdle(false);
					SetRaised(false);
				}
			}

			pInputController.OverrideHeading(false, 0);
			pInputController.OverrideTurnSpeed(false, 20);
			m_AIAgent.SetKeepInIdle(false);
		}

		target = DayZPlayerUtils.GetMeleeTarget(this.GetPosition(), this.GetDirection(), 45, 100, -100.0, 100.0, this, m_TargetableObjects, m_AllTargetObjects);

		//! target is outside the targeting cone; skip attack
		/*
		if (m_ActualTarget != target)
		{
			m_AllTargetObjects.Clear();
			return false;
		}
		*/
		/*
		array<EntityAI> kokoti = new array<EntityAI>();
		GetEntitesInTriangle(m_TargetableObjects,kokoti);
		*/
		// SetAnimInstance(IBAnimInstance.KNIFE);
		CarScript car = CarScript.Cast(target);
		PlayerBase player = PlayerBase.Cast(target);
		_targetCreature = DayZCreature.Cast(target);
		
		vector carpos;
		if (car)
		{
			carpos = car.GetPosition();
			carpos[1] = carpos[1] + 0.8;
		}
		
		#ifdef VPPADMINTOOLS
		if (player && player.InvisibilityStatus())
		{
			return false;
		}
		#endif
		
		#ifdef JM_COT
		if (player && player.COTGetCannotBeTargetedByAI())
		{
			return false;
		}
		#endif
		// If guards were aggroed by a raised player, drop the target once the player lowers the weapon
		
		if (player && GetGroup() && GetGroup().GetFaction() == "Guards" && !IsSniper() && !player.IsRaised())
		{
			ClearTarget();
			SetRaised(false);
			return false;
		}

		if ((GetAnimInstance() == IBAnimInstance.RIFLE || GetAnimInstance() == IBAnimInstance.PISTOL) && target && player && (GetGroup().GetFaction() == "Bandits" || (GetGroup().GetFaction() == "Guards" && player.IsRaised()) || IsSniper()) && vector.DistanceSq(target.GetPosition(), this.GetPosition()) > 2 * 2 && (!IsViewOccluded(player.GetBonePositionWS(player.GetBoneIndexByName("Head"))) || !IsViewOccluded(player.GetBonePositionWS(player.GetBoneIndexByName("Pelvis")))))
		{
			float randomthrow = Math.RandomFloatInclusive(0.0, 1.0);
			if (randomthrow < GetGrenadeChance() && vector.Distance(target.GetPosition(), this.GetPosition()) > 30 && vector.Distance(target.GetPosition(), this.GetPosition()) <= 40)
			{
				SetRaised(false);
				GetGame().RPCSingleParam(this, 8832135811, null, true);
				StartCommand_Attack(m_ActualTarget, 18, 0);
				m_AttackCooldownTime = 2;
				pInputController.OverrideMovementSpeed(true, 0);
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ThrowGrenade, 700, false);
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(AfterThrow, 900, false, pInputController);
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(AfterThrowLater, 6500, false, GetStance());
				return true;
			}
			else
			{
				m_ActualTarget = EntityAI.Cast(target);
				Raise();
				SetAimY(ComputeAimY(GetBonePositionWS(GetBoneIndexByName("Head")), player.GetBonePositionWS(player.GetBoneIndexByName("Head"))));
				StartCommand_Attack(m_ActualTarget, 16, 0);
				m_AttackCooldownTime = 2;
				return true;
			}
		}
		else if ((GetAnimInstance() == IBAnimInstance.RIFLE || GetAnimInstance() == IBAnimInstance.PISTOL) && target && _targetCreature && vector.DistanceSq(target.GetPosition(), this.GetPosition()) > 2 * 2 && (!IsViewOccluded(_targetCreature.GetBonePositionWS(_targetCreature.GetBoneIndexByName("Head"))) || !IsViewOccluded(_targetCreature.GetBonePositionWS(_targetCreature.GetBoneIndexByName("Pelvis")))))
		{
			AnimalBase animal = AnimalBase.Cast(_targetCreature);
			ZombieBase zombie = ZombieBase.Cast(_targetCreature);
			InfectedBanditBase bandit = InfectedBanditBase.Cast(_targetCreature);
			if ( GetGroup().GetFaction() == "Guards" && ((zombie && zombie.IsDanger()) || (animal && animal.IsDanger())))
			{
				m_ActualTarget = _targetCreature;
				Raise();
				SetAimY(ComputeAimY(GetBonePositionWS(GetBoneIndexByName("Head")), _targetCreature.GetBonePositionWS(_targetCreature.GetBoneIndexByName("Head"))));
				StartCommand_Attack(m_ActualTarget, 16, 0);
				m_AttackCooldownTime = 2;
				return true;
			
			}
			else if (!IsSniper() && bandit && !bandit.IsSniper() && bandit.GetGroup().GetFaction() != this.GetGroup().GetFaction())
			{
				m_ActualTarget = _targetCreature;
				Raise();
				SetAimY(ComputeAimY(GetBonePositionWS(GetBoneIndexByName("Head")), _targetCreature.GetBonePositionWS(_targetCreature.GetBoneIndexByName("Head"))));
				StartCommand_Attack(m_ActualTarget, 16, 0);
				m_AttackCooldownTime = 2;
				return true;
			}

		}
		else if ((GetAnimInstance() == IBAnimInstance.RIFLE || GetAnimInstance() == IBAnimInstance.PISTOL) && target && car && car.CrewMember(0) && (GetGroup().GetFaction() == "Bandits" || IsSniper()) && vector.DistanceSq(target.GetPosition(), this.GetPosition()) > 2 * 2 && !IsViewOccludedFor(carpos, car))
		{
			m_ActualTarget = EntityAI.Cast(target);
			Raise();
			SetAimY(ComputeAimY(GetBonePositionWS(GetBoneIndexByName("Head")), carpos));
			StartCommand_Attack(m_ActualTarget, 16, 0);
			m_AttackCooldownTime = 0;
			return true;
		}
		/*
		else if ( (GetAnimInstance() == IBAnimInstance.KNIFE) && target && player && (GetGroup().GetFaction() == "Bandits" || (GetGroup().GetFaction() == "Guards" && player.IsRaised() ) || IsSniper() ) && vector.DistanceSq(target.GetPosition(), this.GetPosition()) > 2 * 2 && ( !IsViewOccluded(player.GetBonePositionWS(player.GetBoneIndexByName("Head"))) || !IsViewOccluded(player.GetBonePositionWS(player.GetBoneIndexByName("Pelvis"))) ) )
		{
			SetRaised(false);
			GetGame().RPCSingleParam(this, 8832135811, null, true);
			SetAnimInstance(IBAnimInstance.KNIFE);
			StartCommand_Attack(m_ActualTarget, 18, 0);
			m_AttackCooldownTime = 4;
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( ThrowGrenade, 900 , false);
		}
		*/
		else
		{
			SetRaised(false);
		}

		return false;
	}

	void ThrowGrenade()
	{
		// vector m4[4];
		// this.GetTransform(m4);

		vector position = GetBonePositionWS(GetBoneIndexByName("RightHand"));

		// vector rotation_matrix[3];
		// Math3D.YawPitchRollMatrix(this.GetOrientation(), rotation_matrix);
		// float direction[4];
		// Math3D.MatrixToQuat(rotation_matrix, direction);
		Object object = Object.Cast(GetGame().CreateObject("M67Grenade", position));
		object.CreateDynamicPhysics(PhxInteractionLayers.DYNAMICITEM);
		Grenade_Base grenade = Grenade_Base.Cast(object);

		vector dirthrow = GetDirection();
		// dirthrow [1] = 0.1;
		dirthrow.Normalize();
		float THROW_FORCE = 94.0;
		float UP_FORCE = 12.0;
		vector impulse = dirthrow * THROW_FORCE + vector.Up * UP_FORCE;
		dBodyApplyImpulse(object, impulse);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ArmWhenLandedTick, 100, false, grenade, 0);
		// grenade.ThrowPhysically(null, dirthrow*80, true);
		// MiscGameplayFunctions.ThrowEntityFromInventory( grenade, position, direction, "0 20 100", ThrowEntityFlags.NONE);
	}

	void AfterThrow(DayZInfectedInputController pInputController)
	{
		GetGame().RPCSingleParam(this, 8832135811, null, false);
		pInputController.OverrideMovementSpeed(false, 0);
		SetStance(2);
	}

	void AfterThrowLater(int stance)
	{
		SetStance(stance);
	}

	void ArmWhenLandedTick(Grenade_Base g, int waitedMs)
	{
		int FUSE_AFTER_LAND_MS = 2000;
		int ARM_CHECK_INTERVAL_MS = 100;
		int ARM_MAX_WAIT_MS = 3000; // max čekání na dopad
		float ARM_MIN_SPEED = 0.15; // práh "už leží" (m/s-ish)
		if (!g)
		{
			return;
		}

		// if waited too long, fallback: arm anyway (prevents "never explodes" cases)
		if (waitedMs >= ARM_MAX_WAIT_MS)
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(g.ForceActivateFuse, FUSE_AFTER_LAND_MS, false);
			return;
		}

		// speed check (approx "is resting")
		vector v = GetVelocity(g);
		float speed = v.Length();

		// heuristic: if it's slow, it's likely on ground (or stuck)
		if (speed <= ARM_MIN_SPEED)
		{

			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(g.ForceActivateFuse, FUSE_AFTER_LAND_MS, false);
			return;
		}

		// keep waiting
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.ArmWhenLandedTick, ARM_CHECK_INTERVAL_MS, false, g, waitedMs + ARM_CHECK_INTERVAL_MS);
	}

	bool FightAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		// always update target - it can be destroyed
		m_ActualTarget = pInputController.GetTargetEntity();
		if (!IsTargetValid(m_ActualTarget))
		{
			ClearTarget();
			return false;
		}

		//! do not attack players in vehicle - hotfix
		PlayerBase pb = PlayerBase.Cast(m_ActualTarget);
		if (pb && pb.GetCommand_Vehicle())
		{
			return false;
		}

		if (m_AttackCooldownTime > 0)
		{
			m_AttackCooldownTime -= pDt * GameConstants.AI_ATTACKSPEED;
			return false;
		}

		if (m_ActualTarget == NULL)
			return false;

		vector targetPos = m_ActualTarget.GetPosition();
		float targetDist = vector.Distance(targetPos, this.GetPosition());
		int pitch = GetAttackPitch(m_ActualTarget);

		if (!CanAttackToPosition(targetPos))
			return false;

		m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.FIGHT, targetDist, pitch);
		// Print("FIGHT ATTACK LOGIC");
		if (m_ActualAttackType)
		{
			Object target = DayZPlayerUtils.GetMeleeTarget(this.GetPosition(), this.GetDirection(), TARGET_CONE_ANGLE_FIGHT, m_ActualAttackType.m_Distance, -1.0, 2.0, this, m_TargetableObjects, m_AllTargetObjects);
			//! target is outside the targeting cone; skip attack
			if (m_ActualTarget != target)
			{
				m_AllTargetObjects.Clear();
				return false;
			}
#ifdef DAYZ_DOG
			Dayz_Doggo dog = Dayz_Doggo.Cast(m_ActualTarget);
			if (dog)
			{
				return false;
			}
#endif
			StartCommand_Attack(m_ActualTarget, m_ActualAttackType.m_Type, m_ActualAttackType.m_Subtype);
			m_AttackCooldownTime = m_ActualAttackType.m_Cooldown;
			return true;
		}

		return false;
	}

	int GetAttackPitch(EntityAI target)
	{
		vector attackRefPos;

		attackRefPos = target.GetDefaultHitPosition();
		//! no default hit pos fallback
		if (attackRefPos != vector.Zero)
		{
			attackRefPos = target.ModelToWorld(attackRefPos);
		}
		else
		{
			attackRefPos = target.GetPosition();
		}

		// Now we have only erect stance, we need to get head position later too
		float headPosY = GetPosition()[1];
		headPosY += 1.8;

		float diff = Math.AbsFloat(attackRefPos[1] - headPosY);

		if (diff < 0.3)
			return 0;

		if (headPosY > attackRefPos[1])
			return -1;
		else
			return 1;
	}

	//-------------------------------------------------------------
	//!
	//! Crawl transition
	//!

	int m_CrawlTransition = -1;

	bool HandleCrawlTransition(int pCurrentCommandID)
	{
		if (m_CrawlTransition != -1)
		{
			StartCommand_Crawl(m_CrawlTransition);

			m_CrawlTransition = -1;
			m_IsCrawling = true;
			SetSynchDirty();
			return true;
		}

		return pCurrentCommandID == DayZInfectedConstants.COMMANDID_CRAWL;
	}

	bool EvaluateCrawlTransitionAnimation(EntityAI pSource, string pComponent, string pAmmoType, out int pAnimType)
	{
		pAnimType = -1;
		if (pComponent == "LeftLeg" && GetHealth(pComponent, "Health") == 0)
			pAnimType = 0;
		else if (pComponent == "RightLeg" && GetHealth(pComponent, "Health") == 0)
			pAnimType = 2;

		if (pAnimType != -1)
		{
			vector targetDirection = GetDirection();
			vector toSourceDirection = (pSource.GetPosition() - GetPosition());

			targetDirection[1] = 0;
			toSourceDirection[1] = 0;

			targetDirection.Normalize();
			toSourceDirection.Normalize();

			float cosFi = vector.Dot(targetDirection, toSourceDirection);
			if (cosFi >= 0) // front
				pAnimType++;
		}

		return pAnimType != -1;
	}

	//-------------------------------------------------------------
	//!
	//! Damage hits
	//!

	bool m_DamageHitToProcess = false;
	bool m_DamageHitHeavy = false;
	int m_DamageHitType = 0;
	float m_ShockDamage = 0;

	bool HandleDamageHit(int pCurrentCommandID)
	{
		if (pCurrentCommandID == DayZInfectedConstants.COMMANDID_HIT)
		{
			m_DamageHitToProcess = false;
			m_ShockDamage = 0;
			return true;
		}

		if (m_DamageHitToProcess)
		{
			int randNum = Math.RandomIntInclusive(0, 100);
			float stunChange = SHOCK_TO_STUN_MULTIPLIER * m_ShockDamage;

			if (m_DamageHitHeavy || randNum <= stunChange || (m_MindState == DayZInfectedConstants.MINDSTATE_CALM || m_MindState == DayZInfectedConstants.MINDSTATE_DISTURBED))
				StartCommand_Hit(m_DamageHitHeavy, m_DamageHitType, m_DamageHitDirection);

			m_DamageHitToProcess = false;
			m_ShockDamage = 0;
			m_HeavyHitOverride = false;
			return true;
		}

		return false;
	}

	//! selects animation type and direction based on damage system data
	bool EvaluateDamageHitAnimation(EntityAI pSource, string pComponent, string pAmmoType, out bool pHeavyHit, out int pAnimType, out float pAnimHitDir)
	{
		int invertHitDir = 0; // Used to flip the heavy hit animation direction

		//! heavy hit
		pHeavyHit = ((GetGame().ConfigGetInt("cfgAmmo " + pAmmoType + " hitAnimation") > 0) || m_HeavyHitOverride);
		invertHitDir = GetGame().ConfigGetInt("cfgAmmo " + pAmmoType + " invertHitDir");

		//! anim type
		pAnimType = 0; // belly

		if (!pHeavyHit)
		{
			if (pComponent == "Torso") // body
				pAnimType = 1;
			else if (pComponent == "Head") // head
				pAnimType = 2;
		}

		//! direction
		// pAnimHitDir = ComputeHitDirectionAngle(pSource);
		pAnimHitDir = ComputeHitDirectionAngleEx(pSource, invertHitDir);
		//! shock GetDamage
		// m_ShockDamage = GetGame().ConfigGetFloat( "CfgAmmo " + pAmmoType + " DamageApplied " + "Shock " + "damage");
		return true;
	}

	float ComputeHitDirectionAngle(EntityAI pSource)
	{
		vector targetDirection = GetDirection();
		vector toSourceDirection = (pSource.GetPosition() - GetPosition());

		targetDirection[1] = 0;
		toSourceDirection[1] = 0;

		targetDirection.Normalize();
		toSourceDirection.Normalize();

		float cosFi = vector.Dot(targetDirection, toSourceDirection);
		vector cross = targetDirection * toSourceDirection;

		float dirAngle = Math.Acos(cosFi) * Math.RAD2DEG;
		if (cross[1] < 0)
			dirAngle = -dirAngle;

		return dirAngle;
	}

	float ComputeHitDirectionAngleEx(EntityAI pSource, int invertHitDir = 0)
	{
		vector targetDirection = GetDirection();
		vector toSourceDirection = (pSource.GetPosition() - GetPosition());

		targetDirection[1] = 0;
		toSourceDirection[1] = 0;

		targetDirection.Normalize();
		toSourceDirection.Normalize();

		float cosFi = vector.Dot(targetDirection, toSourceDirection);
		vector cross = targetDirection * toSourceDirection;

		float dirAngle = Math.Acos(cosFi) * Math.RAD2DEG;

		// We will invert direction of the hit
		if (invertHitDir > 0)
			dirAngle -= 180;

		if (cross[1] < 0)
			dirAngle = -dirAngle;

		return dirAngle;
	}

	//!
	//! Events from damage system
	//!

	// ** VANILLA OVERRIDE - ENGINE LEVEL FUNCTIONS - DAMAGE AND HITS ** //

	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if (this.GetPose() > 0)
		{
			return false;
		}

		return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}

	override bool CanBeTargetedByAI(EntityAI ai)
	{

		if (ai.IsAnimal())
		{
			return AI_CanBeTargetedByAnimal(AnimalBase.Cast(ai));
		}
		else if (ai.IsZombie())
		{
			return AI_CanBeTargetedByInfected(ZombieBase.Cast(ai));
		}
		
		else
		{
			InfectedBanditBase bandit = InfectedBanditBase.Cast(ai);
			if (bandit)
				return AI_CanBeTargetedByFaction(bandit);
		}
		
		return super.CanBeTargetedByAI(ai);
	}

	// ** TARGETING LOGIC - OVERRIDE HERE ** //

	protected bool AI_CanBeTargetedByAnimal(AnimalBase animal)
	{
		return false;
	}

	protected bool AI_CanBeTargetedByInfected(ZombieBase zombie)
	{
		if (this.GetGroup().GetFaction() == "Guards")
		{
			return true;
		}
		return false;
	}

	protected bool AI_CanBeTargetedByFaction(InfectedBanditBase ai)
	{
		if (ai.GetGroup().GetFaction() != this.GetGroup().GetFaction())
		{
			//is enemy of
			return true;
		}

		return false;
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		AI_EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}

	// ** CUSTOM LOGIC FOR EEHITBY - MAKE OVERRIDES ON THIS IF YOU WANT TO MODIFY ** //
	protected void AI_EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		m_TransportHitRegistered = false;

		if (!IsAlive())
		{
			dBodySetInteractionLayer(this, PhxInteractionLayers.RAGDOLL);
			InfectedBanditHitData data = new InfectedBanditHitData;
			data.m_Component = component;
			data.m_DamageZone = dmgZone;
			data.m_AmmoType = ammo;
			EvaluateDeathAnimationEx(source, data, m_DeathType, m_DamageHitDirection);
		}
		else
		{
			bool fromZombie = source && source.IsInherited(ZombieBase);
			bool fromAnimal = source && source.IsInherited(AnimalBase);
			if (fromZombie || fromAnimal)
			{
				float zoneDamage = damageResult.GetDamage(dmgZone, "Health");
				float healBack = zoneDamage * (1.0 - 0.5);
				if (healBack > 0.0)
					AddHealth("GlobalHealth", "Health", healBack);
			}

			int crawlTransitionType = -1;
			if (EvaluateCrawlTransitionAnimation(source, dmgZone, ammo, crawlTransitionType))
			{
				m_CrawlTransition = crawlTransitionType;
				return;
			}

			if (EvaluateDamageHitAnimation(source, dmgZone, ammo, m_DamageHitHeavy, m_DamageHitType, m_DamageHitDirection))
			{
				if (dmgZone)
					m_ShockDamage = damageResult.GetDamage(dmgZone, "Shock");
				m_DamageHitToProcess = true;
				return;
			}
		}
	}

	//! sound debug messages
	protected void DebugSound(string s)
	{
		// Print(s);
	}

	override protected void EOnContact(IEntity other, Contact extra)
	{
		if (!IsAlive())
			return;

		Transport transport = Transport.Cast(other);
		if (transport)
		{
			if (GetGame().IsServer())
			{
				RegisterTransportHit(transport);
			}
		}
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!IsAlive())
		{
			return false;
		}
		return super.CanReceiveAttachment(attachment, slotId);
	}

	override vector GetCenter()
	{
		return GetBonePositionWS(GetBoneIndexByName("spine3"));
	}

	bool IsCrawling()
	{
		return m_IsCrawling;
	}
	/*
	int DetermineFinisherDeathAnimation(int hit_type)
	{
		switch ( hit_type )
		{
			case MeleeConstants.CFG_FINISHER_LIVER:
				return DayZInfectedDeathAnims.ANIM_DEATH_BACKSTAB;
		}

		ErrorEx("Unknown finisher hit type, playing default death animation!",ErrorExSeverity.WARNING);
		return DayZInfectedDeathAnims.ANIM_DEATH_DEFAULT;
	}
	*/

	// ** FIREARM LOGIC ** //

	void HandleWeaponFireScriptEvent()
	{
		if (!IsTargetValid(m_ActualTarget))
		{
			ClearTarget();
			return;
		}

		if (m_ActualTarget && PlayerBase.Cast(m_ActualTarget))
		{
			_targetPlayer = PlayerBase.Cast(m_ActualTarget);
		}
		else if (m_ActualTarget && DayZCreature.Cast(m_ActualTarget))
		{
			_targetCreature = DayZCreature.Cast(m_ActualTarget);
		}
		else if (m_ActualTarget && CarScript.Cast(m_ActualTarget))
		{
			_targetCar = CarScript.Cast(m_ActualTarget);
		}

		string weaponType = "";
		string bulletType = "Bullet_9x19"; // fallback
		float bulletDamage = 1.0;
		// float baseBulletDamage = 0.3; // proměnná pro základní dmg z databáze

		Weapon_Base wpn = Weapon_Base.Cast(this.GetFirearm());
		if (wpn)
		{
			GetGame().RPCSingleParam(wpn, 8832135611, null, true);
		
			weaponType = wpn.GetType();
			bulletType = AIBAmmoTypeDatabase.GetBulletForWeapon(weaponType);
			// baseBulletDamage = AIBAmmoDamageDatabase.GetDamageForBullet(bulletType);
		}

		if (_targetPlayer)
		{
			// _targetPlayer.AddHealth("GlobalHealth", "Shock", -15);
			float randomhit = Math.RandomFloatInclusive(0.0, 1.0);
			if (IsSniper() && randomhit <= GetAccuracy())
			{
				_targetPlayer.ProcessDirectDamage(DT_FIRE_ARM, this, "Pelvis", bulletType, _targetPlayer.GetDamageZonePos("Zone_Pelvis"), 0.3);
			}
			else if (!IsSniper() && randomhit <= GetAccuracy())
			{
				float distcoef = 1 / vector.DistanceSq(_targetPlayer.GetPosition(), this.GetPosition());
				_targetPlayer.ProcessDirectDamage(DT_FIRE_ARM, this, "Pelvis", bulletType, _targetPlayer.GetDamageZonePos("Zone_Pelvis"), 0.2 + distcoef);
			}
			else
			{
				// poslat rpc pro prehrani zvuku kulky
				Param1<vector> bulletpos = new Param1<vector>(_targetPlayer.GetPosition());
				GetGame().RPCSingleParam(wpn, 8832135612, bulletpos, true);
			}
		}
		else if (_targetCreature)
		{
			// float randomhit1 = Math.RandomFloatInclusive(0.0, 1.0);
			// if (randomhit1 <= GetAccuracy())
			//{
			float distcoef1 = 1 / vector.DistanceSq(_targetCreature.GetPosition(), this.GetPosition());
			_targetCreature.ProcessDirectDamage(DT_FIRE_ARM, this, "Pelvis", bulletType, _targetCreature.GetDamageZonePos("Zone_Chest"), 1.0);
			//}
		}
		else if (_targetCar)
		{
			float distcoef3 = 1 / vector.DistanceSq(_targetCar.GetPosition(), this.GetPosition());
			// _targetCar.ProcessDirectDamage(DT_FIRE_ARM, this, "dmgZone_front", bulletType, _targetCar.GetDamageZonePos("dmgZone_front"), baseBulletDamage+distcoef3);
			// _targetCar.ProcessDirectDamage(DT_FIRE_ARM, this, "dmgZone_windowFront", bulletType, _targetCar.GetDamageZonePos("dmgZone_windowFront"), bulletDamage+distcoef3);
			// doplnit nahodny hit hrace
			//  to chce vylepsit

			TIntArray posadka = new TIntArray();

			for (int i = 0; i < _targetCar.CrewSize(); i++)
			{
				Human crew0 = _targetCar.CrewMember(i);
				if (!crew0)
					continue;
				else
					posadka.Insert(i);
			}

			int rndcrew = posadka.GetRandomElement();
			DynamicAIBConfig config = GetDayZGame().GetDynamicAIBConfig();
			if (config)
			{
				if (config.cardamage && posadka.Count() > 0)
				{
					// Print("car have inside " + posadka.Count());
					Human crew = _targetCar.CrewMember(rndcrew);
					if (crew)
					{
						// Print("car have driver");
						float randomhit1 = Math.RandomFloatInclusive(0.0, 1.0);
						// Print("car crew random hit" + randomhit1);
						if (randomhit1 <= (-0.15 + GetAccuracy()) && _targetCar.GetSpeedometerAbsolute() <= 50 )
						{
							crew.ProcessDirectDamage(DT_FIRE_ARM, this, "Pelvis", bulletType, crew.GetDamageZonePos("Zone_Pelvis"), 0.3);
						}
					}
				}
				if (config.cardamage)
				{
					if (_targetCar.HasRadiator())
					{
						_targetCar.GetRadiator().AddHealth("", "", -40);
					}

					int randomwheel = Math.RandomIntInclusive(0, -1 + _targetCar.WheelCount());
					CarWheel wheel = CarWheel.Cast(_targetCar.WheelGetEntity(randomwheel));
					wheel.AddHealth("", "", -30);
				}
			}
		}
	}

	// ** LIFETIME ** //

	// float _pathTimer = 0.0;
	// float _pathCheckInterval = 2.0;

	override protected void EOnSimulate(IEntity other, float dt)
	{

		// _pathTimer += dt;
		// if (_pathTimer >= _pathCheckInterval)
		// {
		// 	ValidatePath();
		// 	_pathTimer = 0.0;
		// }

		if (!_isAttacking)
		{
			return;
		}

		if (!IsTargetValid(m_ActualTarget))
		{
			ClearTarget();
			return;
		}

		_attackTimer += dt;
		if (_attackTimer >= _attackInterval)
		{
			HandleWeaponFireScriptEvent();
			_attackTimer = 0.0;
			_attackCount--;

			if (_attackCount <= 0)
			{
				_isAttacking = false;
			}
		}
	}

	// void ValidatePath()
	// {
	// 	if (_itAttacking)
	// 	{
	// 		return;
	// 	}

	// }
}
