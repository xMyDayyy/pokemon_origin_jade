MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_MAUVILLE_GYM_STATE
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
#if IS_HNS
	setvar VAR_0x8004, LIC_ROCK_SMASH
	special SetHoennLicense
#endif
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_DEFEATED_MAUVILLE_GYM
	setflag FLAG_BADGE03_GET
	setvar VAR_0x8004, 2
	special SetHoennBadge
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem_unless_owned ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem_unless_owned ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_MAUVILLE_GYM_STATE, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_MAUVILLE_GYM_STATE, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_ANGELO, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAUVILLE_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
#if IS_HNS
	@ HnS: Hoenn badge 3 (Wattson).
	setvar VAR_0x8004, 2
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
#endif
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
#if IS_HNS
	@ HnS: Hoenn badge 3 (Wattson).
	setvar VAR_0x8004, 2
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
#endif
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
#if GERMAN
	.string "Hey, wie sieht es aus, auf dem Weg zum\n"
	.string "Champ, {PLAYER}?\p"
	.string "Walter, der Arenaleiter von Malvenfroh\n"
	.string "City, setzt Elektro-Pokémon ein.\p"
	.string "Wenn du ihn mit Wasser-Pokémon\n"
	.string "angreifst, macht er sie fertig!\l"
	.string "Britzel! \p"
	.string "Und die Türen lassen sich nur mit\n"
	.string "Schaltern öffnen! Wahnsinn!\p"
	.string "Nun, dann mal los!$"
#else
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "WATTSON, the LEADER of MAUVILLE\n"
	.string "GYM, uses ELECTRIC-type POKéMON.\p"
	.string "If you challenge him with WATER-type\n"
	.string "POKéMON, he'll zap them! Bzzt!\p"
	.string "And, he's put in switch-controlled\n"
	.string "doors all over his GYM! Eccentric!\p"
	.string "Hey, go for it!$"
#endif

MauvilleCity_Gym_Text_GymGuidePostVictory:
#if GERMAN
	.string "Aah, du bist elektrifizierend!\n"
	.string "Du hast die Tür offen gezwungen!$"
#else
	.string "Whoa, you're electrifying!\n"
	.string "You've powered the door open!$"
#endif

MauvilleCity_Gym_Text_KirkIntro:
#if GERMAN
	.string "Die Spannung meiner Seele, sie setzt\n"
	.string "alle deine Träume unter Strom!\l"
	.string "Ja-haha!$"
#else
	.string "My electric soul, it'll shatter your\n"
	.string "dreams whole, whoa-yeahah!$"
#endif

MauvilleCity_Gym_Text_KirkDefeat:
#if GERMAN
	.string "Da wurde der Stromkreis geschlossen\n"
	.string "und bis zum Kurzschluss belastet!$"
#else
	.string "That was plugged in, amped up,\n"
	.string "over-driven electric, man!$"
#endif

MauvilleCity_Gym_Text_KirkPostBattle:
#if GERMAN
	.string "Pokémon und Rock… Alles, was ins Herz\n"
	.string "trifft, boh yeah!$"
#else
	.string "POKéMON and rock, it's all about heart,\n"
	.string "whoa-yeah!$"
#endif

MauvilleCity_Gym_Text_ShawnIntro:
#if GERMAN
	.string "Ich habe unter Walter trainiert!\n"
	.string "So einfach verliere ich nicht.$"
#else
	.string "I trained under WATTSON!\n"
	.string "There ain't no way I'll lose easily!$"
#endif

MauvilleCity_Gym_Text_ShawnDefeat:
#if GERMAN
	.string "Stecker raus und ausgeschaltet…$"
#else
	.string "Unplugged and turned off…$"
#endif

MauvilleCity_Gym_Text_ShawnPostBattle:
#if GERMAN
	.string "Walter, unser Arenaleiter, ist schon\n"
	.string "sehr, sehr lange hier ansässig.\p"
	.string "Er kämpfte schon, da waren wir alle\n"
	.string "noch nicht geboren.$"
#else
	.string "WATTSON, our GYM LEADER, has been\n"
	.string "around for a long, long time.\p"
	.string "He was battling before any of us\n"
	.string "were born, that tough coot.$"
#endif

MauvilleCity_Gym_Text_BenIntro:
#if GERMAN
	.string "Diese Arena stellt dir eine Knobel-\n"
	.string "aufgabe. Ist das nicht lustig?$"
#else
	.string "This GYM's got puzzles!\n"
	.string "Isn't it fun?$"
#endif

MauvilleCity_Gym_Text_BenDefeat:
#if GERMAN
	.string "Verlieren ist gar nicht lustig…$"
#else
	.string "It's no fun to lose…$"
#endif

MauvilleCity_Gym_Text_BenPostBattle:
#if GERMAN
	.string "Walter sagt, er liebt es, Fallen mit\n"
	.string "Schaltern zu installieren.$"
#else
	.string "WATTSON says he likes setting up\n"
	.string "little traps with switches.$"
#endif

MauvilleCity_Gym_Text_VivianIntro:
#if GERMAN
	.string "Mein Charme und die Attacken meiner\n"
	.string "Pokémon werden dich schocken!$"
#else
	.string "With my charm and my POKéMON's moves,\n"
	.string "you'll be shocked!$"
#endif

MauvilleCity_Gym_Text_VivianDefeat:
#if GERMAN
	.string "Ich bin geschockt von deiner Stärke!$"
#else
	.string "I'm shocked by your power!$"
#endif

MauvilleCity_Gym_Text_VivianPostBattle:
#if GERMAN
	.string "Ich habe gehört, dass Malvenfroh City\n"
	.string "von Walter gegründet wurde.\p"
	.string "Er war Trainer, lange bevor wir geboren\n"
	.string "wurden. Er muss ein umfangreiches\l"
	.string "Wissen besitzen.$"
#else
	.string "I've heard that MAUVILLE was founded\n"
	.string "by WATTSON.\p"
	.string "He was a TRAINER long before we\n"
	.string "became TRAINERS.\l"
	.string "He must know all sorts of things!$"
#endif

MauvilleCity_Gym_Text_AngeloIntro:
#if GERMAN
	.string "Ich liebe glitzernde und funkelnde\n"
	.string "Dinge!$"
#else
	.string "I love shiny things!$"
#endif

MauvilleCity_Gym_Text_AngeloDefeat:
#if GERMAN
	.string "Oh… Ich bin geblendet…$"
#else
	.string "Oh…\n"
	.string "My eyes are frazzled…$"
#endif

MauvilleCity_Gym_Text_AngeloPostBattle:
#if GERMAN
	.string "Arenaleiter Walter aus Malvenfroh City\n"
	.string "hat eine glänzende Stirn. Das finde ich\l"
	.string "klasse!$"
#else
	.string "MAUVILLE GYM's WATTSON has a shiny\n"
	.string "forehead. It makes me happy!$"
#endif

MauvilleCity_Gym_Text_WattsonIntro:
#if GERMAN
	.string "Ich habe es aufgegeben, die Stadt\n"
	.string "umpolen zu wollen.\p"
	.string "Stattdessen verwende ich meine Energie\n"
	.string "lieber auf das Installieren von Fallen\l"
	.string "in meiner Arena.\p"
	.string "Oh? Was machst du denn hier?\p"
	.string "Was ist das? Du hast es geschafft,\n"
	.string "alle meine Schalter zu finden?\p"
	.string "Uahahahaha!\n"
	.string "Das ist wirklich amüsant!\p"
	.string "Dann ist es nun an mir - dem Arenaleiter\n"
	.string "von Malvenfroh City - dich unter\l"
	.string "Spannung zu setzen!$"
#else
	.string "I've given up on my plans to convert\n"
	.string "the city, I have.\p"
	.string "And so, I put my time into making\n"
	.string "door traps in my GYM.\p"
	.string "Oh? Now, what are you doing here?\p"
	.string "What's that? You say you've gotten\n"
	.string "past all my rigged doors?\p"
	.string "Wahahahah!\n"
	.string "Now, that is amusing!\p"
	.string "Then, I, WATTSON, the LEADER of\n"
	.string "MAUVILLE GYM, shall electrify you!$"
#endif

MauvilleCity_Gym_Text_WattsonDefeat:
#if GERMAN
	.string "Uahahahaha!\n"
	.string "Schön, ich habe verloren!\p"
	.string "Du hast es geschafft, meinen\n"
	.string "Stromkreis zu unterbrechen! Nimm\l"
	.string "diesen Orden!$"
#else
	.string "Wahahahah!\n"
	.string "Fine, I lost!\p"
	.string "You ended up giving me a thrill!\n"
	.string "Take this BADGE!$"
#endif

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
#if GERMAN
	.string "{PLAYER} hat den Dynamo-Orden von\n"
	.string "Walter erhalten.$"
#else
	.string "{PLAYER} received the DYNAMO BADGE\n"
	.string "from WATTSON.$"
#endif

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
#if GERMAN
	.string "Der Dynamo-Orden macht deine Pokémon\n"
	.string "ein kleines bisschen schneller.\p"
	.string "In Hoenn gilt er außerdem als\n"
	.string "Erlaubnis, Zertrümmerer einzusetzen.\p"
	.string "Hmm…\n"
	.string "Dies hier solltest du auch nehmen!$"
#else
	.string "The DYNAMO BADGE will make your\n"
	.string "POKéMON a little bit faster.\p"
	.string "In HOENN it also serves as your\n"
	.string "permission to use ROCK SMASH.\p"
	.string "Hmm…\n"
	.string "You should take this, too!$"
#endif

MauvilleCity_Gym_Text_ExplainShockWave:
#if GERMAN
	.string "Dies ist TM34 - Schockwelle.\p"
	.string "Eine verlässliche Attacke, die niemals\n"
	.string "daneben geht! Verlass dich drauf!\p"
	.string "… … … … … …$"
#else
	.string "That TM34 there contains SHOCK WAVE.\p"
	.string "It's a trustworthy move that never\n"
	.string "misses! You can count on it!\p"
	.string "… … … … … …$"
#endif

MauvilleCity_Gym_Text_RegisteredWattson:
#if GERMAN
	.string "Arenaleiter Walter wurde im PokéCom-\n"
	.string "Verzeichnis eingetragen.$"
#else
	.string "Registered GYM LEADER WATTSON\n"
	.string "in the POKéGEAR.$"
#endif

MauvilleCity_Gym_Text_WattsonPostBattle:
#if GERMAN
	.string "Optimismus erfüllt mich, wenn ich einen\n"
	.string "so viel versprechenden Trainer wie dich\l"
	.string "sehe!$"
#else
	.string "I swell with optimism, seeing a promising\n"
	.string "young TRAINER like you!$"
#endif

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
#if GERMAN
	.string "Ahahahaha!\n"
	.string "Mach weiter so, streng dich an, Kind!$"
#else
	.string "Wahahahah!\n"
	.string "Go forth and endeavor, youngster!$"
#endif

MauvilleCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon Arena von Malvenfroh City$"
#else
	.string "MAUVILLE CITY POKéMON GYM$"
#endif

MauvilleCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon Arena von Malvenfroh City\p"
	.string "Walters anerkannte Trainer:\n"
	.string "{PLAYER}$"
#else
	.string "MAUVILLE CITY POKéMON GYM\p"
	.string "WATTSON'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

MauvilleCity_Gym_Text_WattsonPreRematch:
#if GERMAN
	.string "Walter: Ah ha! Endlich bist du hier.\n"
	.string "Ich weiß, was du willst! Du willst gegen\l"
	.string "meine Pokémon antreten.\p"
	.string "Hähähähähä!\p"
	.string "Ich werde deine Funken zum Fliegen\n"
	.string "bringen! Und sag hinterher nicht, ich\l"
	.string "hätte dich nicht gewarnt!!!$"
#else
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "I'll make sparks fly from you!\n"
	.string "Don't say I didn't warn you!$"
#endif

MauvilleCity_Gym_Text_WattsonRematchDefeat:
#if GERMAN
	.string "Uff… Meine Batterie ist leer…$"
#else
	.string "Oof…\n"
	.string "Our batteries ran dry…$"
#endif

MauvilleCity_Gym_Text_WattsonPostRematch:
#if GERMAN
	.string "Walter: Wir müssen unsere Batterien\n"
	.string "neu aufladen.\p"
	.string "Und wenn wir das gemacht haben, dann\n"
	.string "werden wir deine Herausforderung gerne\l"
	.string "annehmen.\p"
	.string "Du kommst doch bestimmt mal wieder\n"
	.string "hier vorbei, nicht wahr?$"
#else
	.string "WATTSON: We'll have to recharge our\n"
	.string "batteries again.\p"
	.string "When we're fully charged up, we'll\n"
	.string "gladly accept your challenge.\p"
	.string "So, come back again sometime,\n"
	.string "won't you?$"
#endif

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
#if GERMAN
	.string "Walter: Ah ha! Endlich bist du hier.\n"
	.string "Ich weiß, was du willst! Du willst gegen\l"
	.string "meine Pokémon antreten.\p"
	.string "Hähähähähä!\p"
	.string "Hey! Einen Moment mal.\n"
	.string "Du hast ja nur ein Pokémon dabei!\p"
	.string "Komm bitte wieder, wenn du zwei oder\n"
	.string "mehr Pokémon hast, ja?$"
#else
	.string "WATTSON: Ah-ha! Here at last!\n"
	.string "I know what you want.\l"
	.string "You want to battle my POKéMON!\p"
	.string "Wahahahaha!\p"
	.string "Oops! Wait!\n"
	.string "You've only one POKéMON with you!\p"
	.string "Come see me with two or more\n"
	.string "POKéMON, all right?$"
#endif

