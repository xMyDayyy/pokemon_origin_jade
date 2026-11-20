#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen3[] =
{
#endif

#if P_FAMILY_TREECKO
    [SPECIES_TREECKO] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Geckarbor"),
#else
        .speciesName = _("TREECKO"),
#endif
        .cryId = CRY_TREECKO,
        .natDexNum = NATIONAL_DEX_TREECKO,
#if GERMAN
        .categoryName = _("Waldgecko"),
#else
        .categoryName = _("Wood Gecko"),
#endif
        .height = 5,
        .weight = 50,
        .description = COMPOUND_STRING(
#if GERMAN
        "Geckarbor baut in einem Riesenbaum sein\n"
        "Nest. Jeder Eindringling wird von ihm\n"
        "verjagt, daher nennt man es auch den\n"
        "Wächter der Bäume."),
#else
            "It makes its nest in a giant tree in the\n"
            "forest. It ferociously guards against\n"
            "anything nearing its territory. It is said\n"
            "to be the protector of the forest's trees."),
#endif
        .pokemonScale = 541,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Treecko,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Treecko,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Treecko,
        .shinyPalette = gMonShinyPalette_Treecko,
        .iconSprite = gMonIcon_Treecko,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, 4, SHADOW_SIZE_S)
        FOOTPRINT(Treecko)
        OVERWORLD(
            sPicTable_Treecko,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Treecko,
            gShinyOverworldPalette_Treecko
        )
        .levelUpLearnset = sTreeckoLevelUpLearnset,
        .teachableLearnset = sTreeckoTeachableLearnset,
        .eggMoveLearnset = sTreeckoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_GROVYLE}),
    },

    [SPECIES_GROVYLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 141,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Reptain"),
#else
        .speciesName = _("GROVYLE"),
#endif
        .cryId = CRY_GROVYLE,
        .natDexNum = NATIONAL_DEX_GROVYLE,
#if GERMAN
        .categoryName = _("Waldgecko"),
#else
        .categoryName = _("Wood Gecko"),
#endif
        .height = 9,
        .weight = 216,
        .description = COMPOUND_STRING(
#if GERMAN
            "Aus seinem Körper wachsen Blätter. Diese\n"
            "Blätter helfen ihm, sich vor Feinden im\n"
            "dichtbewachsenen Wald zu tarnen."),
#else
            "Leaves grow out of this Pokémon's body.\n"
            "They help obscure a Grovyle from the eyes\n"
            "of its enemies while it is in a thickly\n"
            "overgrown forest."),
#endif
        .pokemonScale = 360,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grovyle,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Grovyle,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Grovyle,
        .shinyPalette = gMonShinyPalette_Grovyle,
        .iconSprite = gMonIcon_Grovyle,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_M)
        FOOTPRINT(Grovyle)
        OVERWORLD(
            sPicTable_Grovyle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Grovyle,
            gShinyOverworldPalette_Grovyle
        )
        .levelUpLearnset = sGrovyleLevelUpLearnset,
        .teachableLearnset = sGrovyleTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SCEPTILE}),
    },

    [SPECIES_SCEPTILE] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 120,
        .baseSpAttack  = 105,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 208,
    #endif
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Gewaldro"),
#else
        .speciesName = _("SCEPTILE"),
#endif
        .cryId = CRY_SCEPTILE,
        .natDexNum = NATIONAL_DEX_SCEPTILE,
#if GERMAN
        .categoryName = _("Dschungel"),
#else
        .categoryName = _("Forest"),
#endif
        .height = 17,
        .weight = 522,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seine Kraft sucht im Dschungel ihres-\n"
            "gleichen. Gewaldro züchtet vorsichtig\n"
            "Bäume und Pflanzen. Es reguliert seine\n"
            "Körpertemperatur durch Sonnenlicht."),
#else
            "In the jungle, its power is without equal.\n"
            "This Pokémon carefully grows trees and\n"
            "plants. It regulates its body temperature\n"
            "by basking in sunlight."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 275,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Sceptile,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 26),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Sceptile,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Sceptile,
        .shinyPalette = gMonShinyPalette_Sceptile,
        .iconSprite = gMonIcon_Sceptile,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_L)
        FOOTPRINT(Sceptile)
        OVERWORLD(
            sPicTable_Sceptile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sceptile,
            gShinyOverworldPalette_Sceptile
        )
        .levelUpLearnset = sSceptileLevelUpLearnset,
        .teachableLearnset = sSceptileTeachableLearnset,
        .formSpeciesIdTable = sSceptileFormSpeciesIdTable,
        .formChangeTable = sSceptileFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_SCEPTILE_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 75,
        .baseSpeed     = 145,
        .baseSpAttack  = 145,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 315 : 284,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_LIGHTNING_ROD, ABILITY_LIGHTNING_ROD },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Gewaldro"),
#else
        .speciesName = _("SCEPTILE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SCEPTILE_MEGA,
    #else
        .cryId = CRY_SCEPTILE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SCEPTILE,
#if GERMAN
        .categoryName = _("Dschungel"),
#else
        .categoryName = _("Forest"),
#endif
        .height = 19,
        .weight = 552,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es schießt seine Schwanzspitze\n"
        "ab, indem es die Samen auf seinem Rücken,\n"
        "die von der Energie der Mega-Entwicklung\n"
        "erfüllt sind, explodieren lässt."),
#else
            "Thanks to the power in its quick legs,\n"
            "Mega Sceptile can be on its opponent in a\n"
            "flash. It can cut off a portion of its tail\n"
            "to fire it like a missile at an opponent."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 275,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_SceptileMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SceptileMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_SceptileMega,
        .shinyPalette = gMonShinyPalette_SceptileMega,
        .iconSprite = gMonIcon_SceptileMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 11, SHADOW_SIZE_L)
        FOOTPRINT(Sceptile)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SceptileMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SceptileMega,
            gShinyOverworldPalette_SceptileMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSceptileLevelUpLearnset,
        .teachableLearnset = sSceptileTeachableLearnset,
        .formSpeciesIdTable = sSceptileFormSpeciesIdTable,
        .formChangeTable = sSceptileFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_TREECKO

#if P_FAMILY_TORCHIC
    [SPECIES_TORCHIC] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 45,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 65,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Flemmli"),
#else
        .speciesName = _("TORCHIC"),
#endif
        .cryId = CRY_TORCHIC,
        .natDexNum = NATIONAL_DEX_TORCHIC,
#if GERMAN
        .categoryName = _("Küken"),
#else
        .categoryName = _("Chick"),
#endif
        .height = 4,
        .weight = 25,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei einem Angriff verteidigt es sich mit\n"
            "Feuerbällen, die es in seinem Magen formt.\n"
            "Flemmli mag die Dunkelheit nicht, weil\n"
            "es dort nichts sehen kann."),
#else
            "If attacked, it strikes back by spitting\n"
            "balls of fire it forms in its stomach.\n"
            "A Torchic dislikes darkness because it\n"
            "can't see its surroundings."),
#endif
        .pokemonScale = 566,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Torchic,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Torchic,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Torchic,
        .shinyPalette = gMonShinyPalette_Torchic,
        .iconSprite = gMonIcon_Torchic,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .backPicFemale = gMonBackPic_TorchicF,
        .backPicSizeFemale = MON_COORDS_SIZE(40, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Torchic)
        OVERWORLD(
            sPicTable_Torchic,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Torchic,
            gShinyOverworldPalette_Torchic
        )
        OVERWORLD_FEMALE(
            sPicTable_TorchicF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sTorchicLevelUpLearnset,
        .teachableLearnset = sTorchicTeachableLearnset,
        .eggMoveLearnset = sTorchicEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_COMBUSKEN}),
    },

    [SPECIES_COMBUSKEN] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 142,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Jungglut"),
#else
        .speciesName = _("COMBUSKEN"),
#endif
        .cryId = CRY_COMBUSKEN,
        .natDexNum = NATIONAL_DEX_COMBUSKEN,
#if GERMAN
        .categoryName = _("Jungvogel"),
#else
        .categoryName = _("Young Fowl"),
#endif
        .height = 9,
        .weight = 195,
        .description = COMPOUND_STRING(
#if GERMAN
        "Jungglut kann bis zu zehn Tritte pro\n"
        "Sekunde austeilen. Sein unbändiger\n"
        "Kampfeswille veranlasst ihn,\n"
        "weiterzukämpfen, bis der Gegner aufgibt."),
#else
            "It lashes out with 10 kicks per second.\n"
            "Its strong fighting instinct compels it\n"
            "to keep up its offensive until the\n"
            "opponent gives up."),
#endif
        .pokemonScale = 343,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Combusken,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 12),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Combusken,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Combusken,
        .shinyPalette = gMonShinyPalette_Combusken,
        .iconSprite = gMonIcon_Combusken,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_CombuskenF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 64),
        .backPicFemale = gMonBackPic_CombuskenF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Combusken)
        OVERWORLD(
            sPicTable_Combusken,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Combusken,
            gShinyOverworldPalette_Combusken
        )
        OVERWORLD_FEMALE(
            sPicTable_CombuskenF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sCombuskenLevelUpLearnset,
        .teachableLearnset = sCombuskenTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_BLAZIKEN}),
    },

    [SPECIES_BLAZIKEN] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FIGHTING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 209,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Lohgock"),
#else
        .speciesName = _("BLAZIKEN"),
#endif
        .cryId = CRY_BLAZIKEN,
        .natDexNum = NATIONAL_DEX_BLAZIKEN,
#if GERMAN
        .categoryName = _("Großbrand"),
#else
        .categoryName = _("Blaze"),
#endif
        .height = 19,
        .weight = 520,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es erlernt Kampfsportarten bei denen man\n"
        "Tritte und Faustschläge einsetzt. Alle\n"
        "paar Jahre verbrennen die Federn und\n"
        "neue, weiche Federn wachsen nach."),
#else
            "It learns martial arts that use punches\n"
            "and kicks. Every several years, its old\n"
            "feathers burn off, and new, supple\n"
            "feathers grow back in their place."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Blaziken,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Blaziken,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Blaziken,
        .shinyPalette = gMonShinyPalette_Blaziken,
        .shinyPaletteModern = gMonShinyPaletteModern_Blaziken,
        .iconSprite = gMonIcon_Blaziken,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_BlazikenF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 64),
        .backPicFemale = gMonBackPic_BlazikenF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_M)
        FOOTPRINT(Blaziken)
        OVERWORLD(
            sPicTable_Blaziken,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Blaziken,
            gShinyOverworldPalette_Blaziken,
            gShinyModernOverworldPalette_Blaziken
        )
        OVERWORLD_FEMALE(
            sPicTable_BlazikenF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sBlazikenLevelUpLearnset,
        .teachableLearnset = sBlazikenTeachableLearnset,
        .formSpeciesIdTable = sBlazikenFormSpeciesIdTable,
        .formChangeTable = sBlazikenFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_BLAZIKEN_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 160,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 130,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 315 : 284,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SPEED_BOOST, ABILITY_SPEED_BOOST, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Lohgock"),
#else
        .speciesName = _("BLAZIKEN"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_BLAZIKEN_MEGA,
    #else
        .cryId = CRY_BLAZIKEN,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_BLAZIKEN,
#if GERMAN
        .categoryName = _("Großbrand"),
#else
        .categoryName = _("Blaze"),
#endif
        .height = 19,
        .weight = 520,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kochendes Blut fließt durch seinen ganzen\n"
        "Körper und verdoppelt die Präzision seiner\n"
        "Attacken. Gegner bezwingt es im\n"
        "Handumdrehen."),
#else
            "As it unleashes a flurry of savage kicks,\n"
            "its legs can begin to burn from the\n"
            "friction of the surrounding atmosphere.\n"
            "They're always a source of pride to it."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_BlazikenMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_BlazikenMega,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_BlazikenMega,
        .shinyPalette = gMonShinyPalette_BlazikenMega,
        .iconSprite = gMonIcon_BlazikenMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Blaziken)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_BlazikenMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BlazikenMega,
            gShinyOverworldPalette_BlazikenMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sBlazikenLevelUpLearnset,
        .teachableLearnset = sBlazikenTeachableLearnset,
        .formSpeciesIdTable = sBlazikenFormSpeciesIdTable,
        .formChangeTable = sBlazikenFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_TORCHIC

#if P_FAMILY_MUDKIP
    [SPECIES_MUDKIP] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 65,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Hydropi"),
#else
        .speciesName = _("MUDKIP"),
#endif
        .cryId = CRY_MUDKIP,
        .natDexNum = NATIONAL_DEX_MUDKIP,
#if GERMAN
        .categoryName = _("Lehmhüpfer"),
#else
        .categoryName = _("Mud Fish"),
#endif
        .height = 4,
        .weight = 76,
        .description = COMPOUND_STRING(
#if GERMAN
        "An Land kann es große Felsen\n"
        "heben, indem es seine vier Füße unter\n"
        "den Felsen bringt und ihn dann anhebt.\n"
        "Es schläft eingegraben am Flussufer."),
#else
            "On land, it can powerfully lift large\n"
            "boulders by planting its four feet and\n"
            "heaving. It sleeps by burying itself in soil\n"
            "at the water's edge."),
#endif
        .pokemonScale = 535,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mudkip,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 13),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Mudkip,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Mudkip,
        .shinyPalette = gMonShinyPalette_Mudkip,
        .iconSprite = gMonIcon_Mudkip,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Mudkip)
        OVERWORLD(
            sPicTable_Mudkip,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mudkip,
            gShinyOverworldPalette_Mudkip
        )
        .levelUpLearnset = sMudkipLevelUpLearnset,
        .teachableLearnset = sMudkipTeachableLearnset,
        .eggMoveLearnset = sMudkipEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_MARSHTOMP}),
    },

    [SPECIES_MARSHTOMP] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 143,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Moorabbel"),
#else
        .speciesName = _("MARSHTOMP"),
#endif
        .cryId = CRY_MARSHTOMP,
        .natDexNum = NATIONAL_DEX_MARSHTOMP,
#if GERMAN
        .categoryName = _("Lehmhüpfer"),
#else
        .categoryName = _("Mud Fish"),
#endif
        .height = 7,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es starken Hinterbeine ermöglichen es\n"
        "ihm, aufrecht zu stehen. Da das\n"
        "Austrocknen seiner Haut eine Schwächung\n"
        "bedeutet, spielt es gerne im Schlamm."),
#else
            "Its toughened hind legs enable it to stand\n"
            "upright. Because it weakens if its skin\n"
            "dries out, it replenishes fluids by playing\n"
            "in mud."),
#endif
        .pokemonScale = 340,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Marshtomp,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SLIDE : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Marshtomp,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Marshtomp,
        .shinyPalette = gMonShinyPalette_Marshtomp,
        .iconSprite = gMonIcon_Marshtomp,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 7, SHADOW_SIZE_M)
        FOOTPRINT(Marshtomp)
        OVERWORLD(
            sPicTable_Marshtomp,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Marshtomp,
            gShinyOverworldPalette_Marshtomp
        )
        .levelUpLearnset = sMarshtompLevelUpLearnset,
        .teachableLearnset = sMarshtompTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SWAMPERT}),
    },

    [SPECIES_SWAMPERT] =
    {
        .baseHP        = 100,
        .baseAttack    = 110,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 268,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 241,
    #else
        .expYield = 210,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Sumpex"),
#else
        .speciesName = _("SWAMPERT"),
#endif
        .cryId = CRY_SWAMPERT,
        .natDexNum = NATIONAL_DEX_SWAMPERT,
#if GERMAN
        .categoryName = _("Lehmhüpfer"),
#else
        .categoryName = _("Mud Fish"),
#endif
        .height = 15,
        .weight = 819,
        .description = COMPOUND_STRING(
#if GERMAN
            "Spürt es einen Sturm oder eine Flutwelle\n"
            "kommen, versucht es sein Nest am Ufer\n"
            "mit Felsen zu schützen. Es schwimmt\n"
            "so schnell wie ein Jetski."),
#else
            "If it senses the approach of a storm and\n"
            "a tidal wave, it protects its seaside nest\n"
            "by piling up boulders. It swims as fast as\n"
            "a jet ski."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swampert,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 18),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_JUMPS_BIG : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Swampert,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Swampert,
        .shinyPalette = gMonShinyPalette_Swampert,
        .iconSprite = gMonIcon_Swampert,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 7, SHADOW_SIZE_L)
        FOOTPRINT(Swampert)
        OVERWORLD(
            sPicTable_Swampert,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Swampert,
            gShinyOverworldPalette_Swampert
        )
        .levelUpLearnset = sSwampertLevelUpLearnset,
        .teachableLearnset = sSwampertTeachableLearnset,
        .formSpeciesIdTable = sSwampertFormSpeciesIdTable,
        .formChangeTable = sSwampertFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_SWAMPERT_MEGA] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 110,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 318 : 286,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_SWIFT_SWIM, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Sumpex"),
#else
        .speciesName = _("SWAMPERT"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SWAMPERT_MEGA,
    #else
        .cryId = CRY_SWAMPERT,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SWAMPERT,
#if GERMAN
        .categoryName = _("Lehmhüpfer"),
#else
        .categoryName = _("Mud Fish"),
#endif
        .height = 19,
        .weight = 1020,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seine bereits aufgepumpten Muskeln\n"
        "werden vom Wasser in seinem Körper nach\n"
        "dem Prinzip einer Hydraulikpumpe noch\n"
        "weiter verstärkt."),
#else
            "When it Mega Evolves, the strength that it\n"
            "needs to act in the water is increased.\n"
            "It can use its tenacious power\n"
            "both on land and in the water."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SwampertMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SwampertMega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_SwampertMega,
        .shinyPalette = gMonShinyPalette_SwampertMega,
        .iconSprite = gMonIcon_SwampertMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Swampert)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SwampertMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SwampertMega,
            gShinyOverworldPalette_SwampertMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSwampertLevelUpLearnset,
        .teachableLearnset = sSwampertTeachableLearnset,
        .formSpeciesIdTable = sSwampertFormSpeciesIdTable,
        .formChangeTable = sSwampertFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MUDKIP

#if P_FAMILY_POOCHYENA
    [SPECIES_POOCHYENA] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 35,
        .baseSpeed     = 35,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 255,
    #if P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 56,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 44,
    #else
        .expYield = 55,
    #endif
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_RUN_AWAY, ABILITY_QUICK_FEET, ABILITY_RATTLED },
    #else
        .abilities = { ABILITY_RUN_AWAY, ABILITY_NONE, ABILITY_RATTLED },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Fiffyen"),
#else
        .speciesName = _("POOCHYENA"),
#endif
        .cryId = CRY_POOCHYENA,
        .natDexNum = NATIONAL_DEX_POOCHYENA,
#if GERMAN
        .categoryName = _("Biss"),
#else
        .categoryName = _("Bite"),
#endif
        .height = 5,
        .weight = 136,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es bedroht seine Feinde mit gefletschten\n"
        "Zähnen. Fliehenden Gegnern hetzt\n"
        "es nach. Fiffyen macht auf der Stelle\n"
        "kehrt, wenn der Gegner zurückschlägt."),
#else
            "It savagely threatens foes with bared\n"
            "fangs. It chases after fleeing targets\n"
            "tenaciously. It turns tail and runs,\n"
            "however, if the foe strikes back."),
#endif
        .pokemonScale = 481,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Poochyena,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Poochyena,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Poochyena,
        .shinyPalette = gMonShinyPalette_Poochyena,
        .iconSprite = gMonIcon_Poochyena,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_M)
        FOOTPRINT(Poochyena)
        OVERWORLD(
            sPicTable_Poochyena,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Poochyena,
            gShinyOverworldPalette_Poochyena
        )
        .levelUpLearnset = sPoochyenaLevelUpLearnset,
        .teachableLearnset = sPoochyenaTeachableLearnset,
        .eggMoveLearnset = sPoochyenaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_MIGHTYENA}),
    },

    [SPECIES_MIGHTYENA] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 127,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 128,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INTIMIDATE, ABILITY_QUICK_FEET, ABILITY_MOXIE },
    #else
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_MOXIE },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Magnayen"),
#else
        .speciesName = _("MIGHTYENA"),
#endif
        .cryId = CRY_MIGHTYENA,
        .natDexNum = NATIONAL_DEX_MIGHTYENA,
#if GERMAN
        .categoryName = _("Biss"),
#else
        .categoryName = _("Bite"),
#endif
        .height = 10,
        .weight = 370,
        .description = COMPOUND_STRING(
#if GERMAN
            "Magnayen leben in der Wildnis im Rudel.\n"
            "Sie gehorchen stets den Anordnungen des\n"
            "Rudelführers. Beim Erlegen von Feinden\n"
            "arbeiten sie perfekt zusammen."),
#else
            "In the wild, Mightyena live in a pack.\n"
            "They never defy their leader's orders.\n"
            "They defeat foes with perfectly\n"
            "coordinated teamwork."),
#endif
        .pokemonScale = 362,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mightyena,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Mightyena,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Mightyena,
        .shinyPalette = gMonShinyPalette_Mightyena,
        .iconSprite = gMonIcon_Mightyena,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 6, SHADOW_SIZE_L)
        FOOTPRINT(Mightyena)
        OVERWORLD(
            sPicTable_Mightyena,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mightyena,
            gShinyOverworldPalette_Mightyena
        )
        .levelUpLearnset = sMightyenaLevelUpLearnset,
        .teachableLearnset = sMightyenaTeachableLearnset,
    },
#endif //P_FAMILY_POOCHYENA

#if P_FAMILY_ZIGZAGOON
    [SPECIES_ZIGZAGOON] =
    {
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 41,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 41,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
    #if P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 56,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 48,
    #else
        .expYield = 60,
    #endif
        .evYield_Speed = 1,
        .itemCommon = ITEM_POTION,
        .itemRare = ITEM_REVIVE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_PICKUP, ABILITY_GLUTTONY, ABILITY_QUICK_FEET },
    #else
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_QUICK_FEET },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Zigzachs"),
#else
        .speciesName = _("ZIGZAGOON"),
#endif
        .cryId = CRY_ZIGZAGOON,
        .natDexNum = NATIONAL_DEX_ZIGZAGOON,
#if GERMAN
        .categoryName = _("Kleindachs"),
#else
        .categoryName = _("Tiny Raccoon"),
#endif
        .height = 4,
        .weight = 175,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zigzachs sucht ständig mit der Nase auf\n"
            "dem Boden nach etwas. Man erkennt es an\n"
            "den Fußspuren, die es im Zickzackmuster\n"
            "hinterlässt."),
#else
            "Rubbing its nose against the ground, it\n"
            "always wanders about back and forth in\n"
            "search of something. It is distinguished\n"
            "by the zigzag footprints it leaves."),
#endif
        .pokemonScale = 560,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Zigzagoon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Zigzagoon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Zigzagoon,
        .shinyPalette = gMonShinyPalette_Zigzagoon,
        .iconSprite = gMonIcon_Zigzagoon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-4, 0, SHADOW_SIZE_M)
        FOOTPRINT(Zigzagoon)
        OVERWORLD(
            sPicTable_Zigzagoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zigzagoon,
            gShinyOverworldPalette_Zigzagoon
        )
        .levelUpLearnset = sZigzagoonLevelUpLearnset,
        .teachableLearnset = sZigzagoonTeachableLearnset,
        .eggMoveLearnset = sZigzagoonEggMoveLearnset,
        .formSpeciesIdTable = sZigzagoonFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_LINOONE}),
    },

    [SPECIES_LINOONE] =
    {
        .baseHP        = 78,
        .baseAttack    = 70,
        .baseDefense   = 61,
        .baseSpeed     = 100,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 128,
        .evYield_Speed = 2,
        .itemCommon = ITEM_POTION,
        .itemRare = ITEM_MAX_REVIVE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_PICKUP, ABILITY_GLUTTONY, ABILITY_QUICK_FEET },
    #else
        .abilities = { ABILITY_PICKUP, ABILITY_NONE, ABILITY_QUICK_FEET },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Geradaks"),
#else
        .speciesName = _("LINOONE"),
#endif
        .cryId = CRY_LINOONE,
        .natDexNum = NATIONAL_DEX_LINOONE,
#if GERMAN
        .categoryName = _("Sprinter"),
#else
        .categoryName = _("Rushing"),
#endif
        .height = 5,
        .weight = 325,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wenn es nur geradeaus rennen muss, ist es\n"
            "sehr schnell. Sieht es im Teich Beute, die\n"
            "unter Wasser ist, springt es hinein\n"
            "und erlegt sie mit seinen scharfen Klauen."),
#else
            "It is exceedingly fast if it only has to run\n"
            "in a straight line. When it spots pond-\n"
            "dwelling prey underwater, it quickly leaps\n"
            "in and catches it with its sharp claws."),
#endif
        .pokemonScale = 321,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Linoone,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Linoone,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Linoone,
        .shinyPalette = gMonShinyPalette_Linoone,
        .iconSprite = gMonIcon_Linoone,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-6, 0, SHADOW_SIZE_L)
        FOOTPRINT(Linoone)
        OVERWORLD(
            sPicTable_Linoone,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Linoone,
            gShinyOverworldPalette_Linoone
        )
        .levelUpLearnset = sLinooneLevelUpLearnset,
        .teachableLearnset = sLinooneTeachableLearnset,
        .formSpeciesIdTable = sLinooneFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_ZIGZAGOON_GALAR] =
    {
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 41,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 41,
        .types = MON_TYPES(TYPE_DARK, TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PICKUP, ABILITY_GLUTTONY, ABILITY_QUICK_FEET },
        .bodyColor = BODY_COLOR_WHITE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Zigzachs-G"),
#else
        .speciesName = _("ZIGZAGOON-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Zigzachs"),
#else
        .speciesName = _("ZIGZAGOON"),
#endif
#endif
        .cryId = CRY_ZIGZAGOON,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_ZIGZAGOON_GALAR,
#else
        .natDexNum = NATIONAL_DEX_ZIGZAGOON,
#endif
#if GERMAN
        .categoryName = _("Kleindachs"),
#else
        .categoryName = _("Tiny Raccoon"),
#endif
        .height = 4,
        .weight = 175,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es tollt rastlos umher. Begegnet es einem\n"
        "anderen Pokémon, rempelt es dieses\n"
        "absichtlich an, um einen Streit\n"
        "anzuzetteln."),
#else
            "Its restlessness has it constantly moving\n"
            "in zigzags. It will purposely run into other\n"
            "Pokémon to start fights. It's thought to\n"
            "be the oldest form of Zigzagoon."),
#endif
        .pokemonScale = 560,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ZigzagoonGalar,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZigzagoonGalar,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZigzagoonGalar,
        .shinyPalette = gMonShinyPalette_ZigzagoonGalar,
        .iconSprite = gMonIcon_ZigzagoonGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-5, 0, SHADOW_SIZE_M)
        FOOTPRINT(Zigzagoon)
        OVERWORLD(
            sPicTable_ZigzagoonGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZigzagoonGalar,
            gShinyOverworldPalette_ZigzagoonGalar
        )
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sZigzagoonGalarLevelUpLearnset,
        .teachableLearnset = sZigzagoonGalarTeachableLearnset,
        .eggMoveLearnset = sZigzagoonGalarEggMoveLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sZigzagoonGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sZigzagoonFormSpeciesIdTable,
#endif
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_LINOONE_GALAR}),
    },

    [SPECIES_LINOONE_GALAR] =
    {
        .baseHP        = 78,
        .baseAttack    = 70,
        .baseDefense   = 61,
        .baseSpeed     = 100,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        .types = MON_TYPES(TYPE_DARK, TYPE_NORMAL),
        .catchRate = 90,
        .expYield = 147,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_PICKUP, ABILITY_GLUTTONY, ABILITY_QUICK_FEET },
        .bodyColor = BODY_COLOR_WHITE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Geradaks-G"),
#else
        .speciesName = _("LINOONE-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Geradaks"),
#else
        .speciesName = _("LINOONE"),
#endif
#endif
        .cryId = CRY_LINOONE,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_LINOONE_GALAR,
#else
        .natDexNum = NATIONAL_DEX_LINOONE,
#endif
#if GERMAN
        .categoryName = _("Sprinter"),
#else
        .categoryName = _("Rushing"),
#endif
        .height = 5,
        .weight = 325,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit seiner langen Zunge provoziert\n"
        "es seine Beute, bis diese vor Wut kocht.\n"
        "Danach rammt es sie mit voller Wucht."),
#else
            "This very aggressive Pokémon will\n"
            "recklessly challenge opponents stronger\n"
            "than itself. It uses its long tongue to\n"
            "taunt them to then tackle forcefully."),
#endif
        .pokemonScale = 321,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LinooneGalar,
        .frontPicSize = MON_COORDS_SIZE(64, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_LinooneGalar,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_LinooneGalar,
        .shinyPalette = gMonShinyPalette_LinooneGalar,
        .iconSprite = gMonIcon_LinooneGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-4, 0, SHADOW_SIZE_L)
        FOOTPRINT(Linoone)
        OVERWORLD(
            sPicTable_LinooneGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_LinooneGalar,
            gShinyOverworldPalette_LinooneGalar
        )
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sLinooneGalarLevelUpLearnset,
        .teachableLearnset = sLinooneGalarTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sLinooneGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sLinooneFormSpeciesIdTable,
#endif
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_OBSTAGOON, CONDITIONS({IF_TIME, TIME_NIGHT})}),
    },

    [SPECIES_OBSTAGOON] =
    {
        .dexNotRequired = TRUE,
        .baseHP        = 93,
        .baseAttack    = 90,
        .baseDefense   = 101,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 81,
        .types = MON_TYPES(TYPE_DARK, TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 260,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RECKLESS, ABILITY_GUTS, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Barrikadax"),
#else
        .speciesName = _("OBSTAGOON"),
#endif
        .cryId = CRY_OBSTAGOON,
        .natDexNum = NATIONAL_DEX_OBSTAGOON,
#if GERMAN
        .categoryName = _("Barrikade"),
#else
        .categoryName = _("Blocking"),
#endif
        .height = 16,
        .weight = 460,
        .description = COMPOUND_STRING(
#if GERMAN
        "Barrikadax verfügt über\n"
        "eine beeindruckende Stimmkraft. Sein\n"
        "von Schreien begleitetes Drohverhalten\n"
        "nennt man auch “Abblocker“."),
#else
            "Its voice is staggering in volume.\n"
            "Obstagoon has a tendency to take on a\n"
            "threatening posture and shout--this move\n"
            "is known as Obstruct."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Obstagoon,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Obstagoon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Obstagoon,
        .shinyPalette = gMonShinyPalette_Obstagoon,
        .iconSprite = gMonIcon_Obstagoon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_M)
        FOOTPRINT(Obstagoon)
        OVERWORLD(
            sPicTable_Obstagoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Obstagoon,
            gShinyOverworldPalette_Obstagoon
        )
        .levelUpLearnset = sObstagoonLevelUpLearnset,
        .teachableLearnset = sObstagoonTeachableLearnset,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_ZIGZAGOON

#if P_FAMILY_WURMPLE
    [SPECIES_WURMPLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 20,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 255,
    #if P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 56,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 39,
    #else
        .expYield = 54,
    #endif
        .evYield_HP = 1,
        .itemCommon = ITEM_PECHA_BERRY,
        .itemRare = ITEM_BRIGHT_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Waumpel"),
#else
        .speciesName = _("WURMPLE"),
#endif
        .cryId = CRY_WURMPLE,
        .natDexNum = NATIONAL_DEX_WURMPLE,
#if GERMAN
        .categoryName = _("Wurm"),
#else
        .categoryName = _("Worm"),
#endif
        .height = 3,
        .weight = 36,
        .description = COMPOUND_STRING(
#if GERMAN
        "Waumpel haftet an Ästen und frisst\n"
        "die Blätter. Der Faden, den es ausspuckt,\n"
        "wird an der Luft klebrig und schränkt\n"
        "den Bewegungsfreiraum des Gegners ein."),
#else
            "It sticks to tree branches and eats\n"
            "leaves. The thread it spits from its mouth,\n"
            "which becomes gooey when it touches\n"
            "air, slows the movement of its foes."),
#endif
        .pokemonScale = 711,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wurmple,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wurmple,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Wurmple,
        .shinyPalette = gMonShinyPalette_Wurmple,
        .iconSprite = gMonIcon_Wurmple,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Wurmple)
        OVERWORLD(
            sPicTable_Wurmple,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Wurmple,
            gShinyOverworldPalette_Wurmple
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sWurmpleLevelUpLearnset,
        .teachableLearnset = sWurmpleTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 7, SPECIES_SILCOON, CONDITIONS({IF_PID_UPPER_MODULO_10_GT, 4})},
                                {EVO_LEVEL, 7, SPECIES_CASCOON, CONDITIONS({IF_PID_UPPER_MODULO_10_LT, 5})}),
    },

    [SPECIES_SILCOON] =
    {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 55,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_4) ? 72 : 71,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Schaloko"),
#else
        .speciesName = _("SILCOON"),
#endif
        .cryId = CRY_SILCOON,
        .natDexNum = NATIONAL_DEX_SILCOON,
#if GERMAN
        .categoryName = _("Kokon"),
#else
        .categoryName = _("Cocoon"),
#endif
        .height = 6,
        .weight = 100,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es bereitet sich auf die Entwicklung vor\n"
        "und nutzt dabei die Energie, die es als\n"
        "Waumpel gespeichert hat. Mit seinen\n"
        "beiden Augen beobachtet es die Umgebung."),
#else
            "It prepares for evolution using the\n"
            "energy it stored while it was a Wurmple.\n"
            "It keeps watch over the surroundings with\n"
            "its two eyes."),
#endif
        .pokemonScale = 431,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Silcoon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Silcoon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 21 : 13,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Silcoon,
        .shinyPalette = gMonShinyPalette_Silcoon,
        .iconSprite = gMonIcon_Silcoon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -4, SHADOW_SIZE_M)
        FOOTPRINT(Silcoon)
        OVERWORLD(
            sPicTable_Silcoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Silcoon,
            gShinyOverworldPalette_Silcoon
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sSilcoonLevelUpLearnset,
        .teachableLearnset = sSilcoonTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_BEAUTIFLY}),
    },

    [SPECIES_BEAUTIFLY] =
    {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_6 ? 100 : 90,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 198,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 178,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 173,
    #else
        .expYield = 161,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Papinella"),
#else
        .speciesName = _("BEAUTIFLY"),
#endif
        .cryId = CRY_BEAUTIFLY,
        .natDexNum = NATIONAL_DEX_BEAUTIFLY,
#if GERMAN
        .categoryName = _("Falter"),
#else
        .categoryName = _("Butterfly"),
#endif
        .height = 10,
        .weight = 284,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seine Kennzeichen sind\n"
        "die bunt bemusterten Flügel. Papinella\n"
        "fliegt durch blumenübersäte Wiesen und\n"
        "sammelt Blütenstaub. Es greift brutal an."),
#else
            "Its colorfully patterned wings are its\n"
            "most prominent feature. It flies through\n"
            "flower-covered fields collecting pollen.\n"
            "It attacks ferociously when angered."),
#endif
        .pokemonScale = 298,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Beautifly,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .backPic = gMonBackPic_Beautifly,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Beautifly,
        .shinyPalette = gMonShinyPalette_Beautifly,
        .iconSprite = gMonIcon_Beautifly,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_BeautiflyF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_BeautiflyF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_S)
        FOOTPRINT(Beautifly)
        OVERWORLD(
            sPicTable_Beautifly,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Beautifly,
            gShinyOverworldPalette_Beautifly
        )
        OVERWORLD_FEMALE(
            sPicTable_BeautiflyF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following
        )
        .levelUpLearnset = sBeautiflyLevelUpLearnset,
        .teachableLearnset = sBeautiflyTeachableLearnset,
    },

    [SPECIES_CASCOON] =
    {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 55,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 120,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 72,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 41,
    #else
        .expYield = 72,
    #endif
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Panekon"),
#else
        .speciesName = _("CASCOON"),
#endif
        .cryId = CRY_CASCOON,
        .natDexNum = NATIONAL_DEX_CASCOON,
#if GERMAN
        .categoryName = _("Kokon"),
#else
        .categoryName = _("Cocoon"),
#endif
        .height = 7,
        .weight = 115,
        .description = COMPOUND_STRING(
#if GERMAN
            "Um von Feinden nicht entdeckt zu werden,\n"
            "versteckt es sich unter Laubbergen oder\n"
            "in Astgabeln. Auch abgefallene Blätter\n"
            "dienen ihm als Tarnung."),
#else
            "To avoid detection by its enemies, it hides\n"
            "motionlessly beneath large leaves and in\n"
            "the gaps of branches. It also attaches\n"
            "dead leaves to its body for camouflage."),
#endif
        .pokemonScale = 391,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cascoon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Cascoon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 24) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 15,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Cascoon,
        .shinyPalette = gMonShinyPalette_Cascoon,
        .iconSprite = gMonIcon_Cascoon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -4, SHADOW_SIZE_M)
        FOOTPRINT(Cascoon)
        OVERWORLD(
            sPicTable_Cascoon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Cascoon,
            gShinyOverworldPalette_Cascoon
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sCascoonLevelUpLearnset,
        .teachableLearnset = sCascoonTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_DUSTOX}),
    },

    [SPECIES_DUSTOX] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 193,
    #elif P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 173,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 135,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 161,
    #else
        .expYield = 160,
    #endif
        .evYield_SpDefense = 3,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_COMPOUND_EYES },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Pudox"),
#else
        .speciesName = _("DUSTOX"),
#endif
        .cryId = CRY_DUSTOX,
        .natDexNum = NATIONAL_DEX_DUSTOX,
#if GERMAN
        .categoryName = _("Giftmotte"),
#else
        .categoryName = _("Poison Moth"),
#endif
        .height = 12,
        .weight = 316,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon ist nachtaktiv und fliegt\n"
        "bei Dunkelheit von den Feldern und Bergen\n"
        "zum Licht der Laternen. Dabei verstreut\n"
        "es giftigen Puder von seinen Flügeln."),
#else
            "It is a nocturnal Pokémon that flies from\n"
            "fields and mountains to the attraction of\n"
            "streetlights at night. It looses highly\n"
            "toxic powder from its wings."),
#endif
        .pokemonScale = 269,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dustox,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .backPic = gMonBackPic_Dustox,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 1,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Dustox,
        .shinyPalette = gMonShinyPalette_Dustox,
        .iconSprite = gMonIcon_Dustox,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 5,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_DustoxF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 48),
        .backPicFemale = gMonBackPic_DustoxF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_S)
        FOOTPRINT(Dustox)
        OVERWORLD(
            sPicTable_Dustox,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Dustox,
            gShinyOverworldPalette_Dustox
        )
        OVERWORLD_FEMALE(
            sPicTable_DustoxF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following
        )
        .levelUpLearnset = sDustoxLevelUpLearnset,
        .teachableLearnset = sDustoxTeachableLearnset,
    },
#endif //P_FAMILY_WURMPLE

#if P_FAMILY_LOTAD
    [SPECIES_LOTAD] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER, TYPE_GRASS),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 44 : 74,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_GRASS),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_RAIN_DISH, ABILITY_OWN_TEMPO },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Loturzel"),
#else
        .speciesName = _("LOTAD"),
#endif
        .cryId = CRY_LOTAD,
        .natDexNum = NATIONAL_DEX_LOTAD,
#if GERMAN
        .categoryName = _("Wasserlinse"),
#else
        .categoryName = _("Water Weed"),
#endif
        .height = 5,
        .weight = 26,
        .description = COMPOUND_STRING(
#if GERMAN
        "Loturzel ist in Teichen mit reinem Wasser\n"
        "zu Hause. Kleine Pokémon werden von ihm\n"
        "auf seinem weiten Blatt sicher über den\n"
        "Teich befördert."),
#else
            "This Pokémon lives in ponds with clean\n"
            "water. It is known to ferry small Pokémon\n"
            "across ponds by carrying them on the\n"
            "broad leaf on its head."),
#endif
        .pokemonScale = 406,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lotad,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 55),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lotad,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Lotad,
        .shinyPalette = gMonShinyPalette_Lotad,
        .iconSprite = gMonIcon_Lotad,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(2, -3, SHADOW_SIZE_S)
        FOOTPRINT(Lotad)
        OVERWORLD(
            sPicTable_Lotad,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lotad,
            gShinyOverworldPalette_Lotad
        )
        .levelUpLearnset = sLotadLevelUpLearnset,
        .teachableLearnset = sLotadTeachableLearnset,
        .eggMoveLearnset = sLotadEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_LOMBRE}),
    },

    [SPECIES_LOMBRE] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER, TYPE_GRASS),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 119 : 141,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_GRASS),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_RAIN_DISH, ABILITY_OWN_TEMPO },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Lombrero"),
#else
        .speciesName = _("LOMBRE"),
#endif
        .cryId = CRY_LOMBRE,
        .natDexNum = NATIONAL_DEX_LOMBRE,
#if GERMAN
        .categoryName = _("Frohmut"),
#else
        .categoryName = _("Jolly"),
#endif
        .height = 12,
        .weight = 325,
        .description = COMPOUND_STRING(
#if GERMAN
            "Nachts macht es sich einen Riesenspaß,\n"
            "indem es aus Flüssen empor springt und\n"
            "Leute erschreckt. Es ernährt sich von\n"
            "Moos, das auf Felsen im Flussbett wächst."),
#else
            "In the evening, it takes great delight in\n"
            "popping out of rivers and startling people.\n"
            "It feeds on aquatic moss that grows on\n"
            "rocks in the riverbed."),
#endif
        .pokemonScale = 277,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lombre,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lombre,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Lombre,
        .shinyPalette = gMonShinyPalette_Lombre,
        .iconSprite = gMonIcon_Lombre,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 2, SHADOW_SIZE_S)
        FOOTPRINT(Lombre)
        OVERWORLD(
            sPicTable_Lombre,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lombre,
            gShinyOverworldPalette_Lombre
        )
        .levelUpLearnset = sLombreLevelUpLearnset,
        .teachableLearnset = sLombreTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_LUDICOLO}),
    },

    [SPECIES_LUDICOLO] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_WATER, TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 240,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 216,
    #else
        .expYield = 181,
    #endif
        .evYield_SpDefense = 3,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_GRASS),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_RAIN_DISH, ABILITY_OWN_TEMPO },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Kappalores"),
#else
        .speciesName = _("LUDICOLO"),
#endif
        .cryId = CRY_LUDICOLO,
        .natDexNum = NATIONAL_DEX_LUDICOLO,
#if GERMAN
        .categoryName = _("Sorglos"),
#else
        .categoryName = _("Carefree"),
#endif
        .height = 15,
        .weight = 550,
        .description = COMPOUND_STRING(
#if GERMAN
            "Vernimmt es festliche Musik, möchten sich\n"
            "alle Zellen in seinem Körper zu diesem\n"
            "Rhythmus bewegen. Es gibt sich selbst ei-\n"
            "nem übermächtigen Feind nicht geschlagen."),
#else
            "When it hears festive music, all the cells\n"
            "in its body become stimulated, and it\n"
            "begins moving in rhythm. It does not\n"
            "quail even when it faces a tough opponent."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = -1,
        .frontPic = gMonFrontPic_Ludicolo,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW,
        .backPic = gMonBackPic_Ludicolo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Ludicolo,
        .shinyPalette = gMonShinyPalette_Ludicolo,
        .iconSprite = gMonIcon_Ludicolo,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_LudicoloF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 64),
        .backPicFemale = gMonBackPic_LudicoloF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 14, SHADOW_SIZE_M)
        FOOTPRINT(Ludicolo)
        OVERWORLD(
            sPicTable_Ludicolo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ludicolo,
            gShinyOverworldPalette_Ludicolo
        )
        OVERWORLD_FEMALE(
            sPicTable_LudicoloF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sLudicoloLevelUpLearnset,
        .teachableLearnset = sLudicoloTeachableLearnset,
    },
#endif //P_FAMILY_LOTAD

#if P_FAMILY_SEEDOT
    [SPECIES_SEEDOT] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 44 : 74,
        .evYield_Defense = 1,
        .itemRare = ITEM_POWER_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_EARLY_BIRD, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Samurzel"),
#else
        .speciesName = _("SEEDOT"),
#endif
        .cryId = CRY_SEEDOT,
        .natDexNum = NATIONAL_DEX_SEEDOT,
#if GERMAN
        .categoryName = _("Eichelnuss"),
#else
        .categoryName = _("Acorn"),
#endif
        .height = 5,
        .weight = 40,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es hängt von Ästen und nimmt Nährstoffe\n"
        "auf. Nach dem Essen ist sein Körper so\n"
        "schwer, dass es sich einfach fallen lässt\n"
        "und mit lautem Knall aufschlägt."),
#else
            "It hangs off branches and absorbs\n"
            "nutrients. When it finishes eating, its\n"
            "body becomes so heavy that it drops to\n"
            "the ground with a thump."),
#endif
        .pokemonScale = 472,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Seedot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES : ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Seedot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Seedot,
        .shinyPalette = gMonShinyPalette_Seedot,
        .iconSprite = gMonIcon_Seedot,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Seedot)
        OVERWORLD(
            sPicTable_Seedot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Seedot,
            gShinyOverworldPalette_Seedot
        )
        .levelUpLearnset = sSeedotLevelUpLearnset,
        .teachableLearnset = sSeedotTeachableLearnset,
        .eggMoveLearnset = sSeedotEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_NUZLEAF}),
    },

    [SPECIES_NUZLEAF] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DARK),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 119 : 141,
        .evYield_Attack = 2,
        .itemRare = ITEM_POWER_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_EARLY_BIRD, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Blanas"),
#else
        .speciesName = _("NUZLEAF"),
#endif
        .cryId = CRY_NUZLEAF,
        .natDexNum = NATIONAL_DEX_NUZLEAF,
#if GERMAN
        .categoryName = _("Hinterlist"),
#else
        .categoryName = _("Wily"),
#endif
        .height = 10,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
        "Blanas lebt im Wald und ist ein geschickter\n"
        "Kletterer. Seine lange, spitze Nase ist\n"
        "sein Schwachpunkt. Greift man seine Nase,\n"
        "wird es schwächer."),
#else
            "A forest-dwelling Pokémon that is skilled\n"
            "at climbing trees. Its long and pointed\n"
            "nose is its weak point. It loses power if\n"
            "the nose is gripped."),
#endif
        .pokemonScale = 299,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nuzleaf,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Nuzleaf,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Nuzleaf,
        .shinyPalette = gMonShinyPalette_Nuzleaf,
        .iconSprite = gMonIcon_Nuzleaf,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_NuzleafF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 56),
        .backPicFemale = gMonBackPic_NuzleafF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 5, SHADOW_SIZE_S)
        FOOTPRINT(Nuzleaf)
        OVERWORLD(
            sPicTable_Nuzleaf,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nuzleaf,
            gShinyOverworldPalette_Nuzleaf
        )
        OVERWORLD_FEMALE(
            sPicTable_NuzleafF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sNuzleafLevelUpLearnset,
        .teachableLearnset = sNuzleafTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SHIFTRY}),
    },

    [SPECIES_SHIFTRY] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 80,
        .baseSpAttack  = 90,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DARK),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 240,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 216,
    #else
        .expYield = 181,
    #endif
        .evYield_Attack = 3,
        .itemRare = ITEM_POWER_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_9
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_WIND_RIDER, ABILITY_PICKPOCKET },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_EARLY_BIRD, ABILITY_PICKPOCKET },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Tengulist"),
#else
        .speciesName = _("SHIFTRY"),
#endif
        .cryId = CRY_SHIFTRY,
        .natDexNum = NATIONAL_DEX_SHIFTRY,
#if GERMAN
        .categoryName = _("Verschlagen"),
#else
        .categoryName = _("Wicked"),
#endif
        .height = 13,
        .weight = 596,
        .description = COMPOUND_STRING(
#if GERMAN
            "Tengulist soll mit den eisigen Winterwinden\n"
            "auftauchen. Seit langer Zeit wird es als\n"
            "Wächter des Waldes gefürchtet und es lebt\n"
            "tief im Wald, wo kein Mensch hingelangt."),
#else
            "It is said to arrive on chilly, wintry winds.\n"
            "Feared from long ago as the guardian of\n"
            "forests, this Pokémon lives in a deep\n"
            "forest where people do not venture."),
#endif
        .pokemonScale = 290,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shiftry,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Shiftry,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Shiftry,
        .shinyPalette = gMonShinyPalette_Shiftry,
        .iconSprite = gMonIcon_Shiftry,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 5,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_ShiftryF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_ShiftryF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 5, SHADOW_SIZE_M)
        FOOTPRINT(Shiftry)
        OVERWORLD(
            sPicTable_Shiftry,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Shiftry,
            gShinyOverworldPalette_Shiftry
        )
        OVERWORLD_FEMALE(
            sPicTable_ShiftryF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sShiftryLevelUpLearnset,
        .teachableLearnset = sShiftryTeachableLearnset,
    },
#endif //P_FAMILY_SEEDOT

#if P_FAMILY_TAILLOW
    [SPECIES_TAILLOW] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 85,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 54 : 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Schwalbini"),
#else
        .speciesName = _("TAILLOW"),
#endif
        .cryId = CRY_TAILLOW,
        .natDexNum = NATIONAL_DEX_TAILLOW,
#if GERMAN
        .categoryName = _("Schwälblein"),
#else
        .categoryName = _("Tiny Swallow"),
#endif
        .height = 3,
        .weight = 23,
        .description = COMPOUND_STRING(
#if GERMAN
            "Trotz seiner geringen Größe ist es mutig.\n"
            "Es stellt sich einem großen Panzaeron\n"
            "tapfer entgegen. Sein Kampfeswille wird\n"
            "jedoch durch Hunger geschwächt."),
#else
            "Although it is small, it is very courageous.\n"
            "It will take on a larger Skarmory on an\n"
            "equal footing. However, its will weakens if\n"
            "it becomes hungry."),
#endif
        .pokemonScale = 465,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Taillow,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 32) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_JUMPS_BIG,
        .backPic = gMonBackPic_Taillow,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 32) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Taillow,
        .shinyPalette = gMonShinyPalette_Taillow,
        .iconSprite = gMonIcon_Taillow,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 1, SHADOW_SIZE_S)
        FOOTPRINT(Taillow)
        OVERWORLD(
            sPicTable_Taillow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Taillow,
            gShinyOverworldPalette_Taillow
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sTaillowLevelUpLearnset,
        .teachableLearnset = sTaillowTeachableLearnset,
        .eggMoveLearnset = sTaillowEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_SWELLOW}),
    },

    [SPECIES_SWELLOW] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 125,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 75 : 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 159,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 151,
    #else
        .expYield = 162,
    #endif
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_GUTS, ABILITY_NONE, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Schwalboss"),
#else
        .speciesName = _("SWELLOW"),
#endif
        .cryId = CRY_SWELLOW,
        .natDexNum = NATIONAL_DEX_SWELLOW,
#if GERMAN
        .categoryName = _("Schwalbe"),
#else
        .categoryName = _("Swallow"),
#endif
        .height = 7,
        .weight = 198,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwalboss stürzt sich aus großen\n"
            "Höhen auf seine Beute. Dabei verfehlt es\n"
            "sein Ziel nie. Es fliegt immer auf der\n"
            "Suche nach warmem Klima."),
#else
            "A Swellow dives upon prey from far above.\n"
            "It never misses its targets. It takes to\n"
            "the skies in search of lands with a warm\n"
            "climate."),
#endif
        .pokemonScale = 428,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swellow,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Swellow,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Swellow,
        .shinyPalette = gMonShinyPalette_Swellow,
        .iconSprite = gMonIcon_Swellow,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 7, SHADOW_SIZE_M)
        FOOTPRINT(Swellow)
        OVERWORLD(
            sPicTable_Swellow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Swellow,
            gShinyOverworldPalette_Swellow
        )
        .levelUpLearnset = sSwellowLevelUpLearnset,
        .teachableLearnset = sSwellowTeachableLearnset,
    },
#endif //P_FAMILY_TAILLOW

#if P_FAMILY_WINGULL
    [SPECIES_WINGULL] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 54 : 64,
        .evYield_Speed = 1,
        .itemCommon = ITEM_PRETTY_FEATHER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_KEEN_EYE, ABILITY_HYDRATION, ABILITY_RAIN_DISH },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_RAIN_DISH },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Wingull"),
#else
        .speciesName = _("WINGULL"),
#endif
        .cryId = CRY_WINGULL,
        .natDexNum = NATIONAL_DEX_WINGULL,
#if GERMAN
        .categoryName = _("Seemöwe"),
#else
        .categoryName = _("Seagull"),
#endif
        .height = 6,
        .weight = 95,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wingull baut sein Nest an kahlen Klippen\n"
            "nahe des Meers. Es fällt ihm nicht leicht,\n"
            "beim Fliegen mit den Flügeln zu schlagen,\n"
            "daher nutzt es Aufwinde."),
#else
            "It makes its nest on a sheer cliff at the\n"
            "edge of the sea. It has trouble keeping\n"
            "its wings flapping in flight. Instead, it\n"
            "soars on updrafts."),
#endif
        .pokemonScale = 295,
        .pokemonOffset = -2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wingull,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 24 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 17),
            ANIMCMD_FRAME(1, 23),
            ANIMCMD_FRAME(0, 13),
        ),
        .frontAnimId = ANIM_H_PIVOT,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 16 : 15,
        .backPic = gMonBackPic_Wingull,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Wingull,
        .shinyPalette = gMonShinyPalette_Wingull,
        .iconSprite = gMonIcon_Wingull,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 15, SHADOW_SIZE_S)
        FOOTPRINT(Wingull)
        OVERWORLD(
            sPicTable_Wingull,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Wingull,
            gShinyOverworldPalette_Wingull
        )
        .levelUpLearnset = sWingullLevelUpLearnset,
        .teachableLearnset = sWingullTeachableLearnset,
        .eggMoveLearnset = sWingullEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_PELIPPER}),
    },

    [SPECIES_PELIPPER] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 100,
        .baseSpeed     = 65,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 95 : 85,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 154,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 151,
    #else
        .expYield = 164,
    #endif
        .evYield_Defense = 2,
        .itemCommon = ITEM_PRETTY_FEATHER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_KEEN_EYE, ABILITY_DRIZZLE, ABILITY_RAIN_DISH },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_RAIN_DISH },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Pelipper"),
#else
        .speciesName = _("PELIPPER"),
#endif
        .cryId = CRY_PELIPPER,
        .natDexNum = NATIONAL_DEX_PELIPPER,
#if GERMAN
        .categoryName = _("Wasservogel"),
#else
        .categoryName = _("Water Bird"),
#endif
        .height = 12,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es überfliegt die Wellenspitzen. Sieht es\n"
            "dabei Beute, setzt es seinen langen\n"
            "Schnabel ein, um die Beute einzufangen.\n"
            "Seine Eier sind im Schnabel gut geschützt."),
#else
            "It skims the tops of waves as it flies.\n"
            "When it spots prey, it uses its large beak\n"
            "to scoop up the victim with water.\n"
            "It protects its eggs in its beak."),
#endif
        .pokemonScale = 288,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pelipper,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Pelipper,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Pelipper,
        .shinyPalette = gMonShinyPalette_Pelipper,
        .iconSprite = gMonIcon_Pelipper,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 17, SHADOW_SIZE_M)
        FOOTPRINT(Pelipper)
        OVERWORLD(
            sPicTable_Pelipper,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Pelipper,
            gShinyOverworldPalette_Pelipper
        )
        .levelUpLearnset = sPelipperLevelUpLearnset,
        .teachableLearnset = sPelipperTeachableLearnset,
    },
#endif //P_FAMILY_WINGULL

#if P_FAMILY_RALTS
#define RALTS_FAMILY_TYPE2 (P_UPDATED_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_PSYCHIC)

#if P_UPDATED_EGG_GROUPS >= GEN_8
    #define RALTS_FAMILY_EGG_GROUPS MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE, EGG_GROUP_AMORPHOUS)
#else
    #define RALTS_FAMILY_EGG_GROUPS MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS)
#endif

    [SPECIES_RALTS] =
    {
        .baseHP        = 28,
        .baseAttack    = 25,
        .baseDefense   = 25,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_PSYCHIC, RALTS_FAMILY_TYPE2),
        .catchRate = 235,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 40 : 70,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = RALTS_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_TRACE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Trasla"),
#else
        .speciesName = _("RALTS"),
#endif
        .cryId = CRY_RALTS,
        .natDexNum = NATIONAL_DEX_RALTS,
#if GERMAN
        .categoryName = _("Gefühl"),
#else
        .categoryName = _("Feeling"),
#endif
        .height = 4,
        .weight = 66,
        .description = COMPOUND_STRING(
#if GERMAN
        "Trasla kann die Emotionen der Menschen\n"
        "und Pokémon mit seinem Horn fühlen. Fühlt\n"
        "es Feindseligkeit, versteckt es sich."),
#else
            "A Ralts has the power to sense the\n"
            "emotions of people and Pokémon with the\n"
            "horns on its head. It takes cover if it\n"
            "senses any hostility."),
#endif
        .pokemonScale = 457,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ralts,
        .frontPicSize = MON_COORDS_SIZE(24, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Ralts,
        .backPicSize = MON_COORDS_SIZE(32, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Ralts,
        .shinyPalette = gMonShinyPalette_Ralts,
        .iconSprite = gMonIcon_Ralts,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Ralts)
        OVERWORLD(
            sPicTable_Ralts,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ralts,
            gShinyOverworldPalette_Ralts
        )
        .levelUpLearnset = sRaltsLevelUpLearnset,
        .teachableLearnset = sRaltsTeachableLearnset,
        .eggMoveLearnset = sRaltsEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_KIRLIA}),
    },

    [SPECIES_KIRLIA] =
    {
        .baseHP        = 38,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_PSYCHIC, RALTS_FAMILY_TYPE2),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 97 : 140,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = RALTS_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_TRACE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Kirlia"),
#else
        .speciesName = _("KIRLIA"),
#endif
        .cryId = CRY_KIRLIA,
        .natDexNum = NATIONAL_DEX_KIRLIA,
        .categoryName = _("Emotion"),
        .height = 8,
        .weight = 202,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kirlia hat Psykräfte, mit denen es ein\n"
            "Loch in die Dimensionen reißen kann, um\n"
            "in die Zukunft zu sehen. An sonnigen\n"
            "Morgen soll es mit Freude tanzen."),
#else
            "A Kirlia has the psychic power to create \n"
            "a rip in the dimensions and see into the\n"
            "future. It is said to dance with pleasure\n"
            "on sunny mornings."),
#endif
        .pokemonScale = 354,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kirlia,
        .frontPicSize = MON_COORDS_SIZE(32, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 39),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kirlia,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 56) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Kirlia,
        .shinyPalette = gMonShinyPalette_Kirlia,
        .iconSprite = gMonIcon_Kirlia,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, 7, SHADOW_SIZE_S)
        FOOTPRINT(Kirlia)
        OVERWORLD(
            sPicTable_Kirlia,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kirlia,
            gShinyOverworldPalette_Kirlia
        )
        .levelUpLearnset = sKirliaLevelUpLearnset,
        .teachableLearnset = sKirliaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_GARDEVOIR}
                            #if P_GEN_4_CROSS_EVOS
                                ,{EVO_ITEM, ITEM_DAWN_STONE, SPECIES_GALLADE, CONDITIONS({IF_GENDER, MON_MALE})}
                            #endif
                            ),
    },

    [SPECIES_GARDEVOIR] =
    {
        .baseHP        = 68,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 125,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_PSYCHIC, RALTS_FAMILY_TYPE2),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 259,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 233,
    #else
        .expYield = 208,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = RALTS_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_SYNCHRONIZE, ABILITY_TRACE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Guardevoir"),
#else
        .speciesName = _("GARDEVOIR"),
#endif
        .cryId = CRY_GARDEVOIR,
        .natDexNum = NATIONAL_DEX_GARDEVOIR,
#if GERMAN
        .categoryName = _("Umarmung"),
#else
        .categoryName = _("Embrace"),
#endif
        .height = 16,
        .weight = 484,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Schwerkraft scheint ihm nichts\n"
            "auszumachen, da es mittels seiner\n"
            "Psykräfte schwebt. Es würde sein\n"
            "Leben für seinen Trainer geben."),
#else
            "It apparently does not feel the pull of\n"
            "gravity because it supports itself with\n"
            "psychic power. It will give its life to\n"
            "protect its Trainer."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gardevoir,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Gardevoir,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Gardevoir,
        .shinyPalette = gMonShinyPalette_Gardevoir,
        .iconSprite = gMonIcon_Gardevoir,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_L)
        FOOTPRINT(Gardevoir)
        OVERWORLD(
            sPicTable_Gardevoir,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gardevoir,
            gShinyOverworldPalette_Gardevoir
        )
        .levelUpLearnset = sGardevoirLevelUpLearnset,
        .teachableLearnset = sGardevoirTeachableLearnset,
        .formSpeciesIdTable = sGardevoirFormSpeciesIdTable,
        .formChangeTable = sGardevoirFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_GARDEVOIR_MEGA] =
    {
        .baseHP        = 68,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 165,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 309 : 278,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = RALTS_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_PIXILATE, ABILITY_PIXILATE, ABILITY_PIXILATE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Guardevoir"),
#else
        .speciesName = _("GARDEVOIR"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GARDEVOIR_MEGA,
    #else
        .cryId = CRY_GARDEVOIR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GARDEVOIR,
#if GERMAN
        .categoryName = _("Umarmung"),
#else
        .categoryName = _("Embrace"),
#endif
        .height = 16,
        .weight = 484,
        .description = COMPOUND_STRING(
#if GERMAN
        "Breitet es die roten Platten in seiner\n"
        "Brust aus und befreit damit sein Herz,\n"
        "werden seine stärksten Psycho-Kräfte\n"
        "entfesselt."),
#else
            "By opening its heart, Mega Gardevoir\n"
            "becomes able to use tremendous psychic\n"
            "power. The red plate in its chest is said to\n"
            "be a physical manifestation of its heart."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GardevoirMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GardevoirMega,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_GardevoirMega,
        .shinyPalette = gMonShinyPalette_GardevoirMega,
        .iconSprite = gMonIcon_GardevoirMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 14, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Gardevoir)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_GardevoirMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GardevoirMega,
            gShinyOverworldPalette_GardevoirMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sGardevoirLevelUpLearnset,
        .teachableLearnset = sGardevoirTeachableLearnset,
        .formSpeciesIdTable = sGardevoirFormSpeciesIdTable,
        .formChangeTable = sGardevoirFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GEN_4_CROSS_EVOS
    [SPECIES_GALLADE] =
    {
        .baseHP        = 68,
        .baseAttack    = 125,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 65,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FIGHTING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 259,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 233,
    #else
        .expYield = 208,
    #endif
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = RALTS_FAMILY_EGG_GROUPS,
    #if P_UPDATED_ABILITIES >= GEN_9
        .abilities = { ABILITY_STEADFAST, ABILITY_SHARPNESS, ABILITY_JUSTIFIED },
    #else
        .abilities = { ABILITY_STEADFAST, ABILITY_NONE, ABILITY_JUSTIFIED },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Galagladi"),
#else
        .speciesName = _("GALLADE"),
#endif
        .cryId = CRY_GALLADE,
        .natDexNum = NATIONAL_DEX_GALLADE,
#if GERMAN
        .categoryName = _("Klinge"),
#else
        .categoryName = _("Blade"),
#endif
        .height = 16,
        .weight = 520,
        .description = COMPOUND_STRING(
#if GERMAN
            "Da es selbst die leisesten Gedanken\n"
            "seines Gegners lesen kann, kann es\n"
            "immer zuerst angreifen."),
#else
            "A master of courtesy and swordsmanship,\n"
            "it fights using extending swords on its\n"
            "elbows when trying to protect someone.\n"
            "It can sense what its foe is thinking."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Gallade,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Gallade,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Gallade,
        .shinyPalette = gMonShinyPalette_Gallade,
        .iconSprite = gMonIcon_Gallade,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 13, SHADOW_SIZE_L)
        FOOTPRINT(Gallade)
        OVERWORLD(
            sPicTable_Gallade,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gallade,
            gShinyOverworldPalette_Gallade
        )
        .levelUpLearnset = sGalladeLevelUpLearnset,
        .teachableLearnset = sGalladeTeachableLearnset,
        .formSpeciesIdTable = sGalladeFormSpeciesIdTable,
        .formChangeTable = sGalladeFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_GALLADE_MEGA] =
    {
        .baseHP        = 68,
        .baseAttack    = 165,
        .baseDefense   = 95,
        .baseSpeed     = 110,
        .baseSpAttack  = 65,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 309 : 278,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = RALTS_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_INNER_FOCUS, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Galagladi"),
#else
        .speciesName = _("GALLADE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GALLADE_MEGA,
    #else
        .cryId = CRY_GALLADE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GALLADE,
#if GERMAN
        .categoryName = _("Klinge"),
#else
        .categoryName = _("Blade"),
#endif
        .height = 16,
        .weight = 564,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Bindung zu seinem Trainer\n"
        "verleiht ihm Kraft. In dieser Form besitzt\n"
        "es Klingen, um Gegner aufzuschlitzen,\n"
        "und einen schützenden Mantel."),
#else
            "Mega Gallade has a knightly appearance.\n"
            "It can use its psychic power to reshape\n"
            "both arms into blades simultaneously and\n"
            "fight using a dual-wielding style."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_GalladeMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GalladeMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_GalladeMega,
        .shinyPalette = gMonShinyPalette_GalladeMega,
        .iconSprite = gMonIcon_GalladeMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Gallade)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_GalladeMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GalladeMega,
            gShinyOverworldPalette_GalladeMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sGalladeLevelUpLearnset,
        .teachableLearnset = sGalladeTeachableLearnset,
        .formSpeciesIdTable = sGalladeFormSpeciesIdTable,
        .formChangeTable = sGalladeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_RALTS

#if P_FAMILY_SURSKIT
    [SPECIES_SURSKIT] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 32,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 52,
        .types = MON_TYPES(TYPE_BUG, TYPE_WATER),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 54 : 63,
        .evYield_Speed = 1,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_BUG),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_RAIN_DISH },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Gehweiher"),
#else
        .speciesName = _("SURSKIT"),
#endif
        .cryId = CRY_SURSKIT,
        .natDexNum = NATIONAL_DEX_SURSKIT,
#if GERMAN
        .categoryName = _("Wassergeher"),
#else
        .categoryName = _("Pond Skater"),
#endif
        .height = 5,
        .weight = 17,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gehweiher trifft sich mit Artgenossen\n"
            "nach heftigen Regenfällen in Pfützen,\n"
            "um über die Oberfläche zu gleiten. Es\n"
            "sondert einen Honig von seinem Kopf ab."),
#else
            "They gather on puddles after evening\n"
            "downpours, gliding across the surface\n"
            "of water as if sliding. It secretes honey\n"
            "with a sweet aroma from its head."),
#endif
        .pokemonScale = 375,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Surskit,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Surskit,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 13,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Surskit,
        .shinyPalette = gMonShinyPalette_Surskit,
        .iconSprite = gMonIcon_Surskit,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -3, SHADOW_SIZE_S)
        FOOTPRINT(Surskit)
        OVERWORLD(
            sPicTable_Surskit,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Surskit,
            gShinyOverworldPalette_Surskit
        )
        .levelUpLearnset = sSurskitLevelUpLearnset,
        .teachableLearnset = sSurskitTeachableLearnset,
        .eggMoveLearnset = sSurskitEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_MASQUERAIN}),
    },

    [SPECIES_MASQUERAIN] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 62,
        .baseSpeed     = P_UPDATED_STATS >= GEN_7 ? 80 : 60,
        .baseSpAttack  = P_UPDATED_STATS >= GEN_7 ? 100 : 80,
        .baseSpDefense = 82,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 75,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 159,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 145,
    #else
        .expYield = 128,
    #endif
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_BUG),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Maskeregen"),
#else
        .speciesName = _("MASQUERAIN"),
#endif
        .cryId = CRY_MASQUERAIN,
        .natDexNum = NATIONAL_DEX_MASQUERAIN,
#if GERMAN
        .categoryName = _("Auge"),
#else
        .categoryName = _("Eyeball"),
#endif
        .height = 8,
        .weight = 36,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es schüchtert seine Feinde mit dem großen\n"
            "augenartigen Muster auf seinen Fühlern\n"
            "ein. Da es mit nassen Flügeln nicht fliegen\n"
            "kann, sucht es bei Regen Unterschlupf."),
#else
            "It intimidates foes with the large eyelike\n"
            "patterns on its antennae. Because it can't\n"
            "fly if its wings get wet, it shelters itself\n"
            "from rain under large trees and eaves."),
#endif
        .pokemonScale = 378,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Masquerain,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Masquerain,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Masquerain,
        .shinyPalette = gMonShinyPalette_Masquerain,
        .iconSprite = gMonIcon_Masquerain,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 17, SHADOW_SIZE_M)
        FOOTPRINT(Masquerain)
        OVERWORLD(
            sPicTable_Masquerain,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Masquerain,
            gShinyOverworldPalette_Masquerain
        )
        .levelUpLearnset = sMasquerainLevelUpLearnset,
        .teachableLearnset = sMasquerainTeachableLearnset,
    },
#endif //P_FAMILY_SURSKIT

#if P_FAMILY_SHROOMISH
    [SPECIES_SHROOMISH] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 35,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 59 : 65,
        .evYield_HP = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_POISON_HEAL, ABILITY_QUICK_FEET },
    #else
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_QUICK_FEET },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Knilz"),
#else
        .speciesName = _("SHROOMISH"),
#endif
        .cryId = CRY_SHROOMISH,
        .natDexNum = NATIONAL_DEX_SHROOMISH,
#if GERMAN
        .categoryName = _("Pilz"),
#else
        .categoryName = _("Mushroom"),
#endif
        .height = 4,
        .weight = 45,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es ernährt sich am liebsten von feuchter,\n"
            "verrotteter Walderde. Wenn du nach einem\n"
            "Regenguss in den Wald gehst, kannst du\n"
            "viele Knilz auf Komposterde finden."),
#else
            "It loves to eat damp, composted soil in\n"
            "forests. If you enter a forest after a\n"
            "long rain, you can see many Shroomish\n"
            "feasting on composted soil."),
#endif
        .pokemonScale = 513,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shroomish,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Shroomish,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 9,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Shroomish,
        .shinyPalette = gMonShinyPalette_Shroomish,
        .iconSprite = gMonIcon_Shroomish,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Shroomish)
        OVERWORLD(
            sPicTable_Shroomish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Shroomish,
            gShinyOverworldPalette_Shroomish
        )
        .levelUpLearnset = sShroomishLevelUpLearnset,
        .teachableLearnset = sShroomishTeachableLearnset,
        .eggMoveLearnset = sShroomishEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 23, SPECIES_BRELOOM}),
    },

    [SPECIES_BRELOOM] =
    {
        .baseHP        = 60,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FIGHTING),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 161 : 165,
        .evYield_Attack = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_POISON_HEAL, ABILITY_TECHNICIAN },
    #else
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_TECHNICIAN },
    #endif
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Kapilz"),
#else
        .speciesName = _("BRELOOM"),
#endif
        .cryId = CRY_BRELOOM,
        .natDexNum = NATIONAL_DEX_BRELOOM,
#if GERMAN
        .categoryName = _("Pilz"),
#else
        .categoryName = _("Mushroom"),
#endif
        .height = 12,
        .weight = 392,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es die Kappe auf seinem Kopf verteilt es\n"
        "Sporen. Kapilz liebt warmes und feuchtes\n"
        "Klima. Es ernährt sich von Bäumen und\n"
        "Pflanzen im Wald und auf den Wiesen."),
#else
            "It scatters spores from holes in the cap\n"
            "on its head. It loves warm and humid\n"
            "climates. It feeds on trees and plants in\n"
            "fields and forests."),
#endif
        .pokemonScale = 324,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Breloom,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Breloom,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Breloom,
        .shinyPalette = gMonShinyPalette_Breloom,
        .iconSprite = gMonIcon_Breloom,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 9, SHADOW_SIZE_M)
        FOOTPRINT(Breloom)
        OVERWORLD(
            sPicTable_Breloom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Breloom,
            gShinyOverworldPalette_Breloom
        )
        .levelUpLearnset = sBreloomLevelUpLearnset,
        .teachableLearnset = sBreloomTeachableLearnset,
    },
#endif //P_FAMILY_SHROOMISH

#if P_FAMILY_SLAKOTH
    [SPECIES_SLAKOTH] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 30,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 56 : 83,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TRUANT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Bummelz"),
#else
        .speciesName = _("SLAKOTH"),
#endif
        .cryId = CRY_SLAKOTH,
        .natDexNum = NATIONAL_DEX_SLAKOTH,
#if GERMAN
        .categoryName = _("Faulpelz"),
#else
        .categoryName = _("Slacker"),
#endif
        .height = 8,
        .weight = 240,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es schläft den ganzen Tag und die ganze\n"
            "Nacht. Auch baut es in seinem ganzen\n"
            "Leben nur ein Nest. Manchmal legt es aller-\n"
            "dings große Strecken in Flüssen zurück."),
#else
            "It sleeps virtually all day and night long.\n"
            "It doesn't change its nest its entire life,\n"
            "but it sometimes travels great distances\n"
            "by swimming in rivers."),
#endif
        .pokemonScale = 291,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Slakoth,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Slakoth,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Slakoth,
        .shinyPalette = gMonShinyPalette_Slakoth,
        .iconSprite = gMonIcon_Slakoth,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, -4, SHADOW_SIZE_M)
        FOOTPRINT(Slakoth)
        OVERWORLD(
            sPicTable_Slakoth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Slakoth,
            gShinyOverworldPalette_Slakoth
        )
        .levelUpLearnset = sSlakothLevelUpLearnset,
        .teachableLearnset = sSlakothTeachableLearnset,
        .eggMoveLearnset = sSlakothEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_VIGOROTH}),
    },

    [SPECIES_VIGOROTH] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 90,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 154 : 126,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Muntier"),
#else
        .speciesName = _("VIGOROTH"),
#endif
        .cryId = CRY_VIGOROTH,
        .natDexNum = NATIONAL_DEX_VIGOROTH,
#if GERMAN
        .categoryName = _("Wildaffe"),
#else
        .categoryName = _("Wild Monkey"),
#endif
        .height = 14,
        .weight = 465,
        .description = COMPOUND_STRING(
#if GERMAN
            "Da sein Blut vor Energie strotzt, kann es\n"
            "nicht stillsitzen. Den ganzen Tag rennt es\n"
            "über Felder und Berge, um sich abzuregen.\n"
            "Schlägt das fehl, kann es nicht schlafen."),
#else
            "It can't keep still because its blood boils\n"
            "with energy. It runs through the fields\n"
            "and mountains all day to calm itself. If it\n"
            "doesn't, it can't sleep at night."),
#endif
        .pokemonScale = 301,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vigoroth,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 13),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Vigoroth,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Vigoroth,
        .shinyPalette = gMonShinyPalette_Vigoroth,
        .iconSprite = gMonIcon_Vigoroth,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 6, SHADOW_SIZE_M)
        FOOTPRINT(Vigoroth)
        OVERWORLD(
            sPicTable_Vigoroth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vigoroth,
            gShinyOverworldPalette_Vigoroth
        )
        .levelUpLearnset = sVigorothLevelUpLearnset,
        .teachableLearnset = sVigorothTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SLAKING}),
    },

    [SPECIES_SLAKING] =
    {
        .baseHP        = 150,
        .baseAttack    = 160,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 95,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 285,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 252,
    #else
        .expYield = 210,
    #endif
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TRUANT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Letarking"),
#else
        .speciesName = _("SLAKING"),
#endif
        .cryId = CRY_SLAKING,
        .natDexNum = NATIONAL_DEX_SLAKING,
#if GERMAN
        .categoryName = _("Müßig"),
#else
        .categoryName = _("Lazy"),
#endif
        .height = 20,
        .weight = 1305,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wenn die Früchte reif sind, versammeln sich\n"
        "Letarking um Bäume. Sie warten dort\n"
        "geduldig, dass die reifen Früchte vom Baum\n"
        "fallen."),
#else
            "Hordes of Slaking gather around trees\n"
            "when fruits come into season. They wait\n"
            "around patiently for ripened fruits to fall\n"
            "out of the trees."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 300,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Slaking,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Slaking,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Slaking,
        .shinyPalette = gMonShinyPalette_Slaking,
        .iconSprite = gMonIcon_Slaking,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Slaking)
        OVERWORLD(
            sPicTable_Slaking,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Slaking,
            gShinyOverworldPalette_Slaking
        )
        .levelUpLearnset = sSlakingLevelUpLearnset,
        .teachableLearnset = sSlakingTeachableLearnset,
    },
#endif //P_FAMILY_SLAKOTH

#if P_FAMILY_NINCADA
    [SPECIES_NINCADA] =
    {
        .baseHP        = 31,
        .baseAttack    = 45,
        .baseDefense   = 90,
        .baseSpeed     = 40,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_BUG, TYPE_GROUND),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 53 : 65,
        .evYield_Defense = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_NONE, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Nincada"),
#else
        .speciesName = _("NINCADA"),
#endif
        .cryId = CRY_NINCADA,
        .natDexNum = NATIONAL_DEX_NINCADA,
#if GERMAN
        .categoryName = _("Vorbereiter"),
#else
        .categoryName = _("Trainee"),
#endif
        .height = 5,
        .weight = 55,
        .description = COMPOUND_STRING(
#if GERMAN
        "Am Fuße von mächtigen Bäumen baut es sein\n"
        "Nest. Mit seinen schnurrbartähnlichen\n"
        "Fühlern überprüft es die Umgebung aus der\n"
        "dunklen Erde."),
#else
            "It makes its nest at the roots of a mighty\n"
            "tree. Using its whiskerlike antennae, it\n"
            "probes its surroundings in the\n"
            "pitch-black darkness of soil."),
#endif
        .pokemonScale = 405,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nincada,
        .frontPicSize = MON_COORDS_SIZE(56, 32),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Nincada,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 18,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Nincada,
        .shinyPalette = gMonShinyPalette_Nincada,
        .iconSprite = gMonIcon_Nincada,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, -3, SHADOW_SIZE_M)
        FOOTPRINT(Nincada)
        OVERWORLD(
            sPicTable_Nincada,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Nincada,
            gShinyOverworldPalette_Nincada
        )
        .levelUpLearnset = sNincadaLevelUpLearnset,
        .teachableLearnset = sNincadaTeachableLearnset,
        .eggMoveLearnset = sNincadaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_NINJASK},
                            #if P_SHEDINJA_BALL >= GEN_4
                                {EVO_SPLIT_FROM_EVO, SPECIES_NINJASK, SPECIES_SHEDINJA, CONDITIONS({IF_BAG_ITEM_COUNT, ITEM_POKE_BALL, 1})}),
                            #else
                                {EVO_SPLIT_FROM_EVO, SPECIES_NINJASK, SPECIES_SHEDINJA}),
                            #endif
    },

    [SPECIES_NINJASK] =
    {
        .baseHP        = 61,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 160,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_BUG, TYPE_FLYING),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 160 : 155,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SPEED_BOOST, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Ninjask"),
#else
        .speciesName = _("NINJASK"),
#endif
        .cryId = CRY_NINJASK,
        .natDexNum = NATIONAL_DEX_NINJASK,
        .categoryName = _("Ninja"),
        .height = 8,
        .weight = 120,
        .description = COMPOUND_STRING(
#if GERMAN
            "Da es sich blitzschnell bewegt, ist es\n"
            "schwer zu sehen. Wenn man seine\n"
            "charakteristischen Schreie zu lange\n"
            "hört, bekommt man Kopfschmerzen."),
#else
            "Because it darts about vigorously at high\n"
            "speed, it is very difficult to see. Hearing\n"
            "its distinctive cries for too long induces\n"
            "a headache."),
#endif
        .pokemonScale = 383,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ninjask,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 33),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 1),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Ninjask,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 13,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Ninjask,
        .shinyPalette = gMonShinyPalette_Ninjask,
        .iconSprite = gMonIcon_Ninjask,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_S)
        FOOTPRINT(Ninjask)
        OVERWORLD(
            sPicTable_Ninjask,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Ninjask,
            gShinyOverworldPalette_Ninjask
        )
        .levelUpLearnset = sNinjaskLevelUpLearnset,
        .teachableLearnset = sNinjaskTeachableLearnset,
    },

    [SPECIES_SHEDINJA] =
    {
        .baseHP        = 1,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 40,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_BUG, TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 83 : 95,
        .evYield_HP = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_WONDER_GUARD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Ninjatom"),
#else
        .speciesName = _("SHEDINJA"),
#endif
        .cryId = CRY_SHEDINJA,
        .natDexNum = NATIONAL_DEX_SHEDINJA,
#if GERMAN
        .categoryName = _("Häutung"),
#else
        .categoryName = _("Shed"),
#endif
        .height = 8,
        .weight = 12,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dieses besondere Pokémon schwebt\n"
            "in der Luft, auch wenn es seine Flügel\n"
            "nicht bewegt. Das Innere seines Körpers\n"
            "ist hohl und stockfinster."),
#else
            "A peculiar Pokémon that floats in air even\n"
            "though its wings remain completely still.\n"
            "The inside of its body is hollow and\n"
            "utterly dark."),
#endif
        .pokemonScale = 372,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shedinja,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 33),
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 33),
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Shedinja,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Shedinja,
        .shinyPalette = gMonShinyPalette_Shedinja,
        .iconSprite = gMonIcon_Shedinja,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 9, SHADOW_SIZE_S)
        FOOTPRINT(Shedinja)
        OVERWORLD(
            sPicTable_Shedinja,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Shedinja,
            gShinyOverworldPalette_Shedinja
        )
        .levelUpLearnset = sShedinjaLevelUpLearnset,
        .teachableLearnset = sShedinjaTeachableLearnset,
    },
#endif //P_FAMILY_NINCADA

#if P_FAMILY_WHISMUR
    [SPECIES_WHISMUR] =
    {
        .baseHP        = 64,
        .baseAttack    = 51,
        .baseDefense   = 23,
        .baseSpeed     = 28,
        .baseSpAttack  = 51,
        .baseSpDefense = 23,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 48 : 68,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_NONE, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Flurmel"),
#else
        .speciesName = _("WHISMUR"),
#endif
        .cryId = CRY_WHISMUR,
        .natDexNum = NATIONAL_DEX_WHISMUR,
#if GERMAN
        .categoryName = _("Flüster"),
#else
        .categoryName = _("Whisper"),
#endif
        .height = 6,
        .weight = 163,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es schreit so laut wie ein Düsenjet.\n"
            "Flurmel atmet durch seine Hörkanäle\n"
            "ein und kann daher kontinuierlich\n"
            "schreien, ohne Luft zu holen."),
#else
            "Its cries equal a jet plane in volume.\n"
            "It inhales through its ear canals. Because\n"
            "of this system, it can cry continually\n"
            "without having to catch its breath."),
#endif
        .pokemonScale = 373,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Whismur,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 33),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Whismur,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Whismur,
        .shinyPalette = gMonShinyPalette_Whismur,
        .iconSprite = gMonIcon_Whismur,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Whismur)
        OVERWORLD(
            sPicTable_Whismur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Whismur,
            gShinyOverworldPalette_Whismur
        )
        .levelUpLearnset = sWhismurLevelUpLearnset,
        .teachableLearnset = sWhismurTeachableLearnset,
        .eggMoveLearnset = sWhismurEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_LOUDRED}),
    },

    [SPECIES_LOUDRED] =
    {
        .baseHP        = 84,
        .baseAttack    = 71,
        .baseDefense   = 43,
        .baseSpeed     = 48,
        .baseSpAttack  = 71,
        .baseSpDefense = 43,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 120,
        .expYield = 126,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_NONE, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Krakeelo"),
#else
        .speciesName = _("LOUDRED"),
#endif
        .cryId = CRY_LOUDRED,
        .natDexNum = NATIONAL_DEX_LOUDRED,
#if GERMAN
        .categoryName = _("Lauthals"),
#else
        .categoryName = _("Big Voice"),
#endif
        .height = 10,
        .weight = 405,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es richtet die runden Lautsprecher auf\n"
        "seinem Kopf so aus, dass es Gegner mit\n"
        "Ultraschallwellen in großer Lautstärke\n"
        "angreifen kann. Stampfen gibt ihm Kraft."),
#else
            "It positions the round speakers on its\n"
            "head to assail foes with ultrasonic waves\n"
            "at massive volume. It builds power by\n"
            "stomping the ground."),
#endif
        .pokemonScale = 356,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Loudred,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 33),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW : ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Loudred,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Loudred,
        .shinyPalette = gMonShinyPalette_Loudred,
        .iconSprite = gMonIcon_Loudred,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Loudred)
        OVERWORLD(
            sPicTable_Loudred,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Loudred,
            gShinyOverworldPalette_Loudred
        )
        .levelUpLearnset = sLoudredLevelUpLearnset,
        .teachableLearnset = sLoudredTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_EXPLOUD}),
    },

    [SPECIES_EXPLOUD] =
    {
        .baseHP        = 104,
        .baseAttack    = 91,
        .baseDefense   = 63,
        .baseSpeed     = 68,
        .baseSpAttack  = 91,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 73 : 63,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 245,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 221,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 216,
    #else
        .expYield = 184,
    #endif
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_FIELD),
        .abilities = { ABILITY_SOUNDPROOF, ABILITY_NONE, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Krawumms"),
#else
        .speciesName = _("EXPLOUD"),
#endif
        .cryId = CRY_EXPLOUD,
        .natDexNum = NATIONAL_DEX_EXPLOUD,
#if GERMAN
        .categoryName = _("Krach"),
#else
        .categoryName = _("Loud Noise"),
#endif
        .height = 15,
        .weight = 840,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sein Körper ist angefüllt mit geräusch-\n"
            "produzierenden Organen. Es kommuniziert\n"
            "mit Artgenossen, indem es die Tonlage\n"
            "und Lautstärke seiner Schreie ändert."),
#else
            "It has sound-generating organs all over\n"
            "its body. It communicates with others by\n"
            "adjusting the tone and volume of the cries\n"
            "it emits."),
#endif
        .pokemonScale = 284,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Exploud,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 9),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Exploud,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Exploud,
        .shinyPalette = gMonShinyPalette_Exploud,
        .iconSprite = gMonIcon_Exploud,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_L)
        FOOTPRINT(Exploud)
        OVERWORLD(
            sPicTable_Exploud,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Exploud,
            gShinyOverworldPalette_Exploud
        )
        .levelUpLearnset = sExploudLevelUpLearnset,
        .teachableLearnset = sExploudTeachableLearnset,
    },
#endif //P_FAMILY_WHISMUR

#if P_FAMILY_MAKUHITA
    [SPECIES_MAKUHITA] =
    {
        .baseHP        = 72,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 25,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 180,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 47 : 87,
        .evYield_HP = 1,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_THICK_FAT, ABILITY_GUTS, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Makuhita"),
#else
        .speciesName = _("MAKUHITA"),
#endif
        .cryId = CRY_MAKUHITA,
        .natDexNum = NATIONAL_DEX_MAKUHITA,
#if GERMAN
        .categoryName = _("Courage"),
#else
        .categoryName = _("Guts"),
#endif
        .height = 10,
        .weight = 864,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es liebt es, seinen Körper zu stählen.\n"
        "Falls du erdbebenartige Geräusche\n"
        "aus einer Höhle hörst, ist es bestimmt\n"
        "ein Makuhita, das intensiv trainiert."),
#else
            "It loves to toughen up its body above all\n"
            "else. If you hear quaking rumbles in a cave,\n"
            "it is the sound of Makuhita undertaking\n"
            "strenuous training."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Makuhita,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE : ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Makuhita,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Makuhita,
        .shinyPalette = gMonShinyPalette_Makuhita,
        .iconSprite = gMonIcon_Makuhita,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 5, SHADOW_SIZE_M)
        FOOTPRINT(Makuhita)
        OVERWORLD(
            sPicTable_Makuhita,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Makuhita,
            gShinyOverworldPalette_Makuhita
        )
        .levelUpLearnset = sMakuhitaLevelUpLearnset,
        .teachableLearnset = sMakuhitaTeachableLearnset,
        .eggMoveLearnset = sMakuhitaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_HARIYAMA}),
    },

    [SPECIES_HARIYAMA] =
    {
        .baseHP        = 144,
        .baseAttack    = 120,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 184,
        .evYield_HP = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_THICK_FAT, ABILITY_GUTS, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Hariyama"),
#else
        .speciesName = _("HARIYAMA"),
#endif
        .cryId = CRY_HARIYAMA,
        .natDexNum = NATIONAL_DEX_HARIYAMA,
#if GERMAN
        .categoryName = _("Armwurf"),
#else
        .categoryName = _("Arm Thrust"),
#endif
        .height = 23,
        .weight = 2538,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es zögert es nicht, andere zu einem\n"
        "Kraftvergleich herauszufordern. Es ist\n"
        "dafür bekannt, sich auf Gleise zu stellen\n"
        "und Züge mit Armstößen aufzuhalten."),
#else
            "It has the habit of challenging others\n"
            "without hesitation to tests of strength.\n"
            "It's been known to stand on train tracks\n"
            "and stop trains using forearm thrusts."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 343,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Hariyama,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_ROTATE_UP_TO_SIDES,
        .backPic = gMonBackPic_Hariyama,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Hariyama,
        .shinyPalette = gMonShinyPalette_Hariyama,
        .iconSprite = gMonIcon_Hariyama,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 9, SHADOW_SIZE_L)
        FOOTPRINT(Hariyama)
        OVERWORLD(
            sPicTable_Hariyama,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hariyama,
            gShinyOverworldPalette_Hariyama
        )
        .levelUpLearnset = sHariyamaLevelUpLearnset,
        .teachableLearnset = sHariyamaTeachableLearnset,
    },
#endif //P_FAMILY_MAKUHITA

#if P_FAMILY_NOSEPASS
    [SPECIES_NOSEPASS] =
    {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 135,
        .baseSpeed     = 30,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 75 : 108,
        .evYield_Defense = 1,
        .itemRare = ITEM_MAGNET,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STURDY, ABILITY_MAGNET_PULL, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Nasgnet"),
#else
        .speciesName = _("NOSEPASS"),
#endif
        .cryId = CRY_NOSEPASS,
        .natDexNum = NATIONAL_DEX_NOSEPASS,
#if GERMAN
        .categoryName = _("Kompass"),
#else
        .categoryName = _("Compass"),
#endif
        .height = 10,
        .weight = 970,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sein Körper ist stark magnetisch. Nasgnet\n"
            "ernährt sich von Beute, die es mit Gewalt\n"
            "heranzieht. Im Winter ist sein Magnetfeld\n"
            "stärker."),
#else
            "Its body emits a powerful magnetism.\n"
            "It feeds on prey that is pulled in by the\n"
            "force. Its magnetism is stronger in cold\n"
            "seasons."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 9,
        .trainerScale = 289,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Nosepass,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 27),
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 27),
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 27),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW : ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Nosepass,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Nosepass,
        .shinyPalette = gMonShinyPalette_Nosepass,
        .iconSprite = gMonIcon_Nosepass,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_M)
        FOOTPRINT(Nosepass)
        OVERWORLD(
            sPicTable_Nosepass,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nosepass,
            gShinyOverworldPalette_Nosepass
        )
        .levelUpLearnset = sNosepassLevelUpLearnset,
        .teachableLearnset = sNosepassTeachableLearnset,
        .eggMoveLearnset = sNosepassEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_PROBOPASS, CONDITIONS({IF_IN_MAPSEC, MAPSEC_ROUTE_10})},
                                {EVO_LEVEL, 0, SPECIES_PROBOPASS, CONDITIONS({IF_IN_MAPSEC, MAPSEC_POWER_PLANT})},
                                {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_PROBOPASS}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_PROBOPASS] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 145,
        .baseSpeed     = 40,
        .baseSpAttack  = 75,
        .baseSpDefense = 150,
        .types = MON_TYPES(TYPE_ROCK, TYPE_STEEL),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 184 : 198,
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_MAGNET,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STURDY, ABILITY_MAGNET_PULL, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Voluminas"),
#else
        .speciesName = _("PROBOPASS"),
#endif
        .cryId = CRY_PROBOPASS,
        .natDexNum = NATIONAL_DEX_PROBOPASS,
#if GERMAN
        .categoryName = _("Kompass"),
#else
        .categoryName = _("Compass"),
#endif
        .height = 14,
        .weight = 3400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Um aus drei Richtungen anzugreifen,\n"
            "steuert es drei kleine Einheiten,\n"
            "die Mininasen genannt werden."),
#else
            "It freely controls three units called\n"
            "Mini-Noses using magnetic force.\n"
            "With them, it can attack its foes from\n"
            "three directions."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Probopass,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Probopass,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Probopass,
        .shinyPalette = gMonShinyPalette_Probopass,
        .iconSprite = gMonIcon_Probopass,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_L)
        FOOTPRINT(Probopass)
        OVERWORLD(
            sPicTable_Probopass,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Probopass,
            gShinyOverworldPalette_Probopass
        )
        .levelUpLearnset = sProbopassLevelUpLearnset,
        .teachableLearnset = sProbopassTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_NOSEPASS

#if P_FAMILY_SKITTY
    [SPECIES_SKITTY] =
    {
        .baseHP        = 50,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 52 : 65,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NORMALIZE, ABILITY_WONDER_SKIN },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_WONDER_SKIN },
    #endif
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Eneco"),
#else
        .speciesName = _("SKITTY"),
#endif
        .cryId = CRY_SKITTY,
        .natDexNum = NATIONAL_DEX_SKITTY,
#if GERMAN
        .categoryName = _("Kätzchen"),
#else
        .categoryName = _("Kitten"),
#endif
        .height = 6,
        .weight = 110,
        .description = COMPOUND_STRING(
#if GERMAN
        "Aufgrund seines niedlichen Verhaltens\n"
        "ist es sehr beliebt. Im Kampf schlägt\n"
        "es mit dem Schweif zu. Durch grimmiges\n"
        "Fauchen schüchtert es den Feind ein."),
#else
            "A Skitty's adorably cute behavior makes it\n"
            "highly popular. In battle, it makes its tail\n"
            "puff out. It threatens foes with a sharp\n"
            "growl."),
#endif
        .pokemonScale = 492,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Skitty,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 9),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Skitty,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 6,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Skitty,
        .shinyPalette = gMonShinyPalette_Skitty,
        .iconSprite = gMonIcon_Skitty,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 1, SHADOW_SIZE_S)
        FOOTPRINT(Skitty)
        OVERWORLD(
            sPicTable_Skitty,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Skitty,
            gShinyOverworldPalette_Skitty
        )
        .levelUpLearnset = sSkittyLevelUpLearnset,
        .teachableLearnset = sSkittyTeachableLearnset,
        .eggMoveLearnset = sSkittyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_DELCATTY}),
    },

    [SPECIES_DELCATTY] =
    {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = P_UPDATED_STATS >= GEN_7 ? 90 : 70,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 60,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 140,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 133,
    #else
        .expYield = 138,
    #endif
        .evYield_HP = 1,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NORMALIZE, ABILITY_WONDER_SKIN },
    #else
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_WONDER_SKIN },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Enekoro"),
#else
        .speciesName = _("DELCATTY"),
#endif
        .cryId = CRY_DELCATTY,
        .natDexNum = NATIONAL_DEX_DELCATTY,
#if GERMAN
        .categoryName = _("Eingebildet"),
#else
        .categoryName = _("Prim"),
#endif
        .height = 11,
        .weight = 326,
        .description = COMPOUND_STRING(
#if GERMAN
        "Enekoro hat keinen festen Schlafplatz,\n"
        "sondern sucht sich gewöhnlich ein\n"
        "gemütliches Plätzchen und schläft dort.\n"
        "Es wird bei Einbruch der Dunkelheit aktiv."),
#else
            "Rather than keeping a permanent lair,\n"
            "it habitually seeks comfortable spots and\n"
            "sleeps there. It is nocturnal and becomes\n"
            "active at dusk."),
#endif
        .pokemonScale = 322,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Delcatty,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 46),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Delcatty,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Delcatty,
        .shinyPalette = gMonShinyPalette_Delcatty,
        .iconSprite = gMonIcon_Delcatty,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_S)
        FOOTPRINT(Delcatty)
        OVERWORLD(
            sPicTable_Delcatty,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Delcatty,
            gShinyOverworldPalette_Delcatty
        )
        .levelUpLearnset = sDelcattyLevelUpLearnset,
        .teachableLearnset = sDelcattyTeachableLearnset,
    },
#endif //P_FAMILY_SKITTY

#if P_FAMILY_SABLEYE
    [SPECIES_SABLEYE] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DARK, TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 133 : 98,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .itemRare = ITEM_WIDE_LENS,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_KEEN_EYE, ABILITY_STALL, ABILITY_PRANKSTER },
    #else
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_PRANKSTER },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Zobiris"),
#else
        .speciesName = _("SABLEYE"),
#endif
        .cryId = CRY_SABLEYE,
        .natDexNum = NATIONAL_DEX_SABLEYE,
#if GERMAN
        .categoryName = _("Finsternis"),
#else
        .categoryName = _("Darkness"),
#endif
        .height = 5,
        .weight = 110,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit seinen scharfen Klauen gräbt es\n"
            "Abzweigungen in Höhlen, um nach Futter\n"
            "- seltene Edelsteine - zu suchen. Zobiris\n"
            "lauert im Dunkeln und man sieht es selten."),
#else
            "It digs branching holes in caves using its\n"
            "sharp claws in search of food--raw gems.\n"
            "A Sableye lurks in darkness and is seen\n"
            "only rarely."),
#endif
        .pokemonScale = 451,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sableye,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GLOW_BLACK,
        .backPic = gMonBackPic_Sableye,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 13,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Sableye,
        .shinyPalette = gMonShinyPalette_Sableye,
        .iconSprite = gMonIcon_Sableye,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(2, 3, SHADOW_SIZE_S)
        FOOTPRINT(Sableye)
        OVERWORLD(
            sPicTable_Sableye,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sableye,
            gShinyOverworldPalette_Sableye
        )
        .levelUpLearnset = sSableyeLevelUpLearnset,
        .teachableLearnset = sSableyeTeachableLearnset,
        .eggMoveLearnset = sSableyeEggMoveLearnset,
        .formSpeciesIdTable = sSableyeFormSpeciesIdTable,
        .formChangeTable = sSableyeFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_SABLEYE_MEGA] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 125,
        .baseSpeed     = 20,
        .baseSpAttack  = 85,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_DARK, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Zobiris"),
#else
        .speciesName = _("SABLEYE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SABLEYE_MEGA,
    #else
        .cryId = CRY_SABLEYE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SABLEYE,
#if GERMAN
        .categoryName = _("Finsternis"),
#else
        .categoryName = _("Darkness"),
#endif
        .height = 5,
        .weight = 1610,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Mega-Entwicklung wurde das\n"
        "Juwel auf seiner Brust so groß, dass es\n"
        "sich durch seine Haut schnitt und vom\n"
        "Körper löste."),
#else
            "Bathed in the energy of Mega Evolution,\n"
            "the gemstone on its chest expands, rips\n"
            "through its skin, and falls out."),
#endif
        .pokemonScale = 451,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SableyeMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SableyeMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_SableyeMega,
        .shinyPalette = gMonShinyPalette_SableyeMega,
        .iconSprite = gMonIcon_SableyeMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(3, 7, SHADOW_SIZE_S)
        FOOTPRINT(Sableye)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SableyeMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_SableyeMega,
            gShinyOverworldPalette_SableyeMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSableyeLevelUpLearnset,
        .teachableLearnset = sSableyeTeachableLearnset,
        .eggMoveLearnset = sSableyeEggMoveLearnset,
        .formSpeciesIdTable = sSableyeFormSpeciesIdTable,
        .formChangeTable = sSableyeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_SABLEYE

#if P_FAMILY_MAWILE

    [SPECIES_MAWILE] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
    #if P_UPDATED_TYPES >= GEN_6
        .types = MON_TYPES(TYPE_STEEL, TYPE_FAIRY),
    #else
        .types = MON_TYPES(TYPE_STEEL),
    #endif
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 133 : 98,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .itemRare = ITEM_IRON_BALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_INTIMIDATE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Flunkifer"),
#else
        .speciesName = _("MAWILE"),
#endif
        .cryId = CRY_MAWILE,
        .natDexNum = NATIONAL_DEX_MAWILE,
#if GERMAN
        .categoryName = _("Schwindler"),
#else
        .categoryName = _("Deceiver"),
#endif
        .height = 6,
        .weight = 115,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seine gewaltigen Kiefer sind eigentlich\n"
            "Stahlhörner. Es ruft bei Feinden mit seinen\n"
            "anmutigen Gesten Selbstgefälligkeit her-\n"
            "vor und schnappt dann mit seinem Maul zu."),
#else
            "Its giant jaws are actually steel horns\n"
            "that transformed. It fools foes into\n"
            "complacency with its adorable gestures,\n"
            "then chomps them with its huge jaws."),
#endif
        .pokemonScale = 466,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mawile,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Mawile,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Mawile,
        .shinyPalette = gMonShinyPalette_Mawile,
        .iconSprite = gMonIcon_Mawile,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 4, SHADOW_SIZE_L)
        FOOTPRINT(Mawile)
        OVERWORLD(
            sPicTable_Mawile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mawile,
            gShinyOverworldPalette_Mawile
        )
        .levelUpLearnset = sMawileLevelUpLearnset,
        .teachableLearnset = sMawileTeachableLearnset,
        .eggMoveLearnset = sMawileEggMoveLearnset,
        .formSpeciesIdTable = sMawileFormSpeciesIdTable,
        .formChangeTable = sMawileFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_MAWILE_MEGA] =
    {
        .baseHP        = 50,
        .baseAttack    = 105,
        .baseDefense   = 125,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_STEEL, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HUGE_POWER, ABILITY_HUGE_POWER, ABILITY_HUGE_POWER },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Flunkifer"),
#else
        .speciesName = _("MAWILE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_MAWILE_MEGA,
    #else
        .cryId = CRY_MAWILE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_MAWILE,
#if GERMAN
        .categoryName = _("Schwindel"),
#else
        .categoryName = _("Deceiver"),
#endif
        .height = 10,
        .weight = 235,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein äußerst angriffslustiges Pokémon,\n"
        "das seine Beute mit der geballten\n"
        "Kraft seiner beiden Kiefer zerreißt."),
#else
            "Its two sets of jaws thrash about\n"
            "violently as if they each had a will of\n"
            "their own. One gnash from them can turn a\n"
            "boulder to dust."),
#endif
        .pokemonScale = 466,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MawileMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MawileMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_MawileMega,
        .shinyPalette = gMonShinyPalette_MawileMega,
        .iconSprite = gMonIcon_MawileMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Mawile)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_MawileMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MawileMega,
            gShinyOverworldPalette_MawileMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sMawileLevelUpLearnset,
        .teachableLearnset = sMawileTeachableLearnset,
        .eggMoveLearnset = sMawileEggMoveLearnset,
        .formSpeciesIdTable = sMawileFormSpeciesIdTable,
        .formChangeTable = sMawileFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MAWILE

#if P_FAMILY_ARON
    [SPECIES_ARON] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 100,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_STEEL, TYPE_ROCK),
        .catchRate = 180,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 96,
        .evYield_Defense = 1,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Stollunior"),
#else
        .speciesName = _("ARON"),
#endif
        .cryId = CRY_ARON,
        .natDexNum = NATIONAL_DEX_ARON,
#if GERMAN
        .categoryName = _("Eisenpanzer"),
#else
        .categoryName = _("Iron Armor"),
#endif
        .height = 4,
        .weight = 600,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es steckt in einem Stahlpanzer. Bei der\n"
            "Entwicklung entsteht ein neuer Panzer.\n"
            "Der abgeworfene Panzer wird eingesammelt,\n"
            "um aus ihm Eisenwaren herzustellen."),
#else
            "A Pokémon that is clad in steel armor.\n"
            "A new suit of armor is made when it evolves.\n"
            "The old, discarded armor is salvaged as\n"
            "metal for making iron products."),
#endif
        .pokemonScale = 419,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Aron,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 24) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 33),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 33),
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Aron,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 12,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Aron,
        .shinyPalette = gMonShinyPalette_Aron,
        .iconSprite = gMonIcon_Aron,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, -3, SHADOW_SIZE_S)
        FOOTPRINT(Aron)
        OVERWORLD(
            sPicTable_Aron,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Aron,
            gShinyOverworldPalette_Aron
        )
        .levelUpLearnset = sAronLevelUpLearnset,
        .teachableLearnset = sAronTeachableLearnset,
        .eggMoveLearnset = sAronEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_LAIRON}),
    },

    [SPECIES_LAIRON] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_STEEL, TYPE_ROCK),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 151 : 152,
        .evYield_Defense = 2,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Stollrak"),
#else
        .speciesName = _("LAIRON"),
#endif
        .cryId = CRY_LAIRON,
        .natDexNum = NATIONAL_DEX_LAIRON,
#if GERMAN
        .categoryName = _("Eisenpanzer"),
#else
        .categoryName = _("Iron Armor"),
#endif
        .height = 9,
        .weight = 1200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Treffen zwei Stollrak in der Wildnis auf-\n"
            "einander, kämpfen sie um ihr Gebiet, indem\n"
            "sie sich mit ihren Stahlkörpern beharken.\n"
            "Dieses Geräusch ist meilenweit zu hören."),
#else
            "When two Lairon meet in the wild, they\n"
            "fight for territory by bashing into each\n"
            "other with their steel bodies. The sound\n"
            "of their collision carries for miles."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lairon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 29),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 29),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lairon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 15,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Lairon,
        .shinyPalette = gMonShinyPalette_Lairon,
        .iconSprite = gMonIcon_Lairon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 2, SHADOW_SIZE_L)
        FOOTPRINT(Lairon)
        OVERWORLD(
            sPicTable_Lairon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lairon,
            gShinyOverworldPalette_Lairon
        )
        .levelUpLearnset = sLaironLevelUpLearnset,
        .teachableLearnset = sLaironTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_AGGRON}),
    },

    [SPECIES_AGGRON] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 180,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_STEEL, TYPE_ROCK),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 205,
    #endif
        .evYield_Defense = 3,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_STURDY, ABILITY_ROCK_HEAD, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Stolloss"),
#else
        .speciesName = _("AGGRON"),
#endif
        .cryId = CRY_AGGRON,
        .natDexNum = NATIONAL_DEX_AGGRON,
#if GERMAN
        .categoryName = _("Eisenpanzer"),
#else
        .categoryName = _("Iron Armor"),
#endif
        .height = 21,
        .weight = 3600,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es Stahlhörner werden ständig ein wenig\n"
        "länger. Daran kann man sein Alter ablesen.\n"
        "Die Kratzer und Abschürfungen in seinem\n"
        "Panzer sind stolze Andenken an Kämpfe."),
#else
            "Its iron horns grow longer a little at\n"
            "a time. They are used to determine the\n"
            "Aggron's age. The gouges in its armor are\n"
            "worn with pride as mementos from battles."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 350,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Aggron,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Aggron,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 5,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Aggron,
        .shinyPalette = gMonShinyPalette_Aggron,
        .iconSprite = gMonIcon_Aggron,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 12, SHADOW_SIZE_L)
        FOOTPRINT(Aggron)
        OVERWORLD(
            sPicTable_Aggron,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Aggron,
            gShinyOverworldPalette_Aggron
        )
        .levelUpLearnset = sAggronLevelUpLearnset,
        .teachableLearnset = sAggronTeachableLearnset,
        .formSpeciesIdTable = sAggronFormSpeciesIdTable,
        .formChangeTable = sAggronFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AGGRON_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 140,
        .baseDefense   = 230,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 315 : 284,
        .evYield_Defense = 3,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 35,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER),
        .abilities = { ABILITY_FILTER, ABILITY_FILTER, ABILITY_FILTER },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Stolloss"),
#else
        .speciesName = _("AGGRON"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_AGGRON_MEGA,
    #else
        .cryId = CRY_AGGRON,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_AGGRON,
#if GERMAN
        .categoryName = _("Eisenpanzer"),
#else
        .categoryName = _("Iron Armor"),
#endif
        .height = 22,
        .weight = 3950,
        .description = COMPOUND_STRING(
#if GERMAN
        "Das Eisen in seinem Körper wurde durch die\n"
        "Energie der Mega-Entwicklung zu einem\n"
        "Panzer aus Stahl, der seinen ganzen Körper\n"
        "bedeckt."),
#else
            "When Aggron Mega Evolves into\n"
            "Mega Aggron, the destructive ability of\n"
            "its fearsome horns can turn a steel-clad\n"
            "tank into so much scrap metal."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = -1,
        .trainerScale = 350,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_AggronMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AggronMega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_AggronMega,
        .shinyPalette = gMonShinyPalette_AggronMega,
        .iconSprite = gMonIcon_AggronMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Aggron)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AggronMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_AggronMega,
            gShinyOverworldPalette_AggronMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAggronLevelUpLearnset,
        .teachableLearnset = sAggronTeachableLearnset,
        .formSpeciesIdTable = sAggronFormSpeciesIdTable,
        .formChangeTable = sAggronFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_ARON

#if P_FAMILY_MEDITITE
    [SPECIES_MEDITITE] =
    {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_PSYCHIC),
        .catchRate = 180,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 56 : 91,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PURE_POWER, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Meditie"),
#else
        .speciesName = _("MEDITITE"),
#endif
        .cryId = CRY_MEDITITE,
        .natDexNum = NATIONAL_DEX_MEDITITE,
#if GERMAN
        .categoryName = _("Meditation"),
#else
        .categoryName = _("Meditate"),
#endif
        .height = 6,
        .weight = 112,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es meditiert kontinuierlich mehrere\n"
            "Stunden täglich. Das Ergebnis seines\n"
            "hingebungsvollen Yogatrainings ist, dass\n"
            "es mittels seiner Psykräfte fliegen kann."),
#else
            "It continually meditates for hours every\n"
            "day. As a result of rigorous and dedicated\n"
            "yoga training, it has tempered its\n"
            "spiritual power so much it can fly."),
#endif
        .pokemonScale = 465,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Meditite,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES,
        .backPic = gMonBackPic_Meditite,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Meditite,
        .shinyPalette = gMonShinyPalette_Meditite,
        .iconSprite = gMonIcon_Meditite,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_MedititeF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 48),
        .backPicFemale = gMonBackPic_MedititeF,
        .backPicSizeFemale = MON_COORDS_SIZE(48, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Meditite)
        OVERWORLD(
            sPicTable_Meditite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Meditite,
            gShinyOverworldPalette_Meditite
        )
        OVERWORLD_FEMALE(
            sPicTable_MedititeF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sMedititeLevelUpLearnset,
        .teachableLearnset = sMedititeTeachableLearnset,
        .eggMoveLearnset = sMedititeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_MEDICHAM}),
    },

    [SPECIES_MEDICHAM] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 80,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_PSYCHIC),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 144 : 153,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PURE_POWER, ABILITY_NONE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Meditalis"),
#else
        .speciesName = _("MEDICHAM"),
#endif
        .cryId = CRY_MEDICHAM,
        .natDexNum = NATIONAL_DEX_MEDICHAM,
#if GERMAN
        .categoryName = _("Meditation"),
#else
        .categoryName = _("Meditate"),
#endif
        .height = 13,
        .weight = 315,
        .description = COMPOUND_STRING(
#if GERMAN
            "Durch erbittertes Yogatraining kann es\n"
            "die Angriffe seiner Feinde vorhersehen.\n"
            "Sein Kampfstil ist anmutig und ähnelt\n"
            "einem Tanz."),
#else
            "Through crushingly harsh yoga training, it\n"
            "gained the power to foretell its foe's\n"
            "actions. It battles with elegant, dance-\n"
            "like movement."),
#endif
        .pokemonScale = 298,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Medicham,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 64) : MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Medicham,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Medicham,
        .shinyPalette = gMonShinyPalette_Medicham,
        .iconSprite = gMonIcon_Medicham,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_MedichamF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 64),
        .backPicFemale = gMonBackPic_MedichamF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_S)
        FOOTPRINT(Medicham)
        OVERWORLD(
            sPicTable_Medicham,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Medicham,
            gShinyOverworldPalette_Medicham
        )
        OVERWORLD_FEMALE(
            sPicTable_MedichamF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sMedichamLevelUpLearnset,
        .teachableLearnset = sMedichamTeachableLearnset,
        .formSpeciesIdTable = sMedichamFormSpeciesIdTable,
        .formChangeTable = sMedichamFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_MEDICHAM_MEGA] =
    {
        .baseHP        = 60,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_PSYCHIC),
        .catchRate = 90,
        .expYield = 179,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PURE_POWER, ABILITY_PURE_POWER, ABILITY_PURE_POWER },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Meditalis"),
#else
        .speciesName = _("MEDICHAM"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_MEDICHAM_MEGA,
    #else
        .cryId = CRY_MEDICHAM,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_MEDICHAM,
#if GERMAN
        .categoryName = _("Meditation"),
#else
        .categoryName = _("Meditate"),
#endif
        .height = 13,
        .weight = 315,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Mega-Entwicklung ließ\n"
        "seine geistige Kraft ins Unermessliche\n"
        "wachsen. Gegner schaltet es aus, indem\n"
        "es blutrünstige Arme heraufbeschwört."),
#else
            "It uses its amped-up willpower to create\n"
            "additional arms for itself. The more it\n"
            "has trained its spirit, the more realistic\n"
            "and dexterous these arms become."),
#endif
        .pokemonScale = 298,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MedichamMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MedichamMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_MedichamMega,
        .shinyPalette = gMonShinyPalette_MedichamMega,
        .iconSprite = gMonIcon_MedichamMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_S)
        FOOTPRINT(Medicham)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_MedichamMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MedichamMega,
            gShinyOverworldPalette_MedichamMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sMedichamLevelUpLearnset,
        .teachableLearnset = sMedichamTeachableLearnset,
        .formSpeciesIdTable = sMedichamFormSpeciesIdTable,
        .formChangeTable = sMedichamFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_MEDITITE

#if P_FAMILY_ELECTRIKE
    [SPECIES_ELECTRIKE] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 59 : 104,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_LIGHTNING_ROD, ABILITY_MINUS },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Frizelbliz"),
#else
        .speciesName = _("ELECTRIKE"),
#endif
        .cryId = CRY_ELECTRIKE,
        .natDexNum = NATIONAL_DEX_ELECTRIKE,
#if GERMAN
        .categoryName = _("Gewitter"),
#else
        .categoryName = _("Lightning"),
#endif
        .height = 6,
        .weight = 152,
        .description = COMPOUND_STRING(
#if GERMAN
            "Aus der Reibung der Atmosphäre generiert\n"
            "es Elektrizität. Wenn die Luft besonders\n"
            "trocken ist, glüht sein ganzer Körper vor\n"
            "elektrischen Funken."),
#else
            "It generates electricity using friction\n"
            "from the atmosphere. In seasons with\n"
            "especially arid air, its entire body blazes\n"
            "with violent showers of sparks."),
#endif
        .pokemonScale = 290,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Electrike,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 32) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 17),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Electrike,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Electrike,
        .shinyPalette = gMonShinyPalette_Electrike,
        .iconSprite = gMonIcon_Electrike,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(3, -1, SHADOW_SIZE_M)
        FOOTPRINT(Electrike)
        OVERWORLD(
            sPicTable_Electrike,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Electrike,
            gShinyOverworldPalette_Electrike
        )
        .levelUpLearnset = sElectrikeLevelUpLearnset,
        .teachableLearnset = sElectrikeTeachableLearnset,
        .eggMoveLearnset = sElectrikeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_MANECTRIC}),
    },

    [SPECIES_MANECTRIC] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 105,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 168,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_LIGHTNING_ROD, ABILITY_MINUS },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Voltenso"),
#else
        .speciesName = _("MANECTRIC"),
#endif
        .cryId = CRY_MANECTRIC,
        .natDexNum = NATIONAL_DEX_MANECTRIC,
#if GERMAN
        .categoryName = _("Entladung"),
#else
        .categoryName = _("Discharge"),
#endif
        .height = 15,
        .weight = 402,
        .description = COMPOUND_STRING(
#if GERMAN
            "Da Gewitter ständig in seiner Nähe\n"
            "auftauchen, nahm man an, dass\n"
            "Voltenso in Gewittern geboren wird.\n"
            "Im Kampf generiert es Donnerwolken."),
#else
            "Because lightning falls in their vicinities,\n"
            "Manectric were thought to have been born\n"
            "from lightning. In battle, they create\n"
            "thunderclouds."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Manectric,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 56) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 33),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Manectric,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Manectric,
        .shinyPalette = gMonShinyPalette_Manectric,
        .iconSprite = gMonIcon_Manectric,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_M)
        FOOTPRINT(Manectric)
        OVERWORLD(
            sPicTable_Manectric,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Manectric,
            gShinyOverworldPalette_Manectric
        )
        .levelUpLearnset = sManectricLevelUpLearnset,
        .teachableLearnset = sManectricTeachableLearnset,
        .formSpeciesIdTable = sManectricFormSpeciesIdTable,
        .formChangeTable = sManectricFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_MANECTRIC_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 135,
        .baseSpAttack  = 135,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = 201,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_INTIMIDATE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Voltenso"),
#else
        .speciesName = _("MANECTRIC"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_MANECTRIC_MEGA,
    #else
        .cryId = CRY_MANECTRIC,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_MANECTRIC,
#if GERMAN
        .categoryName = _("Entladung"),
#else
        .categoryName = _("Discharge"),
#endif
        .height = 18,
        .weight = 440,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Mega-Entwicklung sammelt\n"
        "sich in seinem Körper mehr elektrische\n"
        "Energie an, als es verbrauchen kann."),
#else
            "Too much electricity has built up in its\n"
            "body, irritating Manectric. Its explosive\n"
            "speed is equal to that of a lightning bolt."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ManectricMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ManectricMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_ManectricMega,
        .shinyPalette = gMonShinyPalette_ManectricMega,
        .iconSprite = gMonIcon_ManectricMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_L)
        FOOTPRINT(Manectric)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_ManectricMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ManectricMega,
            gShinyOverworldPalette_ManectricMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sManectricLevelUpLearnset,
        .teachableLearnset = sManectricTeachableLearnset,
        .formSpeciesIdTable = sManectricFormSpeciesIdTable,
        .formChangeTable = sManectricFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_ELECTRIKE

#if P_FAMILY_PLUSLE
    [SPECIES_PLUSLE] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 95,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 120,
        .evYield_Speed = 1,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_PLUS, ABILITY_NONE, ABILITY_LIGHTNING_ROD },
    #else
        .abilities = { ABILITY_PLUS, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Plusle"),
#else
        .speciesName = _("PLUSLE"),
#endif
        .cryId = CRY_PLUSLE,
        .natDexNum = NATIONAL_DEX_PLUSLE,
#if GERMAN
        .categoryName = _("Jubel"),
#else
        .categoryName = _("Cheering"),
#endif
        .height = 4,
        .weight = 42,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es spornt seine Mitstreiter an. Plusle\n"
            "entlädt Elektrizität aus seinen\n"
            "Handflächen und generiert so Pompons\n"
            "zum Anfeuern."),
#else
            "It has the trait of cheering on its fellow\n"
            "Pokémon. By shorting out the electricity\n"
            "it releases from its paws, it creates\n"
            "pom-poms for cheering."),
#endif
        .pokemonScale = 515,
        .pokemonOffset = -9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Plusle,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SQUISH_AND_BOUNCE : ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Plusle,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Plusle,
        .shinyPalette = gMonShinyPalette_Plusle,
        .iconSprite = gMonIcon_Plusle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 3, SHADOW_SIZE_S)
        FOOTPRINT(Plusle)
        OVERWORLD(
            sPicTable_Plusle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Plusle,
            gShinyOverworldPalette_Plusle
        )
        .levelUpLearnset = sPlusleLevelUpLearnset,
        .teachableLearnset = sPlusleTeachableLearnset,
        .eggMoveLearnset = sPlusleEggMoveLearnset,
    },
#endif //P_FAMILY_PLUSLE

#if P_FAMILY_MINUN
    [SPECIES_MINUN] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 142 : 120,
        .evYield_Speed = 1,
        .itemRare = ITEM_CELL_BATTERY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_MINUS, ABILITY_NONE, ABILITY_VOLT_ABSORB },
    #else
        .abilities = { ABILITY_MINUS, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Minun"),
#else
        .speciesName = _("MINUN"),
#endif
        .cryId = CRY_MINUN,
        .natDexNum = NATIONAL_DEX_MINUN,
#if GERMAN
        .categoryName = _("Jubel"),
#else
        .categoryName = _("Cheering"),
#endif
        .height = 4,
        .weight = 42,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei einem Kongress von Pokémon-Weisen\n"
            "wurde bekannt gegeben, dass die\n"
            "Elektrizität von Plusle und Minun\n"
            "den Kreislauf und die Vitalität steigert."),
#else
            "At a meeting of Pokémon academics, it was\n"
            "announced that simultaneous exposure to\n"
            "electricity from a Plusle and Minun will\n"
            "promote circulation and boost vitality."),
#endif
        .pokemonScale = 512,
        .pokemonOffset = -7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Minun,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_CIRCULAR_STRETCH_TWICE : ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_Minun,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 4,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Minun,
        .shinyPalette = gMonShinyPalette_Minun,
        .iconSprite = gMonIcon_Minun,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-4, 3, SHADOW_SIZE_S)
        FOOTPRINT(Minun)
        OVERWORLD(
            sPicTable_Minun,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Minun,
            gShinyOverworldPalette_Minun
        )
        .levelUpLearnset = sMinunLevelUpLearnset,
        .teachableLearnset = sMinunTeachableLearnset,
        .eggMoveLearnset = sMinunEggMoveLearnset,
    },
#endif //P_FAMILY_MINUN

#if P_FAMILY_VOLBEAT_ILLUMISE
    [SPECIES_VOLBEAT] =
    {
        .baseHP        = 65,
        .baseAttack    = 73,
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 75 : 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 47,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 85 : 75,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 150,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 151,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 140,
    #else
        .expYield = 146,
    #endif
        .evYield_Speed = 1,
        .itemRare = ITEM_BRIGHT_POWDER,
        .genderRatio = MON_MALE,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_ILLUMINATE, ABILITY_SWARM, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Volbeat"),
#else
        .speciesName = _("VOLBEAT"),
#endif
        .cryId = CRY_VOLBEAT,
        .natDexNum = NATIONAL_DEX_VOLBEAT,
#if GERMAN
        .categoryName = _("Glühwürmchen"),
#else
        .categoryName = _("Firefly"),
#endif
        .height = 7,
        .weight = 177,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit leuchtenden Schwanzenden fliegt\n"
            "Volbeat durch den Nachthimmel und\n"
            "zeichnet dabei geometrische Muster."),
#else
            "With their taillights lit, Volbeat fly in\n"
            "a swarm, drawing geometric designs in the\n"
            "night sky. They move their nests if their\n"
            "pond water becomes dirty."),
#endif
        .pokemonScale = 442,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Volbeat,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Volbeat,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Volbeat,
        .shinyPalette = gMonShinyPalette_Volbeat,
        .iconSprite = gMonIcon_Volbeat,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 5, SHADOW_SIZE_S)
        FOOTPRINT(Volbeat)
        OVERWORLD(
            sPicTable_Volbeat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Volbeat,
            gShinyOverworldPalette_Volbeat
        )
        .levelUpLearnset = sVolbeatLevelUpLearnset,
        .teachableLearnset = sVolbeatTeachableLearnset,
        .eggMoveLearnset = sVolbeatEggMoveLearnset,
    },

    [SPECIES_ILLUMISE] =
    {
        .baseHP        = 65,
        .baseAttack    = 47,
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 75 : 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 73,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 85 : 75,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 150,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 151,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 140,
    #else
        .expYield = 146,
    #endif
        .evYield_Speed = 1,
        .itemRare = ITEM_BRIGHT_POWDER,
        .genderRatio = MON_FEMALE,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_TINTED_LENS, ABILITY_PRANKSTER },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_PRANKSTER },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Illumise"),
#else
        .speciesName = _("ILLUMISE"),
#endif
        .cryId = CRY_ILLUMISE,
        .natDexNum = NATIONAL_DEX_ILLUMISE,
#if GERMAN
        .categoryName = _("Glühwürmchen"),
#else
        .categoryName = _("Firefly"),
#endif
        .height = 6,
        .weight = 177,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es wird mit Einbruch der Nacht aktiv.\n"
            "Illumise führt einen Schwarm Volbeat an\n"
            "und lässt sie Muster in den Nachthimmel\n"
            "zeichnen. Es gibt über 200 Muster."),
#else
            "A nocturnal Pokémon that becomes active\n"
            "upon nightfall. It leads a Volbeat swarm\n"
            "to draw patterns in the night sky. Over 200\n"
            "different patterns have been confirmed."),
#endif
        .pokemonScale = 572,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Illumise,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_BOUNCE_ROTATE_TO_SIDES : ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Illumise,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 8,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Illumise,
        .shinyPalette = gMonShinyPalette_Illumise,
        .iconSprite = gMonIcon_Illumise,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 5, SHADOW_SIZE_S)
        FOOTPRINT(Illumise)
        OVERWORLD(
            sPicTable_Illumise,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Illumise,
            gShinyOverworldPalette_Illumise
        )
        .levelUpLearnset = sIllumiseLevelUpLearnset,
        .teachableLearnset = sIllumiseTeachableLearnset,
        .eggMoveLearnset = sIllumiseEggMoveLearnset,
    },
#endif //P_FAMILY_VOLBEAT_ILLUMISE

#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    [SPECIES_BUDEW] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 56 : 68,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_POISON_POINT, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Knospi"),
#else
        .speciesName = _("BUDEW"),
#endif
        .cryId = CRY_BUDEW,
        .natDexNum = NATIONAL_DEX_BUDEW,
#if GERMAN
        .categoryName = _("Knospe"),
#else
        .categoryName = _("Bud"),
#endif
        .height = 2,
        .weight = 12,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei Sonnenlicht öffnet es seine\n"
            "Knospe und gibt Pollen ab. Es lebt\n"
            "in der Nähe von sauberem Wasser."),
#else
            "Over the winter, it closes its bud and\n"
            "endures the cold. Sensitive to changing\n"
            "temperature, the bud is said to bloom\n"
            "when it feels the sun's warm touch."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Budew,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Budew,
        .backPicSize = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Budew,
        .shinyPalette = gMonShinyPalette_Budew,
        .iconSprite = gMonIcon_Budew,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-3, 0, SHADOW_SIZE_S)
        FOOTPRINT(Budew)
        OVERWORLD(
            sPicTable_Budew,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Budew,
            gShinyOverworldPalette_Budew
        )
        .levelUpLearnset = sBudewLevelUpLearnset,
        .teachableLearnset = sBudewTeachableLearnset,
        .eggMoveLearnset = sBudewEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_ROSELIA, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD},{IF_NOT_TIME, TIME_NIGHT})}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_ROSELIA] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 150,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 140 : 152,
        .evYield_SpAttack = (P_UPDATED_EVS >= GEN_4) ? 2 : 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_POISON_POINT, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Roselia"),
#else
        .speciesName = _("ROSELIA"),
#endif
        .cryId = CRY_ROSELIA,
        .natDexNum = NATIONAL_DEX_ROSELIA,
#if GERMAN
        .categoryName = _("Dorn"),
#else
        .categoryName = _("Thorn"),
#endif
        .height = 3,
        .weight = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Trinkt Roselia nährstoffreiches\n"
            "Quellwasser, trägt es volle Blüte. Der\n"
            "Duft seiner Blüten veranlasst die Feinde,\n"
            "ihre Vorsicht aufzugeben."),
#else
            "A Roselia that drinks nutritionally rich\n"
            "springwater blooms with lovely flowers.\n"
            "The fragrance of its flowers has the\n"
            "effect of making its foes careless."),
#endif
        .pokemonScale = 677,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Roselia,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 18),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Roselia,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_Roselia,
        .shinyPalette = gMonShinyPalette_Roselia,
        .iconSprite = gMonIcon_Roselia,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 4,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_RoseliaF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 48),
        .backPicFemale = gMonBackPic_RoseliaF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, 3, SHADOW_SIZE_S)
        FOOTPRINT(Roselia)
        OVERWORLD(
            sPicTable_Roselia,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Roselia,
            gShinyOverworldPalette_Roselia
        )
        OVERWORLD_FEMALE(
            sPicTable_RoseliaF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym
        )
        .levelUpLearnset = sRoseliaLevelUpLearnset,
        .teachableLearnset = sRoseliaTeachableLearnset,
        .eggMoveLearnset = sRoseliaEggMoveLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_ROSERADE}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_ROSERADE] =
    {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = P_UPDATED_STATS >= GEN_6 ? 65 : 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 125,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 75,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 258,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 232,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 227,
    #else
        .expYield = 204,
    #endif
        .evYield_SpAttack = 3,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_GRASS),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_POISON_POINT, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Roserade"),
#else
        .speciesName = _("ROSERADE"),
#endif
        .cryId = CRY_ROSERADE,
        .natDexNum = NATIONAL_DEX_ROSERADE,
#if GERMAN
        .categoryName = _("Blumenstrauß"),
#else
        .categoryName = _("Bouquet"),
#endif
        .height = 9,
        .weight = 145,
        .description = COMPOUND_STRING(
#if GERMAN
        "Roserade lockt seine Beute mit süßem\n"
        "Duft an und vergiftet sie. Je stärker\n"
        "das Gift, desto stärker sein Duft."),
#else
            "Its sweet aroma attracts prey.\n"
            "With the movements of a dancer,\n"
            "it strikes with whips that are densely\n"
            "lined with poison thorns."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Roserade,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Roserade,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Roserade,
        .shinyPalette = gMonShinyPalette_Roserade,
        .iconSprite = gMonIcon_Roserade,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_RoseradeF,
        .frontPicSizeFemale = MON_COORDS_SIZE(48, 56),
        .backPicFemale = gMonBackPic_RoseradeF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 56),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_S)
        FOOTPRINT(Roserade)
        OVERWORLD(
            sPicTable_Roserade,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Roserade,
            gShinyOverworldPalette_Roserade
        )
        OVERWORLD_FEMALE(
            sPicTable_RoseradeF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym
        )
        .levelUpLearnset = sRoseradeLevelUpLearnset,
        .teachableLearnset = sRoseradeTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_ROSELIA

#if P_FAMILY_GULPIN
    [SPECIES_GULPIN] =
    {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 75,
        .evYield_HP = 1,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LIQUID_OOZE, ABILITY_STICKY_HOLD, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Schluppuck"),
#else
        .speciesName = _("GULPIN"),
#endif
        .cryId = CRY_GULPIN,
        .natDexNum = NATIONAL_DEX_GULPIN,
#if GERMAN
        .categoryName = _("Magen"),
#else
        .categoryName = _("Stomach"),
#endif
        .height = 4,
        .weight = 103,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Magensäure dieses Pokémon ist so\n"
            "stark, dass sie selbst Gusseisen\n"
            "zersetzen kann. Es kann einen Gegenstand\n"
            "seiner Größe auf einmal verschlucken."),
#else
            "This Pokémon's stomach fluid can even\n"
            "digest scrap iron. In one gulp, it can\n"
            "swallow something that is as large as\n"
            "itself."),
#endif
        .pokemonScale = 593,
        .pokemonOffset = 23,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gulpin,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gulpin,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Gulpin,
        .shinyPalette = gMonShinyPalette_Gulpin,
        .iconSprite = gMonIcon_Gulpin,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_GulpinF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_GulpinF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 48),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Gulpin)
        OVERWORLD(
            sPicTable_Gulpin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Gulpin,
            gShinyOverworldPalette_Gulpin
        )
        OVERWORLD_FEMALE(
            sPicTable_GulpinF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sGulpinLevelUpLearnset,
        .teachableLearnset = sGulpinTeachableLearnset,
        .eggMoveLearnset = sGulpinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_SWALOT}),
    },

    [SPECIES_SWALOT] =
    {
        .baseHP        = 100,
        .baseAttack    = 73,
        .baseDefense   = 83,
        .baseSpeed     = 55,
        .baseSpAttack  = 73,
        .baseSpDefense = 83,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 168,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LIQUID_OOZE, ABILITY_STICKY_HOLD, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Schlukwech"),
#else
        .speciesName = _("SWALOT"),
#endif
        .cryId = CRY_SWALOT,
        .natDexNum = NATIONAL_DEX_SWALOT,
#if GERMAN
        .categoryName = _("Giftbeutel"),
#else
        .categoryName = _("Poison Bag"),
#endif
        .height = 17,
        .weight = 800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seine starke Magensäure zersetzt fast\n"
            "alles. Das Einzige auf der Welt, das ein\n"
            "Schlukwech nicht verdauen kann,\n"
            "ist sein eigener Magen."),
#else
            "Its powerful stomach acid is capable of\n"
            "digesting almost anything. The one thing\n"
            "in the whole world a Swalot can't digest is\n"
            "its own stomach."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 345,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Swalot,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Swalot,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swalot,
        .shinyPalette = gMonShinyPalette_Swalot,
        .iconSprite = gMonIcon_Swalot,
        .iconPalIndex = 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_SwalotF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_SwalotF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 3, SHADOW_SIZE_L)
        FOOTPRINT(Swalot)
        OVERWORLD(
            sPicTable_Swalot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Swalot,
            gShinyOverworldPalette_Swalot
        )
        OVERWORLD_FEMALE(
            sPicTable_SwalotF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sSwalotLevelUpLearnset,
        .teachableLearnset = sSwalotTeachableLearnset,
    },
#endif //P_FAMILY_GULPIN

#if P_FAMILY_CARVANHA
    [SPECIES_CARVANHA] =
    {
        .baseHP        = 45,
        .baseAttack    = 90,
        .baseDefense   = 20,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 20,
        .types = MON_TYPES(TYPE_WATER, TYPE_DARK),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 61 : 88,
        .evYield_Attack = 1,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_ROUGH_SKIN, ABILITY_NONE, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Kanivanha"),
#else
        .speciesName = _("CARVANHA"),
#endif
        .cryId = CRY_CARVANHA,
        .natDexNum = NATIONAL_DEX_CARVANHA,
#if GERMAN
        .categoryName = _("Gnadenlos"),
#else
        .categoryName = _("Savage"),
#endif
        .height = 8,
        .weight = 208,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schiffe werden von Kanivanha in Schwär-\n"
            "men angegriffen und versenkt. Obwohl es\n"
            "ein sehr brutales Pokémon sein soll,\n"
            "ergreift es die Flucht, wenn es allein ist."),
#else
            "Carvanha attack ships in swarms, making\n"
            "them sink. Although it is said to be a very\n"
            "vicious Pokémon, it timidly flees as soon\n"
            "as it finds itself alone."),
#endif
        .pokemonScale = 362,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Carvanha,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW,
        .backPic = gMonBackPic_Carvanha,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 10,
        .backAnimId = BACK_ANIM_H_SPRING_REPEATED,
        .palette = gMonPalette_Carvanha,
        .shinyPalette = gMonShinyPalette_Carvanha,
        .iconSprite = gMonIcon_Carvanha,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_S)
        FOOTPRINT(Carvanha)
        OVERWORLD(
            sPicTable_Carvanha,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Carvanha,
            gShinyOverworldPalette_Carvanha
        )
        .levelUpLearnset = sCarvanhaLevelUpLearnset,
        .teachableLearnset = sCarvanhaTeachableLearnset,
        .eggMoveLearnset = sCarvanhaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SHARPEDO}),
    },

    [SPECIES_SHARPEDO] =
    {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 40,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_WATER, TYPE_DARK),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 161 : 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_ROUGH_SKIN, ABILITY_NONE, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Tohaido"),
#else
        .speciesName = _("SHARPEDO"),
#endif
        .cryId = CRY_SHARPEDO,
        .natDexNum = NATIONAL_DEX_SHARPEDO,
        .categoryName = _("Brutal"),
        .height = 18,
        .weight = 888,
        .description = COMPOUND_STRING(
#if GERMAN
            "Der brutale und listige Schurke der See.\n"
            "Seine Haut ist so strukturiert, dass der\n"
            "Wasserwiderstand gering ist. Es kann\n"
            "bis zu 120 km/h schnell schwimmen."),
#else
            "The vicious and sly gangster of the sea.\n"
            "Its skin is specially textured to minimize\n"
            "drag in water. Its speed tops out at over\n"
            "75 miles per hour."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Sharpedo,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH_TWICE,
        .backPic = gMonBackPic_Sharpedo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 3,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Sharpedo,
        .shinyPalette = gMonShinyPalette_Sharpedo,
        .iconSprite = gMonIcon_Sharpedo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Sharpedo)
        OVERWORLD(
            sPicTable_Sharpedo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Sharpedo,
            gShinyOverworldPalette_Sharpedo
        )
        .levelUpLearnset = sSharpedoLevelUpLearnset,
        .teachableLearnset = sSharpedoTeachableLearnset,
        .formSpeciesIdTable = sSharpedoFormSpeciesIdTable,
        .formChangeTable = sSharpedoFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_SHARPEDO_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 140,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 110,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_DARK),
        .catchRate = 60,
        .expYield = 196,
        .evYield_Attack = 2,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_STRONG_JAW, ABILITY_STRONG_JAW, ABILITY_STRONG_JAW },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Tohaido"),
#else
        .speciesName = _("SHARPEDO"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SHARPEDO_MEGA,
    #else
        .cryId = CRY_SHARPEDO,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SHARPEDO,
        .categoryName = _("Brutal"),
        .height = 25,
        .weight = 1303,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei den gelben Mustern handelt es sich um\n"
            "alte Narben, die stark schmerzen, wenn\n"
            "Energie aus der Mega-Entwicklung durch\n"
            "seinen Leib fließt."),
#else
            "The yellow patterns it bears are old scars.\n"
            "The energy from Mega Evolution runs\n"
            "through them, causing it sharp pain and\n"
            "suffering."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 317,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_SharpedoMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 1,
        .backPic = gMonBackPic_SharpedoMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_SharpedoMega,
        .shinyPalette = gMonShinyPalette_SharpedoMega,
        .iconSprite = gMonIcon_SharpedoMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Sharpedo)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SharpedoMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_SharpedoMega,
            gShinyOverworldPalette_SharpedoMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSharpedoLevelUpLearnset,
        .teachableLearnset = sSharpedoTeachableLearnset,
        .formSpeciesIdTable = sSharpedoFormSpeciesIdTable,
        .formChangeTable = sSharpedoFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_CARVANHA

#if P_FAMILY_WAILMER
    [SPECIES_WAILMER] =
    {
        .baseHP        = 130,
        .baseAttack    = 70,
        .baseDefense   = 35,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 125,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 80 : 137,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_WATER_VEIL, ABILITY_OBLIVIOUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Wailmer"),
#else
        .speciesName = _("WAILMER"),
#endif
        .cryId = CRY_WAILMER,
        .natDexNum = NATIONAL_DEX_WAILMER,
#if GERMAN
        .categoryName = _("Kugelwal"),
#else
        .categoryName = _("Ball Whale"),
#endif
        .height = 20,
        .weight = 1300,
        .description = COMPOUND_STRING(
#if GERMAN
        "Obwohl Wailmer normalerweise im Meer lebt,\n"
        "kann es auch an Land überleben, wenn\n"
        "auch nicht sehr lang. Es verliert Lebens-\n"
        "energie, wenn sein Körper austrocknet."),
#else
            "While this Pokémon usually lives in the sea,\n"
            "it can survive on land, although not too\n"
            "long. It loses vitality if its body becomes\n"
            "dried out."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 493,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wailmer,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Wailmer,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 21 : 9,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Wailmer,
        .shinyPalette = gMonShinyPalette_Wailmer,
        .iconSprite = gMonIcon_Wailmer,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_L)
        FOOTPRINT(Wailmer)
        OVERWORLD(
            sPicTable_Wailmer,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Wailmer,
            gShinyOverworldPalette_Wailmer
        )
        .levelUpLearnset = sWailmerLevelUpLearnset,
        .teachableLearnset = sWailmerTeachableLearnset,
        .eggMoveLearnset = sWailmerEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_WAILORD}),
    },

    [SPECIES_WAILORD] =
    {
        .baseHP        = 170,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 90,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 206,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_WATER_VEIL, ABILITY_OBLIVIOUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Wailord"),
#else
        .speciesName = _("WAILORD"),
#endif
        .cryId = CRY_WAILORD,
        .natDexNum = NATIONAL_DEX_WAILORD,
#if GERMAN
        .categoryName = _("Flutwal"),
#else
        .categoryName = _("Float Whale"),
#endif
        .height = 145,
        .weight = 3980,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es atmet durch das Blasloch, das es dazu\n"
            "aus dem Meer erhebt. Wenn es seine Lungen\n"
            "vollständig mit Luft gefüllt hat, kann\n"
            "Wailord bis zu 3000 Meter tief tauchen."),
#else
            "It breathes through nostrils that it\n"
            "raises above the sea. By inhaling to its\n"
            "maximum capacity, a Wailord can dive close\n"
            "to 10,000 feet beneath the waves."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 1352,
        .trainerOffset = 18,
        .frontPic = gMonFrontPic_Wailord,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 26),
            ANIMCMD_FRAME(1, 48),
            ANIMCMD_FRAME(0, 33),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .frontAnimDelay = 10,
        .backPic = gMonBackPic_Wailord,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 22 : 14,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Wailord,
        .shinyPalette = gMonShinyPalette_Wailord,
        .iconSprite = gMonIcon_Wailord,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Wailord)
        OVERWORLD(
            sPicTable_Wailord,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Wailord,
            gShinyOverworldPalette_Wailord
        )
        .levelUpLearnset = sWailordLevelUpLearnset,
        .teachableLearnset = sWailordTeachableLearnset,
    },
#endif //P_FAMILY_WAILMER

#if P_FAMILY_NUMEL
    [SPECIES_NUMEL] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GROUND),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 61 : 88,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_SIMPLE, ABILITY_OWN_TEMPO },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_OWN_TEMPO },
    #endif
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Camaub"),
#else
        .speciesName = _("NUMEL"),
#endif
        .cryId = CRY_NUMEL,
        .natDexNum = NATIONAL_DEX_NUMEL,
#if GERMAN
        .categoryName = _("Taubheit"),
#else
        .categoryName = _("Numb"),
#endif
        .height = 7,
        .weight = 240,
        .description = COMPOUND_STRING(
#if GERMAN
        "Camaub speichert kochendes\n"
        "Magma in seinem Höcker. Es ist ein\n"
        "zähes Pokémon, das bis zu 100 Kilo tragen\n"
        "kann. Die Menschen schätzen seine Hilfe."),
#else
            "A Numel stores boiling magma in the hump\n"
            "on its back. It is a hardy Pokémon that can\n"
            "transport a 220-pound load. It has served\n"
            "humans at work since long ago."),
#endif
        .pokemonScale = 342,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Numel,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 40),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Numel,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Numel,
        .shinyPalette = gMonShinyPalette_Numel,
        .iconSprite = gMonIcon_Numel,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_NumelF,
        .frontPicSizeFemale = MON_COORDS_SIZE(40, 48),
        .backPicFemale = gMonBackPic_NumelF,
        .backPicSizeFemale = MON_COORDS_SIZE(56, 56),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(4, 2, SHADOW_SIZE_S)
        FOOTPRINT(Numel)
        OVERWORLD(
            sPicTable_Numel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Numel,
            gShinyOverworldPalette_Numel
        )
        OVERWORLD_FEMALE(
            sPicTable_NumelF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sNumelLevelUpLearnset,
        .teachableLearnset = sNumelTeachableLearnset,
        .eggMoveLearnset = sNumelEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_CAMERUPT}),
    },

    [SPECIES_CAMERUPT] =
    {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GROUND),
        .catchRate = 150,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 161 : 175,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_SOLID_ROCK, ABILITY_ANGER_POINT },
    #else
        .abilities = { ABILITY_MAGMA_ARMOR, ABILITY_NONE, ABILITY_ANGER_POINT },
    #endif
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Camerupt"),
#else
        .speciesName = _("CAMERUPT"),
#endif
        .cryId = CRY_CAMERUPT,
        .natDexNum = NATIONAL_DEX_CAMERUPT,
#if GERMAN
        .categoryName = _("Ausbruch"),
#else
        .categoryName = _("Eruption"),
#endif
        .height = 19,
        .weight = 2200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Camerupt lebt in einem Vulkankrater. Alle\n"
            "10 Jahre brechen die Vulkane auf seinem\n"
            "Rücken aus. Forschungen beschäftigen\n"
            "sich bereits mit diesen Eruptionen."),
#else
            "A Pokémon that lives in the crater of\n"
            "a volcano. Every 10 years, the volcanoes\n"
            "on its back erupt violently. Research is\n"
            "under way on the cause of eruption."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 7,
        .trainerScale = 345,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Camerupt,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Camerupt,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 19 : 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Camerupt,
        .shinyPalette = gMonShinyPalette_Camerupt,
        .iconSprite = gMonIcon_Camerupt,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_CameruptF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 56),
        .backPicFemale = gMonBackPic_CameruptF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 40),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_L)
        FOOTPRINT(Camerupt)
        OVERWORLD(
            sPicTable_Camerupt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Camerupt,
            gShinyOverworldPalette_Camerupt
        )
        OVERWORLD_FEMALE(
            sPicTable_CameruptF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sCameruptLevelUpLearnset,
        .teachableLearnset = sCameruptTeachableLearnset,
        .formSpeciesIdTable = sCameruptFormSpeciesIdTable,
        .formChangeTable = sCameruptFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_CAMERUPT_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 145,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_FIRE, TYPE_GROUND),
        .catchRate = 150,
        .expYield = 196,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_SHEER_FORCE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Camerupt"),
#else
        .speciesName = _("CAMERUPT"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_CAMERUPT_MEGA,
    #else
        .cryId = CRY_CAMERUPT,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_CAMERUPT,
#if GERMAN
        .categoryName = _("Ausbruch"),
#else
        .categoryName = _("Eruption"),
#endif
        .height = 25,
        .weight = 3205,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wenn sein Zorn den Siedepunkt erreicht,\n"
        "bricht der gewaltige Höckervulkan auf\n"
        "seinem Rücken heftig aus und spuckt Lava."),
#else
            "The humps on its back have transformed\n"
            "into one large and very active volcano. It\n"
            "has a deep hatred of water or any moisture\n"
            "and has an explosive personality."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 7,
        .trainerScale = 345,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_CameruptMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CameruptMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_CameruptMega,
        .shinyPalette = gMonShinyPalette_CameruptMega,
        .iconSprite = gMonIcon_CameruptMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 6, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Camerupt)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_CameruptMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_CameruptMega,
            gShinyOverworldPalette_CameruptMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sCameruptLevelUpLearnset,
        .teachableLearnset = sCameruptTeachableLearnset,
        .formSpeciesIdTable = sCameruptFormSpeciesIdTable,
        .formChangeTable = sCameruptFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_NUMEL

#if P_FAMILY_TORKOAL
    [SPECIES_TORKOAL] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 140,
        .baseSpeed     = 20,
        .baseSpAttack  = 85,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 165 : 161,
        .evYield_Defense = 2,
        .itemRare = ITEM_CHARCOAL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_WHITE_SMOKE, ABILITY_DROUGHT, ABILITY_SHELL_ARMOR },
    #else
        .abilities = { ABILITY_WHITE_SMOKE, ABILITY_NONE, ABILITY_SHELL_ARMOR },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Qurtel"),
#else
        .speciesName = _("TORKOAL"),
#endif
        .cryId = CRY_TORKOAL,
        .natDexNum = NATIONAL_DEX_TORKOAL,
#if GERMAN
        .categoryName = _("Kohle"),
#else
        .categoryName = _("Coal"),
#endif
        .height = 5,
        .weight = 804,
        .description = COMPOUND_STRING(
#if GERMAN
        "Qurtel verbrennt Kohle,\n"
        "um Energie für den Kampf zu haben. Wenn\n"
        "es Rauch aus seinen Nasenlöchern stößt,\n"
        "macht es ein Geräusch wie eine Dampflok."),
#else
            "It battles using energy it gets from\n"
            "burning coal. When loosing smoke from its\n"
            "nostrils, it lets off a sound that is\n"
            "similar to a locomotive's horn."),
#endif
        .pokemonScale = 390,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Torkoal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Torkoal,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Torkoal,
        .shinyPalette = gMonShinyPalette_Torkoal,
        .iconSprite = gMonIcon_Torkoal,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(2, 7, SHADOW_SIZE_L)
        FOOTPRINT(Torkoal)
        OVERWORLD(
            sPicTable_Torkoal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Torkoal,
            gShinyOverworldPalette_Torkoal
        )
        .levelUpLearnset = sTorkoalLevelUpLearnset,
        .teachableLearnset = sTorkoalTeachableLearnset,
        .eggMoveLearnset = sTorkoalEggMoveLearnset,
    },
#endif //P_FAMILY_TORKOAL

#if P_FAMILY_SPOINK
    [SPECIES_SPOINK] =
    {
        .baseHP        = 60,
        .baseAttack    = 25,
        .baseDefense   = 35,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 66 : 89,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_THICK_FAT, ABILITY_OWN_TEMPO, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Spoink"),
#else
        .speciesName = _("SPOINK"),
#endif
        .cryId = CRY_SPOINK,
        .natDexNum = NATIONAL_DEX_SPOINK,
#if GERMAN
        .categoryName = _("Sprungfeder"),
#else
        .categoryName = _("Bounce"),
#endif
        .height = 7,
        .weight = 306,
        .description = COMPOUND_STRING(
#if GERMAN
            "Spoink kann nach Belieben Psykräfte\n"
            "manipulieren. Selbst wenn es schläft,\n"
            "hüpft es. Am liebsten isst es Pilze,\n"
            "die unter der Erde wachsen."),
#else
            "A Pokémon that manipulates psychic power\n"
            "at will. It doesn't stop bouncing even when\n"
            "it is asleep. It loves eating mushrooms\n"
            "that grow underground."),
#endif
        .pokemonScale = 423,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Spoink,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH_TWICE,
        .backPic = gMonBackPic_Spoink,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(40, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 4,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Spoink,
        .shinyPalette = gMonShinyPalette_Spoink,
        .iconSprite = gMonIcon_Spoink,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 5, SHADOW_SIZE_S)
        FOOTPRINT(Spoink)
        OVERWORLD(
            sPicTable_Spoink,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Spoink,
            gShinyOverworldPalette_Spoink
        )
        .levelUpLearnset = sSpoinkLevelUpLearnset,
        .teachableLearnset = sSpoinkTeachableLearnset,
        .eggMoveLearnset = sSpoinkEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_GRUMPIG}),
    },

    [SPECIES_GRUMPIG] =
    {
        .baseHP        = 80,
        .baseAttack    = 45,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 90,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 165 : 164,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_THICK_FAT, ABILITY_OWN_TEMPO, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Groink"),
#else
        .speciesName = _("GRUMPIG"),
#endif
        .cryId = CRY_GRUMPIG,
        .natDexNum = NATIONAL_DEX_GRUMPIG,
#if GERMAN
        .categoryName = _("Manipulator"),
#else
        .categoryName = _("Manipulate"),
#endif
        .height = 9,
        .weight = 715,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die schwarzen Perlen auf seiner Stirn\n"
            "speichern seine Energie. Setzt es\n"
            "Psykraft ein, tanzt es merkwürdig. Dieser\n"
            "Tanzstil wurde Übersee sehr beliebt."),
#else
            "It stores power in the black pearls on its\n"
            "forehead. When it uses psychic power, it\n"
            "performs an odd dance step. Its style of\n"
            "dancing became hugely popular overseas."),
#endif
        .pokemonScale = 358,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grumpig,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .frontAnimDelay = 15,
        .backPic = gMonBackPic_Grumpig,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 2,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Grumpig,
        .shinyPalette = gMonShinyPalette_Grumpig,
        .iconSprite = gMonIcon_Grumpig,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Grumpig)
        OVERWORLD(
            sPicTable_Grumpig,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Grumpig,
            gShinyOverworldPalette_Grumpig
        )
        .levelUpLearnset = sGrumpigLevelUpLearnset,
        .teachableLearnset = sGrumpigTeachableLearnset,
    },
#endif //P_FAMILY_SPOINK

#if P_FAMILY_SPINDA
    [SPECIES_SPINDA] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 126 : 85,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_TANGLED_FEET, ABILITY_CONTRARY },
    #else
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_NONE, ABILITY_CONTRARY },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Pandir"),
#else
        .speciesName = _("SPINDA"),
#endif
        .cryId = CRY_SPINDA,
        .natDexNum = NATIONAL_DEX_SPINDA,
#if GERMAN
        .categoryName = _("Punkt-Panda"),
#else
        .categoryName = _("Spot Panda"),
#endif
        .height = 11,
        .weight = 50,
        .description = COMPOUND_STRING(
#if GERMAN
        "Da sein Punktmuster stets\n"
        "unterschiedlich ist, kann man es dadurch\n"
        "unterscheiden. Sein wankender Gang\n"
        "erschwert es dem Gegner, es zu treffen."),
#else
            "It is distinguished by a pattern of\n"
            "spots that is always different. Its\n"
            "unsteady, tottering walk has the\n"
            "effect of fouling its foe's aim."),
#endif
        .pokemonScale = 321,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Spinda,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 8,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 17),
                ANIMCMD_FRAME(1, 23),
                ANIMCMD_FRAME(0, 17),
                ANIMCMD_FRAME(1, 23),
                ANIMCMD_FRAME(0, 13),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_JUMPS : ANIM_CIRCLE_INTO_BG,
        .backPic = gMonBackPic_Spinda,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        .palette = gMonPalette_Spinda,
        .shinyPalette = gMonShinyPalette_Spinda,
        .iconSprite = gMonIcon_Spinda,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 6, SHADOW_SIZE_S)
        FOOTPRINT(Spinda)
        OVERWORLD(
            sPicTable_Spinda,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Spinda,
            gShinyOverworldPalette_Spinda
        )
        .levelUpLearnset = sSpindaLevelUpLearnset,
        .teachableLearnset = sSpindaTeachableLearnset,
        .eggMoveLearnset = sSpindaEggMoveLearnset,
    },
#endif //P_FAMILY_SPINDA

#if P_FAMILY_TRAPINCH
#if P_UPDATED_EGG_GROUPS >= GEN_8
    #define TRAPINCH_FAMILY_EGG_GROUPS MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_DRAGON)
#else
    #define TRAPINCH_FAMILY_EGG_GROUPS MON_EGG_GROUPS(EGG_GROUP_BUG)
#endif

    [SPECIES_TRAPINCH] =
    {
        .baseHP        = 45,
        .baseAttack    = 100,
        .baseDefense   = 45,
        .baseSpeed     = 10,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 73,
        .evYield_Attack = 1,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = TRAPINCH_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_ARENA_TRAP, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Knacklion"),
#else
        .speciesName = _("TRAPINCH"),
#endif
        .cryId = CRY_TRAPINCH,
        .natDexNum = NATIONAL_DEX_TRAPINCH,
#if GERMAN
        .categoryName = _("Ameisenlöwe"),
#else
        .categoryName = _("Ant Pit"),
#endif
        .height = 7,
        .weight = 150,
        .description = COMPOUND_STRING(
#if GERMAN
        "Knacklions kräftigen Kiefer zermalmen\n"
        "selbst Felsen. Da sein Kopf so groß ist,\n"
        "fällt es ihm schwer sich aufzurichten,\n"
        "wenn es umgefallen ist."),
#else
            "Its big jaws crunch through boulders.\n"
            "Because its head is so big, it has a hard\n"
            "time getting back upright if it tips over\n"
            "onto its back."),
#endif
        .pokemonScale = 298,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Trapinch,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 32) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Trapinch,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 40) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 10,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Trapinch,
        .shinyPalette = gMonShinyPalette_Trapinch,
        .iconSprite = gMonIcon_Trapinch,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(4, -1, SHADOW_SIZE_S)
        FOOTPRINT(Trapinch)
        OVERWORLD(
            sPicTable_Trapinch,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Trapinch,
            gShinyOverworldPalette_Trapinch
        )
        .levelUpLearnset = sTrapinchLevelUpLearnset,
        .teachableLearnset = sTrapinchTeachableLearnset,
        .eggMoveLearnset = sTrapinchEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_VIBRAVA}),
    },

    [SPECIES_VIBRAVA] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GROUND, TYPE_DRAGON),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 119 : 126,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = TRAPINCH_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_LEVITATE, ABILITY_LEVITATE, ABILITY_LEVITATE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Vibrava"),
#else
        .speciesName = _("VIBRAVA"),
#endif
        .cryId = CRY_VIBRAVA,
        .natDexNum = NATIONAL_DEX_VIBRAVA,
        .categoryName = _("Vibration"),
        .height = 11,
        .weight = 153,
        .description = COMPOUND_STRING(
#if GERMAN
            "Reibt es seine Flügel aneinander,\n"
            "generiert es Ultraschallwellen. Da\n"
            "seine Flügel noch immer wachsen,\n"
            "kann es nur kurze Distanzen fliegen."),
#else
            "It looses ultrasonic waves by rubbing its\n"
            "wings together. Since a Vibrava's wings\n"
            "are still in the process of growing, it can\n"
            "only fly short distances."),
#endif
        .pokemonScale = 370,
        .pokemonOffset = 11,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vibrava,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Vibrava,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 12,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Vibrava,
        .shinyPalette = gMonShinyPalette_Vibrava,
        .iconSprite = gMonIcon_Vibrava,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 0, SHADOW_SIZE_L)
        FOOTPRINT(Vibrava)
        OVERWORLD(
            sPicTable_Vibrava,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vibrava,
            gShinyOverworldPalette_Vibrava
        )
        .levelUpLearnset = sVibravaLevelUpLearnset,
        .teachableLearnset = sVibravaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 45, SPECIES_FLYGON}),
    },

    [SPECIES_FLYGON] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GROUND, TYPE_DRAGON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 260,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 234,
    #else
        .expYield = 197,
    #endif
        .evYield_Attack = 1,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = TRAPINCH_FAMILY_EGG_GROUPS,
        .abilities = { ABILITY_LEVITATE, ABILITY_LEVITATE, ABILITY_LEVITATE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Libelldra"),
#else
        .speciesName = _("FLYGON"),
#endif
        .cryId = CRY_FLYGON,
        .natDexNum = NATIONAL_DEX_FLYGON,
#if GERMAN
        .categoryName = _("Mystik"),
#else
        .categoryName = _("Mystic"),
#endif
        .height = 20,
        .weight = 820,
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Schlagen seiner Flügel hört sich\n"
            "wie Gesang an. Um sich vor den Angriffen\n"
            "der Feinde zu schützen, wirbelt es eine\n"
            "Wolke Wüstensand auf."),
#else
            "The flapping of its wings sounds like\n"
            "singing. To prevent detection by enemies,\n"
            "it hides itself by flapping up a cloud of\n"
            "desert sand."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 268,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Flygon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Flygon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 3,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Flygon,
        .shinyPalette = gMonShinyPalette_Flygon,
        .iconSprite = gMonIcon_Flygon,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_M)
        FOOTPRINT(Flygon)
        OVERWORLD(
            sPicTable_Flygon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Flygon,
            gShinyOverworldPalette_Flygon
        )
        .levelUpLearnset = sFlygonLevelUpLearnset,
        .teachableLearnset = sFlygonTeachableLearnset,
    },
#endif //P_FAMILY_TRAPINCH

#if P_FAMILY_CACNEA
    [SPECIES_CACNEA] =
    {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 85,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 67 : 97,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Tuska"),
#else
        .speciesName = _("CACNEA"),
#endif
        .cryId = CRY_CACNEA,
        .natDexNum = NATIONAL_DEX_CACNEA,
#if GERMAN
        .categoryName = _("Kaktus"),
#else
        .categoryName = _("Cactus"),
#endif
        .height = 4,
        .weight = 513,
        .description = COMPOUND_STRING(
#if GERMAN
            "Tuska wohnt in der Wüste, in der es nie\n"
            "regnet. Es kämpft, indem es seine dicken,\n"
            "mit Dornen übersäten Arme schwingt.\n"
            "Einmal im Jahr erblüht eine gelbe Blüte."),
#else
            "Cacnea live in deserts with virtually no\n"
            "rainfall. It battles by swinging its thick,\n"
            "spiked arms. Once a year, a yellow flower\n"
            "blooms."),
#endif
        .pokemonScale = 455,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cacnea,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 32) : MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW,
        .backPic = gMonBackPic_Cacnea,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 15 : 12,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Cacnea,
        .shinyPalette = gMonShinyPalette_Cacnea,
        .iconSprite = gMonIcon_Cacnea,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Cacnea)
        OVERWORLD(
            sPicTable_Cacnea,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cacnea,
            gShinyOverworldPalette_Cacnea
        )
        .levelUpLearnset = sCacneaLevelUpLearnset,
        .teachableLearnset = sCacneaTeachableLearnset,
        .eggMoveLearnset = sCacneaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_CACTURNE}),
    },

    [SPECIES_CACTURNE] =
    {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DARK),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 166 : 177,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Noktuska"),
#else
        .speciesName = _("CACTURNE"),
#endif
        .cryId = CRY_CACTURNE,
        .natDexNum = NATIONAL_DEX_CACTURNE,
#if GERMAN
        .categoryName = _("Vogelschock"),
#else
        .categoryName = _("Scarecrow"),
#endif
        .height = 13,
        .weight = 774,
        .description = COMPOUND_STRING(
#if GERMAN
            "Nach 1000 Jahren in der Wüste hat sein\n"
            "Blut nun dieselbe Zusammensetzung wie\n"
            "Wüstensand. Da es nachtaktiv ist, geht\n"
            "es nachts auf Beutejagd."),
#else
            "After spending thousands of years in\n"
            "harsh deserts, its blood transformed into\n"
            "the same substances as sand. It is\n"
            "nocturnal, so it hunts at night."),
#endif
        .pokemonScale = 327,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cacturne,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Cacturne,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 0,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Cacturne,
        .shinyPalette = gMonShinyPalette_Cacturne,
        .iconSprite = gMonIcon_Cacturne,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_CacturneF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cacturne)
        OVERWORLD(
            sPicTable_Cacturne,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cacturne,
            gShinyOverworldPalette_Cacturne
        )
        OVERWORLD_FEMALE(
            sPicTable_CacturneF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following
        )
        .levelUpLearnset = sCacturneLevelUpLearnset,
        .teachableLearnset = sCacturneTeachableLearnset,
    },
#endif //P_FAMILY_CACNEA

#if P_FAMILY_SWABLU
    [SPECIES_SWABLU] =
    {
        .baseHP        = 45,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 74,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_NONE, ABILITY_CLOUD_NINE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Wablu"),
#else
        .speciesName = _("SWABLU"),
#endif
        .cryId = CRY_SWABLU,
        .natDexNum = NATIONAL_DEX_SWABLU,
#if GERMAN
        .categoryName = _("Wollvogel"),
#else
        .categoryName = _("Cotton Bird"),
#endif
        .height = 4,
        .weight = 12,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wablu hat watteähnliche Flügel. Nach\n"
        "einem Winter ohne viel Nahrung, schwärmen\n"
        "Wablu im Frühling näher zu den Städten."),
#else
            "A Pokémon that has wings like cottony\n"
            "clouds. After enduring winter, in which\n"
            "little food is available, Swablu flocks\n"
            "move closer to towns in the spring."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swablu,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 17 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SLIDE : ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 12 : 0,
        .backPic = gMonBackPic_Swablu,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 11,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Swablu,
        .shinyPalette = gMonShinyPalette_Swablu,
        .iconSprite = gMonIcon_Swablu,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Swablu)
        OVERWORLD(
            sPicTable_Swablu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Swablu,
            gShinyOverworldPalette_Swablu
        )
        .levelUpLearnset = sSwabluLevelUpLearnset,
        .teachableLearnset = sSwabluTeachableLearnset,
        .eggMoveLearnset = sSwabluEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_ALTARIA}),
    },

    [SPECIES_ALTARIA] =
    {
        .baseHP        = 75,
        .baseAttack    = 70,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 70,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 172 : 188,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_NONE, ABILITY_CLOUD_NINE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Altaria"),
#else
        .speciesName = _("ALTARIA"),
#endif
        .cryId = CRY_ALTARIA,
        .natDexNum = NATIONAL_DEX_ALTARIA,
#if GERMAN
        .categoryName = _("Summsel"),
#else
        .categoryName = _("Humming"),
#endif
        .height = 11,
        .weight = 206,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es hat eine wunderschöne Sopranstimme.\n"
            "Altaria fliegt zwischen den weißen Wolken\n"
            "am blauen Himmel und schießt heiße\n"
            "Feuerbälle aus seinem Maul."),
#else
            "It hums in a beautiful soprano voice.\n"
            "It flies among white clouds in the blue\n"
            "sky. It launches intensely hot fireballs\n"
            "from its mouth."),
#endif
        .pokemonScale = 327,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Altaria,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_STRETCH : ANIM_V_STRETCH,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backPic = gMonBackPic_Altaria,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 10,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Altaria,
        .shinyPalette = gMonShinyPalette_Altaria,
        .iconSprite = gMonIcon_Altaria,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 14, SHADOW_SIZE_L)
        FOOTPRINT(Altaria)
        OVERWORLD(
            sPicTable_Altaria,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Altaria,
            gShinyOverworldPalette_Altaria
        )
        .levelUpLearnset = sAltariaLevelUpLearnset,
        .teachableLearnset = sAltariaTeachableLearnset,
        .formSpeciesIdTable = sAltariaFormSpeciesIdTable,
        .formChangeTable = sAltariaFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_ALTARIA_MEGA] =
    {
        .baseHP        = 75,
        .baseAttack    = 110,
        .baseDefense   = 110,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 207,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_PIXILATE, ABILITY_PIXILATE, ABILITY_PIXILATE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Altaria"),
#else
        .speciesName = _("ALTARIA"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_ALTARIA_MEGA,
    #else
        .cryId = CRY_ALTARIA,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_ALTARIA,
#if GERMAN
        .categoryName = _("Summsel"),
#else
        .categoryName = _("Humming"),
#endif
        .height = 15,
        .weight = 206,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seine Daunen, die sich unfassbar weich\n"
        "anfühlen, sind so robust, dass ein paar\n"
        "davon reichen, um einen Kipplaster in der\n"
        "Luft zu halten."),
#else
            "It sings with a voice that is even more\n"
            "beautiful than before it Mega Evolved.\n"
            "Its feathers became larger for protection\n"
            "and glimmer with an iridescent sheen."),
#endif
        .pokemonScale = 327,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AltariaMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_AltariaMega,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_AltariaMega,
        .shinyPalette = gMonShinyPalette_AltariaMega,
        .iconSprite = gMonIcon_AltariaMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 17, SHADOW_SIZE_L)
        FOOTPRINT(Altaria)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AltariaMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_AltariaMega,
            gShinyOverworldPalette_AltariaMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAltariaLevelUpLearnset,
        .teachableLearnset = sAltariaTeachableLearnset,
        .formSpeciesIdTable = sAltariaFormSpeciesIdTable,
        .formChangeTable = sAltariaFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_SWABLU

#if P_FAMILY_ZANGOOSE
    [SPECIES_ZANGOOSE] =
    {
        .baseHP        = 73,
        .baseAttack    = 115,
        .baseDefense   = 60,
        .baseSpeed     = 90,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 160 : 165,
        .evYield_Attack = 2,
        .itemRare = ITEM_QUICK_CLAW,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_IMMUNITY, ABILITY_NONE, ABILITY_TOXIC_BOOST },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Sengo"),
#else
        .speciesName = _("ZANGOOSE"),
#endif
        .cryId = CRY_ZANGOOSE,
        .natDexNum = NATIONAL_DEX_ZANGOOSE,
#if GERMAN
        .categoryName = _("Frettkatz"),
#else
        .categoryName = _("Cat Ferret"),
#endif
        .height = 13,
        .weight = 403,
        .description = COMPOUND_STRING(
#if GERMAN
            "Beim Kampf steht es auf seinen Hinter-\n"
            "beinen und greift mit seinen scharfen\n"
            "Klauen an den Vorderbeinen an. Trifft\n"
            "es auf Vipitis, sträubt sich sein Fell."),
#else
            "When it battles, it stands on its hind legs\n"
            "and attacks with its sharply clawed\n"
            "forelegs. Its fur bristles if it encounters\n"
            "any Seviper."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Zangoose,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Zangoose,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Zangoose,
        .shinyPalette = gMonShinyPalette_Zangoose,
        .iconSprite = gMonIcon_Zangoose,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Zangoose)
        OVERWORLD(
            sPicTable_Zangoose,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Zangoose,
            gShinyOverworldPalette_Zangoose
        )
        .levelUpLearnset = sZangooseLevelUpLearnset,
        .teachableLearnset = sZangooseTeachableLearnset,
        .eggMoveLearnset = sZangooseEggMoveLearnset,
    },
#endif //P_FAMILY_ZANGOOSE

#if P_FAMILY_SEVIPER
    [SPECIES_SEVIPER] =
    {
        .baseHP        = 73,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 160 : 165,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Vipitis"),
#else
        .speciesName = _("SEVIPER"),
#endif
        .cryId = CRY_SEVIPER,
        .natDexNum = NATIONAL_DEX_SEVIPER,
#if GERMAN
        .categoryName = _("Reißzahn"),
#else
        .categoryName = _("Fang Snake"),
#endif
        .height = 27,
        .weight = 525,
        .description = COMPOUND_STRING(
#if GERMAN
            "Vipitis und Sengo sind Erzrivalen.\n"
            "Vipitis kontert die atemberaubende\n"
            "Flinkheit von Sengo mit seinem schwert-\n"
            "ähnlichen Schwanz, aus dem Gift austritt."),
#else
            "Seviper and Zangoose are eternal rivals.\n"
            "It counters a Zangoose's dazzling agility\n"
            "with its swordlike tail, which also oozes\n"
            "a horrible poison."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Seviper,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Seviper,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Seviper,
        .shinyPalette = gMonShinyPalette_Seviper,
        .iconSprite = gMonIcon_Seviper,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 7, SHADOW_SIZE_L)
        FOOTPRINT(Seviper)
        OVERWORLD(
            sPicTable_Seviper,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BIKE_TIRE,
            sAnimTable_Following_Asym,
            gOverworldPalette_Seviper,
            gShinyOverworldPalette_Seviper
        )
        .levelUpLearnset = sSeviperLevelUpLearnset,
        .teachableLearnset = sSeviperTeachableLearnset,
        .eggMoveLearnset = sSeviperEggMoveLearnset,
    },
#endif //P_FAMILY_SEVIPER

#if P_FAMILY_LUNATONE
    [SPECIES_LUNATONE] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 90 : 70,
        .baseAttack    = 55,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ROCK, TYPE_PSYCHIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 161,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 154,
    #else
        .expYield = 150,
    #endif
        .evYield_SpAttack = 2,
        .itemCommon = ITEM_STARDUST,
        .itemRare = ITEM_MOON_STONE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Lunastein"),
#else
        .speciesName = _("LUNATONE"),
#endif
        .cryId = CRY_LUNATONE,
        .natDexNum = NATIONAL_DEX_LUNATONE,
#if GERMAN
        .categoryName = _("Meteorit"),
#else
        .categoryName = _("Meteorite"),
#endif
        .height = 10,
        .weight = 1680,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei Vollmond wird es sehr aktiv. Dieses\n"
            "Pokémon wurde erst vor 40 Jahren neben\n"
            "der Einschlagstelle eines Meteoriten\n"
            "entdeckt."),
#else
            "It becomes very active on the night of\n"
            "a full moon. This Pokémon was first\n"
            "discovered 40 years ago at the site of\n"
            "a meteor strike."),
#endif
        .pokemonScale = 300,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lunatone,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_SWING_CONVEX_FAST,
        .enemyMonElevation = 13,
        .backPic = gMonBackPic_Lunatone,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 8,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Lunatone,
        .shinyPalette = gMonShinyPalette_Lunatone,
        .iconSprite = gMonIcon_Lunatone,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_S)
        FOOTPRINT(Lunatone)
        OVERWORLD(
            sPicTable_Lunatone,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Lunatone,
            gShinyOverworldPalette_Lunatone
        )
        .levelUpLearnset = sLunatoneLevelUpLearnset,
        .teachableLearnset = sLunatoneTeachableLearnset,
    },
#endif //P_FAMILY_LUNATONE

#if P_FAMILY_SOLROCK
    [SPECIES_SOLROCK] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 90 : 70,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 70,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ROCK, TYPE_PSYCHIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 161,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 154,
    #else
        .expYield = 150,
    #endif
        .evYield_Attack = 2,
        .itemCommon = ITEM_STARDUST,
        .itemRare = ITEM_SUN_STONE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Sonnfel"),
#else
        .speciesName = _("SOLROCK"),
#endif
        .cryId = CRY_SOLROCK,
        .natDexNum = NATIONAL_DEX_SOLROCK,
#if GERMAN
        .categoryName = _("Meteorit"),
#else
        .categoryName = _("Meteorite"),
#endif
        .height = 12,
        .weight = 1540,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dieses Pokémon bezieht seine Energie\n"
            "aus dem Sonnenlicht. Bei Sonnenschein\n"
            "kann man viele Sonnfel beim Sonnen\n"
            "beobachten."),
#else
            "Solar energy is the source of this \n"
            "Pokémon's power. On sunny days, groups of\n"
            "Solrock line up facing the sun and absorb\n"
            "its light."),
#endif
        .pokemonScale = 328,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Solrock,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_ROTATE_TO_SIDES_TWICE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_Solrock,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 2,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Solrock,
        .shinyPalette = gMonShinyPalette_Solrock,
        .iconSprite = gMonIcon_Solrock,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_M)
        FOOTPRINT(Solrock)
        OVERWORLD(
            sPicTable_Solrock,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Solrock,
            gShinyOverworldPalette_Solrock
        )
        .levelUpLearnset = sSolrockLevelUpLearnset,
        .teachableLearnset = sSolrockTeachableLearnset,
    },
#endif //P_FAMILY_SOLROCK

#if P_FAMILY_BARBOACH
    [SPECIES_BARBOACH] =
    {
        .baseHP        = 50,
        .baseAttack    = 48,
        .baseDefense   = 43,
        .baseSpeed     = 60,
        .baseSpAttack  = 46,
        .baseSpDefense = 41,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 92,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_ANTICIPATION, ABILITY_HYDRATION },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_HYDRATION },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Schmerbe"),
#else
        .speciesName = _("BARBOACH"),
#endif
        .cryId = CRY_BARBOACH,
        .natDexNum = NATIONAL_DEX_BARBOACH,
#if GERMAN
        .categoryName = _("Barthaar"),
#else
        .categoryName = _("Whiskers"),
#endif
        .height = 4,
        .weight = 19,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schmerbes Körper ist mit einem schleimigen\n"
        "Film überzogen. Dieser Film dient zum\n"
        "Schutz vor Keimen, die sich im\n"
        "Schlammwasser tummeln."),
#else
            "Its body is covered with a slimy film.\n"
            "The film acts as a barrier to prevent germs\n"
            "in muddy water from entering the\n"
            "Barboach's body."),
#endif
        .pokemonScale = 581,
        .pokemonOffset = -3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Barboach,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 0 : 7,
        .backPic = gMonBackPic_Barboach,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Barboach,
        .shinyPalette = gMonShinyPalette_Barboach,
        .iconSprite = gMonIcon_Barboach,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_M)
        FOOTPRINT(Barboach)
        OVERWORLD(
            sPicTable_Barboach,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Barboach,
            gShinyOverworldPalette_Barboach
        )
        .levelUpLearnset = sBarboachLevelUpLearnset,
        .teachableLearnset = sBarboachTeachableLearnset,
        .eggMoveLearnset = sBarboachEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_WHISCASH}),
    },

    [SPECIES_WHISCASH] =
    {
        .baseHP        = 110,
        .baseAttack    = 78,
        .baseDefense   = 73,
        .baseSpeed     = 60,
        .baseSpAttack  = 76,
        .baseSpDefense = 71,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 164 : 158,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_ANTICIPATION, ABILITY_HYDRATION },
    #else
        .abilities = { ABILITY_OBLIVIOUS, ABILITY_NONE, ABILITY_HYDRATION },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Welsar"),
#else
        .speciesName = _("WHISCASH"),
#endif
        .cryId = CRY_WHISCASH,
        .natDexNum = NATIONAL_DEX_WHISCASH,
#if GERMAN
        .categoryName = _("Barthaar"),
#else
        .categoryName = _("Whiskers"),
#endif
        .height = 9,
        .weight = 236,
        .description = COMPOUND_STRING(
#if GERMAN
        "Welsar kann eigenartigerweise\n"
        "Erdbeben vorhersehen. Tagsüber\n"
        "schläft es im Schlamm auf dem Grund eines\n"
        "Teiches und nachts isst es permanent."),
#else
            "Mysteriously, it can foretell earthquakes.\n"
            "In the daytime, it sleeps in mud at the\n"
            "bottom of a pond. When it awakens, it\n"
            "continually feeds throughout the night."),
#endif
        .pokemonScale = 317,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Whiscash,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW,
        .backPic = gMonBackPic_Whiscash,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Whiscash,
        .shinyPalette = gMonShinyPalette_Whiscash,
        .iconSprite = gMonIcon_Whiscash,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_L)
        FOOTPRINT(Whiscash)
        OVERWORLD(
            sPicTable_Whiscash,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Whiscash,
            gShinyOverworldPalette_Whiscash
        )
        .levelUpLearnset = sWhiscashLevelUpLearnset,
        .teachableLearnset = sWhiscashTeachableLearnset,
    },
#endif //P_FAMILY_BARBOACH

#if P_FAMILY_CORPHISH
    [SPECIES_CORPHISH] =
    {
        .baseHP        = 43,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 35,
        .baseSpAttack  = 50,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 205,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 62 : 111,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SHELL_ARMOR, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Krebscorps"),
#else
        .speciesName = _("CORPHISH"),
#endif
        .cryId = CRY_CORPHISH,
        .natDexNum = NATIONAL_DEX_CORPHISH,
#if GERMAN
        .categoryName = _("Grobian"),
#else
        .categoryName = _("Ruffian"),
#endif
        .height = 6,
        .weight = 115,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wenn es einmal die Beute mit seinen\n"
            "großen Scheren gegriffen hat, lässt es\n"
            "nicht mehr los. Es ist ein sehr zähes\n"
            "Pokémon, das überall überleben kann."),
#else
            "Once it grips prey with its large pincers,\n"
            "it will never let go, no matter what.\n"
            "It is a hardy Pokémon that can thrive\n"
            "in any environment."),
#endif
        .pokemonScale = 484,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Corphish,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Corphish,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 8,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Corphish,
        .shinyPalette = gMonShinyPalette_Corphish,
        .iconSprite = gMonIcon_Corphish,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 5, SHADOW_SIZE_M)
        FOOTPRINT(Corphish)
        OVERWORLD(
            sPicTable_Corphish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Corphish,
            gShinyOverworldPalette_Corphish
        )
        .levelUpLearnset = sCorphishLevelUpLearnset,
        .teachableLearnset = sCorphishTeachableLearnset,
        .eggMoveLearnset = sCorphishEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_CRAWDAUNT}),
    },

    [SPECIES_CRAWDAUNT] =
    {
        .baseHP        = 63,
        .baseAttack    = 120,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 90,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER, TYPE_DARK),
        .catchRate = 155,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 164 : 161,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_HYPER_CUTTER, ABILITY_SHELL_ARMOR, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Krebutack"),
#else
        .speciesName = _("CRAWDAUNT"),
#endif
        .cryId = CRY_CRAWDAUNT,
        .natDexNum = NATIONAL_DEX_CRAWDAUNT,
#if GERMAN
        .categoryName = _("Schlingel"),
#else
        .categoryName = _("Rogue"),
#endif
        .height = 11,
        .weight = 328,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses brutale Pokémon liebt den Kampf.\n"
        "Als Veteran, der in hunderten von Kämpfen\n"
        "bestanden hat, sind seine mächtigen\n"
        "Scheren mit Kratzern und Spuren übersät."),
#else
            "A brutish Pokémon that loves to battle.\n"
            "A veteran Crawdaunt that has prevailed in\n"
            "hundreds of battles has giant pincers\n"
            "marked with countless scars."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Crawdaunt,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Crawdaunt,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 7,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Crawdaunt,
        .shinyPalette = gMonShinyPalette_Crawdaunt,
        .iconSprite = gMonIcon_Crawdaunt,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 9, SHADOW_SIZE_M)
        FOOTPRINT(Crawdaunt)
        OVERWORLD(
            sPicTable_Crawdaunt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Crawdaunt,
            gShinyOverworldPalette_Crawdaunt
        )
        .levelUpLearnset = sCrawdauntLevelUpLearnset,
        .teachableLearnset = sCrawdauntTeachableLearnset,
    },
#endif //P_FAMILY_CORPHISH

#if P_FAMILY_BALTOY
    [SPECIES_BALTOY] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND, TYPE_PSYCHIC),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 58,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Puppance"),
#else
        .speciesName = _("BALTOY"),
#endif
        .cryId = CRY_BALTOY,
        .natDexNum = NATIONAL_DEX_BALTOY,
#if GERMAN
        .categoryName = _("Lehmpuppe"),
#else
        .categoryName = _("Clay Doll"),
#endif
        .height = 5,
        .weight = 215,
        .description = COMPOUND_STRING(
#if GERMAN
        "Puppance dreht sich auf seinem Fuß. Es\n"
        "wurde bereits in Wandmalereien einer einst\n"
        "geschäftigen Stadt der Antike abgebildet."),
#else
            "A Baltoy moves by spinning on its single\n"
            "foot. It has been depicted in murals \n"
            "adorning the walls of a once-bustling city\n"
            "in an ancient age."),
#endif
        .pokemonScale = 457,
        .pokemonOffset = 21,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Baltoy,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 4 : 8,
        .backPic = gMonBackPic_Baltoy,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Baltoy,
        .shinyPalette = gMonShinyPalette_Baltoy,
        .iconSprite = gMonIcon_Baltoy,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 5, SHADOW_SIZE_S)
        FOOTPRINT(Baltoy)
        OVERWORLD(
            sPicTable_Baltoy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Baltoy,
            gShinyOverworldPalette_Baltoy
        )
        .levelUpLearnset = sBaltoyLevelUpLearnset,
        .teachableLearnset = sBaltoyTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_CLAYDOL}),
    },

    [SPECIES_CLAYDOL] =
    {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = 105,
        .baseSpeed     = 75,
        .baseSpAttack  = 70,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_GROUND, TYPE_PSYCHIC),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 175 : 189,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Lepumentas"),
#else
        .speciesName = _("CLAYDOL"),
#endif
        .cryId = CRY_CLAYDOL,
        .natDexNum = NATIONAL_DEX_CLAYDOL,
#if GERMAN
        .categoryName = _("Lehmpuppe"),
#else
        .categoryName = _("Clay Doll"),
#endif
        .height = 15,
        .weight = 1080,
        .description = COMPOUND_STRING(
#if GERMAN
        "Lepumentas schläft schwebend. Seine Arme\n"
        "sind nicht an seinem Körper befestigt. Die\n"
        "Manipulation durch Psykräfte lässt sie\n"
        "schweben."),
#else
            "A Claydol sleeps while hovering in midair.\n"
            "Its arms are separate from its body.\n"
            "They are kept floating by the Pokémon's\n"
            "manipulation of psychic power."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 280,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Claydol,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Claydol,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Claydol,
        .shinyPalette = gMonShinyPalette_Claydol,
        .iconSprite = gMonIcon_Claydol,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 18, SHADOW_SIZE_M)
        FOOTPRINT(Claydol)
        OVERWORLD(
            sPicTable_Claydol,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Claydol,
            gShinyOverworldPalette_Claydol
        )
        .levelUpLearnset = sClaydolLevelUpLearnset,
        .teachableLearnset = sClaydolTeachableLearnset,
    },
#endif //P_FAMILY_BALTOY

#if P_FAMILY_LILEEP
    [SPECIES_LILEEP] =
    {
        .baseHP        = 66,
        .baseAttack    = 41,
        .baseDefense   = 77,
        .baseSpeed     = 23,
        .baseSpAttack  = 61,
        .baseSpDefense = 87,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 71,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 99,
    #else
        .expYield = 121,
    #endif
        .evYield_SpDefense = 1,
        .itemRare = ITEM_BIG_ROOT,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SUCTION_CUPS, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Liliep"),
#else
        .speciesName = _("LILEEP"),
#endif
        .cryId = CRY_LILEEP,
        .natDexNum = NATIONAL_DEX_LILEEP,
#if GERMAN
        .categoryName = _("Seeanemone"),
#else
        .categoryName = _("Sea Lily"),
#endif
        .height = 10,
        .weight = 238,
        .description = COMPOUND_STRING(
#if GERMAN
            "Liliep wedelt mit den Tentakeln, um sich als\n"
            "Seetang zu tarnen. Beute, die ihm zu nahe\n"
            "kommt, wird ganz verschluckt. Vor 100\n"
            "Millionen Jahren galt es als ausgestorben."),
#else
            "It disguises itself as seaweed by making\n"
            "its tentacles sway. Unsuspecting prey\n"
            "that come too close are swallowed whole.\n"
            "It became extinct 100 million years ago."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lileep,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Lileep,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(48, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 8,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Lileep,
        .shinyPalette = gMonShinyPalette_Lileep,
        .iconSprite = gMonIcon_Lileep,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 5, SHADOW_SIZE_S)
        FOOTPRINT(Lileep)
        OVERWORLD(
            sPicTable_Lileep,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Lileep,
            gShinyOverworldPalette_Lileep
        )
        .levelUpLearnset = sLileepLevelUpLearnset,
        .teachableLearnset = sLileepTeachableLearnset,
        .eggMoveLearnset = sLileepEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_CRADILY}),
    },

    [SPECIES_CRADILY] =
    {
        .baseHP        = 86,
        .baseAttack    = 81,
        .baseDefense   = 97,
        .baseSpeed     = 43,
        .baseSpAttack  = 81,
        .baseSpDefense = 107,
        .types = MON_TYPES(TYPE_ROCK, TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 173,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 199,
    #else
        .expYield = 201,
    #endif
        .evYield_SpDefense = 2,
        .itemRare = ITEM_BIG_ROOT,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SUCTION_CUPS, ABILITY_NONE, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Wielie"),
#else
        .speciesName = _("CRADILY"),
#endif
        .cryId = CRY_CRADILY,
        .natDexNum = NATIONAL_DEX_CRADILY,
#if GERMAN
        .categoryName = _("Rankfüßer"),
#else
        .categoryName = _("Barnacle"),
#endif
        .height = 15,
        .weight = 604,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es schleppt seinen schweren Körper über\n"
            "den Meeresboden. Wielie baut sein Nest\n"
            "in Untiefen der warmen See. Bei Ebbe kann\n"
            "man es am Strand sehen."),
#else
            "It drags its heavy body along the\n"
            "seafloor. It makes its nest in the shallows\n"
            "of warm seas. Cradily can be seen on\n"
            "beaches when the tide goes out."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cradily,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Cradily,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 0,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Cradily,
        .shinyPalette = gMonShinyPalette_Cradily,
        .iconSprite = gMonIcon_Cradily,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Cradily)
        OVERWORLD(
            sPicTable_Cradily,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Cradily,
            gShinyOverworldPalette_Cradily
        )
        .levelUpLearnset = sCradilyLevelUpLearnset,
        .teachableLearnset = sCradilyTeachableLearnset,
    },
#endif //P_FAMILY_LILEEP

#if P_FAMILY_ANORITH
    [SPECIES_ANORITH] =
    {
        .baseHP        = 45,
        .baseAttack    = 95,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ROCK, TYPE_BUG),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 71,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 99,
    #else
        .expYield = 119,
    #endif
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Anorith"),
#else
        .speciesName = _("ANORITH"),
#endif
        .cryId = CRY_ANORITH,
        .natDexNum = NATIONAL_DEX_ANORITH,
#if GERMAN
        .categoryName = _("Urgarnelen"),
#else
        .categoryName = _("Old Shrimp"),
#endif
        .height = 7,
        .weight = 125,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dank der Wissenschaft konnte Anorith aus\n"
        "einem Fossil wiederhergestellt werden. Es\n"
        "schwimmt, indem es seine acht Flügel, die\n"
        "sich dem Meer angepasst haben, bewegt."),
#else
            "It was resurrected from a fossil using the\n"
            "power of science. It swims by undulating\n"
            "the eight wings at its sides. They were\n"
            "feet that adapted to life in the sea."),
#endif
        .pokemonScale = 296,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Anorith,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_TWIST,
        .backPic = gMonBackPic_Anorith,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(56, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 23 : 19,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Anorith,
        .shinyPalette = gMonShinyPalette_Anorith,
        .iconSprite = gMonIcon_Anorith,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Anorith)
        OVERWORLD(
            sPicTable_Anorith,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_BUG,
            sAnimTable_Following,
            gOverworldPalette_Anorith,
            gShinyOverworldPalette_Anorith
        )
        .levelUpLearnset = sAnorithLevelUpLearnset,
        .teachableLearnset = sAnorithTeachableLearnset,
        .eggMoveLearnset = sAnorithEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_ARMALDO}),
    },

    [SPECIES_ARMALDO] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 45,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ROCK, TYPE_BUG),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 173,
    #elif P_UPDATED_EXP_YIELDS >= GEN_4
        .expYield = 199,
    #else
        .expYield = 200,
    #endif
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_3),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Armaldo"),
#else
        .speciesName = _("ARMALDO"),
#endif
        .cryId = CRY_ARMALDO,
        .natDexNum = NATIONAL_DEX_ARMALDO,
#if GERMAN
        .categoryName = _("Schild"),
#else
        .categoryName = _("Plate"),
#endif
        .height = 15,
        .weight = 682,
        .description = COMPOUND_STRING(
#if GERMAN
            "Früher hat Armaldo an Land gelebt. Wenn\n"
            "es jetzt jedoch nach Beute jagt, taucht\n"
            "es tief in den Ozean. Mittels seiner zwei\n"
            "großen Schwingen schwimmt es."),
#else
            "Armaldo usually lives on land. However,\n"
            "when it hunts for prey, it dives beneath\n"
            "the ocean. It swims around using its two\n"
            "large wings."),
#endif
        .pokemonScale = 312,
        .pokemonOffset = 3,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Armaldo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Armaldo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Armaldo,
        .shinyPalette = gMonShinyPalette_Armaldo,
        .iconSprite = gMonIcon_Armaldo,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_L)
        FOOTPRINT(Armaldo)
        OVERWORLD(
            sPicTable_Armaldo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Armaldo,
            gShinyOverworldPalette_Armaldo
        )
        .levelUpLearnset = sArmaldoLevelUpLearnset,
        .teachableLearnset = sArmaldoTeachableLearnset,
    },
#endif //P_FAMILY_ANORITH

#if P_FAMILY_FEEBAS
    [SPECIES_FEEBAS] =
    {
        .baseHP        = 20,
        .baseAttack    = 15,
        .baseDefense   = 20,
        .baseSpeed     = 80,
        .baseSpAttack  = 10,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 40 : 61,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_OBLIVIOUS, ABILITY_ADAPTABILITY },
    #else
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_ADAPTABILITY },
    #endif
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Barschwa"),
#else
        .speciesName = _("FEEBAS"),
#endif
        .cryId = CRY_FEEBAS,
        .natDexNum = NATIONAL_DEX_FEEBAS,
#if GERMAN
        .categoryName = _("Fisch"),
#else
        .categoryName = _("Fish"),
#endif
        .height = 6,
        .weight = 74,
        .description = COMPOUND_STRING(
#if GERMAN
            "Barschwa lebt in Teichen, die reich\n"
            "an Tang und Schilf sind. Aufgrund seiner\n"
            "liederlichen Gestalt, wird es nur von\n"
            "wenigen trainiert."),
#else
            "Feebas live in ponds that are heavily\n"
            "infested with weeds. Because of its\n"
            "hopelessly shabby appearance, it\n"
            "seems as if few Trainers raise it."),
#endif
        .pokemonScale = 423,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Feebas,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SLOW,
        .backPic = gMonBackPic_Feebas,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 6,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Feebas,
        .shinyPalette = gMonShinyPalette_Feebas,
        .iconSprite = gMonIcon_Feebas,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 2, SHADOW_SIZE_S)
        FOOTPRINT(Feebas)
        OVERWORLD(
            sPicTable_Feebas,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Feebas,
            gShinyOverworldPalette_Feebas
        )
        .levelUpLearnset = sFeebasLevelUpLearnset,
        .teachableLearnset = sFeebasTeachableLearnset,
        .eggMoveLearnset = sFeebasEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_MILOTIC, CONDITIONS({IF_MIN_BEAUTY, 170})},
                                {EVO_TRADE, 0, SPECIES_MILOTIC, CONDITIONS({IF_HOLD_ITEM, ITEM_PRISM_SCALE})},
                                {EVO_ITEM, ITEM_PRISM_SCALE, SPECIES_MILOTIC}),
    },

    [SPECIES_MILOTIC] =
    {
        .baseHP        = 95,
        .baseAttack    = 60,
        .baseDefense   = 79,
        .baseSpeed     = 81,
        .baseSpAttack  = 100,
        .baseSpDefense = 125,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 189 : 213,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_DRAGON),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_MARVEL_SCALE, ABILITY_COMPETITIVE, ABILITY_CUTE_CHARM },
    #else
        .abilities = { ABILITY_MARVEL_SCALE, ABILITY_NONE, ABILITY_CUTE_CHARM },
    #endif
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Milotic"),
#else
        .speciesName = _("MILOTIC"),
#endif
        .cryId = CRY_MILOTIC,
        .natDexNum = NATIONAL_DEX_MILOTIC,
#if GERMAN
        .categoryName = _("Zartheit"),
#else
        .categoryName = _("Tender"),
#endif
        .height = 62,
        .weight = 1620,
        .description = COMPOUND_STRING(
#if GERMAN
            "Man sagt, es lebe am Grund von großen\n"
            "Seen. Da es als das schönste aller\n"
            "Pokémon gilt, wurde es schon oft\n"
            "gemalt und als Statue dargestellt."),
#else
            "It is said to live at the bottom of\n"
            "large lakes. Considered to be the most\n"
            "beautiful of all Pokémon, it has been\n"
            "depicted in paintings and statues."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Milotic,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_GLOW_BLUE : ANIM_CIRCULAR_STRETCH_TWICE,
        .frontAnimDelay = 45,
        .backPic = gMonBackPic_Milotic,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Milotic,
        .shinyPalette = gMonShinyPalette_Milotic,
        .iconSprite = gMonIcon_Milotic,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_MiloticF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_MiloticF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_M)
        FOOTPRINT(Milotic)
        OVERWORLD(
            sPicTable_Milotic,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Milotic,
            gShinyOverworldPalette_Milotic
        )
        OVERWORLD_FEMALE(
            sPicTable_MiloticF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following
        )
        .levelUpLearnset = sMiloticLevelUpLearnset,
        .teachableLearnset = sMiloticTeachableLearnset,
    },
#endif //P_FAMILY_FEEBAS

#if P_FAMILY_CASTFORM
    [SPECIES_CASTFORM_NORMAL] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .itemCommon = ITEM_MYSTIC_WATER,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_FORECAST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Formeo"),
#else
        .speciesName = _("CASTFORM"),
#endif
        .cryId = CRY_CASTFORM,
        .natDexNum = NATIONAL_DEX_CASTFORM,
#if GERMAN
        .categoryName = _("Wetter"),
#else
        .categoryName = _("Weather"),
#endif
        .height = 3,
        .weight = 8,
        .description = COMPOUND_STRING(
#if GERMAN
        "Formeos Äußeres hängt vom Wetter ab.\n"
        "Ändert sich das Klima in Punkto Temperatur\n"
        "oder Feuchtigkeit, so ändert sich\n"
        "scheinbar seine Zellstruktur."),
#else
            "It alters its form depending on the\n"
            "weather. Changes in the climate such as\n"
            "the temperature and humidity appear to\n"
            "affect its cellular structure."),
#endif
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformNormal,
        .frontPicSize = MON_COORDS_SIZE(24, 32),
        .frontPicYOffset = 17,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 12),
                ANIMCMD_FRAME(1, 24),
                ANIMCMD_FRAME(0, 24),
                ANIMCMD_FRAME(1, 24),
                ANIMCMD_FRAME(0, 24),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 16,
        .backPic = gMonBackPic_CastformNormal,
        .backPicSize = MON_COORDS_SIZE(32, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_CastformNormal,
        .shinyPalette = gMonShinyPalette_CastformNormal,
        .iconSprite = gMonIcon_CastformNormal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_S)
        FOOTPRINT(Castform)
        OVERWORLD(
            sPicTable_CastformNormal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_CastformNormal,
            gShinyOverworldPalette_CastformNormal
        )
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformFormChangeTable,
    },

    [SPECIES_CASTFORM_SUNNY] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .itemCommon = ITEM_MYSTIC_WATER,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_FORECAST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Formeo"),
#else
        .speciesName = _("CASTFORM"),
#endif
        .cryId = CRY_CASTFORM,
        .natDexNum = NATIONAL_DEX_CASTFORM,
#if GERMAN
        .categoryName = _("Wetter"),
#else
        .categoryName = _("Weather"),
#endif
        .height = 3,
        .weight = 8,
        .description = COMPOUND_STRING(
#if GERMAN
        "Diese Gestalt nimmt Formeo\n"
        "an sonnigen Tagen an. Versuche, diesen\n"
        "Wandel künstlich mit einem Heizstrahler\n"
        "herbeizuführen, schlugen fehl."),
#else
            "Castform takes this form on bright days.\n"
            "In an experiment where is was placed in\n"
            "front of a heater, it didn't change to this\n"
            "form. Its body is warm and toasty."),
#endif
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformSunny,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 9,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 12),
                ANIMCMD_FRAME(1, 12),
                ANIMCMD_FRAME(0, 12),
                ANIMCMD_FRAME(1, 12),
                ANIMCMD_FRAME(0, 12),
                ANIMCMD_FRAME(1, 12),
                ANIMCMD_FRAME(0, 12),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SLIDE_WOBBLE : ANIM_GROW_VIBRATE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_CastformSunny,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = P_GBA_STYLE_SPECIES_GFX ? BACK_ANIM_CONVEX_DOUBLE_ARC : BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_CastformSunny,
        .shinyPalette = gMonShinyPalette_CastformSunny,
        .iconSprite = gMonIcon_CastformSunny,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_S)
        FOOTPRINT(Castform)
        OVERWORLD(
            sPicTable_CastformSunny,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_CastformSunny,
            gShinyOverworldPalette_CastformSunny
        )
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_CASTFORM_RAINY] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .itemCommon = ITEM_MYSTIC_WATER,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_FORECAST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Formeo"),
#else
        .speciesName = _("CASTFORM"),
#endif
        .cryId = CRY_CASTFORM,
        .natDexNum = NATIONAL_DEX_CASTFORM,
#if GERMAN
        .categoryName = _("Wetter"),
#else
        .categoryName = _("Weather"),
#endif
        .height = 3,
        .weight = 8,
        .description = COMPOUND_STRING(
#if GERMAN
        "Diese Gestalt nimmt Formeo an, wenn Regen\n"
        "auf es niederprasselt. Sein Körper ist\n"
        "dann weich und hat etwas Wasser\n"
        "aufgesogen."),
#else
            "This is Castform's form while it's raining.\n"
            "In an experiment where it was placed in a\n"
            "shower, it didn't change to this form. Its\n"
            "body is soft, slightly swollen with water."),
#endif
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformRainy,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 9,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 22),
                ANIMCMD_FRAME(1, 22),
                ANIMCMD_FRAME(0, 22),
                ANIMCMD_FRAME(1, 22),
                ANIMCMD_FRAME(0, 11),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SLIDE_WOBBLE : ANIM_SWING_CONVEX_FAST,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_CastformRainy,
        .backPicSize = MON_COORDS_SIZE(40, 64),
        .backPicYOffset = 0,
        .backAnimId = P_GBA_STYLE_SPECIES_GFX ? BACK_ANIM_CONVEX_DOUBLE_ARC : BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_CastformRainy,
        .shinyPalette = gMonShinyPalette_CastformRainy,
        .iconSprite = gMonIcon_CastformRainy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_S)
        FOOTPRINT(Castform)
        OVERWORLD(
            sPicTable_CastformRainy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_CastformRainy,
            gShinyOverworldPalette_CastformRainy
        )
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_CASTFORM_SNOWY] =
    {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 145,
        .evYield_HP = 1,
        .itemCommon = ITEM_MYSTIC_WATER,
        .itemRare = ITEM_MYSTIC_WATER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_FORECAST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Formeo"),
#else
        .speciesName = _("CASTFORM"),
#endif
        .cryId = CRY_CASTFORM,
        .natDexNum = NATIONAL_DEX_CASTFORM,
#if GERMAN
        .categoryName = _("Wetter"),
#else
        .categoryName = _("Weather"),
#endif
        .height = 3,
        .weight = 8,
        .description = COMPOUND_STRING(
#if GERMAN
        "Diese Gestalt nimmt Formeo an,\n"
        "wenn es hagelt. Versuche, diesen Wandel\n"
        "künstlich mithilfe einer Gefriertruhe\n"
        "herbeizuführen, schlugen fehl."),
#else
            "This is Castform's form in a hailstorm.\n"
            "In an experiment where it was placed\n"
            "in a freezer, it didn't change to this form.\n"
            "Its cold skin is as smooth as ice."),
#endif
        .pokemonScale = 435,
        .pokemonOffset = -5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CastformSnowy,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 8,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 5),
                ANIMCMD_FRAME(1, 12),
                ANIMCMD_FRAME(0, 12),
                ANIMCMD_FRAME(1, 29),
                ANIMCMD_FRAME(0, 12),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_SLIDE_WOBBLE : ANIM_V_STRETCH,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_CastformSnowy,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = P_GBA_STYLE_SPECIES_GFX ? BACK_ANIM_CONVEX_DOUBLE_ARC : BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_CastformSnowy,
        .shinyPalette = gMonShinyPalette_CastformSnowy,
        .iconSprite = gMonIcon_CastformSnowy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_S)
        FOOTPRINT(Castform)
        OVERWORLD(
            sPicTable_CastformSnowy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_CastformSnowy,
            gShinyOverworldPalette_CastformSnowy
        )
        .levelUpLearnset = sCastformLevelUpLearnset,
        .teachableLearnset = sCastformTeachableLearnset,
        .eggMoveLearnset = sCastformEggMoveLearnset,
        .formSpeciesIdTable = sCastformFormSpeciesIdTable,
        .formChangeTable = sCastformFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_CASTFORM

#if P_FAMILY_KECLEON
    [SPECIES_KECLEON] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 154 : 132,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_COLOR_CHANGE, ABILITY_NONE, ABILITY_PROTEAN },
    #else
        .abilities = { ABILITY_COLOR_CHANGE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Kecleon"),
#else
        .speciesName = _("KECLEON"),
#endif
        .cryId = CRY_KECLEON,
        .natDexNum = NATIONAL_DEX_KECLEON,
#if GERMAN
        .categoryName = _("Farbenspiel"),
#else
        .categoryName = _("Color Swap"),
#endif
        .height = 10,
        .weight = 220,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kecleon kann seine Körperfarbe der\n"
            "Umgebungsfarbe anpassen. Wird es\n"
            "erschreckt, kehrt seine ursprüngliche\n"
            "Farbe zurück."),
#else
            "A Pokémon that has the ability to alter its\n"
            "body colors to match its surroundings.\n"
            "A Kecleon reverts to its original colors if\n"
            "it is startled."),
#endif
        .pokemonScale = 316,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kecleon,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_FLICKER_INCREASING,
        .frontAnimDelay = 30,
        .backPic = gMonBackPic_Kecleon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Kecleon,
        .shinyPalette = gMonShinyPalette_Kecleon,
        .iconSprite = gMonIcon_Kecleon,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_S)
        FOOTPRINT(Kecleon)
        OVERWORLD(
            sPicTable_Kecleon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kecleon,
            gShinyOverworldPalette_Kecleon
        )
        .levelUpLearnset = sKecleonLevelUpLearnset,
        .teachableLearnset = sKecleonTeachableLearnset,
        .eggMoveLearnset = sKecleonEggMoveLearnset,
    },
#endif //P_FAMILY_KECLEON

#if P_FAMILY_SHUPPET
    [SPECIES_SHUPPET] =
    {
        .baseHP        = 44,
        .baseAttack    = 75,
        .baseDefense   = 35,
        .baseSpeed     = 45,
        .baseSpAttack  = 63,
        .baseSpDefense = 33,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 59 : 97,
        .evYield_Attack = 1,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_FRISK, ABILITY_CURSED_BODY },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_CURSED_BODY },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Shuppet"),
#else
        .speciesName = _("SHUPPET"),
#endif
        .cryId = CRY_SHUPPET,
        .natDexNum = NATIONAL_DEX_SHUPPET,
#if GERMAN
        .categoryName = _("Puppe"),
#else
        .categoryName = _("Puppet"),
#endif
        .height = 6,
        .weight = 23,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es schleicht durch die finstere Nacht und\n"
        "sucht nach negativen Emotionen wie Neid\n"
        "und Missgunst. Bei Sonnenaufgang kehrt\n"
        "es in sein Nest zurück."),
#else
            "This Pokémon roams about deep in the\n"
            "night seeking such negative emotions as\n"
            "grudges and envy. It retreats to its nest\n"
            "when the sun begins to rise."),
#endif
        .pokemonScale = 440,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shuppet,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 12 : 14,
        .backPic = gMonBackPic_Shuppet,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 5,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Shuppet,
        .shinyPalette = gMonShinyPalette_Shuppet,
        .iconSprite = gMonIcon_Shuppet,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 12, SHADOW_SIZE_S)
        FOOTPRINT(Shuppet)
        OVERWORLD(
            sPicTable_Shuppet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Shuppet,
            gShinyOverworldPalette_Shuppet
        )
        .levelUpLearnset = sShuppetLevelUpLearnset,
        .teachableLearnset = sShuppetTeachableLearnset,
        .eggMoveLearnset = sShuppetEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_BANETTE}),
    },

    [SPECIES_BANETTE] =
    {
        .baseHP        = 64,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 83,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 179,
        .evYield_Attack = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INSOMNIA, ABILITY_FRISK, ABILITY_CURSED_BODY },
    #else
        .abilities = { ABILITY_INSOMNIA, ABILITY_NONE, ABILITY_CURSED_BODY },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Banette"),
#else
        .speciesName = _("BANETTE"),
#endif
        .cryId = CRY_BANETTE,
        .natDexNum = NATIONAL_DEX_BANETTE,
        .categoryName = _("Marionette"),
        .height = 11,
        .weight = 125,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dieses Pokémon war einst eine zurück-\n"
            "gelassene Plüschpuppe. Banette lebt\n"
            "auf Müllhalden und hält nach dem Kind\n"
            "Ausschau, das es weggeworfen hat."),
#else
            "An abandoned plush doll became this\n"
            "Pokémon. They are said to live in garbage\n"
            "dumps and wander about in search of the\n"
            "children that threw them away."),
#endif
        .pokemonScale = 262,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Banette,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONVEX : ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backPic = gMonBackPic_Banette,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 5,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Banette,
        .shinyPalette = gMonShinyPalette_Banette,
        .iconSprite = gMonIcon_Banette,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_S)
        FOOTPRINT(Banette)
        OVERWORLD(
            sPicTable_Banette,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Banette,
            gShinyOverworldPalette_Banette
        )
        .levelUpLearnset = sBanetteLevelUpLearnset,
        .teachableLearnset = sBanetteTeachableLearnset,
        .formSpeciesIdTable = sBanetteFormSpeciesIdTable,
        .formChangeTable = sBanetteFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_BANETTE_MEGA] =
    {
        .baseHP        = 64,
        .baseAttack    = 165,
        .baseDefense   = 75,
        .baseSpeed     = 75,
        .baseSpAttack  = 93,
        .baseSpDefense = 83,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
        .expYield = 194,
        .evYield_Attack = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_PRANKSTER, ABILITY_PRANKSTER, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Banette"),
#else
        .speciesName = _("BANETTE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_BANETTE_MEGA,
    #else
        .cryId = CRY_BANETTE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_BANETTE,
        .categoryName = _("Marionette"),
        .height = 12,
        .weight = 130,
        .description = COMPOUND_STRING(
#if GERMAN
        "Von gewaltigen Energiemengen verstärkt,\n"
        "wird sein Fluch unbeherrschbar. Es hegt\n"
        "selbst gegen seinen eigenen Trainer einen\n"
        "Groll."),
#else
            "Extraordinary energy amplifies its\n"
            "cursing power to such an extent that it\n"
            "can't help but curse its own Trainer."),
#endif
        .pokemonScale = 262,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BanetteMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_BanetteMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_BanetteMega,
        .shinyPalette = gMonShinyPalette_BanetteMega,
        .iconSprite = gMonIcon_BanetteMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 16, SHADOW_SIZE_M)
        FOOTPRINT(Banette)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_BanetteMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BanetteMega,
            gShinyOverworldPalette_BanetteMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sBanetteLevelUpLearnset,
        .teachableLearnset = sBanetteTeachableLearnset,
        .formSpeciesIdTable = sBanetteFormSpeciesIdTable,
        .formChangeTable = sBanetteFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_SHUPPET

#if P_FAMILY_DUSKULL
    [SPECIES_DUSKULL] =
    {
        .baseHP        = 20,
        .baseAttack    = 40,
        .baseDefense   = 90,
        .baseSpeed     = 25,
        .baseSpAttack  = 30,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 59 : 97,
        .evYield_Defense = (P_UPDATED_EVS >= GEN_4) ? 0 : 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_FRISK },
    #else
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Zwirrlicht"),
#else
        .speciesName = _("DUSKULL"),
#endif
        .cryId = CRY_DUSKULL,
        .natDexNum = NATIONAL_DEX_DUSKULL,
        .categoryName = _("Requiem"),
        .height = 8,
        .weight = 150,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Blick seines purpurroten Auges jagt\n"
            "sogar gestandenen Personen einen Schauer\n"
            "über den Rücken. Es ist nachtaktiv und\n"
            "nutzt die Dunkelheit für seine Zwecke."),
#else
            "A glare from its single scarlet eye makes\n"
            "even burly grown-ups freeze in utter fear.\n"
            "It is a nocturnal Pokémon that roams\n"
            "about under the cloak of darkness."),
#endif
        .pokemonScale = 406,
        .pokemonOffset = -4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Duskull,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_ZIGZAG_FAST,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 9 : 13,
        .backPic = gMonBackPic_Duskull,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Duskull,
        .shinyPalette = gMonShinyPalette_Duskull,
        .iconSprite = gMonIcon_Duskull,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_S)
        FOOTPRINT(Duskull)
        OVERWORLD(
            sPicTable_Duskull,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Duskull,
            gShinyOverworldPalette_Duskull
        )
        .levelUpLearnset = sDuskullLevelUpLearnset,
        .teachableLearnset = sDuskullTeachableLearnset,
        .eggMoveLearnset = sDuskullEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_DUSCLOPS}),
    },

    [SPECIES_DUSCLOPS] =
    {
        .baseHP        = 40,
        .baseAttack    = 70,
        .baseDefense   = 130,
        .baseSpeed     = 25,
        .baseSpAttack  = 60,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 90,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 159 : 179,
        .evYield_Defense = 1,
        .evYield_SpDefense = (P_UPDATED_EVS >= GEN_4) ? 1 : 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FRISK },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Zwirrklop"),
#else
        .speciesName = _("DUSCLOPS"),
#endif
        .cryId = CRY_DUSCLOPS,
        .natDexNum = NATIONAL_DEX_DUSCLOPS,
#if GERMAN
        .categoryName = _("Wink"),
#else
        .categoryName = _("Beckon"),
#endif
        .height = 16,
        .weight = 306,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zwirrklops Körper ist angeblich hohl und\n"
        "nur ein spektraler Feuerball glüht darin.\n"
        "Niemand ist jedoch in der Lage, diese\n"
        "Theorie zu bestätigen."),
#else
            "It is thought that its body is hollow with\n"
            "only a spectral ball of fire burning inside.\n"
            "However, no one has been able to\n"
            "confirm this theory as fact."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 299,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Dusclops,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .frontAnimDelay = 30,
        .backPic = gMonBackPic_Dusclops,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 2,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Dusclops,
        .shinyPalette = gMonShinyPalette_Dusclops,
        .iconSprite = gMonIcon_Dusclops,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Dusclops)
        OVERWORLD(
            sPicTable_Dusclops,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dusclops,
            gShinyOverworldPalette_Dusclops
        )
        .levelUpLearnset = sDusclopsLevelUpLearnset,
        .teachableLearnset = sDusclopsTeachableLearnset,
    #if P_GEN_4_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_DUSKNOIR, CONDITIONS({IF_HOLD_ITEM, ITEM_REAPER_CLOTH})},
                                {EVO_ITEM, ITEM_REAPER_CLOTH, SPECIES_DUSKNOIR}),
    #endif
    },

#if P_GEN_4_CROSS_EVOS
    [SPECIES_DUSKNOIR] =
    {
        .baseHP        = 45,
        .baseAttack    = 100,
        .baseDefense   = 135,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 263,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 236,
    #else
        .expYield = 210,
    #endif
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_FRISK },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Zwirrfinst"),
#else
        .speciesName = _("DUSKNOIR"),
#endif
        .cryId = CRY_DUSKNOIR,
        .natDexNum = NATIONAL_DEX_DUSKNOIR,
#if GERMAN
        .categoryName = _("Greifer"),
#else
        .categoryName = _("Gripper"),
#endif
        .height = 22,
        .weight = 1066,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zwirrfinst reist zwischen dem Dies-\n"
        "und dem Jenseits. Die Menschen fürchten\n"
        "es, da es verirrte Seelen aufsaugt."),
#else
            "This feared Pokémon is said to travel to\n"
            "worlds unknown. Some even believe that\n"
            "it takes lost spirits into its pliant body\n"
            "and guides them home."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Dusknoir,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 9),
            ANIMCMD_FRAME(0, 9),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Dusknoir,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Dusknoir,
        .shinyPalette = gMonShinyPalette_Dusknoir,
        .iconSprite = gMonIcon_Dusknoir,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 13, SHADOW_SIZE_M)
        FOOTPRINT(Dusknoir)
        OVERWORLD(
            sPicTable_Dusknoir,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dusknoir,
            gShinyOverworldPalette_Dusknoir
        )
        .levelUpLearnset = sDusknoirLevelUpLearnset,
        .teachableLearnset = sDusknoirTeachableLearnset,
    },
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_DUSKULL

#if P_FAMILY_TROPIUS
    [SPECIES_TROPIUS] =
    {
        .baseHP        = 99,
        .baseAttack    = 68,
        .baseDefense   = 83,
        .baseSpeed     = 51,
        .baseSpAttack  = 72,
        .baseSpDefense = 87,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FLYING),
        .catchRate = 200,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 161 : 169,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_GRASS),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SOLAR_POWER, ABILITY_HARVEST },
    #else
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE, ABILITY_HARVEST },
    #endif
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Tropius"),
#else
        .speciesName = _("TROPIUS"),
#endif
        .cryId = CRY_TROPIUS,
        .natDexNum = NATIONAL_DEX_TROPIUS,
#if GERMAN
        .categoryName = _("Obst"),
#else
        .categoryName = _("Fruit"),
#endif
        .height = 20,
        .weight = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
        "Tropius fliegt, indem es seine weiten\n"
        "Blätter bewegt. Die Früchte, die um seinen\n"
        "Hals wachsen, sind schmackhaft und süß.\n"
        "Es verteilt Blütenstaub von seinem Hals."),
#else
            "It flies by flapping its broad leaves.\n"
            "The bunch of fruit that grows around its\n"
            "neck is deliciously sweet. In the spring,\n"
            "it scatters pollen from its neck."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 344,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Tropius,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Tropius,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 0,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Tropius,
        .shinyPalette = gMonShinyPalette_Tropius,
        .iconSprite = gMonIcon_Tropius,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 13, SHADOW_SIZE_L)
        FOOTPRINT(Tropius)
        OVERWORLD(
            sPicTable_Tropius,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tropius,
            gShinyOverworldPalette_Tropius
        )
        .levelUpLearnset = sTropiusLevelUpLearnset,
        .teachableLearnset = sTropiusTeachableLearnset,
        .eggMoveLearnset = sTropiusEggMoveLearnset,
    },
#endif //P_FAMILY_TROPIUS

#if P_FAMILY_CHIMECHO
#if P_GEN_4_CROSS_EVOS
    [SPECIES_CHINGLING] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 57 : 74,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_CLEANSE_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Klingplim"),
#else
        .speciesName = _("CHINGLING"),
#endif
        .cryId = CRY_CHINGLING,
        .natDexNum = NATIONAL_DEX_CHINGLING,
#if GERMAN
        .categoryName = _("Glöckchen"),
#else
        .categoryName = _("Bell"),
#endif
        .height = 2,
        .weight = 6,
        .description = COMPOUND_STRING(
#if GERMAN
            "Menschenohren können die Frequenz\n"
            "seines Rufs nicht hören. Schreit es\n"
            "los, hört es so bald nicht mehr auf."),
#else
            "There is an orb inside its mouth.\n"
            "When it hops, the orb bounces all\n"
            "over and makes a ringing sound.\n"
            "It can cry for an awfully long time."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chingling,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Chingling,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Chingling,
        .shinyPalette = gMonShinyPalette_Chingling,
        .iconSprite = gMonIcon_Chingling,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Chingling)
        OVERWORLD(
            sPicTable_Chingling,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Chingling,
            gShinyOverworldPalette_Chingling
        )
        .levelUpLearnset = sChinglingLevelUpLearnset,
        .teachableLearnset = sChinglingTeachableLearnset,
        .eggMoveLearnset = sChinglingEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_CHIMECHO, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD},{IF_TIME, TIME_NIGHT})}),
    },
#endif //P_GEN_4_CROSS_EVOS

    [SPECIES_CHIMECHO] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 75 : 65,
        .baseAttack    = 50,
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 80 : 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = P_UPDATED_STATS >= GEN_7 ? 90 : 80,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 159,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 149,
    #else
        .expYield = 147,
    #endif
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_CLEANSE_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Palimpalim"),
#else
        .speciesName = _("CHIMECHO"),
#endif
        .cryId = CRY_CHIMECHO,
        .natDexNum = NATIONAL_DEX_CHIMECHO,
#if GERMAN
        .categoryName = _("Windspiel"),
#else
        .categoryName = _("Wind Chime"),
#endif
        .height = 6,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wird es heiß, fliegen sie wild umher. Sie\n"
            "kommunizieren miteinander mit sieben\n"
            "unterschiedlichen Schreien."),
#else
            "They fly about very actively when the hot\n"
            "season arrives. They communicate among\n"
            "themselves using seven different and\n"
            "distinguishing cries."),
#endif
        .pokemonScale = 505,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chimecho,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 12 : 16,
        .backPic = gMonBackPic_Chimecho,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 9,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Chimecho,
        .shinyPalette = gMonShinyPalette_Chimecho,
        .iconSprite = gMonIcon_Chimecho,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 16, SHADOW_SIZE_S)
        FOOTPRINT(Chimecho)
        OVERWORLD(
            sPicTable_Chimecho,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Chimecho,
            gShinyOverworldPalette_Chimecho
        )
        .levelUpLearnset = sChimechoLevelUpLearnset,
        .teachableLearnset = sChimechoTeachableLearnset,
        .eggMoveLearnset = sChimechoEggMoveLearnset,
        .formSpeciesIdTable = sChimechoFormSpeciesIdTable,
        .formChangeTable = sChimechoFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_CHIMECHO_MEGA] =
    {
        .baseHP        = 75,
        .baseAttack    = 50,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 135,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_STEEL),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_7
        .expYield = 159,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 149,
    #else
        .expYield = 147,
    #endif
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_CLEANSE_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Palimpalim"),
#else
        .speciesName = _("CHIMECHO"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_CHIMECHO_MEGA,
    #else
        .cryId = CRY_CHIMECHO,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_CHIMECHO,
#if GERMAN
        .categoryName = _("Windspiel"),
#else
        .categoryName = _("Wind Chime"),
#endif
        .height = 12,
        .weight = 80,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit Schallwellen, die es durch Vibration\n"
            "seines ganzen Körpers erzeugt, greift es\n"
            "alles ringsum an. Wer diese hört, vergisst\n"
            "seine eigene Identität."),
#else
            "It vibrates its entire body to attack in\n"
            "all directions using sound waves. Any who\n"
            "hear the vibrations get so confused, they\n"
            "forget who they are."),
#endif
        .frontPic = gMonFrontPic_ChimechoMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_ChimechoMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ChimechoMega,
        .shinyPalette = gMonShinyPalette_ChimechoMega,
        .iconSprite = gMonIcon_ChimechoMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Chimecho)
        SHADOW(-2, 18, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sChimechoLevelUpLearnset,
        .teachableLearnset = sChimechoTeachableLearnset,
        .eggMoveLearnset = sChimechoEggMoveLearnset,
        .formSpeciesIdTable = sChimechoFormSpeciesIdTable,
        .formChangeTable = sChimechoFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_CHIMECHO

#if P_FAMILY_ABSOL
    [SPECIES_ABSOL] =
    {
        .baseHP        = 65,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 75,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 163 : 174,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_PRESSURE, ABILITY_SUPER_LUCK, ABILITY_JUSTIFIED },
    #else
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_JUSTIFIED },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Absol"),
#else
        .speciesName = _("ABSOL"),
#endif
        .cryId = CRY_ABSOL,
        .natDexNum = NATIONAL_DEX_ABSOL,
#if GERMAN
        .categoryName = _("Desaster"),
#else
        .categoryName = _("Disaster"),
#endif
        .height = 12,
        .weight = 470,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es bemerkt sogar kleinste Veränderungen\n"
            "der Luft und der Erde und kann Natur-\n"
            "katastrophen vorhersagen. Absol lebt\n"
            "sehr lange, um die 100 Jahre."),
#else
            "It sharply senses even subtle changes in\n"
            "the sky and the land to predict natural\n"
            "disasters. It is a long-lived Pokémon that\n"
            "has a life-span of 100 years."),
#endif
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Absol,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 64) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .frontAnimDelay = 45,
        .backPic = gMonBackPic_Absol,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Absol,
        .shinyPalette = gMonShinyPalette_Absol,
        .iconSprite = gMonIcon_Absol,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 6, SHADOW_SIZE_L)
        FOOTPRINT(Absol)
        OVERWORLD(
            sPicTable_Absol,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Absol,
            gShinyOverworldPalette_Absol
        )
        .levelUpLearnset = sAbsolLevelUpLearnset,
        .teachableLearnset = sAbsolTeachableLearnset,
        .eggMoveLearnset = sAbsolEggMoveLearnset,
        .formSpeciesIdTable = sAbsolFormSpeciesIdTable,
        .formChangeTable = sAbsolFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_ABSOL_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 150,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 115,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 30,
        .expYield = 198,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Absol"),
#else
        .speciesName = _("ABSOL"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_ABSOL_MEGA,
    #else
        .cryId = CRY_ABSOL,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_ABSOL,
#if GERMAN
        .categoryName = _("Desaster"),
#else
        .categoryName = _("Disaster"),
#endif
        .height = 12,
        .weight = 490,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses von Natur aus konfliktscheue\n"
        "Pokémon nimmt nur widerwillig diese eigens\n"
        "auf Kämpfe ausgerichtete Gestalt an."),
#else
            "As the energy of Mega Evolution fills it,\n"
            "its fur bristles. What you see on its back\n"
            "are not true wings, and this Pokémon isn't\n"
            "able to fly."),
#endif
        .pokemonScale = 301,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AbsolMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AbsolMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_AbsolMega,
        .shinyPalette = gMonShinyPalette_AbsolMega,
        .iconSprite = gMonIcon_AbsolMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 7, SHADOW_SIZE_L)
        FOOTPRINT(Absol)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AbsolMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_AbsolMega,
            gShinyOverworldPalette_AbsolMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAbsolLevelUpLearnset,
        .teachableLearnset = sAbsolTeachableLearnset,
        .eggMoveLearnset = sAbsolEggMoveLearnset,
        .formSpeciesIdTable = sAbsolFormSpeciesIdTable,
        .formChangeTable = sAbsolFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_ABSOL_MEGA_Z] =
    {
        .baseHP        = 65,
        .baseAttack    = 154,
        .baseDefense   = 60,
        .baseSpeed     = 151,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK, TYPE_GHOST),
        .catchRate = 30,
        .expYield = 198,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Absol"),
#else
        .speciesName = _("ABSOL"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_ABSOL_MEGA_Z,
    #else
        .cryId = CRY_ABSOL,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_ABSOL,
#if GERMAN
        .categoryName = _("Desaster"),
#else
        .categoryName = _("Disaster"),
#endif
        .height = 12,
        .weight = 490,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses von Natur aus konfliktscheue\n"
        "Pokémon nimmt nur widerwillig diese eigens\n"
        "auf Kämpfe ausgerichtete Gestalt an."),
#else
            "Using fur that it has made into sharp,\n"
            "clawlike shapes, it cuts down foes with\n"
            "a single blow. This is an act of kindness\n"
            "to keep them from suffering."),
#endif
        .frontPic = gMonFrontPic_AbsolMegaZ,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AbsolMegaZ,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_AbsolMegaZ,
        .shinyPalette = gMonShinyPalette_AbsolMegaZ,
        .iconSprite = gMonIcon_AbsolMegaZ,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Absol)
        SHADOW(-1, 7, SHADOW_SIZE_XL_BATTLE_ONLY)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAbsolLevelUpLearnset,
        .teachableLearnset = sAbsolTeachableLearnset,
        .eggMoveLearnset = sAbsolEggMoveLearnset,
        .formSpeciesIdTable = sAbsolFormSpeciesIdTable,
        .formChangeTable = sAbsolFormChangeTable,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_ABSOL

#if P_FAMILY_SNORUNT
    [SPECIES_SNORUNT] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 74,
        .evYield_HP = 1,
        .itemRare = ITEM_SNOWBALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_ICE_BODY, ABILITY_MOODY },
    #else
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_MOODY },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Schneppke"),
#else
        .speciesName = _("SNORUNT"),
#endif
        .cryId = CRY_SNORUNT,
        .natDexNum = NATIONAL_DEX_SNORUNT,
#if GERMAN
        .categoryName = _("Schneehut"),
#else
        .categoryName = _("Snow Hat"),
#endif
        .height = 7,
        .weight = 168,
        .description = COMPOUND_STRING(
#if GERMAN
        "Normalerweise ziehen sie in\n"
        "Fünfergruppen umher. Wird ein Schneppke\n"
        "nachts in Schneegebieten gesehen,\n"
        "soll es am nächsten Morgen schneien."),
#else
            "They tend to move about in groups of\n"
            "around five Snorunt. In snowy regions,\n"
            "it is said that when they are seen late at\n"
            "night, snowfall will arrive by morning."),
#endif
        .pokemonScale = 380,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Snorunt,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .frontAnimDelay = 20,
        .backPic = gMonBackPic_Snorunt,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Snorunt,
        .shinyPalette = gMonShinyPalette_Snorunt,
        .iconSprite = gMonIcon_Snorunt,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Snorunt)
        OVERWORLD(
            sPicTable_Snorunt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Snorunt,
            gShinyOverworldPalette_Snorunt
        )
        .levelUpLearnset = sSnoruntLevelUpLearnset,
        .teachableLearnset = sSnoruntTeachableLearnset,
        .eggMoveLearnset = sSnoruntEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_GLALIE}
                            #if P_GEN_4_CROSS_EVOS
                                ,{EVO_ITEM, ITEM_DAWN_STONE, SPECIES_FROSLASS, CONDITIONS({IF_GENDER, MON_FEMALE})}
                            #endif
                            ),
    },

    [SPECIES_GLALIE] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 168 : 187,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_ICE_BODY, ABILITY_MOODY },
    #else
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_MOODY },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Firnontor"),
#else
        .speciesName = _("GLALIE"),
#endif
        .cryId = CRY_GLALIE,
        .natDexNum = NATIONAL_DEX_GLALIE,
#if GERMAN
        .categoryName = _("Antlitz"),
#else
        .categoryName = _("Face"),
#endif
        .height = 15,
        .weight = 2565,
        .description = COMPOUND_STRING(
#if GERMAN
            "Firnontor kann die Feuchtigkeit in der\n"
            "Atmosphäre sofort einfrieren. Eine\n"
            "schillernde Wolke diamantähnlichen\n"
            "Eises umgibt seinen Körper."),
#else
            "A Glalie has the power to instantaneously\n"
            "freeze moisture in the atmosphere.\n"
            "A dazzling cloud of diamondlike ice\n"
            "crystals forms around its body."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 344,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Glalie,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_ZIGZAG_FAST,
        .enemyMonElevation = 12,
        .backPic = gMonBackPic_Glalie,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Glalie,
        .shinyPalette = gMonShinyPalette_Glalie,
        .iconSprite = gMonIcon_Glalie,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 15, SHADOW_SIZE_M)
        FOOTPRINT(Glalie)
        OVERWORLD(
            sPicTable_Glalie,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Glalie,
            gShinyOverworldPalette_Glalie
        )
        .levelUpLearnset = sGlalieLevelUpLearnset,
        .teachableLearnset = sGlalieTeachableLearnset,
        .formSpeciesIdTable = sGlalieFormSpeciesIdTable,
        .formChangeTable = sGlalieFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_GLALIE_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 75,
        .expYield = 203,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_REFRIGERATE, ABILITY_REFRIGERATE, ABILITY_REFRIGERATE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Firnontor"),
#else
        .speciesName = _("GLALIE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GLALIE_MEGA,
    #else
        .cryId = CRY_GLALIE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GLALIE,
#if GERMAN
        .categoryName = _("Antlitz"),
#else
        .categoryName = _("Face"),
#endif
        .height = 21,
        .weight = 3502,
        .description = COMPOUND_STRING(
#if GERMAN
        "Aus seinem zerbrochenen Maul\n"
        "stößt es eiskalte Luftströme aus, welche\n"
        "die gesamte Umgebung in Weiß hüllen."),
#else
            "The power of Mega Evolution was so strong\n"
            "that it smashed Glalie's jaw. Its inability\n"
            "to eat very well leaves Glalie irritated."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 3,
        .trainerScale = 344,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GlalieMega,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_GlalieMega,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_GlalieMega,
        .shinyPalette = gMonShinyPalette_GlalieMega,
        .iconSprite = gMonIcon_GlalieMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 18, SHADOW_SIZE_L)
        FOOTPRINT(Glalie)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_GlalieMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GlalieMega,
            gShinyOverworldPalette_GlalieMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sGlalieLevelUpLearnset,
        .teachableLearnset = sGlalieTeachableLearnset,
        .formSpeciesIdTable = sGlalieFormSpeciesIdTable,
        .formChangeTable = sGlalieFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS

#if P_GEN_4_CROSS_EVOS
    [SPECIES_FROSLASS] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 110,
        .baseSpAttack  = 80,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ICE, TYPE_GHOST),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 168 : 187,
        .evYield_Speed = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Frosdedje"),
#else
        .speciesName = _("FROSLASS"),
#endif
        .cryId = CRY_FROSLASS,
        .natDexNum = NATIONAL_DEX_FROSLASS,
#if GERMAN
        .categoryName = _("Schneegebiet"),
#else
        .categoryName = _("Snow Land"),
#endif
        .height = 13,
        .weight = 266,
        .description = COMPOUND_STRING(
#if GERMAN
            "In schneereichen Gegenden erzählt\n"
            "man sich, es sei die Wiedergeburt\n"
            "einer in den Bergen Verunglückten."),
#else
            "When it finds people or Pokémon it likes,\n"
            "it freezes them and takes them to its\n"
            "chilly den, where they become its\n"
            "decorations."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Froslass,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Froslass,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Froslass,
        .shinyPalette = gMonShinyPalette_Froslass,
        .iconSprite = gMonIcon_Froslass,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_S)
        FOOTPRINT(Froslass)
        OVERWORLD(
            sPicTable_Froslass,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Froslass,
            gShinyOverworldPalette_Froslass
        )
        .levelUpLearnset = sFroslassLevelUpLearnset,
        .teachableLearnset = sFroslassTeachableLearnset,
        .formSpeciesIdTable = sFroslassFormSpeciesIdTable,
        .formChangeTable = sFroslassFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_FROSLASS_MEGA] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 120,
        .baseSpAttack  = 140,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_ICE, TYPE_GHOST),
        .catchRate = 75,
        .expYield = 168,
        .evYield_Speed = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Frosdedje"),
#else
        .speciesName = _("FROSLASS"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_FROSLASS_MEGA,
    #else
        .cryId = CRY_FROSLASS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_FROSLASS,
#if GERMAN
        .categoryName = _("Schneegebiet"),
#else
        .categoryName = _("Snow Land"),
#endif
        .height = 26,
        .weight = 296,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit grausig frostiger Luft, die von\n"
        "Geister-Energie erfüllt ist, kann es\n"
        "selbst formlose Dinge wie Flammen oder den\n"
        "Wind gefrieren lassen."),
#else
            "This Pokémon can use eerie cold\n"
            "air imbued with ghost energy to\n"
            "freeze even insubstantial things,\n"
            "such as flames or the wind."),
#endif
        .frontPic = gMonFrontPic_FroslassMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 2,
        .backPic = gMonBackPic_FroslassMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_FroslassMega,
        .shinyPalette = gMonShinyPalette_FroslassMega,
        .iconSprite = gMonIcon_FroslassMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Froslass)
        SHADOW(0, 14, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sFroslassLevelUpLearnset,
        .teachableLearnset = sFroslassTeachableLearnset,
        .formSpeciesIdTable = sFroslassFormSpeciesIdTable,
        .formChangeTable = sFroslassFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_SNORUNT

#if P_FAMILY_SPHEAL
    [SPECIES_SPHEAL] =
    {
        .baseHP        = 70,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 55,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ICE, TYPE_WATER),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 58 : 75,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_THICK_FAT, ABILITY_ICE_BODY, ABILITY_OBLIVIOUS },
    #else
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_OBLIVIOUS },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Seemops"),
#else
        .speciesName = _("SPHEAL"),
#endif
        .cryId = CRY_SPHEAL,
        .natDexNum = NATIONAL_DEX_SPHEAL,
#if GERMAN
        .categoryName = _("Applaus"),
#else
        .categoryName = _("Clap"),
#endif
        .height = 8,
        .weight = 395,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seemops hat flauschiges Fell. Daher\n"
            "friert es nie, wenn es sich auf dem Eis\n"
            "entlang rollt oder von Eisschollen aus\n"
            "ins Meer hinabtaucht."),
#else
            "It is completely covered with plushy fur.\n"
            "As a result, it never feels the cold even\n"
            "when it is rolling about on ice floes or\n"
            "diving in the sea."),
#endif
        .pokemonScale = 315,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Spheal,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 43),
            ANIMCMD_FRAME(1, 60),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SPIN : ANIM_SPIN_LONG,
        .frontAnimDelay = 15,
        .backPic = gMonBackPic_Spheal,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 32) : MON_COORDS_SIZE(48, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 18 : 15,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Spheal,
        .shinyPalette = gMonShinyPalette_Spheal,
        .iconSprite = gMonIcon_Spheal,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, -1, SHADOW_SIZE_M)
        FOOTPRINT(Spheal)
        OVERWORLD(
            sPicTable_Spheal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Spheal,
            gShinyOverworldPalette_Spheal
        )
        .levelUpLearnset = sSphealLevelUpLearnset,
        .teachableLearnset = sSphealTeachableLearnset,
        .eggMoveLearnset = sSphealEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_SEALEO}),
    },

    [SPECIES_SEALEO] =
    {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ICE, TYPE_WATER),
        .catchRate = 120,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 144 : 128,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_THICK_FAT, ABILITY_ICE_BODY, ABILITY_OBLIVIOUS },
    #else
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_OBLIVIOUS },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Seejong"),
#else
        .speciesName = _("SEALEO"),
#endif
        .cryId = CRY_SEALEO,
        .natDexNum = NATIONAL_DEX_SEALEO,
#if GERMAN
        .categoryName = _("Spielball"),
#else
        .categoryName = _("Ball Roll"),
#endif
        .height = 11,
        .weight = 876,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seejong lebt in Herden auf Eisschollen.\n"
        "Mit seinen ausgeprägten Flossen kann es\n"
        "Eis zerschlagen. Fünf Mal am Tag taucht\n"
        "es hinab ins Meer, um Beute zu jagen."),
#else
            "Sealeo live in herds on ice floes. Using its\n"
            "powerful flippers, it shatters ice.\n"
            "It dives into the sea to hunt prey five\n"
            "times a day."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sealeo,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Sealeo,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Sealeo,
        .shinyPalette = gMonShinyPalette_Sealeo,
        .iconSprite = gMonIcon_Sealeo,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 2, SHADOW_SIZE_L)
        FOOTPRINT(Sealeo)
        OVERWORLD(
            sPicTable_Sealeo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sealeo,
            gShinyOverworldPalette_Sealeo
        )
        .levelUpLearnset = sSealeoLevelUpLearnset,
        .teachableLearnset = sSealeoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 44, SPECIES_WALREIN}),
    },

    [SPECIES_WALREIN] =
    {
        .baseHP        = 110,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ICE, TYPE_WATER),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 265,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 239,
    #else
        .expYield = 192,
    #endif
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_4
        .abilities = { ABILITY_THICK_FAT, ABILITY_ICE_BODY, ABILITY_OBLIVIOUS },
    #else
        .abilities = { ABILITY_THICK_FAT, ABILITY_NONE, ABILITY_OBLIVIOUS },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Walraisa"),
#else
        .speciesName = _("WALREIN"),
#endif
        .cryId = CRY_WALREIN,
        .natDexNum = NATIONAL_DEX_WALREIN,
#if GERMAN
        .categoryName = _("Eisbrecher"),
#else
        .categoryName = _("Ice Break"),
#endif
        .height = 14,
        .weight = 1506,
        .description = COMPOUND_STRING(
#if GERMAN
            "Um seine Herde zu beschützen, greift der\n"
            "Anführer jeden Eindringling sofort an,\n"
            "auch wenn es ihn sein Leben kosten könnte.\n"
            "Seine Stoßzähne können im Kampf abfallen."),
#else
            "To protect its herd, the leader battles\n"
            "anything that invades its territory, even\n"
            "at the cost of its life. Its tusks may snap\n"
            "off in battle."),
#endif
        .pokemonScale = 316,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Walrein,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Walrein,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Walrein,
        .shinyPalette = gMonShinyPalette_Walrein,
        .iconSprite = gMonIcon_Walrein,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_L)
        FOOTPRINT(Walrein)
        OVERWORLD(
            sPicTable_Walrein,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Walrein,
            gShinyOverworldPalette_Walrein
        )
        .levelUpLearnset = sWalreinLevelUpLearnset,
        .teachableLearnset = sWalreinTeachableLearnset,
    },
#endif //P_FAMILY_SPHEAL

#if P_FAMILY_CLAMPERL
    [SPECIES_CLAMPERL] =
    {
        .baseHP        = 35,
        .baseAttack    = 64,
        .baseDefense   = 85,
        .baseSpeed     = 32,
        .baseSpAttack  = 74,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 69 : 142,
        .evYield_Defense = 1,
        .itemCommon = ITEM_PEARL,
        .itemRare = ITEM_BIG_PEARL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SHELL_ARMOR, ABILITY_NONE, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Perlu"),
#else
        .speciesName = _("CLAMPERL"),
#endif
        .cryId = CRY_CLAMPERL,
        .natDexNum = NATIONAL_DEX_CLAMPERL,
#if GERMAN
        .categoryName = _("Muschel"),
#else
        .categoryName = _("Bivalve"),
#endif
        .height = 4,
        .weight = 525,
        .description = COMPOUND_STRING(
#if GERMAN
            "Perlu fängt die Beute mit seiner Schale.\n"
            "Die Perle, die bei der Entwicklung\n"
            "entsteht, soll angeblich eine\n"
            "geheimnisvolle Energie besitzen."),
#else
            "A Clamperl slams its shell closed on prey\n"
            "to prevent escape. The pearl it creates\n"
            "upon evolution is said to be infused with\n"
            "a mysterious energy."),
#endif
        .pokemonScale = 691,
        .pokemonOffset = 22,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Clamperl,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_TWIST,
        .backPic = gMonBackPic_Clamperl,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Clamperl,
        .shinyPalette = gMonShinyPalette_Clamperl,
        .iconSprite = gMonIcon_Clamperl,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, 1, SHADOW_SIZE_M)
        FOOTPRINT(Clamperl)
        OVERWORLD(
            sPicTable_Clamperl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Clamperl,
            gShinyOverworldPalette_Clamperl
        )
        .levelUpLearnset = sClamperlLevelUpLearnset,
        .teachableLearnset = sClamperlTeachableLearnset,
        .eggMoveLearnset = sClamperlEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_HUNTAIL, CONDITIONS({IF_HOLD_ITEM, ITEM_DEEP_SEA_TOOTH})},
                                {EVO_TRADE, 0, SPECIES_GOREBYSS, CONDITIONS({IF_HOLD_ITEM, ITEM_DEEP_SEA_SCALE})},
                                {EVO_ITEM, ITEM_DEEP_SEA_TOOTH, SPECIES_HUNTAIL},
                                {EVO_ITEM, ITEM_DEEP_SEA_SCALE, SPECIES_GOREBYSS}),
    },

    [SPECIES_HUNTAIL] =
    {
        .baseHP        = 55,
        .baseAttack    = 104,
        .baseDefense   = 105,
        .baseSpeed     = 52,
        .baseSpAttack  = 94,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 170 : 178,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Aalabyss"),
#else
        .speciesName = _("HUNTAIL"),
#endif
        .cryId = CRY_HUNTAIL,
        .natDexNum = NATIONAL_DEX_HUNTAIL,
#if GERMAN
        .categoryName = _("Tiefsee"),
#else
        .categoryName = _("Deep Sea"),
#endif
        .height = 17,
        .weight = 270,
        .description = COMPOUND_STRING(
#if GERMAN
            "Um dem hohen Druck tief unten im Meer\n"
            "standzuhalten, ist sein Rückgrat stabil\n"
            "und solide. Sein fischähnlicher Schwanz\n"
            "hat Augen, die leuchten können."),
#else
            "To withstand the crushing pressure of\n"
            "water deep under the sea, its spine is very\n"
            "thick and sturdy. Its tail, which is shaped\n"
            "like a small fish, has eyes that light up."),
#endif
        .pokemonScale = 307,
        .pokemonOffset = 1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Huntail,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Huntail,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 64) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 4,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Huntail,
        .shinyPalette = gMonShinyPalette_Huntail,
        .iconSprite = gMonIcon_Huntail,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 7, SHADOW_SIZE_L)
        FOOTPRINT(Huntail)
        OVERWORLD(
            sPicTable_Huntail,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Huntail,
            gShinyOverworldPalette_Huntail
        )
        .levelUpLearnset = sHuntailLevelUpLearnset,
        .teachableLearnset = sHuntailTeachableLearnset,
    },

    [SPECIES_GOREBYSS] =
    {
        .baseHP        = 55,
        .baseAttack    = 84,
        .baseDefense   = 105,
        .baseSpeed     = 52,
        .baseSpAttack  = 114,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 170 : 178,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Saganabyss"),
#else
        .speciesName = _("GOREBYSS"),
#endif
        .cryId = CRY_GOREBYSS,
        .natDexNum = NATIONAL_DEX_GOREBYSS,
#if GERMAN
        .categoryName = _("Südsee"),
#else
        .categoryName = _("South Sea"),
#endif
        .height = 18,
        .weight = 226,
        .description = COMPOUND_STRING(
#if GERMAN
            "Saganabyss filtert die Körperflüssigkeit\n"
            "seiner Beute in seinem dünnen, schlauch-\n"
            "artigen Mund. Seine hellpinke Körperfarbe\n"
            "intensiviert sich nach dem Mahl."),
#else
            "A Gorebyss siphons the body fluids of prey\n"
            "through its thin, tubular mouth. Its light\n"
            "pink body color turns vivid when it\n"
            "finishes feeding."),
#endif
        .pokemonScale = 278,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gorebyss,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Gorebyss,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Gorebyss,
        .shinyPalette = gMonShinyPalette_Gorebyss,
        .iconSprite = gMonIcon_Gorebyss,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 5, SHADOW_SIZE_M)
        FOOTPRINT(Gorebyss)
        OVERWORLD(
            sPicTable_Gorebyss,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SLITHER,
            sAnimTable_Following,
            gOverworldPalette_Gorebyss,
            gShinyOverworldPalette_Gorebyss
        )
        .levelUpLearnset = sGorebyssLevelUpLearnset,
        .teachableLearnset = sGorebyssTeachableLearnset,
    },
#endif //P_FAMILY_CLAMPERL

#if P_FAMILY_RELICANTH
    [SPECIES_RELICANTH] =
    {
        .baseHP        = 100,
        .baseAttack    = 90,
        .baseDefense   = 130,
        .baseSpeed     = 55,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_ROCK),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 170 : 198,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_ROCK_HEAD, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Relicanth"),
#else
        .speciesName = _("RELICANTH"),
#endif
        .cryId = CRY_RELICANTH,
        .natDexNum = NATIONAL_DEX_RELICANTH,
#if GERMAN
        .categoryName = _("Bestand"),
#else
        .categoryName = _("Longevity"),
#endif
        .height = 10,
        .weight = 234,
        .description = COMPOUND_STRING(
#if GERMAN
            "Man nahm einst an, dieses Pokémon sei\n"
            "ausgestorben. Diese Art hat seine Form\n"
            "seit 100 Millionen Jahren nicht verändert.\n"
            "Es läuft mittels seiner Bauchflossen."),
#else
            "A Pokémon that was once believed to have\n"
            "been extinct. The species has not changed\n"
            "its form for 100 million years. It walks on\n"
            "the seafloor using its pectoral fins."),
#endif
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Relicanth,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Relicanth,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Relicanth,
        .shinyPalette = gMonShinyPalette_Relicanth,
        .iconSprite = gMonIcon_Relicanth,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 1 : 2,
#if P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .frontPicFemale = gMonFrontPic_RelicanthF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_RelicanthF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 40),
#endif //P_GENDER_DIFFERENCES && !P_GBA_STYLE_SPECIES_GFX
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_M)
        FOOTPRINT(Relicanth)
        OVERWORLD(
            sPicTable_Relicanth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Relicanth,
            gShinyOverworldPalette_Relicanth
        )
        OVERWORLD_FEMALE(
            sPicTable_RelicanthF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following
        )
        .levelUpLearnset = sRelicanthLevelUpLearnset,
        .teachableLearnset = sRelicanthTeachableLearnset,
        .eggMoveLearnset = sRelicanthEggMoveLearnset,
    },
#endif //P_FAMILY_RELICANTH

#if P_FAMILY_LUVDISC
    [SPECIES_LUVDISC] =
    {
        .baseHP        = 43,
        .baseAttack    = 30,
        .baseDefense   = 55,
        .baseSpeed     = 97,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 225,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 116 : 110,
        .evYield_Speed = 1,
        .itemCommon = ITEM_HEART_SCALE,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Liebiskus"),
#else
        .speciesName = _("LUVDISC"),
#endif
        .cryId = CRY_LUVDISC,
        .natDexNum = NATIONAL_DEX_LUVDISC,
        .categoryName = _("Rendezvous"),
        .height = 6,
        .weight = 87,
        .description = COMPOUND_STRING(
#if GERMAN
            "Liebiskus baut in den Armen von\n"
            "Corasonn sein Nest. Eine Tradition\n"
            "besagt, dass man ein Liebiskus als\n"
            "Zeichen seiner Liebe verschenkt."),
#else
            "Luvdisc make the branches of Corsola\n"
            "their nests. There is a custom from long\n"
            "ago of giving a Luvdisc as a gift to\n"
            "express one's feelings of love."),
#endif
        .pokemonScale = 371,
        .pokemonOffset = 2,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Luvdisc,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 24 : 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .backPic = gMonBackPic_Luvdisc,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(32, 48) : MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SPRING_REPEATED,
        .palette = gMonPalette_Luvdisc,
        .shinyPalette = gMonShinyPalette_Luvdisc,
        .iconSprite = gMonIcon_Luvdisc,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Luvdisc)
        OVERWORLD(
            sPicTable_Luvdisc,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_SPOT,
            sAnimTable_Following,
            gOverworldPalette_Luvdisc,
            gShinyOverworldPalette_Luvdisc
        )
        .levelUpLearnset = sLuvdiscLevelUpLearnset,
        .teachableLearnset = sLuvdiscTeachableLearnset,
        .eggMoveLearnset = sLuvdiscEggMoveLearnset,
    },
#endif //P_FAMILY_LUVDISC

#if P_FAMILY_BAGON
    [SPECIES_BAGON] =
    {
        .baseHP        = 45,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 89,
        .evYield_Attack = 1,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kindwurm"),
#else
        .speciesName = _("BAGON"),
#endif
        .cryId = CRY_BAGON,
        .natDexNum = NATIONAL_DEX_BAGON,
#if GERMAN
        .categoryName = _("Steinhaupt"),
#else
        .categoryName = _("Rock Head"),
#endif
        .height = 6,
        .weight = 421,
        .description = COMPOUND_STRING(
#if GERMAN
            "Obwohl es sehr klein ist, ist es sehr\n"
            "kräftig, da sein Körper ein Muskelbündel\n"
            "ist. Es verteilt Kopfstöße mit seinem\n"
            "stahlharten Schädel."),
#else
            "Although it is small, this Pokémon is very\n"
            "powerful because its body is a bundle of\n"
            "muscles. It launches head-butts with its\n"
            "ironlike skull."),
#endif
        .pokemonScale = 448,
        .pokemonOffset = 18,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Bagon,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 48) : MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE_TWICE : ANIM_H_SHAKE,
        .backPic = gMonBackPic_Bagon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(48, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 8 : 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Bagon,
        .shinyPalette = gMonShinyPalette_Bagon,
        .iconSprite = gMonIcon_Bagon,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(4, 3, SHADOW_SIZE_S)
        FOOTPRINT(Bagon)
        OVERWORLD(
            sPicTable_Bagon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bagon,
            gShinyOverworldPalette_Bagon
        )
        .levelUpLearnset = sBagonLevelUpLearnset,
        .teachableLearnset = sBagonTeachableLearnset,
        .eggMoveLearnset = sBagonEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SHELGON}),
    },

    [SPECIES_SHELGON] =
    {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 144,
        .evYield_Defense = 2,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_NONE, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Draschel"),
#else
        .speciesName = _("SHELGON"),
#endif
        .cryId = CRY_SHELGON,
        .natDexNum = NATIONAL_DEX_SHELGON,
#if GERMAN
        .categoryName = _("Durchsteher"),
#else
        .categoryName = _("Endurance"),
#endif
        .height = 11,
        .weight = 1105,
        .description = COMPOUND_STRING(
#if GERMAN
        "Draschel isst kaum, wenn es sich auf\n"
        "seine Entwicklung vorbereitet. Dadurch\n"
        "wird es noch zäher. Bei der Entwicklung\n"
        "wird die Haut sofort abgestreift."),
#else
            "It hardly eats while it awaits evolution.\n"
            "It becomes hardier by enduring hunger.\n"
            "Its shell peels off the instant it begins\n"
            "to evolve."),
#endif
        .pokemonScale = 311,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shelgon,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Shelgon,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 13 : 12,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Shelgon,
        .shinyPalette = gMonShinyPalette_Shelgon,
        .iconSprite = gMonIcon_Shelgon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Shelgon)
        OVERWORLD(
            sPicTable_Shelgon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Shelgon,
            gShinyOverworldPalette_Shelgon
        )
        .levelUpLearnset = sShelgonLevelUpLearnset,
        .teachableLearnset = sShelgonTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_SALAMENCE}),
    },

    [SPECIES_SALAMENCE] =
    {
        .baseHP        = 95,
        .baseAttack    = 135,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 110,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 218,
    #endif
        .evYield_Attack = 3,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Brutalanda"),
#else
        .speciesName = _("SALAMENCE"),
#endif
        .cryId = CRY_SALAMENCE,
        .natDexNum = NATIONAL_DEX_SALAMENCE,
#if GERMAN
        .categoryName = _("Drache"),
#else
        .categoryName = _("Dragon"),
#endif
        .height = 15,
        .weight = 1026,
        .description = COMPOUND_STRING(
#if GERMAN
            "Nach vielen Jahren mutierte plötzlich\n"
            "seine Zellstruktur und es wuchsen ihm\n"
            "Flügel. Wenn es wütend ist, kann es\n"
            "nicht mehr klar denken und flippt aus."),
#else
            "After many long years, its cellular\n"
            "structure underwent a sudden mutation to\n"
            "grow wings. When angered, it loses all\n"
            "thought and rampages out of control."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Salamence,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 70,
        .backPic = gMonBackPic_Salamence,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 56) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 4,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Salamence,
        .shinyPalette = gMonShinyPalette_Salamence,
        .iconSprite = gMonIcon_Salamence,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 8, SHADOW_SIZE_L)
        FOOTPRINT(Salamence)
        OVERWORLD(
            sPicTable_Salamence,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Salamence,
            gShinyOverworldPalette_Salamence
        )
        .levelUpLearnset = sSalamenceLevelUpLearnset,
        .teachableLearnset = sSalamenceTeachableLearnset,
        .formSpeciesIdTable = sSalamenceFormSpeciesIdTable,
        .formChangeTable = sSalamenceFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_SALAMENCE_MEGA] =
    {
        .baseHP        = 95,
        .baseAttack    = 145,
        .baseDefense   = 130,
        .baseSpeed     = 120,
        .baseSpAttack  = 120,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_Attack = 3,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_AERILATE, ABILITY_AERILATE, ABILITY_AERILATE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Brutalanda"),
#else
        .speciesName = _("SALAMENCE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SALAMENCE_MEGA,
    #else
        .cryId = CRY_SALAMENCE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SALAMENCE,
#if GERMAN
        .categoryName = _("Drache"),
#else
        .categoryName = _("Dragon"),
#endif
        .height = 18,
        .weight = 1126,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Kraft der Mega-Entwicklung\n"
        "wuchsen seine geliebten Flügel\n"
        "unnatürlich zusammen, was bei ihm Stress\n"
        "und Tobsucht auslöste."),
#else
            "Mega Evolution fuels its brutality, and it\n"
            "may even turn on the Trainer who raised it.\n"
            "It's been dubbed the blood-soaked.\n"
            "crescent."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SalamenceMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SalamenceMega,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_SalamenceMega,
        .shinyPalette = gMonShinyPalette_SalamenceMega,
        .iconSprite = gMonIcon_SalamenceMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 8, SHADOW_SIZE_L)
        FOOTPRINT(Salamence)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_SalamenceMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SalamenceMega,
            gShinyOverworldPalette_SalamenceMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sSalamenceLevelUpLearnset,
        .teachableLearnset = sSalamenceTeachableLearnset,
        .formSpeciesIdTable = sSalamenceFormSpeciesIdTable,
        .formChangeTable = sSalamenceFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_BAGON

#if P_FAMILY_BELDUM
    [SPECIES_BELDUM] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 35,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_STEEL, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 60 : 103,
        .evYield_Defense = 1,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_LIGHT_METAL },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Tanhel"),
#else
        .speciesName = _("BELDUM"),
#endif
        .cryId = CRY_BELDUM,
        .natDexNum = NATIONAL_DEX_BELDUM,
#if GERMAN
        .categoryName = _("Eisenkugel"),
#else
        .categoryName = _("Iron Ball"),
#endif
        .height = 6,
        .weight = 952,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wenn sich Tanhel versammeln, bewegen sie\n"
            "sich so synchron, dass man meinen könnte,\n"
            "es handele sich um ein Pokémon. Sie reden\n"
            "über ihre Gehirnwellen miteinander."),
#else
            "When Beldum gather in a swarm, they move\n"
            "in perfect unison as if they were but one\n"
            "Pokémon. They communicate with each other\n"
            "using brain waves."),
#endif
        .pokemonScale = 414,
        .pokemonOffset = -1,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Beldum,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(40, 40) : MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Beldum,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 9,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Beldum,
        .shinyPalette = gMonShinyPalette_Beldum,
        .iconSprite = gMonIcon_Beldum,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Beldum)
        OVERWORLD(
            sPicTable_Beldum,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Beldum,
            gShinyOverworldPalette_Beldum
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sBeldumLevelUpLearnset,
        .teachableLearnset = sBeldumTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_METANG}),
    },

    [SPECIES_METANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_STEEL, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_5) ? 147 : 153,
        .evYield_Defense = 2,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_LIGHT_METAL },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Metang"),
#else
        .speciesName = _("METANG"),
#endif
        .cryId = CRY_METANG,
        .natDexNum = NATIONAL_DEX_METANG,
#if GERMAN
        .categoryName = _("Eisenklaue"),
#else
        .categoryName = _("Iron Claw"),
#endif
        .height = 12,
        .weight = 2025,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Krallen an seinen Armen haben so\n"
            "viel Kraft, dass sie durch dicke Eisen-\n"
            "blöcke schneiden, als wären sie aus Seide.\n"
            "Es fliegt bis zu 100 km/h schnell."),
#else
            "The claws tipping its arms pack the\n"
            "destructive power to tear through thick\n"
            "iron sheets as if they were silk. It flies\n"
            "at over 60 miles per hour."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 6,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Metang,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Metang,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 32) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 16 : 13,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Metang,
        .shinyPalette = gMonShinyPalette_Metang,
        .iconSprite = gMonIcon_Metang,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Metang)
        OVERWORLD(
            sPicTable_Metang,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Metang,
            gShinyOverworldPalette_Metang
        )
        .levelUpLearnset = sMetangLevelUpLearnset,
        .teachableLearnset = sMetangTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 45, SPECIES_METAGROSS}),
    },

    [SPECIES_METAGROSS] =
    {
        .baseHP        = 80,
        .baseAttack    = 135,
        .baseDefense   = 130,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_STEEL, TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 210,
    #endif
        .evYield_Defense = 3,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_LIGHT_METAL },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Metagross"),
#else
        .speciesName = _("METAGROSS"),
#endif
        .cryId = CRY_METAGROSS,
        .natDexNum = NATIONAL_DEX_METAGROSS,
#if GERMAN
        .categoryName = _("Eisenfuß"),
#else
        .categoryName = _("Iron Leg"),
#endif
        .height = 16,
        .weight = 5500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Metagross hat vier Gehirne, die über ein\n"
            "neurales Netzwerk miteinander verbunden\n"
            "sind. Das Ergebnis der Integrierung ist,\n"
            "dass es schlauer als ein Superrechner ist."),
#else
            "Metagross has four brains that are joined\n"
            "by a complex neural network. As a result of\n"
            "integration, this Pokémon is smarter than\n"
            "a supercomputer."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 447,
        .trainerOffset = 9,
        .frontPic = gMonFrontPic_Metagross,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
            ANIMCMD_FRAME(1, 16),
            ANIMCMD_FRAME(0, 16),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Metagross,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 24) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 20 : 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Metagross,
        .shinyPalette = gMonShinyPalette_Metagross,
        .iconSprite = gMonIcon_Metagross,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, -2, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Metagross)
        OVERWORLD(
            sPicTable_Metagross,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Metagross,
            gShinyOverworldPalette_Metagross
        )
        .levelUpLearnset = sMetagrossLevelUpLearnset,
        .teachableLearnset = sMetagrossTeachableLearnset,
        .formSpeciesIdTable = sMetagrossFormSpeciesIdTable,
        .formChangeTable = sMetagrossFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_METAGROSS_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 145,
        .baseDefense   = 150,
        .baseSpeed     = 110,
        .baseSpAttack  = 105,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_STEEL, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_Defense = 3,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS, ABILITY_TOUGH_CLAWS },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Metagross"),
#else
        .speciesName = _("METAGROSS"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_METAGROSS_MEGA,
    #else
        .cryId = CRY_METAGROSS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_METAGROSS,
#if GERMAN
        .categoryName = _("Eisenfuß"),
#else
        .categoryName = _("Iron Leg"),
#endif
        .height = 25,
        .weight = 9429,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Zunahme seiner Hirnkapazität\n"
        "wurde sein Kampfstil derart schonungslos,\n"
        "dass man einfach nur wegschauen möchte."),
#else
            "When it knows it can't win, it digs the\n"
            "claws on its legs into its opponent and\n"
            "starts the countdown to a big explosion."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 4,
        .trainerScale = 447,
        .trainerOffset = 9,
        .frontPic = gMonFrontPic_MetagrossMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_MetagrossMega,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_MetagrossMega,
        .shinyPalette = gMonShinyPalette_MetagrossMega,
        .iconSprite = gMonIcon_MetagrossMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 15, SHADOW_SIZE_L)
        FOOTPRINT(Metagross)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_MetagrossMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MetagrossMega,
            gShinyOverworldPalette_MetagrossMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sMetagrossLevelUpLearnset,
        .teachableLearnset = sMetagrossTeachableLearnset,
        .formSpeciesIdTable = sMetagrossFormSpeciesIdTable,
        .formChangeTable = sMetagrossFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_BELDUM

#if P_FAMILY_REGIROCK
    [SPECIES_REGIROCK] =
    {
        .dexNotRequired = TRUE,
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 200,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 217,
    #endif
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Regirock"),
#else
        .speciesName = _("REGIROCK"),
#endif
        .cryId = CRY_REGIROCK,
        .natDexNum = NATIONAL_DEX_REGIROCK,
#if GERMAN
        .categoryName = _("Steingipfel"),
#else
        .categoryName = _("Rock Peak"),
#endif
        .height = 17,
        .weight = 2300,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es besteht nur aus Steinen und Felsen.\n"
        "Falls Teile seines Körpers im Kampf\n"
        "davonfliegen, repariert es sich selbst,\n"
        "indem es einfach neue Steine hinzufügt."),
#else
            "A Pokémon that is made entirely of rocks\n"
            "and boulders. If parts of its body chip off\n"
            "in battle, Regirock repairs itself by\n"
            "adding new rocks."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 309,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Regirock,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Regirock,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Regirock,
        .shinyPalette = gMonShinyPalette_Regirock,
        .iconSprite = gMonIcon_Regirock,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_L)
        FOOTPRINT(Regirock)
        OVERWORLD(
            sPicTable_Regirock,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regirock,
            gShinyOverworldPalette_Regirock
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRegirockLevelUpLearnset,
        .teachableLearnset = sRegirockTeachableLearnset,
    },
#endif //P_FAMILY_REGIROCK

#if P_FAMILY_REGICE
    [SPECIES_REGICE] =
    {
        .dexNotRequired = TRUE,
        .baseHP        = 80,
        .baseAttack    = 50,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 200,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 216,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Regice"),
#else
        .speciesName = _("REGICE"),
#endif
        .cryId = CRY_REGICE,
        .natDexNum = NATIONAL_DEX_REGICE,
#if GERMAN
        .categoryName = _("Eisberg"),
#else
        .categoryName = _("Iceberg"),
#endif
        .height = 18,
        .weight = 1750,
        .description = COMPOUND_STRING(
#if GERMAN
        "Regices Körper besteht aus Eis der\n"
        "Antarktis. Ausgiebige Forschungen haben\n"
        "ergeben, dass dieses Eis aus einer Eiszeit\n"
        "stammt."),
#else
            "Its entire body is made of Antarctic ice.\n"
            "After extensive studies, researchers\n"
            "believe the ice was formed during an\n"
            "ice age."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 301,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Regice,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FOUR_PETAL : ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Regice,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Regice,
        .shinyPalette = gMonShinyPalette_Regice,
        .shinyPaletteModern = gMonShinyPaletteModern_Regice,
        .iconSprite = gMonIcon_Regice,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_L)
        FOOTPRINT(Regice)
        OVERWORLD(
            sPicTable_Regice,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regice,
            gShinyOverworldPalette_Regice,
            gShinyModernOverworldPalette_Regice
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRegiceLevelUpLearnset,
        .teachableLearnset = sRegiceTeachableLearnset,
    },
#endif //P_FAMILY_REGICE

#if P_FAMILY_REGISTEEL
    [SPECIES_REGISTEEL] =
    {
        .dexNotRequired = TRUE,
        .baseHP        = 80,
        .baseAttack    = 75,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 75,
        .baseSpDefense = 150,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 215,
    #endif
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_LIGHT_METAL },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Registeel"),
#else
        .speciesName = _("REGISTEEL"),
#endif
        .cryId = CRY_REGISTEEL,
        .natDexNum = NATIONAL_DEX_REGISTEEL,
#if GERMAN
        .categoryName = _("Eisen"),
#else
        .categoryName = _("Iron"),
#endif
        .height = 19,
        .weight = 2050,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sein Körper ist härter als jede andere Art\n"
            "Metall, da das Metall aus geheimnisvollen\n"
            "Substanzen besteht. Es ist nicht nur fest,\n"
            "sondern schrumpft und dehnt sich auch."),
#else
            "Its body is harder than any other kind of\n"
            "metal. The body metal is composed of a\n"
            "mysterious substance. Not only is it hard,\n"
            "it shrinks and stretches flexibly."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 359,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Registeel,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Registeel,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Registeel,
        .shinyPalette = gMonShinyPalette_Registeel,
        .iconSprite = gMonIcon_Registeel,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_L)
        FOOTPRINT(Registeel)
        OVERWORLD(
            sPicTable_Registeel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Registeel,
            gShinyOverworldPalette_Registeel
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRegisteelLevelUpLearnset,
        .teachableLearnset = sRegisteelTeachableLearnset,
    },
#endif //P_FAMILY_REGISTEEL

#if P_FAMILY_LATIAS
    [SPECIES_LATIAS] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 110,
        .baseSpAttack  = 110,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 211,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Latias"),
#else
        .speciesName = _("LATIAS"),
#endif
        .cryId = CRY_LATIAS,
        .natDexNum = NATIONAL_DEX_LATIAS,
#if GERMAN
        .categoryName = _("Äon"),
#else
        .categoryName = _("Eon"),
#endif
        .height = 14,
        .weight = 400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sie bilden nur kleine Gruppen und nehmen\n"
            "nur selten Kontakt zu den Menschen oder\n"
            "anderen Pokémon auf. Spüren sie Feinde,\n"
            "verschwinden sie sofort."),
#else
            "They make a small herd of only several\n"
            "members. They rarely make contact with\n"
            "people or other Pokémon. They disappear\n"
            "if they sense enemies."),
#endif
        .pokemonScale = 304,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Latias,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE_FAST_SHORT : ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 12,
        .backPic = gMonBackPic_Latias,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 0,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Latias,
        .shinyPalette = gMonShinyPalette_Latias,
        .iconSprite = gMonIcon_Latias,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 15, SHADOW_SIZE_M)
        FOOTPRINT(Latias)
        OVERWORLD(
            sPicTable_Latias,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Latias,
            gShinyOverworldPalette_Latias
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLatiasLevelUpLearnset,
        .teachableLearnset = sLatiasTeachableLearnset,
        .formSpeciesIdTable = sLatiasFormSpeciesIdTable,
        .formChangeTable = sLatiasFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_LATIAS_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 110,
        .baseSpAttack  = 140,
        .baseSpDefense = 150,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_LEVITATE, ABILITY_LEVITATE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Latias"),
#else
        .speciesName = _("LATIAS"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_LATIAS_MEGA,
    #else
        .cryId = CRY_LATIAS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_LATIAS,
#if GERMAN
        .categoryName = _("Äon"),
#else
        .categoryName = _("Eon"),
#endif
        .height = 18,
        .weight = 520,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seine Flugfertigkeiten\n"
        "und seine Angriffskraft wurden\n"
        "erhöht. Es verstreut durchsichtige\n"
        "Daunen, um Gegner zu verwirren."),
#else
            "Its body is smaller than Mega Latios's\n"
            "body. It is more agile and can make very\n"
            "sharp turns. When it Mega Evolves, its\n"
            "defensive strength grows substantially."),
#endif
        .pokemonScale = 304,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LatiasMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_LatiasMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_LatiasMega,
        .shinyPalette = gMonShinyPalette_LatiasMega,
        .iconSprite = gMonIcon_LatiasMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 19, SHADOW_SIZE_L)
        FOOTPRINT(Latias)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_LatiasMega,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_LatiasMega,
            gShinyOverworldPalette_LatiasMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isSubLegendary = TRUE,
        .isMegaEvolution = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLatiasLevelUpLearnset,
        .teachableLearnset = sLatiasTeachableLearnset,
        .formSpeciesIdTable = sLatiasFormSpeciesIdTable,
        .formChangeTable = sLatiasFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_LATIAS

#if P_FAMILY_LATIOS
    [SPECIES_LATIOS] =
    {
        .baseHP        = 80,
        .baseAttack    = 90,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 211,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Latios"),
#else
        .speciesName = _("LATIOS"),
#endif
        .cryId = CRY_LATIOS,
        .natDexNum = NATIONAL_DEX_LATIOS,
#if GERMAN
        .categoryName = _("Äon"),
#else
        .categoryName = _("Eon"),
#endif
        .height = 20,
        .weight = 600,
        .description = COMPOUND_STRING(
#if GERMAN
            "Auch wenn es sich versteckt, kann es\n"
            "mittels Telepathie die Aufenthaltsorte\n"
            "der anderen und ihre Emotionen wahr-\n"
            "nehmen. Es versteht sogar Menschen."),
#else
            "Even in hiding, it can detect the locations\n"
            "of others and sense their emotions since\n"
            "it has telepathy. Its intelligence allows\n"
            "it to understand human languages."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 294,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Latios,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE : ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Latios,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 0,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Latios,
        .shinyPalette = gMonShinyPalette_Latios,
        .iconSprite = gMonIcon_Latios,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 17, SHADOW_SIZE_M)
        FOOTPRINT(Latios)
        OVERWORLD(
            sPicTable_Latios,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Latios,
            gShinyOverworldPalette_Latios
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLatiosLevelUpLearnset,
        .teachableLearnset = sLatiosTeachableLearnset,
        .formSpeciesIdTable = sLatiosFormSpeciesIdTable,
        .formChangeTable = sLatiosFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_LATIOS_MEGA] =
    {
        .baseHP        = 80,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 110,
        .baseSpAttack  = 160,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_LEVITATE, ABILITY_LEVITATE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Latios"),
#else
        .speciesName = _("LATIOS"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_LATIOS_MEGA,
    #else
        .cryId = CRY_LATIOS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_LATIOS,
#if GERMAN
        .categoryName = _("Äon"),
#else
        .categoryName = _("Eon"),
#endif
        .height = 23,
        .weight = 700,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es erreicht Fluggeschwindigkeiten,\n"
        "die Mach 4 überschreiten.\n"
        "Seine Fertigkeiten im Luftkampf gehören\n"
        "zur Spitzenklasse unter den Pokémon."),
#else
            "It's larger than Mega Latias, and can\n"
            "achieve higher speeds in flight.\n"
            "This Pokémon can use its speed in battle\n"
            "to unleash a flurry of attacks."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 294,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_LatiosMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_LatiosMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_LatiosMega,
        .shinyPalette = gMonShinyPalette_LatiosMega,
        .iconSprite = gMonIcon_LatiosMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 19, SHADOW_SIZE_L)
        FOOTPRINT(Latios)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_LatiosMega,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_LatiosMega,
            gShinyOverworldPalette_LatiosMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isSubLegendary = TRUE,
        .isMegaEvolution = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLatiosLevelUpLearnset,
        .teachableLearnset = sLatiosTeachableLearnset,
        .formSpeciesIdTable = sLatiosFormSpeciesIdTable,
        .formChangeTable = sLatiosFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_LATIOS

#if P_FAMILY_KYOGRE
    [SPECIES_KYOGRE] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 140,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 335,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 302,
    #else
        .expYield = 218,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DRIZZLE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kyogre"),
#else
        .speciesName = _("KYOGRE"),
#endif
        .cryId = CRY_KYOGRE,
        .natDexNum = NATIONAL_DEX_KYOGRE,
#if GERMAN
        .categoryName = _("Seegründler"),
#else
        .categoryName = _("Sea Basin"),
#endif
        .height = 45,
        .weight = 3520,
        .description = COMPOUND_STRING(
#if GERMAN
            "Laut Mythologie soll Kyogre die See\n"
            "erschaffen haben. Nach jahrelanger\n"
            "Fehde mit Groudon schläft es\n"
            "am Grund der See."),
#else
            "Kyogre has appeared in mythology as the\n"
            "creator of the sea. After long years of\n"
            "feuding with Groudon, it took to sleep at\n"
            "the bottom of the sea."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_Kyogre,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        .frontAnimDelay = 60,
        .backPic = gMonBackPic_Kyogre,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 19 : 18,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Kyogre,
        .shinyPalette = gMonShinyPalette_Kyogre,
        .iconSprite = gMonIcon_Kyogre,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kyogre)
        OVERWORLD(
            sPicTable_Kyogre,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Kyogre,
            gShinyOverworldPalette_Kyogre
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKyogreLevelUpLearnset,
        .teachableLearnset = sKyogreTeachableLearnset,
        .formSpeciesIdTable = sKyogreFormSpeciesIdTable,
        .formChangeTable = sKyogreFormChangeTable,
    },
#if P_PRIMAL_REVERSIONS
    [SPECIES_KYOGRE_PRIMAL] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 180,
        .baseSpDefense = 160,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 385 : 347,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRIMORDIAL_SEA, ABILITY_PRIMORDIAL_SEA },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kyogre"),
#else
        .speciesName = _("KYOGRE"),
#endif
        .cryId = CRY_KYOGRE_PRIMAL,
        .natDexNum = NATIONAL_DEX_KYOGRE,
#if GERMAN
        .categoryName = _("Seegründler"),
#else
        .categoryName = _("Sea Basin"),
#endif
        .height = 98,
        .weight = 4300,
        .description = COMPOUND_STRING(
#if GERMAN
            "Durch die urzeitliche Energie der Blauen\n"
            "Kugel nahm es seine ursprüngliche Form\n"
            "an. Sein Körper ähnelt Meerwasser."),
#else
            "When Kyogre roared, water poured forth\n"
            "and the seas spread outward.\n"
            "Dark clouds enshrouded the world,\n"
            "and the deluge fell upon all…"),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 14,
        .frontPic = gMonFrontPic_KyogrePrimal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_KyogrePrimal,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_KyogrePrimal,
        .shinyPalette = gMonShinyPalette_KyogrePrimal,
        .iconSprite = gMonIcon_KyogrePrimal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kyogre)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_KyogrePrimal,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_KyogrePrimal,
            gShinyOverworldPalette_KyogrePrimal
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isRestrictedLegendary = TRUE,
        .isPrimalReversion = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKyogreLevelUpLearnset,
        .teachableLearnset = sKyogreTeachableLearnset,
        .formSpeciesIdTable = sKyogreFormSpeciesIdTable,
        .formChangeTable = sKyogreFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_PRIMAL_REVERSIONS
#endif //P_FAMILY_KYOGRE

#if P_FAMILY_GROUDON
    [SPECIES_GROUDON] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 140,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 335,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 302,
    #else
        .expYield = 218,
    #endif
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DROUGHT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Groudon"),
#else
        .speciesName = _("GROUDON"),
#endif
        .cryId = CRY_GROUDON,
        .natDexNum = NATIONAL_DEX_GROUDON,
#if GERMAN
        .categoryName = _("Kontinent"),
#else
        .categoryName = _("Continent"),
#endif
        .height = 35,
        .weight = 9500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Laut Mythologie soll Groudon das Land\n"
            "erschaffen haben. Es schläft in Magma\n"
            "und soll Vulkanausbrüche hervorrufen,\n"
            "wenn es geweckt wird."),
#else
            "Groudon has appeared in mythology as the\n"
            "creator of the land. It sleeps in magma\n"
            "underground and is said to make volcanoes\n"
            "erupt on awakening."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 14,
        .frontPic = gMonFrontPic_Groudon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Groudon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Groudon,
        .shinyPalette = gMonShinyPalette_Groudon,
        .iconSprite = gMonIcon_Groudon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Groudon)
        OVERWORLD(
            sPicTable_Groudon,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Groudon,
            gShinyOverworldPalette_Groudon
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sGroudonLevelUpLearnset,
        .teachableLearnset = sGroudonTeachableLearnset,
        .formSpeciesIdTable = sGroudonFormSpeciesIdTable,
        .formChangeTable = sGroudonFormChangeTable,
    },

#if P_PRIMAL_REVERSIONS
    [SPECIES_GROUDON_PRIMAL] =
    {
        .baseHP        = 100,
        .baseAttack    = 180,
        .baseDefense   = 160,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FIRE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 385 : 347,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DESOLATE_LAND, ABILITY_DESOLATE_LAND },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Groudon"),
#else
        .speciesName = _("GROUDON"),
#endif
        .cryId = CRY_GROUDON_PRIMAL,
        .natDexNum = NATIONAL_DEX_GROUDON,
#if GERMAN
        .categoryName = _("Kontinent"),
#else
        .categoryName = _("Continent"),
#endif
        .height = 50,
        .weight = 9997,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dies ist seine ursprüngliche Form, die es\n"
        "durch die Rote Kugel zurückerlangt hat.\n"
        "Energie quillt in Form von Magma aus seinem\n"
        "Körper."),
#else
            "When Groudon howled, the earth swelled and\n"
            "the land grew wide. The sun blazed atop\n"
            "and all the world around the creature\n"
            "was enveloped in incandescent heat."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 515,
        .trainerOffset = 14,
        .frontPic = gMonFrontPic_GroudonPrimal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GroudonPrimal,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_GroudonPrimal,
        .shinyPalette = gMonShinyPalette_GroudonPrimal,
        .iconSprite = gMonIcon_GroudonPrimal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Groudon)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_GroudonPrimal,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GroudonPrimal,
            gShinyOverworldPalette_GroudonPrimal
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isRestrictedLegendary = TRUE,
        .isPrimalReversion = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sGroudonLevelUpLearnset,
        .teachableLearnset = sGroudonTeachableLearnset,
        .formSpeciesIdTable = sGroudonFormSpeciesIdTable,
        .formChangeTable = sGroudonFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_PRIMAL_REVERSIONS
#endif //P_FAMILY_GROUDON

#if P_FAMILY_RAYQUAZA
    [SPECIES_RAYQUAZA] =
    {
        .baseHP        = 105,
        .baseAttack    = 150,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 150,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_AIR_LOCK, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Rayquaza"),
#else
        .speciesName = _("RAYQUAZA"),
#endif
        .cryId = CRY_RAYQUAZA,
        .natDexNum = NATIONAL_DEX_RAYQUAZA,
#if GERMAN
        .categoryName = _("Himmelhoch"),
#else
        .categoryName = _("Sky High"),
#endif
        .height = 70,
        .weight = 2065,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dieses Pokémon fliegt ständig in der\n"
            "Ozonschicht. Man sagt, es würde auf die\n"
            "Erde zurückkehren, wenn Kyogre und\n"
            "Groudon zu kämpfen beginnen."),
#else
            "A Pokémon that flies endlessly in the\n"
            "ozone layer. It is said it would descend\n"
            "to the ground if Kyogre and Groudon\n"
            "were to fight."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 448,
        .trainerOffset = 12,
        .frontPic = gMonFrontPic_Rayquaza,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 60,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Rayquaza,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Rayquaza,
        .shinyPalette = gMonShinyPalette_Rayquaza,
        .iconSprite = gMonIcon_Rayquaza,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_L)
        FOOTPRINT(Rayquaza)
        OVERWORLD(
            sPicTable_Rayquaza,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Rayquaza,
            gShinyOverworldPalette_Rayquaza
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRayquazaLevelUpLearnset,
        .teachableLearnset = sRayquazaTeachableLearnset,
        .formSpeciesIdTable = sRayquazaFormSpeciesIdTable,
        .formChangeTable = sRayquazaFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_RAYQUAZA_MEGA] =
    {
        .baseHP        = 105,
        .baseAttack    = 180,
        .baseDefense   = 100,
        .baseSpeed     = 115,
        .baseSpAttack  = 180,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 390 : 351,
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DELTA_STREAM, ABILITY_DELTA_STREAM, ABILITY_DELTA_STREAM },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Rayquaza"),
#else
        .speciesName = _("RAYQUAZA"),
#endif
        .cryId = CRY_RAYQUAZA_MEGA,
        .natDexNum = NATIONAL_DEX_RAYQUAZA,
#if GERMAN
        .categoryName = _("Himmelhoch"),
#else
        .categoryName = _("Sky High"),
#endif
        .height = 108,
        .weight = 3920,
        .description = COMPOUND_STRING(
#if GERMAN
        "Eine leuchtende Sternschnuppe am\n"
        "Nachthimmel könnte in Wirklichkeit\n"
        "Mega-Rayquaza sein, das anmutig einem\n"
        "Meteor nachjagt."),
#else
            "Particles stream from the filaments that\n"
            "extend from its jaw. They can control the\n"
            "density and humidity of the air, allowing\n"
            "Rayquaza to manipulate the weather."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 448,
        .trainerOffset = 12,
        .frontPic = gMonFrontPic_RayquazaMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_RayquazaMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_RayquazaMega,
        .shinyPalette = gMonShinyPalette_RayquazaMega,
        .iconSprite = gMonIcon_RayquazaMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_L)
        FOOTPRINT(Rayquaza)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_RayquazaMega,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_RayquazaMega,
            gShinyOverworldPalette_RayquazaMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isRestrictedLegendary = TRUE,
        .isMegaEvolution = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRayquazaLevelUpLearnset,
        .teachableLearnset = sRayquazaTeachableLearnset,
        .formSpeciesIdTable = sRayquazaFormSpeciesIdTable,
        .formChangeTable = sRayquazaFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_RAYQUAZA

#if P_FAMILY_JIRACHI
    [SPECIES_JIRACHI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_STEEL, TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 215,
    #endif
        .evYield_HP = 3,
        .itemCommon = ITEM_STAR_PIECE,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Jirachi"),
#else
        .speciesName = _("JIRACHI"),
#endif
        .cryId = CRY_JIRACHI,
        .natDexNum = NATIONAL_DEX_JIRACHI,
#if GERMAN
        .categoryName = _("Wünscher"),
#else
        .categoryName = _("Wish"),
#endif
        .height = 3,
        .weight = 11,
        .description = COMPOUND_STRING(
#if GERMAN
            "Jirachi soll Wünsche wahr werden lassen.\n"
            "Während es schläft, beschützt eine\n"
            "kristalline Hülle seinen Körper vor\n"
            "Angriffen."),
#else
            "Jirachi is said to make wishes come true.\n"
            "While it sleeps, a tough crystalline shell\n"
            "envelops the body to protect it from\n"
            "enemies."),
#endif
        .pokemonScale = 608,
        .pokemonOffset = -8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Jirachi,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 48) : MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONVEX : ANIM_RISING_WOBBLE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 12 : 14,
        .backPic = gMonBackPic_Jirachi,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 5 : 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Jirachi,
        .shinyPalette = gMonShinyPalette_Jirachi,
        .iconSprite = gMonIcon_Jirachi,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_S)
        FOOTPRINT(Jirachi)
        OVERWORLD(
            sPicTable_Jirachi,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Jirachi,
            gShinyOverworldPalette_Jirachi
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sJirachiLevelUpLearnset,
        .teachableLearnset = sJirachiTeachableLearnset,
    },
#endif //P_FAMILY_JIRACHI

#if P_FAMILY_DEOXYS
#if P_UPDATED_EXP_YIELDS >= GEN_8
    #define DEOXYS_EXP_YIELD 300
#elif P_UPDATED_EXP_YIELDS >= GEN_5
    #define DEOXYS_EXP_YIELD 270
#else
    #define DEOXYS_EXP_YIELD 215
#endif

    [SPECIES_DEOXYS_NORMAL] =
    {
        .baseHP        = 50,
        .baseAttack    = 150,
        .baseDefense   = 50,
        .baseSpeed     = 150,
        .baseSpAttack  = 150,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = DEOXYS_EXP_YIELD,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Deoxys"),
#else
        .speciesName = _("DEOXYS"),
#endif
        .cryId = CRY_DEOXYS,
        .natDexNum = NATIONAL_DEX_DEOXYS,
#if GERMAN
        .categoryName = _("DNS"),
#else
        .categoryName = _("DNA"),
#endif
        .height = 17,
        .weight = 608,
        .description = COMPOUND_STRING(
#if GERMAN
            "Deoxys ist eine mutierte Form eines außer-\n"
            "irdischen Virus, das einem Laserstrahl\n"
            "ausgesetzt war. Sein Körper ist auf\n"
            "Agilität und Geschwindigkeit konfiguriert."),
#else
            "Deoxys emerged from a virus that came\n"
            "from space. It is highly intelligent and\n"
            "can shoot lasers from the crystalline\n"
            "organ on its chest."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_DeoxysNormal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 16),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 26),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 16),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_PIVOT : ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backPic = gMonBackPic_DeoxysNormal,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_DeoxysNormal,
        .shinyPalette = gMonShinyPalette_DeoxysNormal,
        .iconSprite = gMonIcon_DeoxysNormal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_M)
        FOOTPRINT(Deoxys)
        OVERWORLD(
            sPicTable_DeoxysNormal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_DeoxysNormal,
            gShinyOverworldPalette_DeoxysNormal
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sDeoxysNormalLevelUpLearnset,
        .teachableLearnset = sDeoxysNormalTeachableLearnset,
        .formSpeciesIdTable = sDeoxysFormSpeciesIdTable,
        .formChangeTable = sDeoxysNormalFormChangeTable,
    },

    [SPECIES_DEOXYS_ATTACK] =
    {
        .baseHP        = 50,
        .baseAttack    = 180,
        .baseDefense   = 20,
        .baseSpeed     = 150,
        .baseSpAttack  = 180,
        .baseSpDefense = 20,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = DEOXYS_EXP_YIELD,
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Deoxys"),
#else
        .speciesName = _("DEOXYS"),
#endif
        .cryId = CRY_DEOXYS,
        .natDexNum = NATIONAL_DEX_DEOXYS,
#if GERMAN
        .categoryName = _("DNS"),
#else
        .categoryName = _("DNA"),
#endif
        .height = 17,
        .weight = 608,
        .description = COMPOUND_STRING(
#if GERMAN
            "Deoxys ist eine mutierte Form eines außer-\n"
            "irdischen Virus, das einem Laserstrahl\n"
            "ausgesetzt war. Sein Körper ist auf \n"
            "Agilität und Geschwindigkeit konfiguriert."),
#else
            "This Deoxys has transformed into its\n"
            "aggressive guise. It can fool enemies\n"
            "by altering its appearance."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_DeoxysAttack,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 16),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 26),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 16),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_PIVOT : ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backPic = gMonBackPic_DeoxysAttack,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 1,
        .backAnimId = P_GBA_STYLE_SPECIES_GFX ? BACK_ANIM_SHRINK_GROW_VIBRATE : BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_DeoxysAttack,
        .shinyPalette = gMonShinyPalette_DeoxysAttack,
        .iconSprite = gMonIcon_DeoxysAttack,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_M)
        OVERWORLD(
            sPicTable_DeoxysAttack,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DeoxysAttack,
            gShinyOverworldPalette_DeoxysAttack
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sDeoxysAttackLevelUpLearnset,
        .teachableLearnset = sDeoxysAttackTeachableLearnset,
        .formSpeciesIdTable = sDeoxysFormSpeciesIdTable,
        .formChangeTable = sDeoxysAttackFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_DEOXYS_DEFENSE] =
    {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 160,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 160,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = DEOXYS_EXP_YIELD,
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Deoxys"),
#else
        .speciesName = _("DEOXYS"),
#endif
        .cryId = CRY_DEOXYS,
        .natDexNum = NATIONAL_DEX_DEOXYS,
#if GERMAN
        .categoryName = _("DNS"),
#else
        .categoryName = _("DNA"),
#endif
        .height = 17,
        .weight = 608,
        .description = COMPOUND_STRING(
#if GERMAN
            "Deoxys ist eine mutierte Form eines außer-\n"
            "irdischen Virus, das einem Laserstrahl\n"
            "ausgesetzt war. Sein Körper ist auf \n"
            "Agilität und Geschwindigkeit konfiguriert."),
#else
            "When it changes form, an aurora\n"
            "appears. It absorbs attacks by\n"
            "altering its cellular structure."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_DeoxysDefense,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 16),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 26),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 16),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_PIVOT : ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backPic = gMonBackPic_DeoxysDefense,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 8,
        .backAnimId = P_GBA_STYLE_SPECIES_GFX ? BACK_ANIM_SHRINK_GROW_VIBRATE : BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_DeoxysDefense,
        .shinyPalette = gMonShinyPalette_DeoxysDefense,
        .iconSprite = gMonIcon_DeoxysDefense,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_M)
        FOOTPRINT(Deoxys)
        OVERWORLD(
            sPicTable_DeoxysDefense,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DeoxysDefense,
            gShinyOverworldPalette_DeoxysDefense
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sDeoxysDefenseLevelUpLearnset,
        .teachableLearnset = sDeoxysDefenseTeachableLearnset,
        .formSpeciesIdTable = sDeoxysFormSpeciesIdTable,
        .formChangeTable = sDeoxysDefenseFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_DEOXYS_SPEED] =
    {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 90,
        .baseSpeed     = 180,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = DEOXYS_EXP_YIELD,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Deoxys"),
#else
        .speciesName = _("DEOXYS"),
#endif
        .cryId = CRY_DEOXYS,
        .natDexNum = NATIONAL_DEX_DEOXYS,
#if GERMAN
        .categoryName = _("DNS"),
#else
        .categoryName = _("DNA"),
#endif
        .height = 17,
        .weight = 608,
        .description = COMPOUND_STRING(
#if GERMAN
            "Deoxys ist eine mutierte Form eines außer-\n"
            "irdischen Virus, das einem Laserstrahl\n"
            "ausgesetzt war. Sein Körper ist auf \n"
            "Agilität und Geschwindigkeit konfiguriert."),
#else
            "A Pokémon that mutated from an\n"
            "extraterrestrial virus exposed to a laser\n"
            "beam. Its body is configured for superior \n"
            "agility and speed."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_DeoxysSpeed,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        #if !P_GBA_STYLE_SPECIES_GFX
            .frontAnimFrames = ANIM_FRAMES(
                ANIMCMD_FRAME(0, 16),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 26),
                ANIMCMD_FRAME(1, 16),
                ANIMCMD_FRAME(0, 16),
            ),
        #else
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        #endif
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_H_PIVOT : ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 8 : 0,
        .backPic = gMonBackPic_DeoxysSpeed,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 9 : 0,
        .backAnimId = P_GBA_STYLE_SPECIES_GFX ? BACK_ANIM_SHRINK_GROW_VIBRATE : BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_DeoxysSpeed,
        .shinyPalette = gMonShinyPalette_DeoxysSpeed,
        .iconSprite = gMonIcon_DeoxysSpeed,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 13, SHADOW_SIZE_M)
        FOOTPRINT(Deoxys)
        OVERWORLD(
            sPicTable_DeoxysSpeed,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_DeoxysSpeed,
            gShinyOverworldPalette_DeoxysSpeed
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sDeoxysSpeedLevelUpLearnset,
        .teachableLearnset = sDeoxysSpeedTeachableLearnset,
        .formSpeciesIdTable = sDeoxysFormSpeciesIdTable,
        .formChangeTable = sDeoxysSpeedFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_DEOXYS

#ifdef __INTELLISENSE__
};
#endif
