#include "move.h"
#include "board.h"

/*MINDEN OFFSET POZÍCIÓ A SZABÁLYOS LÉPÉSEKHEZ*/
const CH_position UP        = { 0,-1};
const CH_position DOWN      = { 0, 1};
const CH_position LEFT      = {-1, 0};
const CH_position RIGHT     = { 1, 0};
const CH_position UPRIGHT   = { 1,-1};
const CH_position UPLEFT    = {-1,-1};
const CH_position DOWNRIGHT = { 1, 1};
const CH_position DOWNLEFT  = {-1, 1};

/* A szabályos lépéskeresés során használt függvény, mivel több másik függvény használja,
külön függvény készült*/
int _contains_position(CH_position* positions, CH_position position, int count)
{
    for(int i = 0; i < count; i++)
    {
        if(CH_pos_equals(positions[i], position))
        {
            return 1;
        }
    }
    return 0;
}


/*A BÁSTYA VEZÉR ÉS FUTÓ LÉPÉSTÍPUSÁNAK MEGHATÁROZÁSA, SZABÁLYELLENŐRZÉS*/
CH_move _test_rook_queen_bishop(CH_board board, CH_move move,CH_piece piece)
{
    /* Korábban 3 külön function, nagyon hasonlóak voltak. Ezért egyben is működik*/
    /* A type alapján az offsetetk megállapítása*/
    int offset_count;
    int valid_count = 0;
    CH_position offsets[8] = {UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT};
    /* A vezér maximum 27 mezőt tud támadni*/
    CH_position valid_ends  [27] = {0};

    if(piece.type == ROOK || piece.type == BISHOP){offset_count = 4;}
    else offset_count = 8;

    if(piece.type == BISHOP)
    {offsets[0] = UPRIGHT; offsets[1] = UPLEFT; offsets[2] = DOWNRIGHT; offsets[3] = DOWNLEFT;}


    /* Végigmegyünk a lehetséges irányon*/
    for(int j= 0; j < offset_count; j++)
    {
        /*Állítsuk a keresett pozíciót a mostanira*/
        CH_position searched_pos = move.start_pos;
        for(int i = 0; i < 7; i++)
        {
            /* Mivel a get_piece nem ellenőriz indexet, itt korábban kell ellenőrizni*/
            searched_pos = CH_add_positions(offsets[j], searched_pos);
            if(!CH_is_on_board(searched_pos))break;
            CH_piece piece_found = CH_get_piece_from_position(board, searched_pos);
            
            /* Ha a mező üres: */
            if(piece_found.type == NO_PIECE)
            {
                /* A pozíció jó lesz, hozzáad, számlálót növel*/
                valid_ends[valid_count] = searched_pos;valid_count++;
            }
            else if(piece_found.color != piece.color)
            {
                /* Ha a talált bábu másik színű a lépés még helyes,
                de nincs több az irányban, ezért kilépünk és megyünk a következőre*/
                valid_ends[valid_count] = searched_pos;valid_count++;break;
            }else break; /* Ha a talált bábu fehér*/
        }
    }

    if(_contains_position(valid_ends, move.end_pos, valid_count))move.type = NORMAL;
    else move.type = ERROR;

    return move;
}


/* A HUSZÁR LÉPÉSTÍPUSA, SZABÁLYELLENŐRZÉS*/
CH_move _test_knight(CH_board board, CH_move move, CH_color_t color)
{
    int valid_count = 0;
    /* Összes lehetséges relatív huszárlépés*/
    CH_position knight_offsets[8] = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    CH_position valid_ends[8] = {0};

    /* megnézzük a huszárlépések közül melyek lehetségesek*/
    for(int i = 0; i < 8; i++)
    {
        CH_position search_position = CH_add_positions(move.start_pos, knight_offsets[i]); /*relatív poz->poz*/
        if(!CH_is_on_board(search_position))continue; /*táblán- van-e?*/
        CH_piece piece_found = CH_get_piece_from_position(board, search_position);/*milyen bábu ez*/
        if(piece_found.color == color)continue; /* Ugyanolyan színűek-e vagy sem*/
        valid_ends[valid_count] = search_position;
        valid_count++;
    }

    if(_contains_position(valid_ends, move.end_pos, valid_count))move.type = NORMAL;
    else move.type = ERROR;
    return move;
}


/* Beállítja a lépés típusát, itt ellenőrzi a szabályosságot is*/
CH_move _set_move_type(CH_board board, CH_move move)
{
    /* Kezelei a biztosan rossz lépéseket*/
    if(move.type == ERROR)return move; /*tudjuk már hogy az*/
    if(CH_pos_equals(move.start_pos, move.end_pos)){move.type = ERROR; return move;}/*ugyanoda lép*/
    CH_piece moving_piece = CH_get_piece_from_position(board, move.start_pos);
    CH_piece other_piece  = CH_get_piece_from_position(board,move.end_pos);
    if(moving_piece.color == other_piece.color){move.type = ERROR; return move;} /*egyező színre lép*/
    if(moving_piece.color == NO_COLOR){move.type = ERROR; return move;}

    /* A megfelelő bábuhoz a megfelelő ellenőrzőfüggvény keresése*/
    switch(moving_piece.type)
    {
        /* A ROOK BISHOP ÉS QUEEN esetekben is ugyanazt a függvényt hívjuk*/
        case ROOK:      
        case BISHOP:    
        case QUEEN:     move = _test_rook_queen_bishop(board,move,moving_piece);  break;
        case KNIGHT:    move = _test_knight(board,move,moving_piece.color);       break;  
        case PAWN:                                                                break;
        case KING:                                                                break;
        default:        move.type = ERROR;                                        break;
    }
    return move;
}

/* Gyárfüggvény a CH_move struktúrának*/
CH_move CH_create_move(CH_position from, CH_position to, CH_move_t type)
{
    CH_move move;
    if(!CH_is_on_board(from) || !CH_is_on_board(to))type = ERROR;
    move.type = type;
    move.start_pos = from;
    move.end_pos = to;
    return move;
}

/* A szín ellentétét visszaadó függvény*/
CH_color_t CH_opponent_color_t(CH_color_t color)
{
    if     (color == BLACK) return WHITE;
    else if(color == WHITE) return BLACK;
    else                    return NO_COLOR;
}

/* Ha a move típusa normál, ez fut le*/
CH_board CH_make_normal_move(CH_board board, CH_move move)
{
    /* megnézzük mit mozgatunk*/
    CH_piece piece = CH_get_piece_from_position(board, move.start_pos);
    piece.has_moved = 1;
    /* átmozgatjuk*/
    board = CH_set_piece(board, (CH_piece)
    {.type= NO_PIECE, .color = NO_COLOR, .has_moved = 0}, move.start_pos);
    board = CH_set_piece(board, piece, move.end_pos);
    return board;
}


/* Ezzel a függvénnyel lehet mozgatni bármilyen bábut bárhova*/
CH_board CH_make_move(CH_board board, CH_move move)
{
    move = _set_move_type(board,move);
    if(move.type == ERROR)return board;
    switch(move.type)
    {
        default: board = CH_make_normal_move(board,move);
    }
    return board;
}
