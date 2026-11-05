PokemonLeague_HallOfFame_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PokemonLeague_HallOfFame_OnFrame_Hns
	.byte 0

PokemonLeague_HallOfFame_OnFrame_Hns::
	map_script_2 VAR_LEAGUE_STATE, 6, PokemonLeague_HallOfFame_EventScript_Cutscene
	.2byte 0

PokemonLeague_HallOfFame_EventScript_Cutscene::
	lock
	@ First Johto title or a repeat visit.
	goto_if_set FLAG_IS_JOHTO_CHAMPION, PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	call PokemonLeague_HallOfFame_EventScript_OakAndTroy
	call PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags
	goto PokemonLeague_HallOfFame_EventScript_GameClear

@ Repeat visit (title defence).
PokemonLeague_HallOfFame_EventScript_CutsceneKantoChamp::
	applymovement LOCALID_HALLOFFAME_LANCE, PokemonLeague_HallOfFame_Movement_LanceEnter
	applymovement OBJ_EVENT_ID_PLAYER, PokemonLeague_HallOfFame_Movement_PlayerEnter
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_HALLOFFAME_LANCE
	msgbox PokemonLeague_HallOfFame_Rematch_LanceText, MSGBOX_DEFAULT
	closemessage
	special GivePartyMonChampionRibbon
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	dofieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	waitfieldeffect FLDEFF_HALL_OF_FAME_RECORD_FRLG
	delay 40
	setvar VAR_TEMP_1, 1
	setvar VAR_LEAGUE_STATE, 1
	goto PokemonLeague_HallOfFame_EventScript_GameClear

@ Every Johto title: knocked-out legendaries return, the Hall of Fame screen saves, then the
@ player wakes up in their room in Pallet Town, without credits.
PokemonLeague_HallOfFame_EventScript_GameClear:
	call Common_EventScript_ReviveDefeatedLegendaries
	setrespawn HEAL_LOCATION_PALLET_TOWN_PLAYERS_ROOM
	fadescreenspeed FADE_TO_BLACK, 24
	special GameClearNoCredits
	waitstate
	releaseall
	end

PokemonLeague_HallOfFame_EventScript_SetFirstGameClearFlags::
	setflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setflag FLAG_HIDE_SLOWPOKE_WELL_TAILLESS_SLOWPOKES
	clearflag FLAG_HIDE_AZALEA_TOWN_TAILED_SLOWPOKES
	setflag FLAG_IS_CHAMPION
	setflag FLAG_IS_JOHTO_CHAMPION
	setflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	setvar VAR_LEAGUE_STATE, 1
	setvar VAR_NEWBARK_TOWN_STATE, 6
	@ Troy waits in Oak's lab; set before the Hall of Fame saves.
	goto_if_ne VAR_HOENN_TICKET_STATE, 0, Common_EventScript_NopReturn
	setvar VAR_HOENN_TICKET_STATE, 1
	return

@ First Johto title: Oak and Troy come in after the record. Troy only talks to Oak, then Oak
@ asks the player to his lab.
PokemonLeague_HallOfFame_EventScript_OakAndTroy::
	addobject LOCALID_HALLOFFAME_OAK
	addobject LOCALID_HALLOFFAME_TROY
	applymovement LOCALID_HALLOFFAME_TROY, PokemonLeague_HallOfFame_Movement_TroyEnter
	applymovement LOCALID_HALLOFFAME_OAK, PokemonLeague_HallOfFame_Movement_OakEnter
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement LOCALID_HALLOFFAME_TROY
	waitmovement LOCALID_HALLOFFAME_OAK
	msgbox PokemonLeague_HallOfFame_Text_TroyToOak, MSGBOX_DEFAULT
	msgbox PokemonLeague_HallOfFame_Text_OakToTroy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_HALLOFFAME_TROY, PokemonLeague_HallOfFame_Movement_TroyLeave
	waitmovement LOCALID_HALLOFFAME_TROY
	playse SE_EXIT
	removeobject LOCALID_HALLOFFAME_TROY
	applymovement LOCALID_HALLOFFAME_OAK, Common_Movement_WalkUp
	waitmovement LOCALID_HALLOFFAME_OAK
	msgbox PokemonLeague_HallOfFame_Text_OakComeToLab, MSGBOX_DEFAULT
	closemessage
	return

@ From the door (4,12) to (4,6), next to Oak.
PokemonLeague_HallOfFame_Movement_TroyEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

@ From the door (5,12) to (5,6), two tiles below the player; steps up after Troy leaves.
PokemonLeague_HallOfFame_Movement_OakEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_TroyLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PokemonLeague_HallOfFame_Movement_LanceEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	face_left
	step_end

PokemonLeague_HallOfFame_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_right
	step_end

PokemonLeague_HallOfFame_LanceText:
#if GERMAN
	.string "Siegfried: Es ist lange her, dass ich\n"
	.string "zuletzt hier war.\p"
	.string "Hier ehren wir die Liga-Champions\n"
	.string "für alle Ewigkeit.\p"
	.string "Auch ihre mutigen Pokémon werden\n"
	.string "hier aufgenommen.\p"
	.string "Heute erlebten wir den Aufstieg\n"
	.string "eines neuen Liga-Champions -\p"
	.string "eines Trainers, der Mitgefühl und\n"
	.string "Vertrauen gegenüber allen Pokémon\l"
	.string "zeigt.\p"
	.string "Eines Trainers, der durch Ausdauer und\n"
	.string "Entschlossenheit erfolgreich war.\p"
	.string "Der neue Liga-Champion hat alles,\n"
	.string "was zu Größe gehört!\p"
	.string "{PLAYER}, lass mich dich und deine\n"
	.string "Partner als Champions eintragen!$"
#else
    .string "LANCE: It's been a long time since I\n"
    .string "last came here.\p"
    .string "This is where we honor the LEAGUE\n"
    .string "CHAMPIONS for all eternity.\p"
    .string "Their courageous POKéMON are also\n"
    .string "inducted.\p"
    .string "Here today, we witnessed the rise\n"
    .string "of a new LEAGUE CHAMPION--a\p"
    .string "trainer who feels compassion for,\n"
    .string "and trust toward, all POKéMON.\p"
    .string "A trainer who succeeded through\n"
    .string "perseverance and determination.\p"
    .string "The new LEAGUE CHAMPION who has\n"
    .string "all the makings of greatness!\p"
    .string "{PLAYER}, allow me to register you\n"
    .string "and your partners as CHAMPIONS!$"
#endif

PokemonLeague_HallOfFame_Text_TroyToOak:
#if GERMAN
	.string "???: Professor Eich! Verzeihen Sie\n"
	.string "die Störung.\p"
	.string "Ich muss dringend etwas mit Ihnen\n"
	.string "besprechen.\p"
	.string "Ich warte in Ihrem Labor.$"
#else
	.string "???: PROF. OAK! Forgive the\n"
	.string "interruption.\p"
	.string "I urgently need to talk to you.\p"
	.string "I'll wait for you in your LAB.$"
#endif

PokemonLeague_HallOfFame_Text_OakToTroy:
#if GERMAN
	.string "Prof. Eich: Oh! …Gut, ich komme,\n"
	.string "so schnell ich kann.$"
#else
	.string "PROF.OAK: Oh! …Very well, I'll come\n"
	.string "as soon as I can.$"
#endif

PokemonLeague_HallOfFame_Text_OakComeToLab:
#if GERMAN
	.string "Prof. Eich: {PLAYER}!\p"
	.string "Wenn du wieder zu Hause bist, komm\n"
	.string "bitte in mein Labor.$"
#else
	.string "PROF.OAK: {PLAYER}!\p"
	.string "When you're back home, please\n"
	.string "come to my LAB.$"
#endif

PokemonLeague_HallOfFame_Rematch_LanceText:
#if GERMAN
	.string "Siegfried: Wieder stehen wir hier,\n"
	.string "wo wir die besten Trainer und ihre\l"
	.string "Pokémon ehren.\p"
	.string "Du hast die Top Vier und mich\n"
	.string "erneut besiegt.\p"
	.string "Deine Pokémon vertrauen dir. Dieses\n"
	.string "Band führt dich immer wieder\l"
	.string "zum Sieg.\p"
	.string "Es ist mir eine Ehre, {PLAYER},\n"
	.string "dich und deine treuen Partner\l"
	.string "erneut als Champs einzutragen.$"
#else
    .string "LANCE: Here we stand once more,\n"
    .string "where we honor the very best\l"
    .string "trainers and their POKéMON.\p"
    .string "You have beaten the ELITE FOUR and\n"
    .string "me once again.\p"
    .string "Your POKéMON trust you. That bond\n"
    .string "leads you to victory time and\l"
    .string "again.\p"
    .string "{PLAYER}, it is my honor to register\n"
    .string "you and your trusted partners\l"
    .string "as champions once again.$"
#endif

