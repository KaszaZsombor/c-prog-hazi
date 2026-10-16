Kasza Zsombor - Programozás alapjai 1 - Nagyházi - SAKK PROGRAM

FÁJLRENDSZER:
    - .c fájlok az src mappában
    - .h fájlok az include mappában
    - .o fájlok a bin mappában
    - .md dokumentációk a docs fileban
    - .exe lefordított program a gyökérkönyvtárban van, nem a bin mappában

MEGJ:
    - ha nem létezik a bin mappa, a make legenerálja

Minden header tetején ellenőrizve van, hogy az adott fájlban korábban már includolva lett-e a header,
így a program fordításánal a duplikált kód elkerülhető.

    
FELADAT :
    BOARD SETUP CLEANUP
    FŐ GAME LOOP
    BEMENET FELDOLGOZÁSA
    SZABÁLYOK ELLENŐRZÉSE
    KÜLÖNLEGES LÉPÉSEK
+:
grafika
játszma betöltése elemzésre
játszma mentése a játék után file-ba