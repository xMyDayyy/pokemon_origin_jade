ReceptionGate_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ReceptionGate_OnTransition
	.byte 0

@ Origin Jade: the Black Belt in front of the Mt. Silver exit is gone once
@ Johto's league is won.
ReceptionGate_OnTransition:
	call_if_set FLAG_IS_JOHTO_CHAMPION, ReceptionGate_EventScript_HideSilverGuard
	end

ReceptionGate_EventScript_HideSilverGuard:
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	return

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
#if GERMAN
	.string "Janina: Ich bin auf dem Weg zu\n"
	.string "meinem Vater, um ihm das\l"
	.string "Mittagessen zu bringen.\p"
	.string "Die Top Vier hat keine Zeit für\n"
	.string "Erholung, Tag oder Nacht.\p"
	.string "Es ist wirklich harte Arbeit,\n"
	.string "weißt du?\p"
	.string "Wenn du bereit für einen weiteren\n"
	.string "Kampf bist, ich bin später im Dojo.$"
#else
	.string "JANINE: I'm on the way to my dad's\n"
	.string "house to give him his lunch.\p"
	.string "The ELITE FOUR has no time to rest\n"
	.string "day or night. It's such hard work,\l"
	.string "you know?\p"
	.string "If you're ready for another\n"
	.string "battle, I'll be at the DOJO later.$"
#endif


ReceptionGate_EventScript_Officer::
	lock
	faceplayer
	specialvar VAR_RESULT, CountJohtoBadges
	goto_if_lt VAR_RESULT, 8, ReceptionGate_EventScript_OfficerCheckpoint
	goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_OfficerLegendary
	msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
	release
	end

ReceptionGate_EventScript_OfficerCheckpoint::
	msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
	release
	end

ReceptionGate_EventScript_OfficerLegendary::
	msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
	release
	end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
#if GERMAN
	.string "Nur Trainer, die sich als würdig\n"
	.string "erwiesen haben, dürfen eintreten.$"
#else
	.string "Only trainers who have proven\n"
	.string "themselves may pass.$"
#endif

VictoryRoadGate_Text_Kimono:
#if GERMAN
	.string "Tut mir leid, dieser Weg bleibt\n"
	.string "gesperrt, bis sich jemand um das\l"
	.string "legendäre Pokémon kümmert…$"
#else
	.string "Sorry kid, this way is closed until\n"
	.string "someone deals with that LEGENDARY\l"
	.string "POKéMON...$"
#endif

VictoryRoadGate_Text_EightBadges:
#if GERMAN
	.string "Oh! Alle acht Orden von Johto!\p"
	.string "Geh bitte weiter!$"
#else
    .string "Oh! The eight BADGES of JOHTO!\p"
    .string "Please, go right on through!$"
#endif

VictoryRoadGate_Text_LeftBlackBelt:
#if GERMAN
	.string "Dieser Weg führt zum Silberberg.\p"
	.string "Dir werden beängstigend starke\n"
	.string "Pokémon begegnen.$"
#else
    .string "This way leads to MT.SILVER.\p"
    .string "You'll see scary-strong POKéMON out\n"
    .string "there.$"
#endif

@ ============================================================================
@ Origin Jade: gate checks. East = Kanto, north = league, south = Johto,
@ west = Mt. Silver. Each check has its own temp var: Johto VAR_TEMP_5,
@ Mt. Silver VAR_TEMP_6, league VAR_TEMP_7.
@ ============================================================================

ReceptionGate_EventScript_BlockJohto::
	lock
	goto_if_set FLAG_SYS_GAME_CLEAR, ReceptionGate_EventScript_PassJohto
	applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox ReceptionGate_Text_JohtoClosed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	release
	end

ReceptionGate_EventScript_PassJohto::
	setvar VAR_TEMP_5, 1
	release
	end

ReceptionGate_EventScript_BlockMtSilver::
	lock
	goto_if_set FLAG_IS_JOHTO_CHAMPION, ReceptionGate_EventScript_PassMtSilver
	msgbox ReceptionGate_Text_MtSilverClosed, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	release
	end

ReceptionGate_EventScript_PassMtSilver::
	setvar VAR_TEMP_6, 1
	release
	end

ReceptionGate_Text_JohtoClosed:
#if GERMAN
	.string "Halt! Hinter diesem Tor beginnt\n"
	.string "Johto.\p"
	.string "Der Weg ist gesperrt, solange die\n"
	.string "Top Vier nicht besiegt sind.\p"
	.string "Erst musst du dich hier beweisen.$"
#else
	.string "Hold it! Beyond this gate lies\n"
	.string "JOHTO.\p"
	.string "The road stays closed until the\n"
	.string "ELITE FOUR have been defeated.\p"
	.string "Prove yourself here first.$"
#endif

ReceptionGate_Text_MtSilverClosed:
#if GERMAN
	.string "Der Weg zum Silberberg ist\n"
	.string "gesperrt.\p"
	.string "Dort draußen hausen Pokémon, gegen\n"
	.string "die selbst die Top Vier alt\l"
	.string "aussehen.\p"
	.string "Kantos Orden zählen hier nicht.\n"
	.string "Komm wieder, wenn du auch Johtos\l"
	.string "Liga geschlagen hast.$"
#else
	.string "The road to MT.SILVER is closed.\p"
	.string "The POKéMON out there would make\n"
	.string "even the ELITE FOUR look tame.\p"
	.string "KANTO BADGES don't count here. Come\n"
	.string "back when you've beaten JOHTO's\l"
	.string "LEAGUE too.$"
#endif

ReceptionGate_EventScript_LeagueCheck::
	lock
	goto_if_unset FLAG_BADGE01_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE02_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE03_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE04_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE05_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE06_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE07_GET, ReceptionGate_EventScript_LeagueDenied
	goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_LeagueDenied
	setvar VAR_TEMP_7, 1
	release
	end

ReceptionGate_EventScript_LeagueDenied::
	msgbox ReceptionGate_Text_LeagueDenied, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	release
	end

ReceptionGate_Text_LeagueDenied:
#if GERMAN
	.string "Nur Trainer mit allen acht Orden\n"
	.string "von Kanto dürfen zur Siegesstraße.\p"
	.string "Komm wieder, wenn du so weit bist.$"
#else
	.string "Only trainers with all eight BADGES\n"
	.string "of KANTO may enter VICTORY ROAD.\p"
	.string "Come back when you're ready.$"
#endif
