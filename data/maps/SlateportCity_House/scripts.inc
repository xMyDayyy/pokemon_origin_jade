SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	lock
	faceplayer
	checkitem ITEM_CONTEST_PASS
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_House_EventScript_HaveContestPass
	msgbox SlateportCity_House_Text_NeedContestPass, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_EventScript_HaveContestPass::
	msgbox SlateportCity_House_Text_HaveContestPass, MSGBOX_DEFAULT
	release
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
#if GERMAN
	.string "Mein Pokémon hat ein Hastiges Wesen.\p"
	.string "Seine Initiative ist im Vergleich\n"
	.string "zu meinen anderen Pokémon höher.\p"
	.string "Vielleicht hat ihr Wesen etwas mit den\n"
	.string "Statusvorteilen der Pokémon zu tun.$"
#else
	.string "My POKéMON has a HASTY nature.\p"
	.string "It has higher SPEED compared to\n"
	.string "my other POKéMON.\p"
	.string "Maybe their nature has something to\n"
	.string "do with the stat gains of POKéMON.$"
#endif

SlateportCity_House_Text_NeedContestPass:
#if GERMAN
	.string "Um an einem Wettbewerb teilnehmen zu\n"
	.string "können, brauchst du eine\l"
	.string "Wettbewerbskarte.\p"
	.string "Die bekommst du leicht. Jeder, der ein\n"
	.string "Pokémon hat, bekommt eine.$"
#else
	.string "You need a CONTEST PASS to enter a\n"
	.string "CONTEST.\p"
	.string "It's easy to get. They give it to\n"
	.string "anyone who has POKéMON.$"
#endif

SlateportCity_House_Text_HaveContestPass:
#if GERMAN
	.string "Oh, eine Wettbewerbskarte!\n"
	.string "Bist du auch ein Bewerber?$"
#else
	.string "Oh, a CONTEST PASS!\n"
	.string "You're going to be a contestant?$"
#endif

