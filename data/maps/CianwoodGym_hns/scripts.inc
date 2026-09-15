CianwoodGym_hns_MapScripts::
	.byte 0


CianwoodGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Statue2
	msgbox CianwoodGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_EventScript_Statue2::
	msgbox CianwoodGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_GymStatue:
#if GERMAN
	.string "Pokémon-Arena von Anemonia City$"
#else
	.string "CIANWOOD CITY POKéMON GYM$"
#endif

CianwoodGym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon-Arena von Anemonia City\p"
	.string "Leiter: Hartwig\n"
	.string "Anerkannte Trainer:\p"
	.string "{PLAYER}$"
#else
	.string "CIANWOOD CITY POKéMON GYM\p"
	.string "CHUCK'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

CianwoodGym_EventScript_Chuck::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_CHUCK, CianwoodGym_EventScript_ChuckAtDojo
	goto_if_set FLAG_VISITED_VERMILION_CITY, CianwoodGym_EventScript_ChuckGotoDojo
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, CianwoodGym_EventScript_Chuck_Defeated
	msgbox CianwoodGym_Text_ChuckIntro1, MSGBOX_DEFAULT
	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckLeft
	waitmovement 0
	message CianwoodGym_Text_ChuckIntro2
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_LEFT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0

	delay 20

	applymovement LOCALID_CIANWOOD_CHUCK, CianwoodGym_Movement_ChuckRight
	waitmovement 0
	applymovement LOCALID_CIANWOOD_CHUCK_ROCK_RIGHT, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	waitmessage
	turnobject LOCALID_CIANWOOD_CHUCK, DIR_SOUTH
	msgbox CianwoodGym_Text_ChuckIntro3, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_OlivineCheckMahog
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_MahogCheckOlivine
	goto CianwoodGym_EventScript_Chuck_Battle1

CianwoodGym_EventScript_ChuckVictory::
	message CianwoodGym_Text_GetStormBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CianwoodGym_Text_ChuckBadgeSpeech, MSGBOX_DEFAULT
	setvar VAR_0x8004, 4
	special SetJohtoBadge
	setflag FLAG_BADGE05_GET
	@ Chuck: Johto-Orden 5. Die Flag oben teilt sich Johto mit Kanto und
	@ ist nach der Kanto-Liga laengst gesetzt - gezaehlt wird in VAR_JOHTO_BADGES.
	setvar VAR_0x8004, 4
	special SetJohtoBadge
	setflag FLAG_DEFEATED_CIANWOOD_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers_hns
	giveitem ITEM_TM_FOCUS_PUNCH
	msgbox CianwoodGym_Text_ChuckTMSpeech, MSGBOX_DEFAULT
	setvar VAR_GETFLY, 1
	setrespawn HEAL_LOCATION_CIANWOOD_CITY_HNS
    call_if_eq VAR_NUM_BADGES, 7, MahoganyTown_Gym_EventScript_SetupElmRocketCall
	closemessage
	release
	end

CianwoodGym_EventScript_ChuckGotoDojo::
	msgbox CianwoodGym_Text_ChuckGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_CHUCK
	release
	end

CianwoodGym_Text_ChuckGotoDojo:
#if GERMAN
	.string "Wahahaha {PLAYER}!\n"
	.string "Ich bin mitten im Training!\p"
	.string "Wenn du erneut kämpfen willst,\n"
	.string "komm zum Kampf-Dojo in Saffronia City!$"
#else
	.string "WAHAHAHA {PLAYER}!\n"
	.string "I'm in the middle of my training!\p"
	.string "If you want another match, come to\n"
#endif

CianwoodGym_EventScript_ChuckAtDojo::
	msgbox CianwoodGym_Text_ChuckAtDojo, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Text_ChuckAtDojo:
#if GERMAN
	.string "Wir sehen uns im Dojo!\n"
	.string "Wahahahahaha$"
#else
	.string "I will see you at the DOJO!\n"
	.string "WAHAHAHAHAHA$"
#endif

CianwoodGym_EventScript_OlivineCheckMahog::
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_MahogCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, CianwoodGym_EventScript_Chuck_Battle3
	goto CianwoodGym_EventScript_Chuck_Battle2

CianwoodGym_EventScript_Chuck_Battle1::
	trainerbattle_no_intro TRAINER_CHUCK_1_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle2::
	trainerbattle_no_intro TRAINER_CHUCK_1_2_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Battle3::
	trainerbattle_no_intro TRAINER_CHUCK_1_3_HNS, CianwoodGym_Text_ChuckIntro2
	goto CianwoodGym_EventScript_ChuckVictory

CianwoodGym_EventScript_Chuck_Defeated::
	msgbox CianwoodGym_Text_ChuckAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodGym_Movement_ChuckLeft:
	jump_in_place_left
	step_end

CianwoodGym_Movement_ChuckRight:
	jump_in_place_right
	step_end

CianwoodGym_Text_ChuckIntro1:
#if GERMAN
	.string "Wahahah!\p"
	.string "Du bist also bis hierher gekommen!\p"
	.string "Ich sag’s dir: Ich bin hart!\p"
	.string "Meine Pokémon zerquetschen Felsen\n"
	.string "und zerschmettern Knochen!\p"
	.string "Pass auf!$"
#else
	.string "WAHAHAH!\p"
	.string "So you've come this far!\p"
	.string "Let me tell you, I'm tough!\p"
	.string "My POKéMON will crush stones and\n"
	.string "shatter bones!\p"
	.string "Watch this!$"
#endif

CianwoodGym_Text_ChuckIntro2:
#if GERMAN
	.string "Urrrgh!\n"
	.string "… … …\p"
	.string "Huaaargh!$"
#else
	.string "CHUCK: Urggh!\n"
	.string "…\p"
	.string "Oooarrgh!$"
#endif

CianwoodGym_Text_ChuckIntro3:
#if GERMAN
	.string "Na, da staunst du, was?\p"
	.string "Was sagst du da? Mit Pokémon hat das\n"
	.string "herzlich wenig zu tun?\l"
	.string "Klar, da hast du natürlich recht!\l"
	.string "Komm schon, lass uns kämpfen!$"
#else
	.string "There! Scared now, are you?\p"
	.string "What? It has nothing to do with\n"
	.string "POKéMON?\p"
	.string "That's true!\p"
	.string "Come on. We shall do battle!$"
#endif

CianwoodGym_Text_ChuckLoss:
#if GERMAN
	.string "Was? Hä? Ich hab verloren?\p"
	.string "Wie wär’s damit!\n"
	.string "Du bist würdig für den Faustorden!$"
#else
	.string "Wha? Huh? I lost?\p"
	.string "How about that!\n"
	.string "You're worthy of STORMBADGE!$"
#endif

CianwoodGym_Text_GetStormBadge:
#if GERMAN
	.string "{PLAYER} erhält den Faustorden!$"
#else
	.string "{PLAYER} received STORMBADGE.$"
#endif

CianwoodGym_Text_ChuckBadgeSpeech:
#if GERMAN
	.string "Der Faustorden sorgt dafür, dass dir\n"
	.string "alle Pokémon bis L70 gehorchen, auch\l"
	.string "getauschte.\p"
	.string "Außerdem können deine Pokémon Fliegen\n"
	.string "auch außerhalb von Kämpfen einsetzen.\p"
	.string "Hier, nimm das auch noch!$"
#else
	.string "STORMBADGE makes all POKéMON up to\n"
	.string "L70 obey, even traded ones.\p"
	.string "It also lets your POKéMON use FLY\n"
	.string "when you're not in a battle.\p"
	.string "Here, take this too!$"
#endif

CianwoodGym_Text_ChuckTMSpeech:
#if GERMAN
	.string "Das ist Power-Punch.\p"
	.string "Er ist langsam, verursacht aber\n"
	.string "riesigen Schaden. Lass dich nur nicht\l"
	.string "zuerst treffen!$"
#else
	.string "That is FOCUS PUNCH.\p"
	.string "It moves slow but deals huge\n"
	.string "damage. Just don't get hit first!$"
#endif

CianwoodGym_Text_ChuckAfter:
#if GERMAN
	.string "Hartwig: Hahaha! Es war mir ein großes\n"
	.string "Vergnügen, gegen dich zu kämpfen!\p"
	.string "Aber das ändert nichts daran, dass ich\n"
	.string "verloren habe. Von nun an werde ich 24\l"
	.string "Stunden am Tag trainieren!$"
#else
	.string "WAHAHAH! I enjoyed battling you!\p"
	.string "But a loss is a loss!\p"
	.string "From now on, I'm going to train\n"
	.string "24 hours a day!$"
#endif

CianwoodGym_Text_ChuckRematch:
#if GERMAN
	.string "Wahahah! Johto-Champion!\p"
	.string "Du willst noch eine Runde!\p"
	.string "Ich sehe, deine Fähigkeiten sind\n"
	.string "besser geworden!\p"
	.string "Bereit für ein Kräftemessen?$"
#else
	.string "WAHAHAH! JOHTO CHAMPION!\p"
	.string "You've come back for more!\p"
	.string "I see your skills have improved!\p"
	.string "Ready to see who's stronger?$"
#endif

CianwoodGym_Text_ChuckRematchDefeat:
#if GERMAN
	.string "Was? Hä? Ich habe verloren?\n"
	.string "Schon wieder?$"
#else
	.string "Wha? Huh? I lost?\n"
	.string "Again?$"
#endif

CianwoodGym_EventScript_Yoshi::
	trainerbattle_single TRAINER_YOSHI_HNS, CianwoodGym_Text_BlackbeltYoshiSeen, CianwoodGym_Text_BlackbeltYoshiBeaten
	msgbox CianwoodGym_Text_BlackbeltYoshiAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltYoshiSeen:
#if GERMAN
	.string "Meine Pokémon und mich verbindet eine\n"
	.string "tiefe Freundschaft.\l"
	.string "Dieses Band wird nie jemand zerreißen!$"
#else
	.string "My POKéMON and I are bound togeth-\n"
	.string "er by friendship.\p"
	.string "Our bond will never be broken!$"
#endif

CianwoodGym_Text_BlackbeltYoshiBeaten:
#if GERMAN
	.string "Das ist unmöglich!$"
#else
	.string "This isn't real!$"
#endif

CianwoodGym_Text_BlackbeltYoshiAfter:
#if GERMAN
	.string "Es scheint, als stündest auch du\n"
	.string "deinen Pokémon sehr nahe!$"
#else
	.string "You seem to have a strong bond\n"
	.string "with your POKéMON too!$"
#endif

CianwoodGym_EventScript_Lao::
	trainerbattle_single TRAINER_LAO_HNS, CianwoodGym_Text_BlackbeltLaoSeen, CianwoodGym_Text_BlackbeltLaoBeaten
	msgbox CianwoodGym_Text_BlackbeltLaoAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLaoSeen:
#if GERMAN
	.string "Wir Meister der Kampfkunst kennen\n"
	.string "keine Angst!$"
#else
	.string "We martial artists fear nothing!$"
#endif

CianwoodGym_Text_BlackbeltLaoBeaten:
#if GERMAN
	.string "Schockierend!$"
#else
	.string "That's shocking!$"
#endif

CianwoodGym_Text_BlackbeltLaoAfter:
#if GERMAN
	.string "Kampf-Pokémon haben Angst vor\n"
	.string "Psycho…$"
#else
	.string "Fighting POKéMON are afraid of\n"
	.string "psychics…$"
#endif


CianwoodGym_EventScript_Nob::
	trainerbattle_single TRAINER_NOB_HNS, CianwoodGym_Text_BlackbeltNobSeen, CianwoodGym_Text_BlackbeltNobBeaten
	msgbox CianwoodGym_Text_BlackbeltNobAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltNobSeen:
#if GERMAN
	.string "Weltlicher Besitz ist sinnlos.\n"
	.string "Worte sind nutzlos.\l"
	.string "Lass deine Fäuste sprechen!$"
#else
	.string "Words are useless.\n"
	.string "Let your fists do the talking!$"
#endif

CianwoodGym_Text_BlackbeltNobBeaten:
	.string "…$"

CianwoodGym_Text_BlackbeltNobAfter:
#if GERMAN
	.string "Ich habe verloren!\n"
	.string "Ich bin sprachlos!$"
#else
	.string "I lost! I'm speechless!$"
#endif

CianwoodGym_EventScript_Lung::
	trainerbattle_single TRAINER_LUNG_HNS, CianwoodGym_Text_BlackbeltLungSeen, CianwoodGym_Text_BlackbeltLungBeaten
	msgbox CianwoodGym_Text_BlackbeltLungAfter, MSGBOX_AUTOCLOSE
	end

CianwoodGym_Text_BlackbeltLungSeen:
#if GERMAN
	.string "Die Wut meiner Fäuste wird deine\n"
	.string "Pokémon das Fürchten lehren!$"
#else
	.string "My raging fists will shatter your\n"
	.string "POKéMON!$"
#endif

CianwoodGym_Text_BlackbeltLungBeaten:
#if GERMAN
	.string "Ich wurde zerschmettert!$"
#else
	.string "I got shattered!$"
#endif

CianwoodGym_Text_BlackbeltLungAfter:
#if GERMAN
	.string "Meine Pokémon haben verloren…\n"
	.string "Mein Stolz ist nur noch Staub…$"
#else
	.string "My POKéMON lost…\n"
	.string "My… my pride is shattered…$"
#endif

