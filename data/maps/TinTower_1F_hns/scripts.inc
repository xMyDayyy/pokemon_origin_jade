TinTower_1F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_1F_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	end

@ 1F only; TinTower_OnTransition is shared with 2F-9F.
@ Suicune waits here once the Route 36 sighting is done (VAR_SUICUNE_ENCOUNTERS >= 4)
@ and the legendary rules allow it. FLAG_TEMP_1 hides Suicune, FLAG_TEMP_2 hides Eusine.
@ See docs/origin_jade/DECISIONS.md, D-026 and D-038.
TinTower_1F_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL_HNS, 35, 42
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_1
	goto_if_lt VAR_SUICUNE_ENCOUNTERS, 4, TinTower_1F_OnTransition_End
	setvar VAR_0x8004, LEGENDARY_SUICUNE
	specialvar VAR_RESULT, IsLegendaryAvailable
	call_if_eq VAR_RESULT, TRUE, TinTower_1F_EventScript_ShowSuicune
TinTower_1F_OnTransition_End:
	end

TinTower_1F_EventScript_ShowSuicune::
	clearflag FLAG_TEMP_1
	return

@ Suicune, fixed Lv 50 like the story Lugia and Ho-Oh.
@ The LEGEND API records caught / knocked out / fled; this script only hides it for the visit.
TinTower_1F_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	setvar VAR_0x8004, LEGENDARY_SUICUNE
	special RecordLegendaryBattleOutcome
	specialvar VAR_RESULT, GetBattleOutcome
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_TINTOWER1F_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, TinTower_1F_EventScript_SuicuneDone
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, TinTower_1F_EventScript_SuicuneDone
	msgbox TinTower_1F_Text_SuicuneRanAway, MSGBOX_DEFAULT
	closemessage
	release
	end

@ First knockout or catch only: Eusine comes in once (VAR_SUICUNE_ENCOUNTERS 4 -> 8).
TinTower_1F_EventScript_SuicuneDone::
	goto_if_ne VAR_SUICUNE_ENCOUNTERS, 4, TinTower_1F_EventScript_SuicuneRelease
	hidefollower
	playse SE_EXIT
	playbgm MUS_HG_EUSINE, FALSE
	clearflag FLAG_TEMP_2
	addobject LOCALID_TINTOWER1F_EUSINE
	applymovement LOCALID_TINTOWER1F_EUSINE, TinTower_1F_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox TinTower_1F_EusineSuicune_Text, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TINTOWER1F_EUSINE, TinTower_1F_Movement_EusineLeave
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_TINTOWER1F_EUSINE
	fadedefaultbgm
	setvar VAR_SUICUNE_ENCOUNTERS, 8
TinTower_1F_EventScript_SuicuneRelease:
	release
	end

TinTower_1F_Movement_EusineEnter:
	walk_up
	step_end

TinTower_1F_Movement_EusineLeave:
	walk_down
	walk_down
	step_end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	@ VAR_COMPLETED_HO_OH 2: Ho-Oh waits on the roof (Ho-Oh path, after the theater).
	goto_if_eq VAR_COMPLETED_HO_OH, 2, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_COMPLETED_HO_OH, 2, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_COMPLETED_HO_OH, 2, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
#if GERMAN
	.string "Der Legende nach…\p"
	.string "Wenn die Seelen von Pokémon und\n"
	.string "Menschen sich berühren, steigt ein\l"
	.string "Pokémon in Regenbogenfarben vom\l"
	.string "Himmel herab…\p"
	.string "Könnte es sein, dass die\n"
	.string "legendären Pokémon uns Menschen\l"
	.string "auf die Probe stellen?$"
#else
	.string "According to legend…\n"
	.string "When the souls of POKéMON and humans\p"
	.string "commune, from the heavens descends a\n"
	.string "POKéMON of rainbow colors…\p"
	.string "Could it mean the legendary POKéMON\n"
	.string "are testing us humans?$"
#endif

TinTower_1F_Sage2_Text:
#if GERMAN
	.string "Beim Brand der heutigen Turmruine\n"
	.string "sollen drei namenlose Pokémon\l"
	.string "umgekommen sein. Es war tragisch.\p"
	.string "Jedoch…\p"
	.string "Ein Pokémon in Regenbogenfarben…\n"
	.string "Mit anderen Worten…\p"
	.string "Ho-Oh stieg vom Himmel herab und\n"
	.string "schenkte den drei Pokémon neues\l"
	.string "Leben.\p"
	.string "Es sind…\n"
	.string "Suicune, Entei und Raikou.\p"
	.string "So sagt man es zumindest.$"
#else
	.string "When the BRASS TOWER burned down,\n"
	.string "three nameless POKéMON were said\l"
	.string "to have perished. It was tragic.\p"
	.string "However…\p"
	.string "A rainbow-colored POKéMON…\n"
	.string "In other words…\p"
	.string "HO-OH descended from the sky and\n"
	.string "gave new life to the three POKéMON.\p"
	.string "They are…\n"
	.string "SUICUNE, ENTEI and RAIKOU.\p"
	.string "That is what they say.$"
#endif

TinTower_1F_Sage3_Text:
#if GERMAN
	.string "Die zwei Türme sollen erbaut worden\n"
	.string "sein, um Freundschaft und Hoffnung\l"
	.string "zwischen Pokémon und Menschen zu\l"
	.string "fördern.\p"
	.string "Das war vor 700 Jahren, aber das\n"
	.string "Ideal ist noch heute wichtig.$"
#else
	.string "The two TOWERS are said to have been\n"
	.string "built to foster friendship and\p"
	.string "hope between POKéMON and people.\n"
	.string "That was 700 years ago, but the ideal\p"
	.string "still remains important today.$"
#endif

TinTower_1F_Sage4_Text1:
#if GERMAN
	.string "Ho-Oh scheint sich auf dem\n"
	.string "Glockenturm niedergelassen\l"
	.string "zu haben!$"
#else
	.string "HO-OH appears to have descended\n"
	.string "upon this, the TIN TOWER!$"
#endif

TinTower_1F_Sage4_Text2:
#if GERMAN
	.string "Die legendären Pokémon sollen\n"
	.string "drei Kräfte verkörpern…\p"
	.string "Den Blitz, der den Turm traf.\p"
	.string "Das Feuer, das den Turm\n"
	.string "verbrannte.\p"
	.string "Und den Regen, der das Feuer\n"
	.string "löschte…$"
#else
	.string "The legendary POKéMON are said\n"
	.string "to embody three powers…\p"
	.string "The lightning that struck the TOWER.\n"
	.string "The fire that burned the TOWER.\p"
	.string "And the rain that put out the fire…$"
#endif

TinTower_1F_Sage6_Text2:
#if GERMAN
	.string "Von den legendären Pokémon soll\n"
	.string "Suicune Ho-Oh am nächsten stehen.\p"
	.string "Ich höre, dass es auch eine\n"
	.string "Verbindung zu Pokémon namens\l"
	.string "Icognito geben soll.\p"
	.string "Icognito muss eine enge Verbindung\n"
	.string "zu Suicune haben.$"
#else
	.string "Of the legendary POKéMON, SUICUNE\n"
	.string "is said to be the closest to HO-OH.\p"
	.string "I hear there may also be a link to\n"
	.string "POKéMON known as UNOWN.\p"
	.string "The POKéMON UNOWN must be sharing a\n"
	.string "cooperative bond with SUICUNE.$"
#endif

TinTower_1F_EusineHoOh_Text:
#if GERMAN
	.string "Ich wusste es.\p"
	.string "Ich wusste, dass du das Pokémon in\n"
	.string "Regenbogenfarben sehen würdest,\l"
	.string "{PLAYER}.\p"
	.string "Es geschah genau so, wie ich es mir\n"
	.string "vorgestellt hatte.\l"
	.string "Meine Forschung ist gar nicht so\l"
	.string "schlecht, muss ich sagen.\p"
	.string "Ich werde weiter Pokémon studieren,\n"
	.string "um ein berühmter Pokénarr zu werden!$"
#else
	.string "I knew it.\p"
	.string "I knew you'd get to see the POKéMON\n"
	.string "of rainbow colors, <PLAYER>.\p"
	.string "It happened just as I envisioned.\n"
	.string "My research isn't bad, I might say.\p"
	.string "I'm going to keep studying POKéMON\n"
	.string "to become a famous POKéMANIAC!$"
#endif

TinTower_1F_EusineSuicune_Text:
#if GERMAN
	.string "Eusin: Unglaublich! Einfach zu\n"
	.string "unglaublich! So einen Kampf hab ich\l"
	.string "noch nie gesehen.\p"
	.string "Das war wirklich inspirierend.\n"
	.string "Suicune war stark, aber du warst\l"
	.string "noch beeindruckender, {PLAYER}.\p"
	.string "Ich habe gehört, Suicunes mystische\n"
	.string "Kraft ruft ein Pokémon in\l"
	.string "Regenbogenfarben herbei.\p"
	.string "Vielleicht, nur vielleicht, wird\n"
	.string "das, was heute geschah, dieses\l"
	.string "Pokémon erscheinen lassen.\p"
	.string "Ich werde die Legenden weiter\n"
	.string "erforschen.\p"
	.string "Danke, dass du mir diesen\n"
	.string "fantastischen Kampf gezeigt hast.\p"
	.string "Bis dann, {PLAYER}!$"
#else
	.string "EUSINE: Awesome! Too awesome,\n"
	.string "even! I've never seen a battle\l"
	.string "that great.\p"
	.string "That was truly inspiring to see.\n"
	.string "SUICUNE was tough, but you were\l"
	.string "even more incredible, {PLAYER}.\p"
	.string "I heard SUICUNE's mystic power\n"
	.string "summons a rainbow-colored POKéMON.\p"
	.string "Maybe, just maybe, what went on\n"
	.string "today will cause that POKéMON to\l"
	.string "appear.\p"
	.string "I'm going to study the legends\n"
	.string "more.\p"
	.string "Thanks for showing me that\n"
	.string "fantastic battle.\p"
	.string "Later, {PLAYER}!$"
#endif

TinTower_1F_Text_SuicuneRanAway:
#if GERMAN
	.string "Suicune lief davon!$"
#else
	.string "SUICUNE ran away!$"
#endif
