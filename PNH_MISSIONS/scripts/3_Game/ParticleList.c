modded class ParticleList
{
	
  static const int ALP_SPAD        = RegisterParticle( "PNH_Missions/data/spad/", "spad" );
  static const int ALP_SPAD_BIG    = RegisterParticle( "PNH_Missions/data/spad/", "spad_big" );
  static const int ALP_SPAD_FAST   = RegisterParticle( "PNH_Missions/data/spad/", "spad_fast" );
  static const int ALP_SPARKS        = RegisterParticle( "PNH_Missions/data/sparks/", "alp_sparks" );
};

class alp_DynamiteExplosion : EffectParticle
{
	void alp_DynamiteExplosion()
	{
		SetParticleID(ParticleList.EXPLOSION_LANDMINE);
	}
}
