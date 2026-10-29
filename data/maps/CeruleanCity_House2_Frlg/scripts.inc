CeruleanCity_House2_Frlg_MapScripts::
	.byte 0

CeruleanCity_House2_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM28_FROM_ROCKET, CeruleanCity_House2_EventScript_HikerGotTM28
	msgbox CeruleanCity_House2_Text_RocketsStoleTMForDig
	release
	end

CeruleanCity_House2_EventScript_HikerGotTM28::
	msgbox CeruleanCity_House2_Text_TeachDiglettDigWithoutTM
	release
	end

CeruleanCity_House2_EventScript_Lass::
	msgbox CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood, MSGBOX_NPC
	end

CeruleanCity_House2_EventScript_WallHole::
	msgbox CeruleanCity_House2_Text_TeamRocketLeftWayOut, MSGBOX_SIGN
	end

CeruleanCity_House2_Text_RocketsStoleTMForDig::
#if GERMAN
	.string "Dieses gemeine Team Rocket!\p"
	.string "Hör dir an, was sie wieder verbrochen\n"
	.string "haben!\p"
	.string "Sie haben den Schaufler gestohlen, eine\n"
	.string "TM, mit der Pokémon Löcher graben\l"
	.string "können!\p"
	.string "Der Schaufler war sündhaft teuer!$"
#else
	.string "Those miserable ROCKETS!\p"
	.string "Look what they've done to my\n"
	.string "house!\p"
	.string "They stole a TM for teaching\n"
	.string "POKéMON how to DIG holes!\p"
	.string "I was going to use it on a\n"
	.string "MANKEY or a SANDSHREW…\p"
	.string "That cost me a bundle, it did!$"
#endif

CeruleanCity_House2_Text_TeachDiglettDigWithoutTM::
#if GERMAN
	.string "Was weg ist, ist weg!\p"
	.string "Dann bringe ich meinem Digda\n"
	.string "Schaufler eben ohne TM bei!$"
#else
	.string "I figure what's lost is lost.\p"
	.string "I decided to teach DIGLETT how to\n"
	.string "DIG without a TM.$"
#endif

CeruleanCity_House2_Text_TeamRocketTryingToDigIntoNoGood::
#if GERMAN
	.string "Das Team Rocket braucht den Schaufler\n"
	.string "sicher für irgendeine Schandtat!$"
#else
	.string "TEAM ROCKET must be trying to DIG\n"
	.string "their way into no good!$"
#endif

CeruleanCity_House2_Text_TeamRocketLeftWayOut::
#if GERMAN
	.string "Das Team Rocket hat Spuren\n"
	.string "hinterlassen!$"
#else
	.string "TEAM ROCKET left a way out!$"
#endif

