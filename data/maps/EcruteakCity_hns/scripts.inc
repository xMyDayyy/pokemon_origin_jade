EcruteakCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, FALSE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1

	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
#if GERMAN
	.string "Rumms!$"
#else
	.string "THUD!!$"
#endif

EcruteakCity_Text_Silver2:
#if GERMAN
	.string "{RIVAL}: Warum, warum, warum?!?\n"
	.string "Warum kann ich nur nicht gewinnen?!?\p"
	.string "Dabei war mein Gegner doch nur so\n"
	.string "ein mickriges Kimono-Girl!$"
#else
	.string "{RIVAL}: How...? How is this\n"
	.string "possible? How can I lose to mere\l"
	.string "KIMONO GIRLS...?$"
#endif

EcruteakCity_Text_Silver3:
#if GERMAN
	.string "{RIVAL}: Hast du mir zugesehen,\n"
	.string "{PLAYER}?\p"
	.string "Ja, ich habe verloren.\p"
	.string "Und ich dachte noch, es würde ein\n"
	.string "Kinderspiel, alle fünf Kimono-Girls der\l"
	.string "Reihe nach plattzumachen… aber sie\l"
	.string "waren mir haushoch überlegen.\p"
	.string "… … …\p"
	.string "Du bist bestimmt auch hier, um die\n"
	.string "Kimono-Girls herauszufordern, oder?\p"
	.string "Ruhe dich aber nicht auf den Lorbeeren\n"
	.string "deines Siegs über Team Rocket aus!\p"
	.string "Diese Kimono-Girls sind nämlich echt\n"
	.string "unglaublich stark.\p"
	.string "Aber geh nur!\p"
	.string "Versuch’s ruhig!\p"
	.string "Mich kriegt da niemand mehr rein.\p"
	.string "Ich habe keine Lust, dir dabei\n"
	.string "zuzusehen, wie du gewinnst.$"
#else
	.string "{RIVAL}: You were watching me,\n"
	.string "{PLAYER}...\p"
	.string "Yeah, that's right!\p"
	.string "I never thought defeating five\n"
	.string "KIMONO GIRLS would be so hard...\p"
	.string "I got beaten to a pulp...\p"
	.string "...\p"
	.string "You must have come here for the\n"
	.string "same reason, right?\p"
	.string "Don't get cocky just because you\n"
	.string "defeated TEAM ROCKET!\p"
	.string "These KIMONO GIRLS are insanely\n"
	.string "strong.\p"
	.string "See if you can defeat them.\p"
	.string "But I'm not going back, I don't\n"
	.string "want to see you win.$"
#endif

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
#if GERMAN
	.string "Evoli: Veee!$"
#else
	.string "EEVEE: Veee!$"
#endif

EcruteakCity_Text_Vulpix:
#if GERMAN
	.string "Vulpix: Vullll Pix!$"
#else
	.string "VULPIX: Vullll Pix!$"
#endif


EcruteakCity_Text_UnusedMissingDaughter:
#if GERMAN
	.string "Oh nein. Oh nein…\p"
	.string "Meine Tochter ist verschwunden.\p"
	.string "Nein… Sie kann doch nicht in den\n"
	.string "Turmruine gegangen sein!$"
#else
	.string "Oh, no. Oh, no…\p"
	.string "My daughter is missing.\p"
	.string "No… She couldn't have gone to the\n"
	.string "BURNED TOWER.\p"
	.string "I told her not to go near it…\p"
	.string "People seem to disappear there…\p"
	.string "Oh, what should I do…?$"
#endif

EcruteakCity_Text_Gramps1:
#if GERMAN
	.string "Es gab wohl mal zwei Türme in Teak City,\n"
	.string "einen im Osten und einen im Westen…$"
#else
	.string "ECRUTEAK used to have two towers:\n"
	.string "one each in the east and west.$"
#endif

EcruteakCity_Text_Gramps2:
#if GERMAN
	.string "Na, Kröte? Hast du gelernt zu\n"
	.string "tanzen wie die Kimono-Girls?\p"
	.string "Ich habe gehört, dass dir ein\n"
	.string "eigenartiger Mann etwas Nettes geben\l"
	.string "wird,\p"
	.string "wenn du zu ihrem Tanztheater gehst.$"
#else
	.string "Ah, child. Have you learned to\n"
	.string "dance like the KIMONO GIRLS?\p"
	.string "If you go to their DANCE THEATER,\n"
	.string "an odd old man will give you\l"
	.string "something nice, I hear.$"
#endif

EcruteakCity_Text_Lass1:
#if GERMAN
	.string "Ich bin auf dem Weg zum Tanztheater,\n"
	.string "um Tanzen zu üben. Kommst du mit?$"
#else
	.string "I'm going to practice at the DANCE\n"
	.string "THEATER. Care to join me?$"
#endif

EcruteakCity_Text_Lass2:
#if GERMAN
	.string "Der Turm, der früher hier stand…\p"
	.string "Meine Oma sagte mir, dass er früher\n"
	.string "höher war.$"
#else
	.string "The tower that used to be here…\p"
	.string "My grandma told me it used to be\n"
	.string "much taller.\p"
	.string "I hear there are ghosts in it now.$"
#endif

EcruteakCity_Text_Lass2_ReleasedBeasts:
#if GERMAN
	.string "Hier sind eben drei große Pokémon an mir\n"
	.string "vorbeigerannt und in verschiedene\l"
	.string "Richtungen verschwunden.\l"
	.string "Was war da bloß los?$"
#else
	.string "Three big POKéMON ran off in different\n"
	.string "directions. What were they?$"
#endif

EcruteakCity_Text_Fisher:
#if GERMAN
	.string "Es kursiert ein Gerücht über den\n"
	.string "Leuchtturm in Oliviana City.\p"
	.string "Das Pokémon, das als Leuchtfeuer\n"
	.string "dient, wurde krank.\p"
	.string "Sieht so aus, als wären sie in\n"
	.string "Schwierigkeiten.$"
#else
	.string "I heard a rumor about OLIVINE\n"
	.string "LIGHTHOUSE.\p"
	.string "The POKéMON that serves as the\n"
	.string "beacon fell ill. Sounds like they\l"
	.string "are in trouble.$"
#endif

EcruteakCity_Text_Fisher_JasmineReturned:
#if GERMAN
	.string "Das Pokémon im Leuchtturm von Oliviana\n"
	.string "City wurde geheilt.\p"
	.string "Jetzt können die Schiffe wieder\n"
	.string "gefahrlos nachts in See stechen.$"
#else
	.string "The POKéMON at OLIVINE LIGHTHOUSE\n"
	.string "has been cured.\p"
	.string "Boats can safely sail out to sea at\n"
	.string "night again.$"
#endif

EcruteakCity_Text_Youngster:
#if GERMAN
	.string "Ich hörte, dass Pokémon am See des\n"
	.string "Zorns Unruhe stiften.\p"
	.string "Das würde ich gerne sehen.$"
#else
	.string "I hear POKéMON are rampaging at the\n"
	.string "LAKE OF RAGE. I'd like to see that.$"
#endif

EcruteakCity_Text_Gramps3:
#if GERMAN
	.string "Vor langer Zeit…\n"
	.string "Ist dieser Turm abgebrannt.\p"
	.string "Drei namenlose Pokémon sind dabei\n"
	.string "umgekommen.\p"
	.string "Ein regenbogenfarbenes Pokémon kam\n"
	.string "herab und hauchte ihnen wieder Leben\l"
	.string "ein…\p"
	.string "Diese Legende wird von jedem Leiter der\n"
	.string "Pokémon-Arena von Teak City an den\l"
	.string "nächsten weitergegeben.\p"
	.string "Ich?\p"
	.string "Damals war ich ein Trainer. Hohoho!$"
#else
	.string "In the distant past…\p"
	.string "This tower burned in a fire. Three\n"
	.string "nameless POKéMON perished in it.\p"
	.string "A rainbow-colored POKéMON descended\n"
	.string "from the sky and resurrected them…\p"
	.string "It's a legend that has been passed\n"
	.string "down by ECRUTEAK GYM LEADERS.\p"
	.string "Me?\p"
	.string "I was a trainer way back when.\n"
	.string "Hohoho!$"
#endif

EcruteakCity_Text_SageGym:
#if GERMAN
	.string "Arenaleiter Jens ist gerade nicht hier.\n"
	.string "Du kannst ihn vielleicht an der\l"
	.string "Turmruine finden.$"
#else
	.string "Gym Leader MORTY is not here right\n"
	.string "now. You may find him at the\l"
	.string "BURNED TOWER.$"
#endif

EcruteakCity_Text_Sign:
#if GERMAN
	.string "Teak City Eine historische Stadt, wo\n"
	.string "Vergangenheit und Gegenwart\l"
	.string "aufeinandertreffen$"
#else
	.string "ECRUTEAK CITY\n"
	.string "A Historical City\p"
	.string "Where the Past Meets the Present$"
#endif

EcruteakCity_Text_TinTowerSign:
#if GERMAN
	.string "Glockenturm\p"
	.string "Hier soll ein legendäres Pokémon\n"
	.string "ruhen.$"
#else
	.string "TIN TOWER\p"
	.string "A legendary POKéMON is said to\n"
	.string "roost here.$"
#endif

EcruteakCity_Text_OfficeSign:
#if GERMAN
	.string "Kontrollposten vor dem Glockenturm\n"
	.string "Kein Zutritt für Unbefugte!$"
#else
	.string "Barrier Station to TIN TOWER\p"
	.string "No Trespassing by the Unworthy.$"
#endif

EcruteakCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Teak City Leiter:\n"
	.string "Jens Der bescheidene Hellseher$"
#else
	.string "ECRUTEAK CITY POKéMON GYM\n"
	.string "LEADER: MORTY\p"
	.string "The Mystic Seer of the Future$"
#endif

EcruteakCity_Text_DanceTheaterSign:
#if GERMAN
	.string "Tanztheater von Teak City$"
#else
	.string "ECRUTEAK DANCE THEATER$"
#endif

EcruteakCity_Text_BurnedTowerSign:
#if GERMAN
	.string "Diese Ruinen sind die Reste eines Turms,\n"
	.string "der einst einem Brandunglück zum Opfer\l"
	.string "fiel, das nie aufgeklärt werden konnte.\p"
	.string "Mach besser einen großen Bogen um\n"
	.string "diese Gemäuer, denn in ihrem Inneren\l"
	.string "könnte es gefährlich werden!$"
#else
	.string "BURNED TOWER\p"
	.string "It was destroyed by a mysterious\n"
	.string "fire.\p"
	.string "Please stay away, as it is unsafe.$"
#endif
