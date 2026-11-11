#ifndef GUARD_CONSTANTS_JOHTO_PERMITS_H
#define GUARD_CONSTANTS_JOHTO_PERMITS_H

// HM permits for Johto (bit positions in VAR_JOHTO_PERMITS). Flash needs none;
// Fly is tied to the police scene in Elm's lab (see IsFieldMoveUnlocked_Fly).
// Keep the order in sync with LIC_* in constants/hoenn_licenses.h.
#define PERM_CUT         0
#define PERM_ROCK_SMASH  1
#define PERM_STRENGTH    2
#define PERM_SURF        3
#define PERM_DIVE        4
#define PERM_WATERFALL   5
#define PERM_COUNT       6

#endif // GUARD_CONSTANTS_JOHTO_PERMITS_H
