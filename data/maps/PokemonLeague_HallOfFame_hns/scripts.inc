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

@ Every Johto title: knocked-out legendaries return (D-026), the Hall of Fame screen saves, then the
@ player continues in New Bark Town in front of Elm's lab, without credits.
@ See docs/origin_jade/DECISIONS.md, D-028.
PokemonLeague_HallOfFame_EventScript_GameClear:
	call Common_EventScript_ReviveDefeatedLegendaries
	setrespawn HEAL_LOCATION_NEW_BARK_TOWN_LAB_HNS
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
	return

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

