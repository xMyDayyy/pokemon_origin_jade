AzaleaTown_House1_hns_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_ge VAR_ILEX_FOREST_FARFETCHD, 3, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end



CharcoalKiln_Text_Boss1:
#if GERMAN
	.string "In der Stadt gibt es kein einziges\n"
	.string "Flegmon mehr.\p"
	.string "Vielleicht haben wir ja den Zorn des\n"
	.string "Schutzpatrons auf uns gezogen?\p"
	.string "Das könnte ein böses Vorzeichen sein.\n"
	.string "Wir sollten auf alles gefasst sein…$"
#else
	.string "All the SLOWPOKE have disappeared\n"
	.string "from the town.\p"
	.string "The forest's protector may be\n"
	.string "angry with us…\p"
	.string "It may be a bad omen. We should\n"
	.string "stay in.$"
#endif

CharcoalKiln_Text_Boss2:
#if GERMAN
	.string "Die Flegmon sind zurück…$"
#else
	.string "The SLOWPOKE have returned…$"
#endif

CharcoalKiln_Text_Boss3:
#if GERMAN
	.string "Die Flegmon sind zurück…\p"
	.string "Aber mein Lehrling ist noch nicht\n"
	.string "aus dem Steineichenwald zurück.\p"
	.string "Wo steckt dieser faule Kerl nur?$"
#else
	.string "The SLOWPOKE have returned…\p"
	.string "But my APPRENTICE hasn't come back\n"
	.string "from ILEX FOREST.\p"
	.string "Where in the world is that lazy guy?$"
#endif

CharcoalKiln_Text_Boss4:
#if GERMAN
	.string "Du hast Team Rocket vertrieben und\n"
	.string "bist alleine in den Steineichenwald\l"
	.string "gegangen. Du hast Mumm! Das gefällt mir!\p"
	.string "Was sagst du, würdest du nicht gerne\n"
	.string "bei mir in die Lehre gehen?$"
#else
	.string "You chased off TEAM ROCKET and\n"
	.string "went to ILEX FOREST alone?\p"
	.string "That takes guts! I like that.\n"
	.string "Come train with us.$"
#endif

CharcoalKiln_Text_Apprentice1:
#if GERMAN
	.string "Wo sind nur all die Flegmon hin?\n"
	.string "Machen sie sich vielleicht irgendwo\l"
	.string "einen schönen Lenz?$"
#else
	.string "Where have all the SLOWPOKE gone?\p"
	.string "Are they out playing somewhere?$"
#endif

CharcoalKiln_Text_Apprentice2:
#if GERMAN
	.string "Die Flegmon sind wieder da!$"
#else
	.string "The SLOWPOKE came back!$"
#endif

CharcoalKiln_Text_Apprentice3:
#if GERMAN
	.string "E-Entschuldige, ich habe vergessen\n"
	.string "mich zu bedanken.\p"
	.string "Das hier ist Holzkohle, sie verstärkt\n"
	.string "Feuer-Attacken. Gib sie einem Pokémon.$"
#else
	.string "I'm sorry--I forgot to thank you.\p"
	.string "This is CHARCOAL that I made.\p"
	.string "FIRE-type POKéMON would be happy\n"
	.string "to hold that.$"
#endif

CharcoalKiln_Text_Apprentice4:
#if GERMAN
	.string "Die Flegmon sind wieder da, und die\n"
	.string "Porenta hast du auch wiedergefunden.\l"
	.string "Du bist echt der Coolste!$"
#else
	.string "The SLOWPOKE came back, and you even\n"
	.string "found FARFETCH'D.\p"
	.string "You're the coolest, man!$"
#endif

CharcoalKiln_Text_Farfetchd:
#if GERMAN
	.string "Porenta: Pooorenta!$"
#else
	.string "FARFETCH'D: Kwaa!$"
#endif
