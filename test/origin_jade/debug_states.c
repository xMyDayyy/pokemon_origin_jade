#include "global.h"
#include "debug.h"
#include "event_data.h"
#include "item.h"
#include "pokedex.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "region_rule_oj.h"
#include "test/test.h"

// Debug menu states "Johto Test" and "Hoenn Test" (tools/make_debug_states.py),
// see docs/origin_jade/DECISIONS.md, D-050.

static u32 CountPcMons(void)
{
    u32 box, pos, count = 0;

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (pos = 0; pos < IN_BOX_COUNT; pos++)
        {
            if (GetBoxMonDataAt(box, pos, MON_DATA_SPECIES) != SPECIES_NONE)
                count++;
        }
    }
    return count;
}

// Level of the PC's Pokémon of this species, 0 if none.
static u32 GetPcMonLevel(u16 species)
{
    u32 box, pos;

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (pos = 0; pos < IN_BOX_COUNT; pos++)
        {
            if (GetBoxMonDataAt(box, pos, MON_DATA_SPECIES) == species)
                return GetLevelFromBoxMonExp(GetBoxedMonPtr(box, pos));
        }
    }
    return 0;
}

static bool32 IsPcMonUsable(u16 species)
{
    u32 box, pos;

    for (box = 0; box < TOTAL_BOXES_COUNT; box++)
    {
        for (pos = 0; pos < IN_BOX_COUNT; pos++)
        {
            if (GetBoxMonDataAt(box, pos, MON_DATA_SPECIES) == species)
            {
                return !GetBoxMonDataAt(box, pos, MON_DATA_IS_EGG)
                    && GetBoxMonDataAt(box, pos, MON_DATA_OT_ID) == READ_OTID_FROM_SAVE
                    && GetBoxMonDataAt(box, pos, MON_DATA_POKEBALL) == ITEM_POKE_BALL;
            }
        }
    }
    return FALSE;
}

static void ExpectPartyMon(u32 slot, u16 species, u32 level)
{
    EXPECT_EQ(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), species);
    EXPECT_EQ(GetMonData(&gPlayerParty[slot], MON_DATA_LEVEL), level);
}

TEST("Debug states: Johto Test is Kanto complete, Johto and Hoenn stay locked")
{
    u32 flag;

    Debug_SetJohtoTestState();

    // Every stage of the Kanto lines: the 151 and 34 babies and later evolutions.
    EXPECT_EQ(GetNationalPokedexCount(FLAG_GET_CAUGHT), 185);
    EXPECT_EQ(GetNationalPokedexCount(FLAG_GET_SEEN), 185);
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_PICHU), FLAG_GET_CAUGHT));
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_MAGNEZONE), FLAG_GET_CAUGHT));
    EXPECT(!GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_CHIKORITA), FLAG_GET_SEEN));

    // The 81 final stages of the 151: six in the party, the others in the PC.
    EXPECT_EQ(CountPartyMons(), PARTY_SIZE);
    ExpectPartyMon(0, SPECIES_CHARIZARD, 49);
    ExpectPartyMon(1, SPECIES_PIDGEOT, 43);
    EXPECT_EQ(CountPcMons(), 75);
    EXPECT_EQ(GetPcMonLevel(SPECIES_VENUSAUR), 32);    // level evolution
    EXPECT_EQ(GetPcMonLevel(SPECIES_VILEPLUME), 23);   // Leaf Stone: Gloom 21 + 2
    EXPECT_EQ(GetPcMonLevel(SPECIES_MEWTWO), 50);      // static battle
    EXPECT_EQ(GetPcMonLevel(SPECIES_GOLBAT), 22);
    EXPECT_EQ(GetPcMonLevel(SPECIES_PIDGEOTTO), 0);
    EXPECT_EQ(GetPcMonLevel(SPECIES_CROBAT), 0);
    EXPECT(IsPcMonUsable(SPECIES_DRAGONITE));

    // Every item obtainable in Kanto, purchases and repeatable sources once.
    EXPECT(CheckBagHasItem(ITEM_TM13, 1));             // Game Corner prize
    EXPECT(CheckBagHasItem(ITEM_FRESH_WATER, 1));      // vending machine
    EXPECT(CheckBagHasItem(ITEM_POKE_DOLL, 1));        // Celadon's department store
    EXPECT(CheckBagHasItem(ITEM_PREMIER_BALL, 1));     // mart bonus for ten balls
    EXPECT(CheckBagHasItem(ITEM_CHOICE_BAND, 1));      // Mom's savings
    EXPECT(CheckBagHasItem(ITEM_TAMATO_BERRY, 1));     // berry tree
    EXPECT(CheckBagHasItem(ITEM_LEEK, 1));             // held item of an in-game trade
    EXPECT(CheckBagHasItem(ITEM_HEART_SCALE, 1));      // Rock Smash find

    EXPECT(FlagGet(FLAG_IS_KANTO_CHAMPION));
    EXPECT(FlagGet(FLAG_SYS_GAME_CLEAR));
    for (flag = FLAG_BADGE01_GET; flag <= FLAG_BADGE08_GET; flag++)
        EXPECT(FlagGet(flag));
    EXPECT_EQ(VarGet(VAR_JOHTO_HANDOVER), 1);
    EXPECT(!IsRegionUnlocked(REGION_JOHTO));
    EXPECT(!IsRegionUnlocked(REGION_HOENN));
    EXPECT_EQ(VarGet(VAR_HOENN_TICKET_STATE), 0);
}

TEST("Debug states: Hoenn Test is Kanto and Johto complete, Troy waits in Oak's lab")
{
    u32 flag;

    // Mints switched off in the challenge menu.
    FlagSet(FLAG_MINTS_DISABLED);
    Debug_SetHoennTestState();

    // Every stage of the Kanto and Johto lines, Azurill and Wynaut included.
    EXPECT_EQ(GetNationalPokedexCount(FLAG_GET_CAUGHT), 282);
    EXPECT_EQ(GetNationalPokedexCount(FLAG_GET_SEEN), 282);
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_AZURILL), FLAG_GET_CAUGHT));
    EXPECT(GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TOGEKISS), FLAG_GET_CAUGHT));
    EXPECT(!GetSetPokedexFlag(SpeciesToNationalPokedexNum(SPECIES_TREECKO), FLAG_GET_SEEN));

    // The 142 final stages: six in the party, the others in the PC.
    EXPECT_EQ(CountPartyMons(), PARTY_SIZE);
    ExpectPartyMon(0, SPECIES_CHARIZARD, 70);
    ExpectPartyMon(1, SPECIES_MEGANIUM, 63);
    ExpectPartyMon(2, SPECIES_GYARADOS, 63);
    ExpectPartyMon(3, SPECIES_AMPHAROS, 62);
    ExpectPartyMon(4, SPECIES_NIDOKING, 60);
    ExpectPartyMon(5, SPECIES_ESPEON, 60);
    EXPECT_EQ(CountPcMons(), 136);
    EXPECT_EQ(GetPcMonLevel(SPECIES_CROBAT), 24);      // friendship: Golbat 22 + 2
    EXPECT_EQ(GetPcMonLevel(SPECIES_TYRANITAR), 55);   // level evolution
    EXPECT_EQ(GetPcMonLevel(SPECIES_HO_OH), 78);
    EXPECT_EQ(GetPcMonLevel(SPECIES_LUGIA), 80);
    EXPECT_EQ(GetPcMonLevel(SPECIES_VENUSAUR), 32);    // as in the Johto Test
    EXPECT_EQ(GetPcMonLevel(SPECIES_RAICHU), 44);      // the Johto Test's party
    EXPECT_EQ(GetPcMonLevel(SPECIES_GOLBAT), 0);
    EXPECT(IsPcMonUsable(SPECIES_CELEBI));

    // Map pickups collected, also HnS's Poké Ball objects and the fossils.
    EXPECT(FlagGet(FLAG_ITEM_ROUTE32_TM_BULLET_SEED));
    EXPECT(CheckBagHasItem(ITEM_TM_BULLET_SEED, 1));
    EXPECT(FlagGet(FLAG_ITEM_DOME_FOSSIL));
    EXPECT(CheckBagHasItem(ITEM_DOME_FOSSIL, 1));
    // Purchases and repeatable sources of both regions once.
    EXPECT(CheckBagHasItem(ITEM_TM13, 1));             // Celadon's Game Corner
    EXPECT(CheckBagHasItem(ITEM_TM_SUBSTITUTE, 1));    // Goldenrod's Game Corner
    EXPECT(CheckBagHasItem(ITEM_RAGE_CANDY_BAR, 1));   // Mahogany's merchant
    EXPECT(CheckBagHasItem(ITEM_MOOMOO_MILK, 1));      // Moomoo Farm
    EXPECT(CheckBagHasItem(ITEM_LOVE_BALL, 1));        // Kurt
    EXPECT(CheckBagHasItem(ITEM_SUN_STONE, 1));        // Bug-Catching Contest
    EXPECT(CheckBagHasItem(ITEM_LEPPA_BERRY, 1));      // berry tree
    EXPECT(CheckBagHasItem(ITEM_SHARP_BEAK, 1));       // phone trainer's gift
    EXPECT(CheckBagHasItem(ITEM_SALAC_BERRY, 1));      // Route 40 Trainer Hill prize
    // Challenge settings untouched; mints only while the option sells them.
    EXPECT(FlagGet(FLAG_MINTS_DISABLED));
    EXPECT(!CheckBagHasItem(ITEM_ADAMANT_MINT, 1));

    EXPECT(FlagGet(FLAG_IS_KANTO_CHAMPION));
    EXPECT(FlagGet(FLAG_IS_JOHTO_CHAMPION));
    EXPECT(FlagGet(FLAG_DEFEATED_RED));
    EXPECT(FlagGet(FLAG_CAUGHT_LUGIA));
    EXPECT(FlagGet(FLAG_CAUGHT_HO_OH));
    EXPECT(FlagGet(FLAG_CAUGHT_MEWTWO));
    EXPECT_EQ(VarGet(VAR_JOHTO_BADGES), 0xFF);
    for (flag = FLAG_BADGE09_GET; flag <= FLAG_BADGE16_GET; flag++)
        EXPECT(!FlagGet(flag));
    EXPECT(IsRegionUnlocked(REGION_JOHTO));
    EXPECT(!IsRegionUnlocked(REGION_HOENN));
    EXPECT_EQ(VarGet(VAR_HOENN_ARRIVAL_STATE), 0);

    // Troy's scene in Oak's lab is pending and the ticket fits into the bag.
    EXPECT_EQ(VarGet(VAR_HOENN_TICKET_STATE), 1);
    EXPECT(!CheckBagHasItem(ITEM_HOENN_TICKET, 1));
    EXPECT(CheckBagHasSpace(ITEM_HOENN_TICKET, 1));
    EXPECT(!CheckBagHasItem(ITEM_GS_BALL, 1));
}

TEST("Debug states: Hoenn Test holds Goldenrod's mints when the challenge option sells them")
{
    FlagClear(FLAG_MINTS_DISABLED);
    Debug_SetHoennTestState();

    EXPECT(!FlagGet(FLAG_MINTS_DISABLED));
    EXPECT(CheckBagHasItem(ITEM_ADAMANT_MINT, 1));
    EXPECT(CheckBagHasItem(ITEM_MIRROR_HERB, 1));
}
