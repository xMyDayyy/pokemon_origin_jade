#ifndef GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H
#define GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H

// =====================================================================
// Origin Jade - Reservierungsblock fuer Flags
//
// WOFUER
// Alle Flags, die Origin Jade selbst anlegt, kommen ab jetzt aus diesem
// Block. Nicht mehr hinten an flags_hns.h oder flags_hoenn_de.h
// anhaengen - genau daraus sind die bisherigen Kollisionen entstanden
// (Match Call gegen die Hoenn-Inhaltsflags, FRLG-Trainerflags gegen die
// Ordensflags).
//
// WARUM AUSSERHALB VON SaveBlock1
// SaveBlock1 ist voll: zwischen sizeof(struct SaveBlock1) und der
// Sektorgrenze liegen weniger als acht Byte. Der Block wird deshalb wie
// die FRLG-Flags nach SaveBlock3 umgeleitet (GetFlagPointer in
// src/event_data.c). Die Nummern 0x2000-0x21FF liegen bewusst in einem
// Loch zwischen den FRLG-Flags (0x1000-0x13FF) und den umgeleiteten
// FRLG-Trainerflags (ab 0x3400).
//
// AUFTEILUNG
// Erst nach Region in der Reihenfolge Kanto, Johto, Hoenn, dann
// regionsuebergreifend. Zwischen den Regionen stehen je 32 Reserveplaetze,
// damit ein Nachtrag in Kanto nicht alles dahinter verschiebt. Innerhalb
// einer Region frei nach Thema sortieren.
//
// REGELN
//  1. Neue Flags IMMER an das Ende des passenden Regionsabschnitts,
//     nie in die Luecke dahinter - die ist der Puffer.
//  2. Nummern nie wiederverwenden. Ein Flag, das wegfaellt, wird zu
//     FLAG_OJ_UNUSED_* umbenannt und bleibt stehen.
//  3. Nach jedem HnS-Merge tools/check_flags.py laufen lassen. Der
//     Pruefer loest alle Flags und Vars numerisch auf und meldet
//     Doppelbelegungen - der Compiler tut das nicht.
//  4. Laeuft ein Abschnitt voll, wird OJ_FLAGS_COUNT erhoeht und der
//     naechste Abschnitt nach hinten geschoben. Platz ist da: der
//     Block darf bis 0x33FF wachsen.
// =====================================================================

#define OJ_FLAGS_START              0x2000
#define OJ_FLAGS_COUNT              512
#define OJ_FLAGS_END                (OJ_FLAGS_START + OJ_FLAGS_COUNT - 1)
#define OJ_NUM_FLAG_BYTES           ((OJ_FLAGS_COUNT + 7) / 8)

// Abschnittsanfaenge als Offset auf OJ_FLAGS_START.
#define OJ_FLAGS_KANTO              (OJ_FLAGS_START + 0)    // 96 Plaetze
#define OJ_FLAGS_KANTO_SIZE         96
#define OJ_FLAGS_JOHTO              (OJ_FLAGS_START + 128)  // 160 Plaetze
#define OJ_FLAGS_JOHTO_SIZE         160
#define OJ_FLAGS_HOENN              (OJ_FLAGS_START + 320)  // 96 Plaetze
#define OJ_FLAGS_HOENN_SIZE         96
#define OJ_FLAGS_GLOBAL             (OJ_FLAGS_START + 448)  // 64 Plaetze
#define OJ_FLAGS_GLOBAL_SIZE        64

// ---------------------------------------------------------------------
// Kanto (OJ_FLAGS_KANTO + 0 bis + 95)
// ---------------------------------------------------------------------
// noch keine Eintraege

// ---------------------------------------------------------------------
// Johto (OJ_FLAGS_JOHTO + 0 bis + 159)
// ---------------------------------------------------------------------
// Gegenstueck zu FLAG_IS_HOENN_CHAMPION: gesetzt, sobald Lance gefallen
// ist. Ein eigenes Flag ist noetig, weil FLAG_SYS_GAME_CLEAR schon von
// der Kanto-Liga gesetzt wird - Johto koennte daran nicht erkennen, ob
// der Spieler auch hier Champion ist. Steuert Anruftexte und alles, was
// nach der Johto-Liga anders laufen soll.
#define FLAG_IS_JOHTO_CHAMPION                       (OJ_FLAGS_JOHTO + 0)

// ---------------------------------------------------------------------
// Hoenn (OJ_FLAGS_HOENN + 0 bis + 95)
// ---------------------------------------------------------------------
// Umgezogene Hoenn-Flags. Sie standen in flags_hns.h mit fest
// eingetragenen Nummern, die im HnS-Block fuer erweiterte Inhalte liegen -
// jede teilte sich ihre Adresse mit einem Johto-, Kanto- oder Sinjoh-Flag.
// Praktisch hiess das zum Beispiel: wer in Kanto Route 4 betrat, blendete
// in Hoenn Scott aus. Gefunden mit tools/check_flags.py.
//
// Die Hoenn-Seite zieht um, nicht die andere - so bleiben die HnS-Flags
// auf ihren Nummern und kuenftige Upstream-Merges kollidieren nicht.
// Der Umzug steht hier und nicht in flags_hoenn_de.h, weil dieser Header
// zuletzt eingebunden wird und der Hoenn-Block in SaveBlock1 keinen Platz
// mehr haette.
// lag auf FLAG_ITEM_GOLDENROD_UNDERGROUND_COIN_CASE
#undef  FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380   (OJ_FLAGS_HOENN + 0)
// lag auf FLAG_EXP_SHARE
#undef  FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE                  (OJ_FLAGS_HOENN + 1)
// lag auf FLAG_HIDE_MT_SILVER_2F_AZURE_FLUTE
#undef  FLAG_HIDE_MARINE_CAVE_KYOGRE
#define FLAG_HIDE_MARINE_CAVE_KYOGRE                         (OJ_FLAGS_HOENN + 2)
// lag auf FLAG_ROUTE50_ITEMBALL_1
#undef  FLAG_UNKNOWN_0x363
#define FLAG_UNKNOWN_0x363                                   (OJ_FLAGS_HOENN + 3)
// lag auf FLAG_SINJOHRUINS_ITEM_1
#undef  FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2  (OJ_FLAGS_HOENN + 4)
// lag auf FLAG_SINJOHRUINS_ITEM_2
#undef  FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
#define FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD                   (OJ_FLAGS_HOENN + 5)
// lag auf FLAG_SINJOHRUINS_ITEM_3
#undef  FLAG_HIDE_FANCLUB_OLD_LADY
#define FLAG_HIDE_FANCLUB_OLD_LADY                           (OJ_FLAGS_HOENN + 6)
// lag auf FLAG_SINJOHRUINS_ITEM_4
#undef  FLAG_HIDE_FANCLUB_BOY
#define FLAG_HIDE_FANCLUB_BOY                                (OJ_FLAGS_HOENN + 7)
// lag auf FLAG_VISITED_ROUTE10
#undef  FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON
#define FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON       (OJ_FLAGS_HOENN + 8)
// lag auf FLAG_VISITED_ROUTE4
#undef  FLAG_HIDE_MAUVILLE_CITY_SCOTT
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                        (OJ_FLAGS_HOENN + 9)
// lag auf FLAG_HIDE_ROUTE49_TM_ROCK_CLIMB
#undef  FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                       (OJ_FLAGS_HOENN + 10)
// lag auf FLAG_COMPLETED_TAUROS_TRADE
#undef  FLAG_HIDE_CHAMPIONS_ROOM_BIRCH
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                       (OJ_FLAGS_HOENN + 11)
// lag auf FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
#undef  FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                    (OJ_FLAGS_HOENN + 12)
// lag auf FLAG_ULAULA_MOVE_TUTOR_PAID
#undef  FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                    (OJ_FLAGS_HOENN + 13)
// lag auf FLAG_USED_TELEPORTER
#undef  FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS
#define FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS              (OJ_FLAGS_HOENN + 14)
// lag auf FLAG_HIDE_MT_SILVER_PC_MEARA
#undef  FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
#define FLAG_HIDE_METEOR_FALLS_TEAM_AQUA                     (OJ_FLAGS_HOENN + 15)
// lag auf FLAG_SINJOH_UNLOCK_MIGRATED
#undef  FLAG_HIDE_ROUTE_128_STEVEN
#define FLAG_HIDE_ROUTE_128_STEVEN                           (OJ_FLAGS_HOENN + 16)

// ---------------------------------------------------------------------
// Regionsuebergreifend (OJ_FLAGS_GLOBAL + 0 bis + 63)
// ---------------------------------------------------------------------
// noch keine Eintraege

#endif // GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H
