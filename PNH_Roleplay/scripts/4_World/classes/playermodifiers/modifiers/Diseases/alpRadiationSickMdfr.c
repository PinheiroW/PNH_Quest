class alpRadiationSickMdfr: ModifierBase
{
	static const int WATER_DRAIN_FROM_VOMIT = 450;
	static const int ENERGY_DRAIN_FROM_VOMIT = 310;
	
	const ref array<string> BLEEDINGZONES = {"Head","Neck","Pelvis","Spine","LeftShoulder","LeftArm","LeftArmRoll","LeftForeArm","RightShoulder","RightArm","RightArmRoll","RightForeArm","LeftForeArmRoll","RightForeArmRoll","LeftLeg","LeftLegRoll","LeftUpLeg","LeftUpLegRoll","RightLeg","RightLegRoll","RightUpLeg","RightUpLegRoll","LeftFoot","LeftToeBase","RightFoot","RightToeBase"};

	override void Init()
	{
		m_ID 					= rModifiers.MDF_ALPRADIATIONSICK1; // Usamos o ID do 1 para compatibilidade
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 4; // [OTIMIZAÇÃO] Corre apenas a cada 4 segundos (antes era 1s)
	}

	override bool ActivateCondition(PlayerBase player)
	{
		// Ativa se o jogador tiver qualquer nível de radiação (L1 ou superior)
		return ( player.GetSingleAgentCount(alpeAgents.RADIATION) >= ALP_RADPOISON.L1 );
	}

	override void OnActivate(PlayerBase player)
	{
		player.IncreaseDiseaseCount();
	}

	override void OnDeactivate(PlayerBase player)
	{
		player.DecreaseDiseaseCount();
		player.GetRP().SetRadiationSickStage( ALP_RADIATION_SICKSTAGE.NONE );
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		// Desativa se a radiação cair abaixo do nível L1
		return ( player.GetSingleAgentCount(alpeAgents.RADIATION) < ALP_RADPOISON.L1 );
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		int agents = player.GetSingleAgentCount(alpeAgents.RADIATION);
		
		// 1. Morte Instantânea (L6)
		if ( agents >= ALP_RADPOISON.L6 )
		{
			player.SetHealth("","",0);
			return;
		}

		// 2. Definir Estágio Visual/Roleplay
		int stage = ALP_RADIATION_SICKSTAGE.NONE;
		if (agents >= ALP_RADPOISON.L5) 		stage = ALP_RADIATION_SICKSTAGE.L5;
		else if (agents >= ALP_RADPOISON.L4) 	stage = ALP_RADIATION_SICKSTAGE.L4;
		else if (agents >= ALP_RADPOISON.L3) 	stage = ALP_RADIATION_SICKSTAGE.L3;
		else if (agents >= ALP_RADPOISON.L2) 	stage = ALP_RADIATION_SICKSTAGE.L2;
		else if (agents >= ALP_RADPOISON.L1) 	stage = ALP_RADIATION_SICKSTAGE.L1;

		player.GetRP().SetRadiationSickStage(stage);

		// 3. Efeito de Sede (Comum a todos os estágios ativos)
		float metabolic_speed = PlayerConstants.METABOLIC_SPEED_WATER_SPRINT;
		player.GetStatWater().Add( (-metabolic_speed * deltaT) );

		// 4. Lógica de Probabilidades por Estágio
		float vomitChance = 1.0;
		float infectionChance = 1.0;
		float bleedChance = 1.0;
		float damageChance = 1.0;

		switch(stage)
		{
			case ALP_RADIATION_SICKSTAGE.L1:
				infectionChance = 0.98; // Raro
				break;
			case ALP_RADIATION_SICKSTAGE.L2:
				vomitChance = 0.995; infectionChance = 0.95;
				break;
			case ALP_RADIATION_SICKSTAGE.L3:
				vomitChance = 0.990; infectionChance = 0.85; bleedChance = 0.998;
				break;
			case ALP_RADIATION_SICKSTAGE.L4:
				vomitChance = 0.985; infectionChance = 0.75; bleedChance = 0.995; damageChance = 0.999;
				break;
			case ALP_RADIATION_SICKSTAGE.L5:
				vomitChance = 0.970; infectionChance = 0.65; bleedChance = 0.800; damageChance = 0.900;
				break;
		}

		float roll = Math.RandomFloat01();

		// Aplicar Infecção (Wound Agent)
		if (roll >= infectionChance)
			player.m_AgentPool.AddAgent(eAgents.WOUND_AGENT, 10);

		// Aplicar Vómito
		if (roll >= vomitChance)
		{
			SymptomBase symptom = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
			if (symptom)
			{
				symptom.SetDuration(5);
				player.GetStatWater().Add(-WATER_DRAIN_FROM_VOMIT);
				player.GetStatEnergy().Add(-ENERGY_DRAIN_FROM_VOMIT);
			}
		}

		// Aplicar Hemorragia (Cortes aleatórios)
		if (roll >= bleedChance && stage >= ALP_RADIATION_SICKSTAGE.L3)
		{
			string zone = BLEEDINGZONES.GetRandomElement();
			player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(zone);
		}

		// Aplicar Dano Direto (L4 e L5)
		if (roll >= damageChance && stage >= ALP_RADIATION_SICKSTAGE.L4)
		{
			player.AddHealth("", "", -1.5);
		}
	}
};