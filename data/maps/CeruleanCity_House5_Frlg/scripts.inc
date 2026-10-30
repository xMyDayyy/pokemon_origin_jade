CeruleanCity_House5_Frlg_MapScripts::
	.byte 0

CeruleanCity_House5_EventScript_BerryPowderMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_POWDER_JAR, CeruleanCity_House5_EventScript_AskToExchangePowder
	msgbox CeruleanCity_House1_Text_AnyInterestInBerries, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_NoInterestInBerries
	@ Needs at least one berry in the bag.
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NoBerries
	msgbox CeruleanCity_House1_Text_HaveJustTheThing
	setflag FLAG_GOT_POWDER_JAR
	giveitem ITEM_POWDER_JAR
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
	msgbox CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner
	release
	end

CeruleanCity_House5_EventScript_NoBerries::
	msgbox CeruleanCity_House1_Text_WhyMustYouLieNoBerries
	release
	end

CeruleanCity_House5_EventScript_NoInterestInBerries::
	msgbox CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings
	release
	end

CeruleanCity_House5_EventScript_AskToExchangePowder::
	special DisplayBerryPowderVendorMenu
	msgbox CeruleanCity_House1_Text_HaveYouBroughtBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_ChooseExchangeItem::
	message CeruleanCity_House5_Text_ExchangeWithWhat
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, CeruleanCity_House5_EventScript_EnergyPowder
	case 1, CeruleanCity_House5_EventScript_EnergyRoot
	case 2, CeruleanCity_House5_EventScript_HealPowder
	case 3, CeruleanCity_House5_EventScript_RevivalHerb
	case 4, CeruleanCity_House5_EventScript_Protein
	case 5, CeruleanCity_House5_EventScript_Iron
	case 6, CeruleanCity_House5_EventScript_Carbos
	case 7, CeruleanCity_House5_EventScript_Calcium
	case 8, CeruleanCity_House5_EventScript_Zinc
	case 9, CeruleanCity_House5_EventScript_HPUp
	case 10, CeruleanCity_House5_EventScript_PPUp
	case 11, CeruleanCity_House5_EventScript_ExitMenu
	case 127, CeruleanCity_House5_EventScript_ExitMenu
	end

CeruleanCity_House5_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto CeruleanCity_House5_EventScript_ExchangePowderForItem
	end

CeruleanCity_House5_EventScript_ExitMenu::
	msgbox CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_ExchangePowderForItem::
	msgbox CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CeruleanCity_House5_EventScript_ChooseExchangeItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, CeruleanCity_House5_EventScript_BagIsFull
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox CeruleanCity_House1_Text_TradeMoreBerryPowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, CeruleanCity_House5_EventScript_ChooseExchangeItem
	msgbox CeruleanCity_House1_Text_HopeToSeeYouAgain
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_BagIsFull::
	msgbox gText_TheBagIsFull
	special RemoveBerryPowderVendorMenu
	release
	end

CeruleanCity_House5_EventScript_NotEnoughBerryPowder::
	msgbox CeruleanCity_House1_Text_DontHaveEnoughBerryPowder
	goto CeruleanCity_House5_EventScript_ChooseExchangeItem
	end

CeruleanCity_House5_EventScript_BerryCrushRankings::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

CeruleanCity_House1_Text_AnyInterestInBerries::
#if GERMAN
	.string "Ich stelle eine Vielzahl Medikamente\n"
	.string "aus Beerenpuder her.\l"
	.string "Mit gutem Beerenpuder kann ich jedes\l"
	.string "Medikament herstellen!\p"
	.string "Hast du Interesse an Beeren?$"
#else
	.string "I concoct a variety of medicine\n"
	.string "from BERRY POWDER.\p"
	.string "Using good BERRY POWDER, I can\n"
	.string "make any kind of medicine.\p"
	.string "Now tell me, have you any interest\n"
	.string "in BERRIES?$"
#endif

CeruleanCity_House1_Text_HaveJustTheThing::
#if GERMAN
	.string "Schön! Dann habe ich genau das Richtige\n"
	.string "für dich!$"
#else
	.string "Ah, good! For you, then, I have\n"
	.string "just the thing.$"
#endif

CeruleanCity_House1_Text_GoCrushBerriesAtDirectCorner::
#if GERMAN
	.string "Im Pokémon-Center gibt es im oberen\n"
	.string "Stockwerk beim Direktklub etwas Neues.\l"
	.string "Der Drahtlose GBA-Adapter zum Beeren\l"
	.string "mahlen wurde eingerichtet.\l"
	.string "Da kommst du ins Spiel.\p"
	.string "Du bist der Einzige, den ich um diesen\n"
	.string "Gefallen bitten kann.\p"
	.string "Kannst du mit dieser Maschine\n"
	.string "Beerenpuder für mich herstellen?\l"
	.string "Sie steht im Direktklub des\l"
	.string "Pokémon-Centers.\p"
	.string "Ich werde Medizin herstellen, wenn du\n"
	.string "mir Beerenpuder bringst.\l"
	.string "Mahle Beeren und bring mir Beerenpuder.$"
#else
	.string "There's something new on the second\n"
	.string "floor of POKéMON CENTERS, at the\l"
	.string "DIRECT CORNER.\p"
	.string "They installed a Wireless Adapter\n"
	.string "machine for crushing BERRIES.\p"
	.string "This is where you come in.\p"
	.string "I have a favor to ask, one that\n"
	.string "I can entrust only to you.\p"
	.string "Could you make BERRY POWDER for\n"
	.string "me using that machine?\p"
	.string "Don't forget, the machine is at the\n"
	.string "DIRECT CORNER of POKéMON CENTERS.\p"
	.string "I'll concoct medicine for you if\n"
	.string "you bring me some BERRY POWDER.\p"
	.string "Don't forget, crush BERRIES into\n"
	.string "BERRY POWDER and bring it to me.$"
#endif

CeruleanCity_House1_Text_WhyMustYouLieNoBerries::
#if GERMAN
	.string "Warum lügst du mich an?\p"
	.string "Wie viele Beeren hast du?\n"
	.string "Keine einzige!$"
#else
	.string "Why must you lie to me?\p"
	.string "How many BERRIES do you have?\n"
	.string "Not a one!$"
#endif

CeruleanCity_House1_Text_TakeInterestInAllSortsOfThings::
#if GERMAN
	.string "Du interessierst dich nicht für Beeren?\n"
	.string "Auch als Kind sollte man sich für alle\l"
	.string "möglichen Dinge interessieren.$"
#else
	.string "You have no interest in BERRIES?\p"
	.string "Young one, it's important to take an\n"
	.string "interest in all sorts of things.$"
#endif

CeruleanCity_House1_Text_HaveYouBroughtBerryPowder::
#if GERMAN
	.string "Ähm! Hast du mir Beerenpuder gebracht?$"
#else
	.string "Er-hem! Have you brought me some\n"
	.string "BERRY POWDER?$"
#endif

CeruleanCity_House5_Text_ExchangeWithWhat::
#if GERMAN
	.string "Wogegen möchtest du es tauschen?$"
#else
	.string "With what would you like to \n"
	.string "exchange it?$"
#endif

CeruleanCity_House1_Text_YoullExchangeBerryPowderForItem::
#if GERMAN
	.string "Gut, ich gebe dir {STR_VAR_1}\n"
	.string "im Austausch für deinen Beerenpuder!$"
#else
	.string "Fine, you'll exchange your BERRY\n"
	.string "POWDER for one {STR_VAR_1}?$"
#endif

CeruleanCity_House1_Text_DontHaveEnoughBerryPowder::
#if GERMAN
	.string "Hm? Du hast nicht genügend\n"
	.string "Beerenpuder!$"
#else
	.string "Hm? You don't have enough\n"
	.string "BERRY POWDER.$"
#endif

CeruleanCity_House1_Text_TradeMoreBerryPowder::
#if GERMAN
	.string "Das ist wirklich erstklassiger\n"
	.string "Beerenpuder! Daraus lässt sich gute\l"
	.string "Medizin herstellen.\l"
	.string "Möchtest du noch mehr Beerenpuder\l"
	.string "tauschen?$"
#else
	.string "This is fine BERRY POWDER indeed.\n"
	.string "It will make excellent medicine.\p"
	.string "Would you like to trade more BERRY\n"
	.string "POWDER for something else?$"
#endif

CeruleanCity_House1_Text_HopeToSeeYouAgain::
#if GERMAN
	.string "Das ist in Ordnung!\n"
	.string "Ich hoffe, wir sehen uns!$"
#else
	.string "That's fine, then.\n"
	.string "I'll hope to see you back again.$"
#endif

CeruleanCity_House1_Text_SeeMeIfYoudLikeToTradePowder::
#if GERMAN
	.string "Komm einfach vorbei, wenn du\n"
	.string "Beerenpuder tauschen möchtest!$"
#else
	.string "Come see me if you'd like to trade\n"
	.string "your BERRY POWDER.$"
#endif

