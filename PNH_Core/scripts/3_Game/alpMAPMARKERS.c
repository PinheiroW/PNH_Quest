// --- ENUMS DE CONTROLO DE MAPA E HARDWARE ---
enum alpRADIO
{
    NONE = 0,
    ALLOWED_BY_CONFIG_PERSONAL = 1,
    ALLOWED_BY_CONFIG_FIELD = 2,
    HAS_WALKIE_TALKIE = 4,
    HAS_BASE_RADIO = 8,
    HAS_GPS = 16,
    HAS_COMPASS = 32,   
}

// --- CLASSES DE MARCADORES ---
class alpQuestMarker
{
    float X;
    float Y;
    string Title;
    string MapTitle;
    int Count;

    void AddMarker(float x, float y, string maptitle, string title)
    {
        X = x;
        Y = y;
        MapTitle = maptitle;
        Title += Widget.TranslateString(GetDisplayName(title)) + ", ";
    }
    
    string GetTitle() 
    {
        return Widget.TranslateString("#trader_bring_me") + ": " + Title.Substring(0, Title.Length() - 2);
    }
    
    static string GetDisplayName(string className)
    {
        string name;
        TStringArray cfg = {"CfgVehicles", "CfgWeapons", "CfgMagazines", "CfgAmmo"};
        foreach(string p : cfg)
        {
            GetGame().ConfigGetText(p + " " + className + " displayName", name);
            if (name != "")
            {
                className = name;
                break;
            }
        }
        className.Replace("$UNT$", "");
        return className;
    }   
}

class alpMAPMARKERS 
{
    static int ALP_COLOR_MISSION = 0xFFFF8C00;
    static ref map<string, ref alpQuestMarker> m_QuestMarkers;
    
    static string GetMissionStatus(int mtype, int setting)
    {
        string status = "";
        
        if (setting & alpMISSION_SETTING.MISSION_STATUS)
        {
            string active = " (" + Widget.TranslateString("#alp_mactive") + ")";
            string nonactive = " (" + Widget.TranslateString("#alp_mnonactive") + ")";
            string unsecured = " (" + Widget.TranslateString("#alp_munsecured") + ")";
            string cleared = " (" + Widget.TranslateString("#alp_mcleared") + ")";
            string occupied = " (" + Widget.TranslateString("#alp_moccupied") + ")";
            string conquer = " (" + Widget.TranslateString("#alp_mconquer") + ")";
            string defend = " (" + Widget.TranslateString("#alp_mdefend") + ")";
            string secured = " (" + Widget.TranslateString("#alp_msecured") + ")";
            string expired = " (" + Widget.TranslateString("#alp_mexpired") + ")";
            string failed = " (" + Widget.TranslateString("#alp_mfailed") + ")";
            
            if (setting & alpMISSION_SETTING.MISSION_IDLE) {
                status = nonactive;     
            } else {
                status = active;    
            }   

            if (setting & alpMISSION_SETTING.MISSION_UNSECURED) status = unsecured;           
            if (setting & alpMISSION_SETTING.MISSION_CLEARED) status = cleared;           
            
            if (setting & alpMISSION_SETTING.MISSION_OCCUPIED || setting & alpMISSION_SETTING.MISSION_HOSTILE_OCCUPIED) 
            {
                status = occupied;      
                if (setting & alpMISSION_SETTING.MISSION_CLEARED && mtype == ALP_MISSIONTYPEID.conquerdefend) 
                {
                    if (setting & alpMISSION_SETTING.MISSION_HOSTILE_OCCUPIED) status = conquer;   
                    else status = defend;    
                }
            } 
            if (setting & alpMISSION_SETTING.MISSION_SECURED) status = secured;   
            if (setting & alpMISSION_SETTING.MISSION_EXPIRED) status = expired;   
            if (setting & alpMISSION_SETTING.MISSION_FAILED) status = failed;                               
        }       
        return status;
    }
    
    static void ShowALLMissionsALP(MapWidget m)
    {
        Man player = GetGame().GetPlayer();
        int level;
        if (player && player.GetIdentity())
        {
            level = player.GetIdentity().GetPlayerLevel();
        }
        
        int nav = alp_ND_base.HasWalkieTalkie();
        if (nav) 
        {
            if (nav & alpRADIO.ALLOWED_BY_CONFIG_PERSONAL || nav & alpRADIO.ALLOWED_BY_CONFIG_FIELD || nav & alpRADIO.HAS_WALKIE_TALKIE || nav & alpRADIO.HAS_BASE_RADIO) 
            {
                alp_ND_base.MarkMissionOnMap(); 
                alp_ND_base.UpdateMostWanted(); 
                alp_ND_base.UpdateNPCquests();          
            }
            
            if (alp_ND_base.alp_OptionsMS.ShowPlayersOnMap && nav & alpRADIO.HAS_GPS)
            {
                m.AddUserMark(player.GetPosition(), player.GetIdentity().GetName(), COLOR_BLUE, "ND_MISSIONS\\gui\\images\\PlayerIcon.paa");   
                
                if (alp_ND_base.alp_OptionsMS.SetMapPositionToPlayer)
                {
                    m.SetScale(0.1);                
                    m.SetMapPos(player.GetPosition()); 
                }
            }
        }

        if (!m_QuestMarkers) m_QuestMarkers = new map<string, ref alpQuestMarker>;
        m_QuestMarkers.Clear();
        
        array<ref alpRegisteredQuest> reg_quests = alp_ND_base.GetMarkedRegisteredQuests();
        if (reg_quests)
        {
            foreach (alpRegisteredQuest reg : reg_quests)
            {
                if (reg)
                {             
                    alpTraderQuest quest = alp_ND_base.GetQuest(reg.Quest);       
                    if (quest && level >= quest.RequiredLevel)
                    {
                        string posTxt = reg.PosX.ToString() + ":" + reg.PosY.ToString();
                        alpQuestMarker qm;
                        if (!m_QuestMarkers.Find(posTxt, qm))
                        {
                            qm = new alpQuestMarker();
                            m_QuestMarkers.Set(posTxt, qm);
                        }       
                        qm.AddMarker(reg.PosX, reg.PosY, quest.MapTitle, quest.WantedItem);                                                                
                    }               
                }
            }       
            for(int i = 0; i < m_QuestMarkers.Count(); i++)
            {
                alpQuestMarker qM = m_QuestMarkers.GetElement(i);
                if (qM) m.AddUserMark(Vector(qM.X, 0, qM.Y), qM.GetTitle(), COLOR_YELLOW, "ND_MISSIONS\\gui\\images\\smTrader.paa");
            } 
        }
        
        // --- MOSTRAR MOST WANTED ---
        array<ref alpMostWanted> mostWanted = alp_ND_base.GetMostWanted();
        if (mostWanted)
        {
            foreach (alpMostWanted wanted : mostWanted)
            {
                if (wanted) m.AddUserMark(wanted.GetRealPostition(), wanted.GetName(), COLOR_RED, wanted.GetIcon());   
            }       
        }
        
        // --- MOSTRAR MISSÕES ---
        array<ref alpMissionTemplateClient> markedMission = alp_ND_base.GetMarkedMission();
        if (markedMission)
        {
            foreach (alpMissionTemplateClient data : markedMission)
            {                                           
                if (!alp_ND_base.IsMissionKnown(data.id, data.missionStarted, data.requiredLevel)) continue;
                
                string inProgress = GetMissionStatus(data.type, data.setting);

                if ((data.showInMap && data.type == ALP_MISSIONTYPEID.radiation && data.setting & alpMISSION_SETTING.RADIATION_ACTIVE) || (data.showInMap && data.type == ALP_MISSIONTYPEID.radiationMission && data.setting & alpMISSION_SETTING.RADIATION_ACTIVE))
                {
                    m.AddUserMark(data.position, Widget.TranslateString(data.title) + inProgress, COLOR_RED, "ND_MISSIONS\\gui\\images\\smRadiation.paa");
                    if (alp_ND_base.alp_OptionsMS.ShowMissionRadius)
                    {
                        float ur = data.GetRadiusMultiplier() * data.missionRadius;
                        if (ur > 10) ShowResctrictedArea(m, data.position, ur, COLOR_RED, data.aspectRatioB, data.safeRadiusPointA, data.safeRadiusPointB);        
                    }
                }
    
                if (data.showInMap && (data.type == ALP_MISSIONTYPEID.trader || (data.type == ALP_MISSIONTYPEID.savemerchants && data.setting & alpMISSION_SETTING.MISSION_CLEARED)) && data.position != vector.Zero)
                {
                    m.AddUserMark(data.position, Widget.TranslateString(data.title) + inProgress, COLOR_GREEN, "ND_MISSIONS\\gui\\images\\smTrader.paa");                                     
                }   
                if (data.showInMap && data.type == ALP_MISSIONTYPEID.carAccident && data.position != vector.Zero)
                {
                    m.AddUserMark(data.position, Widget.TranslateString(data.title) + inProgress, ALP_COLOR_MISSION, "ND_MISSIONS\\gui\\images\\car.paa");                             
                }                                                           
                if (data.showInMap && (data.type == ALP_MISSIONTYPEID.fuelstation) && data.position != vector.Zero)
                {
                    m.AddUserMark(data.position, Widget.TranslateString(data.title) + inProgress, ALP_COLOR_MISSION, "ND_MISSIONS\\gui\\images\\fuel.paa");                              
                }       
            }   
        }
    }
    
    static void ShowClanMemebersOnMapALP(MapWidget m) {}
    static void ShowALLRestictedAreasALP(MapWidget m) {}

    static void ShowResctrictedArea(MapWidget m, vector position, float radius, int color, float ratioB = 0, vector pointA = "0 0 0", vector pointB = "0 0 0")
    {
        if (!ratioB)
        {
            float len = radius;
            int countPoints = len * 2 * Math.PI / 10;
            float angle = 360.0 / countPoints;
            for (int i = 0; i < countPoints; i++)
            {       
                float angle2 = i * angle;               
                vector pos = vector.Zero;               
                pos[0] = Math.NormalizeAngle(angle2);
                pos = pos.AnglesToVector(); 
                pos[0] = pos[0] * len;
                pos[2] = pos[2] * len;
                m.AddUserMark((position + pos), "", color, "ND_MISSIONS\\gui\\images\\Bod.paa");
            }           
        }
    }   
}