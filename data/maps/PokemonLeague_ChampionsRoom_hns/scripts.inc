PokemonLeague_ChampionsRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ChampionRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_ChampionsRoom_OnResume_Hns
	.byte 0

PokemonLeague_ChampionsRoom_OnResume_Hns::
	setvar VAR_0x8004, 4
	special DoPokemonLeagueLightingEffect
	end

ChampionRoom_OnFrame::
	map_script_2 VAR_TEMP_0, 0, ChampionRoom_CloseDoor
	.2byte 0

ChampionRoom_CloseDoor::
	lock
	setflag FLAG_TEMP_2
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, ChamionRoom_Movement_Enter
	waitmovement 0
	setvar VAR_TEMP_0, 1
	release
	end

ChamionRoom_Movement_Enter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ChampionRoom_Trigger::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

PokemonLeague_WillsRoom_EventScript_Lance::
	lockall
	call_if_eq VAR_FACING, DIR_EAST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast
	call_if_eq VAR_FACING, DIR_SOUTH, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth
	call_if_eq VAR_FACING, DIR_WEST, PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest
	faceplayer
	@ Origin Jade: rematch once Johto's league is won.
	goto_if_set FLAG_IS_JOHTO_CHAMPION, PokemonLeague_WillsRoom_EventScript_LanceRematch
	msgbox PokemonLeague_ChampionsRoom_Text_BattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_1_HNS, PokemonLeague_ChampionsRoom_Text_BattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto

PokemonLeague_WillsRoom_EventScript_LanceRematch::
	goto_if_unset FLAG_IS_KANTO_CHAMPION, PokemonLeague_WillsRoom_EventScript_LanceRematchStandard
	goto_if_ge VAR_SINJOH_STORYLINE, 13, PokemonLeague_WillsRoom_EventScript_LanceRematchPostOBC

PokemonLeague_WillsRoom_EventScript_LanceRematchStandard::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_2_HNS, PokemonLeague_ChampionsRoom_Text_RematchBattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_WillsRoom_EventScript_LanceRematchPostOBC::
	msgbox PokemonLeague_ChampionsRoom_Text_RematchBattleIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_LANCE_POSTOBC_HNS, PokemonLeague_ChampionsRoom_Text_RematchBattleWin
	goto PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto

PokemonLeague_WillsRoom_EventScript_LanceOnDefeatJohto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_BattleAfter, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	playse SE_PIN
	applymovement LOCALID_LEAGUE_LANCE, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_LANCE
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceMoveOver
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_LEAGUE_LANCE
	addobject LOCALID_LEAGUE_MARY
	addobject LOCALID_LEAGUE_OAK
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryEnter
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryOhNoOak, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_OAK, PokemonLeague_ChampionsRoom_Movement_OakEnter_Hns
	delay 60
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryMoveOver
	waitmovement LOCALID_LEAGUE_MARY
	waitmovement LOCALID_LEAGUE_OAK
	msgbox PokemonLeague_ChampionsRoom_Text_OakCongratulations_Hns, MSGBOX_DEFAULT
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryInterview
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_MaryInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceAnxious
	waitmovement 0
	msgbox PokemonLeague_ChampionsRoom_Text_Noisy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceLeave
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerLeave
	waitmovement LOCALID_LEAGUE_LANCE
	@setobjectxyperm LOCALID_LEAGUE_LANCE, 6, 14
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	waitse
	delay 50
	applymovement LOCALID_LEAGUE_MARY, PokemonLeague_ChampionsRoom_Movement_MaryLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LEAGUE_MARY, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_LEAGUE_MARY
	msgbox PokemonLeague_ChampionsRoom_Text_MaryNoInterview, MSGBOX_DEFAULT
	closemessage
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

@ Title defence: short scene without Mary and Oak, then the Hall of Fame.
@ See docs/origin_jade/DECISIONS.md, D-028.
PokemonLeague_WillsRoom_EventScript_LanceOnDefeatKanto::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_ChampionsRoom_Text_RematchFollowMe, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x3F2, FALSE
	setmetatile 6, 2, 0x296, FALSE
	playse SE_DOOR
	special DrawWholeMapView
	applymovement LOCALID_LEAGUE_LANCE, PokemonLeague_ChampionsRoom_Movement_LanceToHallOfFame
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_PlayerToHallOfFame
	waitmovement LOCALID_LEAGUE_LANCE
	removeobject LOCALID_LEAGUE_LANCE
	playse SE_EXIT
	waitmovement OBJ_EVENT_ID_PLAYER
	playse SE_EXIT
	setvar VAR_LEAGUE_STATE, 6
	warpsilent MAP_POKEMON_LEAGUE_HALL_OF_FAME_HNS, 0
	waitstate
	releaseall
	end

PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingEast::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingSouth::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth
	waitmovement 0
	return
PokemonLeague_ChampionsRoom_EventScript_AdjustPlayerFacingWest::
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest
	waitmovement 0
	return

PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingEast:
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingSouth:
	walk_left
	walk_down
	walk_down
	walk_right
	face_up
	step_end
PokemonLeague_ChampionsRoom_Movement_AdjustPlayerFacingWest:
	walk_down
	walk_left
	face_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerMoveToCenter:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceMoveOver:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_2
	walk_in_place_fast_down
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryMoveOver:
	walk_left
	face_right
	step_end

PokemonLeague_ChampionsRoom_Movement_OakEnter_Hns:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryInterview:
	walk_fast_up
	walk_in_place_fast_right
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceAnxious:
	face_up
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	face_left
	step_end

PokemonLeague_ChampionsRoom_Movement_LanceLeave:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_PlayerLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Movement_MaryLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ Title defence: Lance walks from (6,8) to the Hall of Fame door (6,2).
PokemonLeague_ChampionsRoom_Movement_LanceToHallOfFame:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

@ Title defence: the player follows from (6,9).
PokemonLeague_ChampionsRoom_Movement_PlayerToHallOfFame:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

PokemonLeague_ChampionsRoom_Text_RematchBattleIntro:
#if GERMAN
	.string "Siegfried: Willkommen zurück,\n"
	.string "{PLAYER}!\p"
	.string "Du hast mich schon einmal besiegt\n"
	.string "und nun auch die Top Vier erneut.\p"
	.string "Seitdem habe ich mein Team weiter\n"
	.string "gestärkt.\p"
	.string "Zeig mir, dass dein Sieg kein\n"
	.string "Zufall war!$"
#else
    .string "LANCE: Welcome back, {PLAYER}!\p"
    .string "You beat me once, and now you have\n"
    .string "beaten the ELITE FOUR again.\p"
    .string "Since then, I have made my team\n"
    .string "even stronger.\p"
    .string "Show me that your win was no\n"
    .string "fluke!$"
#endif

PokemonLeague_ChampionsRoom_Text_BattleIntro:
#if GERMAN
	.string "Siegfried: Ich habe auf dich gewartet.\p"
	.string "{PLAYER}!\p"
	.string "Ich wusste, dass du mit deinem\n"
	.string "Können eines Tages hier stehst.\p"
	.string "Jetzt braucht es keine Worte.\p"
	.string "Wir kämpfen um zu sehen, wer von uns der\n"
	.string "Stärkere ist.\p"
	.string "Als mächtigster Trainer und als\n"
	.string "Champion der Pokémon-Liga…\p"
	.string "ich, Siegfried, der Drachenmeister,\n"
	.string "nehme deine Herausforderung an!$"
#else
    .string "LANCE: I've been waiting for you.\p"
    .string "{PLAYER}!\p"
    .string "I knew that you, with your skills,\n"
    .string "would eventually reach me here.\p"
    .string "There's no need for words now.\p"
    .string "We will battle to determine who is\n"
    .string "the stronger of the two of us.\p"
    .string "As the most powerful trainer and as\n"
    .string "the POKéMON LEAGUE CHAMPION…\p"
    .string "I, LANCE the dragon master, accept\n"
    .string "your challenge!$"
#endif

PokemonLeague_ChampionsRoom_Text_BattleWin:
#if GERMAN
	.string "Es ist vorbei.\p"
	.string "Ein seltsames Gefühl.\p"
	.string "Ich bin nicht wütend, dass ich verloren\n"
	.string "habe. Ich bin glücklich. Glücklich, dass\l"
	.string "ich den Aufstieg eines neuen Champs\l"
	.string "miterleben durfte.$"
#else
    .string "…It's over.\p"
    .string "But it's an odd feeling.\p"
    .string "I'm not angry that I lost. In fact,\n"
    .string "I feel happy.\p"
    .string "Happy that I witnessed the rise\n"
    .string "of a great new CHAMPION!$"
#endif

@ Lance's in-battle defeat text in a title defence.
PokemonLeague_ChampionsRoom_Text_RematchBattleWin:
#if GERMAN
	.string "Es ist vorbei…\p"
	.string "Du hast mich erneut geschlagen.\n"
	.string "Du bist ein würdiger Champ!$"
#else
    .string "…It's over.\p"
    .string "You beat me once again.\n"
    .string "You are a worthy CHAMPION!$"
#endif

PokemonLeague_ChampionsRoom_Text_RematchFollowMe:
#if GERMAN
	.string "Siegfried: Puh… Du bist noch\n"
	.string "stärker geworden, {PLAYER}.\p"
	.string "Komm mit. Die Ruhmeshalle wartet.$"
#else
    .string "LANCE: Whew… You have grown even\n"
    .string "stronger, {PLAYER}.\p"
    .string "Come with me. The HALL OF FAME\n"
    .string "awaits.$"
#endif

PokemonLeague_ChampionsRoom_Text_BattleAfter:
#if GERMAN
	.string "…Puh.\p"
	.string "Du bist wirklich stark geworden,\n"
	.string "{PLAYER}.\p"
	.string "Deine Pokémon reagieren auf deine\n"
	.string "aufrechte und starke Art.\p"
	.string "Als Trainer wirst du gemeinsam\n"
	.string "mit deinen Pokémon weiter wachsen.$"
#else
    .string "…Whew.\p"
    .string "You have become truly powerful,\n"
    .string "{PLAYER}.\p"
    .string "Your POKéMON have responded to your\n"
    .string "strong and upstanding nature.\p"
    .string "As a trainer, you will continue to\n"
    .string "grow strong with your POKéMON.$"
#endif

PokemonLeague_ChampionsRoom_Text_MaryOhNoOak:
#if GERMAN
	.string "Margit: Oh nein! Es ist vorbei!\p"
	.string "Prof. Eich, wärst du nicht so langsam…$"
#else
    .string "MARY: Oh, no! It's all over!\p"
    .string "PROF.OAK, if you weren't so slow…$"
#endif

PokemonLeague_ChampionsRoom_Text_OakCongratulations_Hns:
#if GERMAN
	.string "Prof. Eich: Ah, {PLAYER}!\p"
	.string "Schön, dich wiederzusehen.\p"
	.string "Du wirkst sehr beeindruckend.\p"
	.string "Dein Sieg in der Johto-Liga ist\n"
	.string "wirklich fantastisch!\p"
	.string "Dein Einsatz, dein Vertrauen und\n"
	.string "deine Liebe zu Pokémon haben das\l"
	.string "möglich gemacht.\p"
	.string "Auch deine Pokémon waren großartig.\p"
	.string "Sie glaubten an dich als Trainer\n"
	.string "und hielten durch.\p"
	.string "Herzlichen Glückwunsch, {PLAYER}!$"
#else
    .string "PROF.OAK: Ah, {PLAYER}!\p"
    .string "It's good to see you again.\p"
    .string "You certainly look more impressive.\p"
    .string "Your conquest of the JOHTO LEAGUE\n"
    .string "is just fantastic!\p"
    .string "Your dedication, trust and love\n"
    .string "for your POKéMON made this happen.\p"
    .string "Your POKéMON were outstanding too.\p"
    .string "Because they believed in you as a\n"
    .string "trainer, they persevered.\p"
    .string "Congratulations, {PLAYER}!$"
#endif

PokemonLeague_ChampionsRoom_Text_MaryInterview:
#if GERMAN
	.string "Margit: Interview mit dem neuen\p"
	.string "Johto-Champion!$"
#else
    .string "MARY: Let's interview the brand new\n"
    .string "JOHTO CHAMPION!$"
#endif

PokemonLeague_ChampionsRoom_Text_Noisy:
#if GERMAN
	.string "Siegfried: Es wird mir etwas zu laut…\p"
	.string "{PLAYER}, komm bitte mit mir.$"
#else
    .string "LANCE: This is getting to be a bit\n"
    .string "too noisy…\p"
    .string "{PLAYER}, could you come with me?$"
#endif

PokemonLeague_ChampionsRoom_Text_MaryNoInterview:
#if GERMAN
	.string "Margit: Halt, Moment mal! Was wird denn\n"
	.string "jetzt aus unserem Interview?$"
#else
    .string "MARY: Oh, wait! We haven't done\n"
    .string "the interview!$"
#endif

