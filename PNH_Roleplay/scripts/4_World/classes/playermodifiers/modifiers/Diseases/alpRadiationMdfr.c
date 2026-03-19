class alpRadiationMdfr: ModifierBase
{
	int alp_WATER_DRAIN_CONST;
	int alp_RADIATION_CAP;
	float alp_ARMOR_RATIO;

	override void Init()
	{
		m_TrackActivatedTime = false;
		m_ID = rModifiers.MDF_ALPRADIATION;
		m_TickIntervalInactive = DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive = 2; // [OTIMIZAÇÃO] Corre a cada 2 segundos (menos peso no servidor)
		
		if ( GetND() && GetND().GetMS() && GetND().GetMS().GetOptionsRadiation() )
		{
			alp_WATER_DRAIN_CONST = GetND().GetMS().GetOptionsRadiation().WaterDrainInRadiationPerSec;
			alp_RADIATION_CAP = GetND().GetMS().GetOptionsRadiation().RadiationCapForCalc;
			alp_ARMOR_RATIO	= GetND().GetMS().GetOptionsRadiation().ArmorRatioNBCforWaterDrain;			
		}
	}
	
	override bool ActivateCondition(PlayerBase player)
	{
		return true;
	}

	override void OnActivate(PlayerBase player) {}
	override void OnReconnect(PlayerBase player) {}
	override void OnDeactivate(PlayerBase player) {}
	override bool DeactivateCondition(PlayerBase player) { return false; }

	override void OnTick(PlayerBase player, float deltaT)
	{
		if ( !GetND() || !GetND().GetMS() || !GetND().GetMS().GetOptionsRadiation() )
			return;

		// Lê a radiação local e a defesa do fato NBC
		float radH = player.GetRP().GetRadiation();
		float radiation = radH / 60 / 60;
		float shield = player.GetRP().GetProtection().GetTotalRadiationShield();

		// 1. Dreno de Água pelo suor (Calor do fato / Zona radioativa)
		if ( alp_WATER_DRAIN_CONST > 0 && radiation > 0 )
		{
			float waterDrain = ( radH / alp_RADIATION_CAP ) * alp_WATER_DRAIN_CONST;
			waterDrain = ( waterDrain - waterDrain * alp_ARMOR_RATIO * shield ) * deltaT;
			player.GetStatWater().Add( -waterDrain );
		}

		// 2. INJEÇÃO DE DOSE NO CORPO (Faz o jogador ficar doente)
		if ( radiation && shield < 1 )
		{
			float doses = ( radiation * ( 1 - shield ) * 1000 ) * deltaT;
			player.GetRP().SetRecievedRadiation( doses );
		}

		// 3. Desgaste de Itens e Contaminação
		if ( GetND().GetMS().GetOptionsRadiation().RadiationLimitDegradingAttachments || GetND().GetMS().GetOptionsRadiation().RadiationLimitToContamineItems )
		{
			float damage = radH - GetND().GetMS().GetOptionsRadiation().RadiationLimitDegradingAttachments;
			
			if ( damage > 0 )
			{
				damage = Math.Pow( damage, GetND().GetMS().GetOptionsRadiation().DamageToAttachmentsExponent );
				damage *= GetND().GetMS().GetOptionsRadiation().DamageToAttachmentsCoef * deltaT;
			}
			else
			{
				damage = 0;
			}

			ItemBase itm;
			for( int i = 0; i < player.GetInventory().AttachmentCount(); i++ )
			{
				itm = ItemBase.Cast( player.GetInventory().GetAttachmentFromIndex( i ) );		
				
				if ( itm )
				{
					float health = itm.GetHealth("","");
					
					// Degradar a vida do fato NBC / Máscara
					if ( GetND().GetMS().GetOptionsRadiation().RadiationLimitDegradingAttachments && health > 20 && radH > GetND().GetMS().GetOptionsRadiation().RadiationLimitDegradingAttachments )			
					{
						health -= damage;
						health = Math.Clamp( health, 20, health );
						itm.SetHealth("","", health );
					}
					
					// Contaminar o item para que seja necessário lavá-lo depois
					if ( GetND().GetMS().GetOptionsRadiation().RadiationLimitToContamineItems && radH > GetND().GetMS().GetOptionsRadiation().RadiationLimitToContamineItems && !( itm.GetAgents() & alpeAgents.RADIATION )  )
					{
						player.AddContaminedItem(itm.GetID());
						itm.InsertAgent(alpeAgents.RADIATION, 1);
						itm.SetSynchDirty();
					}
				}
			}
		}
	}
};