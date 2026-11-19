#ifndef GUARD_CONFIG_LEVEL_REMAP_H
#define GUARD_CONFIG_LEVEL_REMAP_H

// =====================================================================
// Fixed levels (Balancing-Remake)
//
// Every wild and trainer Pokemon has a fixed level. Nothing depends on the
// player's party. Johto and Hoenn take the original game's level, scaled
// linearly per region at runtime:
//   Johto: HnS          3-56 -> 44-73 (above 56: 56-100 -> 73-100, post-game)
//   Hoenn: Emerald      3-58 -> 67-100 (above: 100)
// level = TO_LO + (level - FROM_LO) * (TO_HI - TO_LO) / (FROM_HI - FROM_LO),
// rounded, kept within 2..100.
// Kanto: the levels are written in the data (trainers_frlg.party: FireRed 5-63
// scaled to 5-47; wild_encounters.json as set by hand). VS Seeker rematches are
// raised to their tier's floor (src/vs_seeker.c).
// Scripted encounters, gifts and roamers keep their script levels.
// TRUE replaces the anchor scaling of config/hoenn_scaling.h, johto_scaling.h
// and kanto_scaling.h (their corridors and bands are no longer used).
// =====================================================================

#define LEVEL_REMAP                  TRUE  // master switch

// Kanto's formula, used to write trainers_frlg.party (not applied at runtime).
#define REMAP_KANTO_FROM_LO          5
#define REMAP_KANTO_FROM_HI          63
#define REMAP_KANTO_TO_LO            5
#define REMAP_KANTO_TO_HI            47

#define REMAP_JOHTO_FROM_LO          3
#define REMAP_JOHTO_FROM_HI          56
#define REMAP_JOHTO_TO_LO            44
#define REMAP_JOHTO_TO_HI            73

#define REMAP_HOENN_FROM_LO          3
#define REMAP_HOENN_FROM_HI          58
#define REMAP_HOENN_TO_LO            67
#define REMAP_HOENN_TO_HI            100

// Johto entry from Kanto (Route 26, Route 27, Tohjo Falls): the HnS levels stay,
// but never below this.
#define REMAP_JOHTO_ENTRY_MIN        38

// =====================================================================
// Experience (replaces EXP_DAMP_* of config/hoenn_scaling.h while LEVEL_REMAP is TRUE)
// =====================================================================
// Base factor by region (where the battle takes place), in percent.
#define REMAP_EXP_KANTO_LOW_UNTIL    20    // Kanto, receiving Pokemon up to this level:
#define REMAP_EXP_KANTO_LOW_PERCENT  100
#define REMAP_EXP_KANTO_PERCENT      71    // Kanto above it
#define REMAP_EXP_JOHTO_PERCENT      22
#define REMAP_EXP_HOENN_PERCENT      35    // also for maps outside the three regions

// Soft limit per Pokemon, measured against the defeated or caught Pokemon:
// more than ABOVE levels higher -> only ABOVE_PERCENT of the experience,
// more than BELOW levels lower -> no damping (from Kanto's third badge on).
#define REMAP_EXP_SOFT_ABOVE         4
#define REMAP_EXP_SOFT_ABOVE_PERCENT 25
#define REMAP_EXP_SOFT_BELOW         6

#endif // GUARD_CONFIG_LEVEL_REMAP_H
