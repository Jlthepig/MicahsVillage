#pragma once
#include <cstdint>
namespace Universe
{
    namespace Terrain
    {
        namespace Config
        {
            constexpr int MAP_WIDTH = 64;
            constexpr int MAP_HEIGHT = 64;
            constexpr int TILE_SIZE = 32;
            constexpr int CELL_SIZE = 16;
            constexpr int TOTAL_TILES = MAP_WIDTH * MAP_HEIGHT;
        }

        struct ItemHandle
        {
            uint32_t index = 0;
            uint32_t generation = 0;

            friend bool operator==(ItemHandle, ItemHandle) = default;
            [[nodiscard]] bool valid() const noexcept { return generation !=0; }

        };

        enum TileType: uint8_t
        {
            GRASS = 0, WATER = 0, SAND = 0
        };

        struct Tile
        {
            TileType type = TileType::GRASS;
            ItemHandle item;
        };
    }
}

    
