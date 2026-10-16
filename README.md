Kasza Zsombor - Programozás alapjai 1 - Nagyházi - SAKK PROGRAM

FÁJLRENDSZER:
    - .c fájlok az src mappában
    - .h fájlok az include mappában
    - .o fájlok a bin mappában
    - .md dokumentációk a docs fileban
    - .exe lefordított program a gyökérkönyvtárban van, nem a bin mappában

MEGJ:
    - ha nem létezik a bin mappa, a make legenerálja
    - minden header fájlban az #ifndef és #define segítségével biztosítva van,
      hogy ne legyen többszörös deklaráció. 
    
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