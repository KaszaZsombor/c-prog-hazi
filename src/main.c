#include <stdio.h>
#include "board.h"
#include "move.h"
#include "types.h"
#include "ui.h"
#include "parser.h"

int main(void)
{
    CH_board board = CH_create_default_board();
    UI_draw_board(board);

    CH_move move2 = PA_parse_string("e2e4");
    board = CH_make_move(board, move2);
    UI_draw_board(board);
    
    CH_move move1 = PA_parse_string("e7e5");
    board = CH_make_move(board, move1);
    UI_draw_board(board);
    
    CH_move move3 = PA_parse_string("a2a3");
    board = CH_make_move(board, move3);
    UI_draw_board(board);
    
    return 0;
}