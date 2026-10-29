BirthIsland_Harbor_hns_MapScripts::
	.byte 0

@ M.S. Aqua to Olivine, Vermilion or Hoenn (see docs/origin_jade/DECISIONS.md, D-029).
BirthIsland_Harbor_hns_EventScript_Sailor::
	lock
	faceplayer
	setvar VAR_0x8004, LOCALID_BIRTH_ISLAND_HARBOR_HNS_SS_TIDAL
	message BirthIsland_Harbor_hns_Text_SailorReturn
	waitmessage
	goto SSAqua_EventScript_ChooseReturnPort

@ Sailor at the landing place outside (object LOCALID_BIRTH_ISLAND_EXTERIOR_HNS_SAILOR of BirthIsland_Exterior_hns).
BirthIsland_Harbor_hns_EventScript_ExteriorSailor::
	lock
	faceplayer
	setvar VAR_0x8004, LOCALID_BIRTH_ISLAND_EXTERIOR_HNS_SS_TIDAL
	message BirthIsland_Harbor_hns_Text_SailorReturn
	waitmessage
	goto SSAqua_EventScript_ChooseReturnPort

BirthIsland_Harbor_hns_Text_SailorReturn:
#if GERMAN
	.string "Was für eine seltsam geformte\n"
	.string "Insel, nicht?\p"
	.string "Wohin möchtest du segeln?$"
#else
	.string "What an oddly shaped island, eh?\p"
	.string "Where would you like to sail?$"
#endif
