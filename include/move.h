#ifndef MOVE_H
#define MOVE_H
#include "board.h"
    CH_move     CH_create_move (CH_position from, CH_position to, CH_move_t type);
    CH_board    CH_make_move   (CH_board board, CH_move move);
    CH_movelist CH_get_movelist(CH_board board, CH_position position);
#endif