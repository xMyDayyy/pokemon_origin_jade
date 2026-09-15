#ifndef GUARD_CONSTANTS_VARS_ORIGIN_JADE_H
#define GUARD_CONSTANTS_VARS_ORIGIN_JADE_H

// =====================================================================
// Origin Jade - Reservierungsblock fuer Vars
//
// Gegenstueck zu constants/flags_origin_jade.h; dieselben Regeln.
// Neue Vars von Origin Jade kommen aus diesem Block, nicht mehr hinten
// an vars_hoenn_de.h.
//
// Auch hier liegt der Speicher in SaveBlock3 (GetVarPointer in
// src/event_data.c), weil SaveBlock1 voll ist. Die Nummern 0x4300-0x437F
// liegen hinter den FRLG-Vars (0x4200-0x42BF) und weit vor den
// Spezialvars (0x8000).
//
// Aufteilung wie bei den Flags: Kanto, Johto, Hoenn, regionsuebergreifend,
// mit je acht Reserveplaetzen dazwischen. Vars kosten zwei Byte statt
// einem Bit, deshalb ist der Block kleiner - wer nur ein Ja/Nein braucht,
// nimmt ein Flag.
// =====================================================================

#define OJ_VARS_START               0x4300
#define OJ_VARS_COUNT               128
#define OJ_VARS_END                 (OJ_VARS_START + OJ_VARS_COUNT - 1)

#define OJ_VARS_KANTO               (OJ_VARS_START + 0)     // 24 Plaetze
#define OJ_VARS_KANTO_SIZE          24
#define OJ_VARS_JOHTO               (OJ_VARS_START + 32)    // 40 Plaetze
#define OJ_VARS_JOHTO_SIZE          40
#define OJ_VARS_HOENN               (OJ_VARS_START + 80)    // 24 Plaetze
#define OJ_VARS_HOENN_SIZE          24
#define OJ_VARS_GLOBAL              (OJ_VARS_START + 112)   // 16 Plaetze
#define OJ_VARS_GLOBAL_SIZE         16

// ---------------------------------------------------------------------
// Kanto (OJ_VARS_KANTO + 0 bis + 23)
// ---------------------------------------------------------------------
// noch keine Eintraege

// ---------------------------------------------------------------------
// Johto (OJ_VARS_JOHTO + 0 bis + 39)
// ---------------------------------------------------------------------
// VM-Befugnisse als Bitmaske, siehe include/johto_permits.h.
#define VAR_JOHTO_PERMITS           (OJ_VARS_JOHTO + 0)
// Kein VAR_JOHTO_BADGES hier: das gibt es seit dem Kanto-Merge schon in
// constants/vars_frlg_hns.h, und der Trainerpass liest es bereits aus.
// Gefuellt wird es erst jetzt (src/johto_badges.c).
// Stand der Anreise aus Kanto, Gegenstueck zu VAR_HOENN_ARRIVAL_STATE.
#define VAR_JOHTO_ARRIVAL_STATE     (OJ_VARS_JOHTO + 1)

// ---------------------------------------------------------------------
// Hoenn (OJ_VARS_HOENN + 0 bis + 23)
// ---------------------------------------------------------------------
// noch keine Eintraege

// ---------------------------------------------------------------------
// Regionsuebergreifend (OJ_VARS_GLOBAL + 0 bis + 15)
// ---------------------------------------------------------------------
// noch keine Eintraege

#endif // GUARD_CONSTANTS_VARS_ORIGIN_JADE_H
