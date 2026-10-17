#include "parser.h"
#include "move.h"
#include <stdio.h>

int _char_to_index(char c)
{
    /* a függvény a betűket átalakítja táblaindexekké, és a számokat is, a számok átalakítása
    kicsit nehezebb. 1-8-ig érkeznek. ebből mi intet csinálunk, kivonunk egyet a helyes tömbindexért,
    majd megfordítjuk hogy ne lent kezdődjön bal alul az index, hanem bal felül. Feltételezzük hogy az ide
    érkező lépéseknél a betűk a-h közötti kisbetűk, a számok 1-8 közötti számok*/
    if (c >= 'a' && c <= 'h') return c-'a';
    if (c >= '1' && c <= '8') return 7-(c-'1');
}

/* Ez a függvény nem állítja be a CH_move_t értéket, csak a pozíciókat adja vissza.
A memóriaszemét elkerülése miatt mindent NORMAL-ra állít, ezt később a program átalakítja*/
CH_move PA_parse_string(char string[4])
{
    CH_position from = (CH_position){.x = _char_to_index(string[0]), .y = _char_to_index(string[1])};
    CH_position to = (CH_position){.x = _char_to_index(string[2]), .y = _char_to_index(string[3])};
    printf("x:%d y:%d\n", from.x, from.y);
    printf("x:%d y:%d\n", to.x, to.y);
    return CH_create_move(from, to, NORMAL);
}