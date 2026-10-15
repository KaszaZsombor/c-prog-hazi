A nagy házi feladat specifikációja
GeoGebra-szerű síkgeometriai szerkesztő C nyelven, SDL grafikus felülettel
1. Mit fog csinálni a program
Egy GeoGebra-szerű, interaktív síkgeometriai szerkesztő C nyelven, SDL grafikus felülettel. A felhasználó egérrel pontokat, szakaszokat, egyeneseket ésköröket rajzolhat egy ablakban, ezekből egyszerű szerkesztési lépésekkel újabb alakzatokat hozhat létre, a kész rajzot pedig fájlba mentheti és később betöltheti.
Főbb funkciók:
• Alakzatok felvétele egérrel: pont, szakasz, egyenes, kör.
• Tetszőleges számú alakzat tárolása, a darabszámot csak a memória korlátozza.
• Szerkesztési lépések:
    ◦ két alakzat metszéspontjainak meghatározása (egyenes–egyenes, egyenes–kör, kör–kör, szakaszok esetén annak vizsgálata is, hogy a metszéspont rajta van-e a szakaszon),
    ◦ adott pontban merőleges állítása egy egyenesre vagy szakaszra.
• Alakzat kijelölése kattintással, törlése.
• Rajz mentése fájlba és betöltése fájlból.
• Az ablakban az összes alakzat kirajzolása, a kijelölt kiemelve.
2. Bemenő adatok
• Egér: kattintások az ablakban, amelyek a síkon pontokat jelölnek ki. Egy kör például két kattintással adható meg (középpont, majd egy kerületi pont), egy szakasz vagy egyenes szintén kettővel.
• Billentyűzet: az aktív eszköz kiválasztása (pont, szakasz, egyenes, kör, metszéspont, merőleges, kijelölés), törlés, mentés, betöltés, kilépés.
• Fájl: korábban mentett rajz szöveges fájlja, betöltéskor. A fájlnevet a program indításakor parancssori argumentumként vagy a felületen lehet megadni (ez még eldöntendő).
3. Kimenő adatok
• Képernyő: az SDL ablakban a megrajzolt alakzatok, a kijelölés kiemelése, és egy rövid állapotsor vagy üzenet arról, hogy melyik eszköz aktív, illetve hogy mi a következő lépés.
• Fájl: a mentett rajz szöveges formában, soronként egy alakzattal. Minden sorban elöl az alakzat típusa áll, utána a megadó adatai: pontnál két koordináta, szakasznál a két végpont koordinátái, egyenesnél két pont koordinátái, körnél a középpont koordinátái és a sugár.
• Hibaüzenetek: például ha a fájl nem nyitható meg, hibás a formátuma, vagy a metszésnek nincs eredménye (párhuzamos egyenesek, nem metsző körök).
4. Korlátok és feltevések
• A síkbeli koordináták lebegőpontos számok, az összehasonlításhoz egy kis tűréshatárt (epszilont) használ a program.
• A metszéspontok a létrehozáskor kapnak értéket, és utólag nem követik az alakzatok mozgatását.
5. Hibakezelés elve
Mit csinál a program, ha nem sikerül a memóriafoglalás, ha a fájl hibás, vagy ha a kijelölt alakzatokra nem értelmezhető a művelet. Ezt a részt még ki kell dolgozni.
6. Példa forgatókönyv
A felhasználó rajzol két kört, kiválasztja a metszéspont eszközt, rákattint a két körre, és megjelenik a két metszéspont.
7. Még eldöntendő kérdések
1. A fájlnevet a program indításakor adja meg a felhasználó, vagy a programon belül, billentyűzettel?
2. A kijelölés és a törlés benne legyen az első változatban, vagy csak később?
3. A metszéspontok maradjanak állandó pontok, ahogy feltételeztük?