UnionCave_1F_hns_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL_HNS, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY_HNS, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL_HNS, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL_HNS, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY_HNS, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
#if GERMAN
	.string "Du willst nach Azalea City, oder?\p"
	.string "Meine Pokémon sollen prüfen, ob du\n"
	.string "stark genug für einen Kampf bist.$"
#else
	.string "You're headed to AZALEA, are you?\p"
	.string "Let my POKéMON see if you are good\n"
	.string "enough to battle.$"
#endif

UnionCave_1F_Text_HikerRussellBeaten:
#if GERMAN
	.string "Oh, oh, oh!$"
#else
	.string "Oh, oh, oh!$"
#endif

UnionCave_1F_Text_HikerRussellAfter:
#if GERMAN
	.string "Also gut, ich habe mich entschieden.\p"
	.string "Ich gehe hier erst weg, wenn meine\n"
	.string "Pokémon stärker geworden sind!$"
#else
	.string "All right, then! I've decided.\p"
	.string "I'm not leaving until my POKéMON\n"
	.string "get tougher!$"
#endif

UnionCave_1F_Text_PokemaniacLarrySeen:
#if GERMAN
	.string "Ich ziehe weit umher, immer auf der\n"
	.string "Suche nach Pokémon.\p"
	.string "Suchst du etwa auch nach Pokémon?\p"
	.string "Dann bist du mein Sammelrivale!$"
#else
	.string "I roam far and wide in search of\n"
	.string "POKéMON.\p"
	.string "Are you looking for POKéMON too?\p"
	.string "Then you're my collecting rival!$"
#endif

UnionCave_1F_Text_PokemaniacLarryBeaten:
#if GERMAN
	.string "Ach… Meine armen Pokémon…$"
#else
	.string "Ugh. My poor POKéMON…$"
#endif

UnionCave_1F_Text_PokemaniacLarryAfter:
#if GERMAN
	.string "Manchmal hört man tief drinnen in der\n"
	.string "Höhle Pokémon brüllen.$"
#else
	.string "Sometimes, you can hear POKéMON\n"
	.string "roars from deep inside the cave.$"
#endif

UnionCave_1F_Text_HikerDanielSeen:
#if GERMAN
	.string "Huch! Was für eine Überraschung!\p"
	.string "Ich hätte nicht gedacht, dass hier\n"
	.string "jemand vorbeikommt!$"
#else
	.string "Whoa! What a surprise!\p"
	.string "I didn't expect to see anyone here!$"
#endif

UnionCave_1F_Text_HikerDanielBeaten:
#if GERMAN
	.string "Huch! Das war eine klare Niederlage!$"
#else
	.string "Whoa! I'm beaten big time!$"
#endif

UnionCave_1F_Text_HikerDanielAfter:
#if GERMAN
	.string "Man hat mir eine Flegmon-Rute\n"
	.string "angedreht.\p"
	.string "Das arme Pokémon tut mir so leid.$"
#else
	.string "I was conned into buying a\n"
	.string "SLOWPOKETAIL.\p"
	.string "I feel sorry for the poor POKéMON.$"
#endif

UnionCave_1F_Text_FirebreatherBillSeen:
#if GERMAN
	.string "Die Superschall-Attacke von Zubat\n"
	.string "verwirrt meine Pokémon ständig.\p"
	.string "Das regt mich richtig auf!$"
#else
	.string "ZUBAT's SUPERSONIC keeps confusing\n"
	.string "my POKéMON.\p"
	.string "I'm seriously upset about that!$"
#endif

UnionCave_1F_Text_FirebreatherBillBeaten:
#if GERMAN
	.string "Ich bin ausgebrannt!$"
#else
	.string "I flamed out!$"
#endif

UnionCave_1F_Text_FirebreatherBillAfter:
#if GERMAN
	.string "Am Wochenende hört man tief aus der\n"
	.string "Höhle ein seltsames Gebrüll.$"
#else
	.string "On weekends, you can hear strange\n"
	.string "roars from deep in the cave.$"
#endif

UnionCave_1F_Text_FirebreatherRaySeen:
#if GERMAN
	.string "Ist es hell, ist eine Höhle nicht\n"
	.string "unheimlich.\p"
	.string "Ist man stark, sind Pokémon nicht\n"
	.string "unheimlich.$"
#else
	.string "If it's light, a cave isn't scary.\p"
	.string "If you're strong, POKéMON aren't\n"
	.string "scary.$"
#endif

UnionCave_1F_Text_FirebreatherRayBeaten:
#if GERMAN
	.string "Blitz!$"
#else
	.string "FLASH!$"
#endif

UnionCave_1F_Text_FirebreatherRayAfter:
#if GERMAN
	.string "Das Feuer meiner Pokémon erhellt\n"
	.string "diese Höhle.$"
#else
	.string "It's my POKéMON's fire that lights\n"
	.string "up this cave.$"
#endif
