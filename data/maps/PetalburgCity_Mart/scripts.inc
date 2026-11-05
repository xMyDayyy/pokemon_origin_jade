PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_ExpandedItems::
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFENSE
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_Woman::
#if IS_HNS
	goto_if_ge VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Mart_EventScript_WomanGymOpen
#endif
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_WomanGymOpen::
	msgbox PetalburgCity_Mart_Text_GymLeaderShopsHere, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger:
#if GERMAN
	.string "Der Arenaleiter ist erst vor Kurzem\n"
	.string "hergezogen.\p"
	.string "Gesehen habe ich ihn noch nicht - die\n"
	.string "Arena wird ja gerade umgebaut.$"
#else
	.string "The GYM LEADER only moved here\n"
	.string "recently.\p"
	.string "I haven't laid eyes on him yet - the\n"
	.string "GYM is being rebuilt, after all.$"
#endif

PetalburgCity_Mart_Text_GymLeaderShopsHere:
#if GERMAN
	.string "Der Arenaleiter ist erst vor Kurzem\n"
	.string "hergezogen.\p"
	.string "Seit die Arena offen ist, kauft er\n"
	.string "sogar bei uns ein. Ein netter Mann!$"
#else
	.string "The GYM LEADER only moved here\n"
	.string "recently.\p"
	.string "Since the GYM opened, he even shops\n"
	.string "here. Such a nice man!$"
#endif

PetalburgCity_Mart_Text_RepelIsUseful:
#if GERMAN
	.string "Der Wald im Norden ist voller\n"
	.string "Käfer-Pokémon.\p"
	.string "Ich gehe da nur mit einem Vorrat an\n"
	.string "Gegengift rein.$"
#else
	.string "The woods to the north are full of\n"
	.string "BUG POKéMON.\p"
	.string "I won't go in without a supply of\n"
	.string "ANTIDOTES.$"
#endif

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
#if GERMAN
	.string "Meine Frau sagt, ich soll weniger\n"
	.string "einkaufen.\p"
	.string "Aber wer weiß, wann ich das nächste\n"
	.string "Mal in eine Stadt komme?$"
#else
	.string "My wife says I should buy less.\p"
	.string "But who knows when I will next\n"
	.string "reach a town?$"
#endif
