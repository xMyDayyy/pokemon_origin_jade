@ Symbols from the removed HnS Kanto maps that Johto maps still use.

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_LockedDoor:
#if GERMAN
	.string "Abgeschlossen…$"
#else
	.string "It's locked…$"
#endif
