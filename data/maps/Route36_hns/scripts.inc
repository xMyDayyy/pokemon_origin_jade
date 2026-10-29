Route36_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition:
	callnative SetTimeBasedEncounters
	special GetWeekday
	call_if_ne VAR_RESULT, WEEKDAY_THU, Route36_EventScript_HideArthur
	call_if_ne VAR_SUICUNE_ENCOUNTERS, 3, Route36_EventScript_HideSuicune
	setflag FLAG_TEMP_3
	end

@ Arthur of the weekday siblings is only here on Thursday, see
@ docs/origin_jade/DECISIONS.md, D-033.
Route36_EventScript_HideArthur:
	setflag FLAG_TEMP_1
	return

@ Suicune stands here only at VAR_SUICUNE_ENCOUNTERS 3 (both other Johto sightings
@ done); FLAG_TEMP_2 hides Suicune, FLAG_TEMP_3 hides Eusine.
@ See docs/origin_jade/DECISIONS.md, D-038.
Route36_EventScript_HideSuicune:
	setflag FLAG_TEMP_2
	return

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	@ Origin Jade: Hard Stone instead if the player already owns HM Rock Smash.
	checkitem ITEM_HM_ROCK_SMASH
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RockSmashGuyHasHM
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_RockSmashGuyHasHM::
	msgbox Route36_Text_RockSmashGuyHasHM, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 50
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK_HNS, Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN_HNS, Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten, Route36_EventScript_RegisterAlan
	goto_if_set FLAG_ALAN_HAS_ITEM_HNS, Route36_EventScript_AlanGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_RematchAlan
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_RegisterAlan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route36_Text_AlanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ALAN_HNS
	release
	end

Route36_EventScript_RematchAlan::
	trainerbattle_rematch TRAINER_ALAN_HNS, Route36_Text_AlanRematchIntro, Route36_Text_AlanRematchDefeat
	msgbox Route36_Text_AlanPostRematch, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanGiveItem::
	msgbox Route36_Text_AlanHasItem, MSGBOX_DEFAULT
	giveitem VAR_ALAN_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route36_EventScript_AlanNoRoom
	clearflag FLAG_ALAN_HAS_ITEM_HNS
	msgbox Route36_Text_AlanGaveItem, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_AlanNoRoom::
	msgbox Route36_Text_AlanNoRoom, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
#if GERMAN
	.string "Das ist ein merkwürdiger Baum.\n"
	.string "Möchtest du die Schiggykanne benutzen?$"
#else
	.string "Use SQUIRTBOTTLE?$"
#endif

Route36_Text_UsedSquirtbottle:
#if GERMAN
	.string "{PLAYER} setzt die Schiggykanne ein!$"
#else
	.string "{PLAYER} used the SQUIRTBOTTLE.$"
#endif

Route36_Text_SudowoodoAttacked:
#if GERMAN
	.string "Der merkwürdige Baum krümmt sich unter\n"
	.string "dem Wasser aus der Schiggykanne!\p"
	.string "Er greift dich an!$"
#else
	.string "The weird tree doesn't like the\n"
	.string "SQUIRTBOTTLE!\p"
	.string "The weird tree attacked!$"
#endif

Route36_Text_RockSmashGuy1:
#if GERMAN
	.string "Wat is los!\p"
	.string "Ich wollte diesen Baum mit einem\n"
	.string "geraden Schlag fällen.\p"
	.string "Aber es ging nicht!\n"
	.string "Ich bin ein Versager!$"
#else
	.string "Wa-hey!\p"
	.string "I was going to snap that tree\n"
	.string "with my straight-arm punch.\p"
	.string "But I couldn't! I'm a failure!$"
#endif

Route36_Text_RockSmashGuy2:
#if GERMAN
	.string "Hast du diesen lästigen Baum\n"
	.string "beseitigt?\p"
	.string "Ich bin beeindruckt!\n"
	.string "Das hier sollst du haben.$"
#else
	.string "Did you clear that wretched tree?\p"
	.string "I'm impressed!\n"
	.string "I want you to have this.$"
#endif

Route36_Text_RockSmashGuy3:
#if GERMAN
	.string "Das ist übrigens Zertrümmerer.\p"
	.string "Damit kannst du Felsen mit einem\n"
	.string "gezielten Hieb zertrümmern.\p"
	.string "Sind dir Steine im Weg, schlag sie\n"
	.string "einfach kaputt!$"
#else
	.string "That happens to be ROCK SMASH.\p"
	.string "You can shatter rocks with just a\n"
	.string "single well-aimed smack.\p"
	.string "If any rocks are in your way,\n"
	.string "just smash 'em up!$"
#endif

Route36_Text_OddTree:
#if GERMAN
	.string "Ein seltsamer Baum versperrt\n"
	.string "den Weg.$"
#else
	.string "A weird tree is blocking the way.$"
#endif

Route36_Text_Lass1:
#if GERMAN
	.string "Ein merkwürdiger Baum blockiert die\n"
	.string "Straße nach Dukatia City.\p"
	.string "Wegen dieses Baumes kann ich\n"
	.string "nicht einkaufen gehen.\p"
	.string "Man sollte etwas dagegen tun.$"
#else
	.string "Be careful at night on this route!\p"
	.string "I saw a POKéMON that looked like\n"
	.string "GROWLITHE, but it had a scary aura\l"
	.string "to it.$"
#endif

Route36_Text_Lass2_ClearedSudowoodo:
#if GERMAN
	.string "Dieser merkwürdige Baum ist spurlos\n"
	.string "verschwunden.\p"
	.string "Ach! Der Baum war in Wirklichkeit ein\n"
	.string "Pokémon?$"
#else
	.string "That odd tree disappeared without\n"
	.string "a trace.\p"
	.string "Oh! That tree was really a\n"
	.string "POKéMON?$"
#endif

Route36_Text_PsychicMarkSeen:
#if GERMAN
	.string "Ich werde jetzt deine Gedanken lesen!$"
#else
	.string "I'm going to read your thoughts!$"
#endif

Route36_Text_PsychicMarkBeaten:
#if GERMAN
	.string "Ich habe mich wohl bei dir verlesen!$"
#else
	.string "I misread you!$"
#endif

Route36_Text_PsychicMarkAfter:
#if GERMAN
	.string "Wenn ich doch bloß die Gedanken\n"
	.string "meiner Gegner lesen könnte.$"
#else
	.string "I'd be strong if only I could tell\n"
	.string "what my opponent was thinking.$"
#endif

Route36_Text_SchoolboyAlan1Seen:
#if GERMAN
	.string "Dank meiner Studien bin ich für jedes\n"
	.string "Pokémon bereit!$"
#else
	.string "Thanks to my studies, I'm ready\n"
	.string "for any POKéMON!$"
#endif

Route36_Text_SchoolboyAlan1Beaten:
#if GERMAN
	.string "Ups! Ein Fehler in der Berechnung?$"
#else
	.string "Oops! Computation error?$"
#endif

Route36_Text_SchoolboyAlanAfter:
#if GERMAN
	.string "Mist. Ich lerne fünf Stunden am Tag.\p"
	.string "Zum Lernen gehört mehr als nur Bücher\n"
	.string "zu lesen.$"
#else
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"
#endif

Route36_Text_MeetArthur:
#if GERMAN
	.string "Donatus: Wer bist du?\p"
	.string "Ich bin Donatus vom Donnerstag.\p"
	.string "Hier, das kannst du haben.$"
#else
	.string "ARTHUR: Who are you?\p"
	.string "I'm ARTHUR of Thursday.\p"
	.string "Here. You can have this.$"
#endif

Route36_Text_ArthurGaveGift:
#if GERMAN
	.string "Donatus: Ein Pokémon mit\n"
	.string "Gestein-Attacken sollte das tragen.\p"
	.string "Es verstärkt Gestein-Attacken.$"
#else
	.string "ARTHUR: A POKéMON that uses ROCK-\n"
	.string "type moves should hold on to that.\p"
	.string "It pumps up ROCK-type attacks.$"
#endif

Route36_Text_ArthurThursday:
#if GERMAN
	.string "Donatus: Ich bin Donatus vom\n"
	.string "Donnerstag.\p"
	.string "Ich bin der fünfte von sieben\n"
	.string "Geschwistern.$"
#else
	.string "ARTHUR: I'm ARTHUR of Thursday.\n"
	.string "I'm the fifth son out of seven.$"
#endif

Route36_Text_Sign:
#if GERMAN
	.string "Route 36$"
#else
	.string "ROUTE 36$"
#endif

Route36_Text_Sign_RuinsNorth:
#if GERMAN
	.string "Alph-Ruinen\n"
	.string "Nordeingang$"
#else
	.string "RUINS OF ALPH\n"
	.string "NORTH ENTRANCE$"
#endif

Route36_Text_Tips1:
#if GERMAN
	.string "Route 36\p"
	.string "Westlich liegt Teak City,\n"
	.string "östlich die Ruinen von Alph.$"
#else
	.string "ROUTE 36\p"
	.string "ECRUTEAK CITY lies to the west,\n"
	.string "the RUINS OF ALPH to the east.$"
#endif

Route36_Text_Tips2:
#if GERMAN
	.string "Route 36\p"
	.string "Achtung, Wurzeln und loses Geröll.\n"
	.string "Wanderer bitte vorsichtig gehen.$"
#else
	.string "ROUTE 36\p"
	.string "Watch for roots and loose stones.\n"
	.string "Travellers, tread carefully.$"
#endif

Route36_Text_AlanRegister:
#if GERMAN
    .string "Verdammt. Ich lerne auch fünf\n"
    .string "Stunden am Tag.\p"
    .string "Zum Lernen gehört mehr, als nur\n"
    .string "Bücher zu lesen.$"
#else
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"
#endif

Route36_Text_AlanRematchIntro:
#if GERMAN
    .string "Dank meines Studiums bin ich auf\n"
    .string "jedes Pokémon vorbereitet!$"
#else
	.string "Thanks to my studies, I'm ready\n"
	.string "for any POKéMON!$"
#endif

Route36_Text_AlanRematchDefeat:
#if GERMAN
    .string "Ups! Rechenfehler?$"
#else
	.string "Oops! Computation error?$"
#endif

Route36_Text_AlanPostRematch:
#if GERMAN
    .string "Verdammt. Ich lerne auch fünf\n"
    .string "Stunden am Tag.\p"
    .string "Zum Lernen gehört mehr, als nur\n"
    .string "Bücher zu lesen.$"
#else
	.string "Darn. I study five hours a day too.\p"
	.string "There's more to learning than just\n"
	.string "reading books.$"
#endif

Route36_Text_AlanHasItem:
#if GERMAN
    .string "Hey! Ich habe beim Lernen etwas\n"
    .string "gefunden!\p"
    .string "Hier, du kannst es haben!$"
#else
	.string "Hey! I found something\n"
	.string "while studying!\p"
	.string "Here, you can have it!$"
#endif

Route36_Text_AlanGaveItem:
#if GERMAN
    .string "Ich sage dir Bescheid, wenn ich\n"
    .string "noch etwas finde!$"
#else
	.string "I'll let you know if I find\n"
	.string "anything else!$"
#endif

Route36_Text_AlanNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
#endif

Route36_Text_RockSmashGuyHasHM:
#if GERMAN
	.string "Der Brocken lag hier, seit ich denken\n"
	.string "kann. Und du räumst ihn weg, als wäre\l"
	.string "er Kies.\p"
	.string "Den Zertrümmerer wollte ich dir geben.\n"
	.string "Brauchst du offenbar nicht.\p"
	.string "Nimm den hier. Der hält, was er\n"
	.string "verspricht.$"
#else
	.string "That rock sat here as long as I can\n"
	.string "remember. You clear it like gravel.\p"
	.string "I meant to give you ROCK SMASH. You\n"
	.string "clearly don't need it.\p"
	.string "Take this instead. It holds up.$"
#endif

@ Third Johto sighting: Suicune runs off north, Eusine walks in from the south
@ and points to the Glockenturm (VAR_SUICUNE_ENCOUNTERS 3 -> 4).
Route36_EventScript_SuicuneTrigger::
	lockall
	hidefollower
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ROUTE36_SUICUNE, Route36_Movement_SuicuneRunOff
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement 0
	removeobject LOCALID_ROUTE36_SUICUNE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	delay 30
	playbgm MUS_HG_EUSINE, FALSE
	clearflag FLAG_TEMP_3
	addobject LOCALID_ROUTE36_EUSINE
	goto_if_unset FLAG_HIDE_SUDOWOODO, Route36_EventScript_EusineBehindSudowoodo
	applymovement LOCALID_ROUTE36_EUSINE, Route36_Movement_EusineEnter
Route36_EventScript_EusineArrived:
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route36_Text_EusineTinTower, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE36_EUSINE, Route36_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE36_EUSINE
	fadedefaultbgm
	setvar VAR_SUICUNE_ENCOUNTERS, 4
	releaseall
	end

@ Sudowoodo still stands on (39,19): Eusine stops one tile south of it.
Route36_EventScript_EusineBehindSudowoodo:
	applymovement LOCALID_ROUTE36_EUSINE, Route36_Movement_EusineEnterShort
	goto Route36_EventScript_EusineArrived

Route36_Movement_SuicuneRunOff:
	jump_in_place_right
	jump_right
	jump_2_up
	jump_2_up
	jump_2_up
	step_end

Route36_Movement_EusineEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route36_Movement_EusineEnterShort:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route36_Movement_EusineLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route36_Text_EusineTinTower:
#if GERMAN
	.string "Eusin: {PLAYER}! Hast du es auch\n"
	.string "gesehen? Das war Suicune!\p"
	.string "Es ist nach Norden gelaufen, in\n"
	.string "Richtung Teak City…\p"
	.string "Ich glaube, es will zum\n"
	.string "Glockenturm.\p"
	.string "Der Legende nach prüft dort ein\n"
	.string "Pokémon jeden Trainer, der die\l"
	.string "Seelen der Pokémon berühren kann.\p"
	.string "Doch den Turm dürfen nur\n"
	.string "Auserwählte betreten…$"
#else
	.string "EUSINE: {PLAYER}! Did you see that?\n"
	.string "That was SUICUNE!\p"
	.string "It ran north, toward ECRUTEAK…\p"
	.string "I think it's heading for the\n"
	.string "TIN TOWER.\p"
	.string "Legend has it that a POKéMON there\n"
	.string "tests every trainer who can touch\l"
	.string "the souls of POKéMON.\p"
	.string "But only the chosen may enter\n"
	.string "the tower…$"
#endif
