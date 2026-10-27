IndigoPlateau_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, IndigoPlateau_PokemonCenter_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, IndigoPlateau_Pokecenter_OnTransition
	.byte 0

IndigoPlateau_PokemonCenter_OnFrame::
	map_script_2 VAR_LEAGUE_STATE, 0, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 2, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 3, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 4, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 5, IndigoPlateau_PokemonCenter_Enter
	map_script_2 VAR_LEAGUE_STATE, 6, IndigoPlateau_PokemonCenter_Enter
	.2byte 0

IndigoPlateau_PokemonCenter_Enter::
	setflag FLAG_VISITED_INDIGO_PLATEAU
	setvar VAR_LEAGUE_STATE, 1
	end

IndigoPlateau_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_INDIGO_PLATEAU_HNS
	@ The Black Belt never blocks the Elite Four door; Johto's league can be repeated.
	@ See docs/origin_jade/DECISIONS.md, D-028.
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	call IndigoPlateau_EventScript_SetupSilverFinal
	call_if_set FLAG_IS_JOHTO_CHAMPION, IndigoPlateau_EventScript_ShowSilverDaily
	end

@ After the Johto title Silver waits here for a daily battle (IndigoPlateau_EventScript_Silver).
@ See docs/origin_jade/DECISIONS.md, D-032.
IndigoPlateau_EventScript_ShowSilverDaily::
	clearflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
	return

@ Origin Jade: Silver blocks the Elite Four door until his last battle is won.
IndigoPlateau_EventScript_SetupSilverFinal::
	goto_if_set FLAG_IS_JOHTO_CHAMPION, IndigoPlateau_EventScript_SetupSilverFinalDone
	goto_if_ge VAR_ROUTE27_STATE, 3, IndigoPlateau_EventScript_SetupSilverFinalDone
	clearflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
	setobjectxyperm LOCALID_INDIGOPLATEAU_SILVER, 32, 3
	setobjectmovementtype LOCALID_INDIGOPLATEAU_SILVER, MOVEMENT_TYPE_FACE_DOWN
IndigoPlateau_EventScript_SetupSilverFinalDone:
	return


IndigoPlateau_EventScript_Cooltrainer::
	msgbox IndigoPlateau_Text_CooltrainerM, MSGBOX_NPC
	end

IndigoPlateau_EventScript_BlackBelt::
	msgbox IndigoPlateau_Text_Blackbelt, MSGBOX_NPC
	end

IndigoPlateau_EventScript_ShigyNinja::
	msgbox IndigoPlateau_Text_ShigyNinja, MSGBOX_NPC
	end

IndigoPlateau_Text_ShigyNinja:
#if GERMAN
	.string "Glückwunsch das du es hierher\n"
	.string "geschafft hast!\p"
	.string "Über die Jahre habe ich viele Trainer\n"
	.string "hier ankommen sehen, jeder Einzigartig.\p"
	.string "Du kannst stolz auf dich sein,\n"
	.string "so weit gekommen zu sein.\p"
	.string "Nun Los, weiter!$"
#else
	.string "Congrats on making it here!\p"
	.string "I've seen tons of trainers come\n"
	.string "through here over the years, and\l"
	.string "all of them are wonderfully unique.\p"
	.string "You should be proud of yourself\n"
	.string "for getting this far!\p"
	.string "Now, go get 'em!$"
#endif

IndigoPlateau_Text_Blackbelt:
#if GERMAN
	.string "Die Pokémon Liga akzeptiert momentan\n"
	.string "keine neuen Herausforderer.\p"
	.string "Bitte komm später wieder.$"
#else
	.string "The POKéMON LEAGUE is not taking\n"
	.string "new challengers at the moment.\p"
	.string "Please check back later.$"
#endif

IndigoPlateau_Text_CooltrainerM:
#if GERMAN
	.string "Die Pokémon Liga stellt dich auf eine\n"
	.string "harte Probe: Entweder du schaffst es,\l"
	.string "die Top Vier am Stück zu besiegen, oder\l"
	.string "du musst noch mal von vorne anfangen!$"
#else
    .string "At the POKéMON LEAGUE, you'll get\n"
    .string "tested by the ELITE FOUR.\p"
    .string "You have to beat them all. If you\n"
    .string "lose, you have to start all over!$"
#endif

IndigoPlateau_EventScript_Silver::
	goto_if_lt VAR_ROUTE27_STATE, 3, IndigoPlateau_EventScript_SilverFinal
	lock
	faceplayer
	goto_if_set FLAG_DAILY_BEAT_SILVER, IndigoPlateau_EventScript_SilverBeat
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	msgbox IndigoPlateau_Text_RivalEntrance1, MSGBOX_DEFAULT
	call_if_eq VAR_JOHTO_STARTER_MON, 0, IndigoPlateau_Silver_Battle_Cyndaquil
	call_if_eq VAR_JOHTO_STARTER_MON, 1, IndigoPlateau_Silver_Battle_Totodile
	call_if_eq VAR_JOHTO_STARTER_MON, 2, IndigoPlateau_Silver_Battle_Chikorita
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	setflag FLAG_DAILY_BEAT_SILVER
	release
	end

IndigoPlateau_EventScript_SilverBeat::
	msgbox IndigoPlateau_Text_RivalAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_7_HNS, IndigoPlateau_Text_RivalWin
	return

IndigoPlateau_EventScript_SilverFinal:
	lock
	faceplayer
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	msgbox IndigoPlateau_Text_SilverFinalBefore, MSGBOX_DEFAULT
	call_if_eq VAR_JOHTO_STARTER_MON, 0, IndigoPlateau_EventScript_SilverFinalCyndaquil
	call_if_eq VAR_JOHTO_STARTER_MON, 1, IndigoPlateau_EventScript_SilverFinalTotodile
	call_if_eq VAR_JOHTO_STARTER_MON, 2, IndigoPlateau_EventScript_SilverFinalChikorita
	playbgm MUS_HG_RIVAL_EXIT, FALSE
	msgbox IndigoPlateau_Text_SilverFinalAfter, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_INDIGOPLATEAU_SILVER
	setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
	fadescreenswapbuffers FADE_FROM_BLACK
	fadedefaultbgm
	setvar VAR_ROUTE27_STATE, 3
	release
	end

IndigoPlateau_EventScript_SilverFinalCyndaquil:
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_5_HNS, IndigoPlateau_Text_SilverFinalDefeat
	return

IndigoPlateau_EventScript_SilverFinalTotodile:
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_5_HNS, IndigoPlateau_Text_SilverFinalDefeat
	return

IndigoPlateau_EventScript_SilverFinalChikorita:
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_5_HNS, IndigoPlateau_Text_SilverFinalDefeat
	return

IndigoPlateau_Text_RivalEntrance1:
#if GERMAN
	.string "…{PLAYER}.\p"
	.string "Ich warte hier jeden Tag auf dich.\p"
	.string "Meine Pokémon und ich sind stärker\n"
	.string "geworden. Diesmal gewinne ich!\p"
	.string "{PLAYER}! Ich fordere dich heraus!$"
#else
    .string "…{PLAYER}.\p"
    .string "I wait for you here every day.\p"
    .string "My POKéMON and I have grown\n"
    .string "stronger. This time, I'll win!\p"
    .string "{PLAYER}!\n"
    .string "I challenge you!$"
#endif

IndigoPlateau_Text_RivalWin:
#if GERMAN
	.string "…\p"
	.string "Ich gebe mich geschlagen…$"
#else
    .string "…\p"
    .string "OK--I lost…$"
#endif

IndigoPlateau_Text_RivalAfter:
#if GERMAN
	.string "…Mist… Ich kann immer noch nicht\n"
	.string "gewinnen…\p"
	.string "Ich… ich muss mehr über meine\n"
	.string "Pokémon nachdenken…\p"
	.string "Pah! Morgen bin ich wieder hier.\n"
	.string "Dann gewinne ich!$"
#else
    .string "…Darn… I still can't win…\p"
    .string "I… I have to think more about my\n"
    .string "POKéMON…\p"
    .string "Humph! I'll be back here tomorrow.\n"
    .string "Then I'll win!$"
#endif

IndigoPlateau_EventScript_Psychic::
	lock
	faceplayer
	msgbox IndigoPlateau_Text_TeleportGuy1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, IndigoPlateau_EventScript_PsychicTeleport
	msgbox IndigoPlateau_Text_TeleportGuyNo, MSGBOX_DEFAULT
	closemessage
	release
	end

IndigoPlateau_EventScript_PsychicTeleport::
	msgbox IndigoPlateau_Text_TeleportGuyYes, MSGBOX_DEFAULT
	closemessage
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	@ Origin Jade: home is Pallet Town; 6,8 is in front of the player's house.
	playbgm MUS_RG_PALLET, FALSE
	delay 60
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	applymovement2 LOCALID_INDIGOPLATEAU_ABRA, IndigoPLateau_Movement_Abra
	waitmovement 0
	fadescreen FADE_TO_WHITE
	warpteleport MAP_PALLET_TOWN, 6, 8
	waitstate
	release
	end

IndigoPLateau_Movement_Abra:
	jump_in_place_right
	jump_in_place_right
	step_end

IndigoPlateau_EventScript_Abra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ABRA, CRY_MODE_NORMAL
	msgbox IndigoPlateau_Text_Abra, MSGBOX_DEFAULT
	waitmoncry
	release
	end

IndigoPlateau_Text_TeleportGuy1:
#if GERMAN
	.string "Ah! Du forderst die Top-Vier heraus?\p"
	.string "Bist du sicher, dass du bereit bist?\p"
	.string "Wenn du noch trainieren willst,\n"
	.string "kann mein Abra dir helfen.\p"
	.string "Es kann dich nach Hause teleportieren.\p"
	.string "Willst du jetzt nach Hause gehen?$"
#else
    .string "Ah! You're challenging the ELITE\n"
    .string "FOUR? Are you sure you're ready?\p"
    .string "If you need to train some more,\n"
    .string "my ABRA can help you.\p"
    .string "It can TELEPORT you home.\p"
    .string "Would you like to go home now?$"
#endif

IndigoPlateau_Text_TeleportGuyYes:
#if GERMAN
	.string "Gut, in Ordnung! Dann rufe dir nun bitte\n"
	.string "das Bild von dem Ort, den du Zuhause\l"
	.string "nennst, ins Gedächtnis.$"
#else
    .string "OK, OK. Picture your house in your\n"
    .string "mind…$"
#endif

IndigoPlateau_Text_TeleportGuyNo:
#if GERMAN
	.string "Na gut, in Ordnung! Dann noch viel\n"
	.string "Erfolg!$"
#else
    .string "OK, OK. The best of luck to you!$"
#endif

IndigoPlateau_Text_Abra:
#if GERMAN
	.string "Abra: Abra…$"
#else
    .string "ABRA: Aabra…$"
#endif

IndigoPlateau_Text_SilverFinalBefore:
#if GERMAN
	.string "Moment.\p"
	.string "…Wirst du das Abenteuer der Pokémon\n"
	.string "Liga bestreiten?\p"
	.string "…Bring mich nicht zum Lachen.\p"
	.string "Du bist viel schwächer als ich.\p"
	.string "Ich bin nicht mehr so wie früher.\p"
	.string "Nun habe ich die besten und stärksten\n"
	.string "Pokémon.\p"
	.string "Ich bin unschlagbar!\p"
	.string "{PLAYER}! Ich fordere dich heraus!$"
#else
    .string "Hold it.\p"
    .string "…Are you going to take the POKéMON\n"
    .string "LEAGUE challenge?\p"
    .string "…Don't make me laugh.\p"
    .string "You're so much weaker than I am.\p"
    .string "I'm not like I was before.\p"
    .string "I now have the best and strongest\n"
    .string "POKéMON with me.\p"
    .string "I'm invincible!\p"
    .string "{PLAYER}!\n"
    .string "I challenge you!$"
#endif

IndigoPlateau_Text_SilverFinalDefeat:
#if GERMAN
	.string "…Ich konnte nicht gewinnen…\p"
	.string "Ich habe alles gegeben…\p"
	.string "Was du besitzt und was mir fehlt…\p"
	.string "Langsam begreife ich, was der\n"
	.string "Drachenmeister zu mir sagte…$"
#else
    .string "…I couldn't win…\p"
    .string "I gave it every-thing I had…\p"
    .string "What you possess, and what I lack…\p"
    .string "I'm beginning to understand what\n"
    .string "that dragon master said to me…$"
#endif

IndigoPlateau_Text_SilverFinalAfter:
#if GERMAN
	.string "…Ich habe nicht aufgegeben, der\n"
	.string "weltbeste Trainer zu werden…\p"
	.string "Ich werde herausfinden, warum ich nicht\n"
	.string "gewinnen kann und dann werde ich\l"
	.string "stärker…\p"
	.string "Wenn ich soweit bin, fordere ich dich\n"
	.string "heraus.\p"
	.string "Dann werde ich dir die Leviten lesen.\p"
	.string "…Humpf! Halte bis dahin durch.$"
#else
    .string "…I haven't given up on becoming the\n"
    .string "greatest trainer…\p"
    .string "I'm going to find out why I can't\n"
    .string "win and become stronger…\p"
    .string "When I do, I will challenge you.\p"
    .string "And I'll beat you down with all my\n"
    .string "power.\p"
    .string "…Humph! You keep at it until then.$"
#endif
