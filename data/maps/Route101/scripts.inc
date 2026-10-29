Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_ROUTE101_BIRCH, 0, 15
	setobjectxy LOCALID_ROUTE101_ZIGZAGOON, 0, 16
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_ROUTE101_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ROUTE101_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

#if IS_HNS
@ Steven's call about Hoenn's HM licenses, from four trigger tiles at the north exit.
Route101_EventScript_TroyLicenseCall::
	lockall
	setvar VAR_HOENN_ARRIVAL_STATE, 5
	pokenavcall Route101_Text_TroyLicenseCall
	waitmessage
	releaseall
	end

Route101_Text_TroyLicenseCall:
#if GERMAN
	.string "Troy: Hallo, {PLAYER}! Prof. Birk\n"
	.string "hat mir gesagt, dass du in Hoenn\l"
	.string "angekommen bist.\p"
	.string "Eine Sache, die für deine Reise\n"
	.string "wichtig ist: Um VMs draußen\l"
	.string "einsetzen zu können, brauchst du\l"
	.string "die jeweilige Erlaubnis dazu.\p"
	.string "Du wirst schon herausfinden, wo\n"
	.string "du sie herbekommst.\p"
	.string "Bis bald!$"
#else
	.string "STEVEN: Hello, {PLAYER}! PROF.\n"
	.string "BIRCH told me you've arrived in\l"
	.string "HOENN.\p"
	.string "One thing that matters on your\n"
	.string "journey: to use HMs outside of\l"
	.string "battle you need permission for\l"
	.string "each of them.\p"
	.string "You'll work out where to get it.\p"
	.string "See you soon!$"
#endif
#endif

Route101_EventScript_Youngster::
#if IS_HNS
	msgbox Route101_Text_HoennStrangerWarning, MSGBOX_NPC
	end
#endif
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROUTE101_ZIGZAGOON
	setobjectxy LOCALID_PLAYER, 6, 13
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_ROUTE101_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
#if GERMAN
	.string "Hi… Hiiiilfe!!!$"
#else
	.string "H-help me!$"
#endif

Route101_Text_PleaseHelp:
#if GERMAN
	.string "Hilfe!!! Du dort drüben!\n"
	.string "Bitte! Hilfe!!!\p"
	.string "In meinem Beutel…\n"
	.string "Da findest du einen Pokéball!$"
#else
	.string "Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my BAG!\n"
	.string "There's a POKé BALL!$"
#endif

Route101_Text_DontLeaveMe:
#if GERMAN
	.string "Wo-Wo wi-willst du hin?\n"
	.string "Lass mich nicht im Stich!!!$"
#else
	.string "Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"
#endif

Route101_Text_YouSavedMe:
#if GERMAN
	.string "Prof. Birk: Puuuh…\p"
	.string "Ich habe im hohen Gras Pokémon\n"
	.string "studiert, als ich angesprungen wurde.\l"
	.string "\p"
	.string "Du hast mich gerettet.\n"
	.string "Vielen, vielen Dank!\p"
	.string "Oh?\p"
	.string "Hi, du bist doch {PLAYER}{KUN}!\p"
	.string "Aber dies ist nicht der Ort für ein\n"
	.string "Schwätzchen, komm doch mit in mein\l"
	.string "Pokémon-Labor, okay?$"
#else
	.string "PROF. BIRCH: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "POKéMON when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {PLAYER}{KUN}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my POKéMON LAB later, okay?$"
#endif

Route101_Text_HoennStrangerWarning:
#if GERMAN
	.string "Dich habe ich hier noch nie gesehen.\p"
	.string "Pass bloß auf - die Pokémon in Hoenn\n"
	.string "sind viel stärker als die vom Festland.$"
#else
	.string "I've never seen you around here.\p"
	.string "Be careful - the POKéMON in HOENN\n"
	.string "are much stronger than back home.$"
#endif

Route101_Text_TakeTiredPokemonToPokeCenter:
#if GERMAN
	.string "Sind deine Pokémon müde, bring sie in\n"
	.string "ein Pokémon-Center.\p"
	.string "In Rosaltstadt, gleich hier um die\n"
	.string "Ecke, gibt es ein Pokémon-Center.$"
#else
	.string "If POKéMON get tired, take them to\n"
	.string "a POKéMON CENTER.\p"
	.string "There's a POKéMON CENTER in OLDALE\n"
	.string "TOWN right close by.$"
#endif

Route101_Text_WildPokemonInTallGrass:
#if GERMAN
	.string "Wilde Pokémon springen dich in hohem\n"
	.string "Gras gerne an.\p"
	.string "Wenn du Pokémon fangen willst, musst\n"
	.string "du ins hohe Gras gehen und sie suchen.$"
#else
	.string "Wild POKéMON will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch POKéMON, you have\n"
	.string "to go into the tall grass and search.$"
#endif

Route101_Text_RouteSign:
#if GERMAN
	.string "Route 101\n"
	.string "{UP_ARROW} Rosaltstadt$"
#else
	.string "ROUTE 101\n"
	.string "{UP_ARROW} OLDALE TOWN$"
#endif

