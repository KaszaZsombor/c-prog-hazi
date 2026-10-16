#include <stdio.h>
#include "board.h"
#include "types.h"

int main(void)
{
    CH_board board = CH_set_board_to_default();

    for(int i = 0; i < 64; i++)
    {
        printf(" | c: %d, p: %d |", board.squares[i].piece_color, board.squares[i].piece_type);
        printf("\n");
    }

    return 0;
}