CeruleanCity_Gym_Frlg_MapScripts::
	.byte 0

CeruleanCity_Gym_EventScript_Misty::
	famechecker FAMECHECKER_MISTY, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_MISTY, CeruleanCity_Gym_Text_MistyIntro, CeruleanCity_Gym_Text_MistyDefeat, CeruleanCity_Gym_EventScript_MistyDefeated, NO_MUSIC
	goto_if_unset FLAG_GOT_TM03_FROM_MISTY, CeruleanCity_Gym_EventScript_GiveTM03
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_MistyDefeated::
	famechecker FAMECHECKER_MISTY, 1
	setflag FLAG_DEFEATED_MISTY
	setflag FLAG_BADGE02_GET
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	set_gym_trainers_frlg 2
	goto CeruleanCity_Gym_EventScript_GiveTM03
	end

CeruleanCity_Gym_EventScript_GiveTM03::
	msgbox CeruleanCity_Gym_Text_ExplainCascadeBadge
	checkitemspace ITEM_TM03
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_Gym_EventScript_NoRoomForTM03
	giveitem_msg CeruleanCity_Gym_Text_ReceivedTM03FromMisty, ITEM_TM03
	setflag FLAG_GOT_TM03_FROM_MISTY
	msgbox CeruleanCity_Gym_Text_ExplainTM03
	release
	end

CeruleanCity_Gym_EventScript_NoRoomForTM03::
	msgbox CeruleanCity_Gym_Text_BetterMakeRoomForThis
	release
	end

CeruleanCity_Gym_EventScript_Diana::
	trainerbattle_single TRAINER_PICNICKER_DIANA, CeruleanCity_Gym_Text_DianaIntro, CeruleanCity_Gym_Text_DianaDefeat
	msgbox CeruleanCity_Gym_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_Luis::
	trainerbattle_single TRAINER_SWIMMER_MALE_LUIS, CeruleanCity_Gym_Text_LuisIntro, CeruleanCity_Gym_Text_LuisDefeat
	famechecker FAMECHECKER_MISTY, 2
	msgbox CeruleanCity_Gym_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MISTY, CeruleanCity_Gym_EventScript_GymGuyPostVictory
	msgbox CeruleanCity_Gym_Text_GymGuyAdvice
	release
	end

CeruleanCity_Gym_EventScript_GymGuyPostVictory::
	msgbox CeruleanCity_Gym_Text_WeMakePrettyGoodTeam
	release
	end

CeruleanCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanCity_Gym_Text_MistyIntro::
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}Du musst neu sein, ich habe dich\n"
	.string "noch nie gesehen!\p"
	.string "Wenn ein Trainer zum Profi werden\n"
	.string "möchte, muss er sich eine\l"
	.string "Pokémon-Taktik erarbeiten!\p"
	.string "Auf welche Weise fängst du deine\n"
	.string "Pokémon?\p"
	.string "Meine Strategie basiert auf dem\n"
	.string "gnadenlosen Offensiv-Einsatz von\l"
	.string "Wasser-Pokémon!$"
#else
	.string "Hi, you're a new face!\p"
	.string "Only those TRAINERS who have a\n"
	.string "policy about POKéMON can turn pro.\p"
	.string "What is your approach when you\n"
	.string "catch and train POKéMON?\p"
	.string "My policy is an all-out offensive\n"
	.string "with WATER-type POKéMON!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

CeruleanCity_Gym_Text_ExplainTM03::
#if GERMAN
	.string "TM03 ist die Aquawelle!\p"
	.string "Wasser-Pokémon können diese\n"
	.string "Attacke erlernen!$"
#else
	.string "TM03 teaches WATER PULSE.\p"
	.string "Use it on an aquatic POKéMON!$"
#endif

CeruleanCity_Gym_Text_ExplainCascadeBadge::
#if GERMAN
	.string "Der Quellorden ist der Beweis, dass du\n"
	.string "mich besiegt hast!\p"
	.string "Deine Pokémon können den Zerschneider\n"
	.string "nun jederzeit einsetzen!\p"
	.string "Du kannst kleine Büsche zerhacken\n"
	.string "und so neue Wege freilegen!\p"
	.string "Zu guter Letzt schenke ich dir\n"
	.string "noch meine Lieblings-TM!$"
#else
	.string "The CASCADEBADGE is proof that\n"
	.string "you defeated me.\p"
	.string "There's more. You can now use CUT\n"
	.string "anytime, even out of battle.\p"
	.string "You can CUT down small trees to\n"
	.string "open new pathways.\p"
	.string "You can also have my favorite TM.$"
#endif

CeruleanCity_Gym_Text_ReceivedTM03FromMisty::
#if GERMAN
	.string "{PLAYER} erhält TM03!$"
#else
	.string "{PLAYER} received TM03\n"
	.string "from MISTY.$"
#endif

CeruleanCity_Gym_Text_BetterMakeRoomForThis::
#if GERMAN
	.string "Du hast momentan keinen Platz für\n"
	.string "mein Geschenk!$"
#else
	.string "You better make room for this!$"
#endif

CeruleanCity_Gym_Text_MistyDefeat::
#if GERMAN
	.string "Wow!\n"
	.string "Du bist sehr gut!\p"
	.string "Alles klar!\p"
	.string "Ich überlasse dir den Quellorden\n"
	.string "als Zeichen deines Triumphes!$"
#else
	.string "Wow!\n"
	.string "You're too much!\p"
	.string "All right!\p"
	.string "You can have the CASCADEBADGE to\n"
	.string "show you beat me.$"
#endif

CeruleanCity_Gym_Text_DianaIntro::
#if GERMAN
	.string "Wie? Du?\n"
	.string "Ich bin schon zu gut für dich!\p"
	.string "Misty muss sich nicht mit dir abgeben!$"
#else
	.string "What? You?\n"
	.string "I'm more than good enough for you!\p"
	.string "MISTY won't have to be bothered.$"
#endif

CeruleanCity_Gym_Text_DianaDefeat::
#if GERMAN
	.string "Ich bin überwältigt!$"
#else
	.string "You overwhelmed me!$"
#endif

CeruleanCity_Gym_Text_DianaPostBattle::
#if GERMAN
	.string "Du musst dich anderen Trainern stellen,\n"
	.string "um herauszufinden, wie gut du bist.$"
#else
	.string "You have to face other TRAINERS\n"
	.string "to see how good you really are.$"
#endif

CeruleanCity_Gym_Text_LuisIntro::
#if GERMAN
	.string "Platsch!\p"
	.string "Ich bin dein erster Gegner!\n"
	.string "Es geht los!$"
#else
	.string "Splash!\p"
	.string "I'm first up!\n"
	.string "Let's do it!$"
#endif

CeruleanCity_Gym_Text_LuisDefeat::
#if GERMAN
	.string "Das darf nicht wahr sein!$"
#else
	.string "That can't be!$"
#endif

CeruleanCity_Gym_Text_LuisPostBattle::
#if GERMAN
	.string "Misty verbessert stets ihr Können!\p"
	.string "Jemand wie du hat keine Chance,\n"
	.string "sie zu besiegen!$"
#else
	.string "MISTY is a TRAINER who's going to\n"
	.string "keep improving.\p"
	.string "She won't lose to someone like you!$"
#endif

CeruleanCity_Gym_Text_GymGuyAdvice::
#if GERMAN
	.string "Heh!\n"
	.string "Warte, du Champion in spe!\p"
	.string "Ich habe einen Tipp für dich!\p"
	.string "Misty, die Arenaleiterin, kämpft\n"
	.string "mit Wasser-Pokémon!\p"
	.string "Du kannst ihnen das Wasser mit\n"
	.string "Pflanzen-Pokémon entziehen!\p"
	.string "Elektro-Pokémon dürften sich auch\n"
	.string "als nützlich erweisen!$"
#else
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "Let me give you some advice!\p"
	.string "The LEADER, MISTY, is a pro who\n"
	.string "uses WATER-type POKéMON.\p"
	.string "You can drain all their water with\n"
	.string "GRASS-type POKéMON.\p"
	.string "Or, you might use ELECTRIC-type\n"
	.string "POKéMON and zap them!$"
#endif

CeruleanCity_Gym_Text_WeMakePrettyGoodTeam::
#if GERMAN
	.string "Du hast Misty besiegt! Habe ich es\n"
	.string "nicht gesagt?\p"
	.string "Glaub mir, wir beide bilden ein\n"
	.string "sehr gutes Team!$"
#else
	.string "You beat MISTY!\n"
	.string "See, what'd I tell ya?\p"
	.string "You and me, kid, we make a pretty\n"
	.string "darn-good team!$"
#endif

CeruleanCity_Gym_Text_GymStatue::
#if GERMAN
	.string "Azuria Pokémon-Arena\n"
	.string "Leitung: Misty\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}$"
#else
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
#endif

CeruleanCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
	.string "Azuria Pokémon-Arena\n"
	.string "Leitung: Misty\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "CERULEAN POKéMON GYM\n"
	.string "LEADER: MISTY\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif

