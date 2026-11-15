#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen5[] =
{
#endif

#if P_FAMILY_VICTINI
    [SPECIES_VICTINI] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FIRE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_VICTORY_STAR, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Victini"),
#else
        .speciesName = _("VICTINI"),
#endif
        .cryId = CRY_VICTINI,
        .natDexNum = NATIONAL_DEX_VICTINI,
#if GERMAN
        .categoryName = _("Triumph"),
#else
        .categoryName = _("Victory"),
#endif
        .height = 4,
        .weight = 40,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein siegverheißendes Pokémon. Man sagt,\n"
        "Trainer, die ein Victini in ihrem Team haben,\n"
        "seien unschlagbar."),
#else
            "This Pokémon brings victory.\n"
            "It is said that Trainers with Victini\n"
            "always win, regardless of the type\n"
            "of encounter."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Victini,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 46),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS,
        .backPic = gMonBackPic_Victini,
        .backPicSize = MON_COORDS_SIZE(40, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Victini,
        .shinyPalette = gMonShinyPalette_Victini,
        .iconSprite = gMonIcon_Victini,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 4, SHADOW_SIZE_S)
        FOOTPRINT(Victini)
        OVERWORLD(
            sPicTable_Victini,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Victini,
            gShinyOverworldPalette_Victini
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sVictiniLevelUpLearnset,
        .teachableLearnset = sVictiniTeachableLearnset,
    },
#endif //P_FAMILY_VICTINI

#if P_FAMILY_SNIVY
    [SPECIES_SNIVY] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 63,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Serpifeu"),
#else
        .speciesName = _("SNIVY"),
#endif
        .cryId = CRY_SNIVY,
        .natDexNum = NATIONAL_DEX_SNIVY,
#if GERMAN
        .categoryName = _("Grasschlange"),
#else
        .categoryName = _("Grass Snake"),
#endif
        .height = 6,
        .weight = 81,
        .description = COMPOUND_STRING(
#if GERMAN
        "Im Sonnenlicht erhöht sich das Tempo\n"
        "seiner Bewegungen. Es ist mit seinen\n"
        "Schlingen geschickter als mit den Händen."),
#else
            "It is very intelligent and calm.\n"
            "Being exposed to lots of sunlight makes\n"
            "its movements swifter. When they are\n"
            "not feeling well, their tails droop."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Snivy,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Snivy,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Snivy,
        .shinyPalette = gMonShinyPalette_Snivy,
        .iconSprite = gMonIcon_Snivy,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Snivy)
        OVERWORLD(
            sPicTable_Snivy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Snivy,
            gShinyOverworldPalette_Snivy
        )
        .levelUpLearnset = sSnivyLevelUpLearnset,
        .teachableLearnset = sSnivyTeachableLearnset,
        .eggMoveLearnset = sSnivyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_SERVINE}),
    },

    [SPECIES_SERVINE] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 83,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = 145,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Efoserp"),
#else
        .speciesName = _("SERVINE"),
#endif
        .cryId = CRY_SERVINE,
        .natDexNum = NATIONAL_DEX_SERVINE,
#if GERMAN
        .categoryName = _("Grasschlange"),
#else
        .categoryName = _("Grass Snake"),
#endif
        .height = 8,
        .weight = 160,
        .description = COMPOUND_STRING(
#if GERMAN
        "Huscht beinahe gleitend über den Boden\n"
        "und täuscht Gegner mit agilen Manövern,\n"
        "bis es mithilfe seiner Efeurute obsiegt."),
#else
            "When it gets dirty, its leaves can't be\n"
            "used in photosynthesis, so it always keeps\n"
            "clean. They avoid attacks by sinking into\n"
            "the shadows of thick foliage."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Servine,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 7,
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
        .backPic = gMonBackPic_Servine,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Servine,
        .shinyPalette = gMonShinyPalette_Servine,
        .iconSprite = gMonIcon_Servine,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 7, SHADOW_SIZE_S)
        FOOTPRINT(Servine)
        OVERWORLD(
            sPicTable_Servine,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Servine,
            gShinyOverworldPalette_Servine
        )
        .levelUpLearnset = sServineLevelUpLearnset,
        .teachableLearnset = sServineTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SERPERIOR}),
    },

    [SPECIES_SERPERIOR] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 95,
        .baseSpeed     = 113,
        .baseSpAttack  = 75,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 264 : 238,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_GRASS),
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_CONTRARY },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Serpiroyal"),
#else
        .speciesName = _("SERPERIOR"),
#endif
        .cryId = CRY_SERPERIOR,
        .natDexNum = NATIONAL_DEX_SERPERIOR,
#if GERMAN
        .categoryName = _("Hoheit"),
#else
        .categoryName = _("Regal"),
#endif
        .height = 33,
        .weight = 630,
        .description = COMPOUND_STRING(
#if GERMAN
        "Im Kampf zeigt es nur Gegnern, die seinem\n"
        "edlen Blick standhalten, seine wahre\n"
        "Kraft."),
#else
            "They raise their heads to intimidate foes,\n"
            "but only give it their all when fighting\n"
            "powerful opponents who are not fazed\n"
            "by the glare from its noble eyes."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 405,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Serperior,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Serperior,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Serperior,
        .shinyPalette = gMonShinyPalette_Serperior,
        .iconSprite = gMonIcon_Serperior,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Serperior)
        OVERWORLD(
            sPicTable_Serperior,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Serperior,
            gShinyOverworldPalette_Serperior
        )
        .levelUpLearnset = sSerperiorLevelUpLearnset,
        .teachableLearnset = sSerperiorTeachableLearnset,
    },
#endif //P_FAMILY_SNIVY

#if P_FAMILY_TEPIG
    [SPECIES_TEPIG] =
    {
        .baseHP        = 65,
        .baseAttack    = 63,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 45,
        .expYield = 62,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Floink"),
#else
        .speciesName = _("TEPIG"),
#endif
        .cryId = CRY_TEPIG,
        .natDexNum = NATIONAL_DEX_TEPIG,
#if GERMAN
        .categoryName = _("Feuerferkel"),
#else
        .categoryName = _("Fire Pig"),
#endif
        .height = 5,
        .weight = 99,
        .description = COMPOUND_STRING(
#if GERMAN
        "Weicht flink gegnerischen Angriffen\n"
        "aus und schießt Flammen aus dem Rüssel,\n"
        "mit denen es gern auch mal Nüsse röstet."),
#else
            "It loves to eat roasted berries, but\n"
            "sometimes it gets too excited and burns\n"
            "them to a crisp. It blows fire through\n"
            "its nose."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tepig,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Tepig,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Tepig,
        .shinyPalette = gMonShinyPalette_Tepig,
        .iconSprite = gMonIcon_Tepig,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -2, SHADOW_SIZE_S)
        FOOTPRINT(Tepig)
        OVERWORLD(
            sPicTable_Tepig,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tepig,
            gShinyOverworldPalette_Tepig
        )
        .levelUpLearnset = sTepigLevelUpLearnset,
        .teachableLearnset = sTepigTeachableLearnset,
        .eggMoveLearnset = sTepigEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_PIGNITE}),
    },

    [SPECIES_PIGNITE] =
    {
        .baseHP        = 90,
        .baseAttack    = 93,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 146,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_THICK_FAT },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Ferkokel"),
#else
        .speciesName = _("PIGNITE"),
#endif
        .cryId = CRY_PIGNITE,
        .natDexNum = NATIONAL_DEX_PIGNITE,
#if GERMAN
        .categoryName = _("Feuerferkel"),
#else
        .categoryName = _("Fire Pig"),
#endif
        .height = 10,
        .weight = 555,
        .description = COMPOUND_STRING(
#if GERMAN
        "Je mehr es frisst, desto stärker\n"
        "werden die Flammen in seinem Magen.\n"
        "Dies führt zu rapiden Energieschüben."),
#else
            "The more it eats, the more fuel it has\n"
            "to make the fire in its stomach stronger.\n"
            "When it is angered, the intensity of the\n"
            "flame increases."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pignite,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Pignite,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Pignite,
        .shinyPalette = gMonShinyPalette_Pignite,
        .iconSprite = gMonIcon_Pignite,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_M)
        FOOTPRINT(Pignite)
        OVERWORLD(
            sPicTable_Pignite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pignite,
            gShinyOverworldPalette_Pignite
        )
        .levelUpLearnset = sPigniteLevelUpLearnset,
        .teachableLearnset = sPigniteTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_EMBOAR}),
    },

    [SPECIES_EMBOAR] =
    {
        .baseHP        = 110,
        .baseAttack    = 123,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 264 : 238,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Flambirex"),
#else
        .speciesName = _("EMBOAR"),
#endif
        .cryId = CRY_EMBOAR,
        .natDexNum = NATIONAL_DEX_EMBOAR,
#if GERMAN
        .categoryName = _("Feuerschwein"),
#else
        .categoryName = _("Fire Pig"),
#endif
        .height = 16,
        .weight = 1500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steckt mit dem Feuer um sein Kinn seine\n"
            "Fäuste in Brand und holt zu feurigen\n"
            "Fausthieben aus. Zeigt großen Teamgeist."),
#else
            "It is adept at using many different moves.\n"
            "It can throw a fire punch by setting its\n"
            "fists on fire with its fiery chin.\n"
            "It cares deeply about its friends."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Emboar,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 4),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Emboar,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Emboar,
        .shinyPalette = gMonShinyPalette_Emboar,
        .iconSprite = gMonIcon_Emboar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_L)
        FOOTPRINT(Emboar)
        OVERWORLD(
            sPicTable_Emboar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Emboar,
            gShinyOverworldPalette_Emboar
        )
        .levelUpLearnset = sEmboarLevelUpLearnset,
        .teachableLearnset = sEmboarTeachableLearnset,
        .formSpeciesIdTable = sEmboarFormSpeciesIdTable,
        .formChangeTable = sEmboarFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_EMBOAR_MEGA] =
    {
        .baseHP        = 110,
        .baseAttack    = 148,
        .baseDefense   = 75,
        .baseSpeed     = 75,
        .baseSpAttack  = 110,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_FIRE, TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 264,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Flambirex"),
#else
        .speciesName = _("EMBOAR"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_EMBOAR_MEGA,
    #else
        .cryId = CRY_EMBOAR,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_EMBOAR,
#if GERMAN
        .categoryName = _("Feuerferkel"),
#else
        .categoryName = _("Fire Pig"),
#endif
        .height = 18,
        .weight = 1803,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sind seine Gefährten in Not, eilt es ihnen\n"
        "zu Hilfe und schwingt dabei eine\n"
        "schlangenförmige Lanze aus lodernden\n"
        "Flammen."),
#else
            "Brandishing a blazing flame\n"
            "shaped like a serpentine spear,\n"
            "it rushes in to save its\n"
            "imperiled allies."),
#endif
        .frontPic = gMonFrontPic_EmboarMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_EmboarMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EmboarMega,
        .shinyPalette = gMonShinyPalette_EmboarMega,
        .iconSprite = gMonIcon_EmboarMega,
        .iconPalIndex = 5,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Emboar)
        SHADOW(-2, 14, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sEmboarLevelUpLearnset,
        .teachableLearnset = sEmboarTeachableLearnset,
        .formSpeciesIdTable = sEmboarFormSpeciesIdTable,
        .formChangeTable = sEmboarFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_TEPIG

#if P_FAMILY_OSHAWOTT
    [SPECIES_OSHAWOTT] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 63,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 62,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Ottaro"),
#else
        .speciesName = _("OSHAWOTT"),
#endif
        .cryId = CRY_OSHAWOTT,
        .natDexNum = NATIONAL_DEX_OSHAWOTT,
#if GERMAN
        .categoryName = _("Otter"),
#else
        .categoryName = _("Sea Otter"),
#endif
        .height = 5,
        .weight = 59,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Muschel an seinem Bauch dient\n"
        "ihm nicht nur als Waffe, sondern auch als\n"
        "Messer, mit dem es Beeren aufschneidet."),
#else
            "The scalchop on its stomach isn't just\n"
            "used for battle, it can be used to break\n"
            "open hard berries as well. It is made\n"
            "from the same element as its claws."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Oshawott,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 14,
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
        .backPic = gMonBackPic_Oshawott,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Oshawott,
        .shinyPalette = gMonShinyPalette_Oshawott,
        .iconSprite = gMonIcon_Oshawott,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 0, SHADOW_SIZE_S)
        FOOTPRINT(Oshawott)
        OVERWORLD(
            sPicTable_Oshawott,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Oshawott,
            gShinyOverworldPalette_Oshawott
        )
        .levelUpLearnset = sOshawottLevelUpLearnset,
        .teachableLearnset = sOshawottTeachableLearnset,
        .eggMoveLearnset = sOshawottEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_DEWOTT}),
    },

    [SPECIES_DEWOTT] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 83,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = 145,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Zwottronin"),
#else
        .speciesName = _("DEWOTT"),
#endif
        .cryId = CRY_DEWOTT,
        .natDexNum = NATIONAL_DEX_DEWOTT,
#if GERMAN
        .categoryName = _("Schulung"),
#else
        .categoryName = _("Discipline"),
#endif
        .height = 8,
        .weight = 245,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zwottronin eignet sich durch strenges\n"
            "Training elegant ineinander übergehende\n"
            "Attacken mit seinen zwei Muscheln an."),
#else
            "Strict training and disclipine leads it\n"
            "to master its flowing double-scalchop\n"
            "technique. Scalchop techniques differ\n"
            "from one Dewott to another."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dewott,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 28),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Dewott,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Dewott,
        .shinyPalette = gMonShinyPalette_Dewott,
        .iconSprite = gMonIcon_Dewott,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 6, SHADOW_SIZE_S)
        FOOTPRINT(Dewott)
        OVERWORLD(
            sPicTable_Dewott,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dewott,
            gShinyOverworldPalette_Dewott
        )
        .levelUpLearnset = sDewottLevelUpLearnset,
        .teachableLearnset = sDewottTeachableLearnset,
                            #if P_HISUIAN_FORMS
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SAMUROTT, CONDITIONS({IF_NOT_REGION, REGION_HISUI})}
                                ,{EVO_LEVEL, 36, SPECIES_SAMUROTT_HISUI, CONDITIONS({IF_REGION, REGION_HISUI})}
                            ),
                            #else
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SAMUROTT}),
                            #endif
    },

    [SPECIES_SAMUROTT] =
    {
        .baseHP        = 95,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 70,
        .baseSpAttack  = 108,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 264 : 238,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Admurai"),
#else
        .speciesName = _("SAMUROTT"),
#endif
        .cryId = CRY_SAMUROTT,
        .natDexNum = NATIONAL_DEX_SAMUROTT,
#if GERMAN
        .categoryName = _("Würde"),
#else
        .categoryName = _("Formidable"),
#endif
        .height = 15,
        .weight = 946,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ehe man sichs versieht, hat es schon\n"
        "das Langschwert aus seinen Vorderbeinen\n"
        "gezogen und seinen Gegner besiegt."),
#else
            "One swing of the seamitars attached\n"
            "to its armor can fell an opponent.\n"
            "A simple glare from one of them is\n"
            "enough to intimidate most enemies."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Samurott,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Samurott,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Samurott,
        .shinyPalette = gMonShinyPalette_Samurott,
        .iconSprite = gMonIcon_Samurott,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Samurott)
        OVERWORLD(
            sPicTable_Samurott,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Samurott,
            gShinyOverworldPalette_Samurott
        )
        .levelUpLearnset = sSamurottLevelUpLearnset,
        .teachableLearnset = sSamurottTeachableLearnset,
        .formSpeciesIdTable = sSamurottFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_SAMUROTT_HISUI] =
    {
        .baseHP        = 90,
        .baseAttack    = 108,
        .baseDefense   = 80,
        .baseSpeed     = 85,
        .baseSpAttack  = 100,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_DARK),
        .catchRate = 45,
        .expYield = 264,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SHARPNESS },
        .bodyColor = BODY_COLOR_BLUE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Admurai-H"),
#else
        .speciesName = _("SAMUROTT-H"),
#endif
#else
#if GERMAN
        .speciesName = _("Admurai"),
#else
        .speciesName = _("SAMUROTT"),
#endif
#endif
        .cryId = CRY_SAMUROTT,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_SAMUROTT_HISUI,
#else
        .natDexNum = NATIONAL_DEX_SAMUROTT,
#endif
#if GERMAN
        .categoryName = _("Würde"),
#else
        .categoryName = _("Formidable"),
#endif
        .height = 15,
        .weight = 582,
        .description = COMPOUND_STRING(
#if GERMAN
            "Unbarmherzig und meisterhaft mit dem\n"
            "Schwert lässt es seine Hiebe auf Gegner\n"
            "niedergehen wie Wellen in der Brandung.\n"
            "Diese seltene Form entstand in Hisui."),
#else
            "Hard of heart and deft of blade,\n"
            "this rare form of Samurott is a\n"
            "product of the Pokémon's evolution in the\n"
            "region of Hisui."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_SamurottHisui,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SamurottHisui,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_SamurottHisui,
        .shinyPalette = gMonShinyPalette_SamurottHisui,
        .iconSprite = gMonIcon_SamurottHisui,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_L)
        FOOTPRINT(Samurott)
        OVERWORLD(
            sPicTable_SamurottHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SamurottHisui,
            gShinyOverworldPalette_SamurottHisui
        )
        .isHisuianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sSamurottHisuiLevelUpLearnset,
        .teachableLearnset = sSamurottHisuiTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sSamurottHisuiFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sSamurottFormSpeciesIdTable,
#endif
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_OSHAWOTT

#if P_FAMILY_PATRAT
    [SPECIES_PATRAT] =
    {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 39,
        .baseSpeed     = 42,
        .baseSpAttack  = 35,
        .baseSpDefense = 39,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 51,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KEEN_EYE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Nagelotz"),
#else
        .speciesName = _("PATRAT"),
#endif
        .cryId = CRY_PATRAT,
        .natDexNum = NATIONAL_DEX_PATRAT,
#if GERMAN
        .categoryName = _("Späher"),
#else
        .categoryName = _("Scout"),
#endif
        .height = 5,
        .weight = 116,
        .description = COMPOUND_STRING(
#if GERMAN
        "Hortet in seinen Backentaschen Futter,\n"
        "um tagelang Wache stehen zu können, und\n"
        "gibt Kameraden über seine Rute Signale."),
#else
            "Extremely cautious, they take shifts to\n"
            "maintain a constant watch of their nest.\n"
            "Using food stored in cheek pouches,\n"
            "they can keep watch for days."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Patrat,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Patrat,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Patrat,
        .shinyPalette = gMonShinyPalette_Patrat,
        .iconSprite = gMonIcon_Patrat,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Patrat)
        OVERWORLD(
            sPicTable_Patrat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Patrat,
            gShinyOverworldPalette_Patrat
        )
        .levelUpLearnset = sPatratLevelUpLearnset,
        .teachableLearnset = sPatratTeachableLearnset,
        .eggMoveLearnset = sPatratEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_WATCHOG}),
    },

    [SPECIES_WATCHOG] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 69,
        .baseSpeed     = 77,
        .baseSpAttack  = 60,
        .baseSpDefense = 69,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_ILLUMINATE, ABILITY_KEEN_EYE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Kukmarda"),
#else
        .speciesName = _("WATCHOG"),
#endif
        .cryId = CRY_WATCHOG,
        .natDexNum = NATIONAL_DEX_WATCHOG,
#if GERMAN
        .categoryName = _("Wachsamkeit"),
#else
        .categoryName = _("Lookout"),
#endif
        .height = 11,
        .weight = 270,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kukmarda kann mit einer körpereigenen\n"
            "Substanz seine Augen und seinen Torso\n"
            "aufleuchten lassen, um Gegner zu\n"
            "erschrecken."),
#else
            "Using luminescent matter, it makes its\n"
            "eyes and body glow and stuns attacking\n"
            "opponents. Keen eyesight lets them see\n"
            "in the dark."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Watchog,
        .frontPicSize = MON_COORDS_SIZE(32, 64),
        .frontPicYOffset = 2,
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
        .backPic = gMonBackPic_Watchog,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Watchog,
        .shinyPalette = gMonShinyPalette_Watchog,
        .iconSprite = gMonIcon_Watchog,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 11, SHADOW_SIZE_S)
        FOOTPRINT(Watchog)
        OVERWORLD(
            sPicTable_Watchog,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Watchog,
            gShinyOverworldPalette_Watchog
        )
        .levelUpLearnset = sWatchogLevelUpLearnset,
        .teachableLearnset = sWatchogTeachableLearnset,
    },
#endif //P_FAMILY_PATRAT

#if P_FAMILY_LILLIPUP
    [SPECIES_LILLIPUP] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 55,
        .baseSpAttack  = 25,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 55,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_VITAL_SPIRIT, ABILITY_PICKUP, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Yorkleff"),
#else
        .speciesName = _("LILLIPUP"),
#endif
        .cryId = CRY_LILLIPUP,
        .natDexNum = NATIONAL_DEX_LILLIPUP,
#if GERMAN
        .categoryName = _("Welpe"),
#else
        .categoryName = _("Puppy"),
#endif
        .height = 4,
        .weight = 41,
        .description = COMPOUND_STRING(
#if GERMAN
        "Das lange Fell um sein Gesicht\n"
        "fungiert als Hightech-Radar, mit dem es\n"
        "fein säuberlich seine Umgebung abtastet."),
#else
            "It faces strong opponents with great\n"
            "courage. Because it doesn't yelp, it's\n"
            "extremely popular with Trainers who live\n"
            "in apartment buildings."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lillipup,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 12,
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
        .backPic = gMonBackPic_Lillipup,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Lillipup,
        .shinyPalette = gMonShinyPalette_Lillipup,
        .iconSprite = gMonIcon_Lillipup,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 1, SHADOW_SIZE_S)
        FOOTPRINT(Lillipup)
        OVERWORLD(
            sPicTable_Lillipup,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lillipup,
            gShinyOverworldPalette_Lillipup
        )
        .levelUpLearnset = sLillipupLevelUpLearnset,
        .teachableLearnset = sLillipupTeachableLearnset,
        .eggMoveLearnset = sLillipupEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_HERDIER}),
    },

    [SPECIES_HERDIER] =
    {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 120,
        .expYield = 130,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Terribark"),
#else
        .speciesName = _("HERDIER"),
#endif
        .cryId = CRY_HERDIER,
        .natDexNum = NATIONAL_DEX_HERDIER,
#if GERMAN
        .categoryName = _("Treuhund"),
#else
        .categoryName = _("Loyal Dog"),
#endif
        .height = 9,
        .weight = 147,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses äußerst treue Pokémon geht nicht\n"
        "nur seinem Trainer zur Hand, sondern hilft\n"
        "auch anderen Pokémon."),
#else
            "Its dense black fur grows continuously.\n"
            "The high cost of keeping its hard fur\n"
            "properly groomed makes this a\n"
            "troublesome Pokémon to train."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Herdier,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Herdier,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Herdier,
        .shinyPalette = gMonShinyPalette_Herdier,
        .iconSprite = gMonIcon_Herdier,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 5, SHADOW_SIZE_M)
        FOOTPRINT(Herdier)
        OVERWORLD(
            sPicTable_Herdier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Herdier,
            gShinyOverworldPalette_Herdier
        )
        .levelUpLearnset = sHerdierLevelUpLearnset,
        .teachableLearnset = sHerdierTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_STOUTLAND}),
    },

    [SPECIES_STOUTLAND] =
    {
        .baseHP        = 85,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 110 : 100,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 250,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 225,
    #else
        .expYield = 221,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_SAND_RUSH, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Bissbark"),
#else
        .speciesName = _("STOUTLAND"),
#endif
        .cryId = CRY_STOUTLAND,
        .natDexNum = NATIONAL_DEX_STOUTLAND,
#if GERMAN
        .categoryName = _("Großmut"),
#else
        .categoryName = _("Big-Hearted"),
#endif
        .height = 12,
        .weight = 610,
        .description = COMPOUND_STRING(
#if GERMAN
        "Bissbark rettet Menschen, die aufgrund\n"
        "eines Schneesturmes im Gebirge\n"
        "festsitzen. Sein langes Fell schützt es\n"
        "vor Kälte."),
#else
            "Intelligent, good-natured, and valiant,\n"
            "there could be no concern that it would\n"
            "ever attack people. Some parents even\n"
            "trust it to babysit."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Stoutland,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Stoutland,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Stoutland,
        .shinyPalette = gMonShinyPalette_Stoutland,
        .iconSprite = gMonIcon_Stoutland,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 9, SHADOW_SIZE_L)
        FOOTPRINT(Stoutland)
        OVERWORLD(
            sPicTable_Stoutland,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Stoutland,
            gShinyOverworldPalette_Stoutland
        )
        .levelUpLearnset = sStoutlandLevelUpLearnset,
        .teachableLearnset = sStoutlandTeachableLearnset,
    },
#endif //P_FAMILY_LILLIPUP

#if P_FAMILY_PURRLOIN
    [SPECIES_PURRLOIN] =
    {
        .baseHP        = 41,
        .baseAttack    = 50,
        .baseDefense   = 37,
        .baseSpeed     = 66,
        .baseSpAttack  = 50,
        .baseSpDefense = 37,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Felilou"),
#else
        .speciesName = _("PURRLOIN"),
#endif
        .cryId = CRY_PURRLOIN,
        .natDexNum = NATIONAL_DEX_PURRLOIN,
#if GERMAN
        .categoryName = _("Schelm"),
#else
        .categoryName = _("Devious"),
#endif
        .height = 4,
        .weight = 101,
        .description = COMPOUND_STRING(
#if GERMAN
        "Felilou lenkt die Menschen durch sein\n"
        "süßes Verhalten ab, um sie zu bestehlen.\n"
        "Ist es wütend, kratzt es gern mal."),
#else
            "Their deceptively cute act is the\n"
            "perfect ruse. They steal from people for\n"
            "fun, but their victims can't help but\n"
            "forgive them."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Purrloin,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 9),
            ANIMCMD_FRAME(1, 54),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Purrloin,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Purrloin,
        .shinyPalette = gMonShinyPalette_Purrloin,
        .iconSprite = gMonIcon_Purrloin,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Purrloin)
        OVERWORLD(
            sPicTable_Purrloin,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Purrloin,
            gShinyOverworldPalette_Purrloin
        )
        .levelUpLearnset = sPurrloinLevelUpLearnset,
        .teachableLearnset = sPurrloinTeachableLearnset,
        .eggMoveLearnset = sPurrloinEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_LIEPARD}),
    },

    [SPECIES_LIEPARD] =
    {
        .baseHP        = 64,
        .baseAttack    = 88,
        .baseDefense   = 50,
        .baseSpeed     = 106,
        .baseSpAttack  = 88,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 90,
        .expYield = 156,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Kleoparda"),
#else
        .speciesName = _("LIEPARD"),
#endif
        .cryId = CRY_LIEPARD,
        .natDexNum = NATIONAL_DEX_LIEPARD,
#if GERMAN
        .categoryName = _("Gefühlskälte"),
#else
        .categoryName = _("Cruel"),
#endif
        .height = 11,
        .weight = 375,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kleopardas anmutiges Auftreten verdankt\n"
        "es den Muskeln, die es entwickelt\n"
        "hat. Es prescht lautlos durch die Nacht."),
#else
            "Many Trainers are drawn to their\n"
            "beautiful form and fur. These Pokémon\n"
            "vanish and appear unexpectedly.\n"
            "They run silently in the night."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Liepard,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Liepard,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Liepard,
        .shinyPalette = gMonShinyPalette_Liepard,
        .iconSprite = gMonIcon_Liepard,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_M)
        FOOTPRINT(Liepard)
        OVERWORLD(
            sPicTable_Liepard,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Liepard,
            gShinyOverworldPalette_Liepard
        )
        .levelUpLearnset = sLiepardLevelUpLearnset,
        .teachableLearnset = sLiepardTeachableLearnset,
    },
#endif //P_FAMILY_PURRLOIN

#if P_FAMILY_PANSAGE
    [SPECIES_PANSAGE] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_OVERGROW },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Vegimak"),
#else
        .speciesName = _("PANSAGE"),
#endif
        .cryId = CRY_PANSAGE,
        .natDexNum = NATIONAL_DEX_PANSAGE,
#if GERMAN
        .categoryName = _("Grasaffe"),
#else
        .categoryName = _("Grass Monkey"),
#endif
        .height = 6,
        .weight = 105,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schwächelnden Pokémon gibt\n"
        "es ein paar der Kräuter auf seinem Kopf\n"
        "ab und hilft ihnen so wieder auf die Beine."),
#else
            "This Pokémon dwells deep in the forest.\n"
            "It's good at finding berries and gathers\n"
            "them from all over. It's kind enough to\n"
            "share them with friends."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pansage,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 13),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Pansage,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Pansage,
        .shinyPalette = gMonShinyPalette_Pansage,
        .iconSprite = gMonIcon_Pansage,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 3, SHADOW_SIZE_S)
        FOOTPRINT(Pansage)
        OVERWORLD(
            sPicTable_Pansage,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pansage,
            gShinyOverworldPalette_Pansage
        )
        .levelUpLearnset = sPansageLevelUpLearnset,
        .teachableLearnset = sPansageTeachableLearnset,
        .eggMoveLearnset = sPansageEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_LEAF_STONE, SPECIES_SIMISAGE}),
    },

    [SPECIES_SIMISAGE] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_OVERGROW },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Vegichita"),
#else
        .speciesName = _("SIMISAGE"),
#endif
        .cryId = CRY_SIMISAGE,
        .natDexNum = NATIONAL_DEX_SIMISAGE,
#if GERMAN
        .categoryName = _("Stachelaffe"),
#else
        .categoryName = _("Thorn Monkey"),
#endif
        .height = 11,
        .weight = 305,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wer sich mit diesem temperamentvollen\n"
        "Pokémon anlegt, bekommt seinen\n"
        "mit Dornen bestückten Schweif zu spüren."),
#else
            "Ill tempered, it attacks enemies by\n"
            "swinging its barbed tail around wildly.\n"
            "The leaf growing on its head is\n"
            "very bitter."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Simisage,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Simisage,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Simisage,
        .shinyPalette = gMonShinyPalette_Simisage,
        .iconSprite = gMonIcon_Simisage,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_M)
        FOOTPRINT(Simisage)
        OVERWORLD(
            sPicTable_Simisage,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Simisage,
            gShinyOverworldPalette_Simisage
        )
        .levelUpLearnset = sSimisageLevelUpLearnset,
        .teachableLearnset = sSimisageTeachableLearnset,
    },
#endif //P_FAMILY_PANSAGE

#if P_FAMILY_PANSEAR
    [SPECIES_PANSEAR] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_BLAZE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Grillmak"),
#else
        .speciesName = _("PANSEAR"),
#endif
        .cryId = CRY_PANSEAR,
        .natDexNum = NATIONAL_DEX_PANSEAR,
#if GERMAN
        .categoryName = _("Hitze"),
#else
        .categoryName = _("High Temp"),
#endif
        .height = 6,
        .weight = 110,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein kultiviertes Pokémon, das\n"
        "Beeren vor dem Verzehr stets anbrät. Es\n"
        "bietet den Menschen gerne seine Hilfe an."),
#else
            "The fire within the tuft on its head can\n"
            "reach up to 600ºF. Very intelligent,\n"
            "it roasts berries before eating them.\n"
            "It likes to help people."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pansear,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Pansear,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Pansear,
        .shinyPalette = gMonShinyPalette_Pansear,
        .iconSprite = gMonIcon_Pansear,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, 3, SHADOW_SIZE_S)
        FOOTPRINT(Pansear)
        OVERWORLD(
            sPicTable_Pansear,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pansear,
            gShinyOverworldPalette_Pansear
        )
        .levelUpLearnset = sPansearLevelUpLearnset,
        .teachableLearnset = sPansearTeachableLearnset,
        .eggMoveLearnset = sPansearEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_FIRE_STONE, SPECIES_SIMISEAR}),
    },

    [SPECIES_SIMISEAR] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_BLAZE },
        .bodyColor = BODY_COLOR_RED,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Grillchita"),
#else
        .speciesName = _("SIMISEAR"),
#endif
        .cryId = CRY_SIMISEAR,
        .natDexNum = NATIONAL_DEX_SIMISEAR,
#if GERMAN
        .categoryName = _("Funkenregen"),
#else
        .categoryName = _("Ember"),
#endif
        .height = 10,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
        "Grillchita entfacht in seinem\n"
        "Körper ein Feuer und verkohlt Gegner\n"
        "mit Funken aus seinem Kopf und Schweif."),
#else
            "It loves sweets because they become\n"
            "energy for the fire burning inside its\n"
            "body. It scatters embers from its head\n"
            "and tail to sear its opponents."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Simisear,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        .backPic = gMonBackPic_Simisear,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Simisear,
        .shinyPalette = gMonShinyPalette_Simisear,
        .iconSprite = gMonIcon_Simisear,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Simisear)
        OVERWORLD(
            sPicTable_Simisear,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Simisear,
            gShinyOverworldPalette_Simisear
        )
        .levelUpLearnset = sSimisearLevelUpLearnset,
        .teachableLearnset = sSimisearTeachableLearnset,
    },
#endif //P_FAMILY_PANSEAR

#if P_FAMILY_PANPOUR
    [SPECIES_PANPOUR] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 48,
        .baseSpeed     = 64,
        .baseSpAttack  = 53,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_TORRENT },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Sodamak"),
#else
        .speciesName = _("PANPOUR"),
#endif
        .cryId = CRY_PANPOUR,
        .natDexNum = NATIONAL_DEX_PANPOUR,
#if GERMAN
        .categoryName = _("Wasserstrahl"),
#else
        .categoryName = _("Spray"),
#endif
        .height = 6,
        .weight = 135,
        .description = COMPOUND_STRING(
#if GERMAN
        "Das Büschel auf seinem Kopf enthält\n"
        "eine sehr nahrhafte Flüssigkeit, mit der\n"
        "es über seinen Schweif Pflanzen wässert."),
#else
            "The water stored inside the tuft of its\n"
            "head is rich in nutrients. It waters\n"
            "plants using its tail, plants that\n"
            "receive its water grow large."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Panpour,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Panpour,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Panpour,
        .shinyPalette = gMonShinyPalette_Panpour,
        .iconSprite = gMonIcon_Panpour,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, 4, SHADOW_SIZE_S)
        FOOTPRINT(Panpour)
        OVERWORLD(
            sPicTable_Panpour,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Panpour,
            gShinyOverworldPalette_Panpour
        )
        .levelUpLearnset = sPanpourLevelUpLearnset,
        .teachableLearnset = sPanpourTeachableLearnset,
        .eggMoveLearnset = sPanpourEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_WATER_STONE, SPECIES_SIMIPOUR}),
    },

    [SPECIES_SIMIPOUR] =
    {
        .baseHP        = 75,
        .baseAttack    = 98,
        .baseDefense   = 63,
        .baseSpeed     = 101,
        .baseSpAttack  = 98,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_NONE, ABILITY_TORRENT },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Sodachita"),
#else
        .speciesName = _("SIMIPOUR"),
#endif
        .cryId = CRY_SIMIPOUR,
        .natDexNum = NATIONAL_DEX_SIMIPOUR,
#if GERMAN
        .categoryName = _("Drainage"),
#else
        .categoryName = _("Geyser"),
#endif
        .height = 10,
        .weight = 290,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sodachita schießt mit so hohem\n"
        "Druck Wasser aus seinem Schweif, dass\n"
        "selbst Betonwände den Kürzeren ziehen."),
#else
            "It can shoot highly-pressurised water\n"
            "from its tail with enough power to\n"
            "break through a solid concrete wall.\n"
            "It prefers places with clean water."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Simipour,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Simipour,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Simipour,
        .shinyPalette = gMonShinyPalette_Simipour,
        .iconSprite = gMonIcon_Simipour,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Simipour)
        OVERWORLD(
            sPicTable_Simipour,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Simipour,
            gShinyOverworldPalette_Simipour
        )
        .levelUpLearnset = sSimipourLevelUpLearnset,
        .teachableLearnset = sSimipourTeachableLearnset,
    },
#endif //P_FAMILY_PANPOUR

#if P_FAMILY_MUNNA
    [SPECIES_MUNNA] =
    {
        .baseHP        = 76,
        .baseAttack    = 25,
        .baseDefense   = 45,
        .baseSpeed     = 24,
        .baseSpAttack  = 67,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 190,
        .expYield = 58,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FOREWARN, ABILITY_SYNCHRONIZE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Somniam"),
#else
        .speciesName = _("MUNNA"),
#endif
        .cryId = CRY_MUNNA,
        .natDexNum = NATIONAL_DEX_MUNNA,
#if GERMAN
        .categoryName = _("Traumfresser"),
#else
        .categoryName = _("Dream Eater"),
#endif
        .height = 6,
        .weight = 233,
        .description = COMPOUND_STRING(
#if GERMAN
        "Somniam erscheint vor schlafenden\n"
        "Menschen und Pokémon und frisst ihre\n"
        "Alpträume."),
#else
            "This Pokémon appears before people\n"
            "and Pokémon who are having nightmares\n"
            "and eats those dreams. Munna always\n"
            "float in the air. "),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Munna,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = 16,
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
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Munna,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Munna,
        .shinyPalette = gMonShinyPalette_Munna,
        .iconSprite = gMonIcon_Munna,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Munna)
        OVERWORLD(
            sPicTable_Munna,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Munna,
            gShinyOverworldPalette_Munna
        )
        .levelUpLearnset = sMunnaLevelUpLearnset,
        .teachableLearnset = sMunnaTeachableLearnset,
        .eggMoveLearnset = sMunnaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_MOON_STONE, SPECIES_MUSHARNA}),
    },

    [SPECIES_MUSHARNA] =
    {
        .baseHP        = 116,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 29,
        .baseSpAttack  = 107,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 75,
        .expYield = 170,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_FOREWARN, ABILITY_SYNCHRONIZE, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Somnivora"),
#else
        .speciesName = _("MUSHARNA"),
#endif
        .cryId = CRY_MUSHARNA,
        .natDexNum = NATIONAL_DEX_MUSHARNA,
#if GERMAN
        .categoryName = _("Halbschlaf"),
#else
        .categoryName = _("Drowsing"),
#endif
        .height = 11,
        .weight = 605,
        .description = COMPOUND_STRING(
#if GERMAN
        "Der Dunst, der aus seiner Stirn tritt,\n"
        "enthält die Träume unzähliger Menschen\n"
        "und Pokémon."),
#else
            "The mist emanating from their foreheads\n"
            "is packed with the dreams of people and\n"
            "Pokémon. It changes into different colors\n"
            "depending on the dream that was eaten."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Musharna,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_ROTATE_TO_SIDES_TWICE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Musharna,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Musharna,
        .shinyPalette = gMonShinyPalette_Musharna,
        .iconSprite = gMonIcon_Musharna,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 10, SHADOW_SIZE_M)
        FOOTPRINT(Musharna)
        OVERWORLD(
            sPicTable_Musharna,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Musharna,
            gShinyOverworldPalette_Musharna
        )
        .levelUpLearnset = sMusharnaLevelUpLearnset,
        .teachableLearnset = sMusharnaTeachableLearnset,
    },
#endif //P_FAMILY_MUNNA

#if P_FAMILY_PIDOVE
    [SPECIES_PIDOVE] =
    {
        .baseHP        = 50,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 43,
        .baseSpAttack  = 36,
        .baseSpDefense = 30,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 255,
        .expYield = 53,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Dusselgurr"),
#else
        .speciesName = _("PIDOVE"),
#endif
        .cryId = CRY_PIDOVE,
        .natDexNum = NATIONAL_DEX_PIDOVE,
#if GERMAN
        .categoryName = _("Täubchen"),
#else
        .categoryName = _("Tiny Pigeon"),
#endif
        .height = 3,
        .weight = 21,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wartet oft vergeblich auf Anweisungen,\n"
        "obwohl es bereits einen Befehl erhalten\n"
        "hat. Ein sehr zerstreutes Pokémon."),
#else
            "This very forgetful Pokémon will wait for\n"
            "a new order from its Trainer even though\n"
            "it already has one. Flocks often gather\n"
            "in parks and plazas."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pidove,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 46),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Pidove,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Pidove,
        .shinyPalette = gMonShinyPalette_Pidove,
        .iconSprite = gMonIcon_Pidove,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 1, SHADOW_SIZE_S)
        FOOTPRINT(Pidove)
        OVERWORLD(
            sPicTable_Pidove,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pidove,
            gShinyOverworldPalette_Pidove
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sPidoveLevelUpLearnset,
        .teachableLearnset = sPidoveTeachableLearnset,
        .eggMoveLearnset = sPidoveEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 21, SPECIES_TRANQUILL}),
    },

    [SPECIES_TRANQUILL] =
    {
        .baseHP        = 62,
        .baseAttack    = 77,
        .baseDefense   = 62,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 42,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 120,
        .expYield = 125,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Navitaub"),
#else
        .speciesName = _("TRANQUILL"),
#endif
        .cryId = CRY_TRANQUILL,
        .natDexNum = NATIONAL_DEX_TRANQUILL,
#if GERMAN
        .categoryName = _("Wildtaube"),
#else
        .categoryName = _("Wild Pigeon"),
#endif
        .height = 6,
        .weight = 150,
        .description = COMPOUND_STRING(
#if GERMAN
        "Viele Leute glauben, dass es tief\n"
        "in seinem heimatlichen Wald ein Land der\n"
        "Harmonie gibt, wo man keine Kriege kennt."),
#else
            "No matter where in the world it goes,\n"
            "it knows where its nest is, so it can\n"
            "always return to its Trainer's location\n"
            "regardless of the distance."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tranquill,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Tranquill,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Tranquill,
        .shinyPalette = gMonShinyPalette_Tranquill,
        .iconSprite = gMonIcon_Tranquill,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 6, SHADOW_SIZE_S)
        FOOTPRINT(Tranquill)
        OVERWORLD(
            sPicTable_Tranquill,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tranquill,
            gShinyOverworldPalette_Tranquill
        )
        .levelUpLearnset = sTranquillLevelUpLearnset,
        .teachableLearnset = sTranquillTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_UNFEZANT}),
    },

    [SPECIES_UNFEZANT] =
    {
        .baseHP        = 80,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 115 : 105,
        .baseDefense   = 80,
        .baseSpeed     = 93,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 244,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 220,
    #else
        .expYield = 215,
    #endif
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_BIG_PECKS, ABILITY_SUPER_LUCK, ABILITY_RIVALRY },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Fasasnob"),
#else
        .speciesName = _("UNFEZANT"),
#endif
        .cryId = CRY_UNFEZANT,
        .natDexNum = NATIONAL_DEX_UNFEZANT,
#if GERMAN
        .categoryName = _("Stolz"),
#else
        .categoryName = _("Proud"),
#endif
        .height = 12,
        .weight = 290,
        .description = COMPOUND_STRING(
#if GERMAN
        "Männchen schrecken Gegner ab, indem sie\n"
        "ihren Kopfschmuck schütteln. Weibchen\n"
        "verfügen über bessere Flugfertigkeiten."),
#else
            "Males have plumage on their heads.\n"
            "The females' flying abilities surpass\n"
            "those of the males. They will only let\n"
            "themselves feel close to their Trainers."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Unfezant,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Unfezant,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Unfezant,
        .shinyPalette = gMonShinyPalette_Unfezant,
        .iconSprite = gMonIcon_Unfezant,
        .iconPalIndex = 1,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_UnfezantF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 64),
        .backPicFemale = gMonBackPic_UnfezantF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .paletteFemale = gMonPalette_UnfezantF,
        .shinyPaletteFemale = gMonShinyPalette_UnfezantF,
        .iconSpriteFemale = gMonIcon_UnfezantF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_M)
        FOOTPRINT(Unfezant)
        OVERWORLD(
            sPicTable_Unfezant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Unfezant,
            gShinyOverworldPalette_Unfezant
        )
        OVERWORLD_FEMALE(
            sPicTable_UnfezantF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_UnfezantF,
            gShinyOverworldPalette_UnfezantF
        )
        .levelUpLearnset = sUnfezantLevelUpLearnset,
        .teachableLearnset = sUnfezantTeachableLearnset,
    },
#endif //P_FAMILY_PIDOVE

#if P_FAMILY_BLITZLE
    [SPECIES_BLITZLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 32,
        .baseSpeed     = 76,
        .baseSpAttack  = 50,
        .baseSpDefense = 32,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_MOTOR_DRIVE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Elezeba"),
#else
        .speciesName = _("BLITZLE"),
#endif
        .cryId = CRY_BLITZLE,
        .natDexNum = NATIONAL_DEX_BLITZLE,
#if GERMAN
        .categoryName = _("Hochspannung"),
#else
        .categoryName = _("Electrified"),
#endif
        .height = 8,
        .weight = 298,
        .description = COMPOUND_STRING(
#if GERMAN
        "Elezeba erscheint, wenn Gewitterwolken\n"
        "den Himmel verdunkeln. Es fängt mit seiner\n"
        "Mähne Blitze und hortet ihre Energie."),
#else
            "Its mane shines when it discharges\n"
            "electricity. They use the frequency and\n"
            "rhythm of these flashes to communicate\n"
            "with one another."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Blitzle,
        .frontPicSize = MON_COORDS_SIZE(40, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Blitzle,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Blitzle,
        .shinyPalette = gMonShinyPalette_Blitzle,
        .iconSprite = gMonIcon_Blitzle,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_M)
        FOOTPRINT(Blitzle)
        OVERWORLD(
            sPicTable_Blitzle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Blitzle,
            gShinyOverworldPalette_Blitzle
        )
        .levelUpLearnset = sBlitzleLevelUpLearnset,
        .teachableLearnset = sBlitzleTeachableLearnset,
        .eggMoveLearnset = sBlitzleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 27, SPECIES_ZEBSTRIKA}),
    },

    [SPECIES_ZEBSTRIKA] =
    {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 63,
        .baseSpeed     = 116,
        .baseSpAttack  = 80,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = 174,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_MOTOR_DRIVE, ABILITY_SAP_SIPPER },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Zebritz"),
#else
        .speciesName = _("ZEBSTRIKA"),
#endif
        .cryId = CRY_ZEBSTRIKA,
        .natDexNum = NATIONAL_DEX_ZEBSTRIKA,
#if GERMAN
        .categoryName = _("Donnerkeil"),
#else
        .categoryName = _("Thunderbolt"),
#endif
        .height = 16,
        .weight = 795,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein stürmischer Geselle.\n"
        "Wenn es wütend ist, feuert es über seine\n"
        "Mähne in alle Richtungen Stromsalven ab."),
#else
            "When Zebstrika run at full speed, the\n"
            "sound of thunder reverberates. It is\n"
            "dangerous when it's angry as it shoots\n"
            "lightning from its mane in all directions."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Zebstrika,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Zebstrika,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Zebstrika,
        .shinyPalette = gMonShinyPalette_Zebstrika,
        .iconSprite = gMonIcon_Zebstrika,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_M)
        FOOTPRINT(Zebstrika)
        OVERWORLD(
            sPicTable_Zebstrika,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zebstrika,
            gShinyOverworldPalette_Zebstrika
        )
        .levelUpLearnset = sZebstrikaLevelUpLearnset,
        .teachableLearnset = sZebstrikaTeachableLearnset,
    },
#endif //P_FAMILY_BLITZLE

#if P_FAMILY_ROGGENROLA
    [SPECIES_ROGGENROLA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 255,
        .expYield = 56,
        .evYield_Defense = 1,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_STURDY, ABILITY_WEAK_ARMOR, ABILITY_SAND_FORCE },
    #else
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SAND_FORCE },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kiesling"),
#else
        .speciesName = _("ROGGENROLA"),
#endif
        .cryId = CRY_ROGGENROLA,
        .natDexNum = NATIONAL_DEX_ROGGENROLA,
#if GERMAN
        .categoryName = _("Erdmantel"),
#else
        .categoryName = _("Mantle"),
#endif
        .height = 4,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hat ein sechseckiges Ohr. Sein durch das\n"
            "Erdreich gepresster Körper steht Stahl in\n"
            "Sachen Härte in nichts nach."),
#else
            "The hexagonal cavity is its ear.\n"
            "It walks in the direction of sounds it\n"
            "hears, but if the sounds cease, it panics\n"
            "and topples over."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Roggenrola,
        .frontPicSize = MON_COORDS_SIZE(24, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Roggenrola,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Roggenrola,
        .shinyPalette = gMonShinyPalette_Roggenrola,
        .iconSprite = gMonIcon_Roggenrola,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Roggenrola)
        OVERWORLD(
            sPicTable_Roggenrola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Roggenrola,
            gShinyOverworldPalette_Roggenrola
        )
        .levelUpLearnset = sRoggenrolaLevelUpLearnset,
        .teachableLearnset = sRoggenrolaTeachableLearnset,
        .eggMoveLearnset = sRoggenrolaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_BOLDORE}),
    },

    [SPECIES_BOLDORE] =
    {
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 105,
        .baseSpeed     = 20,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 120,
        .expYield = 137,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_STURDY, ABILITY_WEAK_ARMOR, ABILITY_SAND_FORCE },
    #else
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SAND_FORCE },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Sedimantur"),
#else
        .speciesName = _("BOLDORE"),
#endif
        .cryId = CRY_BOLDORE,
        .natDexNum = NATIONAL_DEX_BOLDORE,
#if GERMAN
        .categoryName = _("Erz"),
#else
        .categoryName = _("Ore"),
#endif
        .height = 9,
        .weight = 1020,
        .description = COMPOUND_STRING(
#if GERMAN
        "Energie, die ungehindert\n"
        "aus seinem Körper austrat, hat sich an ihm\n"
        "zu orangefarbenen Kristallen verfestigt."),
#else
            "Its orange crystal is a mass of energy.\n"
            "Just one crystal fragment would provide\n"
            "enough fuel for a hundred dump trucks.\n"
            "When it is healthy, its core sticks out."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Boldore,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Boldore,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Boldore,
        .shinyPalette = gMonShinyPalette_Boldore,
        .iconSprite = gMonIcon_Boldore,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 3, SHADOW_SIZE_L)
        FOOTPRINT(Boldore)
        OVERWORLD(
            sPicTable_Boldore,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Boldore,
            gShinyOverworldPalette_Boldore
        )
        .levelUpLearnset = sBoldoreLevelUpLearnset,
        .teachableLearnset = sBoldoreTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_BLACK_AUGURITE, SPECIES_GIGALITH},
                                {EVO_TRADE, 0, SPECIES_GIGALITH},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GIGALITH}),
    },

    [SPECIES_GIGALITH] =
    {
        .baseHP        = 85,
        .baseAttack    = 135,
        .baseDefense   = 130,
        .baseSpeed     = 25,
        .baseSpAttack  = 60,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 258,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 232,
    #else
        .expYield = 227,
    #endif
        .evYield_Attack = 3,
        .itemCommon = ITEM_EVERSTONE,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_STURDY, ABILITY_SAND_STREAM, ABILITY_SAND_FORCE },
    #else
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SAND_FORCE },
    #endif
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Brockoloss"),
#else
        .speciesName = _("GIGALITH"),
#endif
        .cryId = CRY_GIGALITH,
        .natDexNum = NATIONAL_DEX_GIGALITH,
#if GERMAN
        .categoryName = _("Kompression"),
#else
        .categoryName = _("Compressed"),
#endif
        .height = 17,
        .weight = 2600,
        .description = COMPOUND_STRING(
#if GERMAN
        "Brockoloss verarbeitet Sonnenstrahlen in\n"
        "seinem Energiekern zu Lichtkugeln weiter,\n"
        "um sie im Kampf auf seinen Gegner\n"
        "abzufeuern."),
#else
            "The blasts of energy it makes from\n"
            "sunbeams have terrifying power.\n"
            "However, it's not able to fire its blasts\n"
            "at night or on rainy days."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Gigalith,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_ROTATE_UP_SLAM_DOWN,
        .backPic = gMonBackPic_Gigalith,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Gigalith,
        .shinyPalette = gMonShinyPalette_Gigalith,
        .iconSprite = gMonIcon_Gigalith,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Gigalith)
        OVERWORLD(
            sPicTable_Gigalith,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gigalith,
            gShinyOverworldPalette_Gigalith
        )
        .levelUpLearnset = sGigalithLevelUpLearnset,
        .teachableLearnset = sGigalithTeachableLearnset,
    },
#endif //P_FAMILY_ROGGENROLA

#if P_FAMILY_WOOBAT
    [SPECIES_WOOBAT] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 65 : 55,
        .baseAttack    = 45,
        .baseDefense   = 43,
        .baseSpeed     = 72,
        .baseSpAttack  = 55,
        .baseSpDefense = 43,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 190,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_7) ? 65 : 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FLYING),
        .abilities = { ABILITY_UNAWARE, ABILITY_KLUTZ, ABILITY_SIMPLE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Fleknoil"),
#else
        .speciesName = _("WOOBAT"),
#endif
        .cryId = CRY_WOOBAT,
        .natDexNum = NATIONAL_DEX_WOOBAT,
#if GERMAN
        .categoryName = _("Fledermaus"),
#else
        .categoryName = _("Bat"),
#endif
        .height = 4,
        .weight = 21,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wohnt in dunklen Wäldern und Höhlen.\n"
        "Es sendet Ultraschallwellen mit seiner\n"
        "Nase aus, um die Gegend abzutasten."),
#else
            "Its habitat is dark forests and caves.\n"
            "Suction from its nostrils enables it\n"
            "to stick to cave walls during sleep.\n"
            "It leaves a heart-shaped mark behind."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Woobat,
        .frontPicSize = MON_COORDS_SIZE(64, 32),
        .frontPicYOffset = 16,
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
            ANIMCMD_FRAME(1, 5),
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
        .frontAnimId = ANIM_FOUR_PETAL,
        .enemyMonElevation = 19,
        .backPic = gMonBackPic_Woobat,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Woobat,
        .shinyPalette = gMonShinyPalette_Woobat,
        .iconSprite = gMonIcon_Woobat,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_S)
        FOOTPRINT(Woobat)
        OVERWORLD(
            sPicTable_Woobat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Woobat,
            gShinyOverworldPalette_Woobat
        )
        .levelUpLearnset = sWoobatLevelUpLearnset,
        .teachableLearnset = sWoobatTeachableLearnset,
        .eggMoveLearnset = sWoobatEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_SWOOBAT, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },

    [SPECIES_SWOOBAT] =
    {
        .baseHP        = 67,
        .baseAttack    = 57,
        .baseDefense   = 55,
        .baseSpeed     = 114,
        .baseSpAttack  = 77,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 149,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_FLYING),
        .abilities = { ABILITY_UNAWARE, ABILITY_KLUTZ, ABILITY_SIMPLE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Fletiamo"),
#else
        .speciesName = _("SWOOBAT"),
#endif
        .cryId = CRY_SWOOBAT,
        .natDexNum = NATIONAL_DEX_SWOOBAT,
#if GERMAN
        .categoryName = _("Balz"),
#else
        .categoryName = _("Courting"),
#endif
        .height = 9,
        .weight = 105,
        .description = COMPOUND_STRING(
#if GERMAN
        "Beim Abfeuern seiner Ultraschallwellen,\n"
        "mit denen es selbst Beton zertrümmern\n"
        "kann, wedelt es eifrig mit dem Schweif."),
#else
            "Anyone who comes into contact with\n"
            "the ultrasonic waves emitted by a\n"
            "courting male experiences a positive\n"
            "mood shift."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swoobat,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Swoobat,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Swoobat,
        .shinyPalette = gMonShinyPalette_Swoobat,
        .iconSprite = gMonIcon_Swoobat,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 17, SHADOW_SIZE_M)
        FOOTPRINT(Swoobat)
        OVERWORLD(
            sPicTable_Swoobat,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Swoobat,
            gShinyOverworldPalette_Swoobat
        )
        .levelUpLearnset = sSwoobatLevelUpLearnset,
        .teachableLearnset = sSwoobatTeachableLearnset,
    },
#endif //P_FAMILY_WOOBAT

#if P_FAMILY_DRILBUR
    [SPECIES_DRILBUR] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 68,
        .baseSpAttack  = 30,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 120,
        .expYield = 66,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Rotomurf"),
#else
        .speciesName = _("DRILBUR"),
#endif
        .cryId = CRY_DRILBUR,
        .natDexNum = NATIONAL_DEX_DRILBUR,
#if GERMAN
        .categoryName = _("Maulwurf"),
#else
        .categoryName = _("Mole"),
#endif
        .height = 3,
        .weight = 85,
        .description = COMPOUND_STRING(
#if GERMAN
        "Rotomurf führt seine beiden Klauen\n"
        "zusammen, dreht sich rapide um die eigene\n"
        "Achse und gräbt sich ratzfatz durch das\n"
        "Erdreich."),
#else
            "It can dig through the ground at a\n"
            "speed of 30 mph by spinning its body.\n"
            "It could give a car running aboveground\n"
            "a good race."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Drilbur,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        .backPic = gMonBackPic_Drilbur,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Drilbur,
        .shinyPalette = gMonShinyPalette_Drilbur,
        .iconSprite = gMonIcon_Drilbur,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Drilbur)
        OVERWORLD(
            sPicTable_Drilbur,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Drilbur,
            gShinyOverworldPalette_Drilbur
        )
        .levelUpLearnset = sDrilburLevelUpLearnset,
        .teachableLearnset = sDrilburTeachableLearnset,
        .eggMoveLearnset = sDrilburEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_EXCADRILL}),
    },

    [SPECIES_EXCADRILL] =
    {
        .baseHP        = 110,
        .baseAttack    = 135,
        .baseDefense   = 60,
        .baseSpeed     = 88,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 60,
        .expYield = 178,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Stalobor"),
#else
        .speciesName = _("EXCADRILL"),
#endif
        .cryId = CRY_EXCADRILL,
        .natDexNum = NATIONAL_DEX_EXCADRILL,
#if GERMAN
        .categoryName = _("Untergrund"),
#else
        .categoryName = _("Subterrene"),
#endif
        .height = 7,
        .weight = 404,
        .description = COMPOUND_STRING(
#if GERMAN
        "Stalobors zu Stahl weiterentwickelten\n"
        "Bohrer kriegen selbst Eisenplatten klein.\n"
        "Im Tunnelbau ist es ein absolutes Ass."),
#else
            "More than 300 feet below the surface,\n"
            "they build mazelike nests. Their activity\n"
            "can be destructive to subway tunnels,\n"
            "but it can also help with construction."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Excadrill,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Excadrill,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Excadrill,
        .shinyPalette = gMonShinyPalette_Excadrill,
        .iconSprite = gMonIcon_Excadrill,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(3, 8, SHADOW_SIZE_L)
        FOOTPRINT(Excadrill)
        OVERWORLD(
            sPicTable_Excadrill,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Excadrill,
            gShinyOverworldPalette_Excadrill
        )
        .levelUpLearnset = sExcadrillLevelUpLearnset,
        .teachableLearnset = sExcadrillTeachableLearnset,
        .formSpeciesIdTable = sExcadrillFormSpeciesIdTable,
        .formChangeTable = sExcadrillFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_EXCADRILL_MEGA] =
    {
        .baseHP        = 110,
        .baseAttack    = 165,
        .baseDefense   = 100,
        .baseSpeed     = 103,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 60,
        .expYield = 178,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SAND_RUSH, ABILITY_SAND_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Stalobor"),
#else
        .speciesName = _("EXCADRILL"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_EXCADRILL_MEGA,
    #else
        .cryId = CRY_EXCADRILL,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_EXCADRILL,
#if GERMAN
        .categoryName = _("Untergrund"),
#else
        .categoryName = _("Subterrene"),
#endif
        .height = 9,
        .weight = 600,
        .description = COMPOUND_STRING(
#if GERMAN
        "Führt es Arme und Kopf zusammen, um eine\n"
        "Stromlinienform anzunehmen, und dreht\n"
        "sich mit hoher Geschwindigkeit, kann es\n"
        "alles zerstören."),
#else
            "If this Pokémon brings its arms and\n"
            "head together to form a streamlined\n"
            "shape and spins at high speeds,\n"
            "it can destroy anything."),
#endif
        .frontPic = gMonFrontPic_ExcadrillMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ExcadrillMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ExcadrillMega,
        .shinyPalette = gMonShinyPalette_ExcadrillMega,
        .iconSprite = gMonIcon_ExcadrillMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Excadrill)
        SHADOW(5, 13, SHADOW_SIZE_XL_BATTLE_ONLY)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sExcadrillLevelUpLearnset,
        .teachableLearnset = sExcadrillTeachableLearnset,
        .formSpeciesIdTable = sExcadrillFormSpeciesIdTable,
        .formChangeTable = sExcadrillFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_DRILBUR

#if P_FAMILY_AUDINO
    [SPECIES_AUDINO] =
    {
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 86,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 86,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 390,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HEALER, ABILITY_REGENERATOR, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Ohrdoch"),
#else
        .speciesName = _("AUDINO"),
#endif
        .cryId = CRY_AUDINO,
        .natDexNum = NATIONAL_DEX_AUDINO,
#if GERMAN
        .categoryName = _("Gehör"),
#else
        .categoryName = _("Hearing"),
#endif
        .height = 11,
        .weight = 310,
        .description = COMPOUND_STRING(
#if GERMAN
        "Über die Fühler an seinen Ohren kann es\n"
        "ertasten, wie es einer Person geht oder\n"
        "wann ein Pokémon aus seinem Ei schlüpft."),
#else
            "Its auditory sense is astounding.\n"
            "Using the feelers on its ears, it can tell\n"
            "how someone is feeling or when an egg\n"
            "might hatch."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Audino,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Audino,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Audino,
        .shinyPalette = gMonShinyPalette_Audino,
        .iconSprite = gMonIcon_Audino,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_S)
        FOOTPRINT(Audino)
        OVERWORLD(
            sPicTable_Audino,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Audino,
            gShinyOverworldPalette_Audino
        )
        .levelUpLearnset = sAudinoLevelUpLearnset,
        .teachableLearnset = sAudinoTeachableLearnset,
        .eggMoveLearnset = sAudinoEggMoveLearnset,
        .formSpeciesIdTable = sAudinoFormSpeciesIdTable,
        .formChangeTable = sAudinoFormChangeTable,
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_AUDINO_MEGA] =
    {
        .baseHP        = 103,
        .baseAttack    = 60,
        .baseDefense   = 126,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 126,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FAIRY),
        .catchRate = 255,
        .expYield = 425,
        .evYield_HP = 2,
        .itemCommon = ITEM_ORAN_BERRY,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FAIRY),
        .abilities = { ABILITY_HEALER, ABILITY_HEALER, ABILITY_HEALER },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Ohrdoch"),
#else
        .speciesName = _("AUDINO"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_AUDINO_MEGA,
    #else
        .cryId = CRY_AUDINO,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_AUDINO,
#if GERMAN
        .categoryName = _("Gehör"),
#else
        .categoryName = _("Hearing"),
#endif
        .height = 15,
        .weight = 320,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wer das sekundäre Fühlerpaar berührt,\n"
        "das diesem Pokémon am Halsansatz\n"
        "wächst, fällt in einen tiefen Schlaf."),
#else
            "Mega Audino emits a soothing pulse from\n"
            "its body that reduces hostility in others.\n"
            "Anything that comes into contact with its\n"
            "second feelers will fall into a deep sleep."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_AudinoMega,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_AudinoMega,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_AudinoMega,
        .shinyPalette = gMonShinyPalette_AudinoMega,
        .iconSprite = gMonIcon_AudinoMega,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 7, SHADOW_SIZE_M)
        FOOTPRINT(Audino)
    #if OW_BATTLE_ONLY_FORMS
        OVERWORLD(
            sPicTable_AudinoMega,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_AudinoMega,
            gShinyOverworldPalette_AudinoMega
        )
    #endif //OW_BATTLE_ONLY_FORMS
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sAudinoLevelUpLearnset,
        .teachableLearnset = sAudinoTeachableLearnset,
        .eggMoveLearnset = sAudinoEggMoveLearnset,
        .formSpeciesIdTable = sAudinoFormSpeciesIdTable,
        .formChangeTable = sAudinoFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_AUDINO

#if P_FAMILY_TIMBURR
    [SPECIES_TIMBURR] =
    {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 55,
        .baseSpeed     = 35,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 180,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Praktibalk"),
#else
        .speciesName = _("TIMBURR"),
#endif
        .cryId = CRY_TIMBURR,
        .natDexNum = NATIONAL_DEX_TIMBURR,
#if GERMAN
        .categoryName = _("Muskel"),
#else
        .categoryName = _("Muscular"),
#endif
        .height = 6,
        .weight = 125,
        .description = COMPOUND_STRING(
#if GERMAN
            "Trägt stets einen Holzbalken bei sich. Es\n"
            "taucht hier und da auf Baustellen auf und\n"
            "hilft dort den Arbeitern aus."),
#else
            "These Pokémon appear at building\n"
            "sites and help out with construction.\n"
            "They always carry squared logs.\n"
            "As they grow, they carry bigger logs."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Timburr,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Timburr,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Timburr,
        .shinyPalette = gMonShinyPalette_Timburr,
        .iconSprite = gMonIcon_Timburr,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-4, 2, SHADOW_SIZE_S)
        FOOTPRINT(Timburr)
        OVERWORLD(
            sPicTable_Timburr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Timburr,
            gShinyOverworldPalette_Timburr
        )
        .levelUpLearnset = sTimburrLevelUpLearnset,
        .teachableLearnset = sTimburrTeachableLearnset,
        .eggMoveLearnset = sTimburrEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_GURDURR}),
    },

    [SPECIES_GURDURR] =
    {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 90,
        .expYield = 142,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Strepoli"),
#else
        .speciesName = _("GURDURR"),
#endif
        .cryId = CRY_GURDURR,
        .natDexNum = NATIONAL_DEX_GURDURR,
#if GERMAN
        .categoryName = _("Muskel"),
#else
        .categoryName = _("Muscular"),
#endif
        .height = 12,
        .weight = 400,
        .description = COMPOUND_STRING(
#if GERMAN
        "Diese durchtrainierten Muskelprotze\n"
        "sind im Umgang mit Stahlträgern versiert\n"
        "und können damit ganze Häuser abreißen."),
#else
            "They strengthen their bodies by carrying\n"
            "steel beams. This Pokémon is so muscular\n"
            "and strongly built that even a group of\n"
            "wrestlers could not make it budge an inch."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gurdurr,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
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
        .backPic = gMonBackPic_Gurdurr,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Gurdurr,
        .shinyPalette = gMonShinyPalette_Gurdurr,
        .iconSprite = gMonIcon_Gurdurr,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Gurdurr)
        OVERWORLD(
            sPicTable_Gurdurr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gurdurr,
            gShinyOverworldPalette_Gurdurr
        )
        .levelUpLearnset = sGurdurrLevelUpLearnset,
        .teachableLearnset = sGurdurrTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_PROTECTOR, SPECIES_CONKELDURR},
                                {EVO_TRADE, 0, SPECIES_CONKELDURR},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_CONKELDURR}),
    },

    [SPECIES_CONKELDURR] =
    {
        .baseHP        = 105,
        .baseAttack    = 140,
        .baseDefense   = 95,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 253 : 227,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(25),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_GUTS, ABILITY_SHEER_FORCE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Meistagrif"),
#else
        .speciesName = _("CONKELDURR"),
#endif
        .cryId = CRY_CONKELDURR,
        .natDexNum = NATIONAL_DEX_CONKELDURR,
#if GERMAN
        .categoryName = _("Muskel"),
#else
        .categoryName = _("Muscular"),
#endif
        .height = 14,
        .weight = 870,
        .description = COMPOUND_STRING(
#if GERMAN
        "Man nimmt an, dass es der Menschheit vor\n"
        "ca. 2 000 Jahren das Betonmischen\n"
        "beigebracht hat."),
#else
            "They use concrete pillars as walking\n"
            "canes. Rather than rely solely on force,\n"
            "they master moves that utilize the\n"
            "centrifugal force of spinning concrete."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 3,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Conkeldurr,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Conkeldurr,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Conkeldurr,
        .shinyPalette = gMonShinyPalette_Conkeldurr,
        .iconSprite = gMonIcon_Conkeldurr,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 3, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Conkeldurr)
        OVERWORLD(
            sPicTable_Conkeldurr,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Conkeldurr,
            gShinyOverworldPalette_Conkeldurr
        )
        .levelUpLearnset = sConkeldurrLevelUpLearnset,
        .teachableLearnset = sConkeldurrTeachableLearnset,
    },
#endif //P_FAMILY_TIMBURR

#if P_FAMILY_TYMPOLE
    [SPECIES_TYMPOLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 64,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 255,
        .expYield = 59,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_HYDRATION, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Schallquap"),
#else
        .speciesName = _("TYMPOLE"),
#endif
        .cryId = CRY_TYMPOLE,
        .natDexNum = NATIONAL_DEX_TYMPOLE,
#if GERMAN
        .categoryName = _("Kaulquappe"),
#else
        .categoryName = _("Tadpole"),
#endif
        .height = 5,
        .weight = 45,
        .description = COMPOUND_STRING(
#if GERMAN
        "Erzeugt mit seinen Wangen\n"
        "für Menschen unhörbare Schallwellen,\n"
        "um Artgenossen vor Gefahr zu warnen."),
#else
            "By vibrating its cheeks, it emits sound\n"
            "waves imperceptible to humans. It uses\n"
            "the rhythm of these sounds to talk and\n"
            "warns others of danger."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tympole,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Tympole,
        .backPicSize = MON_COORDS_SIZE(40, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_SPRING,
        .palette = gMonPalette_Tympole,
        .shinyPalette = gMonShinyPalette_Tympole,
        .iconSprite = gMonIcon_Tympole,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Tympole)
        OVERWORLD(
            sPicTable_Tympole,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tympole,
            gShinyOverworldPalette_Tympole
        )
        .levelUpLearnset = sTympoleLevelUpLearnset,
        .teachableLearnset = sTympoleTeachableLearnset,
        .eggMoveLearnset = sTympoleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_PALPITOAD}),
    },

    [SPECIES_PALPITOAD] =
    {
        .baseHP        = 75,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 69,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 120,
        .expYield = 134,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_HYDRATION, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Mebrana"),
#else
        .speciesName = _("PALPITOAD"),
#endif
        .cryId = CRY_PALPITOAD,
        .natDexNum = NATIONAL_DEX_PALPITOAD,
        .categoryName = _("Vibration"),
        .height = 8,
        .weight = 170,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wenn es die Beulen auf seinem Kopf zum\n"
            "Schwingen bringt, tobt je nach Umgebung\n"
            "entweder das Wasser oder die Erde bebt."),
#else
            "It lives in the water and on land.\n"
            "When they vibrate the bumps on their\n"
            "heads, they can make waves in water\n"
            "or earthquake-like vibrations on land."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Palpitoad,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 13),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Palpitoad,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Palpitoad,
        .shinyPalette = gMonShinyPalette_Palpitoad,
        .iconSprite = gMonIcon_Palpitoad,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 3, SHADOW_SIZE_S)
        FOOTPRINT(Palpitoad)
        OVERWORLD(
            sPicTable_Palpitoad,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Palpitoad,
            gShinyOverworldPalette_Palpitoad
        )
        .levelUpLearnset = sPalpitoadLevelUpLearnset,
        .teachableLearnset = sPalpitoadTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SEISMITOAD}),
    },

    [SPECIES_SEISMITOAD] =
    {
        .baseHP        = 105,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 95 : 85,
        .baseDefense   = 75,
        .baseSpeed     = 74,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER, TYPE_GROUND),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 255,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 229,
    #else
        .expYield = 225,
    #endif
        .evYield_HP = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_POISON_TOUCH, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Branawarz"),
#else
        .speciesName = _("SEISMITOAD"),
#endif
        .cryId = CRY_SEISMITOAD,
        .natDexNum = NATIONAL_DEX_SEISMITOAD,
        .categoryName = _("Vibration"),
        .height = 15,
        .weight = 620,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wenn es die Beulen an seinen Fäusten zum\n"
            "Schwingen bringt, kann es doppelt so fest\n"
            "zuschlagen und Felsen zertrümmern."),
#else
            "It increases the power of its punches\n"
            "by vibrating the bumps on its fists.\n"
            "They can also shoot paralyzing liquid\n"
            "from their head bumps."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Seismitoad,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
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
        .backPic = gMonBackPic_Seismitoad,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Seismitoad,
        .shinyPalette = gMonShinyPalette_Seismitoad,
        .iconSprite = gMonIcon_Seismitoad,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 10, SHADOW_SIZE_L)
        FOOTPRINT(Seismitoad)
        OVERWORLD(
            sPicTable_Seismitoad,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Seismitoad,
            gShinyOverworldPalette_Seismitoad
        )
        .levelUpLearnset = sSeismitoadLevelUpLearnset,
        .teachableLearnset = sSeismitoadTeachableLearnset,
    },
#endif //P_FAMILY_TYMPOLE

#if P_FAMILY_THROH
    [SPECIES_THROH] =
    {
        .baseHP        = 120,
        .baseAttack    = 100,
        .baseDefense   = 85,
        .baseSpeed     = 45,
        .baseSpAttack  = 30,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 163,
        .evYield_HP = 2,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_GUTS, ABILITY_INNER_FOCUS, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Jiutesto"),
#else
        .speciesName = _("THROH"),
#endif
        .cryId = CRY_THROH,
        .natDexNum = NATIONAL_DEX_THROH,
        .categoryName = _("Judo"),
        .height = 13,
        .weight = 555,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zurrt es seinen Gürtel fest, gewinnt es an\n"
            "Kraft. Wilde Exemplare flechten sich ihren\n"
            "Gürtel in Handarbeit aus Ranken."),
#else
            "When it tightens its belt, it becomes\n"
            "stronger. Wild Throh use vines to weave\n"
            "their own belts. It changes belts as it\n"
            "gets more powerful."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Throh,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Throh,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Throh,
        .shinyPalette = gMonShinyPalette_Throh,
        .iconSprite = gMonIcon_Throh,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 4, SHADOW_SIZE_M)
        FOOTPRINT(Throh)
        OVERWORLD(
            sPicTable_Throh,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Throh,
            gShinyOverworldPalette_Throh
        )
        .levelUpLearnset = sThrohLevelUpLearnset,
        .teachableLearnset = sThrohTeachableLearnset,
    },
#endif //P_FAMILY_THROH

#if P_FAMILY_SAWK
    [SPECIES_SAWK] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 30,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 163,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_BELT,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_STURDY, ABILITY_INNER_FOCUS, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Karadonis"),
#else
        .speciesName = _("SAWK"),
#endif
        .cryId = CRY_SAWK,
        .natDexNum = NATIONAL_DEX_SAWK,
        .categoryName = _("Karate"),
        .height = 14,
        .weight = 510,
        .description = COMPOUND_STRING(
#if GERMAN
        "Karadonis lebt zurückgezogen in den\n"
        "Bergen und trainiert Tag und Nacht, um\n"
        "seinen Karateschlag zu perfektionieren."),
#else
            "The sound of Sawk punching boulders\n"
            "and trees can be heard all the way from\n"
            "the mountains where they train.\n"
            "Disturbing their training angers them."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 4,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sawk,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Sawk,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Sawk,
        .shinyPalette = gMonShinyPalette_Sawk,
        .iconSprite = gMonIcon_Sawk,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_M)
        FOOTPRINT(Sawk)
        OVERWORLD(
            sPicTable_Sawk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sawk,
            gShinyOverworldPalette_Sawk
        )
        .levelUpLearnset = sSawkLevelUpLearnset,
        .teachableLearnset = sSawkTeachableLearnset,
    },
#endif //P_FAMILY_SAWK

#if P_FAMILY_SEWADDLE
    [SPECIES_SEWADDLE] =
    {
        .baseHP        = 45,
        .baseAttack    = 53,
        .baseDefense   = 70,
        .baseSpeed     = 42,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_BUG, TYPE_GRASS),
        .catchRate = 255,
        .expYield = 62,
        .evYield_Defense = 1,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Strawickl"),
#else
        .speciesName = _("SEWADDLE"),
#endif
        .cryId = CRY_SEWADDLE,
        .natDexNum = NATIONAL_DEX_SEWADDLE,
#if GERMAN
        .categoryName = _("Schneider"),
#else
        .categoryName = _("Sewing"),
#endif
        .height = 3,
        .weight = 25,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schneidert sich ein Kleid, indem es sich\n"
        "Blätter zurechtbeißt und sie mit\n"
        "Klebefäden aus seinem Mund zusammennäht."),
#else
            "It chews up leaves and sews them with\n"
            "sticky thread extruded from its mouth.\n"
            "Since this Pokémon makes its own clothes,\n"
            "it is a mascot for fashion designers."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sewaddle,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_CIRCLE_INTO_BG,
        .backPic = gMonBackPic_Sewaddle,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Sewaddle,
        .shinyPalette = gMonShinyPalette_Sewaddle,
        .iconSprite = gMonIcon_Sewaddle,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Sewaddle)
        OVERWORLD(
            sPicTable_Sewaddle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sewaddle,
            gShinyOverworldPalette_Sewaddle
        )
        .levelUpLearnset = sSewaddleLevelUpLearnset,
        .teachableLearnset = sSewaddleTeachableLearnset,
        .eggMoveLearnset = sSewaddleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_SWADLOON}),
    },

    [SPECIES_SWADLOON] =
    {
        .baseHP        = 55,
        .baseAttack    = 63,
        .baseDefense   = 90,
        .baseSpeed     = 42,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_BUG, TYPE_GRASS),
        .catchRate = 120,
        .expYield = 133,
        .evYield_Defense = 2,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Folikon"),
#else
        .speciesName = _("SWADLOON"),
#endif
        .cryId = CRY_SWADLOON,
        .natDexNum = NATIONAL_DEX_SWADLOON,
#if GERMAN
        .categoryName = _("Wickelblatt"),
#else
        .categoryName = _("Leaf-Wrapped"),
#endif
        .height = 5,
        .weight = 73,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es wandelt herabgefallenes Laub in\n"
        "Nährstoffe um. In Wäldern, wo es Folikon\n"
        "gibt, fühlen sich Pflanzen pudelwohl."),
#else
            "Forests where Swadloon live have\n"
            "superb foliage because the nutrients\n"
            "they make from fallen leaves nourish\n"
            "the plant life."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swadloon,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Swadloon,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Swadloon,
        .shinyPalette = gMonShinyPalette_Swadloon,
        .iconSprite = gMonIcon_Swadloon,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 1, SHADOW_SIZE_L)
        FOOTPRINT(Swadloon)
        OVERWORLD(
            sPicTable_Swadloon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Swadloon,
            gShinyOverworldPalette_Swadloon
        )
        .levelUpLearnset = sSwadloonLevelUpLearnset,
        .teachableLearnset = sSwadloonTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_LEAVANNY, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },

    [SPECIES_LEAVANNY] =
    {
        .baseHP        = 75,
        .baseAttack    = 103,
        .baseDefense   = 80,
        .baseSpeed     = 92,
        .baseSpAttack  = 70,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .types = MON_TYPES(TYPE_BUG, TYPE_GRASS),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 250,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 225,
    #else
        .expYield = 221,
    #endif
        .evYield_Attack = 3,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_CHLOROPHYLL, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Matrifol"),
#else
        .speciesName = _("LEAVANNY"),
#endif
        .cryId = CRY_LEAVANNY,
        .natDexNum = NATIONAL_DEX_LEAVANNY,
#if GERMAN
        .categoryName = _("Kinderpflege"),
#else
        .categoryName = _("Nurturing"),
#endif
        .height = 12,
        .weight = 205,
        .description = COMPOUND_STRING(
#if GERMAN
        "Begegnet es einem jungen Pokémon,\n"
        "näht es ihm mit den klebrigen Fäden\n"
        "aus seinem Mund ein Kleid aus Blättern."),
#else
            "It keeps its eggs warm with heat from\n"
            "fermenting leaves. It also uses leaves to\n"
            "weave warm wrappings for Sewaddle by\n"
            "using the silk secreted from its mouth."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Leavanny,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Leavanny,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Leavanny,
        .shinyPalette = gMonShinyPalette_Leavanny,
        .iconSprite = gMonIcon_Leavanny,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_S)
        FOOTPRINT(Leavanny)
        OVERWORLD(
            sPicTable_Leavanny,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Leavanny,
            gShinyOverworldPalette_Leavanny
        )
        .levelUpLearnset = sLeavannyLevelUpLearnset,
        .teachableLearnset = sLeavannyTeachableLearnset,
    },
#endif //P_FAMILY_SEWADDLE

#if P_FAMILY_VENIPEDE
    [SPECIES_VENIPEDE] =
    {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 59,
        .baseSpeed     = 57,
        .baseSpAttack  = 30,
        .baseSpDefense = 39,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 255,
        .expYield = 52,
        .evYield_Defense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
    #endif
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Toxiped"),
#else
        .speciesName = _("VENIPEDE"),
#endif
        .cryId = CRY_VENIPEDE,
        .natDexNum = NATIONAL_DEX_VENIPEDE,
#if GERMAN
        .categoryName = _("Tausendfüßer"),
#else
        .categoryName = _("Centipede"),
#endif
        .height = 4,
        .weight = 53,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit seinen Ruten und den Fühlern\n"
        "an seinem Kopf tastet es die Umgebung\n"
        "ab. Ein überaus aggressiver Geselle."),
#else
            "Using the feelers on its head and tail,\n"
            "it picks up vibrations in the air to\n"
            "determine its prey's location and state.\n"
            "It is brutally aggressive."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Venipede,
        .frontPicSize = MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Venipede,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Venipede,
        .shinyPalette = gMonShinyPalette_Venipede,
        .iconSprite = gMonIcon_Venipede,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, -3, SHADOW_SIZE_M)
        FOOTPRINT(Venipede)
        OVERWORLD(
            sPicTable_Venipede,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Venipede,
            gShinyOverworldPalette_Venipede
        )
        .levelUpLearnset = sVenipedeLevelUpLearnset,
        .teachableLearnset = sVenipedeTeachableLearnset,
        .eggMoveLearnset = sVenipedeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_WHIRLIPEDE}),
    },

    [SPECIES_WHIRLIPEDE] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 99,
        .baseSpeed     = 47,
        .baseSpAttack  = 40,
        .baseSpDefense = 79,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 120,
        .expYield = 126,
        .evYield_Defense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Rollum"),
#else
        .speciesName = _("WHIRLIPEDE"),
#endif
        .cryId = CRY_WHIRLIPEDE,
        .natDexNum = NATIONAL_DEX_WHIRLIPEDE,
#if GERMAN
        .categoryName = _("Kokonfüßer"),
#else
        .categoryName = _("Curlipede"),
#endif
        .height = 12,
        .weight = 585,
        .description = COMPOUND_STRING(
#if GERMAN
        "Von einem harten Schutzpanzer umgeben.\n"
        "Es greift seine Gegner an, indem es\n"
        "mit Karacho wie ein Rad in sie hineinrollt."),
#else
            "Storing energy for evolution, it sits.\n"
            "But when attacked, it spins its body at\n"
            "high speed like a wheel and then\n"
            "crashes furiously into its opponent."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Whirlipede,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .backPic = gMonBackPic_Whirlipede,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Whirlipede,
        .shinyPalette = gMonShinyPalette_Whirlipede,
        .iconSprite = gMonIcon_Whirlipede,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Whirlipede)
        OVERWORLD(
            sPicTable_Whirlipede,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Whirlipede,
            gShinyOverworldPalette_Whirlipede
        )
        .levelUpLearnset = sWhirlipedeLevelUpLearnset,
        .teachableLearnset = sWhirlipedeTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_SCOLIPEDE}),
    },

    [SPECIES_SCOLIPEDE] =
    {
        .baseHP        = 60,
        .baseAttack    = P_UPDATED_STATS >= GEN_6 ? 100 : 90,
        .baseDefense   = 89,
        .baseSpeed     = 112,
        .baseSpAttack  = 55,
        .baseSpDefense = 69,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 243,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 218,
    #else
        .expYield = 214,
    #endif
        .evYield_Speed = 3,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
    #else
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_QUICK_FEET },
    #endif
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Cerapendra"),
#else
        .speciesName = _("SCOLIPEDE"),
#endif
        .cryId = CRY_SCOLIPEDE,
        .natDexNum = NATIONAL_DEX_SCOLIPEDE,
#if GERMAN
        .categoryName = _("Riesenfüßer"),
#else
        .categoryName = _("Megapede"),
#endif
        .height = 25,
        .weight = 2005,
        .description = COMPOUND_STRING(
#if GERMAN
        "Lähmt seine Beute, indem es sie\n"
        "mit den Zacken an seinem Hals aufspießt.\n"
        "Mit einer Ladung Gift gibt es ihr den Rest."),
#else
            "With quick movements, it chases down\n"
            "its foes, attacking relentlessly with its\n"
            "horns until it prevails. Then it finishes\n"
            "them off with deadly poison."),
#endif
        .pokemonScale = 257,
        .pokemonOffset = 2,
        .trainerScale = 423,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Scolipede,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Scolipede,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Scolipede,
        .shinyPalette = gMonShinyPalette_Scolipede,
        .iconSprite = gMonIcon_Scolipede,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_L)
        FOOTPRINT(Scolipede)
        OVERWORLD(
            sPicTable_Scolipede,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Scolipede,
            gShinyOverworldPalette_Scolipede
        )
        .levelUpLearnset = sScolipedeLevelUpLearnset,
        .teachableLearnset = sScolipedeTeachableLearnset,
        .formSpeciesIdTable = sScolipedeFormSpeciesIdTable,
        .formChangeTable = sScolipedeFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_SCOLIPEDE_MEGA] =
    {
        .baseHP        = 60,
        .baseAttack    = 140,
        .baseDefense   = 149,
        .baseSpeed     = 62,
        .baseSpAttack  = 75,
        .baseSpDefense = 99,
        .types = MON_TYPES(TYPE_BUG, TYPE_POISON),
        .catchRate = 45,
        .expYield = 243,
        .evYield_Speed = 3,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_POISON_POINT, ABILITY_SWARM, ABILITY_SPEED_BOOST },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Cerapendra"),
#else
        .speciesName = _("SCOLIPEDE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SCOLIPEDE_MEGA,
    #else
        .cryId = CRY_SCOLIPEDE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SCOLIPEDE,
#if GERMAN
        .categoryName = _("Riesenfüßer"),
#else
        .categoryName = _("Megapede"),
#endif
        .height = 32,
        .weight = 2305,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein trüb leuchtendes, tödliches Gift hat\n"
        "Cerapendras Psyche in einer Weise\n"
        "stimuliert, die seine Tobsucht noch\n"
        "verstärkte."),
#else
            "Its deadly venom gives off a faint\n"
            "glow. The venom affects Scolipede's\n"
            "mind, honing its viciousness."),
#endif
        .frontPic = gMonFrontPic_ScolipedeMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ScolipedeMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ScolipedeMega,
        .shinyPalette = gMonShinyPalette_ScolipedeMega,
        .iconSprite = gMonIcon_ScolipedeMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Scolipede)
        SHADOW(2, 14, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sScolipedeLevelUpLearnset,
        .teachableLearnset = sScolipedeTeachableLearnset,
        .formSpeciesIdTable = sScolipedeFormSpeciesIdTable,
        .formChangeTable = sScolipedeFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_VENIPEDE

#if P_FAMILY_COTTONEE
#define COTTONEE_FAMILY_TYPE2 (P_UPDATED_TYPES >= GEN_6 ? TYPE_FAIRY : TYPE_GRASS)

    [SPECIES_COTTONEE] =
    {
        .baseHP        = 40,
        .baseAttack    = 27,
        .baseDefense   = 60,
        .baseSpeed     = 66,
        .baseSpAttack  = 37,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GRASS, COTTONEE_FAMILY_TYPE2),
        .catchRate = 190,
        .expYield = 56,
        .evYield_Speed = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_PRANKSTER, ABILITY_INFILTRATOR, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Waumboll"),
#else
        .speciesName = _("COTTONEE"),
#endif
        .cryId = CRY_COTTONEE,
        .natDexNum = NATIONAL_DEX_COTTONEE,
#if GERMAN
        .categoryName = _("Wattebausch"),
#else
        .categoryName = _("Cotton Puff"),
#endif
        .height = 3,
        .weight = 6,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wird es angegriffen, verstreut es zur\n"
            "Täuschung Watte. Es flieht, während der\n"
            "Gegner nach dem wahren Waumboll sucht."),
#else
            "When it finds others of its kind, they all\n"
            "stick together. When enough of them\n"
            "have collected, the mass resembles a\n"
            "cumulonimbus cloud."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cottonee,
        .frontPicSize = MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 50),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cottonee,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Cottonee,
        .shinyPalette = gMonShinyPalette_Cottonee,
        .iconSprite = gMonIcon_Cottonee,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, -5, SHADOW_SIZE_M)
        FOOTPRINT(Cottonee)
        OVERWORLD(
            sPicTable_Cottonee,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cottonee,
            gShinyOverworldPalette_Cottonee
        )
        .levelUpLearnset = sCottoneeLevelUpLearnset,
        .teachableLearnset = sCottoneeTeachableLearnset,
        .eggMoveLearnset = sCottoneeEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_WHIMSICOTT}),
    },

    [SPECIES_WHIMSICOTT] =
    {
        .baseHP        = 60,
        .baseAttack    = 67,
        .baseDefense   = 85,
        .baseSpeed     = 116,
        .baseSpAttack  = 77,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GRASS, COTTONEE_FAMILY_TYPE2),
        .catchRate = 75,
        .expYield = 168,
        .evYield_Speed = 2,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_FAIRY),
        .abilities = { ABILITY_PRANKSTER, ABILITY_INFILTRATOR, ABILITY_CHLOROPHYLL },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Elfun"),
#else
        .speciesName = _("WHIMSICOTT"),
#endif
        .cryId = CRY_WHIMSICOTT,
        .natDexNum = NATIONAL_DEX_WHIMSICOTT,
#if GERMAN
        .categoryName = _("Windschatten"),
#else
        .categoryName = _("Windveiled"),
#endif
        .height = 7,
        .weight = 66,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sie erscheinen mit Orkanböen und spielen\n"
        "den Leuten Streiche, indem sie in Häusern\n"
        "Möbel verrücken oder Watte verstreuen."),
#else
            "It rides on the wind and slips into\n"
            "people's homes. After it has turned a\n"
            "room into a cotton-filled mess, it giggles\n"
            "to itself and takes off."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Whimsicott,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .backPic = gMonBackPic_Whimsicott,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Whimsicott,
        .shinyPalette = gMonShinyPalette_Whimsicott,
        .iconSprite = gMonIcon_Whimsicott,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Whimsicott)
        OVERWORLD(
            sPicTable_Whimsicott,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Whimsicott,
            gShinyOverworldPalette_Whimsicott
        )
        .levelUpLearnset = sWhimsicottLevelUpLearnset,
        .teachableLearnset = sWhimsicottTeachableLearnset,
    },
#endif //P_FAMILY_COTTONEE

#if P_FAMILY_PETILIL
    [SPECIES_PETILIL] =
    {
        .baseHP        = 45,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 190,
        .expYield = 56,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_OWN_TEMPO, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Lilminip"),
#else
        .speciesName = _("PETILIL"),
#endif
        .cryId = CRY_PETILIL,
        .natDexNum = NATIONAL_DEX_PETILIL,
#if GERMAN
        .categoryName = _("Wurzel"),
#else
        .categoryName = _("Bulb"),
#endif
        .height = 5,
        .weight = 66,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Blätter auf seinem Kopf schmecken\n"
            "furchtbar bitter, doch sie helfen\n"
            "ausgezeichnet gegen Erschöpfung."),
#else
            "By pruning the leaves on its head with\n"
            "regularity, this Pokémon can be grown\n"
            "into a fine plump shape. These bitter\n"
            "leaves refresh those who eat them."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Petilil,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Petilil,
        .backPicSize = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Petilil,
        .shinyPalette = gMonShinyPalette_Petilil,
        .iconSprite = gMonIcon_Petilil,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, 6, SHADOW_SIZE_S)
        FOOTPRINT(Petilil)
        OVERWORLD(
            sPicTable_Petilil,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Petilil,
            gShinyOverworldPalette_Petilil
        )
        .levelUpLearnset = sPetililLevelUpLearnset,
        .teachableLearnset = sPetililTeachableLearnset,
        .eggMoveLearnset = sPetililEggMoveLearnset,
                            #if P_HISUIAN_FORMS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_LILLIGANT, CONDITIONS({IF_NOT_REGION, REGION_HISUI})}
                                ,{EVO_ITEM, ITEM_SUN_STONE, SPECIES_LILLIGANT_HISUI, CONDITIONS({IF_REGION, REGION_HISUI})}
                            ),
                            #else
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_LILLIGANT}),
                            #endif
    },

    [SPECIES_LILLIGANT] =
    {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 75,
        .expYield = 168,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_OWN_TEMPO, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Dressella"),
#else
        .speciesName = _("LILLIGANT"),
#endif
        .cryId = CRY_LILLIGANT,
        .natDexNum = NATIONAL_DEX_LILLIGANT,
#if GERMAN
        .categoryName = _("Blumenzier"),
#else
        .categoryName = _("Flowering"),
#endif
        .height = 11,
        .weight = 163,
        .description = COMPOUND_STRING(
#if GERMAN
        "Der Duft des Blumenschmucks auf seinem\n"
        "Kopf wirkt beruhigend. Damit der Schmuck\n"
        "nicht verwelkt, muss man es gut pflegen."),
#else
            "Even veteran Trainers face a challenge\n"
            "in getting its beautiful flower to bloom.\n"
            "It withers away if a trainer does not\n"
            "take good care of it."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lilligant,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Lilligant,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Lilligant,
        .shinyPalette = gMonShinyPalette_Lilligant,
        .iconSprite = gMonIcon_Lilligant,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 13, SHADOW_SIZE_M)
        FOOTPRINT(Lilligant)
        OVERWORLD(
            sPicTable_Lilligant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lilligant,
            gShinyOverworldPalette_Lilligant
        )
        .levelUpLearnset = sLilligantLevelUpLearnset,
        .teachableLearnset = sLilligantTeachableLearnset,
        .formSpeciesIdTable = sLilligantFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_LILLIGANT_HISUI] =
    {
        .baseHP        = 70,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 105,
        .baseSpAttack  = 50,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FIGHTING),
        .catchRate = 75,
        .expYield = 168,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .itemRare = ITEM_ABSORB_BULB,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_HUSTLE, ABILITY_LEAF_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Dressella-H"),
#else
        .speciesName = _("LILLIGANT-H"),
#endif
#else
#if GERMAN
        .speciesName = _("Dressella"),
#else
        .speciesName = _("LILLIGANT"),
#endif
#endif
        .cryId = CRY_LILLIGANT,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_LILLIGANT_HISUI,
#else
        .natDexNum = NATIONAL_DEX_LILLIGANT,
#endif
#if GERMAN
        .categoryName = _("Pirouetten"),
#else
        .categoryName = _("Spinning"),
#endif
        .height = 12,
        .weight = 192,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die starke Beinmuskulatur verdankt\n"
        "es wohl dem Leben auf schneebedeckten\n"
        "Bergen. Über seine Blumenkrone\n"
        "verströmt es stimulierende Düfte."),
#else
            "Its well-developed legs are the result of\n"
            "a life spent on mountains covered in deep\n"
            "snow. The scent it exudes from its flower\n"
            "crown heartens those in proximity."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LilligantHisui,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_LilligantHisui,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_LilligantHisui,
        .shinyPalette = gMonShinyPalette_LilligantHisui,
        .iconSprite = gMonIcon_LilligantHisui,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 13, SHADOW_SIZE_S)
        FOOTPRINT(Lilligant)
        OVERWORLD(
            sPicTable_LilligantHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_LilligantHisui,
            gShinyOverworldPalette_LilligantHisui
        )
        .isHisuianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sLilligantHisuiLevelUpLearnset,
        .teachableLearnset = sLilligantHisuiTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sLilligantHisuiFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sLilligantFormSpeciesIdTable,
#endif
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_PETILIL

#if P_FAMILY_BASCULIN
    [SPECIES_BASCULIN_RED_STRIPED] =
    {
        .baseHP        = 70,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 98,
        .baseSpAttack  = 80,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = 161,
        .evYield_Speed = 2,
        .itemRare = ITEM_DEEP_SEA_TOOTH,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_RECKLESS, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Barschuft"),
#else
        .speciesName = _("BASCULIN"),
#endif
        .cryId = CRY_BASCULIN,
        .natDexNum = NATIONAL_DEX_BASCULIN,
#if GERMAN
        .categoryName = _("Grobheit"),
#else
        .categoryName = _("Hostile"),
#endif
        .height = 10,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sie gelten als Delikatesse. Aufgrund\n"
        "ihrer brutalen Natur liegen rot und\n"
        "blau gestreifte Exemplare immer im Clinch."),
#else
            "It used to be a common food source. The\n"
            "meat of red Basculin is on the fatty side\n"
            "and it's more popular with the youth.\n"
            "Its temperament is vicious and aggressive."),
#endif
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BasculinRedStriped,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_BasculinRedStriped,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_BasculinRedStriped,
        .shinyPalette = gMonShinyPalette_BasculinRedStriped,
        .iconSprite = gMonIcon_BasculinRedStriped,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 4, SHADOW_SIZE_S)
        FOOTPRINT(Basculin)
        OVERWORLD(
            sPicTable_BasculinRedStriped,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BasculinRedStriped,
            gShinyOverworldPalette_BasculinRedStriped
        )
        .levelUpLearnset = sBasculinLevelUpLearnset,
        .teachableLearnset = sBasculinTeachableLearnset,
        .eggMoveLearnset = sBasculinEggMoveLearnset,
        .formSpeciesIdTable = sBasculinFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_RANDOM_FORM,
    },

    [SPECIES_BASCULIN_BLUE_STRIPED] =
    {
        .baseHP        = 70,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 98,
        .baseSpAttack  = 80,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = 161,
        .evYield_Speed = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Barschuft"),
#else
        .speciesName = _("BASCULIN"),
#endif
        .cryId = CRY_BASCULIN,
        .natDexNum = NATIONAL_DEX_BASCULIN,
#if GERMAN
        .categoryName = _("Grobheit"),
#else
        .categoryName = _("Hostile"),
#endif
        .height = 10,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es frisst alles, was ihm vor seinen\n"
        "gewaltigen Kiefer kommt. Doch im Angesicht\n"
        "noch stärkerer Pokémon wird es selbst\n"
        "schnell zur Beute."),
#else
            "They form schools with others of the same\n"
            "color. The greatest foe of a school of blue\n"
            "Basculin is a school of red Basculin.\n"
            "Its flavor is light and inoffensive."),
#endif
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BasculinBlueStriped,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_BasculinBlueStriped,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_BasculinBlueStriped,
        .shinyPalette = gMonShinyPalette_BasculinBlueStriped,
        .iconSprite = gMonIcon_BasculinBlueStriped,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 1, SHADOW_SIZE_S)
        FOOTPRINT(Basculin)
        OVERWORLD(
            sPicTable_BasculinBlueStriped,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BasculinBlueStriped,
            gShinyOverworldPalette_BasculinBlueStriped
        )
        .levelUpLearnset = sBasculinLevelUpLearnset,
        .teachableLearnset = sBasculinTeachableLearnset,
        .eggMoveLearnset = sBasculinEggMoveLearnset,
        .formSpeciesIdTable = sBasculinFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_HISUIAN_FORMS
    [SPECIES_BASCULIN_WHITE_STRIPED] =
    {
        .baseHP        = 70,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 98,
        .baseSpAttack  = 80,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 190,
        .expYield = 161,
        .evYield_Speed = 2,
        .itemRare = ITEM_DEEP_SEA_SCALE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_RATTLED, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Barschuft"),
#else
        .speciesName = _("BASCULIN"),
#endif
        .cryId = CRY_BASCULIN,
        .natDexNum = NATIONAL_DEX_BASCULIN,
#if GERMAN
        .categoryName = _("Sanftheit"),
#else
        .categoryName = _("Mellow"),
#endif
        .height = 10,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sie bilden Schwärme in extrem kalten\n"
        "Meeren und teilen sich ihr Futter. Wenn die\n"
        "Zeit reif ist, kehren sie zum Fluss ihrer\n"
        "Geburt zurück."),
#else
            "While this ancient form of Basculin shares\n"
            "a vast array of qualities with other forms,\n"
            "it differs in several respects, including\n"
            "demeanor, being much gentler than others."),
#endif
        .pokemonScale = 316,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BasculinWhiteStriped,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Basculin,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_BasculinWhiteStriped,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_BasculinWhiteStriped,
        .shinyPalette = gMonShinyPalette_BasculinWhiteStriped,
        .iconSprite = gMonIcon_BasculinWhiteStriped,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 5, SHADOW_SIZE_S)
        FOOTPRINT(Basculin)
        OVERWORLD(
            sPicTable_BasculinWhiteStriped,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BasculinWhiteStriped,
            gShinyOverworldPalette_BasculinWhiteStriped
        )
        .levelUpLearnset = sBasculinWhiteStripedLevelUpLearnset,
        .teachableLearnset = sBasculinWhiteStripedTeachableLearnset,
        .eggMoveLearnset = sBasculinWhiteStripedEggMoveLearnset,
        .formSpeciesIdTable = sBasculinFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_BASCULEGION_M, CONDITIONS({IF_RECOIL_DAMAGE_GE, 294}, {IF_GENDER, MON_MALE})},
                                {EVO_LEVEL, 0, SPECIES_BASCULEGION_F, CONDITIONS({IF_RECOIL_DAMAGE_GE, 294}, {IF_GENDER, MON_FEMALE})}),
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_BASCULEGION_M] =
    {
        .baseHP        = 120,
        .baseAttack    = 112,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 265,
        .evYield_HP = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Salmagnis"),
#else
        .speciesName = _("BASCULEGION"),
#endif
        .cryId = CRY_BASCULEGION,
        .natDexNum = NATIONAL_DEX_BASCULEGION,
#if GERMAN
        .categoryName = _("Großfisch"),
#else
        .categoryName = _("Big Fish"),
#endif
        .height = 30,
        .weight = 1100,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es hüllt seinen Körper in die Seelen von\n"
        "Artgenossen, die auf dem beschwerlichen\n"
        "Weg zum Fluss ihrer Geburt ihr Leben\n"
        "ließen."),
#else
            "Clads itself in the souls of comrades that\n"
            "perished before fulfilling their goals of\n"
            "journeying upstream. No other species in\n"
            "all Hisui's rivers is Basculegion's equal."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BasculegionM,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_BasculegionM,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_BasculegionM,
        .shinyPalette = gMonShinyPalette_BasculegionM,
        .iconSprite = gMonIcon_BasculegionM,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 16, SHADOW_SIZE_M)
        FOOTPRINT(Basculegion)
        OVERWORLD(
            sPicTable_BasculegionM,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BasculegionM,
            gShinyOverworldPalette_BasculegionM
        )
        .levelUpLearnset = sBasculegionLevelUpLearnset,
        .teachableLearnset = sBasculegionTeachableLearnset,
        .formSpeciesIdTable = sBasculegionFormSpeciesIdTable,
    },

    [SPECIES_BASCULEGION_F] =
    {
        .baseHP        = 120,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 78,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_WATER, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 265,
        .evYield_HP = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_2),
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_ADAPTABILITY, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Salmagnis"),
#else
        .speciesName = _("BASCULEGION"),
#endif
        .cryId = CRY_BASCULEGION,
        .natDexNum = NATIONAL_DEX_BASCULEGION,
#if GERMAN
        .categoryName = _("Großfisch"),
#else
        .categoryName = _("Big Fish"),
#endif
        .height = 30,
        .weight = 1100,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Seelen seiner Artgenossen\n"
        "umhüllen seinen Körper und werden\n"
        "zu der Antriebskraft, die es selbst\n"
        "durch reißende Ströme schwimmen lässt."),
#else
            "The souls of its comrades cloak its\n"
            "body and propel it effortlessly\n"
            "through even raging rapids."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BasculegionF,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_BasculegionF,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_BasculegionF,
        .shinyPalette = gMonShinyPalette_BasculegionF,
        .iconSprite = gMonIcon_BasculegionF,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 16, SHADOW_SIZE_M)
        FOOTPRINT(Basculegion)
        OVERWORLD(
            sPicTable_BasculegionF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BasculegionF,
            gShinyOverworldPalette_BasculegionF
        )
        .levelUpLearnset = sBasculegionLevelUpLearnset,
        .teachableLearnset = sBasculegionTeachableLearnset,
        .formSpeciesIdTable = sBasculegionFormSpeciesIdTable,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_BASCULIN

#if P_FAMILY_SANDILE
    [SPECIES_SANDILE] =
    {
        .baseHP        = 50,
        .baseAttack    = 72,
        .baseDefense   = 35,
        .baseSpeed     = 65,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_GROUND, TYPE_DARK),
        .catchRate = 180,
        .expYield = 58,
        .evYield_Attack = 1,
        .itemRare = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Ganovil"),
#else
        .speciesName = _("SANDILE"),
#endif
        .cryId = CRY_SANDILE,
        .natDexNum = NATIONAL_DEX_SANDILE,
#if GERMAN
        .categoryName = _("Wüstenkroko"),
#else
        .categoryName = _("Desert Croc"),
#endif
        .height = 7,
        .weight = 152,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wenn es sich durch den Sand gräbt,\n"
        "ragen nur noch Nase und Augen hervor.\n"
        "Die schwarze Haut dient als Augenschutz."),
#else
            "It conceals itself in the sand and\n"
            "chomps down on the legs of any prey\n"
            "that unwarily walk over it. Its favorite\n"
            "food is Trapinch."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sandile,
        .frontPicSize = MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = 18,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Sandile,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Sandile,
        .shinyPalette = gMonShinyPalette_Sandile,
        .iconSprite = gMonIcon_Sandile,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(4, -5, SHADOW_SIZE_M)
        FOOTPRINT(Sandile)
        OVERWORLD(
            sPicTable_Sandile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sandile,
            gShinyOverworldPalette_Sandile
        )
        .levelUpLearnset = sSandileLevelUpLearnset,
        .teachableLearnset = sSandileTeachableLearnset,
        .eggMoveLearnset = sSandileEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 29, SPECIES_KROKOROK}),
    },

    [SPECIES_KROKOROK] =
    {
        .baseHP        = 60,
        .baseAttack    = 82,
        .baseDefense   = 45,
        .baseSpeed     = 74,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_GROUND, TYPE_DARK),
        .catchRate = 90,
        .expYield = 123,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Rokkaiman"),
#else
        .speciesName = _("KROKOROK"),
#endif
        .cryId = CRY_KROKOROK,
        .natDexNum = NATIONAL_DEX_KROKOROK,
#if GERMAN
        .categoryName = _("Wüstenkroko"),
#else
        .categoryName = _("Desert Croc"),
#endif
        .height = 10,
        .weight = 334,
        .description = COMPOUND_STRING(
#if GERMAN
        "Bildet mit mehreren Artgenossen ein Rudel.\n"
        "Eine Membran schützt seine Augen vor\n"
        "Sandstürmen."),
#else
            "They move in groups of a few individuals.\n"
            "Thanks to the special membrane covering\n"
            "its eyes, it can see its surroundings\n"
            "clearly, even in the dead of night."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Krokorok,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Krokorok,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Krokorok,
        .shinyPalette = gMonShinyPalette_Krokorok,
        .iconSprite = gMonIcon_Krokorok,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Krokorok)
        OVERWORLD(
            sPicTable_Krokorok,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Krokorok,
            gShinyOverworldPalette_Krokorok
        )
        .levelUpLearnset = sKrokorokLevelUpLearnset,
        .teachableLearnset = sKrokorokTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_KROOKODILE}),
    },

    [SPECIES_KROOKODILE] =
    {
        .baseHP        = 95,
        .baseAttack    = 117,
        .baseDefense   = P_UPDATED_STATS >= GEN_6 ? 80 : 70,
        .baseSpeed     = 92,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_GROUND, TYPE_DARK),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 260,
    #elif P_UPDATED_EXP_YIELDS >= GEN_6
        .expYield = 234,
    #else
        .expYield = 229,
    #endif
        .evYield_Attack = 3,
        .itemCommon = ITEM_BLACK_GLASSES,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_MOXIE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Rabigator"),
#else
        .speciesName = _("KROOKODILE"),
#endif
        .cryId = CRY_KROOKODILE,
        .natDexNum = NATIONAL_DEX_KROOKODILE,
#if GERMAN
        .categoryName = _("Abschreckung"),
#else
        .categoryName = _("Intimidate"),
#endif
        .height = 15,
        .weight = 963,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein äußerst grausames Pokémon. Es greift\n"
            "jeden, der ihm unter die Augen kommt, mit\n"
            "seinen scharfen Reißzähnen an."),
#else
            "Very violent Pokémon, they never allow\n"
            "their prey to escape. Their jaws are so\n"
            "powerful, they can crush the body of\n"
            "an automobile."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Krookodile,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        .backPic = gMonBackPic_Krookodile,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Krookodile,
        .shinyPalette = gMonShinyPalette_Krookodile,
        .iconSprite = gMonIcon_Krookodile,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 12, SHADOW_SIZE_L)
        FOOTPRINT(Krookodile)
        OVERWORLD(
            sPicTable_Krookodile,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Krookodile,
            gShinyOverworldPalette_Krookodile
        )
        .levelUpLearnset = sKrookodileLevelUpLearnset,
        .teachableLearnset = sKrookodileTeachableLearnset,
    },
#endif //P_FAMILY_SANDILE

#if P_FAMILY_DARUMAKA
    [SPECIES_DARUMAKA] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 15,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 120,
        .expYield = 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Flampion"),
#else
        .speciesName = _("DARUMAKA"),
#endif
        .cryId = CRY_DARUMAKA,
        .natDexNum = NATIONAL_DEX_DARUMAKA,
#if GERMAN
        .categoryName = _("Lampion"),
#else
        .categoryName = _("Zen Charm"),
#endif
        .height = 6,
        .weight = 375,
        .description = COMPOUND_STRING(
#if GERMAN
        "Früher nutzte man die heißen\n"
        "Ausscheidungen von Flampion, um sich den\n"
        "Körper zu wärmen."),
#else
            "When its internal fire is burning, it\n"
            "cannot calm down and it runs around.\n"
            "When the fire diminishes, it pulls its\n"
            "limbs into its body and falls asleep."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Darumaka,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Darumaka,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Darumaka,
        .shinyPalette = gMonShinyPalette_Darumaka,
        .iconSprite = gMonIcon_Darumaka,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, 1, SHADOW_SIZE_S)
        FOOTPRINT(Darumaka)
        OVERWORLD(
            sPicTable_Darumaka,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Darumaka,
            gShinyOverworldPalette_Darumaka
        )
        .levelUpLearnset = sDarumakaLevelUpLearnset,
        .teachableLearnset = sDarumakaTeachableLearnset,
        .eggMoveLearnset = sDarumakaEggMoveLearnset,
        .formSpeciesIdTable = sDarumakaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_DARMANITAN_STANDARD}),
    },

    [SPECIES_DARMANITAN_STANDARD] =
    {
        .baseHP        = 105,
        .baseAttack    = 140,
        .baseDefense   = 55,
        .baseSpeed     = 95,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 60,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_ZEN_MODE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Flampivian"),
#else
        .speciesName = _("DARMANITAN"),
#endif
        .cryId = CRY_DARMANITAN,
        .natDexNum = NATIONAL_DEX_DARMANITAN,
#if GERMAN
        .categoryName = _("Lichterloh"),
#else
        .categoryName = _("Blazing"),
#endif
        .height = 13,
        .weight = 929,
        .description = COMPOUND_STRING(
#if GERMAN
        "Nimmt es in einem heißen Kampf Schaden,\n"
        "wird es hart wie Stein und fällt in eine\n"
        "Trance, um seinen Verstand zu schärfen."),
#else
            "When one is injured in a fierce battle,\n"
            "it transforms into a stone statue.\n"
            "Then it meditates and sharpens its\n"
            "mind and fights on mentally."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DarmanitanStandard,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_DarmanitanStandard,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_DarmanitanStandard,
        .shinyPalette = gMonShinyPalette_DarmanitanStandard,
        .iconSprite = gMonIcon_DarmanitanStandard,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 5, SHADOW_SIZE_L)
        FOOTPRINT(Darmanitan)
        OVERWORLD(
            sPicTable_DarmanitanStandard,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DarmanitanStandard,
            gShinyOverworldPalette_DarmanitanStandard
        )
        .levelUpLearnset = sDarmanitanLevelUpLearnset,
        .teachableLearnset = sDarmanitanTeachableLearnset,
        .formSpeciesIdTable = sDarmanitanFormSpeciesIdTable,
        .formChangeTable = sDarmanitanFormChangeTable,
    },

    [SPECIES_DARMANITAN_ZEN] =
    {
        .baseHP        = 105,
        .baseAttack    = 30,
        .baseDefense   = 105,
        .baseSpeed     = 55,
        .baseSpAttack  = 140,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_FIRE, TYPE_PSYCHIC),
        .catchRate = 60,
        .expYield = 189,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_ZEN_MODE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Flampivian"),
#else
        .speciesName = _("DARMANITAN"),
#endif
        .cryId = CRY_DARMANITAN,
        .natDexNum = NATIONAL_DEX_DARMANITAN,
#if GERMAN
        .categoryName = _("Lichterloh"),
#else
        .categoryName = _("Blazing"),
#endif
        .height = 13,
        .weight = 929,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es meditiert, um seine wilden Impulse zu\n"
        "zügeln. Dies hat zugleich eine beachtliche\n"
        "Steigerung seiner Psycho-Kräfte zur\n"
        "Folge."),
#else
            "When wounded, it stops moving. It\n"
            "goes as still as stone to meditate,\n"
            "sharpening its mind and spirit."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DarmanitanZen,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_DarmanitanZen,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_DarmanitanZen,
        .shinyPalette = gMonShinyPalette_DarmanitanZen,
        .iconSprite = gMonIcon_DarmanitanZen,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, -1, SHADOW_SIZE_S)
        FOOTPRINT(Darmanitan)
        .levelUpLearnset = sDarmanitanLevelUpLearnset,
        .teachableLearnset = sDarmanitanTeachableLearnset,
        .formSpeciesIdTable = sDarmanitanFormSpeciesIdTable,
        .formChangeTable = sDarmanitanFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#if P_GALARIAN_FORMS
    [SPECIES_DARUMAKA_GALAR] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 15,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 120,
        .expYield = 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_WHITE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Flampion-G"),
#else
        .speciesName = _("DARUMAKA-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Flampion"),
#else
        .speciesName = _("DARUMAKA"),
#endif
#endif
        .cryId = CRY_DARUMAKA,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_DARUMAKA_GALAR,
#else
        .natDexNum = NATIONAL_DEX_DARUMAKA,
#endif
#if GERMAN
        .categoryName = _("Lampion"),
#else
        .categoryName = _("Zen Charm"),
#endif
        .height = 7,
        .weight = 400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seit es in kälteren Gefilden lebt, hat sich\n"
            "sein innerer Flammensack zurückgebildet.\n"
            "Stattdessen wuchs ein Organ heran, das\n"
            "eiskalte Luft erzeugt."),
#else
            "The colder they get, the more\n"
            "energetic they are. They freeze their\n"
            "breath to make snowballs, using them\n"
            "as ammo for playful snowball fights."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DarumakaGalar,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DarumakaGalar,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DarumakaGalar,
        .shinyPalette = gMonShinyPalette_DarumakaGalar,
        .iconSprite = gMonIcon_DarumakaGalar,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, -1, SHADOW_SIZE_S)
        FOOTPRINT(Darumaka)
        OVERWORLD(
            sPicTable_DarumakaGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DarumakaGalar,
            gShinyOverworldPalette_DarumakaGalar
        )
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sDarumakaGalarLevelUpLearnset,
        .teachableLearnset = sDarumakaGalarTeachableLearnset,
        .eggMoveLearnset = sDarumakaGalarEggMoveLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sDarumakaGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sDarumakaFormSpeciesIdTable,
#endif
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_ICE_STONE, SPECIES_DARMANITAN_GALAR_STANDARD}),
    },

    [SPECIES_DARMANITAN_GALAR_STANDARD] =
    {
        .baseHP        = 105,
        .baseAttack    = 140,
        .baseDefense   = 55,
        .baseSpeed     = 95,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 60,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GORILLA_TACTICS, ABILITY_NONE, ABILITY_ZEN_MODE },
        .bodyColor = BODY_COLOR_WHITE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Flampivian-G"),
#else
        .speciesName = _("DARMANITAN-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Flampivian"),
#else
        .speciesName = _("DARMANITAN"),
#endif
#endif
        .cryId = CRY_DARMANITAN,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_DARMANITAN_GALAR,
#else
        .natDexNum = NATIONAL_DEX_DARMANITAN,
#endif
#if GERMAN
        .categoryName = _("Lampion"),
#else
        .categoryName = _("Zen Charm"),
#endif
        .height = 17,
        .weight = 1200,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es lagert Futter in dem Schneeball auf\n"
        "seinem Kopf und trägt es nach Hause. Bei\n"
        "Schneestürmen steigt es zu den Siedlungen\n"
        "der Menschen hinab."),
#else
            "On days when blizzards blow\n"
            "through, it comes down to where people\n"
            "live. It stashes food in the snowball on\n"
            "its head, taking it home for later."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DarmanitanGalarStandard,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DarmanitanGalarStandard,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DarmanitanGalarStandard,
        .shinyPalette = gMonShinyPalette_DarmanitanGalarStandard,
        .iconSprite = gMonIcon_DarmanitanGalarStandard,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_L)
        FOOTPRINT(Darmanitan)
        OVERWORLD(
            sPicTable_DarmanitanGalarStandard,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DarmanitanGalarStandard,
            gShinyOverworldPalette_DarmanitanGalarStandard
        )
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sDarmanitanGalarLevelUpLearnset,
        .teachableLearnset = sDarmanitanGalarTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sDarmanitanGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sDarmanitanFormSpeciesIdTable,
#endif
        .formChangeTable = sDarmanitanGalarFormChangeTable,
    },

    [SPECIES_DARMANITAN_GALAR_ZEN] =
    {
        .baseHP        = 105,
        .baseAttack    = 160,
        .baseDefense   = 55,
        .baseSpeed     = 135,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_ICE, TYPE_FIRE),
        .catchRate = 60,
        .expYield = 189,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GORILLA_TACTICS, ABILITY_NONE, ABILITY_ZEN_MODE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Flampivian-G"),
#else
        .speciesName = _("DARMANITAN-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Flampivian"),
#else
        .speciesName = _("DARMANITAN"),
#endif
#endif
        .cryId = CRY_DARMANITAN,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_DARMANITAN_GALAR,
#else
        .natDexNum = NATIONAL_DEX_DARMANITAN,
#endif
#if GERMAN
        .categoryName = _("Lichterloh"),
#else
        .categoryName = _("Blazing"),
#endif
        .height = 17,
        .weight = 1200,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es lagert Futter in dem Schneeball auf\n"
        "seinem Kopf und trägt es nach Hause. Bei\n"
        "Schneestürmen steigt es zu den Siedlungen\n"
        "der Menschen hinab."),
#else
            "Darmanitan takes this form when\n"
            "enraged. It won't stop spewing flames\n"
            "until its rage has settled, even if\n"
            "its body starts to melt."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_DarmanitanGalarZen,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_DarmanitanGalarZen,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_DarmanitanGalarZen,
        .shinyPalette = gMonShinyPalette_DarmanitanGalarZen,
        .iconSprite = gMonIcon_DarmanitanGalarZen,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 11, SHADOW_SIZE_S)
        FOOTPRINT(Darmanitan)
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sDarmanitanGalarLevelUpLearnset,
        .teachableLearnset = sDarmanitanGalarTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sDarmanitanGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sDarmanitanFormSpeciesIdTable,
#endif
        .formChangeTable = sDarmanitanGalarFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_DARUMAKA

#if P_FAMILY_MARACTUS
    [SPECIES_MARACTUS] =
    {
        .baseHP        = 75,
        .baseAttack    = 86,
        .baseDefense   = 67,
        .baseSpeed     = 60,
        .baseSpAttack  = 106,
        .baseSpDefense = 67,
        .types = MON_TYPES(TYPE_GRASS),
        .catchRate = 255,
        .expYield = 161,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CHLOROPHYLL, ABILITY_STORM_DRAIN },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Maracamba"),
#else
        .speciesName = _("MARACTUS"),
#endif
        .cryId = CRY_MARACTUS,
        .natDexNum = NATIONAL_DEX_MARACTUS,
#if GERMAN
        .categoryName = _("Kaktus"),
#else
        .categoryName = _("Cactus"),
#endif
        .height = 10,
        .weight = 280,
        .description = COMPOUND_STRING(
#if GERMAN
        "Verjagt Vogel-Pokémon,\n"
        "die auf seine Blüten aus sind, mit einem\n"
        "flotten Tänzchen und lauter Untermalung."),
#else
            "Arid regions are their habitat.\n"
            "When it moves rhythmically, it makes a\n"
            "sound similar to maracas, making the\n"
            "surprised Pokémon flee."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 6,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Maractus,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Maractus,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Maractus,
        .shinyPalette = gMonShinyPalette_Maractus,
        .iconSprite = gMonIcon_Maractus,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_S)
        FOOTPRINT(Maractus)
        OVERWORLD(
            sPicTable_Maractus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Maractus,
            gShinyOverworldPalette_Maractus
        )
        .levelUpLearnset = sMaractusLevelUpLearnset,
        .teachableLearnset = sMaractusTeachableLearnset,
        .eggMoveLearnset = sMaractusEggMoveLearnset,
    },
#endif //P_FAMILY_MARACTUS

#if P_FAMILY_DWEBBLE
    [SPECIES_DWEBBLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = MON_TYPES(TYPE_BUG, TYPE_ROCK),
        .catchRate = 190,
        .expYield = 65,
        .evYield_Defense = 1,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STURDY, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Lithomith"),
#else
        .speciesName = _("DWEBBLE"),
#endif
        .cryId = CRY_DWEBBLE,
        .natDexNum = NATIONAL_DEX_DWEBBLE,
#if GERMAN
        .categoryName = _("Steinhaus"),
#else
        .categoryName = _("Rock Inn"),
#endif
        .height = 3,
        .weight = 145,
        .description = COMPOUND_STRING(
#if GERMAN
        "Höhlt sich einen brauchbaren Stein\n"
        "aus, um darin zu wohnen. Geht er zu Bruch,\n"
        "ruht es nicht, bis es einen neuen findet."),
#else
            "It makes a hole in a stone of a suitable\n"
            "size. If that rock breaks, the Pokémon\n"
            "remains agitated until it locates\n"
            "a replacement."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Dwebble,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 50),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Dwebble,
        .backPicSize = MON_COORDS_SIZE(56, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Dwebble,
        .shinyPalette = gMonShinyPalette_Dwebble,
        .iconSprite = gMonIcon_Dwebble,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -2, SHADOW_SIZE_S)
        FOOTPRINT(Dwebble)
        OVERWORLD(
            sPicTable_Dwebble,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dwebble,
            gShinyOverworldPalette_Dwebble
        )
        .levelUpLearnset = sDwebbleLevelUpLearnset,
        .teachableLearnset = sDwebbleTeachableLearnset,
        .eggMoveLearnset = sDwebbleEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_CRUSTLE}),
    },

    [SPECIES_CRUSTLE] =
    {
        .baseHP        = 70,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 105 : 95,
        .baseDefense   = 125,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_BUG, TYPE_ROCK),
        .catchRate = 75,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_7) ? 170 : 166,
        .evYield_Defense = 2,
        .itemRare = ITEM_HARD_STONE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STURDY, ABILITY_SHELL_ARMOR, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Castellith"),
#else
        .speciesName = _("CRUSTLE"),
#endif
        .cryId = CRY_CRUSTLE,
        .natDexNum = NATIONAL_DEX_CRUSTLE,
#if GERMAN
        .categoryName = _("Felshaus"),
#else
        .categoryName = _("Stone Home"),
#endif
        .height = 14,
        .weight = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
        "Castellith ist hart genug im Nehmen, um\n"
        "mitsamt seines schweren Felsens mehrere\n"
        "Tage durch trockene Gebiete zu wandern."),
#else
            "Competing for territory, Crustle fight\n"
            "viciously. The one whose boulder is\n"
            "broken is the loser of the battle and\n"
            "begins to weaken."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Crustle,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Crustle,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Crustle,
        .shinyPalette = gMonShinyPalette_Crustle,
        .iconSprite = gMonIcon_Crustle,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 8, SHADOW_SIZE_L)
        FOOTPRINT(Crustle)
        OVERWORLD(
            sPicTable_Crustle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Crustle,
            gShinyOverworldPalette_Crustle
        )
        .levelUpLearnset = sCrustleLevelUpLearnset,
        .teachableLearnset = sCrustleTeachableLearnset,
    },
#endif //P_FAMILY_DWEBBLE

#if P_FAMILY_SCRAGGY
    [SPECIES_SCRAGGY] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 48,
        .baseSpAttack  = 35,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIGHTING),
        .catchRate = 180,
        .expYield = 70,
        .evYield_Attack = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Zurrokex"),
#else
        .speciesName = _("SCRAGGY"),
#endif
        .cryId = CRY_SCRAGGY,
        .natDexNum = NATIONAL_DEX_SCRAGGY,
#if GERMAN
        .categoryName = _("Hautwechsel"),
#else
        .categoryName = _("Shedding"),
#endif
        .height = 6,
        .weight = 118,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zurrokex zieht seine gummiartige Haut bis\n"
        "zum Hals hinauf und nimmt eine\n"
        "Abwehrhaltung ein, um sich vor Schaden zu\n"
        "schützen."),
#else
            "Its skin has a rubbery elasticity, so it\n"
            "can reduce damage by defensively\n"
            "pulling its skin up to its neck.\n"
            "Its skull is massively thick."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Scraggy,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Scraggy,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Scraggy,
        .shinyPalette = gMonShinyPalette_Scraggy,
        .iconSprite = gMonIcon_Scraggy,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-4, 2, SHADOW_SIZE_S)
        FOOTPRINT(Scraggy)
        OVERWORLD(
            sPicTable_Scraggy,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Scraggy,
            gShinyOverworldPalette_Scraggy
        )
        .levelUpLearnset = sScraggyLevelUpLearnset,
        .teachableLearnset = sScraggyTeachableLearnset,
        .eggMoveLearnset = sScraggyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_SCRAFTY}),
    },

    [SPECIES_SCRAFTY] =
    {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 115,
        .baseSpeed     = 58,
        .baseSpAttack  = 45,
        .baseSpDefense = 115,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIGHTING),
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Irokex"),
#else
        .speciesName = _("SCRAFTY"),
#endif
        .cryId = CRY_SCRAFTY,
        .natDexNum = NATIONAL_DEX_SCRAFTY,
#if GERMAN
        .categoryName = _("Halunke"),
#else
        .categoryName = _("Hoodlum"),
#endif
        .height = 11,
        .weight = 300,
        .description = COMPOUND_STRING(
#if GERMAN
        "Irokex wehrt Angriffe mit seiner alten\n"
        "Haut ab und kontert mit Tritten. Sein\n"
        "Ego entspricht der Größe seines Kamms."),
#else
            "Groups of them beat up anything that\n"
            "enters their territory. The one with the\n"
            "biggest crest is the group leader, and\n"
            "is the most respected."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Scrafty,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Scrafty,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Scrafty,
        .shinyPalette = gMonShinyPalette_Scrafty,
        .iconSprite = gMonIcon_Scrafty,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 9, SHADOW_SIZE_M)
        FOOTPRINT(Scrafty)
        OVERWORLD(
            sPicTable_Scrafty,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Scrafty,
            gShinyOverworldPalette_Scrafty
        )
        .levelUpLearnset = sScraftyLevelUpLearnset,
        .teachableLearnset = sScraftyTeachableLearnset,
        .formSpeciesIdTable = sScraftyFormSpeciesIdTable,
        .formChangeTable = sScraftyFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_SCRAFTY_MEGA] =
    {
        .baseHP        = 65,
        .baseAttack    = 130,
        .baseDefense   = 135,
        .baseSpeed     = 68,
        .baseSpAttack  = 55,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_DARK, TYPE_FIGHTING),
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_SHED_SKIN, ABILITY_MOXIE, ABILITY_INTIMIDATE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Irokex"),
#else
        .speciesName = _("SCRAFTY"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_SCRAFTY_MEGA,
    #else
        .cryId = CRY_SCRAFTY,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_SCRAFTY,
#if GERMAN
        .categoryName = _("Halunke"),
#else
        .categoryName = _("Hoodlum"),
#endif
        .height = 11,
        .weight = 310,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Mega-Entwicklung färbte seine Haut\n"
        "weiß und verlieh ihr Härte und\n"
        "Geschmeidigkeit. Sein großer Kampfgeist\n"
        "blieb jedoch unverändert."),
#else
            "Mega Evolution has caused Scrafty's\n"
            "shed skin to turn white, growing\n"
            "tough and supple. Of course, this\n"
            "Pokémon is still as feisty as ever."),
#endif
        .frontPic = gMonFrontPic_ScraftyMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ScraftyMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ScraftyMega,
        .shinyPalette = gMonShinyPalette_ScraftyMega,
        .iconSprite = gMonIcon_ScraftyMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Scrafty)
        SHADOW(-4, 12, SHADOW_SIZE_M)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sScraftyLevelUpLearnset,
        .teachableLearnset = sScraftyTeachableLearnset,
        .formSpeciesIdTable = sScraftyFormSpeciesIdTable,
        .formChangeTable = sScraftyFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_SCRAGGY

#if P_FAMILY_SIGILYPH
    [SPECIES_SIGILYPH] =
    {
        .baseHP        = 72,
        .baseAttack    = 58,
        .baseDefense   = 80,
        .baseSpeed     = 97,
        .baseSpAttack  = 103,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 172,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_WONDER_SKIN, ABILITY_MAGIC_GUARD, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Symvolara"),
#else
        .speciesName = _("SIGILYPH"),
#endif
        .cryId = CRY_SIGILYPH,
        .natDexNum = NATIONAL_DEX_SIGILYPH,
#if GERMAN
        .categoryName = _("Vogelgleich"),
#else
        .categoryName = _("Avianoid"),
#endif
        .height = 14,
        .weight = 140,
        .description = COMPOUND_STRING(
#if GERMAN
        "Einst war es der Wächter einer Stadt\n"
        "aus uralten Zeiten. Wer sich in sein Revier\n"
        "wagt, lernt seine Psycho-Kräfte kennen."),
#else
            "The guardians of an ancient city, they\n"
            "always fly the same route while keeping\n"
            "watch for invaders. They use their\n"
            "psychic power to attack enemies."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Sigilyph,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
            ANIMCMD_FRAME(1, 7),
            ANIMCMD_FRAME(0, 7),
        ),
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Sigilyph,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Sigilyph,
        .shinyPalette = gMonShinyPalette_Sigilyph,
        .iconSprite = gMonIcon_Sigilyph,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 18, SHADOW_SIZE_S)
        FOOTPRINT(Sigilyph)
        OVERWORLD(
            sPicTable_Sigilyph,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Sigilyph,
            gShinyOverworldPalette_Sigilyph
        )
        .levelUpLearnset = sSigilyphLevelUpLearnset,
        .teachableLearnset = sSigilyphTeachableLearnset,
        .eggMoveLearnset = sSigilyphEggMoveLearnset,
    },
#endif //P_FAMILY_SIGILYPH

#if P_FAMILY_YAMASK
    [SPECIES_YAMASK] =
    {
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense = 1,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_MUMMY, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Makabaja"),
#else
        .speciesName = _("YAMASK"),
#endif
        .cryId = CRY_YAMASK,
        .natDexNum = NATIONAL_DEX_YAMASK,
#if GERMAN
        .categoryName = _("Seele"),
#else
        .categoryName = _("Spirit"),
#endif
        .height = 5,
        .weight = 15,
        .description = COMPOUND_STRING(
#if GERMAN
        "Makabaja entsteht aus den Seelen von\n"
        "längst begrabenen Menschen und kann sich\n"
        "immer noch an deren Vergangenheit\n"
        "erinnern."),
#else
            "These Pokémon arose from the spirits\n"
            "of people interred in graves in past ages.\n"
            "Each of them carries a mask that used\n"
            "to be its face when it was human."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Yamask,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Yamask,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Yamask,
        .shinyPalette = gMonShinyPalette_Yamask,
        .iconSprite = gMonIcon_Yamask,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_S)
        FOOTPRINT(Yamask)
        OVERWORLD(
            sPicTable_Yamask,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Yamask,
            gShinyOverworldPalette_Yamask
        )
        .levelUpLearnset = sYamaskLevelUpLearnset,
        .teachableLearnset = sYamaskTeachableLearnset,
        .eggMoveLearnset = sYamaskEggMoveLearnset,
        .formSpeciesIdTable = sYamaskFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COFAGRIGUS}),
    },

    [SPECIES_COFAGRIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 50,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 95,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_GHOST),
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .itemRare = ITEM_SPELL_TAG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_MUMMY, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Echnatoll"),
#else
        .speciesName = _("COFAGRIGUS"),
#endif
        .cryId = CRY_COFAGRIGUS,
        .natDexNum = NATIONAL_DEX_COFAGRIGUS,
#if GERMAN
        .categoryName = _("Sarkophag"),
#else
        .categoryName = _("Coffin"),
#endif
        .height = 17,
        .weight = 765,
        .description = COMPOUND_STRING(
#if GERMAN
        "Angeblich verschlingt es jeden,\n"
        "der sich ihm auch nur nähert. Besonders\n"
        "gern frisst es Klumpen aus reinem Gold."),
#else
            "Grave robbers who mistake them for\n"
            "real coffins and get too close end up\n"
            "trapped inside their bodies. Their bodies\n"
            "are covered in pure gold."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Cofagrigus,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GLOW_BLACK,
        .backPic = gMonBackPic_Cofagrigus,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Cofagrigus,
        .shinyPalette = gMonShinyPalette_Cofagrigus,
        .iconSprite = gMonIcon_Cofagrigus,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 12, SHADOW_SIZE_M)
        FOOTPRINT(Cofagrigus)
        OVERWORLD(
            sPicTable_Cofagrigus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cofagrigus,
            gShinyOverworldPalette_Cofagrigus
        )
        .levelUpLearnset = sCofagrigusLevelUpLearnset,
        .teachableLearnset = sCofagrigusTeachableLearnset,
    },

#if P_GALARIAN_FORMS
    [SPECIES_YAMASK_GALAR] =
    {
        .baseHP        = 38,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GHOST),
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WANDERING_SPIRIT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Makabaja-G"),
#else
        .speciesName = _("YAMASK-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Makabaja"),
#else
        .speciesName = _("YAMASK"),
#endif
#endif
        .cryId = CRY_YAMASK,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_YAMASK_GALAR,
#else
        .natDexNum = NATIONAL_DEX_YAMASK,
#endif
#if GERMAN
        .categoryName = _("Seele"),
#else
        .categoryName = _("Spirit"),
#endif
        .height = 5,
        .weight = 15,
        .description = COMPOUND_STRING(
#if GERMAN
        "Eine Tontafel, auf der ein Fluch eingeritzt\n"
        "wurde, hat Besitz von diesem Makabaja\n"
        "ergriffen. Man sagt, es ziehe seine Kraft\n"
        "aus dem Groll anderer."),
#else
            "A clay slab with cursed engravings\n"
            "took possession of a Yamask. The\n"
            "slab is said to be absorbing the\n"
            "Yamask's dark power."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_YamaskGalar,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_YamaskGalar,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_YamaskGalar,
        .shinyPalette = gMonShinyPalette_YamaskGalar,
        .iconSprite = gMonIcon_YamaskGalar,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Yamask)
        OVERWORLD(
            sPicTable_YamaskGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_YamaskGalar,
            gShinyOverworldPalette_YamaskGalar
        )
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sYamaskGalarLevelUpLearnset,
        .teachableLearnset = sYamaskGalarTeachableLearnset,
        .eggMoveLearnset = sYamaskGalarEggMoveLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sYamaskGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sYamaskFormSpeciesIdTable,
#endif
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_PEAT_BLOCK, SPECIES_RUNERIGUS},
                                {EVO_SCRIPT_TRIGGER, 0, SPECIES_RUNERIGUS, CONDITIONS({IF_CURRENT_DAMAGE_GE, 49})}),
    },

    [SPECIES_RUNERIGUS] =
    {
        .baseHP        = 58,
        .baseAttack    = 95,
        .baseDefense   = 145,
        .baseSpeed     = 30,
        .baseSpAttack  = 50,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GHOST),
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WANDERING_SPIRIT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Oghnatoll"),
#else
        .speciesName = _("RUNERIGUS"),
#endif
        .cryId = CRY_RUNERIGUS,
        .natDexNum = NATIONAL_DEX_RUNERIGUS,
#if GERMAN
        .categoryName = _("Gram"),
#else
        .categoryName = _("Grudge"),
#endif
        .height = 16,
        .weight = 666,
        .description = COMPOUND_STRING(
#if GERMAN
        "Eine antike Malerei, die mit einem\n"
        "mächtigen Fluch versehen wurde, nahm die\n"
        "Seele eines Makabaja auf und erwachte zum\n"
        "Leben."),
#else
            "A powerful curse was woven into an ancient\n"
            "painting. After absorbing the spirit of\n"
            "a Yamask, the painting began to move."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Runerigus,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Runerigus,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Runerigus,
        .shinyPalette = gMonShinyPalette_Runerigus,
        .iconSprite = gMonIcon_Runerigus,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(14, 14, SHADOW_SIZE_M)
        FOOTPRINT(Runerigus)
        OVERWORLD(
            sPicTable_Runerigus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Runerigus,
            gShinyOverworldPalette_Runerigus
        )
        .levelUpLearnset = sRunerigusLevelUpLearnset,
        .teachableLearnset = sRunerigusTeachableLearnset,
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_YAMASK

#if P_FAMILY_TIRTOUGA
    [SPECIES_TIRTOUGA] =
    {
        .baseHP        = 54,
        .baseAttack    = 78,
        .baseDefense   = 103,
        .baseSpeed     = 22,
        .baseSpAttack  = 53,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_WATER, TYPE_ROCK),
        .catchRate = 45,
        .expYield = 71,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SOLID_ROCK, ABILITY_STURDY, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Galapaflos"),
#else
        .speciesName = _("TIRTOUGA"),
#endif
        .cryId = CRY_TIRTOUGA,
        .natDexNum = NATIONAL_DEX_TIRTOUGA,
#if GERMAN
        .categoryName = _("Urzeitkröte"),
#else
        .categoryName = _("Prototurtle"),
#endif
        .height = 7,
        .weight = 165,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schwamm bereits vor 100 Millionen Jahren\n"
        "durch die Meere. Ab und zu führt es die\n"
        "Jagd auch an Land."),
#else
            "Reputed to be the ancestor of most\n"
            "turtle Pokémon, it lived in warm seas\n"
            "about a hundred million years ago.\n"
            "It was restored from a fossil."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tirtouga,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Tirtouga,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Tirtouga,
        .shinyPalette = gMonShinyPalette_Tirtouga,
        .iconSprite = gMonIcon_Tirtouga,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, -3, SHADOW_SIZE_M)
        FOOTPRINT(Tirtouga)
        OVERWORLD(
            sPicTable_Tirtouga,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tirtouga,
            gShinyOverworldPalette_Tirtouga
        )
        .levelUpLearnset = sTirtougaLevelUpLearnset,
        .teachableLearnset = sTirtougaTeachableLearnset,
        .eggMoveLearnset = sTirtougaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_CARRACOSTA}),
    },

    [SPECIES_CARRACOSTA] =
    {
        .baseHP        = 74,
        .baseAttack    = 108,
        .baseDefense   = 133,
        .baseSpeed     = 32,
        .baseSpAttack  = 83,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_WATER, TYPE_ROCK),
        .catchRate = 45,
        .expYield = 173,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_SOLID_ROCK, ABILITY_STURDY, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Karippas"),
#else
        .speciesName = _("CARRACOSTA"),
#endif
        .cryId = CRY_CARRACOSTA,
        .natDexNum = NATIONAL_DEX_CARRACOSTA,
#if GERMAN
        .categoryName = _("Urzeitkröte"),
#else
        .categoryName = _("Prototurtle"),
#endif
        .height = 12,
        .weight = 810,
        .description = COMPOUND_STRING(
#if GERMAN
        "Karippas lebt im Meer und an Land. Es\n"
        "ist so stark, dass es mit einem einzigen\n"
        "Hieb ein Loch in ein Schiff reißen kann."),
#else
            "They can live both in the ocean and\n"
            "on land. Incredible jaw strength enables\n"
            "them to chew up steel beams and rocks\n"
            "along with their prey."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Carracosta,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
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
        .frontAnimId = ANIM_H_SHAKE_SLOW,
        .backPic = gMonBackPic_Carracosta,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Carracosta,
        .shinyPalette = gMonShinyPalette_Carracosta,
        .iconSprite = gMonIcon_Carracosta,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_L)
        FOOTPRINT(Carracosta)
        OVERWORLD(
            sPicTable_Carracosta,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Carracosta,
            gShinyOverworldPalette_Carracosta
        )
        .levelUpLearnset = sCarracostaLevelUpLearnset,
        .teachableLearnset = sCarracostaTeachableLearnset,
    },
#endif //P_FAMILY_TIRTOUGA

#if P_FAMILY_ARCHEN
    [SPECIES_ARCHEN] =
    {
        .baseHP        = 55,
        .baseAttack    = 112,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 74,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 71,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_DEFEATIST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Flapteryx"),
#else
        .speciesName = _("ARCHEN"),
#endif
        .cryId = CRY_ARCHEN,
        .natDexNum = NATIONAL_DEX_ARCHEN,
#if GERMAN
        .categoryName = _("Urzeitvogel"),
#else
        .categoryName = _("First Bird"),
#endif
        .height = 5,
        .weight = 95,
        .description = COMPOUND_STRING(
#if GERMAN
        "Flapteryx wurde aus einem Fossil\n"
        "reanimiert. Man geht davon aus, dass\n"
        "es der Urahn aller Vogel-Pokémon ist."),
#else
            "Said to be the ancestor of all bird\n"
            "Pokémon, Archen itself could not actually\n"
            "fly but moved by hopping from treetop\n"
            "to treetop."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Archen,
        .frontPicSize = MON_COORDS_SIZE(56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 46),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Archen,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Archen,
        .shinyPalette = gMonShinyPalette_Archen,
        .iconSprite = gMonIcon_Archen,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-3, -2, SHADOW_SIZE_S)
        FOOTPRINT(Archen)
        OVERWORLD(
            sPicTable_Archen,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Archen,
            gShinyOverworldPalette_Archen
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sArchenLevelUpLearnset,
        .teachableLearnset = sArchenTeachableLearnset,
        .eggMoveLearnset = sArchenEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_ARCHEOPS}),
    },

    [SPECIES_ARCHEOPS] =
    {
        .baseHP        = 75,
        .baseAttack    = 140,
        .baseDefense   = 65,
        .baseSpeed     = 110,
        .baseSpAttack  = 112,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING, EGG_GROUP_WATER_3),
        .abilities = { ABILITY_DEFEATIST, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Aeropteryx"),
#else
        .speciesName = _("ARCHEOPS"),
#endif
        .cryId = CRY_ARCHEOPS,
        .natDexNum = NATIONAL_DEX_ARCHEOPS,
#if GERMAN
        .categoryName = _("Urzeitvogel"),
#else
        .categoryName = _("First Bird"),
#endif
        .height = 14,
        .weight = 320,
        .description = COMPOUND_STRING(
#if GERMAN
        "Bevor es abhebt, nimmt es am\n"
        "Boden Anlauf. Es ist schlau genug, seine\n"
        "Beute zusammen mit Artgenossen zu jagen."),
#else
            "They are intelligent and will cooperate\n"
            "to catch prey. When one Archeops\n"
            "had the prey cornered, another would\n"
            "swoop on it."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Archeops,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
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
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 11,
        .backPic = gMonBackPic_Archeops,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Archeops,
        .shinyPalette = gMonShinyPalette_Archeops,
        .iconSprite = gMonIcon_Archeops,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 18, SHADOW_SIZE_M)
        FOOTPRINT(Archeops)
        OVERWORLD(
            sPicTable_Archeops,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Archeops,
            gShinyOverworldPalette_Archeops
        )
        .levelUpLearnset = sArcheopsLevelUpLearnset,
        .teachableLearnset = sArcheopsTeachableLearnset,
    },
#endif //P_FAMILY_ARCHEN

#if P_FAMILY_TRUBBISH
    [SPECIES_TRUBBISH] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 62,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 62,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 190,
        .expYield = 66,
        .evYield_Speed = 1,
        .itemRare = ITEM_SILK_SCARF,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STENCH, ABILITY_STICKY_HOLD, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Unratütox"),
#else
        .speciesName = _("TRUBBISH"),
#endif
        .cryId = CRY_TRUBBISH,
        .natDexNum = NATIONAL_DEX_TRUBBISH,
#if GERMAN
        .categoryName = _("Mülltüte"),
#else
        .categoryName = _("Trash Bag"),
#endif
        .height = 6,
        .weight = 310,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Mülltüte, der Industrieabfälle und\n"
            "chemische Reaktionen neues Leben\n"
            "eingehaucht haben."),
#else
            "It gorges on trash until its stomach\n"
            "is full. Then it belches toxic gas.\n"
            "An unlucky whiff of this gas will put\n"
            "a person in the hospital."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Trubbish,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Trubbish,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Trubbish,
        .shinyPalette = gMonShinyPalette_Trubbish,
        .iconSprite = gMonIcon_Trubbish,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-2, -1, SHADOW_SIZE_S)
        FOOTPRINT(Trubbish)
        OVERWORLD(
            sPicTable_Trubbish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Trubbish,
            gShinyOverworldPalette_Trubbish
        )
        .levelUpLearnset = sTrubbishLevelUpLearnset,
        .teachableLearnset = sTrubbishTeachableLearnset,
        .eggMoveLearnset = sTrubbishEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GARBODOR}),
    },

    [SPECIES_GARBODOR] =
    {
        .baseHP        = 80,
        .baseAttack    = 95,
        .baseDefense   = 82,
        .baseSpeed     = 75,
        .baseSpAttack  = 60,
        .baseSpDefense = 82,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 60,
        .expYield = 166,
        .evYield_Attack = 2,
        .itemCommon = ITEM_SILK_SCARF,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STENCH, ABILITY_WEAK_ARMOR, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Deponitox"),
#else
        .speciesName = _("GARBODOR"),
#endif
        .cryId = CRY_GARBODOR,
        .natDexNum = NATIONAL_DEX_GARBODOR,
#if GERMAN
        .categoryName = _("Müllhalde"),
#else
        .categoryName = _("Trash Heap"),
#endif
        .height = 19,
        .weight = 1073,
        .description = COMPOUND_STRING(
#if GERMAN
        "Deponitox nimmt mit dem rechten Arm\n"
        "Gegner in die Mangel und gibt ihnen mit dem\n"
        "giftigen Gas aus seinem Maul den Rest."),
#else
            "Beware the poisonous liquid it shoots\n"
            "from its right arm. If even a little of it\n"
            "gets on you, you'll experience the full\n"
            "effects of this unidentified toxin."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Garbodor,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Garbodor,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Garbodor,
        .shinyPalette = gMonShinyPalette_Garbodor,
        .iconSprite = gMonIcon_Garbodor,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Garbodor)
        OVERWORLD(
            sPicTable_Garbodor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Garbodor,
            gShinyOverworldPalette_Garbodor
        )
        .levelUpLearnset = sGarbodorLevelUpLearnset,
        .teachableLearnset = sGarbodorTeachableLearnset,
        .formSpeciesIdTable = sGarbodorFormSpeciesIdTable,
        .formChangeTable = sGarbodorFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_GARBODOR_GMAX] =
    {
        .baseHP        = 80,
        .baseAttack    = 95,
        .baseDefense   = 82,
        .baseSpeed     = 75,
        .baseSpAttack  = 60,
        .baseSpDefense = 82,
        .types = MON_TYPES(TYPE_POISON),
        .catchRate = 60,
        .expYield = 166,
        .evYield_Attack = 2,
        .itemCommon = ITEM_SILK_SCARF,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_STENCH, ABILITY_WEAK_ARMOR, ABILITY_AFTERMATH },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Deponitox"),
#else
        .speciesName = _("GARBODOR"),
#endif
        .cryId = CRY_GARBODOR,
        .natDexNum = NATIONAL_DEX_GARBODOR,
#if GERMAN
        .categoryName = _("Müllhalde"),
#else
        .categoryName = _("Trash Heap"),
#endif
        .height = 210,
        .weight = 0,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Gigadynamax-Energie hat sich\n"
        "sein giftiges Gas weiter verdichtet und\n"
        "die Form von entsorgtem Spielzeug\n"
        "angenommen."),
#else
            "It sprays toxic gas from its mouth\n"
            "and fingers. If the gas engulfs you,\n"
            "the toxins will seep in all the way\n"
            "down to your bones."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_GarbodorGmax,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GarbodorGmax,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GarbodorGmax,
        .shinyPalette = gMonShinyPalette_GarbodorGmax,
        .iconSprite = gMonIcon_GarbodorGmax,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        NO_SHADOW
        FOOTPRINT(Garbodor)
        .isGigantamax = TRUE,
        .levelUpLearnset = sGarbodorLevelUpLearnset,
        .teachableLearnset = sGarbodorTeachableLearnset,
        .formSpeciesIdTable = sGarbodorFormSpeciesIdTable,
        .formChangeTable = sGarbodorFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_TRUBBISH

#if P_FAMILY_ZORUA
    [SPECIES_ZORUA] =
    {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 75,
        .expYield = 66,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Zorua"),
#else
        .speciesName = _("ZORUA"),
#endif
        .cryId = CRY_ZORUA,
        .natDexNum = NATIONAL_DEX_ZORUA,
#if GERMAN
        .categoryName = _("Lausefuchs"),
#else
        .categoryName = _("Tricky Fox"),
#endif
        .height = 7,
        .weight = 125,
        .description = COMPOUND_STRING(
#if GERMAN
        "Nicht selten überrumpelt es Gegner,\n"
        "indem es ihre Gestalt annimmt und den\n"
        "Überraschungseffekt zur Flucht nutzt."),
#else
            "To protect themselves from danger, they\n"
            "hide their true identities by transforming\n"
            "into people and Pokémon. Apparently, it\n"
            "often transforms into a silent child."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Zorua,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .backPic = gMonBackPic_Zorua,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Zorua,
        .shinyPalette = gMonShinyPalette_Zorua,
        .iconSprite = gMonIcon_Zorua,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, 2, SHADOW_SIZE_S)
        FOOTPRINT(Zorua)
        OVERWORLD(
            sPicTable_Zorua,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zorua,
            gShinyOverworldPalette_Zorua
        )
        .levelUpLearnset = sZoruaLevelUpLearnset,
        .teachableLearnset = sZoruaTeachableLearnset,
        .eggMoveLearnset = sZoruaEggMoveLearnset,
        .formSpeciesIdTable = sZoruaFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ZOROARK}),
    },

    [SPECIES_ZOROARK] =
    {
        .baseHP        = 60,
        .baseAttack    = 105,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 120,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_DARK),
        .catchRate = 45,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Zoroark"),
#else
        .speciesName = _("ZOROARK"),
#endif
        .cryId = CRY_ZOROARK,
        .natDexNum = NATIONAL_DEX_ZOROARK,
#if GERMAN
        .categoryName = _("Polymorfuchs"),
#else
        .categoryName = _("Illusion Fox"),
#endif
        .height = 16,
        .weight = 811,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kann auf einen Schlag große\n"
        "Massen von Menschen täuschen. Es kreiert\n"
        "Illusionen, um sein Revier zu schützen."),
#else
            "Bonds between these Pokémon are very\n"
            "strong. It protects the safety of its\n"
            "pack by tricking its opponents. They\n"
            "defend their lair with illusory scenery."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Zoroark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_FLICKER_INCREASING,
        .backPic = gMonBackPic_Zoroark,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Zoroark,
        .shinyPalette = gMonShinyPalette_Zoroark,
        .iconSprite = gMonIcon_Zoroark,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 8, SHADOW_SIZE_L)
        FOOTPRINT(Zoroark)
        OVERWORLD(
            sPicTable_Zoroark,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zoroark,
            gShinyOverworldPalette_Zoroark
        )
        .levelUpLearnset = sZoroarkLevelUpLearnset,
        .teachableLearnset = sZoroarkTeachableLearnset,
        .formSpeciesIdTable = sZoroarkFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_ZORUA_HISUI] =
    {
        .baseHP        = 35,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 85,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GHOST),
        .catchRate = 75,
        .expYield = 66,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Zorua-H"),
#else
        .speciesName = _("ZORUA-H"),
#endif
#else
#if GERMAN
        .speciesName = _("Zorua"),
#else
        .speciesName = _("ZORUA"),
#endif
#endif
        .cryId = CRY_ZORUA,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_ZORUA_HISUI,
#else
        .natDexNum = NATIONAL_DEX_ZORUA,
#endif
#if GERMAN
        .categoryName = _("Grollfuchs"),
#else
        .categoryName = _("Spiteful Fox"),
#endif
        .height = 7,
        .weight = 125,
        .description = COMPOUND_STRING(
#if GERMAN
        "Eine verstorbene Seele, die\n"
        "zu neuem Leben erwachte. Groll verleiht\n"
        "ihm Kraft und quillt aus seinem Kopf,\n"
        "um die Gestalt seiner Feinde anzunehmen."),
#else
            "Derives power from resentment,\n"
            "which rises as energy atop its head and\n"
            "takes on the forms of foes. In this\n"
            "way, Zorua vents lingering malice."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ZoruaHisui,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZoruaHisui,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZoruaHisui,
        .shinyPalette = gMonShinyPalette_ZoruaHisui,
        .iconSprite = gMonIcon_ZoruaHisui,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 12, SHADOW_SIZE_S)
        FOOTPRINT(Zorua)
        OVERWORLD(
            sPicTable_ZoruaHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZoruaHisui,
            gShinyOverworldPalette_ZoruaHisui
        )
        .isHisuianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sZoruaHisuiLevelUpLearnset,
        .teachableLearnset = sZoruaHisuiTeachableLearnset,
        .eggMoveLearnset = sZoruaHisuiEggMoveLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sZoruaHisuiFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sZoruaFormSpeciesIdTable,
#endif
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ZOROARK_HISUI}),
    },

    [SPECIES_ZOROARK_HISUI] =
    {
        .baseHP        = 55,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GHOST),
        .catchRate = 45,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_ILLUSION, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Zoroark-H"),
#else
        .speciesName = _("ZOROARK-H"),
#endif
#else
#if GERMAN
        .speciesName = _("Zoroark"),
#else
        .speciesName = _("ZOROARK"),
#endif
#endif
        .cryId = CRY_ZOROARK,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_ZOROARK_HISUI,
#else
        .natDexNum = NATIONAL_DEX_ZOROARK,
#endif
#if GERMAN
        .categoryName = _("Fluchfuchs"),
#else
        .categoryName = _("Baneful Fox"),
#endif
        .height = 16,
        .weight = 730,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die zerzauste weiße\n"
        "Mähne gleicht es Gevatter Tod. Getrieben\n"
        "von bitterem Groll streckt es Feinde ohne\n"
        "Rücksicht auf das eigene Leben nieder."),
#else
            "Heedless of its own safety,\n"
            "Zoroark attacks its nemeses with a bitter\n"
            "energy so intense, it lacerates\n"
            "Zoroark's own body."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_ZoroarkHisui,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_ZoroarkHisui,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ZoroarkHisui,
        .shinyPalette = gMonShinyPalette_ZoroarkHisui,
        .iconSprite = gMonIcon_ZoroarkHisui,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(11, 13, SHADOW_SIZE_L)
        FOOTPRINT(Zoroark)
        OVERWORLD(
            sPicTable_ZoroarkHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZoroarkHisui,
            gShinyOverworldPalette_ZoroarkHisui
        )
        .isHisuianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sZoroarkHisuiLevelUpLearnset,
        .teachableLearnset = sZoroarkHisuiTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sZoroarkHisuiFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sZoroarkFormSpeciesIdTable,
#endif
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_ZORUA

#if P_FAMILY_MINCCINO
    [SPECIES_MINCCINO] =
    {
        .baseHP        = 55,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .expYield = 60,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Picochilla"),
#else
        .speciesName = _("MINCCINO"),
#endif
        .cryId = CRY_MINCCINO,
        .natDexNum = NATIONAL_DEX_MINCCINO,
        .categoryName = _("Chinchilla"),
        .height = 4,
        .weight = 58,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sie begrüßen einander, indem sie ihr\n"
        "Gegenüber mithilfe ihres Schweifs säubern."),
#else
            "These Pokémon prefer a tidy habitat.\n"
            "They greet one another by rubbing each\n"
            "other with their tails, which are always\n"
            "kept well groomed and clean."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Minccino,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Minccino,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Minccino,
        .shinyPalette = gMonShinyPalette_Minccino,
        .iconSprite = gMonIcon_Minccino,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-3, 3, SHADOW_SIZE_S)
        FOOTPRINT(Minccino)
        OVERWORLD(
            sPicTable_Minccino,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Minccino,
            gShinyOverworldPalette_Minccino
        )
        .levelUpLearnset = sMinccinoLevelUpLearnset,
        .teachableLearnset = sMinccinoTeachableLearnset,
        .eggMoveLearnset = sMinccinoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_CINCCINO}),
    },

    [SPECIES_CINCCINO] =
    {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 60,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_TECHNICIAN, ABILITY_SKILL_LINK },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Chillabell"),
#else
        .speciesName = _("CINCCINO"),
#endif
        .cryId = CRY_CINCCINO,
        .natDexNum = NATIONAL_DEX_CINCCINO,
#if GERMAN
        .categoryName = _("Schal"),
#else
        .categoryName = _("Scarf"),
#endif
        .height = 5,
        .weight = 75,
        .description = COMPOUND_STRING(
#if GERMAN
        "Chillabells weißer Flaum fühlt sich\n"
        "wunderbar flauschig an und zieht weder\n"
        "Staub noch statische Elektrizität an."),
#else
            "Their white fur feels amazing to touch.\n"
            "Cinccino's body is coated in a special\n"
            "oil that repels dust and helps it deflect\n"
            "attacks, such as punches."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cinccino,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SLIDE,
        .backPic = gMonBackPic_Cinccino,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Cinccino,
        .shinyPalette = gMonShinyPalette_Cinccino,
        .iconSprite = gMonIcon_Cinccino,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(0, 6, SHADOW_SIZE_M)
        FOOTPRINT(Cinccino)
        OVERWORLD(
            sPicTable_Cinccino,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cinccino,
            gShinyOverworldPalette_Cinccino
        )
        .levelUpLearnset = sCinccinoLevelUpLearnset,
        .teachableLearnset = sCinccinoTeachableLearnset,
    },
#endif //P_FAMILY_MINCCINO

#if P_FAMILY_GOTHITA
    [SPECIES_GOTHITA] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 200,
        .expYield = 58,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
    #else
        .abilities = { ABILITY_FRISK, ABILITY_NONE, ABILITY_SHADOW_TAG },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Mollimorba"),
#else
        .speciesName = _("GOTHITA"),
#endif
        .cryId = CRY_GOTHITA,
        .natDexNum = NATIONAL_DEX_GOTHITA,
#if GERMAN
        .categoryName = _("Glotz"),
#else
        .categoryName = _("Fixation"),
#endif
        .height = 4,
        .weight = 58,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die schleifenförmigen Fühler erhöhen\n"
        "seine Psycho-Kräfte. Es scheint stets\n"
        "irgendetwas anzustarren."),
#else
            "They intently observe both Trainers and\n"
            "Pokémon. Apparently, Gothita are looking\n"
            "at something that only they can see. Their\n"
            "ribbonlike feelers increase their power."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gothita,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .backPic = gMonBackPic_Gothita,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Gothita,
        .shinyPalette = gMonShinyPalette_Gothita,
        .iconSprite = gMonIcon_Gothita,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-3, 2, SHADOW_SIZE_S)
        FOOTPRINT(Gothita)
        OVERWORLD(
            sPicTable_Gothita,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gothita,
            gShinyOverworldPalette_Gothita
        )
        .levelUpLearnset = sGothitaLevelUpLearnset,
        .teachableLearnset = sGothitaTeachableLearnset,
        .eggMoveLearnset = sGothitaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_GOTHORITA}),
    },

    [SPECIES_GOTHORITA] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 70,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 100,
        .expYield = 137,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
    #else
        .abilities = { ABILITY_FRISK, ABILITY_NONE, ABILITY_SHADOW_TAG },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Hypnomorba"),
#else
        .speciesName = _("GOTHORITA"),
#endif
        .cryId = CRY_GOTHORITA,
        .natDexNum = NATIONAL_DEX_GOTHORITA,
#if GERMAN
        .categoryName = _("Manipulator"),
#else
        .categoryName = _("Manipulate"),
#endif
        .height = 7,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zieht seine Energie aus dem Sternenlicht.\n"
        "Bei Nacht bringt es Steine zum Schweben\n"
        "und bildet damit Sternzeichen nach."),
#else
            "Starlight is the source of their power.\n"
            "They use hypnosis to control people and\n"
            "Pokémon. Tales of Gothorita leading them\n"
            "astray are told in every corner."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gothorita,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Gothorita,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Gothorita,
        .shinyPalette = gMonShinyPalette_Gothorita,
        .iconSprite = gMonIcon_Gothorita,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-2, 7, SHADOW_SIZE_S)
        FOOTPRINT(Gothorita)
        OVERWORLD(
            sPicTable_Gothorita,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gothorita,
            gShinyOverworldPalette_Gothorita
        )
        .levelUpLearnset = sGothoritaLevelUpLearnset,
        .teachableLearnset = sGothoritaTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_GOTHITELLE}),
    },

    [SPECIES_GOTHITELLE] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 95,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 50,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 245 : 221,
        .evYield_SpDefense = 3,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_FRISK, ABILITY_COMPETITIVE, ABILITY_SHADOW_TAG },
    #else
        .abilities = { ABILITY_FRISK, ABILITY_NONE, ABILITY_SHADOW_TAG },
    #endif
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Morbitesse"),
#else
        .speciesName = _("GOTHITELLE"),
#endif
        .cryId = CRY_GOTHITELLE,
        .natDexNum = NATIONAL_DEX_GOTHITELLE,
#if GERMAN
        .categoryName = _("Gestirn"),
#else
        .categoryName = _("Astral Body"),
#endif
        .height = 15,
        .weight = 440,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch seine mächtigen Psycho-Kräfte\n"
        "krümmt sich der Raum und Bilder eines\n"
        "Lichtjahre entfernten Ortes erscheinen."),
#else
            "Starry skies thousands of light-years\n"
            "away are visible in the space distorted by\n"
            "their intense psychic power. When it learns\n"
            "its Trainer's life span, it cries in sadness."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Gothitelle,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Gothitelle,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Gothitelle,
        .shinyPalette = gMonShinyPalette_Gothitelle,
        .iconSprite = gMonIcon_Gothitelle,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_M)
        FOOTPRINT(Gothitelle)
        OVERWORLD(
            sPicTable_Gothitelle,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Gothitelle,
            gShinyOverworldPalette_Gothitelle
        )
        .levelUpLearnset = sGothitelleLevelUpLearnset,
        .teachableLearnset = sGothitelleTeachableLearnset,
    },
#endif //P_FAMILY_GOTHITA

#if P_FAMILY_SOLOSIS
    [SPECIES_SOLOSIS] =
    {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 105,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 200,
        .expYield = 58,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Monozyto"),
#else
        .speciesName = _("SOLOSIS"),
#endif
        .cryId = CRY_SOLOSIS,
        .natDexNum = NATIONAL_DEX_SOLOSIS,
#if GERMAN
        .categoryName = _("Zelle"),
#else
        .categoryName = _("Cell"),
#endif
        .height = 3,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die spezielle Flüssigkeit, die es umgibt,\n"
            "bietet ihm in jeder noch so gefährlichen\n"
            "Situation Schutz."),
#else
            "Because their bodies are enveloped\n"
            "in a special liquid, they are fine in any\n"
            "environment, no matter how severe. They\n"
            "can use telepathy to talk with others."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Solosis,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_TWIST,
        .enemyMonElevation = 14,
        .backPic = gMonBackPic_Solosis,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Solosis,
        .shinyPalette = gMonShinyPalette_Solosis,
        .iconSprite = gMonIcon_Solosis,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_S)
        FOOTPRINT(Solosis)
        OVERWORLD(
            sPicTable_Solosis,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Solosis,
            gShinyOverworldPalette_Solosis
        )
        .levelUpLearnset = sSolosisLevelUpLearnset,
        .teachableLearnset = sSolosisTeachableLearnset,
        .eggMoveLearnset = sSolosisEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_DUOSION}),
    },

    [SPECIES_DUOSION] =
    {
        .baseHP        = 65,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 125,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 100,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Mitodos"),
#else
        .speciesName = _("DUOSION"),
#endif
        .cryId = CRY_DUOSION,
        .natDexNum = NATIONAL_DEX_DUOSION,
#if GERMAN
        .categoryName = _("Zellteilung"),
#else
        .categoryName = _("Mitosis"),
#endif
        .height = 6,
        .weight = 80,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wegen seines gespaltenen Denkapparates\n"
        "kann es vorkommen, dass es sich\n"
        "abrupt einer anderen Tätigkeit zuwendet."),
#else
            "When their brains, now divided in two,\n"
            "are thinking the same thoughts,\n"
            "these Pokémon exhibit their maximized\n"
            "psychic power."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Duosion,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Duosion,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_GROW,
        .palette = gMonPalette_Duosion,
        .shinyPalette = gMonShinyPalette_Duosion,
        .iconSprite = gMonIcon_Duosion,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 6, SHADOW_SIZE_M)
        FOOTPRINT(Duosion)
        OVERWORLD(
            sPicTable_Duosion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Duosion,
            gShinyOverworldPalette_Duosion
        )
        .levelUpLearnset = sDuosionLevelUpLearnset,
        .teachableLearnset = sDuosionTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_REUNICLUS}),
    },

    [SPECIES_REUNICLUS] =
    {
        .baseHP        = 110,
        .baseAttack    = 65,
        .baseDefense   = 75,
        .baseSpeed     = 30,
        .baseSpAttack  = 125,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 50,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 245 : 221,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_OVERCOAT, ABILITY_MAGIC_GUARD, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Zytomega"),
#else
        .speciesName = _("REUNICLUS"),
#endif
        .cryId = CRY_REUNICLUS,
        .natDexNum = NATIONAL_DEX_REUNICLUS,
#if GERMAN
        .categoryName = _("Vermehrung"),
#else
        .categoryName = _("Multiplying"),
#endif
        .height = 10,
        .weight = 201,
        .description = COMPOUND_STRING(
#if GERMAN
        "Zytomegas Arme bestehen aus einer\n"
        "speziellen Flüssigkeit. Dank seiner\n"
        "Psycho-Kräfte kann es mit ihnen Felsen\n"
        "zerschmettern."),
#else
            "They use psychic power to control their\n"
            "arms, which are made of a special liquid.\n"
            "When Reuniclus shake hands, a network\n"
            "forms between their brains."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Reuniclus,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Reuniclus,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_Reuniclus,
        .shinyPalette = gMonShinyPalette_Reuniclus,
        .iconSprite = gMonIcon_Reuniclus,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_M)
        FOOTPRINT(Reuniclus)
        OVERWORLD(
            sPicTable_Reuniclus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Reuniclus,
            gShinyOverworldPalette_Reuniclus
        )
        .levelUpLearnset = sReuniclusLevelUpLearnset,
        .teachableLearnset = sReuniclusTeachableLearnset,
    },
#endif //P_FAMILY_SOLOSIS

#if P_FAMILY_DUCKLETT
    [SPECIES_DUCKLETT] =
    {
        .baseHP        = 62,
        .baseAttack    = 44,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 44,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 61,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_BIG_PECKS, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Piccolente"),
#else
        .speciesName = _("DUCKLETT"),
#endif
        .cryId = CRY_DUCKLETT,
        .natDexNum = NATIONAL_DEX_DUCKLETT,
#if GERMAN
        .categoryName = _("Wasservogel"),
#else
        .categoryName = _("Water Bird"),
#endif
        .height = 5,
        .weight = 55,
        .description = COMPOUND_STRING(
#if GERMAN
        "Gerät es in Gefahr, versprüht es\n"
        "Wasser aus seinem Federkleid und nutzt\n"
        "den Sprühregen, um Reißaus zu nehmen."),
#else
            "These bird Pokémon are excellent divers.\n"
            "They are better at swimming than flying,\n"
            "and they happily eat their favorite food,\n"
            "peat moss, as they dive underwater."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ducklett,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 12,
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
        .backPic = gMonBackPic_Ducklett,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Ducklett,
        .shinyPalette = gMonShinyPalette_Ducklett,
        .iconSprite = gMonIcon_Ducklett,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Ducklett)
        OVERWORLD(
            sPicTable_Ducklett,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ducklett,
            gShinyOverworldPalette_Ducklett
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sDucklettLevelUpLearnset,
        .teachableLearnset = sDucklettTeachableLearnset,
        .eggMoveLearnset = sDucklettEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_SWANNA}),
    },

    [SPECIES_SWANNA] =
    {
        .baseHP        = 75,
        .baseAttack    = 87,
        .baseDefense   = 63,
        .baseSpeed     = 98,
        .baseSpAttack  = 87,
        .baseSpDefense = 63,
        .types = MON_TYPES(TYPE_WATER, TYPE_FLYING),
        .catchRate = 45,
        .expYield = 166,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_BIG_PECKS, ABILITY_HYDRATION },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Swaroness"),
#else
        .speciesName = _("SWANNA"),
#endif
        .cryId = CRY_SWANNA,
        .natDexNum = NATIONAL_DEX_SWANNA,
#if GERMAN
        .categoryName = _("Schwan"),
#else
        .categoryName = _("White Bird"),
#endif
        .height = 13,
        .weight = 242,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sie wirken zerbrechlich,\n"
        "aber ihre starken Schwingen tragen\n"
        "sie in einem Stück bis zu 1 000 km weit."),
#else
            "Despite their elegant appearance, they\n"
            "can flap their wings strongly and fly for\n"
            "thousands of miles. The one in the middle\n"
            "is the leader of the flock."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Swanna,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Swanna,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Swanna,
        .shinyPalette = gMonShinyPalette_Swanna,
        .iconSprite = gMonIcon_Swanna,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_M)
        FOOTPRINT(Swanna)
        OVERWORLD(
            sPicTable_Swanna,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Swanna,
            gShinyOverworldPalette_Swanna
        )
        .levelUpLearnset = sSwannaLevelUpLearnset,
        .teachableLearnset = sSwannaTeachableLearnset,
    },
#endif //P_FAMILY_DUCKLETT

#if P_FAMILY_VANILLITE
    [SPECIES_VANILLITE] =
    {
        .baseHP        = 36,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 44,
        .baseSpAttack  = 65,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 255,
        .expYield = 61,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK, ABILITY_WEAK_ARMOR },
    #else
        .abilities = { ABILITY_ICE_BODY, ABILITY_NONE, ABILITY_WEAK_ARMOR },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Gelatini"),
#else
        .speciesName = _("VANILLITE"),
#endif
        .cryId = CRY_VANILLITE,
        .natDexNum = NATIONAL_DEX_VANILLITE,
#if GERMAN
        .categoryName = _("Neuschnee"),
#else
        .categoryName = _("Fresh Snow"),
#endif
        .height = 4,
        .weight = 57,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Temperatur seines Odems liegt\n"
        "bei -50 Grad. Es erzeugt Eiskristalle\n"
        "und lässt es in seiner Umgebung schneien."),
#else
            "The temperature of their breath is -58ºF.\n"
            "They create snow crystals and make snow\n"
            "fall in the areas around them. Vanillite is\n"
            "treasured by households in warm regions."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vanillite,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Vanillite,
        .backPicSize = MON_COORDS_SIZE(40, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Vanillite,
        .shinyPalette = gMonShinyPalette_Vanillite,
        .iconSprite = gMonIcon_Vanillite,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Vanillite)
        OVERWORLD(
            sPicTable_Vanillite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vanillite,
            gShinyOverworldPalette_Vanillite
        )
        .levelUpLearnset = sVanilliteLevelUpLearnset,
        .teachableLearnset = sVanilliteTeachableLearnset,
        .eggMoveLearnset = sVanilliteEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_VANILLISH}),
    },

    [SPECIES_VANILLISH] =
    {
        .baseHP        = 51,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 59,
        .baseSpAttack  = 80,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 120,
        .expYield = 138,
        .evYield_SpAttack = 2,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_CLOAK, ABILITY_WEAK_ARMOR },
    #else
        .abilities = { ABILITY_ICE_BODY, ABILITY_NONE, ABILITY_WEAK_ARMOR },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Gelatroppo"),
#else
        .speciesName = _("VANILLISH"),
#endif
        .cryId = CRY_VANILLISH,
        .natDexNum = NATIONAL_DEX_VANILLISH,
#if GERMAN
        .categoryName = _("Firn"),
#else
        .categoryName = _("Icy Snow"),
#endif
        .height = 11,
        .weight = 410,
        .description = COMPOUND_STRING(
#if GERMAN
        "Gelatroppo produziert Eiskörner, indem es\n"
        "die Luft um sich herum abkühlt, und zieht\n"
        "mit ihnen eine Eisschicht um seinen Gegner."),
#else
            "Vanillish has existed since the Ice Age.\n"
            "It controls particles of ice, freezes its\n"
            "opponents, and then shatters them with\n"
            "a headbutt."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vanillish,
        .frontPicSize = MON_COORDS_SIZE(32, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Vanillish,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Vanillish,
        .shinyPalette = gMonShinyPalette_Vanillish,
        .iconSprite = gMonIcon_Vanillish,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 9, SHADOW_SIZE_S)
        FOOTPRINT(Vanillish)
        OVERWORLD(
            sPicTable_Vanillish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vanillish,
            gShinyOverworldPalette_Vanillish
        )
        .levelUpLearnset = sVanillishLevelUpLearnset,
        .teachableLearnset = sVanillishTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 47, SPECIES_VANILLUXE}),
    },

    [SPECIES_VANILLUXE] =
    {
        .baseHP        = 71,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 79,
        .baseSpAttack  = 110,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 268 : 241,
        .evYield_SpAttack = 3,
        .itemCommon = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_ICE_BODY, ABILITY_SNOW_WARNING, ABILITY_WEAK_ARMOR },
    #else
        .abilities = { ABILITY_ICE_BODY, ABILITY_NONE, ABILITY_WEAK_ARMOR },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Gelatwino"),
#else
        .speciesName = _("VANILLUXE"),
#endif
        .cryId = CRY_VANILLUXE,
        .natDexNum = NATIONAL_DEX_VANILLUXE,
#if GERMAN
        .categoryName = _("Schneesturm"),
#else
        .categoryName = _("Snowstorm"),
#endif
        .height = 13,
        .weight = 575,
        .description = COMPOUND_STRING(
#if GERMAN
        "Bringt man beide Köpfe in Rage, stößt\n"
        "sein Horn heftige Eisböen aus, und alles\n"
        "in seiner Umgebung versinkt in Schnee."),
#else
            "Each of its two heads has a brain, and\n"
            "when they are in agreement, it attacks\n"
            "its enemies by exhaling a violent blizzard.\n"
            "It makes snow clouds inside its body."),
#endif
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vanilluxe,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Vanilluxe,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Vanilluxe,
        .shinyPalette = gMonShinyPalette_Vanilluxe,
        .iconSprite = gMonIcon_Vanilluxe,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 10, SHADOW_SIZE_M)
        FOOTPRINT(Vanilluxe)
        OVERWORLD(
            sPicTable_Vanilluxe,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Vanilluxe,
            gShinyOverworldPalette_Vanilluxe
        )
        .levelUpLearnset = sVanilluxeLevelUpLearnset,
        .teachableLearnset = sVanilluxeTeachableLearnset,
    },
#endif //P_FAMILY_VANILLITE

#if P_FAMILY_DEERLING
    [SPECIES_DEERLING_SPRING] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 67,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Sesokitz"),
#else
        .speciesName = _("DEERLING"),
#endif
        .cryId = CRY_DEERLING,
        .natDexNum = NATIONAL_DEX_DEERLING,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 6,
        .weight = 195,
        .description = COMPOUND_STRING(
#if GERMAN
        "Unabhängig von der Jahreszeit ändert\n"
        "sich seine Farbe auch bei wechselnder\n"
        "Temperatur oder Luftfeuchtigkeit leicht."),
#else
            "Deerling have different scents\n"
            "depending on the season. In early\n"
            "spring, these Pokémon give off a\n"
            "delicate, sweet, and calming scent."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Deerling,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Deerling,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Deerling,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_DeerlingSpring,
        .shinyPalette = gMonShinyPalette_DeerlingSpring,
        .iconSprite = gMonIcon_DeerlingSpring,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Deerling)
        OVERWORLD(
            sPicTable_DeerlingSpring,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DeerlingSpring,
            gShinyOverworldPalette_DeerlingSpring
        )
        .levelUpLearnset = sDeerlingLevelUpLearnset,
        .teachableLearnset = sDeerlingTeachableLearnset,
        .eggMoveLearnset = sDeerlingEggMoveLearnset,
        .formSpeciesIdTable = sDeerlingFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_SPRING}),
        .randomizerMode = MON_RANDOMIZER_RANDOM_FORM,
    },

    [SPECIES_DEERLING_SUMMER] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 67,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Sesokitz"),
#else
        .speciesName = _("DEERLING"),
#endif
        .cryId = CRY_DEERLING,
        .natDexNum = NATIONAL_DEX_DEERLING,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 6,
        .weight = 195,
        .description = COMPOUND_STRING(
#if GERMAN
        "Um es von ihren Feldern fernzuhalten,\n"
        "setzen viele Landwirte seinen natürlichen\n"
        "Fressfeind Wolwerock als Wächter ein."),
#else
            "To prevent Deerling from entering\n"
            "their fields, many farmers will have\n"
            "several Lycanroc stand guard, as\n"
            "they are its natural enemy."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Deerling,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Deerling,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Deerling,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_DeerlingSummer,
        .shinyPalette = gMonShinyPalette_DeerlingSummer,
        .iconSprite = gMonIcon_DeerlingSummer,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Deerling)
        OVERWORLD(
            sPicTable_DeerlingSummer,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DeerlingSummer,
            gShinyOverworldPalette_DeerlingSummer
        )
        .levelUpLearnset = sDeerlingLevelUpLearnset,
        .teachableLearnset = sDeerlingTeachableLearnset,
        .eggMoveLearnset = sDeerlingEggMoveLearnset,
        .formSpeciesIdTable = sDeerlingFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_SUMMER}),
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_DEERLING_AUTUMN] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 67,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Sesokitz"),
#else
        .speciesName = _("DEERLING"),
#endif
        .cryId = CRY_DEERLING,
        .natDexNum = NATIONAL_DEX_DEERLING,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 6,
        .weight = 195,
        .description = COMPOUND_STRING(
#if GERMAN
        "Da es nicht schüchtern\n"
        "ist, fühlt es sich auch in Gegenwart\n"
        "von Menschen wohl. Wenn man es füttert,\n"
        "freundet es sich sofort mit einem an."),
#else
            "Deerling have different scents\n"
            "depending on the season. In this form,\n"
            "Deerling have a softly sweet scent\n"
            "that lingers in the nose."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Deerling,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Deerling,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Deerling,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_DeerlingAutumn,
        .shinyPalette = gMonShinyPalette_DeerlingAutumn,
        .iconSprite = gMonIcon_DeerlingAutumn,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Deerling)
        OVERWORLD(
            sPicTable_DeerlingAutumn,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DeerlingAutumn,
            gShinyOverworldPalette_DeerlingAutumn
        )
        .levelUpLearnset = sDeerlingLevelUpLearnset,
        .teachableLearnset = sDeerlingTeachableLearnset,
        .eggMoveLearnset = sDeerlingEggMoveLearnset,
        .formSpeciesIdTable = sDeerlingFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_AUTUMN}),
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_DEERLING_WINTER] =
    {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 190,
        .expYield = 67,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Sesokitz"),
#else
        .speciesName = _("DEERLING"),
#endif
        .cryId = CRY_DEERLING,
        .natDexNum = NATIONAL_DEX_DEERLING,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 6,
        .weight = 195,
        .description = COMPOUND_STRING(
#if GERMAN
        "Sein Geruch ändert sich mit der\n"
        "Jahreszeit, verschwindet aber fast\n"
        "vollständig, sobald es seine Winterform\n"
        "annimmt."),
#else
            "Deerling's scent changes with the\n"
            "seasons, but when the Pokémon is in\n"
            "its Winter Form, it has hardly any\n"
            "scent at all."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Deerling,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Deerling,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Deerling,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_DeerlingWinter,
        .shinyPalette = gMonShinyPalette_DeerlingWinter,
        .iconSprite = gMonIcon_DeerlingWinter,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Deerling)
        OVERWORLD(
            sPicTable_DeerlingWinter,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_DeerlingWinter,
            gShinyOverworldPalette_DeerlingWinter
        )
        .levelUpLearnset = sDeerlingLevelUpLearnset,
        .teachableLearnset = sDeerlingTeachableLearnset,
        .eggMoveLearnset = sDeerlingEggMoveLearnset,
        .formSpeciesIdTable = sDeerlingFormSpeciesIdTable,
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SAWSBUCK_WINTER}),
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_SAWSBUCK_SPRING] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 75,
        .expYield = 166,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Kronjuwild"),
#else
        .speciesName = _("SAWSBUCK"),
#endif
        .cryId = CRY_SAWSBUCK,
        .natDexNum = NATIONAL_DEX_SAWSBUCK,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 19,
        .weight = 925,
        .description = COMPOUND_STRING(
#if GERMAN
        "An seinem Geweih kann man ablesen, wann\n"
        "eine neue Jahreszeit beginnt. Sein Revier\n"
        "wechselt mit jeder neuen Jahreszeit."),
#else
            "Some people call Sawsbuck the harbingers\n"
            "of spring because the plants growing on\n"
            "its horns change according to the season.\n"
            "The leader possesses magnificent horns."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_SawsbuckSpring,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Sawsbuck,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SawsbuckSpring,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_SawsbuckSpring,
        .shinyPalette = gMonShinyPalette_SawsbuckSpring,
        .iconSprite = gMonIcon_SawsbuckSpring,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 13, SHADOW_SIZE_M)
        FOOTPRINT(Sawsbuck)
        OVERWORLD(
            sPicTable_SawsbuckSpring,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SawsbuckSpring,
            gShinyOverworldPalette_SawsbuckSpring
        )
        .levelUpLearnset = sSawsbuckLevelUpLearnset,
        .teachableLearnset = sSawsbuckTeachableLearnset,
        .formSpeciesIdTable = sSawsbuckFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_RANDOM_FORM,
    },

    [SPECIES_SAWSBUCK_SUMMER] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 75,
        .expYield = 166,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Kronjuwild"),
#else
        .speciesName = _("SAWSBUCK"),
#endif
        .cryId = CRY_SAWSBUCK,
        .natDexNum = NATIONAL_DEX_SAWSBUCK,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 19,
        .weight = 925,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon hat viele\n"
        "Bewunderer. Es wird als umso prächtiger\n"
        "empfunden, je dichter und größer\n"
        "die Äste und Blätter seines Geweihs sind."),
#else
            "The thicker and larger the\n"
            "branches and leaves on its antlers, the\n"
            "more majestic the Sawsbuck is thought\n"
            "to be."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_SawsbuckSummer,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Sawsbuck,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SawsbuckSummer,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_SawsbuckSummer,
        .shinyPalette = gMonShinyPalette_SawsbuckSummer,
        .iconSprite = gMonIcon_SawsbuckSummer,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 13, SHADOW_SIZE_M)
        FOOTPRINT(Sawsbuck)
        OVERWORLD(
            sPicTable_SawsbuckSummer,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SawsbuckSummer,
            gShinyOverworldPalette_SawsbuckSummer
        )
        .levelUpLearnset = sSawsbuckLevelUpLearnset,
        .teachableLearnset = sSawsbuckTeachableLearnset,
        .formSpeciesIdTable = sSawsbuckFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_SAWSBUCK_AUTUMN] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 75,
        .expYield = 166,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Kronjuwild"),
#else
        .speciesName = _("SAWSBUCK"),
#endif
        .cryId = CRY_SAWSBUCK,
        .natDexNum = NATIONAL_DEX_SAWSBUCK,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 19,
        .weight = 925,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dieses Pokémon hat viele\n"
        "Bewunderer. Es wird als umso schicker\n"
        "empfunden, je tiefer das Rot der Blätter\n"
        "ist, die von seinem Geweih herabhängen."),
#else
            "Sawsbuck in their Autumn Form are\n"
            "known for having very short\n"
            "tempers. The males fight each other\n"
            "incessantly."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_SawsbuckAutumn,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Sawsbuck,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SawsbuckAutumn,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_SawsbuckAutumn,
        .shinyPalette = gMonShinyPalette_SawsbuckAutumn,
        .iconSprite = gMonIcon_SawsbuckAutumn,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 13, SHADOW_SIZE_M)
        FOOTPRINT(Sawsbuck)
        OVERWORLD(
            sPicTable_SawsbuckAutumn,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SawsbuckAutumn,
            gShinyOverworldPalette_SawsbuckAutumn
        )
        .levelUpLearnset = sSawsbuckLevelUpLearnset,
        .teachableLearnset = sSawsbuckTeachableLearnset,
        .formSpeciesIdTable = sSawsbuckFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_SAWSBUCK_WINTER] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_GRASS),
        .catchRate = 75,
        .expYield = 166,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_SAP_SIPPER, ABILITY_SERENE_GRACE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Kronjuwild"),
#else
        .speciesName = _("SAWSBUCK"),
#endif
        .cryId = CRY_SAWSBUCK,
        .natDexNum = NATIONAL_DEX_SAWSBUCK,
#if GERMAN
        .categoryName = _("Jahreszeit"),
#else
        .categoryName = _("Season"),
#endif
        .height = 19,
        .weight = 925,
        .description = COMPOUND_STRING(
#if GERMAN
        "In dieser Form gilt es als besonders sanft\n"
        "und leicht zu zähmen. Diese Jahreszeit\n"
        "eignet sich bestens, um es als Partner zu\n"
        "gewinnen."),
#else
            "Though there are many enthusiasts\n"
            "for Sawsbuck as a species, this\n"
            "seasonal form in particular is not\n"
            "very popular."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_SawsbuckWinter,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Sawsbuck,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_SawsbuckWinter,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_SawsbuckWinter,
        .shinyPalette = gMonShinyPalette_SawsbuckWinter,
        .iconSprite = gMonIcon_SawsbuckWinter,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(7, 13, SHADOW_SIZE_M)
        FOOTPRINT(Sawsbuck)
        OVERWORLD(
            sPicTable_SawsbuckWinter,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_SawsbuckWinter,
            gShinyOverworldPalette_SawsbuckWinter
        )
        .levelUpLearnset = sSawsbuckLevelUpLearnset,
        .teachableLearnset = sSawsbuckTeachableLearnset,
        .formSpeciesIdTable = sSawsbuckFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

#endif //P_FAMILY_DEERLING

#if P_FAMILY_EMOLGA
    [SPECIES_EMOLGA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 103,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 200,
        .expYield = 150,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_STATIC, ABILITY_NONE, ABILITY_MOTOR_DRIVE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Emolga"),
#else
        .speciesName = _("EMOLGA"),
#endif
        .cryId = CRY_EMOLGA,
        .natDexNum = NATIONAL_DEX_EMOLGA,
#if GERMAN
        .categoryName = _("Flughörnchen"),
#else
        .categoryName = _("Sky Squirrel"),
#endif
        .height = 4,
        .weight = 50,
        .description = COMPOUND_STRING(
#if GERMAN
        "Lebt in den Wipfeln der Waldbäume.\n"
        "Während es durch die Lüfte gleitet,\n"
        "entlädt es Strom aus seinen Fluglappen."),
#else
            "It glides using its cape-like membrane.\n"
            "It grills berries and bug Pokémon with\n"
            "electric shocks from the pouches on its\n"
            "cheeks and makes a meal of them."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Emolga,
        .frontPicSize = MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 21),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .enemyMonElevation = 19,
        .backPic = gMonBackPic_Emolga,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 16,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Emolga,
        .shinyPalette = gMonShinyPalette_Emolga,
        .iconSprite = gMonIcon_Emolga,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_S)
        FOOTPRINT(Emolga)
        OVERWORLD(
            sPicTable_Emolga,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Emolga,
            gShinyOverworldPalette_Emolga
        )
        .levelUpLearnset = sEmolgaLevelUpLearnset,
        .teachableLearnset = sEmolgaTeachableLearnset,
        .eggMoveLearnset = sEmolgaEggMoveLearnset,
    },
#endif //P_FAMILY_EMOLGA

#if P_FAMILY_KARRABLAST
    [SPECIES_KARRABLAST] =
    {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 200,
        .expYield = 63,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_SHED_SKIN, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Laukaps"),
#else
        .speciesName = _("KARRABLAST"),
#endif
        .cryId = CRY_KARRABLAST,
        .natDexNum = NATIONAL_DEX_KARRABLAST,
#if GERMAN
        .categoryName = _("Schnappbiss"),
#else
        .categoryName = _("Clamping"),
#endif
        .height = 5,
        .weight = 59,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein mysteriöses Pokémon,\n"
        "das sich entwickelt, wenn es zusammen mit\n"
        "Schnuthelm einen Stromschlag abbekommt."),
#else
            "When they feel threatened, they spit an\n"
            "acidic liquid to drive attackers away.\n"
            "For some reason they evolve while they\n"
            "are in the same place as Shelmet."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Karrablast,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Karrablast,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Karrablast,
        .shinyPalette = gMonShinyPalette_Karrablast,
        .iconSprite = gMonIcon_Karrablast,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(-1, 0, SHADOW_SIZE_S)
        FOOTPRINT(Karrablast)
        OVERWORLD(
            sPicTable_Karrablast,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Karrablast,
            gShinyOverworldPalette_Karrablast
        )
        .levelUpLearnset = sKarrablastLevelUpLearnset,
        .teachableLearnset = sKarrablastTeachableLearnset,
        .eggMoveLearnset = sKarrablastEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_METAL_COAT, SPECIES_ESCAVALIER},
                                {EVO_TRADE, 0, SPECIES_ESCAVALIER, CONDITIONS({IF_TRADE_PARTNER_SPECIES, SPECIES_SHELMET})}),
    },

    [SPECIES_ESCAVALIER] =
    {
        .baseHP        = 70,
        .baseAttack    = 135,
        .baseDefense   = 105,
        .baseSpeed     = 20,
        .baseSpAttack  = 60,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_BUG, TYPE_STEEL),
        .catchRate = 75,
        .expYield = 173,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_SHELL_ARMOR, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Cavalanzas"),
#else
        .speciesName = _("ESCAVALIER"),
#endif
        .cryId = CRY_ESCAVALIER,
        .natDexNum = NATIONAL_DEX_ESCAVALIER,
#if GERMAN
        .categoryName = _("Kavallerie"),
#else
        .categoryName = _("Cavalry"),
#endif
        .height = 10,
        .weight = 330,
        .description = COMPOUND_STRING(
#if GERMAN
        "Eine von einem Schnuthelm gestohlene\n"
        "Muschel dient ihm als Helm. Es greift\n"
        "Gegner mit seinen beiden Lanzen an."),
#else
            "Wearing the shell covering they stole\n"
            "from Shelmet, they defend themselves and\n"
            "attack with two lances. The steel armor\n"
            "protects their whole body."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Escavalier,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        .backPic = gMonBackPic_Escavalier,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Escavalier,
        .shinyPalette = gMonShinyPalette_Escavalier,
        .iconSprite = gMonIcon_Escavalier,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_M)
        FOOTPRINT(Escavalier)
        OVERWORLD(
            sPicTable_Escavalier,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Escavalier,
            gShinyOverworldPalette_Escavalier
        )
        .levelUpLearnset = sEscavalierLevelUpLearnset,
        .teachableLearnset = sEscavalierTeachableLearnset,
    },
#endif //P_FAMILY_KARRABLAST

#if P_FAMILY_FOONGUS
    [SPECIES_FOONGUS] =
    {
        .baseHP        = 69,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 15,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 190,
        .expYield = 59,
        .evYield_HP = 1,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Tarnpignon"),
#else
        .speciesName = _("FOONGUS"),
#endif
        .cryId = CRY_FOONGUS,
        .natDexNum = NATIONAL_DEX_FOONGUS,
#if GERMAN
        .categoryName = _("Pilz"),
#else
        .categoryName = _("Mushroom"),
#endif
        .height = 2,
        .weight = 10,
        .description = COMPOUND_STRING(
#if GERMAN
        "Fällt ein Trainer auf sein Äußeres\n"
        "herein, das komischerweise einem Pokéball\n"
        "ähnelt, besprüht es ihn mit Giftsporen."),
#else
            "It lures Pokémon in with its pattern that\n"
            "looks just like a Poké Ball, then releases\n"
            "its poison spores. Why it resembles a\n"
            "Poké Ball is unknown."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Foongus,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST,
        .backPic = gMonBackPic_Foongus,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Foongus,
        .shinyPalette = gMonShinyPalette_Foongus,
        .iconSprite = gMonIcon_Foongus,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(-1, -3, SHADOW_SIZE_S)
        FOOTPRINT(Foongus)
        OVERWORLD(
            sPicTable_Foongus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Foongus,
            gShinyOverworldPalette_Foongus
        )
        .levelUpLearnset = sFoongusLevelUpLearnset,
        .teachableLearnset = sFoongusTeachableLearnset,
        .eggMoveLearnset = sFoongusEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_AMOONGUSS}),
    },

    [SPECIES_AMOONGUSS] =
    {
        .baseHP        = 114,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 30,
        .baseSpAttack  = 85,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GRASS, TYPE_POISON),
        .catchRate = 75,
        .expYield = 162,
        .evYield_HP = 2,
        .itemCommon = ITEM_TINY_MUSHROOM,
        .itemRare = ITEM_BIG_MUSHROOM,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS),
        .abilities = { ABILITY_EFFECT_SPORE, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Hutsassa"),
#else
        .speciesName = _("AMOONGUSS"),
#endif
        .cryId = CRY_AMOONGUSS,
        .natDexNum = NATIONAL_DEX_AMOONGUSS,
#if GERMAN
        .categoryName = _("Pilz"),
#else
        .categoryName = _("Mushroom"),
#endif
        .height = 6,
        .weight = 105,
        .description = COMPOUND_STRING(
#if GERMAN
        "Um Beute anzulocken, bietet es seinen\n"
        "Hut feil, der einem Pokéball ähnelt. Doch\n"
        "kaum ein Pokémon fällt darauf herein."),
#else
            "It lures prey close by dancing and waving\n"
            "its arm caps, which resemble Poké Balls,\n"
            "in a swaying motion, but very few Pokémon\n"
            "are fooled by this."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Amoonguss,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Amoonguss,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Amoonguss,
        .shinyPalette = gMonShinyPalette_Amoonguss,
        .iconSprite = gMonIcon_Amoonguss,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(1, 5, SHADOW_SIZE_M)
        FOOTPRINT(Amoonguss)
        OVERWORLD(
            sPicTable_Amoonguss,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_Amoonguss,
            gShinyOverworldPalette_Amoonguss
        )
        .levelUpLearnset = sAmoongussLevelUpLearnset,
        .teachableLearnset = sAmoongussTeachableLearnset,
    },
#endif //P_FAMILY_FOONGUS

#if P_FAMILY_FRILLISH
    [SPECIES_FRILLISH] =
    {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_WATER, TYPE_GHOST),
        .catchRate = 190,
        .expYield = 67,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Quabbel"),
#else
        .speciesName = _("FRILLISH"),
#endif
        .cryId = CRY_FRILLISH,
        .natDexNum = NATIONAL_DEX_FRILLISH,
#if GERMAN
        .categoryName = _("Gleit"),
#else
        .categoryName = _("Floating"),
#endif
        .height = 12,
        .weight = 330,
        .description = COMPOUND_STRING(
#if GERMAN
        "Quabbel lähmt seine Beute mit Gift und\n"
        "verschleppt sie in seinen Unterschlupf,\n"
        "8 km unter dem Meeresspiegel."),
#else
            "If its veil-like arms stun and wrap an\n"
            "opponent, that foe will be dragged\n"
            "five miles below the surface to its lair,\n"
            "never to return."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Frillish,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 30),
        ),
        .frontAnimId = ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Frillish,
        .backPicSize = MON_COORDS_SIZE(40, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Frillish,
        .shinyPalette = gMonShinyPalette_Frillish,
        .iconSprite = gMonIcon_Frillish,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_FrillishF,
        .frontPicSizeFemale = MON_COORDS_SIZE(56, 56),
        .backPicFemale = gMonBackPic_FrillishF,
        .backPicSizeFemale = MON_COORDS_SIZE(40, 56),
        .paletteFemale = gMonPalette_FrillishF,
        .shinyPaletteFemale = gMonShinyPalette_FrillishF,
        .iconSpriteFemale = gMonIcon_FrillishF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_S)
        FOOTPRINT(Frillish)
        OVERWORLD(
            sPicTable_Frillish,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Frillish,
            gShinyOverworldPalette_Frillish
        )
        OVERWORLD_FEMALE(
            sPicTable_FrillishF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_FrillishF,
            gShinyOverworldPalette_FrillishF
        )
        .levelUpLearnset = sFrillishLevelUpLearnset,
        .teachableLearnset = sFrillishTeachableLearnset,
        .eggMoveLearnset = sFrillishEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_JELLICENT}),
    },

    [SPECIES_JELLICENT] =
    {
        .baseHP        = 100,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_WATER, TYPE_GHOST),
        .catchRate = 60,
        .expYield = 168,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Apoquallyp"),
#else
        .speciesName = _("JELLICENT"),
#endif
        .cryId = CRY_JELLICENT,
        .natDexNum = NATIONAL_DEX_JELLICENT,
#if GERMAN
        .categoryName = _("Gleit"),
#else
        .categoryName = _("Floating"),
#endif
        .height = 22,
        .weight = 1350,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es heißt, am Meeresboden gebe es einen\n"
        "Palast aus Schiffen, die es versenkt\n"
        "hat. Es besteht fast nur aus Meerwasser."),
#else
            "They propel themselves by expelling\n"
            "absorbed seawater from their bodies.\n"
            "It's said there's a castle of ships\n"
            "Jellicent have sunk on the seafloor."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Jellicent,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 8),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 8),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Jellicent,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Jellicent,
        .shinyPalette = gMonShinyPalette_Jellicent,
        .iconSprite = gMonIcon_Jellicent,
        .iconPalIndex = 0,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_JellicentF,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_JellicentF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 48),
        .paletteFemale = gMonPalette_JellicentF,
        .shinyPaletteFemale = gMonShinyPalette_JellicentF,
        .iconSpriteFemale = gMonIcon_JellicentF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_M)
        FOOTPRINT(Jellicent)
        OVERWORLD(
            sPicTable_Jellicent,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Jellicent,
            gShinyOverworldPalette_Jellicent
        )
        OVERWORLD_FEMALE(
            sPicTable_JellicentF,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_JellicentF,
            gShinyOverworldPalette_JellicentF
        )
        .levelUpLearnset = sJellicentLevelUpLearnset,
        .teachableLearnset = sJellicentTeachableLearnset,
    },
#endif //P_FAMILY_FRILLISH

#if P_FAMILY_ALOMOMOLA
    [SPECIES_ALOMOMOLA] =
    {
        .baseHP        = 165,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 75,
        .expYield = 165,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_WATER_2),
        .abilities = { ABILITY_HEALER, ABILITY_HYDRATION, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_PINK,
#if GERMAN
        .speciesName = _("Mamolida"),
#else
        .speciesName = _("ALOMOMOLA"),
#endif
        .cryId = CRY_ALOMOMOLA,
        .natDexNum = NATIONAL_DEX_ALOMOMOLA,
#if GERMAN
        .categoryName = _("Fürsorge"),
#else
        .categoryName = _("Caring"),
#endif
        .height = 12,
        .weight = 316,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mamolida treibt durch den Ozean. Findet\n"
        "es ein verletztes Pokémon, nimmt es\n"
        "dieses auf und trägt es zurück an Land."),
#else
            "When they find a wounded Pokémon,\n"
            "they embrace it and bring it to shore.\n"
            "The special membrane enveloping\n"
            "Alomomola has the ability to heal wounds."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Alomomola,
        .frontPicSize = MON_COORDS_SIZE(32, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .backPic = gMonBackPic_Alomomola,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Alomomola,
        .shinyPalette = gMonShinyPalette_Alomomola,
        .iconSprite = gMonIcon_Alomomola,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 15, SHADOW_SIZE_S)
        FOOTPRINT(Alomomola)
        OVERWORLD(
            sPicTable_Alomomola,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Alomomola,
            gShinyOverworldPalette_Alomomola
        )
        .levelUpLearnset = sAlomomolaLevelUpLearnset,
        .teachableLearnset = sAlomomolaTeachableLearnset,
        .eggMoveLearnset = sAlomomolaEggMoveLearnset,
    },
#endif //P_FAMILY_ALOMOMOLA

#if P_FAMILY_JOLTIK
    [SPECIES_JOLTIK] =
    {
        .baseHP        = 50,
        .baseAttack    = 47,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 57,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_BUG, TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = 64,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_UNNERVE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Wattzapf"),
#else
        .speciesName = _("JOLTIK"),
#endif
        .cryId = CRY_JOLTIK,
        .natDexNum = NATIONAL_DEX_JOLTIK,
#if GERMAN
        .categoryName = _("Kleben"),
#else
        .categoryName = _("Attaching"),
#endif
        .height = 1,
        .weight = 6,
        .description = COMPOUND_STRING(
#if GERMAN
            "Da es selbst keinen Strom erzeugen kann,\n"
            "klettert es auf andere Pokémon, um ihnen\n"
            "elektrostatische Energie abzusaugen."),
#else
            "Since they can't generate their own\n"
            "electricity, they attach themselves to\n"
            "large-bodied Pokémon and absorb static\n"
            "electricity, which they store in a pouch."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Joltik,
        .frontPicSize = MON_COORDS_SIZE(32, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE,
        .backPic = gMonBackPic_Joltik,
        .backPicSize = MON_COORDS_SIZE(48, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Joltik,
        .shinyPalette = gMonShinyPalette_Joltik,
        .iconSprite = gMonIcon_Joltik,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -5, SHADOW_SIZE_S)
        FOOTPRINT(Joltik)
        OVERWORLD(
            sPicTable_Joltik,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Joltik,
            gShinyOverworldPalette_Joltik
        )
        .levelUpLearnset = sJoltikLevelUpLearnset,
        .teachableLearnset = sJoltikTeachableLearnset,
        .eggMoveLearnset = sJoltikEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GALVANTULA}),
    },

    [SPECIES_GALVANTULA] =
    {
        .baseHP        = 70,
        .baseAttack    = 77,
        .baseDefense   = 60,
        .baseSpeed     = 108,
        .baseSpAttack  = 97,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_BUG, TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = 165,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_COMPOUND_EYES, ABILITY_UNNERVE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Voltula"),
#else
        .speciesName = _("GALVANTULA"),
#endif
        .cryId = CRY_GALVANTULA,
        .natDexNum = NATIONAL_DEX_GALVANTULA,
#if GERMAN
        .categoryName = _("Stromspinne"),
#else
        .categoryName = _("EleSpider"),
#endif
        .height = 8,
        .weight = 143,
        .description = COMPOUND_STRING(
#if GERMAN
        "Lässt seine Beute in elektrisch geladene\n"
        "Fäden tappen. Solang diese durch den\n"
        "Schock gelähmt ist, labt es sich an ihr."),
#else
            "It creates barriers from electrified silk\n"
            "that stun foes. This works as a weapon as\n"
            "well as a defense. While it is immobilized\n"
            "by shock, they leisurely consume it."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Galvantula,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .backPic = gMonBackPic_Galvantula,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 18,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Galvantula,
        .shinyPalette = gMonShinyPalette_Galvantula,
        .iconSprite = gMonIcon_Galvantula,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, -2, SHADOW_SIZE_L)
        FOOTPRINT(Galvantula)
        OVERWORLD(
            sPicTable_Galvantula,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Galvantula,
            gShinyOverworldPalette_Galvantula
        )
        .levelUpLearnset = sGalvantulaLevelUpLearnset,
        .teachableLearnset = sGalvantulaTeachableLearnset,
    },
#endif //P_FAMILY_JOLTIK

#if P_FAMILY_FERROSEED
    [SPECIES_FERROSEED] =
    {
        .baseHP        = 44,
        .baseAttack    = 50,
        .baseDefense   = 91,
        .baseSpeed     = 10,
        .baseSpAttack  = 24,
        .baseSpDefense = 86,
        .types = MON_TYPES(TYPE_GRASS, TYPE_STEEL),
        .catchRate = 255,
        .expYield = 61,
        .evYield_Defense = 1,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_MINERAL),
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Kastadur"),
#else
        .speciesName = _("FERROSEED"),
#endif
        .cryId = CRY_FERROSEED,
        .natDexNum = NATIONAL_DEX_FERROSEED,
#if GERMAN
        .categoryName = _("Dornfrucht"),
#else
        .categoryName = _("Thorn Seed"),
#endif
        .height = 6,
        .weight = 188,
        .description = COMPOUND_STRING(
#if GERMAN
        "Fühlt es sich bedroht, wehrt es sich, indem\n"
        "es eine großzügige Salve Dornen abfeuert."),
#else
            "It absorbs the iron it finds in the rock\n"
            "while clinging to the ceiling of caves.\n"
            "When threatened, it attacks by shooting\n"
            "a barrage of spikes."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ferroseed,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 28),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Ferroseed,
        .backPicSize = MON_COORDS_SIZE(48, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Ferroseed,
        .shinyPalette = gMonShinyPalette_Ferroseed,
        .iconSprite = gMonIcon_Ferroseed,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 1, SHADOW_SIZE_S)
        FOOTPRINT(Ferroseed)
        OVERWORLD(
            sPicTable_Ferroseed,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ferroseed,
            gShinyOverworldPalette_Ferroseed
        )
        .levelUpLearnset = sFerroseedLevelUpLearnset,
        .teachableLearnset = sFerroseedTeachableLearnset,
        .eggMoveLearnset = sFerroseedEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_FERROTHORN}),
    },

    [SPECIES_FERROTHORN] =
    {
        .baseHP        = 74,
        .baseAttack    = 94,
        .baseDefense   = 131,
        .baseSpeed     = 20,
        .baseSpAttack  = 54,
        .baseSpDefense = 116,
        .types = MON_TYPES(TYPE_GRASS, TYPE_STEEL),
        .catchRate = 90,
        .expYield = 171,
        .evYield_Defense = 2,
        .itemRare = ITEM_STICKY_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_GRASS, EGG_GROUP_MINERAL),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE, ABILITY_ANTICIPATION },
    #else
        .abilities = { ABILITY_IRON_BARBS, ABILITY_NONE, ABILITY_NONE },
    #endif
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Tentantel"),
#else
        .speciesName = _("FERROTHORN"),
#endif
        .cryId = CRY_FERROTHORN,
        .natDexNum = NATIONAL_DEX_FERROTHORN,
#if GERMAN
        .categoryName = _("Dornkugel"),
#else
        .categoryName = _("Thorn Pod"),
#endif
        .height = 10,
        .weight = 1100,
        .description = COMPOUND_STRING(
#if GERMAN
        "Tentantel macht mit Gegnern kurzen\n"
        "Prozess, indem es mit seinen drei Schlingen\n"
        "auf sie eindrischt und Dornen auf sie\n"
        "abfeuert."),
#else
            "It fights by swinging around its three\n"
            "spiky feelers and shooting spikes.\n"
            "A hit from these steel spikes can reduce\n"
            "a boulder to rubble."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Ferrothorn,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .enemyMonElevation = 10,
        .backPic = gMonBackPic_Ferrothorn,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Ferrothorn,
        .shinyPalette = gMonShinyPalette_Ferrothorn,
        .iconSprite = gMonIcon_Ferrothorn,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Ferrothorn)
        OVERWORLD(
            sPicTable_Ferrothorn,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Ferrothorn,
            gShinyOverworldPalette_Ferrothorn
        )
        .levelUpLearnset = sFerrothornLevelUpLearnset,
        .teachableLearnset = sFerrothornTeachableLearnset,
    },
#endif //P_FAMILY_FERROSEED

#if P_FAMILY_KLINK
    [SPECIES_KLINK] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 30,
        .baseSpAttack  = 45,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 130,
        .expYield = 60,
        .evYield_Defense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Klikk"),
#else
        .speciesName = _("KLINK"),
#endif
        .cryId = CRY_KLINK,
        .natDexNum = NATIONAL_DEX_KLINK,
#if GERMAN
        .categoryName = _("Getriebe"),
#else
        .categoryName = _("Gear"),
#endif
        .height = 3,
        .weight = 210,
        .description = COMPOUND_STRING(
#if GERMAN
        "Klikk gewinnt lebenswichtige\n"
        "Energie, indem es seine zwei Einzelteile\n"
        "ineinander verzahnt und rotieren lässt."),
#else
            "Two bodies comprise a fixed pair.\n"
            "The two minigears that mesh together\n"
            "are predetermined. Each will rebound from\n"
            "other minigears without meshing."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Klink,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 12,
        .backPic = gMonBackPic_Klink,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Klink,
        .shinyPalette = gMonShinyPalette_Klink,
        .iconSprite = gMonIcon_Klink,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 11, SHADOW_SIZE_S)
        FOOTPRINT(Klink)
        OVERWORLD(
            sPicTable_Klink,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Klink,
            gShinyOverworldPalette_Klink
        )
        .levelUpLearnset = sKlinkLevelUpLearnset,
        .teachableLearnset = sKlinkTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_KLANG}),
    },

    [SPECIES_KLANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 95,
        .baseSpeed     = 50,
        .baseSpAttack  = 70,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 60,
        .expYield = 154,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Kliklak"),
#else
        .speciesName = _("KLANG"),
#endif
        .cryId = CRY_KLANG,
        .natDexNum = NATIONAL_DEX_KLANG,
#if GERMAN
        .categoryName = _("Getriebe"),
#else
        .categoryName = _("Gear"),
#endif
        .height = 6,
        .weight = 510,
        .description = COMPOUND_STRING(
#if GERMAN
        "Teilt Artgenossen seine Gefühlslage mit,\n"
        "indem es die Umlaufrichtung ändert. Wenn\n"
        "es wütend ist, dreht es sich schneller."),
#else
            "A minigear and big gear comprise its\n"
            "body. Spinning minigears are rotated\n"
            "at high speed and repeatedly fired away.\n"
            "It is dangerous if the gears don't return."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Klang,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Klang,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Klang,
        .shinyPalette = gMonShinyPalette_Klang,
        .iconSprite = gMonIcon_Klang,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Klang)
        OVERWORLD(
            sPicTable_Klang,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Klang,
            gShinyOverworldPalette_Klang
        )
        .levelUpLearnset = sKlangLevelUpLearnset,
        .teachableLearnset = sKlangTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 49, SPECIES_KLINKLANG}),
    },

    [SPECIES_KLINKLANG] =
    {
        .baseHP        = 60,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 260 : 234,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_PLUS, ABILITY_MINUS, ABILITY_CLEAR_BODY },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Klikdiklak"),
#else
        .speciesName = _("KLINKLANG"),
#endif
        .cryId = CRY_KLINKLANG,
        .natDexNum = NATIONAL_DEX_KLINKLANG,
#if GERMAN
        .categoryName = _("Getriebe"),
#else
        .categoryName = _("Gear"),
#endif
        .height = 6,
        .weight = 810,
        .description = COMPOUND_STRING(
#if GERMAN
        "Indem es das Rad mit dem roten Zentrum\n"
        "mit hohem Tempo zum Rotieren bringt,\n"
        "kann es eine Turboladung durchführen."),
#else
            "Its red core functions as an energy tank.\n"
            "It is rotated at high speed for a rapid\n"
            "energy charge. It fires the charged energy\n"
            "through its spikes into an area."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Klinklang,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .enemyMonElevation = 4,
        .backPic = gMonBackPic_Klinklang,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        .palette = gMonPalette_Klinklang,
        .shinyPalette = gMonShinyPalette_Klinklang,
        .iconSprite = gMonIcon_Klinklang,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_L)
        FOOTPRINT(Klinklang)
        OVERWORLD(
            sPicTable_Klinklang,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Klinklang,
            gShinyOverworldPalette_Klinklang
        )
        .levelUpLearnset = sKlinklangLevelUpLearnset,
        .teachableLearnset = sKlinklangTeachableLearnset,
    },
#endif //P_FAMILY_KLINK

#if P_FAMILY_TYNAMO
    [SPECIES_TYNAMO] =
    {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 190,
        .expYield = 55,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Zapplardin"),
#else
        .speciesName = _("TYNAMO"),
#endif
        .cryId = CRY_TYNAMO,
        .natDexNum = NATIONAL_DEX_TYNAMO,
#if GERMAN
        .categoryName = _("Stromfisch"),
#else
        .categoryName = _("EleFish"),
#endif
        .height = 2,
        .weight = 3,
        .description = COMPOUND_STRING(
#if GERMAN
        "Allein erzeugt es nur wenig Strom,\n"
        "doch tritt es geschlossen im Schwarm auf,\n"
        "gleicht seine Kraft der eines Blitzes."),
#else
            "These Pokémon move in schools.\n"
            "One alone can emit only a trickle of\n"
            "electricity, so a group of them gathers\n"
            "to unleash a powerful electric shock."),
#endif
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Tynamo,
        .frontPicSize = MON_COORDS_SIZE(40, 24),
        .frontPicYOffset = 22,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 16,
        .backPic = gMonBackPic_Tynamo,
        .backPicSize = MON_COORDS_SIZE(64, 24),
        .backPicYOffset = 21,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Tynamo,
        .shinyPalette = gMonShinyPalette_Tynamo,
        .iconSprite = gMonIcon_Tynamo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 5, SHADOW_SIZE_S)
        FOOTPRINT(Tynamo)
        OVERWORLD(
            sPicTable_Tynamo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Tynamo,
            gShinyOverworldPalette_Tynamo
        )
        .teachingType = TM_ILLITERATE,
        .levelUpLearnset = sTynamoLevelUpLearnset,
        .teachableLearnset = sTynamoTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_EELEKTRIK}),
    },

    [SPECIES_EELEKTRIK] =
    {
        .baseHP        = 65,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 60,
        .expYield = 142,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Zapplalek"),
#else
        .speciesName = _("EELEKTRIK"),
#endif
        .cryId = CRY_EELEKTRIK,
        .natDexNum = NATIONAL_DEX_EELEKTRIK,
#if GERMAN
        .categoryName = _("Stromfisch"),
#else
        .categoryName = _("EleFish"),
#endif
        .height = 12,
        .weight = 220,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schlingt sich um Gegner, lähmt sie über\n"
        "die rund gemaserten Flächen an seinem\n"
        "Körper mit Strom und beißt beherzt zu."),
#else
            "These Pokémon have a big appetite.\n"
            "It wraps itself around its prey and\n"
            "paralyzes it with electricity from the\n"
            "round spots on its sides. Then it chomps."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Eelektrik,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 4),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 4),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Eelektrik,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Eelektrik,
        .shinyPalette = gMonShinyPalette_Eelektrik,
        .iconSprite = gMonIcon_Eelektrik,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 13, SHADOW_SIZE_S)
        FOOTPRINT(Eelektrik)
        OVERWORLD(
            sPicTable_Eelektrik,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Eelektrik,
            gShinyOverworldPalette_Eelektrik
        )
        .levelUpLearnset = sEelektrikLevelUpLearnset,
        .teachableLearnset = sEelektrikTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_THUNDER_STONE, SPECIES_EELEKTROSS}),
    },

    [SPECIES_EELEKTROSS] =
    {
        .baseHP        = 85,
        .baseAttack    = 115,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 30,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 258 : 232,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Zapplarang"),
#else
        .speciesName = _("EELEKTROSS"),
#endif
        .cryId = CRY_EELEKTROSS,
        .natDexNum = NATIONAL_DEX_EELEKTROSS,
#if GERMAN
        .categoryName = _("Stromfisch"),
#else
        .categoryName = _("EleFish"),
#endif
        .height = 21,
        .weight = 805,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit dem Saugnapf an seinem Maul hakt\n"
        "es sich an seiner Beute fest und versetzt\n"
        "ihr über seine Fangzähne Stromschläge."),
#else
            "They crawl out of the ocean using their\n"
            "arms. They will attack prey on shore and\n"
            "immediately drag it into the ocean, with\n"
            "their sucker mouths."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Eelektross,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 27),
            ANIMCMD_FRAME(0, 27),
            ANIMCMD_FRAME(1, 24),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 27),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Eelektross,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Eelektross,
        .shinyPalette = gMonShinyPalette_Eelektross,
        .iconSprite = gMonIcon_Eelektross,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 13, SHADOW_SIZE_M)
        FOOTPRINT(Eelektross)
        OVERWORLD(
            sPicTable_Eelektross,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Eelektross,
            gShinyOverworldPalette_Eelektross
        )
        .levelUpLearnset = sEelektrossLevelUpLearnset,
        .teachableLearnset = sEelektrossTeachableLearnset,
        .formSpeciesIdTable = sEelektrossFormSpeciesIdTable,
        .formChangeTable = sEelektrossFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_EELEKTROSS_MEGA] =
    {
        .baseHP        = 85,
        .baseAttack    = 145,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 135,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 30,
        .expYield = 258 ,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Zapplarang"),
#else
        .speciesName = _("EELEKTROSS"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_EELEKTROSS_MEGA,
    #else
        .cryId = CRY_EELEKTROSS,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_EELEKTROSS,
#if GERMAN
        .categoryName = _("Stromfisch"),
#else
        .categoryName = _("EleFish"),
#endif
        .height = 30,
        .weight = 1800,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es erzeugt zehnmal mehr\n"
        "Elektrizität als vor der Mega-Entwicklung\n"
        "und entlädt diese über seine aus\n"
        "Schleim bestehenden Zapplalek-Imitate."),
#else
            "It now generates 10 times the\n"
            "electricity it did before Mega\n"
            "Evolving. It discharges this energy\n"
            "from its false Eelektrik made of mucus."),
#endif
        .frontPic = gMonFrontPic_EelektrossMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_EelektrossMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_EelektrossMega,
        .shinyPalette = gMonShinyPalette_EelektrossMega,
        .iconSprite = gMonIcon_EelektrossMega,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Eelektross)
        SHADOW(-2, 16, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sEelektrossLevelUpLearnset,
        .teachableLearnset = sEelektrossTeachableLearnset,
        .formSpeciesIdTable = sEelektrossFormSpeciesIdTable,
        .formChangeTable = sEelektrossFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_TYNAMO

#if P_FAMILY_ELGYEM
    [SPECIES_ELGYEM] =
    {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 85,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 255,
        .expYield = 67,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Pygraulon"),
#else
        .speciesName = _("ELGYEM"),
#endif
        .cryId = CRY_ELGYEM,
        .natDexNum = NATIONAL_DEX_ELGYEM,
#if GERMAN
        .categoryName = _("Grips"),
#else
        .categoryName = _("Cerebral"),
#endif
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
#if GERMAN
        "Pygraulon verfügt über mächtige\n"
        "Psycho-Kräfte, mit denen es die Hirne\n"
        "seiner Gegner verwirrt, um ihnen Kopfweh\n"
        "zu bereiten."),
#else
            "It psychically squeezes the brain of\n"
            "its foe, causing unendurable headaches.\n"
            "Rumors of its origin are linked to a UFO\n"
            "crash site in the desert 50 years ago."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Elgyem,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 11,
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
        .frontAnimId = ANIM_RISING_WOBBLE,
        .backPic = gMonBackPic_Elgyem,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Elgyem,
        .shinyPalette = gMonShinyPalette_Elgyem,
        .iconSprite = gMonIcon_Elgyem,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Elgyem)
        OVERWORLD(
            sPicTable_Elgyem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Elgyem,
            gShinyOverworldPalette_Elgyem
        )
        .levelUpLearnset = sElgyemLevelUpLearnset,
        .teachableLearnset = sElgyemTeachableLearnset,
        .eggMoveLearnset = sElgyemEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_BEHEEYEM}),
    },

    [SPECIES_BEHEEYEM] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 40,
        .baseSpAttack  = 125,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 90,
        .expYield = 170,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_TELEPATHY, ABILITY_SYNCHRONIZE, ABILITY_ANALYTIC },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Megalon"),
#else
        .speciesName = _("BEHEEYEM"),
#endif
        .cryId = CRY_BEHEEYEM,
        .natDexNum = NATIONAL_DEX_BEHEEYEM,
#if GERMAN
        .categoryName = _("Grips"),
#else
        .categoryName = _("Cerebral"),
#endif
        .height = 10,
        .weight = 345,
        .description = COMPOUND_STRING(
#if GERMAN
        "Megalon spricht, indem es seine\n"
        "Fingerspitzen leuchten lässt, doch noch\n"
        "konnte der Code dahinter nicht entziffert\n"
        "werden."),
#else
            "It can manipulate an opponent's memory.\n"
            "Apparently, it communicates by flashing\n"
            "its three fingers, but those patterns\n"
            "haven't been decoded. "),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Beheeyem,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Beheeyem,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Beheeyem,
        .shinyPalette = gMonShinyPalette_Beheeyem,
        .iconSprite = gMonIcon_Beheeyem,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_M)
        FOOTPRINT(Beheeyem)
        OVERWORLD(
            sPicTable_Beheeyem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Beheeyem,
            gShinyOverworldPalette_Beheeyem
        )
        .levelUpLearnset = sBeheeyemLevelUpLearnset,
        .teachableLearnset = sBeheeyemTeachableLearnset,
    },
#endif //P_FAMILY_ELGYEM

#if P_FAMILY_LITWICK
    [SPECIES_LITWICK] =
    {
        .baseHP        = 50,
        .baseAttack    = 30,
        .baseDefense   = 55,
        .baseSpeed     = 20,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FIRE),
        .catchRate = 190,
        .expYield = 55,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
    #else
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Lichtel"),
#else
        .speciesName = _("LITWICK"),
#endif
        .cryId = CRY_LITWICK,
        .natDexNum = NATIONAL_DEX_LITWICK,
#if GERMAN
        .categoryName = _("Kerze"),
#else
        .categoryName = _("Candle"),
#endif
        .height = 3,
        .weight = 31,
        .description = COMPOUND_STRING(
#if GERMAN
        "Lichtel entzündet ein Licht und gibt vor,\n"
        "dem Gegner den Weg zu weisen, doch\n"
        "eigentlich saugt es ihm seine\n"
        "Lebensenergie ab."),
#else
            "While Litwick shines a light and pretends\n"
            "to be a guide, it absorbs the life force of\n"
            "any who follow it, which becomes the fuel\n"
            "that it burns."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Litwick,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Litwick,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        .palette = gMonPalette_Litwick,
        .shinyPalette = gMonShinyPalette_Litwick,
        .iconSprite = gMonIcon_Litwick,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NORMAL,
        SHADOW(1, -1, SHADOW_SIZE_S)
        FOOTPRINT(Litwick)
        OVERWORLD(
            sPicTable_Litwick,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Litwick,
            gShinyOverworldPalette_Litwick
        )
        .levelUpLearnset = sLitwickLevelUpLearnset,
        .teachableLearnset = sLitwickTeachableLearnset,
        .eggMoveLearnset = sLitwickEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 41, SPECIES_LAMPENT}),
    },

    [SPECIES_LAMPENT] =
    {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FIRE),
        .catchRate = 90,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
    #else
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Laternecto"),
#else
        .speciesName = _("LAMPENT"),
#endif
        .cryId = CRY_LAMPENT,
        .natDexNum = NATIONAL_DEX_LAMPENT,
#if GERMAN
        .categoryName = _("Lampe"),
#else
        .categoryName = _("Lamp"),
#endif
        .height = 6,
        .weight = 130,
        .description = COMPOUND_STRING(
#if GERMAN
        "Laternecto nährt seine Flamme mit den\n"
        "Seelen seiner Opfer. Heutzutage irrt es\n"
        "auf der Suche nach Seelen durch\n"
        "Krankenhäuser."),
#else
            "This ominous Pokémon is feared.\n"
            "Through cities it wanders, searching\n"
            "for the spirits of the fallen. The spirits\n"
            "it absorbs fuel its baleful fire."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Lampent,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Lampent,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Lampent,
        .shinyPalette = gMonShinyPalette_Lampent,
        .iconSprite = gMonIcon_Lampent,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_S)
        FOOTPRINT(Lampent)
        OVERWORLD(
            sPicTable_Lampent,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lampent,
            gShinyOverworldPalette_Lampent
        )
        .levelUpLearnset = sLampentLevelUpLearnset,
        .teachableLearnset = sLampentTeachableLearnset,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_CHANDELURE}),
    },

    [SPECIES_CHANDELURE] =
    {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 145,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FIRE),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 260 : 234,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
    #if P_UPDATED_ABILITIES >= GEN_6
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
    #else
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_SHADOW_TAG },
    #endif
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Skelabra"),
#else
        .speciesName = _("CHANDELURE"),
#endif
        .cryId = CRY_CHANDELURE,
        .natDexNum = NATIONAL_DEX_CHANDELURE,
#if GERMAN
        .categoryName = _("Geleit"),
#else
        .categoryName = _("Luring"),
#endif
        .height = 10,
        .weight = 343,
        .description = COMPOUND_STRING(
#if GERMAN
        "Skelabra saugt die Seele eines jeden auf,\n"
        "der in seinen Feuerkranz gerät, bis nur\n"
        "noch eine leere Hülle von ihm übrig ist."),
#else
            "Being consumed in Chandelure's flame burns\n"
            "up the spirit, leaving the body behind.\n"
            "By waving the flames on its arms, it puts\n"
            "its foes into a hypnotic trance."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Chandelure,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Chandelure,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Chandelure,
        .shinyPalette = gMonShinyPalette_Chandelure,
        .iconSprite = gMonIcon_Chandelure,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_S)
        FOOTPRINT(Chandelure)
        OVERWORLD(
            sPicTable_Chandelure,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Chandelure,
            gShinyOverworldPalette_Chandelure
        )
        .levelUpLearnset = sChandelureLevelUpLearnset,
        .teachableLearnset = sChandelureTeachableLearnset,
        .formSpeciesIdTable = sChandelureFormSpeciesIdTable,
        .formChangeTable = sChandelureFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_CHANDELURE_MEGA] =
    {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 110,
        .baseSpeed     = 90,
        .baseSpAttack  = 175,
        .baseSpDefense = 110,
        .types = MON_TYPES(TYPE_GHOST, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 260,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_FLAME_BODY, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Skelabra"),
#else
        .speciesName = _("CHANDELURE"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_CHANDELURE_MEGA,
    #else
        .cryId = CRY_CHANDELURE,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_CHANDELURE,
#if GERMAN
        .categoryName = _("Geleit"),
#else
        .categoryName = _("Luring"),
#endif
        .height = 25,
        .weight = 696,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es saugt tiefen Groll in sich auf und\n"
        "wandelt diesen anschließend in Kraft um.\n"
        "Eines seiner Augen ist ein Fenster zum\n"
        "Jenseits."),
#else
            "One of its eyes is a window linking\n"
            "our world with the afterlife.\n"
            "This Pokémon draws in hatred and\n"
            "converts it into power."),
#endif
        .frontPic = gMonFrontPic_ChandelureMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_ChandelureMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_ChandelureMega,
        .shinyPalette = gMonShinyPalette_ChandelureMega,
        .iconSprite = gMonIcon_ChandelureMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Chandelure)
        SHADOW(-1, 16, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sChandelureLevelUpLearnset,
        .teachableLearnset = sChandelureTeachableLearnset,
        .formSpeciesIdTable = sChandelureFormSpeciesIdTable,
        .formChangeTable = sChandelureFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_LITWICK

#if P_FAMILY_AXEW
    [SPECIES_AXEW] =
    {
        .baseHP        = 46,
        .baseAttack    = 87,
        .baseDefense   = 60,
        .baseSpeed     = 57,
        .baseSpAttack  = 30,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 75,
        .expYield = 64,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Milza"),
#else
        .speciesName = _("AXEW"),
#endif
        .cryId = CRY_AXEW,
        .natDexNum = NATIONAL_DEX_AXEW,
#if GERMAN
        .categoryName = _("Stoßzahn"),
#else
        .categoryName = _("Tusk"),
#endif
        .height = 6,
        .weight = 180,
        .description = COMPOUND_STRING(
#if GERMAN
        "Milza knackt mit seinen Hauern Nüsse.\n"
        "Brechen seine Fangzähne ab, wächst\n"
        "an ihrer Stelle ein stärkeres Ersatzpaar."),
#else
            "They mark their territory by leaving\n"
            "gashes in trees with their tusks. If a\n"
            "tusk breaks, a new one grows in quickly,\n"
            "harder and sturdier than the last."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Axew,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Axew,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Axew,
        .shinyPalette = gMonShinyPalette_Axew,
        .iconSprite = gMonIcon_Axew,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(2, 1, SHADOW_SIZE_S)
        FOOTPRINT(Axew)
        OVERWORLD(
            sPicTable_Axew,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Axew,
            gShinyOverworldPalette_Axew
        )
        .levelUpLearnset = sAxewLevelUpLearnset,
        .teachableLearnset = sAxewTeachableLearnset,
        .eggMoveLearnset = sAxewEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_FRAXURE}),
    },

    [SPECIES_FRAXURE] =
    {
        .baseHP        = 66,
        .baseAttack    = 117,
        .baseDefense   = 70,
        .baseSpeed     = 67,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 60,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Sharfax"),
#else
        .speciesName = _("FRAXURE"),
#endif
        .cryId = CRY_FRAXURE,
        .natDexNum = NATIONAL_DEX_FRAXURE,
#if GERMAN
        .categoryName = _("Beilkiefer"),
#else
        .categoryName = _("Axe Jaw"),
#endif
        .height = 10,
        .weight = 360,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit seinen Fängen kriegt es sogar Felsen\n"
            "klein. Gegen Artgenossen, die sein Revier\n"
            "passieren, geht es besonders hart vor."),
#else
            "Their tusks can shatter rocks.\n"
            "A broken tusk will not grow back,\n"
            "so it diligently sharpens its tusks on\n"
            "river rocks after the end of a battle."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Fraxure,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Fraxure,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Fraxure,
        .shinyPalette = gMonShinyPalette_Fraxure,
        .iconSprite = gMonIcon_Fraxure,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_L)
        FOOTPRINT(Fraxure)
        OVERWORLD(
            sPicTable_Fraxure,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Fraxure,
            gShinyOverworldPalette_Fraxure
        )
        .levelUpLearnset = sFraxureLevelUpLearnset,
        .teachableLearnset = sFraxureTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_HAXORUS}),
    },

    [SPECIES_HAXORUS] =
    {
        .baseHP        = 76,
        .baseAttack    = 147,
        .baseDefense   = 90,
        .baseSpeed     = 97,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 270 : 243,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MONSTER, EGG_GROUP_DRAGON),
        .abilities = { ABILITY_RIVALRY, ABILITY_MOLD_BREAKER, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Maxax"),
#else
        .speciesName = _("HAXORUS"),
#endif
        .cryId = CRY_HAXORUS,
        .natDexNum = NATIONAL_DEX_HAXORUS,
#if GERMAN
        .categoryName = _("Beilkiefer"),
#else
        .categoryName = _("Axe Jaw"),
#endif
        .height = 18,
        .weight = 1055,
        .description = COMPOUND_STRING(
#if GERMAN
        "Hat eine eher sanfte Natur, doch\n"
        "bei Eindringlingen kennt es keine Gnade.\n"
        "Seine Stoßzähne durchbohren sogar Eisen."),
#else
            "They are kind but can be relentless\n"
            "when defending territory. Their sturdy\n"
            "tusks will stay sharp even if used to cut\n"
            "steel beams."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Haxorus,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Haxorus,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Haxorus,
        .shinyPalette = gMonShinyPalette_Haxorus,
        .iconSprite = gMonIcon_Haxorus,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 9, SHADOW_SIZE_L)
        FOOTPRINT(Haxorus)
        OVERWORLD(
            sPicTable_Haxorus,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Haxorus,
            gShinyOverworldPalette_Haxorus
        )
        .levelUpLearnset = sHaxorusLevelUpLearnset,
        .teachableLearnset = sHaxorusTeachableLearnset,
    },
#endif //P_FAMILY_AXEW

#if P_FAMILY_CUBCHOO
    [SPECIES_CUBCHOO] =
    {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 120,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SLUSH_RUSH, ABILITY_RATTLED },
    #else
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_RATTLED },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Petznief"),
#else
        .speciesName = _("CUBCHOO"),
#endif
        .cryId = CRY_CUBCHOO,
        .natDexNum = NATIONAL_DEX_CUBCHOO,
#if GERMAN
        .categoryName = _("Eisscholle"),
#else
        .categoryName = _("Chill"),
#endif
        .height = 5,
        .weight = 85,
        .description = COMPOUND_STRING(
#if GERMAN
        "Der Schleim, der stets aus seiner Nase\n"
        "hängt, treibt seine Attacken an. Zieht\n"
        "es ihn hoch, steht ein Angriff bevor."),
#else
            "Its nose is always running.\n"
            "Their snot is a barometer of health.\n"
            "When healthy, their snot is sticky and\n"
            "the power of their ice moves increases."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cubchoo,
        .frontPicSize = MON_COORDS_SIZE(32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Cubchoo,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Cubchoo,
        .shinyPalette = gMonShinyPalette_Cubchoo,
        .iconSprite = gMonIcon_Cubchoo,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(-2, 0, SHADOW_SIZE_S)
        FOOTPRINT(Cubchoo)
        OVERWORLD(
            sPicTable_Cubchoo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cubchoo,
            gShinyOverworldPalette_Cubchoo
        )
        .levelUpLearnset = sCubchooLevelUpLearnset,
        .teachableLearnset = sCubchooTeachableLearnset,
        .eggMoveLearnset = sCubchooEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_BEARTIC}),
    },

    [SPECIES_BEARTIC] =
    {
        .baseHP        = 95,
        .baseAttack    = P_UPDATED_STATS >= GEN_7 ? 130 : 110,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 60,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_7) ? 177 : 170,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
    #if P_UPDATED_ABILITIES >= GEN_7
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_SLUSH_RUSH, ABILITY_SWIFT_SWIM },
    #else
        .abilities = { ABILITY_SNOW_CLOAK, ABILITY_NONE, ABILITY_SWIFT_SWIM },
    #endif
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Siberio"),
#else
        .speciesName = _("BEARTIC"),
#endif
        .cryId = CRY_BEARTIC,
        .natDexNum = NATIONAL_DEX_BEARTIC,
#if GERMAN
        .categoryName = _("Packeis"),
#else
        .categoryName = _("Freezing"),
#endif
        .height = 26,
        .weight = 2600,
        .description = COMPOUND_STRING(
#if GERMAN
        "Siberio liebt die kalten Meere im Norden\n"
        "und überquert ihre Flächen auf Stegen,\n"
        "die es mit seinem gefrorenen Atem baut."),
#else
            "It freezes its breath to create fangs\n"
            "and claws of ice to fight with.\n"
            "Very able in the water, it swims around\n"
            "in northern seas and catches prey."),
#endif
        .pokemonScale = 266,
        .pokemonOffset = 3,
        .trainerScale = 399,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Beartic,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Beartic,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        .palette = gMonPalette_Beartic,
        .shinyPalette = gMonShinyPalette_Beartic,
        .iconSprite = gMonIcon_Beartic,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 13, SHADOW_SIZE_L)
        FOOTPRINT(Beartic)
        OVERWORLD(
            sPicTable_Beartic,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Beartic,
            gShinyOverworldPalette_Beartic
        )
        .levelUpLearnset = sBearticLevelUpLearnset,
        .teachableLearnset = sBearticTeachableLearnset,
    },
#endif //P_FAMILY_CUBCHOO

#if P_FAMILY_CRYOGONAL
    [SPECIES_CRYOGONAL] =
    {
        .baseHP        = P_UPDATED_STATS >= GEN_7 ? 80 : 70,
        .baseAttack    = 50,
        .baseDefense   = P_UPDATED_STATS >= GEN_7 ? 50 : 30,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 135,
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 25,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_7) ? 180 : 170,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Frigometri"),
#else
        .speciesName = _("CRYOGONAL"),
#endif
        .cryId = CRY_CRYOGONAL,
        .natDexNum = NATIONAL_DEX_CRYOGONAL,
#if GERMAN
        .categoryName = _("Kristall"),
#else
        .categoryName = _("Crystallize"),
#endif
        .height = 11,
        .weight = 1480,
        .description = COMPOUND_STRING(
#if GERMAN
        "Frigometri fängt seine Beute mit Ketten,\n"
        "die sich aus Eiskristallen zusammensetzen.\n"
        "Entstanden ist es aus einer Schneewolke."),
#else
            "They are born in snow clouds. When\n"
            "its body temperature goes up, it turns\n"
            "into steam and vanishes. When its\n"
            "temperature lowers, it returns to ice."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cryogonal,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 48),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SHRINK_GROW,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_Cryogonal,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Cryogonal,
        .shinyPalette = gMonShinyPalette_Cryogonal,
        .iconSprite = gMonIcon_Cryogonal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cryogonal)
        OVERWORLD(
            sPicTable_Cryogonal,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cryogonal,
            gShinyOverworldPalette_Cryogonal
        )
        .levelUpLearnset = sCryogonalLevelUpLearnset,
        .teachableLearnset = sCryogonalTeachableLearnset,
    },
#endif //P_FAMILY_CRYOGONAL

#if P_FAMILY_SHELMET
    [SPECIES_SHELMET] =
    {
        .baseHP        = 50,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 200,
        .expYield = 61,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_HYDRATION, ABILITY_SHELL_ARMOR, ABILITY_OVERCOAT },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Schnuthelm"),
#else
        .speciesName = _("SHELMET"),
#endif
        .cryId = CRY_SHELMET,
        .natDexNum = NATIONAL_DEX_SHELMET,
#if GERMAN
        .categoryName = _("Schnecke"),
#else
        .categoryName = _("Snail"),
#endif
        .height = 4,
        .weight = 77,
        .description = COMPOUND_STRING(
#if GERMAN
        "Hält sich ein Laukaps in seiner Nähe auf\n"
        "und kommen beide mit Strom in Berührung,\n"
        "entwickeln sie sich."),
#else
            "When attacked, it defends itself by\n"
            "closing the lid of its shell. It evolves\n"
            "when bathed in an electric-like energy\n"
            "along with Karrablast."),
#endif
        .pokemonScale = 491,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Shelmet,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_TWIST,
        .backPic = gMonBackPic_Shelmet,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 19,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Shelmet,
        .shinyPalette = gMonShinyPalette_Shelmet,
        .iconSprite = gMonIcon_Shelmet,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -1, SHADOW_SIZE_S)
        FOOTPRINT(Shelmet)
        OVERWORLD(
            sPicTable_Shelmet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Shelmet,
            gShinyOverworldPalette_Shelmet
        )
        .levelUpLearnset = sShelmetLevelUpLearnset,
        .teachableLearnset = sShelmetTeachableLearnset,
        .eggMoveLearnset = sShelmetEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_ACCELGOR, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})},
                                {EVO_TRADE, 0, SPECIES_ACCELGOR, CONDITIONS({IF_TRADE_PARTNER_SPECIES, SPECIES_KARRABLAST})}),
    },

    [SPECIES_ACCELGOR] =
    {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 145,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_BUG),
        .catchRate = 75,
        .expYield = 173,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_HYDRATION, ABILITY_STICKY_HOLD, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Hydragil"),
#else
        .speciesName = _("ACCELGOR"),
#endif
        .cryId = CRY_ACCELGOR,
        .natDexNum = NATIONAL_DEX_ACCELGOR,
#if GERMAN
        .categoryName = _("Entschalung"),
#else
        .categoryName = _("Shell Out"),
#endif
        .height = 8,
        .weight = 253,
        .description = COMPOUND_STRING(
#if GERMAN
        "Seit es die schwere Muschel abgestreift\n"
        "hat, ist es viel leichter. Nun gleichen\n"
        "seine Kampfbewegungen denen eines Ninja."),
#else
            "When its body dries out, it weakens. So, to\n"
            "prevent dehydration, it wraps itself in\n"
            "layers of thin membrane. It is very light\n"
            "and fights with ninja-like movements."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Accelgor,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .backPic = gMonBackPic_Accelgor,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_H_SPRING_REPEATED,
        .palette = gMonPalette_Accelgor,
        .shinyPalette = gMonShinyPalette_Accelgor,
        .iconSprite = gMonIcon_Accelgor,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-14, 8, SHADOW_SIZE_S)
        FOOTPRINT(Accelgor)
        OVERWORLD(
            sPicTable_Accelgor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Accelgor,
            gShinyOverworldPalette_Accelgor
        )
        .levelUpLearnset = sAccelgorLevelUpLearnset,
        .teachableLearnset = sAccelgorTeachableLearnset,
    },
#endif //P_FAMILY_SHELMET

#if P_FAMILY_STUNFISK
    [SPECIES_STUNFISK] =
    {
        .baseHP        = 109,
        .baseAttack    = 66,
        .baseDefense   = 84,
        .baseSpeed     = 32,
        .baseSpAttack  = 81,
        .baseSpDefense = 99,
        .types = MON_TYPES(TYPE_GROUND, TYPE_ELECTRIC),
        .catchRate = 75,
        .expYield = 165,
        .evYield_HP = 2,
        .itemRare = ITEM_SOFT_SAND,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 70,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_STATIC, ABILITY_LIMBER, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Flunschlik"),
#else
        .speciesName = _("STUNFISK"),
#endif
        .cryId = CRY_STUNFISK,
        .natDexNum = NATIONAL_DEX_STUNFISK,
#if GERMAN
        .categoryName = _("Falle"),
#else
        .categoryName = _("Trap"),
#endif
        .height = 7,
        .weight = 110,
        .description = COMPOUND_STRING(
#if GERMAN
        "Dank seiner dicken Haut hält es\n"
        "selbst das Gewicht eines Sumoringers aus.\n"
        "Wenn es Stromschläge verteilt, grinst es."),
#else
            "It conceals itself in the mud of the\n"
            "seashore. Then it waits. When prey touch\n"
            "it, it delivers a jolt of electricity.\n"
            "It smiles when transmitting electricity."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Stunfisk,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 14,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Stunfisk,
        .backPicSize = MON_COORDS_SIZE(64, 24),
        .backPicYOffset = 22,
        .backAnimId = BACK_ANIM_H_STRETCH,
        .palette = gMonPalette_Stunfisk,
        .shinyPalette = gMonShinyPalette_Stunfisk,
        .iconSprite = gMonIcon_Stunfisk,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -1, SHADOW_SIZE_M)
        FOOTPRINT(Stunfisk)
        OVERWORLD(
            sPicTable_Stunfisk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Stunfisk,
            gShinyOverworldPalette_Stunfisk
        )
        .levelUpLearnset = sStunfiskLevelUpLearnset,
        .teachableLearnset = sStunfiskTeachableLearnset,
        .eggMoveLearnset = sStunfiskEggMoveLearnset,
        .formSpeciesIdTable = sStunfiskFormSpeciesIdTable,
    },

#if P_GALARIAN_FORMS
    [SPECIES_STUNFISK_GALAR] =
    {
        .baseHP        = 109,
        .baseAttack    = 81,
        .baseDefense   = 99,
        .baseSpeed     = 32,
        .baseSpAttack  = 66,
        .baseSpDefense = 84,
        .types = MON_TYPES(TYPE_GROUND, TYPE_STEEL),
        .catchRate = 75,
        .expYield = 165,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS),
        .abilities = { ABILITY_MIMICRY, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Flunschlik-G"),
#else
        .speciesName = _("STUNFISK-G"),
#endif
#else
#if GERMAN
        .speciesName = _("Flunschlik"),
#else
        .speciesName = _("STUNFISK"),
#endif
#endif
        .cryId = CRY_STUNFISK,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_STUNFISK_GALAR,
#else
        .natDexNum = NATIONAL_DEX_STUNFISK,
#endif
#if GERMAN
        .categoryName = _("Falle"),
#else
        .categoryName = _("Trap"),
#endif
        .height = 7,
        .weight = 205,
        .description = COMPOUND_STRING(
#if GERMAN
        "Das Leben inmitten von stark\n"
        "eisenhaltigem Schlamm führte dazu, dass\n"
        "es einen robusten Körper aus Stahl\n"
        "entwickelte."),
#else
            "Its conspicuous lips lure prey in\n"
            "as it lies in wait in the mud. When\n"
            "prey gets close, Stunfisk clamps its\n"
            "jagged steel fins down on them."),
#endif
        .pokemonScale = 365,
        .pokemonOffset = 14,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_StunfiskGalar,
        .frontPicSize = MON_COORDS_SIZE(48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_StunfiskGalar,
        .backPicSize = MON_COORDS_SIZE(64, 24),
        .backPicYOffset = 23,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_StunfiskGalar,
        .shinyPalette = gMonShinyPalette_StunfiskGalar,
        .iconSprite = gMonIcon_StunfiskGalar,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_SLOW,
        SHADOW(0, -1, SHADOW_SIZE_M)
        FOOTPRINT(Stunfisk)
        OVERWORLD(
            sPicTable_StunfiskGalar,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_StunfiskGalar,
            gShinyOverworldPalette_StunfiskGalar
        )
        .isGalarianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sStunfiskGalarLevelUpLearnset,
        .teachableLearnset = sStunfiskGalarTeachableLearnset,
        .eggMoveLearnset = sStunfiskGalarEggMoveLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sStunfiskGalarFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sStunfiskFormSpeciesIdTable,
#endif
    },
#endif //P_GALARIAN_FORMS
#endif //P_FAMILY_STUNFISK

#if P_FAMILY_MIENFOO
    [SPECIES_MIENFOO] =
    {
        .baseHP        = 45,
        .baseAttack    = 85,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 180,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_REGENERATOR, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Lin-Fu"),
#else
        .speciesName = _("MIENFOO"),
#endif
        .cryId = CRY_MIENFOO,
        .natDexNum = NATIONAL_DEX_MIENFOO,
#if GERMAN
        .categoryName = _("Kampfkünste"),
#else
        .categoryName = _("Martial Arts"),
#endif
        .height = 9,
        .weight = 200,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schnelle Angriffe sind seine Spezialität.\n"
        "Es gleicht seine Schwächen mit der\n"
        "Vielfalt seines Attackenrepertoires aus."),
#else
            "They have mastered elegant combos.\n"
            "As they concentrate, their battle moves\n"
            "become swifter and more precise. What it\n"
            "lacks in power, it makes up for in quantity."),
#endif
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mienfoo,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Mienfoo,
        .backPicSize = MON_COORDS_SIZE(56, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        .palette = gMonPalette_Mienfoo,
        .shinyPalette = gMonShinyPalette_Mienfoo,
        .iconSprite = gMonIcon_Mienfoo,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 2, SHADOW_SIZE_S)
        FOOTPRINT(Mienfoo)
        OVERWORLD(
            sPicTable_Mienfoo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mienfoo,
            gShinyOverworldPalette_Mienfoo
        )
        .levelUpLearnset = sMienfooLevelUpLearnset,
        .teachableLearnset = sMienfooTeachableLearnset,
        .eggMoveLearnset = sMienfooEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_MIENSHAO}),
    },

    [SPECIES_MIENSHAO] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 60,
        .types = MON_TYPES(TYPE_FIGHTING),
        .catchRate = 45,
        .expYield = 179,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_REGENERATOR, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_PURPLE,
#if GERMAN
        .speciesName = _("Wie-Shu"),
#else
        .speciesName = _("MIENSHAO"),
#endif
        .cryId = CRY_MIENSHAO,
        .natDexNum = NATIONAL_DEX_MIENSHAO,
#if GERMAN
        .categoryName = _("Kampfkünste"),
#else
        .categoryName = _("Martial Arts"),
#endif
        .height = 14,
        .weight = 355,
        .description = COMPOUND_STRING(
#if GERMAN
        "Wie-Shu benutzt das Fell an seinen Armen\n"
        "als Peitsche. Beide Arme bewegen sich\n"
        "dabei mit atemberaubender\n"
        "Geschwindigkeit."),
#else
            "They use the long fur on their arms as\n"
            "a whip to strike their opponents. Its arm\n"
            "attacks come with such rapidity that they\n"
            "cannot even be seen."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mienshao,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 50),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Mienshao,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Mienshao,
        .shinyPalette = gMonShinyPalette_Mienshao,
        .iconSprite = gMonIcon_Mienshao,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_M)
        FOOTPRINT(Mienshao)
        OVERWORLD(
            sPicTable_Mienshao,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mienshao,
            gShinyOverworldPalette_Mienshao
        )
        .levelUpLearnset = sMienshaoLevelUpLearnset,
        .teachableLearnset = sMienshaoTeachableLearnset,
    },
#endif //P_FAMILY_MIENFOO

#if P_FAMILY_DRUDDIGON
    [SPECIES_DRUDDIGON] =
    {
        .baseHP        = 77,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 48,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 170,
        .evYield_Attack = 2,
        .itemRare = ITEM_DRAGON_FANG,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON, EGG_GROUP_MONSTER),
        .abilities = { ABILITY_ROUGH_SKIN, ABILITY_SHEER_FORCE, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Shardrago"),
#else
        .speciesName = _("DRUDDIGON"),
#endif
        .cryId = CRY_DRUDDIGON,
        .natDexNum = NATIONAL_DEX_DRUDDIGON,
#if GERMAN
        .categoryName = _("Höhle"),
#else
        .categoryName = _("Cave"),
#endif
        .height = 16,
        .weight = 1390,
        .description = COMPOUND_STRING(
#if GERMAN
        "Shardrago jagt durch enge Höhlengänge\n"
        "und spießt seine Gegner mit spitzen Klauen\n"
        "auf. Seine Kopfhaut ist fester als Stein."),
#else
            "It warms its body by absorbing sunlight\n"
            "with its wings. When its body temperature\n"
            "falls, it can no longer move. It uses its\n"
            "sharp claws to catch prey."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Druddigon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 22),
            ANIMCMD_FRAME(0, 11),
        ),
        .frontAnimId = ANIM_BOUNCE_ROTATE_TO_SIDES_SMALL_SLOW,
        .backPic = gMonBackPic_Druddigon,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Druddigon,
        .shinyPalette = gMonShinyPalette_Druddigon,
        .iconSprite = gMonIcon_Druddigon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 9, SHADOW_SIZE_M)
        FOOTPRINT(Druddigon)
        OVERWORLD(
            sPicTable_Druddigon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Druddigon,
            gShinyOverworldPalette_Druddigon
        )
        .levelUpLearnset = sDruddigonLevelUpLearnset,
        .teachableLearnset = sDruddigonTeachableLearnset,
        .eggMoveLearnset = sDruddigonEggMoveLearnset,
    },
#endif //P_FAMILY_DRUDDIGON

#if P_FAMILY_GOLETT
    [SPECIES_GOLETT] =
    {
        .baseHP        = 59,
        .baseAttack    = 74,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GHOST),
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack = 1,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Golbit"),
#else
        .speciesName = _("GOLETT"),
#endif
        .cryId = CRY_GOLETT,
        .natDexNum = NATIONAL_DEX_GOLETT,
#if GERMAN
        .categoryName = _("Urgolem"),
#else
        .categoryName = _("Automaton"),
#endif
        .height = 10,
        .weight = 920,
        .description = COMPOUND_STRING(
#if GERMAN
        "Golbit wird durch eine Energie angetrieben,\n"
        "die seinem Körper entspringt. Keiner weiß\n"
        "jedoch, woher diese Energie stammt."),
#else
            "These Pokémon are thought to have\n"
            "been created by the science of an\n"
            "ancient and mysterious civilization.\n"
            "It's been active for thousands of years."),
#endif
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Golett,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 44),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Golett,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Golett,
        .shinyPalette = gMonShinyPalette_Golett,
        .iconSprite = gMonIcon_Golett,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 7, SHADOW_SIZE_M)
        FOOTPRINT(Golett)
        OVERWORLD(
            sPicTable_Golett,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Golett,
            gShinyOverworldPalette_Golett
        )
        .levelUpLearnset = sGolettLevelUpLearnset,
        .teachableLearnset = sGolettTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 43, SPECIES_GOLURK}),
    },

    [SPECIES_GOLURK] =
    {
        .baseHP        = 89,
        .baseAttack    = 124,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GHOST),
        .catchRate = 90,
        .expYield = 169,
        .evYield_Attack = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Golgantes"),
#else
        .speciesName = _("GOLURK"),
#endif
        .cryId = CRY_GOLURK,
        .natDexNum = NATIONAL_DEX_GOLURK,
#if GERMAN
        .categoryName = _("Urgolem"),
#else
        .categoryName = _("Automaton"),
#endif
        .height = 28,
        .weight = 3300,
        .description = COMPOUND_STRING(
#if GERMAN
            "Man munkelt, sein Schöpfer habe ihm\n"
            "aufgetragen, schützend über Pokémon und\n"
            "Menschen zu wachen."),
#else
            "Golurk were created to protect people\n"
            "and Pokémon by an ancient civilisation.\n"
            "Removing the seal on its chest makes its\n"
            "internal energy go out of control."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 3,
        .trainerScale = 300,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Golurk,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Golurk,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Golurk,
        .shinyPalette = gMonShinyPalette_Golurk,
        .iconSprite = gMonIcon_Golurk,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 14, SHADOW_SIZE_L)
        FOOTPRINT(Golurk)
        OVERWORLD(
            sPicTable_Golurk,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Golurk,
            gShinyOverworldPalette_Golurk
        )
        .levelUpLearnset = sGolurkLevelUpLearnset,
        .teachableLearnset = sGolurkTeachableLearnset,
        .formSpeciesIdTable = sGolurkFormSpeciesIdTable,
        .formChangeTable = sGolurkFormChangeTable,
    },

#if P_GEN_9_MEGA_EVOLUTIONS
    [SPECIES_GOLURK_MEGA] =
    {
        .baseHP        = 89,
        .baseAttack    = 159,
        .baseDefense   = 105,
        .baseSpeed     = 55,
        .baseSpAttack  = 70,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_GROUND, TYPE_GHOST),
        .catchRate = 90,
        .expYield = 169,
        .evYield_Attack = 2,
        .itemRare = ITEM_LIGHT_CLAY,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_MINERAL),
        .abilities = { ABILITY_IRON_FIST, ABILITY_KLUTZ, ABILITY_NO_GUARD },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Golgantes"),
#else
        .speciesName = _("GOLURK"),
#endif
    #if P_MODIFIED_MEGA_CRIES
        .cryId = CRY_GOLURK_MEGA,
    #else
        .cryId = CRY_GOLURK,
    #endif // P_MODIFIED_MEGA_CRIES
        .natDexNum = NATIONAL_DEX_GOLURK,
#if GERMAN
        .categoryName = _("Urgolem"),
#else
        .categoryName = _("Automaton"),
#endif
        .height = 40,
        .weight = 3300,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch die Mega-Entwicklung wurde die\n"
        "Energie in seinem Körper aktiviert, sodass\n"
        "es jeden Moment zu einer Explosion kommen\n"
        "könnte."),
#else
            "The energy within Golurk has been\n"
            "stimulated by Mega Evolution.\n"
            "The Pokémon could explode at any moment."),
#endif
        .frontPic = gMonFrontPic_GolurkMega,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_GolurkMega,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_GolurkMega,
        .shinyPalette = gMonShinyPalette_GolurkMega,
        .iconSprite = gMonIcon_GolurkMega,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(Golurk)
        SHADOW(-3, 14, SHADOW_SIZE_L)
        .isMegaEvolution = TRUE,
        .levelUpLearnset = sGolurkLevelUpLearnset,
        .teachableLearnset = sGolurkTeachableLearnset,
        .formSpeciesIdTable = sGolurkFormSpeciesIdTable,
        .formChangeTable = sGolurkFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_GEN_9_MEGA_EVOLUTIONS
#endif //P_FAMILY_GOLETT

#if P_FAMILY_PAWNIARD
    [SPECIES_PAWNIARD] =
    {
        .baseHP        = 45,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = MON_TYPES(TYPE_DARK, TYPE_STEEL),
        .catchRate = 120,
        .expYield = 68,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_DEFIANT, ABILITY_INNER_FOCUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Gladiantri"),
#else
        .speciesName = _("PAWNIARD"),
#endif
        .cryId = CRY_PAWNIARD,
        .natDexNum = NATIONAL_DEX_PAWNIARD,
#if GERMAN
        .categoryName = _("Stahlklinge"),
#else
        .categoryName = _("Sharp Blade"),
#endif
        .height = 5,
        .weight = 102,
        .description = COMPOUND_STRING(
#if GERMAN
        "Gladiantris Körper ist mit Klingen übersät,\n"
        "die es an Felsen eines Flussbettes\n"
        "schärft, wenn sie im Kampf schartig\n"
        "werden."),
#else
            "Ignoring their injuries, groups attack by\n"
            "sinking the blades that cover their bodies\n"
            "into their prey. If battling dulls them, it\n"
            "sharpens them on stones by the river."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Pawniard,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_VIBRATE,
        .backPic = gMonBackPic_Pawniard,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Pawniard,
        .shinyPalette = gMonShinyPalette_Pawniard,
        .iconSprite = gMonIcon_Pawniard,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(4, 4, SHADOW_SIZE_S)
        FOOTPRINT(Pawniard)
        OVERWORLD(
            sPicTable_Pawniard,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Pawniard,
            gShinyOverworldPalette_Pawniard
        )
        .levelUpLearnset = sPawniardLevelUpLearnset,
        .teachableLearnset = sPawniardTeachableLearnset,
        .eggMoveLearnset = sPawniardEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 52, SPECIES_BISHARP}),
    },

    [SPECIES_BISHARP] =
    {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_DARK, TYPE_STEEL),
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .itemRare = ITEM_LEADERS_CREST,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_DEFIANT, ABILITY_INNER_FOCUS, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Caesurio"),
#else
        .speciesName = _("BISHARP"),
#endif
        .cryId = CRY_BISHARP,
        .natDexNum = NATIONAL_DEX_BISHARP,
#if GERMAN
        .categoryName = _("Schwertklinge"),
#else
        .categoryName = _("Sword Blade"),
#endif
        .height = 16,
        .weight = 700,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein kaltblütiges Pokémon,\n"
        "das Gegner zunächst mit einer Schar\n"
        "von Gladiantri lähmt und dann zweiteilt."),
#else
            "This pitiless Pokémon commands a group\n"
            "of Pawniard to hound prey into immobility.\n"
            "It battles to become the boss, but will be\n"
            "driven from the group if it loses."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Bisharp,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Bisharp,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Bisharp,
        .shinyPalette = gMonShinyPalette_Bisharp,
        .iconSprite = gMonIcon_Bisharp,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Bisharp)
        OVERWORLD(
            sPicTable_Bisharp,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bisharp,
            gShinyOverworldPalette_Bisharp
        )
        .levelUpLearnset = sBisharpLevelUpLearnset,
        .teachableLearnset = sBisharpTeachableLearnset,
    #if P_GEN_9_CROSS_EVOS
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_KINGS_ROCK, SPECIES_KINGAMBIT},
                                {EVO_LEVEL, 0, SPECIES_KINGAMBIT, CONDITIONS({IF_DEFEAT_X_WITH_ITEMS, SPECIES_BISHARP, ITEM_LEADERS_CREST, 3})}),
    #endif
    },

#if P_GEN_9_CROSS_EVOS
    [SPECIES_KINGAMBIT] =
    {
        .baseHP        = 100,
        .baseAttack    = 135,
        .baseDefense   = 120,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 85,
        .types = MON_TYPES(TYPE_DARK, TYPE_STEEL),
        .catchRate = 25,
        .expYield = 275,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_DEFIANT, ABILITY_SUPREME_OVERLORD, ABILITY_PRESSURE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Gladimperio"),
#else
        .speciesName = _("KINGAMBIT"),
#endif
        .cryId = CRY_KINGAMBIT,
        .natDexNum = NATIONAL_DEX_KINGAMBIT,
#if GERMAN
        .categoryName = _("Langschwert"),
#else
        .categoryName = _("Big Blade"),
#endif
        .height = 20,
        .weight = 1200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Allein das Caesurio an der Spitze seiner\n"
            "riesigen Armee kann sich zu Gladimperio\n"
            "entwickeln."),
#else
            "Though it commands a massive army\n"
            "in battle, it's not skilled at\n"
            "devising complex strategies. It just uses\n"
            "brute strength to keep pushing."),
#endif
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kingambit,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kingambit,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Kingambit,
        .shinyPalette = gMonShinyPalette_Kingambit,
        .iconSprite = gMonIcon_Kingambit,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Kingambit)
        OVERWORLD(
            sPicTable_Kingambit,
            SIZE_64x64,
            SHADOW_SIZE_L,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Kingambit,
            gShinyOverworldPalette_Kingambit
        )
        .levelUpLearnset = sKingambitLevelUpLearnset,
        .teachableLearnset = sKingambitTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_PAWNIARD

#if P_FAMILY_BOUFFALANT
    [SPECIES_BOUFFALANT] =
    {
        .baseHP        = 95,
        .baseAttack    = 110,
        .baseDefense   = 95,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 45,
        .expYield = 172,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_RECKLESS, ABILITY_SAP_SIPPER, ABILITY_SOUNDPROOF },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Bisofank"),
#else
        .speciesName = _("BOUFFALANT"),
#endif
        .cryId = CRY_BOUFFALANT,
        .natDexNum = NATIONAL_DEX_BOUFFALANT,
#if GERMAN
        .categoryName = _("Kopfstoßrind"),
#else
        .categoryName = _("Bash Buffalo"),
#endif
        .height = 16,
        .weight = 946,
        .description = COMPOUND_STRING(
#if GERMAN
        "Rammt seine Gegner ohne Rücksicht auf\n"
        "Verluste mit dem Kopf und vermag damit\n"
        "sogar Züge zum Entgleisen zu bringen."),
#else
            "Their fluffy fur absorbs damage, even\n"
            "if they strike foes with a fierce headbutt.\n"
            "Their headbutts have enough destructive\n"
            "force to derail a train."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Bouffalant,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 28),
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .backPic = gMonBackPic_Bouffalant,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Bouffalant,
        .shinyPalette = gMonShinyPalette_Bouffalant,
        .iconSprite = gMonIcon_Bouffalant,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(8, 7, SHADOW_SIZE_M)
        FOOTPRINT(Bouffalant)
        OVERWORLD(
            sPicTable_Bouffalant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Bouffalant,
            gShinyOverworldPalette_Bouffalant
        )
        .levelUpLearnset = sBouffalantLevelUpLearnset,
        .teachableLearnset = sBouffalantTeachableLearnset,
        .eggMoveLearnset = sBouffalantEggMoveLearnset,
    },
#endif //P_FAMILY_BOUFFALANT

#if P_FAMILY_RUFFLET
    [SPECIES_RUFFLET] =
    {
        .baseHP        = 70,
        .baseAttack    = 83,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = 37,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Geronimatz"),
#else
        .speciesName = _("RUFFLET"),
#endif
        .cryId = CRY_RUFFLET,
        .natDexNum = NATIONAL_DEX_RUFFLET,
#if GERMAN
        .categoryName = _("Adlerküken"),
#else
        .categoryName = _("Eaglet"),
#endif
        .height = 5,
        .weight = 105,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kann mit seinen Füßen Nüsse zermalmen. Es\n"
            "stellt sich jedem noch so starken Gegner\n"
            "tapfer zum Kampf."),
#else
            "With its sharp claws, this Pokémon pierces\n"
            "its prey, and then it pecks at them.\n"
            "Although it also consumes berries, it's a\n"
            "carnivore at heart."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Rufflet,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Rufflet,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Rufflet,
        .shinyPalette = gMonShinyPalette_Rufflet,
        .iconSprite = gMonIcon_Rufflet,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 2, SHADOW_SIZE_S)
        FOOTPRINT(Rufflet)
        OVERWORLD(
            sPicTable_Rufflet,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Rufflet,
            gShinyOverworldPalette_Rufflet
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sRuffletLevelUpLearnset,
        .teachableLearnset = sRuffletTeachableLearnset,
                            #if P_HISUIAN_FORMS
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_BRAVIARY, CONDITIONS({IF_NOT_REGION, REGION_HISUI})}
                                ,{EVO_LEVEL, 54, SPECIES_BRAVIARY_HISUI, CONDITIONS({IF_REGION, REGION_HISUI})}
                            ),
                            #else
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_BRAVIARY}),
                            #endif
    },

    [SPECIES_BRAVIARY] =
    {
        .baseHP        = 100,
        .baseAttack    = 123,
        .baseDefense   = 75,
        .baseSpeed     = 80,
        .baseSpAttack  = 57,
        .baseSpDefense = 75,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FLYING),
        .catchRate = 60,
        .expYield = 179,
        .evYield_Attack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Washakwil"),
#else
        .speciesName = _("BRAVIARY"),
#endif
        .cryId = CRY_BRAVIARY,
        .natDexNum = NATIONAL_DEX_BRAVIARY,
#if GERMAN
        .categoryName = _("Kühnheit"),
#else
        .categoryName = _("Valiant"),
#endif
        .height = 15,
        .weight = 410,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein tapferer Krieger der Lüfte, der zum\n"
            "Schutz seiner Kameraden auch mit\n"
            "Verletzungen immer weiterkämpft."),
#else
            "For the sake of its friends, this brave\n"
            "warrior of the sky will not stop battling,\n"
            "even if it is injured. One can carry a car\n"
            "while flying."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Braviary,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Braviary,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_Braviary,
        .shinyPalette = gMonShinyPalette_Braviary,
        .iconSprite = gMonIcon_Braviary,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 16, SHADOW_SIZE_M)
        FOOTPRINT(Braviary)
        OVERWORLD(
            sPicTable_Braviary,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Braviary,
            gShinyOverworldPalette_Braviary
        )
        .levelUpLearnset = sBraviaryLevelUpLearnset,
        .teachableLearnset = sBraviaryTeachableLearnset,
        .formSpeciesIdTable = sBraviaryFormSpeciesIdTable,
    },

#if P_HISUIAN_FORMS
    [SPECIES_BRAVIARY_HISUI] =
    {
        .baseHP        = 110,
        .baseAttack    = 83,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 112,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 60,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_KEEN_EYE, ABILITY_SHEER_FORCE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_WHITE,
#if P_SEPARATE_REGIONAL_FORMS
#if GERMAN
        .speciesName = _("Washakwil-H"),
#else
        .speciesName = _("BRAVIARY-H"),
#endif
#else
#if GERMAN
        .speciesName = _("Washakwil"),
#else
        .speciesName = _("BRAVIARY"),
#endif
#endif
        .cryId = CRY_BRAVIARY,
#if P_SEPARATE_REGIONAL_FORMS
        .natDexNum = NATIONAL_DEX_BRAVIARY_HISUI,
#else
        .natDexNum = NATIONAL_DEX_BRAVIARY,
#endif
#if GERMAN
        .categoryName = _("Kampfschrei"),
#else
        .categoryName = _("Battle Cry"),
#endif
        .height = 17,
        .weight = 434,
        .description = COMPOUND_STRING(
#if GERMAN
        "Mit entsetzlichem Kampfgeschrei geht\n"
        "dieses erbarmungslose Vogel-Pokémon\n"
        "auf Jagd. Es erzeugt Stoßwellen über\n"
        "Seen und ergreift die auftreibende Beute."),
#else
            "Screaming a bloodcurdling battle\n"
            "cry, this huge and ferocious bird\n"
            "Pokémon goes out on the hunt."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_BraviaryHisui,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_BraviaryHisui,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_BraviaryHisui,
        .shinyPalette = gMonShinyPalette_BraviaryHisui,
        .iconSprite = gMonIcon_BraviaryHisui,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 14, SHADOW_SIZE_M)
        FOOTPRINT(Braviary)
        OVERWORLD(
            sPicTable_BraviaryHisui,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_BraviaryHisui,
            gShinyOverworldPalette_BraviaryHisui
        )
        .isHisuianForm = TRUE,
        .dexNotRequired = TRUE,
        .levelUpLearnset = sBraviaryHisuiLevelUpLearnset,
        .teachableLearnset = sBraviaryHisuiTeachableLearnset,
#if P_SEPARATE_REGIONAL_FORMS
        .formSpeciesIdTable = sBraviaryHisuiFormSpeciesIdTable,
#else
        .formSpeciesIdTable = sBraviaryFormSpeciesIdTable,
#endif
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_RUFFLET

#if P_FAMILY_VULLABY
    [SPECIES_VULLABY] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 190,
        .expYield = 74,
        .evYield_Defense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_BIG_PECKS, ABILITY_OVERCOAT, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Skallyk"),
#else
        .speciesName = _("VULLABY"),
#endif
        .cryId = CRY_VULLABY,
        .natDexNum = NATIONAL_DEX_VULLABY,
#if GERMAN
        .categoryName = _("Windel"),
#else
        .categoryName = _("Diapered"),
#endif
        .height = 5,
        .weight = 90,
        .description = COMPOUND_STRING(
#if GERMAN
        "Skallyks Flügel sind noch zu\n"
        "klein zum Fliegen. Kurz bevor es sich ent-\n"
        "wickelt, wirft es seine Schädelwindel ab."),
#else
            "It can't fly yet and must wait until its\n"
            "wings have developed more. They guard\n"
            "their posteriors with bones that were\n"
            "gathered by Mandibuzz."),
#endif
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Vullaby,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Vullaby,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Vullaby,
        .shinyPalette = gMonShinyPalette_Vullaby,
        .iconSprite = gMonIcon_Vullaby,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 9, SHADOW_SIZE_M)
        FOOTPRINT(Vullaby)
        OVERWORLD(
            sPicTable_Vullaby,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Vullaby,
            gShinyOverworldPalette_Vullaby
        )
        .isSkyBattleBanned = B_SKY_BATTLE_STRICT_ELIGIBILITY,
        .levelUpLearnset = sVullabyLevelUpLearnset,
        .teachableLearnset = sVullabyTeachableLearnset,
        .eggMoveLearnset = sVullabyEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 54, SPECIES_MANDIBUZZ}),
    },

    [SPECIES_MANDIBUZZ] =
    {
        .baseHP        = 110,
        .baseAttack    = 65,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 55,
        .baseSpDefense = 95,
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 60,
        .expYield = 179,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FLYING),
        .abilities = { ABILITY_BIG_PECKS, ABILITY_OVERCOAT, ABILITY_WEAK_ARMOR },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Grypheldis"),
#else
        .speciesName = _("MANDIBUZZ"),
#endif
        .cryId = CRY_MANDIBUZZ,
        .natDexNum = NATIONAL_DEX_MANDIBUZZ,
#if GERMAN
        .categoryName = _("Knochenadler"),
#else
        .categoryName = _("Bone Vulture"),
#endif
        .height = 12,
        .weight = 395,
        .description = COMPOUND_STRING(
#if GERMAN
        "Grypheldis kreist am Himmel, bis\n"
        "es seine Beute findet. Nach erfolgtem An-\n"
        "griff trägt es sie mühelos zu seinem Nest."),
#else
            "They adorn themselves beautifully with\n"
            "bones. This is supposedly an effort to\n"
            "attract males, but no male Mandibuzz\n"
            "have ever been found."),
#endif
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mandibuzz,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Mandibuzz,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_Mandibuzz,
        .shinyPalette = gMonShinyPalette_Mandibuzz,
        .iconSprite = gMonIcon_Mandibuzz,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Mandibuzz)
        OVERWORLD(
            sPicTable_Mandibuzz,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mandibuzz,
            gShinyOverworldPalette_Mandibuzz
        )
        .levelUpLearnset = sMandibuzzLevelUpLearnset,
        .teachableLearnset = sMandibuzzTeachableLearnset,
    },
#endif //P_FAMILY_VULLABY

#if P_FAMILY_HEATMOR
    [SPECIES_HEATMOR] =
    {
        .baseHP        = 85,
        .baseAttack    = 97,
        .baseDefense   = 66,
        .baseSpeed     = 65,
        .baseSpAttack  = 105,
        .baseSpDefense = 66,
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 90,
        .expYield = 169,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_FIELD),
        .abilities = { ABILITY_GLUTTONY, ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE },
        .bodyColor = BODY_COLOR_RED,
#if GERMAN
        .speciesName = _("Furnifraß"),
#else
        .speciesName = _("HEATMOR"),
#endif
        .cryId = CRY_HEATMOR,
        .natDexNum = NATIONAL_DEX_HEATMOR,
#if GERMAN
        .categoryName = _("Ameisenbär"),
#else
        .categoryName = _("Anteater"),
#endif
        .height = 14,
        .weight = 580,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mit seiner brandheißen Zunge bringt es\n"
            "Fermicula zum Schmelzen, um so an sein\n"
            "weiches Inneres zu gelangen."),
#else
            "It draws in air through its tail,\n"
            "transforms it into fire, and uses it like\n"
            "a tongue. They burn through Durant's steel\n"
            "bodies and consume their insides."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Heatmor,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Heatmor,
        .backPicSize = MON_COORDS_SIZE(64, 24),
        .backPicYOffset = 21,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        .palette = gMonPalette_Heatmor,
        .shinyPalette = gMonShinyPalette_Heatmor,
        .iconSprite = gMonIcon_Heatmor,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 7, SHADOW_SIZE_L)
        FOOTPRINT(Heatmor)
        OVERWORLD(
            sPicTable_Heatmor,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Heatmor,
            gShinyOverworldPalette_Heatmor
        )
        .levelUpLearnset = sHeatmorLevelUpLearnset,
        .teachableLearnset = sHeatmorTeachableLearnset,
        .eggMoveLearnset = sHeatmorEggMoveLearnset,
    },
#endif //P_FAMILY_HEATMOR

#if P_FAMILY_DURANT
    [SPECIES_DURANT] =
    {
        .baseHP        = 58,
        .baseAttack    = 109,
        .baseDefense   = 112,
        .baseSpeed     = 109,
        .baseSpAttack  = 48,
        .baseSpDefense = 48,
        .types = MON_TYPES(TYPE_BUG, TYPE_STEEL),
        .catchRate = 90,
        .expYield = 169,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_SWARM, ABILITY_HUSTLE, ABILITY_TRUANT },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Fermicula"),
#else
        .speciesName = _("DURANT"),
#endif
        .cryId = CRY_DURANT,
        .natDexNum = NATIONAL_DEX_DURANT,
#if GERMAN
        .categoryName = _("Eisenameise"),
#else
        .categoryName = _("Iron Ant"),
#endif
        .height = 3,
        .weight = 330,
        .description = COMPOUND_STRING(
#if GERMAN
        "Eine ausgeklügelte Rollenverteilung\n"
        "hilft ihnen dabei, ihren natürlichen\n"
        "Feind Furnifraß aus dem Nest zu verjagen."),
#else
            "Durant dig nests in mountains.\n"
            "Individuals each play different roles in\n"
            "driving Heatmor, their natural predator,\n"
            "away from their colony."),
#endif
        .pokemonScale = 530,
        .pokemonOffset = 19,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Durant,
        .frontPicSize = MON_COORDS_SIZE(48, 32),
        .frontPicYOffset = 17,
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
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_RAPID_H_HOPS,
        .backPic = gMonBackPic_Durant,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = 17,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Durant,
        .shinyPalette = gMonShinyPalette_Durant,
        .iconSprite = gMonIcon_Durant,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_FAST,
        SHADOW(0, -3, SHADOW_SIZE_L)
        FOOTPRINT(Durant)
        OVERWORLD(
            sPicTable_Durant,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Durant,
            gShinyOverworldPalette_Durant
        )
        .levelUpLearnset = sDurantLevelUpLearnset,
        .teachableLearnset = sDurantTeachableLearnset,
        .eggMoveLearnset = sDurantEggMoveLearnset,
    },
#endif //P_FAMILY_DURANT

#if P_FAMILY_DEINO
    [SPECIES_DEINO] =
    {
        .baseHP        = 52,
        .baseAttack    = 65,
        .baseDefense   = 50,
        .baseSpeed     = 38,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        .types = MON_TYPES(TYPE_DARK, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kapuno"),
#else
        .speciesName = _("DEINO"),
#endif
        .cryId = CRY_DEINO,
        .natDexNum = NATIONAL_DEX_DEINO,
#if GERMAN
        .categoryName = _("Haudrauf"),
#else
        .categoryName = _("Irate"),
#endif
        .height = 8,
        .weight = 173,
        .description = COMPOUND_STRING(
#if GERMAN
        "Da es nichts sehen kann, sucht es seine\n"
        "Umgebung mit Rempel- und Bissattacken\n"
        "ab und ist immer mit Wunden übersät."),
#else
            "Lacking sight, it's unaware of its\n"
            "surroundings, so it bumps into things and\n"
            "eats anything that moves. Approaching\n"
            "it carelessly is dangerous."),
#endif
        .pokemonScale = 366,
        .pokemonOffset = 12,
        .trainerScale = 257,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Deino,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Deino,
        .backPicSize = MON_COORDS_SIZE(48, 48),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Deino,
        .shinyPalette = gMonShinyPalette_Deino,
        .iconSprite = gMonIcon_Deino,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 3, SHADOW_SIZE_S)
        FOOTPRINT(Deino)
        OVERWORLD(
            sPicTable_Deino,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Deino,
            gShinyOverworldPalette_Deino
        )
        .levelUpLearnset = sDeinoLevelUpLearnset,
        .teachableLearnset = sDeinoTeachableLearnset,
        .eggMoveLearnset = sDeinoEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_ZWEILOUS}),
    },

    [SPECIES_ZWEILOUS] =
    {
        .baseHP        = 72,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        .types = MON_TYPES(TYPE_DARK, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_HUSTLE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Duodino"),
#else
        .speciesName = _("ZWEILOUS"),
#endif
        .cryId = CRY_ZWEILOUS,
        .natDexNum = NATIONAL_DEX_ZWEILOUS,
#if GERMAN
        .categoryName = _("Grobheit"),
#else
        .categoryName = _("Hostile"),
#endif
        .height = 14,
        .weight = 500,
        .description = COMPOUND_STRING(
#if GERMAN
        "Duodinos zwei Köpfe sind sich spinnefeind.\n"
        "Beide versuchen, über Fresswettbewerbe\n"
        "die Oberhand zu gewinnen."),
#else
            "After it has eaten up all the food in its\n"
            "territory, it moves on to another area.\n"
            "Whichever head eats more than the other\n"
            "gets to be the leader."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 3,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Zweilous,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_H_STRETCH,
        .backPic = gMonBackPic_Zweilous,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Zweilous,
        .shinyPalette = gMonShinyPalette_Zweilous,
        .iconSprite = gMonIcon_Zweilous,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 6, SHADOW_SIZE_L)
        FOOTPRINT(Zweilous)
        OVERWORLD(
            sPicTable_Zweilous,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zweilous,
            gShinyOverworldPalette_Zweilous
        )
        .levelUpLearnset = sZweilousLevelUpLearnset,
        .teachableLearnset = sZweilousTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 64, SPECIES_HYDREIGON}),
    },

    [SPECIES_HYDREIGON] =
    {
        .baseHP        = 92,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 98,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DARK, TYPE_DRAGON),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_DRAGON),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Trikephalo"),
#else
        .speciesName = _("HYDREIGON"),
#endif
        .cryId = CRY_HYDREIGON,
        .natDexNum = NATIONAL_DEX_HYDREIGON,
        .categoryName = _("Brutal"),
        .height = 18,
        .weight = 1600,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Köpfe an seinen beiden Armen\n"
        "haben kein eigenes Gehirn. Seine drei\n"
        "Mäuler kauen alles radikal kurz und klein."),
#else
            "This brutal Pokémon travels the skies on\n"
            "its six wings. The heads on their arms do\n"
            "not have brains. They use all three heads\n"
            "to consume and destroy everything."),
#endif
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Hydreigon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
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
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_Hydreigon,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Hydreigon,
        .shinyPalette = gMonShinyPalette_Hydreigon,
        .iconSprite = gMonIcon_Hydreigon,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 16, SHADOW_SIZE_M)
        FOOTPRINT(Hydreigon)
        OVERWORLD(
            sPicTable_Hydreigon,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Hydreigon,
            gShinyOverworldPalette_Hydreigon
        )
        .levelUpLearnset = sHydreigonLevelUpLearnset,
        .teachableLearnset = sHydreigonTeachableLearnset,
    },
#endif //P_FAMILY_DEINO

#if P_FAMILY_LARVESTA
    [SPECIES_LARVESTA] =
    {
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        .baseSpDefense = 55,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIRE),
        .catchRate = 45,
        .expYield = 72,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Ignivor"),
#else
        .speciesName = _("LARVESTA"),
#endif
        .cryId = CRY_LARVESTA,
        .natDexNum = NATIONAL_DEX_LARVESTA,
#if GERMAN
        .categoryName = _("Fackel"),
#else
        .categoryName = _("Torch"),
#endif
        .height = 11,
        .weight = 288,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es heißt, es sei ein Produkt der Sonne.\n"
        "Wenn es sich entwickelt, hüllt es sich in\n"
        "Flammen, die es aus seinen Hörnern bläst."),
#else
            "This Pokémon was believed to have\n"
            "been born from the sun. It spews fire from\n"
            "its horns and encases itself in a cocoon\n"
            "of fire when it evolves."),
#endif
        .pokemonScale = 320,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Larvesta,
        .frontPicSize = MON_COORDS_SIZE(40, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_GLOW_ORANGE,
        .backPic = gMonBackPic_Larvesta,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        .palette = gMonPalette_Larvesta,
        .shinyPalette = gMonShinyPalette_Larvesta,
        .iconSprite = gMonIcon_Larvesta,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 0, SHADOW_SIZE_S)
        FOOTPRINT(Larvesta)
        OVERWORLD(
            sPicTable_Larvesta,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Larvesta,
            gShinyOverworldPalette_Larvesta
        )
        .levelUpLearnset = sLarvestaLevelUpLearnset,
        .teachableLearnset = sLarvestaTeachableLearnset,
        .eggMoveLearnset = sLarvestaEggMoveLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 59, SPECIES_VOLCARONA}),
    },

    [SPECIES_VOLCARONA] =
    {
        .baseHP        = 85,
        .baseAttack    = 60,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 135,
        .baseSpDefense = 105,
        .types = MON_TYPES(TYPE_BUG, TYPE_FIRE),
        .catchRate = 15,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 275 : 248,
        .evYield_SpAttack = 3,
        .itemCommon = ITEM_SILVER_POWDER,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_BUG),
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_SWARM },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Ramoth"),
#else
        .speciesName = _("VOLCARONA"),
#endif
        .cryId = CRY_VOLCARONA,
        .natDexNum = NATIONAL_DEX_VOLCARONA,
#if GERMAN
        .categoryName = _("Sonne"),
#else
        .categoryName = _("Sun"),
#endif
        .height = 16,
        .weight = 460,
        .description = COMPOUND_STRING(
#if GERMAN
        "Schüttelt sich glühenden Staub aus\n"
        "seinen sechs Flügeln und verwandelt das\n"
        "Umfeld in ein einziges Meer aus Flammen."),
#else
            "When volcanic ash darkened the\n"
            "atmosphere, it appeared and saved Pokémon\n"
            "from freezing, Volcarona's fire provided a\n"
            "replacement for the sun."),
#endif
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Volcarona,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 25),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Volcarona,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Volcarona,
        .shinyPalette = gMonShinyPalette_Volcarona,
        .iconSprite = gMonIcon_Volcarona,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 14, SHADOW_SIZE_M)
        FOOTPRINT(Volcarona)
        OVERWORLD(
            sPicTable_Volcarona,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Volcarona,
            gShinyOverworldPalette_Volcarona
        )
        .levelUpLearnset = sVolcaronaLevelUpLearnset,
        .teachableLearnset = sVolcaronaTeachableLearnset,
    },
#endif //P_FAMILY_LARVESTA

#if P_FAMILY_COBALION
    [SPECIES_COBALION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 129,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 72,
        .types = MON_TYPES(TYPE_STEEL, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Kobalium"),
#else
        .speciesName = _("COBALION"),
#endif
        .cryId = CRY_COBALION,
        .natDexNum = NATIONAL_DEX_COBALION,
#if GERMAN
        .categoryName = _("Eisenkern"),
#else
        .categoryName = _("Iron Will"),
#endif
        .height = 21,
        .weight = 2500,
        .description = COMPOUND_STRING(
#if GERMAN
        "Kobaliums Körper und sein Herz sind aus\n"
        "Stahl. Ein böser Blick genügt und selbst\n"
        "die wildesten Pokémon unterwerfen sich\n"
        "ihm."),
#else
            "It has a body and heart of steel. This\n"
            "legendary Pokémon battled against humans\n"
            "to protect Pokémon. Its personality\n"
            "is calm and composed."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Cobalion,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Cobalion,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Cobalion,
        .shinyPalette = gMonShinyPalette_Cobalion,
        .iconSprite = gMonIcon_Cobalion,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cobalion)
        OVERWORLD(
            sPicTable_Cobalion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cobalion,
            gShinyOverworldPalette_Cobalion
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sCobalionLevelUpLearnset,
        .teachableLearnset = sCobalionTeachableLearnset,
    },
#endif //P_FAMILY_COBALION

#if P_FAMILY_TERRAKION
    [SPECIES_TERRAKION] =
    {
        .baseHP        = 91,
        .baseAttack    = 129,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 72,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
#if GERMAN
        .speciesName = _("Terrakium"),
#else
        .speciesName = _("TERRAKION"),
#endif
        .cryId = CRY_TERRAKION,
        .natDexNum = NATIONAL_DEX_TERRAKION,
#if GERMAN
        .categoryName = _("Felsenhöhle"),
#else
        .categoryName = _("Cavern"),
#endif
        .height = 19,
        .weight = 2600,
        .description = COMPOUND_STRING(
#if GERMAN
        "Terrakiums Angriffskraft genügt,\n"
        "um selbst mächtige Wälle niederzureißen.\n"
        "Ein Held zahlreicher Legenden."),
#else
            "Spoken of in legend, this Pokémon used\n"
            "its phenomenal power to destroy a castle\n"
            "in its effort to protect Pokémon that had\n"
            "lost their homes in a war among humans."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 336,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Terrakion,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Terrakion,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Terrakion,
        .shinyPalette = gMonShinyPalette_Terrakion,
        .iconSprite = gMonIcon_Terrakion,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 6, SHADOW_SIZE_L)
        FOOTPRINT(Terrakion)
        OVERWORLD(
            sPicTable_Terrakion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Terrakion,
            gShinyOverworldPalette_Terrakion
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTerrakionLevelUpLearnset,
        .teachableLearnset = sTerrakionTeachableLearnset,
    },
#endif //P_FAMILY_TERRAKION

#if P_FAMILY_VIRIZION
    [SPECIES_VIRIZION] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 72,
        .baseSpeed     = 108,
        .baseSpAttack  = 90,
        .baseSpDefense = 129,
        .types = MON_TYPES(TYPE_GRASS, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Viridium"),
#else
        .speciesName = _("VIRIZION"),
#endif
        .cryId = CRY_VIRIZION,
        .natDexNum = NATIONAL_DEX_VIRIZION,
#if GERMAN
        .categoryName = _("Wiese"),
#else
        .categoryName = _("Grassland"),
#endif
        .height = 20,
        .weight = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Das Horn an seinem Kopf ist eine scharfe\n"
            "Klinge. Neckt seine Gegner mit quirligen\n"
            "Bewegungen und greift blitzartig an."),
#else
            "Its head sprouts horns as sharp as blades.\n"
            "Legends say this Pokémon used\n"
            "whirlwind-like movements to confound\n"
            "and swiftly cut its opponents."),
#endif
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 344,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Virizion,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Virizion,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Virizion,
        .shinyPalette = gMonShinyPalette_Virizion,
        .iconSprite = gMonIcon_Virizion,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Virizion)
        OVERWORLD(
            sPicTable_Virizion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Virizion,
            gShinyOverworldPalette_Virizion
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sVirizionLevelUpLearnset,
        .teachableLearnset = sVirizionTeachableLearnset,
    },
#endif //P_FAMILY_VIRIZION

#if P_FAMILY_TORNADUS
    [SPECIES_TORNADUS_INCARNATE] =
    {
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Boreos"),
#else
        .speciesName = _("TORNADUS"),
#endif
        .cryId = CRY_TORNADUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_TORNADUS,
#if GERMAN
        .categoryName = _("Wirbelsturm"),
#else
        .categoryName = _("Cyclone"),
#endif
        .height = 15,
        .weight = 630,
        .description = COMPOUND_STRING(
#if GERMAN
        "Boreos' Unterkörper ist in eine\n"
        "wolkenartige Energieschicht gehüllt. Es\n"
        "jagt mit bis zu 300 km/h durch die Lüfte."),
#else
            "Tornadus expels massive energy from\n"
            "its tail, causing severe storms.\n"
            "Its power can blow entire houses away.\n"
            "It zooms through the sky at 200 mph."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TornadusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
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
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_TornadusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_TornadusIncarnate,
        .shinyPalette = gMonShinyPalette_TornadusIncarnate,
        .iconSprite = gMonIcon_TornadusIncarnate,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Tornadus)
        OVERWORLD(
            sPicTable_TornadusIncarnate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_TornadusIncarnate,
            gShinyOverworldPalette_TornadusIncarnate
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTornadusLevelUpLearnset,
        .teachableLearnset = sTornadusTeachableLearnset,
        .formSpeciesIdTable = sTornadusFormSpeciesIdTable,
        .formChangeTable = sTornadusFormChangeTable,
    },

    [SPECIES_TORNADUS_THERIAN] =
    {
        .baseHP        = 79,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 121,
        .baseSpAttack  = 110,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_REGENERATOR, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
#if GERMAN
        .speciesName = _("Boreos"),
#else
        .speciesName = _("TORNADUS"),
#endif
        .cryId = CRY_TORNADUS_THERIAN,
        .natDexNum = NATIONAL_DEX_TORNADUS,
#if GERMAN
        .categoryName = _("Wirbelsturm"),
#else
        .categoryName = _("Cyclone"),
#endif
        .height = 14,
        .weight = 630,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Beispiel für das Phänomen des\n"
            "Formwandels. Diese seltsame vogelähnliche\n"
            "Gestalt, die über dem Meer gesichtet\n"
            "wurde, ist wohl sein wahres Antlitz."),
#else
            "An example of what is known as a\n"
            "“form change”. Tornadus has been\n"
            "sighted crossing the ocean while in this\n"
            "form."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TornadusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_TornadusTherian,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_TornadusTherian,
        .shinyPalette = gMonShinyPalette_TornadusTherian,
        .iconSprite = gMonIcon_TornadusTherian,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_L)
        FOOTPRINT(Tornadus)
        OVERWORLD(
            sPicTable_TornadusTherian,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TornadusTherian,
            gShinyOverworldPalette_TornadusTherian
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sTornadusLevelUpLearnset,
        .teachableLearnset = sTornadusTeachableLearnset,
        .formSpeciesIdTable = sTornadusFormSpeciesIdTable,
        .formChangeTable = sTornadusFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_TORNADUS

#if P_FAMILY_THUNDURUS
    [SPECIES_THUNDURUS_INCARNATE] =
    {
        .baseHP        = 79,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 111,
        .baseSpAttack  = 125,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Voltolos"),
#else
        .speciesName = _("THUNDURUS"),
#endif
        .cryId = CRY_THUNDURUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_THUNDURUS,
#if GERMAN
        .categoryName = _("Torpedo"),
#else
        .categoryName = _("Bolt Strike"),
#endif
        .height = 15,
        .weight = 610,
        .description = COMPOUND_STRING(
#if GERMAN
        "Voltolos ist bei den Leuten verhasst, weil\n"
        "es auf seinen Rundflügen immer wieder\n"
        "Blitze erzeugt, die Waldbrände\n"
        "verursachen."),
#else
            "The spikes on its tail discharge immense\n"
            "bolts of lightning. Countless charred\n"
            "remains mar the landscape of places\n"
            "through which Thundurus has passed."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ThundurusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
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
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_ThundurusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_ThundurusIncarnate,
        .shinyPalette = gMonShinyPalette_ThundurusIncarnate,
        .iconSprite = gMonIcon_ThundurusIncarnate,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Thundurus)
        OVERWORLD(
            sPicTable_ThundurusIncarnate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_ThundurusIncarnate,
            gShinyOverworldPalette_ThundurusIncarnate
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sThundurusLevelUpLearnset,
        .teachableLearnset = sThundurusTeachableLearnset,
        .formSpeciesIdTable = sThundurusFormSpeciesIdTable,
        .formChangeTable = sThundurusFormChangeTable,
    },

    [SPECIES_THUNDURUS_THERIAN] =
    {
        .baseHP        = 79,
        .baseAttack    = 105,
        .baseDefense   = 70,
        .baseSpeed     = 101,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NONE, ABILITY_VOLT_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
#if GERMAN
        .speciesName = _("Voltolos"),
#else
        .speciesName = _("THUNDURUS"),
#endif
        .cryId = CRY_THUNDURUS_THERIAN,
        .natDexNum = NATIONAL_DEX_THUNDURUS,
#if GERMAN
        .categoryName = _("Torpedo"),
#else
        .categoryName = _("Bolt Strike"),
#endif
        .height = 30,
        .weight = 610,
        .description = COMPOUND_STRING(
#if GERMAN
        "Es erscheint aus dem Nichts mit der Wucht\n"
        "von Blitz und Donner und pulverisiert\n"
        "Feinde mit Blitzen aus den Kugeln an seiner\n"
        "Rute."),
#else
            "It pulverizes foes into nothingness\n"
            "with showers of devastatingly\n"
            "powerful lightning bolts launched\n"
            "from the string of orbs on its tail."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ThundurusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
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
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_ThundurusTherian,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_ThundurusTherian,
        .shinyPalette = gMonShinyPalette_ThundurusTherian,
        .iconSprite = gMonIcon_ThundurusTherian,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 16, SHADOW_SIZE_M)
        FOOTPRINT(Thundurus)
        OVERWORLD(
            sPicTable_ThundurusTherian,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ThundurusTherian,
            gShinyOverworldPalette_ThundurusTherian
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sThundurusLevelUpLearnset,
        .teachableLearnset = sThundurusTeachableLearnset,
        .formSpeciesIdTable = sThundurusFormSpeciesIdTable,
        .formChangeTable = sThundurusFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_THUNDURUS

#if P_FAMILY_RESHIRAM
    [SPECIES_RESHIRAM] =
    {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FIRE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
#if GERMAN
        .speciesName = _("Reshiram"),
#else
        .speciesName = _("RESHIRAM"),
#endif
        .cryId = CRY_RESHIRAM,
        .natDexNum = NATIONAL_DEX_RESHIRAM,
#if GERMAN
        .categoryName = _("Wahres Weiß"),
#else
        .categoryName = _("Vast White"),
#endif
        .height = 32,
        .weight = 3300,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein Legendäres Pokémon mit der Macht,\n"
        "die Welt mit seinen Flammen einzuäschern.\n"
        "Hilft allen, die nach Wirklichkeit streben."),
#else
            "This Pokémon appears in legends. It\n"
            "sends flames into the air from its tail,\n"
            "burning up everything around it. It helps\n"
            "those who want to build a world of truth."),
#endif
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 445,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Reshiram,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Reshiram,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Reshiram,
        .shinyPalette = gMonShinyPalette_Reshiram,
        .iconSprite = gMonIcon_Reshiram,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_L)
        FOOTPRINT(Reshiram)
        OVERWORLD(
            sPicTable_Reshiram,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Reshiram,
            gShinyOverworldPalette_Reshiram
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sReshiramLevelUpLearnset,
        .teachableLearnset = sReshiramTeachableLearnset,
    },
#endif //P_FAMILY_RESHIRAM

#if P_FAMILY_ZEKROM
    [SPECIES_ZEKROM] =
    {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ELECTRIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
#if GERMAN
        .speciesName = _("Zekrom"),
#else
        .speciesName = _("ZEKROM"),
#endif
        .cryId = CRY_ZEKROM,
        .natDexNum = NATIONAL_DEX_ZEKROM,
#if GERMAN
        .categoryName = _("Reines Schwarz"),
#else
        .categoryName = _("Deep Black"),
#endif
        .height = 29,
        .weight = 3450,
        .description = COMPOUND_STRING(
#if GERMAN
        "Ein Legendäres Pokémon mit der Macht,\n"
        "die Welt durch Donner einzuäschern. Hilft\n"
        "allen, die einer Welt der Wünsche harren."),
#else
            "This legendary Pokémon can scorch the\n"
            "world with lightning. It has a generator\n"
            "that creates electricity in its tail. It\n"
            "assists those with strong ideals."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 2,
        .trainerScale = 412,
        .trainerOffset = 10,
        .frontPic = gMonFrontPic_Zekrom,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Zekrom,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Zekrom,
        .shinyPalette = gMonShinyPalette_Zekrom,
        .iconSprite = gMonIcon_Zekrom,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_L)
        FOOTPRINT(Zekrom)
        OVERWORLD(
            sPicTable_Zekrom,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zekrom,
            gShinyOverworldPalette_Zekrom
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sZekromLevelUpLearnset,
        .teachableLearnset = sZekromTeachableLearnset,
    },
#endif //P_FAMILY_ZEKROM

#if P_FAMILY_LANDORUS
    [SPECIES_LANDORUS_INCARNATE] =
    {
        .baseHP        = 89,
        .baseAttack    = 125,
        .baseDefense   = 90,
        .baseSpeed     = 101,
        .baseSpAttack  = 115,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SAND_FORCE, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Demeteros"),
#else
        .speciesName = _("LANDORUS"),
#endif
        .cryId = CRY_LANDORUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_LANDORUS,
#if GERMAN
        .categoryName = _("Reichtum"),
#else
        .categoryName = _("Abundance"),
#endif
        .height = 15,
        .weight = 680,
        .description = COMPOUND_STRING(
#if GERMAN
        "Da an Orten, wo es sich blicken lässt,\n"
        "mit reicher Ernte zu rechnen ist, nennt\n"
        "man es auch den “Herrn des Ackerbaus“."),
#else
            "The energy that comes pouring from its\n"
            "tail increases the nutrition in the soil,\n"
            "granting bountiful crops. It has been\n"
            "hailed as “The Guardian of the Fields.”"),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LandorusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
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
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_LandorusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_LandorusIncarnate,
        .shinyPalette = gMonShinyPalette_LandorusIncarnate,
        .iconSprite = gMonIcon_LandorusIncarnate,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Landorus)
        OVERWORLD(
            sPicTable_LandorusIncarnate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_LandorusIncarnate,
            gShinyOverworldPalette_LandorusIncarnate
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLandorusLevelUpLearnset,
        .teachableLearnset = sLandorusTeachableLearnset,
        .formSpeciesIdTable = sLandorusFormSpeciesIdTable,
        .formChangeTable = sLandorusFormChangeTable,
    },

    [SPECIES_LANDORUS_THERIAN] =
    {
        .baseHP        = 89,
        .baseAttack    = 145,
        .baseDefense   = 90,
        .baseSpeed     = 91,
        .baseSpAttack  = 105,
        .baseSpDefense = 80,
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
#if GERMAN
        .speciesName = _("Demeteros"),
#else
        .speciesName = _("LANDORUS"),
#endif
        .cryId = CRY_LANDORUS_THERIAN,
        .natDexNum = NATIONAL_DEX_LANDORUS,
#if GERMAN
        .categoryName = _("Reichtum"),
#else
        .categoryName = _("Abundance"),
#endif
        .height = 13,
        .weight = 680,
        .description = COMPOUND_STRING(
#if GERMAN
        "Die Menschen verehren es, da es das Land\n"
        "mit Fruchtbarkeit segnet, während es in\n"
        "seiner Tiergeistform durch die Lüfte\n"
        "gleitet."),
#else
            "Landorus soars through the sky in\n"
            "this form, bestowing plentiful\n"
            "harvests upon the land and earning the\n"
            "people's reverence."),
#endif
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LandorusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .backPic = gMonBackPic_LandorusTherian,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_LandorusTherian,
        .shinyPalette = gMonShinyPalette_LandorusTherian,
        .iconSprite = gMonIcon_LandorusTherian,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Landorus)
        OVERWORLD(
            sPicTable_LandorusTherian,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_LandorusTherian,
            gShinyOverworldPalette_LandorusTherian
        )
        .isSubLegendary = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sLandorusLevelUpLearnset,
        .teachableLearnset = sLandorusTeachableLearnset,
        .formSpeciesIdTable = sLandorusFormSpeciesIdTable,
        .formChangeTable = sLandorusFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_LANDORUS

#if P_FAMILY_KYUREM
    [SPECIES_KYUREM] =
    {
        .baseHP        = 125,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 330 : 297,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Kyurem"),
#else
        .speciesName = _("KYUREM"),
#endif
        .cryId = CRY_KYUREM,
        .natDexNum = NATIONAL_DEX_KYUREM,
#if GERMAN
        .categoryName = _("Schwelle"),
#else
        .categoryName = _("Boundary"),
#endif
        .height = 30,
        .weight = 3250,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Legendäres Eis-Pokémon, das auf den\n"
            "Helden wartet, der seinen verstümmelten\n"
            "Körper mit Wunsch und Wirklichkeit heilt."),
#else
            "This legendary ice Pokémon waits for a\n"
            "hero to fill in the missing parts of its\n"
            "body with truth or ideals. Its body became\n"
            "frozen when its energy leaked out."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kyurem,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kyurem,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Kyurem,
        .shinyPalette = gMonShinyPalette_Kyurem,
        .iconSprite = gMonIcon_Kyurem,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_L)
        FOOTPRINT(Kyurem)
        OVERWORLD(
            sPicTable_Kyurem,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kyurem,
            gShinyOverworldPalette_Kyurem
        )
        .isRestrictedLegendary = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKyuremLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .formSpeciesIdTable = sKyuremFormSpeciesIdTable,
    },

#if P_FUSION_FORMS
    [SPECIES_KYUREM_WHITE] =
    {
        .baseHP        = 125,
        .baseAttack    = 120,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 170,
        .baseSpDefense = 100,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Kyurem"),
#else
        .speciesName = _("KYUREM"),
#endif
        .cryId = CRY_KYUREM_WHITE,
        .natDexNum = NATIONAL_DEX_KYUREM,
#if GERMAN
        .categoryName = _("Schwelle"),
#else
        .categoryName = _("Boundary"),
#endif
        .height = 36,
        .weight = 3250,
        .description = COMPOUND_STRING(
#if GERMAN
        "Nachdem es Reshiram, das über identische\n"
        "Gene verfügt, absorbiert hat, kann es nun\n"
        "sowohl Feuer- als auch Eis-Energie\n"
        "einsetzen."),
#else
            "The sameness of Reshiram's and\n"
            "Kyurem's genes allowed Kyurem to\n"
            "absorb Reshiram. Kyurem can now use the\n"
            "power of both fire and ice."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KyuremWhite,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_KyuremWhite,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_KyuremWhite,
        .shinyPalette = gMonShinyPalette_KyuremWhite,
        .iconSprite = gMonIcon_KyuremWhite,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-8, 14, SHADOW_SIZE_L)
        FOOTPRINT(Kyurem)
        OVERWORLD(
            sPicTable_KyuremWhite,
            SIZE_32x32, //TODO: 64x64 overworld sprite!
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_KyuremWhite,
            gShinyOverworldPalette_KyuremWhite
        )
        .isRestrictedLegendary = TRUE,
        .cannotBeTraded = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKyuremWhiteLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .formSpeciesIdTable = sKyuremFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },

    [SPECIES_KYUREM_BLACK] =
    {
        .baseHP        = 125,
        .baseAttack    = 170,
        .baseDefense   = 100,
        .baseSpeed     = 95,
        .baseSpAttack  = 120,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Kyurem"),
#else
        .speciesName = _("KYUREM"),
#endif
        .cryId = CRY_KYUREM_BLACK,
        .natDexNum = NATIONAL_DEX_KYUREM,
#if GERMAN
        .categoryName = _("Schwelle"),
#else
        .categoryName = _("Boundary"),
#endif
        .height = 33,
        .weight = 3250,
        .description = COMPOUND_STRING(
#if GERMAN
        "Man sagt, es kämpfe dafür, dass in Zukunft\n"
        "eine Welt der Wünsche für Menschen und\n"
        "Pokémon zur Realität werden kann."),
#else
            "The sameness of Zekrom's and\n"
            "Kyurem's genes allowed Kyurem to absorb\n"
            "Zekrom. Kyurem can now use the\n"
            "power of both electricity and ice."),
#endif
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 356,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KyuremBlack,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_KyuremBlack,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_KyuremBlack,
        .shinyPalette = gMonShinyPalette_KyuremBlack,
        .iconSprite = gMonIcon_KyuremBlack,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 14, SHADOW_SIZE_L)
        FOOTPRINT(Kyurem)
        OVERWORLD(
            sPicTable_KyuremBlack,
            SIZE_32x32, //TODO: 64x64 overworld sprite!
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_KyuremBlack,
            gShinyOverworldPalette_KyuremBlack
        )
        .isRestrictedLegendary = TRUE,
        .cannotBeTraded = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKyuremBlackLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .formSpeciesIdTable = sKyuremFormSpeciesIdTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FUSION_FORMS
#endif //P_FAMILY_KYUREM

#if P_FAMILY_KELDEO
    [SPECIES_KELDEO_ORDINARY] =
    {
        .baseHP        = 91,
        .baseAttack    = 72,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 129,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_WATER, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
#if GERMAN
        .speciesName = _("Keldeo"),
#else
        .speciesName = _("KELDEO"),
#endif
        .cryId = CRY_KELDEO,
        .natDexNum = NATIONAL_DEX_KELDEO,
#if GERMAN
        .categoryName = _("Fohlen"),
#else
        .categoryName = _("Colt"),
#endif
        .height = 14,
        .weight = 485,
        .description = COMPOUND_STRING(
#if GERMAN
        "Keldeo kann auf dem Wasser laufen und\n"
        "reist auf Flüssen und Meeren um die Welt.\n"
        "Zu sehen in malerischen Küstengebieten."),
#else
            "When it is resolute, its body fills with\n"
            "power and it becomes swifter. It crosses\n"
            "the world, running over the surfaces of\n"
            "oceans and rivers."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KeldeoOrdinary,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 32),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_KeldeoOrdinary,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .palette = gMonPalette_KeldeoOrdinary,
        .shinyPalette = gMonShinyPalette_KeldeoOrdinary,
        .iconSprite = gMonIcon_KeldeoOrdinary,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 8, SHADOW_SIZE_M)
        FOOTPRINT(Keldeo)
        OVERWORLD(
            sPicTable_KeldeoOrdinary,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_KeldeoOrdinary,
            gShinyOverworldPalette_KeldeoOrdinary
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKeldeoLevelUpLearnset,
        .teachableLearnset = sKeldeoTeachableLearnset,
        .formSpeciesIdTable = sKeldeoFormSpeciesIdTable,
        .formChangeTable = sKeldeoFormChangeTable,
    },

    [SPECIES_KELDEO_RESOLUTE] =
    {
        .baseHP        = 91,
        .baseAttack    = 72,
        .baseDefense   = 90,
        .baseSpeed     = 108,
        .baseSpAttack  = 129,
        .baseSpDefense = 90,
        .types = MON_TYPES(TYPE_WATER, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Keldeo"),
#else
        .speciesName = _("KELDEO"),
#endif
        .cryId = CRY_KELDEO,
        .natDexNum = NATIONAL_DEX_KELDEO,
#if GERMAN
        .categoryName = _("Fohlen"),
#else
        .categoryName = _("Colt"),
#endif
        .height = 14,
        .weight = 485,
        .description = COMPOUND_STRING(
#if GERMAN
        "Durch seinen starken Kampfeswillen wurde\n"
        "sein Körper mit purer Willenskraft erfüllt,\n"
        "woraufhin es diese Form annehmen konnte."),
#else
            "The power that lay hidden in its\n"
            "body now covers its horn, turning it\n"
            "into a sword that can slice through\n"
            "anything."),
#endif
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KeldeoResolute,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_JUMPS_H_JUMPS,
        .backPic = gMonBackPic_KeldeoResolute,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_KeldeoResolute,
        .shinyPalette = gMonShinyPalette_KeldeoResolute,
        .iconSprite = gMonIcon_KeldeoResolute,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 12, SHADOW_SIZE_M)
        FOOTPRINT(Keldeo)
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sKeldeoLevelUpLearnset,
        .teachableLearnset = sKeldeoTeachableLearnset,
        .formSpeciesIdTable = sKeldeoFormSpeciesIdTable,
        .formChangeTable = sKeldeoFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_KELDEO

#if P_FAMILY_MELOETTA
    [SPECIES_MELOETTA_ARIA] =
    {
        .baseHP        = 100,
        .baseAttack    = 77,
        .baseDefense   = 77,
        .baseSpeed     = 90,
        .baseSpAttack  = 128,
        .baseSpDefense = 128,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .itemCommon = ITEM_STAR_PIECE,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Meloetta"),
#else
        .speciesName = _("MELOETTA"),
#endif
        .cryId = CRY_MELOETTA,
        .natDexNum = NATIONAL_DEX_MELOETTA,
#if GERMAN
        .categoryName = _("Melodie"),
#else
        .categoryName = _("Melody"),
#endif
        .height = 6,
        .weight = 65,
        .description = COMPOUND_STRING(
#if GERMAN
        "Meloetta besitzt die Macht, Pokémon, die\n"
        "sich in seiner Nähe aufhalten, mit seinen\n"
        "Melodien froh oder traurig zu stimmen."),
#else
            "The melodies sung by Meloetta have the\n"
            "power to make Pokémon that hear them\n"
            "happy or sad. Many famous songs have been\n"
            "inspired by the tunes that Meloetta plays."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MeloettaAria,
        .frontPicSize = MON_COORDS_SIZE(32, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_MeloettaAria,
        .backPicSize = MON_COORDS_SIZE(48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_MeloettaAria,
        .shinyPalette = gMonShinyPalette_MeloettaAria,
        .iconSprite = gMonIcon_MeloettaAria,
        .iconPalIndex = 4,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 10, SHADOW_SIZE_S)
        FOOTPRINT(Meloetta)
        OVERWORLD(
            sPicTable_MeloettaAria,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_MeloettaAria,
            gShinyOverworldPalette_MeloettaAria
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMeloettaLevelUpLearnset,
        .teachableLearnset = sMeloettaTeachableLearnset,
        .formSpeciesIdTable = sMeloettaFormSpeciesIdTable,
        .formChangeTable = sMeloettaFormChangeTable,
    },

    [SPECIES_MELOETTA_PIROUETTE] =
    {
        .baseHP        = 100,
        .baseAttack    = 128,
        .baseDefense   = 90,
        .baseSpeed     = 128,
        .baseSpAttack  = 77,
        .baseSpDefense = 77,
        .types = MON_TYPES(TYPE_NORMAL, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .evYield_Speed = 1,
        .itemCommon = ITEM_STAR_PIECE,
        .itemRare = ITEM_STAR_PIECE,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .noFlip = TRUE,
#if GERMAN
        .speciesName = _("Meloetta"),
#else
        .speciesName = _("MELOETTA"),
#endif
        .cryId = CRY_MELOETTA,
        .natDexNum = NATIONAL_DEX_MELOETTA,
#if GERMAN
        .categoryName = _("Melodie"),
#else
        .categoryName = _("Melody"),
#endif
        .height = 6,
        .weight = 65,
        .description = COMPOUND_STRING(
#if GERMAN
            "Meloetta hat ein lange vergessenes Lied\n"
            "wiederentdeckt und zieht mit seinen\n"
            "betörenden Tanzschritten jeden in seinen\n"
            "Bann."),
#else
            "Meloetta's melodies are sung with\n"
            "a special vocalization method that can\n"
            "control the feelings of those who hear it."),
#endif
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_MeloettaPirouette,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_MeloettaPirouette,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        .palette = gMonPalette_MeloettaPirouette,
        .shinyPalette = gMonShinyPalette_MeloettaPirouette,
        .iconSprite = gMonIcon_MeloettaPirouette,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 16, SHADOW_SIZE_S)
        FOOTPRINT(Meloetta)
        OVERWORLD(
            sPicTable_MeloettaPirouette,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following_Asym,
            gOverworldPalette_MeloettaPirouette,
            gShinyOverworldPalette_MeloettaPirouette
        )
        .isMythical = TRUE,
        .isFrontierBanned = TRUE,
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,
        .levelUpLearnset = sMeloettaLevelUpLearnset,
        .teachableLearnset = sMeloettaTeachableLearnset,
        .formSpeciesIdTable = sMeloettaFormSpeciesIdTable,
        .formChangeTable = sMeloettaFormChangeTable,
        .randomizerMode = MON_RANDOMIZER_INVALID,
    },
#endif //P_FAMILY_MELOETTA

#if P_FAMILY_GENESECT
#define GENESECT_SPECIES_INFO(form, rzMode)                                         \
    {                                                                               \
        .baseHP        = 71,                                                        \
        .baseAttack    = 120,                                                       \
        .baseDefense   = 95,                                                        \
        .baseSpeed     = 99,                                                        \
        .baseSpAttack  = 120,                                                       \
        .baseSpDefense = 95,                                                        \
        .types = MON_TYPES(TYPE_BUG, TYPE_STEEL),                                   \
        .catchRate = 3,                                                             \
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,                    \
        .evYield_Attack = 1,                                                        \
        .evYield_Speed = 1,                                                         \
        .evYield_SpAttack = 1,                                                      \
        .genderRatio = MON_GENDERLESS,                                              \
        .eggCycles = 120,                                                           \
        .friendship = 0,                                                            \
        .growthRate = GROWTH_SLOW,                                                  \
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),                  \
        .abilities = { ABILITY_DOWNLOAD, ABILITY_NONE, ABILITY_NONE },              \
        .bodyColor = BODY_COLOR_PURPLE,                                             \
        .speciesName = _(DE_EN("Genesect", "GENESECT")),                            \
        .cryId = CRY_GENESECT,                                                      \
        .natDexNum = NATIONAL_DEX_GENESECT,                                         \
        .categoryName = _(DE_EN("Paläozoikum", "Paleozoic")),                         \
        .height = 15,                                                               \
        .weight = 825,                                                              \
        .description = gGenesectPokedexText,                                        \
        .pokemonScale = 268,                                                        \
        .pokemonOffset = 2,                                                         \
        .trainerScale = 271,                                                        \
        .trainerOffset = 0,                                                         \
        .frontPic = gMonFrontPic_Genesect,                                          \
        .frontPicSize = MON_COORDS_SIZE(56, 64),                                    \
        .frontPicYOffset = 0,                                                       \
        .frontAnimFrames = sAnims_Genesect,                                         \
        .frontAnimId = ANIM_H_VIBRATE,                                              \
        .backPic = gMonBackPic_Genesect,                                            \
        .backPicSize = MON_COORDS_SIZE(64, 48),                                     \
        .backPicYOffset = 8,                                                        \
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,                            \
        .palette = gMonPalette_##form,                                              \
        .shinyPalette = gMonShinyPalette_##form,                                    \
        .iconSprite = gMonIcon_Genesect,                                            \
        .iconPalIndex = 2,                                                          \
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,                                     \
        SHADOW(5, 13, SHADOW_SIZE_L)                                                \
        FOOTPRINT(Genesect)                                                         \
        OVERWORLD(                                                                  \
            sPicTable_Genesect,                                                     \
            SIZE_32x32,                                                             \
            SHADOW_SIZE_M,                                                          \
            TRACKS_FOOT,                                                            \
            sAnimTable_Following,                                                   \
            gOverworldPalette_Genesect,                                             \
            gShinyOverworldPalette_Genesect                                         \
        )                                                                           \
        .levelUpLearnset = sGenesectLevelUpLearnset,                                \
        .teachableLearnset = sGenesectTeachableLearnset,                            \
        .formSpeciesIdTable = sGenesectFormSpeciesIdTable,                          \
        .formChangeTable = sGenesectFormChangeTable,                                \
        .isMythical = TRUE,                                                         \
        .isFrontierBanned = TRUE,                                                   \
        .perfectIVCount = LEGENDARY_PERFECT_IV_COUNT,                               \
        .randomizerMode = rzMode,                                                   \
    }

    [SPECIES_GENESECT]       = GENESECT_SPECIES_INFO(Genesect,           MON_RANDOMIZER_NORMAL ),
    [SPECIES_GENESECT_DOUSE] = GENESECT_SPECIES_INFO(GenesectDouseDrive, MON_RANDOMIZER_INVALID),
    [SPECIES_GENESECT_SHOCK] = GENESECT_SPECIES_INFO(GenesectShockDrive, MON_RANDOMIZER_INVALID),
    [SPECIES_GENESECT_BURN]  = GENESECT_SPECIES_INFO(GenesectBurnDrive,  MON_RANDOMIZER_INVALID),
    [SPECIES_GENESECT_CHILL] = GENESECT_SPECIES_INFO(GenesectChillDrive, MON_RANDOMIZER_INVALID),
#endif //P_FAMILY_GENESECT

#ifdef __INTELLISENSE__
};
#endif
