#define ND_MISSIONS

// --- CONSTANTES GLOBAIS PNH (LOAD ORDER #0) ---
const float ALP_CURRENTVERSION = 1.0;
const int ALP_VALUE_NOTSET = -1;

// Pastas de Dados
const string ALP_ROOTFOLDER = "$profile:Next-Days/";
const string ALP_RP_FOLDER = ALP_ROOTFOLDER + "Players/";
const string ALP_CLANS_FOLDER = ALP_RP_FOLDER + "Clans/";
const string ALP_MISSIONS_BANK_FOLDER = ALP_RP_FOLDER + "BankAccounts/";

// Ficheiros de Configuração
const string ALP_CLANS_OPTIONS_FILE     = ALP_ROOTFOLDER + "ND_2_Clans.json";   
const string ALP_CLANS_BASES_FILE       = ALP_ROOTFOLDER + "ND_2_Bases.json";
const string ALP_CLANS_LOCKING_FILE     = ALP_ROOTFOLDER + "ND_2_Locking.json";
const string ALP_CLANS_SPAWN_FILE       = ALP_ROOTFOLDER + "ND_2_Spawn.json";

// IDs de Menus GUI
const int ALP_MENU_TRADER = 501;
const int ALP_MENU_ATM = 502;
const int ALP_MENU_INFO_PLAYER = 503;
const int ALP_MENU_MANAGE_PLOTPOLE = 504;
const int ALP_MENU_SPAWN_MANAGE = 505;

// --- DEFINIÇÕES DE MISSÕES E MAPA ---
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

enum alpMISSION_SETTING
{
    NONE = 0,
    RADIATION_ACTIVE = 1,
    MISSION_STATUS = 2,
    MISSION_IDLE = 4,
    MISSION_UNSECURED = 8,
    MISSION_CLEARED = 16,
    MISSION_OCCUPIED = 32,
    MISSION_HOSTILE_OCCUPIED = 64,
    MISSION_SECURED = 128,
    MISSION_EXPIRED = 256,
    MISSION_FAILED = 512
}

// --- DEFINIÇÕES DE HARDWARE / RÁDIO ---
enum alpRADIO
{
    NONE = 0,
    ALLOWED_BY_CONFIG_PERSONAL = 1,
    ALLOWED_BY_CONFIG_FIELD = 2,
    HAS_WALKIE_TALKIE = 4 ,
    HAS_BASE_RADIO = 8,
    HAS_GPS = 16,
    HAS_COMPASS = 32,   
}

// --- DEFINIÇÕES DE RADIAÇÃO ---
enum ALP_RADPOISON
{
    L0 = 200, L1 = 500, L2 = 1000, L3 = 3000, L4 = 6000, L5 = 10000, L6 = 50000
}

enum ALP_RADIATION_SICKSTAGE
{
    NONE, L1, L2, L3, L4, L5, COUNT
}