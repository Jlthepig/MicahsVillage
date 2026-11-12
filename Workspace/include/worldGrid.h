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
            bool checkWorldBoundry(int x, int y) const;
            const Tile& getTile(int x, int y) const;

            void generateBasicTerrain();
            void fillWithSmoothNoise(std::span<float> values, int mapWidth, int mapHeight);

            private:
            inline size_t coordToIndex(int x, int y) const;
            inline float interpolateSmoothNoise(float t);
            inline float next_float(unsigned long& state);
            std::vector<Tile> Grid;
            static Tile errorTile;
        };

    }
}