#ifndef TYPES_H
#define TYPES_H
    /* #################################################### ENUM ################################################## */

    /*A Bábu típus és a szín típust a mezők tárolják. Ezzel tárolva az állást */
    typedef enum CH_piece_t  {ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN, NO_PIECE}     CH_piece_t;
    typedef enum CH_color_t {BLACK, WHITE, NO_COLOR}                                 CH_color_t;

    /* A lépés fajtájának tárolásával egyszerűbb a különleges lépések kezelése*/
    typedef enum CH_move_t   {NORMAL, CASTLE_SHORT, CASTLE_LONG, DOUBLE_PAWN,
                                 EN_PASSANT, ERROR}                                  CH_move_t;
    /* A játék állapot, a main loopnak információ*/
    typedef enum CH_game_state_t  { PLAYING, DRAW, WHITE_WON, BLACK_WON}             CH_game_state_t;

    /* #################################################### STRUCT ###############################################*/

    /* A position indexelése bal felül kezdődik (A8) == (0,0) ; (H1) == (7,7) */
    typedef struct CH_position {int x, y;}                                           CH_position;
    /* a lépés struktúra az alapja a játéknak, ezzel lehet változtatni a táblán,
    a tábla tömbjének közvetlen változtatása nélkül*/
    typedef struct CH_move     {CH_position start_pos, end_pos; CH_move_t type;}     CH_move;
    /*A bábu struktúra tartalmazza az alapinfókat, plusz a szabályokhoz egy has_moved változót*/
    typedef struct CH_piece    {CH_piece_t type; CH_color_t color; int has_moved;}   CH_piece;
    /* Egyenlőre felesleges, A tábla tárol belőle 64-et, de későbbi optimalizálás vagy újraírás során
    hasznos lehet*/
    typedef struct CH_square   {CH_piece piece;}                                     CH_square;
    /* Egy bábu lépéseinek listáját tartalmazza, amik szabályosak*/
    typedef struct CH_movelist {CH_piece piece; int movecount; 
                                 CH_move moves[64];}                                 CH_movelist;
    /*A játék tárolja a jelenlegi táblát és a játék státuszát, a tábla tárolja az összes mezőt.
    a sáncolási jogokat a király bábu tárolja, hogy lépett-e. 
    Ezt azért hogy elég legyen a tábla önmagában a lépés helyességének eldöntésére*/
    typedef struct CH_board    {CH_square squares[64]; CH_color_t next_color; 
                                 CH_position en_passant_position;}                   CH_board;
    /*A mainloopban ez a struktúra jön biztosan létre, ez maga a futó játék, később itt lehet kezelni
    a korábbi CH_Boardok tárolására*/
    typedef struct CH_game     {CH_game_state_t game_state; CH_board board;}         CH_game;
#endif