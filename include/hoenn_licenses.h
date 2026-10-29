#ifndef GUARD_HOENN_LICENSES_H
#define GUARD_HOENN_LICENSES_H

#include "constants/hoenn_licenses.h"

// HM licenses: in Hoenn a field move needs its license.

bool32 HasHoennLicense(u32 index);
bool32 HoennLicensesApply(void);   // TRUE if the player is currently in Hoenn
void SetHoennLicense(void);        // Special: index in gSpecialVar_0x8004
void CheckHoennLicense(void);      // Special: TRUE = allowed here

#endif // GUARD_HOENN_LICENSES_H
