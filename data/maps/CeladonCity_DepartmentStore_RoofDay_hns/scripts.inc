CeladonCity_DepartmentStore_RoofDay_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_DepartmentStore_RoofDay_OnTransition
	.byte 0

CeladonCity_DepartmentStore_RoofDay_OnTransition:
	call_if_set FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight
	call_if_unset FLAG_DAY_POKEMON, CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay
	end

CeladonCity_DepartmentStore_RoofDay_EventScript_SetNight::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_NIGHT_HNS
	return

CeladonCity_DepartmentStore_RoofDay_EventScript_SetDay::
	setmaplayoutindex LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF_DAY_HNS
	return

CeladonDept6_EventScript_Nerd::
	msgbox CeladonDeptStore6F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept6_EventScript_Youngster::
	msgbox CeladonDeptStore6F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept6_EventScript_Directory::
	msgbox CeladonDeptStore6F_Text_Directory, MSGBOX_SIGN
	end


CeladonDeptStore6F_Text_Vending:
#if GERMAN
	.string "Ein Verkaufsautomat! Hier ist das\n"
	.string "Menü.$"
#else
	.string "A vending machine! Here's the menu.$"
#endif

CeladonDeptStore6F_Text_Clang:
#if GERMAN
	.string "Klong!\p"
	.string "{STR_VAR_1} ist herausgesprungen.$"
#else
	.string "Clang!\p"
	.string "{STRING} popped out.$"
#endif

CeladonDeptStore6F_Text_VendingNoMoney:
#if GERMAN
	.string "Ups, nicht genug Geld…$"
#else
	.string "Oops, not enough money…$"
#endif

CeladonDeptStore6F_Text_VendingNoSpace:
#if GERMAN
	.string "Es ist kein Platz mehr vorhanden!$"
#else
	.string "There's no more room for stuff…$"
#endif

CeladonDeptStore6F_Text_SuperNerd:
#if GERMAN
	.string "Ein Verkaufsautomat mit Preisroulette…\p"
	.string "Solche sieht man heute kaum noch.$"
#else
	.string "A vending machine with a prize\n"
	.string "roulette…\p"
	.string "You never see those anymore.$"
#endif

CeladonDeptStore6F_Text_Youngster:
#if GERMAN
	.string "Ach Mann, hier gibt’s ja gar keine\n"
	.string "Videospiele!\l"
	.string "Ich will Videospiele zocken!$"
#else
	.string "Aww! There's no games here!\p"
	.string "I wanted to play…$"
#endif

CeladonDeptStore6F_Text_Directory:
#if GERMAN
	.string "5F: Dachterrasse,\n"
	.string "Verkaufsautomaten$"
#else
	.string "6F: ROOFTOP SQUARE VENDING\n"
	.string "MACHINES$"
#endif
