PalletTown_Lab_hns_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_OakBadgeCheck
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_ROUTE28_SCIENTIST, 1
	setvar VAR_PALLETTOWN_LABSTATE, 2
	call_if_unset FLAG_IS_KANTO_CHAMPION, PalletTown_Lab_EventScript_OakKantoLeague
	release
	end

PalletTown_Lab_EventScript_OakKantoLeague::
	msgbox PalletTown_Lab_Text_OakOpenIndigoPlateau, MSGBOX_DEFAULT
	closemessage
	return

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
#if GERMAN
	.string "Wie kommst du mit dem Pokédex voran?$"
#else
	.string "How is your POKéDEX coming?$"
#endif

PalletTown_Lab_Text_OakWelcomeKanto:
#if GERMAN
	.string "Eich: Oh, {PLAYER}!\n"
	.string "Danke, dass du den weiten Weg bis hier\l"
	.string "nach Kanto auf dich genommen hast!\p"
	.string "Na? \n"
	.string "Was hältst du von den Trainern hier?\l"
	.string "Ziemlich stark, was?$"
#else
	.string "OAK: Ah, {PLAYER}!\n"
	.string "It's good of you to come all this\l"
	.string "way to KANTO.\p"
	.string "What do you think of the trainers\n"
	.string "out here? Pretty tough, huh?$"
#endif

PalletTown_Lab_Text_OakLabGoodbye:
#if GERMAN
	.string "Schau ruhig mal wieder vorbei,\n"
	.string "wenn du in der Gegend bist!$"
#else
	.string "If you're in the area, I hope you\n"
	.string "come visit again.$"
#endif

PalletTown_Lab_Text_OakOpenMtSilver:
#if GERMAN
	.string "Eich: Wow! Hervorragend!\p"
	.string "Du hast alle Arenaorden in Kanto\n"
	.string "gesammelt. Gut gemacht!\p"
	.string "Meine Einschätzung von dir war also\n"
	.string "richtig.\p"
	.string "Weißt du was, {PLAYER}?\n"
	.string "Ich treffe Vorkehrungen, damit du zum\l"
	.string "Silberberg kannst.\p"
	.string "Der Silberberg ist ein riesiger\n"
	.string "Berg voller wilder Pokémon.\p"
	.string "Er ist für normale Trainer zu gefährlich\n"
	.string "und daher gesperrt.\p"
	.string "Doch für dich machen wir eine\n"
	.string "Ausnahme, {PLAYER}.\p"
	.string "Geh zum Indigo Plateau.\n"
	.string "Von dort erreichst du den Silberberg.$"
#else
	.string "OAK: Wow! That's excellent!\p"
	.string "You collected the BADGES of GYMS\n"
	.string "in KANTO. Well done!\p"
	.string "I was right in my assessment of\n"
	.string "you.\p"
	.string "Tell you what, {PLAYER}. I'll make\n"
	.string "arrangements so that you can go\l"
	.string "to MT.SILVER.\p"
	.string "MT.SILVER is a big mountain that\n"
	.string "is home to many wild POKéMON.\p"
	.string "It's too dangerous for your average\n"
	.string "trainer, so it's off limits. But\l"
	.string "we can make an exception in your\l"
	.string "case, {PLAYER}.\p"
	.string "Go up to INDIGO PLATEAU. You can\n"
	.string "reach MT.SILVER from there.$"
#endif

PalletTown_Lab_Text_OakOpenIndigoPlateau:
#if GERMAN
	.string "Oh, und wo wir vom Indigo Plateau, reden,\n"
	.string "jetzt wo du 16 orden hast wird die Liga\l"
	.string "bereit sein dich erneut antreten zu\l"
	.string "lassen.\p"
	.string "Sei gewarnt, Siegfried und seine\n"
	.string "Top-Vier werden dich mit voller Härte\l"
	.string "angehen.\p"
	.string "Viel Glück, {PLAYER}!$"
#else
	.string "Oh, and speaking of the INDIGO\n"
	.string "PLATEAU, now that you've earned\l"
	.string "16 badges, the KANTO LEAGUE\l"
	.string "will be ready to accept\l"
	.string "your challenge once again.\p"
	.string "But be warned, LANCE and his\n"
	.string "ELITE FOUR won't go easy on you\l"
	.string "this time.\p"
	.string "Good luck, {PLAYER}!$"
#endif

PalletTown_Lab_Text_OakNoKantoBadges:
#if GERMAN
	.string "Eich: Hm?\n"
	.string "Offensichtlich hast du hier in Kanto\l"
	.string "noch keinen Orden erhalten.\p"
	.string "Die Arenaleiter in Kanto brauchen sich\n"
	.string "nicht vor denen aus Johto verstecken!\l"
	.string "Sie sind alle ernstzunehmende Gegner!\p"
	.string "Aber das hält dich natürlich nicht davon\n"
	.string "ab, sie herauszufordern, oder?$"
#else
	.string "OAK: Hmm? You're not collecting\n"
	.string "KANTO GYM BADGES?\p"
	.string "The GYM LEADERS in KANTO are as\n"
	.string "tough as any you battled in JOHTO.\p"
	.string "I recommend that you challenge them.$"
#endif

PalletTown_Lab_Text_OakYesKantoBadges:
#if GERMAN
	.string "Eich: Ah, wie ich sehe, erkämpfst du dir\n"
	.string "nach und nach auch die Orden der\l"
	.string "Arenaleiter von Kanto!\p"
	.string "Es ist sicher kein leichtes\n"
	.string "Unterfangen, aber du sammelst dabei\l"
	.string "bestimmt viele wertvolle Erfahrungen.\p"
	.string "Besuche mich wieder, wenn du dir hier\n"
	.string "auch alle Orden erkämpft hast!\l"
	.string "Ein Geschenk wird auf dich warten!\p"
	.string "Halte die Ohren steif, {PLAYER}!$"
#else
	.string "OAK: Ah, you're collecting KANTO\n"
	.string "GYM BADGES.\p"
	.string "I imagine that it's hard, but the\n"
	.string "experience is sure to help you.\p"
	.string "Come see me when you get them all.\p"
	.string "I'll have a gift for you.\p"
	.string "Keep trying hard, {PLAYER}!$"
#endif

PalletTown_Lab_Text_OaksAssistant1:
#if GERMAN
	.string "Die Radiosendung Pokémon Talk des\n"
	.string "Profs wird in Kanto nicht ausgestrahlt.\p"
	.string "Schade, ich würde sie gern hören.$"
#else
	.string "The PROF's POKéMON TALK radio\n"
	.string "program isn't aired here in KANTO.\p"
	.string "It's a shame--I'd like to hear it.$"
#endif

PalletTown_Lab_Text_OaksAssistant2:
#if GERMAN
	.string "Dank deiner Arbeit am Pokédex macht die\n"
	.string "Forschung des Profs große\l"
	.string "Fortschritte.$"
#else
	.string "Thanks to your work on the POKéDEX,\n"
	.string "the PROF's research is coming along\l"
	.string "great.$"
#endif

PalletTown_Lab_Text_OaksAssistant3:
#if GERMAN
	.string "Sag es niemandem weiter, aber Pokémon\n"
	.string "Talk von Prof. Eich ist keine\l"
	.string "Live-Sendung.$"
#else
	.string "Don't tell anyone, but PROF.OAK'S\n"
	.string "POKéMON TALK isn't a live broadcast.$"
#endif

PalletTown_Lab_Text_OaksLabPC:
#if GERMAN
	.string "Auf dem PC ist eine E-Mail.\p"
	.string "…\p"
	.string "Prof. Eich, wie läuft deine\n"
	.string "Forschung?\p"
	.string "Ich arbeite weiterhin fleißig.\p"
	.string "Ich hörte Gerüchte, dass {PLAYER}\n"
	.string "ziemlich bekannt geworden ist.\p"
	.string "Das freut mich sehr zu hören.\p"
	.string "Lind aus Neuborkia 8-)$"
#else
	.string "There's an e-mail message on the PC.\p"
	.string "…\p"
	.string "PROF.OAK, how is your research\n"
	.string "coming along?\p"
	.string "I'm still plugging away.\p"
	.string "I heard rumors that {PLAYER} is\n"
	.string "getting quite a reputation.\p"
	.string "I'm delighted to hear that.\p"
	.string "ELM in NEW BARK TOWN 8-)$"
#endif
