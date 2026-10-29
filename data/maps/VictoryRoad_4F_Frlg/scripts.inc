VictoryRoad_4F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_4F_OnTransition
	.byte 0

@ Moltres (battle in VictoryRoad_3F_Frlg): legendary rules, see docs/origin_jade/DECISIONS.md, D-026.
VictoryRoad_4F_OnTransition::
	setflag FLAG_HIDE_MOLTRES_KANTO
	setvar VAR_0x8004, LEGENDARY_MOLTRES
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_eq VAR_RESULT, TRUE, VictoryRoad_4F_EventScript_ShowMoltres
	end

VictoryRoad_4F_EventScript_ShowMoltres::
	clearflag FLAG_HIDE_MOLTRES_KANTO
	return
