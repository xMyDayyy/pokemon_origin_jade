PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_PlayersHouse_1F_OnFrame
	.byte 0

PalletTown_PlayersHouse_1F_OnFrame::
	map_script_2 VAR_PALLET_HOUSE_INTRO, 0, PalletTown_PlayersHouse_1F_EventScript_Intro
	.2byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	msgbox PalletTown_PlayersHouse_1F_Text_MomGoSeeOak
	release
	end

PalletTown_PlayersHouse_1F_Text_MomGoSeeOak:
#if GERMAN
	.string "Mama: Prof. Eich hat nach dir\n"
	.string "gefragt. Geh doch mal zu ihm!$"
#else
	.string "MOM: PROF. OAK was asking for you.\n"
	.string "Why don't you go and see him?$"
#endif

@ ============================================================================
@ Kanto-Merge: Startgespraech am Treppenfuss. Faengt Rivalennamen, PokeCom
@ und Turbotreter in einer Szene ab; die alte Sperre an der Haustuer
@ entfaellt dadurch. Wortlaut der Uebergaben von der HnS-Mutter.
@ ============================================================================

PalletTown_PlayersHouse_1F_EventScript_Intro::
	lockall
	delay 20
	@ Kanto-Merge: Der Spieler geht selbst zur Mutter hinueber. Der Ablauf
	@ haengt an der Kartenskript-Tabelle und startet direkt nach dem Warp,
	@ nicht erst beim Betreten einer bestimmten Kachel.
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_PlayersHouse_1F_Movement_ToMom
	waitmovement 0
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FacePlayer
	waitmovement 0
	msgbox PalletTown_PlayersHouse_1F_Text_IntroVisitor, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	setflag FLAG_RIVAL_NAMED_BY_MOM
	msgbox PalletTown_PlayersHouse_1F_Text_IntroRivalThere, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message PalletTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	@ Kanto-Merge: Mama traegt sich gleich mit ein - sie sagt im naechsten
	@ Satz ohnehin, dass Nummern im Speicher stehen.
	setflag FLAG_ENABLE_MOM_MATCH_CALL
	msgbox PalletTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox PalletTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox PalletTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_PALLET_HOUSE_INTRO, 1
	@ Anruf der Mutter vorbereiten - sie probiert das Geraet gleich aus.
	setvar VAR_HNS_MOM_CALL_STEPS, 0
	setflag FLAG_HNS_MOM_CALL_PENDING
	releaseall
	end

PalletTown_PlayersHouse_1F_Movement_ToMom::
	walk_down
	walk_down
	walk_left
	face_left
	step_end

PalletTown_PlayersHouse_1F_EventScript_Daisy::
	lock
	faceplayer
	msgbox PalletTown_PlayersHouse_1F_Text_DaisyVisiting
	release
	end

PalletTown_PlayersHouse_1F_Text_IntroVisitor:
#if GERMAN
	.string "Mama: Oh, {PLAYER}!\p"
	.string "Wir haben gerade Besuch von\n"
	.string "Prof. Eichs Enkelin Sarah.\p"
	.string "Er hat nach dir gefragt.\n"
	.string "Geh doch mal zu ihm!\p"
	.string "Sein Enkel$"
#else
	.string "MOM: Oh, {PLAYER}!\p"
	.string "We've got a visitor - PROF. OAK's\n"
	.string "granddaughter DAISY.\p"
	.string "He was asking for you.\n"
	.string "Why don't you go and see him?\p"
	.string "His grandson$"
#endif

PalletTown_PlayersHouse_1F_Text_IntroRivalThere:
#if GERMAN
	.string "Sein Enkel {RIVAL} ist bestimmt\n"
	.string "auch dort.\p"
	.string "Ach, bevor ich es vergesse:\n"
	.string "Dein PokéCom kam aus der\l"
	.string "Werkstatt.\p"
	.string "Hier, nimm es!$"
#else
	.string "His grandson {RIVAL} is bound to\n"
	.string "be there.\p"
	.string "Oh, before I forget:\n"
	.string "your POKéGEAR is back from\l"
	.string "the repair shop.\p"
	.string "Here, take it!$"
#endif

PalletTown_PlayersHouse_1F_Text_DaisyVisiting:
#if GERMAN
	.string "Sarah: Hallo, {PLAYER}!\p"
	.string "Mein Opa ist im Labor und\n"
	.string "wartet schon auf dich.$"
#else
	.string "DAISY: Hi, {PLAYER}!\p"
	.string "GRANDPA's at the lab, and he's\n"
	.string "waiting for you.$"
#endif


PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	call PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	release
	end

@ ============================================================================
@ Kanto-Merge: Sparschwein der Mutter. Lag in HnS bei der Mutter in
@ Neuborkia; dort wohnt der Spieler bei uns nicht mehr. Die Specials und
@ die Kaeufe ueber ShouldDoMomCall sind unveraendert, nur der Ort wechselt.
@ ============================================================================
PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu::
	special Special_MomEnsureInitialized
	msgbox PalletTown_PlayersHouse_1F_Text_MomAnythingElse, MSGBOX_DEFAULT
	multichoice 0, 0, MULTI_MOM_MENU, FALSE
	switch VAR_RESULT
	case 0, PalletTown_PlayersHouse_1F_EventScript_CheckSavings
	case 1, PalletTown_PlayersHouse_1F_EventScript_Deposit
	case 2, PalletTown_PlayersHouse_1F_EventScript_Withdraw
	case 3, PalletTown_PlayersHouse_1F_EventScript_ToggleSaving
	case 4, PalletTown_PlayersHouse_1F_EventScript_ExitSavings
	case MULTI_B_PRESSED, PalletTown_PlayersHouse_1F_EventScript_ExitSavings
	end

PalletTown_PlayersHouse_1F_EventScript_CheckSavings::
	special Special_MomGetBalance
	msgbox PalletTown_PlayersHouse_1F_Text_CurrentSavings, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_Deposit::
	checkmoney 1
	compare VAR_RESULT, FALSE
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_DepositFailed
	closemessage
	special Special_MomOpenDepositInput
	waitstate
	compare VAR_0x8000, 0
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox PalletTown_PlayersHouse_1F_Text_DepositSuccess, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_DepositFailed::
	msgbox PalletTown_PlayersHouse_1F_Text_NoMoneyToDeposit, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_Withdraw::
	special Special_MomGetBalance
	compare VAR_RESULT, 0
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_WithdrawFailed
	closemessage
	special Special_MomOpenWithdrawInput
	waitstate
	compare VAR_0x8000, 0
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	msgbox PalletTown_PlayersHouse_1F_Text_WithdrawSuccess, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_WithdrawFailed::
	msgbox PalletTown_PlayersHouse_1F_Text_NoMoneyToWithdraw, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_ToggleSaving::
	special Special_MomIsSavingEnabled
	compare VAR_RESULT, TRUE
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_DisableSaving
	msgbox PalletTown_PlayersHouse_1F_Text_EnableSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_ConfirmEnable
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_ConfirmEnable::
	special Special_MomEnableSaving
	msgbox PalletTown_PlayersHouse_1F_Text_SavingEnabled, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_DisableSaving::
	msgbox PalletTown_PlayersHouse_1F_Text_DisableSaving, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PalletTown_PlayersHouse_1F_EventScript_ConfirmDisable
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_ConfirmDisable::
	special Special_MomDisableSaving
	msgbox PalletTown_PlayersHouse_1F_Text_SavingDisabled, MSGBOX_DEFAULT
	goto PalletTown_PlayersHouse_1F_EventScript_MomSavingsMenu
	end

PalletTown_PlayersHouse_1F_EventScript_ExitSavings::
	msgbox PalletTown_PlayersHouse_1F_Text_Goodbye, MSGBOX_DEFAULT
	return

PalletTown_PlayersHouse_1F_Text_MomAnythingElse:
#if GERMAN
	.string "Kann ich dir sonst noch helfen,\n"
	.string "Liebling?$"
#else
	.string "Is there anything else I can\n"
	.string "help you with, sweetie?$"
#endif

PalletTown_PlayersHouse_1F_Text_CurrentSavings:
#if GERMAN
	.string "Ich habe {STR_VAR_2} für dich gespart.$"
#else
	.string "I'm holding {STR_VAR_2}\n"
	.string "for you right now.$"
#endif

PalletTown_PlayersHouse_1F_Text_EnableSaving:
#if GERMAN
	.string "Möchtest du, dass ich etwas von\n"
	.string "dem Geld spare, das du verdienst?$"
#else
	.string "Do you want me to save some of the\n"
	.string "money you earn?$"
#endif

PalletTown_PlayersHouse_1F_Text_SavingEnabled:
#if GERMAN
	.string "Okay! Ich spare 25% des Geldes von\n"
	.string "deinen Kämpfen.$"
#else
	.string "Okay! I'll save 25% of\n"
	.string "the money you earn from battles.$"
#endif

PalletTown_PlayersHouse_1F_Text_DisableSaving:
#if GERMAN
	.string "Möchtest du, dass ich nicht mehr für\n"
	.string "dich spare?$"
#else
	.string "Would you like me to stop\n"
	.string "saving for you?$"
#endif

PalletTown_PlayersHouse_1F_Text_SavingDisabled:
#if GERMAN
	.string "Okay, ich höre auf zu sparen.$"
#else
	.string "Okay, I'll stop saving.$"
#endif

PalletTown_PlayersHouse_1F_Text_Goodbye:
#if GERMAN
	.string "Sei vorsichtig, Liebling!$"
#else
	.string "Take care, sweetie!$"
#endif

PalletTown_PlayersHouse_1F_Text_DepositSuccess:
#if GERMAN
	.string "Mama: Hört sich gut an!\n"
	.string "Das kommt ins Sparschwein.$"
#else
	.string "MOM: That sounds good!\n"
	.string "Into the piggy bank it goes.$"
#endif

PalletTown_PlayersHouse_1F_Text_WithdrawSuccess:
#if GERMAN
	.string "Mama: Hier!$"
#else
	.string "MOM: Here you go!$"
#endif

PalletTown_PlayersHouse_1F_Text_NoMoneyToDeposit:
#if GERMAN
	.string "Mama: Du hast leider kein Geld,\n"
	.string "das du sparen könntest, Liebling.$"
#else
	.string "MOM: You don't have any money to\n"
	.string "save right now, sweetie.$"
#endif

PalletTown_PlayersHouse_1F_Text_NoMoneyToWithdraw:
#if GERMAN
	.string "Mama: Ich habe noch kein Geld\n"
	.string "für dich, Liebling.$"
#else
	.string "MOM: I don't have any money for\n"
	.string "you yet, sweetie.$"
#endif


@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
#if GERMAN
	.string "Mutter: Richtig. Irgendwann gehen alle\n"
	.string "Kinder fort, um ein Abenteuer zu\l"
	.string "erleben!\p"
	.string "Prof. Eich von nebenan hat nach\n"
	.string "dir gefragt.$"
#else
	.string "MOM: …Right.\n"
	.string "All boys leave home someday.\l"
	.string "It said so on TV.\p"
	.string "Oh, yes. PROF. OAK, next door, was\n"
	.string "looking for you.$"
#endif

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
#if GERMAN
	.string "Mutter: … genau!\n"
	.string "Jedes Mädchen träumt vom Reisen.\l"
	.string "Das sieht man im Fernsehen.\p"
	.string "Oh, ja, Prof. Eich von nebenan\n"
	.string "hat nach dir gesucht!$"
#else
	.string "MOM: …Right.\n"
	.string "All girls dream of traveling.\l"
	.string "It said so on TV.\p"
	.string "Oh, yes. PROF. OAK, next door, was\n"
	.string "looking for you.$"
#endif

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
#if GERMAN
	.string "Mutter: {PLAYER}! Du solltest eine\n"
	.string "kurze Pause einlegen.$"
#else
	.string "MOM: {PLAYER}!\n"
	.string "You should take a quick rest.$"
#endif

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
#if GERMAN
	.string "Mutter: Sehr gut! Du und deine Pokémon\n"
	.string "sehen großartig aus!\l"
	.string "Achte auf dich!$"
#else
	.string "MOM: Oh, good! You and your\n"
	.string "POKéMON are looking great.\l"
	.string "Take care now!$"
#endif

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
#if GERMAN
	.string "Im Fernsehen läuft ein Film.\n"
	.string "Vier Jungen laufen ein Bahngleis\l"
	.string "entlang!\p"
	.string "Den Film kenne ich schon! Ich\n"
	.string "mache mich besser auf den Weg!$"
#else
	.string "There's a movie on TV.\n"
	.string "Four boys are walking on railroad\l"
	.string "tracks.\p"
	.string "…I better go, too.$"
#endif

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
#if GERMAN
	.string "Es läuft ein Film im TV.\n"
	.string "Ein bezopftes Mädchen läuft einen\l"
	.string "gelben Steinweg entlang.\p"
	.string "… ich breche auch besser auf!$"
#else
	.string "There's a movie on TV.\n"
	.string "A girl with her hair in pigtails is\l"
	.string "walking up a brick road.\p"
	.string "…I better go, too.$"
#endif

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
#if GERMAN
	.string "Ups, falsche Richtung!$"
#else
	.string "Oops, wrong side…$"
#endif

@ Kanto-Merge: Turbotreter kommen von der Mutter statt vom Eich-Assistenten
@ in Marmoria. Der Assistent dort prueft ebenfalls FLAG_SYS_B_DASH und
@ ueberspringt sich damit selbst.
@ Kanto-Merge: Wortlaut und Ablauf 1:1 von der HnS-Mutter in Neuborkia
@ uebernommen (NewBarkTown_PlayersHouse_1F_EventScript_MomsIntro).
PalletTown_PlayersHouse_1F_EventScript_MomGivePokeGear::
	playfanfare MUS_OBTAIN_ITEM
	message PalletTown_PlayersHouse_1F_Text_ObtainedPokeGear
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox PalletTown_PlayersHouse_1F_Text_ExplainPokeGear, MSGBOX_DEFAULT
	closemessage
	delay 30
	@ Anruf der Mutter vorbereiten - sie probiert das Geraet gleich aus.
	setvar VAR_HNS_MOM_CALL_STEPS, 0
	setflag FLAG_HNS_MOM_CALL_PENDING
	goto PalletTown_PlayersHouse_1F_EventScript_MomGiveRunningShoes
	end

PalletTown_PlayersHouse_1F_Text_ObtainedPokeGear:
#if GERMAN
	.string "{PLAYER} erhielt das PokéCom.$"
#else
	.string "{PLAYER} obtained the POKéGEAR.$"
#endif

PalletTown_PlayersHouse_1F_Text_ExplainPokeGear:
#if GERMAN
	.string "Mama: Telefonnummern befinden\n"
	.string "sich im Speicher.\p"
	.string "Wähle einfach einen Namen aus,\n"
	.string "um anzurufen.\p"
	.string "Wie praktisch!$"
#else
	.string "MOM: Phone numbers are stored\n"
	.string "in memory.\p"
	.string "Just choose a name you want to call.\p"
	.string "Gee, isn't that convenient?$"
#endif

PalletTown_PlayersHouse_1F_EventScript_MomGiveRunningShoes::
	msgbox PalletTown_PlayersHouse_1F_Text_WearTheseRunningShoes, MSGBOX_DEFAULT
	waitmessage
	closemessage
	playfanfare MUS_OBTAIN_ITEM
	msgbox PalletTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	msgbox PalletTown_PlayersHouse_1F_Text_ExplainRunningShoes, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_Text_WearTheseRunningShoes:
#if GERMAN
	.string "Oh, und vergiss nicht deine\n"
	.string "Turbotreter!$"
#else
	.string "Oh, and don't forget your\n"
	.string "RUNNING SHOES!$"
#endif

PalletTown_PlayersHouse_1F_Text_SwitchShoesWithRunningShoes:
#if GERMAN
	.string "{PLAYER} tauschte Schuhe gegen\n"
	.string "die Turbotreter.$"
#else
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"
#endif

PalletTown_PlayersHouse_1F_Text_ExplainRunningShoes:
#if GERMAN
	.string "Mama: {PLAYER}, halte B gedrückt,\n"
	.string "um mit diesen Schuhen zu laufen!$"
#else
	.string "MOM: {PLAYER}, press the B Button\n"
	.string "while wearing these to run fast!$"
#endif

PalletTown_PlayersHouse_1F_EventScript_MomAskRivalName::
	msgbox PalletTown_PlayersHouse_1F_Text_MomAskRivalName
	closemessage
	special NameRival
	waitstate
	setflag FLAG_RIVAL_NAMED_BY_MOM
	msgbox PalletTown_PlayersHouse_1F_Text_MomRivalNameConfirm
	goto PalletTown_PlayersHouse_1F_EventScript_MomGivePokeGear
	end

PalletTown_PlayersHouse_1F_Text_MomAskRivalName:
#if GERMAN
	.string "Ach richtig, Professor Eichs Enkel\n"
	.string "war doch vorhin schon hier.\p"
	.string "Wie hieß der Nachbarsjunge nochmal?$"
#else
	.string "Oh right, PROF. OAK's grandson\n"
	.string "stopped by earlier.\p"
	.string "What was that boy's name again?$"
#endif

PalletTown_PlayersHouse_1F_Text_MomRivalNameConfirm:
#if GERMAN
	.string "{RIVAL}, natürlich! Ihr zwei wart\n"
	.string "schon als Kleinkinder unzertrennlich.$"
#else
	.string "{RIVAL}, of course! You two have been\n"
	.string "inseparable since you were toddlers.$"
#endif

@ Kanto-Merge: Die Mutter vergibt Rivalennamen und Turbotreter. Beides ist
@ Voraussetzung fuer den weiteren Ablauf, deshalb haelt sie den Spieler
@ zurueck, bis das Gespraech gelaufen ist. Der Trigger liegt vor der Tuer.
PalletTown_PlayersHouse_1F_EventScript_BlockExit::
	lock
	goto_if_set FLAG_SYS_B_DASH, PalletTown_PlayersHouse_1F_EventScript_ExitAllowed
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox PalletTown_PlayersHouse_1F_Text_MomWaitAMoment
	closemessage
	release
	end

PalletTown_PlayersHouse_1F_EventScript_ExitAllowed::
	setvar VAR_TEMP_5, 1
	release
	end

PalletTown_PlayersHouse_1F_Text_MomWaitAMoment:
#if GERMAN
	.string "Mutter: Warte kurz, {PLAYER}!\p"
	.string "Ich muss dir noch etwas mitgeben,\n"
	.string "bevor du losziehst.$"
#else
	.string "MOM: Hold on a second, {PLAYER}!\p"
	.string "There's something I need to give you\n"
	.string "before you head out.$"
#endif
