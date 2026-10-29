CeruleanCave_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CeruleanCave_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCave_B1F_OnTransition
	.byte 0

CeruleanCave_B1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CeruleanCave_B1F_EventScript_TryRemoveMewtwo
	end

CeruleanCave_B1F_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

CeruleanCave_B1F_OnTransition::
	@ Mewtwo: legendary rules, see docs/origin_jade/DECISIONS.md, D-026.
	setflag FLAG_HIDE_MEWTWO
	setvar VAR_0x8004, LEGENDARY_MEWTWO
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_eq VAR_RESULT, TRUE, CeruleanCave_B1F_EventScript_ShowMewtwo
	end

CeruleanCave_B1F_EventScript_ShowMewtwo::
	clearflag FLAG_HIDE_MEWTWO
	return

CeruleanCave_B1F_EventScript_Mewtwo::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	message CeruleanCave_B1F_Text_Mew
	waitmessage
	waitmoncry
	delay 20
	playbgm MUS_RG_ENCOUNTER_GYM_LEADER, 0
	waitbuttonpress
	setwildbattle SPECIES_MEWTWO, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_0x8004, LEGENDARY_MEWTWO
	special RecordLegendaryBattleOutcome
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_RemoveStaticMon
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, CeruleanCave_B1F_EventScript_RanFromMewtwo
	release
	end

CeruleanCave_B1F_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto EventScript_MonFlewAway
	end

CeruleanCave_B1F_Text_Mew::
#if GERMAN
	.string "Wow!$"
#else
	.string "Mew!$"
#endif

