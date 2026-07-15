// This is a comment
// uncomment the line below if you want to write a filterscript
//#define FILTERSCRIPT

#include <a_samp>
#include <zcmd>     // processador de comandos (nota 09)
#include <sscanf2>  // conversão e validação de parâmetros de texto

// Minhas Bibliotecas
#include <tdm_team>
#include <tdm_commands>
#include <tdm_colors>

#if defined FILTERSCRIPT

public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" Blank Filterscript by your name here");
	print("--------------------------------------\n");
	return 1;
}

public OnFilterScriptExit()
{
	return 1;
}

#else

main()
{
	print("\n----------------------------------");
	print(" Hit and Run - Cops vs. Robbers ");
	print("----------------------------------\n");
}

#endif

public OnGameModeInit()
{
	// Don't use these lines if it's a filterscript
	SetGameModeText("Cops vs. Robbers");
	UsePlayerPedAnims(); // Usar Anim Padrao do Cj
	SkinsPolicia();
	SkinsLadrao();
	VeiculosPolicia();
	VeiculosLadrao();
	CriarGangzones();
	CriarNpcs();
	return 1;
}

public OnGameModeExit()
{
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	// Muda o Horário para Meia Noite (Apenas no Menu de Seleção)
	SetPlayerTime(playerid, 0, 0);

    // Posiciona o jogador no local do menu de seleção enviado por você
    SetPlayerPos(playerid, 1475.6199, -1686.7211, 14.0469);
    SetPlayerFacingAngle(playerid, 177.8250);

    // Posiciona a câmera um pouco à frente do jogador (olhando de frente para ele)
    SetPlayerCameraPos(playerid, 1475.6199, -1690.7211, 14.5000);

    // Faz a câmera focar exatamente no corpo/rosto do jogador
    SetPlayerCameraLookAt(playerid, 1475.6199, -1686.7211, 14.0469);

    return 1;
}

public OnPlayerConnect(playerid)
{
    // Muda o Horário para Meia Noite (Preparando para o menu de seleção)
    // O Horário reseta de qualquer forma quando spawna, é apenas para estética
	SetPlayerTime(playerid, 0, 0);

    SendClientMessage(playerid, COLOR_CYAN, "Hit and Run - Cops vs. Robbers - Bem-Vindo Ao Servidor!");
    SendClientMessage(playerid, COLOR_ORANGE, "Dê /help para ver a lista de comandos!");
    PlayerVehicle[playerid] = INVALID_VEHICLE_ID; // PlayerVehicle[playerid] precisa ter um valor que signifique “este jogador não possui nenhum veículo atualmente” (para /carro)
    TextoTime[playerid] = 0;
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
    TextoTime[playerid] = 0; // para quando alguem com msm ID ver a mensagem tbm
    if (PlayerVehicle[playerid] != INVALID_VEHICLE_ID) // para evitar carro abandonado (do /carro)
    {
        DestroyVehicle(PlayerVehicle[playerid]);
        PlayerVehicle[playerid] = INVALID_VEHICLE_ID;
    }
	return 1;
}

public OnPlayerSpawn(playerid)
{
    MostrarGangzones();

	if (GetPlayerTeam(playerid) == TEAM_POLICE_ID){ // Se for Time Policia
    	EntrarPolicia(playerid);
    	SetarArmaPolicia(playerid);
	}
	if (GetPlayerTeam(playerid) == TEAM_THIEF_ID){ // poderia usar else mas pra garantir
	    EntrarLadrao(playerid);
	    SetarArmaLadrao(playerid);
	}
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	return 1;
}

public OnPlayerText(playerid, text[])
{
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	if (strcmp("/mycommand", cmdtext, true, 10) == 0)
	{
		// Do something here
		return 1;
	}
	return 0;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
	return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveCheckpoint(playerid)
{
	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
	return 1;
}

public OnPlayerLeaveRaceCheckpoint(playerid)
{
	return 1;
}

public OnRconCommand(cmd[])
{
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
	return 1;
}

public OnObjectMoved(objectid)
{
	return 1;
}

public OnPlayerObjectMoved(playerid, objectid)
{
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	return 1;
}

public OnVehicleMod(playerid, vehicleid, componentid)
{
	return 1;
}

public OnVehiclePaintjob(playerid, vehicleid, paintjobid)
{
	return 1;
}

public OnVehicleRespray(playerid, vehicleid, color1, color2)
{
	return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
	return 1;
}

public OnPlayerExitedMenu(playerid)
{
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	return 1;
}

public OnPlayerUpdate(playerid)
{
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	return 1;
}

public OnPlayerStreamOut(playerid, forplayerid)
{
	return 1;
}

public OnVehicleStreamIn(vehicleid, forplayerid)
{
	return 1;
}

public OnVehicleStreamOut(vehicleid, forplayerid)
{
	return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	return 1;
}

public OnPlayerClickPlayer(playerid, clickedplayerid, source)
{
	return 1;
}
