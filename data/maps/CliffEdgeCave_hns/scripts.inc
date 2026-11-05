CliffEdgeCave_hns_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
#if GERMAN
	.string "Wenn du in einer Höhle auf eine\n"
	.string "Weggabelung stößt, ist einer der beiden\l"
	.string "Wege meistens der richtige und der\l"
	.string "andere endet in einer Sackgasse.\p"
	.string "Aber bevor wir nicht beide Richtungen\n"
	.string "ausprobiert haben, finden wir Menschen\l"
	.string "einfach keine Ruhe.\p"
	.string "Für welche Leiter\n"
	.string "entscheidest du dich?\p"
	.string "Für die, die nach oben führt, oder für\n"
	.string "die, die nach unten führt?$"
#else
	.string "If you see a fork in the road\n"
	.string "inside a cave, most likely one\l"
	.string "way is right and the other leads\l"
	.string "to a dead end.\p"
	.string "But people can't help trying both.$"
#endif
