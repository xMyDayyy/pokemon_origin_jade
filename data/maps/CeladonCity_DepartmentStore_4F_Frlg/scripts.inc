CeladonCity_DepartmentStore_4F_Frlg_MapScripts::
	.byte 0

CeladonCity_DepartmentStore_4F_EventScript_Man::
	msgbox CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster::
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign::
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox gText_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items::
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_RETRO_MAIL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	@ Evolution items no active Kanto map holds, see docs/origin_jade/DECISIONS.md, D-013.
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_BLACK_AUGURITE
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_METAL_COAT
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_NONE
	release
	end

CeladonCity_DepartmentStore_4F_Text_GettingPokeDollAsPresent::
#if GERMAN
	.string "Ich kaufe ein Geschenk für meine\n"
	.string "Freundin.\p"
	.string "Sie freut sich bestimmt über eine\n"
	.string "Poképuppe!$"
#else
	.string "I'm getting a present for my\n"
	.string "girlfriend.\p"
	.string "I guess a POKé DOLL will be it.\n"
	.string "It's the popular thing.$"
#endif

CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll::
#if GERMAN
	.string "Ich habe einen Tipp bekommen!\p"
	.string "Du kannst vor wilden Pokémon fliehen,\n"
	.string "wenn du sie mit einer PokéPuppe\l"
	.string "ablenkst!$"
#else
	.string "I heard something useful.\p"
	.string "If a wild POKéMON appears, you can\n"
	.string "distract it with a POKé DOLL.\p"
	.string "You can run away while the wild\n"
	.string "POKéMON is distracted.$"
#endif

CeladonCity_DepartmentStore_4F_Text_FloorSign::
#if GERMAN
	.string "Lass ein Geschenk für dich sprechen!\n"
	.string "3S: Geschenkartikel\p"
	.string "Entwicklungs-Spezial!\n"
	.string "Steine jetzt im Angebot!$"
#else
	.string "Express yourself with gifts!\n"
	.string "4F: WISE MAN GIFTS\p"
	.string "Evolution Special!\n"
	.string "Element STONES on sale now!$"
#endif
