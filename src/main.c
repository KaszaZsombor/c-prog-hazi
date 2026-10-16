#include <stdio.h>
#include "board.h"
#include "move.h"
#include "types.h"
#include "ui.h"

int main(void)
{
    CH_board board = CH_set_board_to_default();
    UI_draw_board(board);
    CH_move move = {.startPos.x = 1, .startPos.y = 1, .endPos.x = 1, .endPos.y = 2, .type = NORMAL};
    board = CH_make_move(board,move);
    UI_draw_board(board);
    return 0;
}