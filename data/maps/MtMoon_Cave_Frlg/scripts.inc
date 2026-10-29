MtMoon_Cave_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoonCave_OnTransition
	.byte 0

@ Mew: legendary rules, see docs/origin_jade/DECISIONS.md, D-026.
MtMoonCave_OnTransition::
	setflag FLAG_HIDE_MEW_KANTO
	setvar VAR_0x8004, LEGENDARY_MEW
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_eq VAR_RESULT, TRUE, MtMoonCave_EventScript_ShowMew
	end

MtMoonCave_EventScript_ShowMew::
	clearflag FLAG_HIDE_MEW_KANTO
	return

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
	setvar VAR_0x8004, LEGENDARY_MEW
	special RecordLegendaryBattleOutcome
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_RemoveStaticMon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_RemoveStaticMon
	setvar VAR_0x8004, SPECIES_MEW
	goto EventScript_MonFlewAway

MtMoonCave_Text_Mew::
	.string "Mew!$"
