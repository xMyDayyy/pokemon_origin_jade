Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_IS_HOENN_CHAMPION, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_5, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_2, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_3, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_WEATHER_INSTITUTE, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_1
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_2
	removeobject LOCALID_WEATHER_INSTITUTE_2F_SHELLY
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_4
	removeobject LOCALID_WEATHER_INSTITUTE_2F_GRUNT_3
	applymovement LOCALID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_WEATHER_INSTITUTE_2F_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM_NORMAL
	givemon SPECIES_CASTFORM_NORMAL, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM_NORMAL
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_IS_HOENN_CHAMPION, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	@ Counts Kyogre and Groudon that cannot be met now (see docs/origin_jade/DECISIONS.md, D-026).
	setvar VAR_0x8005, 0
	setvar VAR_0x8004, LEGENDARY_KYOGRE
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_ne VAR_RESULT, TRUE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	setvar VAR_0x8004, LEGENDARY_GROUDON
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_ne VAR_RESULT, TRUE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8005, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Neither can be met
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8005, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
#if GERMAN
	.string "Das Institut hat ein Pokémon ent-\n"
	.string "wickelt, das irgendwas mit dem Wetter\l"
	.string "zu tun hat. Das müssen wir kriegen!$"
#else
	.string "The INSTITUTE created a type of\n"
	.string "POKéMON that has something to do with\l"
	.string "the weather. We're here to take them!$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
#if GERMAN
	.string "Ein Kind hat unsere Pläne durchkreuzt?$"
#else
	.string "Our plan's being spoiled by a kid?$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
#if GERMAN
	.string "Wenn sie hier tatsächlich ein Pokémon\n"
	.string "entwickelt haben, das das Wetter\l"
	.string "kontrollieren kann, müssen wir von Team\l"
	.string "Aqua es in unsere Gewalt bringen!$"
#else
	.string "If the POKéMON they made here can\n"
	.string "control the weather freely, then we of\l"
	.string "TEAM AQUA definitely need it!$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
#if GERMAN
	.string "Wir sind Team Aqua!\n"
	.string "Wir sind überall dort, wo Raritäten\l"
	.string "gefunden wurden!$"
#else
	.string "We're TEAM AQUA!\n"
	.string "We appear wherever anything rare is\l"
	.string "found!$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
#if GERMAN
	.string "Das war’s dann wohl!$"
#else
	.string "You got me!$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
#if GERMAN
	.string "Du hast doch gar keine Ahnung, was wir\n"
	.string "von Team Aqua vorbereiten!\l"
	.string "Geh uns gefälligst aus dem Weg!$"
#else
	.string "You don't have any idea what we of\n"
	.string "TEAM AQUA are working towards!\l"
	.string "You stay out of our way!$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
#if GERMAN
	.string "Jetzt sag nicht, du bist auch auf der\n"
	.string "Suche nach diesem Wetter-Pokémon?\p"
	.string "Das erlaube ich nicht!\n"
	.string "Wir waren schließlich zuerst hier!$"
#else
	.string "Don't tell me you're looking for that\n"
	.string "weather POKéMON, too?\p"
	.string "That's a no-no!\n"
	.string "We were here to get it first!$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
#if GERMAN
	.string "Nun schau dir meine Pokémon an.$"
#else
	.string "Oh, will you look at my POKéMON?$"
#endif

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
#if GERMAN
	.string "Hmpf… Was soll’s?!?\n"
	.string "Das, was wir suchen…\p"
	.string "ist sowieso nicht hier zu finden…\n"
	.string "Hihihihihihihiiiii…$"
#else
	.string "Humph, so what?\n"
	.string "What we want…\p"
	.string "What we really want isn't here…\n"
	.string "Ihihihihi…$"
#endif

Route119_WeatherInstitute_2F_Text_ShellyIntro:
#if GERMAN
	.string "Ahahahahaha!!!\p"
	.string "Du willst dich allen Ernstes in die\n"
	.string "Angelegenheiten von Team Aqua\l"
	.string "einmischen?\p"
	.string "\p"
	.string "Dann bist du entweder furchtlos oder\n"
	.string "einfach dumm! Oder beides?\p"
	.string "Du bist ja so niedlich. Einfach wider-\n"
	.string "lich! Ich mach dich fertig, du Baby!$"
#else
	.string "Ahahahaha!\p"
	.string "You're going to meddle in TEAM AQUA's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I'll put you down, kiddy!$"
#endif

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
#if GERMAN
	.string "Ahahahahaha!!!!!\n"
	.string "Du bist einfach widerlich… stark!$"
#else
	.string "Ahahahaha!\n"
	.string "You're disgustingly strong!$"
#endif

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
#if GERMAN
	.string "Es ist schon schlimm genug, sich\n"
	.string "ständig mit Team Magma auseinander-\p"
	.string "setzen zu müssen, und jetzt kommst du\n"
	.string "auch noch daher!\p"
	.string "Warum musst du deine spitze Nase in\n"
	.string "Dinge stecken, die dich nichts angehen?$"
#else
	.string "It's bad enough to have TEAM MAGMA\n"
	.string "blunder about, but now there's you!\p"
	.string "What makes you want to sniff around\n"
	.string "in our business, anyway?$"
#endif

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
#if GERMAN
	.string "Wir haben hier eine Krisensituation!\p"
	.string "Eine Gruppe von Team Magma ist gerade\n"
	.string "am Klima-Institut vorbeigelaufen!\p"
	.string "Sie ist wohl auf dem Weg zum Pyroberg!$"
#else
	.string "We have a situation here!\p"
	.string "A TEAM MAGMA mob just passed\n"
	.string "the WEATHER INSTITUTE.\p"
	.string "They appear to be headed for\n"
	.string "MT. PYRE!$"
#endif

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
#if GERMAN
	.string "Was?!?\n"
	.string "Dann lasst uns von hier verschwinden!\l"
	.string "\p"
	.string "Und zwar schnell! Wir müssen so\n"
	.string "schnell wie möglich zum Pyroberg!\p"
	.string "Ahahahahahaha!\n"
	.string "Team Magma, mach dich auf was gefasst!$"
#else
	.string "What?!\p"
	.string "We can't waste any more time here!\n"
	.string "We have to hurry to MT. PYRE, too!\p"
	.string "Ahahahaha!\n"
	.string "TEAM MAGMA, just you wait!$"
#endif

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
#if GERMAN
	.string "Danke! Vielen Dank! Nun sind wir in\n"
	.string "Sicherheit! \p"
	.string "Es ist vielleicht eine seltsame Art\n"
	.string "danke zu sagen, aber dieses Pokémon ist\l"
	.string "für dich!$"
#else
	.string "Thanks!\n"
	.string "Thanks to you, we're safe!\p"
	.string "It might be an odd way of thanking you,\n"
	.string "but take this POKéMON.$"
#endif

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
#if GERMAN
	.string "Hm? Du scheinst keinen Platz für\n"
	.string "dieses Pokémon zu haben.$"
#else
	.string "Hm? You don't seem to have any room\n"
	.string "for this POKéMON.$"
#endif

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
#if GERMAN
	.string "{PLAYER} erhält Formeo!$"
#else
	.string "{PLAYER} received CASTFORM!$"
#endif

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
#if GERMAN
	.string "Dieses Pokémon ändert seine Gestalt\n"
	.string "abhängig vom jeweiligen Wetter.\p"
	.string "Hier im Institut gibt es sehr viele\n"
	.string "davon - du kannst es ruhig annehmen.$"
#else
	.string "That POKéMON changes shape according\n"
	.string "to the weather conditions.\p"
	.string "There're plenty of them in the\n"
	.string "INSTITUTE--go ahead and take it.$"
#endif

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
#if GERMAN
	.string "Seit Jahren erforsche ich den Regen,\n"
	.string "aber zu denken, dass Menschen das\l"
	.string "Wetter frei bestimmen können, ist dumm.$"
#else
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"
#endif

Route119_WeatherInstitute_2F_Text_GroudonWeather:
#if GERMAN
	.string "Ich zeichne die Klimaveränderungen in\n"
	.string "der Hoenn-Region auf.\p"
	.string "Im Moment gibt es eine Dürre. Und\n"
	.string "zwar… auf der {STR_VAR_1}.\p"
	.string "Bedeutet das, dass auf der {STR_VAR_1}…$"
#else
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"
#endif

Route119_WeatherInstitute_2F_Text_KyogreWeather:
#if GERMAN
	.string "Ich zeichne die Klimaveränderungen in\n"
	.string "der Hoenn-Region auf.\p"
	.string "Im Moment gibt es starke Niederschläge.\n"
	.string "Und zwar… auf der {STR_VAR_1}.\p"
	.string "Bedeutet das, dass auf der {STR_VAR_1}…$"
#else
	.string "I track weather patterns over\n"
	.string "the HOENN region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"
#endif

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
#if GERMAN
	.string "Das Wetter hat sich beruhigt. Es gibt\n"
	.string "keine außergewöhnlichen Vorkommnisse.\l"
	.string "\p"
	.string "Der gelegentliche Regen ist ein Segen,\n"
	.string "wirklich.$"
#else
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"
#endif

