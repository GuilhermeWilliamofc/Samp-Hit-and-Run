// 1. Guardas de Inclusão (Evita dupla inclusão)
#if defined _tdm_team_included
    #endinput
#endif
#define _tdm_team_included

// 2. Definições de constantes locais do módulo
// ex: #define VALOR_XP_DIARIO 150

// Dados de Time
#define COLOR_POLICE 0x0000FFFF // Cor do Time Policial (Azul)
#define COLOR_THIEF 0xFF9900FF // Cor do Time Ladrao (Laranja)
#define TEAM_POLICE_ID 1 // Id do Time Policial
#define TEAM_THIEF_ID 2 // Id do Time Ladrao

// usa new para uma variável global não constante
new TextoTime[MAX_PLAYERS]; // Array para mostrar o texto de time apenas quando trocar de time
new GangZonePolicia; // A Área da Policia no Minimapa
new GangZoneLadroes; // A Área dos Ladroes no Minimapa

// Dados de Spawn
#define spawn_policia_x 1544.8274
#define spawn_policia_y -1675.6476
#define spawn_policia_z 13.5592
#define angulo_policia_z 91.7027

#define spawn_ladrao_x 1347.8749
#define spawn_ladrao_y -1753.2872
#define spawn_ladrao_z 13.3581
#define angulo_ladrao_z 359.7154

// 3. Variáveis Globais Limitadas a este módulo
// ex: static VariávelPrivada[MAX_PLAYERS];
// O uso de 'static' faz com que apenas este .inc consiga ver essa variável!

// 4. Funções Utilitárias (Sempre usando 'stock')
stock EntrarPolicia(playerid){
    SetPlayerColor(playerid, COLOR_POLICE); // Cor do Nome do Player + Radar
    SetPlayerTeam(playerid, TEAM_POLICE_ID); // Define o time 1 - Policia
    
    if (TextoTime[playerid] == 0){ // se eh a primeira vez q ve ou trocou de time
    	SendClientMessage(playerid, COLOR_POLICE, "Você agora faz parte da Policia!");
    	TextoTime[playerid]++;
    }
	return 1;
}

stock EntrarLadrao(playerid){
	SetPlayerColor(playerid, COLOR_THIEF); // Cor do Nome do Player + Radar
    SetPlayerTeam(playerid, TEAM_THIEF_ID); // Define o time 2 - Ladrao
    
    if (TextoTime[playerid] == 0){ // se eh a primeira vez q ve ou trocou de time
    	SendClientMessage(playerid, COLOR_THIEF, "Você agora faz parte dos Ladroes!");
    	TextoTime[playerid]++;
    }
	return 1;
}

stock SetarArmaPolicia(playerid){
	// Kit de Arma Policial
    GivePlayerWeapon(playerid, 3, 0); // Cacetete
    GivePlayerWeapon(playerid, 23, 9999); // Pistola Silenciada, munição "quase infinita"
    GivePlayerWeapon(playerid, 28, 9999); // Micro-Uzi
    GivePlayerWeapon(playerid, 31, 9999); // M4
    
    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, 100.0);
	return 1;
}

stock SetarArmaLadrao(playerid){
	// Kit de Arma Ladrao
    GivePlayerWeapon(playerid, 5, 0); // Taco de Beisebol
    GivePlayerWeapon(playerid, 22, 9999); // Pistola Comum, munição "quase infinita"
    GivePlayerWeapon(playerid, 32, 9999); // TEC9
    GivePlayerWeapon(playerid, 30, 9999); // AK-47

    SetPlayerHealth(playerid, 100.0);
    SetPlayerArmour(playerid, 100.0);
	return 1;
}

stock SkinsPolicia(){
    AddPlayerClassEx(TEAM_POLICE_ID, 280, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // LSPD
    AddPlayerClassEx(TEAM_POLICE_ID, 281, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // SFPD
    AddPlayerClassEx(TEAM_POLICE_ID, 282, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // LVPD
    AddPlayerClassEx(TEAM_POLICE_ID, 283, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // Sheriff
    AddPlayerClassEx(TEAM_POLICE_ID, 284, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // Policial de Moto
    
    AddPlayerClassEx(TEAM_POLICE_ID, 285, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // SWAT
    AddPlayerClassEx(TEAM_POLICE_ID, 286, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // FBI
    AddPlayerClassEx(TEAM_POLICE_ID, 287, spawn_policia_x, spawn_policia_y, spawn_policia_z, angulo_policia_z, 0, 0, 0, 0, 0, 0); // Militar Exercito
    return 1;
}

stock SkinsLadrao(){
	AddPlayerClassEx(TEAM_THIEF_ID, 21, spawn_ladrao_x, spawn_ladrao_y, spawn_ladrao_z, angulo_ladrao_z, 0, 0, 0, 0, 0, 0); // Gangster
    AddPlayerClassEx(TEAM_THIEF_ID, 28, spawn_ladrao_x, spawn_ladrao_y, spawn_ladrao_z, angulo_ladrao_z, 0, 0, 0, 0, 0, 0); // Traficante 1
    AddPlayerClassEx(TEAM_THIEF_ID, 29, spawn_ladrao_x, spawn_ladrao_y, spawn_ladrao_z, angulo_ladrao_z, 0, 0, 0, 0, 0, 0); // Traficante 2
    AddPlayerClassEx(TEAM_THIEF_ID, 30, spawn_ladrao_x, spawn_ladrao_y, spawn_ladrao_z, angulo_ladrao_z, 0, 0, 0, 0, 0, 0); // Traficante 3
    return 1;
}

stock VeiculosPolicia(){
    // Carros da Policia Estacionados Na Pershing Square (Delegacia de Los Santos)
    // Viatura 1 a 7 com Respawn de 5 minutos (300 segundos) e Sirene Ativada (1)
    AddStaticVehicleEx(427, 1532.9441, -1652.0148, 13.3828, 0.5218, 0, 1, 300, 1); // Blindado da S.W.A.T. / Polícia
    AddStaticVehicleEx(490, 1525.9507, -1628.8308, 13.3828, 359.1117, 0, 1, 300, 1); // SUV Preta do FBI
    AddStaticVehicleEx(596, 1525.6558, -1689.6870, 13.3828, 180.0401, 0, 1, 300, 1); // Viatura da Polícia de Los Santos
    AddStaticVehicleEx(597, 1532.8809, -1711.8108, 13.3828, 180.0401, 0, 1, 300, 1); // Viatura da Polícia de San Fierro
    AddStaticVehicleEx(598, 1555.2692, -1618.4733, 13.5469, 316.3180, 0, 1, 300, 1); // Viatura da Polícia de Las Venturas
    AddStaticVehicleEx(599, 1567.6611, -1619.4781, 13.5469, 316.3180, 0, 1, 300, 1); // Pick-up da Polícia Rural
    AddStaticVehicleEx(601, 1580.1508, -1619.6652, 13.3828, 316.5530, 0, 1, 300, 1); // Blindado de Água da S.W.A.T.
    return 1;
}

stock VeiculosLadrao(){
	// === SPAWNS DOS VEÍCULOS DOS LADRÕES ===
	// Sintaxe: AddStaticVehicleEx(id_modelo, X, Y, Z, Angulo, Cor1, Cor2, Tempo_Respawn_Segundos)
	// Usando cores escuras/esportivas e respawn de 5 minutos (300 segundos)

	AddStaticVehicleEx(426, 1345.1417, -1728.9789, 13.3828, 268.8172, 1, 1, 300, 0); // spawn_ladrao_carro1 -> Premier (Sedan balanceado)
	AddStaticVehicleEx(496, 1366.9381, -1735.4171, 13.3828, 268.8172, 3, 3, 300, 0); // spawn_ladrao_carro2 -> Blista Compact (Hatch ágil)
	AddStaticVehicleEx(405, 1382.0220, -1729.1337, 13.3828, 268.8172, 8, 8, 300, 0); // spawn_ladrao_carro3 -> Sentinel (Executivo firme)
	AddStaticVehicleEx(492, 1332.0204, -1735.3381, 13.3828, 90.4505,  0, 0, 300, 0); // spawn_ladrao_carro4 -> Greenwood (Carro clássico do Sweet)
	AddStaticVehicleEx(475, 1358.9590, -1749.9475, 13.3783, 178.5763, 4, 4, 300, 0); // spawn_ladrao_carro5 -> Sabre (Muscle bom de curva)
	AddStaticVehicleEx(445, 1339.9113, -1747.6237, 13.5419, 178.1063, 7, 7, 300, 0); // spawn_ladrao_carro6 -> Admiral (Sedan resistente)
	AddStaticVehicleEx(542, 1339.3726, -1763.9016, 13.5309, 178.1063, 12,1, 300, 0); // spawn_ladrao_carro7 -> Clover (Muscle clássico e desafiador)
	return 1;
}

stock CriarGangzones(){
    // GangZone da Polícia
    GangZonePolicia = GangZoneCreate(
        1431.0, -1725.5,
        1587.0, -1591.5
    );

    // GangZone dos Ladrões
    GangZoneLadroes = GangZoneCreate(
        1294.0, -1870.5,
        1394.0, -1722.5
    );
    
    return 1;
}

stock MostrarGangzones(){
    // GangZone da Polícia
    GangZoneShowForAll(
        GangZonePolicia,
        COLOR_POLICE
    );

    // GangZone dos Ladrões
    GangZoneShowForAll(
        GangZoneLadroes,
        COLOR_THIEF
    );

    return 1;
}

stock CriarNpcs(){
    // Npc's Policiais (Skins de Patrulha/Segurança: 280, 281, 282, 283)
    CreateActor(280, 1544.1525, -1631.9205, 13.3828, 89.7993);  // npc_pm1 (LSPD)
    CreateActor(281, 1580.6525, -1634.2545, 13.5620, 0.7336);   // npc_pm2 (SFPD)
    CreateActor(282, 1549.4182, -1669.8883, 13.5644, 92.6270);  // npc_pm3 (LVPD)
    CreateActor(283, 1548.7021, -1681.1852, 13.5580, 89.5720);  // npc_pm4 (Sheriff)

    // Npc's Ladrões (Skins: 21, 28, 29, 30)
    CreateActor(21, 1346.7854, -1758.8040, 13.5156, 359.4071);  // npc_ladrao1 (Gangster)
    CreateActor(28, 1357.1654, -1758.9390, 13.5078, 4.8122);    // npc_ladrao2 (Traficante 1)
    CreateActor(29, 1345.9795, -1719.4088, 13.5747, 271.3812);  // npc_ladrao3 (Traficante 2)

    return 1;
}
