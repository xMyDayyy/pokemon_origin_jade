VioletCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY_HNS
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_Offer @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_AideNoRoom
VioletCity_PokemonCenter_EventScript_Aide_Offer::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_Aide_FullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	goto_if_eq VAR_0x8004, 1, VioletCity_PokemonCenter_EventScript_Aide_GiveEgg @ party limit of 1: the Egg goes to the PC
	getpartysize
	goto_if_eq VAR_RESULT, VAR_0x8004, VioletCity_PokemonCenter_EventScript_Aide_FullParty
VioletCity_PokemonCenter_EventScript_Aide_GiveEgg::
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon @ party limit of 1 and every BOX full
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PC, VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_AideFullParty::
	msgbox VioletCity_PokeCenter_Text_ElmsAideFullParty, MSGBOX_DEFAULT
	closemessage
	release
	end
VioletCity_PokemonCenter_EventScript_Aide_EggSentToPC::
	msgbox VioletCity_PokeCenter_Text_ElmsAideEggToPC, MSGBOX_DEFAULT
	closemessage
	return

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
#if GERMAN
	.string "{PLAYER}, lange nicht gesehen.\p"
	.string "Prof. Lind hat mich gebeten, nach dir zu\n"
	.string "suchen.\p"
	.string "Er hat noch eine Bitte an dich.\p"
	.string "Nimm bitte das Pokémon-Ei!$"
#else
	.string "{PLAYER}, long time, no see.\p"
	.string "PROF.ELM asked me to find you.\p"
	.string "He has another favor to ask.\p"
	.string "Would you take the POKéMON EGG?$"
#endif

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
#if GERMAN
	.string "{PLAYER}, lange nicht gesehen.\p"
	.string "Prof. Lind hat mich gebeten, nach dir zu\n"
	.string "suchen.\p"
	.string "Er hat noch eine Bitte an dich.\p"
	.string "Nimm bitte das Pokémon-Ei!\p"
	.string "Oh, du hast keinen Platz mehr\n"
	.string "für ein weiteres Pokémon.\p"
	.string "Ich warte hier, bis du Platz für\n"
	.string "das Ei geschaffen hast.$"
#else
	.string "{PLAYER}, long time, no see.\p"
	.string "PROF.ELM asked me to find you.\p"
	.string "He has another favor to ask.\p"
	.string "Would you take the POKéMON EGG?\p"
	.string "Oh, wait... You need to make room\n"
	.string "in your party first.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
#if GERMAN
	.string "Wir haben entdeckt, dass ein Pokémon\n"
	.string "erst schlüpft, nachdem es im Ei\l"
	.string "gewachsen ist.\p"
	.string "Außerdem muss es sich in der Nähe\n"
	.string "anderer Pokémon befinden, um zu\l"
	.string "schlüpfen.\p"
	.string "Du bist die einzige Person, auf die wir\n"
	.string "uns verlassen können.\p"
	.string "Bitte ruf Prof. Lind an, wenn das Ei so\n"
	.string "weit ist!$"
#else
	.string "We discovered that a POKéMON won't\n"
	.string "hatch until it grows in the EGG.\p"
	.string "It also has to be with other\n"
	.string "active POKéMON to hatch.\p"
	.string "{PLAYER}, you're the only person\n"
	.string "we can rely on.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
#if GERMAN
	.string "Oh, das hier könnte helfen, wenn es\n"
	.string "geschlüpft ist.$"
#else
	.string "Oh, and this might help when it hatches.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideFullParty:
#if GERMAN
	.string "Oh, du hast keinen Platz mehr für ein\n"
	.string "weiteres Pokémon.\p"
	.string "Ich warte hier, bis du Platz für das Ei\n"
	.string "geschaffen hast.$"
#else
	.string "Oh, no. You can't carry any more\n"
	.string "POKéMON with you.\p"
	.string "I'll wait here while you make\n"
	.string "room for the EGG.$"
#endif

VioletCity_PokeCenter_Text_ElmsAideEggToPC:
	.string "Oh, but you can't carry any more\n"
	.string "POKéMON with you.\p"
	.string "Don't worry--I sent the EGG to\n"
	.string "BILL'S PC for you.$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
#if GERMAN
	.string "A-Aber… Prof. Lind hat nach dir\n"
	.string "gefragt…$"
#else
	.string "B-but… PROF.ELM asked for you…$"
#endif

VioletCity_PokeCenter_Text_BooksAreGreat:
#if GERMAN
	.string "Während meine Pokémon sich erholen,\n"
	.string "lese ich gerne ein gutes Buch.$"
#else
	.string "While my POKéMON are recovering\n"
	.string "I love to read a good book.$"
#endif

VioletCity_PokeCenter_Text_MobileAdapter:
#if GERMAN
	.string "Woran denkst du, wenn du versuchst,\p"
	.string "daran zu denken, nicht daran zu denken,\n"
	.string "dass du denkst, dass du dumm bist,\p"
	.string "obwohl du nicht dumm bist?\n"
	.string "Hähhhh?$"
#else
	.string "I just battled a friend in\n"
	.string "CIANWOOD over a link.\p"
	.string "If you connect a MOBILE ADAPTER,\n"
	.string "you can link with a friend far\l"
	.string "away.$"
#endif

VioletCity_PokeCenter_Text_GameboyKid:
#if GERMAN
	.string "Ein Kerl namens Bill hat das\n"
	.string "PC-Pokémon-Lagerungssystem erfunden.$"
#else
	.string "A guy named BILL made the\n"
	.string "POKéMON PC storage system.$"
#endif

VioletCity_PokeCenter_Text_Gentleman:
#if GERMAN
	.string "Es war vor etwa drei Jahren.\p"
	.string "Team Rocket hatte etwas Übles mit den\n"
	.string "Pokémon vor.\p"
	.string "Aber die Gerechtigkeit hat gesiegt! Ein\n"
	.string "junger Trainer hat sie zerschlagen.$"
#else
	.string "It was around three years ago.\p"
	.string "TEAM ROCKET was up to no good\n"
	.string "with POKéMON.\p"
	.string "But justice prevailed--a young\n"
	.string "kid broke 'em up.$"
#endif

VioletCity_PokeCenter_Text_Youngster:
#if GERMAN
	.string "Pokémon sind schlau.\n"
	.string "Sie gehorchen nur Trainern, vor denen\l"
	.string "sie auch Respekt haben.\p"
	.string "Hat der Trainer nicht genug Orden,\n"
	.string "machen sie, was sie wollen.$"
#else
	.string "POKéMON are smart. They won't\n"
	.string "obey a trainer they don't respect.\p"
	.string "Without the right GYM BADGES,\n"
	.string "they will just do as they please.$"
#endif
