GoldenrodCity_UndergroundEntrance_hns_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
#if GERMAN
	.string "Uff… ich habe unten in der Passage\n"
	.string "einen Pokémon-Kampf angezettelt, aber\l"
	.string "dabei ziemlich auf die Mütze gekriegt.\l"
	.string "Sei besser auf dem, äh, der Hut!$"
#else
	.string "I was challenged to a battle\n"
	.string "downstairs.\p"
	.string "It's rough down there. You'd\n"
	.string "better be careful.$"
#endif


GoldenrodUnderground1_Text_Teacher:
#if GERMAN
	.string "Unten in der Passage\n"
	.string "gibt es Geschäfte!\p"
	.string "Aber da lungern so viele Trainer herum,\n"
	.string "dass ich mich nicht hinuntertraue.$"
#else
	.string "There are some shops downstairs…\n"
	.string "But there are also trainers.\p"
	.string "I'm scared to go down there.$"
#endif
