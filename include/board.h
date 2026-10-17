#ifndef BOARD_H
#define BOARD_H
#include "types.h"
    CH_board        CH_create_empty_board       (void);
    CH_board        CH_create_default_board     (void);
    CH_piece        CH_get_piece_from_position  (CH_board, CH_position);
    CH_board        CH_set_piece                (CH_board, CH_piece, CH_position);
    int             CH_is_on_board              (CH_position);
    int             CH_pos_equals               (CH_position, CH_position);
    CH_position     CH_add_positions            (CH_position, CH_position);
    CH_position     CH_multiply_position        (CH_position, int);
#endif