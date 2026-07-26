
#include <cstdint>
namespace Universe
{
    namespace Terrain
    {
        namespace Config
        {
            constexpr int MAP_WIDTH = 1000;
            constexpr int MAP_HEIGHT = 1000;
            constexpr int TOTAL_TILES = MAP_WIDTH * MAP_HEIGHT;
        }

        enum TileType: uint8_t
        {
            GRASS, WATER, SAND
        };

        struct Tile
        {
            TileType type = TileType::GRASS;
            int32_t itemIndex = -1;
        };
    }
}

    
