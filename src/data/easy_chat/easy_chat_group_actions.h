const struct EasyChatWordInfo gEasyChatGroup_Actions[] = {
    [EC_INDEX(EC_WORD_MEETS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trifft"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BRAG),
#else
        .text = COMPOUND_STRING("MEETS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONCEDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Resignieren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKING),
#else
        .text = COMPOUND_STRING("CONCEDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGERS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Geben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANGERS),
#else
        .text = COMPOUND_STRING("GIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIVES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gibt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKE_UP),
#else
        .text = COMPOUND_STRING("GIVES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEARS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spielte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINT),
#else
        .text = COMPOUND_STRING("PLAYED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELIEVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLAYS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Spielt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OWN),
#else
        .text = COMPOUND_STRING("PLAYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BRAG),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLLECT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sammeln"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLEASE),
#else
        .text = COMPOUND_STRING("COLLECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wandern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINKS),
#else
        .text = COMPOUND_STRING("WALKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAPABLE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wandert"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOW),
#else
        .text = COMPOUND_STRING("WALKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAUSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAYS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sagt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEAR),
#else
        .text = COMPOUND_STRING("SAYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANGE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WENT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ging"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPEARS),
#else
        .text = COMPOUND_STRING("WENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOOSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SAID)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sagte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE),
#else
        .text = COMPOUND_STRING("SAID"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKE_UP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Aufwachen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAPABLE),
#else
        .text = COMPOUND_STRING("WAKE UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WAKES_UP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wacht auf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RELEASE),
#else
        .text = COMPOUND_STRING("WAKES UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONCEDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANGERS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ärgert"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE),
#else
        .text = COMPOUND_STRING("ANGERS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULDN_T),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lehren"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USE),
#else
        .text = COMPOUND_STRING("TEACH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPEAR),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lehrt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USES),
#else
        .text = COMPOUND_STRING("TEACHES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLEASE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Bitte"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARING),
#else
        .text = COMPOUND_STRING("PLEASE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EATS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEARN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lerne"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVES),
#else
        .text = COMPOUND_STRING("LEARN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHANGE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wechseln"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WENT),
#else
        .text = COMPOUND_STRING("CHANGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINTED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Story"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELIEVE),
#else
        .text = COMPOUND_STRING("STORY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGET),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRUST)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vertrauen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIDE),
#else
        .text = COMPOUND_STRING("TRUST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGETS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LAVISH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Großzügig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAVISH),
#else
        .text = COMPOUND_STRING("LAVISH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LISTENS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Hört"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAUSE),
#else
        .text = COMPOUND_STRING("LISTENS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIVES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEARING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gehört"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENS),
#else
        .text = COMPOUND_STRING("HEARING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEARING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAINS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trainiert"),
#else
        .text = COMPOUND_STRING("TRAINS"),
#endif
        .alphabeticalOrder = EC_INDEX(EC_WORD_IGNORANT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOOSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wählen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EATS),
#else
        .text = COMPOUND_STRING("CHOOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kommen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAME),
#else
        .text = COMPOUND_STRING("COME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOWS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAME)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kam"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAINTED),
#else
        .text = COMPOUND_STRING("CAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LAVISH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEARCH)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Suche"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COME),
#else
        .text = COMPOUND_STRING("SEARCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEARN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Machen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COULDN_T),
#else
        .text = COMPOUND_STRING("MAKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LISTENS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAUSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Grund"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORES),
#else
        .text = COMPOUND_STRING("CAUSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Wissen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACH),
#else
        .text = COMPOUND_STRING("KNOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KNOWS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Weiß"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHES),
#else
        .text = COMPOUND_STRING("KNOWS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEETS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFUSE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Weigern"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEARN),
#else
        .text = COMPOUND_STRING("REFUSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERDO),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Lagert"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRAISE),
#else
        .text = COMPOUND_STRING("STORES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OWN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BRAG)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Angeben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKE),
#else
        .text = COMPOUND_STRING("BRAG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYED),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IGNORANT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ignorant"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALKING),
#else
        .text = COMPOUND_STRING("IGNORANT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Denkt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALK),
#else
        .text = COMPOUND_STRING("THINKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLEASE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELIEVE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Glaube"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUN),
#else
        .text = COMPOUND_STRING("BELIEVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRAISE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLIDE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gleiten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUNS),
#else
        .text = COMPOUND_STRING("SLIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETEND),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EATS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Isst"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONCEDE),
#else
        .text = COMPOUND_STRING("EATS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFUSE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gebrauchen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAYS),
#else
        .text = COMPOUND_STRING("USE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RELEASE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Gebraucht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAID),
#else
        .text = COMPOUND_STRING("USES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUN),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_USING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verwenden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECT),
#else
        .text = COMPOUND_STRING("USING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RUNS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COULDN_T)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Können nicht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOKS),
#else
        .text = COMPOUND_STRING("COULDN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAID),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAPABLE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Fähig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEEP),
#else
        .text = COMPOUND_STRING("CAPABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SAYS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DISAPPEAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Verschwinde"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMACK),
#else
        .text = COMPOUND_STRING("DISAPPEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEARCH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEAR)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erscheinen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEPT),
#else
        .text = COMPOUND_STRING("APPEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THROW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Werfen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKS),
#else
        .text = COMPOUND_STRING("THROW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORRY)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sorge"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEES),
#else
        .text = COMPOUND_STRING("WORRY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEPT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlief"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORRY),
#else
        .text = COMPOUND_STRING("SLEPT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SLEEP)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlaf"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYS),
#else
        .text = COMPOUND_STRING("SLEEP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEEP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RELEASE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Freilassen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLAYED),
#else
        .text = COMPOUND_STRING("RELEASE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLEPT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DRINKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Trinkt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORY),
#else
        .text = COMPOUND_STRING("DRINKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SLIDE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUNS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rennt"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEK),
#else
        .text = COMPOUND_STRING("RUNS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMACK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RUN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Rennen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEARCH),
#else
        .text = COMPOUND_STRING("RUN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sehen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINS),
#else
        .text = COMPOUND_STRING("WORKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORY),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORKING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Arbeiten"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MEETS),
#else
        .text = COMPOUND_STRING("WORKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TAKE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALKING)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Reden"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DRINKS),
#else
        .text = COMPOUND_STRING("TALKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALK),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TALK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Redet"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERDO),
#else
        .text = COMPOUND_STRING("TALK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TALKING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SINK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Versenken"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGET),
#else
        .text = COMPOUND_STRING("SINK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACH),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMACK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schlag"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FORGETS),
#else
        .text = COMPOUND_STRING("SMACK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETEND)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vortäuschen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DISAPPEAR),
#else
        .text = COMPOUND_STRING("PRETEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRAISE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Loben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SINK),
#else
        .text = COMPOUND_STRING("PRAISE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THROW),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERDO)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Übertreiben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUST),
#else
        .text = COMPOUND_STRING("OVERDO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAINS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Zeigen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USING),
#else
        .text = COMPOUND_STRING("SHOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRUST),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOOKS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Schaut"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETEND),
#else
        .text = COMPOUND_STRING("LOOKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USE),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEES)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Sieht"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKES_UP),
#else
        .text = COMPOUND_STRING("SEES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USES),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEK)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Streben nach"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOOSE),
#else
        .text = COMPOUND_STRING("SEEK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_USING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OWN)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Besitzen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKING),
#else
        .text = COMPOUND_STRING("OWN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKE_UP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TAKE)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Ertragen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKS),
#else
        .text = COMPOUND_STRING("TAKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WAKES_UP),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOW)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erlauben"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANGE),
#else
        .text = COMPOUND_STRING("ALLOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGET)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vergessen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFUSE),
#else
        .text = COMPOUND_STRING("FORGET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FORGETS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Vergisst"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOWS),
#else
        .text = COMPOUND_STRING("FORGETS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WENT),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPEARS)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Erscheint"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THROW),
#else
        .text = COMPOUND_STRING("APPEARS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKING),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINT)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Besiegen"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KNOW),
#else
        .text = COMPOUND_STRING("FAINT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORKS),
#endif
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAINTED)] =
    {
#if GERMAN
        .text = COMPOUND_STRING("Kampfunfähig"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOW),
#else
        .text = COMPOUND_STRING("FAINTED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORRY),
#endif
        .enabled = TRUE,
    },
};
