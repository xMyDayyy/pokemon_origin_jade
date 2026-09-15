@ HnS: In Hoenn braucht jede Feldattacke eine Erlaubnis (src/hoenn_licenses.c),
@ in Johto eine Befugnis (src/johto_permits.c). Vor dem Aufruf den Index in
@ VAR_0x8004 legen; Ergebnis FALSE heisst "hier nicht erlaubt". Ausserhalb
@ beider Regionen immer TRUE.
EventScript_NoDiveLicense::
	lockall
	playse SE_SELECT
	buffermovename STR_VAR_1, MOVE_DIVE
	goto EventScript_NeedHoennLicense
	end

EventScript_NeedHoennLicense::
	@ Das Wort kommt aus der Region: Erlaubnis in Hoenn, Befugnis in Johto.
	special BufferFieldPermissionTerm
	msgbox Text_NeedHoennLicense, MSGBOX_DEFAULT
	releaseall
	end

Text_NeedHoennLicense:
#if GERMAN
	.string "Mit einer {STR_VAR_2} könnte man hier\n"
	.string "{STR_VAR_1} einsetzen.$"
#else
	.string "With a {STR_VAR_2}, {STR_VAR_1} could be\n"
	.string "used here.$"
#endif

@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	buffermovename STR_VAR_1, MOVE_CUT
	setvar VAR_0x8004, LIC_CUT
	special CheckFieldPermission
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedHoennLicense
	@ HnS: die VM im Beutel genuegt, das Pokemon muss Zerschneider nicht koennen.
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CheckTreeCantCut
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_CutTreeCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	playse SE_M_CUT
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
#if GERMAN
	.string "Du kannst den Zerschneider hier\n"
	.string "einsetzen!\p"
	.string "Möchtest du den Zerschneider\n"
	.string "einsetzen?$"
#else
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"
#endif

Text_MonUsedFieldMove:
#if GERMAN
	.string "{STR_VAR_1} setzt {STR_VAR_2} ein.$"
#else
	.string "{STR_VAR_1} used {STR_VAR_2}!$"
#endif

Text_CantCut:
#if GERMAN
	.string "Der Zerschneider kann hier eingesetzt\n"
	.string "werden.$"
#else
	.string "This tree looks like it can be\n"
	.string "CUT down!$"
#endif

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	buffermovename STR_VAR_1, MOVE_ROCK_SMASH
	setvar VAR_0x8004, LIC_ROCK_SMASH
	special CheckFieldPermission
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedHoennLicense
	@ HnS: die VM im Beutel genuegt, das Pokemon muss Zertruemmerer nicht koennen.
	checkfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_RockSmashCommon:
	@ check if follower should use the field move
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	playse SE_M_ROCK_THROW
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	random 20
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	call_if_eq VAR_RESULT, 2, EventScript_RockSmashBlueShard
	call_if_eq VAR_RESULT, 3, EventScript_RockSmashRedShard
	call_if_eq VAR_RESULT, 4, EventScript_RockSmashGreenShard
	call_if_eq VAR_RESULT, 5, EventScript_RockSmashYellowShard
	releaseall
	end

@ Interact with headbutt tree
EventScript_Headbutt::
	lockall
	goto_if_unset FLAG_GET_HEADBUTT, EventScript_CantHeadbuttTree
	checkpartymove MOVE_HEADBUTT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantHeadbuttTree
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_MonUsedHeadbutt, MSGBOX_DEFAULT
	closemessage
EventScript_HeadbuttCommon:
	@ check if follower should use the field move
	isfollowerfieldmoveuser VAR_0x8004
EventScript_HeadbuttTree:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	applymovement VAR_LAST_TALKED, Movement_HeadbuttTree
	playse SE_M_HEADBUTT
	waitmovement 0
	special RockSmashWildEncounter
	goto EventScript_EndHeadbutt
	waitstate
	releaseall
	end


Movement_HeadbuttTree:
	rock_smash_break
	step_end

EventScript_CantHeadbuttTree::
	msgbox Text_CantHeadbutt, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelHeadbutt::
	closemessage
	releaseall
	end


EventScript_EndHeadbutt::
	releaseall
	end

Text_MonUsedHeadbutt::
#if GERMAN
	.string "{STR_VAR_1} benutzt Kopfnuss!$"
#else
	.string "{STR_VAR_1} used HEADBUTT!$"
#endif


EventScript_FollowerFieldMove:
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
	specialvar VAR_0x8006, GetPlayerFacingDirection
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return

EventScript_EndSmash::
	random 20
	call_if_eq VAR_RESULT, 1, EventScript_RockSmashHeartscale
	call_if_eq VAR_RESULT, 2, EventScript_RockSmashBlueShard
	call_if_eq VAR_RESULT, 3, EventScript_RockSmashRedShard
	call_if_eq VAR_RESULT, 4, EventScript_RockSmashGreenShard
	call_if_eq VAR_RESULT, 5, EventScript_RockSmashYellowShard
	releaseall
	end

EventScript_RockSmashHeartscale::
	giveitem ITEM_HEART_SCALE
	return

EventScript_RockSmashBlueShard::
	giveitem ITEM_BLUE_SHARD
	return

EventScript_RockSmashRedShard::
	giveitem ITEM_RED_SHARD
	return

EventScript_RockSmashGreenShard::
	giveitem ITEM_GREEN_SHARD
	return

EventScript_RockSmashYellowShard::
	giveitem ITEM_YELLOW_SHARD
	return

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	jump_in_place_up
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	jump_in_place_right
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	jump_in_place_down
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	jump_in_place_left
	step_end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
#if GERMAN
	.string "Dieser Fels sieht zerbrechlich aus.\n"
	.string "Soll Zertrümmerer eingesetzt werden?$"
#else
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"
#endif

Text_CantSmash:
#if GERMAN
	.string "Ein großer Felsen. Ein Pokémon könnte\n"
	.string "ihn vielleicht zertrümmern.$"
#else
	.string "It's a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"
#endif

Text_WantToHeadbutt:
#if GERMAN
	.string "In dem Baum könnte ein Pokémon leben.\n"
	.string "Möchtest du Kopfnuss verwenden?$"
#else
	.string "This tree may house POKéMON.\n"
	.string "Would you like to use HEADBUTT?$"
#endif

Text_CantHeadbutt:
#if GERMAN
	.string "Es ist ein kleiner Baum, aber ein\n"
	.string "Pokémon könnte darin leben.$"
#else
	.string "It's a small tree, but a wild\n"
	.string "POKéMON may be living within.$"
#endif

EventScript_StrengthBoulder::
	lockall
	buffermovename STR_VAR_1, MOVE_STRENGTH
	setvar VAR_0x8004, LIC_STRENGTH
	special CheckFieldPermission
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedHoennLicense
	@ HnS: Staerke haengt an der Hoenn-Erlaubnis, nicht am Johto-Orden.
	checkitem ITEM_HM_STRENGTH
	goto_if_eq VAR_RESULT, FALSE, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkfieldmove FIELD_MOVE_STRENGTH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	@closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
#if GERMAN
	.string "Ein Pokémon kann diesen Felsen\n"
	.string "vielleicht bewegen.\p"
	.string "Möchtest du Stärke einsetzen?$"
#else
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"
#endif

Text_MonUsedStrength:
#if GERMAN
	.string "{STR_VAR_1} setzt Stärke ein.\p"
	.string "Stärke von {STR_VAR_1} ermöglicht es,\n"
	.string "den Felsen zu bewegen.$"
#else
	.string "{STR_VAR_1} used STRENGTH!$"
#endif

Text_CantStrength:
#if GERMAN
	.string "Ein Pokémon kann diesen Felsen\n"
	.string "vielleicht bewegen.$"
#else
	.string "It's a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"
#endif

Text_StrengthActivated:
#if GERMAN
	.string "Stärke ermöglicht es, Felsen zu\n"
	.string "bewegen.$"
#else
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"
#endif

EventScript_UseWaterfall::
	lockall
	@ HnS: Kaskade haengt an der Hoenn-Erlaubnis, nicht am Johto-Orden.
	checkfieldmove FIELD_MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall
	buffermovename STR_VAR_1, MOVE_WATERFALL
	setvar VAR_0x8004, LIC_WATERFALL
	special CheckFieldPermission
	goto_if_eq VAR_RESULT, FALSE, EventScript_NeedHoennLicense

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
#if GERMAN
	.string "Das Wasser fällt steil wie eine Wand\n"
	.string "brüllend in die Tiefe.$"
#else
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"
#endif

Text_WantToWaterfall:
#if GERMAN
	.string "Ein riesiger Wasserfall.\n"
	.string "Möchtest du Kaskade einsetzen?$"
#else
	.string "It's a large waterfall.\n"
	.string "Would you like to use WATERFALL?$"
#endif

Text_MonUsedWaterfall:
#if GERMAN
	.string "{STR_VAR_1} setzt Kaskade ein.$"
#else
	.string "{STR_VAR_1} used WATERFALL.$"
#endif

EventScript_UseDive::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

@HnS
EventScript_Whirlpool::
	lockall
	goto_if_unset FLAG_BADGE07_GET, EventScript_CantWhirlpool
	@checkpartymove MOVE_WHIRLPOOL @checkpartymove doesn't work for the 8th hm i guess.
	@goto_if_eq VAR_RESULT, FALSE, EventScript_CantWhirlpool
	playse SE_M_WATERFALL
	goto_if_eq VAR_FACING, DIR_NORTH, EventScript_WhirlpoolGoNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, EventScript_WhirlpoolGoSouth
	goto_if_eq VAR_FACING, DIR_EAST, EventScript_WhirlpoolGoEast
	goto_if_eq VAR_FACING, DIR_WEST, EventScript_WhirlpoolGoWest
	releaseall
	end

EventScript_WhirlpoolGoNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolNorth
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoSouth::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolSouth
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoEast::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolEast
	waitmovement 0
	releaseall
	end

EventScript_WhirlpoolGoWest::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WhirlpoolWest
	waitmovement 0
	releaseall
	end

EventScript_CantWhirlpool::
	msgbox Text_CantWhirlpool, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

Movement_WhirlpoolNorth:
	slide_up
	slide_up
	slide_up
	step_end

Movement_WhirlpoolSouth:
	slide_down
	slide_down
	slide_down
	step_end

Movement_WhirlpoolEast:
	slide_right
	slide_right
	slide_right
	step_end

Movement_WhirlpoolWest:
	slide_left
	slide_left
	slide_left
	step_end

Text_CantWhirlpool:
#if GERMAN
	.string "Ein strömender Strudel, laut und\n"
	.string "kräftig.$"
#else
	.string "The water is swirling and spinning\n"
	.string "around with a mighty roar.$"
#endif

Text_CantDive:
#if GERMAN
	.string "Das Wasser ist hier tief. Ein Pokémon\n"
	.string "könnte hier vielleicht tauchen.$"
#else
	.string "The sea is deep here. A POKéMON\n"
	.string "may be able to go underwater.$"
#endif

Text_WantToDive:
#if GERMAN
	.string "Das Meer ist an dieser Stelle sehr tief.\n"
	.string "Möchtest du Taucher einsetzen?$"
#else
	.string "The sea is deep here.\n"
	.string "Would you like to use DIVE?$"
#endif

Text_MonUsedDive:
#if GERMAN
	.string "{STR_VAR_1} setzt Taucher ein.$"
#else
	.string "{STR_VAR_1} used WHIRLPOOL.$"
#endif

Text_CantSurface:
#if GERMAN
	.string "Licht schimmert von oben herab. Ein\n"
	.string "Pokémon könnte hier auftauchen.$"
#else
	.string "Light is filtering down from above.\n"
	.string "A POKéMON may be able to surface.$"
#endif

Text_WantToSurface:
#if GERMAN
	.string "Licht schimmert von oben herab.\n"
	.string "Möchtest du Taucher einsetzen?$"
#else
	.string "Light is filtering down from above.\n"
	.string "Would you like to use DIVE?$"
#endif

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
#if GERMAN
	.string "Hier scheint nichts zu sein…$"
#else
	.string "Looks like there's nothing here…$"
#endif

EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_DIG
	waitstate
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon


EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon

EventScript_UseDefog::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_DEFOG
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	waitmovement 0
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_DEFOG
	waitstate
	releaseall
	end

EventScript_UseRockClimb::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_CLIMB
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantRockClimb
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
	msgbox Text_MonUsedRockClimb, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
	waitstate
	goto EventScript_EndRockClimb
	end

EventScript_CantRockClimb::
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT

EventScript_EndRockClimb::
	releaseall
	end

Text_WantToRockClimb:
#if GERMAN
    .string "Eine steile Klippe.\n"
    .string "Möchtest du Kraxler einsetzen?$"
#else
	.string "The cliff is steep.\n"
	.string "Would you like to use Rock Climb?$"
#endif

Text_MonUsedRockClimb:
#if GERMAN
    .string "{STR_VAR_1} benutzt Kraxler!$"
#else
	.string "{STR_VAR_1} used Rock Climb!$"
#endif

Text_CantRockClimb:
#if GERMAN
    .string "Eine steile Klippe.\n"
    .string "Ein Pokémon könnte sie erklimmen.$"
#else
	.string "The cliff is steep.\n"
	.string "A Pokémon may be able to climb it.$"
#endif

SetTimeEncounters::
	callnative SetTimeBasedEncounters
	return
