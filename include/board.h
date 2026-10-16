#ifndef BOARD_H
#define BOARD_H
#include "types.h"
    
    /* ################################### BOARD HEADER ################################################*/
    
    CH_board CH_create_empty_board();
    CH_board CH_set_board_to_default();
    CH_piece CH_get_piece_from_position(CH_board board, CH_position position);
    CH_board CH_set_piece(CH_board board, CH_color_t color, CH_piece_t type, CH_position position);
    CH_board CH_make_move(CH_board board, CH_move move);

#endif