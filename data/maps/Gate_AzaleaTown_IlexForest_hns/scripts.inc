Gate_AzaleaTown_IlexForest_hns_MapScripts::
	.byte 0

Gate_AzaleaTown_IlexForest_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_EventScript_Granny::
	lock
	faceplayer
	msgbox Gate_AzaleaTown_IlexForest_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_AzaleaTown_IlexForest_Text_Officer:
#if GERMAN
	.string "Pass auf, dass du dich nicht verläufst!\n"
	.string "Der Steineichenwald ist sehr groß!$"
#else
	.string "ILEX FOREST is big.\n"
	.string "Be careful!\l"
	.string "Don't get lost.$"
#endif

Gate_AzaleaTown_IlexForest_Text_Granny:
#if GERMAN
	.string "Es heißt, ein Schutzpatron wache über\n"
	.string "den Steineichenwald…\l"
	.string "Mach also besser keine Dummheiten!$"
#else
	.string "The ILEX FOREST is watched\n"
	.string "over by its protector.\p"
	.string "Stay out of mischief!$"
#endif
