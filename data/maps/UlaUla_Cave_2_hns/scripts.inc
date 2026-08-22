UlaUla_Cave_2_hns_MapScripts::
	.byte 0


Alola_Ulaula_BattleMuk::
	lock
	faceplayer
	playmoncry SPECIES_MUK, 0
	msgbox Alola_Ulaula_BattleMuk_Text_0, MSGBOX_AUTOCLOSE
	waitmoncry
	setwildbattle SPECIES_MUK, 60
	dowildbattle
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Alola_Ulaula_BattleMuk_2
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Alola_Ulaula_BattleMuk_3
	release
	end

	release
	end

Alola_Ulaula_BattleMuk_2:
	setflag FLAG_HIDE_MUK_ALOLA
	removeobject Alola_Ulaula_Muk
	release
	end

Alola_Ulaula_BattleMuk_3:
	setflag FLAG_HIDE_MUK_ALOLA
	removeobject Alola_Ulaula_Muk
	release
	end


Alola_Ulaula_BattleMuk_Text_0:
#if GERMAN
	.string "Urgs!$"
#else
	.string "Gaaah!$"
#endif
