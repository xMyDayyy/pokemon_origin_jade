MtSilver_2F_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtSilver_2F_OnResume
	.byte 0

MtSilver_2F_OnResume::
	callnative SetTimeBasedEncounters
	setescapewarp MAP_MT_SILVER_OUTSIDE_HNS, 17, 8
	end

MtSilver_2F_OnTransition: 
	callnative SetTimeBasedEncounters
	setescapewarp MAP_MT_SILVER_OUTSIDE_HNS, 17, 8
	@ Origin Jade: the Azure Flute unlocks Meara's Sinjoh offer
	@ (SINJOH_CONTENT_AVAILABLE in include/config/general.h).
#if SINJOH_CONTENT_AVAILABLE
	call_if_unset FLAG_SINJOH_UNLOCK_MIGRATED, MtSilver_2F_EventScript_ShowAzureFlute
#else
	setflag FLAG_HIDE_MT_SILVER_2F_AZURE_FLUTE
#endif
	end

MtSilver_2F_EventScript_ShowAzureFlute::
	setflag FLAG_SINJOH_UNLOCK_MIGRATED
	checkitem ITEM_AZURE_FLUTE
	goto_if_eq VAR_RESULT, TRUE, Common_EventScript_NopReturn
	clearflag FLAG_HIDE_MT_SILVER_2F_AZURE_FLUTE
	return

MtSilver_2F_Item_AzureFlue::
	finditem ITEM_AZURE_FLUTE
	end
