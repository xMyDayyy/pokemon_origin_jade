GoldenrodCity_RadioTower_2F_hns_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5_HNS, GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26_HNS, GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket
	goto_if_set FLAG_DAILY_BUENAS_PASSWORD_GUESSED, GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed
	goto_if_unset FLAG_DAILY_BUENAS_PASSWORD, GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword, MSGBOX_DEFAULT
	special Special_BuenaPasswordShowMultichoice
	waitstate
	compare VAR_RESULT, 127
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled
	special Special_BuenaCheckAnswer
	compare VAR_RESULT, TRUE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaWrong, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCorrect::
	special Special_BuenaRollReward
	copyvar VAR_0x8004, VAR_RESULT
	checkitemspace VAR_0x8004, 1
	compare VAR_RESULT, FALSE
	goto_if_eq GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull
	giveitem VAR_0x8004, 1
	setflag FLAG_DAILY_BUENAS_PASSWORD_GUESSED
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaCorrect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaBagFull::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaBagFull, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaCancelled::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaComeBack, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaAlreadyPlayed::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaNoShow::
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_BuenaRocket::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
#if GERMAN
	.string "Buena: Was fragst du da?\n"
	.string "Wie das heutige Passwort lautet?\p"
	.string "Zu Hilfe natürlich!$"
#else
	.string "BUENA: Huh? Today's password?\n"
	.string "HELP, of course!$"
#endif

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
#if GERMAN
	.string "Du kannst überall Radio hören.\n"
	.string "Stell einfach ein!$"
#else
	.string "You can listen to the radio\n"
	.string "anywhere. Tune in!$"
#endif

GoldenrodCity_RadioTower_2F_Text_Policeman:
#if GERMAN
	.string "Zutritt hinter diesem Punkt verboten.$"
#else
	.string "Restricted access beyond this\n"
	.string "point.$"
#endif

GoldenrodCity_RadioTower_2F_Text_Teacher:
#if GERMAN
	.string "Wiegenlieder im Radio lassen Pokémon\n"
	.string "einschlafen.$"
#else
	.string "Lullabies on the radio may make\n"
	.string "POKéMON sleep.$"
#endif

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
#if GERMAN
	.string "Was versprechen sie sich bloß davon,\n"
	.string "den Radiosender zu besetzen?$"
#else
	.string "Why would they want to take over\n"
	.string "the RADIO TOWER?$"
#endif

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
#if GERMAN
	.string "Pummeluff: Pummel… uff…$"
#else
	.string "JIGGLYPUFF: Jiggly…$"
#endif

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
#if GERMAN
	.string "Der Zutritt zu den höheren Stockwerken\n"
	.string "ist nur befugtem Personal erlaubt…\p"
	.string "Aber das war nicht immer so! Irgendwas\n"
	.string "stimmt mit unserem Intendanten nicht…$"
#else
	.string "Sorry. Authorized personnel only\n"
	.string "beyond this point.\p"
	.string "It wasn't that way before.\p"
	.string "There's something wrong with the\n"
	.string "DIRECTOR…$"
#endif

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
#if GERMAN
	.string "Alle Teile des Senders können frei \n"
	.string "besichtigt werden! Unser Intendant ist\l"
	.string "wieder sein gutmütiges altes Selbst!$"
#else
	.string "Feel free to look around anywhere.\p"
	.string "The DIRECTOR is nice again, just\n"
	.string "as he was before.$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
#if GERMAN
	.string "Vor drei Jahren war Team Rocket\n"
	.string "gezwungen, sich aufzulösen…\p"
	.string "Aber unser Comeback ist nur noch\n"
	.string "eine Frage der Zeit!$"
#else
	.string "Three years ago, TEAM ROCKET was\n"
	.string "forced to disband.\p"
	.string "But we're making a comeback here!$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
#if GERMAN
	.string "Pah! Keine Zeit für Sentimentalitäten!$"
#else
	.string "Gwah! Don't get cute!$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
#if GERMAN
	.string "Wir lassen es nicht zu, dass du\n"
	.string "unsere Pläne durchkreuzt!$"
#else
	.string "We won't let you ruin our plans\n"
	.string "for our comeback!$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
#if GERMAN
	.string "Wir sind Team Rocket, die Ausbeuter von\n"
	.string "Pokémon!\p"
	.string "Wir lieben das Böse!\n"
	.string "Na, Angst?$"
#else
	.string "We're TEAM ROCKET, the exploiters\n"
	.string "of POKéMON!\p"
	.string "We love being evil! Scared?$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
#if GERMAN
	.string "Du glaubst wohl, du wärst ein Held?$"
#else
	.string "You think you're a hero?$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
#if GERMAN
	.string "Genau genommen tun wir gar nichts\n"
	.string "Böses.\l"
	.string "Wir tun einfach, was wir wollen.$"
#else
	.string "We're not always evil. We just do\n"
	.string "whatever we like.$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
#if GERMAN
	.string "He! Halte dich aus unseren\n"
	.string "Angelegenheiten raus!$"
#else
	.string "Hey, hey! Keep out of our way!$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
#if GERMAN
	.string "Uff. Mir reicht’s.$"
#else
	.string "Arggh. I give up.$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
#if GERMAN
	.string "Unser Vorstand will die Macht an sich\n"
	.string "reißen. Er hat Großes vor.\l"
	.string "Ich frage mich, was das wohl ist?$"
#else
	.string "Our EXECUTIVES are trying to take\n"
	.string "this place over.\p"
	.string "They have some big plan. I wonder\n"
	.string "what that is?$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
#if GERMAN
	.string "Hehehe!\n"
	.string "Nein, wie öde… hier das Ruder zu\l"
	.string "übernehmen, war viel zu einfach!\p"
	.string "Du da! Willst du mich nicht unterhalten?$"
#else
	.string "Hahaha!\p"
	.string "How boring. It was far too easy\n"
	.string "to take over this place!\p"
	.string "Come on, keep me amused!$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
#if GERMAN
	.string "W-wer bist du denn?$"
#else
	.string "Wh-who are you?$"
#endif

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
#if GERMAN
	.string "Du bist stärker als ich?!?\p"
	.string "Na warte! Das wird dir noch leidtun!$"
#else
	.string "You beat me, and I won't forget\n"
	.string "it!$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
#if GERMAN
	.string "Buena: Hör in meine\n"
	.string "Passwort-Show rein!\p"
	.string "Höre das heutige Passwort!$"
#else
	.string "BUENA: Tune in to my PASSWORD\n"
	.string "SHOW!\p"
	.string "Listen to find out today's\n"
	.string "password!$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaAskPassword:
#if GERMAN
	.string "Buena: Hey du!\p"
	.string "So, weißt du das heutige Passwort?\p"
	.string "OK! Wie lautet es?$"
#else
	.string "BUENA: Hi there!\p"
	.string "So, do you know today's\n"
	.string "password?\p"
	.string "OK! Which one is it?$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaCorrect:
#if GERMAN
	.string "Buena: Richtig!\p"
	.string "Hier, nimm {STR_VAR_1} als deinen Preis!$"
#else
	.string "BUENA: You got it!\p"
	.string "Here, take this {STR_VAR_1}\n"
	.string "as your prize!$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaWrong:
#if GERMAN
	.string "Buena: Bzzt! Schade!\p"
	.string "Versuche es wieder morgen!$"
#else
	.string "BUENA: Bzzt! Too bad!\p"
	.string "Try again tomorrow!$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaComeBack:
#if GERMAN
	.string "Buena: Keine Idee?\n"
	.string "Komm später wieder!$"
#else
	.string "BUENA: No guess?\n"
	.string "Come back when you're ready!$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaAlreadyPlayed:
#if GERMAN
	.string "Buena: Du hast heute bereits\n"
	.string "das Passwort erraten!\p"
	.string "Schalte morgen wieder ein!$"
#else
	.string "BUENA: You already guessed\n"
	.string "today's password!\p"
	.string "Tune in again tomorrow!$"
#endif

GoldenrodCity_RadioTower_2F_Text_BuenaBagFull:
#if GERMAN
	.string "Buena: Du hast es, aber deine Tasche ist\n"
	.string "voll!\p"
	.string "Schaffe etwas Platz und komm zurück!$"
#else
	.string "BUENA: You got it right, but\n"
	.string "your BAG is full!\p"
	.string "Make some room and come\n"
	.string "talk to me again!$"
#endif

GoldenrodCity_RadioTower_2F_Text_SalesSign:
#if GERMAN
	.string "1S: Geschäftsabteilung$"
#else
	.string "2F SALES$"
#endif

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
#if GERMAN
	.string "Prof. Eichs Pokémon-Talk\p"
	.string "Die heißeste Show im Radio!$"
#else
	.string "PROF.OAK'S POKéMON TALK\p"
	.string "The Hottest Show on the Air!$"
#endif

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
#if GERMAN
	.string "Überall und jederzeit:\n"
	.string "Pokémon-Radio!$"
#else
	.string "Anywhere, Anytime POKéMON Radio$"
#endif
