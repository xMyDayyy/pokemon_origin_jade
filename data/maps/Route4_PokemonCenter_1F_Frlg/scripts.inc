.equ MAGIKARP_PRICE, 500

Route4_PokemonCenter_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route4_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

Route4_PokemonCenter_1F_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE4_POKEMON_CENTER_1F
	setrespawn HEAL_LOCATION_ROUTE4
	end

Route4_PokemonCenter_1F_EventScript_Boy::
	msgbox Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Gentleman::
	lock
	msgbox Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean
	release
	end

Route4_PokemonCenter_1F_EventScript_MagikarpSalesman::
	lock
	faceplayer
	goto_if_set FLAG_BOUGHT_MAGIKARP, Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp
	showmoneybox 0, 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale
	goto_if_eq VAR_RESULT, FEMALE, Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpMale::
	msgbox Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_AskBuyMagikarpFemale::
	msgbox Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500, MSGBOX_YESNO
	goto Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TryBuyMagikarp::
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_DeclineMagikarp
	checkmoney MAGIKARP_PRICE
	goto_if_eq VAR_RESULT, FALSE, Route4_PokemonCenter_1F_EventScript_NotEnoughMoney
	textcolor NPC_TEXT_COLOR_NEUTRAL
	setvar VAR_TEMP_1, SPECIES_MAGIKARP
	givemon SPECIES_MAGIKARP, 10
	goto_if_eq VAR_RESULT, 0, Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty
	goto_if_eq VAR_RESULT, 1, Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC
	goto_if_eq VAR_RESULT, 2, Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpParty::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	call Common_EventScript_GetGiftMonPartySlot
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BuyMagikarpPC::
	call Route4_PokemonCenter_1F_EventScript_PayForMagikarp
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox
	fadescreen FADE_TO_BLACK
	hidemoneybox
	special ChangePokemonNickname
	waitstate
	lock
	faceplayer
	goto Route4_PokemonCenter_1F_EventScript_TransferMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarpCloseMoneyBox::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp
	end

Route4_PokemonCenter_1F_EventScript_TransferMagikarp::
	call Common_EventScript_TransferredToPC
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_EndPurchaseMagikarp::
	hidemoneybox
	goto Route4_PokemonCenter_1F_EventScript_BoughtMagikarp
	end

Route4_PokemonCenter_1F_EventScript_BoughtMagikarp::
	setflag FLAG_BOUGHT_MAGIKARP
	release
	end

Route4_PokemonCenter_1F_EventScript_PayForMagikarp::
	removemoney MAGIKARP_PRICE
	updatemoneybox
	playfanfare MUS_LEVEL_UP
	message Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_MAGIKARP
	return

Route4_PokemonCenter_1F_EventScript_DeclineMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_NotEnoughMoney::
	msgbox Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_AlreadyBoughtMagikarp::
	msgbox Route4_PokemonCenter_1F_Text_IDontGiveRefunds
	release
	end

Route4_PokemonCenter_1F_EventScript_NoRoomForMagikarp::
	textcolor NPC_TEXT_COLOR_MALE
	msgbox Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon
	hidemoneybox
	release
	end

Route4_PokemonCenter_1F_EventScript_Nurse::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse_Frlg
	release
	end

Route4_PokemonCenter_1F_EventScript_Youngster::
	msgbox Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC, MSGBOX_NPC
	end

Route4_PokemonCenter_1F_EventScript_Newspaper::
	lock
	msgbox Route4_PokemonCenter_1F_Text_ItsANewspaper
	release
	end

Route4_PokemonCenter_1F_Text_CanHaveSixMonsWithYou::
#if GERMAN
	.string "An meinem Gürtel hängen sechs\n"
	.string "Pokébälle.\p"
	.string "Man kann maximal sechs Pokémon mit\n"
	.string "sich führen.$"
#else
	.string "Okay, set six POKé BALLS in my\n"
	.string "belt…\p"
	.string "Yeah, that'll do it. At most, you\n"
	.string "can have six POKéMON with you.$"
#endif

Route4_PokemonCenter_1F_Text_TeamRocketAttacksCerulean::
#if GERMAN
	.string "Das Team Rocket terrorisiert die\n"
	.string "Einwohner von Azuria City!\p"
	.string "Kein Tag vergeht ohne Meldungen\n"
	.string "über Team Rockets Schandtaten!$"
#else
	.string "TEAM ROCKET attacks CERULEAN\n"
	.string "citizens…\p"
	.string "Not a day goes by without TEAM\n"
	.string "ROCKET being in the news.$"
#endif

Route4_PokemonCenter_1F_Text_LaddieBuyMagikarpForJust500::
#if GERMAN
	.string "Mann: Hallo! Möchtest du ein Geschäft\n"
	.string "machen?\p"
	.string "Ich gebe dir ein exzellentes Karpador\n"
	.string "für läppische 500¥!\p"
	.string "Interessiert?$"
#else
	.string "MAN: Hello there, laddie!\n"
	.string "Have I got a deal just for you!\p"
	.string "I'll let you have a secret POKéMON\n"
	.string "- a MAGIKARP - for just ¥500!\p"
	.string "So, you'll buy it, am I right?$"
#endif

Route4_PokemonCenter_1F_Text_SweetieBuyMagikarpForJust500::
#if GERMAN
	.string "Mann: Hallo! Möchtest du ein Geschäft\n"
	.string "machen?\p"
	.string "Ich gebe dir ein exzellentes Karpador\n"
	.string "für läppische 500¥!\p"
	.string "Interessiert?$"
#else
	.string "MAN: Hello there, sweetie pie!\n"
	.string "Have I got a deal just for you!\p"
	.string "I'll let you have a secret POKéMON\n"
	.string "- a MAGIKARP - for just ¥500!\p"
	.string "So, you'll buy it, am I right?$"
#endif

Route4_PokemonCenter_1F_Text_PaidOutrageouslyForMagikarp::
#if GERMAN
	.string "{PLAYER} bezahlte den Wucherpreis\n"
	.string "von 500$ für ein Karpador…\l$"
#else
	.string "{PLAYER} paid an outrageous ¥500\n"
	.string "and bought the MAGIKARP…$"
#endif

Route4_PokemonCenter_1F_Text_OnlyDoingThisAsFavorToYou::
#if GERMAN
	.string "Nein? Ich wollte dir doch einen\n"
	.string "Gefallen tun!$"
#else
	.string "No? You say no? I'm only doing this\n"
	.string "as a favor to you!$"
#endif

Route4_PokemonCenter_1F_Text_NoRoomForMorePokemon::
#if GERMAN
	.string "Du hast keinen Platz mehr für weitere\n"
	.string "Pokémon!$"
#else
	.string "There's no more room for any more\n"
	.string "POKéMON, it looks like.$"
#endif

Route4_PokemonCenter_1F_Text_YoullNeedMoreMoney::
#if GERMAN
	.string "Schade, du hast nicht genug Geld!$"
#else
	.string "You'll need more money than that!$"
#endif

Route4_PokemonCenter_1F_Text_IDontGiveRefunds::
#if GERMAN
	.string "Mann: Der Umtausch ist ausgeschlossen!$"
#else
	.string "MAN: Well, I don't give refunds.\n"
	.string "You knew what you were getting!$"
#endif

Route4_PokemonCenter_1F_Text_ShouldStoreMonsUsingPC::
#if GERMAN
	.string "Wenn du keine weiteren Pokémon tragen\n"
	.string "kannst, solltest du einige via PC\l"
	.string "ablegen!$"
#else
	.string "Sometimes, you'll have too many\n"
	.string "POKéMON with you to add any more.\p"
	.string "In that case, you should just\n"
	.string "store some using any PC.$"
#endif

Route4_PokemonCenter_1F_Text_ItsANewspaper::
#if GERMAN
	.string "Eine Zeitung!$"
#else
	.string "It's a newspaper.$"
#endif

