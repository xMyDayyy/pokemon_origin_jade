RusturfTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
	.byte 0

RusturfTunnel_OnFrame:
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
	.2byte 0

RusturfTunnel_OnTransition:
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
	end

RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_PEEKO, 13, 4
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_GRUNT, 13, 5
	return

RusturfTunnel_EventScript_Wanda::
	lock
	faceplayer
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_AlreadySpokenTo::
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_ClearTunnelScene::
	lockall
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
#if IS_HNS
	@ HnS: no handover, the Strength license comes with the Heat Badge.
	msgbox Text_HnsShatteredBoulderNoHandover, MSGBOX_DEFAULT
#else
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
#endif
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
#if !IS_HNS
	giveitem ITEM_HM_STRENGTH
#endif
	setflag FLAG_RECEIVED_HM_STRENGTH
#if !IS_HNS
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
#endif
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_BoyfriendApproachWanda1::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda2::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda3::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend1::
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend2::
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend3::
	return

RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
	closemessage
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit1
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit::
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0
	return

RusturfTunnel_EventScript_WandasBoyfriendNotice::
	playse SE_PIN
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_WandaExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit:
	delay_8
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused2:
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_Unused3:
	walk_up
	walk_in_place_faster_down
	delay_8
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1:
	walk_left
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend:
	walk_right
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight:
	walk_up
	walk_in_place_faster_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1:
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_faster_up
	step_end

RusturfTunnel_EventScript_TunnelBlockagePos1::
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2::
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3::
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_AquaGruntBackUp::
	lockall
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_GRUNT
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_PEEKO
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end

RusturfTunnel_Movement_GruntAndPeekoBackUp:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_Peeko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RusturfTunnel_EventScript_Grunt::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_PARTS
	closemessage
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntEscape
	waitmovement 0
	removeobject LOCALID_RUSTURF_TUNNEL_GRUNT
	delay 50
	addobject LOCALID_RUSTURF_TUNNEL_BRINEY
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
	waitmovement 0
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
	waitmovement 0
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyExit
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_PeekoExit
	waitmovement 0
	removeobject LOCALID_RUSTURF_TUNNEL_BRINEY
	removeobject LOCALID_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end

RusturfTunnel_Movement_PushPlayerAsideForGrunt:
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney:
	walk_down
	walk_in_place_faster_up
	step_end

RusturfTunnel_Movement_GruntEscape:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_Movement_PlayerWatchBrineyExit:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2:
	delay_16
	walk_right
	step_end

RusturfTunnel_Movement_PeekoExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RusturfTunnel_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

RusturfTunnel_Text_ComeAndGetSome:
#if GERMAN
	.string "Was? Du willst gegen uns antreten?\n"
	.string "Na, dann hol dir eine Tracht Prügel.$"
#else
	.string "What, are you coming?\n"
	.string "Come and get some, then!$"
#endif

RusturfTunnel_Text_Peeko:
#if GERMAN
	.string "Pecko: Pii pihyoh!$"
#else
	.string "PEEKO: Pii pihyoh!$"
#endif

RusturfTunnel_Text_GruntIntro:
#if GERMAN
	.string "Grrr, man sollte sie alle kielholen.\p"
	.string "Das als Geisel genommene Pokémon hat\n"
	.string "sich als völlig wertlos erwiesen!\p"
	.string "Und dafür habe ich nun einen Fluchtweg\n"
	.string "in diesem Tunnel nach Nirgendwo\l"
	.string "gegraben!\p"
	.string "Hey! Du!\n"
	.string "Forderst du mich etwa heraus?$"
#else
	.string "Grah, keelhaul it all!\p"
	.string "That hostage POKéMON turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You!\n"
	.string "So you want to battle me?$"
#endif

RusturfTunnel_Text_GruntDefeat:
#if GERMAN
	.string "Aargh! Und so läuft eine\n"
	.string "vielversprechende kriminelle Karriere\l"
	.string "in eine Sackgasse!$"
#else
	.string "Urrrggh! My career in crime comes to\n"
	.string "a dead end!$"
#endif

RusturfTunnel_Text_GruntTakePackage:
#if GERMAN
	.string "Das ist einfach nicht fair…\p"
	.string "Der Boss hat doch gesagt, der Job sei\n"
	.string "ein wahres Kinderspiel.\p"
	.string "Alles, was ich zu tun hatte, war, ein\n"
	.string "Paket von Devon zu stehlen.\p"
	.string "Tse! Wenn du es so dringend wieder-\n"
	.string "haben willst, dann nimm es halt!$"
#else
	.string "This is plain not right…\p"
	.string "The BOSS told me this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All I had to do was steal some package\n"
	.string "from DEVON.\p"
	.string "Tch!\n"
	.string "You want it back that badly, take it!$"
#endif

RusturfTunnel_Text_PeekoGladToSeeYouSafe:
#if GERMAN
	.string "Pecko! Bin ich froh, dass du unversehrt\n"
	.string "wieder bei mir bist.$"
#else
	.string "PEEKO!\n"
	.string "Am I glad to see you're safe!$"
#endif

RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
#if GERMAN
	.string "Pecko verdankt dir ihr Leben!\p"
	.string "Man nennt mich Mr. Brack.\n"
	.string "Und du bist…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, du bist also {PLAYER}{KUN}!\n"
	.string "Ich danke dir von ganzem Herzen!\p"
	.string "Wenn du irgendein Problem hast, zögere\n"
	.string "nicht, mich um Hilfe zu bitten!\p"
	.string "Ich wohne in dem kleinen Haus am Meer\n"
	.string "in der Nähe des Blütenburgwalds.\p"
	.string "Komm, Pecko, wir sollten uns auf den\n"
	.string "Heimweg machen.\p"
	.string "Pecko: Pihyoh!$"
#else
	.string "PEEKO owes her life to you!\p"
	.string "They call me MR. BRINEY.\n"
	.string "And, you are?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
	.string "I sincerely thank you!\p"
	.string "Now, if there's anything that troubles\n"
	.string "you, don't hesitate to tell me!\p"
	.string "You can usually find me in my cottage\n"
	.string "by the sea near PETALBURG WOODS.\p"
	.string "Come, PEEKO, we should make our way\n"
	.string "home.\p"
	.string "PEEKO: Pihyoh!$"
#endif

RusturfTunnel_Text_WhyCantTheyKeepDigging:
#if GERMAN
	.string "… …\p"
	.string "Warum graben sie nicht weiter?\n"
	.string "Ist das Gestein zu hart?\p"
	.string "Meine Geliebte wartet in Wiesenflur auf\n"
	.string "mich, gleich hinter diesen Felsen…\p"
	.string "Wenn Metarost City und Wiesenflur\n"
	.string "durch diesen Tunnel verbunden wären,\l"
	.string "könnte ich sie jeden Tag besuchen!\p"
	.string "Aber so…\n"
	.string "Was soll ich nur machen?$"
#else
	.string "… …\p"
	.string "Why can't they keep digging?\n"
	.string "Is the bedrock too hard?\p"
	.string "My beloved awaits me in VERDANTURF\n"
	.string "TOWN just beyond here…\p"
	.string "If RUSTBORO and VERDANTURF were\n"
	.string "joined by this tunnel, I could visit\l"
	.string "her every day…\p"
	.string "But this…\n"
	.string "What am I to do?$"
#endif

RusturfTunnel_Text_ToGetToVerdanturf:
#if GERMAN
	.string "Um von Metarost City nach Wiesenflur zu\n"
	.string "gelangen, muss man nach Faustauhaven\l"
	.string "und dann über Graphitport City und\l"
	.string "Malvenfroh City reisen…$"
#else
	.string "To get from RUSTBORO to VERDANTURF,\n"
	.string "you need to go to DEWFORD, then pass\l"
	.string "through SLATEPORT and MAUVILLE…$"
#endif

RusturfTunnel_Text_YouShatteredBoulderTakeHM:
#if GERMAN
	.string "Wow! Du hast den Felsen, der den Weg\n"
	.string "blockierte, einfach zertrümmert.\p"
	.string "Darüber bin ich überglücklich und\n"
	.string "daher möchte ich dir diese VM geben.$"
#else
	.string "Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "To show you how much I appreciate it,\n"
	.string "I'd like you to have this HM.$"
#endif

RusturfTunnel_Text_ExplainStrength:
#if GERMAN
	.string "Diese VM enthält Stärke.\p"
	.string "Wenn ein kräftiges Pokémon diese VM\n"
	.string "lernt, ist es in der Lage, sogar die\l"
	.string "schwersten Felsen zu bewegen.$"
#else
	.string "That HM contains STRENGTH.\p"
	.string "If a muscular POKéMON were to learn\n"
	.string "that, it would be able to move even\l"
	.string "large boulders.$"
#endif

RusturfTunnel_Text_WandaReunion:
#if GERMAN
	.string "Heike!\n"
	.string "Nun kann ich dich jederzeit besuchen!\l"
	.string "\p"
	.string "Heike: Das ist… wunderbar.\p"
	.string "Bitte, ruh dich ein bisschen in meinem\n"
	.string "Haus aus.$"
#else
	.string "WANDA!\n"
	.string "Now I can see you anytime!\p"
	.string "WANDA: That's…wonderful.\p"
	.string "Please, take some rest at my home.$"
#endif

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
#if GERMAN
	.string "Auf der anderen Seite dieses Felsens\n"
	.string "wartet mein Freund.\p"
	.string "Er… Er gräbt den Tunnel nicht nur, um\n"
	.string "mich zu sehen.\p"
	.string "Er reißt sich die Hände auf zum Wohle\n"
	.string "aller.$"
#else
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"
#endif

RusturfTunnel_Text_MikeIntro:
#if GERMAN
	.string "Wie nennt man einen ungestümen Mann\n"
	.string "hoch im Gebirge? Einen Bergfreund.\p"
	.string "So, warum nennt man dann nicht auch ein\n"
	.string "Pokémon in den Bergen ein\l"
	.string "Berg-Pokémon?$"
#else
	.string "What do you call a wild man up in the\n"
	.string "mountains? A mountain man, right?\p"
	.string "So why don't they call a POKéMON in\n"
	.string "the mountains a mountain POKéMON?$"
#endif

RusturfTunnel_Text_MikeDefeat:
#if GERMAN
	.string "Meine Pokémon…\n"
	.string "Haben alle Energie verloren…$"
#else
	.string "My POKéMON…\n"
	.string "Ran out of power…$"
#endif

RusturfTunnel_Text_MikePostBattle:
#if GERMAN
	.string "Sie haben das Projekt hier eingestellt,\n"
	.string "um die Pokémon zu schützen, nicht wahr?\l"
	.string "Eine rührende Story.$"
#else
	.string "They halted development here to\n"
	.string "protect POKéMON, right?\l"
	.string "There's a feel-good story!$"
#endif

#if IS_HNS
@ Unused.
Text_HnsStrengthLicense:
#if GERMAN
	.string "{PLAYER} erhält die Lizenz für\n"
	.string "Stärke!$"
#else
	.string "{PLAYER} received the licence for\n"
	.string "STRENGTH!$"
#endif

Text_HnsShatteredBoulderNoHandover:
#if GERMAN
	.string "Wow! Du hast den Felsen, der den Weg\n"
	.string "blockierte, einfach zertrümmert.\p"
	.string "Darüber bin ich überglücklich!\p"
	.string "Schenken kann ich dir leider nichts,\n"
	.string "was du nicht längst besitzt.$"
#else
	.string "Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "I can't tell you how happy that\n"
	.string "makes me!\p"
	.string "I'm afraid I have nothing to give you\n"
	.string "that you don't already own.$"
#endif
#endif
