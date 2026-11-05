GoldenrodCity_RadioTower_4F_hns_MapScripts::
	.byte 0

GoldenrodCity_RadioTower_4F4_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_Studio2Sign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_4F4_Text_ProductionSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_Grunt28::
	trainerbattle_single TRAINER_GRUNT_28_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen, GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntF4After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_9_HNS, GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen, GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_GruntM10After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower4_EventScript_Proton::
	trainerbattle_single TRAINER_PROTON_2_HNS, GoldenrodCity_RadioTower_4F4_Text_Proton_Seen, GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_Proton_After, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Fisher::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_4F4_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Scientist::
	trainerbattle_single TRAINER_RICH_HNS, GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen, GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten
	msgbox GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_4F4_EventScript_Mary::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_4F4_EventScript_Mary2
	goto_if_unset FLAG_GOT_MARY_BRIGHT_POWDER, GoldenrodCity_RadioTower_4F4_EventScript_Mary3
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary2::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMary, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Mary3::
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_BRIGHT_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_GOT_MARY_BRIGHT_POWDER
	closemessage
	release
	end

GoldenrodCity_RadioTower_4F4_EventScript_Meowth::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MEOWTH, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_4F4_Text_Meowth, MSGBOX_DEFAULT
	waitmoncry
	release
	end


GoldenrodCity_RadioTower_4F4_Text_Proton_Seen:
#if GERMAN
	.string "Lance: Halt!\p"
	.string "…Ach? Dich kenne ich doch aus dem\n"
	.string "Flegmon-Brunnen? Dort hast du unsere\l"
	.string "Pläne schon einmal vereitelt…\p"
	.string "Ah, verstehe… du legst es wohl darauf\n"
	.string "an, unseren Zorn zu provozieren?\p"
	.string "Nun gut, ganz wie du willst.\n"
	.string "Spüre die Rache eines\l"
	.string "Vorstandsmitglieds von Team Rocket!$"
#else
	.string "PROTON: Now wait just one second!\p"
	.string "Aren't you the one who got in our\n"
	.string "way at SLOWPOKE WELL?\p"
	.string "I see... You're doing all this\n"
	.string "because you want to make me angry.\l"
	.string "Be careful!\p"
	.string "But since you seem to wish it, I'll\n"
	.string "show you the full extent of a TEAM\l"
	.string "ROCKET EXECUTIVE's wrath!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_Proton_Beaten:
#if GERMAN
	.string "Pfuuuh…$"
#else
	.string "Phew...$"
#endif

GoldenrodCity_RadioTower_4F4_Text_Proton_After:
#if GERMAN
	.string "Lance: Mich magst du besiegt haben…\n"
	.string "Doch im Endeffekt ziehst du damit bloß\l"
	.string "den Zorn von Team Rocket auf dich!$"
#else
	.string "PROTON: You may have won this\n"
	.string "time... But all you did was make\p"
	.string "TEAM ROCKET's wrath grow.$"
#endif

GoldenrodCity_RadioTower_4F4_Text_Fisher:
#if GERMAN
	.string "Als ich bei den Ruinen mein Radio\n"
	.string "angeschaltet habe, kamen sehr seltsame\l"
	.string "Signale aus den Lautsprechern.$"
#else
	.string "I listened to the radio while I was\n"
	.string "at the RUINS.\p"
	.string "I heard a strange broadcast there.$"
#endif

GoldenrodCity_RadioTower_4F4_Text_DJMary:
#if GERMAN
	.string "Margit: Oh nein, wie konnte ich bloß in\n"
	.string "so einen Schlamassel geraten?\p"
	.string "Hilf mir, Mauzi! Hilf mir!$"
#else
	.string "MARY: Why? Why do I have to suffer\n"
	.string "through this?\p"
	.string "MEOWTH, help me!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_DJMaryCleared:
#if GERMAN
	.string "Margit: Du bist der Trainer, der\n"
	.string "mich gerettet hat, stimmt’s?\p"
	.string "Hier, nimm!\n"
	.string "Das ist ein Zeichen meines Dankes!$"
#else
	.string "MARY: Oh! You're my little savior!\p"
	.string "Will you take this as my thanks?$"
#endif

GoldenrodCity_RadioTower_4F4_Text_DJMaryPinkBow:
#if GERMAN
	.string "Margit: Damit kannst du den Attacken\n"
	.string "des Gegners besser ausweichen.$"
#else
	.string "MARY: It's good for dodging the\n"
	.string "enemy's attacks.$"
#endif

GoldenrodCity_RadioTower_4F4_Text_DJMaryAfter:
#if GERMAN
	.string "Margit: Und hör dir den Pokémon-Talk\n"
	.string "mit Prof. Eich und mir im Radio an, ja?$"
#else
	.string "MARY: Please tune into me on PROF.\n"
	.string "OAK'S POKéMON TALK show!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_Meowth:
#if GERMAN
	.string "Mauzi: …Mauz!$"
#else
	.string "MEOWTH: Meowth…$"
#endif

GoldenrodCity_RadioTower_4F4_Text_GruntM10Seen:
#if GERMAN
	.string "Du hast vor, den Intendanten zu\n"
	.string "retten? Das kannst du dir abschminken,\l"
	.string "denn ich werde dich besiegen!$"
#else
	.string "You plan to rescue the DIRECTOR?\p"
	.string "That won't be possible because I'm\n"
	.string "going to beat you!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_GruntM10Beaten:
#if GERMAN
	.string "Nein! Unglaublich!$"
#else
	.string "No! Unbelievable!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_GruntM10After:
#if GERMAN
	.string "Ich fass es nicht! Ich wurde besiegt!$"
#else
	.string "I don't believe it! I was beaten!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Seen:
#if GERMAN
	.string "Stopp! Man nennt mich die\n"
	.string "Team-Rocket-Festung!\p"
	.string "Keinen Schritt weiter!$"
#else
	.string "Stop! I'm known as the TEAM ROCKET\n"
	.string "fortress!\p"
	.string "You're not taking another step!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2Beaten:
#if GERMAN
	.string "Die Festung ist gefallen!$"
#else
	.string "The fortress came down!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ExecutiveM2After:
#if GERMAN
	.string "Du hast meinen Respekt.\p"
	.string "Ein Rat: Es ist noch nicht zu spät.\n"
	.string "Du kannst immer noch umkehren.$"
#else
	.string "You've earned my respect, so here's\n"
	.string "some advice.\p"
	.string "It's not too late. You can still turn\n"
	.string "back.$"
#endif

GoldenrodCity_RadioTower_4F4_Text_GruntF4Seen:
#if GERMAN
	.string "Ob ich Pokémon niedlich finde?\p"
	.string "Klar! Meine Pokémon werden sooo\n"
	.string "niedlich sein…\p"
	.string "wenn sie deine besiegt haben!$"
#else
	.string "Don't I think POKéMON are cute?\p"
	.string "I'll think my POKéMON are cute--\p"
	.string "after they beat yours!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_GruntF4Beaten:
#if GERMAN
	.string "Tse!\n"
	.string "Was ein nutzloser Haufen!$"
#else
	.string "Oh, no! They're so useless!$"
#endif

GoldenrodCity_RadioTower_4F4_Text_GruntF4After:
#if GERMAN
	.string "Ich liebe mich selbst!\p"
	.string "Wen interessieren Pokémon?$"
#else
	.string "I love my beautiful self!\p"
	.string "Who cares about POKéMON?$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ScientistRichSeen:
#if GERMAN
	.string "Exzellent.\p"
	.string "Mit dem Radioturm können wir unser\n"
	.string "Vorhaben in die Tat umsetzen.$"
#else
	.string "Most excellent.\p"
	.string "This RADIO TOWER will fulfill our\n"
	.string "grand design.$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ScientistRichBeaten:
#if GERMAN
	.string "Hmmm…\n"
	.string "Jeder große Plan hat wohl einen Haken.$"
#else
	.string "Hmmm…\p"
	.string "All grand plans come with snags.$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ScientistRichAfter:
#if GERMAN
	.string "Glaubst du allen Ernstes, Team\n"
	.string "Rocket aufhalten zu können?$"
#else
	.string "Do you honestly believe you can stop\n"
	.string "TEAM ROCKET?$"
#endif

GoldenrodCity_RadioTower_4F4_Text_ProductionSign:
#if GERMAN
	.string "3S: Produktion$"
#else
	.string "4F PRODUCTION$"
#endif

GoldenrodCity_RadioTower_4F4_Text_Studio2Sign:
#if GERMAN
	.string "3S Studio 2$"
#else
	.string "4F STUDIO 2$"
#endif
