ThreeIsland_BerryForest_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ThreeIsland_BerryForest_OnTransition
	.byte 0

ThreeIsland_BerryForest_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_THREE_ISLAND_BERRY_FOREST
	setescapewarp MAP_THREE_ISLAND_BOND_BRIDGE, 12, 6
	end

ThreeIsland_BerryForest_EventScript_Lostelle::
	lock
	faceplayer
	msgbox ThreeIsland_BerryForest_Text_HelpScaryPokemon
	playse SE_PIN
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, ThreeIsland_BerryForest_Movement_LostelleLookAround
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_HereItComesAgain
	waitse
	playmoncry SPECIES_HYPNO, CRY_MODE_ENCOUNTER
	waitmoncry
	setwildbattle SPECIES_HYPNO, 24
	dowildbattle
	applymovement LOCALID_BERRY_FOREST_LOSTELLE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox ThreeIsland_BerryForest_Text_ThankYouHaveThis
	giveitem ITEM_IAPAPA_BERRY
	call_if_eq VAR_RESULT, FALSE, ThreeIsland_BerryForest_EventScript_NoRoomForBerry
	special GetPlayerBigGuyGirlString
	msgbox ThreeIsland_BerryForest_Text_LetsGoHome
	closemessage
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 2
	clearflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	warp MAP_TWO_ISLAND_JOYFUL_GAME_CORNER, 6, 6
	waitstate
	release
	end

ThreeIsland_BerryForest_EventScript_NoRoomForBerry::
	msgbox ThreeIsland_BerryForest_Text_BerryPouchIsFull
	return

ThreeIsland_BerryForest_Movement_LostelleLookAround::
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	step_end

ThreeIsland_BerryForest_EventScript_WelcomeSign::
	msgbox ThreeIsland_BerryForest_Text_WelcomeToBerryForest, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_EventScript_BewareSign::
	msgbox ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons, MSGBOX_SIGN
	end

ThreeIsland_BerryForest_Text_HelpScaryPokemon::
#if GERMAN
	.string "Irrma: Wimmer… schnief…\n"
	.string "Oh! Hilf mir bitte!\p"
	.string "Ein Angst einflößendes Pokémon ist\n"
	.string "dort vor kurzem aufgetaucht.\p"
	.string "Es war so gruselig.\n"
	.string "Es hat Irrma Angst gemacht.\p"
	.string "Ich bin zu verängstigt, um mich zu\n"
	.string "bewegen! Aber ich möchte nach Hause\l"
	.string "gehen…$"
#else
	.string "LOSTELLE: Whimper… Sniff…\n"
	.string "Oh! Please, help!\p"
	.string "A scary POKéMON appeared there\n"
	.string "a little while ago.\p"
	.string "It kept scaring.\n"
	.string "It made LOSTELLE scared.\p"
	.string "I'm too scared to move!\n"
	.string "But I want to go home…$"
#endif

ThreeIsland_BerryForest_Text_HereItComesAgain::
#if GERMAN
	.string "Oh! Hier ist es wieder! Nein!\n"
	.string "Verschwinde! Es macht mir Angst!\p"
	.string "Wahhhhhhhhhhh!\n"
	.string "Ich will zu meinem Papa!$"
#else
	.string "Oh! Here it comes again!\n"
	.string "No! Go away! It's scaring me!\p"
	.string "Waaaaaaah!\n"
	.string "I want my daddy!$"
#endif

ThreeIsland_BerryForest_Text_ThankYouHaveThis::
#if GERMAN
	.string "Oh! Das war so gruselig!\n"
	.string "Dankeschön!\p"
	.string "Irrma wollte hier Beeren pflücken.\p"
	.string "Das ist für dich!$"
#else
	.string "Ohh! That was so scary!\n"
	.string "Thank you!\p"
	.string "LOSTELLE came to pick some\n"
	.string "BERRIES.\p"
	.string "You can have this!$"
#endif

ThreeIsland_BerryForest_Text_LetsGoHome::
#if GERMAN
	.string "Wie heißt du?\p"
	.string "Irrma ist so verängstigt!\n"
	.string "Bringst du mich nach Hause?\p"
	.string "O.K.!\n"
	.string "Lass uns nach Hause gehen!$"
#else
	.string "What's your name?\p"
	.string "LOSTELLE's scared, so can I go\n"
	.string "with you to my daddy's house?\p"
	.string "Okay!\n"
	.string "Let's go home!$"
#endif

ThreeIsland_BerryForest_Text_BerryPouchIsFull::
#if GERMAN
	.string "Deine Beerentüte ist voll.\n"
	.string "Ich denke, du willst das nicht.$"
#else
	.string "Your BERRY POUCH is full.\n"
	.string "I guess you don't want this.$"
#endif

ThreeIsland_BerryForest_Text_WelcomeToBerryForest::
#if GERMAN
	.string "Willkommen im Beerenforst!\p"
	.string "Sei freundlich und teile die Beeren\n"
	.string "mit Anderen und Pokémon!$"
#else
	.string "Welcome to the BERRY FOREST\p"
	.string "Be friendly and share BERRIES with\n"
	.string "others and POKéMON.$"
#endif

ThreeIsland_BerryForest_Text_BewareWildBerryLovingMons::
#if GERMAN
	.string "Nimm dich vor wilden Pokémon,\n"
	.string "die Beeren lieben, in Acht!$"
#else
	.string "Beware of wild, BERRY-loving\n"
	.string "POKéMON!$"
#endif

