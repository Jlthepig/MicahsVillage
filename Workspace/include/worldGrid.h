#pragma once

#include "worldData.h"
#include <span>
#include <vector>

namespace Universe
{
    namespace Terrain
    {
        class WorldGrid
        {
            public:
            WorldGrid();
            constexpr bool checkWorldBoundary(int x, int y) const;
            const Tile& getTile(int x, int y) const;

            void generateBasicTerrain();
            

            private:
            size_t coordToIndex(int x, int y) const;
            float interpolateSmoothNoise(float t);
            void fillWithSmoothNoise(std::span<float> values, int mapWidth, int mapHeight);
            float next_float(unsigned long& state);
            std::vector<Tile> Grid;
        };

    }
}