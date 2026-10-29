BattleFrontier_OutsideWest_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition_hns
	.byte 0

BattleFrontier_OutsideWest_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

@ M.S. Aqua to Olivine, Vermilion or Hoenn (see docs/origin_jade/DECISIONS.md, D-029).
BattleFrontier_OutsideWest_EventScript_EventScript_Sailor_hns::
	lock
	faceplayer
	setvar VAR_0x8004, LOCALID_FARAWAY_BATTLE_FRONTIER_HNS_SS_TIDAL
	message BattleFrontier_OutsideWest_Text_SailorReturn_hns
	waitmessage
	goto SSAqua_EventScript_ChooseReturnPort

BattleFrontier_OutsideWest_EventScript_BattleDomeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign_hns::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign_hns, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2_hns::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1_hns::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns
	waitmessage
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_Maniac2_hns::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk_hns::
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns, MSGBOX_DEFAULT
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hns::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper_hnsFaceFactory_hns::
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Camper_hnsAlreadyFacingFactory_hns::
	return

BattleFrontier_OutsideWest_EventScript_Girl_hns::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderNorth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderSouth_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderWest_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_Girl_hnsShudderEast_hns::
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth_hns:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth_hns:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest_hns:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast_hns:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors_hns::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass_hns::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM_hns::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2_hns::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1_hns::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2_hns::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2_hns::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan_hns::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4_hns::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF_hns::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign_hns:
#if GERMAN
	.string "Dies ist das Kampfstadion!\n"
	.string "Dein Weg zum unschlagbaren Superstar!$"
#else
	.string "This is the BATTLE DOME!\n"
	.string "Your path to the invincible superstar!$"
#endif

BattleFrontier_OutsideWest_Text_BattleFactorySign_hns:
#if GERMAN
	.string "Dies ist die Kampffabrik!\n"
	.string "Hier gibt es die härtesten Pokémon!$"
#else
	.string "This is the BATTLE FACTORY!\n"
	.string "Seek out the toughest POKéMON!$"
#endif

BattleFrontier_OutsideWest_Text_BattlePikeSign_hns:
#if GERMAN
	.string "Dies ist die Kampfipitis!\n"
	.string "Welche der drei Bahnen betrittst du?$"
#else
	.string "This is the BATTLE PIKE!\n"
	.string "Choose one of three paths!$"
#endif

BattleFrontier_OutsideWest_Text_ThisIsBattleTower_hns:
#if GERMAN
	.string "Dies ist der Duellturm.\p"
	.string "Trainer tragen mit ihren besten\n"
	.string "Pokémon Ausscheidungskämpfe aus.$"
#else
	.string "This is the BATTLE TOWER.\p"
	.string "TRAINERS bring their best-raised\n"
	.string "POKéMON for elimination-style matches.$"
#endif

BattleFrontier_OutsideWest_Text_MayISeeYourTicket_hns:
#if GERMAN
	.string "Hi! Möchtest du mit der Fähre fahren?\n"
	.string "Zeigst du mir bitte dein Ticket?$"
#else
	.string "Hello, are you here for the ferry?\n"
	.string "May I see your TICKET?$"
#endif

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard_hns:
#if GERMAN
	.string "{PLAYER} hat kein Ticket…\p"
	.string "Das tut mir schrecklich Leid.\p"
	.string "Nur mit einem Ticket kannst du mit der\n"
	.string "Fähre fahren.$"
#else
	.string "{PLAYER} doesn't have the TICKET…\p"
	.string "I'm terribly sorry.\p"
	.string "You must have a TICKET to board\n"
	.string "the ferry.$"
#endif

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo_hns:
#if GERMAN
	.string "{PLAYER} zückt das Ticket.\p"
	.string "Perfekt! Damit kannst du an Bord!\p"
	.string "Und wo soll die Reise hingehen?$"
#else
	.string "{PLAYER} flashed the TICKET.\p"
	.string "Perfect! That's all you need!\p"
	.string "And where would you like to go?$"
#endif

BattleFrontier_OutsideWest_Text_SlateportItIs_hns:
#if GERMAN
	.string "Nach Graphitport City?$"
#else
	.string "SLATEPORT CITY it is, then!$"
#endif

BattleFrontier_OutsideWest_Text_LilycoveItIs_hns:
#if GERMAN
	.string "Nach Seegrasulb City?$"
#else
	.string "LILYCOVE CITY it is, then!$"
#endif

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime_hns:
#if GERMAN
	.string "Bitte komm später noch einmal wieder!$"
#else
	.string "Please sail with us another time!$"
#endif

BattleFrontier_OutsideWest_Text_PleaseBoardFerry_hns:
#if GERMAN
	.string "Bitte komm an Bord. Wir legen bald ab.$"
#else
	.string "Please board the ferry and wait for\n"
	.string "departure.$"
#endif

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo_hns:
#if GERMAN
	.string "Und wo soll die Reise hingehen?$"
#else
	.string "Then, where would you like to go?$"
#endif

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends_hns:
#if GERMAN
	.string "Ich bin der Beste aus unserem\n"
	.string "Freundeskreis. Aber hier…\l"
	.string "Hier bin ich echt aufgeschmissen!$"
#else
	.string "I'm the best out of all my friends.\n"
	.string "But here…\l"
	.string "I've been useless!$"
#endif

BattleFrontier_OutsideWest_Text_CantFindBattleTower_hns:
#if GERMAN
	.string "Ich möchte gerne in den Duellturm, aber\n"
	.string "ich finde den einfach nicht, obwohl ich\l"
	.string "eine Karte der Kampfzone\p"
	.string "habe. Hier ist alles so groß…$"
#else
	.string "I want to go to the BATTLE TOWER,\n"
	.string "but I can't find it even though I have\l"
	.string "a map of the BATTLE FRONTIER.\p"
	.string "This place is just too big!$"
#endif

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere_hns:
#if GERMAN
	.string "Ich wollte mich einer Herausforderung\n"
	.string "stellen, sobald ich hier angekommen bin.\p"
	.string "Aber auf dem Weg hierhin bin ich\n"
	.string "seekrank geworden… hurps…$"
#else
	.string "I wanted to take a challenge as soon\n"
	.string "as I arrived here.\p"
	.string "But on the way, I got seasick…\n"
	.string "Urrrrp…$"
#endif

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere_hns:
#if GERMAN
	.string "Weißt du, hier kann nicht einfach\n"
	.string "jeder hinkommen.\p"
	.string "Nur die Trainer, die durch ihr Talent und\n"
	.string "ihre Stärke aufgefallen sind, werden\l"
	.string "eingeladen.\p"
	.string "Deshalb haben viele Trainer noch nie\n"
	.string "etwas über die Kampfzone gehört.$"
#else
	.string "It's not as if just anyone can come\n"
	.string "here, you know?\p"
	.string "Only those TRAINERS who've been\n"
	.string "recognized as tough are brought here.\p"
	.string "That's why many TRAINERS don't even\n"
	.string "know about the BATTLE FRONTIER.$"
#endif

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons_hns:
#if GERMAN
	.string "Hey, Brüderchen…\p"
	.string "Bist du sicher, wir können\n"
	.string "Herausforderungen annehmen, obwohl wir\l"
	.string "keine Pokémon besitzen?$"
#else
	.string "Hey, bro…\p"
	.string "Are you sure we can make challenges\n"
	.string "even if we don't have any POKéMON?$"
#endif

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons_hns:
#if GERMAN
	.string "Ääh… Ich bin sicher, dass das geht!\p"
	.string "Denke ich…\p"
	.string "Erinnerst du dich an diesen großen\n"
	.string "unheimlichen Kerl, der sagte “Ich leihe\l"
	.string "euch Pokémon!”?$"
#else
	.string "Uh…\n"
	.string "I'm sure it'll be okay.\p"
	.string "I think…\p"
	.string "But remember that big scary guy?\n"
	.string "He said, “I'll lend you POKéMON!”$"
#endif

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons_hns:
#if GERMAN
	.string "Dies ist die Kampffabrik. Hier\n"
	.string "kannst du dir starke Pokémon leihen.\p"
	.string "Ich frage mich nur, wer diese Pokémon\n"
	.string "aufzieht?$"
#else
	.string "That's the BATTLE FACTORY.\n"
	.string "You can rent strong POKéMON there.\p"
	.string "But it makes me wonder.\n"
	.string "Who's raising those rental POKéMON?$"
#endif

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper_hns:
#if GERMAN
	.string "Ich habe Angst, zur Kampfipitis zu\n"
	.string "gehen. Ich fürchte mich vor Vipitis…\p"
	.string "Ab-aber ich bin von so weit gekommen,\n"
	.string "ich muss einfach weitergehen!\l"
	.string "… Zitter bibber…$"
#else
	.string "I'm scared of going into the BATTLE\n"
	.string "PIKE because of SEVIPER…\p"
	.string "B-but I came all the way here, so I will\n"
	.string "try to conquer everything!\l"
	.string "…Shudder…$"
#endif

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors_hns:
#if GERMAN
	.string "Komm, wir spielen Schere Stein Papier!\n"
	.string "Eins, zwei, drei!\p"
	.string "… … … … …\n"
	.string "…$"
#else
	.string "Let's play rock, paper, scissors!\n"
	.string "One, two, three!\p"
	.string "… … … … … …$"
#endif

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge_hns:
#if GERMAN
	.string "Juhuu! Ich habe geeewonnen!!!\n"
	.string "Ich werde die\l"
	.string "Kampfipitis-Herausforderung annehmen!$"
#else
	.string "Yay! I won!\n"
	.string "I will take the BATTLE PIKE challenge!$"
#endif

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge_hns:
#if GERMAN
	.string "Oh jeee…\n"
	.string "Ich habe verloren.\p"
	.string "Heute ist anscheinend nicht mein\n"
	.string "Glückstag. Ich warte mit der Eroberung\l"
	.string "der Kampfipitis bis morgen.$"
#else
	.string "Oh, no…\n"
	.string "I lost.\p"
	.string "I guess I'm not very lucky today.\n"
	.string "I'll put off my BATTLE PIKE challenge\l"
	.string "until tomorrow.$"
#endif

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling_hns:
#if GERMAN
	.string "Ich glaube, ich bin das einzige Wesen\n"
	.string "hier, das lieber angelt als kämpft.\l"
	.string "Warum auch immer…\p"
	.string "Wie? Hier kann man gar nichts\n"
	.string "fangen?!? Was für eine Enttäuschung…$"
#else
	.string "I believe I'm the only person here who,\n"
	.string "for some unknown reason, would choose\l"
	.string "fishing over battling.\p"
	.string "Huh? You can't catch anything here?\n"
	.string "That's disappointing…$"
#endif

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol_hns:
#if GERMAN
	.string "Heute werde ich unter allen Umständen\n"
	.string "so lange kämpfen, bis ich ein Symbol\l"
	.string "bekomme!$"
#else
	.string "Today, I'm going to keep battling, no\n"
	.string "matter what, until I get a Symbol.$"
#endif

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome_hns:
#if GERMAN
	.string "Wie? Du willst dich den\n"
	.string "Herausforderungen des Kampfstadions\l"
	.string "stellen?\p"
	.string "Dann wünsche ich dir viel Glück!\n"
	.string "Wir siegen uns den Weg nach oben und\l"
	.string "treffen uns an der Spitze wieder.$"
#else
	.string "Oh? You're off to challenge\n"
	.string "the BATTLE DOME?\p"
	.string "I'll wish you the best of luck.\n"
	.string "Let us both win our way up and meet\l"
	.string "in challenges.$"
#endif

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa_hns:
#if GERMAN
	.string "Opa, hier drüben!\n"
	.string "Das Kampfstadion ist hier!\l"
	.string "Los, Opa, zeig’s ihnen!$"
#else
	.string "Grandpa, over here!\n"
	.string "The BATTLE DOME is here!\l"
	.string "Go get 'em, Grandpa!$"
#endif

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe_hns:
#if GERMAN
	.string "So, dies ist also das Kampfstadion?!?\n"
	.string "Kein Gentleman wird mich besiegen!\p"
	.string "Aber wo ist denn nur der Eingang?$"
#else
	.string "Ah, so this here is the BATTLE DOME?\n"
	.string "I won't let GENTLEMEN beat me!\p"
	.string "But where is the entrance?$"
#endif

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo_hns:
#if GERMAN
	.string "Vor nicht allzu langer Zeit gab es\n"
	.string "hier nichts. Nur Ödnis.\p"
	.string "Und nun schau sich einer diesen Ort an!\n"
	.string "Unglaublich! Ich werde meine Mutter\p"
	.string "mal hierher bringen, damit sie das sieht.$"
#else
	.string "There used to be nothing here not all\n"
	.string "that long ago.\p"
	.string "But, now look at this place! Amazing!\n"
	.string "I'll bring my mother out to see this.$"
#endif

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier_hns:
#if GERMAN
	.string "Endlich habe ich die Kampfzone\n"
	.string "erreicht.\p"
	.string "Mit meinem Aussehen und meinem Talent\n"
	.string "sorge ich bestimmt für Aufsehen.$"
#else
	.string "I've finally arrived at the BATTLE\n"
	.string "FRONTIER!\p"
	.string "I'm sure to grab attention with\n"
	.string "my looks and ability!$"
#endif

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople_hns:
#if GERMAN
	.string "… Kau… … Schmatz…\p"
	.string "Hier sind offensichtlich nur starke\n"
	.string "Typen anwesend.\p"
	.string "… Schmatz… … Kau…$"
#else
	.string "Munch, munch…\p"
	.string "It looks like this square's filled with\n"
	.string "tough people.\p"
	.string "Munch, munch…$"
#endif

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike_hns:
#if GERMAN
	.string "… Mampf… … Mampf…\p"
	.string "Vor einiger Zeit habe ich dieses ältere\n"
	.string "Mädchen an der Kampfipitis getroffen.\p"
	.string "\p"
	.string "Ihre Augen hatten einen bösartigen\n"
	.string "Ausdruck, sie machte einem richtig\l"
	.string "Angst.\p"
	.string "… Mampf… … Mampf…\p"
	.string "Sie wurde richtig giftig: “Könntest du\n"
	.string "Wohl Endlich Aufhören zu Essen?!?”\p"
	.string "Dann hat sie sich lustig über mich\n"
	.string "gemacht.\p"
	.string "Das war wirklich haarsträubend\n"
	.string "unheimlich. Ehrlich!\p"
	.string "… Mampf… … Mampf…$"
#else
	.string "Crunch, munch…\p"
	.string "A while back, I met this older girl\n"
	.string "at the BATTLE PIKE.\p"
	.string "She had these eyes that were scary\n"
	.string "in a real ornery way.\p"
	.string "Crunch, munch…\p"
	.string "She got all furious: “Will you quit\n"
	.string "eating!” Then she whaled on me.\p"
	.string "It was a hair-raising kind of\n"
	.string "scary experience, sure enough.\p"
	.string "Crunch, munch…$"
#endif

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet_hns:
#if GERMAN
	.string "Was? Hör dir doch mal selber zu!\n"
	.string "Das ist doch wirklich popelig!\p"
	.string "Das letzte Mal als ich ihm zugejubelt\n"
	.string "habe, haben sich unsere Augen\p"
	.string "getroffen. Es hat richtig gefunkt\n"
	.string "zwischen uns!$"
#else
	.string "Huh? Will you listen to yourself?\n"
	.string "That's nothing!\p"
	.string "Why, the last time I cheered for him,\n"
	.string "our eyes met and sparks flew!$"
#endif

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering_hns:
#if GERMAN
	.string "Wiiiiie bitte?!?\n"
	.string "Hah! Ha ha ha!\p"
	.string "Der Stadionstar hat doch nur in deine\n"
	.string "Richtung geschaut, weil ich ihm\l"
	.string "zugejubelt habe!$"
#else
	.string "Whaaaaaat?!\n"
	.string "Pfft!\p"
	.string "That only happened because\n"
	.string "I happened to be sitting next to you!\p"
	.string "The DOME ACE only looked our way\n"
	.string "because my cheering was so loud!$"
#endif

BattleFrontier_OutsideWest_Text_DomeAceIsMine_hns:
#if GERMAN
	.string "Oh, bitte, vertragt euch!\n"
	.string "Hört auf zu streiten!\p"
	.string "Ihr solltet lieber einem Arenaleiter\n"
	.string "zujubeln!\p"
	.string "Der Stadionstar ist mein großes Idol!\n"
	.string "Ihr seid zu jung, um sein Talent zu\l"
	.string "verstehen!$"
#else
	.string "Oh, shush!\n"
	.string "Keep that racket down!\p"
	.string "You fair-weather fans should stick\n"
	.string "to cheering for some GYM LEADER!\p"
	.string "The DOME ACE is mine!\n"
	.string "The only idol for me!$"
#endif

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers_hns:
#if GERMAN
	.string "Diese Leute da, die sich gerade in den\n"
	.string "Haaren liegen…\p"
	.string "Es ist schwer zu glauben, aber das\n"
	.string "waren mal Trainer. Gute Trainer sogar!\l"
	.string "\p"
	.string "Sie waren stark und auch berühmt.\p"
	.string "Aber ein bestimmter Trainer hat sie bei\n"
	.string "einem Turnier mit Pauken und Trompeten\l"
	.string "besiegt.\p"
	.string "Trotz ihrer Niederlage haben sie sich\n"
	.string "regelrecht in ihn verliebt.\p"
	.string "Nun leben sie ihr Leben als Fans und\n"
	.string "jubeln diesem Trainer jeden Tag im\l"
	.string "Kampfstadion zu.$"
#else
	.string "Those people squabbling over there…\p"
	.string "It's hard to believe, but they once\n"
	.string "were TRAINERS, and good ones, too.\p"
	.string "They used to be incredibly tough,\n"
	.string "and they were famous, too.\p"
	.string "But they were obliterated by this\n"
	.string "certain TRAINER at a tournament.\p"
	.string "They were so thoroughly whipped,\n"
	.string "they became smitten by the TRAINER.\p"
	.string "Now they're just fans of the TRAINER.\n"
	.string "They go cheer for their idol at the\l"
	.string "BATTLE DOME every day now.$"
#endif

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier_hns:
#if GERMAN
	.string "Ich habe gehört, dass jemand gehört\n"
	.string "hat, ein Pokémon mit einem ungewöhnlich\l"
	.string "langen Schweif sei hier in der\p"
	.string "Kampfzone aufgetaucht. Das ist\n"
	.string "bestimmt anbetungswürdig…\p"
	.string "Die Herausforderungen können warten.\n"
	.string "Ich will dieses hübsche Geschöpf\l"
	.string "finden!$"
#else
	.string "I heard a rumor that someone saw\n"
	.string "a POKéMON with an unusually long tail\l"
	.string "somewhere in the BATTLE FRONTIER.\p"
	.string "It must be adorable. I'm sure of it…\p"
	.string "Oh, challenges can wait. I feel driven\n"
	.string "to find the delightful creature!$"
#endif

BattleFrontier_OutsideWest_Text_SailorReturn_hns:
#if GERMAN
	.string "Die See ist ruhig heute.\p"
	.string "Wohin möchtest du segeln?$"
#else
	.string "The sea is calm today.\p"
	.string "Where would you like to sail?$"
#endif
