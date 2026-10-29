LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllRegionalMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
#if IS_HNS
	call_if_unset FLAG_RECEIVED_SHINY_CHARM, LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm
#endif
	special Special_ShowDiploma
	waitstate
	release
	end

#if IS_HNS
@ Shiny Charm for the completed National Pokedex after the first Hoenn title.
@ Keep the call before Special_ShowDiploma: commands after it never run.
@ See docs/origin_jade/DECISIONS.md, D-036.
LilycoveCity_CoveLilyMotel_2F_EventScript_TryGiveShinyCharm:
	goto_if_unset FLAG_IS_HOENN_CHAMPION, Common_EventScript_NopReturn
	specialvar VAR_RESULT, HasAllMons
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	waitbuttonpress
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NationalDexTakeThisToo, MSGBOX_DEFAULT
	giveitem ITEM_SHINY_CHARM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_SHINY_CHARM
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ExplainShinyCharm, MSGBOX_DEFAULT
	return
#endif

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
#if GERMAN
	.string "Ich bin der Game Designer.\p"
	.string "Oh, wirklich?\n"
	.string "Du arbeitest an einem Pokédex?\p"
	.string "Es ist schwer, ihn zu vervollständigen,\n"
	.string "aber du darfst nicht aufgeben.\p"
	.string "Sobald du ihn vervollständigt hast,\n"
	.string "komm mich wieder besuchen.$"
#else
	.string "I'm the GAME DESIGNER.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a POKéDEX?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
#if GERMAN
	.string "Wow! Das ist beeindruckend!\n"
	.string "Wirklich äußerst beeindruckend!\p"
	.string "Dein Pokédex ist absolut vollständig!\n"
	.string "Du musst die Pokémon wirklich lieben!\l"
	.string "\p"
	.string "Ich bin echt beeindruckt!\p"
	.string "Ich möchte dir als Zeichen meiner\n"
	.string "Aner- kennung gerne etwas schenken!$"
#else
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This POKéDEX is completely filled!\n"
	.string "You really must love POKéMON!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"
#endif

#if IS_HNS
LilycoveCity_CoveLilyMotel_2F_Text_NationalDexTakeThisToo:
#if GERMAN
	.string "Sogar dein Nationaler Pokédex ist\n"
	.string "vollständig!\p"
	.string "Dafür bekommst du noch das hier!$"
#else
	.string "Your NATIONAL POKéDEX is complete,\n"
	.string "too! Please take this as well!$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_ExplainShinyCharm:
#if GERMAN
	.string "Mit dem Schillerpin findest du\n"
	.string "öfter schillernde Pokémon.$"
#else
	.string "With the SHINY CHARM, you will find\n"
	.string "shiny POKéMON more often.$"
#endif
#endif

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
#if GERMAN
	.string "Ich? Sprichst du mit mir?\n"
	.string "Ich bin der Programmierer.\p"
	.string "Ich frage mich, wie die Einarmigen\n"
	.string "Banditen hier wohl so sind.$"
#else
	.string "Me? You're talking to me?\n"
	.string "I'm the PROGRAMMER.\p"
	.string "I wonder what the SLOTS are\n"
	.string "like here.$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
#if GERMAN
	.string "Ich bin der Graphic Artist! Sind die\n"
	.string "Pokémon in der Region von Hoenn nicht\l"
	.string "interessant?$"
#else
	.string "I'm the GRAPHIC ARTIST! Aren't the\n"
	.string "POKéMON of HOENN interesting?$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
#if GERMAN
	.string "Die Mädchen mit den Schwimmreifen\n"
	.string "sind total niedlich, meinst du nicht?\l"
	.string "Ein Kampf gegen so niedliche Mädchen…\l"
	.string "\p"
	.string "Huuh, das ist vielleicht ein Spaß!\p"
	.string "Und die Zwillinge erst! Sind die süß!?!\n"
	.string "Ein 2-gegen-2-Kampf mit Zwillingen…\p"
	.string "Huuh, einfach unglaublicher Spaß!$"
#else
	.string "The girl TUBERS, they're cute, hey?\n"
	.string "To battle against a cute TUBER…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the TWINS! Aren't they cute?\n"
	.string "A 2-on-2 battle with TWINS…\p"
	.string "Whoop, it's unbearably fun!$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
#if GERMAN
	.string "Die frische Seebrise berührt mein\n"
	.string "Herz. Es ist einfach wundervoll hier.$"
#else
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
#if GERMAN
	.string "Du kannst nie vorhersagen, wann und wo\n"
	.string "die Leute dich herausfordern.\p"
	.string "Daher gehe ich niemals ohne meinen\n"
	.string "Game Boy Advance aus dem Haus.$"
#else
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my GAME BOY ADVANCE.$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
#if GERMAN
	.string "Scott: … … … …\n"
	.string "…\l"
	.string "… … … … …\l"
	.string "Zzzzz…\p"
	.string "… … … … …\n"
	.string "Wie?!?\l"
	.string "Oh, tut mir Leid!\l"
	.string "Ich habe ein bisschen gedöst!\p"
	.string "Ich wollte mir mal einen Pokémon\n"
	.string "Wettbewerb anschauen.\p"
	.string "Das scheint ganz interessant zu sein,\n"
	.string "aber…\p"
	.string "Vielleicht bin ich ja Purist - aber ich\n"
	.string "bevorzuge Kämpfe und starke Trainer.\p"
	.string "Aber das liegt wohl an mir.\p"
	.string "Ich hoffe du genießt die Arenen,\n"
	.string "Wettbewerbe, Kampfcamps und all die\l"
	.string "wunderbaren Dinge, {PLAYER}{KUN}!$"
#else
	.string "SCOTT: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this POKéMON\n"
	.string "CONTEST thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough TRAINERS.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the GYMS, CONTESTS, BATTLE TENT,\l"
	.string "the whole works!$"
#endif

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
#if GERMAN
	.string "Scott: Ich denke schon, dass es auf\n"
	.string "Strategie ankommt, um einen Wettbewerb\l"
	.string "zu gewinnen.\p"
	.string "Sich eine Strategie auszudenken ist\n"
	.string "nur ein Weg, ein guter Trainer zu\l"
	.string "werden…$"
#else
	.string "SCOTT: I think it does take strategy\n"
	.string "to win a CONTEST.\p"
	.string "Devising CONTEST strategies is one way\n"
	.string "of becoming a better TRAINER, I'd say.$"
#endif

