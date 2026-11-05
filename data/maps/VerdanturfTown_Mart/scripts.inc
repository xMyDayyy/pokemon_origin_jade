VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_FLUFFY_TAIL
	pokemartlistend

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForContest, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
#if GERMAN
	.string "X-Spezial ist für jeden Pokémon-Kampf\n"
	.string "äußerst wichtig.\p"
	.string "Es erhöht die Stärke mancher Attacken.\n"
	.string "Aber leider nur für einen Kampf.$"
#else
	.string "For any POKéMON match, X SPECIAL\n"
	.string "is crucial.\p"
	.string "It jacks up the power of some moves\n"
	.string "even though it's only for one battle.$"
#endif

VerdanturfTown_Mart_Text_NoStrategyGuidesForContest:
#if GERMAN
	.string "Sie verkaufen keine Items, mit denen\n"
	.string "man einen Wettbewerb gewinnen kann…\p"
	.string "Und das bedeutet, dass du deine\n"
	.string "Pokémon mit äußerster Sorgfalt\l"
	.string "aufziehen musst.$"
#else
	.string "They don't sell any items that will let\n"
	.string "you win CONTESTS…\p"
	.string "It means you have to raise POKéMON\n"
	.string "diligently on an everyday basis.$"
#endif

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
#if GERMAN
	.string "Der Nestball ist bei schwächeren\n"
	.string "Pokémon hervorragend geeignet.\p"
	.string "Den kannst du nur in Wiesenflur\n"
	.string "kaufen.$"
#else
	.string "The NEST BALL works better on\n"
	.string "weakened POKéMON.\p"
	.string "VERDANTURF is the only place you can\n"
	.string "buy it.$"
#endif

