const u8 *const gSpeakerNamesTable[SP_NAME_COUNT] =
{
#if GERMAN
    [SP_NAME_MOM]    = COMPOUND_STRING("Mama"),
#else
    [SP_NAME_MOM]    = COMPOUND_STRING("MOM"),
#endif
    [SP_NAME_PLAYER] = COMPOUND_STRING("{PLAYER}"),
};
