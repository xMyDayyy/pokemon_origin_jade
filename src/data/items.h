#if I_USE_EVO_HELD_ITEMS_FROM_BAG == TRUE
    #define EVO_HELD_ITEM_TYPE ITEM_USE_PARTY_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_EvolutionStone
#else
    #define EVO_HELD_ITEM_TYPE ITEM_USE_BAG_MENU
    #define EVO_HELD_ITEM_FIELD_FUNC ItemUseOutOfBattle_CannotUse
#endif

#define GEM_BOOST_PARAM ((I_GEM_BOOST_POWER >= GEN_6) ? 30 : 50)
#define TYPE_BOOST_PARAM ((I_TYPE_BOOST_POWER >= GEN_4) ? 20 : 10) // For non Pokémon-specific type-boosting held items.
#define POWER_ITEM_BOOST ((I_POWER_ITEM_BOOST >= GEN_7) ? 8 : 4)

#define X_ITEM_STAGES ((B_X_ITEMS_BUFF >= GEN_7) ? 2 : 1)

#define TREASURE_FACTOR ((I_SELL_VALUE_FRACTION >= GEN_9) ? 2 : 1)

#define ITEM_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_LENGTH)
#define ITEM_PLURAL_NAME(str) COMPOUND_STRING_SIZE_LIMIT(str, ITEM_NAME_PLURAL_LENGTH)

// Shared Item Description entries

#if GERMAN
static const u8 sFullHealDesc[]       = _("Beseitigt alle\n"
                                          "Statusprobleme\n"
                                          "eines Pokémon.");
#else
static const u8 sFullHealDesc[]       = _("Heals all the\n"
                                          "status problems of\n"
                                          "one Pokémon.");
#endif

#if GERMAN
static const u8 sPokeDollDesc[]       = _("Ermöglicht Flucht\n"
                                          "im Kampf gegen\n"
                                          "wilde Pokémon.");
#else
static const u8 sPokeDollDesc[]       = _("Use to flee from\n"
                                          "any battle with\n"
                                          "a wild Pokémon.");
#endif

#if GERMAN
static const u8 sMaxReviveDesc[]      = _("Belebt Pokémon und\n"
                                          "füllt KP vollständig\n"
                                          "wieder auf.");
#else
static const u8 sMaxReviveDesc[]      = _("Revives a fainted\n"
                                          "Pokémon with all\n"
                                          "its HP.");
#endif

#if GERMAN
static const u8 sHealthFeatherDesc[]  = _("Hebt die\n"
                                          "KP-Basispunkte\n"
                                          "eines Pokémon.");
#else
static const u8 sHealthFeatherDesc[]  = _("An item that raises\n"
                                          "the base HP of\n"
                                          "a Pokémon.");
#endif

#if GERMAN
static const u8 sMuscleFeatherDesc[]  = _("Hebt die\n"
                                          "Angr.-Basispunkte\n"
                                          "eines Pokémon.");
#else
static const u8 sMuscleFeatherDesc[]  = _("An item that raises\n"
                                          "the base Attack of\n"
                                          "a Pokémon.");
#endif

#if GERMAN
static const u8 sResistFeatherDesc[]  = _("Hebt die\n"
                                          "Vert.-Basispunkte\n"
                                          "eines Pokémon.");
#else
static const u8 sResistFeatherDesc[]  = _("An item that raises\n"
                                          "the base Defense\n"
                                          "of a Pokémon.");
#endif

#if GERMAN
static const u8 sGeniusFeatherDesc[]  = _("Hebt die Sp.\n"
                                          "Angr.-Basispunkte\n"
                                          "eines Pokémon.");
#else
static const u8 sGeniusFeatherDesc[]  = _("An item that raises\n"
                                          "the base Sp. Atk.\n"
                                          "of a Pokémon.");
#endif

#if GERMAN
static const u8 sCleverFeatherDesc[]  = _("Hebt die Sp.\n"
                                          "Vert.-Basispunkte\n"
                                          "eines Pokémon.");
#else
static const u8 sCleverFeatherDesc[]  = _("An item that raises\n"
                                          "the base Sp. Def.\n"
                                          "of a Pokémon.");
#endif

#if GERMAN
static const u8 sSwiftFeatherDesc[]   = _("Hebt die\n"
                                          "Init.-Basispunkte\n"
                                          "eines Pokémon.");
#else
static const u8 sSwiftFeatherDesc[]   = _("An item that raises\n"
                                          "the base Speed of\n"
                                          "a Pokémon.");
#endif

#if GERMAN
static const u8 sBigMushroomDesc[]    = _("Ein seltener Pilz\n"
                                          "von hohem Wert.");
#else
static const u8 sBigMushroomDesc[]    = _("A rare mushroom\n"
                                          "that would sell at a\n"
                                          "high price.");
#endif

#if GERMAN
static const u8 sShardsDesc[]         = _("Scherbe eines\n"
                                          "antiken Relikts\n"
                                          "von geringem Wert.");
#else
static const u8 sShardsDesc[]         = _("A shard from an\n"
                                          "ancient item. Can\n"
                                          "be sold cheaply.");
#endif

#if GERMAN
static const u8 sRootFossilDesc[]     = _("Fossil eines ural-\n"
                                          "ten Pokémon, das in\n"
                                          "der Tiefsee lebte.");
#else
static const u8 sRootFossilDesc[]     = _("A fossil of an\n"
                                          "ancient, seafloor-\n"
                                          "dwelling Pokémon.");
#endif

#if GERMAN
static const u8 sFossilizedFishDesc[] = _("Fossil eines ural-\n"
                                          "ten Pokémon, das in\n"
                                          "der Tiefsee lebte.");
#else
static const u8 sFossilizedFishDesc[] = _("A fossil of an\n"
                                          "ancient, sea-\n"
                                          "dwelling Pokémon.");
#endif

#if GERMAN
static const u8 sBeadMailDesc[]       = _("Brief mit Abbildung\n"
                                          "des Pokémon, das\n"
                                          "ihn trägt.");
#else
static const u8 sBeadMailDesc[]       = _("Mail featuring a\n"
                                          "sketch of the\n"
                                          "holding Pokémon.");
#endif

#if GERMAN
static const u8 sEvolutionStoneDesc[] = _("Löst bei bestimm-\n"
                                          "ten Pokémon die\n"
                                          "Entwicklung aus.");
#else
static const u8 sEvolutionStoneDesc[] = _("Makes certain\n"
                                          "species of Pokémon\n"
                                          "evolve.");
#endif

#if GERMAN
static const u8 sNectarDesc[]         = _("Blütennektar, der\n"
                                          "die Form bestimmter\n"
                                          "Pokémon verändert.");
#else
static const u8 sNectarDesc[]         = _("Flower nectar that\n"
                                          "changes the form\n"
                                          "of certain Pokémon.");
#endif

#if GERMAN
static const u8 sCharizarditeDesc[]   = _("Mega-Stein, mit dem\n"
                                          "Glurak mega-\n"
                                          "entwickeln kann.");
#else
static const u8 sCharizarditeDesc[]   = _("This stone enables\n"
                                          "Charizard to Mega\n"
                                          "Evolve in battle.");
#endif

#if GERMAN
static const u8 sMewtwoniteDesc[]     = _("Mega-Stein, mit dem\n"
                                          "Mewtu mega-\n"
                                          "entwickeln kann.");
#else
static const u8 sMewtwoniteDesc[]     = _("This stone enables\n"
                                          "Mewtwo to Mega\n"
                                          "Evolve in battle.");
#endif

#if GERMAN
static const u8 sRaichuniteDesc[]     = _("Mega-Stein, mit dem\n"
                                          "Raichu mega-\n"
                                          "entwickeln kann.");
#else
static const u8 sRaichuniteDesc[]     = _("This stone enables\n"
                                          "Raichu to Mega\n"
                                          "Evolve in battle.");
#endif

#if GERMAN
static const u8 sAbsoliteDesc[]       = _("Mega-Stein, mit dem\n"
                                          "Absol mega-\n"
                                          "entwickeln kann.");
#else
static const u8 sAbsoliteDesc[]       = _("This stone enables\n"
                                          "Absol to Mega\n"
                                          "Evolve in battle.");
#endif

#if GERMAN
static const u8 sGarchompiteDesc[]    = _("Mega-Stein, mit dem\n"
                                          "Knakrack mega-\n"
                                          "entwickeln kann.");
#else
static const u8 sGarchompiteDesc[]    = _("This stone enables\n"
                                          "Garchomp to Mega\n"
                                          "Evolve in battle.");
#endif

#if GERMAN
static const u8 sLucarioniteDesc[]    = _("Mega-Stein, mit dem\n"
                                          "Lucario mega-\n"
                                          "entwickeln kann.");
#else
static const u8 sLucarioniteDesc[]    = _("This stone enables\n"
                                          "Lucario to Mega\n"
                                          "Evolve in battle.");
#endif

#if GERMAN
static const u8 sSeaIncenseDesc[]     = _("Item (Tragen)\n"
                                          "verstärkt\n"
                                          "Wasser-Attacken.");
#else
static const u8 sSeaIncenseDesc[]     = _("A hold item that\n"
                                          "slightly boosts\n"
                                          "Water-type moves.");
#endif

#if GERMAN
static const u8 sOddIncenseDesc[]     = _("Item (Tragen)\n"
                                          "verstärkt\n"
                                          "Psycho-Attacken.");
#else
static const u8 sOddIncenseDesc[]     = _("A hold item that\n"
                                          "boosts Psychic-\n"
                                          "type moves.");
#endif

#if GERMAN
static const u8 sRockIncenseDesc[]    = _("Item (Tragen)\n"
                                          "verstärkt\n"
                                          "Gestein-Attacken.");
#else
static const u8 sRockIncenseDesc[]    = _("A hold item that\n"
                                          "raises the power of\n"
                                          "Rock-type moves.");
#endif

#if GERMAN
static const u8 sFullIncenseDesc[]    = _("Item (Tragen) lässt\n"
                                          "den Träger\n"
                                          "langsamer agieren.");
#else
static const u8 sFullIncenseDesc[]    = _("A held item that\n"
                                          "makes the holder\n"
                                          "move slower.");
#endif

#if GERMAN
static const u8 sRoseIncenseDesc[]    = _("Item (Tragen)\n"
                                          "verstärkt\n"
                                          "Pflanzen-Attacken.");
#else
static const u8 sRoseIncenseDesc[]    = _("A hold item that\n"
                                          "raises the power of\n"
                                          "Grass-type moves.");
#endif

#if GERMAN
static const u8 sLuckIncenseDesc[]    = _("Doppelter Geldbe-\n"
                                          "trag, wenn Träger\n"
                                          "am Kampf teilnimmt.");
#else
static const u8 sLuckIncenseDesc[]    = _("Doubles money in\n"
                                          "battle if the\n"
                                          "holder takes part.");
#endif

#if GERMAN
static const u8 sPureIncenseDesc[]    = _("Item (Tragen) kann\n"
                                          "wilde Pokémon\n"
                                          "abhalten.");
#else
static const u8 sPureIncenseDesc[]    = _("A hold item that\n"
                                          "helps repel wild\n"
                                          "Pokémon.");
#endif

#if GERMAN
static const u8 sKingsRockDesc[]      = _("Item (Tragen) kann\n"
                                          "Gegner zurückwei-\n"
                                          "chen lassen.");
#else
static const u8 sKingsRockDesc[]      = _("A hold item that\n"
                                          "may cause flinching\n"
                                          "when the foe is hit.");
#endif

#if GERMAN
static const u8 sFigyBerryDesc[]      = _("Item (Tragen) füllt\n"
                                          "KP auf, bewirkt\n"
                                          "evtl. Verwirrung.");
#else
static const u8 sFigyBerryDesc[]      = _("A hold item that\n"
                                          "restores HP but\n"
                                          "may confuse.");
#endif

const u8 gQuestionMarksItemName[] = _("????????");

static const u8 sQuestionMarksDesc[]  = _("?????");

#if GERMAN
static const u8 sKeyToRoomDesc[]      = _("Schlüssel zur Tür\n"
                                          "einer Kabine auf\n"
                                          "dem Schiffswrack.");
#else
static const u8 sKeyToRoomDesc[]      = _("A key that opens a\n"
                                          "door inside the\n"
                                          "Abandoned Ship.");
#endif

#if GERMAN
static const u8 sTeraShardDesc[]      = _("Kristallstück eines\n"
                                          "im Kampf besiegten\n"
                                          "Tera-Pokémon.");
#else
static const u8 sTeraShardDesc[]      = _("These shards may\n"
                                          "form when a Tera\n"
                                          "Pokémon faints.");
#endif

#if GERMAN
static const u8 sGenericMulchDesc[]   = _("Ein Dünger, der für\n"
                                          "den hiesigen Boden\n"
                                          "ungeeignet ist.");
#else
static const u8 sGenericMulchDesc[]   = _("A fertilizer that\n"
                                          "is unsuitable for\n"
                                          "local soil.");
#endif

const struct ItemInfo gItemsInfo[] =
{
    [ITEM_NONE] =
    {
        .name = gQuestionMarksItemName,
        .price = 0,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_UNCATEGORIZED,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

// Poké Balls

    [ITEM_STRANGE_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Rätselball"),
        .pluralName = ITEM_PLURAL_NAME("Rätselbälle"),
#else
        .name = ITEM_NAME("STRANGE BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rätselhafter Ball\n"
            "aus ferner Zeit und\n"
            "unbekanntem Ort."),
#else
            "An unusual Ball\n"
            "warped through\n"
            "space and time."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_STRANGE,
        .iconPic = gItemIcon_StrangeBall,
        .iconPalette = gItemIconPalette_StrangeBall,
    },

    [ITEM_POKE_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokéball"),
        .pluralName = ITEM_PLURAL_NAME("Pokébälle"),
#else
        .name = ITEM_NAME("POKé BALL"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Damit fängst\n"
            "du wilde\n"
#else
            "A tool used for\n"
            "catching wild\n"
#endif
            "Pokémon."),
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_POKE,
        .iconPic = gItemIcon_PokeBall,
        .iconPalette = gItemIconPalette_PokeBall,
    },

    [ITEM_GREAT_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Superball"),
        .pluralName = ITEM_PLURAL_NAME("Superbälle"),
#else
        .name = ITEM_NAME("GREAT BALL"),
#endif
        .price = 400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball mit guter Er-\n"
            "folgsquote. Besser\n"
            "als ein Pokéball."),
#else
            "A good Ball with a\n"
            "higher catch rate\n"
            "than a Poké Ball."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_GREAT,
        .iconPic = gItemIcon_GreatBall,
        .iconPalette = gItemIconPalette_GreatBall,
    },

    [ITEM_ULTRA_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Hyperball"),
        .pluralName = ITEM_PLURAL_NAME("Hyperbälle"),
#else
        .name = ITEM_NAME("ULTRA BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 800 : 1200,
        .price = 800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball mit hoher Er-\n"
            "folgsquote. Besser\n"
            "als ein Superball."),
#else
            "A better Ball with\n"
            "a higher catch rate\n"
            "than a Great Ball."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_ULTRA,
        .iconPic = gItemIcon_UltraBall,
        .iconPalette = gItemIconPalette_UltraBall,
    },

    [ITEM_MASTER_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Meisterball"),
        .pluralName = ITEM_PLURAL_NAME("Meisterbälle"),
#else
        .name = ITEM_NAME("MASTER BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Der beste Ball.\n"
            "Fängt das Pokémon\n"
            "garantiert."),
#else
            "The best Ball that\n"
            "catches a Pokémon\n"
            "without fail."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MASTER,
        .iconPic = gItemIcon_MasterBall,
        .iconPalette = gItemIconPalette_MasterBall,
    },

    [ITEM_PREMIER_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Premierball"),
        .pluralName = ITEM_PLURAL_NAME("Premierbälle"),
#else
        .name = ITEM_NAME("PREMIER BALL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltener Ball, als\n"
            "Reminiszenz an ir-\n"
            "gendein Ereignis."),
#else
            "A rare Ball made\n"
            "in commemoration\n"
            "of some event."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PREMIER,
        .iconPic = gItemIcon_PremierBall,
        .iconPalette = gItemIconPalette_PremierBall,
    },

    [ITEM_HEAL_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Heilball"),
        .pluralName = ITEM_PLURAL_NAME("Heilbälle"),
#else
        .name = ITEM_NAME("HEAL BALL"),
#endif
        .price = 300,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball, der gefangene\n"
            "Pokémon heilt und\n"
            "ihre KP auffüllt."),
#else
            "A remedial Ball\n"
            "that restores\n"
            "caught Pokémon."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAL,
        .iconPic = gItemIcon_HealBall,
        .iconPalette = gItemIconPalette_HealBall,
    },

    [ITEM_NET_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Netzball"),
        .pluralName = ITEM_PLURAL_NAME("Netzbälle"),
#else
        .name = ITEM_NAME("NET BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball fängt besser\n"
            "Pokémon des Typs\n"
            "Wasser und Käfer."),
#else
            "A Ball that works\n"
            "well on Water- and\n"
            "Bug-type Pokémon."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NET,
        .iconPic = gItemIcon_NetBall,
        .iconPalette = gItemIconPalette_NetBall,
    },

    [ITEM_NEST_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Nestball"),
        .pluralName = ITEM_PLURAL_NAME("Nestbälle"),
#else
        .name = ITEM_NAME("NEST BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball mit höherer\n"
            "Erfolgsquote bei\n"
            "schwachen Pokémon."),
#else
            "A Ball that works\n"
            "better on weaker\n"
            "Pokémon."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_NEST,
        .iconPic = gItemIcon_NestBall,
        .iconPalette = gItemIconPalette_NestBall,
    },

    [ITEM_DIVE_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Tauchball"),
        .pluralName = ITEM_PLURAL_NAME("Tauchbälle"),
#else
        .name = ITEM_NAME("DIVE BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball fängt besser\n"
            "Pokémon auf\n"
            "dem Meeresgrund."),
#else
            "A Ball that works\n"
            "better on Pokémon\n"
            "on the ocean floor."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DIVE,
        .iconPic = gItemIcon_DiveBall,
        .iconPalette = gItemIconPalette_DiveBall,
    },

    [ITEM_DUSK_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Finsterball"),
        .pluralName = ITEM_PLURAL_NAME("Finsterbälle"),
#else
        .name = ITEM_NAME("DUSK BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball fängt besser\n"
            "an dunklen Orten\n"
            "und bei Nacht."),
#else
            "Works well if\n"
            "used in a\n"
            "dark place."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DUSK,
        .iconPic = gItemIcon_DuskBall,
        .iconPalette = gItemIconPalette_DuskBall,
    },

    [ITEM_TIMER_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Timerball"),
        .pluralName = ITEM_PLURAL_NAME("Timerbälle"),
#else
        .name = ITEM_NAME("TIMER BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball wird effek-\n"
            "tiver, je länger der\n"
            "Kampf dauert."),
#else
            "A Ball that gains\n"
            "power in battles\n"
            "taking many turns."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_TIMER,
        .iconPic = gItemIcon_TimerBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_QUICK_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Flottball"),
        .pluralName = ITEM_PLURAL_NAME("Flottbälle"),
#else
        .name = ITEM_NAME("QUICK BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball wirkt am\n"
            "besten in der\n"
            "ersten Runde."),
#else
            "Works well if\n"
            "used on the\n"
            "first turn."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_QUICK,
        .iconPic = gItemIcon_QuickBall,
        .iconPalette = gItemIconPalette_QuickBall,
    },

    [ITEM_REPEAT_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Wiederball"),
        .pluralName = ITEM_PLURAL_NAME("Wiederbälle"),
#else
        .name = ITEM_NAME("REPEAT BALL"),
#endif
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball fängt besser\n"
            "bereits gefangene\n"
            "Pokémon."),
#else
            "A Ball that works\n"
            "better on Pokémon\n"
            "caught before."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_REPEAT,
        .iconPic = gItemIcon_RepeatBall,
        .iconPalette = gItemIconPalette_RepeatBall,
    },

    [ITEM_LUXURY_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Luxusball"),
        .pluralName = ITEM_PLURAL_NAME("Luxusbälle"),
#else
        .name = ITEM_NAME("LUXURY BALL"),
#endif
        .price = (I_PRICE >= GEN_8) ? 3000 : 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Behaglicher Ball,\n"
            "der Pokémon\n"
            "freundlicher macht."),
#else
            "A cozy Ball that\n"
            "makes Pokémon\n"
            "more friendly."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LUXURY,
        .iconPic = gItemIcon_LuxuryBall,
        .iconPalette = gItemIconPalette_LuxuryBall,
    },

    [ITEM_LEVEL_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Levelball"),
        .pluralName = ITEM_PLURAL_NAME("Levelbälle"),
#else
        .name = ITEM_NAME("LEVEL BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für Normal,\n"
            "Fug, Eis, und\n"
            "niedrige POKéMON."),
#else
            "Good for NORMAL,\n"
            "FLYING, ICE, and\n"
            "low level POKéMON."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LEVEL,
        .iconPic = gItemIcon_LevelBall,
        .iconPalette = gItemIconPalette_LevelBall,
    },

    [ITEM_LURE_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Köderball"),
        .pluralName = ITEM_PLURAL_NAME("Köderbälle"),
#else
        .name = ITEM_NAME("LURE BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für Wasser,\n"
            "Drache und\n"
            "geangelte Pokémon."),
#else
            "Good for WATER,\n"
            "DRAGON, and fished\n"
            "up POKéMON."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LURE,
        .iconPic = gItemIcon_LureBall,
        .iconPalette = gItemIconPalette_LureBall,
    },

    [ITEM_MOON_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Mondball"),
        .pluralName = ITEM_PLURAL_NAME("Mondbälle"),
#else
        .name = ITEM_NAME("MOON BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für Unlicht,\n"
            "Geist, Gift und\n"
            "Mondstein-Nutzer."),
#else
            "Good for DARK,\n"
            "GHOST, POISON, and\n"
            "MOON STONE users."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_MOON,
        .iconPic = gItemIcon_MoonBall,
        .iconPalette = gItemIconPalette_MoonBall,
    },

    [ITEM_FRIEND_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Freundesball"),
        .pluralName = ITEM_PLURAL_NAME("Freundesbälle"),
#else
        .name = ITEM_NAME("FRIEND BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für Käfer,\n"
            "Pflanze. Macht\n"
            "Pokémon zutraulich."),
#else
            "Good for BUG,\n"
            "GRASS, and making\n"
            "POKéMON friendly."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FRIEND,
        .iconPic = gItemIcon_FriendBall,
        .iconPalette = gItemIconPalette_FriendBall,
    },

    [ITEM_LOVE_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Sympaball"),
        .pluralName = ITEM_PLURAL_NAME("Sympabälle"),
#else
        .name = ITEM_NAME("LOVE BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für Psycho,\n"
            "Fee und das ande-\n"
            "re Geschlecht."),
#else
            "Good for PSYCHIC,\n"
            "FAIRY, and the\n"
            "opposite gender."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_LOVE,
        .iconPic = gItemIcon_LoveBall,
        .iconPalette = gItemIconPalette_LoveBall,
    },

    [ITEM_FAST_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Turboball"),
        .pluralName = ITEM_PLURAL_NAME("Turbobälle"),
#else
        .name = ITEM_NAME("FAST BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für schnelle,\n"
            "Feuer, Elektro und\n"
            "Kampf Pokémon."),
#else
            "Good for fast, FIRE,\n"
            "ELECTRIC, and\n"
            "FIGHTING POKéMON."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_FAST,
        .iconPic = gItemIcon_FastBall,
        .iconPalette = gItemIconPalette_FastBall,
    },

    [ITEM_HEAVY_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Schwerball"),
        .pluralName = ITEM_PLURAL_NAME("Schwerbälle"),
#else
        .name = ITEM_NAME("HEAVY BALL"),
#endif
        //.price = (I_PRICE >= GEN_7) ? 0 : 300,
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gut für Boden,\n"
            "Stein, Stahl und\n"
            "schwere Pokémon."),
#else
            "Good for ROCK,\n"
            "GROUND, STEEL, and\n"
            "Heavy POKéMON."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_HEAVY,
        .iconPic = gItemIcon_HeavyBall,
        .iconPalette = gItemIconPalette_HeavyBall,
    },

    [ITEM_DREAM_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Traumball"),
        .pluralName = ITEM_PLURAL_NAME("Traumbälle"),
#else
        .name = ITEM_NAME("DREAM BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
        #if B_DREAM_BALL_MODIFIER >= GEN_8
#if GERMAN
            "Ball fängt besser\n"
            "schlafende\n"
#else
            "A Ball that works\n"
            "well on sleeping\n"
#endif
            "Pokémon."),
        #else
#if GERMAN
            "Ein Pokéball für den\n"
            "Entrée-Wald."),
#else
            "A Poké Ball used in\n"
            "the Entree Forest."),
#endif
        #endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_DREAM,
        .iconPic = gItemIcon_DreamBall,
        .iconPalette = gItemIconPalette_DreamBall,
    },

    [ITEM_SAFARI_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Safariball"),
        .pluralName = ITEM_PLURAL_NAME("Safaribälle"),
#else
        .name = ITEM_NAME("SAFARI BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Ball, der nur\n"
            "in der Safari-Zone\n"
            "eingesetzt wird."),
#else
            "A special Ball that\n"
            "is used only in the\n"
            "Safari Zone."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SAFARI,
        .iconPic = gItemIcon_SafariBall,
        .iconPalette = gItemIconPalette_SafariBall,
    },

    [ITEM_SPORT_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Turnierball"),
        .pluralName = ITEM_PLURAL_NAME("Turnierbälle"),
#else
        .name = ITEM_NAME("SPORT BALL"),
#endif
        .price = (I_PRICE <= GEN_3 || I_PRICE >= GEN_9) ? 0 : 300,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball, der nur beim\n"
            "Käferturnier ein-\n"
            "gesetzt wird."),
#else
            "A special Ball\n"
            "used in the Bug-\n"
            "Catching Contest."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_SPORT,
        .iconPic = gItemIcon_SportBall,
        .iconPalette = gItemIconPalette_SportBall,
    },

    [ITEM_PARK_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Parkball"),
        .pluralName = ITEM_PLURAL_NAME("Parkbälle"),
#else
        .name = ITEM_NAME("PARK BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Ball nur für\n"
            "den Park der\n"
            "Freunde."),
#else
            "A special Ball for\n"
            "the Pal Park."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_PARK,
        .iconPic = gItemIcon_ParkBall,
        .iconPalette = gItemIconPalette_ParkBall,
    },

    [ITEM_BEAST_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Ultraball"),
        .pluralName = ITEM_PLURAL_NAME("Ultrabälle"),
#else
        .name = ITEM_NAME("BEAST BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ball, der eigens\n"
            "für Ultrabestien\n"
            "entwickelt wurde."),
#else
            "A Ball designed to\n"
            "catch Ultra Beasts."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_BEAST,
        .iconPic = gItemIcon_BeastBall,
        .iconPalette = gItemIconPalette_BeastBall,
    },

    [ITEM_CHERISH_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Jubelball"),
        .pluralName = ITEM_PLURAL_NAME("Jubelbälle"),
#else
        .name = ITEM_NAME("CHERISH BALL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltener Ball, als\n"
            "Reminiszenz an ein\n"
            "besond. Ereignis."),
#else
            "A rare Ball made\n"
            "in commemoration\n"
            "of some event."),
#endif
        .pocket = POCKET_POKE_BALLS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeBall,
        .battleUsage = EFFECT_ITEM_THROW_BALL,
        .secondaryId = BALL_CHERISH,
        .iconPic = gItemIcon_CherishBall,
        .iconPalette = gItemIconPalette_CherishBall,
    },

// Medicine

    [ITEM_POTION] =
    {
#if GERMAN
        .name = ITEM_NAME("Trank"),
        .pluralName = ITEM_PLURAL_NAME("Tränke"),
#else
        .name = ITEM_NAME("POTION"),
#endif
        .price = (I_PRICE >= GEN_7) ? 200 : 300,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt die KP eines\n"
            "Pokémon um 20\n"
            "Punkte auf."),
#else
            "Restores the HP of\n"
            "a Pokémon by\n"
            "20 points."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_Potion,
    },

    [ITEM_SUPER_POTION] =
    {
#if GERMAN
        .name = ITEM_NAME("Supertrank"),
        .pluralName = ITEM_PLURAL_NAME("Supertränke"),
#else
        .name = ITEM_NAME("SUPER POTION"),
#endif
        .price = 700,
        .holdEffectParam = 60,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Füllt die KP eines\n"
            "Pokémon um\n"
            "60 Punkte auf."),
#else
            "60 points."),
#endif
        #else
#if GERMAN
            "Füllt die KP eines\n"
            "Pokémon um\n"
            "50 Punkte auf."),
#else
            "50 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_SuperPotion,
    },

    [ITEM_HYPER_POTION] =
    {
#if GERMAN
        .name = ITEM_NAME("Hypertrank"),
        .pluralName = ITEM_PLURAL_NAME("Hypertränke"),
#else
        .name = ITEM_NAME("HYPER POTION"),
#endif
        .price = (I_PRICE >= GEN_2 && I_PRICE <= GEN_6) ? 1200 : 1500,
        .holdEffectParam = 120,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Füllt die KP eines\n"
            "Pokémon um\n"
            "120 Punkte auf."),
#else
            "120 points."),
#endif
        #else
#if GERMAN
            "Füllt die KP eines\n"
            "Pokémon um\n"
            "200 Punkte auf."),
#else
            "200 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_HyperPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_Potion,
        .iconPalette = gItemIconPalette_HyperPotion,
    },

    [ITEM_MAX_POTION] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Trank"),
        .pluralName = ITEM_PLURAL_NAME("Top-Tränke"),
#else
        .name = ITEM_NAME("MAX POTION"),
#endif
        .price = 2500,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt die KP\n"
            "vollständig auf."),
#else
            "Fully restores the\n"
            "HP of a Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MaxPotion,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_MaxPotion,
    },

    [ITEM_FULL_RESTORE] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Genesung"),
        .pluralName = ITEM_PLURAL_NAME("Top-Genesungen"),
#else
        .name = ITEM_NAME("FULL RESTORE"),
#endif
        .price = 3000,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stellt KP und\n"
            "Status eines\n"
            "Pokémon wieder her."),
#else
            "Fully restores the\n"
            "HP and status of a\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_HEAL_AND_CURE_STATUS,
        .effect = gItemEffect_FullRestore,
        .flingPower = 30,
        .iconPic = gItemIcon_LargePotion,
        .iconPalette = gItemIconPalette_FullRestore,
    },

    [ITEM_REVIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Beleber"),
        .pluralName = ITEM_PLURAL_NAME("Beleber"),
#else
        .name = ITEM_NAME("REVIVE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 1500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Belebt Pokémon und\n"
            "füllt die KP zur\n"
            "Hälfte wieder auf."),
#else
            "Revives a fainted\n"
            "Pokémon with half\n"
            "its HP."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_Revive,
        .flingPower = 30,
        .iconPic = gItemIcon_Revive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_MAX_REVIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Beleber"),
        .pluralName = ITEM_PLURAL_NAME("Top-Beleber"),
#else
        .name = ITEM_NAME("MAX REVIVE"),
#endif
        .price = 4000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxRevive,
        .iconPalette = gItemIconPalette_Revive,
    },

    [ITEM_FRESH_WATER] =
    {
#if GERMAN
        .name = ITEM_NAME("Tafelwasser"),
        .pluralName = ITEM_PLURAL_NAME("Tafelwasser"),
#else
        .name = ITEM_NAME("FRESH WATER"),
#endif
        .price = 200,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Ein stilles Wasser,\n"
            "das die KP um 30\n"
            "Punkte auffüllt."),
#else
            "by 30 points."),
#endif
        #else
#if GERMAN
            "Ein stilles Wasser,\n"
            "das die KP um 50\n"
            "Punkte auffüllt."),
#else
            "by 50 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FreshWater,
        .flingPower = 30,
        .iconPic = gItemIcon_FreshWater,
        .iconPalette = gItemIconPalette_FreshWater,
    },

    [ITEM_SODA_POP] =
    {
#if GERMAN
        .name = ITEM_NAME("Sprudel"),
        .pluralName = ITEM_PLURAL_NAME("Sprudel"),
#else
        .name = ITEM_NAME("SODA POP"),
#endif
        .price = 300,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Ein Mineralwasser,\n"
            "das die KP um 50\n"
            "Punkte auffüllt."),
#else
            "by 50 points."),
#endif
        #else
#if GERMAN
            "Ein Mineralwasser,\n"
            "das die KP um 60\n"
            "Punkte auffüllt."),
#else
            "by 60 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SodaPop,
        .flingPower = 30,
        .iconPic = gItemIcon_SodaPop,
        .iconPalette = gItemIconPalette_SodaPop,
    },

    [ITEM_LEMONADE] =
    {
#if GERMAN
        .name = ITEM_NAME("Limonade"),
        .pluralName = ITEM_PLURAL_NAME("Limonaden"),
#else
        .name = ITEM_NAME("LEMONADE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 70,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Ein süßes Getränk,\n"
            "das die KP um 70\n"
            "Punkte auffüllt."),
#else
            "by 70 points."),
#endif
        #else
#if GERMAN
            "Ein süßes Getränk,\n"
            "das die KP um 80\n"
            "Punkte auffüllt."),
#else
            "by 80 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Lemonade,
        .flingPower = 30,
        .iconPic = gItemIcon_Lemonade,
        .iconPalette = gItemIconPalette_Lemonade,
    },

    [ITEM_MOOMOO_MILK] =
    {
#if GERMAN
        .name = ITEM_NAME("Kuhmuh-Milch"),
        .pluralName = ITEM_PLURAL_NAME("Kuhmuh-Milch"),
#else
        .name = ITEM_NAME("MOOMOO MILK"),
#endif
        .price = (I_PRICE >= GEN_7) ? 600 : 500,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Milch, die die KP um\n"
            "100 Punkte\n"
            "auffüllt."),
#else
            "A nutritious milk\n"
            "that restores HP\n"
            "by 100 points."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_MoomooMilk,
        .flingPower = 30,
        .iconPic = gItemIcon_MoomooMilk,
        .iconPalette = gItemIconPalette_MoomooMilk,
    },

    [ITEM_ENERGY_POWDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Energiestaub"),
        .pluralName = ITEM_PLURAL_NAME("Energiestaub"),
#else
        .name = ITEM_NAME("ENERGY POWDER"),
#endif
        .price = 500,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Ein bitteres Pul-\n"
            "ver, das die KP um\n"
            "60 Punkte auffüllt."),
#else
            "by 60 points."),
#endif
        #else
#if GERMAN
            "Ein bitteres Pul-\n"
            "ver, das die KP um\n"
            "50 Punkte auffüllt."),
#else
            "by 50 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_EnergyPowder,
    },

    [ITEM_ENERGY_ROOT] =
    {
#if GERMAN
        .name = ITEM_NAME("Kraftwurzel"),
        .pluralName = ITEM_PLURAL_NAME("Kraftwurzeln"),
#else
        .name = ITEM_NAME("ENERGY ROOT"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1200 : 800,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Eine Wurzel, die die\n"
            "KP um 120 Punkte\n"
            "auffüllt."),
#else
            "by 120 points."),
#endif
        #else
#if GERMAN
            "Eine Wurzel, die die\n"
            "KP um 200 Punkte\n"
            "auffüllt."),
#else
            "by 200 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_EnergyRoot,
        .flingPower = 30,
        .iconPic = gItemIcon_EnergyRoot,
        .iconPalette = gItemIconPalette_EnergyRoot,
    },

    [ITEM_HEAL_POWDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Heilpuder"),
        .pluralName = ITEM_PLURAL_NAME("Heilpuder"),
#else
        .name = ITEM_NAME("HEAL POWDER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 450,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein bitteres Pul-\n"
            "ver, das alle Sta-\n"
            "tusprobleme heilt."),
#else
            "A bitter powder\n"
            "that heals all\n"
            "status problems."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_HealPowder,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_HealPowder,
    },

    [ITEM_REVIVAL_HERB] =
    {
#if GERMAN
        .name = ITEM_NAME("Vitalkraut"),
        .pluralName = ITEM_PLURAL_NAME("Vitalkräuter"),
#else
        .name = ITEM_NAME("REVIVAL HERB"),
#endif
        .price = 2800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein bitteres Kraut,\n"
            "das besiegte\n"
            "Pokémon belebt."),
#else
            "A very bitter herb\n"
            "that revives a\n"
            "fainted Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_RevivalHerb,
        .flingPower = 30,
        .iconPic = gItemIcon_RevivalHerb,
        .iconPalette = gItemIconPalette_RevivalHerb,
    },

    [ITEM_ANTIDOTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gegengift"),
        .pluralName = ITEM_PLURAL_NAME("Gegengifte"),
#else
        .name = ITEM_NAME("ANTIDOTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 200 : 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt Vergiftung\n"
            "eines Pokémon."),
#else
            "Heals a poisoned\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Antidote,
    },

    [ITEM_PARALYZE_HEAL] =
    {
#if GERMAN
        .name = ITEM_NAME("Para-Heiler"),
        .pluralName = ITEM_PLURAL_NAME("Para-Heiler"),
#else
        .name = ITEM_NAME("PARALYZE HEAL"),
#endif
        .price = (I_PRICE == GEN_7) ? 300 : 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt Paralyse\n"
            "eines Pokémon."),
#else
            "Heals a paralyzed\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_ParalyzeHeal,
    },

    [ITEM_BURN_HEAL] =
    {
#if GERMAN
        .name = ITEM_NAME("Feuerheiler"),
        .pluralName = ITEM_PLURAL_NAME("Feuerheiler"),
#else
        .name = ITEM_NAME("BURN HEAL"),
#endif
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt Verbrennung\n"
            "eines Pokémon."),
#else
            "Heals Pokémon\n"
            "of a burn."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_BurnHeal,
    },

    [ITEM_ICE_HEAL] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisheiler"),
        .pluralName = ITEM_PLURAL_NAME("Eisheiler"),
#else
        .name = ITEM_NAME("ICE HEAL"),
#endif
    #if I_PRICE >= GEN_8
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Taut Pokémon\n"
            "wieder auf."),
#else
            "Defrosts a frozen\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_IceHeal,
    },

    [ITEM_AWAKENING] =
    {
#if GERMAN
        .name = ITEM_NAME("Aufwecker"),
        .pluralName = ITEM_PLURAL_NAME("Aufwecker"),
#else
        .name = ITEM_NAME("AWAKENING"),
#endif
    #if (I_PRICE >= GEN_8 || I_PRICE == GEN_1)
        .price = 200,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 250,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Weckt schlafendes\n"
            "Pokémon auf."),
#else
            "Awakens a sleeping\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_StatusHeal,
        .iconPalette = gItemIconPalette_Awakening,
    },

    [ITEM_FULL_HEAL] =
    {
#if GERMAN
        .name = ITEM_NAME("Hyperheiler"),
        .pluralName = ITEM_PLURAL_NAME("Hyperheiler"),
#else
        .name = ITEM_NAME("FULL HEAL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 400 : 600,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_FullHeal,
        .iconPalette = gItemIconPalette_FullHeal,
    },

    [ITEM_ETHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Äther"),
        .pluralName = ITEM_PLURAL_NAME("Äther"),
#else
        .name = ITEM_NAME("ETHER"),
#endif
        .price = (I_PRICE >= GEN_2) ? 1200 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt AP einer\n"
            "Attacke um 10\n"
            "Punkte auf."),
#else
            "Restores the PP\n"
            "of a selected move\n"
            "by 10."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Ether,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Ether,
    },

    [ITEM_MAX_ETHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Äther"),
        .pluralName = ITEM_PLURAL_NAME("Top-Äther"),
#else
        .name = ITEM_NAME("MAX ETHER"),
#endif
        .price = (I_PRICE >= GEN_2) ? 2000 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt AP einer\n"
            "Attacke\n"
            "vollständig auf."),
#else
            "Fully restores the\n"
            "PP of a selected\n"
            "move."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxEther,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxEther,
    },

    [ITEM_ELIXIR] =
    {
#if GERMAN
        .name = ITEM_NAME("Elixier"),
        .pluralName = ITEM_PLURAL_NAME("Elixiere"),
#else
        .name = ITEM_NAME("ELIXIR"),
#endif
        .price = (I_PRICE >= GEN_2) ? 3000 : 1,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt alle AP eines\n"
            "Pokémon um 10\n"
            "Punkte auf."),
#else
            "Restores the PP\n"
            "of all moves by 10."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_Elixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_Elixir,
    },

    [ITEM_MAX_ELIXIR] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Elixier"),
        .pluralName = ITEM_PLURAL_NAME("Top-Elixiere"),
#else
        .name = ITEM_NAME("MAX ELIXIR"),
#endif
        .price = (I_PRICE >= GEN_2) ? 4500 : 1,
        .holdEffectParam = 255,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt alle AP eines\n"
            "Pokémon\n"
            "vollständig auf."),
#else
            "Fully restores the\n"
            "PP of a Pokémon's\n"
            "moves."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_PP_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_MaxElixir,
        .flingPower = 30,
        .iconPic = gItemIcon_Ether,
        .iconPalette = gItemIconPalette_MaxElixir,
    },

    [ITEM_BERRY_JUICE] =
    {
#if GERMAN
        .name = ITEM_NAME("Beerensaft"),
        .pluralName = ITEM_PLURAL_NAME("Beerensäfte"),
#else
        .name = ITEM_NAME("BERRY JUICE"),
#endif
        .price = 100,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Reiner Fruchtsaft,\n"
            "der die KP um 20\n"
            "Punkte auffüllt."),
#else
            "A 100% pure juice\n"
            "that restores HP\n"
            "by 20 points."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_BerryJuice,
        .iconPalette = gItemIconPalette_BerryJuice,
    },

    [ITEM_SACRED_ASH] =
    {
#if GERMAN
        .name = ITEM_NAME("Zauberasche"),
        .pluralName = ITEM_PLURAL_NAME("Zauberaschen"),
#else
        .name = ITEM_NAME("SACRED ASH"),
        .pluralName = ITEM_PLURAL_NAME("Sacred Ashes"),
#endif
        .price = (I_PRICE >= GEN_7) ? 50000 : 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Belebt und\n"
            "erfrischt alle\n"
            "besiegten Pokémon."),
#else
            "Fully revives and\n"
            "restores all\n"
            "fainted Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_SacredAsh,
        .effect = gItemEffect_SacredAsh,
        .flingPower = 30,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_SacredAsh,
    },

    [ITEM_SWEET_HEART] =
    {
#if GERMAN
        .name = ITEM_NAME("Herzkonfekt"),
#else
        .name = ITEM_NAME("SWEET HEART"),
#endif
        .price = (I_PRICE >= GEN_7) ? 3000 : 100,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein süßer Schokos-\n"
            "nack, der die KP um\n"
            "20 Punkte auffüllt."),
#else
            "A sweet chocolate\n"
            "that restores HP\n"
            "by 20 points."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Potion,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetHeart,
        .iconPalette = gItemIconPalette_SweetHeart,
    },

    [ITEM_MAX_HONEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Dyna-Honig"),
#else
        .name = ITEM_NAME("MAX HONEY"),
        .pluralName = ITEM_PLURAL_NAME("Max Honey"),
#endif
        .price = 8000,
        .description = sMaxReviveDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_REVIVE,
        .effect = gItemEffect_MaxRevive,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxHoney,
        .iconPalette = gItemIconPalette_MaxHoney,
    },

// Regional Specialties

    [ITEM_PEWTER_CRUNCHIES] =
    {
#if GERMAN
        .name = ITEM_NAME("Marmoria-Kräcker"),
#else
        .name = ITEM_NAME("PEWTER CRUNCHIES"),
        .pluralName = ITEM_PLURAL_NAME("Pewter Crunchies"),
#endif
        .price = 250,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_PewterCrunchies,
        .iconPalette = gItemIconPalette_PewterCrunchies,
    },

    [ITEM_RAGE_CANDY_BAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Wutkeks"),
        .pluralName = ITEM_PLURAL_NAME("Wutkekse"),
#else
        .name = ITEM_NAME("RAGE CANDY BAR"),
#endif
        .price = (I_PRICE >= GEN_7) ? 350 : 300,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_RageCandyBar,
        .iconPalette = gItemIconPalette_RageCandyBar,
    },

    [ITEM_LAVA_COOKIE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lavakeks"),
        .pluralName = ITEM_PLURAL_NAME("Lavakekse"),
#else
        .name = ITEM_NAME("LAVA COOKIE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine regionale Spe-\n"
            "zialität. Heilt alle\n"
            "Statusprobleme."),
#else
            "A local specialty\n"
            "that heals all\n"
            "status problems."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LavaCookie,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_OLD_GATEAU] =
    {
#if GERMAN
        .name = ITEM_NAME("Spezialität"),
        .pluralName = ITEM_PLURAL_NAME("Spezialitäten"),
#else
        .name = ITEM_NAME("OLD GATEAU"),
        .pluralName = ITEM_PLURAL_NAME("Old Gateaux"),
#endif
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_OldGateau,
        .iconPalette = gItemIconPalette_OldGateau,
    },

    [ITEM_CASTELIACONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Stratos-Eis"),
#else
        .name = ITEM_NAME("CASTELIACONE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 350 : 100,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_Casteliacone,
        .iconPalette = gItemIconPalette_Casteliacone,
    },

    [ITEM_LUMIOSE_GALETTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Illumina-Galette"),
        .pluralName = ITEM_PLURAL_NAME("Illumina-Galetten"),
#else
        .name = ITEM_NAME("LUMIOSE GALETTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_LumioseGalette,
        .iconPalette = gItemIconPalette_LumioseGalette,
    },

    [ITEM_SHALOUR_SABLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Yantara-Sablé"),
#else
        .name = ITEM_NAME("SHALOUR SABLE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 350 : 200,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_ShalourSable,
        .iconPalette = gItemIconPalette_ShalourSable,
    },

    [ITEM_BIG_MALASADA] =
    {
#if GERMAN
        .name = ITEM_NAME("Maxi-Malasada"),
#else
        .name = ITEM_NAME("BIG MALASADA"),
#endif
        .price = 350,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMalasada,
        .iconPalette = gItemIconPalette_BigMalasada,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
#if GERMAN
        .name = ITEM_NAME("KP-Plus"),
        .pluralName = ITEM_PLURAL_NAME("KP-Plus"),
#else
        .name = ITEM_NAME("HP UP"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt die KP eines\n"
            "Pokémon."),
#else
            "Raises the base HP\n"
            "of one Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_HPUp,
        .iconPalette = gItemIconPalette_HPUp,
    },

    [ITEM_PROTEIN] =
    {
#if GERMAN
        .name = ITEM_NAME("Protein"),
        .pluralName = ITEM_PLURAL_NAME("Proteine"),
#else
        .name = ITEM_NAME("PROTEIN"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt den Angr.-Wert\n"
            "eines Pokémon."),
#else
            "Raises the base\n"
            "Attack stat of one\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Protein,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Protein,
    },

    [ITEM_IRON] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisen"),
        .pluralName = ITEM_PLURAL_NAME("Eisen"),
#else
        .name = ITEM_NAME("IRON"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt den Vert.-Wert\n"
            "eines Pokémon."),
#else
            "Raises the base\n"
            "Defense stat of\n"
            "one Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Iron,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Iron,
    },

    [ITEM_CALCIUM] =
    {
#if GERMAN
        .name = ITEM_NAME("Kalzium"),
        .pluralName = ITEM_PLURAL_NAME("Kalzium"),
#else
        .name = ITEM_NAME("CALCIUM"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt den Sp.\n"
            "Angr.-Wert eines\n"
#else
            "Raises the base\n"
            "Sp. Atk stat of one\n"
#endif
            "Pokémon."),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Calcium,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Calcium,
    },

    [ITEM_ZINC] =
    {
#if GERMAN
        .name = ITEM_NAME("Zink"),
        .pluralName = ITEM_PLURAL_NAME("Zink"),
#else
        .name = ITEM_NAME("ZINC"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt den Sp.\n"
            "Vert.-Wert eines\n"
#else
            "Raises the base\n"
            "Sp. Def stat of one\n"
#endif
            "Pokémon."),
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Zinc,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Zinc,
    },

    [ITEM_CARBOS] =
    {
#if GERMAN
        .name = ITEM_NAME("Carbon"),
        .pluralName = ITEM_PLURAL_NAME("Carbon"),
#else
        .name = ITEM_NAME("CARBOS"),
        .pluralName = ITEM_PLURAL_NAME("Carbos"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt den Init.-Wert\n"
            "eines Pokémon."),
#else
            "Raises the base\n"
            "Speed stat of one\n"
            "Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_Carbos,
        .flingPower = 30,
        .iconPic = gItemIcon_Vitamin,
        .iconPalette = gItemIconPalette_Carbos,
    },

    [ITEM_PP_UP] =
    {
#if GERMAN
        .name = ITEM_NAME("AP-Plus"),
        .pluralName = ITEM_PLURAL_NAME("AP-Plus"),
#else
        .name = ITEM_NAME("PP UP"),
#endif
    #if I_PRICE >= GEN_7
        .price = 10000,
    #elif I_PRICE >= GEN_2
        .price = 9800,
    #else
        .price = 1,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt die maximale\n"
            "Anzahl der AP einer\n"
            "Attacke."),
#else
            "Raises the maximum\n"
            "PP of a selected\n"
            "move."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPUp,
        .flingPower = 30,
        .iconPic = gItemIcon_PPUp,
        .iconPalette = gItemIconPalette_PPUp,
    },

    [ITEM_PP_MAX] =
    {
#if GERMAN
        .name = ITEM_NAME("AP-Top"),
        .pluralName = ITEM_PLURAL_NAME("AP-Tops"),
#else
        .name = ITEM_NAME("PP MAX"),
        .pluralName = ITEM_PLURAL_NAME("PP Maxes"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Maximiert die\n"
            "Anzahl der AP einer\n"
            "Attacke."),
#else
            "Raises the PP of a\n"
            "move to its maximum\n"
            "points."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STAT_BOOST_DRINK,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PPUp,
        .effect = gItemEffect_PPMax,
        .flingPower = 30,
        .iconPic = gItemIcon_PPMax,
        .iconPalette = gItemIconPalette_PPMax,
    },

// EV Feathers

    [ITEM_HEALTH_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Heilfeder"),
#else
        .name = ITEM_NAME("HEALTH FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_HealthFeather,
    },

    [ITEM_MUSCLE_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Kraftfeder"),
#else
        .name = ITEM_NAME("MUSCLE FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_MuscleFeather,
    },

    [ITEM_RESIST_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Abwehrfeder"),
#else
        .name = ITEM_NAME("RESIST FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_ResistFeather,
    },

    [ITEM_GENIUS_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Geniefeder"),
#else
        .name = ITEM_NAME("GENIUS FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_GeniusFeather,
    },

    [ITEM_CLEVER_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Espritfeder"),
#else
        .name = ITEM_NAME("CLEVER FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_CleverFeather,
    },

    [ITEM_SWIFT_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Flinkfeder"),
#else
        .name = ITEM_NAME("SWIFT FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 300 : 3000,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_FEATHER,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedFeather,
        .flingPower = 20,
        .iconPic = gItemIcon_EVFeather,
        .iconPalette = gItemIconPalette_SwiftFeather,
    },

// Ability Modifiers

    [ITEM_ABILITY_CAPSULE] =
    {
#if GERMAN
        .name = ITEM_NAME("Fähigk.-Kapsel"),
#else
        .name = ITEM_NAME("ABILITY CAPSULE"),
#endif
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 1000,
    #endif
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Tauscht die\n"
            "Fähigkeit eines\n"
            "Pokémon aus."),
#else
            "Switches a Poké-\n"
            "mon's ability."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityCapsule,
        .iconPic = gItemIcon_AbilityCapsule,
        .iconPalette = gItemIconPalette_AbilityCapsule,
    },

    [ITEM_ABILITY_PATCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Fähigk.-Pflaster"),
#else
        .name = ITEM_NAME("ABILITY PATCH"),
        .pluralName = ITEM_PLURAL_NAME("Ability Patches"),
#endif
        .price = (I_PRICE >= GEN_9) ? 250000 : 20,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht die Fähigkeit\n"
            "zu einer\n"
            "versteckten."),
#else
            "Turns the ability\n"
            "of a Pokémon into\n"
            "a rare ability."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_AbilityPatch,
        .iconPic = gItemIcon_AbilityPatch,
        .iconPalette = gItemIconPalette_AbilityPatch,
    },

// Mints

    [ITEM_LONELY_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Solo-Minze"),
#else
        .name = ITEM_NAME("LONELY MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Angr.\n"
            "schneller, Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Attack, but\n"
            "reduces Defense."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LONELY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_ADAMANT_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Hart-Minze"),
#else
        .name = ITEM_NAME("ADAMANT MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Angr.\n"
            "schneller, Sp. Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Attack, but\n"
            "reduces Sp. Atk."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_ADAMANT,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_NAUGHTY_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Frech-Minze"),
#else
        .name = ITEM_NAME("NAUGHTY MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Angr.\n"
            "schneller, Sp. Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Attack, but\n"
            "reduces Sp. Def."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAUGHTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BRAVE_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Mutig-Minze"),
#else
        .name = ITEM_NAME("BRAVE MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Angr.\n"
            "schneller, Init.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Attack, but\n"
            "reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BRAVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_RedMint,
    },

    [ITEM_BOLD_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Kühn-Minze"),
#else
        .name = ITEM_NAME("BOLD MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Vert.\n"
            "schneller, Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Defense, but\n"
            "reduces Attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_BOLD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_IMPISH_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Pfiffig-Minze"),
#else
        .name = ITEM_NAME("IMPISH MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Vert.\n"
            "schneller, Sp. Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Defense, but\n"
            "reduces Sp. Atk."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_IMPISH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_LAX_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Lasch-Minze"),
#else
        .name = ITEM_NAME("LAX MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Vert.\n"
            "schneller, Sp. Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Defense, but\n"
            "reduces Sp. Def."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_LAX,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_RELAXED_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Locker-Minze"),
#else
        .name = ITEM_NAME("RELAXED MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Vert.\n"
            "schneller, Init.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Defense, but\n"
            "reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RELAXED,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_BlueMint,
    },

    [ITEM_MODEST_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Mäßig-Minze"),
#else
        .name = ITEM_NAME("MODEST MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Angr.\n"
            "schneller, Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "reduces Attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MODEST,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_MILD_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Mild-Minze"),
#else
        .name = ITEM_NAME("MILD MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Angr.\n"
            "schneller, Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "reduces Defense."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_MILD,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_RASH_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Hitzig-Minze"),
#else
        .name = ITEM_NAME("RASH MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Angr.\n"
            "schneller, Sp. Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "reduces Sp. Def."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_RASH,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_QUIET_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Ruhig-Minze"),
#else
        .name = ITEM_NAME("QUIET MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Angr.\n"
            "schneller, Init.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Atk, but\n"
            "reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_QUIET,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_LightBlueMint,
    },

    [ITEM_CALM_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Still-Minze"),
#else
        .name = ITEM_NAME("CALM MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Vert.\n"
            "schneller, Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "reduces Attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CALM,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_GENTLE_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Zart-Minze"),
#else
        .name = ITEM_NAME("GENTLE MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Vert.\n"
            "schneller, Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "reduces Defense."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_GENTLE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_CAREFUL_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Sacht-Minze"),
#else
        .name = ITEM_NAME("CAREFUL MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Vert.\n"
            "schneller, Sp. Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "reduces Sp. Atk."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_CAREFUL,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_SASSY_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Forsch-Minze"),
#else
        .name = ITEM_NAME("SASSY MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Sp. Vert.\n"
            "schneller, Init.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Sp. Def, but\n"
            "reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SASSY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_PinkMint,
    },

    [ITEM_TIMID_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Scheu-Minze"),
#else
        .name = ITEM_NAME("TIMID MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Init.\n"
            "schneller, Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Speed, but\n"
            "reduces Attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_TIMID,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_HASTY_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Hastig-Minze"),
#else
        .name = ITEM_NAME("HASTY MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Init.\n"
            "schneller, Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Speed, but\n"
            "reduces Defense."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_HASTY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_JOLLY_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Froh-Minze"),
#else
        .name = ITEM_NAME("JOLLY MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Init.\n"
            "schneller, Sp. Angr.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Speed, but\n"
            "reduces Sp. Atk."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_JOLLY,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_NAIVE_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Naiv-Minze"),
#else
        .name = ITEM_NAME("NAIVE MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die Init.\n"
            "schneller, Sp. Vert.\n"
            "langsamer steigert."),
#else
            "Can be smelled. It\n"
            "ups Speed, but\n"
            "reduces Sp. Def."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_NAIVE,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_GreenMint,
    },

    [ITEM_SERIOUS_MINT] =
    {
#if GERMAN
        .name = ITEM_NAME("Ernst-Minze"),
#else
        .name = ITEM_NAME("SERIOUS MINT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Minze, die alle\n"
            "Statuswerte gleich\n"
            "schnell steigert."),
#else
            "Can be smelled. It\n"
            "makes each stat\n"
            "grow equally."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NATURE_MINT,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Mint,
        .secondaryId = NATURE_SERIOUS,
        .flingPower = 10,
        .iconPic = gItemIcon_Mint,
        .iconPalette = gItemIconPalette_YellowMint,
    },

// Candy

    [ITEM_RARE_CANDY] =
    {
#if GERMAN
        .name = ITEM_NAME("Sonderbonbon"),
        .pluralName = ITEM_PLURAL_NAME("Sonderbonbons"),
#else
        .name = ITEM_NAME("RARE CANDY"),
        .pluralName = ITEM_PLURAL_NAME("Rare Candies"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 4800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt den Level\n"
            "eines Pokémon um\n"
            "eins an."),
#else
            "Raises the level\n"
            "of a Pokémon by\n"
            "one."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_RareCandy,
    },

    [ITEM_EXP_CANDY_XS] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Bonbon XS"),
        .pluralName = ITEM_PLURAL_NAME("EP-Bonbons XS"),
#else
        .name = ITEM_NAME("EXP. CANDY XS"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies XS"),
#endif
        .price = 20,
        .holdEffectParam = EXP_100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt eine sehr\n"
            "geringe Menge EP."),
#else
            "Gives a very small\n"
            "amount of Exp. to\n"
            "a single Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_S] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Bonbon S"),
        .pluralName = ITEM_PLURAL_NAME("EP-Bonbons S"),
#else
        .name = ITEM_NAME("EXP. CANDY S"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies S"),
#endif
        .price = 240,
        .holdEffectParam = EXP_800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt eine geringe\n"
            "Menge EP."),
#else
            "Gives a small\n"
            "amount of Exp. to\n"
            "a single Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyS,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_M] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Bonbon M"),
        .pluralName = ITEM_PLURAL_NAME("EP-Bonbons M"),
#else
        .name = ITEM_NAME("EXP. CANDY M"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies M"),
#endif
        .price = 1000,
        .holdEffectParam = EXP_3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt eine gewisse\n"
            "Menge EP."),
#else
            "Gives a moderate\n"
            "amount of Exp. to\n"
            "a single Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyM,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_L] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Bonbon L"),
        .pluralName = ITEM_PLURAL_NAME("EP-Bonbons L"),
#else
        .name = ITEM_NAME("EXP. CANDY L"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies L"),
#endif
        .price = 3000,
        .holdEffectParam = EXP_10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt eine große\n"
            "Menge EP."),
#else
            "Gives a large\n"
            "amount of Exp. to\n"
            "a single Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_EXP_CANDY_XL] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Bonbon XL"),
        .pluralName = ITEM_PLURAL_NAME("EP-Bonbons XL"),
#else
        .name = ITEM_NAME("EXP. CANDY XL"),
        .pluralName = ITEM_PLURAL_NAME("Exp. Candies XL"),
#endif
        .price = 10000,
        .holdEffectParam = EXP_30000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gibt eine sehr\n"
            "große Menge EP."),
#else
            "Gives a very large\n"
            "amount of Exp. to\n"
            "a single Pokémon."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RareCandy,
        .effect = gItemEffect_RareCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpCandyXL,
        .iconPalette = gItemIconPalette_ExpCandies,
    },

    [ITEM_DYNAMAX_CANDY] =
    {
#if GERMAN
        .name = ITEM_NAME("Dynamax-Bonbon"),
        .pluralName = ITEM_PLURAL_NAME("Dynamax-Bonbons"),
#else
        .name = ITEM_NAME("DYNAMAX CANDY"),
        .pluralName = ITEM_PLURAL_NAME("Dynamax Candies"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt Dynamax-Level\n"
            "um eins. Mehr KP bei\n"
            "Dynamaxierung."),
#else
            "Raises the Dynamax\n"
            "Level of a single\n"
            "Pokémon by one."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_LEVEL_UP_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_DynamaxCandy,
        .flingPower = 30,
        .iconPic = gItemIcon_DynamaxCandy,
        .iconPalette = gItemIconPalette_DynamaxCandy,
    },

// Medicinal Flutes

    [ITEM_BLUE_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Blaue Flöte"),
        .pluralName = ITEM_PLURAL_NAME("Blaue Flöten"),
#else
        .name = ITEM_NAME("BLUE FLUTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 20 : 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine gläserne Flöte,\n"
            "die schlafende\n"
            "Pokémon aufweckt."),
#else
            "A glass flute that\n"
            "awakens sleeping\n"
            "Pokémon."),
#endif
        .notConsumed = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlueFlute,
    },

    [ITEM_YELLOW_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gelbe Flöte"),
        .pluralName = ITEM_PLURAL_NAME("Gelbe Flöten"),
#else
        .name = ITEM_NAME("YELLOW FLUTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 20 : 300,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine gläserne Flöte,\n"
            "die verwirrte\n"
            "Pokémon heilt."),
#else
            "A glass flute that\n"
            "snaps Pokémon\n"
            "out of confusion."),
#endif
        .notConsumed = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_YellowFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_YellowFlute,
    },

    [ITEM_RED_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Rote Flöte"),
        .pluralName = ITEM_PLURAL_NAME("Rote Flöten"),
#else
        .name = ITEM_NAME("RED FLUTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 20 : 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine gläserne Flöte,\n"
            "die Pokémon von\n"
            "Anziehung heilt."),
#else
            "A glass flute that\n"
            "snaps Pokémon\n"
            "out of attraction."),
#endif
        .notConsumed = TRUE,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_RedFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_RedFlute,
    },

// Encounter-modifying Flutes

    [ITEM_BLACK_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Schw. Flöte"),
        .pluralName = ITEM_PLURAL_NAME("Schw. Flöten"),
#else
        .name = ITEM_NAME("BLACK FLUTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 20 : 400,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine gläserne Flöte,\n"
            "die wilde Pokémon\n"
            "abhält."),
#else
            "A glass flute that\n"
            "keeps away wild\n"
            "Pokémon."),
#endif
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_BlackFlute,
    },

    [ITEM_WHITE_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Weiße Flöte"),
        .pluralName = ITEM_PLURAL_NAME("Weiße Flöten"),
#else
        .name = ITEM_NAME("WHITE FLUTE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 20 : 500,
        .holdEffectParam = 150,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine gläserne Flöte,\n"
            "die wilde Pokémon\n"
            "anzieht."),
#else
            "A glass flute that\n"
            "lures wild Pokémon."),
#endif
        .notConsumed = TRUE,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FLUTE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_BlackWhiteFlute,
        .flingPower = 30,
        .iconPic = gItemIcon_Flute,
        .iconPalette = gItemIconPalette_WhiteFlute,
    },

// Encounter Modifiers

    [ITEM_REPEL] =
    {
#if GERMAN
        .name = ITEM_NAME("Schutz"),
        .pluralName = ITEM_PLURAL_NAME("Schutze"),
#else
        .name = ITEM_NAME("REPEL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 400 : 350,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält 100 Schritte\n"
            "lang schwache,\n"
            "wilde Pokémon ab."),
#else
            "Repels weak wild\n"
            "Pokémon for 100\n"
            "steps."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_Repel,
    },

    [ITEM_SUPER_REPEL] =
    {
#if GERMAN
        .name = ITEM_NAME("Superschutz"),
        .pluralName = ITEM_PLURAL_NAME("Superschutze"),
#else
        .name = ITEM_NAME("SUPER REPEL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 700 : 500,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält 200 Schritte\n"
            "lang schwache,\n"
            "wilde Pokémon ab."),
#else
            "Repels weak wild\n"
            "Pokémon for 200\n"
            "steps."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_SuperRepel,
    },

    [ITEM_MAX_REPEL] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Schutz"),
        .pluralName = ITEM_PLURAL_NAME("Top-Schutze"),
#else
        .name = ITEM_NAME("MAX REPEL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 900 : 700,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält 250 Schritte\n"
            "lang schwache,\n"
            "wilde Pokémon ab."),
#else
            "Repels weak wild\n"
            "Pokémon for 250\n"
            "steps."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Repel,
        .flingPower = 30,
        .iconPic = gItemIcon_Repel,
        .iconPalette = gItemIconPalette_MaxRepel,
    },

    [ITEM_LURE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lockparfüm"),
#else
        .name = ITEM_NAME("LURE"),
#endif
        .price = 400,
        .holdEffectParam = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Lockt 100 Schritte\n"
            "lang wilde Pokémon\n"
            "an."),
#else
            "Makes Pokémon more\n"
            "likely to appear\n"
            "for 100 steps."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_Lure,
    },

    [ITEM_SUPER_LURE] =
    {
#if GERMAN
        .name = ITEM_NAME("Super-Lockparfüm"),
#else
        .name = ITEM_NAME("SUPER LURE"),
#endif
        .price = 700,
        .holdEffectParam = 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Lockt 200 Schritte\n"
            "lang wilde Pokémon\n"
            "an."),
#else
            "Makes Pokémon more\n"
            "likely to appear\n"
            "for 200 steps."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_SuperLure,
    },

    [ITEM_MAX_LURE] =
    {
#if GERMAN
        .name = ITEM_NAME("Top-Lockparfüm"),
#else
        .name = ITEM_NAME("MAX LURE"),
#endif
        .price = 900,
        .holdEffectParam = 250,
        .description = COMPOUND_STRING(
#if GERMAN
            "Lockt 250 Schritte\n"
            "lang wilde Pokémon\n"
            "an."),
#else
            "Makes Pokémon more\n"
            "likely to appear\n"
            "for 250 steps."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Lure,
        .secondaryId = 0,
        .flingPower = 30,
        .iconPic = gItemIcon_Lure,
        .iconPalette = gItemIconPalette_MaxLure,
    },

    [ITEM_ESCAPE_ROPE] =
    {
#if GERMAN
        .name = ITEM_NAME("Fluchtseil"),
#else
        .name = ITEM_NAME("ESCAPE ROPE"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Ermöglicht die\n"
            "Flucht aus Höhlen\n"
            "oder Ähnlichem."),
#else
            "Use to escape\n"
            "instantly from a\n"
            "cave or a dungeon."),
#endif
    #if I_KEY_ESCAPE_ROPE >= GEN_8
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #else
        //.price = (I_PRICE >= GEN_7) ? 1000 : 550,
        .price = 100,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FIELD_USE,
    #endif
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_EscapeRope,
        .flingPower = 30,
        .iconPic = gItemIcon_EscapeRope,
        .iconPalette = gItemIconPalette_EscapeRope,
    },

// X Items

    [ITEM_X_ATTACK] =
    {
#if GERMAN
        .name = ITEM_NAME("X-Angriff"),
        .pluralName = ITEM_PLURAL_NAME("X-Angriffe"),
#else
        .name = ITEM_NAME("X ATTACK"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt den Angr.-Wert\n"
            "stark für einen\n"
            "Kampf."),
#else
            "Sharply raises stat\n"
            "Attack during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt den\n"
            "Angr.-Wert\n"
            "für einen Kampf."),
#else
            "Raises the stat\n"
            "Attack during one\n"
            "battle."),
#endif
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAttack,
    },

    [ITEM_X_DEFENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("X-Abwehr"),
        .pluralName = ITEM_PLURAL_NAME("X-Abwehr"),
#else
        .name = ITEM_NAME("X DEFENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 550,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt den Vert.-Wert\n"
            "stark für einen\n"
            "Kampf."),
#else
            "Sharply raises stat\n"
            "Defense during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt den\n"
            "Vert.-Wert\n"
            "für einen Kampf."),
#else
            "Raises the stat\n"
            "Defense during one\n"
            "battle."),
#endif
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XDefend,
    },

    [ITEM_X_SP_ATK] =
    {
#if GERMAN
        .name = ITEM_NAME("X-Spezial"),
        .pluralName = ITEM_PLURAL_NAME("X-Spezial"),
#else
        .name = ITEM_NAME("X SP. ATK"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt Sp. Angr. stark\n"
            "für einen Kampf."),
#else
            "Sharply raises stat\n"
            "Sp. Atk during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt den Sp. Angr.-\n"
            "Wert für einen\n"
            "Kampf."),
#else
            "Raises the stat\n"
            "Sp. Atk during one\n"
            "battle."),
#endif
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialAttack,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecial,
    },

    [ITEM_X_SP_DEF] =
    {
#if GERMAN
        .name = ITEM_NAME("X-Spezial-Vert."),
#else
        .name = ITEM_NAME("X SP. DEF"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt Sp. Vert. stark\n"
            "für einen Kampf."),
#else
            "Sharply raises stat\n"
            "Sp. Def during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt den Sp. Vert.-\n"
            "Wert für einen\n"
            "Kampf."),
#else
            "Raises the stat\n"
            "Sp. Def during one\n"
            "battle."),
#endif
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpecialDefense,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpecialDefense,
    },

    [ITEM_X_SPEED] =
    {
#if GERMAN
        .name = ITEM_NAME("X-Tempo"),
        .pluralName = ITEM_PLURAL_NAME("X-Tempos"),
#else
        .name = ITEM_NAME("X SPEED"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 350,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt den Init.-Wert\n"
            "stark für einen\n"
            "Kampf."),
#else
            "Sharply raises stat\n"
            "Speed during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt den\n"
            "Init.-Wert\n"
            "für einen Kampf."),
#else
            "Raises the stat\n"
            "Speed during one\n"
            "battle."),
#endif
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XSpeed,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XSpeed,
    },

    [ITEM_X_ACCURACY] =
    {
#if GERMAN
        .name = ITEM_NAME("X-Treffer"),
        .pluralName = ITEM_PLURAL_NAME("X-Treffer"),
#else
        .name = ITEM_NAME("X ACCURACY"),
        .pluralName = ITEM_PLURAL_NAME("X Accuracies"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 950,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt die Genauig-\n"
            "keit stark für\n"
            "einen Kampf."),
#else
            "Sharply raises move\n"
            "accuracy during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt die\n"
            "Genauigkeit\n"
            "für einen Kampf."),
#else
            "Raises accuracy\n"
            "of attack moves\n"
            "during one battle."),
#endif
        #endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_STAT,
        .effect = gItemEffect_XAccuracy,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_XAccuracy,
    },

    [ITEM_DIRE_HIT] =
    {
#if GERMAN
        .name = ITEM_NAME("Angriffplus"),
        .pluralName = ITEM_PLURAL_NAME("Angriffplus"),
#else
        .name = ITEM_NAME("DIRE HIT"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 650,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt die\n"
            "Volltrefferquote\n"
            "für einen Kampf."),
#else
            "Raises the\n"
            "critical-hit ratio\n"
            "during one battle."),
#endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_FOCUS_ENERGY,
        .effect = gItemEffect_DireHit,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_DireHit,
    },

    [ITEM_GUARD_SPEC] =
    {
#if GERMAN
        .name = ITEM_NAME("Megablock"),
        .pluralName = ITEM_PLURAL_NAME("Megablocks"),
#else
        .name = ITEM_NAME("GUARD SPEC."),
        .pluralName = ITEM_PLURAL_NAME("Guard Specs."),
#endif
        .price = (I_PRICE >= GEN_7) ? 1500 : 700,
        .description = COMPOUND_STRING(
#if GERMAN
            "Statusänderung\n"
            "wird für einen\n"
            "Kampf verhindert."),
#else
            "Prevents stat\n"
            "reduction when\n"
            "used in battle."),
#endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_X_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_SET_MIST,
        .effect = gItemEffect_GuardSpec,
        .flingPower = 30,
        .iconPic = gItemIcon_BattleStatItem,
        .iconPalette = gItemIconPalette_GuardSpec,
    },

    [ITEM_POKE_DOLL] =
    {
#if GERMAN
        .name = ITEM_NAME("Poképuppe"),
        .pluralName = ITEM_PLURAL_NAME("Poképuppen"),
#else
        .name = ITEM_NAME("POKé DOLL"),
#endif
    #if I_PRICE >= GEN_8
        .price = 300,
    #elif I_PRICE == GEN_7
        .price = 100,
    #else
        .price = 1000,
    #endif
        .description = sPokeDollDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeDoll,
        .iconPalette = gItemIconPalette_PokeDoll,
    },

    [ITEM_FLUFFY_TAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Eneco-Rute"),
        .pluralName = ITEM_PLURAL_NAME("Eneco-Ruten"),
#else
        .name = ITEM_NAME("FLUFFY TAIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_FluffyTail,
        .iconPalette = gItemIconPalette_FluffyTail,
    },

    [ITEM_POKE_TOY] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokéwedel"),
#else
        .name = ITEM_NAME("POKé TOY"),
#endif
        .price = (I_PRICE >= GEN_7) ? 100 : 1000,
        .description = sPokeDollDesc,
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_ESCAPE,
        .flingPower = 30,
        .iconPic = gItemIcon_PokeToy,
        .iconPalette = gItemIconPalette_PokeToy,
    },

    [ITEM_MAX_MUSHROOMS] =
    {
#if GERMAN
        .name = ITEM_NAME("Dyna-Pilz"),
        .pluralName = ITEM_PLURAL_NAME("Dyna-Pilze"),
#else
        .name = ITEM_NAME("MAX MUSHROOMS"),
        .pluralName = ITEM_PLURAL_NAME("Max Mushrooms"),
#endif
        .price = 8000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt alle\n"
            "Statuswerte für\n"
            "einen Kampf."),
#else
            "Raises every stat\n"
            "during one battle\n"
            "by one stage."),
#endif
        .pocket = POCKET_BATTLE_ITEMS,
        .sortType = ITEM_TYPE_BATTLE_ITEM,
        .type = B_X_ITEMS_CROSSUSE ? ITEM_USE_BATTLER : ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_INCREASE_ALL_STATS,
        .flingPower = 30,
        .iconPic = gItemIcon_MaxMushrooms,
        .iconPalette = gItemIconPalette_MaxMushrooms,
    },

// Treasures

    [ITEM_BOTTLE_CAP] =
    {
#if GERMAN
        .name = ITEM_NAME("Silberkronkorken"),
#else
        .name = ITEM_NAME("BOTTLE CAP"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 5000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hübscher silberner\n"
            "Kronkorken von\n"
            "sehr hohem Wert."),
#else
            "A beautiful bottle\n"
            "cap that gives off\n"
            "a silver gleam."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_BottleCap,
    },

    [ITEM_GOLD_BOTTLE_CAP] =
    {
#if GERMAN
        .name = ITEM_NAME("Goldkronkorken"),
#else
        .name = ITEM_NAME("GOLD BOTTLE CAP"),
#endif
        .price = (I_PRICE >= GEN_9) ? 60000 : 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hübscher goldener\n"
            "Kronkorken von\n"
            "sehr hohem Wert."),
#else
            "A beautiful bottle\n"
            "cap that gives off\n"
            "a golden gleam."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BottleCap,
        .iconPalette = gItemIconPalette_GoldBottleCap,
    },

    [ITEM_NUGGET] =
    {
#if GERMAN
        .name = ITEM_NAME("Nugget"),
        .pluralName = ITEM_PLURAL_NAME("Nuggets"),
#else
        .name = ITEM_NAME("NUGGET"),
#endif
        .price = 10000 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Barren aus\n"
            "purem Gold, der von\n"
            "hohem Wert ist."),
#else
            "A nugget of pure\n"
            "gold. Can be sold at\n"
            "a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Nugget,
        .iconPalette = gItemIconPalette_Nugget,
    },

    [ITEM_BIG_NUGGET] =
    {
#if GERMAN
        .name = ITEM_NAME("Riesennugget"),
#else
        .name = ITEM_NAME("BIG NUGGET"),
#endif
    #if I_PRICE >= GEN_7
        .price = 40000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 20000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Großer Barren aus\n"
            "purem Gold von sehr\n"
            "hohem Wert."),
#else
            "A big nugget made\n"
            "of gold, sellable\n"
            "at a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = B_UPDATED_MOVE_DATA >= GEN_8 ? 130 : 80,
        .iconPic = gItemIcon_BigNugget,
        .iconPalette = gItemIconPalette_BigNugget,
    },

    [ITEM_TINY_MUSHROOM] =
    {
#if GERMAN
        .name = ITEM_NAME("Minipilz"),
        .pluralName = ITEM_PLURAL_NAME("Minipilze"),
#else
        .name = ITEM_NAME("TINY MUSHROOM"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein gemeiner Pilz\n"
            "von geringem Wert."),
#else
            "A plain mushroom\n"
            "that would sell\n"
            "at a cheap price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BIG_MUSHROOM] =
    {
#if GERMAN
        .name = ITEM_NAME("Riesenpilz"),
        .pluralName = ITEM_PLURAL_NAME("Riesenpilze"),
#else
        .name = ITEM_NAME("BIG MUSHROOM"),
#endif
        .price = 5000 * TREASURE_FACTOR,
        .description = sBigMushroomDesc,
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigMushroom,
        .iconPalette = gItemIconPalette_Mushroom,
    },

    [ITEM_BALM_MUSHROOM] =
    {
#if GERMAN
        .name = ITEM_NAME("Duftpilz"),
        .pluralName = ITEM_PLURAL_NAME("Duftpilze"),
#else
        .name = ITEM_NAME("BALM MUSHROOM"),
#endif
    #if I_PRICE >= GEN_7
        .price = 15000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_6
        .price = 12500,
    #else
        .price = 0,
    #endif
        .description = sBigMushroomDesc,
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BalmMushroom,
        .iconPalette = gItemIconPalette_BalmMushroom,
    },

    [ITEM_PEARL] =
    {
#if GERMAN
        .name = ITEM_NAME("Perle"),
        .pluralName = ITEM_PLURAL_NAME("Perlen"),
#else
        .name = ITEM_NAME("PEARL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR: 1400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine hübsche Perle\n"
            "von geringem Wert."),
#else
            "A pretty pearl\n"
            "that would sell at a\n"
            "cheap price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Pearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_BIG_PEARL] =
    {
#if GERMAN
        .name = ITEM_NAME("Riesenperle"),
        .pluralName = ITEM_PLURAL_NAME("Riesenperlen"),
#else
        .name = ITEM_NAME("BIG PEARL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 8000 * TREASURE_FACTOR: 7500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schöne, große Perle\n"
            "von hohem Wert."),
#else
            "A lovely large pearl\n"
            "that would sell at a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigPearl,
        .iconPalette = gItemIconPalette_Pearl,
    },

    [ITEM_PEARL_STRING] =
    {
#if GERMAN
        .name = ITEM_NAME("Triperle"),
        .pluralName = ITEM_PLURAL_NAME("Triperlen"),
#else
        .name = ITEM_NAME("PEARL STRING"),
#endif
    #if I_PRICE >= GEN_8
        .price = 20000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 30000,
    #elif I_PRICE == GEN_6
        .price = 15000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr große Perlen\n"
            "von sehr hohem\n"
            "Wert."),
#else
            "Very large pearls\n"
            "that would sell at a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PearlString,
        .iconPalette = gItemIconPalette_PearlString,
    },

    [ITEM_STARDUST] =
    {
#if GERMAN
        .name = ITEM_NAME("Sternenstaub"),
        .pluralName = ITEM_PLURAL_NAME("Sternenstaube"),
#else
        .name = ITEM_NAME("STARDUST"),
#endif
        .price = (I_PRICE >= GEN_7) ? 3000 * TREASURE_FACTOR: 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schöner, roter\n"
            "Sand, der von\n"
            "großem Wert ist."),
#else
            "Beautiful red sand.\n"
            "Can be sold at a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_STAR_PIECE] =
    {
#if GERMAN
        .name = ITEM_NAME("Sternenstück"),
        .pluralName = ITEM_PLURAL_NAME("Sternenstücke"),
#else
        .name = ITEM_NAME("STAR PIECE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 12000 * TREASURE_FACTOR: 9800,
        .description = COMPOUND_STRING(
#if GERMAN
            "Roter Edelstein von\n"
            "hohem Wert."),
#else
            "A red gem shard.\n"
            "It would sell for a\n"
            "very high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_Star,
    },

    [ITEM_COMET_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Kometstück"),
        .pluralName = ITEM_PLURAL_NAME("Kometstücke"),
#else
        .name = ITEM_NAME("COMET SHARD"),
#endif
    #if I_PRICE >= GEN_8
        .price = 25000 * TREASURE_FACTOR,
    #elif I_PRICE == GEN_7
        .price = 60000,
    #elif I_PRICE == GEN_6
        .price = 30000,
    #else
        .price = 0,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Splitter aus dem All\n"
            "von sehr hohem\n"
            "Wert."),
#else
            "A comet's shard.\n"
            "It would sell for a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StarPiece,
        .iconPalette = gItemIconPalette_CometShard,
    },

    [ITEM_SHOAL_SALT] =
    {
#if GERMAN
        .name = ITEM_NAME("Küstensalz"),
        .pluralName = ITEM_PLURAL_NAME("Küstensalz"),
#else
        .name = ITEM_NAME("SHOAL SALT"),
#endif
        .price = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Salz, das sich tief\n"
            "in der Küsten-\n"
            "Höhle befand."),
#else
            "Salt obtained from\n"
            "deep inside the\n"
            "Shoal Cave."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Powder,
        .iconPalette = gItemIconPalette_ShoalSalt,
    },

    [ITEM_SHOAL_SHELL] =
    {
#if GERMAN
        .name = ITEM_NAME("Küstenschale"),
        .pluralName = ITEM_PLURAL_NAME("Küstenschalen"),
#else
        .name = ITEM_NAME("SHOAL SHELL"),
#endif
        .price = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Muschelschale, die\n"
            "sich in der Küsten-\n"
            "höhle befand."),
#else
            "A seashell found\n"
            "deep inside the\n"
            "Shoal Cave."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShoalShell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_RED_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Purpurstück"),
        .pluralName = ITEM_PLURAL_NAME("Purpurstücke"),
#else
        .name = ITEM_NAME("RED SHARD"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_RedShard,
    },

    [ITEM_BLUE_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Indigostück"),
        .pluralName = ITEM_PLURAL_NAME("Indigostücke"),
#else
        .name = ITEM_NAME("BLUE SHARD"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_BlueShard,
    },

    [ITEM_YELLOW_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Gelbstück"),
        .pluralName = ITEM_PLURAL_NAME("Gelbstücke"),
#else
        .name = ITEM_NAME("YELLOW SHARD"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_YellowShard,
    },

    [ITEM_GREEN_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Grünstück"),
        .pluralName = ITEM_PLURAL_NAME("Grünstücke"),
#else
        .name = ITEM_NAME("GREEN SHARD"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .description = sShardsDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Shard,
        .iconPalette = gItemIconPalette_GreenShard,
    },

    [ITEM_HEART_SCALE] =
    {
#if GERMAN
        .name = ITEM_NAME("Herzschuppe"),
        .pluralName = ITEM_PLURAL_NAME("Herzschuppen"),
#else
        .name = ITEM_NAME("HEART SCALE"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hübsche Schuppe,\n"
            "höchst begehrt bei\n"
            "Sammlern."),
#else
            "A lovely scale.\n"
            "It is coveted by\n"
            "collectors."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_HeartScale,
        .iconPalette = gItemIconPalette_HeartScale,
    },

    [ITEM_HONEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Honig"),
        .pluralName = ITEM_PLURAL_NAME("Honige"),
#else
        .name = ITEM_NAME("HONEY"),
        .pluralName = ITEM_PLURAL_NAME("Honey"),
#endif
    #if I_PRICE >= GEN_8
        .price = 900,
    #elif I_PRICE == GEN_7
        .price = 300,
    #else
        .price = 100,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Süßer Honig, dessen\n"
            "Duft wilde Pokémon\n"
            "anlockt."),
#else
            "Sweet honey that\n"
            "attracts wild\n"
            "Pokémon when used."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Honey,
        .flingPower = 30,
        .iconPic = gItemIcon_Honey,
        .iconPalette = gItemIconPalette_Honey,
    },

    [ITEM_RARE_BONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Steinknochen"),
        .pluralName = ITEM_PLURAL_NAME("Steinknochen"),
#else
        .name = ITEM_NAME("RARE BONE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 5000 * TREASURE_FACTOR: 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sehr seltener\n"
            "Knochen von hohem\n"
            "Wert."),
#else
            "A very rare bone.\n"
            "It can be sold at\n"
            "a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_ODD_KEYSTONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Spiritkern"),
        .pluralName = ITEM_PLURAL_NAME("Spiritkerne"),
#else
        .name = ITEM_NAME("ODD KEYSTONE"),
#endif
        .price = 2100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wichtiges Item, mit\n"
            "dem ein Steinturm\n"
            "repariert wird."),
#else
            "Voices can be heard\n"
            "from this odd stone\n"
            "occasionally."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_OddKeystone,
        .iconPalette = gItemIconPalette_OddKeystone,
    },

    [ITEM_PRETTY_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Prachtfeder"),
#else
        .name = ITEM_NAME("PRETTY FEATHER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 * TREASURE_FACTOR: 200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine schöne, aber\n"
            "gewöhnliche Feder\n"
            "von geringem Wert."),
#else
            "A beautiful yet\n"
            "plain feather that\n"
            "does nothing."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 20,
        .iconPic = gItemIcon_PrettyFeather,
        .iconPalette = gItemIconPalette_PrettyFeather,
    },

    [ITEM_RELIC_COPPER] =
    {
#if GERMAN
        .name = ITEM_NAME("Alter Heller"),
#else
        .name = ITEM_NAME("RELIC COPPER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alte Kupfermünze\n"
            "von großem Wert."),
#else
            "A copper coin used\n"
            "long ago. It sells\n"
            "at a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicCopper,
    },

    [ITEM_RELIC_SILVER] =
    {
#if GERMAN
        .name = ITEM_NAME("Alter Taler"),
#else
        .name = ITEM_NAME("RELIC SILVER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alte Silbermünze\n"
            "von hohem Wert."),
#else
            "A silver coin used\n"
            "long ago. It sells\n"
            "at a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicSilver,
    },

    [ITEM_RELIC_GOLD] =
    {
#if GERMAN
        .name = ITEM_NAME("Alter Dukat"),
#else
        .name = ITEM_NAME("RELIC GOLD"),
#endif
        .price = (I_PRICE >= GEN_6) ? 60000 : 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alte Goldmünze von\n"
            "sehr hohem Wert."),
#else
            "A gold coin used\n"
            "long ago. It sells\n"
            "at a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCoin,
        .iconPalette = gItemIconPalette_RelicGold,
    },

    [ITEM_RELIC_VASE] =
    {
#if GERMAN
        .name = ITEM_NAME("Alte Vase"),
#else
        .name = ITEM_NAME("RELIC VASE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Uralte Vase von\n"
            "hohem Wert."),
#else
            "A vase made long\n"
            "ago. It sells at\n"
            "a high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicVase,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Alter Reif"),
#else
        .name = ITEM_NAME("RELIC BAND"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alter Armreif von\n"
            "hohem Wert."),
#else
            "An old bracelet.\n"
            "It sells at a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicBand,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_STATUE] =
    {
#if GERMAN
        .name = ITEM_NAME("Alte Statue"),
#else
        .name = ITEM_NAME("RELIC STATUE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alte Statue von\n"
            "hohem Wert."),
#else
            "An old statue.\n"
            "It sells at a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicStatue,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_RELIC_CROWN] =
    {
#if GERMAN
        .name = ITEM_NAME("Alte Krone"),
#else
        .name = ITEM_NAME("RELIC CROWN"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alte Krone von\n"
            "hohem Wert."),
#else
            "An old crown.\n"
            "It sells at a\n"
            "high price."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_RelicCrown,
        .iconPalette = gItemIconPalette_Relics,
    },

    [ITEM_STRANGE_SOUVENIR] =
    {
#if GERMAN
        .name = ITEM_NAME("Skurriloskulptur"),
#else
        .name = ITEM_NAME("STRANGE SOUVENIR"),
#endif
        .price = (I_PRICE >= GEN_7) ? 3000 : 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Skulptur, die ein\n"
            "Pokémon aus Alola\n"
            "darstellt."),
#else
            "An ornament that\n"
            "depicts a Pokémon\n"
            "from ALOLA."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_RELIC,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_StrangeSouvenir,
        .iconPalette = gItemIconPalette_StrangeSouvenir,
    },

// Fossils

    [ITEM_HELIX_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Helixfossil"),
        .pluralName = ITEM_PLURAL_NAME("Helixfossilien"),
#else
        .name = ITEM_NAME("HELIX FOSSIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fossil eines\n"
            "Pokémon, das am\n"
            "Meeresgrund lebte."),
#else
            "A piece of an\n"
            "ancient marine\n"
            "Pokémon's seashell."),
#endif
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_HelixFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_DOME_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Domfossil"),
        .pluralName = ITEM_PLURAL_NAME("Domfossilien"),
#else
        .name = ITEM_NAME("DOME FOSSIL"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Fossil eines\n"
            "Pokémon, das am\n"
            "Meeresgrund lebte."),
#else
            "A piece of an\n"
            "ancient marine\n"
            "Pokémon's shell."),
#endif
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_DomeFossil,
        .iconPalette = gItemIconPalette_KantoFossil,
    },

    [ITEM_OLD_AMBER] =
    {
#if GERMAN
        .name = ITEM_NAME("Altbernstein"),
        .pluralName = ITEM_PLURAL_NAME("Altbernsteine"),
#else
        .name = ITEM_NAME("OLD AMBER"),
#endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Bernstein mit den\n"
            "Genen eines antiken\n"
            "Pokémon."),
#else
            "A stone containing\n"
            "the genes of an\n"
            "ancient Pokémon."),
#endif
    #if I_KEY_FOSSILS >= GEN_4
        .price = 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_OldAmber,
        .iconPalette = gItemIconPalette_OldAmber,
    },

    [ITEM_ROOT_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Wurzelfossil"),
        .pluralName = ITEM_PLURAL_NAME("Wurzelfossilien"),
#else
        .name = ITEM_NAME("ROOT FOSSIL"),
#endif
        .description = sRootFossilDesc,
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RootFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_CLAW_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Klauenfossil"),
        .pluralName = ITEM_PLURAL_NAME("Klauenfossilien"),
#else
        .name = ITEM_NAME("CLAW FOSSIL"),
#endif
        .description = sRootFossilDesc,
    #if I_KEY_FOSSILS >= GEN_4
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
    #else
        .price = 0,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
    #endif
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ClawFossil,
        .iconPalette = gItemIconPalette_HoennFossil,
    },

    [ITEM_ARMOR_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Panzerfossil"),
        .pluralName = ITEM_PLURAL_NAME("Panzerfossilien"),
#else
        .name = ITEM_NAME("ARMOR FOSSIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Teil des Kopfes\n"
            "eines uralten\n"
            "Pokémon."),
#else
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's head."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_ArmorFossil,
        .iconPalette = gItemIconPalette_ArmorFossil,
    },

    [ITEM_SKULL_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Kopffossil"),
        .pluralName = ITEM_PLURAL_NAME("Kopffossilien"),
#else
        .name = ITEM_NAME("SKULL FOSSIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Teil des Nackens\n"
            "eines uralten\n"
            "Pokémon."),
#else
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's collar."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SkullFossil,
        .iconPalette = gItemIconPalette_SkullFossil,
    },

    [ITEM_COVER_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Schildfossil"),
        .pluralName = ITEM_PLURAL_NAME("Schildfossilien"),
#else
        .name = ITEM_NAME("COVER FOSSIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Teil des Rückens\n"
            "eines uralten\n"
            "Pokémon."),
#else
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's back."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_CoverFossil,
        .iconPalette = gItemIconPalette_CoverFossil,
    },

    [ITEM_PLUME_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Federfossil"),
        .pluralName = ITEM_PLURAL_NAME("Federfossilien"),
#else
        .name = ITEM_NAME("PLUME FOSSIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Teil des Flügels\n"
            "eines uralten\n"
            "Pokémon."),
#else
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's wing."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_PlumeFossil,
        .iconPalette = gItemIconPalette_PlumeFossil,
    },

    [ITEM_JAW_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Kieferfossil"),
        .pluralName = ITEM_PLURAL_NAME("Kieferfossilien"),
#else
        .name = ITEM_NAME("JAW FOSSIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Teil des Kiefers\n"
            "eines uralten\n"
            "Pokémon."),
#else
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's large jaw."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_JawFossil,
        .iconPalette = gItemIconPalette_JawFossil,
    },

    [ITEM_SAIL_FOSSIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Flossenfossil"),
        .pluralName = ITEM_PLURAL_NAME("Flossenfossilien"),
#else
        .name = ITEM_NAME("SAIL FOSSIL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 7000: 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Teil der Flosse\n"
            "eines uralten\n"
            "Pokémon."),
#else
            "A piece of a\n"
            "prehistoric Poké-\n"
            "mon's skin sail."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_SailFossil,
        .iconPalette = gItemIconPalette_SailFossil,
    },

    [ITEM_FOSSILIZED_BIRD] =
    {
#if GERMAN
        .name = ITEM_NAME("Vogelfossil"),
        .pluralName = ITEM_PLURAL_NAME("Vogelfossilien"),
#else
        .name = ITEM_NAME("FOSSILIZED BIRD"),
#endif
        .price = 5000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fossil eines\n"
            "uralten Pokémon,\n"
            "das am Himmel flog."),
#else
            "A fossil of an\n"
            "ancient, sky-\n"
            "soaring Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedBird,
        .iconPalette = gItemIconPalette_FossilizedBird,
    },

    [ITEM_FOSSILIZED_FISH] =
    {
#if GERMAN
        .name = ITEM_NAME("Fischfossil"),
        .pluralName = ITEM_PLURAL_NAME("Fischfossilien"),
#else
        .name = ITEM_NAME("FOSSILIZED FISH"),
        .pluralName = ITEM_PLURAL_NAME("Fossilized Fish"),
#endif
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedFish,
        .iconPalette = gItemIconPalette_FossilizedFish,
    },

    [ITEM_FOSSILIZED_DRAKE] =
    {
#if GERMAN
        .name = ITEM_NAME("Drachenfossil"),
        .pluralName = ITEM_PLURAL_NAME("Drachenfossilien"),
#else
        .name = ITEM_NAME("FOSSILIZED DRAKE"),
#endif
        .price = 5000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fossil eines\n"
            "uralten Pokémon,\n"
            "das an Land lebte."),
#else
            "A fossil of an\n"
            "ancient, land-\n"
            "roaming Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDrake,
        .iconPalette = gItemIconPalette_FossilizedDrake,
    },

    [ITEM_FOSSILIZED_DINO] =
    {
#if GERMAN
        .name = ITEM_NAME("Paddelfossil"),
        .pluralName = ITEM_PLURAL_NAME("Paddelfossilien"),
#else
        .name = ITEM_NAME("FOSSILIZED DINO"),
#endif
        .price = 5000,
        .description = sFossilizedFishDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_FOSSIL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_FossilizedDino,
        .iconPalette = gItemIconPalette_FossilizedDino,
    },

// Mulch

    [ITEM_GROWTH_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Wachsmulch"),
        .pluralName = ITEM_PLURAL_NAME("Wachsmulche"),
#else
        .name = ITEM_NAME("GROWTH MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Growth Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der Beeren\n"
            "schneller wachsen\n"
            "lässt."),
#else
            "A fertilizer that\n"
            "accelerates the\n"
            "growth of Berries."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GROWTH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GrowthMulch,
    },

    [ITEM_DAMP_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Feuchtmulch"),
        .pluralName = ITEM_PLURAL_NAME("Feuchtmulche"),
#else
        .name = ITEM_NAME("DAMP MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Damp Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der Beeren\n"
            "langsamer wachsen\n"
            "lässt."),
#else
            "A fertilizer that\n"
            "decelerates the\n"
            "growth of Berries."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_DAMP_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_DampMulch,
    },

    [ITEM_STABLE_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Stabilmulch"),
        .pluralName = ITEM_PLURAL_NAME("Stabilmulche"),
#else
        .name = ITEM_NAME("STABLE MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Stable Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der\n"
            "Beerenbäume länger\n"
            "leben lässt."),
#else
            "A fertilizer that\n"
            "ups the life time\n"
            "of Berry trees."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_STABLE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_StableMulch,
        .iconPalette = gItemIconPalette_StableMulch,
    },

    [ITEM_GOOEY_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Neumulch"),
        .pluralName = ITEM_PLURAL_NAME("Neumulche"),
#else
        .name = ITEM_NAME("GOOEY MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Gooey Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, nach dem\n"
            "mehr Beeren\n"
            "nachwachsen."),
#else
            "A fertilizer that\n"
            "makes more Berries\n"
            "regrow after fall."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_GOOEY_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_GooeyMulch,
    },

    [ITEM_RICH_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Sprießmulch"),
        .pluralName = ITEM_PLURAL_NAME("Sprießmulche"),
#else
        .name = ITEM_NAME("RICH MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Rich Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der die\n"
            "Beerenernte\n"
            "erhöht."),
#else
            "A fertilizer that\n"
            "ups the number of\n"
            "Berries harvested."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_RICH_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_RichMulch,
    },

    [ITEM_SURPRISE_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Wundermulch"),
        .pluralName = ITEM_PLURAL_NAME("Wundermulche"),
#else
        .name = ITEM_NAME("SURPRISE MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Surprise Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der Beeren\n"
            "öfter mutieren\n"
            "lässt."),
#else
            "A fertilizer that\n"
            "ups the chance of\n"
            "Berry mutations."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_SURPRISE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_SurpriseMulch,
    },

    [ITEM_BOOST_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Wuchermulch"),
        .pluralName = ITEM_PLURAL_NAME("Wuchermulche"),
#else
        .name = ITEM_NAME("BOOST MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Boost Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der weichen\n"
            "Boden schneller\n"
            "trocknen lässt."),
#else
            "A fertilizer that\n"
            "ups the dry speed\n"
            "of soft soil."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_BOOST_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_BoostMulch,
    },

    [ITEM_AMAZE_MULCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Ultramulch"),
        .pluralName = ITEM_PLURAL_NAME("Ultramulche"),
#else
        .name = ITEM_NAME("AMAZE MULCH"),
        .pluralName = ITEM_PLURAL_NAME("Amaze Mulch"),
#endif
        .price = 200,
    #if OW_BERRY_MULCH_USAGE == TRUE
        .description = COMPOUND_STRING(
#if GERMAN
            "Dünger, der Sprieß-,\n"
            "Wunder- und Wu-\n"
            "chermulch vereint."),
#else
            "A fertilizer Rich\n"
            "Surprising and\n"
            "Boosting as well."),
#endif
    #else
        .description = sGenericMulchDesc,
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = ITEM_TO_MULCH(ITEM_AMAZE_MULCH),
        .flingPower = 30,
        .iconPic = gItemIcon_Mulch,
        .iconPalette = gItemIconPalette_AmazeMulch,
    },

// Apricorns
    #if (I_PRICE >= GEN_8 || I_PRICE <= GEN_2)
        #define APRICORN_PRICE 200
    #elif I_PRICE >= GEN_5
        #define APRICORN_PRICE 20
    #else
        #define APRICORN_PRICE 0
    #endif

    [ITEM_RED_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Rot"),
        .pluralName = ITEM_PLURAL_NAME("Aprikokos Rot"),
#else
        .name = ITEM_NAME("RED APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine rote Aprikoko.\n"
            "Sie riecht\n"
            "stechend."),
#else
            "A red apricorn.\n"
            "It assails your\n"
            "nostrils."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_RedApricorn,
    },

    [ITEM_BLUE_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Blau"),
#else
        .name = ITEM_NAME("BLUE APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine blaue Aprikoko.\n"
            "Sie riecht frisch\n"
            "wie Gras."),
#else
            "A blue apricorn.\n"
            "It smells a bit\n"
            "like grass."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlueApricorn,
    },

    [ITEM_YELLOW_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Gelb"),
#else
        .name = ITEM_NAME("YELLOW APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine gelbe Aprikoko.\n"
            "Sie riecht belebend."),
#else
            "A yellow apricorn.\n"
            "It has an invigor-\n"
            "ating scent."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_YellowApricorn,
    },

    [ITEM_GREEN_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Grün"),
#else
        .name = ITEM_NAME("GREEN APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine grüne\n"
            "Aprikoko. Sie riecht\n"
            "seltsam aromatisch."),
#else
            "A green apricorn.\n"
            "It has a strange,\n"
            "aromatic scent."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_GreenApricorn,
    },

    [ITEM_PINK_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Pink"),
#else
        .name = ITEM_NAME("PINK APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine pinkfarbene\n"
            "Aprikoko. Sie riecht\n"
            "angenehm süß."),
#else
            "A pink apricorn.\n"
            "It has a nice,\n"
            "sweet scent."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_PinkApricorn,
    },

    [ITEM_WHITE_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Weiß"),
#else
        .name = ITEM_NAME("WHITE APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine weiße Aprikoko.\n"
            "Sie riecht nach\n"
            "nichts."),
#else
            "A white apricorn.\n"
            "It doesn't smell\n"
            "like anything."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_WhiteApricorn,
    },

    [ITEM_BLACK_APRICORN] =
    {
#if GERMAN
        .name = ITEM_NAME("Aprikoko Schwarz"),
#else
        .name = ITEM_NAME("BLACK APRICORN"),
#endif
        .price = APRICORN_PRICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine schwarze\n"
            "Aprikoko. Sie riecht\n"
            "unbeschreiblich."),
#else
            "A black apricorn.\n"
            "It has an inde-\n"
            "scribable scent."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GROWTH,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Apricorn,
        .iconPalette = gItemIconPalette_BlackApricorn,
    },

    [ITEM_WISHING_PIECE] =
    {
#if GERMAN
        .name = ITEM_NAME("Wunschbrocken"),
#else
        .name = ITEM_NAME("WISHING PIECE"),
#endif
        .price = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ins Nest geworfen\n"
            "lockt es ein\n"
            "Dyna-Pokémon an."),
#else
            "Throw into a\n"
            "{PKMN} Den to attract\n"
            "Dynamax Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .flingPower = 50,
        .iconPic = gItemIcon_WishingPiece,
        .iconPalette = gItemIconPalette_WishingPiece,
    },

    [ITEM_GALARICA_TWIG] =
    {
#if GERMAN
        .name = ITEM_NAME("Galarnuss-Zweig"),
#else
        .name = ITEM_NAME("GALARICA TWIG"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zweig aus Galar.\n"
            "Material für\n"
            "Pokémon-Schmuck."),
#else
            "A twig from a tree\n"
            "in Galar called\n"
            "Galarica."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaTwig,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_ARMORITE_ORE] =
    {
#if GERMAN
        .name = ITEM_NAME("Rüstungserz"),
        .pluralName = ITEM_PLURAL_NAME("Rüstungserze"),
#else
        .name = ITEM_NAME("ARMORITE ORE"),
        .pluralName = ITEM_PLURAL_NAME("Armorite Ore"),
#endif
        .price = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltenes Erz. Ein\n"
            "Sammler tauscht es\n"
            "gern ein."),
#else
            "A rare ore. Can be\n"
            "found in the Isle\n"
            "of Armor at Galar."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ArmoriteOre,
        .iconPalette = gItemIconPalette_ArmoriteOre,
    },

    [ITEM_DYNITE_ORE] =
    {
#if GERMAN
        .name = ITEM_NAME("Dyna-Erz"),
        .pluralName = ITEM_PLURAL_NAME("Dyna-Erze"),
#else
        .name = ITEM_NAME("DYNITE ORE"),
        .pluralName = ITEM_PLURAL_NAME("Dynite Ore"),
#endif
        .price = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mysteriöses Erz.\n"
            "Ein Sammler tauscht\n"
            "es gern ein."),
#else
            "A mysterious ore.\n"
            "It can be found in\n"
            "Galar's Max Lair."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_DyniteOre,
        .iconPalette = gItemIconPalette_DyniteOre,
    },

// Mail

    [ITEM_ORANGE_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Zigzagbrief"),
        .pluralName = ITEM_PLURAL_NAME("Zigzagbriefe"),
#else
        .name = ITEM_NAME("ORANGE MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Orange Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Zigzachs-\n"
            "Aufdruck."),
#else
            "A Zigzagoon-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
        .iconPic = gItemIcon_OrangeMail,
        .iconPalette = gItemIconPalette_OrangeMail,
    },

    [ITEM_HARBOR_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Hafenbrief"),
        .pluralName = ITEM_PLURAL_NAME("Hafenbriefe"),
#else
        .name = ITEM_NAME("HARBOR MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Harbor Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Wingull-\n"
            "Aufdruck."),
#else
            "A Wingull-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
        .iconPic = gItemIcon_HarborMail,
        .iconPalette = gItemIconPalette_HarborMail,
    },

    [ITEM_GLITTER_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Glitzerbrief"),
        .pluralName = ITEM_PLURAL_NAME("Glitzerbriefe"),
#else
        .name = ITEM_NAME("GLITTER MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Glitter Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Pikachu-\n"
            "Aufdruck."),
#else
            "A Pikachu-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
        .iconPic = gItemIcon_GlitterMail,
        .iconPalette = gItemIconPalette_GlitterMail,
    },

    [ITEM_MECH_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Eilbrief"),
        .pluralName = ITEM_PLURAL_NAME("Eilbriefe"),
#else
        .name = ITEM_NAME("MECH MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Mech Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Magnetilo-\n"
            "Aufdruck."),
#else
            "A Magnemite-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
        .iconPic = gItemIcon_MechMail,
        .iconPalette = gItemIconPalette_MechMail,
    },

    [ITEM_WOOD_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Waldbrief"),
        .pluralName = ITEM_PLURAL_NAME("Waldbriefe"),
#else
        .name = ITEM_NAME("WOOD MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Wood Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Bummelz-\n"
            "Aufdruck."),
#else
            "A Slakoth-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
        .iconPic = gItemIcon_WoodMail,
        .iconPalette = gItemIconPalette_WoodMail,
    },

    [ITEM_WAVE_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Wellenbrief"),
        .pluralName = ITEM_PLURAL_NAME("Wellenbriefe"),
#else
        .name = ITEM_NAME("WAVE MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Wave Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Wailmer-\n"
            "Aufdruck."),
#else
            "A Wailmer-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
        .iconPic = gItemIcon_WaveMail,
        .iconPalette = gItemIconPalette_WaveMail,
    },

    [ITEM_BEAD_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Perlenbrief"),
        .pluralName = ITEM_PLURAL_NAME("Perlenbriefe"),
#else
        .name = ITEM_NAME("BEAD MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Bead Mail"),
#endif
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
        .iconPic = gItemIcon_BeadMail,
        .iconPalette = gItemIconPalette_BeadMail,
    },

    [ITEM_SHADOW_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Dunkelbrief"),
        .pluralName = ITEM_PLURAL_NAME("Dunkelbriefe"),
#else
        .name = ITEM_NAME("SHADOW MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Shadow Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Zwirrlicht-\n"
            "Aufdruck."),
#else
            "A Duskull-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
        .iconPic = gItemIcon_ShadowMail,
        .iconPalette = gItemIconPalette_ShadowMail,
    },

    [ITEM_TROPIC_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Tropenbrief"),
        .pluralName = ITEM_PLURAL_NAME("Tropenbriefe"),
#else
        .name = ITEM_NAME("TROPIC MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Tropic Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "Blubella-\n"
            "Aufdruck."),
#else
            "A Bellossom-print\n"
            "Mail to be held by\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
        .iconPic = gItemIcon_TropicMail,
        .iconPalette = gItemIconPalette_TropicMail,
    },

    [ITEM_DREAM_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Traumbrief"),
        .pluralName = ITEM_PLURAL_NAME("Traumbriefe"),
#else
        .name = ITEM_NAME("DREAM MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Dream Mail"),
#endif
        .price = 50,
        .description = sBeadMailDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
        .iconPic = gItemIcon_DreamMail,
        .iconPalette = gItemIconPalette_DreamMail,
    },

    [ITEM_FAB_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Edelbrief"),
        .pluralName = ITEM_PLURAL_NAME("Edelbriefe"),
#else
        .name = ITEM_NAME("FAB MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Fab Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief (Tragen) mit\n"
            "edlem Aufdruck."),
#else
            "A gorgeous-print\n"
            "Mail to be held\n"
            "by a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
        .iconPic = gItemIcon_FabMail,
        .iconPalette = gItemIconPalette_FabMail,
    },

    [ITEM_RETRO_MAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Retrobrief"),
        .pluralName = ITEM_PLURAL_NAME("Retrobriefe"),
#else
        .name = ITEM_NAME("RETRO MAIL"),
        .pluralName = ITEM_PLURAL_NAME("Retro Mail"),
#endif
        .price = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief mit den Ab-\n"
            "bildungen dreier\n"
            "Pokémon-Gesichter."),
#else
            "Mail featuring the\n"
            "drawings of three\n"
            "Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MAIL,
        .type = ITEM_USE_MAIL,
        .fieldUseFunc = ItemUseOutOfBattle_Mail,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
        .iconPic = gItemIcon_RetroMail,
        .iconPalette = gItemIconPalette_RetroMail,
    },

// Evolution Items

    [ITEM_FIRE_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Feuerstein"),
        .pluralName = ITEM_PLURAL_NAME("Feuersteine"),
#else
        .name = ITEM_NAME("FIRE STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_FireStone,
        .iconPalette = gItemIconPalette_FireStone,
    },

    [ITEM_WATER_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Wasserstein"),
        .pluralName = ITEM_PLURAL_NAME("Wassersteine"),
#else
        .name = ITEM_NAME("WATER STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_WaterStone,
        .iconPalette = gItemIconPalette_WaterStone,
    },

    [ITEM_THUNDER_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Donnerstein"),
        .pluralName = ITEM_PLURAL_NAME("Donnersteine"),
#else
        .name = ITEM_NAME("THUNDER STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ThunderStone,
        .iconPalette = gItemIconPalette_ThunderStone,
    },

    [ITEM_LEAF_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Blattstein"),
        .pluralName = ITEM_PLURAL_NAME("Blattsteine"),
#else
        .name = ITEM_NAME("LEAF STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LeafStone,
        .iconPalette = gItemIconPalette_LeafStone,
    },

    [ITEM_ICE_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisstein"),
        .pluralName = ITEM_PLURAL_NAME("Eissteine"),
#else
        .name = ITEM_NAME("ICE STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_IceStone,
        .iconPalette = gItemIconPalette_IceStone,
    },

    [ITEM_SUN_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Sonnenstein"),
        .pluralName = ITEM_PLURAL_NAME("Sonnensteine"),
#else
        .name = ITEM_NAME("SUN STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SunStone,
        .iconPalette = gItemIconPalette_SunStone,
    },

    [ITEM_MOON_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Mondstein"),
        .pluralName = ITEM_PLURAL_NAME("Mondsteine"),
#else
        .name = ITEM_NAME("MOON STONE"),
#endif
    #if I_PRICE >= GEN_7
        .price = 3000,
    #elif I_PRICE >= GEN_4
        .price = 2100,
    #elif I_PRICE == GEN_3
        .price = 0,
    #else
        .price = 10000,
    #endif
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MoonStone,
        .iconPalette = gItemIconPalette_MoonStone,
    },

    [ITEM_SHINY_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Leuchtstein"),
        .pluralName = ITEM_PLURAL_NAME("Leuchtsteine"),
#else
        .name = ITEM_NAME("SHINY STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_ShinyStone,
        .iconPalette = gItemIconPalette_ShinyStone,
    },

    [ITEM_DUSK_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Finsterstein"),
        .pluralName = ITEM_PLURAL_NAME("Finstersteine"),
#else
        .name = ITEM_NAME("DUSK STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DuskStone,
        .iconPalette = gItemIconPalette_DuskStone,
    },

    [ITEM_DAWN_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Funkelstein"),
        .pluralName = ITEM_PLURAL_NAME("Funkelsteine"),
#else
        .name = ITEM_NAME("DAWN STONE"),
#endif
        .price = 10000,
        .description = sEvolutionStoneDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_STONE,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_DawnStone,
        .iconPalette = gItemIconPalette_DawnStone,
    },

    [ITEM_SWEET_APPLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Süßer Apfel"),
        .pluralName = ITEM_PLURAL_NAME("Süße Äpfel"),
#else
        .name = ITEM_NAME("SWEET APPLE"),
#endif
        .price = 2200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Süßer Apfel. Löst\n"
            "eine Entwicklung\n"
            "aus."),
#else
            "A very sweet apple\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SweetApple,
        .iconPalette = gItemIconPalette_SweetApple,
    },

    [ITEM_TART_APPLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Saurer Apfel"),
        .pluralName = ITEM_PLURAL_NAME("Saure Äpfel"),
#else
        .name = ITEM_NAME("TART APPLE"),
#endif
        .price = 2200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Saurer Apfel. Löst\n"
            "eine Entwicklung\n"
            "aus."),
#else
            "A very tart apple\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_TartApple,
        .iconPalette = gItemIconPalette_TartApple,
    },

    [ITEM_CRACKED_POT] =
    {
#if GERMAN
        .name = ITEM_NAME("Rissige Kanne"),
        .pluralName = ITEM_PLURAL_NAME("Rissige Kannen"),
#else
        .name = ITEM_NAME("CRACKED POT"),
#endif
        .price = 1600,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rissige Kanne. Löst\n"
            "eine Entwicklung\n"
            "aus."),
#else
            "A cracked teapot\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_CrackedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_CHIPPED_POT] =
    {
#if GERMAN
        .name = ITEM_NAME("Löchrige Kanne"),
        .pluralName = ITEM_PLURAL_NAME("Löchrige Kannen"),
#else
        .name = ITEM_NAME("CHIPPED POT"),
#endif
        .price = 38000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Löchrige Kanne.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A chipped teapot\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_ChippedPot,
        .iconPalette = gItemIconPalette_Pot,
    },

    [ITEM_GALARICA_CUFF] =
    {
#if GERMAN
        .name = ITEM_NAME("Galarnuss-Reif"),
#else
        .name = ITEM_NAME("GALARICA CUFF"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gewobener Armreif\n"
            "aus Galar. Löst eine\n"
            "Entwicklung aus."),
#else
            "A cuff from Galar\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaCuff,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_GALARICA_WREATH] =
    {
#if GERMAN
        .name = ITEM_NAME("Galarnuss-Kranz"),
#else
        .name = ITEM_NAME("GALARICA WREATH"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gewobener Kranz\n"
            "aus Galar. Löst eine\n"
            "Entwicklung aus."),
#else
            "A wreath made in\n"
            "Galar. Makes some\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_GalaricaWreath,
        .iconPalette = gItemIconPalette_GalaricaItem,
    },

    [ITEM_DRAGON_SCALE] =
    {
#if GERMAN
        .name = ITEM_NAME("Drachenhaut"),
        .pluralName = ITEM_PLURAL_NAME("Drachenhäute"),
#else
        .name = ITEM_NAME("DRAGON SCALE"),
#endif
        .price = 20000,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schuppe eines\n"
            "Drachen. Löst eine\n"
            "Entwicklung aus."),
#else
            "A strange scale\n"
            "held by Dragon-\n"
            "type Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DragonScale,
        .iconPalette = gItemIconPalette_DragonScale,
    },

    [ITEM_UPGRADE] =
    {
#if GERMAN
        .name = ITEM_NAME("Up-Grade"),
        .pluralName = ITEM_PLURAL_NAME("Up-Grades"),
#else
        .name = ITEM_NAME("UPGRADE"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mysteriöse Box der\n"
            "Silph Co. Löst eine\n"
            "Entwicklung aus."),
#else
            "A peculiar box made\n"
            "by Silph Co."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_Upgrade,
        .iconPalette = gItemIconPalette_Upgrade,
    },

    [ITEM_PROTECTOR] =
    {
#if GERMAN
        .name = ITEM_NAME("Schützer"),
        .pluralName = ITEM_PLURAL_NAME("Schützer"),
#else
        .name = ITEM_NAME("PROTECTOR"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützendes Item.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "Loved by a certain\n"
            "Pokémon. It's stiff\n"
            "and heavy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Protector,
        .iconPalette = gItemIconPalette_Protector,
    },

    [ITEM_ELECTIRIZER] =
    {
#if GERMAN
        .name = ITEM_NAME("Stromisierer"),
        .pluralName = ITEM_PLURAL_NAME("Stromisierer"),
#else
        .name = ITEM_NAME("ELECTIRIZER"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektro-Schachtel.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "Loved by a certain\n"
            "Pokémon. It's full\n"
            "of electric energy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Electirizer,
        .iconPalette = gItemIconPalette_Electirizer,
    },

    [ITEM_MAGMARIZER] =
    {
#if GERMAN
        .name = ITEM_NAME("Magmaisierer"),
        .pluralName = ITEM_PLURAL_NAME("Magmaisierer"),
#else
        .name = ITEM_NAME("MAGMARIZER"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Magma-Schachtel.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "Loved by a certain\n"
            "Pokémon. It's full\n"
            "of magma energy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Magmarizer,
        .iconPalette = gItemIconPalette_Magmarizer,
    },

    [ITEM_DUBIOUS_DISC] =
    {
#if GERMAN
        .name = ITEM_NAME("Dubiosdisc"),
        .pluralName = ITEM_PLURAL_NAME("Dubiosdiscs"),
#else
        .name = ITEM_NAME("DUBIOUS DISC"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dubiose Scheibe.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A clear device\n"
            "overflowing with\n"
            "dubious data."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 50,
        .iconPic = gItemIcon_DubiousDisc,
        .iconPalette = gItemIconPalette_DubiousDisc,
    },

    [ITEM_REAPER_CLOTH] =
    {
#if GERMAN
        .name = ITEM_NAME("Düsterumhang"),
        .pluralName = ITEM_PLURAL_NAME("Düsterumhänge"),
#else
        .name = ITEM_NAME("REAPER CLOTH"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Geisterhafter\n"
            "Umhang. Löst eine\n"
            "Entwicklung aus."),
#else
            "Loved by a certain\n"
            "Pokémon. Imbued\n"
            "with spirit energy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 10,
        .iconPic = gItemIcon_ReaperCloth,
        .iconPalette = gItemIconPalette_ReaperCloth,
    },

    [ITEM_PRISM_SCALE] =
    {
#if GERMAN
        .name = ITEM_NAME("Schönschuppe"),
        .pluralName = ITEM_PLURAL_NAME("Schönschuppen"),
#else
        .name = ITEM_NAME("PRISM SCALE"),
#endif
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 2000,
    #else
        .price = 20000,
    #endif
        .description = COMPOUND_STRING(
#if GERMAN
            "Schillernde\n"
            "Schuppe. Löst eine\n"
            "Entwicklung aus."),
#else
            "A mysterious scale\n"
            "that evolves a\n"
            "certain Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PrismScale,
        .iconPalette = gItemIconPalette_PrismScale,
    },

    [ITEM_WHIPPED_DREAM] =
    {
#if GERMAN
        .name = ITEM_NAME("Sahnehäubchen"),
#else
        .name = ITEM_NAME("WHIPPED DREAM"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Süßes Häubchen.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A soft and sweet\n"
            "treat loved by\n"
            "a certain Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_WhippedDream,
        .iconPalette = gItemIconPalette_WhippedDream,
    },

    [ITEM_SACHET] =
    {
#if GERMAN
        .name = ITEM_NAME("Duftbeutel"),
#else
        .name = ITEM_NAME("SACHET"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 * TREASURE_FACTOR : 2100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Beutel mit starkem\n"
            "Duft. Löst eine\n"
            "Entwicklung aus."),
#else
            "A sachet of strong\n"
            "perfumes, loved by\n"
            "a certain Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_Sachet,
        .iconPalette = gItemIconPalette_Sachet,
    },

    [ITEM_OVAL_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Ovaler Stein"),
        .pluralName = ITEM_PLURAL_NAME("Ovale Steine"),
#else
        .name = ITEM_NAME("OVAL STONE"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltsamer Stein.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "Peculiar stone\n"
            "that evolves a\n"
            "certain Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_OvalStone,
        .iconPalette = gItemIconPalette_OvalStone,
    },

    [ITEM_STRAWBERRY_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Erdbeere"),
        .pluralName = ITEM_PLURAL_NAME("Zucker-Erdbeeren"),
#else
        .name = ITEM_NAME("STRAWBERRY SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "einer Erdbeere.\n"
            "Hokumil liebt es."),
#else
            "Strawberry-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StrawberrySweet,
        .iconPalette = gItemIconPalette_StrawberrySweet,
    },

    [ITEM_LOVE_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Herz"),
#else
        .name = ITEM_NAME("LOVE SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "eines Herzens.\n"
            "Hokumil liebt es."),
#else
            "A heart-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LoveSweet,
        .iconPalette = gItemIconPalette_LoveSweet,
    },

    [ITEM_BERRY_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Beere"),
        .pluralName = ITEM_PLURAL_NAME("Zucker-Beeren"),
#else
        .name = ITEM_NAME("BERRY SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "einer Beere. Hokumil\n"
            "liebt es."),
#else
            "A berry-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerrySweet,
        .iconPalette = gItemIconPalette_BerrySweet,
    },

    [ITEM_CLOVER_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Kleeblatt"),
#else
        .name = ITEM_NAME("CLOVER SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "eines Kleeblatts.\n"
            "Hokumil liebt es."),
#else
            "A clover-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CloverSweet,
        .iconPalette = gItemIconPalette_CloverSweet,
    },

    [ITEM_FLOWER_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Blume"),
#else
        .name = ITEM_NAME("FLOWER SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "einer Blume. Hokumil\n"
            "liebt es."),
#else
            "A flower-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FlowerSweet,
        .iconPalette = gItemIconPalette_FlowerSweet,
    },

    [ITEM_STAR_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Stern"),
#else
        .name = ITEM_NAME("STAR SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "eines Sterns.\n"
            "Hokumil liebt es."),
#else
            "A star-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarSweet,
        .iconPalette = gItemIconPalette_StarSweet,
    },

    [ITEM_RIBBON_SWEET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zucker-Schleife"),
#else
        .name = ITEM_NAME("RIBBON SWEET"),
#endif
        .price = 500 * TREASURE_FACTOR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zuckerwerk in Form\n"
            "einer Schleife.\n"
            "Hokumil liebt es."),
#else
            "A ribbon-shaped\n"
            "sweet loved by\n"
            "Milcery."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RibbonSweet,
        .iconPalette = gItemIconPalette_RibbonSweet,
    },

    [ITEM_EVERSTONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Ewigstein"),
        .pluralName = ITEM_PLURAL_NAME("Ewigsteine"),
#else
        .name = ITEM_NAME("EVERSTONE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 3000 : 200,
        .holdEffect = HOLD_EFFECT_PREVENT_EVOLVE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wundersamer Stein\n"
            "zum Tragen. Bewirkt\n"
            "Entwicklungsstopp."),
#else
            "A wondrous hold\n"
            "item that prevents\n"
            "evolution."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Everstone,
        .iconPalette = gItemIconPalette_Everstone,
    },

// Nectars

    [ITEM_RED_NECTAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Roter Nektar"),
#else
        .name = ITEM_NAME("RED NECTAR"),
#endif
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_RedNectar,
    },

    [ITEM_YELLOW_NECTAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Gelber Nektar"),
#else
        .name = ITEM_NAME("YELLOW NECTAR"),
#endif
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_YellowNectar,
    },

    [ITEM_PINK_NECTAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Rosa Nektar"),
#else
        .name = ITEM_NAME("PINK NECTAR"),
#endif
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PinkNectar,
    },

    [ITEM_PURPLE_NECTAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Purpurner Nektar"),
#else
        .name = ITEM_NAME("PURPLE NECTAR"),
#endif
        .price = 300,
        .holdEffectParam = 0,
        .description = sNectarDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_NECTAR,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange_ConsumedOnUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Nectar,
        .iconPalette = gItemIconPalette_PurpleNectar,
    },

// Plates

    [ITEM_FLAME_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Feuertafel"),
        .pluralName = ITEM_PLURAL_NAME("Feuertafeln"),
#else
        .name = ITEM_NAME("FLAME PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Feuer-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Fire-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FlamePlate,
    },

    [ITEM_SPLASH_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Wassertafel"),
        .pluralName = ITEM_PLURAL_NAME("Wassertafeln"),
#else
        .name = ITEM_NAME("SPLASH PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Wasser-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Water-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SplashPlate,
    },

    [ITEM_ZAP_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Blitztafel"),
        .pluralName = ITEM_PLURAL_NAME("Blitztafeln"),
#else
        .name = ITEM_NAME("ZAP PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Elektro-Attacken."),
#else
            "A tablet that ups\n"
            "the power of Elec-\n"
            "tric-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ZapPlate,
    },

    [ITEM_MEADOW_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Wiesentafel"),
        .pluralName = ITEM_PLURAL_NAME("Wiesentafeln"),
#else
        .name = ITEM_NAME("MEADOW PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Pflanzen-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Grass-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MeadowPlate,
    },

    [ITEM_ICICLE_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Frosttafel"),
        .pluralName = ITEM_PLURAL_NAME("Frosttafeln"),
#else
        .name = ITEM_NAME("ICICLE PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Eis-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Ice-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IciclePlate,
    },

    [ITEM_FIST_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Fausttafel"),
        .pluralName = ITEM_PLURAL_NAME("Fausttafeln"),
#else
        .name = ITEM_NAME("FIST PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Kampf-Attacken."),
#else
            "A tablet that ups\n"
            "the power of Fight-\n"
            "ing-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_FistPlate,
    },

    [ITEM_TOXIC_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gifttafel"),
        .pluralName = ITEM_PLURAL_NAME("Gifttafeln"),
#else
        .name = ITEM_NAME("TOXIC PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Gift-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Poison-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_ToxicPlate,
    },

    [ITEM_EARTH_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Erdtafel"),
        .pluralName = ITEM_PLURAL_NAME("Erdtafeln"),
#else
        .name = ITEM_NAME("EARTH PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Boden-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Ground-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_EarthPlate,
    },

    [ITEM_SKY_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Wolkentafel"),
        .pluralName = ITEM_PLURAL_NAME("Wolkentafeln"),
#else
        .name = ITEM_NAME("SKY PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Flug-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Flying-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SkyPlate,
    },

    [ITEM_MIND_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Hirntafel"),
        .pluralName = ITEM_PLURAL_NAME("Hirntafeln"),
#else
        .name = ITEM_NAME("MIND PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Psycho-Attacken."),
#else
            "A tablet that ups\n"
            "the power of Psy\n"
            "chic-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_MindPlate,
    },

    [ITEM_INSECT_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Käfertafel"),
        .pluralName = ITEM_PLURAL_NAME("Käfertafeln"),
#else
        .name = ITEM_NAME("INSECT PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Käfer-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Bug-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_InsectPlate,
    },

    [ITEM_STONE_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Steintafel"),
        .pluralName = ITEM_PLURAL_NAME("Steintafeln"),
#else
        .name = ITEM_NAME("STONE PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Gestein-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Rock-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_StonePlate,
    },

    [ITEM_SPOOKY_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Spuktafel"),
        .pluralName = ITEM_PLURAL_NAME("Spuktafeln"),
#else
        .name = ITEM_NAME("SPOOKY PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Geist-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Ghost-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_SpookyPlate,
    },

    [ITEM_DRACO_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Dracotafel"),
        .pluralName = ITEM_PLURAL_NAME("Dracotafeln"),
#else
        .name = ITEM_NAME("DRACO PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Drachen-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Dragon-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DracoPlate,
    },

    [ITEM_DREAD_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Furchttafel"),
        .pluralName = ITEM_PLURAL_NAME("Furchttafeln"),
#else
        .name = ITEM_NAME("DREAD PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Unlicht-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Dark-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_DreadPlate,
    },

    [ITEM_IRON_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisentafel"),
        .pluralName = ITEM_PLURAL_NAME("Eisentafeln"),
#else
        .name = ITEM_NAME("IRON PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Stahl-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Steel-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_IronPlate,
    },

    [ITEM_PIXIE_PLATE] =
    {
#if GERMAN
        .name = ITEM_NAME("Feentafel"),
        .pluralName = ITEM_PLURAL_NAME("Feentafeln"),
#else
        .name = ITEM_NAME("PIXIE PLATE"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_PLATE,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steintafel (Tragen)\n"
            "verstärkt\n"
            "Fee-Attacken."),
#else
            "A tablet that ups\n"
            "the power of\n"
            "Fairy-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_PLATE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 90,
        .iconPic = gItemIcon_Plate,
        .iconPalette = gItemIconPalette_PixiePlate,
    },

// Drives

    [ITEM_DOUSE_DRIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Aquamodul"),
#else
        .name = ITEM_NAME("DOUSE DRIVE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Modul (Tragen)\n"
            "ändert Techblaster\n"
            "zu Wasser."),
#else
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Water-type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_DouseDrive,
    },

    [ITEM_SHOCK_DRIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Blitzmodul"),
#else
        .name = ITEM_NAME("SHOCK DRIVE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Modul (Tragen)\n"
            "ändert Techblaster\n"
            "zu Elektro."),
#else
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Electric-type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ShockDrive,
    },

    [ITEM_BURN_DRIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Flammenmodul"),
#else
        .name = ITEM_NAME("BURN DRIVE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Modul (Tragen)\n"
            "ändert Techblaster\n"
            "zu Feuer."),
#else
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Fire-type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_BurnDrive,
    },

    [ITEM_CHILL_DRIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gefriermodul"),
#else
        .name = ITEM_NAME("CHILL DRIVE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 1000,
        .holdEffect = HOLD_EFFECT_DRIVE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Modul (Tragen)\n"
            "ändert Techblaster\n"
            "zu Eis."),
#else
            "Changes Genesect's\n"
            "Techno Blast to\n"
            "Ice-type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_DRIVE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 70,
        .iconPic = gItemIcon_Drive,
        .iconPalette = gItemIconPalette_ChillDrive,
    },

// Memories

    [ITEM_FIRE_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Feuer-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Feuer-Discs"),
#else
        .name = ITEM_NAME("FIRE MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Fire Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Feuer."),
#else
            "A disc with Fire\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 50,
        .iconPic = gItemIcon_FireMemory,
        .iconPalette = gItemIconPalette_FireMemory,
    },

    [ITEM_WATER_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Wasser-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Wasser-Discs"),
#else
        .name = ITEM_NAME("WATER MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Water Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Wasser."),
#else
            "A disc with Water\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 50,
        .iconPic = gItemIcon_WaterMemory,
        .iconPalette = gItemIconPalette_WaterMemory,
    },

    [ITEM_ELECTRIC_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Elektro-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Elektro-Discs"),
#else
        .name = ITEM_NAME("ELECTRIC MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Electric Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Elektro."),
#else
            "A disc with Electric\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 50,
        .iconPic = gItemIcon_ElectricMemory,
        .iconPalette = gItemIconPalette_ElectricMemory,
    },

    [ITEM_GRASS_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Pflanzen-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Pflanzen-Discs"),
#else
        .name = ITEM_NAME("GRASS MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Grass Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Pflanzen."),
#else
            "A disc with Grass\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 50,
        .iconPic = gItemIcon_GrassMemory,
        .iconPalette = gItemIconPalette_GrassMemory,
    },

    [ITEM_ICE_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Eis-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Eis-Discs"),
#else
        .name = ITEM_NAME("ICE MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Ice Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Eis."),
#else
            "A disc with Ice\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 50,
        .iconPic = gItemIcon_IceMemory,
        .iconPalette = gItemIconPalette_IceMemory,
    },

    [ITEM_FIGHTING_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Kampf-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Kampf-Discs"),
#else
        .name = ITEM_NAME("FIGHTING MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Fighting Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Kampf."),
#else
            "Disc with Fighting\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 50,
        .iconPic = gItemIcon_FightingMemory,
        .iconPalette = gItemIconPalette_FightingMemory,
    },

    [ITEM_POISON_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Gift-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Gift-Discs"),
#else
        .name = ITEM_NAME("POISON MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Poison Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Gift."),
#else
            "A disc with Poison\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 50,
        .iconPic = gItemIcon_PoisonMemory,
        .iconPalette = gItemIconPalette_PoisonMemory,
    },

    [ITEM_GROUND_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Boden-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Boden-Discs"),
#else
        .name = ITEM_NAME("GROUND MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Ground Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Boden."),
#else
            "A disc with Ground\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 50,
        .iconPic = gItemIcon_GroundMemory,
        .iconPalette = gItemIconPalette_GroundMemory,
    },

    [ITEM_FLYING_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Flug-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Flug-Discs"),
#else
        .name = ITEM_NAME("FLYING MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Flying Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Flug."),
#else
            "A disc with Flying\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_FlyingMemory,
        .iconPalette = gItemIconPalette_FlyingMemory,
    },

    [ITEM_PSYCHIC_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Psycho-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Psycho-Discs"),
#else
        .name = ITEM_NAME("PSYCHIC MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Psychic Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Psycho."),
#else
            "A disc with Psychic\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 50,
        .iconPic = gItemIcon_PsychicMemory,
        .iconPalette = gItemIconPalette_PsychicMemory,
    },

    [ITEM_BUG_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Käfer-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Käfer-Discs"),
#else
        .name = ITEM_NAME("BUG MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Bug Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Käfer."),
#else
            "A disc with Bug\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 50,
        .iconPic = gItemIcon_BugMemory,
        .iconPalette = gItemIconPalette_BugMemory,
    },

    [ITEM_ROCK_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Gesteins-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Gesteins-Discs"),
#else
        .name = ITEM_NAME("ROCK MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Rock Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Gestein."),
#else
            "A disc with Rock\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 50,
        .iconPic = gItemIcon_RockMemory,
        .iconPalette = gItemIconPalette_RockMemory,
    },

    [ITEM_GHOST_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Geister-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Geister-Discs"),
#else
        .name = ITEM_NAME("GHOST MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Ghost Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Geist."),
#else
            "A disc with Ghost\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 50,
        .iconPic = gItemIcon_GhostMemory,
        .iconPalette = gItemIconPalette_GhostMemory,
    },

    [ITEM_DRAGON_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Drachen-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Drachen-Discs"),
#else
        .name = ITEM_NAME("DRAGON MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Dragon Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Drachen."),
#else
            "A disc with Dragon\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 50,
        .iconPic = gItemIcon_DragonMemory,
        .iconPalette = gItemIconPalette_DragonMemory,
    },

    [ITEM_DARK_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Unlicht-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Unlicht-Discs"),
#else
        .name = ITEM_NAME("DARK MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Dark Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Unlicht."),
#else
            "A disc with Dark\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 50,
        .iconPic = gItemIcon_DarkMemory,
        .iconPalette = gItemIconPalette_DarkMemory,
    },

    [ITEM_STEEL_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Stahl-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Stahl-Discs"),
#else
        .name = ITEM_NAME("STEEL MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Steel Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Stahl."),
#else
            "A disc with Steel\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .flingPower = 50,
        .iconPic = gItemIcon_SteelMemory,
        .iconPalette = gItemIconPalette_SteelMemory,
    },

    [ITEM_FAIRY_MEMORY] =
    {
#if GERMAN
        .name = ITEM_NAME("Feen-Disc"),
        .pluralName = ITEM_PLURAL_NAME("Feen-Discs"),
#else
        .name = ITEM_NAME("FAIRY MEMORY"),
        .pluralName = ITEM_PLURAL_NAME("Fairy Memories"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_MEMORY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Disc (Tragen)\n"
            "ändert Amigentos\n"
            "Typ zu Fee."),
#else
            "A disc with Fairy\n"
            "type data. It swaps\n"
            "Silvally's type."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEMORY,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 50,
        .iconPic = gItemIcon_FairyMemory,
        .iconPalette = gItemIconPalette_FairyMemory,
    },

    [ITEM_RUSTED_SWORD] =
    {
#if GERMAN
        .name = ITEM_NAME("Rostiges Schwert"),
#else
        .name = ITEM_NAME("RUSTED SWORD"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwert, mit dem ein\n"
            "Held einst Unheil\n"
            "abwendete."),
#else
            "A rusty sword. A\n"
            "hero used it to\n"
            "halt a disaster."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedSword,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

    [ITEM_RUSTED_SHIELD] =
    {
#if GERMAN
        .name = ITEM_NAME("Rostiger Schild"),
#else
        .name = ITEM_NAME("RUSTED SHIELD"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schild, mit dem ein\n"
            "Held einst Unheil\n"
            "abwendete."),
#else
            "A rusty shield. A\n"
            "hero used it to\n"
            "halt a disaster."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RustedShield,
        .iconPalette = gItemIconPalette_RustedWeapons,
    },

// Colored Orbs

    [ITEM_RED_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Rote Kugel"),
        .pluralName = ITEM_PLURAL_NAME("Rote Kugeln"),
#else
        .name = ITEM_NAME("RED ORB"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rot glühende Kugel,\n"
            "die eine uralte\n"
            "Macht bergen soll."),
#else
            "A red, glowing orb\n"
            "said to contain an\n"
            "ancient power."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RedOrb,
        .iconPalette = gItemIconPalette_RedOrb,
    },

    [ITEM_BLUE_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Blaue Kugel"),
        .pluralName = ITEM_PLURAL_NAME("Blaue Kugeln"),
#else
        .name = ITEM_NAME("BLUE ORB"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_PRIMAL_ORB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Blau glühende Ku-\n"
            "gel, die eine uralte\n"
            "Macht bergen soll."),
#else
            "A blue, glowing orb\n"
            "said to contain an\n"
            "ancient power."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BlueOrb,
        .iconPalette = gItemIconPalette_BlueOrb,
    },

// Mega Stones

    [ITEM_VENUSAURITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Bisaflornit"),
#else
        .name = ITEM_NAME("VENUSAURITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Bisaflor mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Venusaur to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Venusaurite,
        .iconPalette = gItemIconPalette_Venusaurite,
    },

    [ITEM_CHARIZARDITE_X] =
    {
#if GERMAN
        .name = ITEM_NAME("Gluraknit X"),
#else
        .name = ITEM_NAME("CHARIZARDITE X"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeX,
        .iconPalette = gItemIconPalette_CharizarditeX,
    },

    [ITEM_CHARIZARDITE_Y] =
    {
#if GERMAN
        .name = ITEM_NAME("Gluraknit Y"),
#else
        .name = ITEM_NAME("CHARIZARDITE Y"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sCharizarditeDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_CharizarditeY,
        .iconPalette = gItemIconPalette_CharizarditeY,
    },

    [ITEM_BLASTOISINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Turtoknit"),
#else
        .name = ITEM_NAME("BLASTOISINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Turtok mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Blastoise to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blastoisinite,
        .iconPalette = gItemIconPalette_Blastoisinite,
    },

    [ITEM_BEEDRILLITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Bibornit"),
#else
        .name = ITEM_NAME("BEEDRILLITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Bibor mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Beedrill to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Beedrillite,
        .iconPalette = gItemIconPalette_Beedrillite,
    },

    [ITEM_PIDGEOTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Taubossnit"),
#else
        .name = ITEM_NAME("PIDGEOTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Tauboss mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Pidgeot to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pidgeotite,
        .iconPalette = gItemIconPalette_Pidgeotite,
    },

    [ITEM_ALAKAZITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Simsalanit"),
#else
        .name = ITEM_NAME("ALAKAZITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Simsala mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Alakazam to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Alakazite,
        .iconPalette = gItemIconPalette_Alakazite,
    },

    [ITEM_SLOWBRONITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lahmusnit"),
#else
        .name = ITEM_NAME("SLOWBRONITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Lahmus mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Slowbro to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Slowbronite,
        .iconPalette = gItemIconPalette_Slowbronite,
    },

    [ITEM_GENGARITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gengarnit"),
#else
        .name = ITEM_NAME("GENGARITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Gengar mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Gengar to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gengarite,
        .iconPalette = gItemIconPalette_Gengarite,
    },

    [ITEM_KANGASKHANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Kangamanit"),
#else
        .name = ITEM_NAME("KANGASKHANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Kangama mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Kangaskhan to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Kangaskhanite,
        .iconPalette = gItemIconPalette_Kangaskhanite,
    },

    [ITEM_PINSIRITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Pinsirnit"),
#else
        .name = ITEM_NAME("PINSIRITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Pinsir mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Pinsir to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pinsirite,
        .iconPalette = gItemIconPalette_Pinsirite,
    },

    [ITEM_GYARADOSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Garadosnit"),
#else
        .name = ITEM_NAME("GYARADOSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Garados mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Gyarados to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gyaradosite,
        .iconPalette = gItemIconPalette_Gyaradosite,
    },

    [ITEM_AERODACTYLITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Aerodactylonit"),
#else
        .name = ITEM_NAME("AERODACTYLITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Aerodactyl mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Aerodactyl to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aerodactylite,
        .iconPalette = gItemIconPalette_Aerodactylite,
    },

    [ITEM_MEWTWONITE_X] =
    {
#if GERMAN
        .name = ITEM_NAME("Mewtunit X"),
#else
        .name = ITEM_NAME("MEWTWONITE X"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteX,
        .iconPalette = gItemIconPalette_MewtwoniteX,
    },

    [ITEM_MEWTWONITE_Y] =
    {
#if GERMAN
        .name = ITEM_NAME("Mewtunit Y"),
#else
        .name = ITEM_NAME("MEWTWONITE Y"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sMewtwoniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_MewtwoniteY,
        .iconPalette = gItemIconPalette_MewtwoniteY,
    },

    [ITEM_AMPHAROSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Ampharosnit"),
#else
        .name = ITEM_NAME("AMPHAROSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Ampharos mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Ampharos to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Ampharosite,
        .iconPalette = gItemIconPalette_Ampharosite,
    },

    [ITEM_STEELIXITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Stahlosnit"),
#else
        .name = ITEM_NAME("STEELIXITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Stahlos mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Steelix to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Steelixite,
        .iconPalette = gItemIconPalette_Steelixite,
    },

    [ITEM_SCIZORITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Scheroxnit"),
#else
        .name = ITEM_NAME("SCIZORITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Scherox mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Scizor to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scizorite,
        .iconPalette = gItemIconPalette_Scizorite,
    },

    [ITEM_HERACRONITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Skarabornit"),
#else
        .name = ITEM_NAME("HERACRONITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Skaraborn mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Heracross to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heracronite,
        .iconPalette = gItemIconPalette_Heracronite,
    },

    [ITEM_HOUNDOOMINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Hundemonit"),
#else
        .name = ITEM_NAME("HOUNDOOMINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Hundemon mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Houndoom to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Houndoominite,
        .iconPalette = gItemIconPalette_Houndoominite,
    },

    [ITEM_TYRANITARITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Despotarnit"),
#else
        .name = ITEM_NAME("TYRANITARITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Despotar mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Tyranitar to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tyranitarite,
        .iconPalette = gItemIconPalette_Tyranitarite,
    },

    [ITEM_SCEPTILITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gewaldronit"),
#else
        .name = ITEM_NAME("SCEPTILITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Gewaldro mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Sceptile to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sceptilite,
        .iconPalette = gItemIconPalette_Sceptilite,
    },

    [ITEM_BLAZIKENITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lohgocknit"),
#else
        .name = ITEM_NAME("BLAZIKENITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Lohgock mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Blaziken to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Blazikenite,
        .iconPalette = gItemIconPalette_Blazikenite,
    },

    [ITEM_SWAMPERTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Sumpexnit"),
#else
        .name = ITEM_NAME("SWAMPERTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Sumpex mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Swampert to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Swampertite,
        .iconPalette = gItemIconPalette_Swampertite,
    },

    [ITEM_GARDEVOIRITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Guardevoirnit"),
#else
        .name = ITEM_NAME("GARDEVOIRITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Guardevoir mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Gardevoir to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Gardevoirite,
        .iconPalette = gItemIconPalette_Gardevoirite,
    },

    [ITEM_SABLENITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Zobirisnit"),
#else
        .name = ITEM_NAME("SABLENITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Zobiris mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Sableye to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sablenite,
        .iconPalette = gItemIconPalette_Sablenite,
    },

    [ITEM_MAWILITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Flunkifernit"),
#else
        .name = ITEM_NAME("MAWILITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Flunkifer mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Mawile to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Mawilite,
        .iconPalette = gItemIconPalette_Mawilite,
    },

    [ITEM_AGGRONITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Stollossnit"),
#else
        .name = ITEM_NAME("AGGRONITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Stolloss mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Aggron to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Aggronite,
        .iconPalette = gItemIconPalette_Aggronite,
    },

    [ITEM_MEDICHAMITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Meditalisnit"),
#else
        .name = ITEM_NAME("MEDICHAMITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Meditalis mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Medicham to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Medichamite,
        .iconPalette = gItemIconPalette_Medichamite,
    },

    [ITEM_MANECTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Voltensonit"),
#else
        .name = ITEM_NAME("MANECTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Voltenso mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Manectric to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Manectite,
        .iconPalette = gItemIconPalette_Manectite,
    },

    [ITEM_SHARPEDONITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Tohaidonit"),
#else
        .name = ITEM_NAME("SHARPEDONITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Tohaido mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Sharpedo to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Sharpedonite,
        .iconPalette = gItemIconPalette_Sharpedonite,
    },

    [ITEM_CAMERUPTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Cameruptnit"),
#else
        .name = ITEM_NAME("CAMERUPTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Camerupt mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Camerupt to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Cameruptite,
        .iconPalette = gItemIconPalette_Cameruptite,
    },

    [ITEM_ALTARIANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Altarianit"),
#else
        .name = ITEM_NAME("ALTARIANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Altaria mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Altaria to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Altarianite,
        .iconPalette = gItemIconPalette_Altarianite,
    },

    [ITEM_BANETTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Banetteonit"),
#else
        .name = ITEM_NAME("BANETTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Banette mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Banette to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Banettite,
        .iconPalette = gItemIconPalette_Banettite,
    },

    [ITEM_ABSOLITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Absolnit"),
#else
        .name = ITEM_NAME("ABSOLITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Absolite,
        .iconPalette = gItemIconPalette_Absolite,
    },

    [ITEM_GLALITITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Firnontornit"),
#else
        .name = ITEM_NAME("GLALITITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Firnontor mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Glalie to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glalitite,
        .iconPalette = gItemIconPalette_Glalitite,
    },

    [ITEM_SALAMENCITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Brutalandanit"),
#else
        .name = ITEM_NAME("SALAMENCITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Brutalanda mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Salamence to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Salamencite,
        .iconPalette = gItemIconPalette_Salamencite,
    },

    [ITEM_METAGROSSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Metagrossnit"),
#else
        .name = ITEM_NAME("METAGROSSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Metagross mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Metagross to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Metagrossite,
        .iconPalette = gItemIconPalette_Metagrossite,
    },

    [ITEM_LATIASITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Latiasnit"),
#else
        .name = ITEM_NAME("LATIASITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Latias mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Latias to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiasite,
        .iconPalette = gItemIconPalette_Latiasite,
    },

    [ITEM_LATIOSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Latiosnit"),
#else
        .name = ITEM_NAME("LATIOSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Latios mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Latios to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Latiosite,
        .iconPalette = gItemIconPalette_Latiosite,
    },

    [ITEM_LOPUNNITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Schlapornit"),
#else
        .name = ITEM_NAME("LOPUNNITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Schlapor mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Lopunny to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lopunnite,
        .iconPalette = gItemIconPalette_Lopunnite,
    },

    [ITEM_GARCHOMPITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Knakracknit"),
#else
        .name = ITEM_NAME("GARCHOMPITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Garchompite,
        .iconPalette = gItemIconPalette_Garchompite,
    },

    [ITEM_LUCARIONITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lucarionit"),
#else
        .name = ITEM_NAME("LUCARIONITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Lucarionite,
        .iconPalette = gItemIconPalette_Lucarionite,
    },

    [ITEM_ABOMASITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Rexblisarnit"),
#else
        .name = ITEM_NAME("ABOMASITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Rexblisar mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Abomasnow to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Abomasite,
        .iconPalette = gItemIconPalette_Abomasite,
    },

    [ITEM_GALLADITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Galagladinit"),
#else
        .name = ITEM_NAME("GALLADITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Galagladi mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Gallade to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Galladite,
        .iconPalette = gItemIconPalette_Galladite,
    },

    [ITEM_AUDINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Ohrdochnit"),
#else
        .name = ITEM_NAME("AUDINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Ohrdoch mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Audino to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Audinite,
        .iconPalette = gItemIconPalette_Audinite,
    },

    [ITEM_DIANCITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Diancienit"),
#else
        .name = ITEM_NAME("DIANCITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Diancie mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Diancie to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Diancite,
        .iconPalette = gItemIconPalette_Diancite,
    },

    [ITEM_CLEFABLITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Pixinit"),
#else
        .name = ITEM_NAME("CLEFABLITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Pixi mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Clefable to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Clefablite,
        .iconPalette = gItemIconPalette_Clefablite,
    },

    [ITEM_VICTREEBELITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Sarzenianit"),
#else
        .name = ITEM_NAME("VICTREEBELITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Sarzenia mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Victreebel to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Victreebelite,
        .iconPalette = gItemIconPalette_Victreebelite,
    },

    [ITEM_STARMINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Starmienit"),
#else
        .name = ITEM_NAME("STARMINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Starmie mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Starmie to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Starminite,
        .iconPalette = gItemIconPalette_Starminite,
    },

    [ITEM_DRAGONINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Dragoranit"),
#else
        .name = ITEM_NAME("DRAGONINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Dragoran mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Dragonite to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragoninite,
        .iconPalette = gItemIconPalette_Dragoninite,
    },

    [ITEM_MEGANIUMITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Meganienit"),
#else
        .name = ITEM_NAME("MEGANIUMITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Meganie mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Meganium to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meganiumite,
        .iconPalette = gItemIconPalette_Meganiumite,
    },

    [ITEM_FERALIGITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Impergatornit"),
#else
        .name = ITEM_NAME("FERALIGITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Impergator mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Feraligatr to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Feraligite,
        .iconPalette = gItemIconPalette_Feraligite,
    },

    [ITEM_SKARMORITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Panzaeronit"),
#else
        .name = ITEM_NAME("SKARMORITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Panzaeron mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Skarmory to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Skarmorite,
        .iconPalette = gItemIconPalette_Skarmorite,
    },

    [ITEM_FROSLASSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Frosdedjenit"),
#else
        .name = ITEM_NAME("FROSLASSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Frosdedje mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Froslass to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Froslassite,
        .iconPalette = gItemIconPalette_Froslassite,
    },

    [ITEM_EMBOARITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Flambirexonit"),
#else
        .name = ITEM_NAME("EMBOARITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Flambirex mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Emboar to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Emboarite,
        .iconPalette = gItemIconPalette_Emboarite,
    },

    [ITEM_EXCADRITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Stalobornit"),
#else
        .name = ITEM_NAME("EXCADRITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Stalobor mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Excadrill to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Excadrite,
        .iconPalette = gItemIconPalette_Excadrite,
    },

    [ITEM_SCOLIPITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Cerapendranit"),
#else
        .name = ITEM_NAME("SCOLIPITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Cerapendra mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Scolipede to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scolipite,
        .iconPalette = gItemIconPalette_Scolipite,
    },

    [ITEM_SCRAFTINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Irokexonit"),
#else
        .name = ITEM_NAME("SCRAFTINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Irokex mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Scrafty to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scraftinite,
        .iconPalette = gItemIconPalette_Scraftinite,
    },

    [ITEM_EELEKTROSSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Zapplarangonit"),
#else
        .name = ITEM_NAME("EELEKTROSSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Zapplarang mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Eelektross to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Eelektrossite,
        .iconPalette = gItemIconPalette_Eelektrossite,
    },

    [ITEM_CHANDELURITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Skelabranit"),
#else
        .name = ITEM_NAME("CHANDELURITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Skelabra mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Chandelure to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chandelurite,
        .iconPalette = gItemIconPalette_Chandelurite,
    },

    [ITEM_CHESNAUGHTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Brigaronit"),
#else
        .name = ITEM_NAME("CHESNAUGHTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Brigaron mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Chesnaught to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chesnaughtite,
        .iconPalette = gItemIconPalette_Chesnaughtite,
    },

    [ITEM_DELPHOXITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Fennexisnit"),
#else
        .name = ITEM_NAME("DELPHOXITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Fennexis mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Delphox to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Delphoxite,
        .iconPalette = gItemIconPalette_Delphoxite,
    },

    [ITEM_GRENINJITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Quajutsunit"),
#else
        .name = ITEM_NAME("GRENINJITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Quajutsu mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Greninja to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Greninjite,
        .iconPalette = gItemIconPalette_Greninjite,
    },

    [ITEM_PYROARITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Pyroleonit"),
#else
        .name = ITEM_NAME("PYROARITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Pyroleo mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Pyroar to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Pyroarite,
        .iconPalette = gItemIconPalette_Pyroarite,
    },

    [ITEM_FLOETTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Floetteonit"),
#else
        .name = ITEM_NAME("FLOETTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Floette mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Floette to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Floettite,
        .iconPalette = gItemIconPalette_Floettite,
    },

    [ITEM_MALAMARITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Calamaneronit"),
#else
        .name = ITEM_NAME("MALAMARITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Calamanero mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Malamar to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Malamarite,
        .iconPalette = gItemIconPalette_Malamarite,
    },

    [ITEM_BARBARACITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Thanathoranit"),
#else
        .name = ITEM_NAME("BARBARACITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Thanathora mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Barbaracle to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Barbaracite,
        .iconPalette = gItemIconPalette_Barbaracite,
    },

    [ITEM_DRAGALGITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Tandraknit"),
#else
        .name = ITEM_NAME("DRAGALGITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Tandrak mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Dragalge to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Dragalgite,
        .iconPalette = gItemIconPalette_Dragalgite,
    },

    [ITEM_HAWLUCHANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Resladeronit"),
#else
        .name = ITEM_NAME("HAWLUCHANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Resladero mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Hawlucha to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Hawluchanite,
        .iconPalette = gItemIconPalette_Hawluchanite,
    },

    [ITEM_ZYGARDITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Zygardenit"),
#else
        .name = ITEM_NAME("ZYGARDITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Zygarde mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Zygarde to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zygardite,
        .iconPalette = gItemIconPalette_Zygardite,
    },

    [ITEM_DRAMPANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Sen-Longnit"),
#else
        .name = ITEM_NAME("DRAMPANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Sen-Long mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Drampa to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Drampanite,
        .iconPalette = gItemIconPalette_Drampanite,
    },

    [ITEM_FALINKSITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Legiosnit"),
#else
        .name = ITEM_NAME("FALINKSITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Legios mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Falinks to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Falinksite,
        .iconPalette = gItemIconPalette_Falinksite,
    },

    [ITEM_HEATRANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Heatranit"),
#else
        .name = ITEM_NAME("HEATRANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Heatran mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Heatran to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Heatranite,
        .iconPalette = gItemIconPalette_Heatranite,
    },

    [ITEM_DARKRANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Darkrainit"),
#else
        .name = ITEM_NAME("DARKRANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Darkrai mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Darkrai to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Darkranite,
        .iconPalette = gItemIconPalette_Darkranite,
    },

    [ITEM_ZERAORITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Zeraoranit"),
#else
        .name = ITEM_NAME("ZERAORITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Zeraora mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Zeraora to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Zeraorite,
        .iconPalette = gItemIconPalette_Zeraorite,
    },

    [ITEM_RAICHUNITE_X] =
    {
#if GERMAN
        .name = ITEM_NAME("Raichunit X"),
#else
        .name = ITEM_NAME("RAICHUNITE X"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sRaichuniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteX,
        .iconPalette = gItemIconPalette_RaichuniteX,
    },

    [ITEM_RAICHUNITE_Y] =
    {
#if GERMAN
        .name = ITEM_NAME("Raichunit Y"),
#else
        .name = ITEM_NAME("RAICHUNITE Y"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sRaichuniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_RaichuniteY,
        .iconPalette = gItemIconPalette_RaichuniteY,
    },

    [ITEM_CHIMECHITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Palimpalimonit"),
#else
        .name = ITEM_NAME("CHIMECHITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Palimpalim mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Chimecho to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Chimechite,
        .iconPalette = gItemIconPalette_Chimechite,
    },

    [ITEM_ABSOLITE_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Absolnit Z"),
#else
        .name = ITEM_NAME("ABSOLITE Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sAbsoliteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AbsoliteZ,
        .iconPalette = gItemIconPalette_AbsoliteZ,
    },

    [ITEM_STARAPTITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Staraptornit"),
#else
        .name = ITEM_NAME("STARAPTITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Staraptor mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Staraptor to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Staraptite,
        .iconPalette = gItemIconPalette_Staraptite,
    },

    [ITEM_GARCHOMPITE_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Knakracknit Z"),
#else
        .name = ITEM_NAME("GARCHOMPITE Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sGarchompiteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_GarchompiteZ,
        .iconPalette = gItemIconPalette_GarchompiteZ,
    },

    [ITEM_LUCARIONITE_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Lucarionit Z"),
#else
        .name = ITEM_NAME("LUCARIONITE Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = sLucarioniteDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_LucarioniteZ,
        .iconPalette = gItemIconPalette_LucarioniteZ,
    },

    [ITEM_GOLURKITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Golgantesnit"),
#else
        .name = ITEM_NAME("GOLURKITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Golgantes mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Golurk to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golurkite,
        .iconPalette = gItemIconPalette_Golurkite,
    },

    [ITEM_MEOWSTICITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Psiaugonit"),
#else
        .name = ITEM_NAME("MEOWSTICITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Psiaugon mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Meowstic to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Meowsticite,
        .iconPalette = gItemIconPalette_Meowsticite,
    },

    [ITEM_CRABOMINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Krawellonit"),
#else
        .name = ITEM_NAME("CRABOMINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Krawell mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Crabominable to\n"
            "Mega in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Crabominite,
        .iconPalette = gItemIconPalette_Crabominite,
    },

    [ITEM_GOLISOPITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Tectassnit"),
#else
        .name = ITEM_NAME("GOLISOPITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Tectass mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Golisopod to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Golisopite,
        .iconPalette = gItemIconPalette_Golisopite,
    },

    [ITEM_MAGEARNITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Magearnanit"),
#else
        .name = ITEM_NAME("MAGEARNITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Magearna mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Magearna to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Magearnite,
        .iconPalette = gItemIconPalette_Magearnite,
    },

    [ITEM_SCOVILLAINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Halupenjonit"),
#else
        .name = ITEM_NAME("SCOVILLAINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Halupenjo mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Scovillain to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Scovillainite,
        .iconPalette = gItemIconPalette_Scovillainite,
    },

    [ITEM_BAXCALIBRITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Espinodonit"),
#else
        .name = ITEM_NAME("BAXCALIBRITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Espinodon mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Baxcalibur to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Baxcalibrite,
        .iconPalette = gItemIconPalette_Baxcalibrite,
    },

    [ITEM_TATSUGIRINITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Nigiraginit"),
#else
        .name = ITEM_NAME("TATSUGIRINITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Nigiragi mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Tatsugiri to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Tatsugirinite,
        .iconPalette = gItemIconPalette_Tatsugirinite,
    },

    [ITEM_GLIMMORANITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lumifloranit"),
#else
        .name = ITEM_NAME("GLIMMORANITE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_MEGA_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mega-Stein, mit dem\n"
            "Lumiflora mega-\n"
            "entwickeln kann."),
#else
            "This stone enables\n"
            "Glimmora to Mega\n"
            "Evolve in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_MEGA_STONE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_Glimmoranite,
        .iconPalette = gItemIconPalette_Glimmoranite,
    },

// GB Player
    [ITEM_GB_PLAYER] =
    {
#if GERMAN
        .name = ITEM_NAME("GB-Player"),
#else
        .name = ITEM_NAME("GB PLAYER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät, das alte\n"
            "Pokémon-Musik\n"
            "abspielt."),
#else
            "A device that plays\n"
            "music from the old\n"
            "Pokémon games."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_GBPlayer,
        .importance = 1,
        .iconPic = gItemIcon_GBPlayer,
        .iconPalette = gItemIconPalette_GBPlayer,
    },

// Gems
    #if I_PRICE >= GEN_9
        #define GEM_PRICE 15000
    #elif I_PRICE >= GEN_7
        #define GEM_PRICE 4000
    #else
        #define GEM_PRICE 200
    #endif

    [ITEM_NORMAL_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Normaljuwel"),
#else
        .name = ITEM_NAME("NORMAL GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Normal-Attacken."),
#else
            "Increases the\n"
            "power of Normal\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_NormalGem,
    },

    [ITEM_FIRE_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Feuerjuwel"),
#else
        .name = ITEM_NAME("FIRE GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Feuer-Attacken."),
#else
            "Increases the\n"
            "power of Fire\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FireGem,
    },

    [ITEM_WATER_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Wasserjuwel"),
#else
        .name = ITEM_NAME("WATER GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Wasser-Attacken."),
#else
            "Increases the\n"
            "power of Water\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_WaterGem,
    },

    [ITEM_ELECTRIC_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Elektrojuwel"),
#else
        .name = ITEM_NAME("ELECTRIC GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Elektro-Attacken."),
#else
            "Increases the\n"
            "power of Electric\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_ElectricGem,
    },

    [ITEM_GRASS_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Pflanzenjuwel"),
#else
        .name = ITEM_NAME("GRASS GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Pflanzen-Attacken."),
#else
            "Increases the\n"
            "power of Grass\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GrassGem,
    },

    [ITEM_ICE_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisjuwel"),
#else
        .name = ITEM_NAME("ICE GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Eis-Attacken."),
#else
            "Increases the\n"
            "power of Ice\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_IceGem,
    },

    [ITEM_FIGHTING_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Kampfjuwel"),
#else
        .name = ITEM_NAME("FIGHTING GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Kampf-Attacken."),
#else
            "Increases the\n"
            "power of Fighting\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FightingGem,
    },

    [ITEM_POISON_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Giftjuwel"),
#else
        .name = ITEM_NAME("POISON GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Gift-Attacken."),
#else
            "Increases the\n"
            "power of Poison\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PoisonGem,
    },

    [ITEM_GROUND_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Bodenjuwel"),
#else
        .name = ITEM_NAME("GROUND GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Boden-Attacken."),
#else
            "Increases the\n"
            "power of Ground\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GroundGem,
    },

    [ITEM_FLYING_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Flugjuwel"),
#else
        .name = ITEM_NAME("FLYING GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Flug-Attacken."),
#else
            "Increases the\n"
            "power of Flying\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FlyingGem,
    },

    [ITEM_PSYCHIC_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Psychojuwel"),
#else
        .name = ITEM_NAME("PSYCHIC GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Psycho-Attacken."),
#else
            "Increases the\n"
            "power of Psychic\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_PsychicGem,
    },

    [ITEM_BUG_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Käferjuwel"),
#else
        .name = ITEM_NAME("BUG GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Käfer-Attacken."),
#else
            "Increases the\n"
            "power of Bug\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_BugGem,
    },

    [ITEM_ROCK_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Gesteinsjuwel"),
#else
        .name = ITEM_NAME("ROCK GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Gestein-Attacken."),
#else
            "Increases the\n"
            "power of Rock\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_RockGem,
    },

    [ITEM_GHOST_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Geisterjuwel"),
#else
        .name = ITEM_NAME("GHOST GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Geist-Attacken."),
#else
            "Increases the\n"
            "power of Ghost\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_GhostGem,
    },

    [ITEM_DRAGON_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Drakojuwel"),
#else
        .name = ITEM_NAME("DRAGON GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Drachen-Attacken."),
#else
            "Increases the\n"
            "power of Dragon\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DragonGem,
    },

    [ITEM_DARK_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Unlichtjuwel"),
#else
        .name = ITEM_NAME("DARK GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Unlicht-Attacken."),
#else
            "Increases the\n"
            "power of Dark\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_DarkGem,
    },

    [ITEM_STEEL_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Stahljuwel"),
#else
        .name = ITEM_NAME("STEEL GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Stahl-Attacken."),
#else
            "Increases the\n"
            "power of Steel\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_SteelGem,
    },

    [ITEM_FAIRY_GEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Feenjuwel"),
#else
        .name = ITEM_NAME("FAIRY GEM"),
#endif
        .price = GEM_PRICE,
        .holdEffect = HOLD_EFFECT_GEMS,
        .holdEffectParam = GEM_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Juwel (Tragen)\n"
            "verstärkt einmalig\n"
            "Fee-Attacken."),
#else
            "Increases the\n"
            "power of Fairy\n"
            "Type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_GEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_TypeGem,
        .iconPalette = gItemIconPalette_FairyGem,
    },

// Z-Crystals

    [ITEM_NORMALIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Normium Z"),
#else
        .name = ITEM_NAME("NORMALIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Normal-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Normal-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .iconPic = gItemIcon_NormaliumZ,
        .iconPalette = gItemIconPalette_NormaliumZ,
    },

    [ITEM_FIRIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Pyrium Z"),
#else
        .name = ITEM_NAME("FIRIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Feuer-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Fire-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .iconPic = gItemIcon_FiriumZ,
        .iconPalette = gItemIconPalette_FiriumZ,
    },

    [ITEM_WATERIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Aquium Z"),
#else
        .name = ITEM_NAME("WATERIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Wasser-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Water-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .iconPic = gItemIcon_WateriumZ,
        .iconPalette = gItemIconPalette_WateriumZ,
    },

    [ITEM_ELECTRIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Voltium Z"),
#else
        .name = ITEM_NAME("ELECTRIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Elektro-Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Electric-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .iconPic = gItemIcon_ElectriumZ,
        .iconPalette = gItemIconPalette_ElectriumZ,
    },

    [ITEM_GRASSIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Botanium Z"),
#else
        .name = ITEM_NAME("GRASSIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Pflanzen-Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Grass-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .iconPic = gItemIcon_GrassiumZ,
        .iconPalette = gItemIconPalette_GrassiumZ,
    },

    [ITEM_ICIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Glacium Z"),
#else
        .name = ITEM_NAME("ICIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Eis-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Ice-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .iconPic = gItemIcon_IciumZ,
        .iconPalette = gItemIconPalette_IciumZ,
    },

    [ITEM_FIGHTINIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Battalium Z"),
#else
        .name = ITEM_NAME("FIGHTINIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Kampf-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Fighting-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .iconPic = gItemIcon_FightiniumZ,
        .iconPalette = gItemIconPalette_FightiniumZ,
    },

    [ITEM_POISONIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Toxium Z"),
#else
        .name = ITEM_NAME("POISONIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Gift-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Poison-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .iconPic = gItemIcon_PoisoniumZ,
        .iconPalette = gItemIconPalette_PoisoniumZ,
    },

    [ITEM_GROUNDIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Terrium Z"),
#else
        .name = ITEM_NAME("GROUNDIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Boden-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Ground-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .iconPic = gItemIcon_GroundiumZ,
        .iconPalette = gItemIconPalette_GroundiumZ,
    },

    [ITEM_FLYINIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Aerium Z"),
#else
        .name = ITEM_NAME("FLYINIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Flug-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Flying-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .iconPic = gItemIcon_FlyiniumZ,
        .iconPalette = gItemIconPalette_FlyiniumZ,
    },

    [ITEM_PSYCHIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Psium Z"),
#else
        .name = ITEM_NAME("PSYCHIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Psycho-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Psychic-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .iconPic = gItemIcon_PsychiumZ,
        .iconPalette = gItemIconPalette_PsychiumZ,
    },

    [ITEM_BUGINIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Insectium Z"),
#else
        .name = ITEM_NAME("BUGINIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Käfer-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Bug-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .iconPic = gItemIcon_BuginiumZ,
        .iconPalette = gItemIconPalette_BuginiumZ,
    },

    [ITEM_ROCKIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Petrium Z"),
#else
        .name = ITEM_NAME("ROCKIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Gestein-Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Rock-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .iconPic = gItemIcon_RockiumZ,
        .iconPalette = gItemIconPalette_RockiumZ,
    },

    [ITEM_GHOSTIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Phantomium Z"),
#else
        .name = ITEM_NAME("GHOSTIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Geist-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Ghost-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .iconPic = gItemIcon_GhostiumZ,
        .iconPalette = gItemIconPalette_GhostiumZ,
    },

    [ITEM_DRAGONIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Dracium Z"),
#else
        .name = ITEM_NAME("DRAGONIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Drachen-Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Dragon-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .iconPic = gItemIcon_DragoniumZ,
        .iconPalette = gItemIconPalette_DragoniumZ,
    },

    [ITEM_DARKINIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Noctium Z"),
#else
        .name = ITEM_NAME("DARKINIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Unlicht-Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Dark-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .iconPic = gItemIcon_DarkiniumZ,
        .iconPalette = gItemIconPalette_DarkiniumZ,
    },

    [ITEM_STEELIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Metallium Z"),
#else
        .name = ITEM_NAME("STEELIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Stahl-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Steel-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_STEEL,
        .iconPic = gItemIcon_SteeliumZ,
        .iconPalette = gItemIconPalette_SteeliumZ,
    },

    [ITEM_FAIRIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Sylphium Z"),
#else
        .name = ITEM_NAME("FAIRIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Fee-Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Fairy-\n"
            "type moves into\n"
            "Z-Moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .iconPic = gItemIcon_FairiumZ,
        .iconPalette = gItemIconPalette_FairiumZ,
    },

    [ITEM_PIKANIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Pikachium Z"),
#else
        .name = ITEM_NAME("PIKANIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Pikachus Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Pikachu's\n"
            "Volt Tackle\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikaniumZ,
        .iconPalette = gItemIconPalette_PikaniumZ,
    },

    [ITEM_EEVIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Evolium Z"),
#else
        .name = ITEM_NAME("EEVIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Evolis Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Eevee's\n"
            "Last Resort\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_EeviumZ,
        .iconPalette = gItemIconPalette_EeviumZ,
    },

    [ITEM_SNORLIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Relaxonium Z"),
#else
        .name = ITEM_NAME("SNORLIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Relaxos Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Snorlax's\n"
            "Giga Impact\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SnorliumZ,
        .iconPalette = gItemIconPalette_SnorliumZ,
    },

    [ITEM_MEWNIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Mewnium Z"),
#else
        .name = ITEM_NAME("MEWNIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht Mews\n"
            "Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade Mew's\n"
            "Psychic into\n"
            "a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MewniumZ,
        .iconPalette = gItemIconPalette_MewniumZ,
    },

    [ITEM_DECIDIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Silvarronium Z"),
#else
        .name = ITEM_NAME("DECIDIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Silvarros Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Decidu-\n"
            "eye's Spirit Sha-\n"
            "ckle into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_DecidiumZ,
        .iconPalette = gItemIconPalette_DecidiumZ,
    },

    [ITEM_INCINIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Fuegronium Z"),
#else
        .name = ITEM_NAME("INCINIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Fuegros Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Incine-\n"
            "roar's Darkest La-\n"
            "riat into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_InciniumZ,
        .iconPalette = gItemIconPalette_InciniumZ,
    },

    [ITEM_PRIMARIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Primarenium Z"),
#else
        .name = ITEM_NAME("PRIMARIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Primarenes Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Primarina's\n"
            "Sparkling Aria\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PrimariumZ,
        .iconPalette = gItemIconPalette_PrimariumZ,
    },

    [ITEM_LYCANIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Wolwerockium Z"),
#else
        .name = ITEM_NAME("LYCANIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Wolwerocks Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Lycanroc's\n"
            "Stone Edge\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LycaniumZ,
        .iconPalette = gItemIconPalette_LycaniumZ,
    },

    [ITEM_MIMIKIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Mimigmium Z"),
#else
        .name = ITEM_NAME("MIMIKIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Mimigmas Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Mimikyu's\n"
            "Play Rough\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MimikiumZ,
        .iconPalette = gItemIconPalette_MimikiumZ,
    },

    [ITEM_KOMMONIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Grandirasium Z"),
#else
        .name = ITEM_NAME("KOMMONIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Grandiras Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Kommo-o's\n"
            "Clanging Scales\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_KommoniumZ,
        .iconPalette = gItemIconPalette_KommoniumZ,
    },

    [ITEM_TAPUNIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Kapium Z"),
#else
        .name = ITEM_NAME("TAPUNIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht der\n"
            "Kapus Attacke zur\n"
            "Z-Attacke."),
#else
            "Upgrade the tapus'\n"
            "Nature's Madness\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  //signature z move
        .iconPic = gItemIcon_TapuniumZ,
        .iconPalette = gItemIconPalette_TapuniumZ,
    },

    [ITEM_SOLGANIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Solgalium Z"),
#else
        .name = ITEM_NAME("SOLGANIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Solgaleos Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Solgaleo's\n"
            "Sunsteel Strike\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_SolganiumZ,
        .iconPalette = gItemIconPalette_SolganiumZ,
    },

    [ITEM_LUNALIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Lunalium Z"),
#else
        .name = ITEM_NAME("LUNALIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Lunalas Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Lunala's\n"
            "Moongeist Beam\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_LunaliumZ,
        .iconPalette = gItemIconPalette_LunaliumZ,
    },

    [ITEM_MARSHADIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Marshadownium Z"),
#else
        .name = ITEM_NAME("MARSHADIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Marshadows Attacke\n"
            "zur Z-Attacke."),
#else
            "Upgrade Marsha-\n"
            "dow's Spectral Thi-\n"
            "ef into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_MarshadiumZ,
        .iconPalette = gItemIconPalette_MarshadiumZ,
    },

    [ITEM_ALORAICHIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("A-Raichunium Z"),
#else
        .name = ITEM_NAME("ALORAICHIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall für\n"
            "Alola-Raichus\n"
            "Z-Attacke."),
#else
            "Upgrade Alolan\n"
            "Raichu's Thunder-\n"
            "bolt into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_AloraichiumZ,
        .iconPalette = gItemIconPalette_AloraichiumZ,
    },

    [ITEM_PIKASHUNIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Ash-Pikachium Z"),
#else
        .name = ITEM_NAME("PIKASHUNIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall macht\n"
            "Ash-Pikachus Atta-\n"
            "cke zur Z-Attacke."),
#else
            "Upgrade Pikachu w/\n"
            "a cap's Thunderbolt\n"
            "into a Z-Move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255,  // signature z move
        .iconPic = gItemIcon_PikashuniumZ,
        .iconPalette = gItemIconPalette_PikashuniumZ,
    },

    [ITEM_ULTRANECROZIUM_Z] =
    {
#if GERMAN
        .name = ITEM_NAME("Ultranecrozium Z"),
#else
        .name = ITEM_NAME("ULTRANECROZIUM Z"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_Z_CRYSTAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kristall, der\n"
            "Necrozma eine neue\n"
            "Form verleiht."),
#else
            "A crystal to turn\n"
            "fused Necrozma\n"
            "into a new form."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_Z_CRYSTAL,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 255, //signature z move
        .iconPic = gItemIcon_UltranecroziumZ,
        .iconPalette = gItemIconPalette_UltranecroziumZ,
    },

// Species-specific Held Items

    [ITEM_LIGHT_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Kugelblitz"),
        .pluralName = ITEM_PLURAL_NAME("Kugelblitze"),
#else
        .name = ITEM_NAME("LIGHT BALL"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 100,
        .holdEffect = HOLD_EFFECT_LIGHT_BALL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht Pikachus Sp.\n"
            "Angr."),
#else
            "A hold item that\n"
            "raises the Atk and\n"
            "Sp. Atk of Pikachu."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightBall,
        .iconPalette = gItemIconPalette_LightBall,
    },

    [ITEM_LEEK] =
    {
#if GERMAN
        .name = ITEM_NAME("Lauchstange"),
        .pluralName = ITEM_PLURAL_NAME("Lauchstangen"),
#else
        .name = ITEM_NAME("LEEK"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 200,
        .holdEffect = HOLD_EFFECT_LEEK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) er-\n"
            "höht Volltreffer-\n"
            "quote von Porenta."),
#else
            "A hold item that\n"
            "raises Farfetch'd's\n"
            "critical-hit ratio."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_Leek,
        .iconPalette = gItemIconPalette_Leek,
    },

    [ITEM_THICK_CLUB] =
    {
#if GERMAN
        .name = ITEM_NAME("Kampfknochen"),
        .pluralName = ITEM_PLURAL_NAME("Kampfknochen"),
#else
        .name = ITEM_NAME("THICK CLUB"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 500,
        .holdEffect = HOLD_EFFECT_THICK_CLUB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) er-\n"
            "höht Angr.-Wert v.\n"
            "Tragosso/Knogga."),
#else
            "A hold item that \n"
            "raises Cubone or\n"
            "Marowak's Attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_Bone,
        .iconPalette = gItemIconPalette_Bone,
    },

    [ITEM_LUCKY_PUNCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Lucky Punch"),
        .pluralName = ITEM_PLURAL_NAME("Lucky Punchs"),
#else
        .name = ITEM_NAME("LUCKY PUNCH"),
        .pluralName = ITEM_PLURAL_NAME("Lucky Punches"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_LUCKY_PUNCH,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht Chaneiras\n"
            "Volltrefferquote."),
#else
            "A hold item that\n"
            "raises Chansey's\n"
            "critical-hit rate."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_LuckyPunch,
        .iconPalette = gItemIconPalette_LuckyPunch,
    },

    [ITEM_METAL_POWDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Metallstaub"),
        .pluralName = ITEM_PLURAL_NAME("Metallstaube"),
#else
        .name = ITEM_NAME("METAL POWDER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_METAL_POWDER,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht Vert.-Wert\n"
            "von Ditto."),
#else
            "A hold item that\n"
            "raises Ditto's\n"
            "Defense."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_MetalPowder,
    },

    [ITEM_QUICK_POWDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Flottstaub"),
        .pluralName = ITEM_PLURAL_NAME("Flottstaube"),
#else
        .name = ITEM_NAME("QUICK POWDER"),
#endif
        .price = (I_PRICE >= GEN_7) ? 1000 : 10,
        .holdEffect = HOLD_EFFECT_QUICK_POWDER,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht Init.-Wert\n"
            "von Ditto."),
#else
            "A hold item that\n"
            "raises the Speed\n"
            "of Ditto."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DittoPowder,
        .iconPalette = gItemIconPalette_QuickPowder,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
#if GERMAN
        .name = ITEM_NAME("Abyssplatte"),
        .pluralName = ITEM_PLURAL_NAME("Abyssplatten"),
#else
        .name = ITEM_NAME("DEEP SEA SCALE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_SCALE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert. von Perlu."),
#else
            "A hold item that\n"
            "raises the Sp. Def\n"
            "of Clamperl."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_DeepSeaScale,
        .iconPalette = gItemIconPalette_DeepSeaScale,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
#if GERMAN
        .name = ITEM_NAME("Abysszahn"),
        .pluralName = ITEM_PLURAL_NAME("Abysszähne"),
#else
        .name = ITEM_NAME("DEEP SEA TOOTH"),
        .pluralName = ITEM_PLURAL_NAME("Deep Sea Teeth"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 200,
        .holdEffect = HOLD_EFFECT_DEEP_SEA_TOOTH,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Angr. von Perlu."),
#else
            "A hold item that\n"
            "raises the Sp. Atk\n"
            "of Clamperl."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 90,
        .iconPic = gItemIcon_DeepSeaTooth,
        .iconPalette = gItemIconPalette_DeepSeaTooth,
    },

    [ITEM_SOUL_DEW] =
    {
#if GERMAN
        .name = ITEM_NAME("Seelentau"),
        .pluralName = ITEM_PLURAL_NAME("Seelentau"),
#else
        .name = ITEM_NAME("SOUL DEW"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 200,
        .holdEffect = HOLD_EFFECT_SOUL_DEW,
        .holdEffectParam = B_SOUL_DEW_BOOST >= GEN_7 ? 20 : 50,
        .description = COMPOUND_STRING(
        #if B_SOUL_DEW_BOOST >= GEN_7
#if GERMAN
            "Stärkt Psycho- und\n"
            "Drachen-Attacken\n"
            "von Latios/Latias."),
#else
            "Powers up Latios' &\n"
            "Latias' Psychic and\n"
            "Dragon-type moves."),
#endif
        #else
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp.Ang & Sp.Ver von\n"
#else
            "Hold item: raises\n"
            "Sp. Atk & Sp. Def of\n"
#endif
            "Latios & Latias."),
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SoulDew,
        .iconPalette = gItemIconPalette_SoulDew,
    },

    [ITEM_ADAMANT_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Adamant-Orb"),
        .pluralName = ITEM_PLURAL_NAME("Adamant-Orbs"),
#else
        .name = ITEM_NAME("ADAMANT ORB"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt Dialgas\n"
            "Drachen- und\n"
            "Stahl-Attacken."),
#else
            "Powers up Dialga's\n"
            "Dragon and Steel-\n"
            "type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantOrb,
        .iconPalette = gItemIconPalette_AdamantOrb,
    },

    [ITEM_LUSTROUS_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Weiß-Orb"),
        .pluralName = ITEM_PLURAL_NAME("Weiß-Orbs"),
#else
        .name = ITEM_NAME("LUSTROUS ORB"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt Palkias\n"
            "Drachen- und\n"
            "Wasser-Attacken."),
#else
            "Powers up Palkia's\n"
            "Dragon and Water-\n"
            "type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousOrb,
        .iconPalette = gItemIconPalette_LustrousOrb,
    },

    [ITEM_GRISEOUS_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Platinum-Orb"),
        .pluralName = ITEM_PLURAL_NAME("Platinum-Orbs"),
#else
        .name = ITEM_NAME("GRISEOUS ORB"),
#endif
        .price = (I_PRICE >= GEN_7) ? 0 : 10000,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt Giratinas\n"
            "Drachen- und\n"
            "Geist-Attacken."),
#else
            "Boosts Giratina's\n"
            "Dragon and Ghost-\n"
            "type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousOrb,
        .iconPalette = gItemIconPalette_GriseousOrb,
    },

// Incenses

    [ITEM_SEA_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Seerauch"),
        .pluralName = ITEM_PLURAL_NAME("Seerauch"),
#else
        .name = ITEM_NAME("SEA INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = I_TYPE_BOOST_POWER >= GEN_4 ? 20 : 5,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_SeaIncense,
        .iconPalette = gItemIconPalette_SeaIncense,
    },

    [ITEM_LAX_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Laxrauch"),
        .pluralName = ITEM_PLURAL_NAME("Laxrauch"),
#else
        .name = ITEM_NAME("LAX INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_EVASION_UP,
    #if I_LAX_INCENSE_BOOST >= GEN_4
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) senkt\n"
            "Genauigkeit des\n"
            "Gegners."),
#else
            "A hold item that\n"
            "lowers the\n"
            "foe's accuracy."),
#endif
    #else
        .holdEffectParam = 5,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) senkt\n"
            "Genauigkeit des\n"
            "Gegners leicht."),
#else
            "A hold item that\n"
            "slightly lowers the\n"
            "foe's accuracy."),
#endif
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaxIncense,
        .iconPalette = gItemIconPalette_LaxIncense,
    },

    [ITEM_ODD_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Schrägrauch"),
        .pluralName = ITEM_PLURAL_NAME("Schrägrauch"),
#else
        .name = ITEM_NAME("ODD INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 10,
        .iconPic = gItemIcon_OddIncense,
        .iconPalette = gItemIconPalette_OddIncense,
    },

    [ITEM_ROCK_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Steinrauch"),
        .pluralName = ITEM_PLURAL_NAME("Steinrauch"),
#else
        .name = ITEM_NAME("ROCK INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 10,
        .iconPic = gItemIcon_RockIncense,
        .iconPalette = gItemIconPalette_RockIncense,
    },

    [ITEM_FULL_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Lahmrauch"),
        .pluralName = ITEM_PLURAL_NAME("Lahmrauch"),
#else
        .name = ITEM_NAME("FULL INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 5000 : 9600,
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .holdEffectParam = 5,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FullIncense,
        .iconPalette = gItemIconPalette_FullIncense,
    },

    [ITEM_WAVE_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Wellenrauch"),
        .pluralName = ITEM_PLURAL_NAME("Wellenrauch"),
#else
        .name = ITEM_NAME("WAVE INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sSeaIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 10,
        .iconPic = gItemIcon_WaveIncense,
        .iconPalette = gItemIconPalette_WaveIncense,
    },

    [ITEM_ROSE_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Rosenrauch"),
        .pluralName = ITEM_PLURAL_NAME("Rosenrauch"),
#else
        .name = ITEM_NAME("ROSE INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 2000 : 9600,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = 20,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseIncense,
        .iconPalette = gItemIconPalette_RoseIncense,
    },

    [ITEM_LUCK_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Glücksrauch"),
        .pluralName = ITEM_PLURAL_NAME("Glücksrauch"),
#else
        .name = ITEM_NAME("LUCK INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 11000 : 9600,
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LuckIncense,
        .iconPalette = gItemIconPalette_LuckIncense,
    },

    [ITEM_PURE_INCENSE] =
    {
#if GERMAN
        .name = ITEM_NAME("Scheuchrauch"),
        .pluralName = ITEM_PLURAL_NAME("Scheuchrauch"),
#else
        .name = ITEM_NAME("PURE INCENSE"),
#endif
        .price = (I_PRICE >= GEN_7) ? 6000 : 9600,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_INCENSE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PureIncense,
        .iconPalette = gItemIconPalette_PureIncense,
    },

// Contest Scarves

    [ITEM_RED_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Roter Schal"),
        .pluralName = ITEM_PLURAL_NAME("Rote Schals"),
#else
        .name = ITEM_NAME("RED SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Red Scarves"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Cool.-Wert für den\n"
            "Wettbewerb."),
#else
            "A hold item that\n"
            "raises Cool in\n"
            "Contests."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_RedScarf,
    },

    [ITEM_BLUE_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Blauer Schal"),
        .pluralName = ITEM_PLURAL_NAME("Blaue Schals"),
#else
        .name = ITEM_NAME("BLUE SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Blue Scarves"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Schön.-Wert für den\n"
            "Wettbewerb."),
#else
            "A hold item that\n"
            "raises Beauty in\n"
            "Contests."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_BlueScarf,
    },

    [ITEM_PINK_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Rosa Schal"),
        .pluralName = ITEM_PLURAL_NAME("Rosa Schals"),
#else
        .name = ITEM_NAME("PINK SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Pink Scarves"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Anmut-Wert für den\n"
            "Wettbewerb."),
#else
            "A hold item that\n"
            "raises Cute in\n"
            "Contests."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_PinkScarf,
    },

    [ITEM_GREEN_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Grüner Schal"),
        .pluralName = ITEM_PLURAL_NAME("Grüne Schals"),
#else
        .name = ITEM_NAME("GREEN SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Green Scarves"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Klug.-Wert für den\n"
            "Wettbewerb."),
#else
            "A hold item that\n"
            "raises Smart in\n"
            "Contests."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_GreenScarf,
    },

    [ITEM_YELLOW_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Gelber Schal"),
        .pluralName = ITEM_PLURAL_NAME("Gelbe Schals"),
#else
        .name = ITEM_NAME("YELLOW SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Yellow Scarves"),
#endif
        .price = 100,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Stärke-Wert für\n"
            "den Wettbewerb."),
#else
            "A hold item that\n"
            "raises Tough in\n"
            "Contests."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_CONTEST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Scarf,
        .iconPalette = gItemIconPalette_YellowScarf,
    },

// EV Gain Modifiers

    [ITEM_MACHO_BRACE] =
    {
#if GERMAN
        .name = ITEM_NAME("Machoband"),
        .pluralName = ITEM_PLURAL_NAME("Machobänder"),
#else
        .name = ITEM_NAME("MACHO BRACE"),
#endif
        .price = 3000,
        .holdEffect = HOLD_EFFECT_MACHO_BRACE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert Wachstum,\n"
            "senkt Init."),
#else
            "A hold item that\n"
            "promotes growth,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_MachoBrace,
        .iconPalette = gItemIconPalette_MachoBrace,
    },

    [ITEM_POWER_WEIGHT] =
    {
#if GERMAN
        .name = ITEM_NAME("Machtgewicht"),
        .pluralName = ITEM_PLURAL_NAME("Machtgewichte"),
#else
        .name = ITEM_NAME("POWER WEIGHT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert KP, senkt\n"
            "Init."),
#else
            "A hold item that\n"
            "promotes HP gain,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_HP,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerWeight,
        .iconPalette = gItemIconPalette_PowerWeight,
    },

    [ITEM_POWER_BRACER] =
    {
#if GERMAN
        .name = ITEM_NAME("Machtreif"),
        .pluralName = ITEM_PLURAL_NAME("Machtreife"),
#else
        .name = ITEM_NAME("POWER BRACER"),
#endif
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert Angr.,\n"
            "senkt Init."),
#else
            "A hold item that\n"
            "promotes Atk gain,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_ATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBracer,
        .iconPalette = gItemIconPalette_PowerBracer,
    },

    [ITEM_POWER_BELT] =
    {
#if GERMAN
        .name = ITEM_NAME("Machtgurt"),
        .pluralName = ITEM_PLURAL_NAME("Machtgurte"),
#else
        .name = ITEM_NAME("POWER BELT"),
#endif
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert Vert.,\n"
            "senkt Init."),
#else
            "A hold item that\n"
            "promotes Def gain,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_DEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBelt,
        .iconPalette = gItemIconPalette_PowerBelt,
    },

    [ITEM_POWER_LENS] =
    {
#if GERMAN
        .name = ITEM_NAME("Machtlinse"),
        .pluralName = ITEM_PLURAL_NAME("Machtlinsen"),
#else
        .name = ITEM_NAME("POWER LENS"),
        .pluralName = ITEM_PLURAL_NAME("Power Lenses"),
#endif
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert Sp. Angr.,\n"
            "senkt Init."),
#else
            "Hold item that pro-\n"
            "motes Sp. Atk gain,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPATK,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerLens,
        .iconPalette = gItemIconPalette_PowerLens,
    },

    [ITEM_POWER_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Machtband"),
        .pluralName = ITEM_PLURAL_NAME("Machtbänder"),
#else
        .name = ITEM_NAME("POWER BAND"),
#endif
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert Sp. Vert.,\n"
            "senkt Init."),
#else
            "Hold item that pro-\n"
            "motes Sp. Def gain,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPDEF,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerBand,
        .iconPalette = gItemIconPalette_PowerBand,
    },

    [ITEM_POWER_ANKLET] =
    {
#if GERMAN
        .name = ITEM_NAME("Machtkette"),
        .pluralName = ITEM_PLURAL_NAME("Machtketten"),
#else
        .name = ITEM_NAME("POWER ANKLET"),
#endif
        .price = (I_PRICE >= GEN_9) ? 10000 : 3000,
        .holdEffect = HOLD_EFFECT_POWER_ITEM,
        .holdEffectParam = POWER_ITEM_BOOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "fördert Init., senkt\n"
            "Init."),
#else
            "A hold item that\n"
            "promotes Spd gain,\n"
            "but reduces Speed."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EV_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = STAT_SPEED,
        .flingPower = 70,
        .iconPic = gItemIcon_PowerAnklet,
        .iconPalette = gItemIconPalette_PowerAnklet,
    },

// Type-boosting Held Items
    #if I_PRICE >= GEN_9
        #define TYPE_BOOSTING_PRICE 3000
    #elif I_PRICE >= GEN_7
        #define TYPE_BOOSTING_PRICE 1000
    #else
        #define TYPE_BOOSTING_PRICE 100
    #endif

    [ITEM_SILK_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Seidenschal"),
        .pluralName = ITEM_PLURAL_NAME("Seidenschals"),
#else
        .name = ITEM_NAME("SILK SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Silk Scarves"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Normal-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Normal-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_NORMAL,
        .flingPower = 10,
        .iconPic = gItemIcon_SilkScarf,
        .iconPalette = gItemIconPalette_SilkScarf,
    },

    [ITEM_CHARCOAL] =
    {
#if GERMAN
        .name = ITEM_NAME("Holzkohle"),
        .pluralName = ITEM_PLURAL_NAME("Holzkohlen"),
#else
        .name = ITEM_NAME("CHARCOAL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 1000,
    #else
        .price = 9800,
    #endif
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Feuer-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Fire-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIRE,
        .flingPower = 30,
        .iconPic = gItemIcon_Charcoal,
        .iconPalette = gItemIconPalette_Charcoal,
    },

    [ITEM_MYSTIC_WATER] =
    {
#if GERMAN
        .name = ITEM_NAME("Zauberwasser"),
        .pluralName = ITEM_PLURAL_NAME("Zauberwässer"),
#else
        .name = ITEM_NAME("MYSTIC WATER"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Wasser-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Water-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_WATER,
        .flingPower = 30,
        .iconPic = gItemIcon_MysticWater,
        .iconPalette = gItemIconPalette_MysticWater,
    },

    [ITEM_MAGNET] =
    {
#if GERMAN
        .name = ITEM_NAME("Magnet"),
        .pluralName = ITEM_PLURAL_NAME("Magnete"),
#else
        .name = ITEM_NAME("MAGNET"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Elektro-Attacken."),
#else
            "A hold item that\n"
            "boosts Electric-\n"
            "type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ELECTRIC,
        .flingPower = 30,
        .iconPic = gItemIcon_Magnet,
        .iconPalette = gItemIconPalette_Magnet,
    },

    [ITEM_MIRACLE_SEED] =
    {
#if GERMAN
        .name = ITEM_NAME("Wundersaat"),
        .pluralName = ITEM_PLURAL_NAME("Wundersaaten"),
#else
        .name = ITEM_NAME("MIRACLE SEED"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRoseIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GRASS,
        .flingPower = 30,
        .iconPic = gItemIcon_MiracleSeed,
        .iconPalette = gItemIconPalette_MiracleSeed,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
#if GERMAN
        .name = ITEM_NAME("Ewiges Eis"),
        .pluralName = ITEM_PLURAL_NAME("Ewiges Eis"),
#else
        .name = ITEM_NAME("NEVER-MELT ICE"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Eis-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Ice-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ICE,
        .flingPower = 30,
        .iconPic = gItemIcon_NeverMeltIce,
        .iconPalette = gItemIconPalette_NeverMeltIce,
    },

    [ITEM_BLACK_BELT] =
    {
#if GERMAN
        .name = ITEM_NAME("Schwarzgurt"),
        .pluralName = ITEM_PLURAL_NAME("Schwarzgurte"),
#else
        .name = ITEM_NAME("BLACK BELT"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Kampf-Attacken."),
#else
            "A hold item that\n"
            "boosts Fighting-\n"
            "type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FIGHTING,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackBelt,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_POISON_BARB] =
    {
#if GERMAN
        .name = ITEM_NAME("Giftstich"),
        .pluralName = ITEM_PLURAL_NAME("Giftstiche"),
#else
        .name = ITEM_NAME("POISON BARB"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Gift-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Poison-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_POISON,
        .flingPower = 70,
        .iconPic = gItemIcon_PoisonBarb,
        .iconPalette = gItemIconPalette_PoisonBarb,
    },

    [ITEM_SOFT_SAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Pudersand"),
        .pluralName = ITEM_PLURAL_NAME("Pudersande"),
#else
        .name = ITEM_NAME("SOFT SAND"),
        .pluralName = ITEM_PLURAL_NAME("Soft Sand"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Boden-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Ground-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GROUND,
        .flingPower = 10,
        .iconPic = gItemIcon_Sand,
        .iconPalette = gItemIconPalette_SoftSand,
    },

    [ITEM_SHARP_BEAK] =
    {
#if GERMAN
        .name = ITEM_NAME("Hackattack"),
        .pluralName = ITEM_PLURAL_NAME("Hackattacken"),
#else
        .name = ITEM_NAME("SHARP BEAK"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Flug-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Flying-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FLYING,
        .flingPower = 50,
        .iconPic = gItemIcon_SharpBeak,
        .iconPalette = gItemIconPalette_SharpBeak,
    },

    [ITEM_TWISTED_SPOON] =
    {
#if GERMAN
        .name = ITEM_NAME("Krummlöffel"),
        .pluralName = ITEM_PLURAL_NAME("Krummlöffel"),
#else
        .name = ITEM_NAME("TWISTED SPOON"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sOddIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_PSYCHIC,
        .flingPower = 30,
        .iconPic = gItemIcon_TwistedSpoon,
        .iconPalette = gItemIconPalette_TwistedSpoon,
    },

    [ITEM_SILVER_POWDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Silberstaub"),
        .pluralName = ITEM_PLURAL_NAME("Silberstaub"),
#else
        .name = ITEM_NAME("SILVER POWDER"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verbessert\n"
            "Käfer-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Bug-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_BUG,
        .flingPower = 10,
        .iconPic = gItemIcon_SilverPowder,
        .iconPalette = gItemIconPalette_SilverPowder,
    },

    [ITEM_HARD_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Granitstein"),
        .pluralName = ITEM_PLURAL_NAME("Granitsteine"),
#else
        .name = ITEM_NAME("HARD STONE"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = sRockIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_ROCK,
        .flingPower = 100,
        .iconPic = gItemIcon_HardStone,
        .iconPalette = gItemIconPalette_HardStone,
    },

    [ITEM_SPELL_TAG] =
    {
#if GERMAN
        .name = ITEM_NAME("Bannsticker"),
        .pluralName = ITEM_PLURAL_NAME("Bannsticker"),
#else
        .name = ITEM_NAME("SPELL TAG"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Geist-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Ghost-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_GHOST,
        .flingPower = 30,
        .iconPic = gItemIcon_SpellTag,
        .iconPalette = gItemIconPalette_SpellTag,
    },

    [ITEM_DRAGON_FANG] =
    {
#if GERMAN
        .name = ITEM_NAME("Drachenzahn"),
        .pluralName = ITEM_PLURAL_NAME("Drachenzähne"),
#else
        .name = ITEM_NAME("DRAGON FANG"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Drachen-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Dragon-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DRAGON,
        .flingPower = 70,
        .iconPic = gItemIcon_DragonFang,
        .iconPalette = gItemIconPalette_DragonFang,
    },

    [ITEM_BLACK_GLASSES] =
    {
#if GERMAN
        .name = ITEM_NAME("Schattenglas"),
        .pluralName = ITEM_PLURAL_NAME("Schattengläser"),
#else
        .name = ITEM_NAME("BLACK GLASSES"),
        .pluralName = ITEM_PLURAL_NAME("Black Glasses"),
#endif
        .price = TYPE_BOOSTING_PRICE,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Unlicht-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Dark-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_DARK,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackGlasses,
        .iconPalette = gItemIconPalette_BlackTypeEnhancingItem,
    },

    [ITEM_METAL_COAT] =
    {
#if GERMAN
        .name = ITEM_NAME("Metallmantel"),
        .pluralName = ITEM_PLURAL_NAME("Metallmäntel"),
        // HnS price (2.0.2).
#else
        .name = ITEM_NAME("METAL COAT"),
#endif
        //#if I_PRICE >= GEN_9
        //    .price = 3000,
        //#elif I_PRICE >= GEN_7
        //    .price = 2000,
        //#else
        //    .price = 100,
        //#endif
        .price = 20000,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Stahl-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Steel-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .secondaryId = TYPE_STEEL,
        .flingPower = 30,
        .iconPic = gItemIcon_MetalCoat,
        .iconPalette = gItemIconPalette_MetalCoat,
    },

// Choice Items

    [ITEM_CHOICE_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Wahlband"),
        .pluralName = ITEM_PLURAL_NAME("Wahlbänder"),
#else
        .name = ITEM_NAME("CHOICE BAND"),
#endif
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_BAND,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt eine Atta-\n"
            "cke. Aber nur diese\n"
            "ist einsetzbar."),
#else
            "Boosts Attack, but\n"
            "allows the use of\n"
            "only one move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceBand,
        .iconPalette = gItemIconPalette_ChoiceBand,
    },

    [ITEM_CHOICE_SPECS] =
    {
#if GERMAN
        .name = ITEM_NAME("Wahlglas"),
        .pluralName = ITEM_PLURAL_NAME("Wahlgläser"),
#else
        .name = ITEM_NAME("CHOICE SPECS"),
        .pluralName = ITEM_PLURAL_NAME("Choice Specs"),
#endif
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SPECS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt Sp. Angr.\n"
            "Aber nur eine Atta-\n"
            "cke ist einsetzbar."),
#else
            "Boosts Sp. Atk, but\n"
            "allows the use of\n"
            "only one move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceSpecs,
        .iconPalette = gItemIconPalette_ChoiceSpecs,
    },

    [ITEM_CHOICE_SCARF] =
    {
#if GERMAN
        .name = ITEM_NAME("Wahlschal"),
        .pluralName = ITEM_PLURAL_NAME("Wahlschals"),
#else
        .name = ITEM_NAME("CHOICE SCARF"),
        .pluralName = ITEM_PLURAL_NAME("Choice Scarves"),
#endif
    #if I_PRICE >= GEN_9
        .price = 100000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_CHOICE_SCARF,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt Init. Aber\n"
            "nur eine Attacke\n"
            "ist einsetzbar."),
#else
            "Boosts Speed, but\n"
            "allows the use of\n"
            "only one move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChoiceScarf,
        .iconPalette = gItemIconPalette_ChoiceScarf,
    },

// Status Orbs

    [ITEM_FLAME_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Heiß-Orb"),
        .pluralName = ITEM_PLURAL_NAME("Heiß-Orbs"),
#else
        .name = ITEM_NAME("FLAME ORB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLAME_ORB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) fügt\n"
            "dem Träger im Kampf\n"
            "Verbrennung zu."),
#else
            "A bizarre orb that\n"
            "inflicts a burn on\n"
            "holder in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FlameOrb,
        .iconPalette = gItemIconPalette_FlameOrb,
    },

    [ITEM_TOXIC_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Toxik-Orb"),
        .pluralName = ITEM_PLURAL_NAME("Toxik-Orbs"),
#else
        .name = ITEM_NAME("TOXIC ORB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_TOXIC_ORB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) ver-\n"
            "giftet den Träger\n"
            "im Kampf schwer."),
#else
            "A bizarre orb that\n"
            "badly poisons the\n"
            "holder in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ToxicOrb,
        .iconPalette = gItemIconPalette_ToxicOrb,
    },

// Weather Rocks

    [ITEM_DAMP_ROCK] =
    {
#if GERMAN
        .name = ITEM_NAME("Nassbrocken"),
        .pluralName = ITEM_PLURAL_NAME("Nassbrocken"),
#else
        .name = ITEM_NAME("DAMP ROCK"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DAMP_ROCK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Regentanz."),
#else
            "Extends the length\n"
            "of Rain Dance if\n"
            "used by the holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_DampRock,
        .iconPalette = gItemIconPalette_DampRock,
    },

    [ITEM_HEAT_ROCK] =
    {
#if GERMAN
        .name = ITEM_NAME("Heißbrocken"),
        .pluralName = ITEM_PLURAL_NAME("Heißbrocken"),
#else
        .name = ITEM_NAME("HEAT ROCK"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_HEAT_ROCK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Sonnentag."),
#else
            "Extends the length\n"
            "of Sunny Day if\n"
            "used by the holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_HeatRock,
        .iconPalette = gItemIconPalette_HeatRock,
    },

    [ITEM_SMOOTH_ROCK] =
    {
#if GERMAN
        .name = ITEM_NAME("Glattbrocken"),
        .pluralName = ITEM_PLURAL_NAME("Glattbrocken"),
#else
        .name = ITEM_NAME("SMOOTH ROCK"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SMOOTH_ROCK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Sandsturm."),
#else
            "Extends the length\n"
            "of Sandstorm if\n"
            "used by the holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SmoothRock,
        .iconPalette = gItemIconPalette_SmoothRock,
    },

    [ITEM_ICY_ROCK] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisbrocken"),
        .pluralName = ITEM_PLURAL_NAME("Eisbrocken"),
#else
        .name = ITEM_NAME("ICY ROCK"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ICY_ROCK,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_HAIL
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Hagelsturm."),
#else
            "Extends the length\n"
            "of the move Hail\n"
            "used by the holder."),
#endif
    #elif B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Schneelandschaft."),
#else
            "Extends the length\n"
            "of Snowscape if\n"
            "used by the holder."),
#endif
    #else
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert kaltes\n"
            "Wetter."),
#else
            "Extends the length\n"
            "of cold weathers\n"
            "used by the holder."),
#endif
    #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_IcyRock,
        .iconPalette = gItemIconPalette_IcyRock,
    },

// Terrain Seeds

    [ITEM_ELECTRIC_SEED] =
    {
#if GERMAN
        .name = ITEM_NAME("Elektro-Samen"),
#else
        .name = ITEM_NAME("ELECTRIC SEED"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_ELECTRIC_TERRAIN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Vert. auf Elektro-\n"
            "feld einmalig."),
#else
            "Boosts Defense on\n"
            "Electric Terrain,\n"
            "but only one time."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_ElectricSeed,
    },

    [ITEM_PSYCHIC_SEED] =
    {
#if GERMAN
        .name = ITEM_NAME("Psycho-Samen"),
#else
        .name = ITEM_NAME("PSYCHIC SEED"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_PSYCHIC_TERRAIN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert. auf Psy-\n"
            "chofeld einmalig."),
#else
            "Boosts Sp. Def. on\n"
            "Psychic Terrain,\n"
            "but only one time."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_PsychicSeed,
    },

    [ITEM_MISTY_SEED] =
    {
#if GERMAN
        .name = ITEM_NAME("Nebel-Samen"),
#else
        .name = ITEM_NAME("MISTY SEED"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_MISTY_TERRAIN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert. auf\n"
            "Nebelfeld einmalig."),
#else
            "Boosts Sp. Def. on\n"
            "Misty Terrain,\n"
            "but only one time."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_MistySeed,
    },

    [ITEM_GRASSY_SEED] =
    {
#if GERMAN
        .name = ITEM_NAME("Gras-Samen"),
#else
        .name = ITEM_NAME("GRASSY SEED"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_SEED,
        .holdEffectParam = HOLD_EFFECT_PARAM_GRASSY_TERRAIN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Vert. auf Grasfeld\n"
            "einmalig."),
#else
            "Boosts Defense on\n"
            "Grassy Terrain,\n"
            "but only one time."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TerrainSeed,
        .iconPalette = gItemIconPalette_GrassySeed,
    },

// Type-activated Stat Modifiers

    [ITEM_ABSORB_BULB] =
    {
#if GERMAN
        .name = ITEM_NAME("Knolle"),
#else
        .name = ITEM_NAME("ABSORB BULB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ABSORB_BULB,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Angr. bei\n"
            "Wasser-Attacke."),
#else
            "Raises Sp. Atk if\n"
            "the holder is hit by\n"
            "a Water-type move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbsorbBulb,
        .iconPalette = gItemIconPalette_AbsorbBulb,
    },

    [ITEM_CELL_BATTERY] =
    {
#if GERMAN
        .name = ITEM_NAME("Akku"),
        .pluralName = ITEM_PLURAL_NAME("Akkus"),
#else
        .name = ITEM_NAME("CELL BATTERY"),
        .pluralName = ITEM_PLURAL_NAME("Cell Batteries"),
#endif
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CELL_BATTERY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Angr. bei\n"
            "Elektro-Attacke."),
#else
            "Raises Attack if\n"
            "the holder is hit by\n"
            "an Electric move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CellBattery,
        .iconPalette = gItemIconPalette_CellBattery,
    },

    [ITEM_LUMINOUS_MOSS] =
    {
#if GERMAN
        .name = ITEM_NAME("Leuchtmoos"),
#else
        .name = ITEM_NAME("LUMINOUS MOSS"),
        .pluralName = ITEM_PLURAL_NAME("Luminous Moss"),
#endif
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_LUMINOUS_MOSS,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert. bei\n"
            "Wasser-Attacke."),
#else
            "Raises Sp. Def if\n"
            "the holder is hit by\n"
            "a Water-type move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuminousMoss,
        .iconPalette = gItemIconPalette_LuminousMoss,
    },

    [ITEM_SNOWBALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Schneeball"),
        .pluralName = ITEM_PLURAL_NAME("Schneebälle"),
#else
        .name = ITEM_NAME("SNOWBALL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SNOWBALL,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Angr. bei\n"
            "Eis-Attacke."),
#else
            "Raises Atk if its\n"
            "holder is hit by an\n"
            "Ice-type move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Snowball,
        .iconPalette = gItemIconPalette_Snowball,
    },

// Misc. Held Items

    [ITEM_BRIGHT_POWDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Blendpuder"),
        .pluralName = ITEM_PLURAL_NAME("Blendpuder"),
#else
        .name = ITEM_NAME("BRIGHT POWDER"),
#endif
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 10,
    #endif
        .holdEffect = HOLD_EFFECT_EVASION_UP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) senkt\n"
            "die Genauigkeit\n"
            "des Gegners."),
#else
            "A hold item that\n"
            "casts a glare to\n"
            "reduce accuracy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BrightPowder,
        .iconPalette = gItemIconPalette_BrightPowder,
    },

    [ITEM_WHITE_HERB] =
    {
#if GERMAN
        .name = ITEM_NAME("Schlohkraut"),
        .pluralName = ITEM_PLURAL_NAME("Schlohkräuter"),
#else
        .name = ITEM_NAME("WHITE HERB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_WHITE_HERB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "jede Statusverän-\n"
            "derung auf."),
#else
            "A hold item that\n"
            "restores any\n"
            "lowered stat."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_WhiteHerb,
    },

    [ITEM_EXP_SHARE] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Teiler"),
#else
        .name = ITEM_NAME("EXP. SHARE"),
#endif
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
    #if I_EXP_SHARE_ITEM >= GEN_6
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) teilt\n"
            "die Kampf-EP."),
#else
            "This device gives\n"
            "exp. to other\n"
            "party members."),
#endif
        .pocket = POCKET_KEY_ITEMS,
    #else
        .price = (I_PRICE == GEN_1) ? 1 : 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "bringt EP aus\n"
            "Kämpfen ein."),
#else
            "A hold item that\n"
            "gets Exp. points\n"
            "from battles."),
#endif
        .pocket = POCKET_ITEMS,
    #endif
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_ExpShare,
        .flingPower = 30,
        .iconPic = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_QUICK_CLAW] =
    {
#if GERMAN
        .name = ITEM_NAME("Flinkklaue"),
        .pluralName = ITEM_PLURAL_NAME("Flinkklauen"),
#else
        .name = ITEM_NAME("QUICK CLAW"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_QUICK_CLAW,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "die Erstschlag-\n"
            "quote."),
#else
            "A hold item that\n"
            "occasionally allows\n"
            "the first strike."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_QuickClaw,
        .iconPalette = gItemIconPalette_QuickClaw,
    },

    [ITEM_SOOTHE_BELL] =
    {
#if GERMAN
        .name = ITEM_NAME("Sanftglocke"),
        .pluralName = ITEM_PLURAL_NAME("Sanftglocken"),
#else
        .name = ITEM_NAME("SOOTHE BELL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FRIENDSHIP_UP,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "sänftigt und för-\n"
            "dert Sympathie."),
#else
            "A hold item that\n"
            "calms spirits and\n"
            "fosters friendship."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SootheBell,
        .iconPalette = gItemIconPalette_SootheBell,
    },

    [ITEM_MENTAL_HERB] =
    {
#if GERMAN
        .name = ITEM_NAME("Mentalkraut"),
        .pluralName = ITEM_PLURAL_NAME("Mentalkräuter"),
#else
        .name = ITEM_NAME("MENTAL HERB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_MENTAL_HERB,
        .description = COMPOUND_STRING(
        #if B_MENTAL_HERB >= GEN_5
#if GERMAN
            "Befreit Pokémon\n"
            "von Binde-\n"
            "Effekten."),
#else
            "Snaps Pokémon out\n"
            "of move-binding\n"
            "effects."),
#endif
        #else
#if GERMAN
            "Item (Tragen) er-\n"
            "löst Pokémon von\n"
            "der Anziehung."),
#else
            "A hold item that\n"
            "snaps Pokémon out\n"
            "of infatuation."),
#endif
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_InBattleHerb,
        .iconPalette = gItemIconPalette_MentalHerb,
    },

    [ITEM_KINGS_ROCK] =
    {
#if GERMAN
        .name = ITEM_NAME("King-Stein"),
        .pluralName = ITEM_PLURAL_NAME("King-Steine"),
#else
        .name = ITEM_NAME("KING'S ROCK"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_KingsRock,
        .iconPalette = gItemIconPalette_KingsRock,
    },

    [ITEM_AMULET_COIN] =
    {
#if GERMAN
        .name = ITEM_NAME("Münzamulett"),
        .pluralName = ITEM_PLURAL_NAME("Münzamulette"),
#else
        .name = ITEM_NAME("AMULET COIN"),
#endif
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 10000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_DOUBLE_PRIZE,
        .description = sLuckIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AmuletCoin,
        .iconPalette = gItemIconPalette_AmuletCoin,
    },

    [ITEM_CLEANSE_TAG] =
    {
#if GERMAN
        .name = ITEM_NAME("Schutzband"),
        .pluralName = ITEM_PLURAL_NAME("Schutzbänder"),
#else
        .name = ITEM_NAME("CLEANSE TAG"),
#endif
        .price = (I_PRICE >= GEN_7) ? 5000 : 200,
        .holdEffect = HOLD_EFFECT_REPEL,
        .description = sPureIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CleanseTag,
        .iconPalette = gItemIconPalette_CleanseTag,
    },

    [ITEM_SMOKE_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Rauchball"),
        .pluralName = ITEM_PLURAL_NAME("Rauchbälle"),
#else
        .name = ITEM_NAME("SMOKE BALL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_CAN_ALWAYS_RUN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) er-\n"
            "möglicht Flucht vor\n"
            "wilden Pokémon."),
#else
            "A hold item that\n"
            "assures fleeing\n"
            "from wild Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_SmokeBall,
        .iconPalette = gItemIconPalette_SmokeBall,
    },

    [ITEM_FOCUS_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Fokus-Band"),
        .pluralName = ITEM_PLURAL_NAME("Fokus-Bänder"),
#else
        .name = ITEM_NAME("FOCUS BAND"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) kann\n"
            "manchmal K.O.\n"
            "verhindern."),
#else
            "A hold item that\n"
            "occasionally\n"
            "prevents fainting."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusBand,
        .iconPalette = gItemIconPalette_FocusBand,
    },

    [ITEM_LUCKY_EGG] =
    {
#if GERMAN
        .name = ITEM_NAME("Glücks-Ei"),
        .pluralName = ITEM_PLURAL_NAME("Glücks-Eier"),
#else
        .name = ITEM_NAME("LUCKY EGG"),
#endif
        .price = (I_PRICE >= GEN_7) ? 10000 : 200,
        .holdEffect = HOLD_EFFECT_LUCKY_EGG,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht im Kampf er-\n"
            "haltene EP."),
#else
            "A hold item that\n"
            "boosts Exp. points\n"
            "earned in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LuckyEgg,
        .iconPalette = gItemIconPalette_LuckyEgg,
    },

    [ITEM_SCOPE_LENS] =
    {
#if GERMAN
        .name = ITEM_NAME("Scope-Linse"),
        .pluralName = ITEM_PLURAL_NAME("Scope-Linsen"),
#else
        .name = ITEM_NAME("SCOPE LENS"),
        .pluralName = ITEM_PLURAL_NAME("Scope Lenses"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht die\n"
            "Volltrefferquote."),
#else
            "A hold item that\n"
            "improves the\n"
            "critical-hit rate."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ScopeLens,
        .iconPalette = gItemIconPalette_ScopeLens,
    },

    [ITEM_LEFTOVERS] =
    {
#if GERMAN
        .name = ITEM_NAME("Überreste"),
        .pluralName = ITEM_PLURAL_NAME("Überreste"),
#else
        .name = ITEM_NAME("LEFTOVERS"),
        .pluralName = ITEM_PLURAL_NAME("Leftovers"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LEFTOVERS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "im Kampf langsam KP\n"
            "wieder auf."),
#else
            "A hold item that\n"
            "gradually restores\n"
            "HP in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_Leftovers,
        .iconPalette = gItemIconPalette_Leftovers,
    },

    [ITEM_SHELL_BELL] =
    {
#if GERMAN
        .name = ITEM_NAME("Seegesang"),
        .pluralName = ITEM_PLURAL_NAME("Seegesänge"),
#else
        .name = ITEM_NAME("SHELL BELL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_SHELL_BELL,
        .holdEffectParam = 8,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "im Kampf langsam KP\n"
            "wieder auf."),
#else
            "A hold item that\n"
            "restores HP upon\n"
            "striking the foe."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ShellBell,
        .iconPalette = gItemIconPalette_Shell,
    },

    [ITEM_WIDE_LENS] =
    {
#if GERMAN
        .name = ITEM_NAME("Großlinse"),
        .pluralName = ITEM_PLURAL_NAME("Großlinsen"),
#else
        .name = ITEM_NAME("WIDE LENS"),
        .pluralName = ITEM_PLURAL_NAME("Wide Lenses"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WIDE_LENS,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht die\n"
            "Genauigkeit."),
#else
            "A magnifying lens\n"
            "that boosts the\n"
            "accuracy of moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WideLens,
        .iconPalette = gItemIconPalette_WideLens,
    },

    [ITEM_MUSCLE_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Muskelband"),
        .pluralName = ITEM_PLURAL_NAME("Muskelbänder"),
#else
        .name = ITEM_NAME("MUSCLE BAND"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_MUSCLE_BAND,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) ver-\n"
            "stärkt physische\n"
            "Attacken."),
#else
            "A headband that\n"
            "boosts the power\n"
            "of physical moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MuscleBand,
        .iconPalette = gItemIconPalette_MuscleBand,
    },

    [ITEM_WISE_GLASSES] =
    {
#if GERMAN
        .name = ITEM_NAME("Schlauglas"),
        .pluralName = ITEM_PLURAL_NAME("Schlaugläser"),
#else
        .name = ITEM_NAME("WISE GLASSES"),
        .pluralName = ITEM_PLURAL_NAME("Wise Glasses"),
#endif
    #if I_PRICE >= GEN_9
        .price = 8000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_WISE_GLASSES,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Spezial-Attacken."),
#else
            "A pair of glasses\n"
            "that ups the power\n"
            "of special moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WiseGlasses,
        .iconPalette = gItemIconPalette_WiseGlasses,
    },

    [ITEM_EXPERT_BELT] =
    {
#if GERMAN
        .name = ITEM_NAME("Expertengurt"),
        .pluralName = ITEM_PLURAL_NAME("Expertengurte"),
#else
        .name = ITEM_NAME("EXPERT BELT"),
#endif
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EXPERT_BELT,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) ver-\n"
            "stärkt sehr effek-\n"
            "tive Attacken."),
#else
            "A belt that boosts\n"
            "the power of super\n"
            "effective moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ExpertBelt,
        .iconPalette = gItemIconPalette_ExpertBelt,
    },

    [ITEM_LIGHT_CLAY] =
    {
#if GERMAN
        .name = ITEM_NAME("Lichtlehm"),
        .pluralName = ITEM_PLURAL_NAME("Lichtlehme"),
#else
        .name = ITEM_NAME("LIGHT CLAY"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIGHT_CLAY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Schutzwände."),
#else
            "Extends the length\n"
            "of barrier moves\n"
            "used by the holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LightClay,
        .iconPalette = gItemIconPalette_LightClay,
    },

    [ITEM_LIFE_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Leben-Orb"),
        .pluralName = ITEM_PLURAL_NAME("Leben-Orbs"),
#else
        .name = ITEM_NAME("LIFE ORB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LIFE_ORB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "stärkt Attacken,\n"
            "kostet aber KP."),
#else
            "Boosts move power\n"
            "but holder loses HP\n"
            "with each attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LifeOrb,
        .iconPalette = gItemIconPalette_LifeOrb,
    },

    [ITEM_POWER_HERB] =
    {
#if GERMAN
        .name = ITEM_NAME("Energiekraut"),
        .pluralName = ITEM_PLURAL_NAME("Energiekräuter"),
#else
        .name = ITEM_NAME("POWER HERB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_POWER_HERB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Item zum\n"
            "einmaligen Tragen."),
#else
            "Allows immediate\n"
            "use of a move that\n"
            "charges first."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PowerHerb,
        .iconPalette = gItemIconPalette_PowerHerb,
    },

    [ITEM_FOCUS_SASH] =
    {
#if GERMAN
        .name = ITEM_NAME("Fokusgurt"),
        .pluralName = ITEM_PLURAL_NAME("Fokusgurte"),
#else
        .name = ITEM_NAME("FOCUS SASH"),
        .pluralName = ITEM_PLURAL_NAME("Focus Sashes"),
#endif
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FOCUS_SASH,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bei vollen KP über-\n"
            "lebt der Träger\n"
            "einen K.o. mit 1 KP."),
#else
            "If the holder has\n"
            "full HP, it endures\n"
            "KO hits with 1 HP."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FocusSash,
        .iconPalette = gItemIconPalette_FocusSash,
    },

    [ITEM_ZOOM_LENS] =
    {
#if GERMAN
        .name = ITEM_NAME("Zoomlinse"),
        .pluralName = ITEM_PLURAL_NAME("Zoomlinsen"),
#else
        .name = ITEM_NAME("ZOOM LENS"),
        .pluralName = ITEM_PLURAL_NAME("Zoom Lenses"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ZOOM_LENS,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht Genauigkeit\n"
            "bei Zweitschlag."),
#else
            "If the holder moves\n"
            "after the foe, it'll\n"
            "boost accuracy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ZoomLens,
        .iconPalette = gItemIconPalette_ZoomLens,
    },

    [ITEM_METRONOME] =
    {
#if GERMAN
        .name = ITEM_NAME("Metronom"),
        .pluralName = ITEM_PLURAL_NAME("Metronome"),
#else
        .name = ITEM_NAME("METRONOME"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_METRONOME,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "stärkt mehrfach\n"
            "genutzte Attacken."),
#else
            "A held item that\n"
            "boosts a move used\n"
            "consecutively."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_Metronome,
        .iconPalette = gItemIconPalette_Metronome,
    },

    [ITEM_IRON_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Eisenkugel"),
        .pluralName = ITEM_PLURAL_NAME("Eisenkugeln"),
#else
        .name = ITEM_NAME("IRON BALL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_IRON_BALL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) senkt\n"
            "Init. und macht\n"
            "anfällig für Boden."),
#else
            "Cuts Speed and\n"
            "becomes vulnerable\n"
            "to Ground moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 130,
        .iconPic = gItemIcon_IronBall,
        .iconPalette = gItemIconPalette_IronBall,
    },

    [ITEM_LAGGING_TAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Schwerschweif"),
#else
        .name = ITEM_NAME("LAGGING TAIL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_LAGGING_TAIL,
        .description = sFullIncenseDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LaggingTail,
        .iconPalette = gItemIconPalette_LaggingTail,
    },

    [ITEM_DESTINY_KNOT] =
    {
#if GERMAN
        .name = ITEM_NAME("Fatumknoten"),
        .pluralName = ITEM_PLURAL_NAME("Fatumknoten"),
#else
        .name = ITEM_NAME("DESTINY KNOT"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_DESTINY_KNOT,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verliebt auch den\n"
            "Gegner."),
#else
            "If the holder falls\n"
            "in love, the foe\n"
            "does too."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DestinyKnot,
        .iconPalette = gItemIconPalette_DestinyKnot,
    },

    [ITEM_BLACK_SLUDGE] =
    {
#if GERMAN
        .name = ITEM_NAME("Giftschleim"),
        .pluralName = ITEM_PLURAL_NAME("Giftschleime"),
#else
        .name = ITEM_NAME("BLACK SLUDGE"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BLACK_SLUDGE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt KP von\n"
            "Gift-Pokémon auf,\n"
            "schadet anderen."),
#else
            "Restores HP for\n"
            "Poison-types.\n"
            "Damages all others."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackSludge,
        .iconPalette = gItemIconPalette_BlackSludge,
    },

    [ITEM_GRIP_CLAW] =
    {
#if GERMAN
        .name = ITEM_NAME("Griffklaue"),
        .pluralName = ITEM_PLURAL_NAME("Griffklauen"),
#else
        .name = ITEM_NAME("GRIP CLAW"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_GRIP_CLAW,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert\n"
            "Binde-Attacken."),
#else
            "A held item that\n"
            "extends binding\n"
            "moves like Wrap."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 90,
        .iconPic = gItemIcon_GripClaw,
        .iconPalette = gItemIconPalette_GripClaw,
    },

    [ITEM_STICKY_BARB] =
    {
#if GERMAN
        .name = ITEM_NAME("Klettdorn"),
        .pluralName = ITEM_PLURAL_NAME("Klettdornen"),
#else
        .name = ITEM_NAME("STICKY BARB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_STICKY_BARB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schadet dem Träger\n"
            "jede Runde."),
#else
            "Damages the holder\n"
            "each turn. May\n"
            "latch on to foes."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_StickyBarb,
        .iconPalette = gItemIconPalette_StickyBarb,
    },

    [ITEM_SHED_SHELL] =
    {
#if GERMAN
        .name = ITEM_NAME("Wechselhülle"),
        .pluralName = ITEM_PLURAL_NAME("Wechselhüllen"),
#else
        .name = ITEM_NAME("SHED SHELL"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 100,
    #endif
        .holdEffect = HOLD_EFFECT_SHED_SHELL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erlaubt sicheres\n"
            "Auswechseln."),
#else
            "Allows the holder\n"
            "to switch out\n"
            "without fail."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShedShell,
        .iconPalette = gItemIconPalette_ShedShell,
    },

    [ITEM_BIG_ROOT] =
    {
#if GERMAN
        .name = ITEM_NAME("Großwurzel"),
        .pluralName = ITEM_PLURAL_NAME("Großwurzeln"),
#else
        .name = ITEM_NAME("BIG ROOT"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BIG_ROOT,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstärkt\n"
            "KP-stehlende\n"
            "Attacken."),
#else
            "A held item that\n"
            "ups the power of\n"
            "HP-stealing moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BigRoot,
        .iconPalette = gItemIconPalette_BigRoot,
    },

    [ITEM_RAZOR_CLAW] =
    {
#if GERMAN
        .name = ITEM_NAME("Scharfklaue"),
        .pluralName = ITEM_PLURAL_NAME("Scharfklauen"),
#else
        .name = ITEM_NAME("RAZOR CLAW"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_SCOPE_LENS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erhöht die\n"
            "Volltrefferquote."),
#else
            "A hooked claw that\n"
            "ups the holder's\n"
            "critical-hit ratio."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_RazorClaw,
        .iconPalette = gItemIconPalette_RazorClaw,
    },

    [ITEM_RAZOR_FANG] =
    {
#if GERMAN
        .name = ITEM_NAME("Scharfzahn"),
        .pluralName = ITEM_PLURAL_NAME("Scharfzähne"),
#else
        .name = ITEM_NAME("RAZOR FANG"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 5000,
    #else
        .price = 2100,
    #endif
        .holdEffect = HOLD_EFFECT_FLINCH,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = EVO_HELD_ITEM_TYPE,
        .fieldUseFunc = EVO_HELD_ITEM_FIELD_FUNC,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_RazorFang,
        .iconPalette = gItemIconPalette_RazorFang,
    },

    [ITEM_EVIOLITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Evolith"),
#else
        .name = ITEM_NAME("EVIOLITE"),
#endif
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EVIOLITE,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt Vert. und Sp.\n"
            "Vert. unentwickel-\n"
            "ter Pokémon."),
#else
            "Raises the Def and\n"
            "Sp. Def of Pokémon\n"
            "that can evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 40,
        .iconPic = gItemIcon_Eviolite,
        .iconPalette = gItemIconPalette_Eviolite,
    },

    [ITEM_FLOAT_STONE] =
    {
#if GERMAN
        .name = ITEM_NAME("Leichtstein"),
        .pluralName = ITEM_PLURAL_NAME("Leichtsteine"),
#else
        .name = ITEM_NAME("FLOAT STONE"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_FLOAT_STONE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hal-\n"
            "biert das Gewicht\n"
            "des Trägers."),
#else
            "It's so light that\n"
            "when held, it halves\n"
            "a Pokémon's weight."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_FloatStone,
        .iconPalette = gItemIconPalette_FloatStone,
    },

    [ITEM_ROCKY_HELMET] =
    {
#if GERMAN
        .name = ITEM_NAME("Beulenhelm"),
#else
        .name = ITEM_NAME("ROCKY HELMET"),
#endif
    #if I_PRICE >= GEN_9
        .price = 50000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_ROCKY_HELMET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schadet Gegnern\n"
            "bei Berührung."),
#else
            "Hurts the foe if\n"
            "they touch its\n"
            "holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_RockyHelmet,
        .iconPalette = gItemIconPalette_RockyHelmet,
    },

    [ITEM_AIR_BALLOON] =
    {
#if GERMAN
        .name = ITEM_NAME("Luftballon"),
#else
        .name = ITEM_NAME("AIR BALLOON"),
#endif
    #if I_PRICE >= GEN_9
        .price = 15000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_AIR_BALLOON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) lässt\n"
            "schweben, platzt\n"
            "bei Treffer."),
#else
            "Makes the holder\n"
            "float but bursts\n"
            "if hit by Attack."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AirBalloon,
        .iconPalette = gItemIconPalette_AirBalloon,
    },

    [ITEM_RED_CARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Rote Karte"),
        .pluralName = ITEM_PLURAL_NAME("Rote Karten"),
#else
        .name = ITEM_NAME("RED CARD"),
#endif
    #if I_PRICE >= GEN_9
        .price = 3000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RED_CARD,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) wech-\n"
            "selt den Gegner bei\n"
            "Treffer aus."),
#else
            "Switches out the\n"
            "foe if they hit the\n"
            "holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RedCard,
        .iconPalette = gItemIconPalette_RedCard,
    },

    [ITEM_RING_TARGET] =
    {
#if GERMAN
        .name = ITEM_NAME("Zielscheibe"),
#else
        .name = ITEM_NAME("RING TARGET"),
#endif
    #if I_PRICE >= GEN_9
        .price = 10000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_RING_TARGET,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) macht\n"
            "wirkungslose\n"
            "Attacken treffend."),
#else
            "Moves that usually\n"
            "have no effect will\n"
            "hit the holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RingTarget,
        .iconPalette = gItemIconPalette_RingTarget,
    },

    [ITEM_BINDING_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Klammerband"),
        .pluralName = ITEM_PLURAL_NAME("Klammerbänder"),
#else
        .name = ITEM_NAME("BINDING BAND"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_BINDING_BAND,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Binde-Attacken."),
#else
            "Increases the\n"
            "power of binding\n"
            "moves when held."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BindingBand,
        .iconPalette = gItemIconPalette_BindingBand,
    },

    [ITEM_EJECT_BUTTON] =
    {
#if GERMAN
        .name = ITEM_NAME("Fluchtknopf"),
#else
        .name = ITEM_NAME("EJECT BUTTON"),
#endif
    #if I_PRICE >= GEN_9
        .price = 30000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 200,
    #endif
        .holdEffect = HOLD_EFFECT_EJECT_BUTTON,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "wechselt den Träger\n"
            "bei Treffer aus."),
#else
            "Switches out the\n"
            "user if they're hit\n"
            "by the foe."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_EjectButton,
        .iconPalette = gItemIconPalette_EjectButton,
    },

    [ITEM_WEAKNESS_POLICY] =
    {
#if GERMAN
        .name = ITEM_NAME("Schwächenschutz"),
#else
        .name = ITEM_NAME("WEAKNESS POLICY"),
        .pluralName = ITEM_PLURAL_NAME("Weakness Policies"),
#endif
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_WEAKNESS_POLICY,
        .holdEffectParam = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt Angr. und Sp.\n"
            "Angr. bei sehr\n"
            "effektivem Treffer."),
#else
            "If hit by a super-\n"
            "effective move,\n"
            "ups Atk and Sp. Atk."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_WeaknessPolicy,
        .iconPalette = gItemIconPalette_WeaknessPolicy,
    },

    [ITEM_ASSAULT_VEST] =
    {
#if GERMAN
        .name = ITEM_NAME("Offensivweste"),
#else
        .name = ITEM_NAME("ASSAULT VEST"),
#endif
        .price = (I_PRICE >= GEN_9) ? 50000 : 1000,
        .holdEffect = HOLD_EFFECT_ASSAULT_VEST,
        .holdEffectParam = 50,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert., verbietet\n"
            "Status-Attacken."),
#else
            "Raises Sp. Def but\n"
            "prevents the use\n"
            "of status moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_AssaultVest,
        .iconPalette = gItemIconPalette_AssaultVest,
    },

    [ITEM_SAFETY_GOGGLES] =
    {
#if GERMAN
        .name = ITEM_NAME("Schutzbrille"),
        .pluralName = ITEM_PLURAL_NAME("Schutzbrillen"),
#else
        .name = ITEM_NAME("SAFETY GOGGLES"),
        .pluralName = ITEM_PLURAL_NAME("Safety Goggles"),
#endif
    #if I_PRICE >= GEN_9
        .price = 20000,
    #elif I_PRICE >= GEN_7
        .price = 4000,
    #else
        .price = 1000,
    #endif
        .holdEffect = HOLD_EFFECT_SAFETY_GOGGLES,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schützt vor Wetter\n"
            "und Puder."),
#else
            "Protect from\n"
            "weather damage and\n"
            "powder moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_SafetyGoggles,
        .iconPalette = gItemIconPalette_SafetyGoggles,
    },

    [ITEM_ADRENALINE_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Zitterorb"),
#else
        .name = ITEM_NAME("ADRENALINE ORB"),
#endif
    #if I_PRICE >= GEN_9
        .price = 5000,
    #elif I_PRICE == GEN_8
        .price = 4000,
    #else
        .price = 300,
    #endif
        .holdEffect = HOLD_EFFECT_ADRENALINE_ORB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Init. bei\n"
            "Einschüchterung."),
#else
            "This orb boosts\n"
            "Speed if the holder\n"
            "is intimidated."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AdrenalineOrb,
        .iconPalette = gItemIconPalette_AdrenalineOrb,
    },

    [ITEM_TERRAIN_EXTENDER] =
    {
#if GERMAN
        .name = ITEM_NAME("Feldbeschichtung"),
#else
        .name = ITEM_NAME("TERRAIN EXTENDER"),
#endif
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_TERRAIN_EXTENDER,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verlängert das\n"
            "aktive Feld."),
#else
            "Extends the length\n"
            "of the active\n"
            "battle terrain."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_TerrainExtender,
        .iconPalette = gItemIconPalette_TerrainExtender,
    },

    [ITEM_PROTECTIVE_PADS] =
    {
#if GERMAN
        .name = ITEM_NAME("Schutzpolster"),
#else
        .name = ITEM_NAME("PROTECTIVE PADS"),
        .pluralName = ITEM_PLURAL_NAME("Protective Pads"),
#endif
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_PROTECTIVE_PADS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schützt vor Effek-\n"
            "ten von Berührung."),
#else
            "Guard the holder\n"
            "from contact move\n"
            "effects."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ProtectivePads,
        .iconPalette = gItemIconPalette_ProtectivePads,
    },

    [ITEM_THROAT_SPRAY] =
    {
#if GERMAN
        .name = ITEM_NAME("Halsspray"),
#else
        .name = ITEM_NAME("THROAT SPRAY"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_THROAT_SPRAY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Angr. bei\n"
            "Lärm-Attacke."),
#else
            "Raises Sp. Atk. if\n"
            "the holder uses a\n"
            "sound-based move."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ThroatSpray,
        .iconPalette = gItemIconPalette_ThroatSpray,
    },

    [ITEM_EJECT_PACK] =
    {
#if GERMAN
        .name = ITEM_NAME("Fluchttasche"),
        .pluralName = ITEM_PLURAL_NAME("Fluchttaschen"),
#else
        .name = ITEM_NAME("EJECT PACK"),
#endif
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_EJECT_PACK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) wech-\n"
            "selt den Träger bei\n"
            "Statussenkung aus."),
#else
            "Forces the user to\n"
            "switch if its stats\n"
            "are lowered."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 50,
        .iconPic = gItemIcon_EjectPack,
        .iconPalette = gItemIconPalette_EjectPack,
    },

    [ITEM_HEAVY_DUTY_BOOTS] =
    {
#if GERMAN
        .name = ITEM_NAME("Plateauschuhe"),
#else
        .name = ITEM_NAME("HEAVY-DUTY BOOTS"),
        .pluralName = ITEM_PLURAL_NAME("Heavy-Duty Boots"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_HEAVY_DUTY_BOOTS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schützt vor Fallen\n"
            "im Feld."),
#else
            "Boots that prevent\n"
            "effects of traps\n"
            "set in the field."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_HeavyDutyBoots,
        .iconPalette = gItemIconPalette_HeavyDutyBoots,
    },

    [ITEM_BLUNDER_POLICY] =
    {
#if GERMAN
        .name = ITEM_NAME("Fehlschlagschutz"),
#else
        .name = ITEM_NAME("BLUNDER POLICY"),
        .pluralName = ITEM_PLURAL_NAME("Blunder Policies"),
#endif
        .price = (I_PRICE >= GEN_9) ? 30000 : 4000,
        .holdEffect = HOLD_EFFECT_BLUNDER_POLICY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Init. nach\n"
            "verfehlter Attacke."),
#else
            "Raises Speed if\n"
            "the user misses\n"
            "due to Accuracy."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 80,
        .iconPic = gItemIcon_BlunderPolicy,
        .iconPalette = gItemIconPalette_BlunderPolicy,
    },

    [ITEM_ROOM_SERVICE] =
    {
#if GERMAN
        .name = ITEM_NAME("Bizarroservice"),
#else
        .name = ITEM_NAME("ROOM SERVICE"),
#endif
        .price = (I_PRICE >= GEN_9) ? 20000 : 4000,
        .holdEffect = HOLD_EFFECT_ROOM_SERVICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt die Init. des\n"
            "Trägers, wenn\n"
            "Bizarroraum wirkt."),
#else
            "Lowers Speed if\n"
            "Trick Room is\n"
            "active."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 100,
        .iconPic = gItemIcon_RoomService,
        .iconPalette = gItemIconPalette_RoomService,
    },

    [ITEM_UTILITY_UMBRELLA] =
    {
#if GERMAN
        .name = ITEM_NAME("Allzweckschirm"),
#else
        .name = ITEM_NAME("UTILITY UMBRELLA"),
#endif
        .price = (I_PRICE >= GEN_9) ? 15000 : 4000,
        .holdEffect = HOLD_EFFECT_UTILITY_UMBRELLA,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schützt vor\n"
            "Wettereffekten."),
#else
            "An umbrella that\n"
            "protects from\n"
            "weather effects."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_UtilityUmbrella,
        .iconPalette = gItemIconPalette_UtilityUmbrella,
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Amrenabeere"),
        .pluralName = ITEM_PLURAL_NAME("Amrenabeeren"),
#else
        .name = ITEM_NAME("CHERI BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Cheri Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PAR,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Paralyse."),
#else
            "A hold item that\n"
            "heals paralysis\n"
            "in battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_ParalyzeHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_CheriBerry,
        .iconPalette = gItemIconPalette_CheriBerry,
    },

    [ITEM_CHESTO_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Maronbeere"),
        .pluralName = ITEM_PLURAL_NAME("Maronbeeren"),
#else
        .name = ITEM_NAME("CHESTO BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Chesto Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_SLP,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) weckt\n"
            "schlafendes\n"
            "Pokémon im Kampf."),
#else
            "A hold item that\n"
            "awakens Pokémon\n"
            "in battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Awakening,
        .flingPower = 10,
        .iconPic = gItemIcon_ChestoBerry,
        .iconPalette = gItemIconPalette_ChestoBerry,
    },

    [ITEM_PECHA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Pirsifbeere"),
        .pluralName = ITEM_PLURAL_NAME("Pirsifbeeren"),
#else
        .name = ITEM_NAME("PECHA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Pecha Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_PSN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Vergiftung."),
#else
            "A hold item that\n"
            "heals poisoning\n"
            "in battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_Antidote,
        .flingPower = 10,
        .iconPic = gItemIcon_PechaBerry,
        .iconPalette = gItemIconPalette_PechaBerry,
    },

    [ITEM_RAWST_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Fragiabeere"),
        .pluralName = ITEM_PLURAL_NAME("Fragiabeeren"),
#else
        .name = ITEM_NAME("RAWST BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Rawst Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_BRN,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Verbrennung."),
#else
            "A hold item that\n"
            "heals a burn in\n"
            "battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_BurnHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_RawstBerry,
        .iconPalette = gItemIconPalette_RawstBerry,
    },

    [ITEM_ASPEAR_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Wilbirbeere"),
        .pluralName = ITEM_PLURAL_NAME("Wilbirbeeren"),
#else
        .name = ITEM_NAME("ASPEAR BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Aspear Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_FRZ,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Frost."),
#else
            "A hold item that\n"
            "defrosts Pokémon\n"
            "in battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_IceHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_AspearBerry,
        .iconPalette = gItemIconPalette_AspearBerry,
    },

    [ITEM_LEPPA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Jonagobeere"),
        .pluralName = ITEM_PLURAL_NAME("Jonagobeeren"),
#else
        .name = ITEM_NAME("LEPPA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Leppa Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_PP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "AP im Kampf um 10\n"
            "Punkte auf."),
#else
            "A hold item that\n"
            "restores 10 PP in\n"
            "battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU_MOVES,
        .fieldUseFunc = ItemUseOutOfBattle_PPRecovery,
        .battleUsage = EFFECT_ITEM_RESTORE_PP,
        .effect = gItemEffect_LeppaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_LeppaBerry,
        .iconPalette = gItemIconPalette_LeppaBerry,
    },

    [ITEM_ORAN_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Sinelbeere"),
        .pluralName = ITEM_PLURAL_NAME("Sinelbeeren"),
#else
        .name = ITEM_NAME("ORAN BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Oran Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 10,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "KP im Kampf um 10\n"
            "Punkte auf."),
#else
            "A hold item that\n"
            "restores 10 HP in\n"
            "battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_OranBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_OranBerry,
        .iconPalette = gItemIconPalette_OranBerry,
    },

    [ITEM_PERSIM_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Persimbeere"),
        .pluralName = ITEM_PLURAL_NAME("Persimbeeren"),
#else
        .name = ITEM_NAME("PERSIM BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Persim Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_CONFUSION,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Verwirrung."),
#else
            "A hold item that\n"
            "heals confusion\n"
            "in battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_PersimBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PersimBerry,
        .iconPalette = gItemIconPalette_PersimBerry,
    },

    [ITEM_LUM_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Prunusbeere"),
        .pluralName = ITEM_PLURAL_NAME("Prunusbeeren"),
#else
        .name = ITEM_NAME("LUM BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Lum Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CURE_STATUS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) be-\n"
            "wirkt Selbstheilung\n"
            "bei Statusproblem."),
#else
            "A hold item that\n"
            "heals any status\n"
            "problem in battle."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 10,
        .iconPic = gItemIcon_LumBerry,
        .iconPalette = gItemIconPalette_LumBerry,
    },

    [ITEM_SITRUS_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Tsitrubeere"),
        .pluralName = ITEM_PLURAL_NAME("Tsitrubeeren"),
#else
        .name = ITEM_NAME("SITRUS BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Sitrus Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
    #if I_SITRUS_BERRY_HEAL >= GEN_4
        .holdEffect = HOLD_EFFECT_RESTORE_PCT_HP,
        .holdEffectParam = 25,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "KP im Kampf um 30\n"
            "Punkte auf."),
#else
            "A hold item that\n"
            "restores the user's\n"
            "HP a little."),
#endif
    #else
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "KP im Kampf um 30\n"
            "Punkte auf."),
#else
            "A hold item that\n"
            "restores 30 HP in\n"
            "battle."),
#endif
    #endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SitrusBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_SitrusBerry,
        .iconPalette = gItemIconPalette_SitrusBerry,
    },

    [ITEM_FIGY_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Giefebeere"),
        .pluralName = ITEM_PLURAL_NAME("Giefebeeren"),
#else
        .name = ITEM_NAME("FIGY BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Figy Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SPICY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_FigyBerry,
        .iconPalette = gItemIconPalette_FigyBerry,
    },

    [ITEM_WIKI_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Wikibeere"),
        .pluralName = ITEM_PLURAL_NAME("Wikibeeren"),
#else
        .name = ITEM_NAME("WIKI BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Wiki Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_DRY,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WikiBerry,
        .iconPalette = gItemIconPalette_WikiBerry,
    },

    [ITEM_MAGO_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Magobeere"),
        .pluralName = ITEM_PLURAL_NAME("Magobeeren"),
#else
        .name = ITEM_NAME("MAGO BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Mago Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SWEET,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagoBerry,
        .iconPalette = gItemIconPalette_MagoBerry,
    },

    [ITEM_AGUAV_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Gauvebeere"),
        .pluralName = ITEM_PLURAL_NAME("Gauvebeeren"),
#else
        .name = ITEM_NAME("AGUAV BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Aguav Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_BITTER,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_AguavBerry,
        .iconPalette = gItemIconPalette_AguavBerry,
    },

    [ITEM_IAPAPA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Yapabeere"),
        .pluralName = ITEM_PLURAL_NAME("Yapabeeren"),
#else
        .name = ITEM_NAME("IAPAPA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Iapapa Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CONFUSE_SOUR,
        .holdEffectParam = CONFUSE_BERRY_HEAL_FRACTION,
        .description = sFigyBerryDesc,
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_IapapaBerry,
        .iconPalette = gItemIconPalette_IapapaBerry,
    },

    [ITEM_RAZZ_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Himmihbeere"),
        .pluralName = ITEM_PLURAL_NAME("Himmihbeeren"),
#else
        .name = ITEM_NAME("RAZZ BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Razz Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Himmih wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Razz."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RazzBerry,
        .iconPalette = gItemIconPalette_RazzBerry,
    },

    [ITEM_BLUK_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Morbbeere"),
        .pluralName = ITEM_PLURAL_NAME("Morbbeeren"),
#else
        .name = ITEM_NAME("BLUK BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Bluk Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Morb wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Bluk."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BlukBerry,
        .iconPalette = gItemIconPalette_BlukBerry,
    },

    [ITEM_NANAB_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Nanabbeere"),
        .pluralName = ITEM_PLURAL_NAME("Nanabbeeren"),
#else
        .name = ITEM_NAME("NANAB BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Nanab Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Nanab wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Nanab."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NanabBerry,
        .iconPalette = gItemIconPalette_NanabBerry,
    },

    [ITEM_WEPEAR_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Nirbebeere"),
        .pluralName = ITEM_PLURAL_NAME("Nirbebeeren"),
#else
        .name = ITEM_NAME("WEPEAR BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Wepear Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Nirbe wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Wepear."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WepearBerry,
        .iconPalette = gItemIconPalette_WepearBerry,
    },

    [ITEM_PINAP_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Sananabeere"),
        .pluralName = ITEM_PLURAL_NAME("Sananabeeren"),
#else
        .name = ITEM_NAME("PINAP BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Pinap Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Sanana wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Pinap."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PinapBerry,
        .iconPalette = gItemIconPalette_PinapBerry,
    },

    [ITEM_POMEG_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Granabeere"),
        .pluralName = ITEM_PLURAL_NAME("Granabeeren"),
#else
        .name = ITEM_NAME("POMEG BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Pomeg Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht freundlicher,\n"
            "senkt\n"
            "KP-Basiswert."),
#else
            "Makes a Pokémon\n"
            "friendly but lowers\n"
            "base HP."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_PomegBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_PomegBerry,
        .iconPalette = gItemIconPalette_PomegBerry,
    },

    [ITEM_KELPSY_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Setangbeere"),
        .pluralName = ITEM_PLURAL_NAME("Setangbeeren"),
#else
        .name = ITEM_NAME("KELPSY BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Kelpsy Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht freundlicher,\n"
            "senkt\n"
            "Angr.-Basiswert."),
#else
            "Makes a Pokémon\n"
            "friendly but lowers\n"
            "base Attack."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_KelpsyBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_KelpsyBerry,
        .iconPalette = gItemIconPalette_KelpsyBerry,
    },

    [ITEM_QUALOT_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Qualotbeere"),
        .pluralName = ITEM_PLURAL_NAME("Qualotbeeren"),
#else
        .name = ITEM_NAME("QUALOT BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Qualot Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht freundlicher,\n"
            "senkt\n"
            "Vert.-Basiswert."),
#else
            "Makes a Pokémon\n"
            "friendly but lowers\n"
            "base Defense."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_QualotBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_QualotBerry,
        .iconPalette = gItemIconPalette_QualotBerry,
    },

    [ITEM_HONDEW_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Honmelbeere"),
        .pluralName = ITEM_PLURAL_NAME("Honmelbeeren"),
#else
        .name = ITEM_NAME("HONDEW BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Hondew Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht freundlicher,\n"
            "senkt Sp.\n"
            "Angr.-Basiswert."),
#else
            "Makes a Pokémon\n"
            "friendly but lowers\n"
            "base Sp. Atk."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_HondewBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_HondewBerry,
        .iconPalette = gItemIconPalette_HondewBerry,
    },

    [ITEM_GREPA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Labrusbeere"),
        .pluralName = ITEM_PLURAL_NAME("Labrusbeeren"),
#else
        .name = ITEM_NAME("GREPA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Grepa Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht freundlicher,\n"
            "senkt Sp.\n"
            "Vert.-Basiswert."),
#else
            "Makes a Pokémon\n"
            "friendly but lowers\n"
            "base Sp. Def."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_GrepaBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_GrepaBerry,
        .iconPalette = gItemIconPalette_GrepaBerry,
    },

    [ITEM_TAMATO_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Tamotbeere"),
        .pluralName = ITEM_PLURAL_NAME("Tamotbeeren"),
#else
        .name = ITEM_NAME("TAMATO BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Tamato Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Macht freundlicher,\n"
            "senkt\n"
            "Init.-Basiswert."),
#else
            "Makes a Pokémon\n"
            "friendly but lowers\n"
            "base Speed."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ReduceEV,
        .effect = gItemEffect_TamatoBerry,
        .flingPower = 10,
        .iconPic = gItemIcon_TamatoBerry,
        .iconPalette = gItemIconPalette_TamatoBerry,
    },

    [ITEM_CORNN_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Saimbeere"),
        .pluralName = ITEM_PLURAL_NAME("Saimbeeren"),
#else
        .name = ITEM_NAME("CORNN BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Cornn Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Saim wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Cornn."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CornnBerry,
        .iconPalette = gItemIconPalette_CornnBerry,
    },

    [ITEM_MAGOST_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Magostbeere"),
        .pluralName = ITEM_PLURAL_NAME("Magostbeeren"),
#else
        .name = ITEM_NAME("MAGOST BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Magost Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Magost wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Magost."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MagostBerry,
        .iconPalette = gItemIconPalette_MagostBerry,
    },

    [ITEM_RABUTA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Rabutabeere"),
        .pluralName = ITEM_PLURAL_NAME("Rabutabeeren"),
#else
        .name = ITEM_NAME("RABUTA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Rabuta Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Rabuta wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Rabuta."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RabutaBerry,
        .iconPalette = gItemIconPalette_RabutaBerry,
    },

    [ITEM_NOMEL_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Tronzibeere"),
        .pluralName = ITEM_PLURAL_NAME("Tronzibeeren"),
#else
        .name = ITEM_NAME("NOMEL BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Nomel Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Tronzi wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Nomel."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_NomelBerry,
        .iconPalette = gItemIconPalette_NomelBerry,
    },

    [ITEM_SPELON_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Kiwanbeere"),
        .pluralName = ITEM_PLURAL_NAME("Kiwanbeeren"),
#else
        .name = ITEM_NAME("SPELON BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Spelon Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Kiwan wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Spelon."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SpelonBerry,
        .iconPalette = gItemIconPalette_SpelonBerry,
    },

    [ITEM_PAMTRE_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Pallmbeere"),
        .pluralName = ITEM_PLURAL_NAME("Pallmbeeren"),
#else
        .name = ITEM_NAME("PAMTRE BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Pamtre Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Pallm wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Pamtre."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PamtreBerry,
        .iconPalette = gItemIconPalette_PamtreBerry,
    },

    [ITEM_WATMEL_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Wasmelbeere"),
        .pluralName = ITEM_PLURAL_NAME("Wasmelbeeren"),
#else
        .name = ITEM_NAME("WATMEL BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Watmel Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Wasmel wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Watmel."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WatmelBerry,
        .iconPalette = gItemIconPalette_WatmelBerry,
    },

    [ITEM_DURIN_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Durinbeere"),
        .pluralName = ITEM_PLURAL_NAME("Durinbeeren"),
#else
        .name = ITEM_NAME("DURIN BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Durin Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Durin wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Durin."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_DurinBerry,
        .iconPalette = gItemIconPalette_DurinBerry,
    },

    [ITEM_BELUE_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Myrtilbeere"),
        .pluralName = ITEM_PLURAL_NAME("Myrtilbeeren"),
#else
        .name = ITEM_NAME("BELUE BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Belue Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "Myrtil wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow Belue."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BelueBerry,
        .iconPalette = gItemIconPalette_BelueBerry,
    },

    [ITEM_CHILAN_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Latchibeere"),
        .pluralName = ITEM_PLURAL_NAME("Latchibeeren"),
#else
        .name = ITEM_NAME("CHILAN BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Chilan Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_NORMAL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schwächt eine\n"
            "Normal-Attacke."),
#else
            "A hold item that\n"
            "weakens a Normal\n"
            "move."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChilanBerry,
        .iconPalette = gItemIconPalette_ChilanBerry,
    },

    [ITEM_OCCA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Koakobeere"),
        .pluralName = ITEM_PLURAL_NAME("Koakobeeren"),
#else
        .name = ITEM_NAME("OCCA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Occa Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIRE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Feuer-Attacke."),
#else
            "A hold item that\n"
            "weakens a Fire\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_OccaBerry,
        .iconPalette = gItemIconPalette_OccaBerry,
    },

    [ITEM_PASSHO_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Foepasbeere"),
        .pluralName = ITEM_PLURAL_NAME("Foepasbeeren"),
#else
        .name = ITEM_NAME("PASSHO BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Passho Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_WATER,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Wasser-Attacke."),
#else
            "A hold item that\n"
            "weakens a Water\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PasshoBerry,
        .iconPalette = gItemIconPalette_PasshoBerry,
    },

    [ITEM_WACAN_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Kerzalbeere"),
        .pluralName = ITEM_PLURAL_NAME("Kerzalbeeren"),
#else
        .name = ITEM_NAME("WACAN BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Wacan Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ELECTRIC,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Elektro-Attacke."),
#else
            "A hold item that\n"
            "weakens a Electric\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_WacanBerry,
        .iconPalette = gItemIconPalette_WacanBerry,
    },

    [ITEM_RINDO_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Grindobeere"),
        .pluralName = ITEM_PLURAL_NAME("Grindobeeren"),
#else
        .name = ITEM_NAME("RINDO BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Rindo Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GRASS,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Pflanzen-Attacke."),
#else
            "A hold item that\n"
            "weakens a Grass\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RindoBerry,
        .iconPalette = gItemIconPalette_RindoBerry,
    },

    [ITEM_YACHE_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Kiroyabeere"),
        .pluralName = ITEM_PLURAL_NAME("Kiroyabeeren"),
#else
        .name = ITEM_NAME("YACHE BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Yache Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Eis-Attacke."),
#else
            "A hold item that\n"
            "weakens a Ice\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_YacheBerry,
        .iconPalette = gItemIconPalette_YacheBerry,
    },

    [ITEM_CHOPLE_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Rospelbeere"),
        .pluralName = ITEM_PLURAL_NAME("Rospelbeeren"),
#else
        .name = ITEM_NAME("CHOPLE BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Chople Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FIGHTING,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Kampf-Attacke."),
#else
            "A hold item that\n"
            "weakens a Fighting\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChopleBerry,
        .iconPalette = gItemIconPalette_ChopleBerry,
    },

    [ITEM_KEBIA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Grarzbeere"),
        .pluralName = ITEM_PLURAL_NAME("Grarzbeeren"),
#else
        .name = ITEM_NAME("KEBIA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Kebia Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_POISON,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Gift-Attacke."),
#else
            "A hold item that\n"
            "weakens a Poison\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KebiaBerry,
        .iconPalette = gItemIconPalette_KebiaBerry,
    },

    [ITEM_SHUCA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Schukebeere"),
        .pluralName = ITEM_PLURAL_NAME("Schukebeeren"),
#else
        .name = ITEM_NAME("SHUCA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Shuca Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GROUND,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Boden-Attacke."),
#else
            "A hold item that\n"
            "weakens a Ground\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ShucaBerry,
        .iconPalette = gItemIconPalette_ShucaBerry,
    },

    [ITEM_COBA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Kobabeere"),
        .pluralName = ITEM_PLURAL_NAME("Kobabeeren"),
#else
        .name = ITEM_NAME("COBA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Coba Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FLYING,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Flug-Attacke."),
#else
            "A hold item that\n"
            "weakens a Flying\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CobaBerry,
        .iconPalette = gItemIconPalette_CobaBerry,
    },

    [ITEM_PAYAPA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Pyapabeere"),
        .pluralName = ITEM_PLURAL_NAME("Pyapabeeren"),
#else
        .name = ITEM_NAME("PAYAPA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Payapa Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_PSYCHIC,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Psycho-Attacke."),
#else
            "A hold item that\n"
            "weakens a Psychic\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PayapaBerry,
        .iconPalette = gItemIconPalette_PayapaBerry,
    },

    [ITEM_TANGA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Tanigabeere"),
        .pluralName = ITEM_PLURAL_NAME("Tanigabeeren"),
#else
        .name = ITEM_NAME("TANGA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Tanga Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_BUG,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Käfer-Attacke."),
#else
            "A hold item that\n"
            "weakens a Bug\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_TangaBerry,
        .iconPalette = gItemIconPalette_TangaBerry,
    },

    [ITEM_CHARTI_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Chiaribeere"),
        .pluralName = ITEM_PLURAL_NAME("Chiaribeeren"),
#else
        .name = ITEM_NAME("CHARTI BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Charti Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_ROCK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Gestein-Attacke."),
#else
            "A hold item that\n"
            "weakens a Rock\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ChartiBerry,
        .iconPalette = gItemIconPalette_ChartiBerry,
    },

    [ITEM_KASIB_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Zitarzbeere"),
        .pluralName = ITEM_PLURAL_NAME("Zitarzbeeren"),
#else
        .name = ITEM_NAME("KASIB BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Kasib Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_GHOST,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Geist-Attacke."),
#else
            "A hold item that\n"
            "weakens a Ghost\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KasibBerry,
        .iconPalette = gItemIconPalette_KasibBerry,
    },

    [ITEM_HABAN_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Terirobeere"),
        .pluralName = ITEM_PLURAL_NAME("Terirobeeren"),
#else
        .name = ITEM_NAME("HABAN BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Haban Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DRAGON,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Drachen-Attacke."),
#else
            "A hold item that\n"
            "weakens a Dragon\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_HabanBerry,
        .iconPalette = gItemIconPalette_HabanBerry,
    },

    [ITEM_COLBUR_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Burleobeere"),
        .pluralName = ITEM_PLURAL_NAME("Burleobeeren"),
#else
        .name = ITEM_NAME("COLBUR BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Colbur Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_DARK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Unlicht-Attacke."),
#else
            "A hold item that\n"
            "weakens a Dark\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ColburBerry,
        .iconPalette = gItemIconPalette_ColburBerry,
    },

    [ITEM_BABIRI_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Babiribeere"),
        .pluralName = ITEM_PLURAL_NAME("Babiribeeren"),
#else
        .name = ITEM_NAME("BABIRI BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Babiri Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_STEEL,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Stahl-Attacke."),
#else
            "A hold item that\n"
            "weakens a Steel\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BabiriBerry,
        .iconPalette = gItemIconPalette_BabiriBerry,
    },

    [ITEM_ROSELI_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Hibisbeere"),
        .pluralName = ITEM_PLURAL_NAME("Hibisbeeren"),
#else
        .name = ITEM_NAME("ROSELI BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Roseli Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RESIST_BERRY,
        .holdEffectParam = TYPE_FAIRY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) mil-\n"
            "dert sehr effektive\n"
            "Fee-Attacke."),
#else
            "A hold item that\n"
            "weakens a Fairy\n"
            "move if weak to it."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RoseliBerry,
        .iconPalette = gItemIconPalette_RoseliBerry,
    },

    [ITEM_LIECHI_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Lydzibeere"),
        .pluralName = ITEM_PLURAL_NAME("Lydzibeeren"),
#else
        .name = ITEM_NAME("LIECHI BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Liechi Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Angr.-Wert in einer\n"
            "Notlage."),
#else
            "A hold item that\n"
            "raises Attack in\n"
            "a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LiechiBerry,
        .iconPalette = gItemIconPalette_LiechiBerry,
    },

    [ITEM_GANLON_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Linganbeere"),
        .pluralName = ITEM_PLURAL_NAME("Linganbeeren"),
#else
        .name = ITEM_NAME("GANLON BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Ganlon Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Vert.-Wert in einer\n"
            "Notlage."),
#else
            "A hold item that\n"
            "raises Defense in\n"
            "a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_GanlonBerry,
        .iconPalette = gItemIconPalette_GanlonBerry,
    },

    [ITEM_SALAC_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Salkabeere"),
        .pluralName = ITEM_PLURAL_NAME("Salkabeeren"),
#else
        .name = ITEM_NAME("SALAC BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Salac Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SPEED_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Init.-Wert in einer\n"
            "Notlage."),
#else
            "A hold item that\n"
            "raises Speed in\n"
            "a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_SalacBerry,
        .iconPalette = gItemIconPalette_SalacBerry,
    },

    [ITEM_PETAYA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Tahaybeere"),
        .pluralName = ITEM_PLURAL_NAME("Tahaybeeren"),
#else
        .name = ITEM_NAME("PETAYA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Petaya Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_ATTACK_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Angr.-Wert in\n"
            "einer Notlage."),
#else
            "A hold item that\n"
            "raises Sp. Atk in\n"
            "a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_PetayaBerry,
        .iconPalette = gItemIconPalette_PetayaBerry,
    },

    [ITEM_APICOT_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Apikobeere"),
        .pluralName = ITEM_PLURAL_NAME("Apikobeeren"),
#else
        .name = ITEM_NAME("APICOT BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Apicot Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_SP_DEFENSE_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert.-Wert in\n"
            "einer Notlage."),
#else
            "A hold item that\n"
            "raises Sp. Def in\n"
            "a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_ApicotBerry,
        .iconPalette = gItemIconPalette_ApicotBerry,
    },

    [ITEM_LANSAT_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Lansatbeere"),
        .pluralName = ITEM_PLURAL_NAME("Lansatbeeren"),
#else
        .name = ITEM_NAME("LANSAT BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Lansat Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CRITICAL_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Volltrefferquote in\n"
            "einer Notlage."),
#else
            "A hold item that\n"
            "ups the critical-\n"
            "hit rate in a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_LansatBerry,
        .iconPalette = gItemIconPalette_LansatBerry,
    },

    [ITEM_STARF_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Krambobeere"),
        .pluralName = ITEM_PLURAL_NAME("Krambobeeren"),
#else
        .name = ITEM_NAME("STARF BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Starf Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_RANDOM_STAT_UP,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "einen Statuswert in\n"
            "einer Notlage."),
#else
            "A hold item that\n"
            "sharply boosts a\n"
            "stat in a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_StarfBerry,
        .iconPalette = gItemIconPalette_StarfBerry,
    },

    [ITEM_ENIGMA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Enigmabeere"),
        .pluralName = ITEM_PLURAL_NAME("Enigmabeeren"),
#else
        .name = ITEM_NAME("ENIGMA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Enigma Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ENIGMA_BERRY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) heilt\n"
            "bei sehr effektiver\n"
            "Attacke."),
#else
            "A hold item that\n"
            "heals from super\n"
            "effective moves."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

    [ITEM_MICLE_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Wunfrubeere"),
        .pluralName = ITEM_PLURAL_NAME("Wunfrubeeren"),
#else
        .name = ITEM_NAME("MICLE BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Micle Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MICLE_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Genauigkeit in\n"
            "einer Notlage."),
#else
            "When held, it ups\n"
            "the Accuracy of a\n"
            "move in a pinch."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MicleBerry,
        .iconPalette = gItemIconPalette_MicleBerry,
    },

    [ITEM_CUSTAP_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Eipfelbeere"),
        .pluralName = ITEM_PLURAL_NAME("Eipfelbeeren"),
#else
        .name = ITEM_NAME("CUSTAP BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Custap Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_CUSTAP_BERRY,
        .holdEffectParam = 4,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "erlaubt Erstschlag\n"
            "in Notlage."),
#else
            "It allows a Pokémon\n"
            "in a pinch to move\n"
            "first just once."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_CustapBerry,
        .iconPalette = gItemIconPalette_CustapBerry,
    },

    [ITEM_JABOCA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Jabocabeere"),
        .pluralName = ITEM_PLURAL_NAME("Jabocabeeren"),
#else
        .name = ITEM_NAME("JABOCA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Jaboca Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_JABOCA_BERRY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schadet dem Gegner\n"
            "bei phys. Attacke."),
#else
            "If hit by a physical\n"
            "move, it will hurt\n"
            "the attacker a bit."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_JabocaBerry,
        .iconPalette = gItemIconPalette_JabocaBerry,
    },

    [ITEM_ROWAP_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Roselbeere"),
        .pluralName = ITEM_PLURAL_NAME("Roselbeeren"),
#else
        .name = ITEM_NAME("ROWAP BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Rowap Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_ROWAP_BERRY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) scha-\n"
            "det dem Gegner bei\n"
            "Spezial-Attacke."),
#else
            "If hit by a special\n"
            "move, it will hurt\n"
            "the attacker a bit."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_RowapBerry,
        .iconPalette = gItemIconPalette_RowapBerry,
    },

    [ITEM_KEE_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Akibeere"),
        .pluralName = ITEM_PLURAL_NAME("Akibeeren"),
#else
        .name = ITEM_NAME("KEE BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Kee Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_KEE_BERRY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Vert. bei phys.\n"
            "Attacke."),
#else
            "If hit by a physical\n"
            "move, it raises the\n"
            "Defense a bit."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_KeeBerry,
        .iconPalette = gItemIconPalette_KeeBerry,
    },

    [ITEM_MARANGA_BERRY] =
    {
#if GERMAN
        .name = ITEM_NAME("Tarabeere"),
        .pluralName = ITEM_PLURAL_NAME("Tarabeeren"),
#else
        .name = ITEM_NAME("MARANGA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Maranga Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .holdEffect = HOLD_EFFECT_MARANGA_BERRY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) hebt\n"
            "Sp. Vert. bei\n"
            "Spezial-Attacke."),
#else
            "If hit by a special\n"
            "move, it raises the\n"
            "Sp. Def. a bit."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_MarangaBerry,
        .iconPalette = gItemIconPalette_MarangaBerry,
    },

    [ITEM_ENIGMA_BERRY_E_READER] =
    {
#if GERMAN
        .name = ITEM_NAME("Enigmabeere"),
        .pluralName = ITEM_PLURAL_NAME("Enigmabeeren"),
#else
        .name = ITEM_NAME("ENIGMA BERRY"),
        .pluralName = ITEM_PLURAL_NAME("Enigma Berries"),
#endif
        .price = (I_BERRY_PRICE >= GEN_8) ? 80 : 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Säe {POKEBLOCK}-Zutat\n"
            "in Lehmboden, damit\n"
            "ein Rätsel wächst."),
#else
            "{POKEBLOCK} ingredient.\n"
            "Plant in loamy soil\n"
            "to grow a mystery."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .fieldUseFunc = ItemUseOutOfBattle_EnigmaBerry,
        .battleUsage = EFFECT_ITEM_ENIGMA_BERRY_EREADER,
        .flingPower = 10,
        .iconPic = gItemIcon_EnigmaBerry,
        .iconPalette = gItemIconPalette_EnigmaBerry,
    },

// TMs/HMs. They don't have a set flingPower, as that's handled by GetFlingPowerFromItemId.

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = ITEM_NAME("TM01"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stark. Pokémon er-\n"
            "schrickt vielleicht\n"
            "bei gegn. Attacke."),
#else
            "Powerful, but makes\n"
            "the user flinch if\n"
            "hit by the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = ITEM_NAME("TM02"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gegner wird mit\n"
            "langen, scharfen\n"
            "Krallen attackiert."),
#else
            "Hooks and slashes\n"
            "the foe with long,\n"
            "sharp claws."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = ITEM_NAME("TM03"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Ultraschall-\n"
            "welle, die den Geg-\n"
            "ner verwirren kann."),
#else
            "Generates an\n"
            "ultrasonic wave\n"
            "that may confuse."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = ITEM_NAME("TM04"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstärkt Sp. Angr.\n"
            "und Sp. Vert. durch\n"
            "Konzentration."),
#else
            "Raises Sp. Atk and\n"
            "Sp. Def by focusing\n"
            "the mind."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROAR] =
    {
        .name = ITEM_NAME("TM05"),
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brüller schlägt\n"
            "Gegner in die Flucht\n"
            "und beendet Kampf."),
#else
            "A savage roar that\n"
            "makes the foe flee \n"
            "to end the battle."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = ITEM_NAME("TM06"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Vergiftet den Geg-\n"
            "ner und schadet ihm\n"
            "zunehmend."),
#else
            "Poisons the foe\n"
            "with a toxin that\n"
            "gradually worsens."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HAIL] =
    {
        .name = ITEM_NAME("TM07"),
        .price = 3000,
    #if B_PREFERRED_ICE_WEATHER == B_ICE_WEATHER_SNOW
        .description = COMPOUND_STRING(
#if GERMAN
            "Hagelsturm schadet\n"
            "allen Pokémon außer\n"
            "denen des Typs Eis."),
#else
            "Raises the Defense\n"
            "of Ice type {PKMN}\n"
            "for 5 turns."),
#endif
    #else
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt Hagelsturm,\n"
            "der allen außer Eis\n"
            "schadet."),
#else
            "Creates a hailstorm\n"
            "that damages all\n"
            "types except Ice."),
#endif
    #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = ITEM_NAME("TM08"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt den Körper.\n"
            "So steigen Angr.\n"
            "und Vert."),
#else
            "Bulks up the body\n"
            "to boost both\n"
            "Attack & Defense."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = ITEM_NAME("TM09"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Beschießt den\n"
            "Gegner mit 2 bis 5\n"
            "Samen auf einmal."),
#else
            "Shoots 2 to 5 seeds\n"
            "in a row to strike\n"
            "the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = ITEM_NAME("TM10"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Stärke dieser\n"
            "Attacke hängt vom\n"
            "jew. Pokémon ab."),
#else
            "The attack power\n"
            "varies among\n"
            "different Pokémon."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = ITEM_NAME("TM11"),
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstärkt\n"
            "Feuer-Attacken\n"
            "über 5 Runden."),
#else
            "Raises the power of\n"
            "Fire-type moves\n"
            "for 5 turns."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = ITEM_NAME("TM12"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Reizt den Gegner,\n"
            "sodass er nur\n"
            "Angriffe einsetzt."),
#else
            "Enrages the foe so\n"
            "it can only use\n"
            "attack moves."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = ITEM_NAME("TM13"),
        .price = 3000,
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Feuert eisigen\n"
            "Strahl, Chance\n"
            "auf Frostbrand."),
#else
            "inflict frostbite."),
#endif
        #else
#if GERMAN
            "Feuert eisigen\n"
            "Strahl, Chance\n"
            "auf einfrieren."),
#else
            "freeze the foe."),
#endif
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = ITEM_NAME("TM14"),
        .price = 10000,
        .description = COMPOUND_STRING(
        #if B_USE_FROSTBITE == TRUE
#if GERMAN
            "Schnee- und Wind\n"
            "Attacke. Chance\n"
            "auf Frostbrand."),
#else
            "A snow-and-wind\n"
            "attack that may\n"
            "inflict frostbite."),
#endif
        #else
#if GERMAN
            "Schnee- und Wind\n"
            "Attacke. Chance\n"
            "auf einfrieren."),
#else
            "A brutal snow-and-\n"
            "wind attack that\n"
            "may freeze the foe."),
#endif
        #endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = ITEM_NAME("TM15"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stark, muss sich in\n"
            "der nächsten Runde\n"
            "aufladen."),
#else
            "Powerful, but needs\n"
            "recharging the\n"
            "next turn."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = ITEM_NAME("TM16"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wand aus Licht, die\n"
            "Schaden des Sp.\n"
            "Angr. verringert."),
#else
            "Creates a wall of\n"
            "light that lowers\n"
            "Sp. Atk damage."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = ITEM_NAME("TM17"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schützt, könnte\n"
            "aber bei häufigem\n"
            "Einsatz versagen."),
#else
            "Negates all damage,\n"
            "but may fail if used\n"
            "in succession."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = ITEM_NAME("TM18"),
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verstärkt\n"
            "Wasser-Attacken\n"
            "über 5 Runden."),
#else
            "Raises the power of\n"
            "Water-type moves\n"
            "for 5 turns."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = ITEM_NAME("TM19"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stiehlt dem Gegner\n"
            "die Hälfte des\n"
            "Schadens als KP."),
#else
            "Recovers half the\n"
            "HP of the damage \n"
            "this move inflicts."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = ITEM_NAME("TM20"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mystische Macht,\n"
            "verhindert Status-\n"
            "veränderungen."),
#else
            "Prevents status\n"
            "abnormality with a\n"
            "mystical power."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = ITEM_NAME("TM21"),
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Je unbeliebter der\n"
            "Trainer, desto grö-\n"
            "ßer die Wirkung."),
#else
            "The less the user\n"
            "likes you, the more\n"
            "powerful this move."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = ITEM_NAME("TM22"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erst wird Sonnen-\n"
            "licht absorbiert,\n"
            "dann erfolgt Angr."),
#else
            "Absorbs sunlight in\n"
            "the 1st turn, then\n"
            "attacks next turn."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = ITEM_NAME("TM23"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlag mit harter\n"
            "Rute. Kann gleichz.\n"
            "Vert.-Wert senken."),
#else
            "Slams the foe with\n"
            "a hard tail. It may\n"
            "lower Defense."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = ITEM_NAME("TM24"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Starke Elektro-\n"
            "Attacke. Kann\n"
            "Paralyse bewirken."),
#else
            "A powerful electric\n"
            "attack that may\n"
            "cause paralysis."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = ITEM_NAME("TM25"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mächtiger Donner-\n"
            "schlag, der Paraly-\n"
            "se bewirken kann."),
#else
            "Strikes the foe\n"
            "with a thunderbolt.\n"
            "It may paralyze."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = ITEM_NAME("TM26"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Starkes Beben. Hat\n"
            "keinen Einfluss auf\n"
            "fliegende Gegner."),
#else
            "Causes a quake\n"
            "that has no effect\n"
            "on flying foes."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_RETURN] =
    {
        .name = ITEM_NAME("TM27"),
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Je beliebter der\n"
            "Trainer, desto grö-\n"
            "ßer die Wirkung."),
#else
            "The more the user\n"
            "likes you, the more\n"
            "powerful this move."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DIG] =
    {
        .name = ITEM_NAME("TM28"),
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erst gräbt sich An-\n"
            "greifer ein, dann\n"
            "erfolgt Angriff."),
#else
            "Digs underground\n"
            "the 1st turn, then\n"
            "strikes next turn."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = ITEM_NAME("TM29"),
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Starke Psycho-At-\n"
            "tacke, die Sp. Vert.\n"
            "senken kann."),
#else
            "A powerful psychic\n"
            "attack that may\n"
            "lower Sp. Def."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = ITEM_NAME("TM30"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Dunkler Klumpen,\n"
            "der Sp. Vert. senken\n"
            "kann."),
#else
            "Hurls a dark lump\n"
            "at the foe. It may\n"
            "lower Sp. Def."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = ITEM_NAME("TM31"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zerstört Barrieren\n"
            "wie Schutzschild,\n"
            "fügt Schaden zu."),
#else
            "Destroys barriers\n"
            "like Light Screen\n"
            "and causes damage."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = ITEM_NAME("TM32"),
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Virtueller Doppel-\n"
            "gänger. Erhöht den\n"
            "Flucht-Wert."),
#else
            "Creates illusory\n"
            "copies to enhance\n"
            "elusiveness."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = ITEM_NAME("TM33"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wand aus Licht, die\n"
            "physische Atta-\n"
            "cken schwächt."),
#else
            "Creates a wall of\n"
            "light that weakens\n"
            "physical attacks."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = ITEM_NAME("TM34"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fügt Gegner einen\n"
            "Stromschlag zu, der\n"
            "nie verfehlt."),
#else
            "Zaps the foe with a\n"
            "jolt of electricity\n"
            "that never misses."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = ITEM_NAME("TM35"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Entfesselt Feuer-\n"
            "strahl, der Gegner\n"
            "verbrennen kann."),
#else
            "Looses a stream of\n"
            "fire that may burn\n"
            "the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = ITEM_NAME("TM36"),
        .price = 1000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bewirft Gegner mit\n"
            "Matsch, der ihn\n"
            "vergiften kann."),
#else
            "Hurls sludge at the\n"
            "foe. It may poison\n"
            "the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = ITEM_NAME("TM37"),
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sandsturm trifft\n"
            "etliche Runden lang\n"
            "die Kämpfenden."),
#else
            "Causes a sandstorm\n"
            "that hits the foe\n"
            "over several turns."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = ITEM_NAME("TM38"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kraftvolle Feuer-\n"
            "Attacke, die Gegner\n"
            "verbrennen kann."),
#else
            "A powerful fire\n"
            "attack that may\n"
            "burn the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = ITEM_NAME("TM39"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Begräbt Gegner mit\n"
            "Steinen. Kann\n"
            "Init.-Wert senken."),
#else
            "Stops the foe from\n"
            "moving with rocks.\n"
            "May lower Speed."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = ITEM_NAME("TM40"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine schnelle\n"
            "Attacke, die\n"
            "unausweichlich ist."),
#else
            "An extremely fast\n"
            "attack that can't\n"
            "be avoided."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = ITEM_NAME("TM41"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Blockiert gerade\n"
            "verwendete Atta-\n"
            "cke des Gegners."),
#else
            "Prevents the foe\n"
            "from using the same\n"
            "move in a row."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_FACADE] =
    {
        .name = ITEM_NAME("TM42"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stärkt Angr.-Wert\n"
            "bei Gift, Brand oder\n"
            "Paralyse."),
#else
            "Raises Attack when\n"
            "poisoned, burned,\n"
            "or paralyzed."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = ITEM_NAME("TM43"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Umgebung\n"
            "beeinflusst die Art\n"
            "der Attacke."),
#else
            "Adds an effect to\n"
            "attack depending\n"
            "on the location."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_REST] =
    {
        .name = ITEM_NAME("TM44"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Pokémon schläft 2\n"
            "Runden. Füllt KP und\n"
            "heilt Status."),
#else
            "The user sleeps for\n"
            "2 turns to restore\n"
            "health and status."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = ITEM_NAME("TM45"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erschwert Angriff\n"
            "auf Gegner des an-\n"
            "deren Geschlechts."),
#else
            "Makes it tough to\n"
            "attack a foe of the\n"
            "opposite gender."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_THIEF] =
    {
        .name = ITEM_NAME("TM46"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Beim Angriff wird\n"
            "Item des Gegners\n"
            "evtl. gestohlen."),
#else
            "While attacking,\n"
            "it may steal the\n"
            "foe's held item."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = ITEM_NAME("TM47"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Den Gegner treffen\n"
            "stählerne\n"
            "Flügelschläge."),
#else
            "Spreads hard-\n"
            "edged wings and\n"
            "slams into the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = ITEM_NAME("TM48"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Austausch der\n"
            "Fähigkeiten bei der\n"
            "nächsten Attacke."),
#else
            "Switches abilities\n"
            "with the foe on the\n"
            "turn this is used."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = ITEM_NAME("TM49"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stiehlt die Effekte\n"
            "der gegnerischen\n"
            "Attacke."),
#else
            "Steals the effects\n"
            "of the move the foe\n"
            "is trying to use."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = ITEM_NAME("TM50"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Höchste Kraft, aber\n"
            "senkt Sp. Angr.\n"
            "enorm."),
#else
            "Enables full-power\n"
            "attack, but sharply\n"
            "lowers Sp. Atk."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM51] = // Roost
    {
        .name = ITEM_NAME("TM51"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Füllt die KP des\n"
            "Anwenders um die\n"
            "Hälfte auf."),
#else
            "Restores the user's\n"
            "HP by half of its\n"
            "max HP."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM52] = // Focus Blast
    {
        .name = ITEM_NAME("TM52"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Volle Kraft. Kann\n"
            "Sp. Vert. des\n"
            "Gegners senken."),
#else
            "Attacks at full\n"
            "power. May lower\n"
            "the foe's Sp. Def."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM53] = // Energy Ball
    {
        .name = ITEM_NAME("TM53"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit\n"
            "Naturkraft. Kann\n"
            "Sp. Vert. senken."),
#else
            "Draws power from\n"
            "nature to attack.\n"
            "May lower Sp. Def."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM54] = // False Swipe
    {
        .name = ITEM_NAME("TM54"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke, die dem\n"
            "Gegner mindestens\n"
            "1 KP lässt."),
#else
            "Attack that leaves\n"
            "the foe with at\n"
            "least 1 HP."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM55] = // Brine
    {
        .name = ITEM_NAME("TM55"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Doppelter Schaden\n"
            "bei Gegnern mit\n"
            "halben KP."),
#else
            "Does double damage\n"
            "to foes with half\n"
            "HP or less."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM56] = // Fling
    {
        .name = ITEM_NAME("TM56"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Wirkung hängt\n"
            "vom getragenen\n"
            "Item ab."),
#else
            "The effectiveness\n"
            "varies with the\n"
            "held item."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM57] = // Charge Beam
    {
        .name = ITEM_NAME("TM57"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Elektrostrahl. Kann\n"
            "Sp. Angr. erhöhen."),
#else
            "Fires a beam of\n"
            "electricity. May\n"
            "raise Sp. Atk."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM58] = // Endure
    {
        .name = ITEM_NAME("TM58"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Übersteht 1 Runde\n"
            "jede Attacke mit\n"
            "mind. 1 KP."),
#else
            "Endures any attack\n"
            "for 1 turn, leaving\n"
            "at least 1 HP."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM59] = // Dragon Pulse
    {
        .name = ITEM_NAME("TM59"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt eine\n"
            "Schockwelle, die\n"
            "dem Gegner schadet."),
#else
            "Generates a shock\n"
            "wave to damage\n"
            "the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM60] = // Drain Punch
    {
        .name = ITEM_NAME("TM60"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke, die den\n"
            "halben Schaden als\n"
            "KP absorbiert."),
#else
            "Attack that\n"
            "absorbs half the\n"
            "damage inflicted."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM61] = // Will-O-Wisp
    {
        .name = ITEM_NAME("TM61"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fügt dem Gegner mit\n"
            "heißem Feuer\n"
            "Verbrennung zu."),
#else
            "Inflicts a burn on\n"
            "the foe with\n"
            "intense fire."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM62] = // Silver Wind
    {
        .name = ITEM_NAME("TM62"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Puder-Attacke, die\n"
            "alle Statuswerte\n"
            "heben kann."),
#else
            "A powdery attack\n"
            "that may raise\n"
            "all abilities."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM63] = // Embargo
    {
        .name = ITEM_NAME("TM63"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hindert den Gegner\n"
            "am Einsatz von\n"
            "Items."),
#else
            "Prevents the foe\n"
            "from using any\n"
            "items."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM64] = // Explosion
    {
        .name = ITEM_NAME("TM64"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fügt hohen Schaden\n"
            "zu, der Anwender\n"
            "wird besiegt."),
#else
            "Inflicts severe\n"
            "damage but makes\n"
            "the user faint."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM65] = // Shadow Claw
    {
        .name = ITEM_NAME("TM65"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlag mit Schat-\n"
            "tenklaue. Hohe\n"
            "Volltrefferquote."),
#else
            "Strikes with a\n"
            "shadow claw. High\n"
            "critical-hit ratio."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM66] = // Payback
    {
        .name = ITEM_NAME("TM66"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke, die\n"
            "stärker wird, wenn\n"
            "man zuletzt agiert."),
#else
            "Attack that gains\n"
            "power if the user\n"
            "moves last."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM67] = // Recycle
    {
        .name = ITEM_NAME("TM67"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwertet ein\n"
            "gebrauchtes Item\n"
            "ein zweites Mal."),
#else
            "Recycles a used item\n"
            "for one more use."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM68] = // Giga Impact
    {
        .name = ITEM_NAME("TM68"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stark, aber der\n"
            "Anwender bleibt 1\n"
            "Runde starr."),
#else
            "Powerful, but leaves\n"
            "the user immobile\n"
            "the next turn."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM69] = // Rock Polish
    {
        .name = ITEM_NAME("TM69"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Poliert den Körper\n"
            "und hebt so Init.\n"
            "stark."),
#else
            "Polishes the body\n"
            "to sharply raise\n"
            "Speed."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

#if IS_HNS
    [ITEM_TM70] = // Rock Climb
    {
        .name = ITEM_NAME("TM70"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wuchtiger Angriff,\n"
            "der Gegner\n"
            "verwirren kann."),
#else
            "An all-out charge\n"
            "attack that may\n"
            "confuse the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#else
    [ITEM_TM70] = // Flash
    {
        .name = ITEM_NAME("TM70"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein gleißender\n"
            "Lichtstrahl, der\n"
            "Genau. senken kann."),
#else
            "Looses a powerful\n"
            "blast of light that\n"
            "cuts accuracy."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#endif

    [ITEM_TM71] = // Stone Edge
    {
        .name = ITEM_NAME("TM71"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sticht mit Steinen\n"
            "zu. Hohe\n"
            "Volltrefferquote."),
#else
            "Stabs the foe with\n"
            "stones. High\n"
            "critical-hit ratio."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM72] = // Avalanche
    {
        .name = ITEM_NAME("TM72"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Attacke agiert\n"
            "zuletzt, wird bei\n"
            "Treffer stärker."),
#else
            "Attack that moves\n"
            "last and gains\n"
            "power if hit."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM73] = // Thunder Wave
    {
        .name = ITEM_NAME("TM73"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwacher\n"
            "Stromstoß, der den\n"
            "Gegner paralysiert."),
#else
            "A weak jolt of\n"
            "electricity that\n"
            "paralyzes the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM74] = // Gyro Ball
    {
        .name = ITEM_NAME("TM74"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schneller Wirbel,\n"
            "der schnelle Gegner\n"
            "härter trifft."),
#else
            "A rapid spin that\n"
            "does more damage\n"
            "to faster foes."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM75] = // Swords Dance
    {
        .name = ITEM_NAME("TM75"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Kampftanz, der\n"
            "den Angr.-Wert\n"
            "stark hebt."),
#else
            "A fighting dance\n"
            "that sharply raises\n"
            "Attack."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM76] = // Stealth Rock
    {
        .name = ITEM_NAME("TM76"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Legt Steine aus, die\n"
            "wechselnde Gegner\n"
            "verletzen."),
#else
            "Floating stones\n"
            "that hurt a foe\n"
            "switching in."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM77] = // Psych Up
    {
        .name = ITEM_NAME("TM77"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kopiert die\n"
            "Statusänderungen\n"
            "des Gegners."),
#else
            "Copies the foe's\n"
            "stat changes and\n"
            "gives to the user."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM78] = // Captivate
    {
        .name = ITEM_NAME("TM78"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Senkt Sp. Angr. des\n"
            "anderen\n"
            "Geschlechts stark."),
#else
            "Makes the opposite\n"
            "gender sharply cut\n"
            "its Sp. Atk."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM79] = // Dark Pulse
    {
        .name = ITEM_NAME("TM79"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Angriff mit übler\n"
            "Aura. Kann zurück-\n"
            "schrecken lassen."),
#else
            "Attacks with a\n"
            "horrible aura. May\n"
            "cause flinching."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM80] = // Rock Slide
    {
        .name = ITEM_NAME("TM80"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Wirft große Felsen.\n"
            "Gegner kann\n"
            "zurückschrecken."),
#else
            "Large boulders are\n"
            "hurled. May cause\n"
            "flinching."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM81] = // X-Scissor
    {
        .name = ITEM_NAME("TM81"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlitzt den Gegner\n"
            "mit gekreuzten\n"
            "Klingen."),
#else
            "Slashes the foe with\n"
            "crossed scythes,\n"
            "claws, etc."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM82] = // Sleep Talk
    {
        .name = ITEM_NAME("TM82"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Setzt im Schlaf\n"
            "zufällig eine\n"
            "Attacke ein."),
#else
            "Uses an available\n"
            "move randomly while\n"
            "asleep."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM83] = // Natural Gift
    {
        .name = ITEM_NAME("TM83"),
        .price = 10000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die Wirkung hängt\n"
            "von der getragenen\n"
            "Beere ab."),
#else
            "The effectiveness\n"
            "varies with the\n"
            "held Berry."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM84] = // Poison Jab
    {
        .name = ITEM_NAME("TM84"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Stich-Attacke, die\n"
            "den Gegner\n"
            "vergiften kann."),
#else
            "A stabbing attack\n"
            "that may poison\n"
            "the foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM85] = // Dream Eater
    {
        .name = ITEM_NAME("TM85"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Absorbiert Schaden\n"
            "an schlafenden\n"
            "Gegnern."),
#else
            "Takes one half the\n"
            "damage inflicted on\n"
            "a sleeping foe."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM86] = // Grass Knot
    {
        .name = ITEM_NAME("TM86"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fessel-Attacke, die\n"
            "schweren Gegnern\n"
            "mehr schadet."),
#else
            "A snare attack that\n"
            "does more damage to\n"
            "heavier foes."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM87] = // Swagger
    {
        .name = ITEM_NAME("TM87"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verwirrt den\n"
            "Gegner, hebt aber\n"
            "seinen Angr. stark."),
#else
            "Confuses the foe,\n"
            "but also sharply\n"
            "raises its Attack."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM88] = // Pluck
    {
        .name = ITEM_NAME("TM88"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Frisst die Beere\n"
            "des Gegners und\n"
            "nutzt ihre Wirkung."),
#else
            "Eats the foe's held\n"
            "Berry, gaining its\n"
            "effect."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM89] = // U-turn
    {
        .name = ITEM_NAME("TM89"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fügt Schaden zu,\n"
            "dann wechselt der\n"
            "Anwender aus."),
#else
            "Does damage then\n"
            "switches out the\n"
            "user."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM90] = // Substitute
    {
        .name = ITEM_NAME("TM90"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt einen Dop-\n"
            "pelgänger aus 1/4\n"
            "der maximalen KP."),
#else
            "Creates a decoy\n"
            "using 1/4 of the\n"
            "user's maximum HP."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM91] = // Flash Cannon
    {
        .name = ITEM_NAME("TM91"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Lichtstoß, der Sp.\n"
            "Vert. senken kann."),
#else
            "Releases a blast of\n"
            "light that may lower\n"
            "Sp. Def."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM92] = // Trick Room
    {
        .name = ITEM_NAME("TM92"),
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Langsame Pokémon\n"
            "agieren 5 Runden\n"
            "lang zuerst."),
#else
            "Slower Pokémon get\n"
            "to move first for\n"
            "5 turns."),
#endif
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM93] =
    {
        .name = ITEM_NAME("TM93"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM94] =
    {
        .name = ITEM_NAME("TM94"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM95] =
    {
        .name = ITEM_NAME("TM95"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM96] =
    {
        .name = ITEM_NAME("TM96"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM97] =
    {
        .name = ITEM_NAME("TM97"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM98] =
    {
        .name = ITEM_NAME("TM98"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM99] =
    {
        .name = ITEM_NAME("TM99"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_TM100] =
    {
        .name = ITEM_NAME("TM100"),
        .price = 3000,
        .description = sQuestionMarksDesc, // Todo
        .importance = I_REUSABLE_TMS,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_CUT] =
    {
#if GERMAN
        .name = ITEM_NAME("VM01"),
#else
        .name = ITEM_NAME("HM01"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gegner wird mit\n"
            "klingenscharfen\n"
            "Krallen attackiert."),
#else
            "Attacks the foe\n"
            "with sharp blades\n"
            "or claws."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLY] =
    {
#if GERMAN
        .name = ITEM_NAME("VM02"),
#else
        .name = ITEM_NAME("HM02"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Pokémon fliegt\n"
            "hoch, dann erfolgt\n"
            "Luftangriff."),
#else
            "Flies up on the\n"
            "first turn, then\n"
            "attacks next turn."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_SURF] =
    {
#if GERMAN
        .name = ITEM_NAME("VM03"),
#else
        .name = ITEM_NAME("HM03"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine riesige Flut-\n"
            "welle ergießt sich\n"
            "über den Gegner."),
#else
            "Creates a huge\n"
            "wave, then crashes\n"
            "it down on the foe."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_STRENGTH] =
    {
#if GERMAN
        .name = ITEM_NAME("VM04"),
#else
        .name = ITEM_NAME("HM04"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Den Gegner trifft\n"
            "ein energiegelade-\n"
            "ner Kraftschlag."),
#else
            "Builds enormous\n"
            "power, then slams\n"
            "the foe."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_FLASH] =
    {
#if GERMAN
        .name = ITEM_NAME("VM05"),
#else
        .name = ITEM_NAME("HM05"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein gleißender\n"
            "Lichtstrahl, der\n"
            "Genau. senken kann."),
#else
            "Looses a powerful\n"
            "blast of light that\n"
            "reduces accuracy."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
#if GERMAN
        .name = ITEM_NAME("VM06"),
#else
        .name = ITEM_NAME("HM06"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Steinbrecherische\n"
            "Attacke, die Vert.-\n"
            "Wert senken kann."),
#else
            "A rock-crushingly\n"
            "tough attack that\n"
            "may lower Defense."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_WATERFALL] =
    {
#if GERMAN
        .name = ITEM_NAME("VM07"),
#else
        .name = ITEM_NAME("HM07"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mächtige Attacke,\n"
            "die Wasserfälle\n"
            "bezwingbar macht."),
#else
            "Attacks the foe\n"
            "with enough power\n"
            "to climb waterfalls."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

#if IS_HNS
    [ITEM_HM_WHIRLPOOL] =
    {
#if GERMAN
        .name = ITEM_NAME("VM08"),
#else
        .name = ITEM_NAME("HM08"),
#endif
        .price = 0,
#if GERMAN
        .description = COMPOUND_STRING(
            "Fängt den Gegner in\n"
            "einem tosenden\n"
            "Strudel."),
#else
        .description = COMPOUND_STRING(
            "Traps the foe in a\n"
            "violent swirling\n"
            "whirlpool."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },

    [ITEM_HM_DIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("VM09"),
#else
        .name = ITEM_NAME("HM09"),
#endif
        .price = 0,
#if GERMAN
        .description = COMPOUND_STRING(
            "Pokémon taucht ab,\n"
            "dann erfolgt An-\n"
            "griff aus der Tiefe."),
#else
        .description = COMPOUND_STRING(
            "Dives underwater\n"
            "the 1st turn, then\n"
            "attacks next turn."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#else
    [ITEM_HM_DIVE] =
    {
#if GERMAN
        .name = ITEM_NAME("VM08"),
#else
        .name = ITEM_NAME("HM08"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Pokémon taucht ab,\n"
            "dann erfolgt An-\n"
            "griff aus der Tiefe."),
#else
            "Dives underwater\n"
            "the 1st turn, then\n"
            "attacks next turn."),
#endif
        .importance = 1,
        .pocket = POCKET_TM_HM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TMHM,
    },
#endif


// Charms

    [ITEM_OVAL_CHARM] =
    {
#if GERMAN
        .name = ITEM_NAME("Ovalpin"),
#else
        .name = ITEM_NAME("OVAL CHARM"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Chance\n"
            "auf Eier in der\n"
            "Pension."),
#else
            "Raises the chance\n"
            "of finding eggs\n"
            "at the daycare."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OvalCharm,
        .iconPalette = gItemIconPalette_OvalCharm,
    },

    [ITEM_SHINY_CHARM] =
    {
#if GERMAN
        .name = ITEM_NAME("Schillerpin"),
#else
        .name = ITEM_NAME("SHINY CHARM"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Chance\n"
            "auf schillernde\n"
            "Pokémon."),
#else
            "A charm that will\n"
            "raise the chance\n"
            "of Shiny Pokémon."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ShinyCharm,
        .iconPalette = gItemIconPalette_ShinyCharm,
    },

    [ITEM_CATCHING_CHARM] =
    {
#if GERMAN
        .name = ITEM_NAME("Superfangpin"),
#else
        .name = ITEM_NAME("CATCHING CHARM"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die Chance\n"
            "auf Volltreffer\n"
            "beim Fangen."),
#else
            "A charm that raises\n"
            "the chance of\n"
            "Critical Captures."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CatchingCharm,
        .iconPalette = gItemIconPalette_CatchingCharm,
    },

    [ITEM_EXP_CHARM] =
    {
#if GERMAN
        .name = ITEM_NAME("EP-Pin"),
#else
        .name = ITEM_NAME("EXP. CHARM"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erhöht die im Kampf\n"
            "erhaltenen EP."),
#else
            "A charm that raises\n"
            "the amount of Exp.\n"
            "earned in battle."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ExpCharm,
        .iconPalette = gItemIconPalette_ExpCharm,
    },

// Form-changing Key Items

    [ITEM_ROTOM_CATALOG] =
    {
#if GERMAN
        .name = ITEM_NAME("Rotom-Katalog"),
#else
        .name = ITEM_NAME("ROTOM CATALOG"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Katalog, mit dem\n"
            "Rotom in Geräte\n"
            "schlüpfen kann."),
#else
            "A catalog full of\n"
            "devices liked by\n"
            "Rotom."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_RotomCatalog,
        .iconPic = gItemIcon_RotomCatalog,
        .iconPalette = gItemIconPalette_RotomCatalog,
    },

    [ITEM_GRACIDEA] =
    {
#if GERMAN
        .name = ITEM_NAME("Gracidea"),
#else
        .name = ITEM_NAME("GRACIDEA"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Blume, die Shaymins\n"
            "Form ändert."),
#else
            "Bouquets made with\n"
            "it are offered as a\n"
            "token of gratitude."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Gracidea,
        .iconPalette = gItemIconPalette_Gracidea,
    },

    [ITEM_REVEAL_GLASS] =
    {
#if GERMAN
        .name = ITEM_NAME("Wahrspiegel"),
#else
        .name = ITEM_NAME("REVEAL GLASS"),
        .pluralName = ITEM_PLURAL_NAME("Reveal Glasses"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Spiegel, der ein Po-\n"
            "kémon in seine Ur-\n"
            "form zurückbringt."),
#else
            "This glass returns\n"
            "a Pokémon back to\n"
            "its original form."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_RevealGlass,
        .iconPalette = gItemIconPalette_RevealGlass,
    },

    [ITEM_DNA_SPLICERS] =
    {
#if GERMAN
        .name = ITEM_NAME("DNS-Keil"),
#else
        .name = ITEM_NAME("DNA SPLICERS"),
        .pluralName = ITEM_PLURAL_NAME("DNA Splicers"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Keil, der Kyurem mit\n"
            "einem Pokémon\n"
            "verschmilzt."),
#else
            "Splicer that fuses\n"
            "Kyurem and a\n"
            "certain Pokémon."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_DNASplicers,
        .iconPalette = gItemIconPalette_DNASplicers,
    },

    [ITEM_ZYGARDE_CUBE] =
    {
#if GERMAN
        .name = ITEM_NAME("Zygarde-Würfel"),
#else
        .name = ITEM_NAME("ZYGARDE CUBE"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Würfel, der\n"
            "Zygardes Form\n"
            "ändern kann."),
#else
            "An item to store\n"
            "Zygarde Cores and\n"
            "Cells."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ZygardeCube,
        .iconPic = gItemIcon_ZygardeCube,
        .iconPalette = gItemIconPalette_ZygardeCube,
    },

    [ITEM_PRISON_BOTTLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Banngefäß"),
#else
        .name = ITEM_NAME("PRISON BOTTLE"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gefäß, mit dem einst\n"
            "ein Pokémon\n"
            "gebannt wurde."),
#else
            "A bottle used to\n"
            "seal a certain\n"
            "Pokémon long ago."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_PrisonBottle,
        .iconPalette = gItemIconPalette_PrisonBottle,
    },

    [ITEM_N_SOLARIZER] =
    {
#if GERMAN
        .name = ITEM_NAME("Necrosol"),
#else
        .name = ITEM_NAME("N-SOLARIZER"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät, das Necrozma\n"
            "und Solgaleo\n"
            "vereint und trennt."),
#else
            "A device to fuse\n"
            "and split Necrozma\n"
            "using a Solgaleo."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NSolarizer,
    },

    [ITEM_N_LUNARIZER] =
    {
#if GERMAN
        .name = ITEM_NAME("Necrolun"),
#else
        .name = ITEM_NAME("N-LUNARIZER"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät, das Necrozma\n"
            "und Lunala vereint\n"
            "und trennt."),
#else
            "A device to fuse\n"
            "and split Necrozma\n"
            "using a Lunala."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_NecrozmaFuser,
        .iconPalette = gItemIconPalette_NLunarizer,
    },

    [ITEM_REINS_OF_UNITY] =
    {
#if GERMAN
        .name = ITEM_NAME("Zügel des Bundes"),
#else
        .name = ITEM_NAME("REINS OF UNITY"),
        .pluralName = ITEM_PLURAL_NAME("Reins of Unity"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Zügel, die Coro-\n"
            "nospa mit seinem\n"
            "Reittier vereinen."),
#else
            "Reins that unite\n"
            "Calyrex with its\n"
            "beloved steed."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Fusion,
        .iconPic = gItemIcon_ReinsOfUnity,
        .iconPalette = gItemIconPalette_ReinsOfUnity,
    },

// Battle Mechanic Key Items

    [ITEM_MEGA_RING] =
    {
#if GERMAN
        .name = ITEM_NAME("Mega-Ring"),
#else
        .name = ITEM_NAME("MEGA RING"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ring, der Pokémon\n"
            "mit Mega-Stein\n"
            "entwickeln lässt."),
#else
            "Enables {PKMN} holding\n"
            "their Mega Stone to\n"
            "Mega Evolve."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MegaRing,
        .iconPalette = gItemIconPalette_MegaRing,
    },

    [ITEM_Z_POWER_RING] =
    {
#if GERMAN
        .name = ITEM_NAME("Z-Kraftring"),
#else
        .name = ITEM_NAME("Z-POWER RING"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ring, der die\n"
            "Z-Kraft eines\n"
            "Pokémon freisetzt."),
#else
            "A strange ring\n"
            "that enables\n"
            "Z-Move usage."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ZPowerRing,
        .iconPalette = gItemIconPalette_ZPowerRing,
    },

    [ITEM_DYNAMAX_BAND] =
    {
#if GERMAN
        .name = ITEM_NAME("Dynamax-Band"),
#else
        .name = ITEM_NAME("DYNAMAX BAND"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Band mit\n"
            "Wunschstern, das\n"
            "Dynamax ermöglicht."),
#else
            "A band carrying a\n"
            "Wishing Star that\n"
            "allows Dynamaxing."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DynamaxBand,
        .iconPalette = gItemIconPalette_DynamaxBand,
    },

// Misc. Key Items

    [ITEM_BICYCLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Fahrrad"),
#else
        .name = ITEM_NAME("BIKE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Klapprad, das\n"
            "schneller als\n"
            "Turbotreter ist."),
#else
            "A folding bicycle.\n"
            "Press R while still\n"
            "to change speeds."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = IS_HNS ? ACRO_BIKE : STANDARD_BIKE,
        .iconPic = gItemIcon_Bicycle,
        .iconPalette = gItemIconPalette_Bicycle,
    },

    [ITEM_MACH_BIKE] =
    {
#if GERMAN
        .name = ITEM_NAME("Eilrad"),
#else
        .name = ITEM_NAME("MACH BIKE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Klapprad, das dop-\n"
            "pelt so schnell ist\n"
            "wie ein Fußgänger."),
#else
            "A folding bicycle\n"
            "that doubles your\n"
            "speed or better."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = MACH_BIKE,
        .iconPic = gItemIcon_MachBike,
        .iconPalette = gItemIconPalette_MachBike,
    },

    [ITEM_ACRO_BIKE] =
    {
#if GERMAN
        .name = ITEM_NAME("Kunstrad"),
#else
        .name = ITEM_NAME("ACRO BIKE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Klapprad ermög-\n"
            "licht Sprünge und\n"
            "Wheelies."),
#else
            "A folding bicycle\n"
            "capable of jumps\n"
            "and wheelies."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Bike,
        .secondaryId = ACRO_BIKE,
        .iconPic = gItemIcon_AcroBike,
        .iconPalette = gItemIconPalette_AcroBike,
    },

    [ITEM_OLD_ROD] =
    {
#if GERMAN
        .name = ITEM_NAME("Angel"),
#else
        .name = ITEM_NAME("OLD ROD"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Damit kannst du in\n"
            "jedem Gewässer\n"
            "Pokémon angeln."),
#else
            "Use by any body of\n"
            "water to fish for\n"
            "wild Pokémon."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = OLD_ROD,
        .iconPic = gItemIcon_OldRod,
        .iconPalette = gItemIconPalette_OldRod,
    },

    [ITEM_GOOD_ROD] =
    {
#if GERMAN
        .name = ITEM_NAME("Profiangel"),
#else
        .name = ITEM_NAME("GOOD ROD"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine recht gute\n"
            "Angel zum Fischen\n"
            "von Pokémon."),
#else
            "A decent fishing\n"
            "rod for catching\n"
            "wild Pokémon."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = GOOD_ROD,
        .iconPic = gItemIcon_GoodRod,
        .iconPalette = gItemIconPalette_GoodRod,
    },

    [ITEM_SUPER_ROD] =
    {
#if GERMAN
        .name = ITEM_NAME("Superangel"),
#else
        .name = ITEM_NAME("SUPER ROD"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Die beste Angel, um\n"
            "nach Pokémon zu\n"
            "fischen."),
#else
            "The best fishing\n"
            "rod for catching\n"
            "wild Pokémon."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Rod,
        .secondaryId = SUPER_ROD,
        .iconPic = gItemIcon_SuperRod,
        .iconPalette = gItemIconPalette_SuperRod,
    },

    [ITEM_DOWSING_MACHINE] =
    {
#if GERMAN
        .name = ITEM_NAME("Itemradar"),
#else
        .name = ITEM_NAME("DOWSING MACHINE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Gerät, das ver-\n"
            "borgene Items via\n"
            "Schallwellen ortet."),
#else
            "A device that\n"
            "signals an invisible\n"
            "item by sound."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_Itemfinder,
        .iconPic = gItemIcon_DowsingMachine,
        .iconPalette = gItemIconPalette_DowsingMachine,
    },

    [ITEM_TOWN_MAP] =
    {
#if GERMAN
        .name = ITEM_NAME("Karte"),
#else
        .name = ITEM_NAME("TOWN MAP"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kann stets aufge-\n"
            "rufen werden. Zeigt\n"
            "Standort."),
#else
            "Can be viewed\n"
            "anytime. Shows your\n"
            "present location."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_TownMap,
        .iconPic = gItemIcon_TownMap,
        .iconPalette = gItemIconPalette_TownMap,
    },

    // Origin Jade: not obtainable, kept so that the item ids do not shift.
    [ITEM_VS_SEEKER] =
    {
#if GERMAN
        .name = ITEM_NAME("Kampffahnder"),
#else
        .name = ITEM_NAME("VS. SEEKER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät, das rück-\n"
            "kampfwillige\n"
            "Trainer anzeigt."),
#else
            "A rechargeable unit\n"
            "that flags battle-\n"
            "ready Trainers."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_VsSeeker,
        .iconPalette = gItemIconPalette_VsSeeker,
    },

    [ITEM_TM_CASE] =
    {
#if GERMAN
        .name = ITEM_NAME("VM/TM-Box"),
#else
        .name = ITEM_NAME("TM CASE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Box, in der VMs und\n"
            "TMs aufbewahrt\n"
            "werden."),
#else
            "A convenient case\n"
            "that holds TMs and\n"
            "HMs."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TMCase,
        .iconPalette = gItemIconPalette_TMCase,
    },

    [ITEM_BERRY_POUCH] =
    {
#if GERMAN
        .name = ITEM_NAME("Beerentüte"),
#else
        .name = ITEM_NAME("BERRY POUCH"),
        .pluralName = ITEM_PLURAL_NAME("Berry Pouches"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Tüte, in der Beeren\n"
            "aufbewahrt werden."),
#else
            "A convenient\n"
            "container that\n"
            "holds Berries."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BerryPouch,
        .iconPalette = gItemIconPalette_BerryPouch,
    },

    [ITEM_POKEMON_BOX_LINK] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokémon-Box"),
#else
        .name = ITEM_NAME("{PKMN} BOX LINK"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät, das Zugriff\n"
            "auf das Lagerungs-\n"
            "system gibt."),
#else
            "This device grants\n"
            "access to the {PKMN}\n"
            "Storage System."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_PokemonBoxLink,
        .iconPic = gItemIcon_PokemonBoxLink,
        .iconPalette = gItemIconPalette_PokemonBoxLink,
    },

    [ITEM_COIN_CASE] =
    {
#if GERMAN
        .name = ITEM_NAME("Münzkorb"),
#else
        .name = ITEM_NAME("COIN CASE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kann bis zu 9999\n"
            "Münzen aufnehmen."),
#else
            "A case that holds\n"
            "up to 9,999 Coins."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CoinCase,
        .iconPic = gItemIcon_CoinCase,
        .iconPalette = gItemIconPalette_CoinCase,
    },

    [ITEM_POWDER_JAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Puderdöschen"),
#else
        .name = ITEM_NAME("POWDER JAR"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Glas für Beeren-\n"
            "Puder der\n"
            "Beerenmühle."),
#else
            "Stores Berry\n"
            "Powder made using\n"
            "a Berry Crusher."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PowderJar,
        .iconPic = gItemIcon_PowderJar,
        .iconPalette = gItemIconPalette_PowderJar,
    },

    [ITEM_WAILMER_PAIL] =
    {
#if GERMAN
        .name = ITEM_NAME("Wailmerkanne"),
#else
        .name = ITEM_NAME("WAILMER PAIL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Gegenstand zum\n"
            "Gießen von Pflan-\n"
            "zen wie Beeren."),
#else
            "A tool used for\n"
            "watering Berries\n"
            "and plants."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_WailmerPail,
        .iconPic = gItemIcon_WailmerPail,
        .iconPalette = gItemIconPalette_WailmerPail,
    },

    [ITEM_POKE_RADAR] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokéradar"),
#else
        .name = ITEM_NAME("POKé RADAR"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Spürt Pokémon im\n"
            "hohen Gras auf."),
#else
            "A tool used to\n"
            "search out Pokémon\n"
            "hiding in grass."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse, // Todo
        .iconPic = gItemIcon_PokeRadar,
        .iconPalette = gItemIconPalette_PokeRadar,
    },

    [ITEM_POKEBLOCK_CASE] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokériegelbox"),
#else
        .name = ITEM_NAME("{POKEBLOCK} CASE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Box für {POKEBLOCK}, die\n"
            "im Beerenmixer\n"
            "hergestellt werden."),
#else
            "A case for holding\n"
            "{POKEBLOCK}s made with\n"
            "a Berry Blender."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PBLOCK_CASE,
        .fieldUseFunc = ItemUseOutOfBattle_PokeblockCase,
        .iconPic = gItemIcon_PokeblockCase,
        .iconPalette = gItemIconPalette_PokeblockCase,
    },

    [ITEM_SOOT_SACK] =
    {
#if GERMAN
        .name = ITEM_NAME("Aschetasche"),
#else
        .name = ITEM_NAME("SOOT SACK"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Beutel zum Sammeln\n"
            "und Aufbewahren\n"
            "von Vulkanasche."),
#else
            "A sack used to\n"
            "gather and hold\n"
            "volcanic ash."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SootSack,
        .iconPalette = gItemIconPalette_SootSack,
    },

    [ITEM_POKE_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokéflöte"),
#else
        .name = ITEM_NAME("POKé FLUTE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Flöte, deren Klang\n"
            "jedes schlafende\n"
            "Pokémon aufweckt."),
#else
            "A sweet-sounding\n"
            "flute that awakens\n"
            "Pokémon."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_PokeFlute,
        .battleUsage = EFFECT_ITEM_USE_POKE_FLUTE,
        .iconPic = gItemIcon_PokeFlute,
        .iconPalette = gItemIconPalette_PokeFlute,
    },

    [ITEM_FAME_CHECKER] =
    {
#if GERMAN
        .name = ITEM_NAME("Ruhmesdatei"),
#else
        .name = ITEM_NAME("FAME CHECKER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät, das Infos\n"
            "über wichtige Per-\n"
            "sonen speichert."),
#else
            "Stores information\n"
            "on famous people\n"
            "for instant recall."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_FameChecker,
        .iconPalette = gItemIconPalette_FameChecker,
    },

    [ITEM_TEACHY_TV] =
    {
#if GERMAN
        .name = ITEM_NAME("Lehrkanal"),
#else
        .name = ITEM_NAME("TEACHY TV"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sendung, die dem\n"
            "Anfänger-Trainer\n"
            "Tipps gibt."),
#else
            "A TV set tuned to\n"
            "an advice program\n"
            "for Trainers."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeachyTV,
        .iconPalette = gItemIconPalette_TeachyTV,
    },

// Story Key Items

    [ITEM_SS_TICKET] =
    {
#if GERMAN
        .name = ITEM_NAME("Bootsticket"),
#else
        .name = ITEM_NAME("S.S. TICKET"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Ticket zur\n"
            "Fahrt auf einer\n"
            "Fähre."),
#else
            "The ticket required\n"
            "for sailing on a\n"
            "ferry."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SSTicket,
        .iconPalette = gItemIconPalette_SSTicket,
    },

    [ITEM_EON_TICKET] =
    {
#if GERMAN
        .name = ITEM_NAME("Äon-Ticket"),
#else
        .name = ITEM_NAME("EON TICKET"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Bootsticket zu\n"
            "einer fernen Insel\n"
            "im Süden."),
#else
            "The ticket for a\n"
            "ferry to a distant\n"
            "southern island."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = 1,
        .iconPic = gItemIcon_EonTicket,
        .iconPalette = gItemIconPalette_EonTicket,
    },

    [ITEM_MYSTIC_TICKET] =
    {
#if GERMAN
        .name = ITEM_NAME("Geheimticket"),
#else
        .name = ITEM_NAME("MYSTIC TICKET"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fahrkarte für das\n"
            "Schiff zum\n"
            "Nabelfelsen."),
#else
            "A ticket required\n"
            "to board the ship\n"
            "to Navel Rock."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MysticTicket,
        .iconPalette = gItemIconPalette_MysticTicket,
    },

    [ITEM_AURORA_TICKET] =
    {
#if GERMAN
        .name = ITEM_NAME("Auroraticket"),
#else
        .name = ITEM_NAME("AURORA TICKET"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Fahrkarte für das\n"
            "Schiff zur\n"
            "Entstehungsinsel."),
#else
            "A ticket required\n"
            "to board the ship\n"
            "to Birth Island."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_AuroraTicket,
        .iconPalette = gItemIconPalette_AuroraTicket,
    },

    [ITEM_OLD_SEA_MAP] =
    {
#if GERMAN
        .name = ITEM_NAME("Alte Karte"),
#else
        .name = ITEM_NAME("OLD SEA MAP"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Alte Seekarte!\n"
            "Zeigt den Weg zu\n"
            "einer Insel."),
#else
            "A faded sea chart\n"
            "that shows the way\n"
            "to a certain island."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_OldSeaMap,
        .iconPalette = gItemIconPalette_OldSeaMap,
    },

    [ITEM_LETTER] =
    {
#if GERMAN
        .name = ITEM_NAME("Brief"),
#else
        .name = ITEM_NAME("LETTER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Brief an Troy vom\n"
            "Präsidenten der\n"
            "Devon Corp."),
#else
            "A letter to Steven\n"
            "from the President\n"
            "of the Devon Corp."),
#endif
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Letter,
        .iconPalette = gItemIconPalette_LavaCookieAndLetter,
    },

    [ITEM_DEVON_PARTS] =
    {
#if GERMAN
        .name = ITEM_NAME("Devon-Waren"),
#else
        .name = ITEM_NAME("DEVON PARTS"),
        .pluralName = ITEM_PLURAL_NAME("Devon Parts"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Päckchen, das Ma-\n"
            "schinenteile von\n"
            "Devon enthält."),
#else
            "A package that\n"
            "contains Devon's\n"
            "machine parts."),
#endif
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonParts,
        .iconPalette = gItemIconPalette_DevonParts,
    },

    [ITEM_GO_GOGGLES] =
    {
#if GERMAN
        .name = ITEM_NAME("Wüstenglas"),
#else
        .name = ITEM_NAME("GO-GOGGLES"),
        .pluralName = ITEM_PLURAL_NAME("Go-Goggles"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schicke Brille, die\n"
            "die Augen vor Sand-\n"
            "stürmen schützt."),
#else
            "Nifty goggles that\n"
            "protect eyes from\n"
            "desert sandstorms."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoGoggles,
        .iconPalette = gItemIconPalette_GoGoggles,
    },

    [ITEM_DEVON_SCOPE] =
    {
#if GERMAN
        .name = ITEM_NAME("Devon-Scope"),
#else
        .name = ITEM_NAME("DEVON SCOPE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gerät von Devon,\n"
            "das unsichtbare\n"
            "Pokémon entlarvt."),
#else
            "A device by Devon\n"
            "that signals any\n"
            "unseeable Pokémon."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_DevonScope,
        .iconPalette = gItemIconPalette_DevonScope,
    },

    [ITEM_BASEMENT_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Kelleröffner"),
#else
        .name = ITEM_NAME("BASEMENT KEY"),
#endif
        .price = 0,
#if IS_HNS
        // HnS: opens the door in the Goldenrod Underground.
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel für eine\n"
            "Tür in der Dukatia-\n"
            "Passage."),
#else
            "The key for the\n"
            "GOLDENROD\n"
            "UNDERGROUND."),
#endif
#else
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel für Neu\n"
            "Malvenfroh unter\n"
            "Malvenfroh City."),
#else
            "The key for New\n"
            "Mauville beneath\n"
            "Mauville City."),
#endif
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BasementKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    // Key item: Troy's ticket for the ferry to Hoenn.
    [ITEM_HOENN_TICKET] =
    {
#if GERMAN
        .name = ITEM_NAME("Hoennticket"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Fahrkarte für die\n"
            "einfache Überfahrt\n"
            "nach Hoenn."),
#else
        .name = ITEM_NAME("HOENN TICKET"),
        .price = 0,
        .description = COMPOUND_STRING(
            "A ticket for a\n"
            "one-way voyage\n"
            "to HOENN."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SSTicket,
        .iconPalette = gItemIconPalette_SSTicket,
    },

    [ITEM_NEW_MAUVILLE_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Werkschlüssel"),
        .price = 0,
        .description = COMPOUND_STRING(
            "Schlüssel für Neu\n"
            "Malvenfroh unter\n"
            "Malvenfroh City."),
#else
        .name = ITEM_NAME("BASEMENT KEY"),
        .price = 0,
        .description = COMPOUND_STRING(
            "The key for NEW\n"
            "MAUVILLE beneath\n"
            "MAUVILLE CITY."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BasementKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_SCANNER] =
    {
#if GERMAN
        .name = ITEM_NAME("Scanner"),
#else
        .name = ITEM_NAME("SCANNER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Gerät, das im\n"
            "Schiffswrack\n"
            "gefunden wurde."),
#else
            "A device found\n"
            "inside the\n"
            "Abandoned Ship."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Scanner,
        .iconPalette = gItemIconPalette_Scanner,
    },

    [ITEM_STORAGE_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Lagerschlüssel"),
#else
        .name = ITEM_NAME("STORAGE KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel zum\n"
            "Lagerraum auf dem\n"
            "Schiffswrack."),
#else
            "The key to the\n"
            "storage inside the\n"
            "Abandoned Ship."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StorageKey,
        .iconPalette = gItemIconPalette_OldKey,
    },

    [ITEM_KEY_TO_ROOM_1] =
    {
#if GERMAN
        .name = ITEM_NAME("R1-Schlüssel"),
#else
        .name = ITEM_NAME("KEY TO ROOM 1"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 1"),
#endif
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom1,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_2] =
    {
#if GERMAN
        .name = ITEM_NAME("R2-Schlüssel"),
#else
        .name = ITEM_NAME("KEY TO ROOM 2"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 2"),
#endif
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom2,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_4] =
    {
#if GERMAN
        .name = ITEM_NAME("R4-Schlüssel"),
#else
        .name = ITEM_NAME("KEY TO ROOM 4"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 4"),
#endif
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom4,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_KEY_TO_ROOM_6] =
    {
#if GERMAN
        .name = ITEM_NAME("R6-Schlüssel"),
#else
        .name = ITEM_NAME("KEY TO ROOM 6"),
        .pluralName = ITEM_PLURAL_NAME("Keys to Room 6"),
#endif
        .price = 0,
        .description = sKeyToRoomDesc,
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_KeyToRoom6,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_METEORITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Meteorit"),
#else
        .name = ITEM_NAME("METEORITE"),
#endif
        .price = 0,
#if GERMAN
        .description = COMPOUND_STRING(
            "Meteorit. Fundort:\n"
            "Meteorfälle."),
#else
        .description = COMPOUND_STRING(
            "A meteorite found\n"
            "at Birth Island."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_FormChange,
        .iconPic = gItemIcon_Meteorite,
        .iconPalette = gItemIconPalette_Meteorite,
    },

    [ITEM_MAGMA_EMBLEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Magmaemblem"),
#else
        .name = ITEM_NAME("MAGMA EMBLEM"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Emblem in der Form\n"
            "von Team Magmas\n"
            "Abzeichen."),
#else
            "A medal-like item in\n"
            "the same shape as\n"
            "Team Magma's mark."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MagmaEmblem,
        .iconPalette = gItemIconPalette_MagmaEmblem,
    },

    [ITEM_CONTEST_PASS] =
    {
#if GERMAN
        .name = ITEM_NAME("Wettbewerbskarte"),
#else
        .name = ITEM_NAME("CONTEST PASS"),
        .pluralName = ITEM_PLURAL_NAME("Contest Passes"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ausweis zur Teil-\n"
            "nahme an Pokémon-\n"
            "Wettbewerben."),
#else
            "The pass required\n"
            "for entering\n"
            "Pokémon Contests."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ContestPass,
        .iconPalette = gItemIconPalette_ContestPass,
    },

    [ITEM_PARCEL] =
    {
#if GERMAN
        .name = ITEM_NAME("Paket"),
#else
        .name = ITEM_NAME("PARCEL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Paket! Supermarkt\n"
            "in Vertania an Prof.\n"
            "Eich."),
#else
            "A parcel for Prof.\n"
            "Oak from a Pokémon\n"
            "Mart's clerk."),
#endif
        .importance = 2,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Parcel,
        .iconPalette = gItemIconPalette_Parcel,
    },

    [ITEM_SECRET_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("?-Öffner"),
#else
        .name = ITEM_NAME("SECRET KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel zur Arena\n"
            "der Zinnoberinsel."),
#else
            "The key to the\n"
            "Cinnabar Island\n"
            "Gym's entrance."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SecretKey,
        .iconPalette = gItemIconPalette_SecretKey,
    },

    [ITEM_BIKE_VOUCHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Rad-Coupon"),
#else
        .name = ITEM_NAME("BIKE VOUCHER"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Gutschein für ein\n"
            "Fahrrad im Laden in\n"
            "Azuria."),
#else
            "A voucher for\n"
            "obtaining a bicycle\n"
            "from the Bike Shop."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_BikeVoucher,
        .iconPalette = gItemIconPalette_BikeVoucher,
    },

    [ITEM_GOLD_TEETH] =
    {
#if GERMAN
        .name = ITEM_NAME("Goldzähne"),
#else
        .name = ITEM_NAME("GOLD TEETH"),
        .pluralName = ITEM_PLURAL_NAME("Gold Teeth"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Verlorenes Gebiss\n"
            "des Wärters der\n"
            "Safari-Zone."),
#else
            "Gold dentures lost\n"
            "by the Safari\n"
            "Zone's Warden."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GoldTeeth,
        .iconPalette = gItemIconPalette_GoldTeeth,
    },

    [ITEM_CARD_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Türöffner"),
#else
        .name = ITEM_NAME("CARD KEY"),
#endif
        .price = 0,
#if IS_HNS
        // HnS: Card Key of the Goldenrod Radio Tower.
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüsselkarte für\n"
            "eine Tür im\n"
            "Funkturm."),
#else
            "A card-type door\n"
            "key used in RADIO\n"
            "TOWER."),
#endif
#else
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüsselkarte für\n"
            "HQ der Silph Co. in\n"
            "Saffronia."),
#else
            "A card-type door\n"
            "key used in Silph\n"
            "Co's office."),
#endif
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CardKey,
        .iconPalette = gItemIconPalette_CardKey,
    },

    [ITEM_LIFT_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("Liftöffner"),
#else
        .name = ITEM_NAME("LIFT KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel für\n"
            "Aufzug im Versteck\n"
            "von Team Rocket."),
#else
            "An elevator key\n"
            "used in Team\n"
            "Rocket's Hideout."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LiftKey,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_SILPH_SCOPE] =
    {
#if GERMAN
        .name = ITEM_NAME("Silph Scope"),
#else
        .name = ITEM_NAME("SILPH SCOPE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Linse, mit der un-\n"
            "sichtbare Pokémon\n"
            "sichtbar werden."),
#else
            "Silph Co's scope\n"
            "makes unseeable\n"
            "POKéMON visible."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SilphScope,
        .iconPalette = gItemIconPalette_SilphScope,
    },

    [ITEM_TRI_PASS] =
    {
#if GERMAN
        .name = ITEM_NAME("Tri-Pass"),
#else
        .name = ITEM_NAME("TRI-PASS"),
        .pluralName = ITEM_PLURAL_NAME("Tri-Passes"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Pass für die Fähren\n"
            "zwischen Eiland\n"
            "eins, zwei, drei."),
#else
            "A pass for ferries\n"
            "between One, Two,\n"
            "and Three Island."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TriPass,
        .iconPalette = gItemIconPalette_TriPass,
    },

    [ITEM_RAINBOW_PASS] =
    {
#if GERMAN
        .name = ITEM_NAME("Bunt-Pass"),
#else
        .name = ITEM_NAME("RAINBOW PASS"),
        .pluralName = ITEM_PLURAL_NAME("Rainbow Passes"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Pass für die Fähren\n"
            "zwischen Orania/\n"
            "Sevii Eilanden."),
#else
            "For ferries serving\n"
            "Vermilion and the\n"
            "Sevii Islands."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RainbowPass,
        .iconPalette = gItemIconPalette_RainbowPass,
    },

    [ITEM_TEA] =
    {
#if GERMAN
        .name = ITEM_NAME("Tee"),
#else
        .name = ITEM_NAME("TEA"),
        .pluralName = ITEM_PLURAL_NAME("Tea"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Tee, der von einer\n"
            "alten Dame\n"
            "zubereitet wird."),
#else
            "A thirst-quenching\n"
            "tea prepared by an\n"
            "old lady."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Tea,
        .iconPalette = gItemIconPalette_Tea,
    },

    [ITEM_RUBY] =
    {
#if GERMAN
        .name = ITEM_NAME("Rubin"),
#else
        .name = ITEM_NAME("RUBY"),
        .pluralName = ITEM_PLURAL_NAME("Rubies"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rotes Juwel, das\n"
            "Leidenschaft\n"
            "symbolisiert."),
#else
            "An exquisite, red-\n"
            "glowing gem that\n"
            "symbolizes passion."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Ruby,
    },

    [ITEM_SAPPHIRE] =
    {
#if GERMAN
        .name = ITEM_NAME("Saphir"),
#else
        .name = ITEM_NAME("SAPPHIRE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Blaues Juwel, das\n"
            "Ehrlichkeit\n"
            "symbolisiert."),
#else
            "A brilliant blue gem\n"
            "that symbolizes\n"
            "honesty."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Gem,
        .iconPalette = gItemIconPalette_Sapphire,
    },

    [ITEM_ABILITY_SHIELD] =
    {
#if GERMAN
        .name = ITEM_NAME("Fähigkeitenschild"),
#else
        .name = ITEM_NAME("ABILITY SHIELD"),
#endif
        .price = 20000,
        .holdEffect = HOLD_EFFECT_ABILITY_SHIELD,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) ver-\n"
            "hindert Änderung\n"
            "der Fähigkeit."),
#else
            "Ability changes are\n"
            "prevented for this\n"
            "items's holder."),
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_AbilityShield,
        .iconPalette = gItemIconPalette_AbilityShield,
    },

// GEN 9 ITEMS

    [ITEM_CLEAR_AMULET] =
    {
#if GERMAN
        .name = ITEM_NAME("Neutralschmuck"),
#else
        .name = ITEM_NAME("CLEAR AMULET"),
#endif
        .price = 30000,
        .holdEffect = HOLD_EFFECT_CLEAR_AMULET,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) ver-\n"
            "hindert das Senken\n"
            "der Statuswerte."),
#else
            "Stat lowering is\n"
            "prevented for this\n"
            "items's holder."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_ClearAmulet,
        .iconPalette = gItemIconPalette_ClearAmulet,
    },

    [ITEM_PUNCHING_GLOVE] =
    {
#if GERMAN
        .name = ITEM_NAME("Boxhandschuh"),
#else
        .name = ITEM_NAME("PUNCHING GLOVE"),
#endif
        .price = 15000,
        .holdEffect = HOLD_EFFECT_PUNCHING_GLOVE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) macht\n"
            "Box-Attacken stark\n"
            "und kontaktlos."),
#else
            "Powers up punching\n"
            "moves and removes\n"
            "their contact."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_PunchingGlove,
        .iconPalette = gItemIconPalette_PunchingGlove,
    },

    [ITEM_COVERT_CLOAK] =
    {
#if GERMAN
        .name = ITEM_NAME("Tarnumhang"),
        .pluralName = ITEM_PLURAL_NAME("Tarnumhänge"),
#else
        .name = ITEM_NAME("COVERT CLOAK"),
#endif
        .price = 20000,
        .holdEffect = HOLD_EFFECT_COVERT_CLOAK,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "schützt vor\n"
            "Zusatzeffekten."),
#else
            "Protects holder\n"
            "from additional\n"
            "effects of moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_CovertCloak,
        .iconPalette = gItemIconPalette_CovertCloak,
    },

    [ITEM_LOADED_DICE] =
    {
#if GERMAN
        .name = ITEM_NAME("Gezinkter Würfel"),
        .pluralName = ITEM_PLURAL_NAME("Gezinkte Würfel"),
#else
        .name = ITEM_NAME("LOADED DICE"),
        .pluralName = ITEM_PLURAL_NAME("Loaded Dice"),
#endif
        .price = 20000,
        .holdEffect = HOLD_EFFECT_LOADED_DICE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Würfelt hohe\n"
            "Zahlen."),
#else
            "Rolls high numbers.\n"
            "Multihit strikes\n"
            "hit more times."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_LoadedDice,
        .iconPalette = gItemIconPalette_LoadedDice,
    },

    [ITEM_AUSPICIOUS_ARMOR] =
    {
#if GERMAN
        .name = ITEM_NAME("Glorienrüstung"),
#else
        .name = ITEM_NAME("AUSPICIOUS ARMOR"),
#endif
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rüstung voll guter\n"
            "Wünsche. Löst eine\n"
            "Entwicklung aus."),
#else
            "Armor inhabited by\n"
            "auspicious wishes.\n"
            "Causes evolution."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_AuspiciousArmor,
        .iconPalette = gItemIconPalette_AuspiciousArmor,
    },

    [ITEM_BOOSTER_ENERGY] =
    {
#if GERMAN
        .name = ITEM_NAME("Energiekapsel"),
        .pluralName = ITEM_PLURAL_NAME("Energiekapseln"),
#else
        .name = ITEM_NAME("BOOSTER ENERGY"),
        .pluralName = ITEM_PLURAL_NAME("Booster Energies"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_BOOSTER_ENERGY,
        .description = COMPOUND_STRING(
#if GERMAN
            "Energie, die Poké-\n"
            "mon mit bestimmten\n"
            "Fähigkeiten stärkt."),
#else
            "Encapsuled energy\n"
            "ups Pokémon with\n"
            "certain Abilities."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BoosterEnergy,
        .iconPalette = gItemIconPalette_BoosterEnergy,
    },

    [ITEM_BIG_BAMBOO_SHOOT] =
    {
#if GERMAN
        .name = ITEM_NAME("Riesenbambusspross"),
#else
        .name = ITEM_NAME("BIG BAMBOO SHOOT"),
#endif
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Großer, seltener\n"
            "Bambusspross von\n"
            "großem Wert."),
#else
            "A large and rare\n"
            "bamboo shoot. Best\n"
            "sold to gourmands."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_BigBambooShoot,
        .iconPalette = gItemIconPalette_BigBambooShoot,
    },

    [ITEM_GIMMIGHOUL_COIN] =
    {
#if GERMAN
        .name = ITEM_NAME("Gierspenst-Münze"),
#else
        .name = ITEM_NAME("GIMMIGHOUL COIN"),
#endif
        .price = 400,
        .description = COMPOUND_STRING(
#if GERMAN
            "Münze von Gier-\n"
            "spenst. Löst eine\n"
            "Entwicklung aus."),
#else
            "Gimmighoul hoard\n"
            "and treasure these\n"
            "curious coins."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GimmighoulCoin,
        .iconPalette = gItemIconPalette_GimmighoulCoin,
    },

    [ITEM_LEADERS_CREST] =
    {
#if GERMAN
        .name = ITEM_NAME("Anführersymbol"),
#else
        .name = ITEM_NAME("LEADER'S CREST"),
#endif
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Scherbe einer alten\n"
            "Klinge. Löst eine\n"
            "Entwicklung aus."),
#else
            "A shard of an old\n"
            "blade of some sort.\n"
            "Held by Bisharp."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LeadersCrest,
        .iconPalette = gItemIconPalette_LeadersCrest,
    },

    [ITEM_MALICIOUS_ARMOR] =
    {
#if GERMAN
        .name = ITEM_NAME("Fluchrüstung"),
#else
        .name = ITEM_NAME("MALICIOUS ARMOR"),
#endif
        .price = 3000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rüstung voll bösen\n"
            "Willens. Löst eine\n"
            "Entwicklung aus."),
#else
            "Armor inhabited by\n"
            "malicious will.\n"
            "Causes evolution."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_MaliciousArmor,
        .iconPalette = gItemIconPalette_MaliciousArmor,
    },

    [ITEM_MIRROR_HERB] =
    {
#if GERMAN
        .name = ITEM_NAME("Kopierkraut"),
        .pluralName = ITEM_PLURAL_NAME("Kopierkräuter"),
#else
        .name = ITEM_NAME("MIRROR HERB"),
#endif
        .price = 30000,
        .holdEffect = HOLD_EFFECT_MIRROR_HERB,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) spie-\n"
            "gelt gegnerische\n"
            "Statuserhöhung."),
#else
            "Mirrors an enemy's\n"
            "stat increases\n"
            "but only once."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_MirrorHerb,
        .iconPalette = gItemIconPalette_MirrorHerb,
    },

    [ITEM_SCROLL_OF_DARKNESS] =
    {
#if GERMAN
        .name = ITEM_NAME("Unlichtschriftrolle"),
#else
        .name = ITEM_NAME("SCROLL OF DARKNESS"),
        .pluralName = ITEM_PLURAL_NAME("Scrolls of Darkness"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schriftrolle mit\n"
            "Geheimnissen des\n"
            "Unlicht-Pfades."),
#else
            "A peculiar scroll\n"
            "with secrets of\n"
            "the dark path."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfDarkness,
        .iconPalette = gItemIconPalette_ScrollOfDarkness,
    },

    [ITEM_SCROLL_OF_WATERS] =
    {
#if GERMAN
        .name = ITEM_NAME("Wasserschriftrolle"),
#else
        .name = ITEM_NAME("SCROLL OF WATERS"),
        .pluralName = ITEM_PLURAL_NAME("Scrolls of Waters"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schriftrolle mit\n"
            "Geheimnissen des\n"
            "Wasser-Pfades."),
#else
            "A peculiar scroll\n"
            "with secrets of\n"
            "the water path."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_ScrollOfWaters,
        .iconPalette = gItemIconPalette_ScrollOfWaters,
    },

    [ITEM_TERA_ORB] =
    {
#if GERMAN
        .name = ITEM_NAME("Terakristall-Orb"),
#else
        .name = ITEM_NAME("TERA ORB"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Orb, dessen Energie\n"
            "die Terakristalli-\n"
            "sierung auslöst."),
#else
            "Energy charges can\n"
            "be used to cause\n"
            "Terastallization."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraOrb,
        .iconPalette = gItemIconPalette_TeraOrb,
    },

    [ITEM_TINY_BAMBOO_SHOOT] =
    {
#if GERMAN
        .name = ITEM_NAME("Minibambusspross"),
#else
        .name = ITEM_NAME("TINY BAMBOO SHOOT"),
#endif
        .price = 750,
        .description = COMPOUND_STRING(
#if GERMAN
            "Kleiner, seltener\n"
            "Bambusspross von\n"
            "geringem Wert."),
#else
            "A small and rare\n"
            "bamboo shoot. Best\n"
            "sold to gourmands."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 30,
        .iconPic = gItemIcon_TinyBambooShoot,
        .iconPalette = gItemIconPalette_TinyBambooShoot,
    },

    [ITEM_BUG_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Käfer)"),
#else
        .name = ITEM_NAME("BUG TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_BugTeraShard,
    },

    [ITEM_DARK_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Unlicht)"),
#else
        .name = ITEM_NAME("DARK TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DarkTeraShard,
    },

    [ITEM_DRAGON_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Drache)"),
#else
        .name = ITEM_NAME("DRAGON TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_DragonTeraShard,
    },

    [ITEM_ELECTRIC_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Elektro)"),
#else
        .name = ITEM_NAME("ELECTRIC TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_ElectricTeraShard,
    },

    [ITEM_FAIRY_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Fee)"),
#else
        .name = ITEM_NAME("FAIRY TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FairyTeraShard,
    },

    [ITEM_FIGHTING_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Kampf)"),
#else
        .name = ITEM_NAME("FIGHTING TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FightingTeraShard,
    },

    [ITEM_FIRE_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Feuer)"),
#else
        .name = ITEM_NAME("FIRE TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FireTeraShard,
    },

    [ITEM_FLYING_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Flug)"),
#else
        .name = ITEM_NAME("FLYING TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_FlyingTeraShard,
    },

    [ITEM_GHOST_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Geist)"),
#else
        .name = ITEM_NAME("GHOST TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GhostTeraShard,
    },

    [ITEM_GRASS_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Pflanze)"),
#else
        .name = ITEM_NAME("GRASS TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GrassTeraShard,
    },

    [ITEM_GROUND_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Boden)"),
#else
        .name = ITEM_NAME("GROUND TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_GroundTeraShard,
    },

    [ITEM_ICE_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Eis)"),
#else
        .name = ITEM_NAME("ICE TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_IceTeraShard,
    },

    [ITEM_NORMAL_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Normal)"),
#else
        .name = ITEM_NAME("NORMAL TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_NormalTeraShard,
    },

    [ITEM_POISON_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Gift)"),
#else
        .name = ITEM_NAME("POISON TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PoisonTeraShard,
    },

    [ITEM_PSYCHIC_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Psycho)"),
#else
        .name = ITEM_NAME("PSYCHIC TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_PsychicTeraShard,
    },

    [ITEM_ROCK_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Gestein)"),
#else
        .name = ITEM_NAME("ROCK TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_RockTeraShard,
    },

    [ITEM_STEEL_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Stahl)"),
#else
        .name = ITEM_NAME("STEEL TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_SteelTeraShard,
    },

    [ITEM_WATER_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Wasser)"),
#else
        .name = ITEM_NAME("WATER TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TeraShard,
        .iconPalette = gItemIconPalette_WaterTeraShard,
    },

    [ITEM_ADAMANT_CRYSTAL] =
    {
#if GERMAN
        .name = ITEM_NAME("Adamantkristall"),
#else
        .name = ITEM_NAME("ADAMANT CRYSTAL"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_ADAMANT_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Leuchtender Edel-\n"
            "stein, der Dialgas\n"
            "Form ändert."),
#else
            "A large, glowing gem\n"
            "that lets Dialga\n"
            "change form."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_AdamantCrystal,
        .iconPalette = gItemIconPalette_AdamantCrystal,
    },

    [ITEM_GRISEOUS_CORE] =
    {
#if GERMAN
        .name = ITEM_NAME("Platinumkristall"),
#else
        .name = ITEM_NAME("GRISEOUS CORE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_GRISEOUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Leuchtender Edel-\n"
            "stein, der Giratinas\n"
            "Form ändert."),
#else
            "A large, glowing gem\n"
            "that lets Giratina\n"
            "change form."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_GriseousCore,
        .iconPalette = gItemIconPalette_GriseousCore,
    },

    [ITEM_LUSTROUS_GLOBE] =
    {
#if GERMAN
        .name = ITEM_NAME("Weißkristall"),
#else
        .name = ITEM_NAME("LUSTROUS GLOBE"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_LUSTROUS_ORB,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Leuchtender Edel-\n"
            "stein, der Palkias\n"
            "Form ändert."),
#else
            "A large, glowing gem\n"
            "that lets Palkia\n"
            "change form."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 60,
        .iconPic = gItemIcon_LustrousGlobe,
        .iconPalette = gItemIconPalette_LustrousGlobe,
    },

    [ITEM_BLACK_AUGURITE] =
    {
#if GERMAN
        .name = ITEM_NAME("Schwarzaugit"),
#else
        .name = ITEM_NAME("BLACK AUGURITE"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schwarzer Stein.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A black stone that\n"
            "makes some Pokémon\n"
            "evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_BlackAugurite,
        .iconPalette = gItemIconPalette_BlackAugurite,
    },

    [ITEM_LINKING_CORD] =
    {
#if GERMAN
        .name = ITEM_NAME("Verbindungsschnur"),
#else
        .name = ITEM_NAME("LINKING CORD"),
#endif
        .price = 8000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltsame Schnur.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A mysterious string\n"
            "that makes some\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_LinkingCord,
        .iconPalette = gItemIconPalette_LinkingCord,
    },

    [ITEM_PEAT_BLOCK] =
    {
#if GERMAN
        .name = ITEM_NAME("Torfblock"),
#else
        .name = ITEM_NAME("PEAT BLOCK"),
#endif
        .price = 20000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Block aus Torf.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A block of material\n"
            "that makes some\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_PeatBlock,
        .iconPalette = gItemIconPalette_PeatBlock,
    },

    [ITEM_BERSERK_GENE] =
    {
#if GERMAN
        .name = ITEM_NAME("Berserk-Gen"),
#else
        .name = ITEM_NAME("BERSERK GENE"),
#endif
        .price = 20,
        .holdEffect = HOLD_EFFECT_BERSERK_GENE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hebt Angr. stark,\n"
            "stiftet aber dauer-\n"
            "haft Verwirrung."),
#else
            "Sharply boosts\n"
            "Attack, but causes\n"
            "lasting confusion."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .flingPower = 10,
        .iconPic = gItemIcon_BerserkGene,
        .iconPalette = gItemIconPalette_BerserkGene,
    },

    [ITEM_FAIRY_FEATHER] =
    {
#if GERMAN
        .name = ITEM_NAME("Feendaune"),
#else
        .name = ITEM_NAME("FAIRY FEATHER"),
#endif
        .price = 1000,
        .holdEffect = HOLD_EFFECT_TYPE_POWER,
        .holdEffectParam = TYPE_BOOST_PARAM,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen)\n"
            "verstärkt\n"
            "Fee-Attacken."),
#else
            "A hold item that\n"
            "raises the power of\n"
            "Fairy-type moves."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TYPE_BOOST_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = TYPE_FAIRY,
        .flingPower = 10,
        .iconPic = gItemIcon_FairyFeather,
        .iconPalette = gItemIconPalette_FairyFeather,
    },

    [ITEM_SYRUPY_APPLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Saftiger Apfel"),
        .pluralName = ITEM_PLURAL_NAME("Saftige Äpfel"),
#else
        .name = ITEM_NAME("SYRUPY APPLE"),
#endif
        .price = 2200,
        .description = COMPOUND_STRING(
#if GERMAN
            "Sirupiger Apfel.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A very syrupy apple\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 30,
        .iconPic = gItemIcon_SyrupyApple,
        .iconPalette = gItemIconPalette_SyrupyApple,
    },

    [ITEM_UNREMARKABLE_TEACUP] =
    {
#if GERMAN
        .name = ITEM_NAME("Simple Teeschale"),
#else
        .name = ITEM_NAME("UNREMARKABLE TEACUP"),
#endif
        .price = 1600,
        .description = COMPOUND_STRING(
#if GERMAN
            "Rissige Teetasse.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A cracked teacup\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_UnremarkableTeacup,
        .iconPalette = gItemIconPalette_UnremarkableTeacup,
    },

    [ITEM_MASTERPIECE_TEACUP] =
    {
#if GERMAN
        .name = ITEM_NAME("Edle Teeschale"),
#else
        .name = ITEM_NAME("MASTERPIECE TEACUP"),
#endif
        .price = 38000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Edle Teetasse. Löst\n"
            "eine Entwicklung\n"
            "aus."),
#else
            "A chipped teacup\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .flingPower = 80,
        .iconPic = gItemIcon_MasterpieceTeacup,
        .iconPalette = gItemIconPalette_MasterpieceTeacup,
    },

    [ITEM_CORNERSTONE_MASK] =
    {
#if GERMAN
        .name = ITEM_NAME("Fundamentmaske"),
#else
        .name = ITEM_NAME("CORNERSTONE MASK"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ermöglicht Ogerpon,\n"
            "den Rock-Typ im\n"
            "Kampf zu führen."),
#else
            "Allows Ogerpon to\n"
            "wield the Rock-\n"
            "type in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_CornerstoneMask,
        .iconPalette = gItemIconPalette_CornerstoneMask,
    },

    [ITEM_WELLSPRING_MASK] =
    {
#if GERMAN
        .name = ITEM_NAME("Brunnenmaske"),
#else
        .name = ITEM_NAME("WELLSPRING MASK"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ermöglicht Ogerpon,\n"
            "den Wassertyp im\n"
            "Kampf einzusetzen."),
#else
            "Allows Ogerpon to\n"
            "wield the Water-\n"
            "type in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_WellspringMask,
        .iconPalette = gItemIconPalette_WellspringMask,
    },

    [ITEM_HEARTHFLAME_MASK] =
    {
#if GERMAN
        .name = ITEM_NAME("Ofenmaske"),
#else
        .name = ITEM_NAME("HEARTHFLAME MASK"),
#endif
        .price = 0,
        .holdEffect = HOLD_EFFECT_OGERPON_MASK,
        .holdEffectParam = 20,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ermöglicht Ogerpon,\n"
            "im Kampf den Feuer-\n"
            "typ zu verwenden."),
#else
            "Allows Ogerpon to\n"
            "wield the Fire-\n"
            "type in battle."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_SPECIAL_HELD_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HearthflameMask,
        .iconPalette = gItemIconPalette_HearthflameMask,
    },

    [ITEM_HEALTH_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Heil-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Heil-Mochis"),
#else
        .name = ITEM_NAME("HEALTH MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Health Mochi"),
#endif
        .price = 500,
        .description = sHealthFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_HpMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_HealthMochi,
    },

    [ITEM_MUSCLE_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Kraft-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Kraft-Mochis"),
#else
        .name = ITEM_NAME("MUSCLE MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Muscle Mochi"),
#endif
        .price = 500,
        .description = sMuscleFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_AtkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_MuscleMochi,
    },

    [ITEM_RESIST_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Abwehr-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Abwehr-Mochis"),
#else
        .name = ITEM_NAME("RESIST MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Resist Mochi"),
#endif
        .price = 500,
        .description = sResistFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_DefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_ResistMochi,
    },

    [ITEM_GENIUS_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Genie-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Genie-Mochis"),
#else
        .name = ITEM_NAME("GENIUS MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Genius Mochi"),
#endif
        .price = 500,
        .description = sGeniusFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpatkMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_GeniusMochi,
    },

    [ITEM_CLEVER_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Esprit-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Esprit-Mochis"),
#else
        .name = ITEM_NAME("CLEVER MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Clever Mochi"),
#endif
        .price = 500,
        .description = sCleverFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpdefMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_CleverMochi,
    },

    [ITEM_SWIFT_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Flink-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Flink-Mochis"),
#else
        .name = ITEM_NAME("SWIFT MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Swift Mochi"),
#endif
        .price = 500,
        .description = sSwiftFeatherDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .effect = gItemEffect_SpeedMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_SwiftMochi,
    },

    [ITEM_FRESH_START_MOCHI] =
    {
#if GERMAN
        .name = ITEM_NAME("Neuanfangs-Mochi"),
        .pluralName = ITEM_PLURAL_NAME("Neuanfangs-Mochis"),
#else
        .name = ITEM_NAME("FRESH-START MOCHI"),
        .pluralName = ITEM_PLURAL_NAME("Fresh-Start Mochi"),
#endif
        .price = 300,
        .description = COMPOUND_STRING(
#if GERMAN
            "Setzt alle\n"
            "Basispunkte eines\n"
            "Pokémon zurück."),
#else
            "An item that resets\n"
            "all base points of\n"
            "a Pokémon."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_STAT_BOOST_MOCHI,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_ResetEVs,
        .effect = gItemEffect_ResetMochi,
        .flingPower = 30,
        .iconPic = gItemIcon_Mochi,
        .iconPalette = gItemIconPalette_FreshStartMochi,
    },

    [ITEM_GLIMMERING_CHARM] =
    {
#if GERMAN
        .name = ITEM_NAME("Glitzerpin"),
#else
        .name = ITEM_NAME("GLIMMERING CHARM"),
#endif
        .price = 0,
        .importance = 1,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Zauber, der die\n"
            "Splitter von Tera\n"
            "Raids hervorbringt."),
#else
            "A charm that will\n"
            "raise the shards\n"
            "from Tera Raids."),
#endif
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_GlimmeringCharm,
        .iconPalette = gItemIconPalette_GlimmeringCharm,
    },

    [ITEM_METAL_ALLOY] =
    {
#if GERMAN
        .name = ITEM_NAME("Legierungsmetall"),
#else
        .name = ITEM_NAME("METAL ALLOY"),
#endif
        .price = 6000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Seltsames Metall.\n"
            "Löst eine\n"
            "Entwicklung aus."),
#else
            "A peculiar metal\n"
            "that makes certain\n"
            "Pokémon evolve."),
#endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_EVOLUTION_ITEM,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_EvolutionStone,
        .effect = gItemEffect_EvoItem,
        .iconPic = gItemIcon_MetalAlloy,
        .iconPalette = gItemIconPalette_MetalAlloy,
    },

    [ITEM_STELLAR_TERA_SHARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Tera-Stk. (Stellar)"),
#else
        .name = ITEM_NAME("STELLAR TERA SHARD"),
#endif
        .price = 0,
        .description = sTeraShardDesc,
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_TERA_SHARD,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_StellarTeraShard,
        .iconPalette = gItemIconPalette_StellarTeraShard,
    },

    [ITEM_JUBILIFE_MUFFIN] =
    {
#if GERMAN
        .name = ITEM_NAME("Jubelmuffin"),
#else
        .name = ITEM_NAME("JUBILIFE MUFFIN"),
#endif
        .price = 250,
        .description = sFullHealDesc,
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_STATUS_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_CURE_STATUS,
        .effect = gItemEffect_FullHeal,
        .flingPower = 30,
        .iconPic = gItemIcon_JubilifeMuffin,
        .iconPalette = gItemIconPalette_JubilifeMuffin,
    },

    [ITEM_REMEDY] =
    {
#if GERMAN
        .name = ITEM_NAME("Arznei"),
        .pluralName = ITEM_PLURAL_NAME("Arzneien"),
#else
        .name = ITEM_NAME("REMEDY"),
        .pluralName = ITEM_PLURAL_NAME("Remedies"),
#endif
        .price = 150,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein bitteres Pulver,\n"
            "das die KP um 20\n"
            "Punkte auffüllt."),
#else
            "A bitter powder\n"
            "that restores HP\n"
            "by 20 points."),
#endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_Remedy,
        .flingPower = 30,
        .iconPic = gItemIcon_Remedy,
        .iconPalette = gItemIconPalette_Remedy,
    },

    [ITEM_FINE_REMEDY] =
    {
#if GERMAN
        .name = ITEM_NAME("Superarznei"),
        .pluralName = ITEM_PLURAL_NAME("Superarzneien"),
#else
        .name = ITEM_NAME("FINE REMEDY"),
        .pluralName = ITEM_PLURAL_NAME("Fine Remedies"),
#endif
        .price = 150,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Ein bitteres Pulver,\n"
            "das die KP um 60\n"
            "Punkte auffüllt."),
#else
            "by 60 points."),
#endif
        #else
#if GERMAN
            "Ein bitteres Pulver,\n"
            "das die KP um 50\n"
            "Punkte auffüllt."),
#else
            "by 50 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_FineRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_FineRemedy,
        .iconPalette = gItemIconPalette_FineRemedy,
    },

    [ITEM_SUPERB_REMEDY] =
    {
#if GERMAN
        .name = ITEM_NAME("Hyperarznei"),
        .pluralName = ITEM_PLURAL_NAME("Hyperarzneien"),
#else
        .name = ITEM_NAME("SUPERB REMEDY"),
        .pluralName = ITEM_PLURAL_NAME("Superb Remedies"),
#endif
        .price = 750,
        .description = COMPOUND_STRING(
        #if I_HEALTH_RECOVERY >= GEN_7
#if GERMAN
            "Ein bitteres Pulver,\n"
            "das die KP um 120\n"
            "Punkte auffüllt."),
#else
            "by 120 points."),
#endif
        #else
#if GERMAN
            "Ein bitteres Pulver,\n"
            "das die KP um 200\n"
            "Punkte auffüllt."),
#else
            "by 200 points."),
#endif
        #endif
        .pocket = POCKET_MEDICINE,
        .sortType = ITEM_TYPE_HEALTH_RECOVERY,
        .type = ITEM_USE_PARTY_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_Medicine,
        .battleUsage = EFFECT_ITEM_RESTORE_HP,
        .effect = gItemEffect_SuperbRemedy,
        .flingPower = 30,
        .iconPic = gItemIcon_SuperbRemedy,
        .iconPalette = gItemIconPalette_SuperbRemedy,
    },

    [ITEM_AUX_EVASION] =
    {
#if GERMAN
        .name = ITEM_NAME("Ausweichvitamine"),
#else
        .name = ITEM_NAME("AUX EVASION"),
#endif
        .price = 800,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt den\n"
            "Fluchtwert stark\n"
            "für einen Kampf."),
#else
            "Sharply raises\n"
            "evasiveness during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt den\n"
            "Fluchtwert für\n"
            "einen Kampf."),
#else
            "Raises evasiveness\n"
            "during one battle."),
#endif
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxEvasion,
    },

    [ITEM_AUX_GUARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Defensivvitamine"),
#else
        .name = ITEM_NAME("AUX GUARD"),
#endif
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt die\n"
            "Verteidigung stark\n"
            "für einen Kampf."),
#else
            "Sharply raises\n"
            "defenses during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt die\n"
            "Verteidigung für\n"
            "einen Kampf."),
#else
            "Raises defenses\n"
            "during one battle."),
#endif
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxGuard,
    },

    [ITEM_AUX_POWER] =
    {
#if GERMAN
        .name = ITEM_NAME("Offensivvitamine"),
#else
        .name = ITEM_NAME("AUX POWER"),
#endif
        .price = 400,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt die Offensive\n"
            "stark für einen\n"
            "Kampf."),
#else
            "Sharply raises\n"
            "offenses during\n"
            "one battle."),
#endif
        #else
#if GERMAN
            "Hebt die Offensive\n"
            "für einen Kampf."),
#else
            "Raises offenses\n"
            "during one battle."),
#endif
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxBottle,
        .iconPalette = gItemIconPalette_AuxPower,
    },

    [ITEM_AUX_POWERGUARD] =
    {
#if GERMAN
        .name = ITEM_NAME("Kombivitamine"),
#else
        .name = ITEM_NAME("AUX POWERGUARD"),
#endif
        .price = 1200,
        .holdEffectParam = X_ITEM_STAGES,
        .description = COMPOUND_STRING(
        #if B_X_ITEMS_BUFF >= GEN_7
#if GERMAN
            "Hebt Offensive und\n"
            "Defensive stark für\n"
            "einen Kampf."),
#else
            "Sharply raises\n"
            "offense & defense\n"
            "during one battle."),
#endif
        #else
#if GERMAN
            "Hebt Offensive und\n"
            "Defensive für einen\n"
            "Kampf."),
#else
            "Raises offense\n"
            "and defense during\n"
            "one battle."),
#endif
        #endif
        .pocket = POCKET_ITEMS,
        .sortType = ITEM_TYPE_AUX_ITEM,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_AuxPowerguard,
        .iconPalette = gItemIconPalette_AuxPowerguard,
    },

    [ITEM_CHOICE_DUMPLING] =
    {
#if GERMAN
        .name = ITEM_NAME("Wahlreishappen"),
#else
        .name = ITEM_NAME("CHOICE DUMPLING"),
#endif
        .price = 1200,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_ChoiceDumpling,
        .iconPalette = gItemIconPalette_ChoiceDumpling,
    },

    [ITEM_SWAP_SNACK] =
    {
#if GERMAN
        .name = ITEM_NAME("Umkehrbratling"),
        .pluralName = ITEM_PLURAL_NAME("Umkehrbratlinge"),
#else
        .name = ITEM_NAME("SWAP SNACK"),
#endif
        .price = 1200,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_SwapSnack,
        .iconPalette = gItemIconPalette_SwapSnack,
    },

    [ITEM_TWICE_SPICED_RADISH] =
    {
#if GERMAN
        .name = ITEM_NAME("Doppelrettich"),
        .pluralName = ITEM_PLURAL_NAME("Doppelrettiche"),
#else
        .name = ITEM_NAME("TWICE-SPICED RADISH"),
        .pluralName = ITEM_PLURAL_NAME("Twice-Spiced Radishes"),
#endif
        .price = 1600,
        .description = sQuestionMarksDesc,
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        //.effect = currently missing
        .iconPic = gItemIcon_TwiceSpicedRadish,
        .iconPalette = gItemIconPalette_TwiceSpicedRadish,
    },

    [ITEM_POKESHI_DOLL] =
    {
#if GERMAN
        .name = ITEM_NAME("Pokémon-Kokeshi"),
#else
        .name = ITEM_NAME("POKéSHI DOLL"),
#endif
        .price = 2000,
        .description = COMPOUND_STRING(
#if GERMAN
            "Holzspielzeug in\n"
            "Form eines Pokémon."),
#else
            "A wooden toy\n"
            "resembling a Poké-\n"
            "mon. Can be sold."),
#endif
        .pocket = POCKET_TREASURES,
        .sortType = ITEM_TYPE_SELLABLE,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_PokeshiDoll,
        .iconPalette = gItemIconPalette_PokeshiDoll,
    },

// HnS Items

    // Key item: Oak's parcel for Elm, opens Celebi's shrine.
    [ITEM_GS_BALL] =
    {
#if GERMAN
        .name = ITEM_NAME("GS-Ball"),
#else
        .name = ITEM_NAME("GS BALL"),
#endif
        .price = 0,
#if GERMAN
        .description = COMPOUND_STRING(
            "Ein geheimnisvoller\n"
            "Ball."),
#else
        .description = COMPOUND_STRING(
            "A mysterious\n"
            "POKé BALL."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .secondaryId = BALL_GS,
        .iconPic = gItemIcon_GSBall,
        .iconPalette = gItemIconPalette_GSBall,
    },

    [ITEM_FERTILIZER] =
    {
#if GERMAN
        .name = ITEM_NAME("Wachsmulch"),
        .pluralName = ITEM_PLURAL_NAME("Wachsmulche"),
#else
        .name = ITEM_NAME("GROWTH MULCH"),
#endif
        .price = 2500,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Dünger, der das\n"
            "Wachstum von Bee-\n"
            "ren beschleunigt."),
#else
            "A fertilizer that\n"
            "accelerates the\n"
            "growth of Berries."),
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_EXP_SHARE_SMALL] =
    {
#if GERMAN
        .name = ITEM_NAME("Kleiner EP-Teiler"),
#else
        .name = ITEM_NAME("EXP. SHARE S"),
#endif
        .price = 6000,
        .holdEffect = HOLD_EFFECT_EXP_SHARE,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) teilt\n"
            "die Kampf-EP."),
#else
            "A held item that\n"
            "gets Exp. Points\n"
            "from battles."),
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ExpShare,
        .iconPalette = gItemIconPalette_ExpShare,
    },

    [ITEM_HEALING_HEART] =
    {
#if GERMAN
        .name = ITEM_NAME("Heilendes Herz"),
#else
        .name = ITEM_NAME("HEALING HEART"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Herz, das im Feld\n"
            "das ganze Team\n"
            "heilt."),
#else
            "A heart that heals\n"
            "your party when\n"
            "used in the field."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HealingHeart,
        .iconPalette = gItemIconPalette_HealingHeart,
    },

    [ITEM_INFINITE_REPEL] =
    {
#if GERMAN
        .name = ITEM_NAME("Dauerschutz"),
#else
        .name = ITEM_NAME("INFIN. REPEL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Hält dauerhaft\n"
            "schwache, wilde\n"
            "Pokémon ab."),
#else
            "An item that repels\n"
            "weak Pokémon\n"
            "permanently."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_INFINITE_RARE_CANDIES] =
    {
#if GERMAN
        .name = ITEM_NAME("Sonderbonbon-Box"),
#else
        .name = ITEM_NAME("RARECANDY BOX"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schachtel mit\n"
            "Sonderbonbons, die\n"
            "nie leer wird."),
#else
            "A box of Rare Candy\n"
            "that never runs\n"
            "out."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_InfiniteRareCandies,
        .iconPic = gItemIcon_RareCandy,
        .iconPalette = gItemIconPalette_RareCandy,
    },

    [ITEM_CLEAR_BELL] =
    {
#if GERMAN
        .name = ITEM_NAME("Klarglocke"),
#else
        .name = ITEM_NAME("CLEAR BELL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt ein\n"
            "angenehmes Läuten."),
#else
            "A bell that makes a\n"
            "clear, pure sound.\n"
            "It calms Pokémon."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_ClearBell,
        .iconPalette = gItemIconPalette_ClearBell,
    },

    [ITEM_LOST_ITEM] =
    {
#if GERMAN
        .name = ITEM_NAME("Fundsache"),
#else
        .name = ITEM_NAME("LOST ITEM"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Poképuppe der\n"
            "Nachahmerin."),
#else
            "An item lost by a\n"
            "girl in Saffron\n"
            "City."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_LostItem,
        .iconPalette = gItemIconPalette_LostItem,
    },

    [ITEM_MACHINE_PART] =
    {
#if GERMAN
        .name = ITEM_NAME("Spule"),
#else
        .name = ITEM_NAME("MACHINE PART"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Spule für das\n"
            "Kraftwerk."),
#else
            "A part needed to\n"
            "repair the Power\n"
            "Plant generator."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MachinePart,
        .iconPalette = gItemIconPalette_MachinePart,
    },

    [ITEM_MYSTERY_EGG] =
    {
#if GERMAN
        .name = ITEM_NAME("Rätsel-Ei"),
#else
        .name = ITEM_NAME("MYSTERY EGG"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein Ei von Mr.\n"
            "Pokémon."),
#else
            "An Egg obtained\n"
            "from Mr. Pokémon.\n"
            "Give it to Elm."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_MysteryEgg,
        .iconPalette = gItemIconPalette_MysteryEgg,
    },

    [ITEM_PASS] =
    {
#if GERMAN
        .name = ITEM_NAME("Fahrschein"),
#else
        .name = ITEM_NAME("PASS"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ticket für\n"
            "Magnetzug."),
#else
            "A pass for the\n"
            "Magnet Train between\n"
            "Goldenrod and Saffron."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_HnsPass,
        .iconPalette = gItemIconPalette_HnsPass,
    },

    [ITEM_RAINBOW_WING] =
    {
#if GERMAN
        .name = ITEM_NAME("Buntschwinge"),
#else
        .name = ITEM_NAME("RAINBOW WING"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Mystische\n"
            "Regenbogen-Feder."),
#else
            "A mystical feather\n"
            "of rainbow colors.\n"
            "It is sacred."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RainbowWing,
        .iconPalette = gItemIconPalette_RainbowWing,
    },

    [ITEM_RED_SCALE] =
    {
#if GERMAN
        .name = ITEM_NAME("Rote Haut"),
#else
        .name = ITEM_NAME("RED SCALE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Haut vom roten\n"
            "Garados."),
#else
            "A scale from the\n"
            "red Gyarados at\n"
            "the Lake of Rage."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_RedScale,
        .iconPalette = gItemIconPalette_RedScale,
    },

    [ITEM_SECRET_POTION] =
    {
#if GERMAN
        .name = ITEM_NAME("Geheimtrank"),
#else
        .name = ITEM_NAME("SECRETPOTION"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Heilt jedes Pokémon\n"
            "vollständig."),
#else
            "A secret medicine\n"
            "made in Cianwood\n"
            "City pharmacy."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SecretPotion,
        .iconPalette = gItemIconPalette_SecretPotion,
    },

    [ITEM_SILVER_WING] =
    {
#if GERMAN
        .name = ITEM_NAME("Silberflügel"),
#else
        .name = ITEM_NAME("SILVER WING"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine seltsame\n"
            "silberne Feder."),
#else
            "A mystical silver\n"
            "feather. It is said\n"
            "to summon Lugia."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SilverWing,
        .iconPalette = gItemIconPalette_SilverWing,
    },

    [ITEM_TIDAL_BELL] =
    {
#if GERMAN
        .name = ITEM_NAME("Gischtglocke"),
#else
        .name = ITEM_NAME("TIDAL BELL"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Erzeugt ein\n"
            "hallendes Läuten."),
#else
            "Bell that produces\n"
            "an echoing sound\n"
            "that calls Lugia."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_TidalBell,
        .iconPalette = gItemIconPalette_TidalBell,
    },

    [ITEM_RADIO] =
    {
#if GERMAN
        .name = ITEM_NAME("Radio"),
#else
        .name = ITEM_NAME("RADIO"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein tragbares\n"
            "Radio."),
#else
            "A portable radio\n"
            "that picks up\n"
            "various channels."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Radio,
        .iconPalette = gItemIconPalette_Radio,
    },

    [ITEM_SQUIRT_BOTTLE] =
    {
#if GERMAN
        .name = ITEM_NAME("Schiggykanne"),
#else
        .name = ITEM_NAME("SQUIRTBOTTLE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Kanne, um\n"
            "Bäume zu wässern."),
#else
            "A bottle for\n"
            "watering plants\n"
            "and Sudowoodo."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_FIELD,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_SquirtBottle,
        .iconPalette = gItemIconPalette_SquirtBottle,
    },

    [ITEM_ROOM_1_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("K1-Schlüssel"),
#else
        .name = ITEM_NAME("RM. 1 KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel zur Tür\n"
            "einer Kabine auf\n"
            "dem Schiffswrack."),
#else
            "A key to a room\n"
            "in the Underground\n"
            "Warehouse."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room1Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_ROOM_2_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("K2-Schlüssel"),
#else
        .name = ITEM_NAME("RM. 2 KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel zur Tür\n"
            "einer Kabine auf\n"
            "dem Schiffswrack."),
#else
            "A key to a room\n"
            "in the Underground\n"
            "Warehouse."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room2Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_ROOM_4_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("K4-Schlüssel"),
#else
        .name = ITEM_NAME("RM. 4 KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel zur Tür\n"
            "einer Kabine auf\n"
            "dem Schiffswrack."),
#else
            "A key to a room\n"
            "in the Underground\n"
            "Warehouse."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room4Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_ROOM_6_KEY] =
    {
#if GERMAN
        .name = ITEM_NAME("K6-Schlüssel"),
#else
        .name = ITEM_NAME("RM. 6 KEY"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Schlüssel zur Tür\n"
            "einer Kabine auf\n"
            "dem Schiffswrack."),
#else
            "A key to a room\n"
            "in the Underground\n"
            "Warehouse."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_Room6Key,
        .iconPalette = gItemIconPalette_Key,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
#if GERMAN
        .name = ITEM_NAME("Tsitrubeere"),
        .pluralName = ITEM_PLURAL_NAME("Tsitrubeeren"),
#else
        .name = ITEM_NAME("SITRUS BERRY"),
#endif
        .price = 20,
        .holdEffect = HOLD_EFFECT_RESTORE_HP,
        .holdEffectParam = 30,
        .description = COMPOUND_STRING(
#if GERMAN
            "Item (Tragen) füllt\n"
            "KP um 30 Punkte\n"
            "auf."),
#else
            "A hold item. Restores\n"
            "the holder's HP by\n"
            "30 points."),
#endif
        .pocket = POCKET_BERRIES,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .name = ITEM_NAME("????????"),
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein nicht\n"
            "verwendeter\n"
            "Artikelplatzhalter."),
#else
            "An unused item\n"
            "placeholder."),
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .name = ITEM_NAME("????????"),
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Ein nicht\n"
            "verwendeter\n"
            "Artikelplatzhalter."),
#else
            "An unused item\n"
            "placeholder."),
#endif
        .pocket = POCKET_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_QuestionMark,
        .iconPalette = gItemIconPalette_QuestionMark,
    },

    [ITEM_AZURE_FLUTE] =
    {
#if GERMAN
        .name = ITEM_NAME("Azurflöte"),
#else
        .name = ITEM_NAME("AZURE FLUTE"),
#endif
        .price = 0,
        .description = COMPOUND_STRING(
#if GERMAN
            "Eine Flöte. Ihre\n"
            "Töne scheinen nicht\n"
            "von dieser Welt."),
#else
            "A flute that puts\n"
            "out a mystifying\n"
            "sound."),
#endif
        .importance = 1,
        .pocket = POCKET_KEY_ITEMS,
        .type = ITEM_USE_BAG_MENU,
        .fieldUseFunc = ItemUseOutOfBattle_CannotUse,
        .iconPic = gItemIcon_AzureFlute,
        .iconPalette = gItemIconPalette_AzureFlute,
    },
};

#undef ITEM_NAME
#undef ITEM_PLURAL_NAME
