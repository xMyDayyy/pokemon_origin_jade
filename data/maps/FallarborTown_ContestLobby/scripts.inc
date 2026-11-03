FallarborTown_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_ContestLobby_OnTransition
	.byte 0

@ Super Rank contest hall, as in Ruby/Sapphire (D-058). Shared scripts are in data/scripts/contest_hall.inc.

FallarborTown_ContestLobby_OnTransition:
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
	end

FallarborTown_ContestLobby_EventScript_ContestReceptionist::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_SUPER
	goto ContestLobby_EventScript_ContestReceptionist
	end

FallarborTown_ContestLobby_EventScript_BerryBlender::
	lockall
	setvar VAR_0x8008, LOCALID_FALLARBOR_CONTEST_LOBBY_BLEND_LEADER
	setvar VAR_0x8009, 1
	goto ContestLobby_EventScript_BerryBlender
	end

@ FLAG_CONTEST_SKETCH_CREATED: the player won a contest here since entering the town.
FallarborTown_ContestLobby_EventScript_SketchArtist::
	goto_if_set FLAG_CONTEST_SKETCH_CREATED, FallarborTown_ContestLobby_EventScript_SketchIsUp
	msgbox FallarborTown_ContestLobby_Text_ICreateSketches, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_SketchIsUp::
	msgbox FallarborTown_ContestLobby_Text_YourSketchIsUp, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_Boy::
	msgbox FallarborTown_ContestLobby_Text_UsedToHaveSketch, MSGBOX_NPC
	end

FallarborTown_ContestLobby_EventScript_Lass::
	msgbox FallarborTown_ContestLobby_Text_AreYouMakingPokeblock, MSGBOX_NPC
	end

FallarborTown_ContestLobby_Text_UsedToHaveSketch:
#if GERMAN
	.string "Dort hing mal eine Zeichnung von\n"
	.string "meinem Pokémon, aber nun hängt dort\l"
	.string "die Zeichnung eines anderen Pokémon.\p"
	.string "Ich werde mein Hana am Wettbewerb\n"
	.string "teilnehmen lassen, dann gibt es eine\l"
	.string "neue Zeichnung von ihm!$"
#else
	.string "They had a sketch of my POKéMON up\n"
	.string "on the wall over there, but they\l"
	.string "changed it with a new one already.\p"
	.string "I'm going to enter my HANA in CONTESTS\n"
	.string "so we can get her sketch up again!$"
#endif

FallarborTown_ContestLobby_Text_AreYouMakingPokeblock:
#if GERMAN
	.string "Hallo, willst du {POKEBLOCK} herstellen?\p"
	.string "Dann komm doch mal wieder vorbei und\n"
	.string "bring genug Beeren mit.$"
#else
	.string "Hi, are you making any {POKEBLOCK}S?\p"
	.string "You should come by with a bunch of\n"
	.string "BERRIES sometime.$"
#endif

FallarborTown_ContestLobby_Text_ICreateSketches:
#if GERMAN
	.string "Siehst du, wie sie hier die Zeichnungen\n"
	.string "des Sieger-Pokémon aushängen?\p"
	.string "Ich bin der Zeichner dieser Werke!\p"
	.string "Sobald eines deiner Pokémon einen\n"
	.string "Wettbewerb gewinnt, werde ich es mit\l"
	.string "Vergnügen zeichnen!$"
#else
	.string "You see how they display a sketch of\n"
	.string "a CONTEST winner here?\p"
	.string "I sketch them!\p"
	.string "If any of your POKéMON wins a CONTEST,\n"
	.string "I'd gladly make a sketch of it!$"
#endif

FallarborTown_ContestLobby_Text_YourSketchIsUp:
#if GERMAN
	.string "Hallo und herzlichen Glückwunsch!\p"
	.string "Ich habe eine Zeichnung deines Pokémon\n"
	.string "hier aufgehängt, damit jeder es sieht.$"
#else
	.string "Hello! Congratulations!\p"
	.string "I've put up a sketch of your POKéMON\n"
	.string "right here for everyone to see!$"
#endif
