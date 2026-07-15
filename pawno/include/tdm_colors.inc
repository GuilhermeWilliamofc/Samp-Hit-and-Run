// 1. Guardas de Inclusão (Evita dupla inclusão)
#if defined _tdm_colors_included
    #endinput
#endif
#define _tdm_colors_included

// 2. Definições de constantes locais do módulo
// ex: #define VALOR_XP_DIARIO 150
#define COLOR_WHITE         0xFFFFFFFF
#define COLOR_BLACK         0x000000FF
#define COLOR_RED           0xFF0000FF
#define COLOR_GREEN         0x00FF00FF
#define COLOR_BLUE          0x0000FFFF
#define COLOR_YELLOW        0xFFFF00FF
#define COLOR_ORANGE        0xFF9900FF
#define COLOR_CYAN          0x00FFFFFF
#define COLOR_MAGENTA       0xFF00FFFF
#define COLOR_PURPLE        0x800080FF
#define COLOR_GREY          0xAFAFAFFF
#define COLOR_LIGHTBLUE     0x33CCFFFF
#define COLOR_DARKGOLD      0x808000FF

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
