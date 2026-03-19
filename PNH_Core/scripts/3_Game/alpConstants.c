const float ALP_CURRENTVERSION = 1.0;

class alpNDversion
{
    // Variável para salvar a versão atual das opções
    int Version = ALP_CURRENTVERSION; 
}

const int ALP_VALUE_NOTSET = -1;

//-------------------------------------------------------------------
// CONSTANTES PARA MENUS GUI
//-------------------------------------------------------------------
const int ALP_MENU_INFO_PAGES         = 500;
const int ALP_MENU_TRADER             = 501;
const int ALP_MENU_ATM                = 502;
const int ALP_MENU_INFO_PLAYER        = 503;
const int ALP_MENU_MANAGE_PLOTPOLE    = 504;
const int ALP_MENU_SPAWN_MANAGE       = 505;
const int ALP_MENU_EXAMINATION        = 506;
const int ALP_MENU_SPREADRUMOUR       = 507;
const int MENU_INSPECT_ALP            = 508;

//-------------------------------------------------------------------
// CORES ESTÁTICAS
//-------------------------------------------------------------------
static int COLOR_AVAILABLE_POSITIVE = COLOR_GREEN;
static int COLOR_UNAVAILABLE        = ARGB(255,168,168,168);
static int COLOR_AVAILABLE_NEGATIVE = COLOR_RED;

//-------------------------------------------------------------------
// ESTRUTURA DE PASTAS E ARQUIVOS
//-------------------------------------------------------------------
const string ALP_TRADEMARK              = "ALPEPINO: ";
const string ALP_ROOTFOLDER             = "$profile:Next-Days/";

const string ALP_LOGS                   = ALP_ROOTFOLDER + "logs/";
const string ALP_NOTF                   = "ND_0_notf.json";
const string ALP_NOTF_ROOT              = ALP_ROOTFOLDER + "Notification/";
const string ALP_NOTF_FOLDER            = ALP_NOTF_ROOT + "Messages";   
const string ALP_NOTF_SERVERMESSAGES    = ALP_NOTF_ROOT + "Messages/messages.json"; 

const string ALP_INFO_FOLDER            = ALP_NOTF_ROOT + "InfoSites/"; 
const string ALP_INFO_FILE              = ALP_INFO_FOLDER + "sites.json";   

const string ALP_RP_FOLDER              = ALP_ROOTFOLDER + "Players/";  
const string ALP_RP_FOLDER_ID           = ALP_RP_FOLDER + "PlayersID/"; 
const string ALP_RP_FOLDER_ID_JSON      = ALP_RP_FOLDER_ID + "PlayersID.json";  

const string ALP_RP_PLAYERS_FILE        = ALP_ROOTFOLDER + "ND_0_RP_players.json";  
const string ALP_RP_VEHICLES_FILE       = ALP_ROOTFOLDER + "ND_0_RP_vehicles.json"; 
const string ALP_RP_VEHICLES_SETTINGS_FILE = ALP_ROOTFOLDER + "ND_0_RP_vehicles_settings.json";

const string ALP_RESOURCES_FOLDER       = ALP_ROOTFOLDER + "Resources/";    
const string ALP_WELLS_FOLDER           = ALP_RESOURCES_FOLDER + "Wells/";  
const string ALP_FUELS_FOLDER           = ALP_RESOURCES_FOLDER + "Fuelstations/";   
const string ALP_RESOURCES_FILE         = ALP_ROOTFOLDER + "ND_0_Resources.json";   

const string ALP_MISSIONSYSTEM_FOLDER   = ALP_ROOTFOLDER + "MissionSystem/";    
const string ALP_MISSIONS_FOLDER        = ALP_MISSIONSYSTEM_FOLDER + "Missions/";   
const string ALP_MISSIONSYSTEM_FILE     = ALP_MISSIONSYSTEM_FOLDER + "MissionsList.json";   
const string ALP_MISSIONSYSTEM_LOOT     = ALP_MISSIONSYSTEM_FOLDER + "MissionsLootTable.json";  
const string ALP_MISSIONSYSTEM_VEHICLES = ALP_MISSIONSYSTEM_FOLDER + "Vehicles.json";
const string ALP_MISSIONSYSTEM_PROTECTION = ALP_MISSIONSYSTEM_FOLDER + "ProtectionBonuses.json";
const string ALP_MISSIONSYSTEM_QUESTS   = ALP_MISSIONSYSTEM_FOLDER + "NPCquests.json";  

const string ALP_MISSIONS_DEFAULT_FILE  = ALP_ROOTFOLDER + "ND_0_MS.json";
const string ALP_MISSIONS_RADIATION_FILE = ALP_ROOTFOLDER + "ND_0_MS_contamined.json";
const string ALP_MISSIONS_TRADER_FILE   = ALP_ROOTFOLDER + "ND_0_MS_trader.json";

const string ALP_MISSIONS_TRADER_FOLDER = ALP_ROOTFOLDER + "Trader/";   

const string ALP_MISSIONS_TRADER_ITEMS_DEFAULT          = ALP_MISSIONS_TRADER_FOLDER + "Items_NOTSYNC.json";    
const string ALP_MISSIONS_TRADER_CATEGORIES_DEFAULT     = ALP_MISSIONS_TRADER_FOLDER + "Categories_NOTSYNC.json";   

const string ALP_MISSIONS_TRADER_ITEMS_OVERRIDE         = ALP_MISSIONS_TRADER_FOLDER + "Items.json";    
const string ALP_MISSIONS_TRADER_CATEGORIES_OVERRIDE    = ALP_MISSIONS_TRADER_FOLDER + "Categories.json";   

const string ALP_MISSIONS_BANK_FOLDER   = ALP_RP_FOLDER + "BankAccounts/";  
const string ALP_MISSIONS_BANK_P_BALANCE = ALP_MISSIONS_BANK_FOLDER + "PlayersBalance.json"; 
const string ALP_MISSIONS_BANK_BALANCE  = ALP_MISSIONS_BANK_FOLDER + "BankBalance.json";    

//-------------------------------------------------------------------
// CONSTANTES DO SISTEMA DE MISSÕES
//-------------------------------------------------------------------
const int ALP_LIFETIMEMAX = 3600 * 24 * 40; // Tempo máximo de vida de objetos
const int ALP_TIMEOUT     = 3000;           // Timeout para gerenciamento de insiders

enum ALP_MISSIONTYPEID
{
    radiation = 1,
    radiationMission,
    noradiation,
    noradiationMission,
    carAccident,
    trader,
    fuelstation,
    savesurvivors,
    savemerchants,  
    conquerdefend,
}

//-------------------------------------------------------------------
// RADIAÇÃO E LÍQUIDOS
//-------------------------------------------------------------------
enum ALP_RADPOISON
{
    L0 = 200,
    L1 = 500,
    L2 = 1000,
    L3 = 3000,
    L4 = 6000, // Requer transfusão
    L5 = 10000, // Incurável
    L6 = 50000  // Morte instantânea
}

enum ALP_RADIATION_SICKSTAGE
{
    NONE, L1, L2, L3, L4, L5, COUNT
}

const int LIQUID_RADIOACTIVEWATER = 268435456;