Route10_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route10_OnTransition
	.byte 0

@ Flugpunkt bereits beim Betreten der Route freischalten, nicht erst
@ beim Betreten des Pokemon-Centers.
Route10_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE10_POKEMON_CENTER_1F
	end

Route10_EventScript_Unused::
	end

Route10_EventScript_NorthRockTunnelSign::
	msgbox Route10_Text_RockTunnelDetourToLavender, MSGBOX_SIGN
	end

Route10_EventScript_SouthRockTunnelSign::
	msgbox Route10_Text_RockTunnel, MSGBOX_SIGN
	end

Route10_EventScript_PowerPlantSign::
	msgbox Route10_Text_PowerPlant, MSGBOX_SIGN
	end

Route10_Text_MarkIntro::
#if GERMAN
	.string "Bist du auch ein Pokémaniac?\n"
	.string "Möchtest du meine Sammlung sehen?$"
#else
	.string "Wow, you came all the way here?\n"
	.string "Maybe you're a POKéMANIAC, too?\l"
	.string "Want to see my collection?$"
#endif

Route10_Text_MarkDefeat::
#if GERMAN
	.string "Na ja, macht nichts!$"
#else
	.string "Humph.\n"
	.string "I'm not angry!$"
#endif

Route10_Text_MarkPostBattle::
#if GERMAN
	.string "Zu Hause habe ich noch mehr seltene\n"
	.string "Pokémon!$"
#else
	.string "I have more rare POKéMON at home!$"
#endif

Route10_Text_ClarkIntro::
#if GERMAN
	.string "Ha-ha-ha-ha!$"
#else
	.string "Ha-hahah-ah-ha!$"
#endif

Route10_Text_ClarkDefeat::
#if GERMAN
	.string "Ha-ha!\n"
	.string "Haha-ha-tschi!$"
#else
	.string "Ha-haha!\n"
	.string "Not laughing!\l"
	.string "Ha-hay fever! Haha-ha-choo!$"
#endif

Route10_Text_ClarkPostBattle::
#if GERMAN
	.string "Schnief...\n"
	.string "Diese verdammte Erkältung!$"
#else
	.string "Haha-ha-choo!\n"
	.string "Ha-choo!\l"
	.string "Snort! Snivel!$"
#endif

Route10_Text_HermanIntro::
#if GERMAN
	.string "Heh du, möchtest du meine Pokémon\n"
	.string "sehen?$"
#else
	.string "Hi, kid!\n"
	.string "Want to see my POKéMON?$"
#endif

Route10_Text_HermanDefeat::
#if GERMAN
	.string "Nein!\n"
	.string "Meine Pokémon!$"
#else
	.string "Oh, no!\n"
	.string "My POKéMON!$"
#endif

Route10_Text_HermanPostBattle::
#if GERMAN
	.string "Ich nehme dir übel, dass du mich\n"
	.string "besiegt hast!$"
#else
	.string "I don't like you.\n"
	.string "I don't like anyone better than me!$"
#endif

Route10_Text_HeidiIntro::
#if GERMAN
	.string "Jedes Mal, wenn ich in einer\n"
	.string "Pokémon-Arena gekämpft habe, wurde\l"
	.string "ich besiegt!$"
#else
	.string "I've been out at a POKéMON GYM\n"
	.string "a few times.\p"
	.string "…But I always lose.$"
#endif

Route10_Text_HeidiDefeat::
#if GERMAN
	.string "Nein!\n"
	.string "Nicht schon wieder!$"
#else
	.string "Ohh!\n"
	.string "After all my training!$"
#endif

Route10_Text_HeidiPostBattle::
#if GERMAN
	.string "Ich habe einige PokémaniacS in\n"
	.string "dieser Gegend gesehen.$"
#else
	.string "I noticed some POKéMANIACS\n"
	.string "prowling around.\p"
	.string "Can you imagine? Them?\n"
	.string "Up here in the mountains?$"
#endif

Route10_Text_TrentIntro::
#if GERMAN
	.string "Ahh! Die Bergluft ist so wunderbar\n"
	.string "erfrischend!$"
#else
	.string "Ah!\n"
	.string "This mountain air is delicious!$"
#endif

Route10_Text_TrentDefeat::
#if GERMAN
	.string "Ich kann wieder klar denken!$"
#else
	.string "That cleared my head!$"
#endif

Route10_Text_TrentPostBattle::
#if GERMAN
	.string "Ich habe von Bergluft die Nase\n"
	.string "gestrichen voll!$"
#else
	.string "I feel bloated on mountain air!$"
#endif

Route10_Text_CarolIntro::
#if GERMAN
	.string "Ich fühle mich vom vielen Wandern\n"
	.string "erschöpft...$"
#else
	.string "I'm feeling a bit faint.\n"
	.string "I haven't hiked in some time.$"
#endif

Route10_Text_CarolDefeat::
#if GERMAN
	.string "Ich bin nicht fit!$"
#else
	.string "I'm too tired.\n"
	.string "I wasn't up for it.$"
#endif

Route10_Text_CarolPostBattle::
#if GERMAN
	.string "Viele Pokémon in dieser Gegend\n"
	.string "sind grob!\p"
	.string "Ich wünschte, eines wäre rosa mit\n"
	.string "einem Blumenmuster!$"
#else
	.string "The POKéMON here in the mountains\n"
	.string "are so chunky…\p"
	.string "I wish there were pink POKéMON\n"
	.string "with a floral pattern!$"
#endif

Route10_Text_RockTunnelDetourToLavender::
#if GERMAN
	.string "Felstunnel\n"
	.string "Umleitung nach Lavandia$"
#else
	.string "ROCK TUNNEL\n"
	.string "Detour to LAVENDER TOWN$"
#endif

Route10_Text_RockTunnel::
#if GERMAN
	.string "Felstunnel$"
#else
	.string "ROCK TUNNEL$"
#endif

Route10_Text_PowerPlant::
#if GERMAN
	.string "Kraftwerk$"
#else
	.string "POWER PLANT$"
#endif

