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
	.string "Möchtest du einen kleinen Tipp für\n"
	.string "Wettbewerbe?\p"
	.string "Wenn du eine bestimmte Attacke nach\n"
	.string "einer anderen bestimmten Attacke\l"
	.string "zeigst, fällst du besonders auf.\p"
	.string "Wenn du weißt, was du tust, kannst du\n"
	.string "beim Ausdruck groß punkten.\p"
	.string "Natürlich könnten deine Gegner deinem\n"
	.string "Pokémon die Schau stehlen wollen.$"
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
	.string "Hey, Mann, ich bin voll sauer, weißt du.\n"
	.string "Ich wollte doch nur wissen, warum mein\l"
	.string "Pokémon nie gewinnt, weißt du, hey?\p"
	.string "Also, ich hab dem Juror mal meine\n"
	.string "Meinung gesagt, kostet ja nichts.\p"
	.string "Und der hört mir nicht mal zu, hey!\n"
	.string "Voll die Enttäuschung, Mann!\p"
	.string "Hey, du da! Halt die Luft an, ja?\n"
	.string "Und jetzt nimm das!$"
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
	.string "MC: Oh, sieh an, sieh an!\n"
	.string "Ist das nicht ein prächtiges Pokémon?\p"
	.string "Bitte! Tritt näher und nimm an unseren\n"
	.string "herrlichen Wettbewerben teil!\p"
	.string "Du wirst dich gut schlagen! Ganz\n"
	.string "sicher! Mein Auge täuscht mich nie!$"
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
	.string "Juror: Hallo, sei gegrüßt!\n"
	.string "Du bist also ein Trainer!\p"
	.string "Dann darfst du dir einen\n"
	.string "Pokémon-Wettbewerb auf keinen Fall\l"
	.string "entgehen lassen!\p"
	.string "Hol dir in Wiesenflur eine\n"
	.string "Wettbewerbskarte und nimm jederzeit\l"
	.string "teil!$"
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
	.string "Sie haben dem Ausdruck meines\n"
	.string "Pokémon kaum Beachtung geschenkt…\p"
	.string "Pah, dieser Juror erkennt etwas Gutes\n"
	.string "nicht, wenn er es vor sich hat.$"
#else
	.string "They didn't pay much attention to\n"
	.string "my POKéMON's appeal…\p"
	.string "Humph, that JUDGE, he doesn't know\n"
	.string "a good thing when he sees it.$"
#endif

SlateportCity_ContestHall_Text_RewardWithSageAdvice:
#if GERMAN
	.string "Oh, hallo! Du musst ein echter Fan\n"
	.string "sein, so nah am Geschehen.\p"
	.string "Für so viel Begeisterung habe ich\n"
	.string "einen weisen Rat für dich.\p"
	.string "Wenn eine Attacke richtig gut ankommt,\n"
	.string "gerät das Publikum in Aufregung.\p"
	.string "Und das Pokémon, das seinen Ausdruck\n"
	.string "genau dann zeigt…\p"
	.string "Nun, da muss doch etwas Gutes\n"
	.string "geschehen!$"
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
	.string "Ich schaffe das nicht! Ich bin noch\n"
	.string "aufgeregter als mein Pokémon.\p"
	.string "Ich zittere und mein Herz rast!$"
#else
	.string "I can't do this! I'm more freaked out\n"
	.string "than my POKéMON.\p"
	.string "I'm shivering and my heart is racing!$"
#endif

SlateportCity_ContestHall_Text_BattleAndContestAlike:
#if GERMAN
	.string "Ein Kampf und ein Wettbewerb sind\n"
	.string "nicht dasselbe, aber doch ähnlich.\p"
	.string "Du musst hart arbeiten und an die\n"
	.string "Pokémon glauben, die du aufgezogen\l"
	.string "hast.$"
#else
	.string "A battle and a CONTEST aren't the\n"
	.string "same, but they are alike, too.\p"
	.string "You need to work hard and believe\n"
	.string "in the POKéMON you've raised.$"
#endif

SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
#if GERMAN
	.string "Dieses Pokémon ist gut in Form, was?\p"
	.string "Ein Pokémon, das im zweiten Durchlauf\n"
	.string "gut abschneidet, wirkt beim Ausdruck\l"
	.string "gelassener.$"
#else
	.string "That POKéMON looks like it's on top\n"
	.string "of its game, huh?\p"
	.string "A POKéMON that does good in the\n"
	.string "secondary judging seems to be more\l"
	.string "relaxed when it's doing appeals.$"
#endif

SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
#if GERMAN
	.string "Schau dir dieses traurige Bild an!\p"
	.string "Hah, mein Pokémon ist eindeutig besser\n"
	.string "als diese Truppe!$"
#else
	.string "Will you look at that sorry sight?\p"
	.string "Heh, my POKéMON's absolutely better\n"
	.string "than that lot!$"
#endif

SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
#if GERMAN
	.string "Bekommst du nicht auch Lust, dich mit\n"
	.string "den Pokémon zu bewegen, wenn sie einen\l"
	.string "schwungvollen Ausdruck zeigen?$"
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
