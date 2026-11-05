VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_VERDANTURF_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_AllContestsOriginateHere, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
#if GERMAN
	.string "Du kannst dich nicht Trainer nennen,\n"
	.string "wenn du nicht an deine Pokémon glaubst!\p"
	.string "Nur diejenigen, die an ihre Pokémon\n"
	.string "glauben, werden am Ende siegen.$"
#else
	.string "You can't consider yourself a real\n"
	.string "TRAINER if you don't have faith\l"
	.string "in your POKéMON.\p"
	.string "Only those people who can believe\n"
	.string "in their battling POKéMON can win\l"
	.string "through to the very end.$"
#endif

VerdanturfTown_PokemonCenter_1F_Text_AllContestsOriginateHere:
#if GERMAN
	.string "Lass mich raten, warum du in\n"
	.string "Wiesenflur bist… Wegen des\l"
	.string "Wettbewerbs!\p"
	.string "Hier ist die Wiege aller Wettbewerbe.$"
#else
	.string "Let me hazard a guess why you're in\n"
	.string "VERDANTURF. The reason: CONTESTS.\p"
	.string "All CONTEST challenges originate here.$"
#endif

