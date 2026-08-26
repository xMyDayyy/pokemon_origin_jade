Route35_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN_HNS, Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT_HNS, Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE_HNS, Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM_HNS, Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN_HNS, Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten, Route35_EventScript_RegisterIrwin
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchIrwin
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterIrwin::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_IrwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_IRWIN_HNS
	release
	end

Route35_EventScript_RematchIrwin::
	trainerbattle_rematch TRAINER_IRWIN_HNS, Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE_HNS, Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten, Route35_EventScript_RegisterArnie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route35_EventScript_RematchArnie
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_RegisterArnie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route35_Text_ArnieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARNIE_HNS
	release
	end

Route35_EventScript_RematchArnie::
	trainerbattle_rematch TRAINER_ARNIE_HNS, Route35_Text_ArnieRematchIntro, Route35_Text_ArnieRematchDefeat
	msgbox Route35_Text_ArniePostRematch, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT_HNS, Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK_HNS, Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_Payback::
	finditem ITEM_TM_PAYBACK
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
#if GERMAN
	.string "Ich hole mir meine Pokémon-Info immer\n"
	.string "aus dem Radio.\l"
	.string "Damit bin ich jederzeit gerüstet.$"
#else
	.string "I've been getting POKéMON data off\n"
	.string "my radio. I think I'm good.$"
#endif

Route35_Text_CamperIvanBeaten:
#if GERMAN
	.string "Ich teile aus!$"
#else
	.string "I give!$"
#endif

Route35_Text_CamperIvanAfter:
#if GERMAN
	.string "Die Musik aus dem Radio beeinflusst die\n"
	.string "Stimmung von wilden Pokémon.\l"
	.string "Sie stimmt sie kampflustig oder zahmer!$"
#else
	.string "Music on the radio changes the\n"
	.string "moods of wild POKéMON.$"
#endif

Route35_Text_CamperElliotSeen:
#if GERMAN
	.string "Ich werde meiner Freundin zeigen, wie\n"
	.string "cool ich bin!$"
#else
	.string "I'm gonna show my girlfriend I'm\n"
	.string "hot stuff!$"
#endif

Route35_Text_CamperElliotBeaten:
#if GERMAN
	.string "Ach Mann! Hättest du nicht einfach…\n"
	.string "verlieren können?$"
#else
	.string "I wish you would have lost for me…$"
#endif

Route35_Text_CamperElliotAfter:
#if GERMAN
	.string "Du hast mich vor meiner Freundin\n"
	.string "lächerlich gemacht…$"
#else
	.string "I was humiliated in front of my\n"
	.string "girlfriend…$"
#endif

Route35_Text_PicnickerBrookeSeen:
#if GERMAN
	.string "Mein Freund ist ein Schwächling.\n"
	.string "Er kann mich nicht beschützen.$"
#else
	.string "My boyfriend's weak, so I can't rely\n"
	.string "on him.$"
#endif

Route35_Text_PicnickerBrookeBeaten:
#if GERMAN
	.string "Meine Güte, bist du stark!$"
#else
	.string "Oh, my! You're so strong!$"
#endif

Route35_Text_PicnickerBrookeAfter:
#if GERMAN
	.string "Meine Pokémon meinem Freund vorzu-\n"
	.string "ziehen, war wohl auch nicht gerade klug.$"
#else
	.string "I can count on my POKéMON more than\n"
	.string "my boyfriend.$"
#endif

Route35_Text_PicnickerKimSeen:
#if GERMAN
	.string "Bist du auf dem Weg zur Pokémon-Arena?\n"
	.string "Ich auch!$"
#else
	.string "Are you going to the GYM? Me too!$"
#endif

Route35_Text_PicnickerKimBeaten:
#if GERMAN
	.string "Ich gewinne aber auch nie!$"
#else
	.string "Oh. I couldn't win…$"
#endif

Route35_Text_PicnickerKimAfter:
#if GERMAN
	.string "Diese Orden sind so hübsch! Das ist\n"
	.string "auch der Grund, warum ich sie sammele!$"
#else
	.string "The GYM BADGES are pretty. I collect\n"
	.string "them.$"
#endif

Route35_Text_BirdKeeperBryanSeen:
#if GERMAN
	.string "Welche Art von Pokéball verwendest du?$"
#else
	.string "What kinds of BALLS do you use?$"
#endif

Route35_Text_BirdKeeperBryanBeaten:
#if GERMAN
	.string "Mist! Nicht schnell genug!$"
#else
	.string "Yikes! Not fast enough!$"
#endif

Route35_Text_BirdKeeperBryanAfter:
#if GERMAN
	.string "Wenn du hinter einem Pokémon mit hoher\n"
	.string "Initiative her bist, wirkt Kurts\l"
	.string "Turboball wahre Wunder!\p"
	.string "Sobald ich eine weiße Aprikoko finde,\n"
	.string "bringe ich sie zu Kurt. Er macht daraus\l"
	.string "einen maßgefertigten Pokéball.$"
#else
	.string "Some POKéMON flee right away.\p"
	.string "Try catching them with KURT's\n"
	.string "FAST BALL.\p"
	.string "Whenever I find a ASPEAR BERRY, I\n"
	.string "take it to KURT.\p"
	.string "He turns it into a custom BALL.$"
#endif

Route35_Text_JugglerIrwinSeen:
#if GERMAN
	.string "Sieh meine elegante Ball-Kunst!$"
#else
	.string "Behold my graceful BALL dexterity!$"
#endif

Route35_Text_JugglerIrwinBeaten:
#if GERMAN
	.string "Puh, das war ein Schlag!$"
#else
	.string "Whew! That was a jolt!$"
#endif

Route35_Text_JugglerIrwinAfter:
#if GERMAN
	.string "Ich wollte dich mit meinen\n"
	.string "preisgekrönten Pokémon blenden.\l"
	.string "Aber dein Können hat mich elektrisiert.$"
#else
	.string "I was going to dazzle you with my\n"
	.string "prize POKéMON.\p"
	.string "But your prowess electrified me!$"
#endif

Route35_Text_BugCatcherArnieSeen:
#if GERMAN
	.string "Mich zieht es überall dort hin, wo es\n"
	.string "Käfer-Pokémon gibt!$"
#else
	.string "I'll go anywhere if bug POKéMON\n"
	.string "appear there.$"
#endif

Route35_Text_BugCatcherArnieBeaten:
#if GERMAN
	.string "Ich hätte nicht verlieren dürfen…$"
#else
	.string "Huh? I shouldn't have lost that…$"
#endif

Route35_Text_BugCatcherArnieAfter:
#if GERMAN
	.string "Mit meinem Bluzuk habe ich das\n"
	.string "Käferturnier im Nationalpark gewonnen.$"
#else
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"
#endif

Route35_Text_IrwinRegister:
#if GERMAN
	.string "Ich wollte dich mit meinen\n"
	.string "Preis-Pokémon beeindrucken.\p"
	.string "Aber dein Können hat mich\n"
	.string "elektrisiert!$"
#else
	.string "I was going to dazzle you with my\n"
	.string "prize POKéMON.\p"
	.string "But your prowess electrified me!$"
#endif

Route35_Text_IrwinRegister:
	.string "I was going to dazzle you with my\n"
	.string "prize POKéMON.\p"
	.string "But your prowess electrified me!$"

Route35_Text_ArnieRegister:
#if GERMAN
	.string "Mit meinem Bluzuk habe ich das\n"
	.string "Käferturnier im Nationalpark gewonnen.$"
#else
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"
#endif

Route35_Text_ArnieRematchIntro:
#if GERMAN
	.string "Mich zieht es überall dort hin, wo es\n"
	.string "Käfer-Pokémon gibt!$"
#else
	.string "I'll go anywhere if bug POKéMON\n"
	.string "appear there.$"
#endif

Route35_Text_ArnieRematchDefeat:
#if GERMAN
    .string "Hä? Das hätte ich doch nicht verlieren\n"
    .string "dürfen…$"
#else
	.string "Huh? I shouldn't have lost that…$"
#endif

Route35_Text_ArniePostRematch:
#if GERMAN
	.string "Mit meinem Bluzuk habe ich das\n"
	.string "Käferturnier im Nationalpark gewonnen.$"
#else
	.string "My VENONAT won me the Bug-Catching\n"
	.string "Contest at the NATIONAL PARK.$"
#endif

Route35_Text_BugCatcherArnieYanma:
#if GERMAN
	.string "Wow… Sieh, all die Yanma!\p"
	.string "Ich bin überwältigt und kann mich nicht\n"
	.string "rühren.$"
#else
	.string "Wow… Look at all those YANMA!\p"
	.string "I'm so blown away, I can't move.$"
#endif

Route35_Text_FirebreatherWaltSeen:
#if GERMAN
	.string "Ich übe mich im Feuerspucken.$"
#else
	.string "I'm practicing my fire breathing.$"
#endif

Route35_Text_FirebreatherWaltBeaten:
#if GERMAN
	.string "Aua! Jetzt habe ich mir die Nasenspitze\n"
	.string "verbrannt!$"
#else
	.string "Ow! I scorched the tip of my nose!$"
#endif

Route35_Text_FirebreatherWaltAfter:
#if GERMAN
	.string "Der Pokémon-Marsch im Radio lockt wilde\n"
	.string "Pokémon an.$"
#else
	.string "The POKéMON March on the radio\n"
	.string "lures wild POKéMON.$"
#endif

Route35_Text_OfficerDirkSeen:
#if GERMAN
	.string "Die Nacht steckt voller Gefahren!$"
#else
	.string "Danger lurks in the night!$"
#endif

Route35_Text_OfficerDirkBeaten:
#if GERMAN
	.string "Ups!$"
#else
	.string "Whoops!$"
#endif

Route35_Text_OfficerDirkAfter:
#if GERMAN
	.string "Weißt du, die Nacht hat auch ihren Reiz.\p"
	.string "Aber übertreib es nicht, ja?$"
#else
	.string "You know, night time is fun in its\n"
	.string "own ways.\p"
	.string "But don't overdo it, OK?$"
#endif

Route35_Text_OfficerDirkTough:
#if GERMAN
	.string "Deine Pokémon sehen ziemlich stark aus!\n"
	.string "Mit denen bist du überall sicher!$"
#else
	.string "Your POKéMON look pretty tough.\p"
	.string "You could go anywhere safely.$"
#endif

Route35_Text_Sign:
#if GERMAN
	.string "Route 35$"
#else
	.string "ROUTE 35$"
#endif

Route35_Text_Sign2:
#if GERMAN
	.string "Nationalpark$"
#else
	.string "NATIONAL PARK GATE$"
#endif
