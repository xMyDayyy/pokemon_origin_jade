OlivineCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	map_script_2 VAR_TRIGGER_ELM_ROCKET_CALL, 1, Mahoganytown_EventScript_RocketTrigger
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	setspeaker OlivineCity_Text_BaobaName
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_BaobaName:
#if GERMAN
	.string "Baoba$"
#else
	.string "BAOBA$"
#endif

OlivineCity_Text_Baoba:
#if GERMAN
	.string "Hallo, {PLAYER}! Ich bin’s,\n"
	.string "Baoba!\p"
	.string "Entschuldige, dass ich dich habe\n"
	.string "warten lassen!\p"
	.string "Sie ist endlich eröffnet, die\n"
	.string "Safari-Zone! Du weißt, wo?\p"
	.string "Du kennst doch das in den Fels\n"
	.string "gehauene Tor in Anemonia City,\l"
	.string "oder?\p"
	.string "Wenn du dort durchgehst,\n"
	.string "erreichst du sie nach einer\l"
	.string "Weile, die Safari-Zone!\p"
	.string "Nun, es liegt nicht gerade auf\n"
	.string "dem Weg, aber schau unbedingt\l"
	.string "einmal vorbei!$"
#else
	.string "{PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "Sorry to have kept you waiting.\n"
	.string "We've finally opened the SAFARI\l"
	.string "ZONE!\p"
	.string "Do you know where it is?\p"
	.string "You know the GATE inside the\n"
	.string "cavern in CIANWOOD CITY?\p"
	.string "If you go through there and walk\n"
	.string "for a short while, you should\l"
	.string "soon see the SAFARI ZONE!\p"
	.string "We're a little out of the way,\n"
	.string "but please come visit!$"
#endif

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0

	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	delay 20

	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
#if GERMAN
	.string "{PLAYER}: … … …\p"
	.string "…Du schon wieder?\p"
	.string "Was stellst du dir eigentlich vor?\n"
	.string "Mit Verlierern wie dir gebe ich mich\l"
	.string "nicht ab.\p"
	.string "Apropos Verlierer: Die Arenaleiterin\n"
	.string "dieser Stadt ist gerade außer Haus.\p"
	.string "Sie kümmert sich wohl gerade um ein\n"
	.string "krankes Pokémon im Leuchtturm.\p"
	.string "…Hmpf! So ein Unfug!\p"
	.string "Ein Pokémon, das zu schwach zum\n"
	.string "Kämpfen ist, ist wertlos!\p"
	.string "Warum trainierst du nicht etwas im\n"
	.string "Leuchtturm?\p"
	.string "Wer weiß, vielleicht wird aus dir ja\n"
	.string "doch noch ein annehmbarer Trainer?$"
#else
	.string "You again?\n"
	.string "There's no need to be alert.\p"
	.string "I don't bother with wimps\n"
	.string "like you.\p"
	.string "Speaking of weaklings, the\n"
	.string "city's GYM LEADER isn't here,\l"
	.string "and is supposedly taking care\l"
	.string "of a sick POKéMON at the\l"
	.string "LIGHTHOUSE.\p"
	.string "Humph! Boo-hoo!\n"
	.string "Just let sick POKéMON go!\p"
	.string "A POKéMON that can't battle\n"
	.string "is worthless!\p"
	.string "Why don't you go train at the\n"
	.string "LIGHTHOUSE?\p"
	.string "Who knows? It may make you a\n"
	.string "bit of a better Trainer!$"
#endif

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_ChargeBeam::
	finditem ITEM_TM_CHARGE_BEAM
	end

@ Aurora Ticket (Birth Island) after the Johto title, see docs/origin_jade/DECISIONS.md, D-029.
OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_JOHTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
#if GERMAN
	.string "Oliviana City Cafe\p"
	.string "Lachs und Aal, Phänomenal.$"
#else
	.string "OLIVINE CAFE\n"
	.string "WHERE STRONG SAILORS ENJOY\l"
	.string "HEARTY MEALS OF STRENGTH$"
#endif

OlivineCity_Text_EonTicketWoman1:
#if GERMAN
	.string "Ich bin Mary!\p"
	.string "Ich mache nur Spaß!\n"
	.string "Aber ich mag ihre Radiosendung!$"
#else
	.string "My name is MARY!\p"
	.string "Just kidding, but I love MARY's\n"
	.string "radio show!$"
#endif

OlivineCity_Text_EonTicketWoman2:
#if GERMAN
	.string "Du musst {PLAYER} sein!!!\p"
	.string "Oh mein Gott! Der Champion!\p"
	.string "Ich hörte von dir in Marys\n"
	.string "Radiosendung!\p"
	.string "Hier, nimm das!$"
#else
	.string "You must be {PLAYER}!!!\p"
	.string "Oh my goodness! The champion!\p"
	.string "I heard about you on MARY's\n"
	.string "radio show!\p"
	.string "Here, take this!$"
#endif

OlivineCity_Text_EonTicketWoman3:
#if GERMAN
	.string "Ich glaube es nicht!\n"
	.string "Ich hab den Champion getroffen!!!$"
#else
	.string "I can't believe I met the\n"
	.string "champion!!!$"
#endif

OlivineCity_Text_Sailor1:
#if GERMAN
	.string "Dunkle Straßen sind nachts gefährlich!\n"
	.string "Dunkle Meeresuntiefen ebenso!\p"
	.string "Ohne das Licht des Leuchtturms sind\n"
	.string "alle Schiffe auf dem Meer gefangen.$"
#else
	.string "Dark roads are dangerous\n"
	.string "at night.\p"
	.string "But in the pitch-black of\n"
	.string "night, the sea is even more\l"
	.string "treacherous!\p"
	.string "Without the beacon of the\n"
	.string "LIGHTHOUSE to guide it,\l"
	.string "no ship can sail.$"
#endif

OlivineCity_Text_YoungsterPokegear:
#if GERMAN
	.string "Dieses Ding da ist doch ein PokéCom!\n"
	.string "Wow, das ist ja sooo cool!$"
#else
	.string "That thing you have--\n"
	.string "it's a POKéGEAR, right?\l"
	.string "Wow, that's cool.$"
#endif

OlivineCity_Text_YoungsterPokedex:
#if GERMAN
	.string "Wow, du hast einen Pokédex!\n"
	.string "Das ist echt cool!$"
#else
	.string "Wow, you have a POKéDEX!\p"
	.string "That is just so awesome.$"
#endif

OlivineCity_Text_Sailor2:
#if GERMAN
	.string "Die Liga führt Jasmin als sechst-\n"
	.string "stärkste Arenaleiterin!\p"
	.string "Pah! So ein Unsinn.\p"
	.string "Niemals könnte Norbert ihren\n"
	.string "Stahl-Pokémon gefährlich werden!\p"
	.string "Reine Bürokratie, wenn du mich fragst.\p"
	.string "Sie ist eine ernst zu nehmende\n"
	.string "Gegnerin, so viel steht fest!$"
#else
	.string "The league has JASMINE\n"
	.string "pegged as the sixth\l"
	.string "strongest GYM LEADER!\p"
	.string "Hah! That's a load of crud.\p"
	.string "There's no way PRYCE could\n"
	.string "hurt JASMINE's STEEL-type\l"
	.string "POKéMON!\p"
	.string "Bureaucracy if you ask me.\p"
	.string "She's something to be feared,\n"
	.string "that's for sure!$"
#endif

OlivineCity_Text_Sign:
#if GERMAN
	.string "Oliviana City\p"
	.string "Das Tor zu einer neuen Welt$"
#else
	.string "OLIVINE CITY\p"
	.string "The Port Closest to Foreign Lands$"
#endif

OlivineCity_Text_PortSign:
#if GERMAN
	.string "Hafen von Oliviana\n"
	.string "City Schnellboot-Pier$"
#else
	.string "OLIVINE PORT\n"
	.string "FAST SHIP PIER$"
#endif

OlivineCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Oliviana City\n"
	.string "Leiterin: Jasmin Ein stahlhartes\l"
	.string "Mädchen!$"
#else
	.string "OLIVINE CITY POKéMON GYM\n"
	.string "LEADER: JASMINE\p"
	.string "The Steel-Clad Defense Girl$"
#endif

OlivineCity_Text_LighthouseSign:
#if GERMAN
	.string "Leuchtturm von Oliviana City\p"
	.string "Auch bekannt als der\n"
	.string "Glitzer-Leuchtturm$"
#else
	.string "OLIVINE LIGHTHOUSE\n"
	.string "Also known as the GLITTER\l"
	.string "LIGHTHOUSE$"
#endif

OlivineCity_Text_BattleTowerSign:
#if GERMAN
	.string "Duellturm Voraus Geöffnet!$"
#else
	.string "TRAINER HILL and\n"
	.string "BATTLE TENTS AHEAD.\p"
	.string "Opening Now!$"
#endif

OlivineCity_Text_Machoke:
#if GERMAN
	.string "Maschock: Cho!$"
#else
	.string "MACHOKE: CHO!$"
#endif
