#ifndef TYPES_H
#define TYPES_H

/* #################################################### ENUM ################################################## */

/*A Bábu típus és a szín típust a mezők tárolják. Ezzel tárolva az állást */
typedef enum CH_piece_t  {ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN, NO_PIECE}     CH_piece_t;
typedef enum CH_color_t {BLACK, WHITE, NO_COLOR}                                 CH_color_t;

/* A lépés fajtájának tárolásával egyszerűbb a különleges lépések kezelése*/
typedef enum CH_move_t   {NORMAL, CASTLE_SHORT, CASTLE_LONG, DOUBLE_PAWN,
                             EN_PASSANT}                                         CH_move_t;
typedef enum CH_game_state_t  {MATE, STALEMATE, PLAYING, WHITE_WON, BLACK_WON}   CH_game_state_t;

/* #################################################### STRUCT ###############################################*/

/* A position indexelése bal felül kezdődik (A8) == (0,0) ; (H1) == (7,7) */
typedef struct CH_position {int x, y;}                                           CH_position;
typedef struct CH_square   {CH_color_t piece_color; CH_piece_t piece_type;}      CH_square;
typedef struct CH_move     {CH_position startPos, endPos; CH_move_t type;}       CH_move;
typedef struct CH_piece    {CH_piece_t type; CH_color_t color;}                  CH_piece;

/*A játék tárolja a jelenlegi táblát és a játék státuszát, a tábla tárolja az összes mezőt,
a sáncolási jogokat. Ezt azért hogy elég legyen a tábla önmagában a lépés helyességének eldöntésére*/
typedef struct CH_board    {CH_square squares[64]; CH_color_t next_color; 
                             CH_position en_passant_position; 
                             int can_castle_short[2]; int can_castle_long[2];}   CH_board;
typedef struct CH_game     {CH_game_state_t game_state; CH_board board;}         CH_game;



#endif