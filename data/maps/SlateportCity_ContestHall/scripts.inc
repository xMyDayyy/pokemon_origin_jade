SlateportCity_ContestHall_MapScripts::
	.byte 0

@ Audience hall behind Slateport's contest lobby, as in Ruby/Sapphire (D-058).

SlateportCity_ContestHall_EventScript_FatMan1::
	msgbox SlateportCity_ContestHall_Text_AdviceForContests, MSGBOX_NPC
	end

SlateportCity_ContestHall_EventScript_LittleBoy::
	msgbox SlateportCity_ContestHall_Text_MyPapaIsContestJudge, MSGBOX_NPC
	end

SlateportCity_ContestHall_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_HOENN_RECEIVED_TM_TORMENT, SlateportCity_ContestHall_EventScript_ReceivedTorment
	msgbox SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed, MSGBOX_DEFAULT
	giveitem_unless_owned ITEM_TM_TORMENT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_HOENN_RECEIVED_TM_TORMENT
	msgbox SlateportCity_ContestHall_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_ContestHall_EventScript_ReceivedTorment::
	msgbox SlateportCity_ContestHall_Text_ExplainTorment, MSGBOX_DEFAULT
	release
	end

SlateportCity_ContestHall_EventScript_MC::
	msgbox SlateportCity_ContestHall_Text_MCStepUpTakePartInContest, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Judge::
	msgbox SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Girl::
	msgbox SlateportCity_ContestHall_Text_ItsAppealTime, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Boy1::
	msgbox SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Boy2::
	msgbox SlateportCity_ContestHall_Text_RewardWithSageAdvice, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_FatMan2::
	msgbox SlateportCity_ContestHall_Text_MoreFreakedOutThanMon, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Maniac::
	msgbox SlateportCity_ContestHall_Text_MyMonBetterThanThatLot, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Hiker::
	msgbox SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Boy3::
	msgbox SlateportCity_ContestHall_Text_BattleAndContestAlike, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_Boy4::
	msgbox SlateportCity_ContestHall_Text_MonLooksOnTopOfGame, MSGBOX_NPC
	goto SlateportCity_ContestHall_EventScript_FaceOriginalDirection
	end

SlateportCity_ContestHall_EventScript_FaceOriginalDirection::
	lockall
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_StageSign::
	msgbox SlateportCity_ContestHall_Text_HyperRankStage, MSGBOX_SIGN
	end

SlateportCity_ContestHall_Text_AdviceForContests:
#if GERMAN
	.string "Soll ich dir einen klitzekleinen Tipp für\n"
	.string "den Wettbewerb geben?\p"
	.string "Wenn du eine besondere Attacke nach\n"
	.string "einer bestimmten Attacke einsetzt,\l"
	.string "weckst du besondere Aufmerksamkeit.\p"
	.string "Solange du genau weißt, was du wie zu\n"
	.string "tun hast, wirst du erfolgreich sein.\p"
	.string "Natürlich werden die Mitstreiter\n"
	.string "versuchen, deinem Pokémon die Show zu\l"
	.string "stehlen.$"
#else
	.string "Want a tasty little bit of advice\n"
	.string "for CONTESTS?\p"
	.string "Using a certain move after another\n"
	.string "certain kind of move sometimes gets\l"
	.string "you extra attention.\p"
	.string "If you know what you're doing,\n"
	.string "you can score big in appeal.\p"
	.string "Of course, your opponents might try\n"
	.string "disrupting your POKéMON's showing.$"
#endif

SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
#if GERMAN
	.string "Mein Papa ist ein Juror des\n"
	.string "Wettbewerbs.\p"
	.string "Ich frage mich, was ich mal werden\n"
	.string "soll: Ein Juror oder ein Arenaleiter?$"
#else
	.string "My papa, he's a CONTEST JUDGE.\p"
	.string "I wonder what I should be when I\n"
	.string "grow up, a JUDGE or a GYM LEADER?$"
#endif

SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
#if GERMAN
	.string "Hey, also, das ist wohl Künstlerpech,\n"
	.string "Mann. Ich will einfach wissen, warum\l"
	.string "mein Pokémon nie gewinnt.\l"
	.string "Weißt du, Mann?\p"
	.string "Daher, Mann, habe ich dem Juror meinen\n"
	.string "Senf dazugegeben.\p"
	.string "Und der hat nicht einmal zugehört,\n"
	.string "Mann! Das ist vielleicht eine Niete.\p"
	.string "Hey! Zieh dir das mal rein!\n"
	.string "Hier, Mann, das ist für dich!$"
#else
	.string "Hey, man, I'm like majorly cheesed,\n"
	.string "you know. Like, you know, I just\l"
	.string "wanted to know why my POKéMON\l"
	.string "never won, you know, like, hey?\p"
	.string "So, like, I gave the JUDGE my two\n"
	.string "cents, you know, they're free.\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"
#endif

SlateportCity_ContestHall_Text_ExplainTorment:
#if GERMAN
	.string "Das ist die TM41, weißt du?\n"
	.string "Hey, das ist Folterknecht, sag ich dir.\p"
	.string "Der Gegner wird so daran gehindert, eine\n"
	.string "Attacke zweimal hintereinander\l"
	.string "auszuführen.\p"
	.string "Aber nun hör mir gut zu. Ich würde nie\n"
	.string "Folterknecht gegen dich einsetzen.$"
#else
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's TORMENT, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"
#endif

SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
#if GERMAN
	.string "MC: Oh, meine Güte!\n"
	.string "Ist das nicht ein Dandy von Pokémon?\p"
	.string "Bitte! Tritt näher und nimm an unserem\n"
	.string "großartigen Wettbewerb teil!\p"
	.string "Ich bin sicher, du wirst hervorragend\n"
	.string "abschneiden. Meine Augen täuschen\l"
	.string "mich nie!$"
#else
	.string "MC: Oh, my, my!\n"
	.string "Now isn't that a dandy of a POKéMON?\p"
	.string "Please! Do step right up and take\n"
	.string "part in our splendid CONTESTS!\p"
	.string "You'll do well! I'm sure of it!\n"
	.string "My eyes have never failed me!$"
#endif

SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
#if GERMAN
	.string "Juror: Hallo, du da!\n"
	.string "Wie ich sehe, bist du ein Trainer!\p"
	.string "Nun, dann kannst du es dir eigentlich\n"
	.string "nicht leisten, einen Wettbewerb zu\l"
	.string "verpassen!\p"
	.string "Hol dir in Wiesenflur eine\n"
	.string "Wettbewerbskarte und nimm teil!$"
#else
	.string "JUDGE: Well, hello there!\n"
	.string "I see that you're a TRAINER!\p"
	.string "Then, it just wouldn't do for you\n"
	.string "to miss a POKéMON CONTEST!\p"
	.string "Get a CONTEST PASS in VERDANTURF\n"
	.string "CITY and enter anytime!$"
#endif

SlateportCity_ContestHall_Text_ItsAppealTime:
#if GERMAN
	.string "Showtime!\n"
	.string "Womit soll ich beginnen?$"
#else
	.string "It's appeal time!\n"
	.string "What should I lead with?$"
#endif

SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
#if GERMAN
	.string "Der Auftritt meines Pokémon fand\n"
	.string "nicht viel Beachtung…\p"
	.string "Männo, der Juror hat wohl Tomaten auf\n"
	.string "den Augen!?!$"
#else
	.string "They didn't pay much attention to\n"
	.string "my POKéMON's appeal…\p"
	.string "Humph, that JUDGE, he doesn't know\n"
	.string "a good thing when he sees it.$"
#endif

SlateportCity_ContestHall_Text_RewardWithSageAdvice:
#if GERMAN
	.string "Oh, hi! Du musst ein wirklich großer Fan\n"
	.string "sein, wenn du so nah herangehst.\p"
	.string "Ich belohne deinen Enthusiasmus mit\n"
	.string "einem weisen Rat.\p"
	.string "Wenn eine Attacke wirklich gut gelingt,\n"
	.string "ist das Publikum begeistert.\p"
	.string "Wenn alle begeistert sind, hat das\n"
	.string "Pokémon einen tollen Auftritt gehabt.\p"
	.string "Dann weißt du, dass etwas Tolles\n"
	.string "passieren wird!$"
#else
	.string "Oh, hi! You must be a serious fan to get\n"
	.string "this close to the action.\p"
	.string "I'll reward your enthusiasm with\n"
	.string "this sage advice.\p"
	.string "If a move goes over really well,\n"
	.string "the audience will get excited.\p"
	.string "The POKéMON that makes its appeal\n"
	.string "right when everyone's excited…\p"
	.string "Well, you'd think something good has\n"
	.string "to happen!$"
#endif

SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
#if GERMAN
	.string "Ich kann es einfach nicht! Ich bin\n"
	.string "nervöser als mein Pokémon.\p"
	.string "Ich zittere und mein Herz rast!$"
#else
	.string "I can't do this! I'm more freaked out\n"
	.string "than my POKéMON.\p"
	.string "I'm shivering and my heart is racing!$"
#endif

SlateportCity_ContestHall_Text_BattleAndContestAlike:
#if GERMAN
	.string "Ein Kampf und ein Wettbewerb sind nicht\n"
	.string "dasselbe, aber sie sind sich ähnlich.\p"
	.string "Du musst hart arbeiten und an die\n"
	.string "Pokémon, die du aufziehst, glauben.$"
#else
	.string "A battle and a CONTEST aren't the\n"
	.string "same, but they are alike, too.\p"
	.string "You need to work hard and believe\n"
	.string "in the POKéMON you've raised.$"
#endif

SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
#if GERMAN
	.string "Dieses Pokémon scheint an der Spitze\n"
	.string "zu stehen, was?\p"
	.string "Ein Pokémon, das im zweiten Durchgang\n"
	.string "gut abschneidet, wird im Wettbewerb\l"
	.string "viel ruhiger auftreten.$"
#else
	.string "That POKéMON looks like it's on top\n"
	.string "of its game, huh?\p"
	.string "A POKéMON that does good in the\n"
	.string "secondary judging seems to be more\l"
	.string "relaxed when it's doing appeals.$"
#endif

SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
#if GERMAN
	.string "Guck dir mal diese jämmerlichen\n"
	.string "Gestalten an.\p"
	.string "Mein Pokémon ist viel, viel besser als\n"
	.string "dieser Haufen!$"
#else
	.string "Will you look at that sorry sight?\p"
	.string "Heh, my POKéMON's absolutely better\n"
	.string "than that lot!$"
#endif

SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
#if GERMAN
	.string "Geht es dir nicht auch so? Wenn ein\n"
	.string "Pokémon all seine Energie in eine\l"
	.string "Attacke steckt, bewegt mich das enorm.$"
#else
	.string "Don't you get the urge to move with\n"
	.string "POKéMON if they're putting on an\l"
	.string "energetic appeal?$"
#endif

SlateportCity_ContestHall_Text_HyperRankStage:
#if GERMAN
	.string "Pokémon Wettbewerbe\n"
	.string "Bühne für die Hyper-Klasse!$"
#else
	.string "POKéMON CONTESTS\n"
	.string "HYPER RANK STAGE!$"
#endif
