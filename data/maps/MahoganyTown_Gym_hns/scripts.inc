MahoganyTown_Gym_hns_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon-Arena von Mahagonia City$"
#else
	.string "MAHOGANY TOWN POKéMON GYM$"
#endif

MahoganyTown_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Mahagonia City\p"
	.string "Leiter: Norbert\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "MAHOGANY TOWN POKéMON GYM\p"
	.string "PRYCE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD_HNS, MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD_HNS, MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS_HNS, MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_HNS, MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA_HNS, MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setvar VAR_0x8004, 6
	special SetJohtoBadge
	setflag FLAG_BADGE07_GET
	@ Pryce: Johto-Orden 7. Die Flag oben teilt sich Johto mit Kanto und
	@ ist nach der Kanto-Liga laengst gesetzt - gezaehlt wird in VAR_JOHTO_BADGES.
	setvar VAR_0x8004, 6
	special SetJohtoBadge
	@ Der Orden ist zugleich die Befugnis fuer Taucher - siehe
	@ src/johto_permits.c. Die Ordensflags teilt sich Johto mit Kanto.
	setvar VAR_0x8004, PERM_DIVE
	special SetJohtoPermit
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANY_TOWN_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_SetupElmRocketCall::
    setvar VAR_TRIGGER_ELM_ROCKET_CALL, 1
    return

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3_HNS, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
#if GERMAN
	.string "Pokémon erleben vieles im Leben,\n"
	.string "so wie wir Menschen.\p"
	.string "Auch ich habe viel erlebt und\n"
	.string "gelitten.\p"
	.string "Da ich älter bin, will ich dir zeigen, was\n"
	.string "ich meine.\p"
	.string "Ich kenne Pokémon schon seit\n"
	.string "vor deiner Geburt.\p"
	.string "Ich verliere nicht leicht.\p"
	.string "Ich, Norbert, der Wintertrainer,\n"
	.string "zeige dir meine Kraft!$"
#else
    .string "POKéMON have many experiences\n"
    .string "in their lives, just like we do.\p"
    .string "I, too, have seen and suffered\n"
    .string "much in my life.\p"
    .string "Since I am your elder, let me\n"
    .string "show you what I mean.\p"
    .string "I have been with POKéMON since\n"
    .string "before you were born.\p"
    .string "I do not lose easily.\p"
    .string "I, PRYCE--the winter trainer--\n"
    .string "shall demonstrate my power!$"
#endif

MahoganyTown_Gym_Text_PryceImpressed:
#if GERMAN
	.string "Ah, ich bin beeindruckt von deiner\n"
	.string "Stärke.\p"
	.string "Mit deinem starken Willen wirst\n"
	.string "du alle Hindernisse überwinden.\p"
	.string "Du verdienst diesen Orden!$"
#else
    .string "Ah, I am impressed by your\n"
    .string "prowess.\p"
    .string "With your strong will, I know you\n"
    .string "will overcome all life's obstacles.\p"
    .string "You are worthy of this BADGE!$"
#endif

MahoganyTown_Gym_Text_ReceivedBadge:
#if GERMAN
	.string "{PLAYER} erhält den Eisorden!$"
#else
    .string "{PLAYER} received GLACIERBADGE.$"
#endif

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
#if GERMAN
	.string "Der Orden erhöht die Spezial-\n"
	.string "attacke deiner Pokémon.\p"
	.string "Er erlaubt deinen Pokémon, Whirlpool zu\n"
	.string "benutzen, um echte Strudel zu\l"
	.string "überqueren.\p"
	.string "Und dies… ist mein Geschenk!$"
#else
    .string "That BADGE will raise the SPECIAL\n"
    .string "ATTACK of POKéMON.\p"
    .string "It also lets your POKéMON use\n"
    .string "WHIRLPOOL to get across\l"
    .string "real whirlpools.\p"
    .string "And this… This is a gift from me!$"
#endif

MahoganyTown_Gym_Text_HailSpeech:
#if GERMAN
	.string "Diese TM enthält Hagelsturm.\p"
	.string "Sie fügt 5 Runden lang Schaden zu.\p"
	.string "So zeigt sie die Härte des Winters.$"
#else
    .string "That TM contains HAIL.\p"
    .string "It inflicts damage every\n"
    .string "turn for 5 turns.\p"
    .string "It demonstrates the harshness\n"
    .string "of winter.$"
#endif

MahoganyTown_Gym_Text_CherishPokemon:
#if GERMAN
	.string "Wenn Eis und Schnee schmelzen,\n"
	.string "kommt der Frühling.\p"
	.string "Du und deine Pokémon werdet viele\n"
	.string "Jahre zusammen verbringen.\p"
	.string "Schätzt eure gemeinsame Zeit!$"
#else
    .string "When the ice and snow melt,\n"
    .string "spring arrives.\p"
    .string "You and your POKéMON will be\n"
    .string "together for many years to come.\p"
    .string "Cherish your time together!$"
#endif

MahoganyTown_Gym_Text_PryceRematch:
#if GERMAN
	.string "Ah, Johto Champion!\p"
	.string "Deine Fähigkeiten sind wirklich\n"
	.string "bemerkenswert.\p"
	.string "Ich bin beeindruckt.\p"
	.string "Doch noch können wir voneinander\n"
	.string "lernen.\p"
	.string "Ich, Norbert, der Wintertrainer,\n"
	.string "habe noch einige Tricks.\p"
	.string "Willst du ein Rückmatch mit mir?$"
#else
    .string "Ah, JOHTO CHAMPION!\p"
    .string "Your skills are indeed\n"
    .string "remarkable.\p"
    .string "I am impressed.\p"
    .string "But even now, there is much to\n"
    .string "learn from each other.\p"
    .string "I, PRYCE--the winter trainer--\n"
    .string "still have a few tricks left.\p"
    .string "Want to have a rematch with me?$"
#endif

MahoganyTown_Gym_Text_PryceRematchDefeat:
#if GERMAN
	.string "Ah, wieder bin ich beeindruckt\n"
	.string "von deiner Stärke.\p"
	.string "Mit deinem starken Willen wirst\n"
	.string "du alle Hindernisse überwinden.$"
#else
    .string "Ah, yet again I'm impressed by\n"
    .string "your prowess.\p"
    .string "With your strong will, I know you\n"
    .string "will overcome all life's obstacles.$"
#endif

MahoganyTown_Gym_Text_Guide:
#if GERMAN
	.string "Norbert ist ein Veteran, der seine\n"
	.string "Pokémon seit fast 50 Jahren trainiert.\p"
	.string "Angeblich friert er Gegner gerne\n"
	.string "mit Eis-Attacken ein.\p"
	.string "Also, nutze deinen Ehrgeiz!$"
#else
    .string "PRYCE is a veteran who has\n"
    .string "trained POKéMON for some 50 years.\p"
    .string "He's got a solid lineup of\n"
    .string "POKéMON to cover whatever\l"
    .string "you bring his way.\p"
    .string "Fire is a good place to start,\n"
    .string "but watch out for the rain!$"
#endif

MahoganyTown_Gym_Text_GuideWin:
#if GERMAN
	.string "Norbert ist stark, aber du bist besser!\p"
	.string "Ein heißer Kampf, der die Generationen\n"
	.string "überbrückt hat.$"
#else
    .string "PRYCE is something, but you're\n"
    .string "something else!\p"
    .string "That was a hot battle that\n"
    .string "bridged the generation gap!$"
#endif

MahoganyTown_Gym_Text_BoarderRonaldSeen:
#if GERMAN
	.string "Ich friere deine Pokémon ein,\n"
	.string "damit du nichts tun kannst!$"
#else
    .string "I'll freeze your POKéMON,\n"
    .string "so you can't do a thing!$"
#endif

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
#if GERMAN
	.string "Verdammt. Ich konnte nichts tun.$"
#else
    .string "Darn. I couldn't do a thing.$"
#endif

MahoganyTown_Gym_Text_BoarderRonaldAfter:
#if GERMAN
	.string "Vielleicht gibt es eine Attacke, die\n"
	.string "Pokémon anwenden können, wenn sie\l"
	.string "eingefroren sind.$"
#else
    .string "I think there's a move a\n"
    .string "POKéMON can use while it's\l"
    .string "frozen.$"
#endif

MahoganyTown_Gym_Text_BoarderBradSeen:
#if GERMAN
	.string "Diese Pokémon-Arena hat einen\n"
	.string "rutschigen Boden. Lustig, oder?\p"
	.string "Aber wir sind nicht hier, um\n"
	.string "rumzublödeln!$"
#else
    .string "This GYM has a slippery floor.\p"
    .string "It's fun, isn't it?\p"
    .string "But hey--we're not playing\n"
    .string "games here!$"
#endif

MahoganyTown_Gym_Text_BoarderBradBeaten:
#if GERMAN
	.string "Siehst du jetzt, wie ernst wir es\n"
	.string "meinen?$"
#else
    .string "Do you see how serious we are?$"
#endif

MahoganyTown_Gym_Text_BoarderBradAfter:
#if GERMAN
	.string "Diese Arena ist großartig.\n"
	.string "Ich liebe Snowboarden mit meinen\l"
	.string "Pokémon!$"
#else
    .string "This GYM is great.\n"
    .string "I love boarding with my\l"
    .string "POKéMON!$"
#endif

MahoganyTown_Gym_Text_BoarderDouglasSeen:
#if GERMAN
	.string "Ich kenne Norberts Geheimnis.$"
#else
    .string "I know PRYCE's secret.$"
#endif

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
#if GERMAN
	.string "Na gut. Ich verrate dir Norberts\n"
	.string "Geheimnis.$"
#else
    .string "OK. I'll tell you PRYCE's secret.$"
#endif

MahoganyTown_Gym_Text_BoarderDouglasAfter:
#if GERMAN
	.string "Das Geheimnis von Norberts Kraft…\p"
	.string "Er meditiert täglich unter einer\n"
	.string "Kaskade, um Körper und Geist zu\l"
	.string "stärken.$"
#else
    .string "The secret behind PRYCE's power…\p"
    .string "He meditates under a waterfall\n"
    .string "daily to strengthen his mind\l"
    .string "and body.$"
#endif

MahoganyTown_Gym_Text_SkierRoxanneSeen:
#if GERMAN
	.string "Um zu Norbert, unserem Arenaleiter, zu\n"
	.string "gelangen, musst du denken, bevor du\l"
	.string "losrutschst.$"
#else
    .string "To get to PRYCE, our GYM LEADER,\n"
    .string "you need to think before you skate.$"
#endif

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
#if GERMAN
	.string "Beim Skifahren würde ich nie gegen dich\n"
	.string "verlieren.$"
#else
    .string "I wouldn't lose to you in skiing!$"
#endif

MahoganyTown_Gym_Text_SkierRoxanneAfter:
#if GERMAN
	.string "Wenn du nicht genau rutschst, kommst\n"
	.string "du in dieser Arena nicht weit. Gerade\l"
	.string "das macht ihren Charme aus.$"
#else
    .string "If you don't skate with precision,\n"
    .string "you won't get far in this GYM.$"
#endif

MahoganyTown_Gym_Text_SkierClarissaSeen:
#if GERMAN
	.string "Sieh dir meinen Parallelschwung an!$"
#else
    .string "Check out my parallel turn!$"
#endif

MahoganyTown_Gym_Text_SkierClarissaBeaten:
#if GERMAN
	.string "Nein! Jetzt bin ich weggerutscht!$"
#else
    .string "No! You made me wipe out!$"
#endif

MahoganyTown_Gym_Text_SkierClarissaAfter:
#if GERMAN
	.string "Ich hätte mit meinen Ski-Künsten nicht\n"
	.string "so angeben sollen…$"
#else
    .string "I shouldn't have been bragging\n"
    .string "about my skiing…$"
#endif

