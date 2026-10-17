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


    return 0;
}