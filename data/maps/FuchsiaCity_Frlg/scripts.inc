FuchsiaCity_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_OnTransition
	.byte 0

FuchsiaCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_FUCHSIA_CITY
	call_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetOmanyteGfx
	call_if_unset FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_SetKabutoGfx
	end

FuchsiaCity_EventScript_SetOmanyteGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OMANYTE
	return

FuchsiaCity_EventScript_SetKabutoGfx::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_KABUTO
	return

FuchsiaCity_EventScript_LittleBoy::
	msgbox FuchsiaCity_Text_DidYouTrySafariGame, MSGBOX_NPC
	end

FuchsiaCity_EventScript_OldMan::
	msgbox FuchsiaCity_Text_SafariZoneZooInFront, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Erik::
	msgbox FuchsiaCity_Text_WheresSara, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_ItemBallInThere, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Lass::
	lock
	faceplayer
	famechecker FAMECHECKER_KOGA, 3
	msgbox FuchsiaCity_Text_MyFatherIsGymLeader
	release
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_CitySign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZoneSign::
	msgbox FuchsiaCity_Text_SafariZoneSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariGameSign::
	msgbox FuchsiaCity_Text_SafariGameSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_WardensHomeSign::
	msgbox FuchsiaCity_Text_WardensHomeSign, MSGBOX_SIGN
	end

@ Unused
FuchsiaCity_EventScript_SafariZoneOfficeSign::
	msgbox FuchsiaCity_Text_SafariZoneOfficeSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	lockall
	call PokemonLeague_EventScript_CheckLeagueChanged
	goto_if_eq VAR_RESULT, TRUE, FuchsiaCity_EventScript_GymSignJanine
	famechecker FAMECHECKER_KOGA, 0
	msgbox FuchsiaCity_Text_GymSign
	releaseall
	end

@ Janina leads the gym after the league change, see docs/origin_jade/DECISIONS.md, D-032.
FuchsiaCity_EventScript_GymSignJanine::
	msgbox FuchsiaCity_Text_GymSignJanine
	releaseall
	end

FuchsiaCity_EventScript_ChanseySign::
	lockall
	setvar VAR_0x8004, SPECIES_CHANSEY
	special SetSeenMon
	showmonpic SPECIES_CHANSEY, 10, 3
	msgbox FuchsiaCity_Text_ChanseySign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_VoltorbSign::
	lockall
	setvar VAR_0x8004, SPECIES_VOLTORB
	special SetSeenMon
	showmonpic SPECIES_VOLTORB, 10, 3
	msgbox FuchsiaCity_Text_VoltorbSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_KangaskhanSign::
	lockall
	setvar VAR_0x8004, SPECIES_KANGASKHAN
	special SetSeenMon
	showmonpic SPECIES_KANGASKHAN, 10, 3
	msgbox FuchsiaCity_Text_KangaskhanSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_SlowpokeSign::
	lockall
	setvar VAR_0x8004, SPECIES_SLOWPOKE
	special SetSeenMon
	showmonpic SPECIES_SLOWPOKE, 10, 3
	msgbox FuchsiaCity_Text_SlowpokeSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_LaprasSign::
	lockall
	setvar VAR_0x8004, SPECIES_LAPRAS
	special SetSeenMon
	showmonpic SPECIES_LAPRAS, 10, 3
	msgbox FuchsiaCity_Text_LaprasSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_FossilMonSign::
	lockall
	goto_if_set FLAG_GOT_DOME_FOSSIL, FuchsiaCity_EventScript_OmanyteSign
	setvar VAR_0x8004, SPECIES_KABUTO
	special SetSeenMon
	showmonpic SPECIES_KABUTO, 10, 3
	msgbox FuchsiaCity_Text_KabutoSign
	hidemonpic
	releaseall
	end

FuchsiaCity_EventScript_OmanyteSign::
	setvar VAR_0x8004, SPECIES_OMANYTE
	special SetSeenMon
	showmonpic SPECIES_OMANYTE, 10, 3
	msgbox FuchsiaCity_Text_OmanyteSign
	hidemonpic
	releaseall
	end

FuchsiaCity_Text_DidYouTrySafariGame::
#if GERMAN
	.string "Hast du schon das Safari-Spiel\n"
	.string "gespielt?\p"
	.string "Manche Pokémon kann man nur dabei\n"
	.string "fangen!$"
#else
	.string "Did you try the SAFARI GAME?\p"
	.string "There are some rare POKéMON that\n"
	.string "can only be caught there.$"
#endif

FuchsiaCity_Text_SafariZoneZooInFront::
#if GERMAN
	.string "Vor dem Eingang zur Safari-Zone\n"
	.string "befindet sich ein Zoo.\p"
	.string "Das Safari-Spiel ist ideal, um\n"
	.string "Pokémon zu fangen.$"
#else
	.string "The SAFARI ZONE has a zoo in front\n"
	.string "of the entrance.\p"
	.string "Out back is the SAFARI GAME for\n"
	.string "catching POKéMON.$"
#endif

FuchsiaCity_Text_WheresSara::
#if GERMAN
	.string "Erik: Wo ist Sara? Ich wollte mich\n"
	.string "hier mit ihr treffen!$"
#else
	.string "ERIK: Where's SARA?\n"
	.string "I said I'd meet her here.$"
#endif

FuchsiaCity_Text_ItemBallInThere::
#if GERMAN
	.string "Dieser Ball dort ist tatsächlich ein\n"
	.string "Pokémon?!$"
#else
	.string "That item ball in there…\n"
	.string "Were you wanting that?\p"
	.string "Me, too!\n"
	.string "…Huh? That's a POKéMON?$"
#endif

FuchsiaCity_Text_CitySign::
#if GERMAN
	.string "Fuchsania City\n"
	.string "Die Stadt der rosaroten Träume!$"
#else
	.string "FUCHSIA CITY\n"
	.string "Behold! It's Passion Pink!$"
#endif

FuchsiaCity_Text_SafariZoneSign::
#if GERMAN
	.string "Pokémon-Paradies\n"
	.string "Safari-Zone$"
#else
	.string "POKéMON PARADISE\n"
	.string "SAFARI ZONE$"
#endif

FuchsiaCity_Text_SafariGameSign::
#if GERMAN
	.string "Safari-Spiel\n"
	.string "Pokémon-Fangen!$"
#else
	.string "SAFARI GAME\n"
	.string "POKéMON-U-CATCH!$"
#endif

FuchsiaCity_Text_WardensHomeSign::
#if GERMAN
	.string "Safari-Zone\n"
	.string "Haus des Wärters$"
#else
	.string "SAFARI ZONE\n"
	.string "WARDEN'S HOME$"
#endif

FuchsiaCity_Text_SafariZoneOfficeSign::
#if GERMAN
	.string "Pokémon-Paradies Willkommen in der\n"
	.string "Safari-Zone Büro der Safari-Zone$"
#else
	.string "POKéMON PARADISE!\n"
	.string "Welcome to the SAFARI ZONE!\l"
	.string "SAFARI ZONE OFFICE$"
#endif

FuchsiaCity_Text_GymSignJanine::
#if GERMAN
	.string "Fuchsania City Pokémon-Arena\n"
	.string "Arenaleiterin: Janina$"
#else
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: JANINE$"
#endif

FuchsiaCity_Text_GymSign::
#if GERMAN
	.string "Fuchsania City Pokémon-Arena\n"
	.string "Arenaleiter: Koga Der Giftige\l"
	.string "Ninja-Meister!$"
#else
	.string "FUCHSIA CITY POKéMON GYM\n"
	.string "LEADER: KOGA\l"
	.string "The Poisonous Ninja Master$"
#endif

FuchsiaCity_Text_ChanseySign::
#if GERMAN
	.string "Name: Chaneira\p"
	.string "Dieses Pokémon zu fangen, ist reine\n"
	.string "Glückssache!$"
#else
	.string "Name: CHANSEY\n"
	.string "Catching one is all up to chance.$"
#endif

FuchsiaCity_Text_VoltorbSign::
#if GERMAN
	.string "Name: Voltobal\p"
	.string "Dieses Pokémon ähnelt einem\n"
	.string "Pokéball.$"
#else
	.string "Name: VOLTORB\n"
	.string "The very image of a POKé BALL.$"
#endif

FuchsiaCity_Text_KangaskhanSign::
#if GERMAN
	.string "Name: Kangama\p"
	.string "Ein Pokémon, das seinen Nachwuchs\n"
	.string "in einem Beutel am Bauch trägt.$"
#else
	.string "Name: KANGASKHAN\p"
	.string "A maternal POKéMON that raises its\n"
	.string "young in a pouch on its belly.$"
#endif

FuchsiaCity_Text_SlowpokeSign::
#if GERMAN
	.string "Name: Flegmon\p"
	.string "Ein freundliches, aber sehr lahmes\n"
	.string "Pokémon.$"
#else
	.string "Name: SLOWPOKE\n"
	.string "Friendly and very slow moving.$"
#endif

FuchsiaCity_Text_LaprasSign::
#if GERMAN
	.string "Name: Lapras\n"
	.string "Der König der Meere!$"
#else
	.string "Name: LAPRAS\n"
	.string "AKA the king of the seas.$"
#endif

FuchsiaCity_Text_OmanyteSign::
#if GERMAN
	.string "Name: Amonitas\p"
	.string "Ein Pokémon, das aus einem Fossil\n"
	.string "wiedererschaffen wurde.$"
#else
	.string "Name: OMANYTE\n"
	.string "An extremely rare POKéMON that was\l"
	.string "regenerated from a fossil.$"
#endif

FuchsiaCity_Text_KabutoSign::
#if GERMAN
	.string "Name: Kabuto\p"
	.string "Ein Pokémon, das aus einem Fossil\n"
	.string "wiedererschaffen wurde.$"
#else
	.string "Name: KABUTO\n"
	.string "An extremely rare POKéMON that was\l"
	.string "regenerated from a fossil.$"
#endif

@ Unused. May have been meant to be the placeholder text for the zoo mons, similar to RB's "!" text
FuchsiaCity_Text_Ellipsis::
	.string "……$"

Text_SubstituteTeach::
#if GERMAN
	.string "Argh, ich wünschte, ich wäre ein\n"
	.string "Kangama-Baby.\p"
	.string "Ich wäre so gerne an Stelle des\n"
	.string "Babys…\p"
	.string "Und würde mich in den Beutel der\n"
	.string "Mutter Kangama kuscheln.\p"
	.string "Aber nur Pokémon können Delegator\n"
	.string "anwenden…\p"
	.string "Soll ich Delegator einem deiner\n"
	.string "Pokémon beibringen?$"
#else
	.string "Aww, I wish I was a KANGASKHAN\n"
	.string "baby.\p"
	.string "I'd love to be a substitute for the\n"
	.string "baby…\p"
	.string "And snuggle in the mother\n"
	.string "KANGASKHAN's belly pouch.\p"
	.string "But only POKéMON can use the\n"
	.string "technique SUBSTITUTE…\p"
	.string "Want me to teach SUBSTITUTE to\n"
	.string "one of your POKéMON?$"
#endif

Text_SubstituteDeclined::
#if GERMAN
	.string "Oh, wirklich?\n"
	.string "Delegator macht Spaß…$"
#else
	.string "Oh, really?\n"
	.string "SUBSTITUTE seems so fun…$"
#endif

Text_SubstituteWhichMon::
#if GERMAN
	.string "Welches Pokémon soll Delegator\n"
	.string "erlernen?$"
#else
	.string "Which POKéMON wants to learn\n"
	.string "SUBSTITUTE?$"
#endif

Text_SubstituteTaught::
#if GERMAN
	.string "Was ich geben würde, wenn ich in den\n"
	.string "Beutel eines Kangamas klettern\l"
	.string "könnte…$"
#else
	.string "Boy, what I'd give to crawl inside\n"
	.string "a KANGASKHAN belly pouch…$"
#endif

FuchsiaCity_Text_MyFatherIsGymLeader::
#if GERMAN
	.string "Mein Vater ist der Arenaleiter\n"
	.string "dieser Stadt.\p"
	.string "Ich trainiere mit Gift-Pokémon,\n"
	.string "genau wie mein Vater.$"
#else
	.string "My father is the GYM LEADER of\n"
	.string "this town.\p"
	.string "I'm training to use POISON POKéMON\n"
	.string "as well as my father.$"
#endif

