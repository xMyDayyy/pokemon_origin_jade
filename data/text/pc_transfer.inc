gText_PkmnTransferredSomeonesPC::
#if GERMAN
	.string "{STR_VAR_2} wurde auf Jemandes PC\n"
	.string "übertragen.\p"
	.string "Es wurde in Box “{STR_VAR_1}” abgelegt.$"
#else
	.string "{STR_VAR_2} was transferred to\n"
	.string "SOMEONE'S PC.\p"
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"
#endif

gText_PkmnTransferredLanettesPC::
#if GERMAN
#if IS_FRLG || IS_HNS
	.string "{STR_VAR_2} wurde auf Bills PC\n"
#else
	.string "{STR_VAR_2} wurde auf Lanettes PC\n"
#endif
	.string "übertragen.\p"
	.string "Es wurde in Box\n"
	.string "“{STR_VAR_1}” abgelegt.$"
#else
	.string "{STR_VAR_2} was transferred to\n"
#if IS_FRLG || IS_HNS
	.string "BILL's PC.\p"
#else
	.string "LANETTE's PC.\p"
#endif
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"
#endif

gText_PkmnTransferredSomeonesPCBoxFull::
#if GERMAN
	.string "Box “{STR_VAR_3}” in\n"
	.string "Jemandes PC ist voll.\p"
	.string "{STR_VAR_2} wurde in Box “{STR_VAR_1}”\n"
	.string "übertragen.$"
#else
	.string "BOX “{STR_VAR_3}” on\n"
	.string "SOMEONE'S PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
#endif

gText_PkmnTransferredLanettesPCBoxFull::
#if GERMAN
	.string "Box “{STR_VAR_3}” in\n"
#if IS_FRLG || IS_HNS
	.string "Bills PC ist voll.\p"
#else
	.string "Lanettes PC ist voll.\p"
#endif
	.string "{STR_VAR_2} wurde in Box\n"
	.string "“{STR_VAR_1}” übertragen.$"
#else
	.string "BOX “{STR_VAR_3}” on\n"
#if IS_FRLG || IS_HNS
	.string "BILL's PC was full.\p"
#else
	.string "LANETTE's PC was full.\p"
#endif
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"
#endif

gText_PkmnSentToPCAfterCatch::
#if GERMAN
	.string "{STR_VAR_2} wurde auf {B_PC_CREATOR_NAME} PC\n"
	.string "übertragen.\p"
	.string "Es wurde in Box “{STR_VAR_1}” abgelegt.$"
#else
	.string "{STR_VAR_2} was sent to\n"
	.string "{B_PC_CREATOR_NAME} PC.\p"
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}”.$"
#endif

gText_PlayerObtainedTheMon::
#if GERMAN
	.string "{PLAYER} erhält das {STR_VAR_1}!$"
#else
	.string "{PLAYER} obtained\n"
	.string "the {STR_VAR_1}!$"
#endif

gText_NoMoreRoomForPokemon::
#if GERMAN
	.string "Es ist kein Platz mehr für Pokémon\n"
	.string "vorhanden!\p"
	.string "Die Pokémon Boxen sind voll und es kann\n"
	.string "kein Pokémon mehr abgelegt werden!$"
#else
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"
#endif

gText_NicknameThisPokemon::
#if GERMAN
	.string "Möchtest du {STR_VAR_1} einen Spitznamen\n"
	.string "geben?$"
#else
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"
#endif
