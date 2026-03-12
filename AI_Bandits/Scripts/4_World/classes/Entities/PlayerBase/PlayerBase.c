modded class PlayerBase
{

	static const autoptr TStringArray DAMAGE_ZONES = {"Torso", "LeftArm", "RightArm", "LeftLeg", "RightLeg", "LeftHand", "RightHand"};

	override bool CanBeTargetedByAI(EntityAI ai)
	{

		InfectedBanditBase bandit = InfectedBanditBase.Cast(ai);
		if (bandit && bandit.GetPose() > 0)
		{
			return false;
		}
		// seznam cilu pro skupinu
		if (bandit && bandit.GetGroup().GetFaction() == "Guards" && !IsRaised())
		{
			return false;
		}
		return super.CanBeTargetedByAI(ai);
	}

	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if (source && source.IsInherited(InfectedBanditBase))
		{
			if (AI_EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef))
			{
				return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
			}
			else
			{
				return false;
			}
		}
		return super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
	}

	bool AI_EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		InfectedBanditBase bandit = InfectedBanditBase.Cast(source);
		if (!bandit)
		{
			return true;
		}

		float health = damageResult.GetDamage(dmgZone, "Health");

		// baseBulletDamage = AIBAmmoDamageDatabase.GetDamageForBullet(bulletType);

		//Print("Initial Health Damage: " + health);
		float blood = damageResult.GetDamage(dmgZone, "Blood");
		//Print("Initial Blood Damage: " + blood);
		float shock = damageResult.GetDamage(dmgZone, "Shock");
		//Print("Initial Shock Damage: " + shock);

		float banditAccuracy = bandit.GetAccuracy(); // Zatim se berec vpotaz automaticky Torso/Pelvis
		if (banditAccuracy > 0.90)
		{
			float chance = Math.RandomFloat01();
			if (chance < 0.1)
			{
				dmgZone = "Head";
			}
			else
			{
				dmgZone = "Torso";
			}
		}
		else if (banditAccuracy < 0.75)					 // Pokud ma bandita nizkou presnost, vememe random koncetinu, stale nechavame Torso
		{
			dmgZone = DAMAGE_ZONES.GetRandomElement();
		}
		else
		{
			dmgZone = "Torso";
		}

		if (dmgZone == "Torso")
		{
			ItemBase vest = ItemBase.Cast(GetInventory().FindAttachment(InventorySlots.VEST));
			if (vest && !vest.IsRuined())
			{
				float vestHp = vest.GetHealth();
				//Print("Vest HP: " + vestHp);
				// GlobalArmor
				// Projectile
				// Health
				float armorPenetration = GetGame().ConfigGetFloat("CfgVehicles " + vest.GetType() + " DamageSystem GlobalArmor Projectile Health");
				//Print("Armor value: " + armorPenetration);

				// DMG je 50
				// Penetrace je 0.5 (50%)

				float damage = health; // 50DMG
				//Print("Damage before vest mitigation: " + damage);

				float damageToVest = damage; // 50DMG
				//Print("Damage to Vest: " + damageToVest);
				
				float damageToPlayer = damage * armorPenetration; // 50DMG * 0.5 = 25DMG - do hrace projde stale nejaky damage, ale jen pulka
				//Print("Damage to Player after vest mitigation: " + damageToPlayer);

				float vestHealthBefore = vest.GetHealth();
				float vestHealthAfter = vestHealthBefore - damageToVest;
				vest.ProcessDirectDamage(damageType, source, "Pelvis", ammo, modelPos, speedCoef, ProcessDirectDamageFlags.ALL_TRANSFER);

				if (vestHealthAfter <= 0)
				{
					damageToPlayer = Math.AbsFloat(vestHealthBefore - damageToVest); // Pokud se vesta znici, hrac dostane zbytek DMG
				}

				// Tady to muzeme pripadne jeste poladit, ale zatim bych to nechal at to projde s krvi i shockem z puvodniho damageResultu
				if (health > 0)
				{
					AddHealth("", "Health", -damageToPlayer);
				}
				if (blood > 0)
				{
					AddHealth("", "Blood", -blood);
				}
				if (shock > 0)
				{
					AddHealth("", "Shock", -shock);
				}

				EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
				return false;
			}
		}

		// Kdyz je vesta znicena, aplikujeme damage na nejaky dalsi slot
		EntityAI dmgZoneItem = GetGearByDmgZone(dmgZone);
		if (dmgZoneItem && !dmgZoneItem.IsRuined())
		{
			dmgZoneItem.ProcessDirectDamage(damageType, source, dmgZone, ammo, modelPos, speedCoef);
		}

		if (health > 0)
		{
			AddHealth("", "Health", -health);
		}
		if (blood > 0)
		{
			AddHealth("", "Blood", -blood);
		}
		if (shock > 0)
		{
			AddHealth("", "Shock", -shock);
		}

		EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);
		return false;
	}

	EntityAI GetGearByDmgZone(string dmgZone)
	{
		if (dmgZone == "Head")
		{
			return GetInventory().FindAttachment(InventorySlots.HEADGEAR);
		}
		else if (dmgZone == "Torso" || dmgZone == "LeftArm" || dmgZone == "RightArm")
		{
			if (dmgZone == "Torso")
			{
				EntityAI vest = GetInventory().FindAttachment(InventorySlots.VEST);
				if (vest)
				{
					return vest;
				}
			}

			return GetInventory().FindAttachment(InventorySlots.BODY);
		}
		else if (dmgZone == "LeftHand" || dmgZone == "RightHand")
		{
			return GetInventory().FindAttachment(InventorySlots.HANDS);
		}
		else if (dmgZone == "LeftLeg" || dmgZone == "RightLeg")
		{
			return GetInventory().FindAttachment(InventorySlots.LEGS);
		}
		else if (dmgZone == "LeftFoot" || dmgZone == "RightFoot")
		{
			return GetInventory().FindAttachment(InventorySlots.FEET);
		}

		return NULL;
	}
}