#ifndef GUARD_CONSTANTS_JOHTO_PERMITS_H
#define GUARD_CONSTANTS_JOHTO_PERMITS_H

// VM-Befugnisse fuer Johto (Bitpositionen in VAR_JOHTO_PERMITS).
// Als #define statt enum, damit die Skript-Assemblerdateien sie ebenfalls
// verwenden koennen. Reihenfolge absichtlich identisch zu den Hoenn-Lizenzen
// (constants/hoenn_licenses.h) - dadurch kommt CheckFieldPermission mit einem
// einzigen Index fuer beide Regionen aus.
// Fliegen und Blitz sind wie in Hoenn bewusst nicht gesperrt.
#define PERM_CUT         0
#define PERM_ROCK_SMASH  1
#define PERM_STRENGTH    2
#define PERM_SURF        3
#define PERM_DIVE        4
#define PERM_WATERFALL   5
#define PERM_COUNT       6

#endif // GUARD_CONSTANTS_JOHTO_PERMITS_H
