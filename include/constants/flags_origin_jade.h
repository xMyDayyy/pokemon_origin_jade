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
// noch keine Eintraege

// ---------------------------------------------------------------------
// Hoenn (OJ_FLAGS_HOENN + 0 bis + 95)
// ---------------------------------------------------------------------
// noch keine Eintraege

// ---------------------------------------------------------------------
// Regionsuebergreifend (OJ_FLAGS_GLOBAL + 0 bis + 63)
// ---------------------------------------------------------------------
// noch keine Eintraege

#endif // GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H
