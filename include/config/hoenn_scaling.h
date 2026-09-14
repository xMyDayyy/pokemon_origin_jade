#ifndef GUARD_CONFIG_HOENN_SCALING_H
#define GUARD_CONFIG_HOENN_SCALING_H

// =====================================================================
// Hoenn-Levelscaling - Regeldatei (hns_de / modern_hns_engde)
//
// Der Spieler erreicht Hoenn als Champion von Johto und Kanto. Damit
// die Region als drittes Kapitel funktioniert, skalieren Trainer und
// wilde Pokemon dynamisch mit dem Spieler, innerhalb eines vom Autor
// vorgegebenen Korridors pro Gebiet ("die Welt waechst mit, bleibt
// aber eine Welt mit Gefaelle").
//
// Kernregeln (mit Marc abgestimmt):
//  - Anker  = hoechstes Level im Spielerteam (nicht manipulierbar,
//             anders als Slot 1).
//  - Trainer: Anker - 5 .. Anker + 3. Die Levelabstaende innerhalb
//             eines Teams bleiben erhalten (das Ass des Trainers
//             liegt am Bandoberrand).
//  - Wild:    Anker - 10 .. Anker - 4. Das Gras liegt bewusst UNTER
//             dem Spieler: Trainingsplatz und Fangrevier, die
//             spannenden Kaempfe kommen von den Trainern.
//  - Bosse (Arenaleiter, Top Vier, Champion, Magma-/Aqua-Bosse und
//             -Vertreter): Bandoberrand + HOENN_SCALING_BOSS_EXTRA.
//  - Artenzusammensetzung bleibt Vanilla - es skalieren NUR Level.
//    Basisformen bleiben fangbar und selbst entwickelbar.
//  - Gilt NUR in der Hoenn-Welt (Mapsection-Guard). Johto laeuft nach
//    denselben Regeln, aber mit eigener Datei (config/johto_scaling.h);
//    Kanto behaelt seine handgesetzte Levelleiter. Feste Event-/
//    Legendaren-Begegnungen, Roamer und die Kampfzone sind nicht
//    betroffen.
//  - Erfahrung: Ueberall dort, wo skaliert wird (Hoenn UND Johto),
//    gilt die Gen-5-Formel (gewichtet nach Leveldifferenz), damit die
//    Exp-Rueckkopplung des Scalings nicht explodiert. Kanto behaelt
//    die Gen-3-Formel.
// =====================================================================

#define HOENN_LEVEL_SCALING          TRUE  // Hauptschalter

#define HOENN_SCALING_TRAINER_BELOW  5     // Trainerband: Anker - 5 ...
#define HOENN_SCALING_TRAINER_ABOVE  3     // ... bis Anker + 3
#define HOENN_SCALING_WILD_BELOW     10    // Wildband: Anker - 10 ...
#define HOENN_SCALING_WILD_ABOVE     4     // ... bis Anker - 4
#define HOENN_SCALING_BOSS_EXTRA     2     // Boss-Ass: Anker + 3 + 2

// Trainer, deren Originalteam bereits auf oder ueber diesem Level liegt,
// sind bewusst gesetzte Superbosse (z. B. Troy/Steven in den Meteorfaellen,
// Level 75-78) und werden NICHT skaliert - wie Rot am Silberberg.
#define HOENN_SCALING_FIXED_MIN_LEVEL 70


// Trainer-Entwicklungsangleich: Trainerpokemon (NICHT Wildpokemon -
// dort bleibt die Fang-/Selbstentwicklungs-Logik unangetastet) werden
// beim Erzeugen entlang ihrer Entwicklungskette angehoben, solange
// das skalierte Level die jeweilige Schwelle erreicht. Ein Level-57-
// Waumpel eines Kaefersammlers wird so zu Papinella/Pudox statt zum
// Scheingegner. Stein-/Tausch-Entwicklungen nutzen die Ersatzschwelle.
// Verzweigungen (z. B. Waumpel) werden zufaellig gewaehlt.
#define HOENN_SCALING_TRAINER_EVOLVE TRUE
#define HOENN_SCALING_EVO_OTHER_LEVEL 36   // Schwelle fuer Stein/Tausch

#define HOENN_SCALING_MIN_LEVEL      5     // absolute Untergrenze
#define HOENN_SCALING_MAX_LEVEL      100   // absolute Obergrenze

// Korridor je Gebiet: {Mapsection, Boden, Deckel}. Der Boden haelt die
// Hoenn-ist-stark-Lore auch bei niedrigem Anker, der Deckel bewahrt
// das Gefaelle der Region (Route 101 wird nie Endgame-hart, die
// Siegesstrasse faellt nie unter ihr Niveau). Gebiete ohne Eintrag
// nutzen HOENN_SCALING_DEFAULT_FLOOR/CEILING.
#define HOENN_SCALING_DEFAULT_FLOOR    40
#define HOENN_SCALING_DEFAULT_CEILING  100

#define HOENN_SCALING_CORRIDORS \
    /* Stufe 1: Einstieg (40-65) */ \
    { MAPSEC_LITTLEROOT_TOWN,   40,  65 }, \
    { MAPSEC_OLDALE_TOWN,       40,  65 }, \
    /* Bluetenburg ist zwar frueh erreichbar, die Arena ist aber der \
       fuenfte Orden - und ausserhalb der Arena stehen dort keine \
       Trainer. Deshalb Stufe 3. */ \
    { MAPSEC_PETALBURG_CITY,    50,  85 }, \
    { MAPSEC_ROUTE_101,         40,  65 }, \
    { MAPSEC_ROUTE_102,         40,  65 }, \
    { MAPSEC_ROUTE_103,         40,  65 }, \
    { MAPSEC_ROUTE_104,         40,  65 }, \
    { MAPSEC_PETALBURG_WOODS,   40,  65 }, \
    { MAPSEC_ROUTE_116,         40,  65 }, \
    { MAPSEC_RUSTURF_TUNNEL,    40,  65 }, \
    { MAPSEC_RUSTBORO_CITY,     40,  65 }, \
    { MAPSEC_DEWFORD_TOWN,      40,  65 }, \
    { MAPSEC_ROUTE_105,         50,  85 }, \
    { MAPSEC_ROUTE_106,         40,  65 }, \
    { MAPSEC_ROUTE_107,         50,  85 }, \
    { MAPSEC_ROUTE_108,         50,  85 }, \
    { MAPSEC_GRANITE_CAVE,      40,  65 }, \
    /* Routen 105/107/108 und das Wrack sind erst mit dem Surfer \
       erreichbar (nach Normans Arena) - sie stehen deshalb in \
       Stufe 3, nicht beim fruehen Dewford-Block. */ \
    { MAPSEC_ABANDONED_SHIP,    50,  85 }, \
    /* Stufe 2: fruehe Mitte (45-75) */ \
    { MAPSEC_SLATEPORT_CITY,    45,  75 }, \
    { MAPSEC_ROUTE_109,         45,  75 }, \
    { MAPSEC_ROUTE_110,         45,  75 }, \
    { MAPSEC_MAUVILLE_CITY,     45,  75 }, \
    { MAPSEC_VERDANTURF_TOWN,   45,  75 }, \
    { MAPSEC_ROUTE_117,         45,  75 }, \
    { MAPSEC_ROUTE_118,         50,  85 }, \
    { MAPSEC_ROUTE_111,         50,  85 }, \
    { MAPSEC_ROUTE_112,         50,  85 }, \
    { MAPSEC_ROUTE_113,         45,  75 }, \
    { MAPSEC_FIERY_PATH,        50,  85 }, \
    { MAPSEC_FIERY_PATH2,       50,  85 }, \
    { MAPSEC_JAGGED_PASS,       50,  85 }, \
    { MAPSEC_JAGGED_PASS2,      50,  85 }, \
    /* Neu-Malvenfroh liegt hinter dem Wasser auf Route 110 - \
       ohne Surfer kommt man nicht hinein. */ \
    { MAPSEC_NEW_MAUVILLE,      50,  85 }, \
    { MAPSEC_MIRAGE_TOWER,      45,  75 }, \
    /* Stufe 3: spaete Mitte (50-85) */ \
    { MAPSEC_FALLARBOR_TOWN,    50,  85 }, \
    { MAPSEC_ROUTE_114,         50,  85 }, \
    { MAPSEC_ROUTE_115,         50,  85 }, \
    { MAPSEC_METEOR_FALLS,      50,  85 }, \
    { MAPSEC_METEOR_FALLS2,     50,  85 }, \
    { MAPSEC_MT_CHIMNEY,        50,  85 }, \
    { MAPSEC_LAVARIDGE_TOWN,    50,  85 }, \
    { MAPSEC_ROUTE_119,         50,  85 }, \
    { MAPSEC_ROUTE_120,         50,  85 }, \
    { MAPSEC_FORTREE_CITY,      50,  85 }, \
    { MAPSEC_SCORCHED_SLAB,     50,  85 }, \
    { MAPSEC_SAFARI_ZONE,       50,  85 }, \
    /* Stufe 4: Endstrecke (55-95) */ \
    { MAPSEC_ROUTE_121,         55,  95 }, \
    { MAPSEC_ROUTE_122,         55,  95 }, \
    { MAPSEC_ROUTE_123,         55,  95 }, \
    { MAPSEC_LILYCOVE_CITY,     55,  95 }, \
    { MAPSEC_MT_PYRE,           55,  95 }, \
    { MAPSEC_ROUTE_124,         55,  95 }, \
    { MAPSEC_ROUTE_125,         55,  95 }, \
    { MAPSEC_ROUTE_126,         55,  95 }, \
    { MAPSEC_ROUTE_127,         55,  95 }, \
    { MAPSEC_ROUTE_128,         55,  95 }, \
    { MAPSEC_UNDERWATER_124,    55,  95 }, \
    { MAPSEC_UNDERWATER_126,    55,  95 }, \
    { MAPSEC_UNDERWATER_127,    55,  95 }, \
    { MAPSEC_UNDERWATER_128,    55,  95 }, \
    { MAPSEC_MOSSDEEP_CITY,     55,  95 }, \
    { MAPSEC_SHOAL_CAVE,        55,  95 }, \
    { MAPSEC_AQUA_HIDEOUT,      55,  95 }, \
    { MAPSEC_AQUA_HIDEOUT_OLD,  55,  95 }, \
    { MAPSEC_MAGMA_HIDEOUT,     55,  95 }, \
    { MAPSEC_SEAFLOOR_CAVERN,   55,  95 }, \
    { MAPSEC_UNDERWATER_SEAFLOOR_CAVERN, 55, 95 }, \
    { MAPSEC_SOOTOPOLIS_CITY,   55,  95 }, \
    { MAPSEC_UNDERWATER_SOOTOPOLIS, 55, 95 }, \
    { MAPSEC_CAVE_OF_ORIGIN,    55,  95 }, \
    { MAPSEC_ROUTE_129,         55,  95 }, \
    { MAPSEC_ROUTE_130,         55,  95 }, \
    { MAPSEC_ROUTE_131,         55,  95 }, \
    { MAPSEC_ROUTE_132,         55,  95 }, \
    { MAPSEC_ROUTE_133,         55,  95 }, \
    { MAPSEC_ROUTE_134,         55,  95 }, \
    { MAPSEC_PACIFIDLOG_TOWN,   55,  95 }, \
    { MAPSEC_MIRAGE_ISLAND,     55,  95 }, \
    { MAPSEC_SEALED_CHAMBER,    55,  95 }, \
    { MAPSEC_UNDERWATER_SEALED_CHAMBER, 55, 95 }, \
    { MAPSEC_ISLAND_CAVE,       55,  95 }, \
    { MAPSEC_DESERT_RUINS,      55,  95 }, \
    { MAPSEC_ANCIENT_TOMB,      55,  95 }, \
    /* Stufe 5: Endgame (60-100) */ \
    { MAPSEC_VICTORY_ROAD,      60, 100 }, \
    { MAPSEC_EVER_GRANDE_CITY,  60, 100 }, \
    { MAPSEC_SKY_PILLAR,        60, 100 }, \
    { MAPSEC_DESERT_UNDERPASS,  60, 100 }, \
    { MAPSEC_ARTISAN_CAVE,      60, 100 }, \
    { MAPSEC_MARINE_CAVE,       60, 100 }, \
    { MAPSEC_UNDERWATER_MARINE_CAVE, 60, 100 }, \
    { MAPSEC_TERRA_CAVE,        60, 100 }, \
    { MAPSEC_ALTERING_CAVE,     60, 100 }, \
    { MAPSEC_NAVEL_ROCK,        60, 100 }, \
    { MAPSEC_UNDERWATER_105,    60, 100 }, \
    { MAPSEC_UNDERWATER_125,    60, 100 }, \
    { MAPSEC_UNDERWATER_129,    60, 100 },


// =====================================================================
// Globale Erfahrungs-Daempfung (gilt WELTWEIT, auch Johto/Kanto!)
// Ziel: Der Spieler soll das Basisspiel nicht mit Level 80-100
// abschliessen und in Hoenn nichts mehr zu leveln haben. Kurve nach
// Marcs Vorgabe: bis 30 zuegig (voll), 30-60 mittel, ab 60 zaeher -
// aber nie Stunden pro Level. Die Daempfung greift pro EMPFAENGER-
// Level: ein niedriges Teammitglied levelt weiter schnell, waehrend
// das hohe Ass gebremst wird.
// =====================================================================
#define EXP_DAMP_ENABLED             TRUE
#define EXP_DAMP_FAST_UNTIL          30    // bis hier: 100 %
#define EXP_DAMP_MID_UNTIL           60    // 31-60:
#define EXP_DAMP_MID_PERCENT         70    //   70 % Erfahrung
#define EXP_DAMP_HIGH_PERCENT        50    // ab 61: 50 % Erfahrung

#endif // GUARD_CONFIG_HOENN_SCALING_H
