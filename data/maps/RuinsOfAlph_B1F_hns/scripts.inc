RuinsOfAlph_B1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RuinsOfAlph_B1F_OnFrame
	.byte 0

RuinsOfAlph_B1F_OnFrame::
	map_script_2 VAR_RUINSOFALPH_STATE, 1, RuinsOfAlph_B1F_EventScript_Presence
	.2byte 0

RuinsOfAlph_B1F_EventScript_Presence::
	lock
	msgbox RuinsOfAlph_B1F_Text_Presence, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RUINSOFALPH_STATE, 0
	release
	end


RuinsOfAlph_B1F_EventScript_Teacher::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Teacher, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Hiker::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Hiker, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_B1F_EventScript_Gramps::
	lock
	faceplayer
	msgbox RuinsOfAlph_B1F_Text_Gramps, MSGBOX_DEFAULT
	release
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_HelixFossil::
	finditem ITEM_HELIX_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_DomeFossil::
	finditem ITEM_DOME_FOSSIL
	end

RuinsOfAlph_PuzzleAndRewardChambers_EventScript_OldAmber::
	finditem ITEM_OLD_AMBER
	end

@ Reward of the Ho-Oh puzzle. The only GS Ball is Prof. Oak's (Elm -> Kurt -> Ilex Forest).
RuinsOfAlph_B1F_EventScript_MasterBall::
	finditem ITEM_MASTER_BALL
	end

RuinsOfAlph_B1F_Text_Presence:
#if GERMAN
	.string "Du kannst irgendeine Präsenz spüren…$"
#else
	.string "There is a strange presence here.$"
#endif

RuinsOfAlph_B1F_Text_Hiker:
#if GERMAN
	.string "Dafür, dass er so leer ist, wurde dieser\n"
	.string "Raum aber ziemlich groß angelegt…$"
#else
	.string "This is a big room, but there's\n"
	.string "nothing here.$"
#endif

RuinsOfAlph_B1F_Text_Teacher:
#if GERMAN
    .string "Dieser Ort hat etwas Mystisches an\n"
    .string "sich.\p"
    .string "Er wirkt sogar irgendwie ätherisch.$"
#else
	.string "This place has a mystical\n"
	.string "quality to it.\p"
	.string "It feels sort of ethereal\n"
	.string "even.$"
#endif

RuinsOfAlph_B1F_Text_Gramps:
#if GERMAN
    .string "Alte Bauwerke sind oft die Gräber\n"
    .string "von Königen.\p"
    .string "Wie zum Beispiel die Pyramiden.$"
#else
	.string "Ancient buildings are often\n"
	.string "tombs of kings.\p"
	.string "Like the pyramids, for\n"
	.string "instance.$"
#endif
