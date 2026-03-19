// Script File
modded class ModifiersManager
{
	override void Init()
	{
		super.Init();
		
		// Gestores de Radiação Externa e Bloqueio
		AddModifier(new alpRadiationMdfr);
		AddModifier(new alpRadiationBlockMdfr);	
		
		// [OTIMIZAÇÃO] Modificador Unificado de Doença por Radiação
		// Este único ficheiro agora gere todos os estágios (1 a 5)
		// e corre apenas a cada 4 segundos para poupar CPU.
		AddModifier(new alpRadiationSickMdfr);
	}
}