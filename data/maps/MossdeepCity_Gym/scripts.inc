MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
#if IS_HNS
	setvar VAR_0x8004, LIC_DIVE
	special SetHoennLicense
#endif
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setvar VAR_0x8004, 6
	special SetHoennBadge
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem_unless_owned ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem_unless_owned ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
#if IS_HNS
	@ HnS: Hoenn badge 7 (Tate and Liza).
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
#endif
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
#if IS_HNS
	@ HnS: Hoenn badge 7 (Tate and Liza).
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
#endif
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
#if GERMAN
	.string "Na, wie sieht es aus, auf dem Weg zum\n"
	.string "Champ, {PLAYER}?\p"
	.string "Die Arenaleiter hier setzen Psycho-\n"
	.string "Pokémon ein.\p"
	.string "Setzt du Kampf- oder Gift-Pokémon ein,\n"
	.string "werden diese großen Schaden nehmen!\p"
	.string "Und außerdem wirst du dich gegen eine\n"
	.string "außergewöhnliche Kombination von\l"
	.string "Attacken behaupten müssen.\p"
	.string "Wenn du gewinnen willst, musst du ihnen\n"
	.string "beweisen, wie sehr du mit deinen\l"
	.string "Pokémon verbunden bist! Und nun los!$"
#else
	.string "Yo, how's it going, CHAMPION-bound\n"
	.string "{PLAYER}?\p"
	.string "The GYM LEADERS here use\n"
	.string "PSYCHIC-type POKéMON.\p"
	.string "If you go up against them with\n"
	.string "FIGHTING- or POISON-type POKéMON,\l"
	.string "they'll inflict horrible damage!\p"
	.string "Plus, they'll come at you with\n"
	.string "outstanding combination attacks.\p"
	.string "If you want to win, you'll need to show\n"
	.string "them how tight you are with your\l"
	.string "POKéMON. Go for it!$"
#endif

MossdeepCity_Gym_Text_GymGuidePostVictory:
#if GERMAN
	.string "Wow, du bist erstaunlich!\n"
	.string "Du bist ein großartiger Trainer!$"
#else
	.string "Wow, you're astounding!\n"
	.string "You're one great TRAINER!$"
#endif

MossdeepCity_Gym_Text_PrestonIntro:
#if GERMAN
	.string "Kämpfe hängen von der Stärke deines\n"
	.string "Geistes ab! Die mit schwachem Geist\l"
	.string "werden niemals gewinnen.$"
#else
	.string "Battles hinge on the strength of your\n"
	.string "spirit! The weak-spirited will never win!$"
#endif

MossdeepCity_Gym_Text_PrestonDefeat:
#if GERMAN
	.string "Ich habe verloren! Ich muss meinen\n"
	.string "Geist stärken!$"
#else
	.string "I lost!\n"
	.string "I must temper my spirit again!$"
#endif

MossdeepCity_Gym_Text_PrestonPostBattle:
#if GERMAN
	.string "Eine nichtssagende Niederlage.\n"
	.string "Das war doch nur eine Warnung an dich.$"
#else
	.string "The indecisive lose.\n"
	.string "That's my warning to you.$"
#endif

MossdeepCity_Gym_Text_VirgilIntro:
#if GERMAN
	.string "Zeig mir, ob du Talent hast.$"
#else
	.string "Let me see your talent!$"
#endif

MossdeepCity_Gym_Text_VirgilDefeat:
#if GERMAN
	.string "Du besitzt offensichtlich Talent.$"
#else
	.string "You possess spectacular talent!$"
#endif

MossdeepCity_Gym_Text_VirgilPostBattle:
#if GERMAN
	.string "Wenn es überhaupt Wunderkinder gibt,\n"
	.string "dann sind es unsere Arenaleiter.\p"
	.string "Aber du scheinst doch talentierter\n"
	.string "als sie zu sein…$"
#else
	.string "If there are prodigies in the world,\n"
	.string "then our GYM LEADERS are them!\p"
	.string "However, you may be even more talented\n"
	.string "than them…$"
#endif

MossdeepCity_Gym_Text_BlakeIntro:
#if GERMAN
	.string "Hihihihi… Achtung! Ich lasse meinen\n"
	.string "Pokéball durch Telekinese schweben!\p"
	.string "Wuhuuuuuuuhuiii! … … … … … … …\p"
	.string "Äh, manchmal fehlt es mir etwas an\n"
	.string "Balance…$"
#else
	.string "Fufufufu… Watch me levitate a POKé\n"
	.string "BALL telekinetically!\p"
	.string "Wrooooooooaaaar!\n"
	.string "… … … … … … …\p"
	.string "Sometimes, I'm out of sync…$"
#endif

MossdeepCity_Gym_Text_BlakeDefeat:
#if GERMAN
	.string "Meine Pokémon kämpften nicht\n"
	.string "synchron!$"
#else
	.string "My POKéMON battling skills are out\n"
	.string "of sync, too!$"
#endif

MossdeepCity_Gym_Text_BlakePostBattle:
#if GERMAN
	.string "Ein Pokéball ist doch etwas zu schwer,\n"
	.string "um ihn schweben zu lassen!\l"
	.string "Aber ein Staubknäuel…\p"
	.string "Wuhuuuuuuuhu! … … … … … … …\p"
	.string "Das ist kein Trick!\n"
	.string "Da ist kein Luftstrom! Ehrlich!$"
#else
	.string "A POKé BALL was too heavy to lift\n"
	.string "psychically. But this dust bunny…\p"
	.string "Whoooooooooooooooh!\n"
	.string "… … … … … …\p"
	.string "No, I'm not cheating!\n"
	.string "I didn't blow on it! Honestly!$"
#endif

MossdeepCity_Gym_Text_HannahIntro:
#if GERMAN
	.string "Solltest du gegen mich verlieren,\n"
	.string "darfst du dir das nicht so zu Herzen\l"
	.string "nehmen.\p"
	.string "Du bist nicht zu schwach - ich bin nur\n"
	.string "zu stark für dich!$"
#else
	.string "When you lose to me, don't be too hard\n"
	.string "on yourself.\p"
	.string "It's not that you're weak--I'm just\n"
	.string "too strong!$"
#endif

MossdeepCity_Gym_Text_HannahDefeat:
#if GERMAN
	.string "Du bist nur zu stark für mich!$"
#else
	.string "You're just too strong!$"
#endif

MossdeepCity_Gym_Text_HannahPostBattle:
#if GERMAN
	.string "Ich lasse mich von dieser Niederlage\n"
	.string "nicht herunterziehen. Ich werde härter\l"
	.string "trainieren.\p"
	.string "Positives Denken - das ist meine\n"
	.string "Stärke!$"
#else
	.string "I'm not going to get down on myself for\n"
	.string "losing. I just need to train harder.\p"
	.string "Positive thinking--that's my strong\n"
	.string "point!$"
#endif

MossdeepCity_Gym_Text_SamanthaIntro:
#if GERMAN
	.string "Ich kann sie sehen…\n"
	.string "Ich sehe deine Zukunft…\p"
	.string "Wenn du mich besiegen kannst, sage ich\n"
	.string "dir deine Zukunft voraus.$"
#else
	.string "I see it…\n"
	.string "I see your future…\p"
	.string "If you can beat me, I will tell you\n"
	.string "your future!$"
#endif

MossdeepCity_Gym_Text_SamanthaDefeat:
#if GERMAN
	.string "Ich ergebe mich!$"
#else
	.string "I surrender!$"
#endif

MossdeepCity_Gym_Text_SamanthaPostBattle:
#if GERMAN
	.string "Du wirst einen irrsinnigen Kampf gegen\n"
	.string "unsere Arenaleiter führen…\p"
	.string "Der Ausgang dieses Kampfes…\n"
	.string "Meine Lippen sind versiegelt.$"
#else
	.string "You will wage a terrifically intense\n"
	.string "battle with our GYM LEADERS…\p"
	.string "The result…\n"
	.string "You won't hear it from me!$"
#endif

MossdeepCity_Gym_Text_MauraIntro:
#if GERMAN
	.string "Die Straßen, die du gewandert bist…\n"
	.string "Das, was du erfahren hast…\p"
	.string "Leg mir alles, was du gelernt hast,\n"
	.string "zu Füßen.$"
#else
	.string "The roads you have traveled…\n"
	.string "What you have experienced…\p"
	.string "Come at me with everything you've\n"
	.string "learned!$"
#endif

MossdeepCity_Gym_Text_MauraDefeat:
#if GERMAN
	.string "Du wandelst auf dem Pfad der Größe!$"
#else
	.string "You've traveled a path of greatness!$"
#endif

MossdeepCity_Gym_Text_MauraPostBattle:
#if GERMAN
	.string "Eine glänzende Zukunft erwartet die,\n"
	.string "die fleißig sind.\p"
	.string "Die, die dem Müßiggang frönen, erwartet\n"
	.string "am Ende des Weges nur die Verzweiflung.\p"
	.string "Man erntet das, was man sät.$"
#else
	.string "A bright future awaits those who have\n"
	.string "worked diligently.\p"
	.string "For those who lazed idly, there is\n"
	.string "only despair at the end.\p"
	.string "What goes around comes around…$"
#endif

MossdeepCity_Gym_Text_SylviaIntro:
#if GERMAN
	.string "Auch wenn ich dabei mein Leben aufs\n"
	.string "Spiel setze - ich werde den Kampf\l"
	.string "gewinnen!$"
#else
	.string "Even at the risk of life, I will win\n"
	.string "this battle!$"
#endif

MossdeepCity_Gym_Text_SylviaDefeat:
#if GERMAN
	.string "Was du da machst…\n"
	.string "Das macht mir Angst…$"
#else
	.string "What you do…\n"
	.string "It horrifies me…$"
#endif

MossdeepCity_Gym_Text_SylviaPostBattle:
#if GERMAN
	.string "Wie konntest du es wagen, mich zu\n"
	.string "besiegen…\p"
	.string "Es ist nicht meine Schuld, wenn dir\n"
	.string "bald etwas Schreckliches passiert…$"
#else
	.string "How dare you beat me…\p"
	.string "It won't be my fault if something\n"
	.string "horrible befalls you…$"
#endif

MossdeepCity_Gym_Text_NateIntro:
#if GERMAN
	.string "Hohoho.\p"
	.string "Du lässt mir keine andere Wahl. Ich\n"
	.string "werde dir zeigen, wie zäh\l"
	.string "Psycho-Pokémon sind.$"
#else
	.string "Hohoho.\p"
	.string "You need me to show you how tenacious\n"
	.string "the PSYCHIC type can be.$"
#endif

MossdeepCity_Gym_Text_NateDefeat:
#if GERMAN
	.string "Oh! Meine Güte!\n"
	.string "Dein Kampfstil ist einfach fantastisch!$"
#else
	.string "Oh! My, my!\n"
	.string "Your battle style is fantastic!$"
#endif

MossdeepCity_Gym_Text_NatePostBattle:
#if GERMAN
	.string "Ich… lasse mich durch eine Niederlage\n"
	.string "nicht aus der Ruhe bringen.$"
#else
	.string "I… I don't let defeat rattle m-me,\n"
	.string "however b-badly.$"
#endif

MossdeepCity_Gym_Text_KathleenIntro:
#if GERMAN
	.string "Ich werde dir eine wunderbar\n"
	.string "schreckliche und gruselige Zeit\l"
	.string "bereiten.$"
#else
	.string "Let me show you a perfectly awful,\n"
	.string "horrifying time!$"
#endif

MossdeepCity_Gym_Text_KathleenDefeat:
#if GERMAN
	.string "NnnneeeeeiiiinnnnN!$"
#else
	.string "N-nooooo!$"
#endif

MossdeepCity_Gym_Text_KathleenPostBattle:
#if GERMAN
	.string "Deine Dynamik ist mit Sicherheit\n"
	.string "ansteckend! Geh schnell weg!$"
#else
	.string "Your vitality is contagious!\n"
	.string "Get away from me quickly!$"
#endif

MossdeepCity_Gym_Text_CliffordIntro:
#if GERMAN
	.string "Ich mag meine beste Zeit gesehen\n"
	.string "haben, aber ich lasse mich von dir nicht\l"
	.string "bevormunden.$"
#else
	.string "I may be past my prime, but I suggest\n"
	.string "you not patronize me.$"
#endif

MossdeepCity_Gym_Text_CliffordDefeat:
#if GERMAN
	.string "Ah, deine jugendliche Energie strömt\n"
	.string "nur so aus dir heraus.$"
#else
	.string "Ah, you overflow with the power\n"
	.string "of youth!$"
#endif

MossdeepCity_Gym_Text_CliffordPostBattle:
#if GERMAN
	.string "Gegen deine jugendliche Energie habe\n"
	.string "ich keine Chance.$"
#else
	.string "It seems that I could not overcome\n"
	.string "your youthful energy.$"
#endif

MossdeepCity_Gym_Text_MaceyIntro:
#if GERMAN
	.string "Du wirst den Weg nicht zu Ende gehen!\n"
	.string "Nicht, wenn ich mich dir in den Weg\l"
	.string "stellen kann.$"
#else
	.string "You're not getting through to the end!\n"
	.string "Not if I can help it!$"
#endif

MossdeepCity_Gym_Text_MaceyDefeat:
#if GERMAN
	.string "Wie kann man nur so stark sein wie du?\n"
	.string "Lächerlich!$"
#else
	.string "How could you be so ludicrously\n"
	.string "strong?$"
#endif

MossdeepCity_Gym_Text_MaceyPostBattle:
#if GERMAN
	.string "Hmpf! Du magst ja stark sein, aber mit\n"
	.string "Psycho-Pokémon kommst du nicht\l"
	.string "zurecht!\p"
	.string "Du hast einen recht brutalen\n"
	.string "Kampfstil.$"
#else
	.string "Humph! You may be strong, but you're\n"
	.string "not suitable for the PSYCHIC type!\p"
	.string "The way you battle is somehow brutal!$"
#endif

MossdeepCity_Gym_Text_NicholasIntro:
#if GERMAN
	.string "Wroooaaar! Schmeck die Superkraft\n"
	.string "meines Pokémon!$"
#else
	.string "Wroooar! Have a taste of my super\n"
	.string "POKéMON hard-battling power!$"
#endif

MossdeepCity_Gym_Text_NicholasDefeat:
#if GERMAN
	.string "Oh! Das war’s dann wohl.$"
#else
	.string "Oh!\n"
	.string "Done in!$"
#endif

MossdeepCity_Gym_Text_NicholasPostBattle:
#if GERMAN
	.string "Gut! Ich glaube, ich sollte eine un-\n"
	.string "schlagbare Pokémon-Kraft entwickeln.$"
#else
	.string "All right! I think I'll develop a special\n"
	.string "invincible POKéMON power next.$"
#endif

MossdeepCity_Gym_Text_TateAndLizaIntro:
#if GERMAN
	.string "Ben: Hähähä… Bist du überrascht?\p"
	.string "Svenja: Hihihi… Bist du überrascht?\p"
	.string "Ben: Dass es hier 2 Arenaleiter gibt?\n"
	.string "Svenja: Dass es hier 2 Arenaleiter gibt?\p"
	.string "Ben: Wir sind Zwillinge!\n"
	.string "Svenja: Wir sind Zwillinge!\p"
	.string "Ben: Wir brauchen nicht zu sprechen…\n"
	.string "Svenja: Wir wissen, was…\p"
	.string "Ben: Der andere gerade denkt…\n"
	.string "Svenja: Gedankenübertragung!\p"
	.string "Ben: Diese doppelte Stärke…\n"
	.string "Svenja: Kannst du sie besiegen?$"
#else
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: Fufufu… Were you surprised?\p"
	.string "TATE: That there are two GYM LEADERS?\n"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: We're twins!\n"
	.string "LIZA: We're twins!\p"
	.string "TATE: We don't need to talk because…\n"
	.string "LIZA: We can each determine what…\p"
	.string "TATE: The other is thinking…\n"
	.string "LIZA: All in our minds!\p"
	.string "TATE: This combination of ours…\n"
	.string "LIZA: Can you beat it?$"
#endif

MossdeepCity_Gym_Text_TateAndLizaDefeat:
#if GERMAN
	.string "Ben: Was?!? Unsere Kombination…\n"
	.string "Svenja: Wurde auseinander gerissen!\p"
	.string "Ben: So sieht’s aus. Du hast gewonnen.\n"
	.string "Svenja: Daher überreichen wir dir dies.$"
#else
	.string "TATE: What?! Our combination…\n"
	.string "LIZA: Was shattered!\p"
	.string "TATE: It can't be helped. You've won…\n"
	.string "LIZA: So, in recognition, take this.$"
#endif

MossdeepCity_Gym_Text_ReceivedMindBadge:
#if GERMAN
	.string "{PLAYER} erhält den Mentalorden von\n"
	.string "Svenja und Ben.$"
#else
	.string "{PLAYER} received the MIND BADGE\n"
	.string "from TATE and LIZA.$"
#endif

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
#if GERMAN
	.string "Ben: Der Mentalorden erhöht den SP.\n"
	.string "ANG. und die SP. Ver. von Pokémon.\p"
	.string "Svenja: In Hoenn gilt er außerdem als\n"
	.string "Erlaubnis, Taucher einzusetzen.\p"
	.string "Ben: Dies ist ebenfalls für dich.$"
#else
	.string "TATE: The MIND BADGE enhances the\n"
	.string "SP. ATK and SP. DEF of POKéMON.\p"
	.string "LIZA: In HOENN it also serves as your\n"
	.string "permission to use DIVE.\p"
	.string "TATE: You should also take this, too.$"
#endif

MossdeepCity_Gym_Text_ExplainCalmMind:
#if GERMAN
	.string "Ben: TM04 enthält…\n"
	.string "Svenja: Gedankengut!\p"
	.string "Ben: Dies erhöht den SP. ANG. und…\n"
	.string "Svenja: Erhöht die SP. Ver.!\p"
	.string "Ben: Eine Attacke, die perfekt…\n"
	.string "Svenja: Für Psycho-Pokémon ist!\p"
	.string "… … … … … …$"
#else
	.string "TATE: That TM04 contains…\n"
	.string "LIZA: CALM MIND!\p"
	.string "TATE: It raises SP. ATK and…\n"
	.string "LIZA: It raises SP. DEF!\p"
	.string "TATE: It's a move that's perfect…\n"
	.string "LIZA: For PSYCHIC POKéMON!\p"
	.string "… … … … … …$"
#endif

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
#if GERMAN
	.string "Arenaleiter Ben und Svenja wurden im\n"
	.string "PokéCom-Verzeichnis eingetragen.$"
#else
	.string "Registered GYM LEADERS TATE & LIZA\n"
	.string "in the POKéGEAR.$"
#endif

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
#if GERMAN
	.string "Ben: Es scheint, als sei das Band\n"
	.string "zwischen dir und deinen Pokémon viel\l"
	.string "stärker als zwischen uns Zwillingen.\p"
	.string "Svenja: Und du wirst noch stärker\n"
	.string "werden! Wir haben gegen dich gekämpft,\l"
	.string "daher können wir das vorhersagen.$"
#else
	.string "TATE: Looks like the bond between you\n"
	.string "and your POKéMON is far stronger than\l"
	.string "the bond that we share as twins.\p"
	.string "LIZA: You will become even stronger!\n"
	.string "We've battled you, so we know.$"
#endif

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
#if GERMAN
	.string "Ben: Hähähä… Bist du überrascht?\p"
	.string "Svenja: Dass es hier 2 Arenaleiter\n"
	.string "gibt?\p"
	.string "Ben: Hups, du hast nur ein…\n"
	.string "Svenja: Pokémon für den Kampf.\p"
	.string "Ben: So können wir nicht kämpfen!\p"
	.string "Svenja: Wenn du uns herausfordern\n"
	.string "willst, dann musst du mehr Pokémon\l"
	.string "haben.$"
#else
	.string "TATE: Hehehe… Were you surprised?\p"
	.string "LIZA: That there are two GYM LEADERS?\p"
	.string "TATE: Oops, you have only one…\n"
	.string "LIZA: POKéMON that can battle.\p"
	.string "TATE: We can't battle that way!\p"
	.string "LIZA: If you want to challenge us,\n"
	.string "bring some more POKéMON.$"
#endif

MossdeepCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon Arena von Moosbach City$"
#else
	.string "MOSSDEEP CITY POKéMON GYM$"
#endif

MossdeepCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon Arena von Moosbach City\p"
	.string "Svenja und Bens anerkannte Trainer:\n"
	.string "{PLAYER}$"
#else
	.string "MOSSDEEP CITY POKéMON GYM\p"
	.string "LIZA AND TATE'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
#if GERMAN
	.string "Ben: Pokémon…\n"
	.string "Svenja: Pokémon…\p"
	.string "Ben: Die Zusammensetzung des Teams…\n"
	.string "Svenja: Bestimmt den Kampfstil.\p"
	.string "Ben: Aber ich…\n"
	.string "Svennja: Aber ich…\p"
	.string "Ben: Kämpfe nur zusammen mit Svenja!\n"
	.string "Svenja: Kämpfe nur zusammen mit Ben!\p"
	.string "Ben: Diese Kombination…\n"
	.string "Svenja: Wirst du immer wieder sehen!$"
#else
	.string "TATE: POKéMON…\n"
	.string "LIZA: POKéMON…\p"
	.string "TATE: By changing the party's mix…\n"
	.string "LIZA: The battle style changes.\p"
	.string "TATE: But me…\n"
	.string "LIZA: But me…\p"
	.string "TATE: I'll always be with LIZA!\n"
	.string "LIZA: I'll always be with TATE!\p"
	.string "TATE: Our combination…\n"
	.string "LIZA: We'll show you again and again!$"
#endif

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
#if GERMAN
	.string "Ben: Du und deine Pokémon…\n"
	.string "Svenja: Seid wie Geschwister! $"
#else
	.string "TATE: You and your POKéMON…\n"
	.string "LIZA: It's as if you were siblings!$"
#endif

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
#if GERMAN
	.string "Ben: Du magst uns besiegen, aber wir\n"
	.string "werden nicht am Boden liegen bleiben!\l"
	.string "\p"
	.string "Svenja: Denn wir beide werden immer\n"
	.string "füreinander da sein!$"
#else
	.string "TATE: You can knock us down,\n"
	.string "but we'll never stay down!\p"
	.string "LIZA: Because the two of us,\n"
	.string "we always support each other!$"
#endif

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
#if GERMAN
	.string "Ben: Du bist zurückgekommen…\n"
	.string "Svenja: Du bist zurückgekommen…\p"
	.string "Ben: Um erneut gegen uns anzutreten.\n"
	.string "Svenja: Um erneut gegen uns\l"
	.string "anzutreten.\p"
	.string "Ben: Aber…\n"
	.string "Svenja: Für diesen Kampf hast du…\p"
	.string "Ben: Nur ein einziges Pokémon dabei!\n"
	.string "Svenja: Nur ein einziges Pokémon dabei!\p"
	.string "Ben: Du musst mindestens zwei…\n"
	.string "Svenja: Pokémon haben.$"
#else
	.string "TATE: You're back again…\n"
	.string "LIZA: You're back again…\p"
	.string "TATE: To give us a rematch.\n"
	.string "LIZA: To give us a rematch.\p"
	.string "TATE: But…\n"
	.string "LIZA: For our match…\p"
	.string "TATE: You brought just one POKéMON!\n"
	.string "LIZA: You brought just one POKéMON!\p"
	.string "TATE: We need you to bring at least…\n"
	.string "LIZA: Two POKéMON when you come back.$"
#endif
