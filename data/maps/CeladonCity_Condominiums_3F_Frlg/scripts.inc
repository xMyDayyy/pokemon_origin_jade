CeladonCity_Condominiums_3F_Frlg_MapScripts::
	.byte 0

CeladonCity_Condominiums_3F_EventScript_Programmer::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheProgrammer, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_GraphicArtist::
	msgbox CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Writer::
	msgbox CeladonCity_Condominiums_3F_Text_IWroteTheStory, MSGBOX_NPC
	end

CeladonCity_Condominiums_3F_EventScript_Designer::
	lock
	faceplayer
	specialvar VAR_RESULT, HasAllKantoMons
	goto_if_eq VAR_RESULT, TRUE, CeladonCity_Condominiums_3F_EventScript_CompletedPokedex
	msgbox CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex
	release
	end

CeladonCity_Condominiums_3F_EventScript_CompletedPokedex::
	goto CeladonCity_Condominiums_3F_EventScript_ShowDiploma
	end

CeladonCity_Condominiums_3F_EventScript_ShowDiploma::
	message CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations
	waitmessage
	delay 60
	call_if_unset FLAG_RECEIVED_CATCHING_CHARM, CeladonCity_Condominiums_3F_EventScript_GiveCatchingCharm
	special Special_ShowDiploma
	waitstate
	release
	end

@ Origin Jade: the Catching Charm with the Kanto diploma (D-059).
@ Keep the call before Special_ShowDiploma: commands after it never run.
CeladonCity_Condominiums_3F_EventScript_GiveCatchingCharm::
	waitbuttonpress
	msgbox CeladonCity_Condominiums_3F_Text_TakeThisToo, MSGBOX_DEFAULT
	giveitem ITEM_CATCHING_CHARM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setflag FLAG_RECEIVED_CATCHING_CHARM
	msgbox CeladonCity_Condominiums_3F_Text_ExplainCatchingCharm, MSGBOX_DEFAULT
	return

CeladonCity_Condominiums_3F_EventScript_DevelopmentRoomSign::
	msgbox CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer1::
	msgbox CeladonCity_Condominiums_3F_Text_ItsTheGameProgram, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer2::
	msgbox CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_EventScript_Computer3::
	msgbox CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding, MSGBOX_SIGN
	end

CeladonCity_Condominiums_3F_Text_ImTheProgrammer::
#if GERMAN
	.string "Ich?\n"
	.string "Ich bin der Programmierer!$"
#else
	.string "Me?\n"
	.string "I'm the programmer!$"
#endif

CeladonCity_Condominiums_3F_Text_ImTheGraphicArtist::
#if GERMAN
	.string "Ich bin der Grafiker!\n"
	.string "Ich habe dies alles gezeichnet!$"
#else
	.string "I'm the graphic artist!\n"
	.string "I drew you!$"
#endif

CeladonCity_Condominiums_3F_Text_IWroteTheStory::
#if GERMAN
	.string "Die Geschichte stammt von mir!\n"
	.string "Ist Erika nicht süß?\p"
	.string "Aber Misty mag ich auch gerne!\n"
	.string "Und nicht zu vergessen, Sabrina!$"
#else
	.string "I wrote the story!\n"
	.string "Isn't ERIKA cute?\p"
	.string "I like MISTY a lot, too!\n"
	.string "Oh, and SABRINA, I like her!$"
#endif

CeladonCity_Condominiums_3F_Text_ImGameDesignerShowMeFinishedPokedex::
#if GERMAN
	.string "Gefällt dir das Spiel?\p"
	.string "Ich habe das Spiel gestaltet!\p"
	.string "Auch wenn es sehr mühsam ist, den\n"
	.string "Pokédex zu erstellen: Gib nicht auf!\p"
	.string "Zeige ihn mir, wenn er komplett ist!$"
#else
	.string "Is that right?\p"
	.string "I'm the game designer!\p"
	.string "Filling up your POKéDEX is tough,\n"
	.string "but don't quit!\p"
	.string "When you finish, come tell me!$"
#endif

CeladonCity_Condominiums_3F_Text_CompletedPokedexCongratulations::
#if GERMAN
	.string "Wow! Fantastisch!\n"
	.string "Dein Pokédex ist vollständig!\l"
	.string "Herzlichen Glückwunsch!\l"
	.string "…$"
#else
	.string "Wow! Excellent!\n"
	.string "You completed your POKéDEX!\l"
	.string "Congratulations!\l"
	.string "…$"
#endif

CeladonCity_Condominiums_3F_Text_ItsTheGameProgram::
#if GERMAN
	.string "Der Programmcode! Davon sollte man\n"
	.string "besser die Finger lassen!$"
#else
	.string "It's the game program! Messing with\n"
	.string "it could bug out the game!$"
#endif

CeladonCity_Condominiums_3F_Text_SomeonesPlayingGame::
#if GERMAN
	.string "Dort spielt jemand, anstatt zu\n"
	.string "arbeiten!$"
#else
	.string "Someone's playing a game instead of\n"
	.string "working!$"
#endif

CeladonCity_Condominiums_3F_Text_ItsScriptBetterNotLookAtEnding::
#if GERMAN
	.string "Das Drehbuch! Ich schaue mir das\n"
	.string "Ende besser nicht an!$"
#else
	.string "It's the script!\n"
	.string "Better not look at the ending!$"
#endif

CeladonCity_Condominiums_3F_Text_GameFreakDevelopmentRoom::
#if GERMAN
	.string "Game Freak Entwicklungs-Abteilung$"
#else
	.string "GAME FREAK Development Room$"
#endif


CeladonCity_Condominiums_3F_Text_TakeThisToo::
#if GERMAN
	.string "Dafür bekommst du noch das hier!$"
#else
	.string "Please take this as well!$"
#endif

CeladonCity_Condominiums_3F_Text_ExplainCatchingCharm::
#if GERMAN
	.string "Mit dem Superfangpin gelingen dir\n"
	.string "öfter kritische Fänge.$"
#else
	.string "With the CATCHING CHARM, critical\n"
	.string "captures happen more often.$"
#endif
