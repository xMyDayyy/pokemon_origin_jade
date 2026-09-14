LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_MIRROR_HERB
	pokemartlistend

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
#if GERMAN
	.string "Willkommen im Kräuterladen! Dem Heim\n"
	.string "wirkungsvoller und preiswerter Medizin!$"
#else
	.string "Welcome to the HERB SHOP, home of\n"
	.string "effective and inexpensive medicine!$"
#endif

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
#if GERMAN
	.string "Du kommst nach Bad Lavastadt, um\n"
	.string "Kräutermedizin zu kaufen?\p"
	.string "Das ist lobenswert!\p"
	.string "Ich finde dich nett! Hier, für dich!$"
#else
	.string "You've come to look at herbal medicine\n"
	.string "in LAVARIDGE?\p"
	.string "That's rather commendable.\p"
	.string "I like you! Take this!$"
#endif

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
#if GERMAN
	.string "Mit dieser Holzkohle wird die Kräuter-\n"
	.string "medizin hergestellt.\p"
	.string "Sie wirkt auch Wunder, wenn sie von\n"
	.string "einem Pokémon getragen wird.\p"
	.string "Sie verstärkt Feuer-Attacken.$"
#else
	.string "That CHARCOAL I gave you, it's used\n"
	.string "for making herbal medicine.\p"
	.string "It also does wonders when held by\n"
	.string "a POKéMON.\p"
	.string "It intensifies the power of FIRE-type\n"
	.string "moves.$"
#endif

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
#if GERMAN
	.string "Kräutermedizin ist erstaunlich\n"
	.string "wirkungsvoll. Aber deine Pokémon mögen\l"
	.string "sie nicht. Sie schmeckt bitter…$"
#else
	.string "Herbal medicine works impressively well.\n"
	.string "But your POKéMON will dislike you for it.\l"
	.string "It must be horribly bitter!$"
#endif

