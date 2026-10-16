#include "ui.h"
#include "board.h"
#include "move.h"
#include <stdio.h>

/* Egy switch segítségével a megfelelő típust megfelelő karakterre váltja*/
char get_char_for_piece_t(CH_piece_t type)
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
char get_char_for_color_t(CH_color_t color)
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
            /* A szín alapján a charachter kiválasztása*/
            char cc = get_char_for_color_t(CH_get_piece_from_position(board,(CH_position){j,i}).color);
            /* A bábutípus alapján a karakter kiválasztása*/
            char pc = get_char_for_piece_t(CH_get_piece_from_position(board, (CH_position){j,i}).type);
            printf("| %c%c ", cc,pc);
        }
        printf("|");
        printf("\n");
    }
    printf("%s\n", line);
}

/* Visszaad 1-et ha újrapróba kell, visszaad 0-t ha nem*/
