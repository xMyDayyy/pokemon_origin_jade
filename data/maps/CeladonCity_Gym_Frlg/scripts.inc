CeladonCity_Gym_Frlg_MapScripts::
	.byte 0

CeladonCity_Gym_EventScript_Erika::
	famechecker FAMECHECKER_ERIKA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_ERIKA, CeladonCity_Gym_Text_ErikaIntro, CeladonCity_Gym_Text_ErikaDefeat, CeladonCity_Gym_EventScript_DefeatedErika, NO_MUSIC
	goto_if_unset FLAG_GOT_TM19_FROM_ERIKA, CeladonCity_Gym_EventScript_GiveTM19
	famechecker FAMECHECKER_ERIKA, 4
	msgbox CeladonCity_Gym_Text_ErikaPostBattle
	release
	end

CeladonCity_Gym_EventScript_DefeatedErika::
	famechecker FAMECHECKER_ERIKA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_ERIKA_JOURNALS
	setflag FLAG_DEFEATED_ERIKA
	setflag FLAG_BADGE04_GET
	set_gym_trainers_frlg 4
	goto CeladonCity_Gym_EventScript_GiveTM19
	end

CeladonCity_Gym_EventScript_GiveTM19::
	msgbox CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis
	checkitemspace ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_Gym_EventScript_NoRoomForTM19
	giveitem_msg CeladonCity_Gym_Text_ReceivedTM19FromErika, ITEM_TM19
	setflag FLAG_GOT_TM19_FROM_ERIKA
	msgbox CeladonCity_Gym_Text_ExplainTM19
	release
	end

CeladonCity_Gym_EventScript_NoRoomForTM19::
	msgbox CeladonCity_Gym_Text_ShouldMakeRoomForThis
	release
	end

CeladonCity_Gym_EventScript_Kay::
	trainerbattle_single TRAINER_LASS_KAY, CeladonCity_Gym_Text_KayIntro, CeladonCity_Gym_Text_KayDefeat
	msgbox CeladonCity_Gym_Text_KayPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lisa::
	trainerbattle_single TRAINER_LASS_LISA, CeladonCity_Gym_Text_LisaIntro, CeladonCity_Gym_Text_LisaDefeat
	famechecker FAMECHECKER_ERIKA, 2
	msgbox CeladonCity_Gym_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tina::
	trainerbattle_single TRAINER_PICNICKER_TINA, CeladonCity_Gym_Text_TinaIntro, CeladonCity_Gym_Text_TinaDefeat
	msgbox CeladonCity_Gym_Text_TinaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BEAUTY_BRIDGET, CeladonCity_Gym_Text_BridgetIntro, CeladonCity_Gym_Text_BridgetDefeat
	msgbox CeladonCity_Gym_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Tamia::
	trainerbattle_single TRAINER_BEAUTY_TAMIA, CeladonCity_Gym_Text_TamiaIntro, CeladonCity_Gym_Text_TamiaDefeat
	famechecker FAMECHECKER_ERIKA, 3
	msgbox CeladonCity_Gym_Text_TamiaPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Lori::
	trainerbattle_single TRAINER_BEAUTY_LORI, CeladonCity_Gym_Text_LoriIntro, CeladonCity_Gym_Text_LoriDefeat
	msgbox CeladonCity_Gym_Text_LoriPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_COOLTRAINER_MARY, CeladonCity_Gym_Text_MaryIntro, CeladonCity_Gym_Text_MaryDefeat
	msgbox CeladonCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_ErikaIntro::
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}Ist das Wetter nicht wundervoll?\n"
	.string "Einfach herrlich!\p"
	.string "Du meine Güte... ich muss kurz\n"
	.string "eingenickt sein! Willkommen!\p"
	.string "Ich bin Erika, die Arenaleiterin\n"
	.string "von Prismania City!\p"
	.string "Ich liebe die Kräfte der Natur!\n"
	.string "Deshalb trainiere ich\l"
	.string "Pflanzen-Pokémon.\p"
	.string "Du möchtest gegen mich antreten?\n"
	.string "Also gut!\p"
	.string "Ich werde ohnehin nicht verlieren!$"
#else
	.string "Hello…\n"
	.string "Lovely weather, isn't it?\l"
	.string "It's so pleasant…\p"
	.string "…Oh, dear…\n"
	.string "I must have dozed off. Welcome.\p"
	.string "My name is ERIKA.\n"
	.string "I am the LEADER of CELADON GYM.\p"
	.string "I am a student of the art of\n"
	.string "flower arranging.\p"
	.string "My POKéMON are solely of the\n"
	.string "GRASS type.\p"
	.string "…Oh, I'm sorry, I had no idea that\n"
	.string "you wished to challenge me.\p"
	.string "Very well, but I shall not lose.{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

CeladonCity_Gym_Text_ErikaDefeat::
#if GERMAN
	.string "Ich muss meine Niederlage eingestehen!\p"
	.string "Deine Stärke ist beachtlich!\n"
	.string "Ich übergebe dir den Farborden!$"
#else
	.string "Oh!\n"
	.string "I concede defeat.\l"
	.string "You are remarkably strong.\p"
	.string "I must confer on you the\n"
	.string "RAINBOWBADGE.$"
#endif

CeladonCity_Gym_Text_ErikaPostBattle::
#if GERMAN
	.string "Du katalogisierst Pokémon?\n"
	.string "Ich bin beeindruckt!\p"
	.string "Ich würde niemals Pokémon sammeln,\n"
	.string "die mich nicht interessieren!$"
#else
	.string "You are cataloging POKéMON?\n"
	.string "I must say I'm impressed.\p"
	.string "I would never collect POKéMON if\n"
	.string "they were unattractive.$"
#endif

CeladonCity_Gym_Text_ExplainRainbowBadgeTakeThis::
#if GERMAN
	.string "Der Farborden ist dein verdienter\n"
	.string "Lohn.\p"
	.string "Außerdem können deine Pokémon nun\n"
	.string "Stärke außerhalb von Kämpfen\l"
	.string "anwenden.\p"
	.string "Nimm bitte noch dieses Geschenk:$"
#else
	.string "The RAINBOWBADGE is your\n"
	.string "well-earned reward.\p"
	.string "It also allows POKéMON to use\n"
	.string "STRENGTH in and out of battle.\p"
	.string "Please also take this with you.$"
#endif

CeladonCity_Gym_Text_ReceivedTM19FromErika::
#if GERMAN
	.string "{PLAYER} erhält TM19!$"
#else
	.string "{PLAYER} received TM19\n"
	.string "from ERIKA.$"
#endif

CeladonCity_Gym_Text_ExplainTM19::
#if GERMAN
	.string "TM19 ist Gigasauger.\p"
	.string "Dein Pokémon erhält die Hälfte der KP,\n"
	.string "die diese Attacke dem Gegner abzieht!$"
#else
	.string "TM19 contains GIGA DRAIN.\p"
	.string "Half the damage it inflicts is\n"
	.string "drained to heal your POKéMON.\p"
	.string "Wouldn't you agree that it's a\n"
	.string "wonderful move?$"
#endif

CeladonCity_Gym_Text_ShouldMakeRoomForThis::
#if GERMAN
	.string "Du solltest etwas Platz schaffen!$"
#else
	.string "You should make room for this.$"
#endif

CeladonCity_Gym_Text_KayIntro::
#if GERMAN
	.string "Ich sollte dir etwas über diese Arena\n"
	.string "erzählen.\l"
	.string "Nur echte Damen sind hier zugelassen!$"
#else
	.string "I should tell you about this GYM.\p"
	.string "Only real ladies are allowed in\n"
	.string "here!$"
#endif

CeladonCity_Gym_Text_KayDefeat::
#if GERMAN
	.string "Sei nicht so grob zu mir!$"
#else
	.string "You're too rough!$"
#endif

CeladonCity_Gym_Text_KayPostBattle::
#if GERMAN
	.string "Buääh!\n"
	.string "Das wird Erika dir heimzahlen!$"
#else
	.string "Bleaah!\n"
	.string "I hope ERIKA wipes you out!$"
#endif

CeladonCity_Gym_Text_BridgetIntro::
#if GERMAN
	.string "Mir wurde es schon langweilig!$"
#else
	.string "Oh, welcome.\n"
	.string "I was getting bored.$"
#endif

CeladonCity_Gym_Text_BridgetDefeat::
#if GERMAN
	.string "Meine Frisur!\n"
	.string "Ganz zerzaust!$"
#else
	.string "My makeup!$"
#endif

CeladonCity_Gym_Text_BridgetPostBattle::
#if GERMAN
	.string "Pflanzen-Pokémon sind gegenüber\n"
	.string "Wasser-Pokémon im Vorteil!\p"
	.string "Ebenso sind sie Stein- und\n"
	.string "Boden-Pokémon überlegen!$"
#else
	.string "GRASS-type POKéMON are tough\n"
	.string "against the WATER type.\p"
	.string "They also have an edge on ROCK-\n"
	.string "and GROUND-type POKéMON.$"
#endif

CeladonCity_Gym_Text_TinaIntro::
#if GERMAN
	.string "… hast du nicht schon einmal hier herein\n"
	.string "geschaut?$"
#else
	.string "…Weren't you peeking in here\n"
	.string "earlier?$"
#endif

CeladonCity_Gym_Text_TinaDefeat::
#if GERMAN
	.string "Ich bin schockiert!$"
#else
	.string "You're an eye-opener!$"
#endif

CeladonCity_Gym_Text_TinaPostBattle::
#if GERMAN
	.string "Oh, du hast Erika angesehen…\n"
	.string "und nicht mich…$"
#else
	.string "Oh, you were looking at ERIKA…\n"
	.string "You weren't looking at me…$"
#endif

CeladonCity_Gym_Text_TamiaIntro::
#if GERMAN
	.string "Schau dir meine Pflanzen-Pokémon\n"
	.string "an!\p"
	.string "Man kann sie ohne Mühe trainieren!$"
#else
	.string "Look, look!\n"
	.string "See my POKéMON!\p"
	.string "I like the GRASS type.\n"
	.string "I like how they're easy to raise.$"
#endif

CeladonCity_Gym_Text_TamiaDefeat::
#if GERMAN
	.string "Nein!$"
#else
	.string "No!$"
#endif

CeladonCity_Gym_Text_TamiaPostBattle::
#if GERMAN
	.string "Wir trainieren ausschließlich\n"
	.string "Pflanzen-Pokémon in unserer Arena!\p"
	.string "Wir lieben die Kräfte der Natur!$"
#else
	.string "We only use GRASS-type POKéMON at\n"
	.string "our GYM.\p"
	.string "Why? We also use them for making\n"
	.string "flower arrangements!$"
#endif

CeladonCity_Gym_Text_LisaIntro::
#if GERMAN
	.string "Bringe bloß keine Käfer- oder\n"
	.string "Feuer-Pokémon hierher!$"
#else
	.string "Oh, hey!\p"
	.string "We don't like BUG- or FIRE-type\n"
	.string "POKéMON in here!$"
#endif

CeladonCity_Gym_Text_LisaDefeat::
#if GERMAN
	.string "Oh!\n"
	.string "Du Grobian!$"
#else
	.string "Oh!\n"
	.string "You!$"
#endif

CeladonCity_Gym_Text_LisaPostBattle::
#if GERMAN
	.string "Wenngleich Erika schüchtern wirkt, ist\n"
	.string "sie eine sehr begabte Arenaleiterin!$"
#else
	.string "Our LEADER ERIKA might be quiet,\n"
	.string "but she's famous around here.$"
#endif

CeladonCity_Gym_Text_LoriIntro::
#if GERMAN
	.string "Ich habe die Ehre... ich liebe\n"
	.string "Pokémon-Kämpfe!$"
#else
	.string "Pleased to meet you.\n"
	.string "My hobby is POKéMON training.$"
#endif

CeladonCity_Gym_Text_LoriDefeat::
#if GERMAN
	.string "Oh!\n"
	.string "Ausgezeichnet!$"
#else
	.string "Oh!\n"
	.string "Splendid!$"
#endif

CeladonCity_Gym_Text_LoriPostBattle::
#if GERMAN
	.string "Es war mir eine Ehre! Wunderbar!\n"
	.string "Mein Benimm-Kurs zeigt Wirkung!$"
#else
	.string "I have a blind date coming up.\n"
	.string "I have to learn to be polite,\l"
	.string "especially if I have to battle.$"
#endif

CeladonCity_Gym_Text_MaryIntro::
#if GERMAN
	.string "Willkommen in der Pokémon-Arena\n"
	.string "von Prismania City!\p"
	.string "Unterschätze niemals die Girl-\n"
	.string "Power!$"
#else
	.string "Welcome to CELADON GYM!\p"
	.string "You'd better not underestimate\n"
	.string "the nice ladies here.$"
#endif

CeladonCity_Gym_Text_MaryDefeat::
#if GERMAN
	.string "Ich habe verloren!$"
#else
	.string "Oh!\n"
	.string "Beaten!$"
#endif

CeladonCity_Gym_Text_MaryPostBattle::
#if GERMAN
	.string "Meine besten Pokémon hatte ich\n"
	.string "nicht dabei!\p"
	.string "Warte nur, beim nächsten Mal…$"
#else
	.string "I didn't bring my best POKéMON.\n"
	.string "Wait until next time!$"
#endif

CeladonCity_Gym_Text_GymStatue::
#if GERMAN
	.string "Prismania Pokémon-Arena\n"
	.string "Leitung: Erika\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}$"
#else
	.string "CELADON POKéMON GYM\n"
	.string "LEADER: ERIKA\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
#endif

CeladonCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
	.string "Prismania Pokémon-Arena\n"
	.string "Leitung: Erika\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "CELADON POKéMON GYM\n"
	.string "LEADER: ERIKA\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif

