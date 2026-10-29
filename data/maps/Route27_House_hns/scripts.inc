Route27_House_hns_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
#if GERMAN
	.string "Oh! Ein Gast.\p"
	.string "Hier hinten verirrt sich sonst\n"
	.string "niemand her.\p"
	.string "Lass mich raten: du bist mit deinen\n"
	.string "Pokémon unterwegs.\p"
	.string "Dann zeig mir doch, wie ihr\n"
	.string "miteinander steht.$"
#else
	.string "Oh! A visitor.\p"
	.string "Nobody wanders out this far.\p"
	.string "Let me guess: you are travelling\n"
	.string "with your POKéMON.\p"
	.string "Then show me how the two of you\n"
	.string "get along.$"
#endif

SandstormHouse_Text_LoyalMon:
#if GERMAN
	.string "Oh, deine Pokémon vertrauen dir\n"
	.string "wirklich! Ich freue mich immer, wenn ich\l"
	.string "einem guten Trainer begegne. Hier, ein\l"
	.string "kleines Abschiedsgeschenk! Nimm nur!$"
#else
    .string "Ah! Your POKéMON trusts you very\n"
    .string "much.\p"
    .string "It's nice to see a good trainer.\p"
    .string "Here. A gift for your journey.$"
#endif

SandstormHouse_Text_TM37Description:
#if GERMAN
	.string "TM37 enthält Sandsturm.\p"
	.string "Diese Attacke fügt beiden Kämpfern\n"
	.string "Schaden zu.\p"
	.string "Nur erfahrene Trainer sollten sie\n"
	.string "einsetzen.\p"
	.string "Setze sie ein, wenn du dich traust! Viel\n"
	.string "Glück!$"
#else
    .string "TM37 happens to be SANDSTORM.\p"
    .string "It's a move that inflicts damage\n"
    .string "on both battlers.\p"
    .string "It's for advanced trainers only.\p"
    .string "Use it if you dare. Good luck!$"
#endif

SandstormHouse_Text_DisloyalMon:
#if GERMAN
	.string "Wenn du nicht für mehr Vertrauen unter\n"
	.string "euch sorgst, kannst du nicht gewinnen!\p"
	.string "Vertrauen ist, was einen Trainer mit\n"
	.string "seinen Pokémon verbindet!$"
#else
    .string "If it doesn't come to trust you\n"
    .string "some more, it could be tough going.\p"
    .string "Trust is the tie that binds POKéMON\n"
    .string "and trainers.$"
#endif


