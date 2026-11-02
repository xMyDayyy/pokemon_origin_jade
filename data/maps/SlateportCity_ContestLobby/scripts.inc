SlateportCity_ContestLobby_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_ContestLobby_OnTransition
	.byte 0

@ Hyper Rank contest hall, as in Ruby/Sapphire (D-058). Shared scripts are in data/scripts/contest_hall.inc.

SlateportCity_ContestLobby_OnTransition:
	call LilycoveCity_ContestLobby_EventScript_TryShowContestReporter
	end

SlateportCity_ContestLobby_EventScript_ContestReceptionist::
	setvar VAR_CONTEST_RANK, CONTEST_RANK_HYPER
	goto ContestLobby_EventScript_ContestReceptionist
	end

SlateportCity_ContestLobby_EventScript_BerryBlender::
	lockall
	applymovement LOCALID_SLATEPORT_CONTEST_LOBBY_BLEND_PARTICIPANT, Common_Movement_FaceOriginalDirection
	setvar VAR_0x8008, LOCALID_SLATEPORT_CONTEST_LOBBY_BLEND_LEADER
	setvar VAR_0x8009, 2
	goto ContestLobby_EventScript_BerryBlender
	end

@ Hands out the Pokeblock Case to players without one (D-058).
SlateportCity_ContestLobby_EventScript_LittleGirl::
	lock
	faceplayer
	checkitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_ContestLobby_EventScript_HavePokeblockCase
	msgbox SlateportCity_ContestLobby_Text_YouCanHavePokeblockCase, MSGBOX_DEFAULT
	giveitem ITEM_POKEBLOCK_CASE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	release
	end

SlateportCity_ContestLobby_EventScript_HavePokeblockCase::
	msgbox SlateportCity_ContestLobby_Text_PutPokeblocksInThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_ContestLobby_EventScript_Man::
	msgbox SlateportCity_ContestLobby_Text_WantToRaiseUltimateMon, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_Girl::
	msgbox SlateportCity_ContestLobby_Text_DoYourFriendsHaveBerries, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_Woman::
	msgbox SlateportCity_ContestLobby_Text_ContestWinnerPostersOnWall, MSGBOX_NPC
	end

SlateportCity_ContestLobby_EventScript_BlendParticipant::
	msgbox BerryBlender_Text_LetsGetBlendingAlready, MSGBOX_NPC
	end

SlateportCity_ContestLobby_Text_WantToRaiseUltimateMon:
#if GERMAN
	.string "Ich möchte ein Pokémon aufziehen, das\n"
	.string "im Kampf und im Wettbewerb\l"
	.string "“unbesiegbar” ist.\p"
	.string "Es ist schon verwirrend, heraus-\n"
	.string "zufinden, welche Attacken es lernen\l"
	.string "soll.$"
#else
	.string "I want to raise a POKéMON that's\n"
	.string "the ultimate in “great” for both\l"
	.string "battles and CONTESTS.\p"
	.string "It's vexing, trying to figure out\n"
	.string "which moves I should make it learn.$"
#endif

SlateportCity_ContestLobby_Text_DoYourFriendsHaveBerries:
#if GERMAN
	.string "Haben einige deiner Freunde Beeren?\p"
	.string "Du kannst den Beerenmixer benutzen\n"
	.string "und zusammen mit ihnen {POKEBLOCK}\l"
	.string "herstellen.\p"
	.string "Das macht sehr viel Spaß!$"
#else
	.string "Do any of your friends have any\n"
	.string "BERRIES?\p"
	.string "You can use that BERRY BLENDER and\n"
	.string "make {POKEBLOCK}S with your friends!\p"
	.string "You should try it - it's a lot of fun!$"
#endif

SlateportCity_ContestLobby_Text_YouCanHavePokeblockCase:
#if GERMAN
	.string "Ich habe zwei. Du kannst eine haben.$"
#else
	.string "I have two, so you can have one!$"
#endif

SlateportCity_ContestLobby_Text_PutPokeblocksInThere:
#if GERMAN
	.string "Stelle {POKEBLOCK} her und verstaue sie\n"
	.string "darin.\p"
	.string "Wenn ihr einen {POKEBLOCK} herstellt,\n"
	.string "muss jeder eine andere Beere einsetzen.$"
#else
	.string "Make {POKEBLOCK}S and put them in there.\p"
	.string "When you make a {POKEBLOCK}, everyone\n"
	.string "has to put in a different BERRY.$"
#endif

SlateportCity_ContestLobby_Text_ContestWinnerPostersOnWall:
#if GERMAN
	.string "Wenn du einen Wettbewerb gewinnst,\n"
	.string "wird ein Bild deines Pokémon an die\l"
	.string "Wand gehängt.\p"
	.string "Das Porträt deines Pokémon wird\n"
	.string "außerdem mit deinem Namen versehen.$"
#else
	.string "If you win a CONTEST, they put up a\n"
	.string "poster of your POKéMON on the wall.\p"
	.string "It will have a portrait of your\n"
	.string "POKéMON and both your names.$"
#endif
