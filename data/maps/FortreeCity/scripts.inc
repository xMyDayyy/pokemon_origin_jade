FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
#if GERMAN
	.string "Niemand glaubt mir. Aber ich habe\n"
	.string "wirklich ein riesiges Pokémon am Himmel\l"
	.string "gesehen!\p"
	.string "Als es Richtung Route 131 flog, schien\n"
	.string "es sich zu winden.\p"
	.string "Schnüffel…\n"
	.string "Äh… Du, uh… riechst angesengt.\p"
	.string "Warst du auf einem Vulkan oder so?$"
#else
	.string "No one believes me, but I saw this\n"
	.string "gigantic POKéMON in the sky.\p"
	.string "It seemed to squirm as it flew toward\n"
	.string "ROUTE 131.\p"
	.string "By the way… Sniff…\n"
	.string "Um… You, uh…smell singed.\p"
	.string "Were you at a volcano or something?$"
#endif

FortreeCity_Text_SomethingBlockingGym:
#if GERMAN
	.string "Ich wollte zur Pokémon Arena, aber\n"
	.string "irgendetwas blockiert den Weg.\p"
	.string "Und das, nachdem ich auf der Route 120\n"
	.string "so fleißig trainiert habe…$"
#else
	.string "I want to go to the POKéMON GYM,\n"
	.string "but something's blocking the way.\p"
	.string "After all the bother I went through\n"
	.string "training on ROUTE 120…$"
#endif

FortreeCity_Text_ThisTimeIllBeatWinona:
#if GERMAN
	.string "Dieses Pokémon ist mein ganzer Stolz!\n"
	.string "Diesmal werde ich Wibke besiegen!$"
#else
	.string "I've got my pride-and-joy POKéMON\n"
	.string "with me. This time, I'll beat WINONA.$"
#endif

FortreeCity_Text_TreesGrowByDrinkingRainwater:
#if GERMAN
	.string "Der Boden nimmt das Regenwasser auf,\n"
	.string "die Bäume trinken es und wachsen…\p"
	.string "Unser Baumhausen City existiert, weil\n"
	.string "es genügend Wasser und Boden gibt.$"
#else
	.string "The ground absorbs rainwater, and\n"
	.string "trees grow by drinking that water…\p"
	.string "Our FORTREE CITY exists because\n"
	.string "there's both water and soil.$"
#endif

FortreeCity_Text_EveryoneHealthyAndLively:
#if GERMAN
	.string "Die Stadt besteht aus Häusern, die auf\n"
	.string "Bäumen gebaut sind.\p"
	.string "Aufgrund dieser Lebensweise ist jeder\n"
	.string "hier gesund und munter.\p"
	.string "Und auch ich fühle mich, als sei ich\n"
	.string "30 Jahre jünger geworden.$"
#else
	.string "The CITY consists of homes built on\n"
	.string "trees.\p"
	.string "Perhaps because of that lifestyle,\n"
	.string "everyone is healthy and lively.\p"
	.string "Why, even myself--I feel as if I've\n"
	.string "grown thirty years younger.$"
#endif

FortreeCity_Text_BugPokemonComeThroughWindow:
#if GERMAN
	.string "Auf Bäumen zu leben, ist klasse.\p"
	.string "Aber manchmal kommen Käfer-Pokémon\n"
	.string "durch die Fenster herein.\l"
	.string "Das kann einen ganz schön erschrecken.$"
#else
	.string "Living on top of trees is okay.\p"
	.string "But sometimes BUG POKéMON come in\n"
	.string "through windows.\l"
	.string "It can be really startling.$"
#endif

FortreeCity_Text_PokemonThatEvolveWhenTraded:
#if GERMAN
	.string "Manche Pokémon entwickeln sich, wenn\n"
	.string "man sie tauscht. Das habe ich\l"
	.string "jedenfalls gehört.$"
#else
	.string "There are POKéMON that evolve when\n"
	.string "you trade them! That's what I heard.$"
#endif

FortreeCity_Text_SomethingUnseeable:
#if GERMAN
	.string "Etwas Unsichtbares blockiert den Weg.$"
#else
	.string "Something unseeable is in the way.$"
#endif

FortreeCity_Text_UnseeableUseDevonScope:
#if GERMAN
	.string "Etwas Unsichtbares blockiert den Weg.\p"
	.string "Willst du das Devon-Scope einsetzen?$"
#else
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"
#endif

FortreeCity_Text_UsedDevonScopePokemonFled:
#if GERMAN
	.string "{PLAYER} setzt das Devon-Scope ein.\p"
	.string "Ein unsichtbares Pokémon ist sichtbar\n"
	.string "geworden!\p"
	.string "Das erschrockene Pokémon flieht!$"
#else
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible POKéMON became completely\n"
	.string "visible!\p"
	.string "The startled POKéMON fled!$"
#endif

FortreeCity_Text_CitySign:
#if GERMAN
	.string "Baumhausen City “Die Stadt in den\n"
	.string "Baumkronen, verbrüdert mit der Natur.”$"
#else
	.string "FORTREE CITY\n"
	.string "“The treetop city that frolics with\l"
	.string "nature.”$"
#endif

FortreeCity_Text_GymSign:
#if GERMAN
	.string "Pokémon Arena von Baumhausen City\n"
	.string "Leiterin: Wibke\p"
	.string "“Die Vogel-Liebhaberin hebt ab zum\n"
	.string "Flug in die Welt.”$"
#else
	.string "FORTREE CITY POKéMON GYM\n"
	.string "LEADER: WINONA\p"
	.string "“The bird user taking flight into\n"
	.string "the world.”$"
#endif

