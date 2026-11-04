@ ============================================================
@ Crossing to Hoenn and arrival at Professor Birch's
@ ============================================================

@ Called from the ports and islands as soon as the player picks Hoenn. Every trip lands on the
@ Route 104 pier. Only the first trip sets the intro's end state and arms Birch's greeting.
@ See docs/origin_jade/DECISIONS.md, D-029 and D-047.
Common_EventScript_SailToHoenn::
	goto_if_lt VAR_HOENN_TICKET_STATE, 3, Common_EventScript_HoennNoTicket
	call Common_EventScript_CheckShipToHoenn
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShipMenuCancel
	closemessage
	delay 20
	msgbox Common_Text_HoennSetSail, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	goto_if_ne VAR_HOENN_ARRIVAL_STATE, 0, Common_EventScript_SailToHoennAgain
	call Common_EventScript_HoennSkipIntro
	setflag FLAG_HIDE_ROUTE104_HOENN_BIRCH
	setvar VAR_HOENN_ARRIVAL_STATE, 1
Common_EventScript_SailToRoute104Pier::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_LAB
	warpsilent MAP_ROUTE104, 12, 52
	waitstate
	release
	end

@ State 1: Birch's greeting still waits behind the pier. From state 2 until Wally's catching
@ tutorial is done (VAR_PETALBURG_CITY_STATE 3 or more, also set by his battle in Mauville)
@ Route 104 sends the player on to the lab, so the ship does not skip Petalburg City.
Common_EventScript_SailToHoennAgain::
	goto_if_lt VAR_HOENN_ARRIVAL_STATE, 2, Common_EventScript_SailToRoute104Pier
	goto_if_ge VAR_PETALBURG_CITY_STATE, 3, Common_EventScript_SailToRoute104Pier
	setflag FLAG_HOENN_SHIP_TO_BIRCHS_LAB
	goto Common_EventScript_SailToRoute104Pier

@ Later trips go to Slateport's or Lilycove's harbour and change no Hoenn state.
Common_EventScript_SailToSlateport::
	call Common_EventScript_CheckShipToSlateport
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShipMenuCancel
	closemessage
	delay 20
	msgbox Common_Text_SetSailSlateport, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	warpsilent MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

Common_EventScript_SailToLilycove::
	call Common_EventScript_CheckShipToLilycove
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShipMenuCancel
	closemessage
	delay 20
	msgbox Common_Text_SetSailLilycove, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	warpsilent MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

Common_EventScript_ShipMenuCancel::
	closemessage
	release
	end

Common_EventScript_HoennNoTicket::
	closemessage
	delay 20
	msgbox Common_Text_HoennNeedTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

Common_Text_HoennNeedTicket:
#if GERMAN
	.string "Für die Überfahrt nach Hoenn brauchst\n"
	.string "du ein Ticket.\p"
	.string "Ohne das kann ich dich nicht\n"
	.string "mitnehmen. Tut mir leid!$"
#else
	.string "You need a ticket for the crossing\n"
	.string "to HOENN.\p"
	.string "Without one I can't take you\n"
	.string "along. Sorry!$"
#endif

@ Sets the end state of Emerald's intro.
Common_EventScript_HoennSkipIntro::
	call Common_EventScript_HoennHideStoryNpcs
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	@ May stays on Route 103 until her battle there.
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	setflag FLAG_SET_WALL_CLOCK
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setflag FLAG_MET_RIVAL_MOM
	setflag FLAG_BIRCH_AIDE_MET
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	goto Common_EventScript_HoennSkipIntroStates

@ Copy of EventScript_ResetAllMapFlags (new_game.inc) with Origin Jade changes.
Common_EventScript_HoennHideStoryNpcs::
	setflag FLAG_HIDE_CONTEST_POKE_BALL
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA
	@ Origin Jade: Wally stays visible, 2 = gym door closed.
	setvar VAR_PETALBURG_GYM_STATE, 2
	setflag FLAG_UNKNOWN_0x363
	setflag FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	@ Origin Jade: the fat man in Littleroot Town stays visible.
	@ Origin Jade: no Poke Mart tour in Oldale Town.
	setflag FLAG_HIDE_OLDALE_TOWN_MART_EMPLOYEE
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	setflag FLAG_HIDE_ROUTE_110_BIRCH
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	setflag FLAG_HIDE_FANCLUB_OLD_LADY
	setflag FLAG_HIDE_FANCLUB_BOY
	setflag FLAG_HIDE_FANCLUB_LITTLE_BOY
	setflag FLAG_HIDE_FANCLUB_LADY
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	setflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	setflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	setflag FLAG_HIDE_ROUTE_119_RIVAL
	setflag FLAG_HIDE_ROUTE_119_SCOTT
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	setflag FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN
	setflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	setflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_BRINEY
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	setflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2
	setflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_HIDE_BATTLE_TOWER_OPPONENT
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR
	setflag FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER
	setflag FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE
	setflag FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON
	setflag FLAG_UNKNOWN_0x393
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_SCOTT
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_HIDE_CHAMPIONS_ROOM_BIRCH
	setflag FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	setflag FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE
	setflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	setflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	setflag FLAG_HIDE_ROUTE_128_STEVEN
	setflag FLAG_HIDE_ROUTE_128_ARCHIE
	setflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	setflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	setflag FLAG_HIDE_ROUTE_101_BOY
	setflag FLAG_HIDE_PETALBURG_CITY_SCOTT
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_ROUTE_111_DESERT_FOSSIL
	setflag FLAG_HIDE_ROUTE_111_PLAYER_DESCENT
	setflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	setflag FLAG_HIDE_SKY_PILLAR_WALLACE
	setflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
	return

Common_EventScript_HoennSkipIntroStates::
	@ Littleroot TV shows the movie.
	setflag FLAG_SYS_TV_HOME
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_BIRCH_LAB_STATE, 5
	setvar VAR_ROUTE101_STATE, 3
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_BIRCH_STATE, 6
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE104_HOENN_BIRCH
	return

@ ------------------------------------------------------------
@ Arrival at the Route 104 beach
@ ------------------------------------------------------------
@ Coord triggers at x=15, not on the pier (elevation 4).
@ VAR_0x8008: 0 = lower lane (row 52), 1 = upper lane (row 51).
Route104_EventScript_HoennArrivalUpper::
	lockall
	setvar VAR_0x8008, 1
	goto Route104_EventScript_HoennArrivalScene

Route104_EventScript_HoennArrivalLower::
	lockall
	setvar VAR_0x8008, 0
	goto Route104_EventScript_HoennArrivalScene

Route104_EventScript_HoennArrivalScene::
	delay 20
	addobject LOCALID_HOENN_BIRCH
	applymovement LOCALID_HOENN_BIRCH, Common_Movement_HoennBirchLeaveHouse
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_HOENN_BIRCH, Common_Movement_HoennExclaim
	waitmovement 0
	delay 20
	goto_if_eq VAR_0x8008, 1, Route104_EventScript_HoennArrivalRunUpper
	applymovement LOCALID_HOENN_BIRCH, Common_Movement_HoennBirchRunLower
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HoennStopAndLook
	waitmovement 0
	goto Route104_EventScript_HoennArrivalTalk

Route104_EventScript_HoennArrivalRunUpper::
	applymovement LOCALID_HOENN_BIRCH, Common_Movement_HoennBirchRunUpper
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HoennFacePlayerRight
	waitmovement 0
	goto Route104_EventScript_HoennArrivalTalk

Route104_EventScript_HoennArrivalTalk::
	playbgm MUS_ENCOUNTER_MALE, FALSE
	msgbox Route104_Text_BirchGreeting, MSGBOX_DEFAULT
	closemessage
	delay 20
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_HOENN_BIRCH
	setvar VAR_HOENN_ARRIVAL_STATE, 2
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	releaseall
	end

@ Ship arrival with FLAG_HOENN_SHIP_TO_BIRCHS_LAB (Common_EventScript_SailToHoennAgain):
@ Route104_OnTransition arms VAR_TEMP_C, Route104_OnFrame warps from the pier into the lab.
@ Never armed by walking onto Route 104. Same lab tile as Birch's greeting.
Route104_EventScript_HoennArmShipToLab::
	clearflag FLAG_HOENN_SHIP_TO_BIRCHS_LAB
	setvar VAR_TEMP_C, 1
	return

Route104_EventScript_HoennShipToLab::
	lockall
	setvar VAR_TEMP_C, 0
	delay 30
	fadescreen FADE_TO_BLACK
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	releaseall
	end

@ ------------------------------------------------------------
@ In the lab: Pokedex upgrade
@ ------------------------------------------------------------
@ Catch-up for players who left the Route 104 beach before Birch's greeting (state 1):
@ on the door row they walk up to Birch, anywhere else the welcome runs in place.
LittlerootTown_ProfessorBirchsLab_EventScript_HoennWelcomeCatchUp::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	goto_if_ne VAR_TEMP_1, 12, LittlerootTown_ProfessorBirchsLab_EventScript_HoennWelcome
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerEnterLabForPokedex
	waitmovement 0
LittlerootTown_ProfessorBirchsLab_EventScript_HoennWelcome::
	lockall
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HoennFaceUp
	waitmovement 0
	msgbox BirchsLab_Text_HoennWelcome1, MSGBOX_DEFAULT
	closemessage
	delay 20
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_ITEM
	message BirchsLab_Text_HoennDexUpgrade
	waitmessage
	waitfanfare
	closemessage
	msgbox BirchsLab_Text_HoennDexExplain, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_HoennGiveBadgeBinder
	setvar VAR_HOENN_ARRIVAL_STATE, 3
	setflag FLAG_SYS_HOENN_DEX_GET
	@ Birch's PokeGear contact (FLAG_ENABLE_PROF_BIRCH_MATCH_CALL is Elm's).
	setflag FLAG_ENABLE_PROF_BIRK_MATCH_CALL
	setflag FLAG_HIDE_ROUTE104_HOENN_BIRCH
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	releaseall
	end

@ ------------------------------------------------------------
@ Movements
@ ------------------------------------------------------------
Common_Movement_HoennStopAndLook:
	walk_in_place_faster_up
	step_end

Common_Movement_HoennFacePlayerRight:
	walk_in_place_faster_right
	step_end

Common_Movement_HoennExclaim:
	emote_exclamation_mark
	delay_16
	step_end

Common_Movement_HoennBirchLeaveHouse:
	walk_down
	step_end

Common_Movement_HoennBirchWalkToPlayer:
	walk_down
	face_left
	step_end

Common_Movement_HoennBirchFacePlayer:
	face_down
	step_end

@ Lower lane: Birch runs from (17,51) to (15,51), above the player.
Common_Movement_HoennBirchRunLower:
	walk_fast_left
	walk_fast_left
	face_down
	step_end

@ Upper lane: Birch stops at (16,51), next to the player.
Common_Movement_HoennBirchRunUpper:
	walk_fast_left
	face_left
	step_end

Common_Movement_HoennFaceDown:
	face_down
	step_end

Common_Movement_HoennFaceUp:
	face_up
	step_end

Common_Movement_HoennFaceRight:
	face_right
	step_end

@ ------------------------------------------------------------
@ Ship menu of the ports and islands
@ ------------------------------------------------------------
@ In: VAR_0x8008 = SHIP_PORT_*. Out: VAR_RESULT = SHIP_DEST_* or MULTI_B_PRESSED.
@ Lists only what can be sailed to now; VAR_0x8009 counts the rows so that the menu ends above
@ the message box. See docs/origin_jade/DECISIONS.md, D-047.
Common_EventScript_ShipMenu::
	setvar VAR_0x8009, 12
	call_if_ne VAR_0x8008, SHIP_PORT_OLIVINE, Common_EventScript_ShipMenuPushOlivine
	call_if_ne VAR_0x8008, SHIP_PORT_VERMILION, Common_EventScript_ShipMenuPushVermilion
	call_if_ne VAR_0x8008, SHIP_PORT_ISLAND, Common_EventScript_ShipMenuPushIslands
	call Common_EventScript_ShipMenuPushHoenn
	call Common_EventScript_ShipMenuPushSlateport
	call Common_EventScript_ShipMenuPushLilycove
	dynmultipush gText_Exit, SHIP_DEST_EXIT
	subvar VAR_0x8009, 2
	call_if_eq VAR_0x8009, 0, Common_EventScript_ShipMenuTopRow
	dynmultistack 28, VAR_0x8009, FALSE, 6, FALSE, 0, DYN_MULTICHOICE_CB_NONE
	return

Common_EventScript_ShipMenuTopRow::
	setvar VAR_0x8009, 1
	return

@ Olivine from the islands always, from Vermilion once the M.S. Aqua sails every day.
Common_EventScript_ShipMenuPushOlivine::
	goto_if_eq VAR_0x8008, SHIP_PORT_ISLAND, Common_EventScript_ShipMenuPushOlivineEntry
	goto_if_lt VAR_SSAQUA_STATE, 7, Common_EventScript_NopReturn
Common_EventScript_ShipMenuPushOlivineEntry::
	dynmultipush Common_Text_ShipOlivine, SHIP_DEST_OLIVINE
	subvar VAR_0x8009, 2
	return

@ Vermilion from Olivine (before VAR_SSAQUA_STATE 7 this is the maiden voyage) and the islands.
Common_EventScript_ShipMenuPushVermilion::
	dynmultipush Common_Text_ShipVermilion, SHIP_DEST_VERMILION
	subvar VAR_0x8009, 2
	return

@ Kampfzone and Birth Island from both ports once the M.S. Aqua sails every day; the Kampfzone
@ only after the Hoenn title (D-030).
Common_EventScript_ShipMenuPushIslands::
	goto_if_lt VAR_SSAQUA_STATE, 7, Common_EventScript_NopReturn
	call_if_set FLAG_IS_HOENN_CHAMPION, Common_EventScript_ShipMenuPushBattleFrontier
	dynmultipush gText_BirthIsland, SHIP_DEST_BIRTH_ISLAND
	subvar VAR_0x8009, 2
	return

Common_EventScript_ShipMenuPushBattleFrontier::
	dynmultipush gText_BattleFrontier, SHIP_DEST_BATTLE_FRONTIER
	subvar VAR_0x8009, 2
	return

Common_EventScript_ShipMenuPushHoenn::
	call Common_EventScript_CheckShipToHoenn
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	dynmultipush gText_HoennRegion, SHIP_DEST_HOENN
	subvar VAR_0x8009, 2
	return

Common_EventScript_ShipMenuPushSlateport::
	call Common_EventScript_CheckShipToSlateport
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	dynmultipush gText_SlateportCity, SHIP_DEST_SLATEPORT
	subvar VAR_0x8009, 2
	return

Common_EventScript_ShipMenuPushLilycove::
	call Common_EventScript_CheckShipToLilycove
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	dynmultipush gText_LilycoveCity, SHIP_DEST_LILYCOVE
	subvar VAR_0x8009, 2
	return

@ VAR_RESULT = TRUE while the Hoenn ferry runs to the Route 104 pier: from the Hoenn Ticket
@ as long as no ship can land in Slateport's harbour.
Common_EventScript_CheckShipToHoenn::
	setvar VAR_RESULT, FALSE
	goto_if_lt VAR_HOENN_TICKET_STATE, 3, Common_EventScript_NopReturn
	call Common_EventScript_CheckShipToSlateport
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_ShipToHoennReplaced
	setvar VAR_RESULT, TRUE
	return

Common_EventScript_ShipToHoennReplaced::
	setvar VAR_RESULT, FALSE
	return

@ VAR_RESULT = TRUE after Birch's welcome once Slateport was visited, unless its harbour is closed
@ for Team Aqua's submarine scene.
Common_EventScript_CheckShipToSlateport::
	setvar VAR_RESULT, FALSE
	goto_if_lt VAR_HOENN_ARRIVAL_STATE, 3, Common_EventScript_NopReturn
	goto_if_unset FLAG_VISITED_SLATEPORT_CITY, Common_EventScript_NopReturn
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, Common_EventScript_NopReturn
	setvar VAR_RESULT, TRUE
	return

@ VAR_RESULT = TRUE after Birch's welcome once Lilycove was visited.
Common_EventScript_CheckShipToLilycove::
	setvar VAR_RESULT, FALSE
	goto_if_lt VAR_HOENN_ARRIVAL_STATE, 3, Common_EventScript_NopReturn
	goto_if_unset FLAG_VISITED_LILYCOVE_CITY, Common_EventScript_NopReturn
	setvar VAR_RESULT, TRUE
	return

@ VAR_RESULT = TRUE if the ship menu has any Hoenn entry.
Common_EventScript_CheckHoennFerry::
	call Common_EventScript_CheckShipToHoenn
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NopReturn
	call Common_EventScript_CheckShipToSlateport
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NopReturn
	goto Common_EventScript_CheckShipToLilycove

@ ------------------------------------------------------------
@ Texts
@ ------------------------------------------------------------
Common_Text_HoennSetSail:
#if GERMAN
	.string "Wir legen bald ab! Geh an Bord.\n"
	.string "Nächster Halt: Hoenn!$"
#else
	.string "We cast off soon! Get on board.\n"
	.string "Next stop: HOENN!$"
#endif

Common_Text_SetSailSlateport:
#if GERMAN
	.string "Wir legen bald ab! Geh an Bord.\n"
	.string "Nächster Halt: Graphitport City!$"
#else
	.string "We cast off soon! Get on board.\n"
	.string "Next stop: SLATEPORT CITY!$"
#endif

Common_Text_SetSailLilycove:
#if GERMAN
	.string "Wir legen bald ab! Geh an Bord.\n"
	.string "Nächster Halt: Seegrasulb City!$"
#else
	.string "We cast off soon! Get on board.\n"
	.string "Next stop: LILYCOVE CITY!$"
#endif

Common_Text_ShipOlivine:
#if GERMAN
	.string "Oliviana City$"
#else
	.string "OLIVINE$"
#endif

Common_Text_ShipVermilion:
#if GERMAN
	.string "Orania$"
#else
	.string "VERMILION$"
#endif

Route104_Text_BirchGreeting:
#if GERMAN
	.string "???: Du musst {PLAYER} sein.\p"
	.string "Troy hat mir schon geschrieben,\n"
	.string "dass du herkommen wirst.\p"
	.string "Komm mit in mein Labor - ich habe\n"
	.string "da etwas für dich.$"
#else
	.string "???: You must be {PLAYER}.\p"
	.string "STEVEN already wrote to me that\n"
	.string "you were on your way.\p"
	.string "Come along to my LAB - I have\n"
	.string "something for you there.$"
#endif

BirchsLab_Text_HoennWelcome1:
#if GERMAN
	.string "Prof. Birk: Willkommen in Hoenn!\p"
	.string "Troy hat mir erzählt, du seist ein\n"
	.string "erfahrener Trainer - und dass du mir bei\l"
	.string "meinem Vorhaben helfen könntest.\p"
	.string "Halt mal kurz deinen Pokédex hoch.$"
#else
	.string "PROF. BIRCH: Welcome to HOENN!\p"
	.string "STEVEN told me you're a seasoned\n"
	.string "TRAINER - and that you might be\l"
	.string "able to help me with my work.\p"
	.string "Hold up your POKéDEX for a moment.$"
#endif

BirchsLab_Text_HoennDexUpgrade:
#if GERMAN
	.string "{PLAYER}s Pokédex wurde um die\n"
	.string "Arten aus Hoenn erweitert!$"
#else
	.string "{PLAYER}'s POKéDEX was expanded\n"
	.string "with the species of HOENN!$"
#endif

BirchsLab_Text_HoennDexExplain:
#if GERMAN
	.string "Prof. Birk: So. Ich habe deinen Pokédex\n"
	.string "auf die hiesige Region erweitert.\p"
	.string "Ich forsche seit Jahren an den\n"
	.string "Lebensräumen dieser Region.\p"
	.string "Wenn du mir hilfst, sie zu füllen,\n"
	.string "wäre mir sehr geholfen.\p"
	.string "Viel Glück auf deiner Reise, {PLAYER}!$"
#else
	.string "PROF. BIRCH: There. I've expanded\n"
	.string "your POKéDEX to cover this region.\p"
	.string "I've studied the habitats of this\n"
	.string "region for years.\p"
	.string "If you help me fill it in, that\n"
	.string "would mean a great deal to me.\p"
	.string "Good luck on your journey,\n"
	.string "{PLAYER}!$"
#endif

@ ------------------------------------------------------------
@ Badge case (FLAG_RECEIVED_PASS_BINDER): Hoenn badges on the trainer card
@ ------------------------------------------------------------
Common_EventScript_HoennGiveBadgeBinder::
	goto_if_set FLAG_RECEIVED_PASS_BINDER, Common_EventScript_HoennBinderDone
	msgbox BirchsLab_Text_BinderIntro, MSGBOX_DEFAULT
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	message BirchsLab_Text_BinderObtained
	waitmessage
	waitfanfare
	closemessage
	msgbox BirchsLab_Text_BinderExplain, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_PASS_BINDER
Common_EventScript_HoennBinderDone::
	return

BirchsLab_Text_BinderIntro:
#if GERMAN
	.string "Prof. Birk: Ach ja, eines noch.\n"
	.string "Das hier ist für dich.$"
#else
	.string "PROF. BIRCH: Oh, one more thing.\n"
	.string "This is for you.$"
#endif

BirchsLab_Text_BinderObtained:
#if GERMAN
	.string "{PLAYER} erhält die Ordensmappe!$"
#else
	.string "{PLAYER} received the BADGE CASE!$"
#endif

BirchsLab_Text_BinderExplain:
#if GERMAN
	.string "Prof. Birk: Troy meinte, du sammelst\n"
	.string "gern Beweise deiner Siege.\p"
	.string "Die Mappe zeigt die Orden von Hoenn\n"
	.string "auf deiner Trainerkarte.$"
#else
	.string "PROF. BIRCH: TROY said you like to\n"
	.string "keep proof of your victories.\p"
	.string "It will display your HOENN BADGES\n"
	.string "on your TRAINER CARD.$"
#endif

BirchsLab_Text_HoennGoodLuck:
#if GERMAN
	.string "Prof. Birk: Blütenburg City liegt\n"
	.string "im Westen, Metarost City im Norden.\p"
	.string "Beide haben Arenen - falls es dich\n"
	.string "danach juckt.\p"
	.string "Ach ja: Meine Tochter Maike ist\n"
	.string "oben auf Route 103 unterwegs.\p"
	.string "Sie würde dich sicher gern kennenlernen\n"
	.string "- schau doch vorbei!\p"
	.string "Und jetzt raus mit dir.\n"
	.string "Viel Spaß, {PLAYER}!$"
#else
	.string "PROF. BIRCH: PETALBURG CITY lies\n"
	.string "west, RUSTBORO to the north.\p"
	.string "Both have GYMS - in case you feel\n"
	.string "the itch.\p"
	.string "Oh, and my daughter MAY is out\n"
	.string "on ROUTE 103 up north.\p"
	.string "I'm sure she'd love to meet you -\n"
	.string "why not drop by?\p"
	.string "Now off you go.\n"
	.string "Have fun, {PLAYER}!$"
#endif
