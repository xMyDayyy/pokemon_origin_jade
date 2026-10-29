RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
#if IS_HNS
	@ HnS: no handover, the Cut license comes from Roxanne.
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	release
	end
#endif
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
#if IS_HNS
	setvar VAR_0x8004, LIC_CUT
	special SetHoennLicense
	playfanfare MUS_OBTAIN_ITEM
	message Text_HnsCutLicense
	waitmessage
	waitfanfare
	closemessage
#else
	giveitem ITEM_HM_CUT
#endif
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
#if GERMAN
	.string "Diese Entschlossenheit…\n"
	.string "Deine Beweglichkeit…\l"
	.string "Deine Hingabe für Pokémon…\p"
	.string "Du bist wirklich ein talentierter\n"
	.string "Trainer!\p"
	.string "Nein, warte. Sag jetzt nichts.\n"
	.string "Ich brauche dich nur anzuschauen.$"
#else
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained POKéMON…\p"
	.string "You're obviously a skilled TRAINER!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.$"
#endif

RustboroCity_CuttersHouse_Text_ExplainCut:
#if GERMAN
	.string "Diese VM, sie enthält Zerschneider.\p"
	.string "Eine VM ist eine Attacke, die auch\n"
	.string "außerhalb des Kampfes von einem\l"
	.string "Pokémon angewandt werden kann.\p"
	.string "Jedes Pokémon, das diese Attacke\n"
	.string "gelernt hat, kann Bäume damit\p"
	.string "zerschneiden, wenn der Trainer den\n"
	.string "Steinorden besitzt.\p"
	.string "Und, im Gegensatz zur TM, kann eine VM\n"
	.string "mehrfach gelehrt werden.$"
#else
	.string "That HIDDEN MACHINE, or HM for\n"
	.string "short, is CUT.\p"
	.string "An HM move is one that can be used\n"
	.string "by POKéMON outside of battle.\p"
	.string "Any POKéMON that's learned CUT can\n"
	.string "chop down thin trees if the TRAINER\l"
	.string "has earned the STONE BADGE.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.$"
#endif

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
#if GERMAN
	.string "Als sie die Stadt Metarost City\n"
	.string "vergrößert haben, hat mein Vater ihnen\l"
	.string "geholfen.\p"
	.string "Seine Pokémon fällten die Bäume mit\n"
	.string "Zerschneider.$"
#else
	.string "When they were expanding the city of\n"
	.string "RUSTBORO, my dad helped out.\p"
	.string "He made his POKéMON use CUT to clear\n"
	.string "the land of trees.$"
#endif

#if IS_HNS
Text_HnsCutLicense:
#if GERMAN
	.string "{PLAYER} erhält die Lizenz für\n"
	.string "Zerschneider!$"
#else
	.string "{PLAYER} received the licence for\n"
	.string "CUT!$"
#endif
#endif
