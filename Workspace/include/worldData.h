#pragma once
#include <cstdint>
namespace Universe
{
    namespace Terrain
    {
        namespace Config
        {
            constexpr int MAP_WIDTH = 100;
            constexpr int MAP_HEIGHT = 100;
            constexpr int TOTAL_TILES = MAP_WIDTH * MAP_HEIGHT;
        }

        enum TileType: uint8_t
        {
            GRASS, WATER, SAND
        };

        struct Tile
        {
            TileType type = TileType::GRASS;
            int8_t width = 32;
            int8_t height = 32;
            int32_t itemIndex = -1;
        };
    }
}

    
