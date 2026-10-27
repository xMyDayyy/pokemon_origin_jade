VermilionCity_PortOutside_Frlg_MapScripts::
	.byte 0

VermilionCity_PortOutsideFrlg_EventScript_Fisher::
	msgbox VermilionCity_PortOutsideFrlg_Text_Fisher, MSGBOX_NPC
	end

VermilionCity_PortOutsideFrlg_Text_Fisher::
#if GERMAN
	.string "Ein Seemann hat mir erzählt, dass\n"
	.string "es in Johto rote Garados gibt!\p"
	.string "Ob das wohl stimmt?$"
#else
	.string "A sailor told me there are RED\n"
	.string "GYARADOS in JOHTO!\p"
	.string "Could that be true?$"
#endif
