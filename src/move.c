#include "move.h"

/* Gyárfüggvény a CH_move struktúrának*/
CH_move CH_create_move(CH_position from, CH_position to, CH_move_t type)
{
    CH_move move;
    move.type = type;
    move.start_pos = from;
    move.end_pos = to;
    return move;
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
    CH_piece piece = CH_get_piece_from_position(board, move.start_pos);
    piece.has_moved = 1;
    /* átmozgatjuk*/
    board = CH_set_piece(board, (CH_piece)
    {.type= NO_PIECE, .color = NO_COLOR, .has_moved = 0}, move.start_pos);
    board = CH_set_piece(board, piece, move.end_pos);
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



/* Ez a függvény egy lépés szabályosságának ellenőrzéséhez legenerálja az összes lehetséges
lépést az adott bábuval*/
CH_movelist _generate_all_moves(CH_board board, CH_position position)
{
    CH_piece piece = CH_get_piece_from_position(board, position);
    switch(piece.type)
    {
        case ROOK: break;
        case BISHOP: break;
        case QUEEN: break;
    }
}