#include "ui.h"
#include "board.h"
#include "move.h"
#include <stdio.h>

/* Egy switch segítségével a megfelelő típust megfelelő karakterre váltja*/
char _get_char_for_piece_t(CH_piece_t type)
{
    switch (type)
    {
        case PAWN: return 'P';
        case ROOK: return 'R';
        case KNIGHT: return 'N';
        case BISHOP:return 'B';
        case KING:return 'K';
        case QUEEN:return 'Q';
        default:return' ';
    }
}

/* Ugyanaz mint a piece-es, csak a színre ad karaktert*/
char _get_char_for_color_t(CH_color_t color)
{
    switch (color)
    {
        case WHITE:return 'w';
        case BLACK:return 'b';
        default:return ' ';
    }
}

/* Tábla a stdoutra rajzolása*/
void UI_draw_board(CH_board board)
{
    char line[] = " ---- ---- ---- ---- ---- ---- ---- ----";
    /*oszlopok*/
    for(int i = 0; i< 8; i++)
    {
        printf("%s\n", line);
        /*sorok*/
        for(int j = 0; j < 8; j++)
        {
            CH_piece piece = CH_get_piece_from_position(board,(CH_position){j,i});
            /* A szín alapján a charachter kiválasztása*/
            char cc = _get_char_for_color_t(piece.color);
            /* A bábutípus alapján a karakter kiválasztása*/
            char pc = _get_char_for_piece_t(piece.type);
            printf("| %c%c ", cc,pc);
        }
        printf("|");
        printf("\n");
    }
    printf("%s\n", line);
}
