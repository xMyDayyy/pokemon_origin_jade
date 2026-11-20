const struct EasyChatWordInfo gEasyChatGroup_Status[] = {
    [EC_INDEX(EC_WORD_DARK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Unlicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KEEN_EYE),
#else
        .text = COMPOUND_STRING("DARK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIR_LOCK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STENCH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Duftnote"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUTS),
#else
        .text = COMPOUND_STRING("STENCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALT_COLOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THICK_FAT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Speckschicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALT_COLOR),
#else
        .text = COMPOUND_STRING("THICK FAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARENA_TRAP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RAIN_DISH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Regengenuss"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUN_AWAY),
#else
        .text = COMPOUND_STRING("RAIN DISH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ARMOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRIZZLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Niesel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CUTENESS),
#else
        .text = COMPOUND_STRING("DRIZZLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAUTIFUL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ARENA_TRAP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ausweglos"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CUTE),
#else
        .text = COMPOUND_STRING("ARENA TRAP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAUTY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INTIMIDATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bedroher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WATER_VEIL),
#else
        .text = COMPOUND_STRING("INTIMIDATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLAZE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK_HEAD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Steinhaupt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ARENA_TRAP),
#else
        .text = COMPOUND_STRING("ROCK HEAD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Farbe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INTIMIDATE),
#else
        .text = COMPOUND_STRING("COLOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHLOROPHYLL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALT_COLOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Alt. farbe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIGHTNINGROD),
#else
        .text = COMPOUND_STRING("ALT. COLOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLEAR_BODY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROCK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gestein"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GROUND),
#else
        .text = COMPOUND_STRING("ROCK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOUD_NINE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEAUTIFUL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schön"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CUTE_CHARM),
#else
        .text = COMPOUND_STRING("BEAUTIFUL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEAUTY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schönheit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHLOROPHYLL),
#else
        .text = COMPOUND_STRING("BEAUTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLOR_CHANGE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AIR_LOCK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klimaschutz"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COOL),
#else
        .text = COMPOUND_STRING("AIR LOCK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMPOUNDEYES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PSYCHIC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Psycho"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COOLNESS),
#else
        .text = COMPOUND_STRING("PSYCHIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COOL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HYPER_CUTTER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Scherenmacht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OBLIVIOUS),
#else
        .text = COMPOUND_STRING("HYPER CUTTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COOLNESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIGHTING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kampf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRAGON),
#else
        .text = COMPOUND_STRING("FIGHTING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CUTE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHADOW_TAG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wegsperre"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STENCH),
#else
        .text = COMPOUND_STRING("SHADOW TAG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CUTE_CHARM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMART)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klug"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROUGHT),
#else
        .text = COMPOUND_STRING("SMART"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CUTENESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMARTNESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Klugheit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERENE_GRACE),
#else
        .text = COMPOUND_STRING("SMARTNESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAMP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPEED_BOOST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Temposchub"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ICE),
#else
        .text = COMPOUND_STRING("SPEED BOOST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DARK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COOL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Cool"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELECTRIC),
#else
        .text = COMPOUND_STRING("COOL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRAGON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COOLNESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Coolness"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ILLUMINATE),
#else
        .text = COMPOUND_STRING("COOLNESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRIZZLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATTLE_ARMOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kampfpanzer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRESSURE),
#else
        .text = COMPOUND_STRING("BATTLE ARMOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DROUGHT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CUTE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Anmutig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHED_SKIN),
#else
        .text = COMPOUND_STRING("CUTE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EARLY_BIRD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CUTENESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Anmut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMPOUNDEYES),
#else
        .text = COMPOUND_STRING("CUTENESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EFFECT_SPORE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STURDY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Robustheit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRACE),
#else
        .text = COMPOUND_STRING("STURDY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELECTRIC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SUCTION_CUPS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Saugnapf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLOR),
#else
        .text = COMPOUND_STRING("SUCTION CUPS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHTING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRASS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pflanze"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLOR_CHANGE),
#else
        .text = COMPOUND_STRING("GRASS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIRE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLEAR_BODY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Neutraltorso"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAMP),
#else
        .text = COMPOUND_STRING("CLEAR BODY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME_BODY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TORRENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sturzbach"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIRE),
#else
        .text = COMPOUND_STRING("TORRENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLASH_FIRE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GHOST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geist"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLASH_FIRE),
#else
        .text = COMPOUND_STRING("GHOST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLYING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ICE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Eis"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLAME_BODY),
#else
        .text = COMPOUND_STRING("ICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORECAST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GUTS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Adrenalin"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIMBER),
#else
        .text = COMPOUND_STRING("GUTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GHOST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ROUGH_SKIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rauhaut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLYING),
#else
        .text = COMPOUND_STRING("ROUGH SKIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRASS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHELL_ARMOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Panzerhaut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EARLY_BIRD),
#else
        .text = COMPOUND_STRING("SHELL ARMOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GROUND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL_CURE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Innere kraft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GHOST),
#else
        .text = COMPOUND_STRING("NATURAL CURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GUTS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAMP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Feuchtigkeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK),
#else
        .text = COMPOUND_STRING("DAMP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUGE_POWER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GROUND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Boden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POISON),
#else
        .text = COMPOUND_STRING("GROUND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUSTLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIMBER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Flexibilität"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POISON_POINT),
#else
        .text = COMPOUND_STRING("LIMBER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER_CUTTER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAGNET_PULL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Magnetfalle"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BLAZE),
#else
        .text = COMPOUND_STRING("MAGNET PULL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ICE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHITE_SMOKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pulverrauch"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WATER_ABSORB),
#else
        .text = COMPOUND_STRING("WHITE SMOKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ILLUMINATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SYNCHRONIZE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Synchro"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWARM),
#else
        .text = COMPOUND_STRING("SYNCHRONIZE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMMUNITY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERGROW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Notdünger"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMMUNITY),
#else
        .text = COMPOUND_STRING("OVERGROW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INNER_FOCUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SWIFT_SWIM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wassertempo"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL_CURE),
#else
        .text = COMPOUND_STRING("SWIFT SWIM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSOMNIA),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAND_STREAM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sandsturm"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSOMNIA),
#else
        .text = COMPOUND_STRING("SAND STREAM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INTIMIDATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAND_VEIL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sandschleier"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUG),
#else
        .text = COMPOUND_STRING("SAND VEIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KEEN_EYE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KEEN_EYE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Adlerauge"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FIGHTING),
#else
        .text = COMPOUND_STRING("KEEN EYE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEVITATE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INNER_FOCUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Konzentrator"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATTLE_ARMOR),
#else
        .text = COMPOUND_STRING("INNER FOCUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIGHTNINGROD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STATIC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Statik"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AIR_LOCK),
#else
        .text = COMPOUND_STRING("STATIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIMBER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TYPE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Typ"),
#else
        .text = COMPOUND_STRING("TYPE"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIQUID_OOZE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOUGH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Stark"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMART),
#else
        .text = COMPOUND_STRING("TOUGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGMA_ARMOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOUGHNESS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Stärke"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMARTNESS),
#else
        .text = COMPOUND_STRING("TOUGHNESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGNET_PULL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHED_SKIN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Expidermis"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INNER_FOCUS),
#else
        .text = COMPOUND_STRING("SHED SKIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MARVEL_SCALE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUGE_POWER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kraftkoloss"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUGE_POWER),
#else
        .text = COMPOUND_STRING("HUGE POWER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MINUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VOLT_ABSORB)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Voltabsorber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOUNDPROOF),
#else
        .text = COMPOUND_STRING("VOLT ABSORB"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL_CURE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WATER_ABSORB)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("H2o-Absorber"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGMA_ARMOR),
#else
        .text = COMPOUND_STRING("WATER ABSORB"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NORMAL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELECTRIC)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Elektro"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGNET_PULL),
#else
        .text = COMPOUND_STRING("ELECTRIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OBLIVIOUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORECAST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Prognose"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PURE_POWER),
#else
        .text = COMPOUND_STRING("FORECAST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERGROW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERENE_GRACE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Edelmut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MINUS),
#else
        .text = COMPOUND_STRING("SERENE GRACE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OWN_TEMPO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POISON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gift"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PICKUP),
#else
        .text = COMPOUND_STRING("POISON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PATTERN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POISON_POINT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Giftdorn"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VITAL_SPIRIT),
#else
        .text = COMPOUND_STRING("POISON POINT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PICKUP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRAGON)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Drachen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PATTERN),
#else
        .text = COMPOUND_STRING("DRAGON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PKRS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRACE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fährte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLEAR_BODY),
#else
        .text = COMPOUND_STRING("TRACE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLUS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OBLIVIOUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dösigkeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRIZZLE),
#else
        .text = COMPOUND_STRING("OBLIVIOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POISON),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUANT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schnarchnase"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NORMAL),
#else
        .text = COMPOUND_STRING("TRUANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POISON_POINT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUN_AWAY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Angsthase"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERGROW),
#else
        .text = COMPOUND_STRING("RUN AWAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRESSURE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STICKY_HOLD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wertehalter"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MARVEL_SCALE),
#else
        .text = COMPOUND_STRING("STICKY HOLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PSYCHIC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOUD_NINE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wolke sieben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHELL_ARMOR),
#else
        .text = COMPOUND_STRING("CLOUD NINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PURE_POWER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NORMAL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Normal"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRASS),
#else
        .text = COMPOUND_STRING("NORMAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RAIN_DISH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STEEL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Stahl"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLUS),
#else
        .text = COMPOUND_STRING("STEEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ILLUMINATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erleuchtung"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PKRS),
#else
        .text = COMPOUND_STRING("ILLUMINATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_HEAD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EARLY_BIRD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Frühwecker"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORECAST),
#else
        .text = COMPOUND_STRING("EARLY BIRD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROUGH_SKIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HUSTLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Übereifer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PSYCHIC),
#else
        .text = COMPOUND_STRING("HUSTLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUN_AWAY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHINE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Scheinen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHIELD_DUST),
#else
        .text = COMPOUND_STRING("SHINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAND_STREAM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLYING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fliegen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHITE_SMOKE),
#else
        .text = COMPOUND_STRING("FLYING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAND_VEIL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DROUGHT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Dürre"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROUGH_SKIN),
#else
        .text = COMPOUND_STRING("DROUGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERENE_GRACE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIGHTNINGROD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Blitzfänger"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RAIN_DISH),
#else
        .text = COMPOUND_STRING("LIGHTNINGROD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADOW_TAG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMPOUNDEYES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Facettenauge"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STURDY),
#else
        .text = COMPOUND_STRING("COMPOUNDEYES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHED_SKIN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MARVEL_SCALE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Notschutz"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAND_VEIL),
#else
        .text = COMPOUND_STRING("MARVEL SCALE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHELL_ARMOR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WONDER_GUARD)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wunderwache"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAND_STREAM),
#else
        .text = COMPOUND_STRING("WONDER GUARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHIELD_DUST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSOMNIA)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Insomnia"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUCTION_CUPS),
#else
        .text = COMPOUND_STRING("INSOMNIA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHINE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEVITATE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schwebe"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHINE),
#else
        .text = COMPOUND_STRING("LEVITATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMART),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Plus"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HYPER_CUTTER),
#else
        .text = COMPOUND_STRING("PLUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMARTNESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRESSURE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erzwinger"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUANT),
#else
        .text = COMPOUND_STRING("PRESSURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOUNDPROOF),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIQUID_OOZE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kloakensoße"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAUTIFUL),
#else
        .text = COMPOUND_STRING("LIQUID OOZE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPEED_BOOST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLOR_CHANGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Farbwechsel"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEAUTY),
#else
        .text = COMPOUND_STRING("COLOR CHANGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STATIC),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOUNDPROOF)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lärmschutz"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEVITATE),
#else
        .text = COMPOUND_STRING("SOUNDPROOF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STEEL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EFFECT_SPORE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sporenwirt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK_FAT),
#else
        .text = COMPOUND_STRING("EFFECT SPORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STENCH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PKRS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Pokérus"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EFFECT_SPORE),
#else
        .text = COMPOUND_STRING("{PK}RS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STICKY_HOLD),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FIRE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Feuer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STEEL),
#else
        .text = COMPOUND_STRING("FIRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STURDY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLAME_BODY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Flammkörper"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOUGH),
#else
        .text = COMPOUND_STRING("FLAME BODY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SUCTION_CUPS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MINUS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Minus"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOUGHNESS),
#else
        .text = COMPOUND_STRING("MINUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWARM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OWN_TEMPO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Tempomacher"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STATIC),
#else
        .text = COMPOUND_STRING("OWN TEMPO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWIFT_SWIM),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAGMA_ARMOR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Magmapanzer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ROCK_HEAD),
#else
        .text = COMPOUND_STRING("MAGMA ARMOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SYNCHRONIZE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WATER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wasser"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TORRENT),
#else
        .text = COMPOUND_STRING("WATER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THICK_FAT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WATER_VEIL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aquahülle"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SYNCHRONIZE),
#else
        .text = COMPOUND_STRING("WATER VEIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TORRENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Käfer"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OWN_TEMPO),
#else
        .text = COMPOUND_STRING("BUG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOUGH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SWARM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hexaplaga"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPEED_BOOST),
#else
        .text = COMPOUND_STRING("SWARM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOUGHNESS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CUTE_CHARM)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Charmebolzen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TYPE),
#else
        .text = COMPOUND_STRING("CUTE CHARM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRACE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMMUNITY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Immunität"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HUSTLE),
#else
        .text = COMPOUND_STRING("IMMUNITY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUANT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BLAZE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Großbrand"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DARK),
#else
        .text = COMPOUND_STRING("BLAZE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TYPE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PICKUP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mitnahme"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VOLT_ABSORB),
#else
        .text = COMPOUND_STRING("PICKUP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VITAL_SPIRIT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PATTERN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Muster"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WATER),
#else
        .text = COMPOUND_STRING("PATTERN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VOLT_ABSORB),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLASH_FIRE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Feuerfänger"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWIFT_SWIM),
#else
        .text = COMPOUND_STRING("FLASH FIRE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WATER),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VITAL_SPIRIT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Munterkeit"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHADOW_TAG),
#else
        .text = COMPOUND_STRING("VITAL SPIRIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WATER_ABSORB),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHLOROPHYLL)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Chlorophyll"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STICKY_HOLD),
#else
        .text = COMPOUND_STRING("CHLOROPHYLL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WATER_VEIL),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PURE_POWER)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Mentalkraft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOUD_NINE),
#else
        .text = COMPOUND_STRING("PURE POWER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHITE_SMOKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHIELD_DUST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Puderabwehr"),
#else
        .text = COMPOUND_STRING("SHIELD DUST"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_WONDER_GUARD),
        .enabled = TRUE,
    },
};
