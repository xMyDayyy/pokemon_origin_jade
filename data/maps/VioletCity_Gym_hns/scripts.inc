VioletCity_Gym_hns_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD_HNS, VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE_HNS, VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1_HNS, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	special SetJohtoBadge
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_ROOST
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
#if GERMAN
	.string "Falk: Ich bin Falk, der Arenaleiter\n"
	.string "von Viola City!\p"
	.string "Viele Leute sagen, mit Elektro-Attacken\n"
	.string "könne man Pokémon vom Typ Flug\l"
	.string "ganz leicht die Flügel stutzen und\l"
	.string "machen sich so über mich lustig…\p"
	.string "Das kann ich so nicht stehen lassen!\p"
	.string "Wenn du erst mal siehst, wie anmutig\n"
	.string "meine Flug-Pokémon durch die Lüfte\l"
	.string "gleiten, weißt du, was wahre Größe ist!$"
#else
	.string "I'm FALKNER, the VIOLET POKéMON\n"
	.string "GYM leader!\p"
	.string "People say you can clip\n"
	.string "FLYING-type POKéMON's wings\p"
	.string "with a jolt of electricity…\n"
	.string "I won't allow such insults to bird\l"
	.string "POKéMON!\p"
	.string "I'll show you the real power\n"
	.string "of the magnificent bird POKéMON!$"
#endif

VioletGym_Text_Falkner_WinLoss:
#if GERMAN
	.string "…Mist! Das wertvolle Vogel-Pokémon\n"
	.string "meines Vaters…\p"
	.string "Hier, nimm das.\p"
	.string "Es ist der offizielle Flügelorden der\n"
	.string "Pokémon Liga.$"
#else
	.string "…Darn! My dad's cherished bird\n"
	.string "POKéMON…\p"
	.string "All right. Take this.\p"
	.string "It's the official POKéMON LEAGUE\n"
	.string "ZEPHYRBADGE.$"
#endif

VioletGym_Text_ReceivedZephyrBadge:
#if GERMAN
	.string "{PLAYER} erhält den Flügelorden!$"
#else
	.string "{PLAYER} received ZEPHYRBADGE.$"
#endif

VioletGym_Text_Falkner_BadgeExplain:
#if GERMAN
	.string "Flügelorden erhöht die Attacke\n"
	.string "deiner Pokémon.\p"
	.string "Er erlaubt Pokémon auch Blitz\n"
	.string "einzusetzen, wenn sie es lernen,\l"
	.string "können.\p"
	.string "Hier-nimm das auch.$"
#else
	.string "ZEPHYRBADGE raises the ATTACK\n"
	.string "power of POKéMON.\p"
	.string "It also enables POKéMON to use\n"
	.string "FLASH, if they can learn it,\l"
	.string "anytime.\p"
	.string "Here--take this too.$"
#endif

VioletGym_Text_Falkner_TMExplain:
#if GERMAN
	.string "Mit einer TM lernt ein Pokémon\n"
	.string "sofort eine neue Attacke.\p"
	.string "TM51 enthält Ruheort.\p"
	.string "Damit heilt dein Pokémon die Hälfte\n"
	.string "seiner KP, verliert dafür aber bis zum\l"
	.string "Rundenende den Flug-Typ.$"
#else
	.string "By using a TM, a POKéMON will\n"
	.string "instantly learn a new move.\p"
	.string "That TM contains ROOST.\p"
	.string "It restores HP up to half of your\n"
	.string "POKéMON's maximum.\p"
	.string "In other words, it heals your\n"
	.string "POKéMON.$"
#endif

VioletGym_Text_Falkner_AfterFight:
#if GERMAN
	.string "Falk: Du wirst von nun an in den Arenen\n"
	.string "vieler Städte zum Kampf antreten.\p"
	.string "Als Nächstes… ja, als Nächstes nimmst\n"
	.string "du dir am besten Azalea City vor!\p"
	.string "Ich werde noch härter trainieren, um\n"
	.string "der größte Vogelfänger aller Zeiten zu\l"
	.string "werden!$"
#else
	.string "There are POKéMON GYMS in cities\n"
	.string "and towns ahead.\p"
	.string "You should test your skills at\n"
	.string "these GYMS.\p"
	.string "I'm going to train harder to\n"
	.string "become the greatest bird master!$"
#endif

VioletGym_Text_Falkner_Rematch:
#if GERMAN
	.string "Glückwunsch zum Sieg über die\n"
	.string "Top-vier!\p"
	.string "Ich habe meine Vogel-Pokémon\n"
	.string "noch härter trainiert.\p"
	.string "Denkst du, du kannst erneut die Kraft\n"
	.string "der Lüfte meistern?$"
#else
	.string "Congratulations on defeating\n"
	.string "the ELITE 4!\p"
	.string "I've been training my\n"
	.string "FLYING-type POKéMON even harder.\p"
	.string "Think you can take on the power\n"
	.string "of the skies again?$"
#endif

VioletGym_Text_Falkner_RematchLoss:
#if GERMAN
	.string "Wow… Du hast mich wieder geschlagen.\p"
	.string "Ich werde härter trainieren, um der\n"
	.string "beste Vogel-Meister zu werden!$"
#else
	.string "Wow… You beat me again.\p"
	.string "I'm going to train harder to\n"
	.string "become the greatest bird master!$"
#endif

VioletGym_Text_BirdKeeperRod_Seen:
#if GERMAN
	.string "Das Stichwort ist Mut!\p"
	.string "Hier trainieren sie Tag und Nacht,\n"
	.string "um Vogel-Pokémon zu meistern.\p"
	.string "Los geht’s!$"
#else
	.string "The keyword is guts!\p"
	.string "Those here are training night and\n"
	.string "day to become bird POKéMON masters.\p"
	.string "Come on!$"
#endif

VioletGym_Text_BirdKeeperRod_Beaten:
#if GERMAN
	.string "Urgs!$"
#else
	.string "Gaaah!$"
#endif

VioletGym_Text_BirdKeeperRod_After:
#if GERMAN
	.string "Falkners Können ist groß!\p"
	.string "Sei nicht überheblich, nur weil du mich\n"
	.string "geschlagen hast!$"
#else
	.string "FALKNER's skills are for real!\p"
	.string "Don't get cocky just because\n"
	.string "you beat me!$"
#endif

VioletGym_Text_BirdKeeperAbe_Seen:
#if GERMAN
	.string "Mal sehen, ob du gut genug bist\n"
	.string "für Falkner!$"
#else
	.string "Let me see if you are good\n"
	.string "enough to face FALKNER!$"
#endif

VioletGym_Text_BirdKeeperAbe_Beaten:
#if GERMAN
	.string "Das kann nicht wahr sein!$"
#else
	.string "This can't be true!$"
#endif

VioletGym_Text_BirdKeeperAbe_After:
#if GERMAN
	.string "Peinlich. Ich hätte wissen müssen,\n"
	.string "wen ich vor mir habe.$"
#else
	.string "Embarrassing. I should have known\n"
	.string "who I was up against.$"
#endif

VioletGym_Text_GymGuide_Intro:
#if GERMAN
	.string "Hey! Was geht? Ich bin kein Trainer,\n"
	.string "aber ich kann ein paar Tipps geben!\p"
	.string "Hörst du zu?\n"
	.string "Dann pass auf.\p"
	.string "Falkners Trumpf ist eine kräftige\n"
	.string "Eule, die gern Beeren frisst.\p"
	.string "Sie ist nicht die stärkste, aber kann\n"
	.string "viel einstecken.\p"
	.string "Wenn du mehr Tipps willst, geh zur\n"
	.string "Pokémon-Akademie.\p"
	.string "Die Schüler dort kennen sich richtig\n"
	.string "gut aus!$"
#else
	.string "Hey! What's up? I'm no trainer,\n"
	.string "but I can give some advice!\p"
	.string "Believe me! If you believe, a\n"
	.string "championship dream can come true.\p"
	.string "You believe? Then listen.\p"
	.string "FALKNER's ace is a bulky owl\n"
	.string "that loves to eat BERRIES.\p"
	.string "While it's not the strongest,\n"
	.string "it can take a lot of hits.\p"
	.string "You can hurt it with ELECTRIC \n"
	.string "and ROCK-type moves, but watch out\l"
	.string "for MUD-SLAP!\p"
	.string "If you want more help, go visit the\n"
	.string "POKéMON ACADEMY.\p"
	.string "The students there really know\n"
	.string "their stuff!$"
#endif

VioletGym_Text_GymGuide_Win:
#if GERMAN
	.string "Netter Kampf! Mach immer so weiter und\n"
	.string "aus dir wird schon bald ein echter\l"
	.string "Champ!$"
#else
	.string "Nice battle! Keep it up,\n"
	.string "and you'll be the CHAMP in no\l"
	.string "time at all!$"
#endif

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon-Arena von Viola City$"
#else
	.string "VIOLET CITY POKéMON GYM$"
#endif

VioletCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Viola City\p"
	.string "Leiter: Falk\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "VIOLET CITY POKéMON GYM\p"
	.string "FALKNER'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif
