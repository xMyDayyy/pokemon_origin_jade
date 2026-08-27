VermilionCity_PortOutside_Frlg_MapScripts::
	.byte 0

VermilionCity_PortOutsideFrlg_EventScript_Fisher::
	msgbox VermilionCity_PortOutsideFrlg_Text_Fisher, MSGBOX_NPC
	end

VermilionCity_PortOutsideFrlg_Text_Fisher::
#if GERMAN
	.string "Bist du gerade aus Johto gekommen?\n"
	.string "Wie fischt es sich da so?\l"
	.string "…\p"
	.string "Johto hat rote Garados?!$"
#else
	.string "You just came from JOHTO?\n"
	.string "How's the fishin' over there\l"
	.string "...\p"
	.string "JOHTO has RED GYARADOS?!$"
#endif
