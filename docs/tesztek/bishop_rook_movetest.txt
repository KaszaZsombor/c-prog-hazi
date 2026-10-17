#include <stdio.h>
#include "parser.h"
#include "types.h"
#include "board.h"
#include "move.h"
#include "ui.h"

int main(void)
{
    CH_board board = CH_create_default_board();
    UI_draw_board(board);



    CH_move a = PA_parse_string("afaa");
    board = CH_make_move(board, a);
    UI_draw_board(board);
    
    CH_move b = PA_parse_string("sdsw");
    board = CH_make_move(board, b);
    UI_draw_board(board);
    
    CH_move c = PA_parse_string("a2dw");
    board = CH_make_move(board, c);
    UI_draw_board(board);
    
    CH_move move0 = PA_parse_string("a2a4");
    board = CH_make_move(board, move0);
    UI_draw_board(board);
    
    CH_move move2 = PA_parse_string("a1a3");
    board = CH_make_move(board, move2);
    UI_draw_board(board);
    
    CH_move move1 = PA_parse_string("a3b3");
    board = CH_make_move(board, move1);
    UI_draw_board(board);
    
    CH_move move3 = PA_parse_string("b3b7");
    board = CH_make_move(board, move3);
    UI_draw_board(board);
    
    CH_move move4 = PA_parse_string("b7b8");
    board = CH_make_move(board, move4);
    UI_draw_board(board);

    CH_move move5 = PA_parse_string("b8h8");
    board = CH_make_move(board, move5);
    UI_draw_board(board);

    CH_move r = PA_parse_string("c8b7");
    board = CH_make_move(board, r);
    UI_draw_board(board);
    
    r = PA_parse_string("b7a8");
    board = CH_make_move(board, r);
    UI_draw_board(board);

    r = PA_parse_string("b7g2");
    board = CH_make_move(board, r);
    UI_draw_board(board);

    return 0;
}