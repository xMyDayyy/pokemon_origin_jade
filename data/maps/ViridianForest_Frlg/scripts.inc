ViridianForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_Youngster::
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
	end

ViridianForest_EventScript_Boy::
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
	end

ViridianForest_EventScript_TrainerTips1::
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips2::
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips3::
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips4::
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
	end

ViridianForest_EventScript_TrainerTips5::
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
	end

ViridianForest_EventScript_ExitSign::
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
	end

ViridianForest_EventScript_Rick::
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	goto_if_set FLAG_IS_KANTO_CHAMPION, ViridianForest_EventScript_RickGiveTMXScissor
	end

@ Origin Jade: TM X-Scissor after the Kanto title (D-059).
ViridianForest_EventScript_RickGiveTMXScissor::
	goto_if_set FLAG_GOT_TM_X_SCISSOR_FROM_RICK, Common_EventScript_NoOp
	lock
	giveitem ITEM_TM_X_SCISSOR
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_X_SCISSOR_FROM_RICK
	release
	end

ViridianForest_EventScript_Doug::
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Sammy::
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Anthony::
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_Charlie::
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

ViridianForest_Text_FriendsItchingToBattle::
#if GERMAN
	.string "Meine Freunde und ich wollten hier\n"
	.string "Käfer-Pokémon fangen…\p"
	.string "Unsere Pokémon wollen kämpfen!!!$"
#else
	.string "I came here with some friends to\n"
	.string "catch us some BUG POKéMON!\p"
	.string "They're all itching to get into\n"
	.string "some POKéMON battles!$"
#endif

ViridianForest_Text_RickIntro::
#if GERMAN
	.string "Heh! Du hast auch Pokémon! Los!\n"
	.string "Lass uns kämpfen!$"
#else
	.string "Hey! You have POKéMON!\n"
	.string "Come on!\l"
	.string "Let's battle 'em!$"
#endif

ViridianForest_Text_RickDefeat::
#if GERMAN
	.string "Ah!\n"
	.string "Raupy hat es nicht geschafft!$"
#else
	.string "No!\nCATERPIE can't hack it!$"
#endif

ViridianForest_Text_RickPostBattle::
#if GERMAN
	.string "Psst! Sei leise!\n"
	.string "Du verjagst alle Käfer...$"
#else
	.string "Ssh! You'll scare the bugs away.\n"
	.string "Another time, okay?$"
#endif

ViridianForest_Text_DougIntro::
#if GERMAN
	.string "Heh!\n"
	.string "Ein Pokémon Trainer stiehlt sich nicht\l"
	.string "so einfach davon!!!$"
#else
	.string "Yo!\n"
	.string "You can't jam out if you're a\l"
	.string "POKéMON TRAINER!$"
#endif

ViridianForest_Text_DougDefeat::
#if GERMAN
	.string "Oh! Ich habe kein kampfbereites\n"
	.string "Pokémon mehr!$"
#else
	.string "Huh?\n"
	.string "I ran out of POKéMON!$"
#endif

ViridianForest_Text_DougPostBattle::
#if GERMAN
	.string "So ein Mist! Ich muss ein paar\n"
	.string "Stärkere fangen!$"
#else
	.string "That totally stinks! I'm going to\n"
	.string "catch some stronger ones!$"
#endif

ViridianForest_Text_SammyIntro::
#if GERMAN
	.string "Heh, warte!\n"
	.string "Warum die Eile?$"
#else
	.string "Hey, wait up!\n"
	.string "What's the hurry? Why the rush?$"
#endif

ViridianForest_Text_SammyDefeat::
#if GERMAN
	.string "Uff!\n"
	.string "Du bist zu gut! Ich gebe auf!$"
#else
	.string "I give!\n"
	.string "You're good at this!$"
#endif

ViridianForest_Text_SammyPostBattle::
#if GERMAN
	.string "Mit ein bisschen Glück findet man\n"
	.string "unterwegs Items!\p"
	.string "Ich muss hier irgendwo etwas\n"
	.string "verloren haben...$"
#else
	.string "Sometimes, you can find stuff on\n"
	.string "the ground.\p"
	.string "I'm looking for the stuff I\n"
	.string "dropped. Can you help me?$"
#endif

ViridianForest_Text_AnthonyIntro::
#if GERMAN
	.string "Ich bin zwar klein, aber ich will nicht,\n"
	.string "dass du mich deswegen gewinnen lässt!$"
#else
	.string "I might be little, but I won't like\n"
	.string "it if you go easy on me!$"
#endif

ViridianForest_Text_AnthonyDefeat::
#if GERMAN
	.string "Oh, nein! Alles ist schief gegangen!$"
#else
	.string "Oh, boo.\n"
	.string "Nothing went right.$"
#endif

ViridianForest_Text_AnthonyPostBattle::
#if GERMAN
	.string "Ich habe meinen Kredit verspielt…$"
#else
	.string "I lost some of my allowance…$"
#endif

ViridianForest_Text_CharlieIntro::
#if GERMAN
	.string "Weißt du, dass Pokémon sich entwickeln?$"
#else
	.string "Did you know that POKéMON evolve?$"
#endif

ViridianForest_Text_CharlieDefeat::
#if GERMAN
	.string "Oh!\n"
	.string "Ich hab verloren!$"
#else
	.string "Oh!\n"
	.string "I lost!$"
#endif

ViridianForest_Text_CharliePostBattle::
#if GERMAN
	.string "Käfer-Pokémon entwickeln sich\n"
	.string "schnell. Sie sind einfach toll!$"
#else
	.string "BUG POKéMON evolve quickly.\n"
	.string "They're a lot of fun!$"
#endif

ViridianForest_Text_RanOutOfPokeBalls::
#if GERMAN
	.string "Verdammt! Mir sind die Pokébälle\n"
	.string "ausgegangen! Wie fange ich nun bloß\l"
	.string "Pokémon?\p"
	.string "Du solltest immer genug Pokébälle\n"
	.string "bei dir haben!$"
#else
	.string "I was throwing POKé BALLS to\n"
	.string "catch POKéMON, and I ran out.\p"
	.string "That's why you can never have too\n"
	.string "many POKé BALLS.$"
#endif

ViridianForest_Text_AvoidGrassyAreasWhenWeak::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Wenn du Kämpfe meiden möchtest,\n"
	.string "bleibe hohem Gras fern!$"
#else
	.string "TRAINER TIPS\p"
	.string "If your POKéMON are weak and you\n"
	.string "want to avoid battles, stay away\l"
	.string "from grassy areas!$"
#endif

ViridianForest_Text_UseAntidoteForPoison::
#if GERMAN
	.string "Bei Vergiftungen hat sich das\n"
	.string "Gegengift aus dem Pokémon-Supermarkt\l"
	.string "bewährt.$"
#else
	.string "For poison, use ANTIDOTE!\n"
	.string "Get it at POKéMON MARTS!$"
#endif

ViridianForest_Text_ContactOakViaPCToRatePokedex::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Du kannst deinen Pokédex jederzeit von\n"
	.string "Prof. Eich via PC bewerten lassen!$"
#else
	.string "TRAINER TIPS\p"
	.string "Contact PROF. OAK via a PC to\n"
	.string "get your POKéDEX evaluated!$"
#endif

ViridianForest_Text_CantCatchOwnedMons::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Es ist verboten, anderen Trainern\n"
	.string "Pokémon zu stehlen! Fang nur wilde\l"
	.string "Pokémon!$"
#else
	.string "TRAINER TIPS\p"
	.string "You can't catch a POKéMON that\n"
	.string "belongs to someone else.\p"
	.string "Throw POKé BALLS only at wild\n"
	.string "POKéMON to catch them!$"
#endif

ViridianForest_Text_WeakenMonsBeforeCapture::
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Geschwächte Pokémon sind leichter\n"
	.string "zu fangen!\p"
	.string "Sind sie bei Kräften, könnten sie\n"
	.string "fliehen!$"
#else
	.string "TRAINER TIPS\p"
	.string "Weaken POKéMON before attempting\n"
	.string "capture!\p"
	.string "When healthy, they may escape!$"
#endif

ViridianForest_Text_LeavingViridianForest::
#if GERMAN
	.string "Auf Wiedersehen im Vertania-Wald Der\n"
	.string "Nächste Ort ist Marmoria City.$"
#else
	.string "LEAVING VIRIDIAN FOREST\n"
	.string "PEWTER CITY AHEAD$"
#endif

