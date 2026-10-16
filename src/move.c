#include "move.h"

/* visszaadja a keresett pozíció a táblán van e?*/
int CH_position_isvalid(CH_position position)
{
    return (position.x >= 0 && position.x < 8 && position.y >= 0 && position.y < 8);
}

/* A szín ellentétét visszaadó függvény*/
CH_color_t CH_opponent_color_t(CH_color_t color)
{
    if     (color == BLACK) return WHITE;
    else if(color == WHITE) return BLACK;
    else                    return NO_COLOR;
}

/* Ha a move típusa normál, ez fut le*/
CH_board CH_make_normal_move(CH_board board, CH_move move)
{
    /* megnézzük mit mozgatunk*/
    CH_piece piece = CH_get_piece_from_position(board, move.startPos);
    piece.has_moved = 1;

    /* átmozgatjuk*/
    board = CH_set_piece(board, (CH_piece){NO_PIECE, NO_COLOR, 0}, move.startPos);
    board = CH_set_piece(board, piece, move.endPos);
    
    return board;
}

/* Ezzel a függvénnyel lehet mozgatni bármilyen bábut bárhova*/
CH_board CH_make_move(CH_board board, CH_move move)
{
    switch(move.type)
    {
        default: board = CH_make_normal_move(board,move);
    }
    return board;
}