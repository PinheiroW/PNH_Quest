modded class VPPMapMenu extends UIScriptedMenu 
{

#ifdef ND_MISSIONS
	
	//int										alp_TimeOffset = 0;
	override void Update(float timeslice) 
	 {
        super.Update(timeslice);
		
	
	 }
	
	
    override void DisplayServerMarkers() {

		super.DisplayServerMarkers();

		if (m_MapWidget)
		{	
			alpMAPMARKERS.ShowALLMissionsALP(m_MapWidget);	
			alpMAPMARKERS.ShowALLRestictedAreasALP(m_MapWidget);
			alpMAPMARKERS.ShowClanMemebersOnMapALP(m_MapWidget);			
		}


		//m_Adapter.UpdateContent();
    }	

#else

	override void Update(float timeslice) 
	 {
        super.Update(timeslice);
		
	
	 }
	
	
    override void DisplayServerMarkers() {

		super.DisplayServerMarkers();

		if (m_MapWidget)
		{	
			MapMenu.ShowALLMissionsALP(m_MapWidget);	
			MapMenu.ShowALLRestictedAreasALP(m_MapWidget);
			MapMenu.ShowClanMemebersOnMapALP(m_MapWidget);			
		}


		//m_Adapter.UpdateContent();
    }
	
	
#endif	
}