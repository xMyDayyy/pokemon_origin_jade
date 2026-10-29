@ Legendary rules (see docs/origin_jade/DECISIONS.md, D-026).
@ Ids: include/constants/legendaries_oj.h, state: src/legendaries_oj.c.

@ Every league victory: knocked-out legendaries return, released roamers roam again.
@ Called by the Kanto, Johto and Hoenn halls of fame; a second call changes nothing.
Common_EventScript_ReviveDefeatedLegendaries::
	special ReviveDefeatedLegendaries
	return

@ Union Cave Lapras and the red Gyarados after a flight (STR_VAR_1 = species name).
Text_MonSwamAway::
#if GERMAN
	.string "{STR_VAR_1} schwamm davon!$"
#else
	.string "{STR_VAR_1} swam away!$"
#endif
