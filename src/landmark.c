#include "global.h"
#include "event_data.h"
#include "constants/region_map_sections.h"

struct Landmark
{
    const u8 *name;
    u16 flag;
};

struct LandmarkList
{
    mapsec_u8_t mapSection;
    u8 id;
    const struct Landmark *const *landmarks;
};

#if GERMAN
static const u8 LandmarkName_MagmaHideout[] = _("MAGMAs Versteck");
#else
static const u8 LandmarkName_MagmaHideout[] = _("MAGMA HIDEOUT");
#endif //Unused

#if GERMAN
static const struct Landmark Landmark_FlowerShop = {COMPOUND_STRING("Blumenladen"), FLAG_LANDMARK_FLOWER_SHOP};
#else
static const struct Landmark Landmark_FlowerShop = {COMPOUND_STRING("FLOWER SHOP"), FLAG_LANDMARK_FLOWER_SHOP};
#endif
#if GERMAN
static const struct Landmark Landmark_PetalburgWoods = {COMPOUND_STRING("Blütenburgwald"), -1};
#else
static const struct Landmark Landmark_PetalburgWoods = {COMPOUND_STRING("PETALBURG WOODS"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_MrBrineysCottage = {COMPOUND_STRING("Mr. Bracks Hütte"), FLAG_LANDMARK_MR_BRINEY_HOUSE};
#else
static const struct Landmark Landmark_MrBrineysCottage = {COMPOUND_STRING("MR. BRINEY'S COTTAGE"), FLAG_LANDMARK_MR_BRINEY_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_AbandonedShip = {COMPOUND_STRING("Schiffswrack"), FLAG_LANDMARK_ABANDONED_SHIP};
#else
static const struct Landmark Landmark_AbandonedShip = {COMPOUND_STRING("ABANDONED SHIP"), FLAG_LANDMARK_ABANDONED_SHIP};
#endif
#if GERMAN
static const struct Landmark Landmark_SeashoreHouse = {COMPOUND_STRING("Strandhaus"), FLAG_LANDMARK_SEASHORE_HOUSE};
#else
static const struct Landmark Landmark_SeashoreHouse = {COMPOUND_STRING("SEASHORE HOUSE"), FLAG_LANDMARK_SEASHORE_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_SlateportBeach = {COMPOUND_STRING("Graphitportstrand"), -1};
#else
static const struct Landmark Landmark_SlateportBeach = {COMPOUND_STRING("SLATEPORT BEACH"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_CyclingRoad = {COMPOUND_STRING("Radweg"), -1};
#else
static const struct Landmark Landmark_CyclingRoad = {COMPOUND_STRING("CYCLING ROAD"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_NewMauville = {COMPOUND_STRING("Neu Malvenfroh"), FLAG_LANDMARK_NEW_MAUVILLE};
#else
static const struct Landmark Landmark_NewMauville = {COMPOUND_STRING("NEW MAUVILLE"), FLAG_LANDMARK_NEW_MAUVILLE};
#endif
#if GERMAN
static const struct Landmark Landmark_TrickHouse = {COMPOUND_STRING("Rätselhaus"), FLAG_LANDMARK_TRICK_HOUSE};
#else
static const struct Landmark Landmark_TrickHouse = {COMPOUND_STRING("TRICK HOUSE"), FLAG_LANDMARK_TRICK_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_OldLadysRestShop = {COMPOUND_STRING("Hotel der alten Dame"), FLAG_LANDMARK_OLD_LADY_REST_SHOP};
#else
static const struct Landmark Landmark_OldLadysRestShop = {COMPOUND_STRING("OLD LADY'S REST STOP"), FLAG_LANDMARK_OLD_LADY_REST_SHOP};
#endif
#if GERMAN
static const struct Landmark Landmark_Desert = {COMPOUND_STRING("Wüste"), -1};
#else
static const struct Landmark Landmark_Desert = {COMPOUND_STRING("DESERT"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_WinstrateFamily = {COMPOUND_STRING("Familie Sihgers"), FLAG_LANDMARK_WINSTRATE_FAMILY};
#else
static const struct Landmark Landmark_WinstrateFamily = {COMPOUND_STRING("THE WINSTRATE FAMILY"), FLAG_LANDMARK_WINSTRATE_FAMILY};
#endif
#if GERMAN
static const struct Landmark Landmark_CableCar = {COMPOUND_STRING("Seilbahn"), -1};
#else
static const struct Landmark Landmark_CableCar = {COMPOUND_STRING("CABLE CAR"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_GlassWorkshop = {COMPOUND_STRING("Glaswerkstatt"), FLAG_LANDMARK_GLASS_WORKSHOP};
#else
static const struct Landmark Landmark_GlassWorkshop = {COMPOUND_STRING("GLASS WORKSHOP"), FLAG_LANDMARK_GLASS_WORKSHOP};
#endif
#if GERMAN
static const struct Landmark Landmark_WeatherInstitute = {COMPOUND_STRING("Klima-Institut"), -1};
#else
static const struct Landmark Landmark_WeatherInstitute = {COMPOUND_STRING("WEATHER INSTITUTE"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_MeteorFalls = {COMPOUND_STRING("Meteorfälle"), -1};
#else
static const struct Landmark Landmark_MeteorFalls = {COMPOUND_STRING("METEOR FALLS"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_TunnelersRestHouse = {COMPOUND_STRING("Bergrasthaus"), FLAG_LANDMARK_TUNNELERS_REST_HOUSE};
#else
static const struct Landmark Landmark_TunnelersRestHouse = {COMPOUND_STRING("TUNNELER'S RESTHOUSE"), FLAG_LANDMARK_TUNNELERS_REST_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_RusturfTunnel = {COMPOUND_STRING("Metaflurtunnel"), -1};
#else
static const struct Landmark Landmark_RusturfTunnel = {COMPOUND_STRING("RUSTURF TUNNEL"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_PokemonDayCare = {COMPOUND_STRING("PokéMon-Pension"), FLAG_LANDMARK_POKEMON_DAYCARE};
#else
static const struct Landmark Landmark_PokemonDayCare = {COMPOUND_STRING("POKéMON DAY CARE"), FLAG_LANDMARK_POKEMON_DAYCARE};
#endif
#if GERMAN
static const struct Landmark Landmark_SafariZoneEntrance = {COMPOUND_STRING("Eingang Safari-Zone"), -1};
#else
static const struct Landmark Landmark_SafariZoneEntrance = {COMPOUND_STRING("SAFARI ZONE ENTRANCE"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_MtPyre = {COMPOUND_STRING("Pyroberg"), -1};
#else
static const struct Landmark Landmark_MtPyre = {COMPOUND_STRING("MT. PYRE"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_ShoalCave = {COMPOUND_STRING("Küstenhöhle"), -1};
#else
static const struct Landmark Landmark_ShoalCave = {COMPOUND_STRING("SHOAL CAVE"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_SeafloorCavern = {COMPOUND_STRING("Tiefseehöhle"), FLAG_LANDMARK_SEAFLOOR_CAVERN};
#else
static const struct Landmark Landmark_SeafloorCavern = {COMPOUND_STRING("SEAFLOOR CAVERN"), FLAG_LANDMARK_SEAFLOOR_CAVERN};
#endif
#if GERMAN
static const struct Landmark Landmark_GraniteCave = {COMPOUND_STRING("Granithöhle"), -1};
#else
static const struct Landmark Landmark_GraniteCave = {COMPOUND_STRING("GRANITE CAVE"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_OceanCurrent = {COMPOUND_STRING("Meeresströmung"), -1};
#else
static const struct Landmark Landmark_OceanCurrent = {COMPOUND_STRING("OCEAN CURRENT"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_LanettesHouse = {COMPOUND_STRING("Lanettes Haus"), FLAG_LANDMARK_LANETTES_HOUSE};
#else
static const struct Landmark Landmark_LanettesHouse = {COMPOUND_STRING("LANETTE'S HOUSE"), FLAG_LANDMARK_LANETTES_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_FieryPath = {COMPOUND_STRING("Feuriger Pfad"), FLAG_LANDMARK_FIERY_PATH};
#else
static const struct Landmark Landmark_FieryPath = {COMPOUND_STRING("FIERY PATH"), FLAG_LANDMARK_FIERY_PATH};
#endif
#if GERMAN
static const struct Landmark Landmark_JaggedPass = {COMPOUND_STRING("Steilpass"), -1};
#else
static const struct Landmark Landmark_JaggedPass = {COMPOUND_STRING("JAGGED PASS"), -1};
#endif
#if GERMAN
static const struct Landmark Landmark_BerryMastersHouse = {COMPOUND_STRING("Beerenmeister-Villa"), FLAG_LANDMARK_BERRY_MASTERS_HOUSE};
#else
static const struct Landmark Landmark_BerryMastersHouse = {COMPOUND_STRING("BERRY MASTER'S HOUSE"), FLAG_LANDMARK_BERRY_MASTERS_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_IslandCave = {COMPOUND_STRING("Inselhöhle"), FLAG_LANDMARK_ISLAND_CAVE};
#else
static const struct Landmark Landmark_IslandCave = {COMPOUND_STRING("ISLAND CAVE"), FLAG_LANDMARK_ISLAND_CAVE};
#endif
#if GERMAN
static const struct Landmark Landmark_DesertRuins = {COMPOUND_STRING("Wüstenruine"), FLAG_LANDMARK_DESERT_RUINS};
#else
static const struct Landmark Landmark_DesertRuins = {COMPOUND_STRING("DESERT RUINS"), FLAG_LANDMARK_DESERT_RUINS};
#endif
#if GERMAN
static const struct Landmark Landmark_ScorchedSlab = {COMPOUND_STRING("Sonnengrotte"), FLAG_LANDMARK_SCORCHED_SLAB};
#else
static const struct Landmark Landmark_ScorchedSlab = {COMPOUND_STRING("SCORCHED SLAB"), FLAG_LANDMARK_SCORCHED_SLAB};
#endif
#if GERMAN
static const struct Landmark Landmark_AncientTomb = {COMPOUND_STRING("Grabmal"), FLAG_LANDMARK_ANCIENT_TOMB};
#else
static const struct Landmark Landmark_AncientTomb = {COMPOUND_STRING("ANCIENT TOMB"), FLAG_LANDMARK_ANCIENT_TOMB};
#endif
#if GERMAN
static const struct Landmark Landmark_SealedChamber = {COMPOUND_STRING("Siegelkammer"), FLAG_LANDMARK_SEALED_CHAMBER};
#else
static const struct Landmark Landmark_SealedChamber = {COMPOUND_STRING("SEALED CHAMBER"), FLAG_LANDMARK_SEALED_CHAMBER};
#endif
#if GERMAN
static const struct Landmark Landmark_FossilManiacsHouse = {COMPOUND_STRING("Fossilmaniacs Haus"), FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE};
#else
static const struct Landmark Landmark_FossilManiacsHouse = {COMPOUND_STRING("FOSSIL MANIAC'S HOUSE"), FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_HuntersHouse = {COMPOUND_STRING("Haus des Tauchers"), FLAG_LANDMARK_HUNTERS_HOUSE};
#else
static const struct Landmark Landmark_HuntersHouse = {COMPOUND_STRING("HUNTER'S HOUSE"), FLAG_LANDMARK_HUNTERS_HOUSE};
#endif
#if GERMAN
static const struct Landmark Landmark_SkyPillar = {COMPOUND_STRING("Himmelturm"), FLAG_LANDMARK_SKY_PILLAR};
#else
static const struct Landmark Landmark_SkyPillar = {COMPOUND_STRING("SKY PILLAR"), FLAG_LANDMARK_SKY_PILLAR};
#endif
#if GERMAN
static const struct Landmark Landmark_MirageTower = {COMPOUND_STRING("Wunderturm"), FLAG_LANDMARK_MIRAGE_TOWER};
#else
static const struct Landmark Landmark_MirageTower = {COMPOUND_STRING("MIRAGE TOWER"), FLAG_LANDMARK_MIRAGE_TOWER};
#endif
#if GERMAN
static const struct Landmark Landmark_AlteringCave = {COMPOUND_STRING("Wandelhöhle"), FLAG_LANDMARK_ALTERING_CAVE};
#else
static const struct Landmark Landmark_AlteringCave = {COMPOUND_STRING("ALTERING CAVE"), FLAG_LANDMARK_ALTERING_CAVE};
#endif
#if GERMAN
static const struct Landmark Landmark_DesertUnderpass = {COMPOUND_STRING("Wüstentunnel"), FLAG_LANDMARK_DESERT_UNDERPASS};
#else
static const struct Landmark Landmark_DesertUnderpass = {COMPOUND_STRING("DESERT UNDERPASS"), FLAG_LANDMARK_DESERT_UNDERPASS};
#endif
#if !IS_HNS
#if GERMAN
static const struct Landmark Landmark_TrainerHill = {COMPOUND_STRING("Trainerberg"), FLAG_LANDMARK_TRAINER_HILL};
#else
static const struct Landmark Landmark_TrainerHill = {COMPOUND_STRING("TRAINER HILL"), FLAG_LANDMARK_TRAINER_HILL};
#endif
#endif

static const struct Landmark *const Landmarks_Route103_2[]  =
{
    &Landmark_AlteringCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route104_0[]  =
{
    &Landmark_FlowerShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route104_1[]  =
{
    &Landmark_PetalburgWoods,
    &Landmark_MrBrineysCottage,
    NULL,
};

static const struct Landmark *const Landmarks_Route105_0[]  =
{
    &Landmark_IslandCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route106_1[]  =
{
    &Landmark_GraniteCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route108_0[]  =
{
    &Landmark_AbandonedShip,
    NULL,
};

static const struct Landmark *const Landmarks_Route109_0[]  =
{
    &Landmark_SeashoreHouse,
    &Landmark_SlateportBeach,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_0[]  =
{
    &Landmark_CyclingRoad,
    &Landmark_NewMauville,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_1[]  =
{
    &Landmark_CyclingRoad,
    NULL,
};

static const struct Landmark *const Landmarks_Route110_2[]  =
{
    &Landmark_CyclingRoad,
    &Landmark_TrickHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_0[]  =
{
    &Landmark_OldLadysRestShop,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_1[]  =
{
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_2[]  =
{
    &Landmark_MirageTower,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_3[]  =
{
    &Landmark_DesertRuins,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route111_4[]  =
{
#if !IS_HNS
    &Landmark_TrainerHill,
#endif
    &Landmark_WinstrateFamily,
    &Landmark_Desert,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_0[]  =
{
    &Landmark_FieryPath,
    &Landmark_JaggedPass,
    NULL,
};

static const struct Landmark *const Landmarks_Route112_1[]  =
{
    &Landmark_CableCar,
    &Landmark_FieryPath,
    NULL,
};

static const struct Landmark *const Landmarks_Route113_1[]  =
{
    &Landmark_GlassWorkshop,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_1[]  =
{
    &Landmark_DesertUnderpass,
    &Landmark_FossilManiacsHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route114_2[]  =
{
    &Landmark_LanettesHouse,
    NULL,
};

static const struct Landmark *const Landmarks_MeteorFalls[]  =
{
    &Landmark_MeteorFalls,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_1[]  =
{
    &Landmark_TunnelersRestHouse,
    &Landmark_RusturfTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route116_2[]  =
{
    &Landmark_RusturfTunnel,
    NULL,
};

static const struct Landmark *const Landmarks_Route117_2[]  =
{
    &Landmark_PokemonDayCare,
    NULL,
};

static const struct Landmark *const Landmarks_Route119_1[]  =
{
    &Landmark_WeatherInstitute,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_0[]  =
{
    &Landmark_ScorchedSlab,
    NULL,
};

static const struct Landmark *const Landmarks_Route120_2[]  =
{
    &Landmark_AncientTomb,
    NULL,
};

static const struct Landmark *const Landmarks_Route121_2[]  =
{
    &Landmark_SafariZoneEntrance,
    NULL,
};

static const struct Landmark *const Landmarks_Route122_0[]  =
{
    &Landmark_MtPyre,
    NULL,
};

static const struct Landmark *const Landmarks_Route123_0[]  =
{
    &Landmark_BerryMastersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route124_7[]  =
{
    &Landmark_HuntersHouse,
    NULL,
};

static const struct Landmark *const Landmarks_Route125_2[]  =
{
    &Landmark_ShoalCave,
    NULL,
};

static const struct Landmark *const Landmarks_Route128_1[]  =
{
    &Landmark_SeafloorCavern,
    NULL,
};

static const struct Landmark *const Landmarks_Route131_1[]  =
{
    &Landmark_SkyPillar,
    NULL,
};

static const struct Landmark *const Landmarks_OceanCurrent[]  =
{
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_Route134_2[]  =
{
    &Landmark_SealedChamber,
    &Landmark_OceanCurrent,
    NULL,
};

static const struct Landmark *const Landmarks_MtChimney_2[]  =
{
    &Landmark_CableCar,
    &Landmark_JaggedPass,
    NULL,
};

static const struct LandmarkList sLandmarkLists[] =
{
    {MAPSEC_ROUTE_103, 2, Landmarks_Route103_2},
    {MAPSEC_ROUTE_104, 0, Landmarks_Route104_0},
    {MAPSEC_ROUTE_104, 1, Landmarks_Route104_1},
    {MAPSEC_ROUTE_105, 0, Landmarks_Route105_0},
    {MAPSEC_ROUTE_106, 1, Landmarks_Route106_1},
    {MAPSEC_ROUTE_108, 0, Landmarks_Route108_0},
    {MAPSEC_ROUTE_109, 0, Landmarks_Route109_0},
    {MAPSEC_ROUTE_110, 0, Landmarks_Route110_0},
    {MAPSEC_ROUTE_110, 1, Landmarks_Route110_1},
    {MAPSEC_ROUTE_110, 2, Landmarks_Route110_2},
    {MAPSEC_ROUTE_111, 0, Landmarks_Route111_0},
    {MAPSEC_ROUTE_111, 1, Landmarks_Route111_1},
    {MAPSEC_ROUTE_111, 2, Landmarks_Route111_2},
    {MAPSEC_ROUTE_111, 3, Landmarks_Route111_3},
    {MAPSEC_ROUTE_111, 4, Landmarks_Route111_4},
    {MAPSEC_ROUTE_112, 0, Landmarks_Route112_0},
    {MAPSEC_ROUTE_112, 1, Landmarks_Route112_1},
    {MAPSEC_ROUTE_113, 1, Landmarks_Route113_1},
    {MAPSEC_ROUTE_114, 1, Landmarks_Route114_1},
    {MAPSEC_ROUTE_114, 2, Landmarks_Route114_2},
    {MAPSEC_ROUTE_114, 3, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_115, 0, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_115, 1, Landmarks_MeteorFalls},
    {MAPSEC_ROUTE_116, 1, Landmarks_Route116_1},
    {MAPSEC_ROUTE_116, 2, Landmarks_Route116_2},
    {MAPSEC_ROUTE_117, 2, Landmarks_Route117_2},
    {MAPSEC_ROUTE_119, 1, Landmarks_Route119_1},
    {MAPSEC_ROUTE_120, 0, Landmarks_Route120_0},
    {MAPSEC_ROUTE_120, 2, Landmarks_Route120_2},
    {MAPSEC_ROUTE_121, 2, Landmarks_Route121_2},
    {MAPSEC_ROUTE_122, 0, Landmarks_Route122_0},
#ifdef BUGFIX
    {MAPSEC_ROUTE_122, 1, Landmarks_Route122_0},
    {MAPSEC_ROUTE_123, 0, Landmarks_Route123_0},
#else
    {MAPSEC_ROUTE_123, 0, Landmarks_Route123_0},
    {MAPSEC_ROUTE_122, 1, Landmarks_Route122_0},
#endif
    {MAPSEC_ROUTE_124, 7, Landmarks_Route124_7},
    {MAPSEC_ROUTE_125, 2, Landmarks_Route125_2},
    {MAPSEC_ROUTE_128, 1, Landmarks_Route128_1},
    {MAPSEC_ROUTE_131, 1, Landmarks_Route131_1},
    {MAPSEC_ROUTE_132, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_132, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_133, 2, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 0, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 1, Landmarks_OceanCurrent},
    {MAPSEC_ROUTE_134, 2, Landmarks_Route134_2},
    {MAPSEC_MT_CHIMNEY, 2, Landmarks_MtChimney_2},
    {MAPSEC_NONE, 0, NULL},
};

static const struct Landmark *const *GetLandmarks(mapsec_u8_t mapSection, u8 id);

const u8 *GetLandmarkName(mapsec_u8_t mapSection, u8 id, u8 count)
{
    const struct Landmark *const *landmarks = GetLandmarks(mapSection, id);

    if (!landmarks)
        return NULL;

    while (1)
    {
        const struct Landmark *landmark = *landmarks;

        if (landmark->flag == 0xFFFF || FlagGet(landmark->flag) == TRUE)
        {
            if (count == 0)
                break;
            else
                count--;
        }

        landmarks++;
        if (!*landmarks)
            return NULL;
    }

    return (*landmarks)->name;
}

static const struct Landmark *const *GetLandmarks(mapsec_u8_t mapSection, u8 id)
{
    u16 i = 0;

    for (; sLandmarkLists[i].mapSection != MAPSEC_NONE; i++)
    {
        if (sLandmarkLists[i].mapSection > mapSection)
            return NULL;
        if (sLandmarkLists[i].mapSection == mapSection)
            break;
    }

    if (sLandmarkLists[i].mapSection == MAPSEC_NONE)
        return NULL;

    for (; sLandmarkLists[i].mapSection == mapSection; i++)
    {
        if (sLandmarkLists[i].id == id)
            return sLandmarkLists[i].landmarks;
    }

    return NULL;
}
