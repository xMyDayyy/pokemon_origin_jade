MtMortar_1F_North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_1F_North_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_1F_North_OnTransition:
	callnative SetTimeBasedEncounters
	end

MtMortar_1F_North_EventScript_Item_MaxRepel::
    finditem ITEM_MAX_REPEL
    end

MtMortar_1F_North_EventScript_Item_EscapeRope::
    finditem ITEM_ESCAPE_ROPE
    end

MtMortar_1F_North_EventScript_Item_MaxPotion::
    finditem ITEM_MAX_POTION
    end

MtMortar_1F_North_EventScript_Item_Protector::
    finditem ITEM_PROTECTOR
    end

MtMortar_1F_North_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

MtMortar_1F_North_EventScript_Item_FullIncense::
    finditem ITEM_REVIVE
    end

MtMortar_1F_North_EventScript_Item_KingsRock::
    finditem ITEM_KINGS_ROCK
    end

MtMortar_1F_North_EventScript_Miller::
	trainerbattle_single TRAINER_MILLER_HNS, MountMortar2_Text_PokemaniacMillerSeen, MountMortar2_Text_PokemaniacMillerBeaten
	msgbox MountMortar2_Text_PokemaniacMillerAfter, MSGBOX_AUTOCLOSE
	end

MtMortar_1F_North_EventScript_Markus::
	trainerbattle_single TRAINER_MARKUS_HNS, MountMortar2_Text_SupernerdMarkusSeen, MountMortar2_Text_SupernerdMarkusBeaten
	msgbox MountMortar2_Text_SupernerdMarkusAfter, MSGBOX_AUTOCLOSE
	end

MountMortar2_Text_PokemaniacMillerSeen:
#if GERMAN
	.string "Wart’s ab! Diesmal verliere ich nicht!$"
#else
	.string "I'm not losing this time!$"
#endif

MountMortar2_Text_PokemaniacMillerBeaten:
#if GERMAN
	.string "Verloren… und das auch noch gegen ein\n"
	.string "Kind!$"
#else
	.string "I lost to some kid...?$"
#endif

MountMortar2_Text_PokemaniacMillerAfter:
#if GERMAN
	.string "Vorhin hat mich so ein komischer\n"
	.string "Karate-Typ zum Kampf herausgefordert.\l"
	.string "Der war vielleicht stark!\l"
	.string "Mir tun immer noch alle Knochen weh!\p"
	.string "Am Schluss blaffte er mich an: “Du\n"
	.string "brauchst mehr Training!”\l"
	.string "und verschwand im Berginneren.\l"
	.string "Was der wohl hier macht?$"
#else
	.string "A while back, this karate dude\n"
	.string "wanted to battle.\p"
	.string "He was ridiculously good.\n"
	.string "He just thrashed us silly.\p"
	.string "He went in deeper saying it\n"
	.string "was for his training.\p"
	.string "I wonder how he is?$"
#endif

MountMortar2_Text_SupernerdMarkusSeen:
#if GERMAN
	.string "He! Randalf!$"
#else
	.string "Hey! HUGH!$"
#endif

MountMortar2_Text_SupernerdMarkusBeaten:
#if GERMAN
	.string "Pardon.\n"
	.string "Ich habe dich mit jemandem verwechselt.$"
#else
	.string "I mistook you for someone\n"
	.string "else…$"
#endif

MountMortar2_Text_SupernerdMarkusAfter:
#if GERMAN
	.string "Ich wollte den Kesselberg erkunden,\n"
	.string "aber wurde von meinem Partner\l"
	.string "getrennt…\p"
	.string "Bist du einem Trainer begegnet,\n"
	.string "dessen Seemon Kaskade kann?$"
#else
	.string "I came to explore MT.MORTAR,\n"
	.string "but I got separated from my\l"
	.string "partner…\p"
	.string "Did you run into a trainer\n"
	.string "who uses a SEADRA that knows\l"
	.string "WATERFALL?$"
#endif
