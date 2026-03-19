#define ND_MISSIONS

// --- CONSTANTES GLOBAIS PNH (LOAD ORDER #0) ---
const float ALP_CURRENTVERSION = 1.0;
const int ALP_VALUE_NOTSET = -1;

// Pastas de Dados globais
const string ALP_ROOTFOLDER = "$profile:Next-Days/";
const string ALP_RP_FOLDER = ALP_ROOTFOLDER + "Players/";
const string ALP_CLANS_FOLDER = ALP_RP_FOLDER + "Clans/";
const string ALP_MISSIONS_BANK_FOLDER = ALP_RP_FOLDER + "BankAccounts/";

// Ficheiros de Configuração
const string ALP_CLANS_OPTIONS_FILE     = ALP_ROOTFOLDER + "ND_2_Clans.json";   
const string ALP_CLANS_BASES_FILE       = ALP_ROOTFOLDER + "ND_2_Bases.json";
const string ALP_CLANS_LOCKING_FILE     = ALP_ROOTFOLDER + "ND_2_Locking.json";
const string ALP_CLANS_SPAWN_FILE       = ALP_ROOTFOLDER + "ND_2_Spawn.json";

// IDs de Menus GUI (Exclusivos)
const int ALP_MENU_TRADER = 501;
const int ALP_MENU_ATM = 502;
const int ALP_MENU_INFO_PLAYER = 503;
const int ALP_MENU_MANAGE_PLOTPOLE = 504;
const int ALP_MENU_SPAWN_MANAGE = 505;

// ATENÇÃO: NÃO coloque aqui enums como alpMISSION_SETTING, ALP_MISSIONTYPEID ou alpRADIO.
// Eles já existem nativamente nos mods PNH_Missions e PNH_Roleplay!