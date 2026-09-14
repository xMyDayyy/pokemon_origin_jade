Route30_House_hns_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
#if GERMAN
	.string "Folgst du dem Weg nach Norden,\n"
	.string "erreichst du Mr. Pokémons Haus.\p"
	.string "Meine Bäume tragen gut dieses Jahr.\n"
	.string "Nimm ruhig, was heruntergefallen\l"
	.string "ist.$"
#else
	.string "Follow the path north and you will\n"
	.string "reach MR. POKéMON's house.\p"
	.string "My trees are bearing well this year.\n"
	.string "Take whatever has fallen.$"
#endif

Route30_BerryHouse_Text_CheckTrees:
#if GERMAN
	.string "Suche in Bäumen nach Beeren. Sie fallen\n"
	.string "einfach herunter.$"
#else
	.string "Check trees for BERRIES.\n"
	.string "They grow back after a few hours.$"
#endif
