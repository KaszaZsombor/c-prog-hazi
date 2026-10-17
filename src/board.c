#include "board.h"

/* Összead 2 pozíciót*/
CH_position CH_add_positions(CH_position pos1, CH_position pos2)
{
    return (CH_position){ pos1.x + pos2.x , pos1.y + pos2.y};
}

/*Szoroz egy pozíciót egy egész számmal*/
CH_position CH_multiply_position(CH_position pos, int x)
{
    pos.x *= x;
    pos.y *= x;
    return pos;
}

/* ellenőrzi hogy 2 pozíció egyenlő-e*/
int CH_pos_equals(CH_position pos1, CH_position pos2)
{
    return (pos1.x == pos2.x && pos1.y == pos2.y);
}

/* visszaadja a keresett pozíció a táblán van e?*/
int CH_is_on_board(CH_position position)
{
    return (position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8);
}

/* Egy pozjciót megadva tudjuk egy mező bábuját változtatni. Az CH_position indexelés bal felül indul*/
CH_board CH_set_piece(CH_board board, CH_piece piece, CH_position position)
{
    /* A túlindexelés ellen, biztosítjuk az indexeket 0-7-ig*/
    if(!CH_is_on_board(position))return board;
    /* a megfelelő mező iválasztása a pozíció alapján, átváltás CH_position és tömbindex között*/
    board.squares[ position.y * 8 + position.x ].piece = piece;
    return board;
}

/* Ezért lett a CH_piece struktúra létrehozva, CH_position-re ad vissza bábut*/
CH_piece CH_get_piece_from_position(CH_board board, CH_position position)
{
    /* A túlindexelés ellen, biztosítjuk az indexeket 0-7-ig*/
    if(!CH_is_on_board(position))return(CH_piece){.color = NO_COLOR, .has_moved = 0, .type = NO_PIECE};
    return board.squares[ position.y * 8 + position.x ].piece;
}

/* Egy üres tábla visszaküldése a hívónak*/
CH_board CH_create_empty_board()
{
    CH_board empty_board;
    /* Az üres táblának legyen a következő lépésen lévője fehér, ne tiltson sáncot*/
    empty_board.next_color = WHITE;

    /*docs-ban említett nincs en-passent jelölés*/
    empty_board.en_passant_position = (CH_position){-1,-1};
    
    CH_piece piece = (CH_piece){.color = NO_COLOR, .has_moved = 0, .type = NO_PIECE};
    for(int i = 0; i < 64; i++) empty_board.squares[i].piece = piece;
    return empty_board;
}

/* Egy alapállásban lévő tábla küldése a hívónak*/
CH_board CH_create_default_board()
{
    /* Az ürestábló jó alap, csak az alapállás bábuit kell beállítani*/
    CH_board default_board = CH_create_empty_board();
    /*Gyalogok*/
    for(int i = 0; i < 8; i++)
    {
        default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = PAWN, .has_moved = 0} ,(CH_position){i, 1});
        default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = PAWN, .has_moved = 0} ,(CH_position){i, 6});
    }
    /*Tisztek*/
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = ROOK,   .has_moved = 0}, (CH_position){0, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = KNIGHT, .has_moved = 0}, (CH_position){1, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = BISHOP, .has_moved = 0}, (CH_position){2, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = QUEEN,  .has_moved = 0}, (CH_position){3, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = KING,   .has_moved = 0}, (CH_position){4, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = BISHOP, .has_moved = 0}, (CH_position){5, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = KNIGHT, .has_moved = 0}, (CH_position){6, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = BLACK, .type = ROOK,   .has_moved = 0}, (CH_position){7, 0});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = ROOK,   .has_moved = 0}, (CH_position){0, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = KNIGHT, .has_moved = 0}, (CH_position){1, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = BISHOP, .has_moved = 0}, (CH_position){2, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = QUEEN,  .has_moved = 0}, (CH_position){3, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = KING,   .has_moved = 0}, (CH_position){4, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = BISHOP, .has_moved = 0}, (CH_position){5, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = KNIGHT, .has_moved = 0}, (CH_position){6, 7});
    default_board = CH_set_piece(default_board, (CH_piece){.color = WHITE, .type = ROOK,   .has_moved = 0}, (CH_position){7, 7});
    return default_board;
}