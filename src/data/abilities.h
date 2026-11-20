const struct AbilityInfo gAbilitiesInfo[ABILITIES_COUNT] =
{
    [ABILITY_NONE] =
    {
        .name = _("-------"),
#if GERMAN
        .description = COMPOUND_STRING("Keine Spezial-Fähigkeit."),
#else
        .description = COMPOUND_STRING("No special ability."),
#endif
        .aiRating = 0,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_STENCH] =
    {
#if GERMAN
        .name = _("Duftnote"),
        .description = COMPOUND_STRING("Wehrt wilde Pokémon ab."),
#else
        .name = _("STENCH"),
        .description = COMPOUND_STRING("May cause a foe to flinch."),
#endif
        .aiRating = 1,
    },

    [ABILITY_DRIZZLE] =
    {
#if GERMAN
        .name = _("Niesel"),
        .description = COMPOUND_STRING("Ruft im Kampf Regen herbei."),
#else
        .name = _("DRIZZLE"),
        .description = COMPOUND_STRING("Summons rain in battle."),
#endif
        .aiRating = 9,
    },

    [ABILITY_SPEED_BOOST] =
    {
#if GERMAN
        .name = _("Temposchub"),
        .description = COMPOUND_STRING("Erhöht Init. nach und nach."),
#else
        .name = _("SPEED BOOST"),
        .description = COMPOUND_STRING("Gradually boosts Speed."),
#endif
        .aiRating = 9,
    },

    [ABILITY_BATTLE_ARMOR] =
    {
#if GERMAN
        .name = _("Kampfpanzer"),
        .description = COMPOUND_STRING("Wehrt Volltreffer ab."),
#else
        .name = _("BATTLE ARMOR"),
        .description = COMPOUND_STRING("Blocks critical hits."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_STURDY] =
    {
#if GERMAN
        .name = _("Robustheit"),
        .description = COMPOUND_STRING("Keine 1-Treffer-K.O.-Att."),
#else
        .name = _("STURDY"),
        .description = COMPOUND_STRING("Negates 1-hit KO attacks."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DAMP] =
    {
#if GERMAN
        .name = _("Feuchtigkeit"),
        .description = COMPOUND_STRING("Gegen Selbstzerstörung."),
#else
        .name = _("DAMP"),
        .description = COMPOUND_STRING("Prevents self-destruction."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_LIMBER] =
    {
#if GERMAN
        .name = _("Flexibilität"),
        .description = COMPOUND_STRING("Verhindert Paralyse."),
#else
        .name = _("LIMBER"),
        .description = COMPOUND_STRING("Prevents paralysis."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SAND_VEIL] =
    {
#if GERMAN
        .name = _("Sandschleier"),
        .description = COMPOUND_STRING("Erh. Fluchtw. i. Sandsturm."),
#else
        .name = _("SAND VEIL"),
        .description = COMPOUND_STRING("Ups evasion in a sandstorm."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_STATIC] =
    {
#if GERMAN
        .name = _("Statik"),
        .description = COMPOUND_STRING("Paralysiert bei Berührung."),
#else
        .name = _("STATIC"),
        .description = COMPOUND_STRING("Paralyzes on contact."),
#endif
        .aiRating = 4,
    },

    [ABILITY_VOLT_ABSORB] =
    {
#if GERMAN
        .name = _("Voltabsorber"),
        .description = COMPOUND_STRING("Wandelt Elektriz. in KP um."),
#else
        .name = _("VOLT ABSORB"),
        .description = COMPOUND_STRING("Turns electricity into HP."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_WATER_ABSORB] =
    {
#if GERMAN
        .name = _("H2O-Absorber"),
        .description = COMPOUND_STRING("Wandelt Wasser in KP um."),
#else
        .name = _("WATER ABSORB"),
        .description = COMPOUND_STRING("Changes water into HP."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_OBLIVIOUS] =
    {
#if GERMAN
        .name = _("Dösigkeit"),
        .description = COMPOUND_STRING("Verhindert Anziehung."),
#else
        .name = _("OBLIVIOUS"),
        .description = COMPOUND_STRING("Prevents attraction."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_CLOUD_NINE] =
    {
#if GERMAN
        .name = _("Wolke Sieben"),
        .description = COMPOUND_STRING("Keine Wetter-Effekte."),
#else
        .name = _("CLOUD NINE"),
        .description = COMPOUND_STRING("Negates weather effects."),
#endif
        .aiRating = 5,
    },

    [ABILITY_COMPOUND_EYES] =
    {
#if GERMAN
        .name = _("Facettenauge"),
        .description = COMPOUND_STRING("Steigert Genauigkeit."),
#else
        .name = _("COMPOUND EYES"),
        .description = COMPOUND_STRING("Raises accuracy."),
#endif
        .aiRating = 7,
    },

    [ABILITY_INSOMNIA] =
    {
#if GERMAN
        .name = _("Insomnia"),
        .description = COMPOUND_STRING("Verhindert Einschlafen."),
#else
        .name = _("INSOMNIA"),
        .description = COMPOUND_STRING("Prevents sleep."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_COLOR_CHANGE] =
    {
#if GERMAN
        .name = _("Farbwechsel"),
        .description = COMPOUND_STRING("Ändert Att.-Typ d. Gegners."),
#else
        .name = _("COLOR CHANGE"),
        .description = COMPOUND_STRING("Changes type to foe's move."),
#endif
        .aiRating = 2,
    },

    [ABILITY_IMMUNITY] =
    {
#if GERMAN
        .name = _("Immunität"),
        .description = COMPOUND_STRING("Verhindert Vergiftungen."),
#else
        .name = _("IMMUNITY"),
        .description = COMPOUND_STRING("Prevents poisoning."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_FLASH_FIRE] =
    {
#if GERMAN
        .name = _("Feuerfänger"),
        .description = COMPOUND_STRING("Steigt, wenn v. Feuer getr."),
#else
        .name = _("FLASH FIRE"),
        .description = COMPOUND_STRING("Powers up if hit by fire."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SHIELD_DUST] =
    {
#if GERMAN
        .name = _("Puderabwehr"),
        .description = COMPOUND_STRING("Gegen Zusatz-Effekte."),
#else
        .name = _("SHIELD DUST"),
        .description = COMPOUND_STRING("Prevents added effects."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_OWN_TEMPO] =
    {
#if GERMAN
        .name = _("Tempomacher"),
        .description = COMPOUND_STRING("Verhindert Verwirrung."),
#else
        .name = _("OWN TEMPO"),
        .description = COMPOUND_STRING("Prevents confusion."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SUCTION_CUPS] =
    {
#if GERMAN
        .name = _("Saugnapf"),
        .description = COMPOUND_STRING("Verankert den Körper."),
#else
        .name = _("SUCTION CUPS"),
        .description = COMPOUND_STRING("Firmly anchors the body."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_INTIMIDATE] =
    {
#if GERMAN
        .name = _("Bedroher"),
        .description = COMPOUND_STRING("Senkt Angr. des Gegners."),
#else
        .name = _("INTIMIDATE"),
        .description = COMPOUND_STRING("Lowers the foe's Attack."),
#endif
        .aiRating = 7,
    },

    [ABILITY_SHADOW_TAG] =
    {
#if GERMAN
        .name = _("Wegsperre"),
        .description = COMPOUND_STRING("Hindert Gegner an Flucht."),
#else
        .name = _("SHADOW TAG"),
        .description = COMPOUND_STRING("Prevents the foe's escape."),
#endif
        .aiRating = 10,
    },

    [ABILITY_ROUGH_SKIN] =
    {
#if GERMAN
        .name = _("Rauhaut"),
        .description = COMPOUND_STRING("Verletzt bei Berührung."),
#else
        .name = _("ROUGH SKIN"),
        .description = COMPOUND_STRING("Hurts to touch."),
#endif
        .aiRating = 6,
    },

    [ABILITY_WONDER_GUARD] =
    {
#if GERMAN
        .name = _("Wunderwache"),
        .description = COMPOUND_STRING("Nur sehr eff. Treff. schad."),
#else
        .name = _("WONDER GUARD"),
        .description = COMPOUND_STRING("Only “Supereffective” hits."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_LEVITATE] =
    {
#if GERMAN
        .name = _("Schwebe"),
        .description = COMPOUND_STRING("Kein Treffer b. Boden-Att."),
#else
        .name = _("LEVITATE"),
        .description = COMPOUND_STRING("Not hit by Ground attacks."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EFFECT_SPORE] =
    {
#if GERMAN
        .name = _("Sporenwirt"),
        .description = COMPOUND_STRING("Gibt bei Kontakt Sporen ab."),
#else
        .name = _("EFFECT SPORE"),
        .description = COMPOUND_STRING("Leaves spores on contact."),
#endif
        .aiRating = 4,
    },

    [ABILITY_SYNCHRONIZE] =
    {
#if GERMAN
        .name = _("Synchro"),
        .description = COMPOUND_STRING("Gibt Stat.-Probleme weiter."),
#else
        .name = _("SYNCHRONIZE"),
        .description = COMPOUND_STRING("Passes on status problems."),
#endif
        .aiRating = 4,
    },

    [ABILITY_CLEAR_BODY] =
    {
#if GERMAN
        .name = _("Neutraltorso"),
        .description = COMPOUND_STRING("Verhindert Fähigk.-Reduk."),
#else
        .name = _("CLEAR BODY"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_NATURAL_CURE] =
    {
#if GERMAN
        .name = _("Innere Kraft"),
        .description = COMPOUND_STRING("Heilt bei Austausch."),
#else
        .name = _("NATURAL CURE"),
        .description = COMPOUND_STRING("Heals upon switching out."),
#endif
        .aiRating = 7,
    },

    [ABILITY_LIGHTNING_ROD] =
    {
#if GERMAN
        .name = _("Blitzfänger"),
        .description = COMPOUND_STRING("Zieht Elektro-Attacken an."),
#else
        .name = _("LIGHTNING ROD"),
        .description = COMPOUND_STRING("Draws electrical moves."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_SERENE_GRACE] =
    {
#if GERMAN
        .name = _("Edelmut"),
        .description = COMPOUND_STRING("Verstärkt Zusatz-Effekte."),
#else
        .name = _("SERENE GRACE"),
        .description = COMPOUND_STRING("Promotes added effects."),
#endif
        .aiRating = 8,
    },

    [ABILITY_SWIFT_SWIM] =
    {
#if GERMAN
        .name = _("Wassertempo"),
        .description = COMPOUND_STRING("Steigert Init. bei Regen."),
#else
        .name = _("SWIFT SWIM"),
        .description = COMPOUND_STRING("Raises Speed in rain."),
#endif
        .aiRating = 6,
    },

    [ABILITY_CHLOROPHYLL] =
    {
#if GERMAN
        .name = _("Chlorophyll"),
        .description = COMPOUND_STRING("Init. + bei Sonnenschein."),
#else
        .name = _("CHLOROPHYLL"),
        .description = COMPOUND_STRING("Raises Speed in sunshine."),
#endif
        .aiRating = 6,
    },

    [ABILITY_ILLUMINATE] =
    {
#if GERMAN
        .name = _("Erleuchtung"),
        .description = COMPOUND_STRING("Mehr Pkmn-Begegnungen."),
#else
        .name = _("ILLUMINATE"),
        .description = COMPOUND_STRING("Encounter rate increases."),
#endif
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_TRACE] =
    {
#if GERMAN
        .name = _("Fährte"),
        .description = COMPOUND_STRING("Kopiert Spezial-Attacke."),
#else
        .name = _("TRACE"),
        .description = COMPOUND_STRING("Copies special ability."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE, //B_UPDATED_ABILITY_DATA >= GEN_4
    },

    [ABILITY_HUGE_POWER] =
    {
#if GERMAN
        .name = _("Kraftkoloss"),
        .description = COMPOUND_STRING("Steigert Angr."),
#else
        .name = _("HUGE POWER"),
        .description = COMPOUND_STRING("Raises Attack."),
#endif
        .aiRating = 10,
    },

    [ABILITY_POISON_POINT] =
    {
#if GERMAN
        .name = _("Giftdorn"),
        .description = COMPOUND_STRING("Vergiftet bei Berührung."),
#else
        .name = _("POISON POINT"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
#endif
        .aiRating = 4,
    },

    [ABILITY_INNER_FOCUS] =
    {
#if GERMAN
        .name = _("Konzentrator"),
        .description = COMPOUND_STRING("Verhindert Zurückschreck."),
#else
        .name = _("INNER FOCUS"),
        .description = COMPOUND_STRING("Prevents flinching."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MAGMA_ARMOR] =
    {
#if GERMAN
        .name = _("Magmapanzer"),
        .description = COMPOUND_STRING("Verhindert Einfrieren."),
#else
        .name = _("MAGMA ARMOR"),
        .description = COMPOUND_STRING("Prevents freezing."),
#endif
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_WATER_VEIL] =
    {
#if GERMAN
        .name = _("Aquahülle"),
        .description = COMPOUND_STRING("Verhindert Verbrennungen."),
#else
        .name = _("WATER VEIL"),
        .description = COMPOUND_STRING("Prevents burns."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_MAGNET_PULL] =
    {
#if GERMAN
        .name = _("Magnetfalle"),
        .description = COMPOUND_STRING("Fängt Stahl-Pokémon."),
#else
        .name = _("MAGNET PULL"),
        .description = COMPOUND_STRING("Traps Steel-type Pokémon."),
#endif
        .aiRating = 9,
    },

    [ABILITY_SOUNDPROOF] =
    {
#if GERMAN
        .name = _("Lärmschutz"),
        .description = COMPOUND_STRING("Immun gg. Lärm-Attacken."),
#else
        .name = _("SOUNDPROOF"),
        .description = COMPOUND_STRING("Avoids sound-based moves."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_RAIN_DISH] =
    {
#if GERMAN
        .name = _("Regengenuss"),
        .description = COMPOUND_STRING("KP-Anstieg bei Regen."),
#else
        .name = _("RAIN DISH"),
        .description = COMPOUND_STRING("Slight HP recovery in rain."),
#endif
        .aiRating = 3,
    },

    [ABILITY_SAND_STREAM] =
    {
#if GERMAN
        .name = _("Sandsturm"),
        .description = COMPOUND_STRING("Erzeugt einen Sandsturm."),
#else
        .name = _("SAND STREAM"),
        .description = COMPOUND_STRING("Summons a sandstorm."),
#endif
        .aiRating = 9,
    },

    [ABILITY_PRESSURE] =
    {
#if GERMAN
        .name = _("Erzwinger"),
        .description = COMPOUND_STRING("Steigert AP des Gegners."),
#else
        .name = _("PRESSURE"),
        .description = COMPOUND_STRING("Raises foe's PP usage."),
#endif
        .aiRating = 5,
    },

    [ABILITY_THICK_FAT] =
    {
#if GERMAN
        .name = _("Speckschicht"),
        .description = COMPOUND_STRING("Schutz vor Hitze und Kälte."),
#else
        .name = _("THICK FAT"),
        .description = COMPOUND_STRING("Heat-and-cold protection."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_EARLY_BIRD] =
    {
#if GERMAN
        .name = _("Frühwecker"),
        .description = COMPOUND_STRING("Schnelles Aufwachen."),
#else
        .name = _("EARLY BIRD"),
        .description = COMPOUND_STRING("Awakens quickly from sleep."),
#endif
        .aiRating = 4,
    },

    [ABILITY_FLAME_BODY] =
    {
#if GERMAN
        .name = _("Flammkörper"),
        .description = COMPOUND_STRING("Verbrennt bei Berührung."),
#else
        .name = _("FLAME BODY"),
        .description = COMPOUND_STRING("Burns the foe on contact."),
#endif
        .aiRating = 4,
    },

    [ABILITY_RUN_AWAY] =
    {
#if GERMAN
        .name = _("Angsthase"),
        .description = COMPOUND_STRING("Erleichtert das Entkommen."),
#else
        .name = _("RUN AWAY"),
        .description = COMPOUND_STRING("Makes escaping easier."),
#endif
        .aiRating = 0,
    },

    [ABILITY_KEEN_EYE] =
    {
#if GERMAN
        .name = _("Adlerauge"),
        .description = COMPOUND_STRING("Verhindert Verl. d. Genauig."),
#else
        .name = _("KEEN EYE"),
        .description = COMPOUND_STRING("Prevents loss of accuracy."),
#endif
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_HYPER_CUTTER] =
    {
#if GERMAN
        .name = _("Scherenmacht"),
        .description = COMPOUND_STRING("Verhindert Angr.-Reduz."),
#else
        .name = _("HYPER CUTTER"),
        .description = COMPOUND_STRING("Prevents Attack reduction."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PICKUP] =
    {
#if GERMAN
        .name = _("Mitnahme"),
        .description = COMPOUND_STRING("Kann Objekte aufnehmen."),
#else
        .name = _("PICKUP"),
        .description = COMPOUND_STRING("May pick up items."),
#endif
        .aiRating = 1,
    },

    [ABILITY_TRUANT] =
    {
#if GERMAN
        .name = _("Schnarchnase"),
        .description = COMPOUND_STRING("Greift in jedem 2. Zug an."),
#else
        .name = _("TRUANT"),
        .description = COMPOUND_STRING("Moves only every two turns."),
#endif
        .aiRating = -2,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HUSTLE] =
    {
#if GERMAN
        .name = _("Übereifer"),
        .description = COMPOUND_STRING("Tauscht Genauigk. u. Kraft."),
#else
        .name = _("HUSTLE"),
        .description = COMPOUND_STRING("Trades accuracy for power."),
#endif
        .aiRating = 7,
    },

    [ABILITY_CUTE_CHARM] =
    {
#if GERMAN
        .name = _("Charmebolzen"),
        .description = COMPOUND_STRING("Wirkt bei Kontakt betörend."),
#else
        .name = _("CUTE CHARM"),
        .description = COMPOUND_STRING("Infatuates on contact."),
#endif
        .aiRating = 2,
    },

    [ABILITY_PLUS] =
    {
#if GERMAN
        .name = _("Plus"),
        .description = COMPOUND_STRING("Bildet ein Team mit Minun."),
#else
        .name = _("PLUS"),
        .description = COMPOUND_STRING("Powers up with Minus."),
#endif
        .aiRating = 0,
    },

    [ABILITY_MINUS] =
    {
#if GERMAN
        .name = _("Minus"),
        .description = COMPOUND_STRING("Bildet ein Team mit Plusle."),
#else
        .name = _("MINUS"),
        .description = COMPOUND_STRING("Powers up with Plus."),
#endif
        .aiRating = 0,
    },

    [ABILITY_FORECAST] =
    {
#if GERMAN
        .name = _("Prognose"),
        .description = COMPOUND_STRING("Ist vom Wetter abhängig."),
#else
        .name = _("FORECAST"),
        .description = COMPOUND_STRING("Changes with the weather."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_4,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_STICKY_HOLD] =
    {
#if GERMAN
        .name = _("Wertehalter"),
        .description = COMPOUND_STRING("Verhindert Item-Diebstahl."),
#else
        .name = _("STICKY HOLD"),
        .description = COMPOUND_STRING("Prevents item theft."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_SHED_SKIN] =
    {
#if GERMAN
        .name = _("Expidermis"),
        .description = COMPOUND_STRING("Heilt durch Häutung."),
#else
        .name = _("SHED SKIN"),
        .description = COMPOUND_STRING("Heals the body by shedding."),
#endif
        .aiRating = 7,
    },

    [ABILITY_GUTS] =
    {
#if GERMAN
        .name = _("Adrenalin"),
        .description = COMPOUND_STRING("Steigert Angr. bei Leiden."),
#else
        .name = _("GUTS"),
        .description = COMPOUND_STRING("Ups Attack if suffering."),
#endif
        .aiRating = 6,
    },

    [ABILITY_MARVEL_SCALE] =
    {
#if GERMAN
        .name = _("Notschutz"),
        .description = COMPOUND_STRING("Steigert Vert. bei Leiden."),
#else
        .name = _("MARVEL SCALE"),
        .description = COMPOUND_STRING("Ups Defense if suffering."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_LIQUID_OOZE] =
    {
#if GERMAN
        .name = _("Kloakensoße"),
        .description = COMPOUND_STRING("Saug-Attacken schädigen."),
#else
        .name = _("LIQUID OOZE"),
        .description = COMPOUND_STRING("Draining causes injury."),
#endif
        .aiRating = 3,
    },

    [ABILITY_OVERGROW] =
    {
#if GERMAN
        .name = _("Notdünger"),
        .description = COMPOUND_STRING("Erhöht Pfl.-Att. i. d. Not."),
#else
        .name = _("OVERGROW"),
        .description = COMPOUND_STRING("Ups Grass moves in a pinch."),
#endif
        .aiRating = 5,
    },

    [ABILITY_BLAZE] =
    {
#if GERMAN
        .name = _("Großbrand"),
        .description = COMPOUND_STRING("Erhöht Feuer-Att. in Not."),
#else
        .name = _("BLAZE"),
        .description = COMPOUND_STRING("Ups Fire moves in a pinch."),
#endif
        .aiRating = 5,
    },

    [ABILITY_TORRENT] =
    {
#if GERMAN
        .name = _("Sturzbach"),
        .description = COMPOUND_STRING("Erhöht Wasser-Att. in Not."),
#else
        .name = _("TORRENT"),
        .description = COMPOUND_STRING("Ups Water moves in a pinch."),
#endif
        .aiRating = 5,
    },

    [ABILITY_SWARM] =
    {
#if GERMAN
        .name = _("Hexaplaga"),
        .description = COMPOUND_STRING("Erhöht Käfer-Att. in Not."),
#else
        .name = _("SWARM"),
        .description = COMPOUND_STRING("Ups Bug moves in a pinch."),
#endif
        .aiRating = 5,
    },

    [ABILITY_ROCK_HEAD] =
    {
#if GERMAN
        .name = _("Steinhaupt"),
        .description = COMPOUND_STRING("Verh. Rückstoß-Schaden."),
#else
        .name = _("ROCK HEAD"),
        .description = COMPOUND_STRING("Prevents recoil damage."),
#endif
        .aiRating = 5,
    },

    [ABILITY_DROUGHT] =
    {
#if GERMAN
        .name = _("Dürre"),
        .description = COMPOUND_STRING("Erzeugt Sonne im Kampf."),
#else
        .name = _("DROUGHT"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
#endif
        .aiRating = 9,
    },

    [ABILITY_ARENA_TRAP] =
    {
#if GERMAN
        .name = _("Ausweglos"),
        .description = COMPOUND_STRING("Verhindert Flucht."),
#else
        .name = _("ARENA TRAP"),
        .description = COMPOUND_STRING("Prevents fleeing."),
#endif
        .aiRating = 9,
    },

    [ABILITY_VITAL_SPIRIT] =
    {
#if GERMAN
        .name = _("Munterkeit"),
        .description = COMPOUND_STRING("Verhindert Einschlafen."),
#else
        .name = _("VITAL SPIRIT"),
        .description = COMPOUND_STRING("Prevents sleep."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_WHITE_SMOKE] =
    {
#if GERMAN
        .name = _("Pulverrauch"),
        .description = COMPOUND_STRING("Verhindert Fähigk.-Reduz."),
#else
        .name = _("WHITE SMOKE"),
        .description = COMPOUND_STRING("Prevents ability reduction."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_PURE_POWER] =
    {
#if GERMAN
        .name = _("Mentalkraft"),
        .description = COMPOUND_STRING("Steigert Angr."),
#else
        .name = _("PURE POWER"),
        .description = COMPOUND_STRING("Raises Attack."),
#endif
        .aiRating = 10,
    },

    [ABILITY_SHELL_ARMOR] =
    {
#if GERMAN
        .name = _("Panzerhaut"),
        .description = COMPOUND_STRING("Wehrt Volltreffer ab."),
#else
        .name = _("SHELL ARMOR"),
        .description = COMPOUND_STRING("Blocks critical hits."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_AIR_LOCK] =
    {
#if GERMAN
        .name = _("Klimaschutz"),
        .description = COMPOUND_STRING("Kehrt Wetter-Effekte um."),
#else
        .name = _("AIR LOCK"),
        .description = COMPOUND_STRING("Negates weather effects."),
#endif
        .aiRating = 5,
    },

    [ABILITY_TANGLED_FEET] =
    {
#if GERMAN
        .name = _("Fußangel"),
        .description = COMPOUND_STRING("Fluchtw. hoch b. Verwirrung."),
#else
        .name = _("TANGLED FEET"),
        .description = COMPOUND_STRING("Ups evasion if confused."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MOTOR_DRIVE] =
    {
#if GERMAN
        .name = _("Starthilfe"),
        .description = COMPOUND_STRING("Elektro-Att. erhöht Init."),
#else
        .name = _("MOTOR DRIVE"),
        .description = COMPOUND_STRING("Electricity raises Speed."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_RIVALRY] =
    {
#if GERMAN
        .name = _("Rivalität"),
        .description = COMPOUND_STRING("Mehr Angr. b. gl. Geschlecht."),
#else
        .name = _("RIVALRY"),
        .description = COMPOUND_STRING("Powers up against rivals."),
#endif
        .aiRating = 1,
    },

    [ABILITY_STEADFAST] =
    {
#if GERMAN
        .name = _("Felsenfest"),
        .description = COMPOUND_STRING("Zurückschrecken hebt Init."),
#else
        .name = _("STEADFAST"),
        .description = COMPOUND_STRING("Flinching raises Speed."),
#endif
        .aiRating = 2,
    },

    [ABILITY_SNOW_CLOAK] =
    {
#if GERMAN
        .name = _("Schneemantel"),
        .description = COMPOUND_STRING("Erh. Fluchtw. bei Hagel."),
#else
        .name = _("SNOW CLOAK"),
        .description = COMPOUND_STRING("Ups evasion in Hail or Snow."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_GLUTTONY] =
    {
#if GERMAN
        .name = _("Völlerei"),
        .description = COMPOUND_STRING("Verwendet Beere früher."),
#else
        .name = _("GLUTTONY"),
        .description = COMPOUND_STRING("Eats Berries early."),
#endif
        .aiRating = 3,
    },

    [ABILITY_ANGER_POINT] =
    {
#if GERMAN
        .name = _("Kurzschluss"),
        .description = COMPOUND_STRING("Volltreffer maximiert Angr."),
#else
        .name = _("ANGER POINT"),
        .description = COMPOUND_STRING("Critical hits raise Attack."),
#endif
        .aiRating = 4,
    },

    [ABILITY_UNBURDEN] =
    {
#if GERMAN
        .name = _("Entlastung"),
        .description = COMPOUND_STRING("Init. hoch bei Itemverlust."),
#else
        .name = _("UNBURDEN"),
        .description = COMPOUND_STRING("Using a hold item ups Speed."),
#endif
        .aiRating = 7,
    },

    [ABILITY_HEATPROOF] =
    {
#if GERMAN
        .name = _("Hitzeschutz"),
        .description = COMPOUND_STRING("Senkt Kraft von Feuer-Att."),
#else
        .name = _("HEATPROOF"),
        .description = COMPOUND_STRING("Heat and burn protection."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SIMPLE] =
    {
#if GERMAN
        .name = _("Wankelmut"),
        .description = COMPOUND_STRING("Anfällig f. Statusänderung."),
#else
        .name = _("SIMPLE"),
        .description = COMPOUND_STRING("Prone to wild stat changes."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_DRY_SKIN] =
    {
#if GERMAN
        .name = _("Trockenheit"),
        .description = COMPOUND_STRING("Hitze senkt KP, Wasser hebt"),
#else
        .name = _("DRY SKIN"),
        .description = COMPOUND_STRING("Prefers moisture to heat."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_DOWNLOAD] =
    {
#if GERMAN
        .name = _("Download"),
        .description = COMPOUND_STRING("Kraft je nach gegn. Werten."),
#else
        .name = _("DOWNLOAD"),
        .description = COMPOUND_STRING("Adjusts power favorably."),
#endif
        .aiRating = 7,
    },

    [ABILITY_IRON_FIST] =
    {
#if GERMAN
        .name = _("Eisenfaust"),
        .description = COMPOUND_STRING("Steigert Box-Attacken."),
#else
        .name = _("IRON FIST"),
        .description = COMPOUND_STRING("Boosts punching moves."),
#endif
        .aiRating = 6,
    },

    [ABILITY_POISON_HEAL] =
    {
#if GERMAN
        .name = _("Aufheber"),
        .description = COMPOUND_STRING("Steigert KP bei Vergiftung."),
#else
        .name = _("POISON HEAL"),
        .description = COMPOUND_STRING("Restores HP if poisoned."),
#endif
        .aiRating = 8,
    },

    [ABILITY_ADAPTABILITY] =
    {
#if GERMAN
        .name = _("Anpassung"),
        .description = COMPOUND_STRING("Steigert Att. gleichen Typs"),
#else
        .name = _("ADAPTABILITY"),
        .description = COMPOUND_STRING("Boosts same type attacks."),
#endif
        .aiRating = 8,
    },

    [ABILITY_SKILL_LINK] =
    {
#if GERMAN
        .name = _("Wertelink"),
        .description = COMPOUND_STRING("Mehr Treffer b. Serien-Att."),
#else
        .name = _("SKILL LINK"),
        .description = COMPOUND_STRING("Multi-hit moves hit 5 times."),
#endif
        .aiRating = 7,
    },

    [ABILITY_HYDRATION] =
    {
#if GERMAN
        .name = _("Hydration"),
        .description = COMPOUND_STRING("Heilt Statusprobl. b. Regen"),
#else
        .name = _("HYDRATION"),
        .description = COMPOUND_STRING("Cures status in rain."),
#endif
        .aiRating = 4,
    },

    [ABILITY_SOLAR_POWER] =
    {
#if GERMAN
        .name = _("Solarkraft"),
        .description = COMPOUND_STRING("Sonne: Sp.-Ang. hoch, KP ab"),
#else
        .name = _("SOLAR POWER"),
        .description = COMPOUND_STRING("Powers up in sunshine."),
#endif
        .aiRating = 3,
    },

    [ABILITY_QUICK_FEET] =
    {
#if GERMAN
        .name = _("Rasanz"),
        .description = COMPOUND_STRING("Init. hoch b. Statusprobl."),
#else
        .name = _("QUICK FEET"),
        .description = COMPOUND_STRING("Ups Speed if suffering."),
#endif
        .aiRating = 5,
    },

    [ABILITY_NORMALIZE] =
    {
#if GERMAN
        .name = _("Regulierung"),
        .description = COMPOUND_STRING("Alle Att. werden Normal."),
#else
        .name = _("NORMALIZE"),
        .description = COMPOUND_STRING("Moves become Normal-type."),
#endif
        .aiRating = -1,
    },

    [ABILITY_SNIPER] =
    {
#if GERMAN
        .name = _("Superschütze"),
        .description = COMPOUND_STRING("Steigert Att. n. Volltreff."),
#else
        .name = _("SNIPER"),
        .description = COMPOUND_STRING("Boosts critical hits."),
#endif
        .aiRating = 3,
    },

    [ABILITY_MAGIC_GUARD] =
    {
#if GERMAN
        .name = _("Magieschild"),
        .description = COMPOUND_STRING("Nur direkte Att. schaden."),
#else
        .name = _("MAGIC GUARD"),
        .description = COMPOUND_STRING("Only damaged by attacks."),
#endif
        .aiRating = 9,
    },

    [ABILITY_NO_GUARD] =
    {
#if GERMAN
        .name = _("Schildlos"),
        .description = COMPOUND_STRING("Alle Angriffe treffen."),
#else
        .name = _("NO GUARD"),
        .description = COMPOUND_STRING("Ensures that all moves hit."),
#endif
        .aiRating = 8,
    },

    [ABILITY_STALL] =
    {
#if GERMAN
        .name = _("Zeitspiel"),
        .description = COMPOUND_STRING("Handelt nach agileren Gegn."),
#else
        .name = _("STALL"),
        .description = COMPOUND_STRING("Always moves last."),
#endif
        .aiRating = -1,
    },

    [ABILITY_TECHNICIAN] =
    {
#if GERMAN
        .name = _("Techniker"),
        .description = COMPOUND_STRING("Steigert schwache Att."),
#else
        .name = _("TECHNICIAN"),
        .description = COMPOUND_STRING("Boosts weaker moves."),
#endif
        .aiRating = 8,
    },

    [ABILITY_LEAF_GUARD] =
    {
#if GERMAN
        .name = _("Floraschild"),
        .description = COMPOUND_STRING("Kein Statusprobl. b. Sonne"),
#else
        .name = _("LEAF GUARD"),
        .description = COMPOUND_STRING("Blocks status in sunshine."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_KLUTZ] =
    {
#if GERMAN
        .name = _("Tollpatsch"),
        .description = COMPOUND_STRING("Kann keine Items nutzen."),
#else
        .name = _("KLUTZ"),
        .description = COMPOUND_STRING("Can't use hold items."),
#endif
        .aiRating = -1,
    },

    [ABILITY_MOLD_BREAKER] =
    {
#if GERMAN
        .name = _("Überbrückung"),
        .description = COMPOUND_STRING("Att. trotz gegn. Fähigkeit."),
#else
        .name = _("MOLD BREAKER"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
#endif
        .aiRating = 7,
    },

    [ABILITY_SUPER_LUCK] =
    {
#if GERMAN
        .name = _("Glückspilz"),
        .description = COMPOUND_STRING("Erhöht Volltreffer-Chance."),
#else
        .name = _("SUPER LUCK"),
        .description = COMPOUND_STRING("Critical hits land often."),
#endif
        .aiRating = 3,
    },

    [ABILITY_AFTERMATH] =
    {
#if GERMAN
        .name = _("Finalschlag"),
        .description = COMPOUND_STRING("Schadet Gegner bei K.O."),
#else
        .name = _("AFTERMATH"),
        .description = COMPOUND_STRING("Fainting damages the foe."),
#endif
        .aiRating = 5,
    },

    [ABILITY_ANTICIPATION] =
    {
#if GERMAN
        .name = _("Vorahnung"),
        .description = COMPOUND_STRING("Ahnt gefährl. Att. voraus."),
#else
        .name = _("ANTICIPATION"),
        .description = COMPOUND_STRING("Senses dangerous moves."),
#endif
        .aiRating = 2,
    },

    [ABILITY_FOREWARN] =
    {
#if GERMAN
        .name = _("Vorwarnung"),
        .description = COMPOUND_STRING("Zeigt stärkste gegn. Att."),
#else
        .name = _("FOREWARN"),
        .description = COMPOUND_STRING("Determines a foe's move."),
#endif
        .aiRating = 2,
    },

    [ABILITY_UNAWARE] =
    {
#if GERMAN
        .name = _("Unkenntnis"),
        .description = COMPOUND_STRING("Ignoriert gegn. Werte-Änd."),
#else
        .name = _("UNAWARE"),
        .description = COMPOUND_STRING("Ignores stat changes."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_TINTED_LENS] =
    {
#if GERMAN
        .name = _("Aufwertung"),
        .description = COMPOUND_STRING("Steigert schwache Att.-Typ"),
#else
        .name = _("TINTED LENS"),
        .description = COMPOUND_STRING("Ups “not very effective”."),
#endif
        .aiRating = 7,
    },

    [ABILITY_FILTER] =
    {
#if GERMAN
        .name = _("Filter"),
        .description = COMPOUND_STRING("Senkt sehr effektive Att."),
#else
        .name = _("FILTER"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SLOW_START] =
    {
#if GERMAN
        .name = _("Saumselig"),
        .description = COMPOUND_STRING("Halbiert Angr. und Init."),
#else
        .name = _("SLOW START"),
        .description = COMPOUND_STRING("Takes a while to get going."),
#endif
        .aiRating = -2,
    },

    [ABILITY_SCRAPPY] =
    {
#if GERMAN
        .name = _("Rauflust"),
        .description = COMPOUND_STRING("Trifft auch Geist-Gegner."),
#else
        .name = _("SCRAPPY"),
        .description = COMPOUND_STRING("Hits Ghost-type Pokémon."),
#endif
        .aiRating = 6,
    },

    [ABILITY_STORM_DRAIN] =
    {
#if GERMAN
        .name = _("Sturmsog"),
        .description = COMPOUND_STRING("Zieht Wasser-Att. an."),
#else
        .name = _("STORM DRAIN"),
        .description = COMPOUND_STRING("Draws in Water moves."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_ICE_BODY] =
    {
#if GERMAN
        .name = _("Eishaut"),
        .description = COMPOUND_STRING("Regeneriert KP bei Hagel."),
#else
        .name = _("ICE BODY"),
        .description = COMPOUND_STRING("HP recovery in Hail or Snow."),
#endif
        .aiRating = 3,
    },

    [ABILITY_SOLID_ROCK] =
    {
#if GERMAN
        .name = _("Felskern"),
        .description = COMPOUND_STRING("Senkt sehr effektive Att."),
#else
        .name = _("SOLID ROCK"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_SNOW_WARNING] =
    {
#if GERMAN
        .name = _("Hagelalarm"),
#else
        .name = _("SNOW WARNING"),
#endif
    #if B_SNOW_WARNING >= GEN_9
#if GERMAN
        .description = COMPOUND_STRING("Beschwört Schnee im Kampf"),
#else
        .description = COMPOUND_STRING("Summons snow in battle."),
#endif
    #else
#if GERMAN
        .description = COMPOUND_STRING("Beschwört Hagel im Kampf"),
#else
        .description = COMPOUND_STRING("Summons hail in battle."),
#endif
    #endif
        .aiRating = 8,
    },

    [ABILITY_HONEY_GATHER] =
    {
#if GERMAN
        .name = _("Honigmaul"),
        .description = COMPOUND_STRING("Kann Honig sammeln."),
#else
        .name = _("HONEY GATHER"),
        .description = COMPOUND_STRING("May gather Honey."),
#endif
        .aiRating = 0,
    },

    [ABILITY_FRISK] =
    {
#if GERMAN
        .name = _("Schnüffler"),
        .description = COMPOUND_STRING("Zeigt gegnerische Items."),
#else
        .name = _("FRISK"),
        .description = COMPOUND_STRING("Checks a foe's item."),
#endif
        .aiRating = 3,
    },

    [ABILITY_RECKLESS] =
    {
#if GERMAN
        .name = _("Achtlos"),
        .description = COMPOUND_STRING("Steigert Rückstoß-Att."),
#else
        .name = _("RECKLESS"),
        .description = COMPOUND_STRING("Boosts moves with recoil."),
#endif
        .aiRating = 6,
    },

    [ABILITY_MULTITYPE] =
    {
#if GERMAN
        .name = _("Variabilität"),
        .description = COMPOUND_STRING("Typ je nach Tafel."),
#else
        .name = _("MULTITYPE"),
        .description = COMPOUND_STRING("Changes type to its Plate."),
#endif
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = B_UPDATED_ABILITY_DATA >= GEN_5,
    },

    [ABILITY_FLOWER_GIFT] =
    {
#if GERMAN
        .name = _("Pflanzengabe"),
        .description = COMPOUND_STRING("Stärkt Team bei Sonne."),
#else
        .name = _("FLOWER GIFT"),
        .description = COMPOUND_STRING("Allies power up in sunshine."),
#endif
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeTraced = B_UPDATED_ABILITY_DATA >= GEN_5,
        .breakable = TRUE,
    },

    [ABILITY_BAD_DREAMS] =
    {
#if GERMAN
        .name = _("Alptraum"),
        .description = COMPOUND_STRING("Senkt KP schlafender Gegn."),
#else
        .name = _("BAD DREAMS"),
        .description = COMPOUND_STRING("Damages sleeping Pokémon."),
#endif
        .aiRating = 4,
    },

    [ABILITY_PICKPOCKET] =
    {
#if GERMAN
        .name = _("Langfinger"),
        .description = COMPOUND_STRING("Stiehlt Item bei Berührung."),
#else
        .name = _("PICKPOCKET"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
#endif
        .aiRating = 3,
    },

    [ABILITY_SHEER_FORCE] =
    {
#if GERMAN
        .name = _("Rohe Gewalt"),
        .description = COMPOUND_STRING("Mehr Kraft, kein Zusatzeff."),
#else
        .name = _("SHEER FORCE"),
        .description = COMPOUND_STRING("Trades effects for power."),
#endif
        .aiRating = 8,
    },

    [ABILITY_CONTRARY] =
    {
#if GERMAN
        .name = _("Umkehrung"),
        .description = COMPOUND_STRING("Kehrt Statusänderung um."),
#else
        .name = _("CONTRARY"),
        .description = COMPOUND_STRING("Inverts stat changes."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_UNNERVE] =
    {
#if GERMAN
        .name = _("Anspannung"),
        .description = COMPOUND_STRING("Gegner isst keine Beeren."),
#else
        .name = _("UNNERVE"),
        .description = COMPOUND_STRING("Foes can't eat Berries."),
#endif
        .aiRating = 3,
    },

    [ABILITY_DEFIANT] =
    {
#if GERMAN
        .name = _("Siegeswille"),
        .description = COMPOUND_STRING("Senkung hebt Angr. stark."),
#else
        .name = _("DEFIANT"),
        .description = COMPOUND_STRING("Lowered stats up Attack."),
#endif
        .aiRating = 5,
    },

    [ABILITY_DEFEATIST] =
    {
#if GERMAN
        .name = _("Schwächling"),
        .description = COMPOUND_STRING("Schwächer bei halben KP."),
#else
        .name = _("DEFEATIST"),
        .description = COMPOUND_STRING("Gives up at half HP."),
#endif
        .aiRating = -1,
    },

    [ABILITY_CURSED_BODY] =
    {
#if GERMAN
        .name = _("Tastfluch"),
        .description = COMPOUND_STRING("Blockt Att. evtl. b. Treffer"),
#else
        .name = _("CURSED BODY"),
        .description = COMPOUND_STRING("Disables moves on contact."),
#endif
        .aiRating = 4,
    },

    [ABILITY_HEALER] =
    {
#if GERMAN
        .name = _("Heilherz"),
        .description = COMPOUND_STRING("Heilt evtl. Statusprobleme."),
#else
        .name = _("HEALER"),
        .description = COMPOUND_STRING("Heals partner Pokémon."),
#endif
        .aiRating = 0,
    },

    [ABILITY_FRIEND_GUARD] =
    {
#if GERMAN
        .name = _("Freundeshut"),
        .description = COMPOUND_STRING("Senkt Schaden an Partnern."),
#else
        .name = _("FRIEND GUARD"),
        .description = COMPOUND_STRING("Lowers damage to partner."),
#endif
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_WEAK_ARMOR] =
    {
#if GERMAN
        .name = _("Bruchrüstung"),
        .description = COMPOUND_STRING("Treffer: Vert. ab, Init. auf"),
#else
        .name = _("WEAK ARMOR"),
        .description = COMPOUND_STRING("Its stats change when hit."),
#endif
        .aiRating = 2,
    },

    [ABILITY_HEAVY_METAL] =
    {
#if GERMAN
        .name = _("Schwermetall"),
        .description = COMPOUND_STRING("Verdoppelt das Gewicht."),
#else
        .name = _("HEAVY METAL"),
        .description = COMPOUND_STRING("Doubles weight."),
#endif
        .aiRating = -1,
        .breakable = TRUE,
    },

    [ABILITY_LIGHT_METAL] =
    {
#if GERMAN
        .name = _("Leichtmetall"),
        .description = COMPOUND_STRING("Halbiert das Gewicht."),
#else
        .name = _("LIGHT METAL"),
        .description = COMPOUND_STRING("Halves weight."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_MULTISCALE] =
    {
#if GERMAN
        .name = _("Multischuppe"),
        .description = COMPOUND_STRING("Weniger Schaden b. voll KP"),
#else
        .name = _("MULTISCALE"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_TOXIC_BOOST] =
    {
#if GERMAN
        .name = _("Giftwahn"),
        .description = COMPOUND_STRING("Vergiftet: mehr Angr."),
#else
        .name = _("TOXIC BOOST"),
        .description = COMPOUND_STRING("Ups Attack if poisoned."),
#endif
        .aiRating = 6,
    },

    [ABILITY_FLARE_BOOST] =
    {
#if GERMAN
        .name = _("Hitzewahn"),
        .description = COMPOUND_STRING("Verbrannt: mehr Sp.-Kraft."),
#else
        .name = _("FLARE BOOST"),
        .description = COMPOUND_STRING("Ups Sp. Atk if burned."),
#endif
        .aiRating = 5,
    },

    [ABILITY_HARVEST] =
    {
#if GERMAN
        .name = _("Reiche Ernte"),
        .description = COMPOUND_STRING("Beere mehrfach verwendbar."),
#else
        .name = _("HARVEST"),
        .description = COMPOUND_STRING("May recycle a used Berry."),
#endif
        .aiRating = 5,
    },

    [ABILITY_TELEPATHY] =
    {
#if GERMAN
        .name = _("Telepathie"),
        .description = COMPOUND_STRING("Pariert Att. der Partner."),
#else
        .name = _("TELEPATHY"),
        .description = COMPOUND_STRING("Can't be damaged by an ally."),
#endif
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_MOODY] =
    {
#if GERMAN
        .name = _("Gefühlswippe"),
        .description = COMPOUND_STRING("Hebt u. senkt je einen Wert"),
#else
        .name = _("MOODY"),
        .description = COMPOUND_STRING("Stats change gradually."),
#endif
        .aiRating = 10,
    },

    [ABILITY_OVERCOAT] =
    {
#if GERMAN
        .name = _("Wetterfest"),
        .description = COMPOUND_STRING("Schutz vor Wetter, Pulver."),
#else
        .name = _("OVERCOAT"),
        .description = COMPOUND_STRING("Blocks weather and powder."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_POISON_TOUCH] =
    {
#if GERMAN
        .name = _("Giftgriff"),
        .description = COMPOUND_STRING("Vergiftet evtl. b. Kontakt."),
#else
        .name = _("POISON TOUCH"),
        .description = COMPOUND_STRING("Poisons foe on contact."),
#endif
        .aiRating = 4,
    },

    [ABILITY_REGENERATOR] =
    {
#if GERMAN
        .name = _("Belebekraft"),
        .description = COMPOUND_STRING("Heilt KP beim Auswechseln."),
#else
        .name = _("REGENERATOR"),
        .description = COMPOUND_STRING("Heals upon switching out."),
#endif
        .aiRating = 8,
    },

    [ABILITY_BIG_PECKS] =
    {
#if GERMAN
        .name = _("Brustbieter"),
        .description = COMPOUND_STRING("Vert. kann nicht sinken."),
#else
        .name = _("BIG PECKS"),
        .description = COMPOUND_STRING("Prevents Defense loss."),
#endif
        .aiRating = 1,
        .breakable = TRUE,
    },

    [ABILITY_SAND_RUSH] =
    {
#if GERMAN
        .name = _("Sandscharrer"),
        .description = COMPOUND_STRING("Erhöht Init. im Sandsturm."),
#else
        .name = _("SAND RUSH"),
        .description = COMPOUND_STRING("Ups Speed in a sandstorm."),
#endif
        .aiRating = 6,
    },

    [ABILITY_WONDER_SKIN] =
    {
#if GERMAN
        .name = _("Wunderhaut"),
        .description = COMPOUND_STRING("Wehrt Status-Att. oft ab."),
#else
        .name = _("WONDER SKIN"),
        .description = COMPOUND_STRING("May avoid status problems."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANALYTIC] =
    {
#if GERMAN
        .name = _("Analyse"),
        .description = COMPOUND_STRING("Mehr Kraft als Letzter."),
#else
        .name = _("ANALYTIC"),
        .description = COMPOUND_STRING("Moving last boosts power."),
#endif
        .aiRating = 5,
    },

    [ABILITY_ILLUSION] =
    {
#if GERMAN
        .name = _("Trugbild"),
        .description = COMPOUND_STRING("Tarnt sich als letztes Pkmn"),
#else
        .name = _("ILLUSION"),
        .description = COMPOUND_STRING("Appears as a partner."),
#endif
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_IMPOSTER] =
    {
#if GERMAN
        .name = _("Doppelgänger"),
        .description = COMPOUND_STRING("Kämpft als Kopie des Gegn."),
#else
        .name = _("IMPOSTER"),
        .description = COMPOUND_STRING("Transforms into the foe."),
#endif
        .aiRating = 9,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_INFILTRATOR] =
    {
#if GERMAN
        .name = _("Schwebedurch"),
        .description = COMPOUND_STRING("Greift durch Schilde an."),
#else
        .name = _("INFILTRATOR"),
        .description = COMPOUND_STRING("Passes through barriers."),
#endif
        .aiRating = 6,
    },

    [ABILITY_MUMMY] =
    {
#if GERMAN
        .name = _("Mumie"),
        .description = COMPOUND_STRING("Überträgt sich b. Kontakt."),
#else
        .name = _("MUMMY"),
        .description = COMPOUND_STRING("Spreads with contact."),
#endif
        .aiRating = 5,
    },

    [ABILITY_MOXIE] =
    {
#if GERMAN
        .name = _("Hochmut"),
        .description = COMPOUND_STRING("K.O. erhöht eigenen Angr."),
#else
        .name = _("MOXIE"),
        .description = COMPOUND_STRING("KOs raise Attack."),
#endif
        .aiRating = 7,
    },

    [ABILITY_JUSTIFIED] =
    {
#if GERMAN
        .name = _("Redlichkeit"),
        .description = COMPOUND_STRING("Unlicht-Att. erhöht Angr."),
#else
        .name = _("JUSTIFIED"),
        .description = COMPOUND_STRING("Dark hits raise Attack."),
#endif
        .aiRating = 4,
    },

    [ABILITY_RATTLED] =
    {
#if GERMAN
        .name = _("Hasenfuß"),
        .description = COMPOUND_STRING("Angst erhöht die Init."),
#else
        .name = _("RATTLED"),
        .description = COMPOUND_STRING("Raises Speed when scared."),
#endif
        .aiRating = 3,
    },

    [ABILITY_MAGIC_BOUNCE] =
    {
#if GERMAN
        .name = _("Magiespiegel"),
        .description = COMPOUND_STRING("Lenkt Status-Att. zurück."),
#else
        .name = _("MAGIC BOUNCE"),
        .description = COMPOUND_STRING("Reflects status moves."),
#endif
        .aiRating = 9,
        .breakable = TRUE,
    },

    [ABILITY_SAP_SIPPER] =
    {
#if GERMAN
        .name = _("Vegetarier"),
        .description = COMPOUND_STRING("Pflanzen-Att. erhöht Angr."),
#else
        .name = _("SAP SIPPER"),
        .description = COMPOUND_STRING("Grass increases Attack."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_PRANKSTER] =
    {
#if GERMAN
        .name = _("Strolch"),
        .description = COMPOUND_STRING("Status-Att. zuerst."),
#else
        .name = _("PRANKSTER"),
        .description = COMPOUND_STRING("Status moves go first."),
#endif
        .aiRating = 8,
    },

    [ABILITY_SAND_FORCE] =
    {
#if GERMAN
        .name = _("Sandgewalt"),
        .description = COMPOUND_STRING("Sandsturm stärkt 3 Typen."),
#else
        .name = _("SAND FORCE"),
        .description = COMPOUND_STRING("Powers up in a sandstorm."),
#endif
        .aiRating = 4,
    },

    [ABILITY_IRON_BARBS] =
    {
#if GERMAN
        .name = _("Eisenstachel"),
        .description = COMPOUND_STRING("Schadet b. Berührung."),
#else
        .name = _("IRON BARBS"),
        .description = COMPOUND_STRING("Hurts to touch."),
#endif
        .aiRating = 6,
    },

    [ABILITY_ZEN_MODE] =
    {
#if GERMAN
        .name = _("Trance-Modus"),
        .description = COMPOUND_STRING("Wechselt Form b. halben KP."),
#else
        .name = _("ZEN MODE"),
        .description = COMPOUND_STRING("Transforms at half HP."),
#endif
        .aiRating = -1,
        .cantBeCopied = TRUE,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = B_UPDATED_ABILITY_DATA >= GEN_7,
        .cantBeOverwritten = B_UPDATED_ABILITY_DATA >= GEN_7,
        .failsOnImposter = TRUE,
    },

    [ABILITY_VICTORY_STAR] =
    {
#if GERMAN
        .name = _("Triumphstern"),
        .description = COMPOUND_STRING("Erhöht Genauigkeit im Team."),
#else
        .name = _("VICTORY STAR"),
        .description = COMPOUND_STRING("Raises party accuracy."),
#endif
        .aiRating = 6,
    },

    [ABILITY_TURBOBLAZE] =
    {
#if GERMAN
        .name = _("Turbobrand"),
        .description = COMPOUND_STRING("Att. trotz gegn. Fähigkeit."),
#else
        .name = _("TURBOBLAZE"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
#endif
        .aiRating = 7,
    },

    [ABILITY_TERAVOLT] =
    {
#if GERMAN
        .name = _("Teravolt"),
        .description = COMPOUND_STRING("Att. trotz gegn. Fähigkeit."),
#else
        .name = _("TERAVOLT"),
        .description = COMPOUND_STRING("Moves hit through abilities."),
#endif
        .aiRating = 7,
    },

    [ABILITY_AROMA_VEIL] =
    {
#if GERMAN
        .name = _("Dufthülle"),
        .description = COMPOUND_STRING("Schützt Team vor Sperren."),
#else
        .name = _("AROMA VEIL"),
        .description = COMPOUND_STRING("Prevents limiting of moves."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_FLOWER_VEIL] =
    {
#if GERMAN
        .name = _("Blütenhülle"),
        .description = COMPOUND_STRING("Schützt Pflanzen-Partner."),
#else
        .name = _("FLOWER VEIL"),
        .description = COMPOUND_STRING("Protects Grass-types."),
#endif
        .aiRating = 0,
        .breakable = TRUE,
    },

    [ABILITY_CHEEK_POUCH] =
    {
#if GERMAN
        .name = _("Backentaschen"),
        .description = COMPOUND_STRING("Beere essen heilt extra KP."),
#else
        .name = _("CHEEK POUCH"),
        .description = COMPOUND_STRING("Eating Berries restores HP."),
#endif
        .aiRating = 4,
    },

    [ABILITY_PROTEAN] =
    {
#if GERMAN
        .name = _("Wandlungskunst"),
        .description = COMPOUND_STRING("Nimmt den Typ der Att. an."),
#else
        .name = _("PROTEAN"),
        .description = COMPOUND_STRING("Changes type to used move."),
#endif
        .aiRating = 8,
    },

    [ABILITY_FUR_COAT] =
    {
#if GERMAN
        .name = _("Fellkleid"),
        .description = COMPOUND_STRING("Halbiert phys. Schaden."),
#else
        .name = _("FUR COAT"),
        .description = COMPOUND_STRING("Raises Defense."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MAGICIAN] =
    {
#if GERMAN
        .name = _("Zauberer"),
        .description = COMPOUND_STRING("Stiehlt Item beim Treffer."),
#else
        .name = _("MAGICIAN"),
        .description = COMPOUND_STRING("Steals the foe's held item."),
#endif
        .aiRating = 3,
    },

    [ABILITY_BULLETPROOF] =
    {
#if GERMAN
        .name = _("Kugelsicher"),
        .description = COMPOUND_STRING("Schützt vor Kugel-Att."),
#else
        .name = _("BULLETPROOF"),
        .description = COMPOUND_STRING("Avoids some projectiles."),
#endif
        .breakable = TRUE,
        .aiRating = 7,
    },

    [ABILITY_COMPETITIVE] =
    {
#if GERMAN
        .name = _("Unbeugsamkeit"),
        .description = COMPOUND_STRING("Senkung hebt Sp.Ang. stark."),
#else
        .name = _("COMPETITIVE"),
        .description = COMPOUND_STRING("Lowered stats up Sp. Atk."),
#endif
        .aiRating = 5,
    },

    [ABILITY_STRONG_JAW] =
    {
#if GERMAN
        .name = _("Titankiefer"),
        .description = COMPOUND_STRING("Stärkt Biss-Attacken."),
#else
        .name = _("STRONG JAW"),
        .description = COMPOUND_STRING("Boosts biting moves."),
#endif
        .aiRating = 6,
    },

    [ABILITY_REFRIGERATE] =
    {
#if GERMAN
        .name = _("Frostschicht"),
        .description = COMPOUND_STRING("Normal-Att. werden Eis."),
#else
        .name = _("REFRIGERATE"),
        .description = COMPOUND_STRING("Normal moves become Ice."),
#endif
        .aiRating = 8,
    },

    [ABILITY_SWEET_VEIL] =
    {
#if GERMAN
        .name = _("Zuckerhülle"),
        .description = COMPOUND_STRING("Team kann nicht schlafen."),
#else
        .name = _("SWEET VEIL"),
        .description = COMPOUND_STRING("Prevents party from sleep."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_STANCE_CHANGE] =
    {
#if GERMAN
        .name = _("Taktikwechsel"),
        .description = COMPOUND_STRING("Wechselt Form je nach Att."),
#else
        .name = _("STANCE CHANGE"),
        .description = COMPOUND_STRING("Transforms as it battles."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GALE_WINGS] =
    {
#if GERMAN
        .name = _("Orkanschwingen"),
        .description = COMPOUND_STRING("Flug-Att. zuerst b. voll KP"),
#else
        .name = _("GALE WINGS"),
        .description = COMPOUND_STRING("Flying moves go first."),
#endif
        .aiRating = 6,
    },

    [ABILITY_MEGA_LAUNCHER] =
    {
#if GERMAN
        .name = _("Megawumme"),
        .description = COMPOUND_STRING("Stärkt Puls- und Aura-Att."),
#else
        .name = _("MEGA LAUNCHER"),
        .description = COMPOUND_STRING("Boosts pulse moves."),
#endif
        .aiRating = 7,
    },

    [ABILITY_GRASS_PELT] =
    {
#if GERMAN
        .name = _("Pflanzenpelz"),
        .description = COMPOUND_STRING("Erhöht Vert. auf Grasfeld."),
#else
        .name = _("GRASS PELT"),
        .description = COMPOUND_STRING("Ups Defense in grass."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SYMBIOSIS] =
    {
#if GERMAN
        .name = _("Nutznießer"),
        .description = COMPOUND_STRING("Gibt Item an Partner ab."),
#else
        .name = _("SYMBIOSIS"),
        .description = COMPOUND_STRING("Passes its item to an ally."),
#endif
        .aiRating = 0,
    },

    [ABILITY_TOUGH_CLAWS] =
    {
#if GERMAN
        .name = _("Krallenwucht"),
        .description = COMPOUND_STRING("Stärkt direkte Attacken."),
#else
        .name = _("TOUGH CLAWS"),
        .description = COMPOUND_STRING("Boosts contact moves."),
#endif
        .aiRating = 7,
    },

    [ABILITY_PIXILATE] =
    {
#if GERMAN
        .name = _("Feenschicht"),
        .description = COMPOUND_STRING("Normal-Att. werden Fee."),
#else
        .name = _("PIXILATE"),
        .description = COMPOUND_STRING("Normal moves become Fairy."),
#endif
        .aiRating = 8,
    },

    [ABILITY_GOOEY] =
    {
#if GERMAN
        .name = _("Viskosität"),
        .description = COMPOUND_STRING("Senkt Init. b. Berührung."),
#else
        .name = _("GOOEY"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
#endif
        .aiRating = 5,
    },

    [ABILITY_AERILATE] =
    {
#if GERMAN
        .name = _("Zenithaut"),
        .description = COMPOUND_STRING("Normal-Att. werden Flug."),
#else
        .name = _("AERILATE"),
        .description = COMPOUND_STRING("Normal moves become Flying."),
#endif
        .aiRating = 8,
    },

    [ABILITY_PARENTAL_BOND] =
    {
#if GERMAN
        .name = _("Familienbande"),
        .description = COMPOUND_STRING("Greift zweimal an."),
#else
        .name = _("PARENTAL BOND"),
        .description = COMPOUND_STRING("Moves hit twice."),
#endif
        .aiRating = 10,
    },

    [ABILITY_DARK_AURA] =
    {
#if GERMAN
        .name = _("Dunkelaura"),
        .description = COMPOUND_STRING("Stärkt alle Unlicht-Att."),
#else
        .name = _("DARK AURA"),
        .description = COMPOUND_STRING("Boosts Dark moves."),
#endif
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_FAIRY_AURA] =
    {
#if GERMAN
        .name = _("Feenaura"),
        .description = COMPOUND_STRING("Stärkt alle Feen-Attacken."),
#else
        .name = _("FAIRY AURA"),
        .description = COMPOUND_STRING("Boosts Fairy moves."),
#endif
        .aiRating = 6,
        .breakable = B_UPDATED_ABILITY_DATA < GEN_8,
    },

    [ABILITY_AURA_BREAK] =
    {
#if GERMAN
        .name = _("Aura-Umkehr"),
        .description = COMPOUND_STRING("Kehrt Auren-Wirkung um."),
#else
        .name = _("AURA BREAK"),
        .description = COMPOUND_STRING("Reverse aura abilities."),
#endif
        .aiRating = 3,
        .breakable = TRUE,
    },

    [ABILITY_PRIMORDIAL_SEA] =
    {
#if GERMAN
        .name = _("Urmeer"),
        .description = COMPOUND_STRING("Regen: Feuer-Att. nutzlos"),
#else
        .name = _("PRIMORDIAL SEA"),
        .description = COMPOUND_STRING("Summons heavy rain."),
#endif
        .aiRating = 10,
    },

    [ABILITY_DESOLATE_LAND] =
    {
#if GERMAN
        .name = _("Endland"),
        .description = COMPOUND_STRING("Sonne: Wasser-Att. nutzlos"),
#else
        .name = _("DESOLATE LAND"),
        .description = COMPOUND_STRING("Summons intense sunlight."),
#endif
        .aiRating = 10,
    },

    [ABILITY_DELTA_STREAM] =
    {
#if GERMAN
        .name = _("Delta-Wind"),
        .description = COMPOUND_STRING("Winde nehmen Flug-Nachteil"),
#else
        .name = _("DELTA STREAM"),
        .description = COMPOUND_STRING("Summons strong winds."),
#endif
        .aiRating = 10,
    },

    [ABILITY_STAMINA] =
    {
#if GERMAN
        .name = _("Zähigkeit"),
        .description = COMPOUND_STRING("Treffer erhöht die Vert."),
#else
        .name = _("STAMINA"),
        .description = COMPOUND_STRING("Boosts Defense when hit."),
#endif
        .aiRating = 6,
    },

    [ABILITY_WIMP_OUT] =
    {
#if GERMAN
        .name = _("Reißaus"),
        .description = COMPOUND_STRING("Flieht bei halben KP."),
#else
        .name = _("WIMP OUT"),
        .description = COMPOUND_STRING("Flees at half HP."),
#endif
        .aiRating = 3,
    },

    [ABILITY_EMERGENCY_EXIT] =
    {
#if GERMAN
        .name = _("Rückzug"),
        .description = COMPOUND_STRING("Wechselt bei halben KP."),
#else
        .name = _("EMERGENCY EXIT"),
        .description = COMPOUND_STRING("Flees at half HP."),
#endif
        .aiRating = 3,
    },

    [ABILITY_WATER_COMPACTION] =
    {
#if GERMAN
        .name = _("Verklumpen"),
        .description = COMPOUND_STRING("Wasser-Att. hebt Vert. sehr"),
#else
        .name = _("WATER COMPACTION"),
        .description = COMPOUND_STRING("Water boosts Defense."),
#endif
        .aiRating = 4,
    },

    [ABILITY_MERCILESS] =
    {
#if GERMAN
        .name = _("Quälerei"),
        .description = COMPOUND_STRING("Volltreffer geg. Vergiftete"),
#else
        .name = _("MERCILESS"),
        .description = COMPOUND_STRING("Criticals poisoned foes."),
#endif
        .aiRating = 4,
    },

    [ABILITY_SHIELDS_DOWN] =
    {
#if GERMAN
        .name = _("Limitschild"),
        .description = COMPOUND_STRING("Panzer bricht b. halben KP."),
#else
        .name = _("SHIELDS DOWN"),
        .description = COMPOUND_STRING("Shell breaks at half HP."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STAKEOUT] =
    {
#if GERMAN
        .name = _("Beschattung"),
        .description = COMPOUND_STRING("Doppelt gegen neue Gegner."),
#else
        .name = _("STAKEOUT"),
        .description = COMPOUND_STRING("Stronger as foes switch in."),
#endif
        .aiRating = 6,
    },

    [ABILITY_WATER_BUBBLE] =
    {
#if GERMAN
        .name = _("Wasserblase"),
        .description = COMPOUND_STRING("Schutz vor Feuer u. Brand."),
#else
        .name = _("WATER BUBBLE"),
        .description = COMPOUND_STRING("Guards from fire and burns."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_STEELWORKER] =
    {
#if GERMAN
        .name = _("Stahlprofi"),
        .description = COMPOUND_STRING("Stärkt Stahl-Attacken."),
#else
        .name = _("STEELWORKER"),
        .description = COMPOUND_STRING("Powers up Steel moves."),
#endif
        .aiRating = 6,
    },

    [ABILITY_BERSERK] =
    {
#if GERMAN
        .name = _("Wutausbruch"),
        .description = COMPOUND_STRING("Halbe KP erhöhen Sp.Ang."),
#else
        .name = _("BERSERK"),
        .description = COMPOUND_STRING("Boosts Sp. Atk at low HP."),
#endif
        .aiRating = 5,
    },

    [ABILITY_SLUSH_RUSH] =
    {
#if GERMAN
        .name = _("Schneescharrer"),
        .description = COMPOUND_STRING("Erhöht Init. bei Hagel."),
#else
        .name = _("SLUSH RUSH"),
        .description = COMPOUND_STRING("Raises Speed in Hail/Snow."),
#endif
        .aiRating = 5,
    },

    [ABILITY_LONG_REACH] =
    {
#if GERMAN
        .name = _("Langstrecke"),
        .description = COMPOUND_STRING("Greift nie direkt an."),
#else
        .name = _("LONG REACH"),
        .description = COMPOUND_STRING("Never makes contact."),
#endif
        .aiRating = 3,
    },

    [ABILITY_LIQUID_VOICE] =
    {
#if GERMAN
        .name = _("Plätscherstimme"),
        .description = COMPOUND_STRING("Schall-Att. werden Wasser."),
#else
        .name = _("LIQUID VOICE"),
        .description = COMPOUND_STRING("Makes sound moves Water."),
#endif
        .aiRating = 5,
    },

    [ABILITY_TRIAGE] =
    {
#if GERMAN
        .name = _("Heilwandel"),
        .description = COMPOUND_STRING("Heil-Att. treffen zuerst."),
#else
        .name = _("TRIAGE"),
        .description = COMPOUND_STRING("Healing moves go first."),
#endif
        .aiRating = 7,
    },

    [ABILITY_GALVANIZE] =
    {
#if GERMAN
        .name = _("Elektrohaut"),
        .description = COMPOUND_STRING("Normal-Att. werden Elektro."),
#else
        .name = _("GALVANIZE"),
        .description = COMPOUND_STRING("Normal moves turn Electric."),
#endif
        .aiRating = 8,
    },

    [ABILITY_SURGE_SURFER] =
    {
#if GERMAN
        .name = _("Surf-Schweif"),
        .description = COMPOUND_STRING("Elektrofeld: doppelte Init."),
#else
        .name = _("SURGE SURFER"),
        .description = COMPOUND_STRING("Faster on electricity."),
#endif
        .aiRating = 4,
    },

    [ABILITY_SCHOOLING] =
    {
#if GERMAN
        .name = _("Fischschwarm"),
        .description = COMPOUND_STRING("Bildet b. viel KP e. Schwarm"),
#else
        .name = _("SCHOOLING"),
        .description = COMPOUND_STRING("Forms a school when strong."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_DISGUISE] =
    {
#if GERMAN
        .name = _("Kostümspuk"),
        .description = COMPOUND_STRING("Wehrt einen Angriff ab."),
#else
        .name = _("DISGUISE"),
        .description = COMPOUND_STRING("Decoy protects it once."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_BATTLE_BOND] =
    {
#if GERMAN
        .name = _("Freundschaftsakt"),
        .description = COMPOUND_STRING("K.O. bringt die Ash-Form."),
#else
        .name = _("BATTLE BOND"),
        .description = COMPOUND_STRING("Changes form after a KO."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_CONSTRUCT] =
    {
#if GERMAN
        .name = _("Scharwandel"),
        .description = COMPOUND_STRING("Zellen helfen b. halben KP."),
#else
        .name = _("POWER CONSTRUCT"),
        .description = COMPOUND_STRING("Cells aid it when weakened."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_CORROSION] =
    {
#if GERMAN
        .name = _("Korrosion"),
        .description = COMPOUND_STRING("Vergiftet auch Stahl, Gift."),
#else
        .name = _("CORROSION"),
        .description = COMPOUND_STRING("Poisons any type."),
#endif
        .aiRating = 5,
    },

    [ABILITY_COMATOSE] =
    {
#if GERMAN
        .name = _("Dauerschlaf"),
        .description = COMPOUND_STRING("Ist immer im Halbschlaf."),
#else
        .name = _("COMATOSE"),
        .description = COMPOUND_STRING("Always drowsing."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_QUEENLY_MAJESTY] =
    {
#if GERMAN
        .name = _("Majestät"),
        .description = COMPOUND_STRING("Schützt vor Erstschlag."),
#else
        .name = _("QUEENLY MAJESTY"),
        .description = COMPOUND_STRING("Protects from priority."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_INNARDS_OUT] =
    {
#if GERMAN
        .name = _("Magenkrempler"),
        .description = COMPOUND_STRING("Schadet Gegner bei K.O."),
#else
        .name = _("INNARDS OUT"),
        .description = COMPOUND_STRING("Hurts foe when defeated."),
#endif
        .aiRating = 5,
    },

    [ABILITY_DANCER] =
    {
#if GERMAN
        .name = _("Tänzer"),
        .description = COMPOUND_STRING("Macht Tanz-Attacken mit."),
#else
        .name = _("DANCER"),
        .description = COMPOUND_STRING("Dances along with others."),
#endif
        .aiRating = 5,
    },

    [ABILITY_BATTERY] =
    {
#if GERMAN
        .name = _("Batterie"),
        .description = COMPOUND_STRING("Stärkt Sp.-Att. der Partner"),
#else
        .name = _("BATTERY"),
        .description = COMPOUND_STRING("Boosts ally's Sp. Atk."),
#endif
        .aiRating = 0,
    },

    [ABILITY_FLUFFY] =
    {
#if GERMAN
        .name = _("Flauschigkeit"),
        .description = COMPOUND_STRING("Halb Kontakt, extra Feuer"),
#else
        .name = _("FLUFFY"),
        .description = COMPOUND_STRING("Tougher but flammable."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_DAZZLING] =
    {
#if GERMAN
        .name = _("Buntkörper"),
        .description = COMPOUND_STRING("Schützt vor Erstschlag."),
#else
        .name = _("DAZZLING"),
        .description = COMPOUND_STRING("Protects from priority."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SOUL_HEART] =
    {
#if GERMAN
        .name = _("Seelenherz"),
        .description = COMPOUND_STRING("Jedes K.O. erhöht Sp.Ang."),
#else
        .name = _("SOUL-HEART"),
        .description = COMPOUND_STRING("KOs raise Sp. Atk."),
#endif
        .aiRating = 7,
    },

    [ABILITY_TANGLING_HAIR] =
    {
#if GERMAN
        .name = _("Lockenkopf"),
        .description = COMPOUND_STRING("Senkt Init. b. Berührung."),
#else
        .name = _("TANGLING HAIR"),
        .description = COMPOUND_STRING("Lowers Speed on contact."),
#endif
        .aiRating = 5,
    },

    [ABILITY_RECEIVER] =
    {
#if GERMAN
        .name = _("Receiver"),
        .description = COMPOUND_STRING("Erhält Fähigkeit b. K.O."),
#else
        .name = _("RECEIVER"),
        .description = COMPOUND_STRING("Copies ally's ability."),
#endif
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POWER_OF_ALCHEMY] =
    {
#if GERMAN
        .name = _("Chemiekraft"),
        .description = COMPOUND_STRING("Erhält Fähigkeit b. K.O."),
#else
        .name = _("POWER OF ALCHEMY"),
        .description = COMPOUND_STRING("Copies ally's ability."),
#endif
        .aiRating = 0,
        .cantBeCopied = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_BEAST_BOOST] =
    {
#if GERMAN
        .name = _("Bestien-Boost"),
        .description = COMPOUND_STRING("K.O. erhöht besten Wert."),
#else
        .name = _("BEAST BOOST"),
        .description = COMPOUND_STRING("KOs boost best stat."),
#endif
        .aiRating = 7,
    },

    [ABILITY_RKS_SYSTEM] =
    {
#if GERMAN
        .name = _("Alpha-System"),
        .description = COMPOUND_STRING("Typ je nach getrag. Disc."),
#else
        .name = _("RKS SYSTEM"),
        .description = COMPOUND_STRING("Memories change its type."),
#endif
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_ELECTRIC_SURGE] =
    {
#if GERMAN
        .name = _("Elektro-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Elektrofeld."),
#else
        .name = _("ELECTRIC SURGE"),
        .description = COMPOUND_STRING("Field becomes Electric."),
#endif
        .aiRating = 8,
    },

    [ABILITY_PSYCHIC_SURGE] =
    {
#if GERMAN
        .name = _("Psycho-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Psychofeld."),
#else
        .name = _("PSYCHIC SURGE"),
        .description = COMPOUND_STRING("Field becomes weird."),
#endif
        .aiRating = 8,
    },

    [ABILITY_MISTY_SURGE] =
    {
#if GERMAN
        .name = _("Nebel-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Nebelfeld."),
#else
        .name = _("MISTY SURGE"),
        .description = COMPOUND_STRING("Field becomes misty."),
#endif
        .aiRating = 8,
    },

    [ABILITY_GRASSY_SURGE] =
    {
#if GERMAN
        .name = _("Gras-Erzeuger"),
        .description = COMPOUND_STRING("Erzeugt ein Grasfeld."),
#else
        .name = _("GRASSY SURGE"),
        .description = COMPOUND_STRING("Field becomes grassy."),
#endif
        .aiRating = 8,
    },

    [ABILITY_FULL_METAL_BODY] =
    {
#if GERMAN
        .name = _("Metallprotektor"),
        .description = COMPOUND_STRING("Werte können nicht sinken."),
#else
        .name = _("FULL METAL BODY"),
        .description = COMPOUND_STRING("Prevents stat reduction."),
#endif
        .aiRating = 4,
    },

    [ABILITY_SHADOW_SHIELD] =
    {
#if GERMAN
        .name = _("Phantomschutz"),
        .description = COMPOUND_STRING("Weniger Schaden b. voll KP"),
#else
        .name = _("SHADOW SHIELD"),
        .description = COMPOUND_STRING("Halves damage at full HP."),
#endif
        .aiRating = 8,
    },

    [ABILITY_PRISM_ARMOR] =
    {
#if GERMAN
        .name = _("Prismarüstung"),
        .description = COMPOUND_STRING("Schwächt sehr eff. Att."),
#else
        .name = _("PRISM ARMOR"),
        .description = COMPOUND_STRING("Weakens “supereffective”."),
#endif
        .aiRating = 6,
    },

    [ABILITY_NEUROFORCE] =
    {
#if GERMAN
        .name = _("Zerebralmacht"),
        .description = COMPOUND_STRING("Stärkt sehr effektive Att."),
#else
        .name = _("NEUROFORCE"),
        .description = COMPOUND_STRING("Ups “supereffective”."),
#endif
        .aiRating = 6,
    },

    [ABILITY_INTREPID_SWORD] =
    {
#if GERMAN
        .name = _("Kühnes Schwert"),
        .description = COMPOUND_STRING("Erhöht Angr. b. Antritt."),
#else
        .name = _("INTREPID SWORD"),
        .description = COMPOUND_STRING("Ups Attack on entry."),
#endif
        .aiRating = 3,
    },

    [ABILITY_DAUNTLESS_SHIELD] =
    {
#if GERMAN
        .name = _("Wackerer Schild"),
        .description = COMPOUND_STRING("Erhöht Vert. b. Antritt."),
#else
        .name = _("DAUNTLESS SHIELD"),
        .description = COMPOUND_STRING("Ups Defense on entry."),
#endif
        .aiRating = 3,
    },

    [ABILITY_LIBERO] =
    {
#if GERMAN
        .name = _("Libero"),
        .description = COMPOUND_STRING("Nimmt den Typ der Att. an."),
#else
        .name = _("LIBERO"),
        .description = COMPOUND_STRING("Changes type to move's."),
#endif
    },

    [ABILITY_BALL_FETCH] =
    {
#if GERMAN
        .name = _("Apport"),
        .description = COMPOUND_STRING("Holt den ersten Ball zurück"),
#else
        .name = _("BALL FETCH"),
        .description = COMPOUND_STRING("Fetches failed Poké Ball."),
#endif
        .aiRating = 0,
    },

    [ABILITY_COTTON_DOWN] =
    {
#if GERMAN
        .name = _("Wollflaum"),
        .description = COMPOUND_STRING("Treffer senkt Init. aller."),
#else
        .name = _("COTTON DOWN"),
        .description = COMPOUND_STRING("Lower Speed of all when hit."),
#endif
        .aiRating = 3,
    },

    [ABILITY_PROPELLER_TAIL] =
    {
#if GERMAN
        .name = _("Schraubflosse"),
        .description = COMPOUND_STRING("Ignoriert Att.-Umleitung."),
#else
        .name = _("PROPELLER TAIL"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
#endif
        .aiRating = 2,
    },

    [ABILITY_MIRROR_ARMOR] =
    {
#if GERMAN
        .name = _("Spiegelrüstung"),
        .description = COMPOUND_STRING("Lenkt Wertesenkung zurück"),
#else
        .name = _("MIRROR ARMOR"),
        .description = COMPOUND_STRING("Reflect stat decreases."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_GULP_MISSILE] =
    {
#if GERMAN
        .name = _("Würggeschoss"),
        .description = COMPOUND_STRING("Speit b. Treffer Beute aus."),
#else
        .name = _("GULP MISSILE"),
        .description = COMPOUND_STRING("If hit, spits prey from sea."),
#endif
        .aiRating = 3,
        .cantBeSwapped = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeCopied = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeTraced = B_UPDATED_ABILITY_DATA < GEN_9,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_STALWART] =
    {
#if GERMAN
        .name = _("Stahlrückgrat"),
        .description = COMPOUND_STRING("Ignoriert Att.-Umleitung."),
#else
        .name = _("STALWART"),
        .description = COMPOUND_STRING("Ignores foe's redirection."),
#endif
        .aiRating = 2,
    },

    [ABILITY_STEAM_ENGINE] =
    {
#if GERMAN
        .name = _("Dampfantrieb"),
        .description = COMPOUND_STRING("Feuer, Wasser: Init. stark."),
#else
        .name = _("STEAM ENGINE"),
        .description = COMPOUND_STRING("Fire or Water hits up Speed."),
#endif
        .aiRating = 3,
    },

    [ABILITY_PUNK_ROCK] =
    {
#if GERMAN
        .name = _("Punk Rock"),
        .description = COMPOUND_STRING("Stärkt Schall, halbiert sie."),
#else
        .name = _("PUNK ROCK"),
        .description = COMPOUND_STRING("Ups and resists sound."),
#endif
        .aiRating = 2,
        .breakable = TRUE,
    },

    [ABILITY_SAND_SPIT] =
    {
#if GERMAN
        .name = _("Sandspeier"),
        .description = COMPOUND_STRING("Treffer erzeugt Sandsturm."),
#else
        .name = _("SAND SPIT"),
        .description = COMPOUND_STRING("Creates a sandstorm if hit."),
#endif
        .aiRating = 5,
    },

    [ABILITY_ICE_SCALES] =
    {
#if GERMAN
        .name = _("Eisflügelstaub"),
        .description = COMPOUND_STRING("Halbiert Spezial-Schaden."),
#else
        .name = _("ICE SCALES"),
        .description = COMPOUND_STRING("Halves special damage."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_RIPEN] =
    {
#if GERMAN
        .name = _("Heranreifen"),
        .description = COMPOUND_STRING("Verdoppelt Beeren-Wirkung."),
#else
        .name = _("RIPEN"),
        .description = COMPOUND_STRING("Doubles effect of Berries."),
#endif
        .aiRating = 4,
    },

    [ABILITY_ICE_FACE] =
    {
#if GERMAN
        .name = _("Tiefkühlkopf"),
        .description = COMPOUND_STRING("Blockt einen phys. Angriff."),
#else
        .name = _("ICE FACE"),
        .description = COMPOUND_STRING("Hail or Snow renew free hit."),
#endif
        .aiRating = 4,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .breakable = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_POWER_SPOT] =
    {
#if GERMAN
        .name = _("Kraftquelle"),
        .description = COMPOUND_STRING("Stärkt Att. der Nachbarn."),
#else
        .name = _("POWER SPOT"),
        .description = COMPOUND_STRING("Powers up ally moves."),
#endif
        .aiRating = 2,
    },

    [ABILITY_MIMICRY] =
    {
#if GERMAN
        .name = _("Mimese"),
        .description = COMPOUND_STRING("Typ richtet sich nach Feld."),
#else
        .name = _("MIMICRY"),
        .description = COMPOUND_STRING("Changes type on terrain."),
#endif
        .aiRating = 2,
    },

    [ABILITY_SCREEN_CLEANER] =
    {
#if GERMAN
        .name = _("Hemmungslos"),
        .description = COMPOUND_STRING("Hebt Schilde b. Antritt auf."),
#else
        .name = _("SCREEN CLEANER"),
        .description = COMPOUND_STRING("Removes walls of light."),
#endif
        .aiRating = 3,
    },

    [ABILITY_STEELY_SPIRIT] =
    {
#if GERMAN
        .name = _("Stählerner Wille"),
        .description = COMPOUND_STRING("Stärkt Stahl-Att. im Team."),
#else
        .name = _("STEELY SPIRIT"),
        .description = COMPOUND_STRING("Boosts ally's Steel moves."),
#endif
        .aiRating = 2,
    },

    [ABILITY_PERISH_BODY] =
    {
#if GERMAN
        .name = _("Unheilskörper"),
        .description = COMPOUND_STRING("Kontakt: beide n. 3 Rd. K.O."),
#else
        .name = _("PERISH BODY"),
        .description = COMPOUND_STRING("Foe faints in 3 turns if hit."),
#endif
        .aiRating = -1,
    },

    [ABILITY_WANDERING_SPIRIT] =
    {
#if GERMAN
        .name = _("Rastlose Seele"),
        .description = COMPOUND_STRING("Tauscht Fähigk. b. Kontakt."),
#else
        .name = _("WANDERING SPIRIT"),
        .description = COMPOUND_STRING("Trade abilities on contact."),
#endif
        .aiRating = 2,
    },

    [ABILITY_GORILLA_TACTICS] =
    {
#if GERMAN
        .name = _("Affenfokus"),
        .description = COMPOUND_STRING("Mehr Angr., nur eine Att."),
#else
        .name = _("GORILLA TACTICS"),
        .description = COMPOUND_STRING("Ups Attack and locks move."),
#endif
        .aiRating = 4,
    },

    [ABILITY_NEUTRALIZING_GAS] =
    {
#if GERMAN
        .name = _("Reaktionsgas"),
        .description = COMPOUND_STRING("Hebt alle Fähigkeiten auf."),
#else
        .name = _("NEUTRALIZING GAS"),
        .description = COMPOUND_STRING("All Abilities are nullified."),
#endif
        .aiRating = 5,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_PASTEL_VEIL] =
    {
#if GERMAN
        .name = _("Pastellhülle"),
        .description = COMPOUND_STRING("Schützt Team vor Gift."),
#else
        .name = _("PASTEL VEIL"),
        .description = COMPOUND_STRING("Protects team from poison."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_HUNGER_SWITCH] =
    {
#if GERMAN
        .name = _("Heißhunger"),
        .description = COMPOUND_STRING("Wechselt jede Runde Form."),
#else
        .name = _("HUNGER SWITCH"),
        .description = COMPOUND_STRING("Changes form each turn."),
#endif
        .aiRating = 2,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUICK_DRAW] =
    {
#if GERMAN
        .name = _("Schnellschuss"),
        .description = COMPOUND_STRING("Handelt gelegentl. zuerst."),
#else
        .name = _("QUICK DRAW"),
        .description = COMPOUND_STRING("Moves first occasionally."),
#endif
        .aiRating = 4,
    },

    [ABILITY_UNSEEN_FIST] =
    {
#if GERMAN
        .name = _("Verborgene Faust"),
        .description = COMPOUND_STRING("Kontakt-Att. trotz Schutz."),
#else
        .name = _("UNSEEN FIST"),
        .description = COMPOUND_STRING("Contact evades protection."),
#endif
        .aiRating = 6,
    },

    [ABILITY_CURIOUS_MEDICINE] =
    {
#if GERMAN
        .name = _("Kuriose Arznei"),
        .description = COMPOUND_STRING("Hebt Werteänderungen auf."),
#else
        .name = _("CURIOUS MEDICINE"),
        .description = COMPOUND_STRING("Remove ally's stat changes."),
#endif
        .aiRating = 3,
    },

    [ABILITY_TRANSISTOR] =
    {
#if GERMAN
        .name = _("Transistor"),
        .description = COMPOUND_STRING("Stärkt Elektro-Attacken."),
#else
        .name = _("TRANSISTOR"),
        .description = COMPOUND_STRING("Ups Electric-type moves."),
#endif
        .aiRating = 6,
    },

    [ABILITY_DRAGONS_MAW] =
    {
#if GERMAN
        .name = _("Drachenkiefer"),
        .description = COMPOUND_STRING("Stärkt Drachen-Attacken."),
#else
        .name = _("DRAGON'S MAW"),
        .description = COMPOUND_STRING("Ups Dragon-type moves."),
#endif
        .aiRating = 6,
    },

    [ABILITY_CHILLING_NEIGH] =
    {
#if GERMAN
        .name = _("Helles Wiehern"),
        .description = COMPOUND_STRING("K.O. erhöht den Angriff."),
#else
        .name = _("CHILLING NEIGH"),
        .description = COMPOUND_STRING("KOs boost Attack stat."),
#endif
        .aiRating = 7,
    },

    [ABILITY_GRIM_NEIGH] =
    {
#if GERMAN
        .name = _("Dunkles Wiehern"),
        .description = COMPOUND_STRING("K.O. erhöht den Sp.Ang."),
#else
        .name = _("GRIM NEIGH"),
        .description = COMPOUND_STRING("KOs boost Sp. Atk stat."),
#endif
        .aiRating = 7,
    },

    [ABILITY_AS_ONE_ICE_RIDER] =
    {
#if GERMAN
        .name = _("Reitgespann"),
        .description = COMPOUND_STRING("Bedroher u. Helles Wiehern"),
#else
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Unnerve and Chilling Neigh."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_AS_ONE_SHADOW_RIDER] =
    {
#if GERMAN
        .name = _("Reitgespann"),
        .description = COMPOUND_STRING("Bedroher u. Dunkles Wiehern"),
#else
        .name = _("AS ONE"),
        .description = COMPOUND_STRING("Unnerve and Grim Neigh."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_LINGERING_AROMA] =
    {
#if GERMAN
        .name = _("Duftschwade"),
        .description = COMPOUND_STRING("Überträgt sich b. Kontakt."),
#else
        .name = _("LINGERING AROMA"),
        .description = COMPOUND_STRING("Spreads with contact."),
#endif
        .aiRating = 5,
    },

    [ABILITY_SEED_SOWER] =
    {
#if GERMAN
        .name = _("Streusaat"),
        .description = COMPOUND_STRING("Treffer erzeugt Grasfeld."),
#else
        .name = _("SEED SOWER"),
        .description = COMPOUND_STRING("Affects terrain when hit."),
#endif
        .aiRating = 5,
    },

    [ABILITY_THERMAL_EXCHANGE] =
    {
#if GERMAN
        .name = _("Thermowandel"),
        .description = COMPOUND_STRING("Feuer-Att. erhöht den Angr."),
#else
        .name = _("THERMAL EXCHANGE"),
        .description = COMPOUND_STRING("Fire hits up Attack."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_ANGER_SHELL] =
    {
#if GERMAN
        .name = _("Wutpanzer"),
        .description = COMPOUND_STRING("Halbe KP: Wut ändert Werte."),
#else
        .name = _("ANGER SHELL"),
        .description = COMPOUND_STRING("Gets angry at half HP."),
#endif
        .aiRating = 3,
    },

    [ABILITY_PURIFYING_SALT] =
    {
#if GERMAN
        .name = _("Läutersalz"),
        .description = COMPOUND_STRING("Schutz vor Statusproblem."),
#else
        .name = _("PURIFYING SALT"),
        .description = COMPOUND_STRING("Protected by pure salts."),
#endif
        .aiRating = 6,
        .breakable = TRUE,
    },

    [ABILITY_WELL_BAKED_BODY] =
    {
#if GERMAN
        .name = _("Knusperkruste"),
        .description = COMPOUND_STRING("Feuer-Att. hebt Vert. sehr."),
#else
        .name = _("WELL-BAKED BODY"),
        .description = COMPOUND_STRING("Strengthened by Fire."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_WIND_RIDER] =
    {
#if GERMAN
        .name = _("Windreiter"),
        .description = COMPOUND_STRING("Wind-Att. erhöht Angriff."),
#else
        .name = _("WIND RIDER"),
        .description = COMPOUND_STRING("Ups Attack if hit by wind."),
#endif
        .aiRating = 4,
        .breakable = TRUE,
    },

    [ABILITY_GUARD_DOG] =
    {
#if GERMAN
        .name = _("Wachhund"),
        .description = COMPOUND_STRING("Bedrohung erhöht Angriff."),
#else
        .name = _("GUARD DOG"),
        .description = COMPOUND_STRING("Cannot be intimidated."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ROCKY_PAYLOAD] =
    {
#if GERMAN
        .name = _("Steinträger"),
        .description = COMPOUND_STRING("Stärkt Gesteins-Attacken."),
#else
        .name = _("ROCKY PAYLOAD"),
        .description = COMPOUND_STRING("Powers up Rock moves."),
#endif
        .aiRating = 6,
    },

    [ABILITY_WIND_POWER] =
    {
#if GERMAN
        .name = _("Windkraft"),
        .description = COMPOUND_STRING("Wind-Att. lädt das Pkmn auf"),
#else
        .name = _("WIND POWER"),
        .description = COMPOUND_STRING("Gets charged by wind."),
#endif
        .aiRating = 4,
    },

    [ABILITY_ZERO_TO_HERO] =
    {
#if GERMAN
        .name = _("Superwechsel"),
        .description = COMPOUND_STRING("Heldenform b. Auswechseln."),
#else
        .name = _("ZERO TO HERO"),
        .description = COMPOUND_STRING("Changes form on switch out."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_COMMANDER] =
    {
#if GERMAN
        .name = _("Kommandant"),
        .description = COMPOUND_STRING("Springt Heerashai ins Maul."),
#else
        .name = _("COMMANDER"),
        .description = COMPOUND_STRING("Commands from Dondozo."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_ELECTROMORPHOSIS] =
    {
#if GERMAN
        .name = _("Dynamo"),
        .description = COMPOUND_STRING("Treffer lädt das Pkmn auf."),
#else
        .name = _("ELECTROMORPHOSIS"),
        .description = COMPOUND_STRING("Gets Charged when hit."),
#endif
        .aiRating = 5,
    },

    [ABILITY_PROTOSYNTHESIS] =
    {
#if GERMAN
        .name = _("Paläosynthese"),
        .description = COMPOUND_STRING("Sonne stärkt besten Wert."),
#else
        .name = _("PROTOSYNTHESIS"),
        .description = COMPOUND_STRING("Sun boosts best stat."),
#endif
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_QUARK_DRIVE] =
    {
#if GERMAN
        .name = _("Quantenantrieb"),
        .description = COMPOUND_STRING("E-Feld stärkt besten Wert."),
#else
        .name = _("QUARK DRIVE"),
        .description = COMPOUND_STRING("Elec. field ups best stat."),
#endif
        .aiRating = 7,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_GOOD_AS_GOLD] =
    {
#if GERMAN
        .name = _("Goldkörper"),
        .description = COMPOUND_STRING("Schutz vor Status-Att."),
#else
        .name = _("GOOD AS GOLD"),
        .description = COMPOUND_STRING("Avoids status moves."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_VESSEL_OF_RUIN] =
    {
#if GERMAN
        .name = _("Unheilsgefäß"),
        .description = COMPOUND_STRING("Senkt gegn. Sp.Ang."),
#else
        .name = _("VESSEL OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' sp. damage."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_SWORD_OF_RUIN] =
    {
#if GERMAN
        .name = _("Unheilsschwert"),
        .description = COMPOUND_STRING("Senkt gegnerische Vert."),
#else
        .name = _("SWORD OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' Defense."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_TABLETS_OF_RUIN] =
    {
#if GERMAN
        .name = _("Unheilstafeln"),
        .description = COMPOUND_STRING("Senkt gegner. Angriff."),
#else
        .name = _("TABLETS OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' damage."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_BEADS_OF_RUIN] =
    {
#if GERMAN
        .name = _("Unheilsjuwelen"),
        .description = COMPOUND_STRING("Senkt gegn. Sp.Vert."),
#else
        .name = _("BEADS OF RUIN"),
        .description = COMPOUND_STRING("Lowers foes' Sp. Defense."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_ORICHALCUM_PULSE] =
    {
#if GERMAN
        .name = _("Orichalkum-Puls"),
        .description = COMPOUND_STRING("Erzeugt Sonne, stärkt Angr."),
#else
        .name = _("ORICHALCUM PULSE"),
        .description = COMPOUND_STRING("Summons sunlight in battle."),
#endif
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_HADRON_ENGINE] =
    {
#if GERMAN
        .name = _("Hadronen-Motor"),
        .description = COMPOUND_STRING("Erzeugt Feld, hebt Sp.Ang."),
#else
        .name = _("HADRON ENGINE"),
        .description = COMPOUND_STRING("Field becomes Electric."),
#endif
        .aiRating = 8,
        .cantBeSwapped = TRUE,
        .cantBeCopied = TRUE,
        .cantBeOverwritten = TRUE,
    },

    [ABILITY_OPPORTUNIST] =
    {
#if GERMAN
        .name = _("Profiteur"),
        .description = COMPOUND_STRING("Kopiert gegn. Steigerung."),
#else
        .name = _("OPPORTUNIST"),
        .description = COMPOUND_STRING("Copies foe's stat change."),
#endif
        .aiRating = 5,
    },

    [ABILITY_CUD_CHEW] =
    {
#if GERMAN
        .name = _("Wiederkäuer"),
        .description = COMPOUND_STRING("Isst die Beere ein 2. Mal."),
#else
        .name = _("CUD CHEW"),
        .description = COMPOUND_STRING("Eats a used berry again."),
#endif
        .aiRating = 4,
    },

    [ABILITY_SHARPNESS] =
    {
#if GERMAN
        .name = _("Scharfkantig"),
        .description = COMPOUND_STRING("Stärkt Schnitt-Attacken."),
#else
        .name = _("SHARPNESS"),
        .description = COMPOUND_STRING("Strengthens slicing moves."),
#endif
        .aiRating = 7,
    },

    [ABILITY_SUPREME_OVERLORD] =
    {
#if GERMAN
        .name = _("Feldherr"),
        .description = COMPOUND_STRING("Je mehr K.O., desto stärker."),
#else
        .name = _("SUPREME OVERLORD"),
        .description = COMPOUND_STRING("Inherits fallen's strength."),
#endif
        .aiRating = 6,
    },

    [ABILITY_COSTAR] =
    {
#if GERMAN
        .name = _("Synchronauftritt"),
        .description = COMPOUND_STRING("Kopiert Werte des Partners."),
#else
        .name = _("COSTAR"),
        .description = COMPOUND_STRING("Copies ally's stat changes."),
#endif
        .aiRating = 5,
    },

    [ABILITY_TOXIC_DEBRIS] =
    {
#if GERMAN
        .name = _("Giftbelag"),
        .description = COMPOUND_STRING("Treffer legt Giftspitzen."),
#else
        .name = _("TOXIC DEBRIS"),
        .description = COMPOUND_STRING("Throws poison spikes if hit."),
#endif
        .aiRating = 4,
    },

    [ABILITY_ARMOR_TAIL] =
    {
#if GERMAN
        .name = _("Schweifrüstung"),
        .description = COMPOUND_STRING("Schützt vor Erstschlag."),
#else
        .name = _("ARMOR TAIL"),
        .description = COMPOUND_STRING("Protects from priority."),
#endif
        .aiRating = 5,
        .breakable = TRUE,
    },

    [ABILITY_EARTH_EATER] =
    {
#if GERMAN
        .name = _("Bodenschmaus"),
        .description = COMPOUND_STRING("Boden-Att. heilt das Pkmn."),
#else
        .name = _("EARTH EATER"),
        .description = COMPOUND_STRING("Eats ground to heal HP."),
#endif
        .aiRating = 7,
        .breakable = TRUE,
    },

    [ABILITY_MYCELIUM_MIGHT] =
    {
#if GERMAN
        .name = _("Myzelienkraft"),
        .description = COMPOUND_STRING("Status-Att. spät u. sicher."),
#else
        .name = _("MYCELIUM MIGHT"),
        .description = COMPOUND_STRING("Status moves never fail."),
#endif
        .aiRating = 2,
    },

    [ABILITY_HOSPITALITY] =
    {
#if GERMAN
        .name = _("Gastlichkeit"),
        .description = COMPOUND_STRING("Heilt den Partner b. Antritt"),
#else
        .name = _("HOSPITALITY"),
        .description = COMPOUND_STRING("Restores ally's HP."),
#endif
        .aiRating = 5,
    },

    [ABILITY_MINDS_EYE] =
    {
#if GERMAN
        .name = _("Geistiges Auge"),
        .description = COMPOUND_STRING("Genauigkeit sinkt nicht."),
#else
        .name = _("MIND'S EYE"),
        .description = COMPOUND_STRING("Keen Eye and Scrappy."),
#endif
        .aiRating = 8,
        .breakable = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_TEAL_MASK] =
    {
#if GERMAN
        .name = _("Erinnerungskraft"),
        .description = COMPOUND_STRING("Maske erhöht die Init."),
#else
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Speed."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_HEARTHFLAME_MASK] =
    {
#if GERMAN
        .name = _("Erinnerungskraft"),
        .description = COMPOUND_STRING("Maske erhöht den Angriff."),
#else
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Attack."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_WELLSPRING_MASK] =
    {
#if GERMAN
        .name = _("Erinnerungskraft"),
        .description = COMPOUND_STRING("Maske erhöht die Sp.Vert."),
#else
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Sp. Def."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_EMBODY_ASPECT_CORNERSTONE_MASK] =
    {
#if GERMAN
        .name = _("Erinnerungskraft"),
        .description = COMPOUND_STRING("Maske erhöht die Vert."),
#else
        .name = _("EMBODY ASPECT"),
        .description = COMPOUND_STRING("Raises Defense."),
#endif
        .aiRating = 6,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TOXIC_CHAIN] =
    {
#if GERMAN
        .name = _("Giftkette"),
        .description = COMPOUND_STRING("Attacken vergiften evtl."),
#else
        .name = _("TOXIC CHAIN"),
        .description = COMPOUND_STRING("Moves can poison."),
#endif
        .aiRating = 8,
    },

    [ABILITY_SUPERSWEET_SYRUP] =
    {
#if GERMAN
        .name = _("Süßer Nektar"),
        .description = COMPOUND_STRING("Senkt Fluchtwert b. Antritt"),
#else
        .name = _("SUPERSWEET SYRUP"),
        .description = COMPOUND_STRING("Lowers the foe's Evasion."),
#endif
        .aiRating = 5,
    },

    [ABILITY_TERA_SHIFT] =
    {
#if GERMAN
        .name = _("Tera-Wandel"),
        .description = COMPOUND_STRING("Terakristallisiert b. Start."),
#else
        .name = _("TERA SHIFT"),
        .description = COMPOUND_STRING("Terastallizes upon entry."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .cantBeSuppressed = TRUE,
        .cantBeOverwritten = TRUE,
        .failsOnImposter = TRUE,
    },

    [ABILITY_TERA_SHELL] =
    {
#if GERMAN
        .name = _("Tera-Panzer"),
        .description = COMPOUND_STRING("Alles wenig eff. b. voll KP"),
#else
        .name = _("TERA SHELL"),
        .description = COMPOUND_STRING("Resists all at full HP."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
        .breakable = TRUE,
    },

    [ABILITY_TERAFORM_ZERO] =
    {
#if GERMAN
        .name = _("Teraforming Null"),
        .description = COMPOUND_STRING("Hebt Wetter und Feld auf."),
#else
        .name = _("TERAFORM ZERO"),
        .description = COMPOUND_STRING("Zeroes weather and terrain."),
#endif
        .aiRating = 10,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },

    [ABILITY_POISON_PUPPETEER] =
    {
#if GERMAN
        .name = _("Giftpuppenspiel"),
        .description = COMPOUND_STRING("Vergiftete werden verwirrt."),
#else
        .name = _("POISON PUPPETEER"),
        .description = COMPOUND_STRING("Confuses poisoned foes."),
#endif
        .aiRating = 8,
        .cantBeCopied = TRUE,
        .cantBeSwapped = TRUE,
        .cantBeTraced = TRUE,
    },
};
