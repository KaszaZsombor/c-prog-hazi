#include "board.h"

/* ################################### BOARD SOURCE ###################################################*/


/* Egy pozjciót megadva tudjuk egy mező bábuját változtatni. Az CH_position indexelés bal felül indul*/
CH_board CH_set_piece(CH_board board, CH_piece_t type, CH_color_t color, CH_position position)
{
    /* A tömbból való kilépés elkerülése miatt, biztosítjuk az indexeket 0-7-ig*/
    position.x = position.x % 8;
    position.y = position.y % 8;

    /* a megfelelő mező iválasztása a pozíció alapján, átváltás CH_position és tömbindex között*/
    board.squares[ position.y * 8 + position.x].piece_type = type;
    board.squares[ position.y * 8 + position.x].piece_color = color;
    return board;
}


/* Egy üres tábla visszaküldése a hívónak*/
CH_board CH_create_empty_board()
{
    /* Az üres táblának legyen a következő lépésen lévője fehér, ne tiltson sáncot*/
    CH_board empty_board;
    empty_board.next_color = WHITE;
    for(int i = 0; i < 64; i++)
    {
        if(i < 2)
        {
            /* Sáncok engedélyezése */
            empty_board.can_castle_short[i] = 1;
            empty_board.can_castle_long [i] = 1;
        }
        /* Minden mező üresre állítása*/
        empty_board.squares[i].piece_color = NO_COLOR;
        empty_board.squares[i].piece_type  = NO_PIECE;
    }
    return empty_board;
}

/* Egy alapállásban lévő tábla küldése a hívónak*/
CH_board CH_set_board_to_default()
{
    /* Az ürestábló jó alap, csak az alapállás bábuit kell beállítani*/
    CH_board default_board = CH_create_empty_board();
    /*Gyalogok*/
    
}