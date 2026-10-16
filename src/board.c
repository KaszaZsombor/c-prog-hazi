#include "board.h"

/* ################################### BOARD SOURCE ###################################################*/


/* Egy pozjciót megadva tudjuk egy mező bábuját változtatni. Az CH_position indexelés bal felül indul*/
CH_board CH_set_piece(CH_board board, CH_color_t color, CH_piece_t type, CH_position position)
{
    /* A tömbból való kilépés elkerülése miatt, biztosítjuk az indexeket 0-7-ig*/
    position.x = position.x % 8;
    position.y = position.y % 8;

    /* a megfelelő mező iválasztása a pozíció alapján, átváltás CH_position és tömbindex között*/
    board.squares[ position.y * 8 + position.x].piece_type = type;
    board.squares[ position.y * 8 + position.x].piece_color = color;
    return board;
}

/* Ezért lett a CH_piece struktúra létrehozva, CH_position-re ad vissza bábut*/
CH_piece CH_get_piece_from_position(CH_board board, CH_position position)
{
     /* A tömbból való kilépés elkerülése miatt, biztosítjuk az indexeket 0-7-ig*/
    position.x = position.x % 8;
    position.y = position.y % 8;

    CH_piece piece;
    piece.type = board.squares[ position.y * 8 + position.x].piece_type;
    piece.color =  board.squares[ position.y * 8 + position.x].piece_color;
    return piece;
}

/* Egy üres tábla visszaküldése a hívónak*/
CH_board CH_create_empty_board()
{
    /* Az üres táblának legyen a következő lépésen lévője fehér, ne tiltson sáncot*/
    CH_board empty_board;
    empty_board.en_passant_position = (CH_position){-1,-1};
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
    for(int i = 0; i < 8; i++)
    {
        default_board = CH_set_piece(default_board, BLACK, PAWN, (CH_position){i, 1});
        default_board = CH_set_piece(default_board, WHITE, PAWN, (CH_position){i, 6});
    }
    /*Tisztek*/
    default_board = CH_set_piece(default_board, BLACK, ROOK,   (CH_position){0, 0});
    default_board = CH_set_piece(default_board, BLACK, KNIGHT, (CH_position){1, 0});
    default_board = CH_set_piece(default_board, BLACK, BISHOP, (CH_position){2, 0});
    default_board = CH_set_piece(default_board, BLACK, QUEEN,  (CH_position){3, 0});
    default_board = CH_set_piece(default_board, BLACK, KING,   (CH_position){4, 0});
    default_board = CH_set_piece(default_board, BLACK, BISHOP, (CH_position){5, 0});
    default_board = CH_set_piece(default_board, BLACK, KNIGHT, (CH_position){6, 0});
    default_board = CH_set_piece(default_board, BLACK, ROOK,   (CH_position){7, 0});
    
    default_board = CH_set_piece(default_board, WHITE, ROOK,   (CH_position){0, 7});
    default_board = CH_set_piece(default_board, WHITE, KNIGHT, (CH_position){1, 7});
    default_board = CH_set_piece(default_board, WHITE, BISHOP, (CH_position){2, 7});
    default_board = CH_set_piece(default_board, WHITE, QUEEN,  (CH_position){3, 7});
    default_board = CH_set_piece(default_board, WHITE, KING,   (CH_position){4, 7});
    default_board = CH_set_piece(default_board, WHITE, BISHOP, (CH_position){5, 7});
    default_board = CH_set_piece(default_board, WHITE, KNIGHT, (CH_position){6, 7});
    default_board = CH_set_piece(default_board, WHITE, ROOK,   (CH_position){7, 7});

    

    return default_board;
}


/* Ezzel a függvénnyel lehet mozgatni bármilyen bábut bárhova*/
CH_board CH_make_move(CH_board board, CH_move move)
{
    /* megnézzük mit mozgatunk*/
    CH_piece piece = CH_get_piece_from_position(board, move.startPos);
    /* átmozgatjuk*/
    board = CH_set_piece(board, NO_COLOR, NO_PIECE, move.startPos);
    board = CH_set_piece(board, piece.color, piece.type, move.endPos);
    return board;

}