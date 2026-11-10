PokemonTower_5F_Frlg_MapScripts::
	.byte 0

PokemonTower_5F_EventScript_Channeler::
	msgbox PokemonTower_5F_Text_RestHereInPurifiedSpace, MSGBOX_NPC
	end

PokemonTower_5F_EventScript_PurifiedZone::
	lockall
	@ Pokemon Center challenge: the zone does not heal.
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, PokemonTower_5F_EventScript_PurifiedZone_PokecenterChallenge
	fadescreen FADE_TO_WHITE
	special HealPlayerParty
	fadescreen FADE_FROM_WHITE
	msgbox PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_PurifiedZone_PokecenterChallenge::
	msgbox SSAquaRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 1
	releaseall
	end

PokemonTower_5F_EventScript_ExitPurifiedZone::
	lockall
	setvar VAR_TEMP_1, 0
	releaseall
	end

PokemonTower_5F_EventScript_Tammy::
	trainerbattle_single TRAINER_CHANNELER_TAMMY, PokemonTower_5F_Text_TammyIntro, PokemonTower_5F_Text_TammyDefeat
	msgbox PokemonTower_5F_Text_TammyPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Ruth::
	trainerbattle_single TRAINER_CHANNELER_RUTH, PokemonTower_5F_Text_RuthIntro, PokemonTower_5F_Text_RuthDefeat
	msgbox PokemonTower_5F_Text_RuthPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Karina::
	trainerbattle_single TRAINER_CHANNELER_KARINA, PokemonTower_5F_Text_KarinaIntro, PokemonTower_5F_Text_KarinaDefeat
	msgbox PokemonTower_5F_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_EventScript_Janae::
	trainerbattle_single TRAINER_CHANNELER_JANAE, PokemonTower_5F_Text_JanaeIntro, PokemonTower_5F_Text_JanaeDefeat
	msgbox PokemonTower_5F_Text_JanaePostBattle, MSGBOX_AUTOCLOSE
	end

PokemonTower_5F_Text_RestHereInPurifiedSpace::
#if GERMAN
	.string "Komm her! Ich habe diese Stelle mit\n"
	.string "weißer Magie versiegelt!\l"
	.string "Du kannst dich hier ausruhen!$"
#else
	.string "Come, child!\n"
	.string "I have purified this space.\l"
	.string "You can rest here.$"
#endif

PokemonTower_5F_Text_TammyIntro::
#if GERMAN
	.string "Gib... mir...\n"
	.string "deine... Seele...$"
#else
	.string "Give…me…\n"
	.string "your…all…$"
#endif

PokemonTower_5F_Text_TammyDefeat::
#if GERMAN
	.string "Puh!$"
#else
	.string "Gasp!$"
#endif

PokemonTower_5F_Text_TammyPostBattle::
#if GERMAN
	.string "Etwas muss von mir Besitz ergriffen\n"
	.string "haben!$"
#else
	.string "I was under possession.$"
#endif

PokemonTower_5F_Text_RuthIntro::
#if GERMAN
	.string "Es... gibt... kein...\n"
	.string "Entkommen...$"
#else
	.string "You…shall…\n"
	.string "join…us…$"
#endif

PokemonTower_5F_Text_RuthDefeat::
#if GERMAN
	.string "Welch ein Alptraum!$"
#else
	.string "What a nightmare!$"
#endif

PokemonTower_5F_Text_RuthPostBattle::
#if GERMAN
	.string "Ich war verhext!$"
#else
	.string "I was possessed.$"
#endif

PokemonTower_5F_Text_KarinaIntro::
	.string "Zombies!$"

PokemonTower_5F_Text_KarinaDefeat::
#if GERMAN
	.string "Was?$"
#else
	.string "Ha?$"
#endif

PokemonTower_5F_Text_KarinaPostBattle::
#if GERMAN
	.string "So langsam komme ich wieder zu\n"
	.string "Sinnen!$"
#else
	.string "I regained my senses.$"
#endif

PokemonTower_5F_Text_JanaeIntro::
#if GERMAN
	.string "Buuh...\n"
	.string "Buhuhu...$"
#else
	.string "Urgah…\n"
	.string "Urff…$"
#endif

PokemonTower_5F_Text_JanaeDefeat::
#if GERMAN
	.string "Das war knapp!$"
#else
	.string "Whoo!$"
#endif

PokemonTower_5F_Text_JanaePostBattle::
#if GERMAN
	.string "Trotz meiner Erfahrung bin ich dem\n"
	.string "Bösen verfallen!$"
#else
	.string "I fell to evil spirits despite my\n"
	.string "training in the mountains…$"
#endif

PokemonTower_5F_Text_PurifiedZoneMonsFullyHealed::
#if GERMAN
	.string "Du hast einen geschützten Bereich\n"
	.string "betreten!\p"
	.string "Die Pokémon von {PLAYER} wurden\n"
	.string "geheilt!$"
#else
	.string "Entered the purified and protected\n"
	.string "zone.\p"
	.string "{PLAYER}'s POKéMON were fully\n"
	.string "healed.$"
#endif

