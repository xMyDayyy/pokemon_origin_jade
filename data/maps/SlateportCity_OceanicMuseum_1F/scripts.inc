SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
#if GERMAN
	.string "Willkommen im Ozeanmuseum.\p"
	.string "Der Eintritt kostet ¥50.\n"
	.string "Hast du Interesse?$"
#else
	.string "Welcome to the OCEANIC MUSEUM.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?$"
#endif

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
#if GERMAN
	.string "Viel Vergnügen!$"
#else
	.string "Please enjoy yourself.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
#if GERMAN
	.string "Oh. Tut mir Leid, aber du hast\n"
	.string "anscheinend nicht genug Geld bei dir.$"
#else
	.string "Oh? I'm sorry, but you don't seem to\n"
	.string "have enough money.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
#if GERMAN
	.string "Oh. Du gehörst zu der Gruppe, die\n"
	.string "gerade hineingegangen ist?\p"
	.string "Sie sind alle schon drin. Beeil dich,\n"
	.string "sonst verlierst du die Gruppe.$"
#else
	.string "Oh? You're with that group that\n"
	.string "went in earlier?\p"
	.string "You're the only one who's late.\n"
	.string "You'd better go catch up to them!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
#if GERMAN
	.string "Wir, Team Aqua, bestehen zum Besten\n"
	.string "für alle!$"
#else
	.string "We, TEAM AQUA, exist for the good\n"
	.string "of all!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
#if GERMAN
	.string "Uns wurde befohlen, uns hier zu\n"
	.string "versammeln. Das taten wir, aber…\p"
	.string "Unser Boss, der Galgenvogel, ist nicht\n"
	.string "hier.$"
#else
	.string "We were told to assemble here,\n"
	.string "so we did, but…\p"
	.string "Our BOSS, the linchpin, isn't here.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
#if GERMAN
	.string "Wenn ich diese ganzen Sachen an mich\n"
	.string "reißen würde, wäre ich dann reich?$"
#else
	.string "If I ripped off the stuff here,\n"
	.string "would it make me rich?$"
#endif

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
#if GERMAN
	.string "Was ich hier lerne, kann ich für meine\n"
	.string "ruchlosen Taten gut gebrauchen…$"
#else
	.string "What I learn here, I can put to use on\n"
	.string "nefarious deeds…$"
#endif

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
#if GERMAN
	.string "Wenn dieser Idiot die Sache in Metarost\n"
	.string "City nicht vermasselt hätte, wären wir\l"
	.string "jetzt nicht hier.$"
#else
	.string "If our goons didn't bungle things\n"
	.string "in RUSTBORO, we wouldn't be here!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
#if GERMAN
	.string "Ich hatte keine ¥50, daher habe ich\n"
	.string "Ewigkeiten gebraucht, an der Rezeption\l"
	.string "vorbeizukommen.$"
#else
	.string "I didn't have ¥50, so it took a long\n"
	.string "time getting by the receptionist.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
#if GERMAN
	.string "Ich möchte etwas über das Meer lernen\n"
	.string "und dieses Wissen in Kämpfen einsetzen.$"
#else
	.string "I want to learn about the sea and\n"
	.string "use that knowledge for battling.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
#if GERMAN
	.string "Mir wird ganz schwindelig und rühr-\n"
	.string "selig, wenn ich das Meer erblicke!\p"
	.string "Für mich ist Kapt. Brigg das absolute\n"
	.string "Vorbild!$"
#else
	.string "I get all giddy and gooey when\n"
	.string "I see the sea!\p"
	.string "For me, CAPT. STERN is the number\n"
	.string "one role model!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
#if GERMAN
	.string "Das Meer ist erbarmungslos rau und\n"
	.string "unendlich tief…\p"
	.string "In ihm müssen viele Pokémon leben, die\n"
	.string "wir bisher noch nicht kennen.$"
#else
	.string "The sea is vast without end, and\n"
	.string "infinitely deep…\p"
	.string "There must be many POKéMON that\n"
	.string "we don't know about.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
#if GERMAN
	.string "Ich möchte ein Pokémon aus dem Meer\n"
	.string "haben.\p"
	.string "Wenn man das umarmt, ist es bestimmt\n"
	.string "schön kalt und wunderbar glitschig.$"
#else
	.string "I want a sea POKéMON.\p"
	.string "I think it would feel cool and nice\n"
	.string "to hug.$"
#endif

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
#if GERMAN
	.string "Aiyeeh! Was machst du hier?\p"
	.string "Ich? Ich bin von Team Aqua. Du hast\n"
	.string "mich in den Boden gestampft. Erinnerst\l"
	.string "du dich? Im Metaflurtunnel?\p"
	.string "Hier, das ist für dich!\n"
	.string "Vergeben und vergessen!$"
#else
	.string "Aiyeeeh!\n"
	.string "What are you doing here?\p"
	.string "Me? I'm the TEAM AQUA member\n"
	.string "you thumped before, remember?\l"
	.string "Back in RUSTURF TUNNEL?\p"
	.string "Here, take this!\n"
	.string "You have to forgive me!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
#if GERMAN
	.string "Mit dieser TM kannst du mehr anfangen,\n"
	.string "als ich es kann.\p"
	.string "Ich hoffe, du läufst mir nie mehr über\n"
	.string "den Weg! Muahahahaha!$"
#else
	.string "That TM, it suits you more than it\n"
	.string "does me.\p"
	.string "Hope I never see you again!\n"
	.string "Wahahaha!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
#if GERMAN
	.string "Oooch, komm schon!\n"
	.string "Nimm es und lass mich gehen!$"
#else
	.string "Awww, come on!\n"
	.string "You have to take this and let me go!$"
#endif

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
#if GERMAN
	.string "Eine blaue Flüssigkeit bewegt sich\n"
	.string "spiralförmig in einem Glasgefäß.\p"
	.string "“Dies ist ein Experiment, das einen\n"
	.string "künstlichen Whirlpool mit Hilfe von Wind\l"
	.string "erzeugt.”$"
#else
	.string "A blue fluid is spiraling inside\n"
	.string "a glass vessel.\p"
	.string "“This is an experiment to create a\n"
	.string "WHIRLPOOL artificially using wind.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
#if GERMAN
	.string "Ein roter Ball hüpft in dem Glasgefäß\n"
	.string "auf und ab.\p"
	.string "“Dies ist ein Experiment, das eine\n"
	.string "künstliche Kaskade mit Hilfe des\l"
	.string "Ballauftriebs erzeugt.”$"
#else
	.string "A red ball is bobbing up and down\n"
	.string "inside a glass vessel.\p"
	.string "“This is an experiment simulating a\n"
	.string "WATERFALL using the ball's buoyancy.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
#if GERMAN
	.string "Dies ist eine Probe vom Meeresboden.\p"
	.string "“Über viele Jahre haben sich die Spuren\n"
	.string "allen Lebens als Sedimente auf dem\l"
	.string "Grund des Meeres abgelagert.\p"
	.string "Analysen dieser Proben geben einen\n"
	.string "Einblick in längst vergangenes Leben.”$"
#else
	.string "It's a sample of soil from the ocean\n"
	.string "floor.\p"
	.string "“Over many years, the remains of\n"
	.string "life-forms settle at the bottom of\l"
	.string "the sea, making sedimentary layers.\p"
	.string "“By analyzing these layers, the\n"
	.string "ancient past is revealed.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
#if GERMAN
	.string "Dies ist eine Probe vom Sand der\n"
	.string "Küste. \p"
	.string "“Die Gesteinsschichten der Berge\n"
	.string "wurden im Laufe der Jahre durch Wasser\l"
	.string "abgetragen und am Boden abgelagert.\p"
	.string "Nun sind sie nur noch kleine Körnchen,\n"
	.string "die den Sand an der Küste bilden.”$"
#else
	.string "It's a sample of beach sand.\p"
	.string "“Stones from mountains are washed\n"
	.string "down by rivers where they are\l"
	.string "chipped and ground down.\p"
	.string "“They are reduced to grains and end\n"
	.string "up as sand on beaches.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
#if GERMAN
	.string "“Meereskunde Fakt 1”\n"
	.string "Warum ist das Wasser im Meer blau?\p"
	.string "“Licht setzt sich aus vielen\n"
	.string "Farben zusammen.\p"
	.string "Scheint das Licht durch Wasser, so\n"
	.string "gehen einige Farben verloren.\p"
	.string "Der Blauanteil des Lichts bleibt aber\n"
	.string "erhalten, das Wasser erscheint blau.”$"
#else
	.string "“OCEANIC MINIFACT 1\n"
	.string "Why is seawater blue?\p"
	.string "“Light is composed of many colors.\p"
	.string "“When light passes through water,\n"
	.string "most kinds of light lose color.\p"
	.string "“However, blue light retains its\n"
	.string "color, making the sea appear blue.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
#if GERMAN
	.string "“Meereskunde Fakt 2”\n"
	.string "Warum ist das Meer salzig?\p"
	.string "“Meerwasser enthält gelöste Salzionen\n"
	.string "in Form von Natrium und Chlorid.\p"
	.string "Diese Ionen wurden durch den Regen\n"
	.string "aus Gesteinsschichten herausgespült.\p"
	.string "Die Konzentration des aufgelösten\n"
	.string "Salzes macht das Meer salzig.”$"
#else
	.string "“OCEANIC MINIFACT 2\n"
	.string "Why is the sea salty?\p"
	.string "“Seawater contains dissolved salt in\n"
	.string "the form of sodium and chlorine ions.\p"
	.string "“These ions leech out of rocks\n"
	.string "and are carried out to sea by rain.\p"
	.string "“The concentration of dissolved salt\n"
	.string "makes the sea salty.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
#if GERMAN
	.string "“Meereskunde Fakt 3”\n"
	.string "Was ist größer? Das Meer oder das Land?\p"
	.string "“Die Erde ist zu 70 % von Wasser\n"
	.string "bedeckt, der Rest ist Land.\p"
	.string "Das Meer ist also mehr als doppelt\n"
	.string "so groß wie das Land.”$"
#else
	.string "“OCEANIC MINIFACT 3\n"
	.string "Which is bigger? The sea or land?\p"
	.string "“The sea covers about 70% of\n"
	.string "the planet, and the rest is land.\p"
	.string "“The sea is therefore more than twice\n"
	.string "the size of land.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
#if GERMAN
	.string "Das ist ein Fossil mit vielen Furchen.\p"
	.string "“Das Erdreich des Meeresbodens wird\n"
	.string "durch die Gezeiten abgetragen.\p"
	.string "Die Bewegungen des Wassers zeichnen\n"
	.string "Rillen und Wellen in den Meeresboden.\p"
	.string "Wenn der Meeresboden versteinert, wird\n"
	.string "ein Bodenrelief sichtbar.”$"
#else
	.string "It's a fossil with wavy ridges on it.\p"
	.string "“Soil on the ocean floor gets scoured\n"
	.string "by the tide.\p"
	.string "“The flowing seawater marks the soil\n"
	.string "with small ridges and valleys.\p"
	.string "“If this soil becomes fossilized, it is\n"
	.string "called a ripple mark.”$"
#endif

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
#if GERMAN
	.string "Eine seltsame Vorrichtung rotiert\n"
	.string "unter einer Glaskuppel.\p"
	.string "Vielleicht misst sie die Tiefe von\n"
	.string "irgendetwas…$"
#else
	.string "A strange machine is rotating under\n"
	.string "a glass dome.\p"
	.string "Maybe it's for measuring the depth\n"
	.string "of something…$"
#endif

