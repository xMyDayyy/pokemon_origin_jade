#ifndef GUARD_CONSTANTS_LEGENDARIES_OJ_H
#define GUARD_CONSTANTS_LEGENDARIES_OJ_H

// One-time encounters that follow the legendary rules (see docs/origin_jade/DECISIONS.md, D-026).
// Scripts pass the id in VAR_0x8004. Ids index sLegendaries in src/legendaries_oj.c and are
// not saved; add new ones before LEGENDARY_COUNT.

// Kanto
#define LEGENDARY_ARTICUNO      0   // Seafoam Islands B4F
#define LEGENDARY_ZAPDOS        1   // Power Plant
#define LEGENDARY_MOLTRES       2   // Victory Road 4F
#define LEGENDARY_MEWTWO        3   // Cerulean Cave B1F
#define LEGENDARY_MEW           4   // Mt. Moon, hidden cave
// Johto
#define LEGENDARY_LUGIA         5   // Whirl Islands
#define LEGENDARY_HO_OH         6   // Tin Tower roof
#define LEGENDARY_CELEBI        7   // Ilex Forest shrine
#define LEGENDARY_SUICUNE       8   // Tin Tower 1F
#define LEGENDARY_DEOXYS        9   // Birth Island (HnS)
#define LEGENDARY_LAPRAS        10  // Union Cave B2F
#define LEGENDARY_RED_GYARADOS  11  // Lake of Rage
#define LEGENDARY_ENTEI         12  // roamer
#define LEGENDARY_RAIKOU        13  // roamer
// Hoenn
#define LEGENDARY_REGIROCK      14  // Desert Ruins
#define LEGENDARY_REGICE        15  // Island Cave
#define LEGENDARY_REGISTEEL     16  // Ancient Tomb
#define LEGENDARY_GROUDON       17  // Terra Cave
#define LEGENDARY_KYOGRE        18  // Marine Cave
#define LEGENDARY_RAYQUAZA      19  // Sky Pillar
#define LEGENDARY_LATIAS        20  // roamer, after the Hoenn title
#define LEGENDARY_LATIOS        21  // roamer, after the Hoenn title
#define LEGENDARY_COUNT         22

#endif // GUARD_CONSTANTS_LEGENDARIES_OJ_H
