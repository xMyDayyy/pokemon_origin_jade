Gate_SaffronCity_Route5_hns_MapScripts::
	.byte 0

Gate_SaffronCity_Route5_EventScript_Guard::
	msgbox Route5_Text_SaffronGateOfficer, MSGBOX_NPC
	end

Route5_Text_SaffronGateOfficer:
#if GERMAN
	.string "Du kommst aus Johto, nicht wahr?\p"
	.string "Wie gefällt dir Kanto? Schön hier, oder\n"
	.string "nicht?$"
#else
	.string "You're from JOHTO, aren't you?\p"
	.string "How do you like KANTO?\n"
	.string "It's nice, don't you agree?$"
#endif
