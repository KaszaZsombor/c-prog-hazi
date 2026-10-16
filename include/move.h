#ifndef MOVE_H
#define MOVE_H
    #include "board.h"
    CH_board CH_make_move(CH_board board, CH_move move);
    CH_movelist CH_get_movelist(CH_board board, CH_position position);
    int CH_position_isvalid(CH_position position);
#endif