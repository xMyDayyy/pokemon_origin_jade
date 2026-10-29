BlackthornCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	@ The boy blocks the gym until the player has Johto badges 5-7.
	call BlackthornCity_EventScript_CheckJohtoBadges5To7
	goto_if_eq VAR_RESULT, FALSE, BlackThornCity_EventScript_MoveGymBoy
	end

@ VAR_RESULT = TRUE if the player holds Johto badges 5, 6 and 7.
BlackthornCity_EventScript_CheckJohtoBadges5To7::
	setvar VAR_0x8004, 4
	special CheckJohtoBadge
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_EventScript_CheckJohtoBadges5To7End
	setvar VAR_0x8004, 5
	special CheckJohtoBadge
	goto_if_eq VAR_RESULT, FALSE, BlackthornCity_EventScript_CheckJohtoBadges5To7End
	setvar VAR_0x8004, 6
	special CheckJohtoBadge
BlackthornCity_EventScript_CheckJohtoBadges5To7End::
	return

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter::
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	special GetWeekday
	call_if_ne VAR_RESULT, WEEKDAY_SAT, BlackthornCity_EventScript_HideSantos
	end

@ Santos of the weekday siblings is only here on Saturday, see
@ docs/origin_jade/DECISIONS.md, D-033.
BlackthornCity_EventScript_HideSantos:
	setflag FLAG_TEMP_1
	return

BlackthornCity_EventScript_Call::
	lock
	setspeaker BlackthornCity_Text_ElmName
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_ElmName:
#if GERMAN
	.string "Lind$"
#else
	.string "PROF.ELM$"
#endif

BlackthornCity_Text_BaobaCall:
#if GERMAN
	.string "Aufseher Baoba: {PLAYER}!\p"
	.string "Hier ist Aufseher Baoba.\p"
	.string "Ich rufe dich an, um dir\n"
	.string "mitzuteilen, dass die\l"
	.string "Safari-Zone vergrößert wurde!\p"
	.string "Bitte komm vorbei!$"
#else
	.string "WARDEN BAOBA: {PLAYER}!\p"
	.string "This is WARDEN BAOBA.\p"
	.string "I'm calling to tell you that the\n"
	.string "SAFARI ZONE has expanded!\p"
	.string "Please come visit!$"
#endif

BlackthornCity_Text_ElmCall:
#if GERMAN
	.string "Hallo, {PLAYER}?\p"
	.string "Professor Eich hat mir etwas für\n"
	.string "dich mitgegeben.\p"
	.string "Komm doch mal im Labor vorbei.\n"
	.string "Ich zähle auf dich!$"
#else
	.string "PROF.ELM: Hello, {PLAYER}?\p"
	.string "I have something here for you.\n"
	.string "Could you swing by my LAB?\p"
	.string "See you later!$"
#endif

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	call BlackthornCity_EventScript_CheckJohtoBadges5To7
	goto_if_eq VAR_RESULT, FALSE, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
#if GERMAN
	.string "Sandra, unsere Arenaleiterin, hat\n"
	.string "deinen Fortschritt verfolgt.\p"
	.string "Sie kämpft jedoch nur gegen Trainer,\n"
	.string "die bereits 7 Orden besitzen.$"
#else
	.string "CLAIR, our GYM LEADER, has been\n"
	.string "following your progress.\p"
	.string "However, she only battles trainers\n"
	.string "who already have 7 badges.$"
#endif

BlackthornCity_Text_ClairIsIn:
#if GERMAN
	.string "Sandra, unsere Arenaleiterin,\n"
	.string "erwartet dich bereits.\p"
	.string "Aber ein mittelmäßiger Trainer\n"
	.string "könnte sie niemals besiegen!$"
#else
	.string "CLAIR, our GYM LEADER, is waiting\n"
	.string "for you.\p"
	.string "However, it would be impossible for\n"
	.string "a run-of-the-mill trainer to win.$"
#endif

BlackthornCity_Text_ClairIsBeaten:
#if GERMAN
	.string "Du hast Sandra besiegt? Unglaublich!\p"
	.string "Außer Siegfried ist es noch niemandem\n"
	.string "gelungen, gegen sie zu gewinnen!$"
#else
	.string "You defeated CLAIR?\p"
	.string "That's amazing!\p"
	.string "I've never heard of her losing to\n"
	.string "anyone other than LANCE.$"
#endif

BlackthornGrampsRefusesEntryText:
#if GERMAN
	.string "Nein. Nur auserwählte Trainer dürfen\n"
	.string "hier trainieren.\p"
	.string "Ich muss dich bitten, wieder zu gehen.$"
#else
	.string "No. Only chosen trainers may train\n"
	.string "here.\p"
	.string "Please leave.$"
#endif

BlackthornGrampsGrantsEntryText:
#if GERMAN
	.string "Wenn Sandra nichts dagegen hat, wird\n"
	.string "auch ihr Großvater, unser Meister,\l"
	.string "sicher kein Problem damit haben.\p"
	.string "Bitte, tritt ein.$"
#else
	.string "If CLAIR allows it, her grand-\n"
	.string "father--our MASTER--will also.\p"
	.string "You may enter.$"
#endif

BlackBeltText_VoicesInMyHead:
#if GERMAN
	.string "Aruuu! Stimmen in meinem Kopf!\p"
	.string "Oh… ich höre ja bloß Radio!$"
#else
	.string "Arooo! Voices in my head!\p"
	.string "Huh? I'm listening to my radio!$"
#endif

BlackthornCooltrainerF1Text:
#if GERMAN
	.string "Oh, sag mal, lässt du deine Pokémon\n"
	.string "auch manchmal Attacken vergessen?$"
#else
	.string "Are you going to make your POKéMON\n"
	.string "remember some moves?$"
#endif

BlackthornYoungsterText:
#if GERMAN
	.string "Ebenholz City ist berühmt für\n"
	.string "seine Drachenmeister.$"
#else
	.string "Dragon masters all come from the city\n"
	.string "of BLACKTHORN.$"
#endif

BlackthornCity_MeetSantosText:
#if GERMAN
	.string "Samson: …\p"
	.string "Heute ist Samstag…\p"
	.string "Ich bin Samson vom Samstag…\p"
	.string "Du kannst das haben…$"
#else
	.string "SANTOS: …\p"
	.string "It's Saturday…\p"
	.string "I'm SANTOS of Saturday…\p"
	.string "You can have this…$"
#endif

BlackthornCity_SantosGaveGiftText:
#if GERMAN
	.string "Samson: …\p"
	.string "Bannsticker…\p"
	.string "Geist-Attacken werden verstärkt…\p"
	.string "Es wird dich gruseln…$"
#else
	.string "SANTOS: …\p"
	.string "SPELL TAG…\p"
	.string "GHOST-type moves get stronger…\p"
	.string "It will frighten you…$"
#endif

BlackthornCity_SantosSaturdayText:
#if GERMAN
	.string "Samson: …\p"
	.string "Wir sehen uns ein andermal…\p"
	.string "Ich hab keine Geschenke mehr…$"
#else
	.string "SANTOS: …\p"
	.string "See you again on another Saturday…\p"
	.string "I won't have any more gifts…$"
#endif

BlackthornCooltrainerF2Text:
#if GERMAN
	.string "Wow, du bist über den Eispfad gekommen!\n"
	.string "Dann musst du ein extrem talentierter\l"
	.string "Trainer sein!$"
#else
	.string "Wow, you came through the ICE PATH?\p"
	.string "You must be a real hotshot trainer!$"
#endif

BlackthornCitySignText:
#if GERMAN
	.string "Ebenholz City\n"
	.string "Ein ruhiger Ort in den Bergen$"
#else
	.string "BLACKTHORN CITY\p"
	.string "A Quiet Mountain Retreat$"
#endif

BlackthornGymSignText:
#if GERMAN
	.string "Pokémon-Arena von Ebenholz City\n"
	.string "Leiterin: Sandra Ein gesegneter\l"
	.string "Drachenprofi!$"
#else
	.string "BLACKTHORN CITY POKéMON GYM\n"
	.string "LEADER: CLAIR\p"
	.string "The Blessed User of Dragon POKéMON$"
#endif

BlackthornCity_Text_MoveDeletersHouseSign:
#if GERMAN
	.string "Attacken-Verlerner-Haus$"
#else
	.string "MOVE BROS' HOUSE$"
#endif

BlackthornCity_Text_DragonDenSign:
#if GERMAN
	.string "Drachenhöhle\n"
	.string "Geradeaus$"
#else
	.string "DRAGON'S DEN AHEAD$"
#endif

