#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen8[] =
{
#endif

#if P_FAMILY_GROOKEY
    [SPECIES_GROOKEY] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Chimpep"),
#else
        .speciesName = _("GROOKEY"),
#endif
        .cryId = CRY_GROOKEY,
        .natDexNum = NATIONAL_DEX_GROOKEY,
#if GERMAN
        .categoryName = _("Schimpanse"),
#else
        .categoryName = _("Chimp"),
#endif
        .height = 3,
        .weight = 50,
        .description = COMPOUND_STRING(
#if GERMAN
        "Der Rhythmus, den es mit seinem\n"
        "besonderen Schlägel erzeugt, verbreitet\n"
        "Schallwellen, die Pflanzen neue Vitalität\n"
        "verleihen können."),
#else
            "When it uses its special stick to strike up\n"
            "a beat, the sound waves produced carry\n"
            "revitalizing energy to the plants and\n"
            "flowers in the area."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grookey,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Grookey,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Grookey,
        .shinyPalette = gMonShinyPalette_Grookey,
        .iconSprite = gMonIcon_Grookey,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Grookey)
        OVERWORLD(
            sPicTable_Grookey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Grookey,
            gShinyOverworldPalette_Grookey
        )
        .levelUpLearnset = sGrookeyLevelUpLearnset,
        .teachableLearnset = sGrookeyTeachableLearnset,
        .eggMoveLearnset = sGrookeyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_THWACKEY}),
    },

    [SPECIES_THWACKEY] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Chimstix"),
#else
        .speciesName = _("THWACKEY"),
#endif
        .cryId = CRY_THWACKEY,
        .natDexNum = NATIONAL_DEX_THWACKEY,
        .categoryName = _("Beat"),
        .height = 7,
        .weight = 140,
        .description = COMPOUND_STRING(
#if GERMAN
        "Je wilder der Beat, den ein Chimstix mit\n"
        "seinen zwei Schlägeln erzeugt, desto mehr\n"
        "wird es von seinen Artgenossen\n"
        "respektiert."),
#else
            "The faster a Thwackey can beat out\n"
            "a rhythm with its two sticks, the more\n"
            "respect it wins from its peers."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Thwackey,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Thwackey,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Thwackey,
        .shinyPalette = gMonShinyPalette_Thwackey,
        .iconSprite = gMonIcon_Thwackey,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(5, 6, SHADOW_SIZE_M)
        FOOTPRINT(Thwackey)
        OVERWORLD(
            sPicTable_Thwackey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Thwackey,
            gShinyOverworldPalette_Thwackey
        )
        .levelUpLearnset = sThwackeyLevelUpLearnset,
        .teachableLearnset = sThwackeyTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_RILLABOOM}),
    },

    [SPECIES_RILLABOOM] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 85,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Gortrom"),
#else
        .speciesName = _("RILLABOOM"),
#endif
        .cryId = CRY_RILLABOOM,
        .natDexNum = NATIONAL_DEX_RILLABOOM,
        .categoryName = _("Drummer"),
        .height = 21,
        .weight = 900,
        .description = COMPOUND_STRING(
#if GERMAN
        "Gortrom kontrolliert die Macht seines\n"
        "speziellen Baumstumpfes durch Trommeln.\n"
        "Im Kampf manipuliert es damit Wurzeln."),
#else
            "By drumming, it taps into the power of\n"
            "its special tree stump. The roots of the\n"
            "stump follow its direction in battle."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Rillaboom,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Rillaboom,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Rillaboom,
        .shinyPalette = gMonShinyPalette_Rillaboom,
        .iconSprite = gMonIcon_Rillaboom,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_L)
        FOOTPRINT(Rillaboom)
        OVERWORLD(
            sPicTable_Rillaboom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rillaboom,
            gShinyOverworldPalette_Rillaboom
        )
        .levelUpLearnset = sRillaboomLevelUpLearnset,
        .teachableLearnset = sRillaboomTeachableLearnset,
        .formSpeciesIdTable = sRillaboomFormSpeciesIdTable,
        .formChangeTable = sRillaboomFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_RILLABOOM_GMAX] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 85,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Gortrom"),
#else
        .speciesName = _("RILLABOOM"),
#endif
        .cryId = CRY_RILLABOOM,
        .natDexNum = NATIONAL_DEX_RILLABOOM,
        .categoryName = _("Drummer"),
        .height = 280,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Durch die Gigadynamax-Energie ist sein\n"
            "Baumstumpf zu einem waldähnlichen\n"
            "Schlagzeug angewachsen."),
#else
            "Rillaboom has become one with its\n"
            "forest of drums and continues to lay\n"
            "down beats that shake all of Galar."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_RillaboomGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_RillaboomGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_RillaboomGmax,
        .shinyPalette = gMonShinyPalette_RillaboomGmax,
        .iconSprite = gMonIcon_RillaboomGmax,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Rillaboom)
        .isGigantamax = TRUE,
        .levelUpLearnset = sRillaboomLevelUpLearnset,
        .teachableLearnset = sRillaboomTeachableLearnset,
        .formSpeciesIdTable = sRillaboomFormSpeciesIdTable,
        .formChangeTable = sRillaboomFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_GROOKEY

#if P_FAMILY_SCORBUNNY
    [SPECIES_SCORBUNNY] =
    {
        .baseHP        = 50,
        .baseAttack    = 71,
        .baseDefense   = 40,
        .baseSpeed     = 69,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Hopplo"),
#else
        .speciesName = _("SCORBUNNY"),
#endif
        .cryId = CRY_SCORBUNNY,
        .natDexNum = NATIONAL_DEX_SCORBUNNY,
#if GERMAN
        .categoryName = _("Hase"),
#else
        .categoryName = _("Rabbit"),
#endif
        .height = 3,
        .weight = 45,
        .description = COMPOUND_STRING(
#if GERMAN
        "Erhöht es durch Rennen seine\n"
        "Körpertemperatur, strömt Feuer-Energie\n"
        "durch seinen Körper. Dann kann es seine\n"
        "wahre Kraft entfesseln."),
#else
            "A warm-up of running around gets fire\n"
            "energy coursing through this Pokémon's\n"
            "body. Once that happens, it's ready to\n"
            "fight at full power."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Scorbunny,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Scorbunny,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Scorbunny,
        .shinyPalette = gMonShinyPalette_Scorbunny,
        .iconSprite = gMonIcon_Scorbunny,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, 6, SHADOW_SIZE_S)
        FOOTPRINT(Scorbunny)
        OVERWORLD(
            sPicTable_Scorbunny,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Scorbunny,
            gShinyOverworldPalette_Scorbunny
        )
        .levelUpLearnset = sScorbunnyLevelUpLearnset,
        .teachableLearnset = sScorbunnyTeachableLearnset,
        .eggMoveLearnset = sScorbunnyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_RABOOT}),
    },

    [SPECIES_RABOOT] =
    {
        .baseHP        = 65,
        .baseAttack    = 86,
        .baseDefense   = 60,
        .baseSpeed     = 94,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 147,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Kickerlo"),
#else
        .speciesName = _("RABOOT"),
#endif
        .cryId = CRY_RABOOT,
        .natDexNum = NATIONAL_DEX_RABOOT,
#if GERMAN
        .categoryName = _("Hase"),
#else
        .categoryName = _("Rabbit"),
#endif
        .height = 6,
        .weight = 90,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kickerlos flauschiges Fell schützt es vor\n"
            "Kälte und ermöglicht es ihm, noch heißere\n"
            "Feuer-Attacken auszuteilen."),
#else
            "Its thick and fluffy fur protects it\n"
            "from the cold and enables it to use\n"
            "hotter fire moves."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Raboot,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Raboot,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Raboot,
        .shinyPalette = gMonShinyPalette_Raboot,
        .iconSprite = gMonIcon_Raboot,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-4, 5, SHADOW_SIZE_S)
        FOOTPRINT(Raboot)
        OVERWORLD(
            sPicTable_Raboot,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Raboot,
            gShinyOverworldPalette_Raboot
        )
        .levelUpLearnset = sRabootLevelUpLearnset,
        .teachableLearnset = sRabootTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_CINDERACE}),
    },

    [SPECIES_CINDERACE] =
    {
        .baseHP        = 80,
        .baseAttack    = 116,
        .baseDefense   = 75,
        .baseSpeed     = 119,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Liberlo"),
#else
        .speciesName = _("CINDERACE"),
#endif
        .cryId = CRY_CINDERACE,
        .natDexNum = NATIONAL_DEX_CINDERACE,
#if GERMAN
        .categoryName = _("Torschütze"),
#else
        .categoryName = _("Striker"),
#endif
        .height = 14,
        .weight = 330,
        .description = COMPOUND_STRING(
#if GERMAN
        "Liberlo jongliert kleine Steine mit den\n"
        "Füßen und erschafft daraus einen\n"
        "Flammenfußball. Seine Gegner verbrennt es\n"
        "mit scharfen Schüssen."),
#else
            "It juggles a pebble with its feet,\n"
            "turning it into a burning soccer ball.\n"
            "Its shots strike opponents hard and\n"
            "leave them scorched."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cinderace,
        .frontPicSize = MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cinderace,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cinderace,
        .shinyPalette = gMonShinyPalette_Cinderace,
        .iconSprite = gMonIcon_Cinderace,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cinderace)
        OVERWORLD(
            sPicTable_Cinderace,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cinderace,
            gShinyOverworldPalette_Cinderace
        )
        .levelUpLearnset = sCinderaceLevelUpLearnset,
        .teachableLearnset = sCinderaceTeachableLearnset,
        .formSpeciesIdTable = sCinderaceFormSpeciesIdTable,
        .formChangeTable = sCinderaceFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_CINDERACE_GMAX] =
    {
        .baseHP        = 80,
        .baseAttack    = 116,
        .baseDefense   = 75,
        .baseSpeed     = 119,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Liberlo"),
#else
        .speciesName = _("CINDERACE"),
#endif
        .cryId = CRY_CINDERACE,
        .natDexNum = NATIONAL_DEX_CINDERACE,
#if GERMAN
        .categoryName = _("Torschütze"),
#else
        .categoryName = _("Striker"),
#endif
        .height = 270,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Der gigantische Feuerball, der von Liberlos\n"
        "loderndem Kampfgeist erfüllt ist, verfehlt\n"
        "nie sein Ziel und heizt diesem ordentlich\n"
        "ein."),
#else
            "Infused with Cinderace's fighting\n"
            "spirit, the gigantic Pyro Ball never\n"
            "misses its targets and completely\n"
            "roasts opponents."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CinderaceGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CinderaceGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CinderaceGmax,
        .shinyPalette = gMonShinyPalette_CinderaceGmax,
        .iconSprite = gMonIcon_CinderaceGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Cinderace)
        .isGigantamax = TRUE,
        .levelUpLearnset = sCinderaceLevelUpLearnset,
        .teachableLearnset = sCinderaceTeachableLearnset,
        .formSpeciesIdTable = sCinderaceFormSpeciesIdTable,
        .formChangeTable = sCinderaceFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SCORBUNNY

#if P_FAMILY_SOBBLE
    [SPECIES_SOBBLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Memmeon"),
#else
        .speciesName = _("SOBBLE"),
#endif
        .cryId = CRY_SOBBLE,
        .natDexNum = NATIONAL_DEX_SOBBLE,
#if GERMAN
        .categoryName = _("Wasserechse"),
#else
        .categoryName = _("Water Lizard"),
#endif
        .height = 3,
        .weight = 40,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hat es Angst, vergießt es Tränen, die\n"
            "Reizstoffe enthalten, welche andere\n"
            "ebenfalls zum Weinen bringen. Sie sind so\n"
            "stark wie 100 Zwiebeln."),
#else
            "When scared, this Pokémon cries.\n"
            "Its tears pack the chemical punch of 100\n"
            "onions, and attackers won't be\n"
            "able to resist weeping."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sobble,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sobble,
        .backPicSize = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sobble,
        .shinyPalette = gMonShinyPalette_Sobble,
        .iconSprite = gMonIcon_Sobble,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-3, 3, SHADOW_SIZE_S)
        FOOTPRINT(Sobble)
        OVERWORLD(
            sPicTable_Sobble,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sobble,
            gShinyOverworldPalette_Sobble
        )
        .levelUpLearnset = sSobbleLevelUpLearnset,
        .teachableLearnset = sSobbleTeachableLearnset,
        .eggMoveLearnset = sSobbleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_DRIZZILE}),
    },

    [SPECIES_DRIZZILE] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 95,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 147,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Phlegleon"),
#else
        .speciesName = _("DRIZZILE"),
#endif
        .cryId = CRY_DRIZZILE,
        .natDexNum = NATIONAL_DEX_DRIZZILE,
#if GERMAN
        .categoryName = _("Wasserechse"),
#else
        .categoryName = _("Water Lizard"),
#endif
        .height = 7,
        .weight = 115,
        .description = COMPOUND_STRING(
#if GERMAN
        "Das Sekret, das aus seinen Handflächen\n"
        "austritt, formt es zu Wasserkugeln. Diese\n"
        "nutzt es im Kampf für taktisch\n"
        "ausgeklügelte Angriffe."),
#else
            "A clever combatant, this Pokémon battles\n"
            "using water balloons created with\n"
            "moisture secreted from its palms."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Drizzile,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Drizzile,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Drizzile,
        .shinyPalette = gMonShinyPalette_Drizzile,
        .iconSprite = gMonIcon_Drizzile,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(2, 5, SHADOW_SIZE_M)
        FOOTPRINT(Drizzile)
        OVERWORLD(
            sPicTable_Drizzile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Drizzile,
            gShinyOverworldPalette_Drizzile
        )
        .levelUpLearnset = sDrizzileLevelUpLearnset,
        .teachableLearnset = sDrizzileTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_INTELEON}),
    },

    [SPECIES_INTELEON] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 120,
        .baseSpAttack  = 125,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Intelleon"),
#else
        .speciesName = _("INTELEON"),
#endif
        .cryId = CRY_INTELEON,
        .natDexNum = NATIONAL_DEX_INTELEON,
#if GERMAN
        .categoryName = _("Geheimagente"),
#else
        .categoryName = _("Secret Agent"),
#endif
        .height = 19,
        .weight = 452,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zu seinen vielen geheimen\n"
        "Talenten gehört es, Wasser aus den\n"
        "Fingern zu schießen und mit der Membran\n"
        "am Rücken durch die Lüfte zu segeln."),
#else
            "It has many hidden capabilities, such as\n"
            "fingertips that can shoot water and a\n"
            "membrane on its back that it can use to\n"
            "glide through the air."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Inteleon,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Inteleon,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Inteleon,
        .shinyPalette = gMonShinyPalette_Inteleon,
        .iconSprite = gMonIcon_Inteleon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_S)
        FOOTPRINT(Inteleon)
        OVERWORLD(
            sPicTable_Inteleon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Inteleon,
            gShinyOverworldPalette_Inteleon
        )
        .levelUpLearnset = sInteleonLevelUpLearnset,
        .teachableLearnset = sInteleonTeachableLearnset,
        .formSpeciesIdTable = sInteleonFormSpeciesIdTable,
        .formChangeTable = sInteleonFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_INTELEON_GMAX] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 120,
        .baseSpAttack  = 125,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 265,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Intelleon"),
#else
        .speciesName = _("INTELEON"),
#endif
        .cryId = CRY_INTELEON,
        .natDexNum = NATIONAL_DEX_INTELEON,
#if GERMAN
        .categoryName = _("Geheimagente"),
#else
        .categoryName = _("Secret Agent"),
#endif
        .height = 400,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein Wasserstrahl erreicht\n"
        "ein Tempo von Mach 7. Beim Anvisieren\n"
        "des Zieles bestimmt es Wind und\n"
        "Temperatur mit dem Kamm auf seinem Kopf."),
#else
            "Gigantamax Inteleon's Water Gun\n"
            "move fires at Mach 7. As the Pokémon\n"
            "takes aim, it uses the crest on its\n"
            "head to gauge wind and temperature."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_InteleonGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_InteleonGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_InteleonGmax,
        .shinyPalette = gMonShinyPalette_InteleonGmax,
        .iconSprite = gMonIcon_InteleonGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_L)
        FOOTPRINT(Inteleon)
        .isGigantamax = TRUE,
        .levelUpLearnset = sInteleonLevelUpLearnset,
        .teachableLearnset = sInteleonTeachableLearnset,
        .formSpeciesIdTable = sInteleonFormSpeciesIdTable,
        .formChangeTable = sInteleonFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SOBBLE

#if P_FAMILY_SKWOVET
    [SPECIES_SKWOVET] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 25,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 55,
        .evYield_HP = 1,
        .itemRare = ITEM_ORAN_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHEEK_POUCH, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Raffel"),
#else
        .speciesName = _("SKWOVET"),
#endif
        .cryId = CRY_SKWOVET,
        .natDexNum = NATIONAL_DEX_SKWOVET,
#if GERMAN
        .categoryName = _("Raffbacke"),
#else
        .categoryName = _("Cheeky"),
#endif
        .height = 3,
        .weight = 25,
        .description = COMPOUND_STRING(
#if GERMAN
        "Da es unentwegt Beeren futtert,\n"
        "ist es zäher als es aussieht. Man sieht es\n"
        "oft auf Feldern, wo es nach Beeren sucht."),
#else
            "Found throughout the Galar region, this\n"
            "Pokémon becomes uneasy if its cheeks are\n"
            "ever completely empty of berries."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Skwovet,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Skwovet,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Skwovet,
        .shinyPalette = gMonShinyPalette_Skwovet,
        .iconSprite = gMonIcon_Skwovet,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-7, 5, SHADOW_SIZE_S)
        FOOTPRINT(Skwovet)
        OVERWORLD(
            sPicTable_Skwovet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Skwovet,
            gShinyOverworldPalette_Skwovet
        )
        .levelUpLearnset = sSkwovetLevelUpLearnset,
        .teachableLearnset = sSkwovetTeachableLearnset,
        .eggMoveLearnset = sSkwovetEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_GREEDENT}),
    },

    [SPECIES_GREEDENT] =
    {
        .baseHP        = 120,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 20,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 90,
        .expYield = 161,
        .evYield_HP = 2,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHEEK_POUCH, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Schlaraffel"),
#else
        .speciesName = _("GREEDENT"),
#endif
        .cryId = CRY_GREEDENT,
        .natDexNum = NATIONAL_DEX_GREEDENT,
#if GERMAN
        .categoryName = _("Gierschlund"),
#else
        .categoryName = _("Greedy"),
#endif
        .height = 6,
        .weight = 60,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es hortet in seinem Schweif Beeren.\n"
        "Versucht es, zu viele unterzubringen,\n"
        "fallen sie heraus. Da es jedoch nicht\n"
        "allzu clever ist, bemerkt es das nicht."),
#else
            "It stashes berries in its tail--so many\n"
            "berries that they fall out constantly.\n"
            "But this Pokémon is a bit slow-witted,\n"
            "so it doesn't notice the loss."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Greedent,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Greedent,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Greedent,
        .shinyPalette = gMonShinyPalette_Greedent,
        .iconSprite = gMonIcon_Greedent,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-11, 10, SHADOW_SIZE_M)
        FOOTPRINT(Greedent)
        OVERWORLD(
            sPicTable_Greedent,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Greedent,
            gShinyOverworldPalette_Greedent
        )
        .levelUpLearnset = sGreedentLevelUpLearnset,
        .teachableLearnset = sGreedentTeachableLearnset,
    },
#endif //P_FAMILY_SKWOVET

#if P_FAMILY_ROOKIDEE
    [SPECIES_ROOKIDEE] =
    {
        .baseHP        = 38,
        .baseAttack    = 47,
        .baseDefense   = 35,
        .baseSpeed     = 57,
        .baseSpAttack  = 33,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_FLYING),
        .catchRate = 255,
        .expYield = 49,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_UNNERVE, ABILITY_BIG_PECKS },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Meikro"),
#else
        .speciesName = _("ROOKIDEE"),
#endif
        .cryId = CRY_ROOKIDEE,
        .natDexNum = NATIONAL_DEX_ROOKIDEE,
#if GERMAN
        .categoryName = _("Kleinvogel"),
#else
        .categoryName = _("Tiny Bird"),
#endif
        .height = 2,
        .weight = 18,
        .description = COMPOUND_STRING(
#if GERMAN
        "Meikro ist von Natur aus sehr mutig\n"
        "und fordert daher jeden noch so starken\n"
        "Feind heraus. Selbst wenn es den Kürzeren\n"
        "zieht, dient dies seinem Training."),
#else
            "It will bravely challenge any opponent,\n"
            "no matter how powerful. This Pokémon\n"
            "benefits from every battle--even a\n"
            "defeat increases its strength a bit."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rookidee,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Rookidee,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Rookidee,
        .shinyPalette = gMonShinyPalette_Rookidee,
        .iconSprite = gMonIcon_Rookidee,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, -3, SHADOW_SIZE_S)
        FOOTPRINT(Rookidee)
        OVERWORLD(
            sPicTable_Rookidee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rookidee,
            gShinyOverworldPalette_Rookidee
        )
        .levelUpLearnset = sRookideeLevelUpLearnset,
        .teachableLearnset = sRookideeTeachableLearnset,
        .eggMoveLearnset = sRookideeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_CORVISQUIRE}),
    },

    [SPECIES_CORVISQUIRE] =
    {
        .baseHP        = 68,
        .baseAttack    = 67,
        .baseDefense   = 55,
        .baseSpeed     = 77,
        .baseSpAttack  = 43,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_FLYING),
        .catchRate = 120,
        .expYield = 128,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_UNNERVE, ABILITY_BIG_PECKS },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kranoviz"),
#else
        .speciesName = _("CORVISQUIRE"),
#endif
        .cryId = CRY_CORVISQUIRE,
        .natDexNum = NATIONAL_DEX_CORVISQUIRE,
#if GERMAN
        .categoryName = _("Krähe"),
#else
        .categoryName = _("Raven"),
#endif
        .height = 8,
        .weight = 160,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kranoviz weiß Objekte geschickt\n"
        "einzusetzen. So greift und wirft\n"
        "es zum Beispiel kleine Steine mit seinen\n"
        "Krallen oder wickelt Seile um Gegner."),
#else
            "Smart enough to use tools in battle,\n"
            "these Pokémon have been seen picking up\n"
            "rocks and flinging them or using ropes\n"
            "to wrap up enemies."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Corvisquire,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_CIRCLE_INTO_BG,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Corvisquire,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Corvisquire,
        .shinyPalette = gMonShinyPalette_Corvisquire,
        .iconSprite = gMonIcon_Corvisquire,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 16, SHADOW_SIZE_S)
        FOOTPRINT(Corvisquire)
        OVERWORLD(
            sPicTable_Corvisquire,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Corvisquire,
            gShinyOverworldPalette_Corvisquire
        )
        .levelUpLearnset = sCorvisquireLevelUpLearnset,
        .teachableLearnset = sCorvisquireTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_CORVIKNIGHT}),
    },

    [SPECIES_CORVIKNIGHT] =
    {
        .baseHP        = 98,
        .baseAttack    = 87,
        .baseDefense   = 105,
        .baseSpeed     = 67,
        .baseSpAttack  = 53,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FLYING, TYPE_STEEL),
        .catchRate = 45,
        .expYield = 248,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_PRESSURE, ABILITY_UNNERVE, ABILITY_MIRROR_ARMOR },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Krarmor"),
#else
        .speciesName = _("CORVIKNIGHT"),
#endif
        .cryId = CRY_CORVIKNIGHT,
        .natDexNum = NATIONAL_DEX_CORVIKNIGHT,
#if GERMAN
        .categoryName = _("Krähe"),
#else
        .categoryName = _("Raven"),
#endif
        .height = 22,
        .weight = 750,
        .description = COMPOUND_STRING(
#if GERMAN
        "Niemand wagt es, ihm den Himmel streitig zu\n"
        "machen. Sein schwarz glänzendes,\n"
        "stählernes Äußeres schüchtert jeden\n"
        "Gegner ein."),
#else
            "This Pokémon reigns supreme in the skies\n"
            "of the Galar region. The black luster of\n"
            "its steel body could drive terror into\n"
            "the heart of any foe."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Corviknight,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Corviknight,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Corviknight,
        .shinyPalette = gMonShinyPalette_Corviknight,
        .iconSprite = gMonIcon_Corviknight,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_L)
        FOOTPRINT(Corviknight)
        OVERWORLD(
            sPicTable_Corviknight,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Corviknight,
            gShinyOverworldPalette_Corviknight
        )
        .levelUpLearnset = sCorviknightLevelUpLearnset,
        .teachableLearnset = sCorviknightTeachableLearnset,
        .formSpeciesIdTable = sCorviknightFormSpeciesIdTable,
        .formChangeTable = sCorviknightFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_CORVIKNIGHT_GMAX] =
    {
        .baseHP        = 98,
        .baseAttack    = 87,
        .baseDefense   = 105,
        .baseSpeed     = 67,
        .baseSpAttack  = 53,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FLYING, TYPE_STEEL),
        .catchRate = 45,
        .expYield = 248,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_PRESSURE, ABILITY_UNNERVE, ABILITY_MIRROR_ARMOR },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Krarmor"),
#else
        .speciesName = _("CORVIKNIGHT"),
#endif
        .cryId = CRY_CORVIKNIGHT,
        .natDexNum = NATIONAL_DEX_CORVIKNIGHT,
#if GERMAN
        .categoryName = _("Krähe"),
#else
        .categoryName = _("Raven"),
#endif
        .height = 140,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Gigadynamax-Energie\n"
        "lösen seine Flügelschläge\n"
        "Sturmböen aus, die sogar stärker als\n"
        "Orkane sind und alles wegfegen können."),
#else
            "Imbued with Gigantamax energy, its\n"
            "wings can whip up winds more\n"
            "forceful than any a hurricane could\n"
            "muster. The gusts blow everything away."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_CorviknightGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CorviknightGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CorviknightGmax,
        .shinyPalette = gMonShinyPalette_CorviknightGmax,
        .iconSprite = gMonIcon_CorviknightGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_L)
        FOOTPRINT(Corviknight)
        .isGigantamax = TRUE,
        .levelUpLearnset = sCorviknightLevelUpLearnset,
        .teachableLearnset = sCorviknightTeachableLearnset,
        .formSpeciesIdTable = sCorviknightFormSpeciesIdTable,
        .formChangeTable = sCorviknightFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_ROOKIDEE

#if P_FAMILY_BLIPBUG
    [SPECIES_BLIPBUG] =
    {
        .baseHP        = 25,
        .baseAttack    = 20,
        .baseDefense   = 20,
        .baseSpeed     = 45,
        .baseSpAttack  = 25,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 255,
        .expYield = 36,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_COMPOUND_EYES, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Sensect"),
#else
        .speciesName = _("BLIPBUG"),
#endif
        .cryId = CRY_BLIPBUG,
        .natDexNum = NATIONAL_DEX_BLIPBUG,
#if GERMAN
        .categoryName = _("Larve"),
#else
        .categoryName = _("Larva"),
#endif
        .height = 4,
        .weight = 80,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sensect ist ein schlaues Pokémon, da es\n"
        "immer fleißig Informationen sammelt. Seine\n"
        "Stärke lässt jedoch zu wünschen übrig."),
#else
            "A constant collector of information,\n"
            "this Pokémon is very smart. Very strong\n"
            "is what it isn't."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Blipbug,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Blipbug,
        .backPicSize = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Blipbug,
        .shinyPalette = gMonShinyPalette_Blipbug,
        .iconSprite = gMonIcon_Blipbug,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(2, 1, SHADOW_SIZE_S)
        FOOTPRINT(Blipbug)
        OVERWORLD(
            sPicTable_Blipbug,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Blipbug,
            gShinyOverworldPalette_Blipbug
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sBlipbugLevelUpLearnset,
        .teachableLearnset = sBlipbugTeachableLearnset,
        .eggMoveLearnset = sBlipbugEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_DOTTLER}),
    },

    [SPECIES_DOTTLER] =
    {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 50,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_BUG, TYPE_PSYCHIC),
        .catchRate = 120,
        .expYield = 117,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_PSYCHIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_COMPOUND_EYES, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Keradar"),
#else
        .speciesName = _("DOTTLER"),
#endif
        .cryId = CRY_DOTTLER,
        .natDexNum = NATIONAL_DEX_DOTTLER,
#if GERMAN
        .categoryName = _("Radarkuppel"),
#else
        .categoryName = _("Radome"),
#endif
        .height = 4,
        .weight = 195,
        .description = COMPOUND_STRING(
#if GERMAN
        "Obwohl es sich fast nie bewegt, ist es am\n"
        "Leben. Es sollen Psycho-Kräfte in ihm\n"
        "erwacht sein, als es ohne Nahrung in seinem\n"
        "Panzer ausharrte."),
#else
            "It barely moves, but it's still alive.\n"
            "Hiding in its shell without food or\n"
            "water seems to have awakened its\n"
            "psychic powers."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dottler,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dottler,
        .backPicSize = MON_COORDS_SIZE(56, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dottler,
        .shinyPalette = gMonShinyPalette_Dottler,
        .iconSprite = gMonIcon_Dottler,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 0, SHADOW_SIZE_M)
        FOOTPRINT(Dottler)
        OVERWORLD(
            sPicTable_Dottler,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dottler,
            gShinyOverworldPalette_Dottler
        )
        .levelUpLearnset = sDottlerLevelUpLearnset,
        .teachableLearnset = sDottlerTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ORBEETLE}),
    },

    [SPECIES_ORBEETLE] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 110,
        .baseSpeed     = 90,
        .baseSpAttack  = 80,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_BUG, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 253,
        .evYield_SpDefense = 3,
        .itemRare = ITEM_PSYCHIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_FRISK, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Maritellit"),
#else
        .speciesName = _("ORBEETLE"),
#endif
        .cryId = CRY_ORBEETLE,
        .natDexNum = NATIONAL_DEX_ORBEETLE,
#if GERMAN
        .categoryName = _("Siebensterne"),
#else
        .categoryName = _("Seven Spot"),
#endif
        .height = 4,
        .weight = 408,
        .description = COMPOUND_STRING(
#if GERMAN
        "Maritellit ist allseits als sehr schlaues\n"
        "Pokémon bekannt. Sein großes Gehirn ist\n"
        "ein Indiz dafür, dass es über mächtige\n"
        "Psycho-Kräfte verfügt."),
#else
            "It's famous for its high level of\n"
            "intelligence, and the large size of its\n"
            "brain is proof that it also possesses\n"
            "immense psychic power."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Orbeetle,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Orbeetle,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Orbeetle,
        .shinyPalette = gMonShinyPalette_Orbeetle,
        .iconSprite = gMonIcon_Orbeetle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_M)
        FOOTPRINT(Orbeetle)
        OVERWORLD(
            sPicTable_Orbeetle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Orbeetle,
            gShinyOverworldPalette_Orbeetle
        )
        .levelUpLearnset = sOrbeetleLevelUpLearnset,
        .teachableLearnset = sOrbeetleTeachableLearnset,
        .formSpeciesIdTable = sOrbeetleFormSpeciesIdTable,
        .formChangeTable = sOrbeetleFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_ORBEETLE_GMAX] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 110,
        .baseSpeed     = 90,
        .baseSpAttack  = 80,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_BUG, TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 253,
        .evYield_SpDefense = 3,
        .itemRare = ITEM_PSYCHIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_FRISK, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Maritellit"),
#else
        .speciesName = _("ORBEETLE"),
#endif
        .cryId = CRY_ORBEETLE,
        .natDexNum = NATIONAL_DEX_ORBEETLE,
#if GERMAN
        .categoryName = _("Siebensterne"),
#else
        .categoryName = _("Seven Spot"),
#endif
        .height = 140,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein gigantisches Gehirn dominiert nun\n"
        "seinen Körper. Es verfügt über enorme\n"
        "Intelligenz und überwältigende\n"
        "Psycho-Kräfte."),
#else
            "Its brain has grown to a gargantuan\n"
            "size, as has the rest of its body.\n"
            "This Pokémon's intellect and\n"
            "psychic abilities are overpowering."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_OrbeetleGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_OrbeetleGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_OrbeetleGmax,
        .shinyPalette = gMonShinyPalette_OrbeetleGmax,
        .iconSprite = gMonIcon_OrbeetleGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Orbeetle)
        .isGigantamax = TRUE,
        .levelUpLearnset = sOrbeetleLevelUpLearnset,
        .teachableLearnset = sOrbeetleTeachableLearnset,
        .formSpeciesIdTable = sOrbeetleFormSpeciesIdTable,
        .formChangeTable = sOrbeetleFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_BLIPBUG

#if P_FAMILY_NICKIT
    [SPECIES_NICKIT] =
    {
        .baseHP        = 40,
        .baseAttack    = 28,
        .baseDefense   = 28,
        .baseSpeed     = 50,
        .baseSpAttack  = 47,
        .baseSpDefense = 52,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 255,
        .expYield = 49,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_UNBURDEN, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Kleptifux"),
#else
        .speciesName = _("NICKIT"),
#endif
        .cryId = CRY_NICKIT,
        .natDexNum = NATIONAL_DEX_NICKIT,
#if GERMAN
        .categoryName = _("Fuchs"),
#else
        .categoryName = _("Fox"),
#endif
        .height = 6,
        .weight = 89,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kleptifux stibitzt Futter, das andere\n"
        "Pokémon gefunden haben. Dank der\n"
        "samtweichen Ballen an seinen Pfoten ist\n"
        "sein Gang lautlos."),
#else
            "Aided by the soft pads on its feet, it\n"
            "silently raids the food stores of other\n"
            "Pokémon. It survives off its\n"
            "ill-gotten gains."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Nickit,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Nickit,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Nickit,
        .shinyPalette = gMonShinyPalette_Nickit,
        .iconSprite = gMonIcon_Nickit,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 4, SHADOW_SIZE_M)
        FOOTPRINT(Nickit)
        OVERWORLD(
            sPicTable_Nickit,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Nickit,
            gShinyOverworldPalette_Nickit
        )
        .levelUpLearnset = sNickitLevelUpLearnset,
        .teachableLearnset = sNickitTeachableLearnset,
        .eggMoveLearnset = sNickitEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_THIEVUL}),
    },

    [SPECIES_THIEVUL] =
    {
        .baseHP        = 70,
        .baseAttack    = 58,
        .baseDefense   = 58,
        .baseSpeed     = 90,
        .baseSpAttack  = 87,
        .baseSpDefense = 92,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 127,
        .expYield = 159,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_UNBURDEN, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Gaunux"),
#else
        .speciesName = _("THIEVUL"),
#endif
        .cryId = CRY_THIEVUL,
        .natDexNum = NATIONAL_DEX_THIEVUL,
#if GERMAN
        .categoryName = _("Fuchs"),
#else
        .categoryName = _("Fox"),
#endif
        .height = 12,
        .weight = 199,
        .description = COMPOUND_STRING(
#if GERMAN
        "Gaunux markiert heimlich\n"
        "die Beute, auf die es ein Auge geworfen\n"
        "hat. Dann folgt es dem Geruch und stiehlt\n"
        "sie, wenn sich die Gelegenheit bietet."),
#else
            "It secretly marks potential targets with\n"
            "a scent. By following the scent, it\n"
            "stalks its targets and steals from them\n"
            "when they least expect it."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Thievul,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Thievul,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Thievul,
        .shinyPalette = gMonShinyPalette_Thievul,
        .iconSprite = gMonIcon_Thievul,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-9, 7, SHADOW_SIZE_M)
        FOOTPRINT(Thievul)
        OVERWORLD(
            sPicTable_Thievul,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Thievul,
            gShinyOverworldPalette_Thievul
        )
        .levelUpLearnset = sThievulLevelUpLearnset,
        .teachableLearnset = sThievulTeachableLearnset,
    },
#endif //P_FAMILY_NICKIT

#if P_FAMILY_GOSSIFLEUR
    [SPECIES_GOSSIFLEUR] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 10,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 190,
        .expYield = 50,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_COTTON_DOWN, ABILITY_REGENERATOR, ABILITY_EFFECT_SPORE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Cottini"),
#else
        .speciesName = _("GOSSIFLEUR"),
#endif
        .cryId = CRY_GOSSIFLEUR,
        .natDexNum = NATIONAL_DEX_GOSSIFLEUR,
#if GERMAN
        .categoryName = _("Blumenzier"),
#else
        .categoryName = _("Flowering"),
#endif
        .height = 4,
        .weight = 22,
        .description = COMPOUND_STRING(
#if GERMAN
        "Steckt es sein Beinchen fest in den Boden\n"
        "und badet dann ausgiebig im Sonnenlicht,\n"
        "nimmt seine Blüte eine kräftigere Farbe an."),
#else
            "It anchors itself in the ground with its\n"
            "single leg, then basks in the sun. After\n"
            "absorbing enough sunlight, its petals\n"
            "spread as it blooms brilliantly."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gossifleur,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Gossifleur,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Gossifleur,
        .shinyPalette = gMonShinyPalette_Gossifleur,
        .iconSprite = gMonIcon_Gossifleur,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Gossifleur)
        OVERWORLD(
            sPicTable_Gossifleur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gossifleur,
            gShinyOverworldPalette_Gossifleur
        )
        .levelUpLearnset = sGossifleurLevelUpLearnset,
        .teachableLearnset = sGossifleurTeachableLearnset,
        .eggMoveLearnset = sGossifleurEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_ELDEGOSS}),
    },

    [SPECIES_ELDEGOSS] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 75,
        .expYield = 161,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_COTTON_DOWN, ABILITY_REGENERATOR, ABILITY_EFFECT_SPORE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Cottomi"),
#else
        .speciesName = _("ELDEGOSS"),
#endif
        .cryId = CRY_ELDEGOSS,
        .natDexNum = NATIONAL_DEX_ELDEGOSS,
#if GERMAN
        .categoryName = _("Baumwollzier"),
#else
        .categoryName = _("Cotton Bloom"),
#endif
        .height = 5,
        .weight = 25,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Saat seines Wollflaums steckt voller\n"
        "Nährstoffe. Es verstreut sie im Wind\n"
        "und heilt damit Pflanzen und Pokémon."),
#else
            "The seeds attached to its cotton fluff\n"
            "are full of nutrients. It spreads them\n"
            "on the wind so that plants and other\n"
            "Pokémon can benefit from them."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Eldegoss,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Eldegoss,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Eldegoss,
        .shinyPalette = gMonShinyPalette_Eldegoss,
        .iconSprite = gMonIcon_Eldegoss,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, 8, SHADOW_SIZE_S)
        FOOTPRINT(Eldegoss)
        OVERWORLD(
            sPicTable_Eldegoss,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Eldegoss,
            gShinyOverworldPalette_Eldegoss
        )
        .levelUpLearnset = sEldegossLevelUpLearnset,
        .teachableLearnset = sEldegossTeachableLearnset,
    },
#endif //P_FAMILY_GOSSIFLEUR

#if P_FAMILY_WOOLOO
    [SPECIES_WOOLOO] =
    {
        .baseHP        = 42,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 48,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 122,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FLUFFY, ABILITY_RUN_AWAY, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Wolly"),
#else
        .speciesName = _("WOOLOO"),
#endif
        .cryId = CRY_WOOLOO,
        .natDexNum = NATIONAL_DEX_WOOLOO,
#if GERMAN
        .categoryName = _("Schaf"),
#else
        .categoryName = _("Sheep"),
#endif
        .height = 6,
        .weight = 60,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wollys stark gelocktes Fell hat eine sehr\n"
            "polsternde Wirkung. Selbst eine Klippe\n"
            "hinunterzufallen macht ihm nichts aus."),
#else
            "Its curly fleece is such an effective\n"
            "cushion that this Pokémon could fall off\n"
            "a cliff and stand right back up at the\n"
            "bottom, unharmed."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Wooloo,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Wooloo,
        .backPicSize = MON_COORDS_SIZE(56, 32),
        .backPicYOffset = 18,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Wooloo,
        .shinyPalette = gMonShinyPalette_Wooloo,
        .iconSprite = gMonIcon_Wooloo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Wooloo)
        OVERWORLD(
            sPicTable_Wooloo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Wooloo,
            gShinyOverworldPalette_Wooloo
        )
        .levelUpLearnset = sWoolooLevelUpLearnset,
        .teachableLearnset = sWoolooTeachableLearnset,
        .eggMoveLearnset = sWoolooEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_DUBWOOL}),
    },

    [SPECIES_DUBWOOL] =
    {
        .baseHP        = 72,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 88,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 127,
        .expYield = 172,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FLUFFY, ABILITY_STEADFAST, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Zwollock"),
#else
        .speciesName = _("DUBWOOL"),
#endif
        .cryId = CRY_DUBWOOL,
        .natDexNum = NATIONAL_DEX_DUBWOOL,
#if GERMAN
        .categoryName = _("Schaf"),
#else
        .categoryName = _("Sheep"),
#endif
        .height = 13,
        .weight = 430,
        .description = COMPOUND_STRING(
#if GERMAN
        "Spannt man einen aus den elastischen\n"
        "Haaren von Zwollock gewobenen Teppich\n"
        "auf, kann man darauf hüpfen wie auf einem\n"
        "Trampolin."),
#else
            "Weave a carpet from its springy wool,\n"
            "and you end up with something closer to\n"
            "a trampoline. You'll start to bounce the\n"
            "moment you set foot on it."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dubwool,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dubwool,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dubwool,
        .shinyPalette = gMonShinyPalette_Dubwool,
        .iconSprite = gMonIcon_Dubwool,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Dubwool)
        OVERWORLD(
            sPicTable_Dubwool,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dubwool,
            gShinyOverworldPalette_Dubwool
        )
        .levelUpLearnset = sDubwoolLevelUpLearnset,
        .teachableLearnset = sDubwoolTeachableLearnset,
    },
#endif //P_FAMILY_WOOLOO

#if P_FAMILY_CHEWTLE
    [SPECIES_CHEWTLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 64,
        .baseDefense   = 50,
        .baseSpeed     = 44,
        .baseSpAttack  = 38,
        .baseSpDefense = 38,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 57,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_STRONG_JAW, ABILITY_SHELL_ARMOR, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Kamehaps"),
#else
        .speciesName = _("CHEWTLE"),
#endif
        .cryId = CRY_CHEWTLE,
        .natDexNum = NATIONAL_DEX_CHEWTLE,
#if GERMAN
        .categoryName = _("Schnapp"),
#else
        .categoryName = _("Snapping"),
#endif
        .height = 3,
        .weight = 85,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kamehaps schnappt sofort nach allem, was\n"
        "ihm unterkommt. Der Grund dafür ist\n"
        "anscheinend, dass seine wachsenden\n"
        "Vorderzähne jucken."),
#else
            "Apparently the itch of its teething\n"
            "impels it to snap its jaws at anything\n"
            "in front of it."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chewtle,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 1),
        ),
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Chewtle,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Chewtle,
        .shinyPalette = gMonShinyPalette_Chewtle,
        .iconSprite = gMonIcon_Chewtle,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(3, 1, SHADOW_SIZE_S)
        FOOTPRINT(Chewtle)
        OVERWORLD(
            sPicTable_Chewtle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Chewtle,
            gShinyOverworldPalette_Chewtle
        )
        .levelUpLearnset = sChewtleLevelUpLearnset,
        .teachableLearnset = sChewtleTeachableLearnset,
        .eggMoveLearnset = sChewtleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_DREDNAW}),
    },

    [SPECIES_DREDNAW] =
    {
        .baseHP        = 90,
        .baseAttack    = 115,
        .baseDefense   = 90,
        .baseSpeed     = 74,
        .baseSpAttack  = 48,
        .baseSpDefense = 68,
        .types = MON_TYPES(TYPE_WATER, TYPE_ROCK),
        .catchRate = 75,
        .expYield = 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_STRONG_JAW, ABILITY_SHELL_ARMOR, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Kamalm"),
#else
        .speciesName = _("DREDNAW"),
#endif
        .cryId = CRY_DREDNAW,
        .natDexNum = NATIONAL_DEX_DREDNAW,
#if GERMAN
        .categoryName = _("Biss"),
#else
        .categoryName = _("Bite"),
#endif
        .height = 10,
        .weight = 1155,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses von Natur aus aggressive Pokémon\n"
        "beißt seine Beute mit seinem kräftigen\n"
        "Kiefer, der selbst Eisenstangen zermalmen\n"
        "kann."),
#else
            "With jaws that can shear through steel\n"
            "rods, this highly aggressive Pokémon\n"
            "chomps down on its unfortunate prey."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Drednaw,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Drednaw,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 18,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Drednaw,
        .shinyPalette = gMonShinyPalette_Drednaw,
        .iconSprite = gMonIcon_Drednaw,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 4, SHADOW_SIZE_L)
        FOOTPRINT(Drednaw)
        OVERWORLD(
            sPicTable_Drednaw,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Drednaw,
            gShinyOverworldPalette_Drednaw
        )
        .levelUpLearnset = sDrednawLevelUpLearnset,
        .teachableLearnset = sDrednawTeachableLearnset,
        .formSpeciesIdTable = sDrednawFormSpeciesIdTable,
        .formChangeTable = sDrednawFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_DREDNAW_GMAX] =
    {
        .baseHP        = 90,
        .baseAttack    = 115,
        .baseDefense   = 90,
        .baseSpeed     = 74,
        .baseSpAttack  = 48,
        .baseSpDefense = 68,
        .types = MON_TYPES(TYPE_WATER, TYPE_ROCK),
        .catchRate = 75,
        .expYield = 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_WATER_1),
        .abilities = { ABILITY_STRONG_JAW, ABILITY_SHELL_ARMOR, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Kamalm"),
#else
        .speciesName = _("DREDNAW"),
#endif
        .cryId = CRY_DREDNAW,
        .natDexNum = NATIONAL_DEX_DREDNAW,
#if GERMAN
        .categoryName = _("Biss"),
#else
        .categoryName = _("Bite"),
#endif
        .height = 240,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Gigadynamax-Energie\n"
        "steht es nun auf seinen Hinterbeinen.\n"
        "Es stürzt sich auf Gegner und\n"
        "zermalmt diese mit seinem riesigen Kiefer."),
#else
            "In the Galar region, there's a tale\n"
            "about this Pokémon chewing up a\n"
            "mountain and using the rubble to stop a\n"
            "flood."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DrednawGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DrednawGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DrednawGmax,
        .shinyPalette = gMonShinyPalette_DrednawGmax,
        .iconSprite = gMonIcon_DrednawGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Drednaw)
        .isGigantamax = TRUE,
        .levelUpLearnset = sDrednawLevelUpLearnset,
        .teachableLearnset = sDrednawTeachableLearnset,
        .formSpeciesIdTable = sDrednawFormSpeciesIdTable,
        .formChangeTable = sDrednawFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_CHEWTLE

#if P_FAMILY_YAMPER
    [SPECIES_YAMPER] =
    {
        .baseHP        = 59,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 26,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 255,
        .expYield = 54,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BALL_FETCH, ABILITY_NONE, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Voldi"),
#else
        .speciesName = _("YAMPER"),
#endif
        .cryId = CRY_YAMPER,
        .natDexNum = NATIONAL_DEX_YAMPER,
#if GERMAN
        .categoryName = _("Welpe"),
#else
        .categoryName = _("Puppy"),
#endif
        .height = 3,
        .weight = 135,
        .description = COMPOUND_STRING(
#if GERMAN
        "Im Austausch gegen Leckerlis hilft dieser\n"
        "kleine Vielfraß Menschen bei der Arbeit.\n"
        "Beim Rennen wird es von knisternder\n"
        "Elektrizität umhüllt."),
#else
            "This Pokémon is very popular as a\n"
            "herding dog in the Galar region. As it\n"
            "runs, it generates electricity from the\n"
            "base of its tail."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Yamper,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Yamper,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Yamper,
        .shinyPalette = gMonShinyPalette_Yamper,
        .iconSprite = gMonIcon_Yamper,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 2, SHADOW_SIZE_M)
        FOOTPRINT(Yamper)
        OVERWORLD(
            sPicTable_Yamper,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Yamper,
            gShinyOverworldPalette_Yamper
        )
        .levelUpLearnset = sYamperLevelUpLearnset,
        .teachableLearnset = sYamperTeachableLearnset,
        .eggMoveLearnset = sYamperEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_BOLTUND}),
    },

    [SPECIES_BOLTUND] =
    {
        .baseHP        = 69,
        .baseAttack    = 90,
        .baseDefense   = 60,
        .baseSpeed     = 121,
        .baseSpAttack  = 90,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 45,
        .expYield = 172,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_STRONG_JAW, ABILITY_NONE, ABILITY_COMPETITIVE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Bellektro"),
#else
        .speciesName = _("BOLTUND"),
#endif
        .cryId = CRY_BOLTUND,
        .natDexNum = NATIONAL_DEX_BOLTUND,
#if GERMAN
        .categoryName = _("Hund"),
#else
        .categoryName = _("Dog"),
#endif
        .height = 10,
        .weight = 340,
        .description = COMPOUND_STRING(
#if GERMAN
        "Bellektro generiert Strom und\n"
        "lässt ihn zur Unterstützung beim Rennen\n"
        "in seine Beine fließen. Dadurch kann es\n"
        "drei Tage und Nächte ohne Pause rennen."),
#else
            "This Pokémon generates electricity and\n"
            "channels it into its legs to keep them\n"
            "going strong. Boltund can run nonstop\n"
            "for three full days."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Boltund,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Boltund,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Boltund,
        .shinyPalette = gMonShinyPalette_Boltund,
        .iconSprite = gMonIcon_Boltund,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_M)
        FOOTPRINT(Boltund)
        OVERWORLD(
            sPicTable_Boltund,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Boltund,
            gShinyOverworldPalette_Boltund
        )
        .levelUpLearnset = sBoltundLevelUpLearnset,
        .teachableLearnset = sBoltundTeachableLearnset,
    },
#endif //P_FAMILY_YAMPER

#if P_FAMILY_ROLYCOLY
    [SPECIES_ROLYCOLY] =
    {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 255,
        .expYield = 48,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_HEATPROOF, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Klonkett"),
#else
        .speciesName = _("ROLYCOLY"),
#endif
        .cryId = CRY_ROLYCOLY,
        .natDexNum = NATIONAL_DEX_ROLYCOLY,
#if GERMAN
        .categoryName = _("Kohle"),
#else
        .categoryName = _("Coal"),
#endif
        .height = 3,
        .weight = 120,
        .description = COMPOUND_STRING(
#if GERMAN
        "Klonkett wurde vor circa 400 Jahren in\n"
        "einer Kohlemine entdeckt. Sein Körper\n"
        "besteht fast aus denselben Komponenten\n"
        "wie Steinkohle."),
#else
            "Most of its body has the same composition\n"
            "as coal. Fittingly, this Pokémon was\n"
            "first discovered in coal mines about\n"
            "400 years ago."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rolycoly,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Rolycoly,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Rolycoly,
        .shinyPalette = gMonShinyPalette_Rolycoly,
        .iconSprite = gMonIcon_Rolycoly,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -3, SHADOW_SIZE_S)
        FOOTPRINT(Rolycoly)
        OVERWORLD(
            sPicTable_Rolycoly,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rolycoly,
            gShinyOverworldPalette_Rolycoly
        )
        .levelUpLearnset = sRolycolyLevelUpLearnset,
        .teachableLearnset = sRolycolyTeachableLearnset,
        .eggMoveLearnset = sRolycolyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_CARKOL}),
    },

    [SPECIES_CARKOL] =
    {
        .baseHP        = 80,
        .baseAttack    = 60,
        .baseDefense   = 90,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIRE),
        .catchRate = 120,
        .expYield = 144,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_FLAME_BODY, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Wagong"),
#else
        .speciesName = _("CARKOL"),
#endif
        .cryId = CRY_CARKOL,
        .natDexNum = NATIONAL_DEX_CARKOL,
#if GERMAN
        .categoryName = _("Kohle"),
#else
        .categoryName = _("Coal"),
#endif
        .height = 11,
        .weight = 780,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wagong dreht seine Füße\n"
        "mit hoher Geschwindigkeit und kann sich\n"
        "dadurch bis zu 30 km/h schnell bewegen.\n"
        "Es speit 1 000 Grad heiße Flammen."),
#else
            "It forms coal inside its body. Coal\n"
            "dropped by this Pokémon once helped fuel\n"
            "the lives of people in the Galar region."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Carkol,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Carkol,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Carkol,
        .shinyPalette = gMonShinyPalette_Carkol,
        .iconSprite = gMonIcon_Carkol,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_M)
        FOOTPRINT(Carkol)
        OVERWORLD(
            sPicTable_Carkol,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Carkol,
            gShinyOverworldPalette_Carkol
        )
        .levelUpLearnset = sCarkolLevelUpLearnset,
        .teachableLearnset = sCarkolTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COALOSSAL}),
    },

    [SPECIES_COALOSSAL] =
    {
        .baseHP        = 110,
        .baseAttack    = 80,
        .baseDefense   = 120,
        .baseSpeed     = 30,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 255,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_FLAME_BODY, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Montecarbo"),
#else
        .speciesName = _("COALOSSAL"),
#endif
        .cryId = CRY_COALOSSAL,
        .natDexNum = NATIONAL_DEX_COALOSSAL,
#if GERMAN
        .categoryName = _("Kohle"),
#else
        .categoryName = _("Coal"),
#endif
        .height = 28,
        .weight = 3105,
        .description = COMPOUND_STRING(
#if GERMAN
        "Meist ist es friedfertig, aber wenn\n"
        "Menschen eine Mine zugrunde richten, sieht\n"
        "es rot und verbrennt sie mit 1 500 ºC\n"
        "heißen Flammen."),
#else
            "It's usually peaceful, but the vandalism\n"
            "of mines enrages it. Offenders will be\n"
            "incinerated with flames that reach\n"
            "2,700 degrees Fahrenheit."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Coalossal,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        .frontAnimId = ANIM_GLOW_RED,
        .backPic = gMonBackPic_Coalossal,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Coalossal,
        .shinyPalette = gMonShinyPalette_Coalossal,
        .iconSprite = gMonIcon_Coalossal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_L)
        FOOTPRINT(Coalossal)
        OVERWORLD(
            sPicTable_Coalossal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Coalossal,
            gShinyOverworldPalette_Coalossal
        )
        .levelUpLearnset = sCoalossalLevelUpLearnset,
        .teachableLearnset = sCoalossalTeachableLearnset,
        .formSpeciesIdTable = sCoalossalFormSpeciesIdTable,
        .formChangeTable = sCoalossalFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_COALOSSAL_GMAX] =
    {
        .baseHP        = 110,
        .baseAttack    = 80,
        .baseDefense   = 120,
        .baseSpeed     = 30,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 255,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_FLAME_BODY, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Montecarbo"),
#else
        .speciesName = _("COALOSSAL"),
#endif
        .cryId = CRY_COALOSSAL,
        .natDexNum = NATIONAL_DEX_COALOSSAL,
#if GERMAN
        .categoryName = _("Kohle"),
#else
        .categoryName = _("Coal"),
#endif
        .height = 420,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein Körper ist ein gigantischer Ofen.\n"
        "Durch die Gigadynamax-Energie hat sich\n"
        "das Feuer in seinem Inneren auf 2 000 Grad\n"
        "erhitzt."),
#else
            "Its body is a colossal stove. With\n"
            "Gigantamax energy stoking the fire,\n"
            "this Pokémon's flame burns hotter\n"
            "than 3,600 degrees Fahrenheit."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CoalossalGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CoalossalGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CoalossalGmax,
        .shinyPalette = gMonShinyPalette_CoalossalGmax,
        .iconSprite = gMonIcon_CoalossalGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Coalossal)
        .isGigantamax = TRUE,
        .levelUpLearnset = sCoalossalLevelUpLearnset,
        .teachableLearnset = sCoalossalTeachableLearnset,
        .formSpeciesIdTable = sCoalossalFormSpeciesIdTable,
        .formChangeTable = sCoalossalFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_ROLYCOLY

#if P_FAMILY_APPLIN
    [SPECIES_APPLIN] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 80,
        .baseSpeed     = 20,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 255,
        .expYield = 52,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Knapfel"),
#else
        .speciesName = _("APPLIN"),
#endif
        .cryId = CRY_APPLIN,
        .natDexNum = NATIONAL_DEX_APPLIN,
#if GERMAN
        .categoryName = _("Apfelhaus"),
#else
        .categoryName = _("Apple Core"),
#endif
        .height = 2,
        .weight = 5,
        .description = COMPOUND_STRING(
#if GERMAN
            "Knapfel verbringt sein ganzes Leben im\n"
            "Inneren eines Apfels. Um sich vor\n"
            "Vogel-Pokémon, seinen Fressfeinden, zu\n"
            "schützen, imitiert es einen Apfel."),
#else
            "It spends its entire life inside an\n"
            "apple. It hides from its natural enemies,\n"
            "bird Pokémon, by pretending it's just an\n"
            "apple and nothing more."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Applin,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Applin,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Applin,
        .shinyPalette = gMonShinyPalette_Applin,
        .iconSprite = gMonIcon_Applin,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, -3, SHADOW_SIZE_S)
        FOOTPRINT(Applin)
        OVERWORLD(
            sPicTable_Applin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Applin,
            gShinyOverworldPalette_Applin
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sApplinLevelUpLearnset,
        .teachableLearnset = sApplinTeachableLearnset,
        .eggMoveLearnset = sApplinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_FLAPPLE},
                                {EVO_ITEM, ITEM_SUN_STONE, SPECIES_APPLETUN},
                                {EVO_ITEM, ITEM_TART_APPLE, SPECIES_FLAPPLE},
                                {EVO_ITEM, ITEM_SWEET_APPLE, SPECIES_APPLETUN}
                            #if P_GEN_9_CROSS_EVOS
                                ,{EVO_ITEM, ITEM_OVAL_STONE, SPECIES_DIPPLIN}
                                ,{EVO_ITEM, ITEM_SYRUPY_APPLE, SPECIES_DIPPLIN}
                            #endif
                            ),
    },

    [SPECIES_FLAPPLE] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 80,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Drapfel"),
#else
        .speciesName = _("FLAPPLE"),
#endif
        .cryId = CRY_FLAPPLE,
        .natDexNum = NATIONAL_DEX_FLAPPLE,
#if GERMAN
        .categoryName = _("Apfelflügel"),
#else
        .categoryName = _("Apple Wing"),
#endif
        .height = 3,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
        "Nach dem Verzehr eines sauren\n"
        "Apfels hat es sich entwickelt. In den\n"
        "Backentaschen speichert es eine saure\n"
        "Substanz, die zu Verbrennungen führt."),
#else
            "It ate a sour apple, and that induced its\n"
            "evolution. In its cheeks, it stores an acid\n"
            "capable of causing chemical burns."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Flapple,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 9,
        .backPic = gMonBackPic_Flapple,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Flapple,
        .shinyPalette = gMonShinyPalette_Flapple,
        .iconSprite = gMonIcon_Flapple,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 11, SHADOW_SIZE_S)
        FOOTPRINT(Flapple)
        OVERWORLD(
            sPicTable_Flapple,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Flapple,
            gShinyOverworldPalette_Flapple
        )
        .levelUpLearnset = sFlappleLevelUpLearnset,
        .teachableLearnset = sFlappleTeachableLearnset,
        .formSpeciesIdTable = sFlappleFormSpeciesIdTable,
        .formChangeTable = sFlappleFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_FLAPPLE_GMAX] =
    {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 80,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Drapfel"),
#else
        .speciesName = _("FLAPPLE"),
#endif
        .cryId = CRY_FLAPPLE,
        .natDexNum = NATIONAL_DEX_FLAPPLE,
#if GERMAN
        .categoryName = _("Apfelflügel"),
#else
        .categoryName = _("Apple Wing"),
#endif
        .height = 240,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Gigadynamax-Energie\n"
        "hat sich die Menge seines\n"
        "Nektars vervielfacht. Seine Gestalt\n"
        "ähnelt nun einem gigantischen Apfel."),
#else
            "Under the influence of Gigantamax\n"
            "energy, it produces much more sweet\n"
            "nectar, and its shape has changed\n"
            "to resemble a giant apple."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_FlappleGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_FlappleGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_FlappleGmax,
        .shinyPalette = gMonShinyPalette_FlappleGmax,
        .iconSprite = gMonIcon_FlappleGmax,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Flapple)
        .isGigantamax = TRUE,
        .levelUpLearnset = sFlappleLevelUpLearnset,
        .teachableLearnset = sFlappleTeachableLearnset,
        .formSpeciesIdTable = sFlappleFormSpeciesIdTable,
        .formChangeTable = sFlappleFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS

    [SPECIES_APPLETUN] =
    {
        .baseHP        = 110,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 170,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Schlapfel"),
#else
        .speciesName = _("APPLETUN"),
#endif
        .cryId = CRY_APPLETUN,
        .natDexNum = NATIONAL_DEX_APPLETUN,
#if GERMAN
        .categoryName = _("Apfelnektar"),
#else
        .categoryName = _("Apple Nectar"),
#endif
        .height = 4,
        .weight = 130,
        .description = COMPOUND_STRING(
#if GERMAN
        "Nach dem Verzehr eines süßen Apfels hat\n"
        "es sich entwickelt. Es verströmt einen\n"
        "süßen Duft und lockt damit sein Futter an:\n"
        "Käfer-Pokémon."),
#else
            "Eating a sweet apple caused its evolution.\n"
            "A nectarous scent wafts from its body,\n"
            "luring in the bug Pokémon it preys on."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Appletun,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Appletun,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Appletun,
        .shinyPalette = gMonShinyPalette_Appletun,
        .iconSprite = gMonIcon_Appletun,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(5, 6, SHADOW_SIZE_L)
        FOOTPRINT(Appletun)
        OVERWORLD(
            sPicTable_Appletun,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Appletun,
            gShinyOverworldPalette_Appletun
        )
        .levelUpLearnset = sAppletunLevelUpLearnset,
        .teachableLearnset = sAppletunTeachableLearnset,
        .formSpeciesIdTable = sAppletunFormSpeciesIdTable,
        .formChangeTable = sAppletunFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_APPLETUN_GMAX] =
    {
        .baseHP        = 110,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 170,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Schlapfel"),
#else
        .speciesName = _("APPLETUN"),
#endif
        .cryId = CRY_APPLETUN,
        .natDexNum = NATIONAL_DEX_APPLETUN,
#if GERMAN
        .categoryName = _("Apfelnektar"),
#else
        .categoryName = _("Apple Nectar"),
#endif
        .height = 240,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es feuert große Mengen an Nektar aus\n"
        "seinem Körper auf seine Gegner, damit\n"
        "diese unter dem klebrigen Schleim\n"
        "ersticken."),
#else
            "Due to Gigantamax energy, this\n"
            "Pokémon's nectar has thickened. The\n"
            "increased viscosity lets the nectar\n"
            "absorb more damage than before."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AppletunGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AppletunGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_AppletunGmax,
        .shinyPalette = gMonShinyPalette_AppletunGmax,
        .iconSprite = gMonIcon_AppletunGmax,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Appletun)
        .isGigantamax = TRUE,
        .levelUpLearnset = sAppletunLevelUpLearnset,
        .teachableLearnset = sAppletunTeachableLearnset,
        .formSpeciesIdTable = sAppletunFormSpeciesIdTable,
        .formChangeTable = sAppletunFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS

#if P_GEN_9_CROSS_EVOS
    [SPECIES_DIPPLIN] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 40,
        .baseSpAttack  = 95,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 170,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SUPERSWEET_SYRUP, ABILITY_GLUTTONY, ABILITY_STICKY_HOLD },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Sirapfel"),
#else
        .speciesName = _("DIPPLIN"),
#endif
        .cryId = CRY_DIPPLIN,
        .natDexNum = NATIONAL_DEX_DIPPLIN,
#if GERMAN
        .categoryName = _("Apfelsirup"),
#else
        .categoryName = _("Candy Apple"),
#endif
        .height = 4,
        .weight = 44,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon besteht aus zwei\n"
        "Individuen. Es hat sich mithilfe eines\n"
        "Apfels entwickelt, der nur in einer\n"
        "bestimmten Gegend angebaut wird."),
#else
            "Dipplin is two creatures in one Pokémon.\n"
            "Its evolution was triggered by a special\n"
            "apple grown only in one place."),
#endif
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dipplin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dipplin,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dipplin,
        .shinyPalette = gMonShinyPalette_Dipplin,
        .iconSprite = gMonIcon_Dipplin,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-4, 8, SHADOW_SIZE_S)
        FOOTPRINT(Dipplin)
        OVERWORLD(
            sPicTable_Dipplin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dipplin,
            gShinyOverworldPalette_Dipplin
        )
        .levelUpLearnset = sDipplinLevelUpLearnset,
        .teachableLearnset = sDipplinTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_HYDRAPPLE},
                                {EVO_LEVEL, 0, SPECIES_HYDRAPPLE, CONDITIONS({IF_KNOWS_MOVE, MOVE_DRAGON_CHEER})}),
    },

    [SPECIES_HYDRAPPLE] =
    {
        .baseHP        = 106,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 44,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_DRAGON),
        .catchRate = 10,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SUPERSWEET_SYRUP, ABILITY_REGENERATOR, ABILITY_STICKY_HOLD },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Hydrapfel"),
#else
        .speciesName = _("HYDRAPPLE"),
#endif
        .cryId = CRY_HYDRAPPLE,
        .natDexNum = NATIONAL_DEX_HYDRAPPLE,
#if GERMAN
        .categoryName = _("Apfelhydra"),
#else
        .categoryName = _("Apple Hydra"),
#endif
        .height = 18,
        .weight = 930,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sieben sogenannte “Schlangel”\n"
        "leben in einem Apfel aus Nektar. Das\n"
        "Exemplar in der Mitte ist der Anführer."),
#else
            "These capricious syrpents have\n"
            "banded together. On the rare\n"
            "occasion that their moods align,\n"
            "their true power is unleashed."),
#endif
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hydrapple,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Hydrapple,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Hydrapple,
        .shinyPalette = gMonShinyPalette_Hydrapple,
        .iconSprite = gMonIcon_Hydrapple,
        .iconPalIndex = 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_L)
        FOOTPRINT(Hydrapple)
        OVERWORLD(
            sPicTable_Hydrapple,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hydrapple,
            gShinyOverworldPalette_Hydrapple
        )
        .levelUpLearnset = sHydrappleLevelUpLearnset,
        .teachableLearnset = sHydrappleTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_APPLIN

#if P_FAMILY_SILICOBRA
    [SPECIES_SILICOBRA] =
    {
        .baseHP        = 52,
        .baseAttack    = 57,
        .baseDefense   = 75,
        .baseSpeed     = 46,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 255,
        .expYield = 63,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SAND_SPIT, ABILITY_SHED_SKIN, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Salanga"),
#else
        .speciesName = _("SILICOBRA"),
#endif
        .cryId = CRY_SILICOBRA,
        .natDexNum = NATIONAL_DEX_SILICOBRA,
#if GERMAN
        .categoryName = _("Sandschlange"),
#else
        .categoryName = _("Sand Snake"),
#endif
        .height = 22,
        .weight = 76,
        .description = COMPOUND_STRING(
#if GERMAN
            "Den Sand, den es beim Graben von Löchern\n"
            "verzehrt, speichert es in einem Beutel in\n"
            "seinem Hals. Dieser kann bis zu 8 kg Sand\n"
            "aufnehmen."),
#else
            "As it digs, it swallows sand and stores\n"
            "it in its neck pouch. The pouch can hold\n"
            "more than 17 pounds of sand."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Silicobra,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Silicobra,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Silicobra,
        .shinyPalette = gMonShinyPalette_Silicobra,
        .iconSprite = gMonIcon_Silicobra,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 1, SHADOW_SIZE_M)
        FOOTPRINT(Silicobra)
        OVERWORLD(
            sPicTable_Silicobra,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Silicobra,
            gShinyOverworldPalette_Silicobra
        )
        .levelUpLearnset = sSilicobraLevelUpLearnset,
        .teachableLearnset = sSilicobraTeachableLearnset,
        .eggMoveLearnset = sSilicobraEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SANDACONDA}),
    },

    [SPECIES_SANDACONDA] =
    {
        .baseHP        = 72,
        .baseAttack    = 107,
        .baseDefense   = 125,
        .baseSpeed     = 71,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 120,
        .expYield = 179,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SAND_SPIT, ABILITY_SHED_SKIN, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Sanaconda"),
#else
        .speciesName = _("SANDACONDA"),
#endif
        .cryId = CRY_SANDACONDA,
        .natDexNum = NATIONAL_DEX_SANDACONDA,
#if GERMAN
        .categoryName = _("Sandschlange"),
#else
        .categoryName = _("Sand Snake"),
#endif
        .height = 38,
        .weight = 655,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zieht es seinen ganzen Körper zusammen,\n"
        "kann es 100 kg Sand aus seinen\n"
        "Nasenlöchern feuern. Geht ihm der Sand\n"
        "aus, verliert es den Mut."),
#else
            "When it contracts its body, over 220\n"
            "pounds of sand sprays from its nose. If\n"
            "it ever runs out of sand, it becomes\n"
            "disheartened."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        .frontPic = gMonFrontPic_Sandaconda,
        .frontPicSize = MON_COORDS_SIZE(64, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sandaconda,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sandaconda,
        .shinyPalette = gMonShinyPalette_Sandaconda,
        .iconSprite = gMonIcon_Sandaconda,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, -1, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Sandaconda)
        OVERWORLD(
            sPicTable_Sandaconda,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sandaconda,
            gShinyOverworldPalette_Sandaconda
        )
        .levelUpLearnset = sSandacondaLevelUpLearnset,
        .teachableLearnset = sSandacondaTeachableLearnset,
        .formSpeciesIdTable = sSandacondaFormSpeciesIdTable,
        .formChangeTable = sSandacondaFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_SANDACONDA_GMAX] =
    {
        .baseHP        = 72,
        .baseAttack    = 107,
        .baseDefense   = 125,
        .baseSpeed     = 71,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 120,
        .expYield = 179,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SAND_SPIT, ABILITY_SHED_SKIN, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Sanaconda"),
#else
        .speciesName = _("SANDACONDA"),
#endif
        .cryId = CRY_SANDACONDA,
        .natDexNum = NATIONAL_DEX_SANDACONDA,
#if GERMAN
        .categoryName = _("Sandschlange"),
#else
        .categoryName = _("Sand Snake"),
#endif
        .height = 220,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein Sandbeutel ist auf\n"
        "eine gigantische Größe herangewachsen.\n"
        "Der Wirbel aus Sand, der es\n"
        "umgibt, wiegt mehr als eine Million Tonnen."),
#else
            "Its sand pouch has grown to tremendous\n"
            "proportions. More than 1,000,000 tons of\n"
            "sand now swirl around its body with enough\n"
            "speed and power to pulverize a skyscraper."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        .frontPic = gMonFrontPic_SandacondaGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SandacondaGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SandacondaGmax,
        .shinyPalette = gMonShinyPalette_SandacondaGmax,
        .iconSprite = gMonIcon_SandacondaGmax,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_M)
        FOOTPRINT(Sandaconda)
        .isGigantamax = TRUE,
        .levelUpLearnset = sSandacondaLevelUpLearnset,
        .teachableLearnset = sSandacondaTeachableLearnset,
        .formSpeciesIdTable = sSandacondaFormSpeciesIdTable,
        .formChangeTable = sSandacondaFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SILICOBRA

#if P_FAMILY_CRAMORANT
    [SPECIES_CRAMORANT] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FLYING, TYPE_WATER),
        .catchRate = 45,
        .expYield = 166,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_GULP_MISSILE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Urgl"),
#else
        .speciesName = _("CRAMORANT"),
#endif
        .cryId = CRY_CRAMORANT,
        .natDexNum = NATIONAL_DEX_CRAMORANT,
#if GERMAN
        .categoryName = _("Schling"),
#else
        .categoryName = _("Gulp"),
#endif
        .height = 8,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Urgl ist so stark, dass es seine Gegner\n"
        "mit einem Angriff vernichten könnte,\n"
        "aber zerstreut wie es ist, vergisst\n"
        "es öfters, wen es gerade bekämpft."),
#else
            "It's so strong that it can knock out some\n"
            "opponents in a single hit, but it also may\n"
            "forget what it's battling midfight."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cramorant,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cramorant,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cramorant,
        .shinyPalette = gMonShinyPalette_Cramorant,
        .iconSprite = gMonIcon_Cramorant,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cramorant)
        OVERWORLD(
            sPicTable_Cramorant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cramorant,
            gShinyOverworldPalette_Cramorant
        )
        .levelUpLearnset = sCramorantLevelUpLearnset,
        .teachableLearnset = sCramorantTeachableLearnset,
        .eggMoveLearnset = sCramorantEggMoveLearnset,
        .formSpeciesIdTable = sCramorantFormSpeciesIdTable,
        .formChangeTable = sCramorantFormChangeTable,
    },

    [SPECIES_CRAMORANT_GULPING] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FLYING, TYPE_WATER),
        .catchRate = 45,
        .expYield = 166,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_GULP_MISSILE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Urgl"),
#else
        .speciesName = _("CRAMORANT"),
#endif
        .cryId = CRY_CRAMORANT_GULPING,
        .natDexNum = NATIONAL_DEX_CRAMORANT,
#if GERMAN
        .categoryName = _("Schling"),
#else
        .categoryName = _("Gulp"),
#endif
        .height = 8,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seine Fressgier verleitete es dazu, ein\n"
        "besonders großes Pikuda mit einem Happs\n"
        "zu vertilgen, welches ihm leider im Hals\n"
        "stecken blieb."),
#else
            "Cramorant's gluttony led it to try\n"
            "to swallow an Arrokuda whole, which\n"
            "in turn led to Cramorant getting an\n"
            "Arrokuda stuck in its throat."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CramorantGulping,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CramorantGulping,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CramorantGulping,
        .shinyPalette = gMonShinyPalette_CramorantGulping,
        .iconSprite = gMonIcon_CramorantGulping,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cramorant)
        .levelUpLearnset = sCramorantLevelUpLearnset,
        .teachableLearnset = sCramorantTeachableLearnset,
        .eggMoveLearnset = sCramorantEggMoveLearnset,
        .formSpeciesIdTable = sCramorantFormSpeciesIdTable,
        .formChangeTable = sCramorantGulpMissleFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_CRAMORANT_GORGING] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_FLYING, TYPE_WATER),
        .catchRate = 45,
        .expYield = 166,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_GULP_MISSILE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Urgl"),
#else
        .speciesName = _("CRAMORANT"),
#endif
        .cryId = CRY_CRAMORANT_GULPING,
        .natDexNum = NATIONAL_DEX_CRAMORANT,
#if GERMAN
        .categoryName = _("Schling"),
#else
        .categoryName = _("Gulp"),
#endif
        .height = 8,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es verschluckte versehentlich\n"
        "ein Pikachu, das ihm in der Kehle stecken\n"
        "blieb und nun das Schlucken erschwert.\n"
        "Allerdings stört Urgl das nur wenig."),
#else
            "This Cramorant has accidentally\n"
            "gotten a Pikachu lodged in its gullet.\n"
            "Cramorant is choking a little, but it\n"
            "isn't really bothered."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CramorantGorging,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CramorantGorging,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CramorantGorging,
        .shinyPalette = gMonShinyPalette_CramorantGorging,
        .iconSprite = gMonIcon_CramorantGorging,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cramorant)
        .levelUpLearnset = sCramorantLevelUpLearnset,
        .teachableLearnset = sCramorantTeachableLearnset,
        .eggMoveLearnset = sCramorantEggMoveLearnset,
        .formSpeciesIdTable = sCramorantFormSpeciesIdTable,
        .formChangeTable = sCramorantGulpMissleFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_CRAMORANT

#if P_FAMILY_ARROKUDA
    [SPECIES_ARROKUDA] =
    {
        .baseHP        = 41,
        .baseAttack    = 63,
        .baseDefense   = 40,
        .baseSpeed     = 66,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_PROPELLER_TAIL },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Pikuda"),
#else
        .speciesName = _("ARROKUDA"),
#endif
        .cryId = CRY_ARROKUDA,
        .natDexNum = NATIONAL_DEX_ARROKUDA,
#if GERMAN
        .categoryName = _("Rempler"),
#else
        .categoryName = _("Rush"),
#endif
        .height = 5,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
        "Pikudas spitz zulaufender Kiefer\n"
        "ist sein ganzer Stolz. Erblickt es etwas,\n"
        "das sich auch nur ein bisschen bewegt,\n"
        "setzt es geradewegs zum Stoßangriff an."),
#else
            "If it sees any movement around it, this\n"
            "Pokémon charges for it straightaway,\n"
            "leading with its sharply pointed jaw.\n"
            "It's very proud of that jaw."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Arrokuda,
        .frontPicSize = MON_COORDS_SIZE(56, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Arrokuda,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Arrokuda,
        .shinyPalette = gMonShinyPalette_Arrokuda,
        .iconSprite = gMonIcon_Arrokuda,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, -5, SHADOW_SIZE_S)
        FOOTPRINT(Arrokuda)
        OVERWORLD(
            sPicTable_Arrokuda,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Arrokuda,
            gShinyOverworldPalette_Arrokuda
        )
        .levelUpLearnset = sArrokudaLevelUpLearnset,
        .teachableLearnset = sArrokudaTeachableLearnset,
        .eggMoveLearnset = sArrokudaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_BARRASKEWDA}),
    },

    [SPECIES_BARRASKEWDA] =
    {
        .baseHP        = 61,
        .baseAttack    = 123,
        .baseDefense   = 60,
        .baseSpeed     = 136,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 60,
        .expYield = 172,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_PROPELLER_TAIL },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Barrakiefa"),
#else
        .speciesName = _("BARRASKEWDA"),
#endif
        .cryId = CRY_BARRASKEWDA,
        .natDexNum = NATIONAL_DEX_BARRASKEWDA,
#if GERMAN
        .categoryName = _("Spieß"),
#else
        .categoryName = _("Skewer"),
#endif
        .height = 13,
        .weight = 300,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein Kiefer ist spitz wie ein\n"
        "Speer und hart wie Stahl. Außerdem soll\n"
        "Barrakiefa überraschend deliziös sein."),
#else
            "This Pokémon has a jaw that's as sharp\n"
            "as a spear and as strong as steel.\n"
            "Apparently Barraskewda's flesh is\n"
            "surprisingly tasty, too."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Barraskewda,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Barraskewda,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Barraskewda,
        .shinyPalette = gMonShinyPalette_Barraskewda,
        .iconSprite = gMonIcon_Barraskewda,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 5, SHADOW_SIZE_M)
        FOOTPRINT(Barraskewda)
        OVERWORLD(
            sPicTable_Barraskewda,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Barraskewda,
            gShinyOverworldPalette_Barraskewda
        )
        .levelUpLearnset = sBarraskewdaLevelUpLearnset,
        .teachableLearnset = sBarraskewdaTeachableLearnset,
    },
#endif //P_FAMILY_ARROKUDA

#if P_FAMILY_TOXEL
    [SPECIES_TOXEL] =
    {
        .baseHP        = 40,
        .baseAttack    = 38,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 54,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_POISON),
        .catchRate = 75,
        .expYield = 48,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_RATTLED, ABILITY_STATIC, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Toxel"),
#else
        .speciesName = _("TOXEL"),
#endif
        .cryId = CRY_TOXEL,
        .natDexNum = NATIONAL_DEX_TOXEL,
        .categoryName = _("Baby"),
        .height = 4,
        .weight = 110,
        .description = COMPOUND_STRING(
#if GERMAN
        "Das Gift aus dem Giftsack in seinem Körper\n"
        "sondert es über die Haut ab. Berührt man\n"
        "es, bekommt man einen lähmenden Schock\n"
        "verpasst."),
#else
            "It stores poison in an internal poison\n"
            "sac and secretes that poison through its\n"
            "skin. If you touch this Pokémon, a\n"
            "tingling sensation follows."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Toxel,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Toxel,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Toxel,
        .shinyPalette = gMonShinyPalette_Toxel,
        .iconSprite = gMonIcon_Toxel,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, 1, SHADOW_SIZE_M)
        FOOTPRINT(Toxel)
        OVERWORLD(
            sPicTable_Toxel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Toxel,
            gShinyOverworldPalette_Toxel
        )
        .levelUpLearnset = sToxelLevelUpLearnset,
        .teachableLearnset = sToxelTeachableLearnset,
        .eggMoveLearnset = sToxelEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_TOXTRICITY_AMPED, CONDITIONS({IF_AMPED_NATURE})},
                                {EVO_LEVEL, 30, SPECIES_TOXTRICITY_LOW_KEY, CONDITIONS({IF_LOW_KEY_NATURE})}),
    },

    [SPECIES_TOXTRICITY_AMPED] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 70,
        .baseSpeed     = 75,
        .baseSpAttack  = 114,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_POISON),
        .catchRate = 45,
        .expYield = 176,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_PLUS, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Riffex"),
#else
        .speciesName = _("TOXTRICITY"),
#endif
        .cryId = CRY_TOXTRICITY_AMPED,
        .natDexNum = NATIONAL_DEX_TOXTRICITY,
        .categoryName = _("Punk"),
        .height = 16,
        .weight = 400,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wenn es am Fortsatz an seiner Brust\n"
        "kratzt und dadurch Strom erzeugt, dann\n"
        "erklingt in der Umgebung ein Ton wie von\n"
        "einer Gitarre."),
#else
            "When this Pokémon sounds as if it's\n"
            "strumming a guitar, it's actually clawing\n"
            "at the protrusions on its chest to\n"
            "generate electricity."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_ToxtricityAmped,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ToxtricityAmped,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ToxtricityAmped,
        .shinyPalette = gMonShinyPalette_ToxtricityAmped,
        .iconSprite = gMonIcon_ToxtricityAmped,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 13, SHADOW_SIZE_M)
        FOOTPRINT(Toxtricity)
        OVERWORLD(
            sPicTable_ToxtricityAmped,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ToxtricityAmped,
            gShinyOverworldPalette_ToxtricityAmped
        )
        .levelUpLearnset = sToxtricityAmpedLevelUpLearnset,
        .teachableLearnset = sToxtricityAmpedTeachableLearnset,
        .formSpeciesIdTable = sToxtricityFormSpeciesIdTable,
        .formChangeTable = sToxtricityAmpedFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_TOXTRICITY_AMPED_GMAX] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 70,
        .baseSpeed     = 75,
        .baseSpAttack  = 114,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_POISON),
        .catchRate = 45,
        .expYield = 176,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_PLUS, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Riffex"),
#else
        .speciesName = _("TOXTRICITY"),
#endif
        .cryId = CRY_TOXTRICITY_AMPED,
        .natDexNum = NATIONAL_DEX_TOXTRICITY,
        .categoryName = _("Punk"),
        .height = 240,
        .weight = 0,
        .description = gToxtricityGigantamaxPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_ToxtricityGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ToxtricityGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ToxtricityGmax,
        .shinyPalette = gMonShinyPalette_ToxtricityGmax,
        .iconSprite = gMonIcon_ToxtricityGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Toxtricity)
        .isGigantamax = TRUE,
        .levelUpLearnset = sToxtricityAmpedLevelUpLearnset,
        .teachableLearnset = sToxtricityAmpedTeachableLearnset,
        .formSpeciesIdTable = sToxtricityFormSpeciesIdTable,
        .formChangeTable = sToxtricityAmpedFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS

    [SPECIES_TOXTRICITY_LOW_KEY] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 70,
        .baseSpeed     = 75,
        .baseSpAttack  = 114,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_POISON),
        .catchRate = 45,
        .expYield = 176,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_MINUS, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Riffex"),
#else
        .speciesName = _("TOXTRICITY"),
#endif
        .cryId = CRY_TOXTRICITY_LOW_KEY,
        .natDexNum = NATIONAL_DEX_TOXTRICITY,
        .categoryName = _("Punk"),
        .height = 16,
        .weight = 400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dieses Pokémon kann 15 000 V starke\n"
            "Elektrizität generieren. Es nimmt keinen\n"
            "Gegner wirklich ernst."),
#else
            "Capable of generating 15,000 volts\n"
            "of electricity, this Pokémon looks\n"
            "down on all that would challenge it."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_ToxtricityLowKey,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ToxtricityLowKey,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ToxtricityLowKey,
        .shinyPalette = gMonShinyPalette_ToxtricityLowKey,
        .iconSprite = gMonIcon_ToxtricityLowKey,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Toxtricity)
        OVERWORLD(
            sPicTable_ToxtricityLowKey,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ToxtricityLowKey,
            gShinyOverworldPalette_ToxtricityLowKey
        )
        .levelUpLearnset = sToxtricityLowKeyLevelUpLearnset,
        .teachableLearnset = sToxtricityLowKeyTeachableLearnset,
        .formSpeciesIdTable = sToxtricityFormSpeciesIdTable,
        .formChangeTable = sToxtricityAmpedFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_TOXTRICITY_LOW_KEY_GMAX] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 70,
        .baseSpeed     = 75,
        .baseSpAttack  = 114,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_POISON),
        .catchRate = 45,
        .expYield = 176,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_MINUS, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Riffex"),
#else
        .speciesName = _("TOXTRICITY"),
#endif
        .cryId = CRY_TOXTRICITY_LOW_KEY,
        .natDexNum = NATIONAL_DEX_TOXTRICITY,
        .categoryName = _("Punk"),
        .height = 240,
        .weight = 0,
        .description = gToxtricityGigantamaxPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_ToxtricityGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ToxtricityGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ToxtricityGmax,
        .shinyPalette = gMonShinyPalette_ToxtricityGmax,
        .iconSprite = gMonIcon_ToxtricityGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Toxtricity)
        .isGigantamax = TRUE,
        .levelUpLearnset = sToxtricityLowKeyLevelUpLearnset,
        .teachableLearnset = sToxtricityLowKeyTeachableLearnset,
        .formSpeciesIdTable = sToxtricityFormSpeciesIdTable,
        .formChangeTable = sToxtricityAmpedFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_TOXEL

#if P_FAMILY_SIZZLIPEDE
    [SPECIES_SIZZLIPEDE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIRE, TYPE_BUG),
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Thermopod"),
#else
        .speciesName = _("SIZZLIPEDE"),
#endif
        .cryId = CRY_SIZZLIPEDE,
        .natDexNum = NATIONAL_DEX_SIZZLIPEDE,
#if GERMAN
        .categoryName = _("Exotherm"),
#else
        .categoryName = _("Radiator"),
#endif
        .height = 7,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit dem entzündlichen Gas in seinem Körper\n"
        "erzeugt es Hitze. Die gelben Stellen an\n"
        "seinem Bauch werden besonders heiß."),
#else
            "It stores flammable gas in its body and\n"
            "uses it to generate heat. The yellow\n"
            "sections on its belly get particularly hot."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sizzlipede,
        .frontPicSize = MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Sizzlipede,
        .backPicSize = MON_COORDS_SIZE(40, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sizzlipede,
        .shinyPalette = gMonShinyPalette_Sizzlipede,
        .iconSprite = gMonIcon_Sizzlipede,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(6, -4, SHADOW_SIZE_S)
        FOOTPRINT(Sizzlipede)
        OVERWORLD(
            sPicTable_Sizzlipede,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sizzlipede,
            gShinyOverworldPalette_Sizzlipede
        )
        .levelUpLearnset = sSizzlipedeLevelUpLearnset,
        .teachableLearnset = sSizzlipedeTeachableLearnset,
        .eggMoveLearnset = sSizzlipedeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_CENTISKORCH}),
    },

    [SPECIES_CENTISKORCH] =
    {
        .baseHP        = 100,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FIRE, TYPE_BUG),
        .catchRate = 75,
        .expYield = 184,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Infernopod"),
#else
        .speciesName = _("CENTISKORCH"),
#endif
        .cryId = CRY_CENTISKORCH,
        .natDexNum = NATIONAL_DEX_CENTISKORCH,
#if GERMAN
        .categoryName = _("Exotherm"),
#else
        .categoryName = _("Radiator"),
#endif
        .height = 30,
        .weight = 1200,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wenn es Hitze erzeugt, beträgt seine\n"
        "Temperatur etwa 800 ºC. Es bewegt seinen\n"
        "Körper wie eine Peitsche, um dann den\n"
        "Gegner anzuspringen."),
#else
            "When it heats up, its body temperature\n"
            "reaches about 1,500 degrees Fahrenheit.\n"
            "It lashes its body like a whip and\n"
            "launches itself at enemies."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Centiskorch,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 1),
        ),
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Centiskorch,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Centiskorch,
        .shinyPalette = gMonShinyPalette_Centiskorch,
        .iconSprite = gMonIcon_Centiskorch,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 7, SHADOW_SIZE_M)
        FOOTPRINT(Centiskorch)
        OVERWORLD(
            sPicTable_Centiskorch,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Centiskorch,
            gShinyOverworldPalette_Centiskorch
        )
        .levelUpLearnset = sCentiskorchLevelUpLearnset,
        .teachableLearnset = sCentiskorchTeachableLearnset,
        .formSpeciesIdTable = sCentiskorchFormSpeciesIdTable,
        .formChangeTable = sCentiskorchFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_CENTISKORCH_GMAX] =
    {
        .baseHP        = 100,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 90,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FIRE, TYPE_BUG),
        .catchRate = 75,
        .expYield = 184,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Infernopod"),
#else
        .speciesName = _("CENTISKORCH"),
#endif
        .cryId = CRY_CENTISKORCH,
        .natDexNum = NATIONAL_DEX_CENTISKORCH,
#if GERMAN
        .categoryName = _("Exotherm"),
#else
        .categoryName = _("Radiator"),
#endif
        .height = 750,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Gigadynamax-Energie\n"
        "wurde seine Körpertemperatur\n"
        "auf über 1 000 Grad erhitzt. Mit seinen\n"
        "Hitzewellen röstet es seine Gegner."),
#else
            "The heat that comes off a\n"
            "Gigantamax Centiskorch may\n"
            "destabilize air currents. Sometimes\n"
            "it can even cause storms."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CentiskorchGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CentiskorchGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CentiskorchGmax,
        .shinyPalette = gMonShinyPalette_CentiskorchGmax,
        .iconSprite = gMonIcon_CentiskorchGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 9, SHADOW_SIZE_L)
        FOOTPRINT(Centiskorch)
        .isGigantamax = TRUE,
        .levelUpLearnset = sCentiskorchLevelUpLearnset,
        .teachableLearnset = sCentiskorchTeachableLearnset,
        .formSpeciesIdTable = sCentiskorchFormSpeciesIdTable,
        .formChangeTable = sCentiskorchFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SIZZLIPEDE

#if P_FAMILY_CLOBBOPUS
    [SPECIES_CLOBBOPUS] =
    {
        .baseHP        = 50,
        .baseAttack    = 68,
        .baseDefense   = 60,
        .baseSpeed     = 32,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 180,
        .expYield = 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Klopptopus"),
#else
        .speciesName = _("CLOBBOPUS"),
#endif
        .cryId = CRY_CLOBBOPUS,
        .natDexNum = NATIONAL_DEX_CLOBBOPUS,
#if GERMAN
        .categoryName = _("Balg"),
#else
        .categoryName = _("Tantrum"),
#endif
        .height = 6,
        .weight = 40,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zur Futtersuche kommt es an Land. Es ist\n"
        "sehr neugierig, weshalb es alles, was es\n"
        "sieht, zunächst einmal mit seinen\n"
        "Tentakeln haut."),
#else
            "It's very curious, but its means of\n"
            "investigating things is to try to punch\n"
            "them with its tentacles. The search for\n"
            "food is what brings it onto land."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Clobbopus,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Clobbopus,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Clobbopus,
        .shinyPalette = gMonShinyPalette_Clobbopus,
        .iconSprite = gMonIcon_Clobbopus,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Clobbopus)
        OVERWORLD(
            sPicTable_Clobbopus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Clobbopus,
            gShinyOverworldPalette_Clobbopus
        )
        .levelUpLearnset = sClobbopusLevelUpLearnset,
        .teachableLearnset = sClobbopusTeachableLearnset,
        .eggMoveLearnset = sClobbopusEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_GRAPPLOCT, CONDITIONS({IF_KNOWS_MOVE, MOVE_TAUNT})}),
    },

    [SPECIES_GRAPPLOCT] =
    {
        .baseHP        = 80,
        .baseAttack    = 118,
        .baseDefense   = 90,
        .baseSpeed     = 42,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kaocto"),
#else
        .speciesName = _("GRAPPLOCT"),
#endif
        .cryId = CRY_GRAPPLOCT,
        .natDexNum = NATIONAL_DEX_GRAPPLOCT,
#if GERMAN
        .categoryName = _("Jiu-Jitsu"),
#else
        .categoryName = _("Jujitsu"),
#endif
        .height = 16,
        .weight = 390,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kaoctos Körper besteht gänzlich aus\n"
        "Muskeln. Die schiere Stärke seines\n"
        "Würgegriffs, bei dem es seine Tentakel\n"
        "einsetzt, ist sagenhaft."),
#else
            "A body made up of nothing but muscle makes\n"
            "the grappling moves this Pokémon performs\n"
            "with its tentacles tremendously powerful."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Grapploct,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Grapploct,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Grapploct,
        .shinyPalette = gMonShinyPalette_Grapploct,
        .iconSprite = gMonIcon_Grapploct,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 9, SHADOW_SIZE_M)
        FOOTPRINT(Grapploct)
        OVERWORLD(
            sPicTable_Grapploct,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Grapploct,
            gShinyOverworldPalette_Grapploct
        )
        .levelUpLearnset = sGrapploctLevelUpLearnset,
        .teachableLearnset = sGrapploctTeachableLearnset,
    },
#endif //P_FAMILY_CLOBBOPUS

#if P_FAMILY_SINISTEA
    [SPECIES_SINISTEA_PHONY] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 74,
        .baseSpDefense = 54,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 120,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Fatalitee"),
#else
        .speciesName = _("SINISTEA"),
#endif
        .cryId = CRY_SINISTEA,
        .natDexNum = NATIONAL_DEX_SINISTEA,
#if GERMAN
        .categoryName = _("Schwarztee"),
#else
        .categoryName = _("Black Tea"),
#endif
        .height = 1,
        .weight = 2,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es heißt, eine einsame Seele habe Besitz\n"
        "von einer abgestellten, kalten Tasse\n"
        "Schwarztee ergriffen und sei zu diesem\n"
        "Pokémon geworden."),
#else
            "This Pokémon is said to have been born\n"
            "when a lonely spirit possessed a cold,\n"
            "leftover cup of tea."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sinistea,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 9,
        .backPic = gMonBackPic_Sinistea,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sinistea,
        .shinyPalette = gMonShinyPalette_Sinistea,
        .iconSprite = gMonIcon_Sinistea,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 3, SHADOW_SIZE_S)
        FOOTPRINT(Sinistea)
        OVERWORLD(
            sPicTable_Sinistea,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sinistea,
            gShinyOverworldPalette_Sinistea
        )
        .levelUpLearnset = sSinisteaLevelUpLearnset,
        .teachableLearnset = sSinisteaTeachableLearnset,
        .formSpeciesIdTable = sSinisteaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_POLTEAGEIST_PHONY},
                                {EVO_ITEM, ITEM_CRACKED_POT, SPECIES_POLTEAGEIST_PHONY}),
        .randomizerMode = MON_RANDOMIZER_SPECIAL_FORM,
    },

    [SPECIES_SINISTEA_ANTIQUE] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 74,
        .baseSpDefense = 54,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 120,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Fatalitee"),
#else
        .speciesName = _("SINISTEA"),
#endif
        .cryId = CRY_SINISTEA,
        .natDexNum = NATIONAL_DEX_SINISTEA,
#if GERMAN
        .categoryName = _("Schwarztee"),
#else
        .categoryName = _("Black Tea"),
#endif
        .height = 1,
        .weight = 2,
        .description = COMPOUND_STRING(
#if GERMAN
        "Der Wirbel auf seinem Körper aus Tee ist\n"
        "seine Schwachstelle. Rührt man diesen um,\n"
        "verliert er seine Form, wodurch Fatalitee\n"
        "schwindlig wird."),
#else
            "The swirl pattern in this Pokémon's\n"
            "body is its weakness. If it gets\n"
            "stirred, the swirl loses its shape, and\n"
            "Sinistea gets dizzy."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sinistea,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Sinistea,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Sinistea,
        .shinyPalette = gMonShinyPalette_Sinistea,
        .iconSprite = gMonIcon_Sinistea,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 4, SHADOW_SIZE_S)
        FOOTPRINT(Sinistea)
        OVERWORLD(
            sPicTable_Sinistea,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sinistea,
            gShinyOverworldPalette_Sinistea
        )
        .levelUpLearnset = sSinisteaLevelUpLearnset,
        .teachableLearnset = sSinisteaTeachableLearnset,
        .formSpeciesIdTable = sSinisteaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_REAPER_CLOTH, SPECIES_POLTEAGEIST_ANTIQUE},
                                {EVO_ITEM, ITEM_CHIPPED_POT, SPECIES_POLTEAGEIST_ANTIQUE}),
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_POLTEAGEIST_PHONY] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 134,
        .baseSpDefense = 114,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 60,
        .expYield = 178,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Mortipot"),
#else
        .speciesName = _("POLTEAGEIST"),
#endif
        .cryId = CRY_POLTEAGEIST,
        .natDexNum = NATIONAL_DEX_POLTEAGEIST,
#if GERMAN
        .categoryName = _("Schwarztee"),
#else
        .categoryName = _("Black Tea"),
#endif
        .height = 2,
        .weight = 4,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sie lassen sich in alten\n"
        "Teekannen nieder. Die meisten dieser\n"
        "Kannen sind billige Fälschungen, aber es\n"
        "gibt auch ein paar sehr seltene Originale."),
#else
            "This species lives in antique teapots.\n"
            "Most pots are forgeries, but on rare\n"
            "occasions, an authentic work is found."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Polteageist,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 12,
        .backPic = gMonBackPic_Polteageist,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Polteageist,
        .shinyPalette = gMonShinyPalette_Polteageist,
        .iconSprite = gMonIcon_Polteageist,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_S)
        FOOTPRINT(Polteageist)
        OVERWORLD(
            sPicTable_Polteageist,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Polteageist,
            gShinyOverworldPalette_Polteageist
        )
        .levelUpLearnset = sPolteageistLevelUpLearnset,
        .teachableLearnset = sPolteageistTeachableLearnset,
        .formSpeciesIdTable = sPolteageistFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_SPECIAL_FORM,
    },

    [SPECIES_POLTEAGEIST_ANTIQUE] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 134,
        .baseSpDefense = 114,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 60,
        .expYield = 178,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Mortipot"),
#else
        .speciesName = _("POLTEAGEIST"),
#endif
        .cryId = CRY_POLTEAGEIST,
        .natDexNum = NATIONAL_DEX_POLTEAGEIST,
#if GERMAN
        .categoryName = _("Schwarztee"),
#else
        .categoryName = _("Black Tea"),
#endif
        .height = 2,
        .weight = 4,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es schmeckt und riecht sehr markant. Wenn\n"
        "es seinem Trainer vertraut, lässt es ihn\n"
        "manchmal ein klitzekleines Schlückchen\n"
        "probieren."),
#else
            "Trainers Polteageist trusts will be\n"
            "allowed to experience its\n"
            "distinctive flavor and aroma firsthand by\n"
            "sampling just a tiny bit of its tea."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Polteageist,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 11,
        .backPic = gMonBackPic_Polteageist,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Polteageist,
        .shinyPalette = gMonShinyPalette_Polteageist,
        .iconSprite = gMonIcon_Polteageist,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_S)
        FOOTPRINT(Polteageist)
        OVERWORLD(
            sPicTable_Polteageist,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Polteageist,
            gShinyOverworldPalette_Polteageist
        )
        .levelUpLearnset = sPolteageistLevelUpLearnset,
        .teachableLearnset = sPolteageistTeachableLearnset,
        .formSpeciesIdTable = sPolteageistFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_SINISTEA

#if P_FAMILY_HATENNA
    [SPECIES_HATENNA] =
    {
        .baseHP        = 42,
        .baseAttack    = 30,
        .baseDefense   = 45,
        .baseSpeed     = 39,
        .baseSpAttack  = 56,
        .baseSpDefense = 53,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 235,
        .expYield = 53,
        .evYield_SpAttack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Brimova"),
#else
        .speciesName = _("HATENNA"),
#endif
        .cryId = CRY_HATENNA,
        .natDexNum = NATIONAL_DEX_HATENNA,
#if GERMAN
        .categoryName = _("Geruhsam"),
#else
        .categoryName = _("Calm"),
#endif
        .height = 4,
        .weight = 34,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit dem Fortsatz an seinem Kopf kann es\n"
        "die Gefühle von Lebewesen wahrnehmen. Es\n"
        "öffnet nur geruhsam veranlagten Leuten\n"
        "sein Herz."),
#else
            "Via the protrusion on its head, it senses\n"
            "other creatures' emotions. If you don't\n"
            "have a calm disposition, it will never\n"
            "warm up to you."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hatenna,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Hatenna,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Hatenna,
        .shinyPalette = gMonShinyPalette_Hatenna,
        .iconSprite = gMonIcon_Hatenna,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 1, SHADOW_SIZE_M)
        FOOTPRINT(Hatenna)
        OVERWORLD(
            sPicTable_Hatenna,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hatenna,
            gShinyOverworldPalette_Hatenna
        )
        .levelUpLearnset = sHatennaLevelUpLearnset,
        .teachableLearnset = sHatennaTeachableLearnset,
        .eggMoveLearnset = sHatennaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_HATTREM}),
    },

    [SPECIES_HATTREM] =
    {
        .baseHP        = 57,
        .baseAttack    = 40,
        .baseDefense   = 65,
        .baseSpeed     = 49,
        .baseSpAttack  = 86,
        .baseSpDefense = 73,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 120,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Brimano"),
#else
        .speciesName = _("HATTREM"),
#endif
        .cryId = CRY_HATTREM,
        .natDexNum = NATIONAL_DEX_HATTREM,
#if GERMAN
        .categoryName = _("Ruhe"),
#else
        .categoryName = _("Serene"),
#endif
        .height = 6,
        .weight = 48,
        .description = COMPOUND_STRING(
#if GERMAN
        "Empfindet jemand starke Emotionen, bringt\n"
        "es ihn auf gewaltsame Art zum Schweigen,\n"
        "egal, um wen es sich dabei handelt."),
#else
            "No matter who you are, if you bring strong\n"
            "emotions near this Pokémon, it will silence\n"
            "you violently."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hattrem,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Hattrem,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Hattrem,
        .shinyPalette = gMonShinyPalette_Hattrem,
        .iconSprite = gMonIcon_Hattrem,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 5, SHADOW_SIZE_M)
        FOOTPRINT(Hattrem)
        OVERWORLD(
            sPicTable_Hattrem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hattrem,
            gShinyOverworldPalette_Hattrem
        )
        .levelUpLearnset = sHattremLevelUpLearnset,
        .teachableLearnset = sHattremTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_HATTERENE}),
    },

    [SPECIES_HATTERENE] =
    {
        .baseHP        = 57,
        .baseAttack    = 90,
        .baseDefense   = 95,
        .baseSpeed     = 29,
        .baseSpAttack  = 136,
        .baseSpDefense = 103,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 255,
        .evYield_SpAttack = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Silembrim"),
#else
        .speciesName = _("HATTERENE"),
#endif
        .cryId = CRY_HATTERENE,
        .natDexNum = NATIONAL_DEX_HATTERENE,
#if GERMAN
        .categoryName = _("Stille"),
#else
        .categoryName = _("Silent"),
#endif
        .height = 21,
        .weight = 51,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die starken Psycho-Kräfte, die es\n"
        "ausstrahlt, rufen Kopfschmerzen hervor.\n"
        "So hält es andere Lebewesen von sich fern."),
#else
            "It emits psychic power strong enough to\n"
            "cause headaches as a deterrent to the\n"
            "approach of others."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Hatterene,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Hatterene,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Hatterene,
        .shinyPalette = gMonShinyPalette_Hatterene,
        .iconSprite = gMonIcon_Hatterene,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 13, SHADOW_SIZE_S)
        FOOTPRINT(Hatterene)
        OVERWORLD(
            sPicTable_Hatterene,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hatterene,
            gShinyOverworldPalette_Hatterene
        )
        .levelUpLearnset = sHattereneLevelUpLearnset,
        .teachableLearnset = sHattereneTeachableLearnset,
        .formSpeciesIdTable = sHattereneFormSpeciesIdTable,
        .formChangeTable = sHattereneFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_HATTERENE_GMAX] =
    {
        .baseHP        = 57,
        .baseAttack    = 90,
        .baseDefense   = 95,
        .baseSpeed     = 29,
        .baseSpAttack  = 136,
        .baseSpDefense = 103,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 255,
        .evYield_SpAttack = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Silembrim"),
#else
        .speciesName = _("HATTERENE"),
#endif
        .cryId = CRY_HATTERENE,
        .natDexNum = NATIONAL_DEX_HATTERENE,
#if GERMAN
        .categoryName = _("Stille"),
#else
        .categoryName = _("Silent"),
#endif
        .height = 260,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es nimmt Gefühlsregungen\n"
        "von Lebewesen wahr, die sich in einem\n"
        "Umkreis von 50 km befinden. Spürt es\n"
        "Feindseligkeit, geht es zum Angriff über."),
#else
            "This Pokémon can read the\n"
            "emotions of creatures over 30 miles away.\n"
            "The minute it senses hostility, it\n"
            "goes on the attack."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_HattereneGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_HattereneGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_HattereneGmax,
        .shinyPalette = gMonShinyPalette_HattereneGmax,
        .iconSprite = gMonIcon_HattereneGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 13, SHADOW_SIZE_S)
        FOOTPRINT(Hatterene)
        .isGigantamax = TRUE,
        .levelUpLearnset = sHattereneLevelUpLearnset,
        .teachableLearnset = sHattereneTeachableLearnset,
        .formSpeciesIdTable = sHattereneFormSpeciesIdTable,
        .formChangeTable = sHattereneFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_HATENNA

#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_DARK, TYPE_FAIRY),
        .catchRate = 255,
        .expYield = 53,
        .evYield_SpAttack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Bähmon"),
#else
        .speciesName = _("IMPIDIMP"),
#endif
        .cryId = CRY_IMPIDIMP,
        .natDexNum = NATIONAL_DEX_IMPIDIMP,
#if GERMAN
        .categoryName = _("Hinterlist"),
#else
        .categoryName = _("Wily"),
#endif
        .height = 4,
        .weight = 55,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bähmon wird kräftiger, indem es die von\n"
            "unzufriedenen Menschen und Pokémon\n"
            "ausgestoßene negative Energie einatmet."),
#else
            "Through its nose, it sucks in the\n"
            "emanations produced by people and\n"
            "Pokémon when they feel annoyed. It\n"
            "thrives off this negative energy."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Impidimp,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Impidimp,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Impidimp,
        .shinyPalette = gMonShinyPalette_Impidimp,
        .iconSprite = gMonIcon_Impidimp,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Impidimp)
        OVERWORLD(
            sPicTable_Impidimp,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Impidimp,
            gShinyOverworldPalette_Impidimp
        )
        .levelUpLearnset = sImpidimpLevelUpLearnset,
        .teachableLearnset = sImpidimpTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_MORGREM}),
    },

    [SPECIES_MORGREM] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 75,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_DARK, TYPE_FAIRY),
        .catchRate = 120,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Pelzebub"),
#else
        .speciesName = _("MORGREM"),
#endif
        .cryId = CRY_MORGREM,
        .natDexNum = NATIONAL_DEX_MORGREM,
#if GERMAN
        .categoryName = _("Schelm"),
#else
        .categoryName = _("Devious"),
#endif
        .height = 8,
        .weight = 125,
        .description = COMPOUND_STRING(
#if GERMAN
        "Pelzebub nutzt eine Taktik,\n"
        "bei der es sich niederwirft und vorgibt,\n"
        "sich zu entschuldigen, nur um dann\n"
        "mit seinem speerartigen Haar zuzustoßen."),
#else
            "When it gets down on all fours as if to\n"
            "beg for forgiveness, it's trying to lure\n"
            "opponents in so that it can stab them\n"
            "with its spear-like hair."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Morgrem,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Morgrem,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Morgrem,
        .shinyPalette = gMonShinyPalette_Morgrem,
        .iconSprite = gMonIcon_Morgrem,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 7, SHADOW_SIZE_M)
        FOOTPRINT(Morgrem)
        OVERWORLD(
            sPicTable_Morgrem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Morgrem,
            gShinyOverworldPalette_Morgrem
        )
        .levelUpLearnset = sMorgremLevelUpLearnset,
        .teachableLearnset = sMorgremTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_GRIMMSNARL}),
    },


    [SPECIES_GRIMMSNARL] =
    {
        .baseHP        = 95,
        .baseAttack    = 120,
        .baseDefense   = 65,
        .baseSpeed     = 60,
        .baseSpAttack  = 95,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_DARK, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 255,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Olangaar"),
#else
        .speciesName = _("GRIMMSNARL"),
#endif
        .cryId = CRY_GRIMMSNARL,
        .natDexNum = NATIONAL_DEX_GRIMMSNARL,
#if GERMAN
        .categoryName = _("Muskelaufbau"),
#else
        .categoryName = _("Bulk Up"),
#endif
        .height = 15,
        .weight = 610,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wickelt es seine Haare um den ganzen\n"
        "Körper, verstärkt dies seine Muskelkraft.\n"
        "Das macht es so stark, dass es sogar\n"
        "Machomei bezwingen könnte."),
#else
            "With the hair wrapped around its body\n"
            "helping to enhance its muscles, this\n"
            "Pokémon can overwhelm even Machamp."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Grimmsnarl,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Grimmsnarl,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Grimmsnarl,
        .shinyPalette = gMonShinyPalette_Grimmsnarl,
        .iconSprite = gMonIcon_Grimmsnarl,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Grimmsnarl)
        OVERWORLD(
            sPicTable_Grimmsnarl,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Grimmsnarl,
            gShinyOverworldPalette_Grimmsnarl
        )
        .levelUpLearnset = sGrimmsnarlLevelUpLearnset,
        .teachableLearnset = sGrimmsnarlTeachableLearnset,
        .formSpeciesIdTable = sGrimmsnarlFormSpeciesIdTable,
        .formChangeTable = sGrimmsnarlFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_GRIMMSNARL_GMAX] =
    {
        .baseHP        = 95,
        .baseAttack    = 120,
        .baseDefense   = 65,
        .baseSpeed     = 60,
        .baseSpAttack  = 95,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_DARK, TYPE_FAIRY),
        .catchRate = 45,
        .expYield = 255,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Olangaar"),
#else
        .speciesName = _("GRIMMSNARL"),
#endif
        .cryId = CRY_GRIMMSNARL,
        .natDexNum = NATIONAL_DEX_GRIMMSNARL,
#if GERMAN
        .categoryName = _("Muskelaufbau"),
#else
        .categoryName = _("Bulk Up"),
#endif
        .height = 320,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Gigadynamax-Energie hat sich\n"
        "sein gesamtes Haarvolumen vervielfacht.\n"
        "Es kann selbst über die höchsten Gebäude\n"
        "springen."),
#else
            "Gigantamax energy has caused more\n"
            "hair to sprout all over its body.\n"
            "With the added strength, it can jump\n"
            "over the world's tallest building."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_GrimmsnarlGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GrimmsnarlGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GrimmsnarlGmax,
        .shinyPalette = gMonShinyPalette_GrimmsnarlGmax,
        .iconSprite = gMonIcon_GrimmsnarlGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Grimmsnarl)
        .isGigantamax = TRUE,
        .levelUpLearnset = sGrimmsnarlLevelUpLearnset,
        .teachableLearnset = sGrimmsnarlTeachableLearnset,
        .formSpeciesIdTable = sGrimmsnarlFormSpeciesIdTable,
        .formChangeTable = sGrimmsnarlFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_IMPIDIMP

#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] =
    {
        .baseHP        = 45,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 34,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 200,
        .expYield = 54,
        .evYield_SpDefense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Hokumil"),
#else
        .speciesName = _("MILCERY"),
#endif
        .cryId = CRY_MILCERY,
        .natDexNum = NATIONAL_DEX_MILCERY,
#if GERMAN
        .categoryName = _("Sahne"),
#else
        .categoryName = _("Cream"),
#endif
        .height = 2,
        .weight = 3,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hokumils Körper besteht aus Sahne. Es\n"
            "entstand aus einer Ansammlung süßer\n"
            "Geruchspartikel in der Luft."),
#else
            "This Pokémon was born from sweet-smelling\n"
            "particles in the air. Its body is made\n"
            "of cream."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Milcery,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Milcery,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Milcery,
        .shinyPalette = gMonShinyPalette_Milcery,
        .iconSprite = gMonIcon_Milcery,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_S)
        FOOTPRINT(Milcery)
        OVERWORLD(
            sPicTable_Milcery,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Milcery,
            gShinyOverworldPalette_Milcery
        )
        .levelUpLearnset = sMilceryLevelUpLearnset,
        .teachableLearnset = sMilceryTeachableLearnset,
        .eggMoveLearnset = sMilceryEggMoveLearnset,
        .evolutions = EVOLUTION(
                                {EVO_ITEM, ITEM_SHINY_STONE,   SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM},
                                {EVO_ITEM, ITEM_FIRE_STONE,    SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM},
                                {EVO_ITEM, ITEM_LEAF_STONE,    SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM},
                                {EVO_ITEM, ITEM_ICE_STONE,     SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM},
                                {EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM},
                                {EVO_ITEM, ITEM_MOON_STONE,    SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM},
                                {EVO_ITEM, ITEM_DUSK_STONE,    SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL},
                                {EVO_ITEM, ITEM_SUN_STONE,     SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL},
                                {EVO_ITEM, ITEM_DAWN_STONE,    SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STRAWBERRY_SWEET},
                                           {IF_TIME, TIME_EVENING})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_BERRY_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_BERRY_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_BERRY_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_BERRY_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_BERRY_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_BERRY_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_BERRY_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_BERRY_SWEET},
                                           {IF_TIME, TIME_EVENING})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_LOVE_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_LOVE_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_LOVE_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_LOVE_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_LOVE_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_LOVE_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_LOVE_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_LOVE_SWEET},
                                           {IF_TIME, TIME_EVENING})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_STAR_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_STAR_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_STAR_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_STAR_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_STAR_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_STAR_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_STAR_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_STAR_SWEET},
                                           {IF_TIME, TIME_EVENING})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_CLOVER_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_CLOVER_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_CLOVER_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_CLOVER_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_CLOVER_SWEET},
                                           {IF_TIME, TIME_EVENING})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_FLOWER_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_FLOWER_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_FLOWER_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_FLOWER_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_FLOWER_SWEET},
                                           {IF_TIME, TIME_EVENING})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_RIBBON_RUBY_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_SHORT, SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_RIBBON_MINT_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_RIBBON_LEMON_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_SHORT, SPECIES_ALCREMIE_RIBBON_SALTED_CREAM,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_NIGHT})},
                                {EVO_SPIN, SPIN_CCW_LONG, SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_CW_LONG, SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_DAY})},
                                {EVO_SPIN, SPIN_EITHER, SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL,
                                CONDITIONS({IF_HOLD_ITEM, ITEM_RIBBON_SWEET},
                                           {IF_TIME, TIME_EVENING})}
                        )
    },

#define ALCREMIE_MISC_INFO(color)                                               \
        .baseHP        = 65,                                                    \
        .baseAttack    = 60,                                                    \
        .baseDefense   = 75,                                                    \
        .baseSpeed     = 64,                                                    \
        .baseSpAttack  = 110,                                                   \
        .baseSpDefense = 121,                                                   \
        .types = MON_TYPES(TYPE_FAIRY),                                         \
        .catchRate = 100,                                                       \
        .expYield = 173,                                                        \
        .evYield_SpDefense = 2,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS),      \
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_AROMA_VEIL },  \
        .bodyColor = color

#define ALCREMIE_REGULAR_SPECIES_INFO(sweet, cream, color, rzMode)                              \
    {                                                                                           \
        ALCREMIE_MISC_INFO(color),                                                              \
        .speciesName = _(DE_EN("Pokusan", "ALCREMIE")),                                        \
        .cryId = CRY_ALCREMIE,                                                                  \
        .natDexNum = NATIONAL_DEX_ALCREMIE,                                                     \
        .categoryName = _(DE_EN("Sahne", "Cream")),                                             \
        .height = 3,                                                                            \
        .weight = 5,                                                                            \
        .description = gAlcremie ##cream##PokedexText,                                          \
        .pokemonScale = 530,                                                                    \
        .pokemonOffset = 13,                                                                    \
        .trainerScale = 256,                                                                    \
        .trainerOffset = 0,                                                                     \
        .frontPic = gMonFrontPic_Alcremie ##sweet,                                              \
        .frontPicSize = MON_COORDS_SIZE(40, 56),                                                \
        .frontPicYOffset = 7,                                                                   \
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,                                       \
        /*.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,*/                                            \
        .backPic = gMonBackPic_Alcremie ##sweet,                                                \
        .backPicSize = MON_COORDS_SIZE(48, 56),                                                 \
        .backPicYOffset = 9,                                                                    \
        /*.backAnimId = BACK_ANIM_NONE,*/                                                       \
        .palette = gMonPalette_Alcremie ##sweet##cream,                                         \
        .shinyPalette = gMonShinyPalette_Alcremie ##sweet,                                      \
        .iconSprite = gMonIcon_AlcremieStrawberryVanillaCream, /*AlcremieStrawberry##cream##*/  \
        .iconPalIndex = 0,                                                                      \
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,                                                 \
        SHADOW(0, 5, SHADOW_SIZE_S)                                                             \
        FOOTPRINT(Alcremie)                                                                     \
        OVERWORLD(                                                                              \
            sPicTable_AlcremieStrawberry, /*Alcremie ##sweet*/                                  \
            SIZE_32x32,                                                                         \
            SHADOW_SIZE_M,                                                                      \
            TRACKS_FOOT,                                                                        \
            sAnimTable_Following,                                                               \
            gOverworldPalette_AlcremieStrawberryVanillaCream, /*Alcremie ##sweet##cream*/       \
            gShinyOverworldPalette_AlcremieStrawberryVanillaCream /*Alcremie ##sweet##cream*/   \
        )                                                                                       \
        .levelUpLearnset = sAlcremieLevelUpLearnset,                                            \
        .teachableLearnset = sAlcremieTeachableLearnset,                                        \
        .formSpeciesIdTable = sAlcremieFormSpeciesIdTable,                                      \
        .formChangeTable = sAlcremieFormChangeTable,                                            \
        .randomizerMode = rzMode,                                                               \
    }

    [SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM] = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_RANDOM_FORM),
    [SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM]    = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM]  = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM]    = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM]   = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM]  = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL]    = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL] = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL] = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_VANILLA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_RUBY_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_MATCHA_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_MINT_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_LEMON_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_SALTED_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_RUBY_SWIRL]         = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL]      = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL]      = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_VANILLA_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Love,       VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_RUBY_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Love,       RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_MATCHA_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Love,       MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_MINT_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Love,       MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_LEMON_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Love,       LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_SALTED_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Love,       SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_RUBY_SWIRL]          = ALCREMIE_REGULAR_SPECIES_INFO(Love,       RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Love,       CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Love,       RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_VANILLA_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Star,       VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_RUBY_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Star,       RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_MATCHA_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Star,       MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_MINT_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Star,       MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_LEMON_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Star,       LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_SALTED_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Star,       SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_RUBY_SWIRL]          = ALCREMIE_REGULAR_SPECIES_INFO(Star,       RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Star,       CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Star,       RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM]     = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_RUBY_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_MINT_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_LEMON_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_SALTED_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL]        = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM]     = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_RUBY_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_MINT_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_LEMON_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_SALTED_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL]        = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM]     = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     VanillaCream, BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_RUBY_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     RubyCream,    BODY_COLOR_PINK,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     MatchaCream,  BODY_COLOR_GREEN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_MINT_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     MintCream,    BODY_COLOR_BLUE,      MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_LEMON_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     LemonCream,   BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_SALTED_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     SaltedCream,  BODY_COLOR_WHITE,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL]        = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     RubySwirl,    BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     CaramelSwirl, BODY_COLOR_BROWN,     MON_RANDOMIZER_INVALID),
    [SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     RainbowSwirl, BODY_COLOR_YELLOW,    MON_RANDOMIZER_INVALID),
#if P_GIGANTAMAX_FORMS
    [SPECIES_ALCREMIE_GMAX] =
    {
        ALCREMIE_MISC_INFO(BODY_COLOR_YELLOW),
#if GERMAN
        .speciesName = _("Pokusan"),
#else
        .speciesName = _("ALCREMIE"),
#endif
        .cryId = CRY_ALCREMIE,
        .natDexNum = NATIONAL_DEX_ALCREMIE,
#if GERMAN
        .categoryName = _("Sahne"),
#else
        .categoryName = _("Cream"),
#endif
        .height = 3,
        .weight = 5,
        .description = COMPOUND_STRING(
#if GERMAN
        "Pokusan macht einem Trainer, dem es\n"
        "vertraut, mit Beeren samt Sahnedekoration\n"
        "eine Freude."),
#else
            "It launches swarms of missiles,\n"
            "each made of cream and loaded with\n"
            "100,000 kilocalories. Get hit by one of\n"
            "these, and your head will swim."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AlcremieGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AlcremieGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_AlcremieGmax,
        .shinyPalette = gMonShinyPalette_AlcremieGmax,
        .iconSprite = gMonIcon_AlcremieGmax,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Alcremie)
        .isGigantamax = TRUE,
        .levelUpLearnset = sAlcremieLevelUpLearnset,
        .teachableLearnset = sAlcremieTeachableLearnset,
        .formSpeciesIdTable = sAlcremieFormSpeciesIdTable,
        .formChangeTable = sAlcremieFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_MILCERY

#if P_FAMILY_FALINKS
    [SPECIES_FALINKS] =
    {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 75,
        .baseSpAttack  = 70,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 165,
        .evYield_Attack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Legios"),
#else
        .speciesName = _("FALINKS"),
#endif
        .cryId = CRY_FALINKS,
        .natDexNum = NATIONAL_DEX_FALINKS,
        .categoryName = _("Formation"),
        .height = 30,
        .weight = 620,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon besteht aus fünf\n"
        "Untergebenen und einem Anführer. Die\n"
        "Befehle des Anführers werden nie in Frage\n"
        "gestellt."),
#else
            "Five of them are troopers, and one is the\n"
            "brass. The brass's orders are absolute."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Falinks,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Falinks,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Falinks,
        .shinyPalette = gMonShinyPalette_Falinks,
        .iconSprite = gMonIcon_Falinks,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 5, SHADOW_SIZE_S)
        FOOTPRINT(Falinks)
        OVERWORLD(
            sPicTable_Falinks,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Falinks,
            gShinyOverworldPalette_Falinks
        )
        .levelUpLearnset = sFalinksLevelUpLearnset,
        .teachableLearnset = sFalinksTeachableLearnset,
        .formSpeciesIdTable = sFalinksFormSpeciesIdTable,
        .formChangeTable = sFalinksFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_FALINKS_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 135,
        .baseDefense   = 135,
        .baseSpeed     = 100,
        .baseSpAttack  = 70,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 165,
        .evYield_Attack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Legios"),
#else
        .speciesName = _("FALINKS"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_FALINKS_MEGA,
    #else
        .cryId = CRY_FALINKS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_FALINKS,
        .categoryName = _("Formation"),
        .height = 16,
        .weight = 990,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es hat die ultimative Formation\n"
        "eingenommen, was nur dank der starken\n"
        "Bande zwischen den einzelnen Gliedern\n"
        "möglich war."),
#else
            "Mega Falinks has taken on the\n"
            "ultimate battle formation, which\n"
            "can be achieved only if the troopers\n"
            "and brass have the strongest of bonds."),
#endif
        .frontPic = gMonFrontPic_FalinksMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_FalinksMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_FalinksMega,
        .shinyPalette = gMonShinyPalette_FalinksMega,
        .iconSprite = gMonIcon_FalinksMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Falinks)
        SHADOW(0, 12, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sFalinksLevelUpLearnset,
        .teachableLearnset = sFalinksTeachableLearnset,
        .formSpeciesIdTable = sFalinksFormSpeciesIdTable,
        .formChangeTable = sFalinksFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_FALINKS

#if P_FAMILY_PINCURCHIN
    [SPECIES_PINCURCHIN] =
    {
        .baseHP        = 48,
        .baseAttack    = 101,
        .baseDefense   = 95,
        .baseSpeed     = 15,
        .baseSpAttack  = 91,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = 152,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_NONE, ABILITY_ELECTRIC_SURGE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Britzigel"),
#else
        .speciesName = _("PINCURCHIN"),
#endif
        .cryId = CRY_PINCURCHIN,
        .natDexNum = NATIONAL_DEX_PINCURCHIN,
#if GERMAN
        .categoryName = _("Seeigel"),
#else
        .categoryName = _("Sea Urchin"),
#endif
        .height = 3,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
        "Aus den Spitzen seiner Stacheln setzt es\n"
        "Elektrizität frei. Mit seinen scharfen\n"
        "Zähnen schabt es Algen von Steinen ab und\n"
        "frisst sie."),
#else
            "It feeds on seaweed, using its teeth to\n"
            "scrape it off rocks. Electric current\n"
            "flows from the tips of its spines."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pincurchin,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Pincurchin,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Pincurchin,
        .shinyPalette = gMonShinyPalette_Pincurchin,
        .iconSprite = gMonIcon_Pincurchin,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -4, SHADOW_SIZE_S)
        FOOTPRINT(Pincurchin)
        OVERWORLD(
            sPicTable_Pincurchin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pincurchin,
            gShinyOverworldPalette_Pincurchin
        )
        .levelUpLearnset = sPincurchinLevelUpLearnset,
        .teachableLearnset = sPincurchinTeachableLearnset,
        .eggMoveLearnset = sPincurchinEggMoveLearnset,
    },
#endif //P_FAMILY_PINCURCHIN

#if P_FAMILY_SNOM
    [SPECIES_SNOM] =
    {
        .baseHP        = 30,
        .baseAttack    = 25,
        .baseDefense   = 35,
        .baseSpeed     = 20,
        .baseSpAttack  = 45,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_ICE, TYPE_BUG),
        .catchRate = 190,
        .expYield = 37,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_SNOWBALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_ICE_SCALES },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Snomnom"),
#else
        .speciesName = _("SNOM"),
#endif
        .cryId = CRY_SNOM,
        .natDexNum = NATIONAL_DEX_SNOM,
#if GERMAN
        .categoryName = _("Wurm"),
#else
        .categoryName = _("Worm"),
#endif
        .height = 3,
        .weight = 38,
        .description = COMPOUND_STRING(
#if GERMAN
        "Snomnom spinnt einen eiskalten Faden, mit\n"
        "dem es sich an einen Ast hängt. Dabei tut\n"
        "es so, als wäre es ein Eiszapfen, um in Ruhe\n"
        "schlafen zu können."),
#else
            "It spits out thread imbued with a frigid\n"
            "sort of energy and uses it to tie its body\n"
            "to branches, disguising itself as an\n"
            "icicle while it sleeps."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Snom,
        .frontPicSize = MON_COORDS_SIZE(40, 32),
        .frontPicYOffset = 20,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Snom,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Snom,
        .shinyPalette = gMonShinyPalette_Snom,
        .iconSprite = gMonIcon_Snom,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, -7, SHADOW_SIZE_S)
        FOOTPRINT(Snom)
        OVERWORLD(
            sPicTable_Snom,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Snom,
            gShinyOverworldPalette_Snom
        )
        .levelUpLearnset = sSnomLevelUpLearnset,
        .teachableLearnset = sSnomTeachableLearnset,
        .eggMoveLearnset = sSnomEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_FROSMOTH, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD},{IF_TIME, TIME_NIGHT})}),
    },

    [SPECIES_FROSMOTH] =
    {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ICE, TYPE_BUG),
        .catchRate = 75,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_ICE_SCALES },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Mottineva"),
#else
        .speciesName = _("FROSMOTH"),
#endif
        .cryId = CRY_FROSMOTH,
        .natDexNum = NATIONAL_DEX_FROSMOTH,
#if GERMAN
        .categoryName = _("Eismotte"),
#else
        .categoryName = _("Frost Moth"),
#endif
        .height = 13,
        .weight = 420,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mottinevas Flügel sind -180\n"
        "ºC kalt. Während es über Felder und Berge\n"
        "fliegt, verstreut es mit Kälte versetzten\n"
        "Flügelstaub, der wie Schnee aussieht."),
#else
            "Icy scales fall from its wings like snow\n"
            "as it flies over fields and mountains.\n"
            "The temperature of its wings is less than\n"
            "-290 degrees Fahrenheit."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Frosmoth,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Frosmoth,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Frosmoth,
        .shinyPalette = gMonShinyPalette_Frosmoth,
        .iconSprite = gMonIcon_Frosmoth,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-7, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Frosmoth)
        OVERWORLD(
            sPicTable_Frosmoth,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Frosmoth,
            gShinyOverworldPalette_Frosmoth
        )
        .levelUpLearnset = sFrosmothLevelUpLearnset,
        .teachableLearnset = sFrosmothTeachableLearnset,
    },
#endif //P_FAMILY_SNOM

#if P_FAMILY_STONJOURNER
    [SPECIES_STONJOURNER] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 135,
        .baseSpeed     = 70,
        .baseSpAttack  = 20,
        .baseSpDefense = 20,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 60,
        .expYield = 165,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_POWER_SPOT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Humanolith"),
#else
        .speciesName = _("STONJOURNER"),
#endif
        .cryId = CRY_STONJOURNER,
        .natDexNum = NATIONAL_DEX_STONJOURNER,
#if GERMAN
        .categoryName = _("Megalith"),
#else
        .categoryName = _("Big Rock"),
#endif
        .height = 25,
        .weight = 5200,
        .description = COMPOUND_STRING(
#if GERMAN
        "Humanolith verweilt auf weitläufigen\n"
        "Wiesen und beobachtet den Lauf der Sonne.\n"
        "Dynamische Trittangriffe sind sein\n"
        "Spezialgebiet."),
#else
            "It stands in grasslands, watching the\n"
            "sun's descent from zenith to horizon. This\n"
            "Pokémon has a talent for delivering\n"
            "dynamic kicks."),
#endif
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Stonjourner,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Stonjourner,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Stonjourner,
        .shinyPalette = gMonShinyPalette_Stonjourner,
        .iconSprite = gMonIcon_Stonjourner,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_L)
        FOOTPRINT(Stonjourner)
        OVERWORLD(
            sPicTable_Stonjourner,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Stonjourner,
            gShinyOverworldPalette_Stonjourner
        )
        .levelUpLearnset = sStonjournerLevelUpLearnset,
        .teachableLearnset = sStonjournerTeachableLearnset,
        .eggMoveLearnset = sStonjournerEggMoveLearnset,
    },
#endif //P_FAMILY_STONJOURNER

#if P_FAMILY_EISCUE
    [SPECIES_EISCUE_ICE] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 60,
        .expYield = 165,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_ICE_FACE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kubuin"),
#else
        .speciesName = _("EISCUE"),
#endif
        .cryId = CRY_EISCUE_ICE,
        .natDexNum = NATIONAL_DEX_EISCUE,
#if GERMAN
        .categoryName = _("Pinguin"),
#else
        .categoryName = _("Penguin"),
#endif
        .height = 14,
        .weight = 890,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kubuin kam von einem extrem kalten Ort,\n"
        "indem es sich treiben ließ und schließlich\n"
        "angespült wurde. Es kühlt unablässig sein\n"
        "Gesicht mit Eis."),
#else
            "It drifted in on the flow of ocean waters\n"
            "from a frigid place. It keeps its head\n"
            "iced constantly to make sure it stays\n"
            "nice and cold."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_EiscueIce,
        .frontPicSize = MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_EiscueIce,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EiscueIce,
        .shinyPalette = gMonShinyPalette_EiscueIce,
        .iconSprite = gMonIcon_EiscueIce,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_S)
        FOOTPRINT(Eiscue)
        OVERWORLD(
            sPicTable_EiscueIce,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_EiscueIce,
            gShinyOverworldPalette_EiscueIce
        )
        .levelUpLearnset = sEiscueLevelUpLearnset,
        .teachableLearnset = sEiscueTeachableLearnset,
        .eggMoveLearnset = sEiscueEggMoveLearnset,
        .formSpeciesIdTable = sEiscueFormSpeciesIdTable,
        .formChangeTable = sEiscueFormChangeTable,
    },

    [SPECIES_EISCUE_NOICE] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 130,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 60,
        .expYield = 165,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FIELD),
        .abilities = { ABILITY_ICE_FACE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kubuin"),
#else
        .speciesName = _("EISCUE"),
#endif
        .cryId = CRY_EISCUE_NOICE_FACE,
        .natDexNum = NATIONAL_DEX_EISCUE,
#if GERMAN
        .categoryName = _("Pinguin"),
#else
        .categoryName = _("Penguin"),
#endif
        .height = 14,
        .weight = 890,
        .description = COMPOUND_STRING(
#if GERMAN
        "Nun, da der Eisblock um seinen Kopf\n"
        "zerbrochen ist, kommt sein verdrossener\n"
        "Gesichtsausdruck zum Vorschein, der viele\n"
        "Menschen bezaubert."),
#else
            "The hair on its head connects to\n"
            "the surface of its brain. When this\n"
            "Pokémon has something on its mind,\n"
            "its hair chills the air around it."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_EiscueNoice,
        .frontPicSize = MON_COORDS_SIZE(40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_EiscueNoice,
        .backPicSize = MON_COORDS_SIZE(40, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EiscueNoice,
        .shinyPalette = gMonShinyPalette_EiscueNoice,
        .iconSprite = gMonIcon_EiscueNoice,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_S)
        FOOTPRINT(Eiscue)
        .levelUpLearnset = sEiscueLevelUpLearnset,
        .teachableLearnset = sEiscueTeachableLearnset,
        .eggMoveLearnset = sEiscueEggMoveLearnset,
        .formSpeciesIdTable = sEiscueFormSpeciesIdTable,
        .formChangeTable = sEiscueFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_EISCUE

#if P_FAMILY_INDEEDEE
    [SPECIES_INDEEDEE_M] =
    {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 95,
        .baseSpAttack  = 105,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_NORMAL),
        .catchRate = 30,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 40,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_SYNCHRONIZE, ABILITY_PSYCHIC_SURGE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Servol"),
#else
        .speciesName = _("INDEEDEE"),
#endif
        .cryId = CRY_INDEEDEE_M,
        .natDexNum = NATIONAL_DEX_INDEEDEE,
        .categoryName = _("Emotion"),
        .height = 9,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit den Hörnern auf seinem Kopf erfasst es\n"
        "die Gefühle seines Gegenübers. Männchen\n"
        "kümmern sich wie Bedienstete um ihren\n"
        "Trainer."),
#else
            "It uses the horns on its head to sense the\n"
            "emotions of others. Males will act as\n"
            "valets for those they serve, looking\n"
            "after their every need."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IndeedeeM,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IndeedeeM,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IndeedeeM,
        .shinyPalette = gMonShinyPalette_IndeedeeM,
        .iconSprite = gMonIcon_IndeedeeM,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_S)
        FOOTPRINT(Indeedee)
        OVERWORLD(
            sPicTable_IndeedeeM,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IndeedeeM,
            gShinyOverworldPalette_IndeedeeM
        )
        .levelUpLearnset = sIndeedeeMLevelUpLearnset,
        .teachableLearnset = sIndeedeeMTeachableLearnset,
        .formSpeciesIdTable = sIndeedeeFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_RANDOM_FORM,
    },

    [SPECIES_INDEEDEE_F] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_NORMAL),
        .catchRate = 30,
        .expYield = 166,
        .evYield_SpDefense = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 40,
        .friendship = 140,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_SYNCHRONIZE, ABILITY_PSYCHIC_SURGE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Servol"),
#else
        .speciesName = _("INDEEDEE"),
#endif
        .cryId = CRY_INDEEDEE_F,
        .natDexNum = NATIONAL_DEX_INDEEDEE,
        .categoryName = _("Emotion"),
        .height = 9,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein äußerst intelligentes\n"
        "Pokémon, das mit seinen Artgenossen\n"
        "kommuniziert, indem es die Hörner eines\n"
        "anderen Exemplars mit seinen berührt."),
#else
            "They diligently serve people and\n"
            "Pokémon so they can gather feelings\n"
            "of gratitude. The females are\n"
            "particularly good at babysitting."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_IndeedeeF,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_IndeedeeF,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_IndeedeeF,
        .shinyPalette = gMonShinyPalette_IndeedeeF,
        .iconSprite = gMonIcon_IndeedeeF,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 4, SHADOW_SIZE_S)
        FOOTPRINT(Indeedee)
        OVERWORLD(
            sPicTable_IndeedeeF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_IndeedeeF,
            gShinyOverworldPalette_IndeedeeF
        )
        .levelUpLearnset = sIndeedeeFLevelUpLearnset,
        .teachableLearnset = sIndeedeeFTeachableLearnset,
        .eggMoveLearnset = sIndeedeeFEggMoveLearnset,
        .formSpeciesIdTable = sIndeedeeFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_INDEEDEE

#if P_FAMILY_MORPEKO
    [SPECIES_MORPEKO_FULL_BELLY] =
    {
        .baseHP        = 58,
        .baseAttack    = 95,
        .baseDefense   = 58,
        .baseSpeed     = 97,
        .baseSpAttack  = 70,
        .baseSpDefense = 58,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DARK),
        .catchRate = 180,
        .expYield = 153,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HUNGER_SWITCH, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Morpeko"),
#else
        .speciesName = _("MORPEKO"),
#endif
        .cryId = CRY_MORPEKO_FULL_BELLY,
        .natDexNum = NATIONAL_DEX_MORPEKO,
#if GERMAN
        .categoryName = _("Alter Ego"),
#else
        .categoryName = _("Two-Sided"),
#endif
        .height = 3,
        .weight = 30,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses immerzu hungrige Pokémon frisst\n"
        "Samen, die es in seinen beutelartigen\n"
        "Taschen verwahrt, und produziert so\n"
        "Elektrizität."),
#else
            "As it eats the seeds stored up in its\n"
            "pocket-like pouches, this Pokémon is not\n"
            "just satisfying its constant hunger. It's\n"
            "also generating electricity."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MorpekoFullBelly,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MorpekoFullBelly,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MorpekoFullBelly,
        .shinyPalette = gMonShinyPalette_MorpekoFullBelly,
        .iconSprite = gMonIcon_MorpekoFullBelly,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Morpeko)
        OVERWORLD(
            sPicTable_MorpekoFullBelly,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_MorpekoFullBelly,
            gShinyOverworldPalette_MorpekoFullBelly
        )
        .levelUpLearnset = sMorpekoLevelUpLearnset,
        .teachableLearnset = sMorpekoTeachableLearnset,
        .eggMoveLearnset = sMorpekoEggMoveLearnset,
        .formSpeciesIdTable = sMorpekoFormSpeciesIdTable,
        .formChangeTable = sMorpekoFormChangeTable,
    },

    [SPECIES_MORPEKO_HANGRY] =
    {
        .baseHP        = 58,
        .baseAttack    = 95,
        .baseDefense   = 58,
        .baseSpeed     = 97,
        .baseSpAttack  = 70,
        .baseSpDefense = 58,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DARK),
        .catchRate = 180,
        .expYield = 153,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HUNGER_SWITCH, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Morpeko"),
#else
        .speciesName = _("MORPEKO"),
#endif
        .cryId = CRY_MORPEKO_HANGRY,
        .natDexNum = NATIONAL_DEX_MORPEKO,
#if GERMAN
        .categoryName = _("Alter Ego"),
#else
        .categoryName = _("Two-Sided"),
#endif
        .height = 3,
        .weight = 30,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es wandelt in seinen Backentaschen\n"
        "Elektrizität in Unlicht-Energie um. Wenn es\n"
        "der Hunger überkommt, wird es rasend vor\n"
        "Wut."),
#else
            "Intense hunger drives it to\n"
            "extremes of violence, and the electricity\n"
            "in its cheek sacs has converted into\n"
            "a Dark-type energy."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MorpekoHangry,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_MorpekoHangry,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_MorpekoHangry,
        .shinyPalette = gMonShinyPalette_MorpekoHangry,
        .iconSprite = gMonIcon_MorpekoHangry,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Morpeko)
        .levelUpLearnset = sMorpekoLevelUpLearnset,
        .teachableLearnset = sMorpekoTeachableLearnset,
        .eggMoveLearnset = sMorpekoEggMoveLearnset,
        .formSpeciesIdTable = sMorpekoFormSpeciesIdTable,
        .formChangeTable = sMorpekoFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_MORPEKO

#if P_FAMILY_CUFANT
    [SPECIES_CUFANT] =
    {
        .baseHP        = 72,
        .baseAttack    = 80,
        .baseDefense   = 49,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 49,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 190,
        .expYield = 66,
        .evYield_Attack = 1,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Kupfanti"),
#else
        .speciesName = _("CUFANT"),
#endif
        .cryId = CRY_CUFANT,
        .natDexNum = NATIONAL_DEX_CUFANT,
#if GERMAN
        .categoryName = _("Kupferfant"),
#else
        .categoryName = _("Copperderm"),
#endif
        .height = 12,
        .weight = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon verfügt\n"
        "über eine Stärke, mit der es problemlos\n"
        "fünf Tonnen stemmen kann. Es nutzt\n"
        "seinen Rüssel, um in der Erde zu graben."),
#else
            "It digs up the ground with its trunk.\n"
            "It's also very strong, being able to\n"
            "carry loads of over five tons without any\n"
            "problem at all."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cufant,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cufant,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Cufant,
        .shinyPalette = gMonShinyPalette_Cufant,
        .iconSprite = gMonIcon_Cufant,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 2, SHADOW_SIZE_M)
        FOOTPRINT(Cufant)
        OVERWORLD(
            sPicTable_Cufant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cufant,
            gShinyOverworldPalette_Cufant
        )
        .levelUpLearnset = sCufantLevelUpLearnset,
        .teachableLearnset = sCufantTeachableLearnset,
        .eggMoveLearnset = sCufantEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COPPERAJAH}),
    },

    [SPECIES_COPPERAJAH] =
    {
        .baseHP        = 122,
        .baseAttack    = 130,
        .baseDefense   = 69,
        .baseSpeed     = 30,
        .baseSpAttack  = 80,
        .baseSpDefense = 69,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 90,
        .expYield = 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Patinaraja"),
#else
        .speciesName = _("COPPERAJAH"),
#endif
        .cryId = CRY_COPPERAJAH,
        .natDexNum = NATIONAL_DEX_COPPERAJAH,
#if GERMAN
        .categoryName = _("Kupferfant"),
#else
        .categoryName = _("Copperderm"),
#endif
        .height = 30,
        .weight = 6500,
        .description = COMPOUND_STRING(
#if GERMAN
        "Patinarajas grüne Haut ist\n"
        "wasserresistent. Es kam vor langer Zeit\n"
        "aus einer anderen Region und verrichtete\n"
        "mit den Menschen Arbeiten."),
#else
            "They came over from another region long\n"
            "ago and worked together with humans.\n"
            "Their green skin is resistant to water."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Copperajah,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Copperajah,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Copperajah,
        .shinyPalette = gMonShinyPalette_Copperajah,
        .iconSprite = gMonIcon_Copperajah,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 7, SHADOW_SIZE_L)
        FOOTPRINT(Copperajah)
        OVERWORLD(
            sPicTable_Copperajah,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Copperajah,
            gShinyOverworldPalette_Copperajah
        )
        .levelUpLearnset = sCopperajahLevelUpLearnset,
        .teachableLearnset = sCopperajahTeachableLearnset,
        .formSpeciesIdTable = sCopperajahFormSpeciesIdTable,
        .formChangeTable = sCopperajahFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_COPPERAJAH_GMAX] =
    {
        .baseHP        = 122,
        .baseAttack    = 130,
        .baseDefense   = 69,
        .baseSpeed     = 30,
        .baseSpAttack  = 80,
        .baseSpDefense = 69,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 90,
        .expYield = 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Patinaraja"),
#else
        .speciesName = _("COPPERAJAH"),
#endif
        .cryId = CRY_COPPERAJAH,
        .natDexNum = NATIONAL_DEX_COPPERAJAH,
#if GERMAN
        .categoryName = _("Kupferfant"),
#else
        .categoryName = _("Copperderm"),
#endif
        .height = 230,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "In seinem Rüssel sammelt sich so viel\n"
        "Energie an, dass es Berge wegfegt und die\n"
        "ganze Landschaft verändert, wenn es sie\n"
        "freisetzt."),
#else
            "After this Pokémon has Gigantamaxed,\n"
            "its massive nose can utterly demolish\n"
            "large structures with a single\n"
            "smashing blow."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CopperajahGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CopperajahGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CopperajahGmax,
        .shinyPalette = gMonShinyPalette_CopperajahGmax,
        .iconSprite = gMonIcon_CopperajahGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_L)
        FOOTPRINT(Copperajah)
        .isGigantamax = TRUE,
        .levelUpLearnset = sCopperajahLevelUpLearnset,
        .teachableLearnset = sCopperajahTeachableLearnset,
        .formSpeciesIdTable = sCopperajahFormSpeciesIdTable,
        .formChangeTable = sCopperajahFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_CUFANT

#if P_FAMILY_DRACOZOLT
    [SPECIES_DRACOZOLT] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 75,
        .baseSpAttack  = 80,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_HUSTLE, ABILITY_SAND_RUSH },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Lectragon"),
#else
        .speciesName = _("DRACOZOLT"),
#endif
        .cryId = CRY_DRACOZOLT,
        .natDexNum = NATIONAL_DEX_DRACOZOLT,
        .categoryName = _("Fossil"),
        .height = 18,
        .weight = 1900,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dank seines kräftigen Unterkörpers\n"
        "war es in der Urzeit unbesiegbar,\n"
        "doch es fraß seine Pflanzennahrung\n"
        "restlos auf und starb daher aus."),
#else
            "In ancient times, it was unbeatable thanks\n"
            "to its powerful lower body, but it went\n"
            "extinct anyway after it depleted all its\n"
            "plant-based food sources."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Dracozolt,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dracozolt,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dracozolt,
        .shinyPalette = gMonShinyPalette_Dracozolt,
        .iconSprite = gMonIcon_Dracozolt,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 10, SHADOW_SIZE_L)
        FOOTPRINT(Dracozolt)
        OVERWORLD(
            sPicTable_Dracozolt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dracozolt,
            gShinyOverworldPalette_Dracozolt
        )
        .levelUpLearnset = sDracozoltLevelUpLearnset,
        .teachableLearnset = sDracozoltTeachableLearnset,
    },
#endif //P_FAMILY_DRACOZOLT

#if P_FAMILY_ARCTOZOLT
    [SPECIES_ARCTOZOLT] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 55,
        .baseSpAttack  = 90,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_ICE),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_STATIC, ABILITY_SLUSH_RUSH },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Lecryodon"),
#else
        .speciesName = _("ARCTOZOLT"),
#endif
        .cryId = CRY_ARCTOZOLT,
        .natDexNum = NATIONAL_DEX_ARCTOZOLT,
        .categoryName = _("Fossil"),
        .height = 23,
        .weight = 1500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Durch das Zittern seines gefrorenen\n"
            "Oberkörpers entsteht Elektrizität. Das\n"
            "Laufen fällt ihm äußerst schwer."),
#else
            "The shaking of its freezing upper half is\n"
            "what generates its electricity. It has a\n"
            "hard time walking around."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Arctozolt,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Arctozolt,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Arctozolt,
        .shinyPalette = gMonShinyPalette_Arctozolt,
        .iconSprite = gMonIcon_Arctozolt,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Arctozolt)
        OVERWORLD(
            sPicTable_Arctozolt,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Arctozolt,
            gShinyOverworldPalette_Arctozolt
        )
        .levelUpLearnset = sArctozoltLevelUpLearnset,
        .teachableLearnset = sArctozoltTeachableLearnset,
    },
#endif //P_FAMILY_ARCTOZOLT

#if P_FAMILY_DRACOVISH
    [SPECIES_DRACOVISH] =
    {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 100,
        .baseSpeed     = 75,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_STRONG_JAW, ABILITY_SAND_RUSH },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Pescragon"),
#else
        .speciesName = _("DRACOVISH"),
#endif
        .cryId = CRY_DRACOVISH,
        .natDexNum = NATIONAL_DEX_DRACOVISH,
        .categoryName = _("Fossil"),
        .height = 23,
        .weight = 2150,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dank der enormen Kraft seiner\n"
        "Beine und seines Kiefers war es in der\n"
        "Urzeit unbesiegbar, doch es fing seine\n"
        "Beute restlos weg und starb daher aus."),
#else
            "Powerful legs and jaws made it the apex\n"
            "predator of its time. Its own overhunting\n"
            "of its prey was what drove it to\n"
            "extinction."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Dracovish,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dracovish,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dracovish,
        .shinyPalette = gMonShinyPalette_Dracovish,
        .iconSprite = gMonIcon_Dracovish,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_M)
        FOOTPRINT(Dracovish)
        OVERWORLD(
            sPicTable_Dracovish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dracovish,
            gShinyOverworldPalette_Dracovish
        )
        .levelUpLearnset = sDracovishLevelUpLearnset,
        .teachableLearnset = sDracovishTeachableLearnset,
    },
#endif //P_FAMILY_DRACOVISH

#if P_FAMILY_ARCTOVISH
    [SPECIES_ARCTOVISH] =
    {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 100,
        .baseSpeed     = 55,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_WATER, TYPE_ICE),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_ICE_BODY, ABILITY_SLUSH_RUSH },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Pescryodon"),
#else
        .speciesName = _("ARCTOVISH"),
#endif
        .cryId = CRY_ARCTOVISH,
        .natDexNum = NATIONAL_DEX_ARCTOVISH,
        .categoryName = _("Fossil"),
        .height = 20,
        .weight = 1750,
        .description = COMPOUND_STRING(
#if GERMAN
        "Pescryodon fängt seine Beute, indem\n"
        "es seine Umgebung einfriert, doch da sich\n"
        "sein Maul oben auf seinem Kopf befindet,\n"
        "ist Fressen für es sehr umständlich."),
#else
            "Though it's able to capture prey by\n"
            "freezing its surroundings, it has trouble\n"
            "eating the prey afterward because its\n"
            "mouth is on top of its head."),
#endif
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Arctovish,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Arctovish,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Arctovish,
        .shinyPalette = gMonShinyPalette_Arctovish,
        .iconSprite = gMonIcon_Arctovish,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_L)
        FOOTPRINT(Arctovish)
        OVERWORLD(
            sPicTable_Arctovish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Arctovish,
            gShinyOverworldPalette_Arctovish
        )
        .levelUpLearnset = sArctovishLevelUpLearnset,
        .teachableLearnset = sArctovishTeachableLearnset,
    },
#endif //P_FAMILY_ARCTOVISH

#if P_FAMILY_DURALUDON
    [SPECIES_DURALUDON] =
    {
        .baseHP        = 70,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 120,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_STEEL, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 187,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_LIGHT_METAL, ABILITY_HEAVY_METAL, ABILITY_STALWART },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Duraludon"),
#else
        .speciesName = _("DURALUDON"),
#endif
        .cryId = CRY_DURALUDON,
        .natDexNum = NATIONAL_DEX_DURALUDON,
#if GERMAN
        .categoryName = _("Legierung"),
#else
        .categoryName = _("Alloy"),
#endif
        .height = 18,
        .weight = 400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Duraludons an aufpoliertes Metall\n"
            "erinnernder Körper ist nicht nur leicht,\n"
            "sondern auch robust. Er hat jedoch den\n"
            "Nachteil, schnell zu rosten."),
#else
            "Its body resembles polished metal, and\n"
            "it's both lightweight and strong. The only\n"
            "drawback is that it rusts easily."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Duraludon,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 60),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_SHAKE_FLASH_YELLOW_FAST,
        .backPic = gMonBackPic_Duraludon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Duraludon,
        .shinyPalette = gMonShinyPalette_Duraludon,
        .iconSprite = gMonIcon_Duraludon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_L)
        FOOTPRINT(Duraludon)
        OVERWORLD(
            sPicTable_Duraludon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Duraludon,
            gShinyOverworldPalette_Duraludon
        )
        .levelUpLearnset = sDuraludonLevelUpLearnset,
        .teachableLearnset = sDuraludonTeachableLearnset,
        .eggMoveLearnset = sDuraludonEggMoveLearnset,
        .formSpeciesIdTable = sDuraludonFormSpeciesIdTable,
        .formChangeTable = sDuraludonFormChangeTable,
    #if P_GEN_9_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_UP_GRADE, SPECIES_ARCHALUDON},
                                {EVO_ITEM, ITEM_METAL_ALLOY, SPECIES_ARCHALUDON}),
    #endif
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_DURALUDON_GMAX] =
    {
        .baseHP        = 70,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 120,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_STEEL, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 187,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_LIGHT_METAL, ABILITY_HEAVY_METAL, ABILITY_STALWART },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Duraludon"),
#else
        .speciesName = _("DURALUDON"),
#endif
        .cryId = CRY_DURALUDON,
        .natDexNum = NATIONAL_DEX_DURALUDON,
#if GERMAN
        .categoryName = _("Legierung"),
#else
        .categoryName = _("Alloy"),
#endif
        .height = 430,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch seine gigantische Größe gleicht es\n"
        "nun einem Wolkenkratzer. Das Übermaß an\n"
        "Energie in ihm lässt einige Körperteile\n"
        "leuchten."),
#else
            "The hardness of its cells is\n"
            "exceptional, even among Steel types. It\n"
            "also has a body structure that's\n"
            "resistant to earthquakes."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_DuraludonGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DuraludonGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DuraludonGmax,
        .shinyPalette = gMonShinyPalette_DuraludonGmax,
        .iconSprite = gMonIcon_DuraludonGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 12, SHADOW_SIZE_L)
        FOOTPRINT(Duraludon)
        .isGigantamax = TRUE,
        .levelUpLearnset = sDuraludonLevelUpLearnset,
        .teachableLearnset = sDuraludonTeachableLearnset,
        .eggMoveLearnset = sDuraludonEggMoveLearnset,
        .formSpeciesIdTable = sDuraludonFormSpeciesIdTable,
        .formChangeTable = sDuraludonFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS

#if P_GEN_9_CROSS_EVOS
    [SPECIES_ARCHALUDON] =
    {
        .baseHP        = 90,
        .baseAttack    = 105,
        .baseDefense   = 130,
        .baseSpeed     = 85,
        .baseSpAttack  = 125,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_STEEL, TYPE_DRAGON),
        .catchRate = 10,
        .expYield = 300,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_STAMINA, ABILITY_STURDY, ABILITY_STALWART },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Briduradon"),
#else
        .speciesName = _("ARCHALUDON"),
#endif
        .cryId = CRY_ARCHALUDON,
        .natDexNum = NATIONAL_DEX_ARCHALUDON,
#if GERMAN
        .categoryName = _("Legierung"),
#else
        .categoryName = _("Alloy"),
#endif
        .height = 20,
        .weight = 600,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es sammelt statische Elektrizität aus der\n"
            "Umgebung. Die Strahlen, die es auf allen\n"
            "Vieren abfeuert, sind extrem stark."),
#else
            "It gathers static electricity\n"
            "from its surroundings. The beams\n"
            "it launches when down on all fours\n"
            "are tremendously powerful."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Archaludon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Archaludon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Archaludon,
        .shinyPalette = gMonShinyPalette_Archaludon,
        .iconSprite = gMonIcon_Archaludon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 14, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Archaludon)
        OVERWORLD(
            sPicTable_Archaludon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Archaludon,
            gShinyOverworldPalette_Archaludon
        )
        .levelUpLearnset = sArchaludonLevelUpLearnset,
        .teachableLearnset = sArchaludonTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_DURALUDON

#if P_FAMILY_DREEPY
    [SPECIES_DREEPY] =
    {
        .baseHP        = 28,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 82,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 54,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_INFILTRATOR, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Grolldra"),
#else
        .speciesName = _("DREEPY"),
#endif
        .cryId = CRY_DREEPY,
        .natDexNum = NATIONAL_DEX_DREEPY,
#if GERMAN
        .categoryName = _("Missgunst"),
#else
        .categoryName = _("Lingering"),
#endif
        .height = 5,
        .weight = 20,
        .description = COMPOUND_STRING(
#if GERMAN
        "In der Urzeit lebte es im Meer. Nun ist es\n"
        "als Geister-Pokémon wiedererwacht und\n"
        "irrt rastlos durch seinen früheren\n"
        "Lebensraum."),
#else
            "After being reborn as a ghost Pokémon,\n"
            "Dreepy wanders the areas it used to\n"
            "inhabit back when it was alive in\n"
            "prehistoric seas."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dreepy,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Dreepy,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dreepy,
        .shinyPalette = gMonShinyPalette_Dreepy,
        .iconSprite = gMonIcon_Dreepy,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Dreepy)
        OVERWORLD(
            sPicTable_Dreepy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dreepy,
            gShinyOverworldPalette_Dreepy
        )
        .levelUpLearnset = sDreepyLevelUpLearnset,
        .teachableLearnset = sDreepyTeachableLearnset,
        .eggMoveLearnset = sDreepyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_DRAKLOAK}),
    },

    [SPECIES_DRAKLOAK] =
    {
        .baseHP        = 68,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 102,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_INFILTRATOR, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Phandra"),
#else
        .speciesName = _("DRAKLOAK"),
#endif
        .cryId = CRY_DRAKLOAK,
        .natDexNum = NATIONAL_DEX_DRAKLOAK,
#if GERMAN
        .categoryName = _("Betreuer"),
#else
        .categoryName = _("Caretaker"),
#endif
        .height = 14,
        .weight = 110,
        .description = COMPOUND_STRING(
#if GERMAN
        "Beim Fliegen ist es bis zu 200 km/h schnell.\n"
        "Es kämpft gemeinsam mit Grolldra und\n"
        "kümmert sich bis zu dessen Entwicklung um\n"
        "es."),
#else
            "It's capable of flying faster than 120 mph.\n"
            "It battles alongside Dreepy and dotes\n"
            "on them until they successfully evolve."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Drakloak,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Drakloak,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Drakloak,
        .shinyPalette = gMonShinyPalette_Drakloak,
        .iconSprite = gMonIcon_Drakloak,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 9, SHADOW_SIZE_M)
        FOOTPRINT(Drakloak)
        OVERWORLD(
            sPicTable_Drakloak,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Drakloak,
            gShinyOverworldPalette_Drakloak
        )
        .levelUpLearnset = sDrakloakLevelUpLearnset,
        .teachableLearnset = sDrakloakTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 60, SPECIES_DRAGAPULT}),
    },

    [SPECIES_DRAGAPULT] =
    {
        .baseHP        = 88,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 142,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 300,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_INFILTRATOR, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Katapuldra"),
#else
        .speciesName = _("DRAGAPULT"),
#endif
        .cryId = CRY_DRAGAPULT,
        .natDexNum = NATIONAL_DEX_DRAGAPULT,
#if GERMAN
        .categoryName = _("Tarnkünstler"),
#else
        .categoryName = _("Stealth"),
#endif
        .height = 30,
        .weight = 500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Katapuldra transportiert Grolldra in den\n"
            "Löchern an seinen Hörnern. Kommt es zum\n"
            "Kampf, schießt es diese mit\n"
            "Mach-Geschwindigkeit ab."),
#else
            "When it isn't battling, it keeps Dreepy\n"
            "in the holes on its horns. Once a fight\n"
            "starts, it launches the Dreepy like\n"
            "supersonic missiles."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dragapult,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_Dragapult,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Dragapult,
        .shinyPalette = gMonShinyPalette_Dragapult,
        .iconSprite = gMonIcon_Dragapult,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_M)
        FOOTPRINT(Dragapult)
        OVERWORLD(
            sPicTable_Dragapult,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dragapult,
            gShinyOverworldPalette_Dragapult
        )
        .levelUpLearnset = sDragapultLevelUpLearnset,
        .teachableLearnset = sDragapultTeachableLearnset,
    },
#endif //P_FAMILY_DREEPY

#if P_FAMILY_ZACIAN
    [SPECIES_ZACIAN_HERO] =
    {
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .baseDefense   = 115,
        .baseSpeed     = 138,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 10,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_9) ? 330 : 335,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INTREPID_SWORD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Zacian"),
#else
        .speciesName = _("ZACIAN"),
#endif
        .cryId = CRY_ZACIAN_HERO,
        .natDexNum = NATIONAL_DEX_ZACIAN,
#if GERMAN
        .categoryName = _("Krieger"),
#else
        .categoryName = _("Warrior"),
#endif
        .height = 28,
        .weight = 1100,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon gilt als legendärer\n"
        "Held. Es nimmt Metall auf, wandelt\n"
        "dies in eine Waffe um und kämpft damit."),
#else
            "Known as a legendary hero, this Pokémon\n"
            "absorbs metal particles, transforming\n"
            "them into a weapon it uses to battle."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ZacianHero,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZacianHero,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZacianHero,
        .shinyPalette = gMonShinyPalette_ZacianHero,
        .iconSprite = gMonIcon_ZacianHero,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_L)
        FOOTPRINT(Zacian)
        OVERWORLD(
            sPicTable_ZacianHero,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZacianHero,
            gShinyOverworldPalette_ZacianHero
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZacianLevelUpLearnset,
        .teachableLearnset = sZacianTeachableLearnset,
        .formSpeciesIdTable = sZacianFormSpeciesIdTable,
        .formChangeTable = sZacianFormChangeTable,
    },

    [SPECIES_ZACIAN_CROWNED] =
    {
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 150 : 170,
        .baseDefense   = 115,
        .baseSpeed     = 148,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_STEEL),
        .catchRate = 10,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_9) ? 350 : 360,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INTREPID_SWORD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Zacian"),
#else
        .speciesName = _("ZACIAN"),
#endif
        .cryId = CRY_ZACIAN_CROWNED,
        .natDexNum = NATIONAL_DEX_ZACIAN,
#if GERMAN
        .categoryName = _("Krieger"),
#else
        .categoryName = _("Warrior"),
#endif
        .height = 28,
        .weight = 3550,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es trägt nun eine Waffe, die es vor langer\n"
        "Zeit einmal führte. Selbst\n"
        "Gigadynamax-Pokémon bezwingt es damit\n"
        "auf einen Streich."),
#else
            "Able to cut down anything with a\n"
            "single strike, it became known as the\n"
            "Fairy King's Sword, and it inspired\n"
            "awe in friend and foe alike."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ZacianCrowned,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZacianCrowned,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZacianCrowned,
        .shinyPalette = gMonShinyPalette_ZacianCrowned,
        .iconSprite = gMonIcon_ZacianCrowned,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 12, SHADOW_SIZE_L)
        FOOTPRINT(Zacian)
        OVERWORLD(
            sPicTable_ZacianCrowned,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZacianCrowned,
            gShinyOverworldPalette_ZacianCrowned
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZacianLevelUpLearnset,
        .teachableLearnset = sZacianTeachableLearnset,
        .formSpeciesIdTable = sZacianFormSpeciesIdTable,
        .formChangeTable = sZacianFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_ZACIAN

#if P_FAMILY_ZAMAZENTA
    [SPECIES_ZAMAZENTA_HERO] =
    {
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .baseDefense   = 115,
        .baseSpeed     = 138,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 10,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_9) ? 330 : 335,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DAUNTLESS_SHIELD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Zamazenta"),
#else
        .speciesName = _("ZAMAZENTA"),
#endif
        .cryId = CRY_ZAMAZENTA_HERO,
        .natDexNum = NATIONAL_DEX_ZAMAZENTA,
#if GERMAN
        .categoryName = _("Krieger"),
#else
        .categoryName = _("Warrior"),
#endif
        .height = 29,
        .weight = 2100,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon fiel in Form einer\n"
        "Steinstatue in solch einen langen Schlaf,\n"
        "dass es in Vergessenheit geraten ist."),
#else
            "In times past, it worked together with a\n"
            "king of the people to save the Galar\n"
            "region. It absorbs metal that it then\n"
            "uses in battle."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ZamazentaHero,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZamazentaHero,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZamazentaHero,
        .shinyPalette = gMonShinyPalette_ZamazentaHero,
        .iconSprite = gMonIcon_ZamazentaHero,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_L)
        FOOTPRINT(Zamazenta)
        OVERWORLD(
            sPicTable_ZamazentaHero,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZamazentaHero,
            gShinyOverworldPalette_ZamazentaHero
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZamazentaLevelUpLearnset,
        .teachableLearnset = sZamazentaTeachableLearnset,
        .formSpeciesIdTable = sZamazentaFormSpeciesIdTable,
        .formChangeTable = sZamazentaFormChangeTable,
    },

    [SPECIES_ZAMAZENTA_CROWNED] =
    {
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .baseDefense   = P_UPDATED_STATS >= GEN_9 ? 140 : 145,
        .baseSpeed     = 128,
        .baseSpAttack  = 80,
        .baseSpDefense = P_UPDATED_STATS >= GEN_9 ? 140 : 145,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_STEEL),
        .catchRate = 10,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_9) ? 350 : 360,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DAUNTLESS_SHIELD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Zamazenta"),
#else
        .speciesName = _("ZAMAZENTA"),
#endif
        .cryId = CRY_ZAMAZENTA_CROWNED,
        .natDexNum = NATIONAL_DEX_ZAMAZENTA,
#if GERMAN
        .categoryName = _("Krieger"),
#else
        .categoryName = _("Warrior"),
#endif
        .height = 29,
        .weight = 7850,
        .description = COMPOUND_STRING(
#if GERMAN
        "Weil es alles und jeden abwehren konnte,\n"
        "trug es einst den Namen\n"
        "“Kämpferkönigsschild” und wurde\n"
        "gleichermaßen gefürchtet und verehrt."),
#else
            "Its ability to deflect any attack\n"
            "led to it being known as the Fighting\n"
            "Master's Shield. It was feared and\n"
            "respected by all."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ZamazentaCrowned,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZamazentaCrowned,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZamazentaCrowned,
        .shinyPalette = gMonShinyPalette_ZamazentaCrowned,
        .iconSprite = gMonIcon_ZamazentaCrowned,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_L)
        FOOTPRINT(Zamazenta)
        OVERWORLD(
            sPicTable_ZamazentaCrowned,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZamazentaCrowned,
            gShinyOverworldPalette_ZamazentaCrowned
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZamazentaLevelUpLearnset,
        .teachableLearnset = sZamazentaTeachableLearnset,
        .formSpeciesIdTable = sZamazentaFormSpeciesIdTable,
        .formChangeTable = sZamazentaFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_ZAMAZENTA

#if P_FAMILY_ETERNATUS
    [SPECIES_ETERNATUS] =
    {
        .baseHP        = 140,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 130,
        .baseSpAttack  = 145,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_POISON, TYPE_DRAGON),
        .catchRate = 255,
        .expYield = 345,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Endynalos"),
#else
        .speciesName = _("ETERNATUS"),
#endif
        .cryId = CRY_ETERNATUS,
        .natDexNum = NATIONAL_DEX_ETERNATUS,
#if GERMAN
        .categoryName = _("Gigant"),
#else
        .categoryName = _("Gigantic"),
#endif
        .height = 200,
        .weight = 9500,
        .description = COMPOUND_STRING(
#if GERMAN
        "Endynalos steckte in einem Meteorit, der\n"
        "vor 20 000 Jahren herabstürzte. Es\n"
        "scheint in Verbindung mit dem\n"
        "Dynamax-Phänomen zu stehen."),
#else
            "The core on its chest absorbs energy\n"
            "emanating from the lands of the Galar\n"
            "region. This energy is what allows\n"
            "Eternatus to stay active."),
#endif
        .pokemonScale = 230,
        .pokemonOffset = 0,
        .trainerScale = 4852,
        .trainerOffset = 20,
        .frontPic = gMonFrontPic_Eternatus,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_Eternatus,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Eternatus,
        .shinyPalette = gMonShinyPalette_Eternatus,
        .iconSprite = gMonIcon_Eternatus,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_L)
        FOOTPRINT(Eternatus)
        OVERWORLD(
            sPicTable_Eternatus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Eternatus,
            gShinyOverworldPalette_Eternatus
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sEternatusLevelUpLearnset,
        .teachableLearnset = sEternatusTeachableLearnset,
        .formSpeciesIdTable = sEternatusFormSpeciesIdTable,
    },

    [SPECIES_ETERNATUS_ETERNAMAX] =
    {
        .baseHP        = 255,
        .baseAttack    = 115,
        .baseDefense   = 250,
        .baseSpeed     = 130,
        .baseSpAttack  = 125,
        .baseSpDefense = 250,
        .types = MON_TYPES(TYPE_POISON, TYPE_DRAGON),
        .catchRate = 255,
        .expYield = 563,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Endynalos"),
#else
        .speciesName = _("ETERNATUS"),
#endif
        .cryId = CRY_ETERNATUS_ETERNAMAX,
        .natDexNum = NATIONAL_DEX_ETERNATUS,
#if GERMAN
        .categoryName = _("Gigant"),
#else
        .categoryName = _("Gigantic"),
#endif
        .height = 1000,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die unendliche Energie, die aus seinem\n"
            "gigantischen Kern austritt, verzerrt das\n"
            "Raum-Zeit-Gefüge um es herum."),
#else
            "As a result of Rose's meddling,\n"
            "Eternatus absorbed all the energy in\n"
            "the Galar region. It's now in a state\n"
            "of power overload."),
#endif
        .pokemonScale = 230,
        .pokemonOffset = 0,
        .trainerScale = 4852,
        .trainerOffset = 20,
        .frontPic = gMonFrontPic_EternatusEternamax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 13,
        .backPic = gMonBackPic_EternatusEternamax,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EternatusEternamax,
        .shinyPalette = gMonShinyPalette_EternatusEternamax,
        .iconSprite = gMonIcon_EternatusEternamax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 20, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Eternatus)
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sEternatusLevelUpLearnset,
        .teachableLearnset = sEternatusTeachableLearnset,
        .formSpeciesIdTable = sEternatusFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_ETERNATUS

#if P_FAMILY_KUBFU
    [SPECIES_KUBFU] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 60,
        .baseSpeed     = 72,
        .baseSpAttack  = 53,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = 77,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Dakuma"),
#else
        .speciesName = _("KUBFU"),
#endif
        .cryId = CRY_KUBFU,
        .natDexNum = NATIONAL_DEX_KUBFU,
#if GERMAN
        .categoryName = _("Kung-Fu"),
#else
        .categoryName = _("Wushu"),
#endif
        .height = 6,
        .weight = 120,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch rigoroses Training perfektioniert es\n"
        "seine Kampftechnik. Diese bestimmt, welche\n"
        "Form Dakuma nach der Entwicklung annimmt."),
#else
            "Kubfu trains hard to perfect its moves.\n"
            "The moves it masters will determine which\n"
            "form it takes when it evolves."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kubfu,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kubfu,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Kubfu,
        .shinyPalette = gMonShinyPalette_Kubfu,
        .iconSprite = gMonIcon_Kubfu,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, 5, SHADOW_SIZE_S)
        FOOTPRINT(Kubfu)
        OVERWORLD(
            sPicTable_Kubfu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kubfu,
            gShinyOverworldPalette_Kubfu
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKubfuLevelUpLearnset,
        .teachableLearnset = sKubfuTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_RAZOR_CLAW, SPECIES_URSHIFU_SINGLE_STRIKE},
                                {EVO_ITEM, ITEM_WATER_STONE, SPECIES_URSHIFU_RAPID_STRIKE},
                                {EVO_SCRIPT_TRIGGER, 0, SPECIES_URSHIFU_SINGLE_STRIKE},
                                {EVO_SCRIPT_TRIGGER, 1, SPECIES_URSHIFU_RAPID_STRIKE},
                                {EVO_ITEM, ITEM_SCROLL_OF_DARKNESS, SPECIES_URSHIFU_SINGLE_STRIKE},
                                {EVO_ITEM, ITEM_SCROLL_OF_WATERS,   SPECIES_URSHIFU_RAPID_STRIKE}),
    },

    [SPECIES_URSHIFU_SINGLE_STRIKE] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 97,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_DARK),
        .catchRate = 3,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_UNSEEN_FIST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Wulaosu"),
#else
        .speciesName = _("URSHIFU"),
#endif
        .cryId = CRY_URSHIFU_SINGLE_STRIKE,
        .natDexNum = NATIONAL_DEX_URSHIFU,
#if GERMAN
        .categoryName = _("Kung-Fu"),
#else
        .categoryName = _("Wushu"),
#endif
        .height = 19,
        .weight = 1050,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wulaosu ist darauf spezialisiert, Gegner\n"
        "mit nur einem Treffer zu bezwingen,\n"
        "indem es sie schlagartig anfällt\n"
        "und einen fokussierten Hieb austeilt."),
#else
            "This form of Urshifu is a strong believer\n"
            "in the one-hit KO. Its strategy is to leap\n"
            "in close to foes and land a devastating\n"
            "blow with a hardened fist."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_UrshifuSingleStrike,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_UrshifuSingleStrike,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_UrshifuSingleStrike,
        .shinyPalette = gMonShinyPalette_UrshifuSingleStrike,
        .iconSprite = gMonIcon_Urshifu,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_L)
        FOOTPRINT(Urshifu)
        OVERWORLD(
            sPicTable_Urshifu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Urshifu,
            gShinyOverworldPalette_Urshifu
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sUrshifuSingleStrikeLevelUpLearnset,
        .teachableLearnset = sUrshifuSingleStrikeTeachableLearnset,
        .formSpeciesIdTable = sUrshifuFormSpeciesIdTable,
        .formChangeTable = sUrshifuSingleStrikeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_URSHIFU_SINGLE_STRIKE_GMAX] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 97,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_DARK),
        .catchRate = 3,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_UNSEEN_FIST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Wulaosu"),
#else
        .speciesName = _("URSHIFU"),
#endif
        .cryId = CRY_URSHIFU_SINGLE_STRIKE,
        .natDexNum = NATIONAL_DEX_URSHIFU,
#if GERMAN
        .categoryName = _("Kung-Fu"),
#else
        .categoryName = _("Wushu"),
#endif
        .height = 290,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es wird die “Inkarnation des\n"
        "Zorns” genannt. Sein furchteinflößender\n"
        "Anblick und sein Kampfschrei sollen\n"
        "böse Geister aus dieser Welt vertreiben."),
#else
            "People call it the embodiment of\n"
            "rage. It's said that this Pokémon's\n"
            "terrifying expression and shout will\n"
            "rid the world of malevolence."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_UrshifuSingleStrikeGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_UrshifuSingleStrikeGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_UrshifuSingleStrikeGmax,
        .shinyPalette = gMonShinyPalette_UrshifuSingleStrikeGmax,
        .iconSprite = gMonIcon_UrshifuSingleStrikeGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_L)
        FOOTPRINT(Urshifu)
        .isSubLegendary = TRUE,
        .isGigantamax = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sUrshifuSingleStrikeLevelUpLearnset,
        .teachableLearnset = sUrshifuSingleStrikeTeachableLearnset,
        .formSpeciesIdTable = sUrshifuFormSpeciesIdTable,
        .formChangeTable = sUrshifuSingleStrikeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS

    [SPECIES_URSHIFU_RAPID_STRIKE] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 97,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_WATER),
        .catchRate = 3,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_UNSEEN_FIST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Wulaosu"),
#else
        .speciesName = _("URSHIFU"),
#endif
        .cryId = CRY_URSHIFU_RAPID_STRIKE,
        .natDexNum = NATIONAL_DEX_URSHIFU,
#if GERMAN
        .categoryName = _("Kung-Fu"),
#else
        .categoryName = _("Wushu"),
#endif
        .height = 19,
        .weight = 1050,
        .description = COMPOUND_STRING(
#if GERMAN
        "Man sagt, es habe den Stil seiner\n"
        "Kampftechnik dem Fließen eines Flusses\n"
        "nachempfunden: manchmal ungestüm,\n"
        "manchmal ruhig."),
#else
            "This form of Urshifu is a strong\n"
            "believer in defeating foes by raining\n"
            "many blows down on them. Its\n"
            "strikes are nonstop, flowing like a river."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_UrshifuRapidStrike,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_UrshifuRapidStrike,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_UrshifuRapidStrike,
        .shinyPalette = gMonShinyPalette_UrshifuRapidStrike,
        .iconSprite = gMonIcon_Urshifu,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 14, SHADOW_SIZE_M)
        FOOTPRINT(Urshifu)
        OVERWORLD(
            sPicTable_Urshifu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Urshifu,
            gShinyOverworldPalette_Urshifu
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sUrshifuRapidStrikeLevelUpLearnset,
        .teachableLearnset = sUrshifuRapidStrikeTeachableLearnset,
        .formSpeciesIdTable = sUrshifuFormSpeciesIdTable,
        .formChangeTable = sUrshifuRapidStrikeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_URSHIFU_RAPID_STRIKE_GMAX] =
    {
        .baseHP        = 100,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 97,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING, TYPE_WATER),
        .catchRate = 3,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_UNSEEN_FIST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Wulaosu"),
#else
        .speciesName = _("URSHIFU"),
#endif
        .cryId = CRY_URSHIFU_RAPID_STRIKE,
        .natDexNum = NATIONAL_DEX_URSHIFU,
#if GERMAN
        .categoryName = _("Kung-Fu"),
#else
        .categoryName = _("Wushu"),
#endif
        .height = 260,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Auf einem Bein stehend wartet es\n"
        "vollkommen regungslos darauf, seine\n"
        "Gigadynamax-Energie zu entfesseln."),
#else
            "As it waits for the right moment to\n"
            "unleash its Gigantamax power, this\n"
            "Pokémon maintains a perfect one-\n"
            "legged stance. It won't even twitch."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_UrshifuRapidStrikeGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_UrshifuRapidStrikeGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_UrshifuRapidStrikeGmax,
        .shinyPalette = gMonShinyPalette_UrshifuRapidStrikeGmax,
        .iconSprite = gMonIcon_UrshifuRapidStrikeGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 13, SHADOW_SIZE_M)
        FOOTPRINT(Urshifu)
        .isSubLegendary = TRUE,
        .isGigantamax = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sUrshifuRapidStrikeLevelUpLearnset,
        .teachableLearnset = sUrshifuRapidStrikeTeachableLearnset,
        .formSpeciesIdTable = sUrshifuFormSpeciesIdTable,
        .formChangeTable = sUrshifuRapidStrikeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_KUBFU


#if P_FAMILY_ZARUDE
    [SPECIES_ZARUDE] =
    {
        .baseHP        = 105,
        .baseAttack    = 120,
        .baseDefense   = 105,
        .baseSpeed     = 105,
        .baseSpAttack  = 70,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DARK, TYPE_GRASS),
        .catchRate = 3,
        .expYield = 300,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Zarude"),
#else
        .speciesName = _("ZARUDE"),
#endif
        .cryId = CRY_ZARUDE,
        .natDexNum = NATIONAL_DEX_ZARUDE,
#if GERMAN
        .categoryName = _("Finsteraffe"),
#else
        .categoryName = _("Rogue Monkey"),
#endif
        .height = 18,
        .weight = 700,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zarude leben gruppenweise in dichten\n"
        "Wäldern und werden von den anderen\n"
        "Pokémon dort gefürchtet, da sie sehr\n"
        "aggressiv sind."),
#else
            "Within dense forests, this Pokémon lives\n"
            "in a pack with others of its kind. It's\n"
            "incredibly aggressive, and the other\n"
            "Pokémon of the forest fear it."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Zarude,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Zarude,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Zarude,
        .shinyPalette = gMonShinyPalette_Zarude,
        .iconSprite = gMonIcon_Zarude,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 11, SHADOW_SIZE_L)
        FOOTPRINT(Zarude)
        OVERWORLD(
            sPicTable_Zarude,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zarude,
            gShinyOverworldPalette_Zarude
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZarudeLevelUpLearnset,
        .teachableLearnset = sZarudeTeachableLearnset,
        .formSpeciesIdTable = sZarudeFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_RANDOM_FORM,
    },

    [SPECIES_ZARUDE_DADA] =
    {
        .baseHP        = 105,
        .baseAttack    = 120,
        .baseDefense   = 105,
        .baseSpeed     = 105,
        .baseSpAttack  = 70,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DARK, TYPE_GRASS),
        .catchRate = 3,
        .expYield = 300,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Zarude"),
#else
        .speciesName = _("ZARUDE"),
#endif
        .cryId = CRY_ZARUDE,
        .natDexNum = NATIONAL_DEX_ZARUDE,
#if GERMAN
        .categoryName = _("Finsteraffe"),
#else
        .categoryName = _("Rogue Monkey"),
#endif
        .height = 18,
        .weight = 700,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Zarude hat seine\n"
        "Gruppe verlassen, um ein Menschenkind\n"
        "aufzuziehen. Es trägt ein Tuch, dessen\n"
        "Geruch das Kind beruhigt, wenn es weint."),
#else
            "This Zarude's special strength\n"
            "stems from its love and care for an\n"
            "orphaned human child that the Pokémon\n"
            "has raised."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_ZarudeDada,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZarudeDada,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZarudeDada,
        .shinyPalette = gMonShinyPalette_ZarudeDada,
        .iconSprite = gMonIcon_ZarudeDada,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 11, SHADOW_SIZE_L)
        FOOTPRINT(Zarude)
        OVERWORLD(
            sPicTable_ZarudeDada,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZarudeDada,
            gShinyOverworldPalette_ZarudeDada
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZarudeLevelUpLearnset,
        .teachableLearnset = sZarudeTeachableLearnset,
        .formSpeciesIdTable = sZarudeFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_ZARUDE

#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] =
    {
        .dexNotRequired = TRUE,
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 200,
        .baseSpAttack  = 100,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 3,
        .expYield = 290,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TRANSISTOR, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Regieleki"),
#else
        .speciesName = _("REGIELEKI"),
#endif
        .cryId = CRY_REGIELEKI,
        .natDexNum = NATIONAL_DEX_REGIELEKI,
#if GERMAN
        .categoryName = _("Elektron"),
#else
        .categoryName = _("Electron"),
#endif
        .height = 12,
        .weight = 1450,
        .description = COMPOUND_STRING(
#if GERMAN
        "Regieleki besteht aus gebündelter\n"
        "elektrischer Energie. Werden die Ringe\n"
        "an seinem Körper entfernt, setzt das\n"
        "angeblich seine verborgenen Kräfte frei."),
#else
            "This Pokémon is a cluster of electrical\n"
            "energy. It's said that removing the rings\n"
            "on Regieleki's body will unleash the\n"
            "Pokémon's latent power."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Regieleki,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Regieleki,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Regieleki,
        .shinyPalette = gMonShinyPalette_Regieleki,
        .iconSprite = gMonIcon_Regieleki,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 14, SHADOW_SIZE_S)
        FOOTPRINT(Regieleki)
        OVERWORLD(
            sPicTable_Regieleki,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regieleki,
            gShinyOverworldPalette_Regieleki
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRegielekiLevelUpLearnset,
        .teachableLearnset = sRegielekiTeachableLearnset,
    },
#endif //P_FAMILY_REGIELEKI

#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] =
    {
        .dexNotRequired = TRUE,
        .baseHP        = 200,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 3,
        .expYield = 290,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DRAGONS_MAW, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Regidrago"),
#else
        .speciesName = _("REGIDRAGO"),
#endif
        .cryId = CRY_REGIDRAGO,
        .natDexNum = NATIONAL_DEX_REGIDRAGO,
#if GERMAN
        .categoryName = _("Drachenkugel"),
#else
        .categoryName = _("Dragon Orb"),
#endif
        .height = 21,
        .weight = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Einer unbestätigten Theorie zufolge sind\n"
            "seine Arme wie der Kopf eines urzeitlichen\n"
            "Drachen-Pokémon geformt."),
#else
            "An academic theory proposes that\n"
            "Regidrago's arms were once the head of an\n"
            "ancient dragon Pokémon. The theory\n"
            "remains unproven."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Regidrago,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Regidrago,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Regidrago,
        .shinyPalette = gMonShinyPalette_Regidrago,
        .iconSprite = gMonIcon_Regidrago,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_M)
        FOOTPRINT(Regidrago)
        OVERWORLD(
            sPicTable_Regidrago,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regidrago,
            gShinyOverworldPalette_Regidrago
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sRegidragoLevelUpLearnset,
        .teachableLearnset = sRegidragoTeachableLearnset,
    },
#endif //P_FAMILY_REGIDRAGO

#if P_FAMILY_GLASTRIER
    [SPECIES_GLASTRIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 145,
        .baseDefense   = 130,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 3,
        .expYield = 290,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CHILLING_NEIGH, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Polaross"),
#else
        .speciesName = _("GLASTRIER"),
#endif
        .cryId = CRY_GLASTRIER,
        .natDexNum = NATIONAL_DEX_GLASTRIER,
#if GERMAN
        .categoryName = _("Wildblut"),
#else
        .categoryName = _("Wild Horse"),
#endif
        .height = 22,
        .weight = 8000,
        .description = COMPOUND_STRING(
#if GERMAN
        "Aus seinen Hufen verströmt es eisige\n"
        "Kälte. Dieses ungestüme Pokémon nimmt\n"
        "sich alles, was es will, mit roher Gewalt."),
#else
            "Glastrier emits intense cold from its\n"
            "hooves. It's also a belligerent Pokémon--\n"
            "anything it wants, it takes by force."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Glastrier,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Glastrier,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Glastrier,
        .shinyPalette = gMonShinyPalette_Glastrier,
        .iconSprite = gMonIcon_Glastrier,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 11, SHADOW_SIZE_L)
        FOOTPRINT(Glastrier)
        OVERWORLD(
            sPicTable_Glastrier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Glastrier,
            gShinyOverworldPalette_Glastrier
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sGlastrierLevelUpLearnset,
        .teachableLearnset = sGlastrierTeachableLearnset,
    },
#endif //P_FAMILY_GLASTRIER

#if P_FAMILY_SPECTRIER
    [SPECIES_SPECTRIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 130,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_GRIM_NEIGH, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Phantoross"),
#else
        .speciesName = _("SPECTRIER"),
#endif
        .cryId = CRY_SPECTRIER,
        .natDexNum = NATIONAL_DEX_SPECTRIER,
#if GERMAN
        .categoryName = _("Flinkblut"),
#else
        .categoryName = _("Swift Horse"),
#endif
        .height = 20,
        .weight = 445,
        .description = COMPOUND_STRING(
#if GERMAN
        "Um sein Umfeld zu erkunden,\n"
        "nutzt es all seine Sinne - bis auf\n"
        "den Sehsinn. Wer von Phantoross getreten\n"
        "wird, verliert angeblich seine Seele."),
#else
            "It probes its surroundings with all its\n"
            "senses save one--it doesn't use its sense\n"
            "of sight. Spectrier's kicks are said to\n"
            "separate soul from body."),
#endif
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Spectrier,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Spectrier,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Spectrier,
        .shinyPalette = gMonShinyPalette_Spectrier,
        .iconSprite = gMonIcon_Spectrier,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-6, 12, SHADOW_SIZE_L)
        FOOTPRINT(Spectrier)
        OVERWORLD(
            sPicTable_Spectrier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Spectrier,
            gShinyOverworldPalette_Spectrier
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sSpectrierLevelUpLearnset,
        .teachableLearnset = sSpectrierTeachableLearnset,
    },
#endif //P_FAMILY_SPECTRIER

#if P_FAMILY_CALYREX
    [SPECIES_CALYREX] =
    {
        .baseHP        = 100,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_GRASS),
        .catchRate = 3,
        .expYield = 250,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_UNNERVE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Coronospa"),
#else
        .speciesName = _("CALYREX"),
#endif
        .cryId = CRY_CALYREX,
        .natDexNum = NATIONAL_DEX_CALYREX,
#if GERMAN
        .categoryName = _("König"),
#else
        .categoryName = _("King"),
#endif
        .height = 11,
        .weight = 77,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein warmherziges Pokémon, das über\n"
        "heilende und segnende Kräfte verfügt."),
#else
            "Calyrex is a merciful Pokémon, capable of\n"
            "providing healing and blessings. It\n"
            "reigned over the Galar region in times\n"
            "of yore."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Calyrex,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Calyrex,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Calyrex,
        .shinyPalette = gMonShinyPalette_Calyrex,
        .iconSprite = gMonIcon_Calyrex,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_S)
        FOOTPRINT(Calyrex)
        OVERWORLD(
            sPicTable_Calyrex,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Calyrex,
            gShinyOverworldPalette_Calyrex
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sCalyrexLevelUpLearnset,
        .teachableLearnset = sCalyrexTeachableLearnset,
        .formSpeciesIdTable = sCalyrexFormSpeciesIdTable,
    },

#if P_FUSION_FORMS
    [SPECIES_CALYREX_ICE] =
    {
        .baseHP        = 100,
        .baseAttack    = 165,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 85,
        .baseSpDefense = 130,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_ICE),
        .catchRate = 3,
        .expYield = 340,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_AS_ONE_ICE_RIDER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Coronospa"),
#else
        .speciesName = _("CALYREX"),
#endif
        .cryId = CRY_CALYREX_ICE,
        .natDexNum = NATIONAL_DEX_CALYREX,
#if GERMAN
        .categoryName = _("Kaiser"),
#else
        .categoryName = _("High King"),
#endif
        .height = 24,
        .weight = 8091,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es zeigte jenen, die sich ihm in den Weg\n"
        "stellten, keine Gnade. Nach dem Kampf soll\n"
        "es allerdings die Wunden seiner Gegner\n"
        "geheilt haben."),
#else
            "According to lore, this Pokémon\n"
            "showed no mercy to those who got in\n"
            "its way, yet it would heal its\n"
            "opponents' wounds after battle."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CalyrexIce,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CalyrexIce,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CalyrexIce,
        .shinyPalette = gMonShinyPalette_CalyrexIce,
        .iconSprite = gMonIcon_CalyrexIce,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 11, SHADOW_SIZE_L)
        FOOTPRINT(Calyrex)
        OVERWORLD(
            sPicTable_CalyrexIce,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_CalyrexIce,
            gShinyOverworldPalette_CalyrexIce
        )
        .isRestrictedLegendary = TRUE,
        .cannotBeTraded = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sCalyrexIceLevelUpLearnset,
        .teachableLearnset = sCalyrexIceTeachableLearnset,
        .formSpeciesIdTable = sCalyrexFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_CALYREX_SHADOW] =
    {
        .baseHP        = 100,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 150,
        .baseSpAttack  = 165,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_GHOST),
        .catchRate = 3,
        .expYield = 340,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_AS_ONE_SHADOW_RIDER, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Coronospa"),
#else
        .speciesName = _("CALYREX"),
#endif
        .cryId = CRY_CALYREX_SHADOW,
        .natDexNum = NATIONAL_DEX_CALYREX,
#if GERMAN
        .categoryName = _("Kaiser"),
#else
        .categoryName = _("High King"),
#endif
        .height = 24,
        .weight = 536,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit seiner Kraft, alles von der\n"
        "Vergangenheit bis zur Zukunft zu sehen,\n"
        "soll es die Bewohner eines Waldes vor einem\n"
        "Meteoriten bewahrt haben."),
#else
            "It's said that Calyrex and a\n"
            "Pokémon that had bonded with it ran all\n"
            "across the Galar region to bring green\n"
            "to the wastelands."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CalyrexShadow,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CalyrexShadow,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CalyrexShadow,
        .shinyPalette = gMonShinyPalette_CalyrexShadow,
        .iconSprite = gMonIcon_CalyrexShadow,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_L)
        FOOTPRINT(Calyrex)
        OVERWORLD(
            sPicTable_CalyrexShadow,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_CalyrexShadow,
            gShinyOverworldPalette_CalyrexShadow
        )
        .isRestrictedLegendary = TRUE,
        .cannotBeTraded = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sCalyrexShadowLevelUpLearnset,
        .teachableLearnset = sCalyrexShadowTeachableLearnset,
        .formSpeciesIdTable = sCalyrexFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FUSION_FORMS
#endif //P_FAMILY_CALYREX

#if P_FAMILY_ENAMORUS
    [SPECIES_ENAMORUS_INCARNATE] =
    {
        .baseHP        = 74,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 106,
        .baseSpAttack  = 135,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_FLYING),
        .catchRate = 3,
        .expYield = 116,
        .evYield_SpAttack = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Cupidos"),
#else
        .speciesName = _("ENAMORUS"),
#endif
        .cryId = CRY_ENAMORUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_ENAMORUS,
#if GERMAN
        .categoryName = _("Hassliebe"),
#else
        .categoryName = _("Love-Hate"),
#endif
        .height = 16,
        .weight = 480,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kommt es übers Meer geflogen, neigt\n"
        "sich der harsche Winter dem Ende zu. Der\n"
        "Volksmund sagt, dass dank seiner Liebe\n"
        "neues Leben in Hisui Knospen treibe."),
#else
            "Its arrival brings an end to the winter.\n"
            "According to legend, this Pokémon's love\n"
            "gives rise to the budding of fresh life\n"
            "across the land."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_EnamorusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_EnamorusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EnamorusIncarnate,
        .shinyPalette = gMonShinyPalette_EnamorusIncarnate,
        .iconSprite = gMonIcon_EnamorusIncarnate,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 19, SHADOW_SIZE_M)
        FOOTPRINT(Enamorus)
        OVERWORLD(
            sPicTable_EnamorusIncarnate,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_EnamorusIncarnate,
            gShinyOverworldPalette_EnamorusIncarnate
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sEnamorusLevelUpLearnset,
        .teachableLearnset = sEnamorusTeachableLearnset,
        .formSpeciesIdTable = sEnamorusFormSpeciesIdTable,
        .formChangeTable = sEnamorusFormChangeTable,
    },

    [SPECIES_ENAMORUS_THERIAN] =
    {
        .baseHP        = 74,
        .baseAttack    = 115,
        .baseDefense   = 110,
        .baseSpeed     = 46,
        .baseSpAttack  = 135,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_FAIRY, TYPE_FLYING),
        .catchRate = 3,
        .expYield = 116,
        .evYield_SpAttack = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_OVERCOAT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Cupidos"),
#else
        .speciesName = _("ENAMORUS"),
#endif
        .cryId = CRY_ENAMORUS_THERIAN,
        .natDexNum = NATIONAL_DEX_ENAMORUS,
#if GERMAN
        .categoryName = _("Hassliebe"),
#else
        .categoryName = _("Love-Hate"),
#endif
        .height = 16,
        .weight = 480,
        .description = COMPOUND_STRING(
#if GERMAN
            "Es hat seine weibliche Gestalt abgelegt\n"
            "und stößt aus dem Wolkenmeer herab, um all\n"
            "jene mit unerbittlichem Zorn zu strafen,\n"
            "die das Leben anderer nicht achten."),
#else
            "From the clouds, it descends upon\n"
            "those who treat any form of life\n"
            "with disrespect and metes out\n"
            "wrathful, ruthless punishment."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_EnamorusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_EnamorusTherian,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EnamorusTherian,
        .shinyPalette = gMonShinyPalette_EnamorusTherian,
        .iconSprite = gMonIcon_EnamorusTherian,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_L)
        FOOTPRINT(Enamorus)
        OVERWORLD(
            sPicTable_EnamorusTherian,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_EnamorusTherian,
            gShinyOverworldPalette_EnamorusTherian
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sEnamorusLevelUpLearnset,
        .teachableLearnset = sEnamorusTeachableLearnset,
        .formSpeciesIdTable = sEnamorusFormSpeciesIdTable,
        .formChangeTable = sEnamorusFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_ENAMORUS

#ifdef __INTELLISENSE__
};
#endif
