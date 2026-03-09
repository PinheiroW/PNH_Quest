modded class OffroadHatchback
{
	const string SMM_MISSION_VEHICLE = "$profile:\\SurvivorMissions\\Cleanup\\MissionVehicle.txt";
	
	override void AfterStoreLoad()
	{
		int b1, b2, b3, b4, b11, b12, b13, b14;
		string strVehID;
		string VehiclePersistentID[4];
		FileHandle MsaveVehicle = OpenFile( SMM_MISSION_VEHICLE, FileMode.READ );
		if ( MsaveVehicle )
		{
			FGets( MsaveVehicle, strVehID );
			CloseFile( MsaveVehicle );
			
			strVehID.ParseString( VehiclePersistentID );
			b1 = VehiclePersistentID[0].ToInt();
			b2 = VehiclePersistentID[1].ToInt();
			b3 = VehiclePersistentID[2].ToInt();
			b4 = VehiclePersistentID[3].ToInt();
			
			this.GetPersistentID( b11, b12, b13, b14 );
			
			if ( b1 == b11 && b2 == b12 && b3 == b13 && b4 == b14 )
			{
				Print("[SMM] OnStartCleanup : Mission vehicle is present and gets deleted.");
				GetGame().ObjectDelete( GetGame().GetEntityByPersitentID( b1, b2, b3, b4 ));
				DeleteFile( SMM_MISSION_VEHICLE ); 
			}						
		}
	}
} 