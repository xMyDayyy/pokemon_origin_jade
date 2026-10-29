Route38_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route38_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route38_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route38_EventScript_Toby::
	trainerbattle_single TRAINER_TOBY_HNS, Route38_Text_BirdKeeperTobySeen, Route38_Text_BirdKeeperTobyBeaten
	msgbox Route38_Text_BirdKeeperTobyAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Chad::
	trainerbattle_single TRAINER_CHAD_HNS, Route38_Text_SchoolboyChad1Seen, Route38_Text_SchoolboyChad1Beaten, Route38_EventScript_RegisterChad
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchChad
	msgbox Route38_Text_SchoolboyChadAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterChad::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_ChadRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CHAD_HNS
	release
	end

Route38_EventScript_RematchChad::
	trainerbattle_rematch TRAINER_CHAD_HNS, Route38_Text_ChadRematchIntro, Route38_Text_ChadRematchDefeat
	msgbox Route38_Text_ChadPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Dana::
	trainerbattle_single TRAINER_DANA_HNS, Route38_Text_LassDana1Seen, Route38_Text_LassDana1Beaten, Route38_EventScript_RegisterDana
	goto_if_set FLAG_DANA_HAS_ITEM_HNS, Route38_EventScript_DanaGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route38_EventScript_RematchDana
	msgbox Route38_Text_LassDanaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_RegisterDana::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route38_Text_DanaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DANA_HNS
	release
	end

Route38_EventScript_RematchDana::
	trainerbattle_rematch TRAINER_DANA_HNS, Route38_Text_DanaRematchIntro, Route38_Text_DanaRematchDefeat
	msgbox Route38_Text_DanaPostRematch, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaGiveItem::
	msgbox Route38_Text_DanaHasItem, MSGBOX_DEFAULT
	giveitem VAR_DANA_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route38_EventScript_DanaNoRoom
	clearflag FLAG_DANA_HAS_ITEM_HNS
	msgbox Route38_Text_DanaGaveItem, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_DanaNoRoom::
	msgbox Route38_Text_DanaNoRoom, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_HNS, Route38_Text_BeautyValerieSeen, Route38_Text_BeautyValerieBeaten
	msgbox Route38_Text_BeautyValerieAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Harry::
	trainerbattle_single TRAINER_HARRY_HNS, Route38_Text_SailorHarrySeen, Route38_Text_SailorHarryBeaten
	msgbox Route38_Text_SailorHarryAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA_HNS, Route38_Text_BeautyOliviaSeen, Route38_Text_BeautyOliviaBeaten
	msgbox Route38_Text_BeautyOliviaAfter, MSGBOX_AUTOCLOSE
	end

Route38_EventScript_Sign1::
	lock
	msgbox Route38_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Sign2::
	lock
	msgbox Route38_Text_WaterSign, MSGBOX_SIGN
	closemessage
	release
	end

Route38_EventScript_Item_LaxIncense::
	finditem ITEM_LAX_INCENSE
	end

Route38_Text_BirdKeeperTobySeen:
#if GERMAN
	.string "Fliegt hoch hinaus, meine herrlichen\n"
	.string "Vogel-Pokémon!$"
#else
	.string "Fly high into the sky,\n"
	.string "my beloved bird POKéMON!$"
#endif

Route38_Text_BirdKeeperTobyBeaten:
#if GERMAN
	.string "Ich wünschte, ich könnte mich\n"
	.string "selbst in die Lüfte erheben.$"
#else
	.string "I feel like just flying\n"
	.string "away now.$"
#endif

Route38_Text_BirdKeeperTobyAfter:
#if GERMAN
	.string "Ich habe vor, in Anemonia City zu\n"
	.string "trainieren und meinen Pokémon das\l"
	.string "Fliegen beizubringen.$"
#else
	.string "I plan to train in CIANWOOD CITY\n"
	.string "to teach my POKéMON how to FLY.$"
#endif

Route38_Text_SchoolboyChad1Seen:
#if GERMAN
	.string "Jetzt probiere ich gleich mal etwas aus,\n"
	.string "das ich heute gelernt habe.$"
#else
	.string "Let me try something\n"
	.string "I learned today.$"
#endif

Route38_Text_SchoolboyChad1Beaten:
#if GERMAN
	.string "Ich fürchte, ich habe noch nicht\n"
	.string "genug gelernt.$"
#else
	.string "I didn't study enough,\n"
	.string "I guess.$"
#endif

Route38_Text_SchoolboyChadAfter:
#if GERMAN
	.string "Bei so vielen Klassenarbeiten bleibt\n"
	.string "mir nicht viel Zeit für Pokémon.\p"
	.string "Wenn ich also mal Zeit zum Spielen habe,\n"
	.string "bin ich mit voller Konzentration dabei.$"
#else
	.string "I have to take so many\n"
	.string "tests, I don't have much\l"
	.string "time for POKéMON.\p"
	.string "So when I do get to play,\n"
	.string "I really concentrate.$"
#endif

Route38_Text_ChadRegister:
#if GERMAN
    .string "Ich muss so viele Prüfungen schreiben,\n"
    .string "dass ich kaum Zeit für Pokémon habe.\p"
    .string "Darum konzentriere ich mich voll und\n"
    .string "ganz, wenn ich einmal spielen kann.$"
#else
	.string "I have to take so many\n"
	.string "tests, I don't have much\l"
	.string "time for POKéMON.\p"
	.string "So when I do get to play,\n"
	.string "I really concentrate.$"
#endif

Route38_Text_ChadRematchIntro:
#if GERMAN
	.string "Jetzt probiere ich gleich mal etwas aus,\n"
	.string "das ich heute gelernt habe.$"
#else
	.string "Let me try something\n"
	.string "I learned today.$"
#endif

Route38_Text_ChadRematchDefeat:
#if GERMAN
	.string "Ich fürchte, ich habe noch nicht genug\n"
	.string "gelernt.$"
#else
	.string "I didn't study enough,\n"
	.string "I guess.$"
#endif

Route38_Text_ChadPostRematch:
#if GERMAN
    .string "Ich muss so viele Prüfungen schreiben,\n"
    .string "dass ich kaum Zeit für Pokémon habe.\p"
    .string "Darum konzentriere ich mich voll und\n"
    .string "ganz, wenn ich einmal spielen kann.$"
#else
	.string "I have to take so many\n"
	.string "tests, I don't have much\l"
	.string "time for POKéMON.\p"
	.string "So when I do get to play,\n"
	.string "I really concentrate.$"
#endif

Route38_Text_LassDana1Seen:
#if GERMAN
	.string "Du scheinst gut mit Pokémon umgehen zu\n"
	.string "können.\p"
	.string "Wenn ja, gibst du mir ein paar Tipps?$"
#else
	.string "You seem to be good at\n"
	.string "POKéMON.\p"
	.string "If you are, how about\n"
	.string "giving me some advice?$"
#endif

Route38_Text_LassDana1Beaten:
#if GERMAN
	.string "Ich verstehe. So kämpfst du also.$"
#else
	.string "I see. So you can battle\n"
	.string "that way.$"
#endif

Route38_Text_LassDanaAfter:
#if GERMAN
	.string "Ich will dir auch etwas verraten!\p"
	.string "Die Milch von der Kuhmuh-Farm ist\n"
	.string "berühmt für ihren Geschmack!$"
#else
	.string "I know something good!\p"
	.string "MOOMOO FARM's milk is\n"
	.string "famous for its flavor.$"
#endif

Route38_Text_BeautyValerieSeen:
#if GERMAN
	.string "Hallöchen!\n"
	.string "Du bist doch bestimmt so nett\p"
	.string "und lässt mich mal sehen, welche\n"
	.string "Pokémon du dabeihast, oder?$"
#else
	.string "Hi! Aren't you a cute\n"
	.string "trainer!\p"
	.string "May I see your POKéMON?$"
#endif

Route38_Text_BeautyValerieBeaten:
#if GERMAN
	.string "Ich bin froh, dass ich dein\n"
	.string "Pokémon-Team sehen durfte!$"
#else
	.string "I'm glad I got to see\n"
	.string "your POKéMON!$"
#endif

Route38_Text_BeautyValerieAfter:
#if GERMAN
	.string "Wann immer ich Pokémon sehe, fühle ich\n"
	.string "mich so… entspannt.\l"
	.string "Da wird mir gleich ganz warm ums Herz.$"
#else
	.string "When I see POKéMON, it\n"
	.string "seems to soothe my nerves.$"
#endif

Route38_Text_SailorHarrySeen:
#if GERMAN
	.string "Ich habe die ganze Welt bereist.\n"
	.string "Deswegen kenne ich alle Pokémon-Arten!$"
#else
	.string "I've been overseas, so I\n"
	.string "know about all sorts of\l"
	.string "POKéMON!$"
#endif

Route38_Text_SailorHarryBeaten:
#if GERMAN
	.string "Deine Fähigkeiten sind Weltklasse!$"
#else
	.string "Your skill is world class!$"
#endif

Route38_Text_SailorHarryAfter:
#if GERMAN
	.string "Alle möglichen Menschen in allen\n"
	.string "möglichen Ländern leben glücklich\l"
	.string "zusammen mit den Pokémon.$"
#else
	.string "All kinds of people around\n"
	.string "the world live happily with\l"
	.string "POKéMON.$"
#endif

Route38_Text_BeautyOliviaSeen:
#if GERMAN
	.string "Meine Pokémon und Ich sind\n"
	.string "wunderschön, nicht wahr?$"
#else
	.string "Don't you think my POKéMON\n"
	.string "and I are beautiful?$"
#endif

Route38_Text_BeautyOliviaBeaten:
#if GERMAN
	.string "Wir trinken täglich Kuhmuh-Milch.$"
#else
	.string "We drink MOOMOO MILK every\n"
	.string "day.$"
#endif

Route38_Text_BeautyOliviaAfter:
#if GERMAN
	.string "Kuhmuh-Milch ist gut für Schönheit und\n"
	.string "Gesundheit.\p"
	.string "Doch leider wird sie nur flaschenweise\n"
	.string "verkauft.$"
#else
	.string "MOOMOO MILK is good for\n"
	.string "beauty and health,\p"
	.string "but inconveniently, they\n"
	.string "only sell one bottle at a time.$"
#endif

Route38_Text_Sign:
#if GERMAN
	.string "Route 38\p"
	.string "Oliviana City - Teak City$"
#else
	.string "ROUTE 38\p"
	.string "OLIVINE CITY - ECRUTEAK CITY$"
#endif

Route38_Text_TrainerTips:
#if GERMAN
	.string "Route 38\p"
	.string "Weidegebiet der Farm Bauer.\n"
	.string "Tore bitte schließen.\p"
	.string "Milchverkauf im Stall nebenan.$"
#else
	.string "ROUTE 38\p"
	.string "MOOMOO FARM pastureland.\n"
	.string "Please close the gates.\p"
	.string "Milk is sold at the barn.$"
#endif


Route38_Text_WaterSign:
#if GERMAN
	.string "Schwimmen und Angeln verboten.\p"
	.string "Wasser nur für Landwirtschaft.\p"
	.string "Bürgermeister von Teak City$"
#else
	.string "NO SWIMMING OR FISHING.\n"
	.string "WATER FOR FARMING ONLY.\p"
	.string "-ECRUTEAK COUNCIL$"
#endif

Route38_Text_DanaRegister:
#if GERMAN
    .string "Ich kenne etwas wirklich Gutes!\p"
    .string "Die Milch der Muhmuh-Farm ist\n"
    .string "für ihren Geschmack berühmt.$"
#else
	.string "I know something good!\p"
	.string "MOOMOO FARM's milk is\n"
	.string "famous for its flavor.$"
#endif

Route38_Text_DanaRematchIntro:
#if GERMAN
    .string "Du scheinst dich gut mit Pokémon\n"
    .string "auszukennen.\p"
    .string "Wenn das so ist, könntest du mir\n"
    .string "vielleicht ein paar Tipps geben?$"
#else
	.string "You seem to be good at\n"
	.string "POKéMON.\p"
	.string "If you are, how about\n"
	.string "giving me some advice?$"
#endif

Route38_Text_DanaRematchDefeat:
#if GERMAN
	.string "Ich verstehe. So kämpfst du also.$"
#else
	.string "I see. So you can battle\n"
	.string "that way.$"
#endif

Route38_Text_DanaPostRematch:
#if GERMAN
    .string "Ich kenne etwas wirklich Gutes!\p"
    .string "Die Milch der Muhmuh-Farm ist\n"
    .string "für ihren Geschmack berühmt.$"
#else
	.string "I know something good!\p"
	.string "MOOMOO FARM's milk is\n"
	.string "famous for its flavor.$"
#endif

Route38_Text_DanaHasItem:
#if GERMAN
    .string "Hey! Ich habe etwas Interessantes\n"
    .string "gefunden!\p"
    .string "Hier, du kannst es haben!$"
#else
	.string "Hey! I found something\n"
	.string "interesting!\p"
	.string "Here, you can have it!$"
#endif

Route38_Text_DanaGaveItem:
#if GERMAN
    .string "Ich sage dir Bescheid, wenn ich\n"
    .string "noch etwas finde!$"
#else
	.string "I'll let you know if I find\n"
	.string "anything else!$"
#endif

Route38_Text_DanaNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
#endif
