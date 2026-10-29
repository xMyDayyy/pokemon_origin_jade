// Origin Jade: color table of the disabled lightning animation.
// Before setting JADE_TITEL_ANIMATION to TRUE, refit the assets with
// colors used only by the beams. The entry below is a placeholder.

struct JadeAnimColor
{
    u16 slot;
    u16 farbe;
};

static const struct JadeAnimColor sJadeStrahlen[] =
{
    { 0x08F, 0x1D02 },
};
