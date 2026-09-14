#include "global.h"
#include "event_data.h"
#include "overworld.h"
#include "level_scaling.h"
#include "hoenn_licenses.h"

// Eigene Bitmaske in VAR_HOENN_LICENSES, unabhaengig von den Johto-Orden.
// Die Sperre greift ausschliesslich innerhalb von Hoenn (IsHoennMapsec);
// in Johto und Kanto gelten weiterhin die Ordenabfragen aus field_move.c.

#if defined(POKEMON_HNS)

bool32 HasHoennLicense(u32 index)
{
    if (index >= LIC_COUNT)
        return FALSE;
    return (VarGet(VAR_HOENN_LICENSES) & (1 << index)) != 0;
}

bool32 HoennLicensesApply(void)
{
    return IsHoennMapsec(gMapHeader.regionMapSectionId);
}

// Special: Lizenzindex (0 - LIC_COUNT-1) in gSpecialVar_0x8004
void SetHoennLicense(void)
{
    if (gSpecialVar_0x8004 < LIC_COUNT)
        VarSet(VAR_HOENN_LICENSES, VarGet(VAR_HOENN_LICENSES) | (1 << gSpecialVar_0x8004));
}

// Special: Lizenzindex in gSpecialVar_0x8004. Ergebnis nach gSpecialVar_Result:
// TRUE = darf hier eingesetzt werden. Ausserhalb von Hoenn immer TRUE, damit
// die Skripte in Johto und Kanto unveraendert durchlaufen.
void CheckHoennLicense(void)
{
    gSpecialVar_Result = (!HoennLicensesApply() || HasHoennLicense(gSpecialVar_0x8004));
}

#else

bool32 HasHoennLicense(u32 index) { return TRUE; }
bool32 HoennLicensesApply(void) { return FALSE; }
void SetHoennLicense(void) {}
void CheckHoennLicense(void) { gSpecialVar_Result = TRUE; }

#endif
