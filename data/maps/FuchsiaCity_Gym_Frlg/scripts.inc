FuchsiaCity_Gym_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_Gym_OnTransition
	.byte 0

@ After the league change (D-010) Koga is in the Johto Elite Four and Janina
@ leads this gym. FLAG_TEMP_1 hides Koga, FLAG_TEMP_2 hides Janina.
@ See docs/origin_jade/DECISIONS.md, D-032.
FuchsiaCity_Gym_OnTransition::
	call PokemonLeague_EventScript_CheckLeagueChanged
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_Gym_EventScript_SetJanineLeader
	setflag FLAG_TEMP_2
	end

FuchsiaCity_Gym_EventScript_SetJanineLeader::
	setflag FLAG_TEMP_1
	end

@ Janina: battle as often as the player likes, TM Poison Jab once, no badge (D-007).
FuchsiaCity_Gym_EventScript_JanineLeader::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_POISON_JAB_FROM_JANINE, FuchsiaCity_Gym_EventScript_JanineRematch
	goto_if_defeated TRAINER_JANINE_HNS, FuchsiaCity_Gym_EventScript_JanineGiveTM
	msgbox FuchsiaCity_Gym_Text_JanineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JANINE_HNS, FuchsiaCity_Gym_Text_JanineDefeat
FuchsiaCity_Gym_EventScript_JanineGiveTM::
	msgbox FuchsiaCity_Gym_Text_JanineGiveTM, MSGBOX_DEFAULT
	checkitemspace ITEM_TM_POISON_JAB
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_JanineNoRoomForTM
	giveitem ITEM_TM_POISON_JAB
	setflag FLAG_GOT_TM_POISON_JAB_FROM_JANINE
	msgbox FuchsiaCity_Gym_Text_JanineExplainTM, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_EventScript_JanineNoRoomForTM::
	msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis, MSGBOX_DEFAULT
	release
	end

FuchsiaCity_Gym_EventScript_JanineRematch::
	msgbox FuchsiaCity_Gym_Text_JanineRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JohtoGym_EventScript_RematchDeclined
	closemessage
	trainerbattle_no_intro TRAINER_JANINE_HNS, FuchsiaCity_Gym_Text_JanineRematchDefeat
	release
	end

FuchsiaCity_Gym_EventScript_Koga::
	famechecker FAMECHECKER_KOGA, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_KOGA, FuchsiaCity_Gym_Text_KogaIntro, FuchsiaCity_Gym_Text_KogaDefeat, FuchsiaCity_Gym_EventScript_DefeatedKoga, NO_MUSIC
	goto_if_unset FLAG_GOT_TM06_FROM_KOGA, FuchsiaCity_Gym_EventScript_GiveTM06
	msgbox FuchsiaCity_Gym_Text_KogaPostBattle
	release
	end

FuchsiaCity_Gym_EventScript_DefeatedKoga::
	famechecker FAMECHECKER_KOGA, 1
	clearflag FLAG_HIDE_FAME_CHECKER_KOGA_JOURNAL
	setflag FLAG_DEFEATED_KOGA
	setflag FLAG_BADGE05_GET
	set_gym_trainers_frlg 5
	call Common_EventScript_ObedienceLevel40IfSixthBadge
	goto FuchsiaCity_Gym_EventScript_GiveTM06
	end

FuchsiaCity_Gym_EventScript_GiveTM06::
	msgbox FuchsiaCity_Gym_Text_KogaExplainSoulBadge
	checkitemspace ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_Gym_EventScript_NoRoomForTM06
	giveitem_msg FuchsiaCity_Gym_Text_ReceivedTM06FromKoga, ITEM_TM06
	setflag FLAG_GOT_TM06_FROM_KOGA
	msgbox FuchsiaCity_Gym_Text_KogaExplainTM06
	release
	end

FuchsiaCity_Gym_EventScript_NoRoomForTM06::
	msgbox FuchsiaCity_Gym_Text_MakeSpaceForThis
	release
	end

FuchsiaCity_Gym_EventScript_Phil::
	trainerbattle_single TRAINER_TAMER_PHIL, FuchsiaCity_Gym_Text_PhilIntro, FuchsiaCity_Gym_Text_PhilDefeat
	msgbox FuchsiaCity_Gym_Text_PhilPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Edgar::
	trainerbattle_single TRAINER_TAMER_EDGAR, FuchsiaCity_Gym_Text_EdgarIntro, FuchsiaCity_Gym_Text_EdgarDefeat
	msgbox FuchsiaCity_Gym_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_JUGGLER_KIRK, FuchsiaCity_Gym_Text_KirkIntro, FuchsiaCity_Gym_Text_KirkDefeat
	famechecker FAMECHECKER_KOGA, 2
	msgbox FuchsiaCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_JUGGLER_SHAWN, FuchsiaCity_Gym_Text_ShawnIntro, FuchsiaCity_Gym_Text_ShawnDefeat
	msgbox FuchsiaCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Kayden::
	trainerbattle_single TRAINER_JUGGLER_KAYDEN, FuchsiaCity_Gym_Text_KaydenIntro, FuchsiaCity_Gym_Text_KaydenDefeat
	msgbox FuchsiaCity_Gym_Text_KaydenPostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_JUGGLER_NATE, FuchsiaCity_Gym_Text_NateIntro, FuchsiaCity_Gym_Text_NateDefeat
	msgbox FuchsiaCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

FuchsiaCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KOGA, FuchsiaCity_Gym_EventScript_GymGuyPostVictory
	msgbox FuchsiaCity_Gym_Text_GymGuyAdvice
	release
	end

FuchsiaCity_Gym_EventScript_GymGuyPostVictory::
	msgbox FuchsiaCity_Gym_Text_GymGuyPostVictory
	release
	end

FuchsiaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_TEMP_1, FuchsiaCity_Gym_EventScript_GymStatueJanine
	goto_if_set FLAG_BADGE05_GET, FuchsiaCity_Gym_EventScript_GymStatuePostVictory
	msgbox FuchsiaCity_Gym_Text_GymStatue
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatuePostVictory::
	msgbox FuchsiaCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

FuchsiaCity_Gym_EventScript_GymStatueJanine::
	msgbox FuchsiaCity_Gym_Text_GymStatueJanine
	releaseall
	end

FuchsiaCity_Gym_Text_KogaIntro::
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}Koga: Hahaha!\p"
	.string "Ein Kind fordert einen Ninja-\n"
	.string "meister zum Kampf heraus?\p"
	.string "Wie du willst! Erlebe eine Welt des\n"
	.string "Schreckens, bevor ich dich besiege!\p"
	.string "An meinen Schlaf- und Gift-\n"
	.string "Attacken sollst du verzweifeln!$"
#else
	.string "KOGA: Fwahahaha!\p"
	.string "A mere child like you dares to\n"
	.string "challenge me?\p"
	.string "The very idea makes me shiver\n"
	.string "with mirth!\p"
	.string "Very well, I shall show you true\n"
	.string "terror as a ninja master.\p"
	.string "Poison brings steady doom.\n"
	.string "Sleep renders foes helpless.\p"
	.string "Despair to the creeping horror of\n"
	.string "POISON-type POKéMON!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

FuchsiaCity_Gym_Text_KogaDefeat::
#if GERMAN
	.string "Na so was!\n"
	.string "Du bist ein würdiger Kämpfer!\p"
	.string "Ich reiche dir den Seelenorden!$"
#else
	.string "Humph!\n"
	.string "You have proven your worth!\p"
	.string "Here!\n"
	.string "Take the SOULBADGE!$"
#endif

FuchsiaCity_Gym_Text_KogaPostBattle::
#if GERMAN
	.string "Wirkt das Toxin erst einmal, leiden\n"
	.string "Pokémon umso mehr, je länger der Kampf\l"
	.string "dauert!\p"
	.string "Ein wahrer Alptraum für den Gegner!$"
#else
	.string "When afflicted by TOXIC, a POKéMON\n"
	.string "suffers more and more.\p"
	.string "It suffers worsening damage as the\n"
	.string "battle wears on!\p"
	.string "It will surely terrorize foes!$"
#endif

FuchsiaCity_Gym_Text_KogaExplainSoulBadge::
#if GERMAN
	.string "Nun, da du Träger des Seelenordens\n"
	.string "bist, wird die Abwehr deiner Pokémon\l"
	.string "steigen!\p"
	.string "Ferner kannst du Surfer nun auch\n"
	.string "außerhalb von Kämpfen nutzen!\p"
	.string "Bitte nimm auch dieses Geschenk!$"
#else
	.string "Now that you have the SOULBADGE,\n"
	.string "the DEFENSE of your POKéMON rises.\p"
	.string "It also lets you SURF outside of\n"
	.string "battle.\p"
	.string "Ah!\n"
	.string "Take this, too!$"
#endif

FuchsiaCity_Gym_Text_ReceivedTM06FromKoga::
#if GERMAN
	.string "{PLAYER} erhält TM06!$"
#else
	.string "{PLAYER} received TM06\n"
	.string "from KOGA.$"
#endif

FuchsiaCity_Gym_Text_KogaExplainTM06::
#if GERMAN
	.string "TM06 ist Toxin!\p"
	.string "Es ist eine mehr als 400 Jahre alte\n"
	.string "Technik!$"
#else
	.string "Sealed within that TM06 lies\n"
	.string "TOXIC!\p"
	.string "It is a secret technique dating\n"
	.string "back some four hundred years.$"
#endif

FuchsiaCity_Gym_Text_MakeSpaceForThis::
#if GERMAN
	.string "Schaffe Platz für mein Geschenk!$"
#else
	.string "Make space for this, child!$"
#endif

FuchsiaCity_Gym_Text_KaydenIntro::
#if GERMAN
	.string "Der Erfolg hängt nicht von der\n"
	.string "Stärke deiner Pokémon ab!\p"
	.string "Es kommt auf die Strategie an!\p"
	.string "Intelligenz obsiegt über rohe\n"
	.string "Kraft!$"
#else
	.string "Strength isn't the key for POKéMON.\n"
	.string "Do you understand this?\p"
	.string "POKéMON is about strategy!\p"
	.string "I'll show you how strategy can\n"
	.string "beat brute strength.$"
#endif

FuchsiaCity_Gym_Text_KaydenDefeat::
#if GERMAN
	.string "Was?\n"
	.string "Außerordentlich!$"
#else
	.string "What?\n"
	.string "Extraordinary!$"
#endif

FuchsiaCity_Gym_Text_KaydenPostBattle::
#if GERMAN
	.string "Du setzt deine Muskeln mit Köpfchen\n"
	.string "ein! Gute Strategie!$"
#else
	.string "So, you mix brawn with brains?\n"
	.string "Good strategy!\p"
	.string "That's remarkable for a child\n"
	.string "TRAINER.$"
#endif

FuchsiaCity_Gym_Text_KirkIntro::
#if GERMAN
	.string "Ich möchte später einmal ein Ninja\n"
	.string "werden!$"
#else
	.string "I was a magician once upon a time.\p"
	.string "But I dreamt of becoming a ninja,\n"
	.string "so I joined this GYM.$"
#endif

FuchsiaCity_Gym_Text_KirkDefeat::
#if GERMAN
	.string "Ich habe verloren!$"
#else
	.string "I'm done for!$"
#endif

FuchsiaCity_Gym_Text_KirkPostBattle::
#if GERMAN
	.string "Ich muss noch eine Menge von Koga,\n"
	.string "meinem Ninja-Meister, lernen!$"
#else
	.string "Even though I've lost, I will keep\n"
	.string "training according to the teachings\l"
	.string "of KOGA, my ninja master.$"
#endif

FuchsiaCity_Gym_Text_NateIntro::
#if GERMAN
	.string "Kannst du gegen meine Spezial-\n"
	.string "Techniken bestehen?$"
#else
	.string "Let's see you beat my special\n"
	.string "techniques!$"
#endif

FuchsiaCity_Gym_Text_NateDefeat::
#if GERMAN
	.string "Du hast mich hereingelegt!$"
#else
	.string "You had me fooled!$"
#endif

FuchsiaCity_Gym_Text_NatePostBattle::
#if GERMAN
	.string "Ich bevorzuge Schlaf- und\n"
	.string "Gift-Attacken. Ihre Wirkung dauert\l"
	.string "auch nach dem Kampf an!$"
#else
	.string "I like poison and sleep techniques,\n"
	.string "as they linger after battle!$"
#endif

FuchsiaCity_Gym_Text_PhilIntro::
#if GERMAN
	.string "Bleib stehen!\p"
	.string "Frustrieren dich die unsichtbaren\n"
	.string "Mauern?$"
#else
	.string "Stop right there!\p"
	.string "The famed invisible walls of\n"
	.string "FUCHSIA GYM have you frustrated?$"
#endif

FuchsiaCity_Gym_Text_PhilDefeat::
#if GERMAN
	.string "Oh!\n"
	.string "Er hat mich besiegt!$"
#else
	.string "Whoa!\n"
	.string "You've got it!$"
#endif

FuchsiaCity_Gym_Text_PhilPostBattle::
#if GERMAN
	.string "Ich bin schwer beeindruckt!\p"
	.string "Ein Tipp: Taste die unsichtbaren\n"
	.string "Mauern nach Durchgängen ab!$"
#else
	.string "You impressed me!\n"
	.string "Here's a hint!\p"
	.string "Look very closely for gaps in the\n"
	.string "invisible walls!$"
#endif

FuchsiaCity_Gym_Text_EdgarIntro::
#if GERMAN
	.string "Meister Koga unterweist mich in der\n"
	.string "Kunst des Ninja-Kampfes!\p"
	.string "Der Einsatz von Pokémon ist eine\n"
	.string "sehr alte Ninja-Tradition!$"
#else
	.string "I also study the way of the ninja\n"
	.string "with Master KOGA!\p"
	.string "Ninja have a long history of using\n"
	.string "animals!$"
#endif

FuchsiaCity_Gym_Text_EdgarDefeat::
#if GERMAN
	.string "Autsch!$"
#else
	.string "Awoo!$"
#endif

FuchsiaCity_Gym_Text_EdgarPostBattle::
#if GERMAN
	.string "Ich muss noch viel lernen!$"
#else
	.string "I still have much to learn.$"
#endif

FuchsiaCity_Gym_Text_ShawnIntro::
#if GERMAN
	.string "Koga ist der Nachfahre einer Reihe\n"
	.string "legendärer Ninja-Kämpfer!\p"
	.string "Wer sind deine Vorfahren?$"
#else
	.string "Master KOGA comes from a long line\n"
	.string "of ninjas.\p"
	.string "What did you descend from?$"
#endif

FuchsiaCity_Gym_Text_ShawnDefeat::
#if GERMAN
	.string "Ich habe es vermasselt!$"
#else
	.string "You're more skilled than I'd\n"
	.string "thought!$"
#endif

FuchsiaCity_Gym_Text_ShawnPostBattle::
#if GERMAN
	.string "Wo Licht ist, ist auch Schatten!\p"
	.string "Licht oder Schatten!\n"
	.string "Wähle einen Weg!$"
#else
	.string "Where there is light, there is\n"
	.string "shadow!\p"
	.string "Light and shadow!\n"
	.string "Which do you choose?$"
#endif

FuchsiaCity_Gym_Text_GymGuyAdvice::
#if GERMAN
	.string "Heh!\n"
	.string "Warte, du Champion in spe!\p"
	.string "Die Arena von Fuchsania City ist\n"
	.string "voller unsichtbarer Mauern!\p"
	.string "Du kannst Koga sehen, ihn aber\n"
	.string "nicht erreichen!\p"
	.string "Du musst nach Lücken in den\n"
	.string "unsichtbaren Mauern suchen!$"
#else
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "FUCHSIA GYM is a tricked-up place.\n"
	.string "It's riddled with invisible walls!\p"
	.string "KOGA might appear close, but he's\n"
	.string "blocked off.\p"
	.string "You have to find gaps in the walls\n"
	.string "to reach him.$"
#endif

FuchsiaCity_Gym_Text_GymGuyPostVictory::
#if GERMAN
	.string "Selbst wenn man sie besiegt hat,\n"
	.string "wirken die Ninjas noch bedrohlich!$"
#else
	.string "It's amazing how ninja can terrify,\n"
	.string "even now!$"
#endif

FuchsiaCity_Gym_Text_GymStatue::
#if GERMAN
	.string "Fuchsania Pokémon-Arena\n"
	.string "Leitung: Koga\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}$"
#else
	.string "FUCHSIA POKéMON GYM\n"
	.string "LEADER: KOGA\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
#endif

FuchsiaCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
	.string "Fuchsania Pokémon-Arena\n"
	.string "Leitung: Koga\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "FUCHSIA POKéMON GYM\n"
	.string "LEADER: KOGA\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif

FuchsiaCity_Gym_Text_JanineIntro:
#if GERMAN
	.string "Janina: Ich bin Janina, die neue\n"
	.string "Arenaleiterin von Fuchsania City!\p"
	.string "Mein Vater Koga gehört jetzt zu\n"
	.string "den Top Vier der Pokémon-Liga.\p"
	.string "Seine Arena führe ich weiter!\n"
	.string "Zeig mir, was du draufhast!$"
#else
	.string "JANINE: I'm JANINE, the new LEADER\n"
	.string "of FUCHSIA GYM!\p"
	.string "My father KOGA has joined the\n"
	.string "POKéMON LEAGUE's ELITE FOUR.\p"
	.string "Now I run his GYM!\n"
	.string "Show me what you've got!$"
#endif

FuchsiaCity_Gym_Text_JanineDefeat:
#if GERMAN
	.string "Janina: Du bist hartnäckig.\n"
	.string "Du hast eindeutig gewonnen…$"
#else
	.string "JANINE: You're a tough one.\n"
	.string "You definitely won…$"
#endif

FuchsiaCity_Gym_Text_JanineGiveTM:
#if GERMAN
	.string "Janina: Du bist stark!\n"
	.string "Ich habe ein Geschenk für dich!$"
#else
	.string "JANINE: You're so tough! I have a\n"
	.string "special gift!$"
#endif

FuchsiaCity_Gym_Text_JanineExplainTM:
#if GERMAN
	.string "Diese Attacke heißt Gifthieb.\n"
	.string "Sie kann deine Gegner vergiften!$"
#else
	.string "It's POISON JAB, a POISON-type move\n"
	.string "that may poison the target.$"
#endif

FuchsiaCity_Gym_Text_JanineRematch:
#if GERMAN
	.string "Janina: Ich trainiere jeden Tag, um\n"
	.string "stärker zu werden als mein Vater!\p"
	.string "Möchtest du einen Rückkampf?$"
#else
	.string "JANINE: I train every day to\n"
	.string "become stronger than Father!\p"
	.string "Want to have a rematch?$"
#endif

FuchsiaCity_Gym_Text_JanineRematchDefeat:
#if GERMAN
	.string "Janina: Ich werde noch viel mehr\n"
	.string "trainieren und stärker werden!$"
#else
	.string "JANINE: I'm going to really apply\n"
	.string "myself and improve my skills.$"
#endif

FuchsiaCity_Gym_Text_GymStatueJanine:
#if GERMAN
	.string "Fuchsania Pokémon-Arena\n"
	.string "Leitung: Janina\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "FUCHSIA POKéMON GYM\n"
	.string "LEADER: JANINE\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif
