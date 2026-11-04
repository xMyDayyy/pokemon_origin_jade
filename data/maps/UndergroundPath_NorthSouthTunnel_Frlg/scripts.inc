UndergroundPath_NorthSouthTunnel_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, UndergroundPath_NorthSouthTunnel_OnTransition
	.byte 0

UndergroundPath_NorthSouthTunnel_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_UNDERGROUND_PATH_NORTH_SOUTH_TUNNEL
	end

@ Origin Jade: HnS's Rage Candy Bar trade for TM Explosion.
UndergroundPath_NorthSouthTunnel_EventScript_BaldingMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_EXPLOSION_UNDERGROUND_PATH, UndergroundPath_NorthSouthTunnel_EventScript_BaldingManAfter
	msgbox UndergroundPath_NorthSouthTunnel_Text_BaldingManIntro, MSGBOX_DEFAULT
	checkitem ITEM_RAGE_CANDY_BAR
	goto_if_eq VAR_RESULT, TRUE, UndergroundPath_NorthSouthTunnel_EventScript_BaldingManCandyBar
	closemessage
	release
	end

UndergroundPath_NorthSouthTunnel_EventScript_BaldingManCandyBar::
	playse SE_PIN
	applymovement LOCALID_UNDERGROUND_PATH_BALDING_MAN, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_UNDERGROUND_PATH_BALDING_MAN
	msgbox UndergroundPath_NorthSouthTunnel_Text_BaldingManCandyBar, MSGBOX_DEFAULT
	checkitemspace ITEM_TM_EXPLOSION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	removeitem ITEM_RAGE_CANDY_BAR
	msgbox UndergroundPath_NorthSouthTunnel_Text_BaldingManGaveCandyBar, MSGBOX_DEFAULT
	giveitem ITEM_TM_EXPLOSION
	setflag FLAG_GOT_TM_EXPLOSION_UNDERGROUND_PATH
UndergroundPath_NorthSouthTunnel_EventScript_BaldingManAfter::
	msgbox UndergroundPath_NorthSouthTunnel_Text_BaldingManGaveTM, MSGBOX_DEFAULT
	closemessage
	release
	end

UndergroundPath_NorthSouthTunnel_Text_BaldingManIntro:
#if GERMAN
	.string "Ich…\p"
	.string "Nein, ich will dir-ir-ir…\p"
	.string "Ich will dir nichts Böse-öses-öses…\p"
	.string "Dieser verlassene Ort ist wie ein\n"
	.string "Auffangbecken für böse Jungs-ungs,\l"
	.string "die hier ihr Unwesen…\p"
	.string "Die hier ihr Unwesen treiben-eiben!\p"
	.string "Mann, das macht mich so wüten-ütend…$"
#else
	.string "Don't be afraid, I'm not a bad\n"
	.string "person.\p"
	.string "A place like this...\n"
	.string "attracts mean people.\p"
	.string "They would eventually cause\n"
	.string "trouble...\p"
	.string "It makes me mad just thinking about\n"
	.string "it.$"
#endif

UndergroundPath_NorthSouthTunnel_Text_BaldingManCandyBar:
#if GERMAN
	.string "Oh!\p"
	.string "Das ist ein Wutkeks!\p"
	.string "Her damit!\n"
	.string "Los, gib ihn mir!$"
#else
	.string "Aha!\n"
	.string "That's a RAGE CANDYBAR!\p"
	.string "Can I have it?\n"
	.string "Please!$"
#endif

UndergroundPath_NorthSouthTunnel_Text_BaldingManGaveCandyBar:
#if GERMAN
	.string "{PLAYER} gibt dem Mann aus\n"
	.string "dem Tunnelpfad den Wutkeks.\p"
	.string "Hamm!\p"
	.string "Knusper, knusper, knusper!\p"
	.string "Der ist aber lecker!\p"
	.string "Mampf, mampf, mampf!\p"
	.string "Knusper, knusper, knusper!\p"
	.string "Mampf, mampf, mampf!\p"
	.string "Knusper, knusper, knusper!\p"
	.string "…Puh.\p"
	.string "Jetzt bin ich irgendwie entspannt.\n"
	.string "Danke für den Snack!\l"
	.string "Hier, nimm das als Dankeschön!$"
#else
	.string "{PLAYER} Gave the RageCandyBar to the\n"
	.string "guy at the underground path.\p"
	.string "Munch!\p"
	.string "How upsetting!\p"
	.string "But this is so good!\p"
	.string "Munch munch!\p"
	.string "Aargh! It makes me mad!\p"
	.string "Munch munch!\p"
	.string "Aargh...\p"
	.string "...................Phew!\p"
	.string "I am feeling much better!\n"
	.string "Thank you for your candy!\l"
	.string "I want you to have this!$"
#endif

UndergroundPath_NorthSouthTunnel_Text_BaldingManGaveTM:
#if GERMAN
	.string "Die TM64 enthält…\p"
	.string "Tick, Tick, Tick, Tick, Tick, Tick, Tick,\n"
	.string "Tick, Tick, … … …\l"
	.string "… … …$"
#else
	.string "TM 64 contains........\p"
	.string "tick-\n"
	.string "            tock\l"
	.string "tick-\l"
	.string "            tock\l"
	.string "tick-\l"
	.string "            tock\l"
	.string "tick-\l"
	.string "            tock\l"
	.string "tick.....\l"
	.string "......................\l"
	.string "......................$"
#endif
