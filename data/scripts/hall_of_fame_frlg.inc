EventScript_SetDefeatedEliteFourFlagsVars::
	setflag FLAG_IS_KANTO_CHAMPION
	@ Origin Jade: opens Cerulean Cave.
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	clearflag FLAG_HIDE_POSTGAME_GOSSIPERS
	call EventScript_ResetEliteFour
	special Script_UpdateTrainerFanClubGameClear
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, FALSE, EventScript_SetReadyTryGiveNationalDexScene
#if IS_HNS
	@ Knocked-out legendaries return after every title, see docs/origin_jade/DECISIONS.md, D-026.
	call Common_EventScript_ReviveDefeatedLegendaries
#else
	call EventScript_ResetLegendaries
#endif
	return

EventScript_SetReadyTryGiveNationalDexScene::
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 2
	return

EventScript_ResetLegendaries::
	clearflag FLAG_LUGIA_FLEW_AWAY
	clearflag FLAG_HO_OH_FLEW_AWAY
	clearflag FLAG_DEOXYS_FLEW_AWAY
	return

EventScript_ResetEliteFourEnd::
	call EventScript_ResetEliteFour
	end

EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_LORELEI
	clearflag FLAG_DEFEATED_BRUNO
	clearflag FLAG_DEFEATED_AGATHA
	clearflag FLAG_DEFEATED_LANCE
	clearflag FLAG_DEFEATED_CHAMP
	cleartrainerflag TRAINER_CHAMPION_FIRST_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_FIRST_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_FIRST_CHARMANDER
	cleartrainerflag TRAINER_CHAMPION_REMATCH_SQUIRTLE
	cleartrainerflag TRAINER_CHAMPION_REMATCH_BULBASAUR
	cleartrainerflag TRAINER_CHAMPION_REMATCH_CHARMANDER
	setvar VAR_MAP_SCENE_POKEMON_LEAGUE, 0
	return
