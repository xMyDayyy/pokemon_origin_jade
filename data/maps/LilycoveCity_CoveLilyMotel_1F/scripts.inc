LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_IS_HOENN_CHAMPION, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
#if IS_HNS
	setvar VAR_0x8004, 6
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
#else
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
#endif
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
#if GERMAN
	.string "Hm, so haben sie also die Anzahl der\n"
	.string "Gäste verdoppelt. Indem sie Pokémon\l"
	.string "als Attraktion präsentieren?\p"
	.string "Hm, vielleicht sollte ich ein niedliches\n"
	.string "Pokémon zum Maskottchen meines\l"
	.string "Gasthofes machen…\p"
	.string "Ich frage mich, ob ich so mehr\n"
	.string "Gäste hätte?$"
#else
	.string "Hm, so they doubled the guests by\n"
	.string "using POKéMON as attractions?\p"
	.string "Hm, well, maybe I should make a cute\n"
	.string "POKéMON our inn's mascot.\p"
	.string "I wonder if that will attract more\n"
	.string "guests to stay with us?$"
#endif

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
#if GERMAN
	.string "Oh, tut mir Leid, tut mir Leid!\n"
	.string "Ich habe so konzentriert ferngesehen!\l"
	.string "\p"
	.string "Seit Team Aqua in diesem Ort ist,\n"
	.string "bleiben die Gäste aus.$"
#else
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "Since that TEAM AQUA came to town,\n"
	.string "the tourists have been staying away.$"
#endif

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
#if GERMAN
	.string "Hey, geh weg da!\n"
	.string "Du bist doch nicht aus Glas!$"
#else
	.string "Hey, down in front!\n"
	.string "I can't see the TV!$"
#endif

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
#if GERMAN
	.string "Interessant! Du sagst, ein Pokémon hat\n"
	.string "ein Item gefunden, das jemand verloren\l"
	.string "hat?\p"
	.string "Das ist ja was! Wenn wir auch so\n"
	.string "clevere Pokémon hätten…\p"
	.string "Dann könnten wir alles wiederfinden,\n"
	.string "was unsere Gäste verloren haben.$"
#else
	.string "Amazing! You're telling me a POKéMON\n"
	.string "found someone's lost item?\p"
	.string "That's something. If we had some smart\n"
	.string "POKéMON like that…\p"
	.string "We could recover anything that our\n"
	.string "guests mislaid…$"
#endif

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
#if GERMAN
	.string "Oh, tut mir Leid, tut mir Leid!\n"
	.string "Ich habe so konzentriert ferngesehen!\p"
	.string "Ich habe gehört, dass jemand das Ver-\n"
	.string "steck von Team Aqua auffliegen ließ.\p"
	.string "Gut! Dadurch haben wir endlich Gäste.\n"
	.string "Eine ganze Gruppe hat reserviert!\p"
	.string "Das sind Angestellte einer Firma… Äh…\n"
	.string "Game irgendwas…$"
#else
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV!\p"
	.string "I heard that someone busted\n"
	.string "the TEAM AQUA HIDEOUT.\p"
	.string "Thanks to that, we just booked\n"
	.string "a reservation from a big group.\p"
	.string "It was a company called… Uh…\n"
	.string "GAME something…$"
#endif

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
#if GERMAN
	.string "Irre! Ein Pokémon, das das Haus be-\n"
	.string "wachte, hat Einbrecher geschnappt?\p"
	.string "Klasse! Wir sollten auch über einen\n"
	.string "Wachschutz durch Pokémon nachdenken.\p"
	.string "Dadurch könnten wir unseren Gästen\n"
	.string "viel mehr Sicherheit bieten.$"
#else
	.string "Amazing! A house-sitting POKéMON\n"
	.string "caught a burglar?\p"
	.string "That's something. If we had a tough\n"
	.string "POKéMON as a security guard…\p"
	.string "We would be able to provide our guests\n"
	.string "with greater safety.$"
#endif

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
#if GERMAN
	.string "Oh, tut mir Leid, tut mir Leid!\n"
	.string "Ich habe so konzentriert ferngesehen!\l"
	.string "\p"
	.string "Oh, ja. Eine große Gruppe von Gästen\n"
	.string "ist vor kurzem hier eingetroffen.\p"
	.string "Sie haben sich als Game Freak\n"
	.string "eingetragen. Ich denke, sie entwickeln\l"
	.string "Spiele.\p"
	.string "Oh oh, ich sollte mich besser um ihr\n"
	.string "Abendessen kümmern!$"
#else
	.string "Oh, sorry, sorry!\n"
	.string "I was too involved in watching TV.\p"
	.string "Oh, yes. A big group of guests arrived\n"
	.string "a little while ago.\p"
	.string "They booked in as GAME FREAK,\n"
	.string "so I guess they must make games.\p"
	.string "Uh-oh, I'd better get working on\n"
	.string "their dinner!$"
#endif

