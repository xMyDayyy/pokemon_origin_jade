Route47_hns_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN_HNS, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
#if GERMAN
	.string "Du kommst goldrichtig! Ich war gerade\n"
	.string "dabei, mich ein wenig einsam zu fühlen…\p"
	.string "Aber ein Kampf ist ein Kampf! Also los!$"
#else
	.string "Longing for others is...\n"
	.string "what it is. \p"
	.string "But battles are battles,\n"
	.string "so let's go!$"
#endif

Route47_Text_HikerBeaten::
#if GERMAN
	.string "Wuahahaha$"
#else
	.string "Wahaha!$"
#endif

Route47_Text_HikerAfter::
#if GERMAN
	.string "Nach einem Kampf sollte man immer mit\n"
	.string "einem Lachen auseinandergehen!$"
#else
	.string "After a battle you should always leave\n"
	.string "with a parting laugh!$"
#endif

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT_HNS, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
#if GERMAN
	.string "Wir haben’s nicht so mit\n"
	.string "Menschenmengen und zelten daher lieber\l"
	.string "im Freien. Geht es dir etwa genauso?$"
#else
	.string "I'm not good with large crowds, so\n"
	.string "I'm camping out here with my\l"
	.string "POKéMON!$"
#endif

Route47_Text_CamperBeaten::
#if GERMAN
	.string "Wir müssen wohl noch tiefer in\n"
	.string "die Berge gehen…$"
#else
	.string "I should be headed deeper into the\n"
	.string "mountain I guess...$"
#endif

Route47_Text_CamperAfter::
#if GERMAN
	.string "Tschüss!$"
#else
	.string "See ya!$"
#endif

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE_HNS, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
#if GERMAN
	.string "Thomas: Eins plus eins ist zwei.\p"
	.string "Aber wir zwei zusammen sind viel\n"
	.string "stärker!\p"
	.string "Katja: Wir zwei sind kein langweiliges\n"
	.string "Gespann!$"
#else
	.string "THOM: One plus one is two. But the\n"
	.string "two of us together is much\l"
	.string "stronger!\p"
	.string "KAE: The two of us aren't just some\n"
	.string "boring pair!$"
#endif

Route47_Text_Couple1Beaten::
#if GERMAN
	.string "Uwe: Damit hatte ich jetzt nicht\n"
	.string "gerechnet…$"
#else
	.string "THOM: That wasn't what I expected.\l"
	.string "KAE: You're unusual too!$"
#endif

Route47_Text_Couple1After1::
#if GERMAN
	.string "Uwe: Dass du so stark bist, hätte\n"
	.string "niemand ahnen können!$"
#else
	.string "THOM: It seems your power is\n"
	.string "impossible to predict!$"
#endif

Route47_Text_Couple1After2::
#if GERMAN
	.string "Nele: Ich habe dich für einen einfachen\n"
	.string "Trainer gehalten, aber du bist mehr!$"
#else
	.string "KAE: I figured you were an ordinary\n"
	.string "lone trainer. Boy was I wrong!$"
#endif

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA_HNS, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
#if GERMAN
	.string "David: Meine Freundin zu beschützen\n"
	.string "lässt mein Herz höherfliegen!\p"
	.string "Eva: Meine Gefühle für meinen Freund\n"
	.string "sind so weit und tief wie der Ozean!$"
#else
	.string "DUFF: Watching over my girlfriend\n"
	.string "makes my heart soar!\p"
	.string "EDA: My heart's feelings for my\n"
	.string "boyfriend are as wide and deep\l"
	.string "the ocean!$"
#endif

Route47_Text_Couple2Beaten::
#if GERMAN
	.string "David: Ich war dir nicht gewachsen…\n"
	.string "Eva: Du bist wirklich etwas Besonderes…$"
#else
	.string "DUFF: I was no match for you...\l"
	.string "EDA: You are really something...$"
#endif

Route47_Text_Couple2After1::
#if GERMAN
	.string "Piz: Ich danke dir für diesen\n"
	.string "vorbildlichen Kampf. Mögen all deine\l"
	.string "Wege geebnet sein!$"
#else
	.string "DUFF: Thank you for the awe-\n"
	.string "inspiring battle! Bye!$"
#endif

Route47_Text_Couple2After2::
#if GERMAN
	.string "Mari: Ich wünsche dir, dass auch du\n"
	.string "einen so wunderbaren Partner findest!$"
#else
	.string "EDA: You should really find a\n"
	.string "wonderful partner, too!$"
#endif

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
#if GERMAN
	.string "Oh, hallo!\p"
	.string "Über diesen Eingang soll man einmal\n"
	.string "in einen riesigen Turm gelangt sein,\l"
	.string "der bis über die Wolken reichte.\p"
	.string "Insbesondere seine ungewöhnliche\n"
	.string "Form soll Aufsehen erregt haben.\p"
	.string "Die Hälfte des Bauwerks wurde wohl\n"
	.string "in diesen Steilhang eingearbeitet.\p"
	.string "Der Turm ragte also nicht nur weit in\n"
	.string "den Himmel, sondern erstreckte sich\l"
	.string "auch bis tief unter die Erde!\p"
	.string "Und zu guter Letzt soll er auch noch\n"
	.string "mit dem Meer verbunden gewesen sein!\p"
	.string "Diese Ruinen waren einmal kolossal…\p"
	.string "Inzwischen liegt der Turm aber fast\n"
	.string "komplett in Trümmern. Viel mehr als der\l"
	.string "Eingang und der Mittelbau mit ein\l"
	.string "paar merkwürdigen Abbildungen ist\l"
	.string "nicht mehr von ihm übrig.$"
#else
	.string "Well, hello!\p"
	.string "It's said that past this hole used to\n"
	.string "be a huge tower reaching far into\l"
	.string "the sky.\p"
	.string "They say that it was a rather strange\n"
	.string "tower with half of it embedded\l"
	.string "in the cliff.\p"
	.string "It was not just a tall tower reaching\n"
	.string "up to the sky, but also reaching deep\l"
	.string "down underground!\p"
	.string "It is rumored that it even reached\n"
	.string "the bottom of the ocean!\p"
	.string "In short, the ruins used to connect\n"
	.string "the sky, the land, and the sea to\l"
	.string "each other…\p"
	.string "Most of the tower is now crumbled,\n"
	.string "and the only things that remain are\l"
	.string "the entrance and its interior, where\l"
	.string "you'll see strange patterns.$"
#endif

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
#if GERMAN
	.string "Lampi: Luuuu!$"
#else
	.string "CHINCHOU: Chou!$"
#endif
