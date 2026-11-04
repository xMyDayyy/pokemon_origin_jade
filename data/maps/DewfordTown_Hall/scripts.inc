DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEWFORD_HALL_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_DEWFORD_HALL_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_DEWFORD_HALL_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
#if GERMAN
	.string "Was in ist? Nun, mit Sicherheit\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Ich kann mir ein Leben ohne “{STR_VAR_1}”\n"
	.string "nicht vorstellen!$"
#else
	.string "What's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
	.string "I can't imagine what life would be like\n"
	.string "without “{STR_VAR_1}”!$"
#endif

DewfordTown_Hall_Text_GettingBoredOfTrend:
#if GERMAN
	.string "Was in ist? Nun, mit Sicherheit\n"
	.string "“{STR_VAR_1}”!\p"
	.string "Aber so langsam langweilt es mich.\p"
	.string "Ich sollte mich nach neuen Sachen\n"
	.string "umsehen.$"
#else
	.string "What's in vogue? Why, it has to be\n"
	.string "“{STR_VAR_1}”!\p"
	.string "But I'm getting kind of bored with it.\p"
	.string "I should look for the next big thing.$"
#endif

DewfordTown_Hall_Text_TeachingMonAboutTrend:
#if GERMAN
	.string "Ich bringe meinen Pokémon etwas über\n"
	.string "“{STR_VAR_1}” bei, aber es klappt nicht so\l"
	.string "recht.\p"
	.string "Scheinbar sind sie damit überfordert.$"
#else
	.string "I'm teaching my POKéMON about\n"
	.string "“{STR_VAR_1},”\l"
	.string "but it's not going well.\p"
	.string "It's a bit too much, I think.$"
#endif

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
#if GERMAN
	.string "Ich vertiefe mich gerade in ein hippes\n"
	.string "“{STR_VAR_1}”.\p"
	.string "Gibt es eine enge Verbindung zwischen\n"
	.string "“{STR_VAR_1}”\l"
	.string "und “{STR_VAR_2}”?$"
#else
	.string "I'm studying up on the hip and trendy\n"
	.string "“{STR_VAR_1}” now.\p"
	.string "Is it true that there's a deep link\n"
	.string "between “{STR_VAR_1}”\l"
	.string "and “{STR_VAR_2}”?$"
#endif

DewfordTown_Hall_Text_MyHunchWasRight:
#if GERMAN
	.string "Oh! Da lag ich ja absolut richtig!\p"
	.string "Ich bin einen Schritt weiter in meinen\n"
	.string "Bemühungen, hip und aufregend zu sein!$"
#else
	.string "Oh!\n"
	.string "So, my hunch was right!\p"
	.string "I'm one step closer to being hip and\n"
	.string "happening, yowza!$"
#endif

DewfordTown_Hall_Text_NotEasyToKeepUp:
#if GERMAN
	.string "Was?!? Wirklich?!?\p"
	.string "Für einen alten Menschen ist es gar\n"
	.string "nicht so leicht, mit der Mode zu gehen!$"
#else
	.string "What?!\n"
	.string "Is that so?!\p"
	.string "It's not easy for an older fellow like\n"
	.string "me to keep up with trends!$"
#endif

DewfordTown_Hall_Text_TVShowAboutTrend:
#if GERMAN
	.string "Diese ganze Sache mit “{STR_VAR_1}”…\n"
	.string "Gibt es da nicht eine Sendung drüber?$"
#else
	.string "This whole business about\n"
	.string "“{STR_VAR_1}”…\l"
	.string "Isn't there a TV show on it?$"
#endif

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
#if GERMAN
	.string "Jenseits des Meeres…\p"
	.string "Ist dort “{STR_VAR_1}”\n"
	.string "noch beliebter?$"
#else
	.string "Across the sea…\p"
	.string "Is “{STR_VAR_1}”\n"
	.string "even more popular?$"
#endif

DewfordTown_Hall_Text_CollectTrendMerchandise:
#if GERMAN
	.string "Ich sammle lizenzierte\n"
	.string "“{STR_VAR_1}”-Artikel.\p"
	.string "Ich habe die offiziellen\n"
	.string "“{STR_VAR_1}”-Puppen.\p"
	.string "Offizielle “{STR_VAR_1}”-Kleidung…\p"
	.string "Und die offiziellen\n"
	.string "“{STR_VAR_1}”-Bilderbücher.\p"
	.string "Hähähä, das besitze ich alles!\n"
	.string "Und ich gebe dir nichts ab! Ätsch!$"
#else
	.string "I collect official\n"
	.string "“{STR_VAR_1}”\l"
	.string "licensed merchandise.\p"
	.string "I have official\n"
	.string "“{STR_VAR_1}” DOLLS…\p"
	.string "Official “{STR_VAR_1}”\n"
	.string "brand clothing…\p"
	.string "And officially licensed\n"
	.string "“{STR_VAR_1}”\l"
	.string "picture books.\p"
	.string "Heheh, I own!\n"
	.string "I'm not sharing anything with you!$"
#endif

DewfordTown_Hall_Text_BooksAboutTrend:
#if GERMAN
	.string "Gute “{STR_VAR_1}” & Schlechte\n"
	.string "“{STR_VAR_1}”…\p"
	.string "Das Band Zwischen “{STR_VAR_1}”\n"
	.string "Und Pokémon…\p"
	.string "Hilfreiche “{STR_VAR_1}”…\p"
	.string "Es ist total voll gestopft mit Büchern\n"
	.string "über “{STR_VAR_1}”.$"
#else
	.string "IDENTIFYING GOOD\n"
	.string "“{STR_VAR_1}” &\l"
	.string "BAD “{STR_VAR_1}”…\p"
	.string "THE LINK BETWEEN\n"
	.string "“{STR_VAR_1}” AND\l"
	.string "POKéMON…\p"
	.string "USEFUL\n"
	.string "“{STR_VAR_1}”…\p"
	.string "It's neatly jammed with books about\n"
	.string "“{STR_VAR_1}.”$"
#endif

DewfordTown_Hall_Text_TrendsScream:
#if GERMAN
	.string "“Der Ruf von {STR_VAR_1}”\n"
	.string "ist der Titel.$"
#else
	.string "“{STR_VAR_1}'S\n"
	.string "SCREAM” is the title.$"
#endif

DewfordTown_Hall_Text_TrendsSmile:
#if GERMAN
	.string "“Das Lächeln von {STR_VAR_1}”\n"
	.string "ist der Titel.$"
#else
	.string "“{STR_VAR_1}'S\n"
	.string "SMILE” is the title.$"
#endif

DewfordTown_Hall_Text_LastTrend:
#if GERMAN
	.string "Es heißt “das Letzte {STR_VAR_1}”.$"
#else
	.string "It's titled “THE LAST\n"
	.string "{STR_VAR_1}”.$"
#endif

DewfordTown_Hall_Text_BirthOfTrend:
#if GERMAN
	.string "Es heißt “die Geburt eines {STR_VAR_1}”.$"
#else
	.string "It's titled “THE BIRTH OF\n"
	.string "{STR_VAR_1}”.$"
#endif

DewfordTown_Hall_Text_SawTrendCoolestThing:
#if GERMAN
	.string "Ich habe “{STR_VAR_1}”\n"
	.string "gesehen! Cool, was?\p"
	.string "Das Coolste überhaupt, würde ich\n"
	.string "sagen! \p"
	.string "Es war unglaublich!\n"
	.string "Das war das absolut Wahre, oh yeah!$"
#else
	.string "I saw “{STR_VAR_1}”!\n"
	.string "Cool, huh?\p"
	.string "It's, like, the coolest thing going!\p"
	.string "It was awesome!\n"
	.string "It was the real thing, oh yeah!$"
#endif

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
#if GERMAN
	.string "Oh, nein, nein, nein.\p"
	.string "Das vermeintliche\n"
	.string "“{STR_VAR_1}”,\l"
	.string "das du gesehen hast - war nicht echt.\p"
	.string "Das echte ist…\n"
	.string "Wie soll ich sagen?\l"
	.string "Ist spitzer und wohlgeformter!\p"
	.string "Aber egal. Es ist erstaunlich!$"
#else
	.string "Oh, no, no, no.\p"
	.string "That alleged\n"
	.string "“{STR_VAR_1}”\l"
	.string "you claim to have seen--it's not.\p"
	.string "The authentic article is much…\n"
	.string "How should I say it?\l"
	.string "Sharper, yet more mellow!\p"
	.string "Ah, no matter. It's astonishing!$"
#endif

DewfordTown_Hall_Text_ComposedTrendThemeSong:
#if GERMAN
	.string "Hey, hör zu! Ich habe ein Leitmotiv für\n"
	.string "“{STR_VAR_1}”\l"
	.string "komponiert.\p"
	.string "“{STR_VAR_1}”\n"
	.string "ist gerade sehr populär.\p"
	.string "Okay, hör zu!\n"
	.string "… …\p"
	.string "Oh! {STR_VAR_1}!\p"
	.string "Wundervolles {STR_VAR_1}!$"
#else
	.string "Hey, listen, I composed a theme song\n"
	.string "for “{STR_VAR_1}.”\p"
	.string "“{STR_VAR_1}”\n"
	.string "is really popular right now.\p"
	.string "Okay, listen!\n"
	.string "… …\p"
	.string "Oh!\n"
	.string "{STR_VAR_1}!\p"
	.string "Wonderful\n"
	.string "{STR_VAR_1}!$"
#endif

DewfordTown_Hall_Text_WorkOnYourSinging:
#if GERMAN
	.string "… …\p"
	.string "Ich würde sagen, du solltest erst\n"
	.string "einmal Gesangsunterricht nehmen, bevor\l"
	.string "du es mit “{STR_VAR_1}”\l"
	.string "aufnimmst.$"
#else
	.string "… …\p"
	.string "I dare say, chap, it would pay for you\n"
	.string "to work on your singing before you\l"
	.string "trifle yourself with\l"
	.string "“{STR_VAR_1}.”$"
#endif

DewfordTown_Hall_Text_OrganizeTrendParty:
#if GERMAN
	.string "Wie ich vorhin schon sagte, sollten wir\n"
	.string "uns zusammentun und eine\l"
	.string "“{STR_VAR_1}”-Party auf der Insel\l"
	.string "veranstalten.$"
#else
	.string "Anyway, as I was saying earlier, we\n"
	.string "should get together and organize a\l"
	.string "“{STR_VAR_1}” party\l"
	.string "on the island.$"
#endif

DewfordTown_Hall_Text_BrilliantIndeed:
#if GERMAN
	.string "Oh, was für eine gute Idee!\p"
	.string "Nun stellen wir ein für alle Mal fest, wer\n"
	.string "der Beste in “{STR_VAR_1}” ist.\l"
	.string "Brillant, wirklich!\p"
	.string "Von heute an dreht sich unser Leben\n"
	.string "um “{STR_VAR_1}”!$"
#else
	.string "Oh, a smashing good idea!\p"
	.string "It will settle once and for all\n"
	.string "who is the best at\l"
	.string "“{STR_VAR_1}.”\l"
	.string "Brilliant, indeed!\p"
	.string "Starting today, our lives will revolve\n"
	.string "around “{STR_VAR_1}”!$"
#endif

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
#if GERMAN
	.string "Ich habe nachgedacht…\p"
	.string "Stimmst du mir zu, dass “{STR_VAR_1}” von\n"
	.string "etwas Modernem zu einem Teil unseres\l"
	.string "Lebens geworden ist?$"
#else
	.string "I was thinking, though…\p"
	.string "Wouldn't you agree that\n"
	.string "“{STR_VAR_1}” has\l"
	.string "grown from being something trendy to\l"
	.string "being a part of our daily lives?$"
#endif

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
#if GERMAN
	.string "Bitte? So dominant?\p"
	.string "Nun ja, natürlich bestimmt “{STR_VAR_1}”\n"
	.string "auch unsere Gedanken, im Wachen und im\l"
	.string "Schlafen.\p"
	.string "Du bist mit Sicherheit der\n"
	.string "“{STR_VAR_1}”-Professor!$"
#else
	.string "Beg pardon?\n"
	.string "That much, what?\p"
	.string "However, it's true that\n"
	.string "“{STR_VAR_1}”\l"
	.string "weighs heavily on your mind, whether\l"
	.string "you're awake or asleep.\p"
	.string "Absolutely, you're the\n"
	.string "“{STR_VAR_1}”\l"
	.string "PROFESSOR, old sport!$"
#endif

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
#if GERMAN
	.string "Wenn du und ich ein Team bilden, sind wir\n"
	.string "unverwundbar gegen “{STR_VAR_1}”!$"
#else
	.string "If you and me team up as a combo,\n"
	.string "we'll be invincible when it comes to all\l"
	.string "things “{STR_VAR_1}”!$"
#endif

DewfordTown_Hall_Text_WellBeTrendDuo:
#if GERMAN
	.string "Licht an, mein Freund!\p"
	.string "Wir sind das “{STR_VAR_1}”-Duo!\p"
	.string "Ist das nicht eine irre Vorstellung?\n"
	.string "Hahahaha!$"
#else
	.string "Spot on, my friend!\p"
	.string "We shall be the\n"
	.string "“{STR_VAR_1}” DUO!\p"
	.string "Isn't that a ripe image?\n"
	.string "Hahahah!$"
#endif

DewfordTown_Hall_Text_GiveYouSludgeBomb:
#if GERMAN
	.string "Für mich ist Matschbombe das absolut\n"
	.string "Größte!\p"
	.string "Wie? Du willst mir doch nicht\n"
	.string "weismachen, dass du Matschbombe nicht\l"
	.string "kennst?\p"
	.string "Das ist aber jammerschade.\n"
	.string "Ich werde dir eine geben.$"
#else
	.string "For me, SLUDGE BOMB is at the peak\n"
	.string "of popularity. It's the one.\p"
	.string "Hunh? You're telling me that you don't\n"
	.string "know about SLUDGE BOMB?\p"
	.string "That's outright pitiful.\n"
	.string "I'll give you one.$"
#endif

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
#if GERMAN
	.string "Ich liebe Matschbombe.\p"
	.string "Aber Pokémon, die “{STR_VAR_1}” kennen,\n"
	.string "sind auch absolut angesagt.$"
#else
	.string "I love SLUDGE BOMB.\p"
	.string "But POKéMON with the move\n"
	.string "“{STR_VAR_1}”\l"
	.string "are in, too.$"
#endif

