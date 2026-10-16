STRUKTÚRÁK

- a projekt fő struktúrái a types.h fájlban vannak, kommentekkel
- ide leírom a használt enumokat is

ENUMOK:
    - CH_piece_t: A bábu lehetséges típusai, szintén van egy NO_PIECE érték, az üres mező kezelésére
    - CH_color_t: A tábla lehetséges színállapotai, tartalmaz NO_COLOR színt. Ez akkor fontos,
      ha egy mezőn nem áll bábu.
    - CH_move_t: A lépések típusát tárolja
    - CH_game_state_t: A játék különböző állapotai: JÁTÉK, PATT, FEHÉR GYŐZÖTT, FEKETE GYŐZÖTT

STRUKTÚRÁK:
    - CH_position: 2 intet tartalmaz, ezek a tábla mezőinek indexeit jelölik. Az indexelés
      a bal felső sarokban indul. Így egyszerűbb lesz a tábla grafikus megjelenítése
    - CH_square: A mező struktúra, tárolja a rajta lévő bábut.
    - CH_move: Tárolja a lépést végző bábu kezdeti és vég CH_position-jét, és a lépés típusát
    - CH_piece: A bábuadatokat egy helyen tárolni tudó struktúra. Ezek a színe, fajtája, és hogy       léptek-e vele már. Ami a szabályos lépések miatt lesz fontos.
      - CH_movelist: Tárolja a bábut, hány lépése van a bábunak, és mik ezek a lépések. Egy functionnek lehet return értéke, egy sima tömbbel szemben
    - CH_board: A táblában tárololt adatokból el kell tudni dönteni korábbi állások ismerése nélkül,
      hogy egy lépés szabályos-e. Ezért tárolni kell mindkét szín mindkét irányba való sáncolási engedélyét és az olyan mezőket, ahova en-passant lépéssel lehet lépni. Ez ha nincs ilyen lépés -1 -1 értékű 
    - CH_game: Tárolja a játszma állását, ez az enumoknál szerepel. És tárolja a jelenlegi táblát.
