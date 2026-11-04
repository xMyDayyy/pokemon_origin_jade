MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
#if GERMAN
	.string "Wenn ich hier bin… dann durchströmt\n"
	.string "mich eine seltsame Macht…$"
#else
	.string "When I'm here…\n"
	.string "A curious power flows into me…$"
#endif

MtPyre_6F_Text_ValerieDefeat:
#if GERMAN
	.string "Die Macht ebbt ab…$"
#else
	.string "The power is ebbing away…$"
#endif

MtPyre_6F_Text_ValeriePostBattle:
#if GERMAN
	.string "Die Geister der hier ruhenden Pokémon,\n"
	.string "erfüllen mich mit ihrer Macht…$"
#else
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"
#endif

MtPyre_6F_Text_ValerieRegister:
#if GERMAN
	.string "Hähähä… Ich habe den Kampf verloren,\n"
	.string "aber… ich habe dieses Talent…\p"
	.string "Ohne, dass ich den PokéCom berühren\n"
	.string "muss… Hiyah!$"
#else
	.string "Fufufu… I lost the match, but…\n"
	.string "I have this little ability…\p"
	.string "Without ever laying my hands on\n"
	.string "your POKéGEAR… Hiyah!$"
#endif

MtPyre_6F_Text_ValerieRematchIntro:
#if GERMAN
	.string "Hinter dir…\n"
	.string "W… Was ist das?$"
#else
	.string "Behind you…\n"
	.string "What is it…$"
#endif

MtPyre_6F_Text_ValerieRematchDefeat:
#if GERMAN
	.string "Etwas war da und verschwand…$"
#else
	.string "Something faded away…$"
#endif

MtPyre_6F_Text_ValeriePostRematch:
#if GERMAN
	.string "Die Pokémon, die hier ruhen…\n"
	.string "Manchmal spielen sie…$"
#else
	.string "The POKéMON at rest here…\n"
	.string "Sometimes, they play…$"
#endif

MtPyre_6F_Text_CedricIntro:
#if GERMAN
	.string "Hast du die Orientierung verloren?\n"
	.string "Keine Angst, ich bin ja hier.$"
#else
	.string "Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"
#endif

MtPyre_6F_Text_CedricDefeat:
#if GERMAN
	.string "Du hattest die Orientierung gar\n"
	.string "nicht verloren?$"
#else
	.string "Weren't you lost?$"
#endif

MtPyre_6F_Text_CedricPostBattle:
#if GERMAN
	.string "Mein Gefühl sagte mir, dass ein\n"
	.string "Trainer,\l"
	.string "der sich verlaufen hat, panisch\l"
	.string "reagiert und leichter zu besiegen ist.\p"
	.string "Das war ein schmutziger Versuch…$"
#else
	.string "I had this feeling that a lost TRAINER\n"
	.string "would be panicked and easy to beat.\p"
	.string "It's dirty and I won't try it again…$"
#endif

