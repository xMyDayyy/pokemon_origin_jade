MtMortar_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMortar_B1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtMortar_B1F_OnTransition:
	callnative SetTimeBasedEncounters
	end

MtMortar_B1F_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

MtMortar_B1F_EventScript_Item_Carbos::
    finditem ITEM_CARBOS
    end

MtMortar_B1F_EventScript_Item_PPUp::
    finditem ITEM_PP_UP
    end

MtMortar_B1F_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

MtMortar_B1F_EventScript_Item_MaxRevive::
    finditem ITEM_MAX_REVIVE
    end

MountMortar4_EventScript_Kiyo::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TYROGUE, MountMortar4_EventScript_KiyoAfter
	goto_if_set FLAG_BEAT_KIYO, MountMortar4_EventScript_KiyoTryGiveTyrogue
	msgbox MountMortar4_Text_KiyoIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIYO_HNS, MountMortar4_Text_KiyoWin
	setflag FLAG_BEAT_KIYO
MountMortar4_EventScript_KiyoTryGiveTyrogue::
	msgbox MountMortar4_Text_KiyoTyrogueReward, MSGBOX_DEFAULT
	@HnS gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TYROGUE
	bufferspeciesname STR_VAR_1, SPECIES_TYROGUE
	givemon SPECIES_TYROGUE, 25
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Common_EventScript_NoMoreRoomForPokemon
	call Common_EventScript_GiftMon
	setflag FLAG_GOT_TYROGUE
MountMortar4_EventScript_KiyoAfter::
	msgbox MountMortar4_Text_KiyoGotTyrogue, MSGBOX_DEFAULT
	closemessage
	release
	end


MountMortar4_Text_KiyoIntro:
#if GERMAN
	.string "Hey da!\n"
	.string "Ich bin der Karate-Meister!\p"
	.string "Ich trainiere hier ganz alleine in dieser\n"
	.string "düsteren Höhle! So bin ich eben!\p"
	.string "In Ordnung!\n"
	.string "Hergehört!\l"
	.string "Ich will, dass du gegen mich kämpfst!\l"
	.string "Harrrgh!$"
#else
	.string "Hey!\p"
	.string "I am the KARATE KING!\n"
	.string "I train alone here in the dark!\p"
	.string "You! Battle with me!\n"
	.string "Hwaaarggh!$"
#endif

MountMortar4_Text_KiyoWin:
#if GERMAN
	.string "Waaargh!\n"
	.string "Ich wurde besiegt!$"
#else
	.string "Waaaarggh!\n"
	.string "I'm beaten!$"
#endif

MountMortar4_Text_KiyoTyrogueReward:
#if GERMAN
	.string "Da-da… das ist doch nicht möglich!\n"
	.string "Wie lange soll ich denn noch trainieren?\p"
	.string "Ich sage es nur ungerne, aber ich habe\n"
	.string "verloren. Ich gebe mich geschlagen!\p"
	.string "Hergehört! Als Beweis für deinen Sieg\n"
	.string "will ich dir dieses kostbare\l"
	.string "Kampf-Pokémon überreichen!$"
#else
	.string "I... I'm crushed...\p"
	.string "My training is still not\n"
	.string "enough...\p"
	.string "But a loss is a loss.\n"
	.string "I admit it.\p"
	.string "As proof that you defeated me,\n"
	.string "I'll give you a rare fighting\l"
	.string "POKéMON.$"
#endif

MountMortar4_Text_ReceiveTyrogue:
#if GERMAN
	.string "{PLAYER} erhält Rabauz.$"
#else
	.string "{PLAYER} received TYROGUE.$"
#endif

MountMortar4_Text_KiyoGotTyrogue:
#if GERMAN
	.string "Rabauz ist ein Pokémon vom Typ Kampf!\p"
	.string "Zieht man es auf, entwickelt es sich\n"
	.string "angeblich zu einem mächtigen Pokémon!\p"
	.string "Also hergehört! Streng dich an!\n"
	.string "Ich setze jetzt auch mein Training\l"
	.string "fort. Hau rein!$"
#else
	.string "TYROGUE is a FIGHTING-type.\p"
	.string "It evolves into a tougher\n"
	.string "POKéMON.\p"
	.string "Keep up the hard work.\n"
	.string "I'll keep training too.\p"
	.string "Farewell!$"
#endif

MountMortar4_Text_KiyoFullParty:
#if GERMAN
	.string "He!\n"
	.string "Du hast zu viele Pokémon dabei!$"
#else
	.string "You have no room in your party!$"
#endif
