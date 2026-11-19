#ifndef GUARD_REMATCHES_H
#define GUARD_REMATCHES_H

// Rows of gRematchTable (src/battle_setup.c), in PokeCom list order: the
// regions in play order (Kanto, Johto, Hoenn), then the special trainers.
// Each row's save bits sit in its region's slot range (RematchSlot,
// src/battle_setup.c; flags_rematch.h), so regions can grow independently.
// Within a region the slot is the row's position: only append to the end
// of a region, never insert or reorder rows.
enum {
    // Kanto phone trainers (route order). The first row gets
    // "= REMATCH_KANTO_START"; REMATCH_KANTO_END follows the last row.
    REMATCH_KANTO_START,
    REMATCH_YOUNGSTER_BEN = REMATCH_KANTO_START,
    REMATCH_BUG_CATCHER_COLTON,
    REMATCH_LASS_JANICE,
    REMATCH_LASS_CRISSY,
    REMATCH_YOUNGSTER_TIMMY,
    REMATCH_LASS_RELI,
    REMATCH_LASS_ALI,
    REMATCH_YOUNGSTER_CHAD,
    REMATCH_PICNICKER_KELSEY,
    REMATCH_HIKER_FRANKLIN,
    REMATCH_HIKER_NOB,
    REMATCH_CAMPER_RICKY,
    REMATCH_CAMPER_JEFF,
    REMATCH_PICNICKER_ISABELLE,
    REMATCH_YOUNGSTER_YASU,
    REMATCH_ENGINEER_BERNIE,
    REMATCH_GAMER_DARIAN,
    REMATCH_CAMPER_CHRIS,
    REMATCH_PICNICKER_ALICIA,
    REMATCH_HIKER_JEREMY,
    REMATCH_POKEMANIAC_MARK,
    REMATCH_POKEMANIAC_HERMAN,
    REMATCH_HIKER_TRENT,
    REMATCH_LASS_MEGAN,
    REMATCH_SUPER_NERD_GLENN,
    REMATCH_GAMER_RICH,
    REMATCH_TWINS_ELI_ANNE,
    REMATCH_BIKER_JAREN,
    REMATCH_FISHERMAN_ELLIOT,
    REMATCH_ROCKER_LUCA,
    REMATCH_YOUNG_COUPLE_GIA_JES,
    REMATCH_BEAUTY_SHEILA,
    REMATCH_BIRD_KEEPER_ROBERT,
    REMATCH_PICNICKER_SUSIE,
    REMATCH_BIKER_LUKAS,
    REMATCH_BIRD_KEEPER_BENNY,
    REMATCH_BIRD_KEEPER_CARTER,
    REMATCH_BIRD_KEEPER_MARLON,
    REMATCH_BEAUTY_GRACE,
    REMATCH_BIRD_KEEPER_CHESTER,
    REMATCH_PICNICKER_BECKY,
    REMATCH_CRUSH_KIN_RON_MYA,
    REMATCH_BIKER_RUBEN,
    REMATCH_CUE_BALL_CAMRON,
    REMATCH_YOUNG_COUPLE_LEA_JED,
    REMATCH_BIKER_JAXON,
    REMATCH_CUE_BALL_ISAIAH,
    REMATCH_CUE_BALL_COREY,
    REMATCH_BIRD_KEEPER_WILTON,
    REMATCH_BIRD_KEEPER_JACOB,
    REMATCH_SWIMMER_MALE_MATTHEW,
    REMATCH_SWIMMER_MALE_TONY,
    REMATCH_SWIMMER_FEMALE_ALICE,
    REMATCH_SWIMMER_MALE_DARRIN,
    REMATCH_SWIMMER_FEMALE_MELISSA,
    REMATCH_PICNICKER_MISSY,
    REMATCH_FISHERMAN_WADE,
    REMATCH_SIS_AND_BRO_LIL_IAN,
    REMATCH_SWIMMER_MALE_JACK,
    REMATCH_SWIMMER_MALE_ROLAND,
    REMATCH_KANTO_END,

    // Johto. The HnS phone trainers reuse the Emerald names of these slots.
    REMATCH_JOHTO_START = REMATCH_KANTO_END,
    REMATCH_ROSE = REMATCH_JOHTO_START,          // Joey
    REMATCH_ANDRES,                              // Wade
    REMATCH_DUSTY,                               // Ralph
    REMATCH_LOLA,                                // Liz
    REMATCH_RICKY,                               // Anthony
    REMATCH_LILA_AND_ROY,                        // Todd
    REMATCH_CRISTIN,                             // Gina
    REMATCH_BROOKE,                              // Irwin
    REMATCH_WILTON,                              // Arnie
    REMATCH_VALERIE,                             // Alan
    REMATCH_CINDY,                               // Dana
    REMATCH_THALIA,                              // Chad
    REMATCH_JESSICA,                             // Derek
    REMATCH_WINSTON,                             // Tully
    REMATCH_STEVE,                               // Brent
    REMATCH_TONY,                                // Tiffany
    REMATCH_NOB,                                 // Vance
    REMATCH_KOJI,                                // Wilton
    REMATCH_FERNANDO,                            // Kenji
    REMATCH_DALTON,                              // Parry
    REMATCH_BERNIE,                              // Erin
    REMATCH_ETHAN,                               // Jack
    REMATCH_JOHN_AND_JAY,                        // Beverly
    REMATCH_JEFFREY,                             // Huey
    REMATCH_CAMERON,                             // Gaven
    REMATCH_JACKI,                               // Beth
    REMATCH_WALTER,                              // Jose
    REMATCH_KAREN,                               // Reena
    REMATCH_JOHTO_END,

    // Hoenn. *_HOENN: names already taken by the Johto rows above.
    REMATCH_HOENN_START = REMATCH_JOHTO_END,
    REMATCH_JERRY = REMATCH_HOENN_START,
    REMATCH_ANNA_AND_MEG,
    REMATCH_ISABEL,
    REMATCH_MIGUEL,
    REMATCH_TIMOTHY,
    REMATCH_SHELBY,
    REMATCH_CALVIN,
    REMATCH_ELLIOT,
    REMATCH_ISAIAH,
    REMATCH_MARIA,
    REMATCH_ABIGAIL,
    REMATCH_DYLAN,
    REMATCH_KATELYN,
    REMATCH_BENJAMIN,
    REMATCH_PABLO,
    REMATCH_NICOLAS,
    REMATCH_ROBERT,
    REMATCH_LAO,
    REMATCH_CYNDY,
    REMATCH_MADELINE,
    REMATCH_JENNY,
    REMATCH_DIANA,
    REMATCH_AMY_AND_LIV,
    REMATCH_ERNEST,
    REMATCH_CORY,
    REMATCH_EDWIN,
    REMATCH_LYDIA,
    REMATCH_ISAAC,
    REMATCH_GABRIELLE,
    REMATCH_CATHERINE,
    REMATCH_JACKSON,
    REMATCH_HALEY,
    REMATCH_JAMES,
    REMATCH_TRENT,
    REMATCH_SAWYER,
    REMATCH_KIRA_AND_DAN,
    REMATCH_ROSE_HOENN,
    REMATCH_ANDRES_HOENN,
    REMATCH_DUSTY_HOENN,
    REMATCH_LOLA_HOENN,
    REMATCH_RICKY_HOENN,
    REMATCH_LILA_AND_ROY_HOENN,
    REMATCH_CRISTIN_HOENN,
    REMATCH_BROOKE_HOENN,
    REMATCH_WILTON_HOENN,
    REMATCH_VALERIE_HOENN,
    REMATCH_CINDY_HOENN,
    REMATCH_THALIA_HOENN,
    REMATCH_JESSICA_HOENN,
    REMATCH_WINSTON_HOENN,
    REMATCH_STEVE_HOENN,
    REMATCH_TONY_HOENN,
    REMATCH_NOB_HOENN,
    REMATCH_KOJI_HOENN,
    REMATCH_FERNANDO_HOENN,
    REMATCH_DALTON_HOENN,
    REMATCH_BERNIE_HOENN,
    REMATCH_ETHAN_HOENN,
    REMATCH_JOHN_AND_JAY_HOENN,
    REMATCH_JEFFREY_HOENN,
    REMATCH_CAMERON_HOENN,
    REMATCH_JACKI_HOENN,
    REMATCH_WALTER_HOENN,
    REMATCH_KAREN_HOENN,
    REMATCH_HOENN_END,

    // Special trainers: Wally, the Hoenn leaders and the Elite Four.
    REMATCH_WALLY_VR = REMATCH_HOENN_END, // Entries before WALLY are normal trainers, from WALLY on special trainers
    REMATCH_ROXANNE,
    REMATCH_BRAWLY,
    REMATCH_WATTSON,
    REMATCH_FLANNERY,
    REMATCH_NORMAN,
    REMATCH_WINONA,
    REMATCH_TATE_AND_LIZA,
    REMATCH_JUAN,
    REMATCH_SIDNEY, // Entries from SIDNEY on are REMATCH_ELITE_FOUR_ENTRIES.
    REMATCH_PHOEBE,
    REMATCH_GLACIA,
    REMATCH_DRAKE,
    REMATCH_WALLACE,
    REMATCH_TABLE_ENTRIES // The total number of rematch entries. Must be last in enum
};

#define REMATCH_SPECIAL_TRAINER_START   REMATCH_WALLY_VR
#define REMATCH_ELITE_FOUR_ENTRIES      REMATCH_SIDNEY

#endif // GUARD_REMATCHES_H
