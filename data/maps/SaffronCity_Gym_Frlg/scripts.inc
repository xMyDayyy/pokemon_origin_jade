SaffronCity_Gym_Frlg_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_Sabrina::
	famechecker FAMECHECKER_SABRINA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_SABRINA, SaffronCity_Gym_Text_SabrinaIntro, SaffronCity_Gym_Text_SabrinaDefeat, SaffronCity_Gym_EventScript_DefeatedSabrina, NO_MUSIC
	goto_if_unset FLAG_GOT_TM04_FROM_SABRINA, SaffronCity_Gym_EventScript_GiveTM04
	msgbox SaffronCity_Gym_Text_ExplainTM04
	release
	end

SaffronCity_Gym_EventScript_DefeatedSabrina::
	famechecker FAMECHECKER_SABRINA, 2
	famechecker FAMECHECKER_SABRINA, 3
	clearflag FLAG_HIDE_SAFFRON_CITY_POKECENTER_SABRINA_JOURNALS
	setflag FLAG_DEFEATED_SABRINA
	setflag FLAG_BADGE06_GET
	set_gym_trainers_frlg 6
	call Common_EventScript_ObedienceLevel40IfSixthBadge
	goto SaffronCity_Gym_EventScript_GiveTM04
	end

SaffronCity_Gym_EventScript_GiveTM04::
	msgbox SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis
	checkitemspace ITEM_TM04
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_Gym_EventScript_NoRoomForTM04
	giveitem_msg SaffronCity_Gym_Text_ReceivedTM04FromSabrina, ITEM_TM04
	setflag FLAG_GOT_TM04_FROM_SABRINA
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle
	release
	end

SaffronCity_Gym_EventScript_NoRoomForTM04::
	msgbox SaffronCity_Gym_Text_BagFullOfOtherItems
	release
	end

SaffronCity_Gym_EventScript_Johan::
	trainerbattle_single TRAINER_PSYCHIC_JOHAN, SaffronCity_Gym_Text_JohanIntro, SaffronCity_Gym_Text_JohanDefeat
	msgbox SaffronCity_Gym_Text_JohanPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tyron::
	trainerbattle_single TRAINER_PSYCHIC_TYRON, SaffronCity_Gym_Text_TyronIntro, SaffronCity_Gym_Text_TyronDefeat
	famechecker FAMECHECKER_SABRINA, 5
	msgbox SaffronCity_Gym_Text_TyronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Cameron::
	trainerbattle_single TRAINER_PSYCHIC_CAMERON, SaffronCity_Gym_Text_CameronIntro, SaffronCity_Gym_Text_CameronDefeat
	msgbox SaffronCity_Gym_Text_CameronPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PSYCHIC_PRESTON, SaffronCity_Gym_Text_PrestonIntro, SaffronCity_Gym_Text_PrestonDefeat
	msgbox SaffronCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Amanda::
	trainerbattle_single TRAINER_CHANNELER_AMANDA, SaffronCity_Gym_Text_AmandaIntro, SaffronCity_Gym_Text_AmandaDefeat
	msgbox SaffronCity_Gym_Text_AmandaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Stacy::
	trainerbattle_single TRAINER_CHANNELER_STACY, SaffronCity_Gym_Text_StacyIntro, SaffronCity_Gym_Text_StacyDefeat
	msgbox SaffronCity_Gym_Text_StacyPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Tasha::
	trainerbattle_single TRAINER_CHANNELER_TASHA, SaffronCity_Gym_Text_TashaIntro, SaffronCity_Gym_Text_TashaDefeat
	msgbox SaffronCity_Gym_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SABRINA, SaffronCity_Gym_EventScript_GymGuyPostVictory
	msgbox SaffronCity_Gym_Text_GymGuyAdvice
	release
	end

SaffronCity_Gym_EventScript_GymGuyPostVictory::
	msgbox SaffronCity_Gym_Text_GymGuyPostVictory
	release
	end

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SaffronCity_Gym_Text_SabrinaIntro::
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}Eine Vision hat mir deine Ankunft\n"
	.string "vorausgesagt!\p"
	.string "Ich beherrsche die Psychokinese,\n"
	.string "seit ich ein Kind war.\p"
	.string "Zunächst habe ich gelernt, mit\n"
	.string "Psychokinese Löffel zu verbiegen.\p"
	.string "Ich verabscheue den Kampf!\n"
	.string "Aber wenn du es wünschst, beweise ich\l"
	.string "dir meine Kräfte!{PLAYER}?À$"
#else
	.string "I had a vision of your arrival.\p"
	.string "I have had psychic powers since\n"
	.string "I was a child.\p"
	.string "It started when a spoon I\n"
	.string "carelessly tossed, bent.\p"
	.string "I dislike battling, but if you wish,\n"
	.string "I will show you my powers!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

SaffronCity_Gym_Text_SabrinaDefeat::
#if GERMAN
	.string "Ich bin erschüttert!\n"
	.string "Aber verloren ist verloren.\p"
	.string "Ich muss gestehen, ich habe mich\n"
	.string "nicht allzu sehr angestrengt!\p"
	.string "Ich schenke dir den Sumpforden!$"
#else
	.string "This loss shocks me!\n"
	.string "But, a loss is a loss.\p"
	.string "I admit, I didn't work hard enough\n"
	.string "to win.\p"
	.string "Your victory has earned you the\n"
	.string "MARSHBADGE.$"
#endif

SaffronCity_Gym_Text_SabrinaPostBattle::
#if GERMAN
	.string "Theoretisch könnte jeder die\n"
	.string "Psychokinese erlernen.\p"
	.string "Viele wissen es nur nicht!$"
#else
	.string "Psychic power isn't something that\n"
	.string "only a few people have.\p"
	.string "Everyone has psychic power.\n"
	.string "People just don't realize it.$"
#endif

SaffronCity_Gym_Text_ExplainMarshBadgeTakeThis::
#if GERMAN
	.string "Nimm den Sumpforden als Zeichen\n"
	.string "deines Sieges.\p"
	.string "Achte darauf, dass du deine Pokémon\n"
	.string "jederzeit unter Kontrolle hast!\p"
	.string "Warte! Nimm noch diese TM von mir!$"
#else
	.string "Take the MARSHBADGE as proof of\n"
	.string "your victory.\p"
	.string "Just don't raise your POKéMON too\n"
	.string "much to avoid that problem.\p"
	.string "Wait, please take this TM with you.$"
#endif

SaffronCity_Gym_Text_ReceivedTM04FromSabrina::
#if GERMAN
	.string "{PLAYER} erhält TM04!$"
#else
	.string "{PLAYER} received TM04 from\n"
	.string "SABRINA.$"
#endif

SaffronCity_Gym_Text_ExplainTM04::
#if GERMAN
	.string "TM04 ist Gedankengut!\p"
	.string "Das Pokémon konzentriert sich, um\n"
	.string "sowohl den SP. ANG.\l"
	.string "als auch die SP. Ver. zu steigern.$"
#else
	.string "TM04 is CALM MIND.\p"
	.string "It makes the POKéMON concentrate\n"
	.string "to raise both SP. ATK and SP. DEF.$"
#endif

SaffronCity_Gym_Text_BagFullOfOtherItems::
#if GERMAN
	.string "Dein Rucksack ist zu voll!$"
#else
	.string "Your BAG is full of other items.$"
#endif

SaffronCity_Gym_Text_AmandaIntro::
#if GERMAN
	.string "Sabrina ist jünger als ich.\n"
	.string "Trotzdem habe ich Respekt vor ihr!$"
#else
	.string "SABRINA is far younger than I,\n"
	.string "but she has earned my respect.$"
#endif

SaffronCity_Gym_Text_AmandaDefeat::
#if GERMAN
	.string "Ich bin nicht gut genug!$"
#else
	.string "Not good enough!$"
#endif

SaffronCity_Gym_Text_AmandaPostBattle::
#if GERMAN
	.string "Sind zwei Gegner gleich stark, so wird\n"
	.string "der entschlossenere Kämpfer gewinnen!\p"
	.string "Wenn du Sabrina schlagen willst,\n"
	.string "konzentriere dich auf den Sieg!$"
#else
	.string "In a battle of equals, the one\n"
	.string "with the stronger will wins.\p"
	.string "If you wish to beat SABRINA, focus\n"
	.string "and will yourself to victory.$"
#endif

SaffronCity_Gym_Text_JohanIntro::
#if GERMAN
	.string "Machen dir unsere Psykräfte Angst?$"
#else
	.string "Does our unseen power scare you?$"
#endif

SaffronCity_Gym_Text_JohanDefeat::
#if GERMAN
	.string "Ich glaube es nicht:\n"
	.string "Ich hab verloren!$"
#else
	.string "I never foresaw this!$"
#endif

SaffronCity_Gym_Text_JohanPostBattle::
#if GERMAN
	.string "Psycho-Pokémon fürchten sich nur\n"
	.string "vor Käfern und Geistern!$"
#else
	.string "PSYCHIC POKéMON fear only ghosts\n"
	.string "and bugs!$"
#endif

SaffronCity_Gym_Text_StacyIntro::
#if GERMAN
	.string "Pokémon passen sich ihrem Trainer\n"
	.string "an.\p"
	.string "Deine Pokémon müssen demnach sehr\n"
	.string "zäh sein!$"
#else
	.string "POKéMON take on the appearance of\n"
	.string "their TRAINERS.\p"
	.string "Your POKéMON must be tough, then!$"
#endif

SaffronCity_Gym_Text_StacyDefeat::
#if GERMAN
	.string "Ich wusste es!$"
#else
	.string "I knew it!$"
#endif

SaffronCity_Gym_Text_StacyPostBattle::
#if GERMAN
	.string "Meine Pokémon müssen stärkere\n"
	.string "Attacken lernen!$"
#else
	.string "I have much to learn still…\p"
	.string "I must master PSYCHIC and teach it\n"
	.string "to my POKéMON…$"
#endif

SaffronCity_Gym_Text_TyronIntro::
#if GERMAN
	.string "Du weißt, dass man mit Stärke allein\n"
	.string "nicht weit kommt, oder?$"
#else
	.string "You understand, don't you?\p"
	.string "That power alone isn't enough to\n"
	.string "win in the world of POKéMON?$"
#endif

SaffronCity_Gym_Text_TyronDefeat::
#if GERMAN
	.string "Das ist unfassbar!$"
#else
	.string "I don't believe this!$"
#endif

SaffronCity_Gym_Text_TyronPostBattle::
#if GERMAN
	.string "Sabrina hat den Karate-meister in\n"
	.string "der Arena nebenan besiegt!$"
#else
	.string "SABRINA just wiped out the KARATE\n"
	.string "MASTER next door.$"
#endif

SaffronCity_Gym_Text_TashaIntro::
#if GERMAN
	.string "Du gegen mich!\n"
	.string "Unsere Pokémon sollen kämpfen!$"
#else
	.string "You and I, our POKéMON shall\n"
	.string "battle!$"
#endif

SaffronCity_Gym_Text_TashaDefeat::
#if GERMAN
	.string "Ich habe nun doch verloren!$"
#else
	.string "I lost after all!$"
#endif

SaffronCity_Gym_Text_TashaPostBattle::
#if GERMAN
	.string "Ich ahnte, dass es passieren\n"
	.string "würde!$"
#else
	.string "I knew that this was going to take\n"
	.string "place.$"
#endif

SaffronCity_Gym_Text_CameronIntro::
#if GERMAN
	.string "Obwohl Sabrina noch jung ist, ist\n"
	.string "sie unsere Arenaleiterin!\p"
	.string "Wir lassen dich nicht einfach so zu\n"
	.string "ihr gehen!$"
#else
	.string "SABRINA is young, but she's also\n"
	.string "our highly skilled LEADER.\p"
	.string "You won't reach her easily!$"
#endif

SaffronCity_Gym_Text_CameronDefeat::
#if GERMAN
	.string "Ich habe die Konzentration verloren!$"
#else
	.string "Ow!\n"
	.string "Down and out!$"
#endif

SaffronCity_Gym_Text_CameronPostBattle::
#if GERMAN
	.string "In Saffronia City gab es zwei\n"
	.string "Pokémon-Arenen.\p"
	.string "Allerdings hat das Kampf-dojo den\n"
	.string "Status als Pokémon-Arena verloren, weil\l"
	.string "wir die Trainer besiegten!$"
#else
	.string "There used to be two POKéMON GYMS\n"
	.string "in SAFFRON.\p"
	.string "The FIGHTING DOJO next door lost\n"
	.string "its GYM status, though.\p"
	.string "We simply creamed them when we\n"
	.string "decided to have just one GYM.$"
#endif

SaffronCity_Gym_Text_PrestonIntro::
#if GERMAN
	.string "Die Pokémon in der Arena von Saffronia\n"
	.string "City sind für ihre übernatürlichen\l"
	.string "Kräfte bekannt!\p"
	.string "Ich weiß, dass du Sabrina herausfordern\n"
	.string "möchtest!$"
#else
	.string "SAFFRON POKéMON GYM is famous for\n"
	.string "training psychics.\p"
	.string "You want to see SABRINA, don't\n"
	.string "you? I can tell!$"
#endif

SaffronCity_Gym_Text_PrestonDefeat::
	.string "Arrrgh!$"

SaffronCity_Gym_Text_PrestonPostBattle::
#if GERMAN
	.string "Ich habe deine Gedanken gelesen!$"
#else
	.string "That's right! I used telepathy to\n"
	.string "read your mind!$"
#endif

SaffronCity_Gym_Text_GymGuyAdvice::
#if GERMAN
	.string "Heh!\n"
	.string "Warte, du Champion in spe!\p"
	.string "Die Pokémon von Sabrina benutzen\n"
	.string "Psychokinese anstelle von physischen\l"
	.string "Kräften!\p"
	.string "Kampf-Pokémon sind Psychokinese\n"
	.string "nicht gewachsen!\p"
	.string "Sie haben nicht einmal den Hauch\n"
	.string "einer Chance!$"
#else
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "SABRINA's POKéMON use psychic\n"
	.string "power instead of force.\p"
	.string "FIGHTING POKéMON are especially\n"
	.string "weak against PSYCHIC POKéMON.\p"
	.string "They'll get destroyed before they\n"
	.string "can even aim a punch!$"
#endif

SaffronCity_Gym_Text_GymGuyPostVictory::
#if GERMAN
	.string "Psychokinese?\p"
	.string "Wenn ich sie hätte, würde ich in\n"
	.string "der Spielhalle reich werden!$"
#else
	.string "Psychic power, huh?\p"
	.string "If I had that, I'd make a bundle\n"
	.string "at the slots!$"
#endif

SaffronCity_Gym_Text_GymStatue::
#if GERMAN
	.string "Saffronia Pokémon-Arena\n"
	.string "Leitung: Sabrina\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}$"
#else
	.string "SAFFRON POKéMON GYM\n"
	.string "LEADER: SABRINA\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
#endif

SaffronCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
	.string "Saffronia Pokémon-Arena\n"
	.string "Leitung: Sabrina\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "SAFFRON POKéMON GYM\n"
	.string "LEADER: SABRINA\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif

