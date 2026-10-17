#ifndef MOVE_H
#define MOVE_H
#include "board.h"
    CH_move  CH_create_move (CH_position, CH_position, CH_move_t);
    CH_board CH_make_move   (CH_board, CH_move);
#endif