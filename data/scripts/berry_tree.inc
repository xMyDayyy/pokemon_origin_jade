#if IS_HNS

@ Origin Jade: Hoenn uses the Emerald berry system (lower part of the file),
@ Johto and Kanto the HGSS one.
BerryTreeScript::
	specialvar VAR_RESULT, IsPlayerInHoenn
	goto_if_eq VAR_RESULT, TRUE, BerryTreeScript_Emerald
	goto BerryTreeScript_Hns
	end

BerryTreeScript_Hns::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Hns_NotRipe
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_Hns_NotRipe
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_Hns_NotRipe
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_Hns_NotRipe
	case BERRY_STAGE_TALLER, BerryTree_EventScript_Hns_NotRipe
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_Hns_NotRipe
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_Hns_FullyGrown
	end

BerryTree_EventScript_Hns_NotRipe::
	lock
	message BerryTree_Text_Hns_NotRipe
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_Hns_FullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	goto BerryTree_EventScript_Hns_PickBerry

BerryTree_EventScript_Hns_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_Hns_BagFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_Hns_Picked
	playfanfare MUS_OBTAIN_BERRY
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	waitmessage
	waitfanfare
	release
	end

BerryTree_EventScript_Hns_BagFull::
	message BerryTree_Text_Hns_BagFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_Hns_Sprout::
	message BerryTree_Text_Hns_Sprouted
	waitmessage
	callnative Berry_Ready
	waitbuttonpress
	release
	end

@ Unused, the item entry points are in the Emerald part below.
BerryTree_EventScript_ItemUsePlantBerry_HnsUnused::
	end

BerryTree_EventScript_ItemUseWailmerPail_HnsUnused::
	end

BerryTree_Text_Hns_NotRipe:
#if GERMAN
	.string "Ein Strauß Beeren!\n"
	.string "Diese Beeren sind noch nicht reif.$"
#else
	.string "It's a BERRY tree!\n"
	.string "These BERRIES aren't ripe yet.$"
#endif

BerryTree_Text_Hns_Picked:
#if GERMAN
	.string "{PLAYER} pflückt die {STR_VAR_2} {STR_VAR_1}.$"
#else
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"
#endif

BerryTree_Text_Hns_BagFull:
#if GERMAN
	.string "Die Beerentasche des Beutels ist voll.\p"
	.string "Die {STR_VAR_1} können nicht mitgenommen\n"
	.string "werden.$"
#else
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"
#endif

BerryTree_Text_Hns_Sprouted:
#if GERMAN
	.string "Die Beeren sprießen plötzlich!$"
#else
	.string "The berry tree suddenly sprouted!$"
#endif

BerryTreeScript_Emerald::
#else
BerryTreeScript::
#endif
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_Sparkling
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_CheckSoil
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_CheckBerryStage1
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_CheckBerryStage2
	case BERRY_STAGE_TALLER, BerryTree_EventScript_CheckBerryStage3
	case BERRY_STAGE_TRUNK, BerryTree_EventScript_CheckBerryStageTrunk
	case BERRY_STAGE_BUDDING, BerryTree_EventScript_CheckBerryStageBudding
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_CheckBerryStage4
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_Sparkling::
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil::
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToPlant
	specialvar VAR_RESULT, PlayerHasMulch
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToMulch
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_WantToPlant::
	specialvar VAR_RESULT, PlayerHasMulch
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WantToPlantMulch
	msgbox BerryTree_Text_WantToPlant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_ChooseBerryToPlant
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPlanting
	end

BerryTree_EventScript_WantToMulch::
.if OW_BERRY_MULCH_USAGE == TRUE
	msgbox BerryTree_Text_WantToMulch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_ChooseMulchToUse
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPlanting
.endif
	end

BerryTree_EventScript_WantToPlantMulch::
.if OW_BERRY_MULCH_USAGE == TRUE
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	multichoice 0, 0, MULTI_BERRY_PLOT, FALSE
	switch VAR_RESULT
	case 0, BerryTree_EventScript_ChooseMulchToUse
	case 1, BerryTree_EventScript_ChooseBerryToPlant
	case 2, BerryTree_EventScript_CancelPlanting
	case MULTI_B_PRESSED, BerryTree_EventScript_CancelPlanting

BerryTree_EventScript_ChooseMulchToUse::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseMulch
	waitstate
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_UseMulch
.endif

BerryTree_EventScript_ChooseBerryToPlant::
	fadescreen FADE_TO_BLACK
	closemessage
	special Bag_ChooseBerry
	waitstate
	goto_if_eq VAR_ITEM_ID, 0, BerryTree_EventScript_CancelPlanting
	removeitem VAR_ITEM_ID
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting::
	release
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	special ObjectEventInteractionGetBerryCountString
	message BerryTree_Text_BerryGrowthStage1
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage2::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage2
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage3::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage3
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStageTrunk::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStageTrunk
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStageBudding::
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStageBudding
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

BerryTree_EventScript_CheckBerryStage4::
	call BerryTree_EventScript_GetCareAdverb
	lockall
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_BerryGrowthStage4
	waitmessage
	waitbuttonpress
	goto BerryTree_EventScript_WantToWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbGreat
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	special ObjectEventInteractionGetBerryCountString
.if OW_BERRY_MUTATIONS == TRUE
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_CheckBerryFullyGrown_Mutation
.endif
	msgbox BerryTree_Text_WantToPick, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry

.set BERRY_NORMAL_BAG_FULL, 0
.set BERRY_NORMAL_SPACE_IN_BAG, 1
.set BERRY_MUTATION_BAG_FULL, 2
.set BERRY_MUTATION_SPACE_IN_BAG, 3

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, BERRY_NORMAL_BAG_FULL, BerryTree_EventScript_BerryPocketFull
.if OW_BERRY_MUTATIONS == TRUE
	goto_if_eq VAR_0x8004, BERRY_MUTATION_BAG_FULL, BerryTree_EventScript_BerryPocketFull_Mutation
	goto_if_eq VAR_0x8004, BERRY_MUTATION_SPACE_IN_BAG, BerryTree_EventScript_PickBerry_Mutation
.endif
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	delay 10
	showberrydescription
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry
	waitmessage
	waitbuttonpress
	hideitemdescription
	release
	end

BerryTree_EventScript_BerryPocketFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_CancelPickingBerry::
	message BerryTree_Text_BerryLeftUnpicked
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry::
	lockall
#if IS_HNS
	@ Origin Jade: planting only in Hoenn.
	specialvar VAR_RESULT, IsPlayerInHoenn
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_ItemUseNoEffectHns
#endif
	special ObjectEventInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

#if IS_HNS
BerryTree_EventScript_ItemUseNoEffectHns::
	releaseall
	end
#endif

BerryTree_EventScript_WantToWater::
.if OW_BERRY_PESTS == TRUE
	call BerryTree_EventScript_CheckForPests
.endif
.if OW_BERRY_WEEDS == TRUE
	call BerryTree_EventScript_CheckForWeed
.endif
	checkitem ITEM_WAILMER_PAIL
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	specialvar VAR_RESULT, CanWaterBerryPlot
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_DontWater
	special ObjectEventInteractionGetBerryName
	msgbox BerryTree_Text_WantToWater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_WaterBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_DontWater

BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail::
	special ObjectEventInteractionGetBerryTreeData
	lockall
#if IS_HNS
	@ Origin Jade: watering only in Hoenn.
	specialvar VAR_RESULT, IsPlayerInHoenn
	goto_if_eq VAR_RESULT, FALSE, BerryTree_EventScript_ItemUseNoEffectHns
#endif
BerryTree_EventScript_WaterBerry::
	special ObjectEventInteractionGetBerryName
	message BerryTree_Text_WateredTheBerry
	waitmessage
	special ObjectEventInteractionWaterBerryTree
	special DoWateringBerryTreeAnim
	waitstate
	message BerryTree_Text_PlantIsDelighted
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	special ObjectEventInteractionGetBerryCountString
	message BerryTree_Text_PlantedOneBerry
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_ItsSoftLoamySoil:
#if GERMAN
	.string "Das ist weicher Lehmboden.$"
#else
	.string "It's soft, loamy soil.$"
#endif

BerryTree_Text_WantToPlant:
#if GERMAN
	.string "Das ist weicher Lehmboden.\n"
	.string "Möchtest du eine Beere pflanzen?$"
#else
	.string "It's soft, loamy soil.\n"
	.string "Want to plant a BERRY?$"
#endif

BerryTree_Text_PlantedOneBerry:
#if GERMAN
	.string "{PLAYER} pflanzt eine {STR_VAR_1} in den\n"
	.string "Lehmboden.$"
#else
	.string "{PLAYER} planted one {STR_VAR_1} in\n"
	.string "the soft, loamy soil.$"
#endif

BerryTree_Text_BerryGrowthStage1:
.if OW_BERRY_SIX_STAGES == TRUE
#if GERMAN
	.string "Hier hast du die {STR_VAR_1}\n"
	.string "gepflanzt!$"
#else
	.string "This is where you planted the\n{STR_VAR_1}!$"
#endif
.else
#if GERMAN
	.string "Eine {STR_VAR_1} wurde\n"
	.string "hier gepflanzt.$"
#else
	.string "One {STR_VAR_1} was planted here.$"
#endif
.endif

BerryTree_Text_BerryGrowthStage2:
.if OW_BERRY_SIX_STAGES == TRUE
#if GERMAN
	.string "Die {STR_VAR_1} sprießt!$"
#else
	.string "The {STR_VAR_1} is sprouting!$"
#endif
.else
#if GERMAN
	.string "{STR_VAR_1} blüht auf.$"
#else
	.string "{STR_VAR_1} has sprouted.$"
#endif
.endif

BerryTree_Text_BerryGrowthStage3:
.if OW_BERRY_SIX_STAGES == TRUE
#if GERMAN
	.string "Der {STR_VAR_1}-Setzling\n"
	.string "wächst gut!$"
#else
	.string "The {STR_VAR_1}'s seedling is growing well!$"
#endif
.else
#if GERMAN
	.string "Die {STR_VAR_1}-Pflanze wächst.$"
#else
	.string "This {STR_VAR_1} plant is growing taller.$"
#endif
.endif

BerryTree_Text_BerryGrowthStageTrunk:
#if GERMAN
	.string "Der {STR_VAR_1}-Stamm wird dicker!$"
#else
	.string "The {STR_VAR_1}'s trunk is getting bigger!$"
#endif

BerryTree_Text_BerryGrowthStageBudding:
#if GERMAN
	.string "Der {STR_VAR_1}-Baum hat Knospen!$"
#else
	.string "The {STR_VAR_1} tree has buds!$"
#endif

BerryTree_Text_BerryGrowthStage4:
.if OW_BERRY_SIX_STAGES == TRUE
#if GERMAN
	.string "Der {STR_VAR_1}-Baum\n"
	.string "steht in Blüte!$"
#else
	.string "The {STR_VAR_1} tree is in bloom!$"
#endif
.else
#if GERMAN
	.string "Diese {STR_VAR_1}-Blumen sind\n"
	.string "{STR_VAR_2}.$"
#else
	.string "These {STR_VAR_1} flowers are blooming\n"
	.string "{STR_VAR_2}.$"
#endif
.endif

BerryTree_Text_CareAdverbGreat:
#if GERMAN
	.string "wunderschön$"
#else
	.string "very beautifully$"
#endif

BerryTree_Text_CareAdverbPoor:
#if GERMAN
	.string "zierlich$"
#else
	.string "cutely$"
#endif

BerryTree_Text_CareAdverbGood:
#if GERMAN
	.string "hübsch$"
#else
	.string "prettily$"
#endif

BerryTree_Text_WantToPick:
#if GERMAN
	.string "{STR_VAR_2} {STR_VAR_1}!\p"
	.string "Möchtest du die {STR_VAR_1} pflücken?$"
#else
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"
#endif

BerryTree_Text_PickedTheBerry:
#if GERMAN
	.string "{PLAYER} pflückt die {STR_VAR_2} {STR_VAR_1}.$"
#else
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"
#endif

BerryTree_Text_PutAwayBerry:
#if GERMAN
	.string "{PLAYER} packt die {STR_VAR_1}\n"
	.string "in die Beerentasche des Beutels.\p"
	.string "Der Boden ist wieder weich und lehmig.$"
#else
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "in the BAG's BERRIES POCKET.\p"
	.string "The soil returned to its soft and\n"
	.string "loamy state.$"
#endif

BerryTree_Text_BerryPocketFull:
#if GERMAN
	.string "Die Beerentasche des Beutels ist voll.\p"
	.string "Die {STR_VAR_1} können nicht mitgenommen\n"
	.string "werden.$"
#else
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn't be taken.$"
#endif

BerryTree_Text_BerryLeftUnpicked:
#if GERMAN
	.string "{PLAYER} pflückt keine {STR_VAR_1}.$"
#else
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"
#endif

BerryTree_Text_WantToWater:
#if GERMAN
	.string "Möchtest du die {STR_VAR_1} mit der\n"
	.string "Wailmerkanne gießen?$"
#else
	.string "Want to water the {STR_VAR_1} with the\n"
	.string "WAILMER PAIL?$"
#endif

BerryTree_Text_WateredTheBerry:
#if GERMAN
	.string "{PLAYER} gießt die {STR_VAR_1}.$"
#else
	.string "{PLAYER} watered the {STR_VAR_1}.$"
#endif

BerryTree_Text_PlantIsDelighted:
#if GERMAN
	.string "Die Pflanze scheint sich zu freuen.$"
#else
	.string "The plant seems to be delighted.$"
#endif

BerryTree_Text_ExclamationPoint:
	.string "!$"

.if OW_BERRY_MUTATIONS == TRUE
BerryTree_EventScript_CheckBerryFullyGrown_Mutation:
	msgbox BerryTree_Text_WantToPick_Mutation, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PickBerry
	goto_if_eq VAR_RESULT, NO, BerryTree_EventScript_CancelPickingBerry_Mutation

BerryTree_EventScript_CancelPickingBerry_Mutation::
	message BerryTree_Text_BerryLeftUnpicked_Mutation
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_BerryPocketFull_Mutation::
	message BerryTree_Text_BerryPocketFull_Mutation
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_PickBerry_Mutation::
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry_Mutation
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	waitbuttonpress
	message BerryTree_Text_PutAwayBerry_Mutation
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_Text_WantToPick_Mutation:
#if GERMAN
	.string "Du findest {STR_VAR_2} {STR_VAR_1}\n"
	.string "und 1 {STR_VAR_3}!\p"
	.string "Möchtest du sie pflücken?$"
#else
	.string "You found {STR_VAR_2} {STR_VAR_1}\n"
	.string "and 1 {STR_VAR_3}!\p"
	.string "Do you want to pick them?$"
#endif

BerryTree_Text_BerryLeftUnpicked_Mutation:
#if GERMAN
	.string "{PLAYER} lässt {STR_VAR_1} und die\n"
	.string "{STR_VAR_3} zurück.$"
#else
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "and the {STR_VAR_3} unpicked.$"
#endif

BerryTree_Text_BerryPocketFull_Mutation:
#if GERMAN
	.string "Die Beeren-Tasche ist voll.\p"
	.string "Die {STR_VAR_1} und die {STR_VAR_3} bleiben\n"
	.string "zurück.$"
#else
	.string "The BAG's BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} and the\n"
	.string "{STR_VAR_3} couldn't be taken.$"
#endif

BerryTree_Text_PickedTheBerry_Mutation:
#if GERMAN
	.string "{PLAYER} pflückt {STR_VAR_2} {STR_VAR_1}\n"
	.string "und die {STR_VAR_3}.$"
#else
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}\n"
	.string "and the {STR_VAR_3}.$"
#endif

BerryTree_Text_PutAwayBerry_Mutation:
#if GERMAN
	.string "{PLAYER} verstaut die {STR_VAR_1} und die\n"
	.string "{STR_VAR_3} in der Beerentasche.\p"
	.string "Der Boden ist wieder weich und lehmig.$"
#else
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "and the {STR_VAR_3} in the BAG's\l"
	.string "BERRIES POCKET.\p"
	.string "The soil returned to its soft and\n"
	.string "loamy state.$"
#endif
.endif

.if OW_BERRY_MULCH_USAGE == TRUE
BerryTree_EventScript_UseMulch::
	special ObjectEventInteractionApplyMulch
	message BerryTree_Text_ScatteredMulch
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_WantToMulch:
#if GERMAN
	.string "Es ist lehmiger Boden.\n"
	.string "Dünger verwenden?$"
#else
	.string "It's soft, loamy soil.\n"
	.string "Put down some fertilizer?$"
#endif

BerryTree_Text_ScatteredMulch:
#if GERMAN
	.string "{PLAYER} verstreut die {STR_VAR_1}\n"
	.string "auf dem weichen Boden.$"
#else
	.string "{PLAYER} scattered the {STR_VAR_1}\n"
	.string "on the soft, loamy soil.$"
#endif
.endif

.if OW_BERRY_WEEDS == TRUE
BerryTree_EventScript_CheckForWeed::
	specialvar VAR_RESULT, ObjectEventInteractionBerryHasWeed
	call_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_WeedIsGrowing
	return

BerryTree_EventScript_WeedIsGrowing::
	msgbox BerryTree_Text_WeedIsGrowing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, BerryTree_EventScript_PullOutWeed
	return

BerryTree_EventScript_PullOutWeed::
	special ObjectEventInteractionPullBerryWeed
	message BerryTree_Text_PulledOutTheWeed
	waitmessage
	waitbuttonpress
	return

BerryTree_Text_WeedIsGrowing:
#if GERMAN
	.string "Unkraut wächst hier.\n"
	.string "Möchtest du es herausziehen?$"
#else
	.string "A weed is growing here.\n"
	.string "Do you want to pull it out?$"
#endif

BerryTree_Text_PulledOutTheWeed:
#if GERMAN
	.string "{PLAYER} zieht das Unkraut heraus!$"
#else
	.string "{PLAYER} pulled out the weed!$"
#endif
.endif

.if OW_BERRY_PESTS == TRUE
BerryTree_EventScript_CheckForPests::
	specialvar VAR_RESULT, ObjectEventInteractionBerryHasPests
	call_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_EncounterPests
	return

BerryTree_EventScript_EncounterPests::
	message BerryTree_Text_APokemonAppeared
	waitmessage
	waitbuttonpress
	dowildbattle
	return

BerryTree_Text_APokemonAppeared:
#if GERMAN
	.string "Ein Pokémon erscheint!$"
#else
	.string "A Pokémon appeared!$"
#endif
.endif
