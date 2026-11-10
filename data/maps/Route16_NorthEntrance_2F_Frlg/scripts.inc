.equ REQUIRED_CAUGHT_MONS, 40

Route16_NorthEntrance_2F_Frlg_MapScripts::
	.byte 0

Route16_NorthEntrance_2F_EventScript_LittleBoy::
	msgbox Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LittleGirl::
	msgbox Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes, MSGBOX_NPC
	end

Route16_NorthEntrance_2F_EventScript_LeftBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_RightBinoculars::
	msgbox Route16_NorthEntrance_2F_Text_LongPathOverWater, MSGBOX_SIGN
	end

Route16_NorthEntrance_2F_EventScript_Aide::
	lock
	faceplayer
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_set FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE, Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin
	msgbox Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Aide_EventScript_DeclineCheckMons
	@ 2: aide count (all species with a species randomizer)
	setvar VAR_0x8004, 2
	specialvar VAR_RESULT, GetFrlgPokedexCount
	buffernumberstring STR_VAR_3, VAR_0x8006
	call Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo
	goto_if_lt VAR_0x8006, REQUIRED_CAUGHT_MONS, Aide_EventScript_HaventCaughtEnough
	msgbox Route16_NorthEntrance_2F_Text_GreatHereYouGo
	checkitemspace ITEM_AMULET_COIN
	goto_if_eq VAR_RESULT, FALSE, Aide_EventScript_NoRoomForItem
	giveitem_msg Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide, ITEM_AMULET_COIN
	setflag FLAG_GOT_AMULET_COIN_FROM_OAKS_AIDE
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_AlreadyGotAmuletCoin::
	msgbox Route16_NorthEntrance_2F_Text_ExplainAmuletCoin
	release
	end

Route16_NorthEntrance_2F_EventScript_GetAideRequestInfo::
	buffernumberstring STR_VAR_1, REQUIRED_CAUGHT_MONS
	bufferitemname STR_VAR_2, ITEM_AMULET_COIN
	return

Route16_NorthEntrance_2F_Text_OnBikeRideWithGirlfriend::
#if GERMAN
	.string "Ich mache mit meiner Freundin einen\n"
	.string "Ausflug!$"
#else
	.string "I'm on a relaxing ride on my new\n"
	.string "bike with my girlfriend.$"
#endif

Route16_NorthEntrance_2F_Text_RidingTogetherOnNewBikes::
#if GERMAN
	.string "Wir werden mit dem Rad fahren!$"
#else
	.string "We're going riding together on our\n"
	.string "new bikes.$"
#endif

Route16_NorthEntrance_2F_Text_ItsCeladonDeptStore::
#if GERMAN
	.string "Du schaust durch das Fernrohr.\p"
	.string "Du siehst das Einkaufszentrum von\n"
	.string "Prismania City!$"
#else
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "It's the CELADON DEPT. STORE!$"
#endif

Route16_NorthEntrance_2F_Text_LongPathOverWater::
#if GERMAN
	.string "Du schaust durch das Fernrohr.\p"
	.string "Dort führt ein langer Weg über das\n"
	.string "Wasser!$"
#else
	.string "Let's see what the binoculars have\n"
	.string "to show…\p"
	.string "There's a long path over water far\n"
	.string "away.$"
#endif

Route16_NorthEntrance_2F_Text_GiveAmuletCoinIfCaught40::
#if GERMAN
	.string "Hallo! Erinnerst du dich?\n"
	.string "Ich bin Prof. Eichs Assistent!\p"
	.string "Wenn du mindestens 40 verschiedene\n"
	.string "Pokémon gefangen hast, habe ich ein\l"
	.string "Geschenk für dich: Münzamulett\p"
	.string "Also, {PLAYER}, hast du 40\n"
	.string "unterschiedliche Pokémon gefangen?$"
#else
	.string "Hi! Remember me?\n"
	.string "I'm one of PROF. OAK's AIDES.\p"
	.string "If your POKéDEX has complete data\n"
	.string "on 40 species, I'm supposed to\l"
	.string "give you a reward.\p"
	.string "PROF. OAK entrusted me with an\n"
	.string "AMULET COIN for you.\p"
	.string "So, {PLAYER}, let me ask you.\p"
	.string "Have you gathered data on at least\n"
	.string "40 kinds of POKéMON?$"
#endif

Route16_NorthEntrance_2F_Text_GreatHereYouGo::
#if GERMAN
	.string "Super! Du hast {STR_VAR_3} verschiedene\n"
	.string "Pokémon gefangen!\p"
	.string "Einfach klasse! Hier, das hast du\n"
	.string "dir redlich verdient!$"
#else
	.string "Great! You have caught or owned\n"
	.string "{STR_VAR_3} kinds of POKéMON!\p"
	.string "Congratulations!\n"
	.string "Here you go!$"
#endif

Route16_NorthEntrance_2F_Text_ReceivedAmuletCoinFromAide::
#if GERMAN
	.string "{PLAYER} erhält Münzamulett!$"
#else
	.string "{PLAYER} received the AMULET COIN\n"
	.string "from the AIDE.$"
#endif

Route16_NorthEntrance_2F_Text_ExplainAmuletCoin::
#if GERMAN
	.string "Ein Münzamulett kann von einem Pokémon\n"
	.string "getragen werden.\p"
	.string "Nimmt das Pokémon an einem siegreichen\n"
	.string "Kampf teil, verdoppelt sich das\l"
	.string "Preisgeld.$"
#else
	.string "An AMULET COIN is an item to be\n"
	.string "held by a POKéMON.\p"
	.string "If the POKéMON appears in a winning\n"
	.string "battle, you will earn more money.$"
#endif

