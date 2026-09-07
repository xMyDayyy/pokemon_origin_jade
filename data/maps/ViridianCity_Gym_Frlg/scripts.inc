ViridianCity_Gym_Frlg_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Giovanni::
	famechecker FAMECHECKER_GIOVANNI, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_GIOVANNI, ViridianCity_Gym_Text_GiovanniIntro, ViridianCity_Gym_Text_GiovanniDefeat, ViridianCity_Gym_EventScript_DefeatedGiovanni, NO_MUSIC
	goto_if_unset FLAG_GOT_TM26_FROM_GIOVANNI, ViridianCity_Gym_EventScript_GiveTM26
	msgbox ViridianCity_Gym_Text_GiovanniPostBattle
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_VIRIDIAN_GIOVANNI
	fadescreen FADE_FROM_BLACK
	release
	end

ViridianCity_Gym_EventScript_DefeatedGiovanni::
	famechecker FAMECHECKER_GIOVANNI, 3
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_DEFEATED_LEADER_GIOVANNI
	setflag FLAG_BADGE08_GET
	setvar VAR_MAP_SCENE_ROUTE22, 3
	set_gym_trainers_frlg 8
	goto ViridianCity_Gym_EventScript_GiveTM26
	end

ViridianCity_Gym_EventScript_GiveTM26::
	msgbox ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis
	checkitemspace ITEM_TM26
	goto_if_eq VAR_RESULT, FALSE, ViridianCity_Gym_EventScript_NoRoomForTM26
	giveitem_msg ViridianCity_Gym_Text_ReceivedTM26FromGiovanni, ITEM_TM26
	setflag FLAG_GOT_TM26_FROM_GIOVANNI
	msgbox ViridianCity_Gym_Text_ExplainTM26
	release
	end

ViridianCity_Gym_EventScript_NoRoomForTM26::
	msgbox ViridianCity_Gym_Text_YouDoNotHaveSpace
	release
	end

ViridianCity_Gym_EventScript_Jason::
	trainerbattle_single TRAINER_TAMER_JASON, ViridianCity_Gym_Text_JasonIntro, ViridianCity_Gym_Text_JasonDefeat
	msgbox ViridianCity_Gym_Text_JasonPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Cole::
	trainerbattle_single TRAINER_TAMER_COLE, ViridianCity_Gym_Text_ColeIntro, ViridianCity_Gym_Text_ColeDefeat
	msgbox ViridianCity_Gym_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Atsushi::
	trainerbattle_single TRAINER_BLACK_BELT_ATSUSHI, ViridianCity_Gym_Text_AtsushiIntro, ViridianCity_Gym_Text_AtsushiDefeat
	msgbox ViridianCity_Gym_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Kiyo::
	trainerbattle_single TRAINER_BLACK_BELT_KIYO, ViridianCity_Gym_Text_KiyoIntro, ViridianCity_Gym_Text_KiyoDefeat
	msgbox ViridianCity_Gym_Text_KiyoPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Takashi::
	trainerbattle_single TRAINER_BLACK_BELT_TAKASHI, ViridianCity_Gym_Text_TakashiIntro, ViridianCity_Gym_Text_TakashiDefeat
	msgbox ViridianCity_Gym_Text_TakashiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Samuel::
	trainerbattle_single TRAINER_COOLTRAINER_SAMUEL, ViridianCity_Gym_Text_SamuelIntro, ViridianCity_Gym_Text_SamuelDefeat
	msgbox ViridianCity_Gym_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Yuji::
	trainerbattle_single TRAINER_COOLTRAINER_YUJI, ViridianCity_Gym_Text_YujiIntro, ViridianCity_Gym_Text_YujiDefeat
	msgbox ViridianCity_Gym_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_Warren::
	trainerbattle_single TRAINER_COOLTRAINER_WARREN, ViridianCity_Gym_Text_WarrenIntro, ViridianCity_Gym_Text_WarrenDefeat
	msgbox ViridianCity_Gym_Text_WarrenPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LEADER_GIOVANNI, ViridianCity_Gym_EventScript_GymGuyPostVictory
	msgbox ViridianCity_Gym_Text_GymGuyAdvice
	release
	end

ViridianCity_Gym_EventScript_GymGuyPostVictory::
	famechecker FAMECHECKER_GIOVANNI, 4
	msgbox ViridianCity_Gym_Text_GymGuyPostVictory
	release
	end

ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GiovanniIntro::
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}Haha! Willkommen in meinem\n"
	.string "Geheimversteck!\p"
	.string "Hier wollte ich das Team Rocket\n"
	.string "wiederauferstehen lassen!\p"
	.string "Aber du hast mich schon wieder\n"
	.string "aufgespürt! Also gut! Dieses Mal kenne\l"
	.string "ich keine Gnade!\p"
	.string "Ich, Giovanni, der größte aller\n"
	.string "Trainer, fordere Revanche!$"
#else
	.string "Fwahahaha!\n"
	.string "Welcome to my hideout!\p"
	.string "It shall be so until I can restore\n"
	.string "TEAM ROCKET to its former glory.\p"
	.string "But, you have found me again.\n"
	.string "So be it.\l"
	.string "This time, I'm not holding back!\p"
	.string "Once more, you shall face\n"
	.string "GIOVANNI, the greatest TRAINER!{PLAY_BGM}{MUS_RG_ENCOUNTER_ROCKET}$"
#endif

ViridianCity_Gym_Text_GiovanniDefeat::
#if GERMAN
	.string "Ha!\n"
	.string "Der Kampf war hart, aber fair!\l"
	.string "Du hast gewonnen!\p"
	.string "Nimm bitte den Erdorden zum\n"
	.string "Zeichen meiner Anerkennung!\l"
	.string "{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}$"
#else
	.string "Ha!\n"
	.string "That was a truly intense fight.\l"
	.string "You have won!\p"
	.string "As proof, here is the EARTHBADGE!\n"
	.string "{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}$"
#endif

ViridianCity_Gym_Text_GiovanniPostBattle::
#if GERMAN
	.string "Ich habe meinen Meister gefunden!\n"
	.string "Meine Taten waren schlecht...\l"
	.string "Ich löse das Team Rocket auf!\p"
	.string "Von nun an widme ich mein Leben\n"
	.string "dem Studium der Pokémon!\p"
	.string "Vielleicht sehen wir uns eines\n"
	.string "Tages wieder! Lebe wohl!$"
#else
	.string "Having lost in this fashion, \n"
	.string "I can't face my followers.\l"
	.string "I have betrayed their trust.\p"
	.string "As of today, TEAM ROCKET is\n"
	.string "finished forever!\p"
	.string "As for myself, I shall dedicate\n"
	.string "my life to training again.\p"
	.string "Let us meet again someday!\n"
	.string "Farewell!$"
#endif

ViridianCity_Gym_Text_ExplainEarthBadgeTakeThis::
#if GERMAN
	.string "Mit dem Erdorden gehorchen dir\n"
	.string "getauschte Pokémon bis Level 50!\p"
	.string "Er stellt den Beweis deines Könnens\n"
	.string "als Pokémon Trainer dar!\p"
	.string "Außerdem gewährt er dir den Zugang\n"
	.string "zur Pokémon Liga!\p"
	.string "Nimm dieses Geschenk mit in dein\n"
	.string "Pokémon Liga-Abenteuer!$"
#else
	.string "The EARTHBADGE makes traded\n"
	.string "POKéMON up to Lv. 50 obey.\p"
	.string "It is evidence of your mastery as\n"
	.string "a POKéMON TRAINER.\p"
	.string "With it, you can challenge the\n"
	.string "POKéMON LEAGUE.\p"
	.string "Also, take this TM.\p"
	.string "Consider it a gift for your POKéMON\n"
	.string "LEAGUE challenge.$"
#endif

ViridianCity_Gym_Text_ReceivedTM26FromGiovanni::
#if GERMAN
	.string "{PLAYER} erhält TM26!$"
#else
	.string "{PLAYER} received TM26\n"
	.string "from GIOVANNI.$"
#endif

ViridianCity_Gym_Text_ExplainTM26::
#if GERMAN
	.string "TM26 ist Erdbeben!\p"
	.string "Eine sehr starke Attacke, die ein\n"
	.string "starkes Beben verursacht.\p"
	.string "Ich habe sie vor langer Zeit\n"
	.string "geschaffen, als ich hier noch\l"
	.string "Arenaleiter war.$"
#else
	.string "TM26 contains EARTHQUAKE.\p"
	.string "It is a powerful attack that causes\n"
	.string "a massive tremor.\p"
	.string "I made it when I ran the GYM here,\n"
	.string "far too long ago… $"
#endif

ViridianCity_Gym_Text_YouDoNotHaveSpace::
#if GERMAN
	.string "Du kannst keine weiteren Items mehr\n"
	.string "tragen!$"
#else
	.string "You do not have space for this!$"
#endif

ViridianCity_Gym_Text_YujiIntro::
#if GERMAN
	.string "Hehe!\n"
	.string "So langsam geht dir die Luft aus!$"
#else
	.string "Heh!\n"
	.string "You must be running out of steam\l"
	.string "by now!$"
#endif

ViridianCity_Gym_Text_YujiDefeat::
#if GERMAN
	.string "Mir gehen die Pokémon aus!!!$"
#else
	.string "I ran out of gas!$"
#endif

ViridianCity_Gym_Text_YujiPostBattle::
#if GERMAN
	.string "Du musst stark sein, um unserem\n"
	.string "Arenaleiter entgegenzutreten!$"
#else
	.string "You'll need power to keep up with\n"
	.string "our GYM LEADER.$"
#endif

ViridianCity_Gym_Text_AtsushiIntro::
#if GERMAN
	.string "Kiai! Mit diesem Kampfschrei mobilisiere\n"
	.string "ich meine Kräfte!$"
#else
	.string "Rrrroar!\n"
	.string "I'm working myself into a rage!$"
#endif

ViridianCity_Gym_Text_AtsushiDefeat::
#if GERMAN
	.string "Meister, verzeihe er mir!$"
#else
	.string "Wargh!$"
#endif

ViridianCity_Gym_Text_AtsushiPostBattle::
#if GERMAN
	.string "Ich bin deiner Gnade unwürdig!$"
#else
	.string "I'm still not worthy!$"
#endif

ViridianCity_Gym_Text_JasonIntro::
#if GERMAN
	.string "Ich bilde mit meinen Pokémon eine\n"
	.string "Einheit wie Yin und Yang!$"
#else
	.string "POKéMON and I, we make wonderful\n"
	.string "music together!$"
#endif

ViridianCity_Gym_Text_JasonDefeat::
#if GERMAN
	.string "Deine Pokémon harmonieren gut mit\n"
	.string "dir!$"
#else
	.string "You are in perfect harmony!$"
#endif

ViridianCity_Gym_Text_JasonPostBattle::
#if GERMAN
	.string "Kennst du die Identität unseres\n"
	.string "Arenaleiters?$"
#else
	.string "Do you know the identity of our\n"
	.string "GYM LEADER?$"
#endif

ViridianCity_Gym_Text_KiyoIntro::
#if GERMAN
	.string "Karate ist die Königsdisziplin des\n"
	.string "Kampfsports!$"
#else
	.string "Karate is the ultimate form of\n"
	.string "martial arts!$"
#endif

ViridianCity_Gym_Text_KiyoDefeat::
#if GERMAN
	.string "Ahh!$"
#else
	.string "Aiyah!$"
#endif

ViridianCity_Gym_Text_KiyoPostBattle::
#if GERMAN
	.string "Ach, wären meine Pokémon doch\n"
	.string "auch so starke Karateka wie ich!$"
#else
	.string "If my POKéMON were as good at\n"
	.string "karate as I…$"
#endif

ViridianCity_Gym_Text_WarrenIntro::
#if GERMAN
	.string "Der Stil zeichnet einen großen\n"
	.string "Kämpfer aus!$"
#else
	.string "The truly talented win with style.$"
#endif

ViridianCity_Gym_Text_WarrenDefeat::
#if GERMAN
	.string "Ich habe den Halt verloren!$"
#else
	.string "I lost my grip!$"
#endif

ViridianCity_Gym_Text_WarrenPostBattle::
#if GERMAN
	.string "Der Meister wird mich schelten!$"
#else
	.string "The LEADER will scold me for\n"
	.string "losing this way…$"
#endif

ViridianCity_Gym_Text_TakashiIntro::
#if GERMAN
	.string "Ich bin der Karate-könig!\n"
	.string "Ich besiegle dein Schicksal!$"
#else
	.string "I'm the KARATE KING!\n"
	.string "Your fate rests with me!$"
#endif

ViridianCity_Gym_Text_TakashiDefeat::
#if GERMAN
	.string "Ahh!$"
#else
	.string "Ayah!$"
#endif

ViridianCity_Gym_Text_TakashiPostBattle::
#if GERMAN
	.string "Du willst in die Pokémon Liga? Du?\n"
	.string "Werde bloß nicht größenwahnsinnig!$"
#else
	.string "The POKéMON LEAGUE?\n"
	.string "You? Don't get cocky!$"
#endif

ViridianCity_Gym_Text_ColeIntro::
#if GERMAN
	.string "Allein mein Anblick lässt deine\n"
	.string "Pokémon schaudern!$"
#else
	.string "Your POKéMON will cower at the\n"
	.string "crack of my whip!$"
#endif

ViridianCity_Gym_Text_ColeDefeat::
#if GERMAN
	.string "Sie kringeln sich vor Lachen! Nein!$"
#else
	.string "Yowch!\n"
	.string "Whiplash!$"
#endif

ViridianCity_Gym_Text_ColePostBattle::
#if GERMAN
	.string "Moment!\n"
	.string "Ich war sorglos!$"
#else
	.string "Wait!\n"
	.string "I was just careless!$"
#endif

ViridianCity_Gym_Text_SamuelIntro::
#if GERMAN
	.string "Die Arenahalle von Vertania City war\n"
	.string "lange Zeit geschlossen, doch nun ist\l"
	.string "der Meister zurück!$"
#else
	.string "VIRIDIAN GYM was closed for a\n"
	.string "long time.\p"
	.string "But now, our LEADER is back!$"
#endif

ViridianCity_Gym_Text_SamuelDefeat::
#if GERMAN
	.string "Ich wurde besiegt?$"
#else
	.string "I was beaten?$"
#endif

ViridianCity_Gym_Text_SamuelPostBattle::
#if GERMAN
	.string "Du kannst nur in die Pokémon Liga, wenn\n"
	.string "du unseren Arenaleiter besiegst!$"
#else
	.string "You can go on to the POKéMON\n"
	.string "LEAGUE only by defeating our GYM\l"
	.string "LEADER!$"
#endif

ViridianCity_Gym_Text_GymGuyAdvice::
#if GERMAN
	.string "Heh!\n"
	.string "Warte, du Champion in spe!\p"
	.string "Nicht einmal ich kenne die Identität\n"
	.string "des Arenaleiters von Vertania City!\p"
	.string "Soweit ich weiß, ist er von allen\n"
	.string "Arenaleitern der gefährlichste!\p"
	.string "Die Trainer hier setzen gerne\n"
	.string "Boden-Pokémon ein!$"
#else
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "Even I don't know the VIRIDIAN\n"
	.string "LEADER's identity.\p"
	.string "But one thing's certain.\n"
	.string "This will be the toughest of all\l"
	.string "the GYM LEADERS.\p"
	.string "Also, I heard that the TRAINERS\n"
	.string "here like GROUND-type POKéMON.$"
#endif

ViridianCity_Gym_Text_GymGuyPostVictory::
#if GERMAN
	.string "Das gibt es nicht!\n"
	.string "Giovanni war hier Arenaleiter?$"
#else
	.string "Blow me away! GIOVANNI was the\n"
	.string "GYM LEADER of VIRIDIAN?$"
#endif

ViridianCity_Gym_Text_GymStatue::
#if GERMAN
	.string "Vertania Pokémon-Arena\n"
	.string "Leitung: ?\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}$"
#else
	.string "VIRIDIAN POKéMON GYM\n"
	.string "LEADER: ?\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
#endif

ViridianCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
	.string "Vertania Pokémon-Arena\n"
	.string "Leitung: Giovanni\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "VIRIDIAN POKéMON GYM\n"
	.string "LEADER: GIOVANNI\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif

