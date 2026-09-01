SaffronCity_Gym_hns_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA_HNS, SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN_HNS, SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS_HNS, SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED_HNS, SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA_HNS, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	msgbox SaffronCity_Gym_Text_Sabrina_GiveTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SKILL_SWAP
	msgbox SaffronCity_Gym_Text_Sabrina_ExplainTM, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers_hns
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}Sabrina: Ich wusste, dass du kommst!\p"
	.string "Ich hatte schon vor drei Jahren eine\n"
	.string "Vision, die mir deine Ankunft ankündigte.\l"
	.string "Du hast es auf meinen Orden abgesehen!\p"
	.string "Kämpfe bereiten mir nur wenig Freude…\p"
	.string "Aber als Leiterin ist es meine Pflicht,\n"
	.string "all denen einen Orden zu überreichen,\l"
	.string "die sich als würdig erweisen.\p"
	.string "Wenn das also dein Wunsch ist, werde\n"
	.string "ich dir meine Psycho-Kräfte zeigen!$"
#else
	.string "SABRINA: I knew you were coming…\p"
	.string "Three years ago I had a vision\n"
	.string "of your arrival.\p"
	.string "You're after my BADGE.\p"
	.string "I don't enjoy battling, but it's\n"
	.string "my duty as a LEADER to confer\l"
	.string "BADGES on anyone who has proven\l"
	.string "him- or herself worthy.\p"
	.string "Since you wish it, I will show\n"
	.string "you my psychic powers!$"
#endif

SaffronCity_Gym_Text_SabrinaWinLoss:
#if GERMAN
	.string "Sabrina: Diese Stärke… in meiner\n"
	.string "Vision warst du viel schwächlicher!\p"
	.string "Scheinbar kann nicht einmal ich die\n"
	.string "Zukunft vollständig vorhersehen…\p"
	.string "Aber gut. Hier, das ist der Sumpforden.\n"
	.string "Du hast ihn dir verdient.$"
#else
	.string "SABRINA: Your power…\p"
	.string "It far exceeds what I foresaw…\p"
	.string "Maybe it isn't possible to fully\n"
	.string "predict what the future holds…\p"
	.string "OK, you win. You earned yourself\n"
	.string "MARSHBADGE.$"
#endif

SaffronCity_Gym_Text_ReceivedMarshBadge:
#if GERMAN
	.string "{PLAYER} erhielt den Sumpforden.$"
#else
	.string "{PLAYER} received MARSHBADGE.$"
#endif

SaffronCity_Gym_Text_MarshBadgeInfo:
#if GERMAN
	.string "Sabrina: Der Sumpforden weckt deine\n"
	.string "verborgenen Kräfte…\p"
	.string "Auch wenn ich deine Kraft nicht genau\n"
	.string "vorhersehen konnte, das weiß ich mit\l"
	.string "Sicherheit:\p"
	.string "Du wirst ein gefeierter und geliebter\n"
	.string "Champion!$"
#else
	.string "SABRINA: MARSHBADGE draws out\n"
	.string "your subliminal powers…\p"
	.string "Although I failed to accurately\n"
	.string "predict your power, this much I\l"
	.string "know to be true.\p"
	.string "You will become a celebrated and\n"
	.string "beloved CHAMPION!$"
#endif

SaffronCity_Gym_Text_Sabrina_GiveTM:
	.string "Here, take this as well.$"

SaffronCity_Gym_Text_Sabrina_ExplainTM:
	.string "It holds SKILL SWAP.\p"
	.string "It can take your opponents' abilities\n"
	.string "away from them and give them your own.\p"
	.string "Use it wisely...$"

SaffronCity_Gym_Text_SabrinaPostBattle:
#if GERMAN
	.string "Sabrina: Deine Liebe zu deinen Pokémon\n"
	.string "hat meine Psychokraft überwältigt…\p"
	.string "Die Kraft der Liebe ist wohl auch eine\n"
	.string "Art Psychokraft…$"
#else
	.string "SABRINA: Your love for your\n"
	.string "POKéMON overwhelmed my psychic\l"
	.string "power…\p"
	.string "The power of love, I think, is\n"
	.string "also a kind of psychic power…$"
#endif

SaffronCity_Gym_Text_SabrinaRematch:
#if GERMAN
	.string "Sabrina: Ah, der Kanto-champion.\p"
	.string "Ich spürte deine Rückkehr.\p"
	.string "Deine Kraft ist enorm gewachsen.\p"
	.string "Selbst jetzt spüre ich deine Aura.\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "SABRINA: Ah, the KANTO CHAMPION.\p"
	.string "I sensed your return.\p"
	.string "Your power has grown immensely.\p"
	.string "Even now, I feel your aura.\p"
	.string "Want to have a rematch with me?$"
#endif

SaffronCity_Gym_Text_SabrinaRematchDefeat:
#if GERMAN
	.string "Sabrina: Deine Liebe zu deinen Pokémon\n"
	.string "hat meine Psychokraft wieder\l"
	.string "überwältigt…$"
#else
	.string "SABRINA: Your love for your\n"
	.string "POKéMON again overwhelmed my\l"
	.string "psychic power…$"
#endif

SaffronCity_Gym_Text_MediumRebeccaSeen:
#if GERMAN
	.string "Ich spüre, wie die Kraft all derer, die du\n"
	.string "besiegt hast, in meinen Körper strömt!$"
#else
	.string "The power of all those you\n"
	.string "defeated comes to me!$"
#endif

SaffronCity_Gym_Text_MediumRebeccaBeaten:
#if GERMAN
	.string "Du bist stark… viel zu stark!$"
#else
	.string "Strong… Far too strong…$"
#endif

SaffronCity_Gym_Text_MediumRebeccaAfter:
#if GERMAN
	.string "Sage es mir! Was ist die Quelle deiner\n"
	.string "Kraft?$"
#else
	.string "What is the source of your power?$"
#endif

SaffronCity_Gym_Text_PsychicFranklinSeen:
#if GERMAN
	.string "Psychokraft ist die Kraft deiner Seele.$"
#else
	.string "Psychic power is the power of\n"
	.string "your soul.$"
#endif

SaffronCity_Gym_Text_PsychicFranklinBeaten:
#if GERMAN
	.string "Du kennst deine Seele besser als ich.\n"
	.string "Deshalb habe ich verloren!$"
#else
	.string "Your soul has more power than\n"
	.string "mine!$"
#endif

SaffronCity_Gym_Text_PsychicFranklinAfter:
#if GERMAN
	.string "Du hast auch deine Seele gestärkt,\n"
	.string "nicht nur deine Fähigkeiten.$"
#else
	.string "You made your soul stronger, not\n"
	.string "just your abilities.$"
#endif

SaffronCity_Gym_Text_MediumDorisSeen:
#if GERMAN
	.string "Hehehehe… ich habe sie deutlich vor mir.\p"
	.string "Ich kann in die Tiefen deiner Seele\n"
	.string "blicken!$"
#else
	.string "Fufufufu… I see it clearly.\p"
	.string "I can see into your soul!$"
#endif

SaffronCity_Gym_Text_MediumDorisBeaten:
#if GERMAN
	.string "Ich kenne zwar die Tiefen deiner Seele,\n"
	.string "aber verloren ist verloren!$"
#else
	.string "Though I read you, I still lost…$"
#endif

SaffronCity_Gym_Text_MediumDorisAfter:
#if GERMAN
	.string "Mist!\n"
	.string "Dabei hatte ich doch vorausgesehen,\l"
	.string "dass ich gegen dich verlieren würde!\l"
	.string "Ich hatte es bloß verdrängt!$"
#else
	.string "Darn! I forgot that I predicted I\n"
	.string "would lose to you.$"
#endif

SaffronCity_Gym_Text_PsychicJaredSeen:
#if GERMAN
	.string "Das Karate Dojo nebenan war früher die\n"
	.string "Pokémon-Arena der Stadt.$"
#else
	.string "The FIGHTING DOJO next door was\n"
	.string "once this city's GYM.$"
#endif

SaffronCity_Gym_Text_PsychicJaredBeaten:
#if GERMAN
	.string "Mit dir kann ich mich nicht messen…$"
#else
	.string "I was no match…$"
#endif

SaffronCity_Gym_Text_PsychicJaredAfter:
#if GERMAN
	.string "Selbst der Karate-Meister, der Leiter\n"
	.string "des Karate Dojo persönlich,\p"
	.string "musste eine ziemlich üble Niederlage\n"
	.string "von Sabrina einstecken.$"
#else
	.string "KARATE KING, the master of the\n"
	.string "FIGHTING DOJO, was just destroyed\l"
	.string "by SABRINA.$"
#endif

SaffronCity_Gym_Text_GymGuideIntro:
#if GERMAN
	.string "Hey, du! Zukünftiger Champ!\p"
	.string "Einem Trainer deines Kalibers brauche\n"
	.string "ich sicher nicht erklären, wie man mit\l"
	.string "Psycho-Pokémon umgeht, nicht wahr?\p"
	.string "Ich erwarte Großes von dir!\n"
	.string "Viel Glück!$"
#else
	.string "Yo, CHAMP in making!\p"
	.string "A trainer as skilled as you\n"
	.string "doesn't need to be told how to\l"
	.string "deal with PSYCHIC-type POKéMON,\l"
	.string "right?\p"
	.string "I expect great things from you!\p"
	.string "Good luck!$"
#endif

SaffronCity_Gym_Text_GymGuideWin:
#if GERMAN
	.string "Das war ein fantastischer Kampf!$"
#else
	.string "That was another fantastic battle!$"
#endif

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
#if GERMAN
    .string "Pokémon-Arena von Saffronia City\n"
    .string "Leiterin: Sabrina\p"
	.string "Anerkannte Trainer:\n"
	.string "Blau, Rot$"
#else
    .string "SAFFRON POKéMON GYM\n"
    .string "LEADER: SABRINA\p"
	.string "WINNING TRAINERS:\n"
	.string "BLUE, RED$"
#endif

SaffronCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
    .string "Pokémon-Arena von Saffronia City\n"
    .string "Leiterin: Sabrina\p"
    .string "Anerkannte Trainer:\n"
	.string "Blau, Rot, {PLAYER}$"
#else
    .string "SAFFRON POKéMON GYM\n"
    .string "LEADER: SABRINA\p"
    .string "WINNING TRAINERS:\n"
	.string "BLUE, RED, {PLAYER}$"
#endif
