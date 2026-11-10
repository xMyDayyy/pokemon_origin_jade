Route26_House1_hns_MapScripts::
	.byte 0

Route26_House1_EventScript_HealWoman::
	lock
	faceplayer
	@ Pokemon Center challenge: no rest and no heal.
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, Route26_House1_EventScript_HealWoman_PokecenterChallenge
	msgbox Route26_Text_HealHouseRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route26_Text_HealHouseKeepAtIt, MSGBOX_DEFAULT
	release
	end

Route26_House1_EventScript_HealWoman_PokecenterChallenge::
	msgbox SSAquaRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	release
	end


Route26_Text_HealHouseRest:
#if GERMAN
	.string "Deine Pokémon sehen müde aus.\p"
	.string "Gönne ihnen eine kleine Pause.$"
#else
    .string "Your POKéMON look a little tired.\p"
    .string "You should rest them a while.$"
#endif

Route26_Text_HealHouseKeepAtIt:
#if GERMAN
	.string "In Ordnung! Deine Pokémon sind wieder\n"
	.string "fit! Dann stürze dich wieder ins\l"
	.string "Abenteuer!$"
#else
    .string "There!\p"
    .string "Your POKéMON are looking good!\p"
    .string "Keep at it!$"
#endif
