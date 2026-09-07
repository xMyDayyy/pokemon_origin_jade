MtSilver_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MtSilver_2F_OnTransition:
	callnative SetTimeBasedEncounters
#if SINJOH_CONTENT_AVAILABLE == FALSE
	setflag FLAG_HIDE_MT_SILVER_2F_AZURE_FLUTE
#else
	@ Einmalig beim Freischalten: das Versteckflag der Azurfloete ist zugleich ihr
	@ Aufsammelflag. Nur einmal loeschen, sonst waere der Ball nach jedem Betreten
	@ der Karte wieder da und die Floete beliebig oft aufsammelbar.
	goto_if_set FLAG_SINJOH_UNLOCK_MIGRATED, MtSilver_2F_OnTransition_Done
	setflag FLAG_SINJOH_UNLOCK_MIGRATED
	clearflag FLAG_HIDE_MT_SILVER_2F_AZURE_FLUTE
MtSilver_2F_OnTransition_Done:
#endif
	end

MtSilver_2F_Item_AzureFlue::
	finditem ITEM_AZURE_FLUTE
	end
