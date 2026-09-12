Route30_MrPokemonsHouse_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MrPokemonHouse_OnFrame
	.byte 0

MrPokemonHouse_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 1, MrPokemonHouse_EventScript_GiveEgg
	.2byte 0

MrPokemonHouse_EventScript_GiveEgg::
	lock
	playse SE_PIN
	applymovement LOCALID_MRPOKEMON, Common_Movement_ExclamationMark	
	delay 55
	waitmovement LOCALID_MRPOKEMON
	turnobject LOCALID_MRPOKEMON, DIR_SOUTH
	msgbox MrPokemonHouse_Text_Intro1, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MrPokemonHouse_Movement_MeetMrPokemon
	waitmovement 0
	msgbox MrPokemonHouse_Text_Intro2, MSGBOX_DEFAULT

	giveitem ITEM_MYSTERY_EGG

	msgbox MrPokemonHouse_Text_Intro3, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro4, MSGBOX_DEFAULT
	msgbox MrPokemonHouse_Text_Intro5, MSGBOX_DEFAULT
	closemessage
	@ Uebergang nach Johto: Prof. Eich tritt hier nicht mehr auf. Er hat den
	@ Spieler selbst hergeschickt und sitzt in Alabastia; und einen Pokedex
	@ braucht ein Champion von Kanto nicht mehr ueberreicht zu bekommen.
	setflag FLAG_DELIVERED_EGG
	turnobject OBJ_EVENT_ID_PLAYER DIR_NORTH
	fadedefaultbgm
	msgbox MrPokemonHouse_Text_Heal, MSGBOX_DEFAULT
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox MrPokemonHouse_Text_DependingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MRPOKEMON, MrPokemonHouse_Movement_MrPokemon_Leave
	waitmovement 0
	removeobject LOCALID_MRPOKEMON
	clearflag FLAG_HIDE_MRPOKEMON
	addobject LOCALID_MRPOKEMON2

	setvar VAR_NEWBARKTOWN_LABSTATE, 4
	setflag FLAG_HIDE_SILVER_NEWBARKTOWN
	checkrandomizer
	call_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_GiveNatDexRandomizer
	clearflag FLAG_HIDE_LAB_POLICEMAN
	setvar VAR_CHERRYGROVE_CITY_STATE, 2
	setrespawn HEAL_LOCATION_CHERRYGROVE_CITY_HNS
	clearflag FLAG_HIDE_SILVER_CHERRYGROVE
	setflag FLAG_HIDE_GUIDE_GENT_CHERRYGROVE
	clearflag FLAG_HIDE_CHERRYGROVE_GUIDE_GENT_HOUSE
	release
	end

MrPokemonHouse_EventScript_GiveNatDexRandomizer::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

MrPokemonHouse_EventScript_MrPokemon::
	lock
	faceplayer
	checkitem ITEM_RED_SCALE
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale
	msgbox MrPokemonHouse_Text_AlwaysNewDiscoveries, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale::
	msgbox MrPokemonHouse_Text_GimmeTheScale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted
	msgbox MrPokemonHouse_Text_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

MrPokemonHouse_EventScript_MrPokemon_RedScale_Accepted::
	removeitem ITEM_RED_SCALE
	giveitem ITEM_EXP_SHARE_SMALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end


MrPokemonHouse_EventScript_Computer::
	lock
	msgbox MrPokemonHouse_Text_BrokenComputer, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Magazine::
	lock
	msgbox MrPokemonHouse_Text_ForeignMagazines, MSGBOX_SIGN
	release
	end

MrPokemonHouse_EventScript_Coins::
	lock
	msgbox MrPokemonHouse_Text_StrangeCoins, MSGBOX_SIGN
	release
	end

MrPokemonHouse_Movement_MeetMrPokemon:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

MrPokemonHouse_Movement_OakToPlayer:
	walk_down
	face_left
	step_end

MrPokemonHouse_Movement_OakLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

MrPokemonHouse_Movement_MrPokemon_Leave:
	walk_up
	walk_left
	walk_left
	step_end

MrPokemonHouse_Text_Intro1:
#if GERMAN
	.string "Hallo! Du musst {PLAYER} sein.\p"
	.string "Prof. Lind sagte, dass du vorbeikommen\n"
	.string "würdest.$"
#else
	.string "Hello, hello! You must be\n"
	.string "{PLAYER}.\p"
	.string "PROF.ELM said that you would\n"
	.string "visit.$"
#endif

MrPokemonHouse_Text_Intro2:
#if GERMAN
	.string "Das ist das Objekt, das Professor\n"
	.string "Lind für mich untersuchen soll.$"
#else
	.string "This is what I want PROF.ELM\n"
	.string "to examine.$"
#endif

MrPokemonHouse_Text_GotEgg:
#if GERMAN
	.string "{PLAYER} erhält Rätsel-Ei.$"
#else
	.string "{PLAYER} received MYSTERY EGG.$"
#endif

MrPokemonHouse_Text_Intro3:
#if GERMAN
	.string "Ich kenne ein Paar, das eine\n"
	.string "Pokémon-Pension leitet.\p"
	.string "Sie gaben mir das Ei.\p"
	.string "Ich war derart fasziniert, dass ich\n"
	.string "Prof. Lind eine E-Mail schrieb.\p"
	.string "Was die Entwicklung von Pokémon\n"
	.string "betrifft, ist Prof. Lind wirklich genial.$"
#else
	.string "I know a couple who run a\n"
	.string "POKéMON DAY-CARE service.\p"
	.string "They gave me that EGG.\p"
	.string "I was intrigued, so I sent\n"
	.string "mail to PROF.ELM.\p"
	.string "For POKéMON evolution,\n"
	.string "PROF.ELM is the authority.$"
#endif


MrPokemonHouse_Text_Intro4:
#if GERMAN
	.string "Prof. Eich hat mir geschrieben, dass\n"
	.string "du kommen würdest.\p"
	.string "Er hält große Stücke auf dich.$"
#else
	.string "PROF. OAK wrote to say that you\n"
	.string "would be coming.\p"
	.string "He thinks very highly of you.$"
#endif

MrPokemonHouse_Text_Intro5:
#if GERMAN
	.string "Bring es zu Prof. Lind. Er weiß mehr\n"
	.string "über dieses Ei als ich.$"
#else
	.string "Take it to PROF. ELM. He knows more\n"
	.string "about this EGG than I do.$"
#endif

MrPokemonHouse_Text_Heal:
#if GERMAN
	.string "Du gehst jetzt wieder zu Professor Lind\n"
	.string "zurück, habe ich nicht recht?\p"
	.string "Dann solltest du deinem Pokémon aber\n"
	.string "vorher eine kurze Pause gönnen!$"
#else
	.string "You are returning to PROF.ELM?\p"
	.string "Here. Your POKéMON should have\n"
	.string "some rest.$"
#endif

MrPokemonHouse_Text_DependingOnYou:
#if GERMAN
	.string "Ich verlasse mich auf dich!$"
#else
	.string "I'm depending on you!$"
#endif

MrPokemonHouse_Text_AlwaysNewDiscoveries:
#if GERMAN
	.string "Das Leben ist schön! Es gibt immer\n"
	.string "etwas Neues zu entdecken!$"
#else
	.string "Life is delightful!\n"
	.string "Always, new discoveries to be made.$"
#endif

MrPokemonHouse_Text_OakIntro:
#if GERMAN
	.string "Eich: Aha! Du bist also {PLAYER}!\p"
	.string "Mein Name ist Prof. Eich!\p"
	.string "Ich bin von Beruf Pokémon-Forscher.\p"
	.string "Ich besuche gerade meinen alten Freund\n"
	.string "Mr. Pokémon.\p"
	.string "Ich hörte, du sollst etwas für Prof.\n"
	.string "Lind besorgen, also habe ich gewartet.\p"
	.string "Oh! Was ist das? Ein seltenes Pokémon!\p"
	.string "Mal sehen…\p"
	.string "Hm, ich verstehe!\p"
	.string "Ich weiß, warum Prof. Lind dir ein\n"
	.string "Pokémon für die Besorgung gab.\p"
	.string "Für Forscher wie Prof. Lind und\n"
	.string "mich sind Pokémon unsere Freunde.\p"
	.string "Er erkannte, dass du deine Pokémon\n"
	.string "liebevoll und umsichtig umsorgst.\p"
	.string "…Ah!\p"
	.string "Du scheinst zuverlässig zu sein.\p"
	.string "Möchtest du mir auch helfen?\p"
	.string "Dies ist die neueste Version des\n"
	.string "Pokédex. Er erfasst automatisch Daten\l"
	.string "über Pokémon, die man gefangen oder\l"
	.string "gesehen hat!\p"
	.string "Er ist eine Art Hi-Tech-Lexikon!$"
#else
	.string "OAK: Aha! So you're {PLAYER}!\p"
	.string "I'm OAK! A POKéMON researcher.\p"
	.string "I was just visiting my old friend\n"
	.string "MR. POKéMON.\p"
	.string "I heard you were running an errand\n"
	.string "for PROF.ELM, so I waited here.\p"
	.string "Oh! What's this? A rare POKéMON!\p"
	.string "Let's see…\n"
	.string "Hm, I see!\p"
	.string "I understand why PROF.ELM gave\n"
	.string "you a POKéMON for this errand.\p"
	.string "To researchers like PROF.ELM and\n"
	.string "I, POKéMON are our friends.\p"
	.string "He saw that you would treat your\n"
	.string "POKéMON with love and care.\p"
	.string "…Ah!\p"
	.string "You seem to be dependable. How\n"
	.string "would you like to help me out?\p"
	.string "See? This is the latest version of\n"
	.string "the POKéDEX.\p"
	.string "It automatically records data on\n"
	.string "POKéMON you've seen or caught.\p"
	.string "It's a hi-tech encyclopedia!\p"
	.string "It shows their habitats, how\n"
	.string "they evolve, and their moves.$"
#endif

MrPokemonHouse_Text_GetDex:
#if GERMAN
	.string "{PLAYER} erhält Pokédex!$"
#else
	.string "{PLAYER} received POKéDEX!$"
#endif

MrPokemonHouse_Text_OakParting:
#if GERMAN
	.string "Triff viele verschiedene Pokémon\n"
	.string "und vervollständige den Pokédex!\p"
	.string "Aber ich bin schon zu lange geblieben.\p"
	.string "Ich muss nach Dukatia City zu meiner\n"
	.string "gewohnten Radiosendung.\p"
	.string "{PLAYER}, ich zähle auf dich!$"
#else
	.string "Go meet many kinds of POKéMON and\n"
	.string "complete that POKéDEX!\p"
	.string "But I've stayed too long.\p"
	.string "I have to get to GOLDENROD\n"
	.string "for my usual radio show.\p"
	.string "{PLAYER}, I'm counting on you!$"
#endif

MrPokemonHouse_Text_GimmeTheScale:
#if GERMAN
	.string "Hm? Diese Schuppe… kann das sein?\n"
	.string "Ja! Die gehörte einem roten Garados!\p"
	.string "Da… das nenne ich mal selten!\n"
	.string "Ich muss sie haben!\p"
	.string "{PLAYER}, würdest du sie mir vielleicht\n"
	.string "im Tausch gegen diesen EP-Teiler\l"
	.string "abtreten, den ich von Professor Eich\l"
	.string "bekommen habe?$"
#else
	.string "Hm? That SCALE! What's that?\n"
	.string "A red GYARADOS?\p"
	.string "That's rare! I, I want it…\p"
	.string "{PLAYER}, would you care to\n"
	.string "trade it?\p"
	.string "I can offer this EXP.SHARE\n"
	.string "that I got from PROF.OAK.$"
#endif

MrPokemonHouse_Text_Disappointed:
#if GERMAN
	.string "Oh, in Ordnung. Schade… dieses\n"
	.string "Pokémon ist wirklich sehr selten…$"
#else
	.string "That's disappointing.\n"
	.string "That happens to be very rare.$"
#endif

MrPokemonHouse_Text_ExpShare:
#if GERMAN
	.string "Ich habe auch ein spezielles Item für\n"
	.string "dich.$"
#else
	.string "I also have a special item\n"
	.string "for you.$"
#endif

MrPokemonHouse_Text_ForeignMagazines:
#if GERMAN
	.string "Das sind Zeitungen aus aller Welt.\p"
	.string "Ich kann die Schlagzeilen nicht lesen…$"
#else
	.string "It's packed with foreign\n"
	.string "magazines.\p"
	.string "Can't even read their titles…$"
#endif

MrPokemonHouse_Text_BrokenComputer:
#if GERMAN
	.string "Das ist ein großer Computer.\n"
	.string "Hm, er ist kaputt…$"
#else
	.string "It's a big computer.\n"
	.string "Hmm. It's broken.$"
#endif

MrPokemonHouse_Text_StrangeCoins:
#if GERMAN
	.string "Ein ganzer Stapel seltsamer Münzen!\n"
	.string "Vielleicht stammen sie ja aus einem\l"
	.string "anderen Land?$"
#else
	.string "A whole pile of strange coins!\p"
	.string "Maybe they're from another\n"
	.string "country…$"
#endif

MrPokemonHouse_Text_GotExpShare:
#if GERMAN
	.string "{PLAYER} erhält EP-Teiler!$"
#else
	.string "{PLAYER} received EXP. SHARE!$"
#endif
