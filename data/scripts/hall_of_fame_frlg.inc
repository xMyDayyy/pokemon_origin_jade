EventScript_SetDefeatedEliteFourFlagsVars::
	@ Kanto-Merge: Den Titel setzt in HnS erst die zweite Ruhmeshalle. Bei uns
	@ ist Kanto die erste Region, also gehoert er hierher. Ohne ihn zeigt die
	@ Trainerkarte keinen Titel, und die Safari-Wache in Fuchsania sowie die
	@ Eon-Ticket-Frau in Olivia erkennen den Champion nicht.
	setflag FLAG_IS_KANTO_CHAMPION
	@ Der Waechter vor der Hoehle von Azuria steht auf (7,11) und damit auf dem
	@ einzigen Feld, ueber das man den Eingang auf (7,10) erreicht. Sein Flag
	@ wird sonst nur in OneIsland_PokemonCenter_1F gesetzt, und die Sevii-Inseln
	@ sind nicht im Build - die Hoehle waere also nie zu betreten.
	setflag FLAG_HIDE_CERULEAN_CAVE_GUARD
	clearflag FLAG_HIDE_POSTGAME_GOSSIPERS
	call EventScript_ResetEliteFour
	special Script_UpdateTrainerFanClubGameClear
	specialvar VAR_RESULT, IsNationalPokedexEnabled
	call_if_eq VAR_RESULT, FALSE, EventScript_SetReadyTryGiveNationalDexScene
	call EventScript_ResetLegendaries
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
