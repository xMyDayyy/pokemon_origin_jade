BattleFrontier_OutsideEast_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume_hns
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition_hns
	.byte 0

BattleFrontier_OutsideEast_OnResume_hns:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo_hns::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition_hns:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo_hns::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker_hns::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac_hns::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1_hns::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon_hns::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy_hns::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF_hns::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin_hns::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM_hns::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo_hns::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo_hns::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FRONTIER_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FRONTIER_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 75
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo_hns::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake_hns:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1_hns::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl_hns::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM_hns::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3_hns::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1_hns::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2_hns::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2_hns::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3_hns::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign_hns::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman_hns::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hns::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWoman_hnsSudowoodoGone_hns::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper_hns::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign_hns:
#if GERMAN
	.string "Duellturm “Besiege alle und werde der\n"
	.string "beste Trainer!”$"
#else
	.string "This is the BATTLE TOWER!\n"
	.string "Keep the win streak as the toughest\l"
	.string "TRAINER!$"
#endif

BattleFrontier_OutsideEast_Text_BattlePalaceSign_hns:
#if GERMAN
	.string "Dies ist der Kampfpalast!\n"
	.string "Schaut euch die Pokémon-Kämpfe an!$"
#else
	.string "This is the BATTLE PALACE!\n"
	.string "Keep your eyes on POKéMON battles!$"
#endif

BattleFrontier_OutsideEast_Text_BattleArenaSign_hns:
#if GERMAN
	.string "Dies ist der Kampfring!\n"
	.string "Hier treffen sich die stärksten Teams!$"
#else
	.string "This is the BATTLE ARENA!\n"
	.string "Let the toughest teams gather!$"
#endif

BattleFrontier_OutsideEast_Text_BattlePyramidSign_hns:
#if GERMAN
	.string "Dies ist die Kampfpyramide!\n"
	.string "Geh in das Abenteuer Kampfforschung!$"
#else
	.string "This is the BATTLE PYRAMID!\n"
	.string "Advance through the Battle Quest!$"
#endif

BattleFrontier_OutsideEast_Text_RankingHallSign_hns:
#if GERMAN
	.string "Kampfzone Ergebnishalle\n"
	.string "Schau dir die neuesten Rekorde an!$"
#else
	.string "BATTLE FRONTIER RANKING HALL\n"
	.string "Set your sights on new records!$"
#endif

BattleFrontier_OutsideEast_Text_ExchangeCornerSign_hns:
#if GERMAN
	.string "Gewinnpunkte Tauschecke\n"
	.string "Löse deine Gewinnpunkte ein!$"
#else
	.string "BATTLE POINT EXCHANGE SERVICE CORNER\n"
	.string "Exchange your Battle Points!$"
#endif

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial_hns:
#if GERMAN
	.string "Wow! Ist das riiiiesig!\p"
	.string "Der Duellturm hat eine besondere\n"
	.string "Atmosphäre. Ganz anders als die\l"
	.string "anderen Orte.$"
#else
	.string "Wow!\n"
	.string "It's huge!\p"
	.string "The BATTLE TOWER feels special.\n"
	.string "It's different from the others.$"
#endif

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier_hns:
#if GERMAN
	.string "Ich habe Großes vor! Ich will die\n"
	.string "Kampfzone und die Pokémon Liga\l"
	.string "erobern!\p"
	.string "Und wenn dieser Traum wahr wird…\p"
	.string "Dann werde ich… meine Nachbarin Mimi\n"
	.string "fragen, ob sie meine Freundin wird!$"
#else
	.string "My grand ambition is to conquer both\n"
	.string "the BATTLE FRONTIER and the POKéMON\l"
	.string "LEAGUE.\p"
	.string "And if my dream comes true…\p"
	.string "I… I'm going to ask MIMI next door\n"
	.string "if she will be friends with me!$"
#endif

BattleFrontier_OutsideEast_Text_PyramidTooHarsh_hns:
#if GERMAN
	.string "Die Kampfpyramide ist wirklich\n"
	.string "hammerhart! Ich schaff das nicht!\p"
	.string "Wenn ich es auf dem normalen Weg nicht\n"
	.string "nach oben schaffe… vielleicht sollte\l"
	.string "ich dann einfach außen hochklettern?!?$"
#else
	.string "The BATTLE PYRAMID's too harsh!\n"
	.string "I just can't make it to the top!\p"
	.string "Since I'm out of options, maybe I can\n"
	.string "climb the outside…$"
#endif

BattleFrontier_OutsideEast_Text_ThriveInDarkness_hns:
#if GERMAN
	.string "Ich lebe von der Dunkelheit…\n"
	.string "Ja… Und welche Herausforderung ist\l"
	.string "gerade gut genug für mich?\p"
	.string "Die Kampfpyramide! Liebst du nicht auch\n"
	.string "die Dunkelheit? Die Verzweiflung und\l"
	.string "das Ungewisse?$"
#else
	.string "I thrive in darkness…\n"
	.string "Yes… What is worthy of me?\l"
	.string "None other than the BATTLE PYRAMID…\p"
	.string "What say you to wandering in darkness\n"
	.string "and in utter and total desperation?$"
#endif

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam_hns:
#if GERMAN
	.string "Es hat mich eine Woche Schlaf gekostet,\n"
	.string "aber jetzt habe ich es zusammen… Das\p"
	.string "ultimative Team!!! Ich sehe mich als\n"
	.string "Sieger, und nur als Sieger, kein Witz!\l"
	.string "\p"
	.string "Wir werden den Kampfring wie ein\n"
	.string "Orkan durchfegen und gewinnen!$"
#else
	.string "I didn't sleep for a week, but then\n"
	.string "I put together the ultimate team!\p"
	.string "I can't see myself losing, no joke.\n"
	.string "We're storming the BATTLE ARENA!$"
#endif

BattleFrontier_OutsideEast_Text_DidScottBringYouHere_hns:
#if GERMAN
	.string "Hat Scott dich auch hierher einge-\n"
	.string "laden? Wie macht er das nur?\p"
	.string "Er scheint ein Auge für talentierte\n"
	.string "Trainer zu haben, aber…\p"
	.string "Ich habe ihn selbst noch nie kämpfen\n"
	.string "gesehen…$"
#else
	.string "Did SCOTT bring you here, too?\n"
	.string "What is it with that guy?\p"
	.string "It sounds like he really does know\n"
	.string "how to spot talented TRAINERS, but…\p"
	.string "I've never seen him battling in person\n"
	.string "ever.$"
#endif

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy_hns:
#if GERMAN
	.string "Zigg!\n"
	.string "Ich glaube an dich, mein kleiner Freund!\p"
	.string "Und wenn du gewinnst, werde ich dich\n"
	.string "mit allem, was du magst, verwöhnen!$"
#else
	.string "ZIGG!\n"
	.string "I believe in you, little buddy!\p"
	.string "I'll make my little ZIGG any favorite\n"
	.string "tasty treats you like if you win!$"
#endif

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant_hns:
#if GERMAN
	.string "Zigzachs schaut erwartungsvoll…$"
#else
	.string "ZIGZAGOON looks vacant…$"
#endif

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody_hns:
#if GERMAN
	.string "Die anderen sagen, ich wäre eine\n"
	.string "Nervensäge, die sich überall einmischt.\p"
	.string "Aber wenn ich ihnen nicht sage, wo es\n"
	.string "langgeht, wer dann?\l"
	.string "…\p"
	.string "Du da, dein Hut sitzt schief!\n"
	.string "Du da, wirf keinen Müll auf den Boden!\l"
	.string "Du da, du machst das ja ganz falsch!\p"
	.string "Ich glaube nicht, dass ich es jemals\n"
	.string "schaffen werde, im Kampfpalast still zu\l"
	.string "sein und zuzuschauen…$"
#else
	.string "People call me a busybody,\n"
	.string "but I can't help it.\p"
	.string "Your hat's on crooked!\n"
	.string "Oh, no, trash on the ground!\l"
	.string "Oops, it's almost dinnertime!\p"
	.string "I don't know if I can stand to just\n"
	.string "watch at the BATTLE PALACE…$"
#endif

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader_hns:
#if GERMAN
	.string "Heute ist das vielleicht schwer\n"
	.string "vorstellbar, aber ich habe mal einen\l"
	.string "Arenaleiter besiegt!\p"
	.string "Wer weiß? Vielleicht sollte ich es\n"
	.string "noch einmal versuchen?!?$"
#else
	.string "I may not look that impressive now,\n"
	.string "but I once beat a GYM LEADER.\p"
	.string "Who knows, maybe I should give it\n"
	.string "another shot at glory.$"
#endif

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles_hns:
#if GERMAN
	.string "Ich bin schnell mit meinem Fahrrad…\n"
	.string "Und genauso schnell bin ich auch im\p"
	.string "Kampf! Ich brauche nur eine\n"
	.string "Millisekunde für den Sieg!$"
#else
	.string "I'm fast on my BIKE, and that goes for\n"
	.string "the way I battle, too.\p"
	.string "I win matches in the blink of\n"
	.string "an eye!$"
#endif

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon_hns:
#if GERMAN
	.string "Ich kann besser mit Pokémon umgehen\n"
	.string "als mein Vati.$"
#else
	.string "I'm better than my daddy\n"
	.string "at POKéMON.$"
#endif

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy_hns:
#if GERMAN
	.string "Los, meine kleine Prinzessin! Besiege\n"
	.string "die Trainer und mach deinen Vati stolz!\p"
	.string "Du bist deiner Mutti sehr ähnlich. Du\n"
	.string "bist dominant, du wirst das schaffen!$"
#else
	.string "Go on, my baby sweetie!\n"
	.string "Go rack up some wins for Daddy!\p"
	.string "You're just like your mother,\n"
	.string "so you'll be dominating!$"
#endif

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena_hns:
#if GERMAN
	.string "Ich wusste, der Weg hierher ist sehr\n"
	.string "schwierig zu meistern. Aber ich hatte\l"
	.string "gehört, dass hier ein umwerfend süßes\l"
	.string "\p"
	.string "Mädchen im Kampfring sein soll.\n"
	.string "Und weißt du, auf wen ich getroffen bin,\l"
	.string "als ich dann endlich hier ankam?!?\p"
	.string "Auf ein Team stinkender, schwitzender,\n"
	.string "primitiver und nervtötender\l"
	.string "Kampfsportler. Ich könnte platzen…$"
#else
	.string "It wasn't easy getting here,\n"
	.string "but I'd heard about this knockout\l"
	.string "pretty girl at the BATTLE ARENA.\p"
	.string "Instead of her, do you know what\n"
	.string "I found?\p"
	.string "A whole teeming mob of sweaty,\n"
	.string "stinky, and primitive martial artists!$"
#endif

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere_hns:
#if GERMAN
	.string "Manchmal läuft hier ein wichtig\n"
	.string "aussehender, älterer Herr herum.\p"
	.string "Er hat wirklich beeindruckende Pokémon\n"
	.string "und er scheint sehr nett zu sein.$"
#else
	.string "I sometimes see this really important-\n"
	.string "looking old man going in there.\p"
	.string "He has these really awesome POKéMON.\n"
	.string "He seems really nice, though.$"
#endif

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid_hns:
#if GERMAN
	.string "Hast du schon mal etwas über die\n"
	.string "Legende der Kampfpyramide gehört?\p"
	.string "Wenn ein überzeugender Trainer den\n"
	.string "goldenen Gipfel erreicht, dann\l"
	.string "erscheint der Trainer aller Trainer.\p"
	.string "Wie, das wusstest du nicht?\n"
	.string "Natürlich nicht!\l"
	.string "Das habe ich doch gerade erfunden!\p"
	.string "Was das heißen soll? Hähähä, das ist\n"
	.string "mein Geheimnis!$"
#else
	.string "Do you know it?\n"
	.string "The legend of the BATTLE PYRAMID?\p"
	.string "When there comes a confident TRAINER\n"
	.string "reaching for the golden pinnacle,\l"
	.string "there shall appear a man among men.\p"
	.string "Don't know that legend?\n"
	.string "Well, of course not!\l"
	.string "I just made it up!\p"
	.string "What's it supposed to mean?\n"
	.string "That, my friend, I can't say!$"
#endif

BattleFrontier_OutsideEast_Text_GotWipedOut_hns:
#if GERMAN
	.string "Grummel… Motz…\n"
	.string "Ich habe bisher noch nie verloren!\p"
	.string "Aber diesmal bin ich vom Platz gefegt\n"
	.string "worden. Meine Würde ist dahin…\p"
	.string "Und dann wird mir noch an den Kopf\n"
	.string "geworfen, ich hätte kein Talent?!?\l"
	.string "Argh… Motz… Meuter…$"
#else
	.string "Man! Oh man!\n"
	.string "I've never lost once before!\p"
	.string "But I got wiped out with no saving\n"
	.string "grace at all!\p"
	.string "And then I'm told I don't have any\n"
	.string "talent?! Man!$"
#endif

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower_hns:
#if GERMAN
	.string "Er ist auf einen mordsmäßig starken\n"
	.string "Trainer getroffen, als er sich durch den\l"
	.string "Duellturm gekämpft hat.\p"
	.string "Und nun schau ihn dir an…\n"
	.string "Ein Häufchen Elend…\p"
	.string "Du musst auf alles gefasst sein, wenn\n"
	.string "du den Duellturm betrittst!$"
#else
	.string "This guy ran into a horribly tough\n"
	.string "TRAINER while he was on the BATTLE\l"
	.string "TOWER challenge.\p"
	.string "Now look at him…\p"
	.string "You need to be cautious if you ever\n"
	.string "decide to go to the BATTLE TOWER.$"
#endif

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll_hns:
#if GERMAN
	.string "Ja!\n"
	.string "Endlich habe ich genug Gewinnpunkte!\p"
	.string "Ich werde mir eine riesige, niedliche\n"
	.string "Plüschpuppe holen!$"
#else
	.string "Yes!\n"
	.string "I've finally got enough Battle Points!\p"
	.string "I guess I'll trade for another giant\n"
	.string "plush DOLL!$"
#endif

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere_hns:
#if GERMAN
	.string "Oh, yeah, okay!\n"
	.string "Dies ist also die Ergebnishalle!\p"
	.string "Ich will in die Geschichte eingehen!\n"
	.string "Als Superchamp! Ich will meinen Namen\l"
	.string "für die Nachwelt verewigen.$"
#else
	.string "Oh, yeah, okay!\n"
	.string "So this is the RANKING HALL!\p"
	.string "I'd like to go down in history as\n"
	.string "a super champ and have my name\l"
	.string "recorded here for posterity.$"
#endif

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou_hns:
#if GERMAN
	.string "Mit dir an meiner Seite…\n"
	.string "kann ich alles schaffen!!!$"
#else
	.string "With you by my side, I can do anything.$"
#endif

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome_hns:
#if GERMAN
	.string "Oh, Liebling, du bist wundervoll!\p"
	.string "Oh, ich kann nicht länger warten!\p"
	.string "Lass uns sofort zu den Multikämpfen\n"
	.string "gehen!\p"
	.string "Wenn wir zusammen in der Teamlounge\n"
	.string "sind… wird die Macht unserer Liebe alle\l"
	.string "Hindernisse beseitigen!\p"
	.string "Sie werden umfallen wie 1000 Domino-\n"
	.string "steine in einer Reihe, Liebling!$"
#else
	.string "Ooh, darling, you are so wonderful!\p"
	.string "Ooh, I just can't wait anymore!\p"
	.string "Let's go to a MULTI BATTLE ROOM\n"
	.string "right this instant!\p"
	.string "If we get together in the BATTLE SALON,\n"
	.string "the power of our love will overcome\l"
	.string "everyone we meet.\p"
	.string "Why, before us, darling, everything\n"
	.string "will topple like dominoes!$"
#endif

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers_hns:
#if GERMAN
	.string "Die Kampfzone steht nicht nur\n"
	.string "starken Trainern offen.\p"
	.string "Hier sind auch viele, die sich durch\n"
	.string "besondere Eigenschaften und\l"
	.string "Fähigkeiten auszeichnen.\p"
	.string "Dieser Scott…\p"
	.string "Er hat diesen Ort mit Sicherheit gebaut,\n"
	.string "weil er etwas Höheres im Sinn hat…$"
#else
	.string "The BATTLE FRONTIER isn't exclusively\n"
	.string "for tough TRAINERS.\p"
	.string "Many people with special abilities\n"
	.string "have been invited, it seems.\p"
	.string "That man SCOTT…\p"
	.string "He may have built this place to serve\n"
	.string "a bigger objective…$"
#endif

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle_hns:
#if GERMAN
	.string "Entschuldige! Du bist jung! Deine\n"
	.string "Augen sind bestimmt hervorragend?!?\p"
	.string "Da vorne ist ein komischer Baum, und\n"
	.string "meine müden Augen scheinen zu sehen,\l"
	.string "dass er sich bewegt.$"
#else
	.string "Excuse me, young one.\n"
	.string "Have you good eyesight?\p"
	.string "There is an odd tree past here, and to\n"
	.string "my tired eyes it seems to wiggle.$"
#endif

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere_hns:
#if GERMAN
	.string "Entschuldige! Du bist noch jung. Dein\n"
	.string "Gedächtnis ist bestimmt sehr gut.\p"
	.string "War hier nicht früher ein merkwürdiger\n"
	.string "Baum?!?$"
#else
	.string "Excuse me, young one.\n"
	.string "Have you a good memory?\p"
	.string "I have this feeling there once was\n"
	.string "an odd tree past here.$"
#endif

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail_hns:
#if GERMAN
	.string "Ich… Ich habe es genau gesehen!!!\p"
	.string "Da vorne war ein merkwürdiges Pokémon\n"
	.string "mit einem langen Schweif!\p"
	.string "Es hatte sich unter einem Felsen\n"
	.string "versteckt und starrte mich an!$"
#else
	.string "I…\n"
	.string "I saw it!\p"
	.string "There was a sticky sort of a POKéMON\n"
	.string "with a long tail up ahead!\p"
	.string "It was hiding under a boulder, and\n"
	.string "it kept staring at me!$"
#endif
