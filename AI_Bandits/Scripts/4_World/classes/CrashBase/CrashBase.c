modded class CrashBase
{
	override void EEInit()
	{
		super.EEInit();
		//spawn group if allowed in server config
		if(GetGame().IsServer())
		{
			GetGame().GetCallQueue( CALL_CATEGORY_GAMEPLAY ).CallLater( SpawnBandits, 1000 , false);	
		}
	}
	void SpawnBandits()
	{
		DynamicAIBConfig config = GetDayZGame().GetDynamicAIBConfig();
		string headgear,masks,vests,backpacks,bodywear,pants,belts,shoes,gloves,armband,weapon,loot;
		TStringArray lootlist;
		int i,j,k,rndnum;
		i = Math.RandomIntInclusive(0,-1+config.GroupLocations.Count());
		if (config.crashsites && config.GroupLocations.Get(i).npcclasses)
		{
			AIBLogger.Log("Spawned CrashSite NPC Group " + config.GroupLocations.Get(i).name + " at " + this.ModelToWorld("15 0 -15") );
			BanditAIGroup group = new BanditAIGroup();
			group.SetName(config.GroupLocations.Get(i).name);
			group.SetFaction("Bandits");
			vector wp1 = this.ModelToWorld("20 0 20");
			vector wp2 = this.ModelToWorld("-20 0 20");
			vector wp3 = this.ModelToWorld("-20 0 -20");
			vector wp4 = this.ModelToWorld("20 0 -20");
			
			wp1[1] = GetGame().SurfaceY(wp1[0], wp1[2]);
			wp2[1] = GetGame().SurfaceY(wp2[0], wp2[2]);
			wp3[1] = GetGame().SurfaceY(wp3[0], wp3[2]);
			wp4[1] = GetGame().SurfaceY(wp4[0], wp4[2]);
			
			TStringArray waypoints = {this.GetPosition().ToString()}; //, wp2.ToString(), wp3.ToString(), wp4.ToString()};
			//group.SetWaypoints(waypoints);
			AIBLogger.Debug("CrashSite waypoints " + waypoints);
			group.SetFormation(new BanditAIFormationVee());
			
			for (j=0; j < config.GroupLocations.Get(i).npcclasses.Count(); j++)
			{
				vector offset = group.GetFormation().LocalFormPos(j);
				vector grplocation = this.ModelToWorld("15 0 -15");
				vector posi = grplocation + offset;
				posi[1] = GetGame().SurfaceY(posi[0], posi[2]);
				
				InfectedBanditBase bandit = InfectedBanditBase.Cast(GetGame().CreateObject(config.GroupLocations.Get(i).npcclasses.Get(j), posi , false, true));
				//Print("NUMBER " + j + " " + config.GroupLocations.Get(i).npcclasses.Get(j));
				if (bandit)
				{
					//Print("NUMBER INSIDE" + j);
					//loadout
					headgear = config.GroupLocations.Get(i).npcproperties.headgear.GetRandomElement();
					masks = config.GroupLocations.Get(i).npcproperties.masks.GetRandomElement();
					vests = config.GroupLocations.Get(i).npcproperties.vests.GetRandomElement();
					backpacks = config.GroupLocations.Get(i).npcproperties.backpacks.GetRandomElement();
					bodywear = config.GroupLocations.Get(i).npcproperties.bodywear.GetRandomElement();
					belts = config.GroupLocations.Get(i).npcproperties.belts.GetRandomElement();
					pants = config.GroupLocations.Get(i).npcproperties.pants.GetRandomElement();
					shoes = config.GroupLocations.Get(i).npcproperties.shoes.GetRandomElement();
					gloves = config.GroupLocations.Get(i).npcproperties.gloves.GetRandomElement();
					armband = config.GroupLocations.Get(i).npcproperties.armband.GetRandomElement();
					weapon = config.GroupLocations.Get(i).weaponpool.GetRandomElement();
					
					if (weapon.Contains("Predefined_"))
					{
						for ( k = 0; k < config.PredefinedWeapons.Count(); k++)
						{
							if (config.PredefinedWeapons.Get(k).name == weapon)
							{
								string wpclass = config.PredefinedWeapons.Get(k).weapon;
								TStringArray wpattach = config.PredefinedWeapons.Get(k).attachments;
								bandit.SetupWeapon(wpclass, wpattach);
							}
						}
					}
					else
					{
						bandit.SetupWeapon(weapon, null);
					}
					
					BanditAI_Base banditai = BanditAI_Base.Cast(bandit);
					TStringArray clothing = new TStringArray;
					if (banditai)
					{
						clothing = {headgear, masks, vests, backpacks, bodywear, belts, pants, shoes, gloves, armband};
						banditai.InitialSetup(clothing);
						lootlist = new TStringArray;
						rndnum = Math.RandomInt(0, 3);
						for (k = 0; k < rndnum; k++)
						{
							loot = config.GroupLocations.Get(i).npcproperties.loot.GetRandomElement();
							lootlist.Insert(loot);
							banditai.SetupLoot(lootlist);

						}
					}
					//bandit.SetStance(IBStance.CROUCH);
					bandit.SetAccuracy(Math.Clamp(config.GroupLocations.Get(i).accuracy,0,100));
					bandit.SetGrenadeChance(Math.Clamp(config.GroupLocations.Get(i).grenadechance,0,100));
					bandit.SetGroup(group);
					bandit.SetGroupID(j);
					if (j==0)
					{
						group.SetLeader(bandit);
					}
					else
					{
						group.AddMember(bandit);
					}
				}
			}
			
			//BanditGroups.Insert(group);
		}
	}

};