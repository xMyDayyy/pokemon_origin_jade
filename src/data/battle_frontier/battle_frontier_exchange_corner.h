struct BPShopEntry
{
    u16 item;
    u16 bpCost;
};

static const struct BPShopEntry sBPVitaminShopEntries[] = {
    { ITEM_PROTEIN, 1 },
    { ITEM_CALCIUM, 1 },
    { ITEM_IRON,    1 },
    { ITEM_ZINC,    1 },
    { ITEM_CARBOS,  1 },
    { ITEM_HP_UP,   1 },
    { ITEM_PP_MAX,   5 },
    { ITEM_ABILITY_CAPSULE,   32 },
    { ITEM_ABILITY_PATCH,   64 },
    { ITEM_HEALTH_MOCHI,  1 },
    { ITEM_MUSCLE_MOCHI,  1 },
    { ITEM_RESIST_MOCHI,  1 },
    { ITEM_GENIUS_MOCHI,  1 },
    { ITEM_CLEVER_MOCHI,  1 },
    { ITEM_SWIFT_MOCHI,   1 },
    { ITEM_FRESH_START_MOCHI, 4 },
    { ITEM_EXP_CANDY_XS,  1 },
    { ITEM_EXP_CANDY_S,   2 },
    { ITEM_EXP_CANDY_M,   4 },
    { ITEM_EXP_CANDY_XL, 16 },
    { ITEM_NONE,    0 },
};

static const struct BPShopEntry sBPPowerShopEntries[] = {
    { ITEM_MACHO_BRACE, 64 },
    { ITEM_POWER_WEIGHT, 64 },
    { ITEM_POWER_BRACER, 64 },
    { ITEM_POWER_BELT, 64 },
    { ITEM_POWER_LENS, 64 },
    { ITEM_POWER_BAND, 64 },
    { ITEM_POWER_ANKLET, 64 },
    { ITEM_NONE,    0 },
};

static const struct BPShopEntry sBPHoldItemShopEntries[] = {
    { ITEM_LEFTOVERS,     48 },
    { ITEM_WHITE_HERB,    48 },
    { ITEM_QUICK_CLAW,    48 },
    { ITEM_MENTAL_HERB,   48 },
    { ITEM_BRIGHT_POWDER, 64 },
    { ITEM_CHOICE_BAND,   64 },
    { ITEM_KINGS_ROCK,    64 },
    { ITEM_FOCUS_BAND,    64 },
    { ITEM_SCOPE_LENS,    64 },
    { ITEM_MUSCLE_BAND,    64 },
    { ITEM_WISE_GLASSES,    64 },
    { ITEM_LIFE_ORB,    64 },
    { ITEM_CHOICE_SPECS,    64 },
    { ITEM_CHOICE_SCARF,    64 },
    { ITEM_FOCUS_SASH,    64 },
    { ITEM_ASSAULT_VEST,    64 },
    { ITEM_NONE,           0 },
};

static const struct BPShopEntry sBPHoldItemShopEntries2[] = {
   { ITEM_EVIOLITE,    64 },
    { ITEM_EXPERT_BELT,    64 },
    { ITEM_ROCKY_HELMET,    64 },
    { ITEM_HEAVY_DUTY_BOOTS,    64 },
    { ITEM_WEAKNESS_POLICY,    64 },
    { ITEM_AIR_BALLOON,    64 },
    { ITEM_RED_CARD,    64 },
    { ITEM_EJECT_BUTTON,    64 },
    { ITEM_METRONOME,    64 },
    { ITEM_FLAME_ORB,    64 },
    { ITEM_TOXIC_ORB,    64 },
    { ITEM_LUCKY_EGG,    64 },
    { ITEM_WIDE_LENS,    64 },
    { ITEM_ZOOM_LENS,    64 },
    { ITEM_MACHO_BRACE,    64 },
    { ITEM_WHITE_HERB,    64 },
    { ITEM_MENTAL_HERB,    64 },
    { ITEM_FLOAT_STONE,      32 },
    { ITEM_RING_TARGET,      32 },
    { ITEM_BINDING_BAND,     32 },
    { ITEM_ROOM_SERVICE,     32 },
    { ITEM_SAFETY_GOGGLES,   48 },
    { ITEM_PROTECTIVE_PADS,  48 },
    { ITEM_THROAT_SPRAY,     48 },
    { ITEM_EJECT_PACK,       48 },
    { ITEM_BLUNDER_POLICY,   48 },
    { ITEM_UTILITY_UMBRELLA, 48 },
    { ITEM_ABILITY_SHIELD,   48 },
    { ITEM_NONE,           0 },
};

// Gems, seeds and newer hold items that have no other source (D-059).
static const struct BPShopEntry UNUSED sBPHoldItemShopEntries3[] = {
    { ITEM_NORMAL_GEM,       16 },
    { ITEM_FIRE_GEM,         16 },
    { ITEM_WATER_GEM,        16 },
    { ITEM_ELECTRIC_GEM,     16 },
    { ITEM_GRASS_GEM,        16 },
    { ITEM_ICE_GEM,          16 },
    { ITEM_FIGHTING_GEM,     16 },
    { ITEM_POISON_GEM,       16 },
    { ITEM_GROUND_GEM,       16 },
    { ITEM_FLYING_GEM,       16 },
    { ITEM_PSYCHIC_GEM,      16 },
    { ITEM_BUG_GEM,          16 },
    { ITEM_ROCK_GEM,         16 },
    { ITEM_GHOST_GEM,        16 },
    { ITEM_DRAGON_GEM,       16 },
    { ITEM_DARK_GEM,         16 },
    { ITEM_STEEL_GEM,        16 },
    { ITEM_FAIRY_GEM,        16 },
    { ITEM_ELECTRIC_SEED,    32 },
    { ITEM_PSYCHIC_SEED,     32 },
    { ITEM_MISTY_SEED,       32 },
    { ITEM_GRASSY_SEED,      32 },
    { ITEM_TERRAIN_EXTENDER, 48 },
    { ITEM_ADRENALINE_ORB,   32 },
    { ITEM_CLEAR_AMULET,     64 },
    { ITEM_PUNCHING_GLOVE,   64 },
    { ITEM_COVERT_CLOAK,     64 },
    { ITEM_LOADED_DICE,      64 },
    { ITEM_NONE,           0 },
};

#if IS_HNS
static const struct BPShopEntry sBPDecor1ShopEntries[] = {
    { DECOR_KISS_POSTER,    48 },
    { DECOR_KISS_CUSHION,   48 },
    { DECOR_SMOOCHUM_DOLL,  48 },
    { DECOR_TOGEPI_DOLL,    48 },
    { DECOR_MEOWTH_DOLL,    48 },
    { DECOR_CLEFAIRY_DOLL,  48 },
    { DECOR_DITTO_DOLL,     48 },
    { DECOR_CYNDAQUIL_DOLL, 80 },
    { DECOR_CHIKORITA_DOLL, 80 },
    { DECOR_TOTODILE_DOLL,  80 },
    { ITEM_NONE,              0 },
};
#else
static const struct BPShopEntry sBPDecor1ShopEntries[] = {
    { DECOR_TREECKO_DOLL,   48 },
    { DECOR_TORCHIC_DOLL,   48 },
    { DECOR_MUDKIP_DOLL,    48 },
    { DECOR_TOGEPI_DOLL,    48 },
    { DECOR_MEOWTH_DOLL,    48 },
    { DECOR_CLEFAIRY_DOLL,  48 },
    { DECOR_DITTO_DOLL,     48 },
    { DECOR_CYNDAQUIL_DOLL, 80 },
    { DECOR_CHIKORITA_DOLL, 80 },
    { DECOR_TOTODILE_DOLL,  80 },
    { ITEM_NONE,              0 },
};
#endif

static const struct BPShopEntry sBPDecor2ShopEntries[] = {
    { DECOR_LAPRAS_DOLL,    128 },
    { DECOR_VENUSAUR_DOLL,  256 },
    { DECOR_CHARIZARD_DOLL, 256 },
    { DECOR_BLASTOISE_DOLL, 256 },
    { ITEM_NONE,              0 },
};

static const struct BPShopEntry sBPPokeBallShopEntries[] = {
    { ITEM_NET_BALL,     1 },
    { ITEM_DIVE_BALL,    1 },
    { ITEM_NEST_BALL,    1 },
    { ITEM_REPEAT_BALL,  1 },
    { ITEM_TIMER_BALL,   1 },
    { ITEM_LUXURY_BALL,  1 },
    { ITEM_NONE,         0 },
};

static const u16 sFrontierExchangeCorner_Decor1[] =
{
    DECOR_KISS_POSTER,
    DECOR_KISS_CUSHION,
    DECOR_SMOOCHUM_DOLL,
    DECOR_TOGEPI_DOLL,
    DECOR_MEOWTH_DOLL,
    DECOR_CLEFAIRY_DOLL,
    DECOR_DITTO_DOLL,
    DECOR_CYNDAQUIL_DOLL,
    DECOR_CHIKORITA_DOLL,
    DECOR_TOTODILE_DOLL,
    ITEM_LIST_END
};

static const u16 sFrontierExchangeCorner_Decor2[] =
{
    DECOR_LAPRAS_DOLL,
    DECOR_SNORLAX_DOLL,
    DECOR_VENUSAUR_DOLL,
    DECOR_CHARIZARD_DOLL,
    DECOR_BLASTOISE_DOLL,
    ITEM_LIST_END
};

static const u16 sFrontierExchangeCorner_Vitamins[] =
{
    ITEM_PROTEIN,
    ITEM_CALCIUM,
    ITEM_IRON,
    ITEM_ZINC,
    ITEM_CARBOS,
    ITEM_HP_UP,
    ITEM_LIST_END
};

static const u16 sFrontierExchangeCorner_HoldItems[] =
{
    ITEM_LEFTOVERS,
    ITEM_WHITE_HERB,
    ITEM_QUICK_CLAW,
    ITEM_MENTAL_HERB,
    ITEM_BRIGHT_POWDER,
    ITEM_CHOICE_BAND,
    ITEM_KINGS_ROCK,
    ITEM_FOCUS_BAND,
    ITEM_SCOPE_LENS,
    ITEM_LIST_END
};

static const u8 *const sFrontierExchangeCorner_Decor1Descriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc,
    BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc,
    BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_TogepiDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_MeowthDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ClefairyDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_DittoDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CyndaquilDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ChikoritaDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_TotodileDollDesc,
    gText_Exit,
};

static const u8 *const sFrontierExchangeCorner_Decor2Descriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc,
    BattleFrontier_ExchangeServiceCorner_Text_LargeDollDesc,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_VitaminsDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_ProteinDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CalciumDesc,
    BattleFrontier_ExchangeServiceCorner_Text_IronDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ZincDesc,
    BattleFrontier_ExchangeServiceCorner_Text_CarbosDesc,
    BattleFrontier_ExchangeServiceCorner_Text_HPUpDesc,
    gText_Exit
};

static const u8 *const sFrontierExchangeCorner_HoldItemsDescriptions[] =
{
    BattleFrontier_ExchangeServiceCorner_Text_LeftoversDesc,
    BattleFrontier_ExchangeServiceCorner_Text_WhiteHerbDesc,
    BattleFrontier_ExchangeServiceCorner_Text_QuickClawDesc,
    BattleFrontier_ExchangeServiceCorner_Text_MentalHerbDesc,
    BattleFrontier_ExchangeServiceCorner_Text_BrightpowderDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ChoiceBandDesc,
    BattleFrontier_ExchangeServiceCorner_Text_KingsRockDesc,
    BattleFrontier_ExchangeServiceCorner_Text_FocusBandDesc,
    BattleFrontier_ExchangeServiceCorner_Text_ScopeLensDesc,
    gText_Exit
};
