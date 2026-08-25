MtMoon_Cave_Frlg_MapScripts::
	.byte 0

MtMoonCave_EventScript_Mew::
	lock
	faceplayer
	setwildbattle SPECIES_MEW, 40
	waitse
	playmoncry SPECIES_MEW, CRY_MODE_ENCOUNTER
	message MtMoonCave_Text_Mew
	waitmessage
	waitmoncry
	delay 10
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtMoonCave_EventScript_DefeatedMew
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMoonCave_EventScript_RanFromMew
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtMoonCave_EventScript_RanFromMew
	setflag FLAG_HIDE_MEW_KANTO
	release
	end

MtMoonCave_EventScript_DefeatedMew::
	setflag FLAG_HIDE_MEW_KANTO
	goto EventScript_RemoveStaticMon
	end

MtMoonCave_EventScript_RanFromMew::
	setvar VAR_0x8004, SPECIES_MEW
	goto EventScript_RemoveStaticMon
	end

MtMoonCave_Text_Mew::
	.string "Mew!$"
