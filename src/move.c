#include "move.h"
#include "board.h"

/*MINDEN OFFSET POZÍCIÓ A SZABÁLYOS LÉPÉSEKHEZ*/
const CH_position UP        = { 0,-1};
const CH_position DOWN      = { 0, 1};
const CH_position LEFT      = {-1, 0};
const CH_position RIGHT     = { 1, 0};
const CH_position UPRIGHT   = { 1,-1};
const CH_position UPLEFT    = {-1,-1};
const CH_position DOWNRIGHT = { 1, 1};
const CH_position DOWNLEFT  = {-1, 1};

/* TESZTELÉSE A BÁSTYALÉPÉSNEK*/
CH_move _test_rook_move(CH_board board, CH_move move, CH_color_t color)
{
    /* Minden irány amibe léphet*/
    /* a lehetséges pozíciók tárolása */
    CH_position offsets     [ 4] = {UP,RIGHT,LEFT,DOWN};
    CH_position valid_ends  [16] = {0};
    int         valid_count      = 0;

    /* Végigmegyünk a 4 lehetséges irányon*/
    for(int j= 0; j < 4; j++)
    {
        /*Állítsuk a keresett pozíciót a mostanira*/
        CH_position searched_pos = move.start_pos;
        for(int i = 0; i < 8; i++)
        {
            /* Mivel a get_piece nem ellenőriz indexet, itt korábban kell ellenőrizni*/
            searched_pos         = CH_add_positions           (offsets[j], searched_pos);
            if(!CH_is_on_board(searched_pos))break;
            CH_piece piece_found = CH_get_piece_from_position (board, searched_pos);
            
            /* Ha a mező üres: */
            if(piece_found.type == NO_PIECE)
            {
                /* A pozíció jó lesz, hozzáad, számlálót növel*/
                valid_ends[valid_count] = searched_pos;valid_count++;
            }
            else if( piece_found.color != color)
            {
                /* Ha a talált bábu másik színű a lépés még helyes,
                de nincs több az irányban, ezért kilépünk és megyünk a következőre*/
                valid_ends[valid_count] = searched_pos;valid_count++;break;
            }else break; /* Ha a talált bábu fehér*/
        }
    }

    for(int i = 0; i < valid_count; i++)
    {
        if(CH_pos_equals(valid_ends[i], move.end_pos))
        {
            move.type = NORMAL;
            return move;
        }
    }
    move.type = ERROR;
    return move;
}

/* Beállítja a lépés típusát, itt ellenőrzi a szabályosságot is*/
CH_move _set_move_type(CH_board board, CH_move move)
{
    if(move.type == ERROR)return move;
    if(CH_pos_equals(move.start_pos, move.end_pos)){move.type = ERROR; return move;}

    CH_piece moving_piece = CH_get_piece_from_position(board, move.start_pos);
    CH_piece other_piece  = CH_get_piece_from_position(board,move.end_pos);

    if(moving_piece.color == other_piece.color){move.type = ERROR; return move;}
    switch(moving_piece.type)
    {
        case NO_PIECE: move.type = ERROR;break;
        case ROOK: move = _test_rook_move(board,move,moving_piece.color);
    }

    return move;
}

/* Gyárfüggvény a CH_move struktúrának*/
CH_move CH_create_move(CH_position from, CH_position to, CH_move_t type)
{
    CH_move move;
    if(!CH_is_on_board(from) || !CH_is_on_board(to))type = ERROR;
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
    move = _set_move_type(board,move);
    if(move.type == ERROR)return board;
    switch(move.type)
    {
        default: board = CH_make_normal_move(board,move);
    }
    return board;
}
