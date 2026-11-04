GoldenrodCity_RadioTower_3F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end

GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8_HNS, GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC_HNS, GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUNNY_DAY, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SUNNY_DAY
	setflag FLAG_GOT_SUNNY_DAY
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
#if GERMAN
	.string "Das ist der Schlitz für den Türöffner!$"
#else
	.string "It's the CARD KEY slot.$"
#endif

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
#if GERMAN
	.string "{PLAYER} verwendet den Türöffner!$"
#else
	.string "{PLAYER} inserted the CARD KEY.$"
#endif

GoldenrodCity_RadioTower_3F_Text_Open:
#if GERMAN
	.string "Das Tor wurde geöffnet.$"
#else
	.string "The gate is open.$"
#endif

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
#if GERMAN
	.string "2S: Allgemeine Angelegenheiten$"
#else
	.string "3F PERSONNEL$"
#endif

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
#if GERMAN
	.string "Pokémon-Musik\n"
	.string "Moderiert von Ben… jawollja!$"
#else
	.string "POKéMON MUSIC with Host DJ BEN$"
#endif

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
#if GERMAN
	.string "Wir haben die Rufe von allen bekannten\n"
	.string "Pokémon auf Tonband.\l"
	.string "Es sind circa 200!$"
#else
	.string "We have recordings of the cries\n"
	.string "of all POKéMON that have been\l"
	.string "found.\p"
	.string "We must have about 400 kinds.$"
#endif

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
#if GERMAN
	.string "Als Partner sind Pokémon für einen\n"
	.string "Trainer unabdingbar!\p"
	.string "Es tut mir in der Seele weh, wenn\n"
	.string "sie jemand so herumkommandiert.$"
#else
	.string "To trainers, POKéMON are their\n"
	.string "beloved partners.\p"
	.string "It's terrible how TEAM ROCKET is\n"
	.string "trying to control POKéMON.$"
#endif

GoldenrodCity_RadioTower_3F_Text_GymGuide:
#if GERMAN
	.string "Wir sind rund um die Uhr auf Sendung!\p"
	.string "Ich selbst bin auch 24 Stunden am Tag\n"
	.string "darum bemüht, unserem Publikum ein\l"
	.string "spannendes Programm darzubieten!$"
#else
	.string "We run 24 hours a day to broadcast\n"
	.string "entertaining programs.\p"
	.string "I'll do my best to run around the\n"
	.string "clock too!$"
#endif

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
#if GERMAN
	.string "Der Anführer von Team Rocket hat sich\n"
	.string "hinter dieser Tür verbarrikadiert.\p"
	.string "Sie wurde von innen abgeschlossen, aber\n"
	.string "der Intendant könnte sie öffnen!\p"
	.string "Du findest ihn im vierten Stock!\n"
	.string "Oh bitte, du musst ihn retten!$"
#else
	.string "The TEAM ROCKET boss has locked\n"
	.string "himself in.\p"
	.string "But the DIRECTOR can open it.\p"
	.string "He's up on the fifth floor.\p"
	.string "Please save him!$"
#endif

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
#if GERMAN
	.string "Geht es dem Intendanten gut?$"
#else
	.string "Is the DIRECTOR safe?$"
#endif

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
#if GERMAN
	.string "Danke! Du bist mein Held!\p"
	.string "Nimm dies als Dankesgeschenk.$"
#else
	.string "Thank you! You're my hero!\p"
	.string "This is a token of my appreciation.$"
#endif

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
#if GERMAN
	.string "Diese TM enthält die Attacke\n"
	.string "Sonnentag. Mit ihr kannst du temporär\l"
	.string "Attacken vom Typ Feuer verstärken.$"
#else
	.string "It's SUNNY DAY.\p"
	.string "It powers up fire-type moves\n"
	.string "for a while.$"
#endif

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
#if GERMAN
	.string "Saubere Arbeit!$"
#else
	.string "You were simply marvelous!$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
#if GERMAN
	.string "Mir wurden strikte Befehle erteilt.\p"
	.string "Jeder, der Team Rocket in die\n"
	.string "Quere kommt, wird pulverisiert!$"
#else
	.string "I've been given strict orders.\p"
	.string "I'm to crush anyone who challenges\n"
	.string "TEAM ROCKET!$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
#if GERMAN
	.string "Hey?$"
#else
	.string "What?!$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
#if GERMAN
	.string "Ich habe versagt…\p"
	.string "Atlas wird so wütend sein…$"
#else
	.string "I failed in my duties…\p"
	.string "ARCHER will be so upset...$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
#if GERMAN
	.string "Es ist ein tolles Gefühl, Pokémon\n"
	.string "für Verbrechen einzusetzen!$"
#else
	.string "It feels great ordering POKéMON\n"
	.string "to commit crimes.$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
#if GERMAN
	.string "…Ich habe was?$"
#else
	.string "You're kidding!$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
#if GERMAN
	.string "Verlieren dagegen ist ein mieses\n"
	.string "Gefühl! Ach, verflixt!\l"
	.string "Ich hasse unfähige Pokémon!$"
#else
	.string "I feel lousy over losing!\p"
	.string "Darn it! I hate useless POKéMON!$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
#if GERMAN
	.string "Wieso steht die Tür offen? Was geht\n"
	.string "hier vor? Hast du was damit zu tun?$"
#else
	.string "Why did the shutter open? Did you\n"
	.string "have something to do with this?$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
#if GERMAN
	.string "Ich bin erledigt!$"
#else
	.string "I'm done for!$"
#endif

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
#if GERMAN
	.string "Was?!? Du bist an unseren Männern im\n"
	.string "Untergrund vorbeigekommen?\l"
	.string "Wie hast du das fertiggebracht?$"
#else
	.string "What?! You made it past our men in\n"
	.string "the UNDERGROUND?\p"
	.string "How could you?$"
#endif

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
#if GERMAN
	.string "Was macht ein fremdes Kind hier?\n"
	.string "Wer bist du?$"
#else
	.string "An unknown child wandering here?\p"
	.string "Who are you?$"
#endif

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
#if GERMAN
	.string "Tse!\n"
	.string "Ich habe dich wohl unterschätzt.$"
#else
	.string "Tch! I took you too lightly!$"
#endif

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
#if GERMAN
	.string "Mwahaha… von hier kann ich Signale\n"
	.string "jeder Stärke aussenden!$"
#else
	.string "Bwahahaha…\p"
	.string "I can transmit as strong a signal\n"
	.string "as I need from here.$"
#endif

