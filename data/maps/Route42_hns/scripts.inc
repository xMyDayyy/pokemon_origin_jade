Route42_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route42_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route42_MapScript_OnTransition::
	call_if_unset FLAG_RELEASED_BEASTS, Route42_MapScript_SuicuneNotReleased
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	call_if_unset FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_SuicuneSide
	callnative SetTimeBasedEncounters
	end

@ No Suicune and no sighting before the Burned Tower release; the release clears the flag.
Route42_MapScript_SuicuneNotReleased::
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	return

Route42_MapScript_HideTrigger::
	setvar VAR_TEMP_0, 1
	return

@ Arriving in the Mahogany half (from Mahogany Town), Suicune waits at the east line.
Route42_MapScript_SuicuneSide::
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_ge VAR_0x8004, 47, Route42_EventScript_SuicuneEast
	return

@ Suicune at (15,13), facing the Ecruteak gate.
Route42_EventScript_SuicuneWest::
	setobjectxyperm LOCALID_ROUTE42_SUICUNE, 15, 13
	setobjectmovementtype LOCALID_ROUTE42_SUICUNE, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

@ Suicune at (86,13), facing Mahogany Town.
Route42_EventScript_SuicuneEast::
	setobjectxyperm LOCALID_ROUTE42_SUICUNE, 86, 13
	setobjectmovementtype LOCALID_ROUTE42_SUICUNE, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	return

@ Lines at both ends of Route 42: every way in after the Burned Tower release
@ crosses one, also from Mt. Mortar's doors. Same scene mirrored, once per game.
@ Triggers on (10,14)-(10,16), the path from the Ecruteak gate; the scene starts on (10,15).
Route42_EventScript_Suicune_Trigger::
	lock
	goto_if_unset FLAG_RELEASED_BEASTS, Route42_EventScript_SuicuneNotYet
	getplayerxy VAR_0x8004, VAR_0x8005
	call_if_eq VAR_0x8005, 14, Route42_EventScript_SuicuneStepDown
	call_if_eq VAR_0x8005, 16, Route42_EventScript_SuicuneStepUp
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	@ Suicune may wait at the other line (arrival from a Mt. Mortar door, older saves).
	call Route42_EventScript_SuicuneWest
	addobject LOCALID_ROUTE42_SUICUNE
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_Suicune3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_Player
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	@ Eusine comes out of Mt. Mortar's west entrance.
	setobjectxyperm LOCALID_ROUTE42_EUSINE, 22, 10
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_Eusine2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	release
	end

@ Triggers on (89,11)-(89,13), the path from Mahogany Town; the scene starts on (89,11).
Route42_EventScript_SuicuneEast_Trigger::
	lock
	goto_if_unset FLAG_RELEASED_BEASTS, Route42_EventScript_SuicuneNotYet
	getplayerxy VAR_0x8004, VAR_0x8005
	@ Row 13 walks up twice, row 12 once.
	call_if_eq VAR_0x8005, 13, Route42_EventScript_SuicuneStepUp
	call_if_ge VAR_0x8005, 12, Route42_EventScript_SuicuneStepUp
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	call Route42_EventScript_SuicuneEast
	addobject LOCALID_ROUTE42_SUICUNE
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_SuicuneEast1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_SuicuneEast2
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0

	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE42_SUICUNE, Route42_Movement_SuicuneEast3
	applymovement OBJ_EVENT_ID_PLAYER, Route42_Movement_PlayerEast
	playse SE_LEDGE
	delay 60
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	waitmovement LOCALID_ROUTE42_SUICUNE
	waitmovement 0
	delay 60
	removeobject LOCALID_ROUTE42_SUICUNE
	setflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_HIDE_ROUTE42_EUSINE
	@ Eusine comes out of Mt. Mortar's east entrance.
	setobjectxyperm LOCALID_ROUTE42_EUSINE, 80, 10
	addobject LOCALID_ROUTE42_EUSINE
	playse SE_EXIT
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_EusineEast1
	waitmovement 0
	msgbox Route42_Text_EusineAdmireSuicune, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_ROUTE42_EUSINE, DIR_EAST
	msgbox Route42_Text_EusineJealous, MSGBOX_DEFAULT
	turnobject LOCALID_ROUTE42_EUSINE, DIR_WEST
	msgbox Route42_Text_EusineWontGiveUp, MSGBOX_DEFAULT
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 2, Route42_EventScript_DoneJohtoSuicune
	closemessage
	applymovement LOCALID_ROUTE42_EUSINE, Route42_Movement_EusineEast2
	waitmovement 0
	setflag FLAG_HIDE_ROUTE42_EUSINE
	removeobject LOCALID_ROUTE42_EUSINE
	setvar VAR_TEMP_0, 1
	release
	end

@ A save made on Route 42 with a build before round 6 can load with the lines armed before
@ the release (OnTransition does not run on Continue): no scene, lines off until the next map load.
Route42_EventScript_SuicuneNotYet::
	setvar VAR_TEMP_0, 1
	release
	end

@ Both Johto sightings done: Suicune appears on Route 36 next (VAR_SUICUNE_ENCOUNTERS 2 -> 3).
Route42_EventScript_DoneJohtoSuicune::
	setvar VAR_SUICUNE_ENCOUNTERS, 3
	return

Route42_EventScript_SuicuneStepDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	return

Route42_EventScript_SuicuneStepUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	return

Route42_Movement_Suicune1:
	jump_in_place_right_left
	jump_in_place_right_left
	step_end

@ (15,13) -> (11,15), in front of the player
Route42_Movement_Suicune2:
	jump_2_left
	jump_2_left
	jump_2_down
	step_end

@ Leaps over the player's tile to (9,15), then away east along row 13
Route42_Movement_Suicune3:
	jump_in_place_left
	delay_2
	face_left
	jump_2_left
	jump_2_up
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

@ (10,15) -> (8,15), facing east
Route42_Movement_Player:
	lock_facing_direction
	delay_2
	jump_2_left
	unlock_facing_direction
	step_end

@ Mt. Mortar's west entrance (22,10) -> (11,15)
Route42_Movement_Eusine1:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_down
	walk_down
	face_right
	step_end

@ (11,15) -> (20,13), off screen
Route42_Movement_Eusine2:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route42_Movement_SuicuneEast1:
	jump_in_place_left_right
	jump_in_place_left_right
	step_end

@ (86,13) -> (88,11), in front of the player
Route42_Movement_SuicuneEast2:
	jump_2_right
	jump_2_up
	step_end

@ Leaps over the player's tile to (90,11), then away west along row 13
Route42_Movement_SuicuneEast3:
	jump_in_place_right
	delay_2
	face_right
	jump_2_right
	jump_2_down
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_left
	jump_2_left
	step_end

@ (89,11) -> (91,11), facing west
Route42_Movement_PlayerEast:
	lock_facing_direction
	delay_2
	jump_2_right
	unlock_facing_direction
	step_end

@ Mt. Mortar's east entrance (80,10) -> (88,11)
Route42_Movement_EusineEast1:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	walk_up
	face_left
	step_end

@ (88,11) -> (79,13), off screen
Route42_Movement_EusineEast2:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route42_Text_EusineAdmireSuicune:
#if GERMAN
	.string "Eusin: Suicune… Du bist so tapfer…\n"
	.string "Du bist so jung und schön… Du bist\l"
	.string "so anmutig… Und du bist immer so\l"
	.string "schnell wieder weg!$"
#else
	.string "EUSINE: SUICUNE...\n"
	.string "How brave it is!\p"
	.string "How refreshing it is!\n"
	.string "How beautiful it is!\p"
	.string "And how quickly it moves!$"
#endif

Route42_Text_EusineJealous:
#if GERMAN
	.string "{PLAYER}!\p"
	.string "Du scheinst immer dort zu sein,\n"
	.string "wo Suicune auftaucht.\p"
	.string "Nun gut. Mein Verlangen, Suicune\n"
	.string "zu finden, übertrifft deines bei\l"
	.string "Weitem…\p"
	.string "Mein Großvater war…\n"
	.string "sehr von Legenden begeistert.\p"
	.string "Ich habe von ihm unzählige\n"
	.string "Geschichten über Suicune gehört.$"
#else
	.string "{PLAYER}!\p"
	.string "You seem to be around where\n"
	.string "SUICUNE would appear.\p"
	.string "Well, that's OK.\l"
	.string "My desire to search for\n"
	.string "SUICUNE is far beyond yours...\p"
	.string "My grandpa was... quite into\n"
	.string "myths.\p"
	.string "I've heard so many stories\n"
	.string "about SUICUNE from him.$"
#endif

Route42_Text_EusineWontGiveUp:
#if GERMAN
	.string "Suicune…\p"
	.string "Ich werde nicht eher ruhen, bis ich\n"
	.string "herausgefunden habe, wohin dich\l"
	.string "deine Reise führt…\p"
	.string "Ach ja, hab ich das nicht schön\n"
	.string "gesagt?$"
#else
	.string "SUICUNE...\n"
	.string "I won't stop following you\l"
	.string "until I've found out what\l"
	.string "you're after...\p"
	.string "You hear me!$"
#endif


Route42_EventScript_Tully::
	trainerbattle_single TRAINER_TULLY_HNS, Route42_Text_FisherTullySeen, Route42_Text_FisherTullyBeaten, Route42_EventScript_RegisterTully
	goto_if_set FLAG_TULLY_HAS_ITEM_HNS, Route42_EventScript_TullyGiveItem
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route42_EventScript_RematchTully
	msgbox Route42_Text_FisherTullyAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_RegisterTully::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route42_Text_TullyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TULLY_HNS
	release
	end

Route42_EventScript_RematchTully::
	trainerbattle_rematch TRAINER_TULLY_HNS, Route42_Text_TullyRematchIntro, Route42_Text_TullyRematchDefeat
	msgbox Route42_Text_TullyPostRematch, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_TullyGiveItem::
	msgbox Route42_Text_TullyHasItem, MSGBOX_DEFAULT
	giveitem VAR_TULLY_ITEM_HNS
	goto_if_eq VAR_RESULT, FALSE, Route42_EventScript_TullyNoRoom
	clearflag FLAG_TULLY_HAS_ITEM_HNS
	msgbox Route42_Text_TullyGaveItem, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_TullyNoRoom::
	msgbox Route42_Text_TullyNoRoom, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Ben::
	trainerbattle_single TRAINER_BENJAMIN_HNS, Route42_Text_HikerBenjaminSeen, Route42_Text_HikerBenjaminBeaten
	msgbox Route42_Text_HikerBenjaminAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Shane::
	trainerbattle_single TRAINER_SHANE_HNS, Route42_Text_PokemaniacShaneSeen, Route42_Text_PokemaniacShaneBeaten
	msgbox Route42_Text_PokemaniacShaneAfter, MSGBOX_AUTOCLOSE
	end

Route42_EventScript_Sign::
	lock
	msgbox Route42_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_MortarSign::
	lock
	msgbox Route42_Text_MtMortarSign1, MSGBOX_SIGN
	closemessage
	release
	end

Route42_EventScript_Item_SuperPotion::
	finditem ITEM_SUPER_POTION
	end
Route42_EventScript_Item_Shadow_Claw::
    finditem ITEM_TM_SHADOW_CLAW
    end
Route42_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route42_Text_FisherTullySeen:
#if GERMAN
	.string "Jetzt demonstriere ich dir die Kraft\n"
	.string "des Pokémon, das ich gefangen habe!$"
#else
	.string "Let me demonstrate the power\n"
	.string "of the POKéMON I caught!$"
#endif

Route42_Text_FisherTullyBeaten:
#if GERMAN
	.string "Was? Das kann nicht sein.$"
#else
	.string "What? That's not right.\n"
	.string "I can't believe this!$"
#endif

Route42_Text_FisherTullyAfter:
#if GERMAN
	.string "Mit dem Pokémon, das ich geangelt habe,\n"
	.string "werde ich der beste Trainer von allen!\l"
	.string "Das ist das A und O eines jeden Anglers!$"
#else
	.string "I want to become the trainer\n"
	.string "CHAMP using the POKéMON I\l"
	.string "caught myself.\p"
	.string "That's the best part of fishing!$"
#endif

Route42_Text_HikerBenjaminSeen:
#if GERMAN
	.string "Ach, ist das schön, im Freien zu sein!\n"
	.string "Ich fühle mich so frei!$"
#else
	.string "Ah, it's good to be outside!\n"
	.string "I feel so free!$"
#endif

Route42_Text_HikerBenjaminBeaten:
#if GERMAN
	.string "Hahaha!$"
#else
	.string "Gahahah! That was a good\n"
	.string "battle!$"
#endif

Route42_Text_HikerBenjaminAfter:
#if GERMAN
	.string "Humbug!$"
#else
	.string "Losing feels insignificant\n"
	.string "if you look up at the big sky!$"
#endif

Route42_Text_PokemaniacShaneSeen:
#if GERMAN
	.string "He!\p"
	.string "Das ist mein Geheimversteck!\n"
	.string "Verschwinde, du Außenseiter!$"
#else
	.string "HEY!\p"
	.string "This is my secret place!\n"
	.string "Get lost, you outsider!$"
#endif

Route42_Text_PokemaniacShaneBeaten:
#if GERMAN
	.string "Ich hätte meinen Mondstein verwenden\n"
	.string "sollen…$"
#else
	.string "I should have used my\n"
	.string "MOON STONE…$"
#endif

Route42_Text_PokemaniacShaneAfter:

Route42_Text_Sign1:
#if GERMAN
	.string "Route 42\p"
	.string "Teak City - Mahagonia City$"
#else
	.string "ROUTE 42\p"
	.string "ECRUTEAK CITY - MAHOGANY TOWN$"
#endif

Route42_Text_MtMortarSign1:
#if GERMAN
	.string "Kesselberg\p"
	.string "Im Inneren des Bergs befindet sich eine\n"
	.string "Höhle mit einem großen Wasserfall.$"
#else
	.string "MT.MORTAR\p"
	.string "WATERFALL CAVE INSIDE$"
#endif

Route42_Text_TullyRegister:
#if GERMAN
    .string "Ich will mit den Pokémon, die ich selbst\n"
    .string "gefangen habe, Pokémon-Champ werden.\p"
    .string "Das ist das Beste am Angeln!$"
#else
	.string "I want to become the trainer\n"
	.string "CHAMP using the POKéMON I\l"
	.string "caught myself.\p"
	.string "That's the best part of fishing!$"
#endif

Route42_Text_TullyRematchIntro:
#if GERMAN
	.string "Jetzt demonstriere ich dir die Kraft\n"
	.string "des Pokémon, das ich gefangen habe!$"
#else
	.string "Let me demonstrate the power\n"
	.string "of the POKéMON I caught!$"
#endif

Route42_Text_TullyRematchDefeat:
#if GERMAN
    .string "Was? Das kann nicht sein.\n"
    .string "Ich glaube es einfach nicht!$"
#else
	.string "What? That's not right.\n"
	.string "I can't believe this!$"
#endif

Route42_Text_TullyPostRematch:
#if GERMAN
    .string "Ich will mit den Pokémon, die ich selbst\n"
    .string "gefangen habe, Pokémon-Champ werden.\p"
    .string "Das ist das Beste am Angeln!$"
#else
	.string "I want to become the trainer\n"
	.string "CHAMP using the POKéMON I\l"
	.string "caught myself.\p"
	.string "That's the best part of fishing!$"
#endif

Route42_Text_TullyHasItem:
#if GERMAN
    .string "Hey! Ich habe beim Angeln etwas\n"
    .string "gefunden!\p"
    .string "Hier, du kannst es haben!$"
#else
	.string "Hey! I found something\n"
	.string "while I was fishing!\p"
	.string "Here, you can have it!$"
#endif

Route42_Text_TullyGaveItem:
#if GERMAN
    .string "Ich sage dir Bescheid, wenn ich noch\n"
    .string "etwas an Land ziehe!$"
#else
	.string "I'll let you know if I\n"
	.string "reel in anything else!$"
#endif

Route42_Text_TullyNoRoom:
#if GERMAN
    .string "Hm, dein Beutel ist voll.\p"
    .string "Komm wieder, wenn du Platz hast.$"
#else
	.string "Hmm, your BAG is full.\p"
	.string "Come back when you have room.$"
#endif
