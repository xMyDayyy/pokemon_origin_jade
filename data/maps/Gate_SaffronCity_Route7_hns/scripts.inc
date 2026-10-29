Gate_SaffronCity_Route7_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route7_EventScript_Guard::
	goto_if_set FLAG_RETURNED_MACHINE_PART, Gate_SaffronCity_Route7_EventScript_GuardReturnedPart
	msgbox Route7_Text_SaffronGuard_PowerPlant, MSGBOX_NPC
	end

Gate_SaffronCity_Route7_EventScript_GuardReturnedPart::
	msgbox Route7_Text_SaffronGuard_Serious, MSGBOX_NPC
	end

Route7_Text_SaffronGuard_PowerPlant:
#if GERMAN
	.string "Anscheinend hat es im Kraftwerk\n"
	.string "einen Unfall gegeben.\p"
	.string "Es liegt östlich von hier, in der Nähe\n"
	.string "von Lavandia.$"
#else
	.string "Did you hear about the accident\n"
	.string "at the POWER PLANT?\p"
	.string "It's located in the East, close\n"
	.string "to LAVENDER TOWN.$"
#endif

Route7_Text_SaffronGuard_Serious:
#if GERMAN
	.string "Ich nehme meinen Posten als Wache\n"
	.string "ernst.\p"
	.string "Hey! Du hast einen Pokédex!\n"
	.string "Alles klar, du darfst passieren!$"
#else
	.string "I take my GUARD job seriously.\p"
	.string "Hey! You have a POKéDEX.\p"
	.string "OK. You can go through.$"
#endif
