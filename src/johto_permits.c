#include "global.h"
#include "event_data.h"
#include "overworld.h"
#include "string_util.h"
#include "johto_permits.h"
#include "hoenn_licenses.h"
#include "constants/region_map_sections.h"
#include "constants/vars_origin_jade.h"

// HM permits for Johto, one bit per PERM_* in VAR_JOHTO_PERMITS.

#if defined(POKEMON_HNS)

bool32 IsJohtoMapsec(u32 mapSecId)
{
    return mapSecId >= JOHTO_MAPSEC_START && mapSecId <= JOHTO_MAPSEC_END;
}

bool32 HasJohtoPermit(u32 index)
{
    if (index >= PERM_COUNT)
        return FALSE;
    return (VarGet(VAR_JOHTO_PERMITS) & (1 << index)) != 0;
}

// Way in from Kanto, where permits do not apply.
static bool32 IsJohtoArrivalCorridor(u32 mapSecId)
{
    return mapSecId == MAPSEC_ROUTE_26
        || mapSecId == MAPSEC_ROUTE_27
        || mapSecId == MAPSEC_TOHJO_FALLS;
}

bool32 JohtoPermitsApply(void)
{
    u32 mapSecId = gMapHeader.regionMapSectionId;

    if (IsJohtoArrivalCorridor(mapSecId))
        return FALSE;
    return IsJohtoMapsec(mapSecId);
}

// Special: permit index (0 - PERM_COUNT-1) in gSpecialVar_0x8004
void SetJohtoPermit(void)
{
    if (gSpecialVar_0x8004 < PERM_COUNT)
        VarSet(VAR_JOHTO_PERMITS, VarGet(VAR_JOHTO_PERMITS) | (1 << gSpecialVar_0x8004));
}

#else

bool32 IsJohtoMapsec(u32 mapSecId) { return FALSE; }
bool32 HasJohtoPermit(u32 index) { return TRUE; }
bool32 JohtoPermitsApply(void) { return FALSE; }
void SetJohtoPermit(void) {}

#endif

// Special: LIC_*/PERM_* index in gSpecialVar_0x8004.
// gSpecialVar_Result = TRUE if the field move may be used here (always outside Hoenn and Johto).
void CheckFieldPermission(void)
{
    if (HoennLicensesApply())
        gSpecialVar_Result = HasHoennLicense(gSpecialVar_0x8004);
    else if (JohtoPermitsApply())
        gSpecialVar_Result = HasJohtoPermit(gSpecialVar_0x8004);
    else
        gSpecialVar_Result = TRUE;
}

// Special: the current region's term into STR_VAR_2 for the shared refusal text.
// Both German terms must be feminine.
void BufferFieldPermissionTerm(void)
{
#if GERMAN
    static const u8 sText_HoennTerm[] = _("Erlaubnis");
    static const u8 sText_JohtoTerm[] = _("Befugnis");
#else
    static const u8 sText_HoennTerm[] = _("licence");
    static const u8 sText_JohtoTerm[] = _("permit");
#endif

    if (JohtoPermitsApply())
        StringCopy(gStringVar2, sText_JohtoTerm);
    else
        StringCopy(gStringVar2, sText_HoennTerm);
}
