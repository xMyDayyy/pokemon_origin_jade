FallarborTown_ContestHall_MapScripts::
	.byte 0

@ Audience hall behind Fallarbor's contest lobby, as in Ruby/Sapphire.

FallarborTown_ContestHall_EventScript_Man::
	msgbox FallarborTown_ContestHall_Text_DoAllRightInPreliminary, MSGBOX_NPC
	end

FallarborTown_ContestHall_EventScript_Woman::
	msgbox FallarborTown_ContestHall_Text_MonAllTheseRibbons, MSGBOX_NPC
	end

FallarborTown_ContestHall_EventScript_Youngster::
	msgbox FallarborTown_ContestHall_Text_CantWinEverywhere, MSGBOX_NPC
	end

FallarborTown_ContestHall_EventScript_StageSign::
	msgbox FallarborTown_ContestHall_Text_SuperRankStage, MSGBOX_SIGN
	end

FallarborTown_ContestHall_Text_DoAllRightInPreliminary:
#if GERMAN
	.string "Im 1. Durchlauf schneiden wir immer\n"
	.string "gut ab, aber im 2. Durchlauf…\p"
	.string "Vielleicht sollte ich beobachten, was\n"
	.string "die anderen Teilnehmer machen…$"
#else
	.string "We do all right in the preliminary round,\n"
	.string "but we can never win the appeals…\p"
	.string "Maybe it means I have to watch what\n"
	.string "other contestants are doing…$"
#endif

FallarborTown_ContestHall_Text_MonAllTheseRibbons:
#if GERMAN
	.string "Schau mal! Mein Pokémon hat all\n"
	.string "diese Bänder gewonnen!\p"
	.string "Besitzen deine Pokémon auch Bänder?\n"
	.string "Du kannst das im PokéCom überprüfen.$"
#else
	.string "See!\n"
	.string "My POKéMON won all these RIBBONS!\p"
	.string "Have your POKéMON earned any RIBBONS?\n"
	.string "You can check them on your POKéGEAR.$"
#endif

FallarborTown_ContestHall_Text_CantWinEverywhere:
#if GERMAN
	.string "Ich kann Arenaleiter nicht besiegen…\p"
	.string "Ich kann keine Wettbewerbe gewinnen…\p"
	.string "Ich war schon hier und dort und überall,\n"
	.string "aber immer vergebens.$"
#else
	.string "I can't beat GYM LEADERS…\p"
	.string "I can't win any CONTESTS…\p"
	.string "I've been here, there, and everywhere,\n"
	.string "and it's all for naught…$"
#endif

FallarborTown_ContestHall_Text_SuperRankStage:
#if GERMAN
	.string "Pokémon-Wettbewerbe\n"
	.string "Bühne für die Super-Klasse!$"
#else
	.string "POKéMON CONTESTS\n"
	.string "SUPER RANK STAGE!$"
#endif
