CianwoodHouse1_hns_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro, MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
#if GERMAN
	.string "Oh, ein Besucher! Leute wie dich\n"
	.string "sieht man hier nur äußerst selten!\p"
	.string "Als ich noch jung war, habe ich auf\n"
	.string "meinen Reisen als Pokémon-Trainerin\l"
	.string "auch nichts unversucht gelassen.\p"
	.string "Ich habe versucht, Türme zu erklimmen\n"
	.string "und die Tiefen des Meeres zu ergründen.\p"
	.string "Aber inzwischen bin ich schon damit\n"
	.string "zufrieden, an diesem Strand den Wellen\l"
	.string "und der Meeresbrise zu lauschen und ein\l"
	.string "gemütliches Leben zu führen.$"
#else
	.string "I don't remember the last time\n"
	.string "someone came to visit me.\p"
	.string "When I was young, I was a\n"
	.string "POKéMON Trainer, too.\l"
	.string "I tried to reach the tower and\l"
	.string "dive into the ocean.\p"
	.string "I put a lot of effort into many\n"
	.string "things.\p"
	.string "Well, I take things easy now,\n"
	.string "listening to the waves and winds\l"
	.string "on this beach.$"
#endif

CianwoodCity_Text_BellTowerStory:
#if GERMAN
	.string "Kennst du den Glockenturm\n"
	.string "in Teak City?\p"
	.string "An seiner Spitze gibt es ein Artefakt,\n"
	.string "das man die Klarglocke nennt.\p"
	.string "Aber egal, wie stark der Wind auch sein\n"
	.string "mag, der dort weht, sie gibt nie auch nur\l"
	.string "einen Laut von sich.\p"
	.string "Es gibt allerdings eine Möglichkeit,\n"
	.string "sie zum Klingen zu bringen.\p"
	.string "Soll ich dir sagen, wie das geht?\p"
	.string "Indem du dir eine weitere Klarglocke\n"
	.string "besorgst, die mit der an der Spitze des\l"
	.string "Turms identisch ist!\p"
	.string "Auch ich habe vor langer Zeit einmal\n"
	.string "versucht, die Glocke in meinen Besitz zu\l"
	.string "bringen, doch es sollte wohl nicht sein.$"
#else
	.string "Have you heard of the TIN TOWER\n"
	.string "in ECRUTEAK?\p"
	.string "There are what they call Clear Bells\n"
	.string "on top of the tower.\p"
	.string "They don't make a single noise\n"
	.string "in strong winds.\p"
	.string "There is only one way to make them\n"
	.string "ring.\p"
	.string "It is to obtain another CLEAR BELL\n"
	.string "just like the ones at the top of the\l"
	.string "tower.\p"
	.string "I went after it when I was young.\n"
	.string "But I never got one...$"
#endif

CianwoodCity_Text_WhirlIslandsStory:
#if GERMAN
	.string "Sag, kennst du den Wasserfall tief\n"
	.string "unter den Strudelinseln?\p"
	.string "An seinem Grund gibt es ein Artefakt,\n"
	.string "das man die Gischtglocke nennt.\p"
	.string "Aber egal, wie stark die See dort auch\n"
	.string "wütet, sie gibt nie auch nur einen Laut\l"
	.string "von sich.\p"
	.string "Es gibt allerdings eine Möglichkeit,\n"
	.string "sie zum Klingen zu bringen.\p"
	.string "Soll ich dir sagen, wie das geht?\p"
	.string "Indem du dir eine weitere Gischtglocke\n"
	.string "besorgst, die mit der am Grund des\l"
	.string "Wasserfalls identisch ist!\p"
	.string "Auch ich habe vor langer Zeit einmal\n"
	.string "versucht, die Glocke in meinen Besitz zu\l"
	.string "bringen, doch es sollte wohl nicht sein.$"
#else
	.string "Have you heard of WHIRL ISLANDS?\p"
	.string "There are what they call Tidal Bells\n"
	.string "at its waterfall basin.\p"
	.string "They don't make a single noise\n"
	.string "in crashing waves.\p"
	.string "There is only one way to make them\n"
	.string "ring.\p"
	.string "It is to obtain another Tidal Bell\n"
	.string "just like the ones at the waterfall\l"
	.string "basin.\p"
	.string "I went after it when I was young.\n"
	.string "But I never got one...$"
#endif

CianwoodCity_Text_ClearBellReaction:
#if GERMAN
	.string "Oh! Soll das etwa heißen, dass du\n"
	.string "die Klarglocke gefunden hast?\p"
	.string "Du hast geschafft, was mir nie\n"
	.string "vergönnt war…\p"
	.string "Ich verstehe. Du kannst…\p"
	.string "… … …\n"
	.string "Du kannst ihn wohl hören…\p"
	.string "Du kannst den Klang der Klarglocke\n"
	.string "hören, den der Wind vom Glockenturm\l"
	.string "herabweht…$"
#else
	.string "Oh! You've managed to get a\n"
	.string "CLEAR BELL?\p"
	.string "The old-time dream of mine...\n"
	.string "I see...\p"
	.string "You've done it...\n"
	.string "...\l"
	.string "...I can hear it!\p"
	.string "The chime of the bells on the wind\n"
	.string "coming from the direction of the\l"
	.string "TIN TOWER...$"
#endif

CianwoodCity_Text_TidalBellReaction:
#if GERMAN
	.string "Oh! Soll das etwa heißen, dass du\n"
	.string "die Gischtglocke gefunden hast?\p"
	.string "Du hast geschafft, was mir nie\n"
	.string "vergönnt war…\p"
	.string "Ich verstehe. Du kannst…\p"
	.string "… … …\n"
	.string "Du kannst ihn wohl hören…\p"
	.string "Du kannst den Klang der Gischtglocke\n"
	.string "hören, den die Meeresbrise aus den\l"
	.string "Tiefen der Strudelinseln heraufbläst…$"
#else
	.string "Oh! You've managed to get a\n"
	.string "Tidal Bell?\p"
	.string "The old-time dream of mine...\n"
	.string "I see...\p"
	.string "You've done it...\n"
	.string "...\l"
	.string "...I can hear it!\p"
	.string "The chime of the bells on the sea\n"
	.string "breeze coming from the direction of\l"
	.string "the WHIRL ISLANDS...$"
#endif
