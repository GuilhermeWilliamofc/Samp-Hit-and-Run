// 1. Guardas de Inclusão (Evita dupla inclusão)
#if defined _tdm_commands_included
    #endinput
#endif
#define _tdm_commands_included

#include <tdm_team>
#include <tdm_colors>

// 2. Definições de constantes locais do módulo
// ex: #define VALOR_XP_DIARIO 150
new PlayerVehicle[MAX_PLAYERS];

// 3. Variáveis Globais Limitadas a este módulo
// ex: static VariávelPrivada[MAX_PLAYERS];
// O uso de 'static' faz com que apenas este .inc consiga ver essa variável!

// 4. Funções Utilitárias (Sempre usando 'stock')
/*stock DarDinheiroBonus(playerid, quantidade)
{
    GivePlayerMoney(playerid, quantidade);
    SendClientMessage(playerid, -1, "Você recebeu um bônus do módulo!");
    return 1;
}*/

CMD:time(playerid, params[]){ // para mudar de time facilmente
    TextoTime[playerid] = 0; // para aparecer o texto do time quando escolher um time novo
    ForceClassSelection(playerid); // Isso apenas "marca" o jogador para ir para lá na próxima vez que ele morrer ou spawnar.
    // Dá problema de menu de seleção duplicado (abre 2 vezes, um ao dar /time e outro quando morre)
    // TogglePlayerSpectating(playerid, true); // Para resolver isso e mandá-lo para a seleção de skin na mesma hora
    // TogglePlayerSpectating(playerid, false);
    SetPlayerHealth(playerid, 0.0); // Mata o jogador imediatamente para aplicar o ForceClassSelection de forma limpa
    SendClientMessage(playerid, -1, "Você voltou para a seleção de skins.");
    return 1;
}

CMD:kill(playerid, params[]){ // Se M*tar
    SendClientMessage(playerid, COLOR_RED, "Se vc tá pedindo...");
    SetPlayerHealth(playerid, 0.0);
    return 1;
}

CMD:help(playerid, params[]){ // Lista de Comandos no Chat
    SendClientMessage(playerid, -1, "Lista de Comandos:");
    SendClientMessage(playerid, -1, "/time - Mudar de Time");
    SendClientMessage(playerid, -1, "/kill - Se Matar");
    SendClientMessage(playerid, -1, "/carro - Spawna um Carro Próximo a sua localização");
	return 1;
}

CMD:carro(playerid, params[])
{
    // Se já possui um carro, destrói o anterior
    if (PlayerVehicle[playerid] != INVALID_VEHICLE_ID)
    {
        DestroyVehicle(PlayerVehicle[playerid]);
        PlayerVehicle[playerid] = INVALID_VEHICLE_ID;
    }

    new Float:x, Float:y, Float:z, Float:a;

    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, a);

    new vehicleid;
    new modelo;

    if (GetPlayerTeam(playerid) == TEAM_POLICE_ID)
    {
        static const CarrosDisponiveisPM[] =
        {
            427, // Blindado da S.W.A.T.
            490, // SUV preta do FBI
            596, // Viatura de Los Santos
            597, // Viatura de San Fierro
            598, // Viatura de Las Venturas
            599, // Pick-up da Polícia Rural
            601  // Blindado de Água da S.W.A.T.
        };

        modelo = CarrosDisponiveisPM[random(sizeof(CarrosDisponiveisPM))];
    }
    else if (GetPlayerTeam(playerid) == TEAM_THIEF_ID)
    {
        static const CarrosDisponiveisLad[] =
        {
            426, // Premier
            496, // Blista Compact
            405, // Sentinel
            492, // Greenwood
            475, // Sabre
            445, // Admiral
            542  // Clover
        };

        modelo = CarrosDisponiveisLad[random(sizeof(CarrosDisponiveisLad))];
    }
    else
    {
        SendClientMessage(playerid, -1, "Você não pertence a nenhum time.");
        return 1;
    }

    vehicleid = CreateVehicle(
        modelo,
        x + 3.0,
        y,
        z,
        a,
        -1,
        -1,
        -1
    );

    if (vehicleid == INVALID_VEHICLE_ID)
    {
        SendClientMessage(playerid, -1, "Não foi possível criar o veículo.");
        return 1;
    }

    PlayerVehicle[playerid] = vehicleid;

    PutPlayerInVehicle(playerid, vehicleid, 0);

    return 1;
}
