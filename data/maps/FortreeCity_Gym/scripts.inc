FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8004, 5
	special SetHoennBadge
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem_unless_owned ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem_unless_owned ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
#if IS_HNS
	@ Hoenn badge 6 (Winona)
	setvar VAR_0x8004, 5
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
#endif
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
#if IS_HNS
	@ Hoenn badge 6 (Winona)
	setvar VAR_0x8004, 5
	special CheckHoennBadge
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_GymStatueCertified
#else
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
#endif
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
#if GERMAN
	.string "Na, wie sieht es aus? Auf dem Weg zum\n"
	.string "Champ, {PLAYER}?\p"
	.string "Die Leiterin der Arena von Baumhausen\n"
	.string "City, Wibke, ist eine Meisterin der\l"
	.string "Flug-Pokémon.\p"
	.string "Sie wartet hinten in der Arena auf\n"
	.string "dich, hinter den Drehtüren.\p"
	.string "Sie wartet auf neue Herausforderer,\n"
	.string "denen sie die Flügel stutzen kann!\p"
	.string "Okay, dann viel Glück!$"
#else
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "FORTREE GYM LEADER WINONA is\n"
	.string "a master of FLYING-type POKéMON.\p"
	.string "She's waiting at the back of this GYM,\n"
	.string "behind the rotating doors.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take wing!\p"
	.string "Okay, go for it!$"
#endif

FortreeCity_Gym_Text_GymGuidePostVictory:
#if GERMAN
	.string "Du hast es geschafft!\n"
	.string "Du hast Startfreigabe!$"
#else
	.string "You did it!\n"
	.string "You've achieved liftoff!$"
#endif

FortreeCity_Gym_Text_JaredIntro:
#if GERMAN
	.string "Bewundere den eleganten Kampfstil der\n"
	.string "Vogel-Pokémon!$"
#else
	.string "Behold the elegant battle style of\n"
	.string "BIRD POKéMON!$"
#endif

FortreeCity_Gym_Text_JaredDefeat:
#if GERMAN
	.string "Du… Du bist stark…$"
#else
	.string "You…\n"
	.string "You're strong…$"
#endif

FortreeCity_Gym_Text_JaredPostBattle:
#if GERMAN
	.string "Ein Trainer muss clever genug sein, mit\n"
	.string "den Wendungen im Kampf fertig zu\l"
	.string "werden.\p"
	.string "Mal sehen, ob du clever genug bist,\n"
	.string "bis zu unserer Leiterin vorzudringen.$"
#else
	.string "A TRAINER has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our LEADER?$"
#endif

FortreeCity_Gym_Text_EdwardoIntro:
#if GERMAN
	.string "Liebhaber von Vogel-Pokémon streben\n"
	.string "danach, dieser Arena beizutreten.\p"
	.string "Als Mitglied der Arena von Baumhausen\n"
	.string "City darf ich nicht verlieren!$"
#else
	.string "The lovers of BIRD POKéMON aspire\n"
	.string "to join this GYM.\p"
	.string "As a member of the FORTREE GYM,\n"
	.string "I'm not allowed to lose!$"
#endif

FortreeCity_Gym_Text_EdwardoDefeat:
#if GERMAN
	.string "Das war doch etwas zu schwer für mich\n"
	.string "zu tragen…$"
#else
	.string "It was too much of a load for me\n"
	.string "to bear…$"
#endif

FortreeCity_Gym_Text_EdwardoPostBattle:
#if GERMAN
	.string "Die Welt ist groß und es gibt zahlreiche\n"
	.string "starke Trainer.\p"
	.string "Ich werde weiter trainieren und so\n"
	.string "immer stärker werden!$"
#else
	.string "The world is huge, and there are\n"
	.string "countless tough TRAINERS.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"
#endif

FortreeCity_Gym_Text_FlintIntro:
#if GERMAN
	.string "Es gibt keinen Grund, dass Wibke, unsere\n"
	.string "Arenaleiterin, sich mit dir abgibt!\p"
	.string "Ich bin schon stark genug für dich!$"
#else
	.string "There's no need for WINONA, our GYM\n"
	.string "LEADER, to deal with you!\p"
	.string "I'm plenty good enough for you!$"
#endif

FortreeCity_Gym_Text_FlintDefeat:
#if GERMAN
	.string "Wibke… Ich…\n"
	.string "Ich habe verlooooren!$"
#else
	.string "WINONA, I…\n"
	.string "I lost!$"
#endif

FortreeCity_Gym_Text_FlintPostBattle:
#if GERMAN
	.string "Wibke ist süß, aber auch stark.\n"
	.string "Sie ist die ultimative Leiterin!\p"
	.string "Hups… Wie peinlich. Ich werde nicht\n"
	.string "rot!$"
#else
	.string "WINONA is cute and she's strong.\n"
	.string "She's the ultimate LEADER!\p"
	.string "Blush…$"
#endif

FortreeCity_Gym_Text_AshleyIntro:
#if GERMAN
	.string "Wibke hat mich persönlich geschult!\n"
	.string "Du wirst kein leichtes Spiel haben!$"
#else
	.string "WINONA taught me personally!\n"
	.string "You can't beat me easily!$"
#endif

FortreeCity_Gym_Text_AshleyDefeat:
#if GERMAN
	.string "Ich wurde geschlagen…$"
#else
	.string "I was beaten…$"
#endif

FortreeCity_Gym_Text_AshleyPostBattle:
#if GERMAN
	.string "Dank Wibke leben die Einwohner von\n"
	.string "Baumhausen City ohne Furcht.$"
#else
	.string "Thanks to WINONA, the people of\n"
	.string "FORTREE can live without fear.$"
#endif

FortreeCity_Gym_Text_HumbertoIntro:
#if GERMAN
	.string "Wibkes Gesicht strahlt eine\n"
	.string "Entschlossenheit aus, wenn sie in den\l"
	.string "Kampf geht. Sie ist dann wunderhübsch!\l"
	.string "\p"
	.string "Ich werde dir dieses hübsche Gesicht\n"
	.string "zeigen!$"
#else
	.string "When WINONA takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"
#endif

FortreeCity_Gym_Text_HumbertoDefeat:
#if GERMAN
	.string "Argh!\n"
	.string "Ich konnte dich einfach nicht stoppen!$"
#else
	.string "Urk!\n"
	.string "I couldn't stop you.$"
#endif

FortreeCity_Gym_Text_HumbertoPostBattle:
#if GERMAN
	.string "Pass mal besser auf! Du solltest Wibke\n"
	.string "nicht mit offenem Mund anstarren,\l"
	.string "sonst gehst du erbärmlich unter!$"
#else
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at WINONA\l"
	.string "or you'll go crashing down in a heap!$"
#endif

FortreeCity_Gym_Text_DariusIntro:
#if GERMAN
	.string "Es gibt viele verschiedene\n"
	.string "Flug-Pokémon.\p"
	.string "Das weißt du, oder?$"
#else
	.string "You'd better know that there are all\n"
	.string "sorts of FLYING-type POKéMON.\p"
	.string "You do know that, right?$"
#endif

FortreeCity_Gym_Text_DariusDefeat:
#if GERMAN
	.string "Du weißt wirklich, was du tust!$"
#else
	.string "You seem to know your stuff!$"
#endif

FortreeCity_Gym_Text_DariusPostBattle:
#if GERMAN
	.string "Okay, du hast mich besiegt. Na und?\n"
	.string "Aber gegen unsere Leiterin Wibke hast\l"
	.string "du keine Chance!$"
#else
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our LEADER\l"
	.string "WINONA's POKéMON are all business.$"
#endif

FortreeCity_Gym_Text_WinonaIntro:
#if GERMAN
	.string "Ich bin Wibke, die Leiterin der Arena\n"
	.string "von Baumhausen City.\p"
	.string "Ich wurde das mit Hilfe meiner Vogel-\n"
	.string "Pokémon und habe den Himmel berührt.\p"
	.string "Wie anstrengend der Kampf auch war,\n"
	.string "wir haben mit Grazie gewonnen…\p"
	.string "Werde Zeuge der eleganten Choreo-\n"
	.string "graphie meiner Vogel-Pokémon!$"
#else
	.string "I am WINONA. I am the LEADER of\n"
	.string "the FORTREE POKéMON GYM.\p"
	.string "I have become one with BIRD POKéMON\n"
	.string "and have soared the skies…\p"
	.string "However grueling the battle, we have\n"
	.string "triumphed with grace…\p"
	.string "Witness the elegant choreography\n"
	.string "of BIRD POKéMON and I!$"
#endif

FortreeCity_Gym_Text_WinonaDefeat:
#if GERMAN
	.string "Ich habe noch nie einen Trainer\n"
	.string "gesehen, der seine Pokémon mit mehr\l"
	.string "Grazie trainiert als ich…\p"
	.string "In Anbetracht deiner Fähigkeiten\n"
	.string "überreiche ich dir diesen Arenaorden.$"
#else
	.string "Never before have I seen a TRAINER\n"
	.string "command POKéMON with more grace\l"
	.string "than I…\p"
	.string "In recognition of your prowess,\n"
	.string "I present to you this GYM BADGE.$"
#endif

FortreeCity_Gym_Text_ReceivedFeatherBadge:
#if GERMAN
	.string "{PLAYER} erhält den Federorden von\n"
	.string "Wibke.$"
#else
	.string "{PLAYER} received the FEATHER BADGE\n"
	.string "from WINONA.$"
#endif

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
#if GERMAN
	.string "Der Federorden ist der Beweis, dass\n"
	.string "du mich geschlagen hast.\p"
	.string "Und dies…\n"
	.string "Dies ist ein Geschenk von mir.$"
#else
	.string "The FEATHER BADGE is proof that you\n"
	.string "defeated me.\p"
	.string "And this…\n"
	.string "This is a gift from me.$"
#endif

FortreeCity_Gym_Text_ExplainAerialAce:
#if GERMAN
	.string "TM40 enthält Aero-Ass.\p"
	.string "Diese Geschwindigkeit…\n"
	.string "Kein Pokémon kann ihr entgehen.\p"
	.string "… … … … … …$"
#else
	.string "TM40 contains AERIAL ACE.\p"
	.string "Its speed…\n"
	.string "No POKéMON should be able to avoid it.\p"
	.string "… … … … … …$"
#endif

FortreeCity_Gym_Text_RegisteredWinona:
#if GERMAN
	.string "Arenaleiterin Wibke wurde im PokéCom-\n"
	.string "Verzeichnis eingetragen.$"
#else
	.string "Registered GYM LEADER WINONA\n"
	.string "in the POKéGEAR.$"
#endif

FortreeCity_Gym_Text_WinonaPostBattle:
#if GERMAN
	.string "Auch wenn ich gegen dich verloren habe,\n"
	.string "gehört meine Liebe den Vogel-Pokémon.$"
#else
	.string "Though I fell to you, I will remain\n"
	.string "devoted to BIRD POKéMON.$"
#endif

FortreeCity_Gym_Text_GymStatue:
#if GERMAN
	.string "Pokémon Arena von Baumhausen City$"
#else
	.string "FORTREE CITY POKéMON GYM$"
#endif

FortreeCity_Gym_Text_GymStatueCertified:
#if GERMAN
	.string "Pokémon Arena von Baumhausen City\p"
	.string "Wibkes anerkannte Trainer:\n"
	.string "{PLAYER}$"
#else
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"
#endif

FortreeCity_Gym_Text_WinonaPreRematch:
#if GERMAN
	.string "Wibke: Wir Menschen können uns der\n"
	.string "Schwerkraft nicht widersetzen.\p"
	.string "Aber in unserem Streben nach\n"
	.string "Perfektion haben auch wir die Kraft,\l"
	.string "vom Boden abzuheben!\p"
	.string "Du hast den Gipfel erstürmt. Als\n"
	.string "Champ.\p"
	.string "Bitte, zeig mir, wie du abhebst! Zeig\n"
	.string "mir deine Kraft.$"
#else
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"
#endif

FortreeCity_Gym_Text_WinonaRematchDefeat:
#if GERMAN
	.string "Du fliegst mir zu hoch…$"
#else
	.string "I failed to reach your height again…$"
#endif

FortreeCity_Gym_Text_WinonaPostRematch:
#if GERMAN
	.string "Wibke: Auch wenn ich verloren habe,\n"
	.string "mein Herz wird stets fliegen.\p"
	.string "Ich werde immer wieder aufsteigen und\n"
	.string "mich in die Lüfte erheben.\p"
	.string "Das weiß ich genau!$"
#else
	.string "WINONA: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"
#endif

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
#if GERMAN
	.string "Wibke: Wir Menschen können uns der\n"
	.string "Schwerkraft nicht widersetzen.\p"
	.string "Aber in unserem Streben nach\n"
	.string "Perfektion haben auch wir die Kraft,\l"
	.string "vom Boden abzuheben!\p"
	.string "Du hast den Gipfel erstürmt. Als\n"
	.string "Champ.\p"
	.string "Bitte, zeig mir wie du abhebst! Zeig\n"
	.string "mir deine Kraft.\p"
	.string "Oh… Du hast nur ein Pokémon bei\n"
	.string "dir?\p"
	.string "Bitte komm später wieder und bring\n"
	.string "mindestens zwei Pokémon mit.$"
#else
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "POKéMON with you?\p"
	.string "Please return with two POKéMON\n"
	.string "at the very least.$"
#endif
