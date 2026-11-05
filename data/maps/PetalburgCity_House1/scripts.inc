PetalburgCity_House1_MapScripts::
	.byte 0

PetalburgCity_House1_EventScript_Man::
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
	end

PetalburgCity_House1_EventScript_Woman::
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
	end

PetalburgCity_House1_Text_TravelingIsWonderful:
#if GERMAN
	.string "Reisen ist einfach wundervoll!\p"
	.string "Als ich noch jung war, waren die See\n"
	.string "und die Berge mein Zuhause.$"
#else
	.string "Traveling is wonderful!\p"
	.string "When I was young, I roamed the seas\n"
	.string "and the mountains!$"
#endif

PetalburgCity_House1_Text_GoOnAdventure:
#if GERMAN
	.string "Seufz…\p"
	.string "Ich wünschte, ich könnte mit einigen\n"
	.string "Pokémon auf Abenteuerreise gehen…\p"
	.string "Sich durch hohes Gras schleichen…\n"
	.string "Steile, zerklüftete Berge erklimmen…\p"
	.string "Das tosende Meer überqueren…\n"
	.string "Dunkle Höhlen erforschen…\p"
	.string "Und manchmal ein wenig Heimweh haben…\p"
	.string "Reisen muss einfach toll sein!$"
#else
	.string "Sigh…\p"
	.string "I wish I could go on an adventure\n"
	.string "with some POKéMON…\p"
	.string "Crawl through some damp grass…\n"
	.string "Climb rocky, rugged mountains…\p"
	.string "Cross the raging seas…\n"
	.string "Wander about in dark caves…\p"
	.string "And, sometimes, even get a little\n"
	.string "homesick…\p"
	.string "It must be fabulous to travel!$"
#endif

