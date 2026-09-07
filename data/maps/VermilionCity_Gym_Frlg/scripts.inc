.equ FOUND_FIRST_SWITCH, FLAG_TEMP_1
.equ SWITCH1_ID,         VAR_0x8004
.equ SWITCH2_ID,         VAR_0x8005
.equ TRASH_CAN_ID,       VAR_0x8008

VermilionCity_Gym_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, Common_EventScript_NopReturn
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_LtSurge::
	famechecker FAMECHECKER_LTSURGE, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
	trainerbattle_single TRAINER_LEADER_LT_SURGE, VermilionCity_Gym_Text_LtSurgeIntro, VermilionCity_Gym_Text_LtSurgeDefeat, VermilionCity_Gym_EventScript_DefeatedLtSurge, NO_MUSIC
	goto_if_unset FLAG_GOT_TM34_FROM_SURGE, VermilionCity_Gym_EventScript_GiveTM34
	msgbox VermilionCity_Gym_Text_LtSurgePostBattle
	release
	end

VermilionCity_Gym_EventScript_DefeatedLtSurge::
	famechecker FAMECHECKER_LTSURGE, 1
	call_if_unset FLAG_GOT_HM05, VermilionCity_Gym_EventScript_ShowOaksAide
	clearflag FLAG_HIDE_FAME_CHECKER_LT_SURGE_JOURNAL
	setflag FLAG_DEFEATED_LT_SURGE
	setflag FLAG_BADGE03_GET
	set_gym_trainers_frlg 3
	@ Ab drei Orden gehorchen getauschte Pokemon bis Level 25.
	msgbox VermilionCity_Gym_Text_ObedienceLevel20
	goto VermilionCity_Gym_EventScript_GiveTM34
	end

VermilionCity_Gym_EventScript_ShowOaksAide::
	clearflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
	return

VermilionCity_Gym_EventScript_GiveTM34::
	msgbox VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis
	checkitemspace ITEM_TM34
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_NoRoomForTM34
	giveitem_msg VermilionCity_Gym_Text_ReceivedTM34FromLtSurge, ITEM_TM34
	setflag FLAG_GOT_TM34_FROM_SURGE
	msgbox VermilionCity_Gym_Text_ExplainTM34
	release
	end

VermilionCity_Gym_EventScript_NoRoomForTM34::
	msgbox VermilionCity_Gym_Text_MakeRoomInYourBag
	release
	end

VermilionCity_Gym_EventScript_Dwayne::
	trainerbattle_single TRAINER_SAILOR_DWAYNE, VermilionCity_Gym_Text_DwayneIntro, VermilionCity_Gym_Text_DwayneDefeat
	famechecker FAMECHECKER_LTSURGE, 4
	msgbox VermilionCity_Gym_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Baily::
	trainerbattle_single TRAINER_ENGINEER_BAILY, VermilionCity_Gym_Text_BailyIntro, VermilionCity_Gym_Text_BailyDefeat
	msgbox VermilionCity_Gym_Text_BailyPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Tucker::
	trainerbattle_single TRAINER_GENTLEMAN_TUCKER, VermilionCity_Gym_Text_TuckerIntro, VermilionCity_Gym_Text_TuckerDefeat, VermilionCity_Gym_EventScript_DefeatedTucker
	famechecker FAMECHECKER_LTSURGE, 3
	msgbox VermilionCity_Gym_Text_TuckerPostBattle, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_DefeatedTucker::
	famechecker FAMECHECKER_LTSURGE, 2
	release
	end

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LT_SURGE, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_Text_LtSurgeIntro::
#if GERMAN
	.string "{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}Heh, Kiddie!\n"
	.string "Was hast du hier verloren?\p"
	.string "Im Kampf hast du keine große\n"
	.string "Chance, so viel ist sicher!\p"
	.string "Lass mich dir etwas erzählen: Während\n"
	.string "der Pokémon-Feldzüge haben mich meine\l"
	.string "Elektro-Pokémon gerettet!\p"
	.string "Sie haben meine Gegner mit Strom\n"
	.string "paralysiert!\p"
	.string "Das Gleiche steht dir nun bevor!$"
#else
	.string "Hey, kid! What do you think you're\n"
	.string "doing here?\p"
	.string "You won't live long in combat!\n"
	.string "Not with your puny power!\p"
	.string "I tell you, kid, electric POKéMON\n"
	.string "saved me during the war!\p"
	.string "They zapped my enemies into\n"
	.string "paralysis!\p"
	.string "The same as I'll do to you!{PLAY_BGM}{MUS_RG_ENCOUNTER_GYM_LEADER}$"
#endif

VermilionCity_Gym_Text_LtSurgePostBattle::
#if GERMAN
	.string "Ich gebe dir noch einen Tipp!\p"
	.string "Die Elektrizität ist enorm kraftvoll!\p"
	.string "Doch sie hat keine Wirkung auf\n"
	.string "Boden-Pokémon!$"
#else
	.string "A little word of advice, kid!\p"
	.string "Electricity is sure powerful!\p"
	.string "But, it's useless against GROUND-\n"
	.string "type POKéMON!$"
#endif

VermilionCity_Gym_Text_ExplainThunderBadgeTakeThis::
#if GERMAN
	.string "Der Donnerorden erhöht die Initiative\n"
	.string "deiner Pokémon!\p"
	.string "Außerdem können deine Pokémon nun\n"
	.string "jederzeit Fliegen einsetzen!\p"
	.string "Du bist ein besonderes Kind!\n"
	.string "Nimm das hier!$"
#else
	.string "The THUNDERBADGE cranks up your\n"
	.string "POKéMON's SPEED!\p"
	.string "It also lets your POKéMON FLY\n"
	.string "lightning-quick anytime, kid!\p"
	.string "You're special, kid!\n"
	.string "Take this!$"
#endif

VermilionCity_Gym_Text_ReceivedTM34FromLtSurge::
#if GERMAN
	.string "{PLAYER} erhält TM34!$"
#else
	.string "{PLAYER} received TM34\n"
	.string "from LT. SURGE.$"
#endif

VermilionCity_Gym_Text_ExplainTM34::
#if GERMAN
	.string "TM34 ist Schockwelle!\p"
	.string "Elektro-Pokémon können diese\n"
	.string "Attacke erlernen!$"
#else
	.string "TM34 contains SHOCK WAVE!\p"
	.string "Teach it to an ELECTRIC POKéMON!$"
#endif

VermilionCity_Gym_Text_MakeRoomInYourBag::
#if GERMAN
	.string "Dein Rucksack ist voll!$"
#else
	.string "Yo, kid, make room in your BAG!$"
#endif

VermilionCity_Gym_Text_LtSurgeDefeat::
#if GERMAN
	.string "Wow!\p"
	.string "Du weißt, wie man kämpft, Kiddie!\p"
	.string "Als Auszeichnung verleihe ich dir\n"
	.string "den Donnerorden!$"
#else
	.string "Now that's a shocker!\p"
	.string "You're the real deal, kid!\p"
	.string "Fine, then, take the THUNDERBADGE!$"
#endif

VermilionCity_Gym_Text_TuckerIntro::
#if GERMAN
	.string "Major Bob war mein Ausbilder!$"
#else
	.string "When I was in the Army, LT. SURGE\n"
	.string "was my strict CO.\p"
	.string "He was a hard taskmaster.$"
#endif

VermilionCity_Gym_Text_TuckerDefeat::
#if GERMAN
	.string "Stopp!\n"
	.string "Du bist zu gut!$"
#else
	.string "Stop!\n"
	.string "You're very good!$"
#endif

VermilionCity_Gym_Text_TuckerPostBattle::
#if GERMAN
	.string "Die Barriere verschwindet nicht?\p"
	.string "Major Bob war immer sehr vorsichtig!$"
#else
	.string "It's not easy opening that door.\p"
	.string "LT. SURGE was always famous for\n"
	.string "his cautious nature in the Army.$"
#endif

VermilionCity_Gym_Text_BailyIntro::
#if GERMAN
	.string "Ich bin ein Fliegengewicht, aber im\n"
	.string "Umgang mit Elektrizität bin ich Profi!$"
#else
	.string "I'm a lightweight, but I'm good\n"
	.string "with electricity!\p"
	.string "That's why I joined this GYM.$"
#endif

VermilionCity_Gym_Text_BailyDefeat::
#if GERMAN
	.string "Ein Kurzschluss!$"
#else
	.string "Fried!$"
#endif

VermilionCity_Gym_Text_BailyPostBattle::
#if GERMAN
	.string "O.k., ich rede!\p"
	.string "Major Bob hat hier irgendwo Schalter\n"
	.string "versteckt!$"
#else
	.string "Okay, I'll talk!\p"
	.string "LT. SURGE said he hid door\n"
	.string "switches inside something.$"
#endif

VermilionCity_Gym_Text_DwayneIntro::
#if GERMAN
	.string "Das hier ist kein Spielplatz!$"
#else
	.string "This is no place for kids!\n"
	.string "Not even if you're good!$"
#endif

VermilionCity_Gym_Text_DwayneDefeat::
#if GERMAN
	.string "Wow!\n"
	.string "Du hast mich überrascht!$"
#else
	.string "Wow!\n"
	.string "Surprised me!$"
#endif

VermilionCity_Gym_Text_DwaynePostBattle::
#if GERMAN
	.string "Major Bob hat die Tür doppelt\n"
	.string "abgesichert!\p"
	.string "Ein Tipp?\p"
	.string "Der zweite Schalter befindet sich\n"
	.string "direkt neben dem ersten!$"
#else
	.string "LT. SURGE installed the traps in\n"
	.string "the GYM himself.\p"
	.string "He set up double locks everywhere.\n"
	.string "Let me give you a hint.\p"
	.string "When you open the first lock, the\n"
	.string "second lock is right next to it.$"
#endif

VermilionCity_Gym_Text_GymGuyAdvice::
#if GERMAN
	.string "Heh!\n"
	.string "Warte, du Champion in spe!\p"
	.string "Major Bob hat einen Spitznamen.\n"
	.string "Man nennt ihn den Blitzschnellen\l"
	.string "Arenaleiter!\p"
	.string "Er ist ein Experte für Elektro-\n"
	.string "Pokémon!\p"
	.string "Flug- und Wasser-Pokémon sind ihm\n"
	.string "hilflos ausgeliefert! Er nutzt auch\l"
	.string "gern Paralyse!\p"
	.string "Major Bob ist sehr vorsichtig!\p"
	.string "Du musst ein Rätsel lösen, um ihn\n"
	.string "zu treffen!$"
#else
	.string "Yo!\n"
	.string "Champ in the making!\p"
	.string "LT. SURGE has a nickname.\p"
	.string "People refer to him as the\n"
	.string "Lightning American!\p"
	.string "He's an expert on electric\n"
	.string "POKéMON.\p"
	.string "BIRD/WATER-type POKéMON match\n"
	.string "poorly against the ELECTRIC type.\p"
	.string "Beware of paralysis, too.\p"
	.string "LT. SURGE is very cautious.\p"
	.string "He's locked himself in, so it won't\n"
	.string "be easy getting to him.$"
#endif

VermilionCity_Gym_Text_GymGuyPostVictory::
#if GERMAN
	.string "Puh!\n"
	.string "Ein elektrisierender Kampf!$"
#else
	.string "Whew!\n"
	.string "That match was electric!$"
#endif

VermilionCity_Gym_Text_GymStatue::
#if GERMAN
	.string "Orania Pokémon-Arena\n"
	.string "Leitung: Major Bob\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}$"
#else
	.string "VERMILION POKéMON GYM\n"
	.string "LEADER: LT. SURGE\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}$"
#endif

VermilionCity_Gym_Text_GymStatuePlayerWon::
#if GERMAN
	.string "Orania Pokémon-Arena\n"
	.string "Leitung: Major Bob\p"
	.string "Bisherige Sieger:\n"
	.string "{RIVAL}, {PLAYER}$"
#else
	.string "VERMILION POKéMON GYM\n"
	.string "LEADER: LT. SURGE\p"
	.string "WINNING TRAINERS:\n"
	.string "{RIVAL}, {PLAYER}$"
#endif

VermilionCity_Gym_Text_NopeOnlyTrashHere::
#if GERMAN
	.string "Hier ist nichts, bloß Abfall.$"
#else
	.string "Nope!\n"
	.string "There's only trash here.$"
#endif

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
#if GERMAN
	.string "Heh! Hier ist ein Hebel versteckt!\n"
	.string "Ich werde ihn betätigen!\p"
	.string "Das erste Schloss wurde entriegelt!$"
#else
	.string "Hey! There's a switch under the\n"
	.string "trash! Turn it on!\p"
	.string "The first electric lock opened!$"
#endif

VermilionCity_Gym_Text_SecondLockOpened::
#if GERMAN
	.string "Das zweite Schloss wurde entriegelt!\p"
	.string "Die mechanische Tür hat sich geöffnet!$"
#else
	.string "The second electric lock opened!\n"
	.string "The motorized door opened!$"
#endif

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
#if GERMAN
	.string "Hier ist nichts, bloß Abfall.\p"
	.string "Heh! Das Schloss wurde wieder\n"
	.string "verriegelt!$"
#else
	.string "Nope!\n"
	.string "There's only trash here.\p"
	.string "Hey!\n"
	.string "The electric locks were reset!$"
#endif

VermilionCity_Gym_Text_ObedienceLevel20::
#if GERMAN
	.string "Und noch etwas: Mit drei Orden\n"
	.string "gehorchen dir getauschte Pokémon\l"
	.string "bis Level 25!\p"
	.string "Stärkere hören vielleicht nicht\n"
	.string "auf dich.$"
#else
	.string "One more thing. With three BADGES,\n"
	.string "traded POKéMON up to Lv. 25 will\l"
	.string "obey you!\p"
	.string "Stronger ones may ignore your\n"
	.string "orders.$"
#endif
