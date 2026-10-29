VioletCity_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VioletCity_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VioletCity_OnFrame::
	map_script_2 VAR_VIOLET_CITY_KIMONO_GIRL, 1, VioletCity_EventScript_Kimono_Girl
	map_script_2 VAR_VIOLET_CITY_STATE, 3, VioletCity_EventScript_ElmCall_Trigger
	.2byte 0

VioletCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

VioletCity_EventScript_Trigger::
	@LOCAL FLAGHEAP
	clearflag FLAG_RECEIVED_TOGEPI_EGG
	clearflag FLAG_VIOLET_NPC_TRADE_COMPLETED
	clearflag FLAG_HIDE_SPROUT_TOWER_SILVER
	clearflag FLAG_HIDE_JOHTO_GYM_LEADERS
	clearflag FLAG_HOOH_BROUGHT
	clearflag FLAG_OMANYTE_BROUGHT
	clearflag FLAG_AERODACTYL_BROUGHT
	clearflag FLAG_KABUTO_BROUGHT
	clearflag FLAG_HIDE_SUDOWOODO
	clearflag FLAG_GOT_HARD_STONE
	clearflag FLAG_GOT_POISON_BARB
	clearflag FLAG_HIDE_UNION_CAVE_LAPRAS
	clearflag FLAG_GOT_BLACK_GLASSES

	setvar VAR_SLOWPOKE_TAIL, 0
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 0
	setvar VAR_RUINSOFALPH_STATE, 0

	setflag FLAG_ITEM_GS_BALL
	setflag FLAG_ITEM_DOME_FOSSIL
	setflag FLAG_ITEM_HELIX_FOSSIL
	setflag FLAG_ITEM_OLD_AMBER
	setflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_VISITED_VIOLET_CITY
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL

	setvar VAR_SPROUT_TOWER, 0
	setvar VAR_VIOLET_CITY_STATE, 1
	end

VioletCity_EventScript_Earl::
	lock
	faceplayer
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	faceplayer
	msgbox VioletCity_Text_EarlAsksIfYouBeatFalkner, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_EventScript_EarlTrainerSchool
	msgbox VioletCity_Text_VeryNiceIndeed, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_EarlTrainerSchool::
	msgbox VioletCity_Text_FollowEarl, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_HG_FOLLOW_ME_2, FALSE
	switch VAR_FACING
	case DIR_NORTH, VioletCity_EventScript_EarlTrainerSchoolSouth
	case DIR_WEST, VioletCity_EventScript_EarlTrainerSchoolEast
	release
	end

VioletCity_EventScript_EarlTrainerSchoolSouth::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_South_Adjustment
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_South_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolEast::
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_East_Adjustment
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Player_East_Adjustment
	waitmovement 0
	waitmovement 0
	goto VioletCity_EventScript_EarlTrainerSchoolTransition
	release
	end

VioletCity_EventScript_EarlTrainerSchoolTransition:
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Walk_To_School
	applymovement OBJ_EVENT_ID_PLAYER, VioletCity_Movement_Walk_To_School
	waitmovement 0
	waitmovement 0
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Spin
	waitmovement 0
	turnobject LOCALID_VIOLETCITY_EARL, DIR_WEST
	msgbox VioletCity_Text_HereTeacherIAm, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLETCITY_EARL, VioletCity_Movement_Earl_Walk_Inside
	delay 20
	opendoor 39, 36
	waitdooranim
	waitmovement 0
	setflag FLAG_HIDE_VIOLET_CITY_EARL
	removeobject LOCALID_VIOLETCITY_EARL
	closedoor 39, 36
	waitdooranim
	clearflag FLAG_HIDE_TRAINER_SCHOOL_EARL
	fadedefaultbgm
	release
	end

VioletCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox VioletCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Boy::
	lock
	faceplayer
	msgbox VioletCity_Text_Boy, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox VioletCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_EventScript_Pichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PICHU, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Pichu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Bellsprout::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BELLSPROUT, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Bellsprout, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_Rattata::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox VioletCity_Text_Rattata, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_EventScript_ElmCall_Trigger::
	lock
	setspeaker VioletCity_Text_ElmName
	pokenavcall VioletCity_Text_Elm_Call
	waitmessage
	delay 30
	clearflag FLAG_HIDE_VIOLET_CITY_AIDE
	setflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	setvar VAR_VIOLET_CITY_STATE, 4
	release
	end

VioletCity_EventScript_Kimono_Girl::
	lock
	playbgm MUS_HG_KIMONO_GIRL, FALSE
	playse SE_PIN
	applymovement LOCALID_VIOLET_KIMONO, Common_Movement_ExclamationMark
	delay 55
	waitmovement LOCALID_VIOLET_KIMONO
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_1
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_2
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_3
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl3, MSGBOX_DEFAULT
	closemessage
	playse SE_M_PETAL_DANCE
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_4
	waitmovement 0
	msgbox VioletCity_Text_Kimono_Girl4, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VIOLET_KIMONO, VioletCity_Movement_Kimono_Girl_5
	waitmovement 0
	fadedefaultbgm
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 2
	setflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	removeobject LOCALID_VIOLET_KIMONO
	release
	end


VioletCity_EventScript_ItemRareCandy::
	finditem ITEM_RARE_CANDY
	end

VioletCity_EventScript_ItemPechaBerry::
	finditem ITEM_PECHA_BERRY
	end

VioletCity_EventScript_ItemHyperPotion::
	finditem ITEM_HYPER_POTION
	end

VioletCity_Movement_Earl_Spin:
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

VioletCity_Movement_Earl_East_Adjustment:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

VioletCity_Movement_Player_East_Adjustment:
	walk_down
	walk_down
	walk_left
	walk_down
	face_right
	step_end

VioletCity_Movement_Earl_South_Adjustment:
	walk_right
	walk_down
	walk_down
	walk_down
	face_right
	step_end

VioletCity_Movement_Player_South_Adjustment:
	walk_down
	walk_down
	step_end

VioletCity_Movement_Walk_To_School:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

VioletCity_Movement_Walk_To_School_Player:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VioletCity_Movement_Earl_Walk_Inside:
	walk_up
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_1:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

VioletCity_Movement_Kimono_Girl_2:
	walk_up
	step_end

VioletCity_Movement_Kimono_Girl_3:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

VioletCity_Movement_Kimono_Girl_4:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_up
	delay_8
	step_end

VioletCity_Movement_Kimono_Girl_5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VioletCity_EventScript_LiquidJustice::
	msgbox VioletCity_Text_LiquidJustice, MSGBOX_NPC
	end

VioletCity_EventScript_GymSign::
	msgbox VioletCity_Text_GymSign, MSGBOX_SIGN
	end

VioletCity_Text_LiquidJustice:
#if GERMAN
	.string "Schau dich um!\p"
	.string "Du siehst leicht, welche Pokémon du in\n"
	.string "einer Gegend fangen kannst, ohne den\l"
	.string "ganzen Tag im hohen Gras\l"
	.string "herumzurennen!$"
#else
	.string "Look around!\p"
	.string "It's easy to see what POKéMON\n"
	.string "you can catch in an area without\l"
	.string "having to run around in tall\l"
	.string "grass all day!$"
#endif

VioletCity_Text_EarlAsksIfYouBeatFalkner:
#if GERMAN
	.string "Hallo! Bist du ein Trainer?\p"
	.string "Hast du den Kampf gegen den\n"
	.string "Arenaleiter gewonnen?$"
#else
	.string "Hello!\n"
	.string "You are trainer?\p"
	.string "Battle GYM LEADER,\n"
	.string "win you did?$"
#endif

VioletCity_Text_VeryNiceIndeed:
#if GERMAN
	.string "Olala! Äußörst beeindrückönd!$"
#else
	.string "Ooh, la la!\n"
	.string "Very indeed nice!$"
#endif

VioletCity_Text_FollowEarl:
#if GERMAN
	.string "Wirklisch? Da ilft nur die Training!\n"
	.string "Folge mir, d'accord?$"
#else
	.string "Is that so? Then study shall\n"
	.string "you! Follow me!$"
#endif

VioletCity_Text_HereTeacherIAm:
#if GERMAN
	.string "Isch bin ier die Lehrör!\p"
	.string "Du solltöst machön die Training ier!$"
#else
	.string "Here, teacher I am.\n"
	.string "Good it is you study here!$"
#endif

VioletCity_Text_Lass:
#if GERMAN
	.string "Man sagt, dass im Knofensa-Turm\n"
	.string "Geister umgehen.\p"
	.string "Pokémon-Attacken des Typs Normal\n"
	.string "zeigen bei Geistern keine Wirkung.$"
#else
	.string "Ghosts are rumored to appear\n"
	.string "in SPROUT TOWER.\p"
	.string "They say that GHOST-type\n"
	.string "moves can bypass the defenses\p"
	.string "of tough POKéMON like ONIX\n"
	.string "and GEODUDE.$"
#endif

VioletCity_Text_Boy:
#if GERMAN
	.string "Hey, du bist ein Pokémon-Trainer?\p"
	.string "Wenn du zur Akademie gehst, kannst du\n"
	.string "vielleicht etwas Neues lernen!$"
#else
	.string "Hey, you're a POKéMON trainer?\p"
	.string "If you head to the ACADEMY,\n"
	.string "you might learn something new!$"
#endif

VioletCity_Text_Gramps:
#if GERMAN
	.string "Falk, der Leiter der Pokémon-Arena von\n"
	.string "Viola City, ist ein großartiger Trainer!\p"
	.string "Er ist in die Fußstapfen seines Vaters\n"
	.string "getreten und leitet die Arena hier mit\l"
	.string "sehr viel Können.$"
#else
	.string "FALKNER, from the VIOLET\n"
	.string "POKéMON GYM, is a fine trainer!\p"
	.string "He inherited his father's gym\n"
	.string "and has done a great job with\l"
	.string "it.$"
#endif

VioletCity_Text_Youngster:
#if GERMAN
	.string "Ich habe einen wackeligen Baum\n"
	.string "gesehen!\p"
	.string "Wenn du ihn berührst, windet er sich und\n"
	.string "tanzt!\l"
	.string "So Cool!$"
#else
	.string "I saw a wiggly tree up ahead!\p"
	.string "If you touch it, it squirms\n"
	.string "and dances! Cool!$"
#endif

VioletCity_Text_Sign:
#if GERMAN
	.string "Viola City\n"
	.string "Die Stadt der Nostalgie$"
#else
	.string "VIOLET CITY\p"
	.string "The City of Nostalgic Scents$"
#endif

VioletCity_Text_GymSign:
#if GERMAN
	.string "Pokémon-Arena von Viola City Leiter:\n"
	.string "Falk Der elegante Meister der\l"
	.string "Flug-Pokémon$"
#else
	.string "VIOLET CITY POKéMON GYM\p"
	.string "LEADER: FALKNER, The Elegant\n"
	.string "Master of Flying POKéMON$"
#endif

VioletCity_Text_SproutTowerSign:
#if GERMAN
	.string "Knofensa-Turm\p"
	.string "Erlebe den Weg der Pokémon$"
#else
	.string "SPROUT TOWER\p"
	.string "Experience the Way of POKéMON$"
#endif

VioletCity_Text_EarlsAcademySign:
#if GERMAN
	.string "Die Pokémonschule$"
#else
	.string "EARL'S POKéMON ACADEMY$"
#endif

VioletCity_Text_Pichu:
#if GERMAN
	.string "Pichu: Chuuuu!$"
#else
	.string "PICHU: Chuuuu!$"
#endif

VioletCity_Text_Bellsprout:
#if GERMAN
	.string "Knofensa: Spuuuu.$"
#else
	.string "BELLSPROUT: Sprouuuut.$"
#endif

VioletCity_Text_Rattata:
#if GERMAN
	.string "Rattfratz: Rattataratta!$"
#else
	.string "RATTATA: RATTATARATTA!$"
#endif

VioletCity_Text_ElmName:
#if GERMAN
	.string "Lind$"
#else
	.string "PROF.ELM$"
#endif

VioletCity_Text_Elm_Call:
#if GERMAN
	.string "Lind: Hallo, {PLAYER}? Ich habe\n"
	.string "Neuigkeiten über das Ei!\p"
	.string "Im Pokémon-Center von Viola City\n"
	.string "solltest du einen meiner\l"
	.string "Assistenten antreffen. Lass dir\l"
	.string "von ihm alles erklären!$"
#else
	.string "PROF.ELM: Hello, {PLAYER}? We\n"
	.string "discovered something about the\l"
	.string "EGG!\p"
	.string "My assistant is at the POKéMON\n"
	.string "CENTER in VIOLET CITY.\p"
	.string "Could you talk to him?$"
#endif

VioletCity_Text_Kimono_Girl1:
#if GERMAN
	.string "Nanu, dieses Ei…$"
#else
.string "Me oh my...\n"
.string "That EGG must be...!$"
#endif

VioletCity_Text_Kimono_Girl2:
#if GERMAN
	.string "Ich verstehe…\p"
	.string "Es ging von Mr. Pokémon zu Prof. Lind,\n"
	.string "dann zu dir.\p"
	.string "Jetzt kapiere ich es…$"
#else
.string "I see...\p"
.string "So it was handed from MR. POKéMON\n"
.string "to PROF.ELM, then from \l"
.string "PROF.ELM to you.\p"
.string "Now I get it...$"
#endif

VioletCity_Text_Kimono_Girl3:
#if GERMAN
	.string "Das ist ein wirklich äußerst kostbares\n"
	.string "Ei, vergesst das bitte nicht! Zieht es\l"
	.string "bitte mit viel Hingabe auf!\p"
	.string "Verstehen wir uns?$"
#else
.string "That EGG is truly an important EGG.\p"
.string "Please do take good care of it\n"
.string "for me. Is that understood?$"
#endif

VioletCity_Text_Kimono_Girl4:
#if GERMAN
	.string "Gut, dann gehabt Euch wohl!$"
#else
.string "I am counting on you.$"
#endif


