#include "worldGrid.h"
#include <cassert>
#include <span>
namespace Universe
{
    namespace Terrain
    {
        WorldGrid::WorldGrid()
        {
            Grid.resize(Config::TOTAL_TILES);
            generateBasicTerrain();
        }

        void WorldGrid::generateBasicTerrain()
        {
            std::vector<float> values(Config::TOTAL_TILES);
            fillWithSmoothNoise(values, Config::MAP_WIDTH, Config::MAP_HEIGHT);

            for (int y = 0; y < Config::MAP_HEIGHT; y++)
            {
                for (int x = 0; x < Config::MAP_WIDTH; x++)
                {
                    size_t index = coordToIndex(x, y);
                    bool isBorder = (x == 0)|| (x == Config::MAP_WIDTH -1) || (y == 0) || (y == Config::MAP_HEIGHT -1);
                    if (isBorder)
                    {
                        Grid[index].type = SAND;
                    }
                    else
                    {
                        if (values[index] < 0.2f) Grid[index].type = WATER;
                        else if (values[index] < 0.3f) Grid[index].type = SAND;
                        else Grid[index].type = GRASS;
                    }
                }
            }

        }

        void WorldGrid::fillWithSmoothNoise(std::span<float> values, int mapWidth, int mapHeight)
        {
            
            size_t seedsX = static_cast<size_t>((mapWidth / Config::CELL_SIZE) + 1);
            size_t seedsY = static_cast<size_t>((mapHeight / Config::CELL_SIZE) + 1);
            std::vector<float> seeds(seedsX * seedsY);
            unsigned long rngState = 12345;
            for (size_t sy =0; sy < seedsY; sy++)
            {
                for (size_t sx = 0; sx < seedsX; sx++)
                {
                    seeds[sy * seedsX + sx] = next_float(rngState);
                }
            }

            for (int y = 0; y < mapHeight; y++)
            {
                for (int x = 0; x < mapWidth; x++)
                {
                    size_t seedX0 = static_cast<size_t>(x / Config::CELL_SIZE);
                    size_t seedY0 = static_cast<size_t>(y / Config::CELL_SIZE);
                    size_t seedX1 = seedX0 +1;
                    size_t seedY1 = seedY0 + 1;

                    float blendX = static_cast<float>((x % Config::CELL_SIZE)) / static_cast<float>(Config::CELL_SIZE);
                    float blendY = static_cast<float>((y % Config::CELL_SIZE)) / static_cast<float>(Config::CELL_SIZE);

                    // interpolation weights
                    float fx = interpolateSmoothNoise(blendX);
                    float fy = interpolateSmoothNoise(blendY);

                    // fetch corner seeds
                    float seed00 = seeds[seedY0 * seedsX + seedX0]; // this is top left
                    float seed10 = seeds[seedY0 * seedsX + seedX1]; // this is top right
                    float seed01 = seeds[seedY1 * seedsX + seedX0]; // this is bottom left
                    float seed11 = seeds[seedY1 * seedsX + seedX1]; // this is bottom right

                    // Bilinear interpolation
                    float topInterpolation = seed00 + fx * (seed10 - seed00);
                    float bottomInterpolation = seed01 + fx * (seed11 - seed01);
                    float finalisedNoise = topInterpolation + fy * (bottomInterpolation - topInterpolation);

                    size_t index = static_cast<size_t>(y) * static_cast<size_t>(mapWidth) + static_cast<size_t>(x);
                    values[index] = finalisedNoise;
                }
            }

        }

        inline float WorldGrid::next_float(unsigned long& state)
        {
            state = (1103515245 * state + 12345) % 2147483648;
            return (float)state / 2147483648.0f;
        }

        inline float WorldGrid::interpolateSmoothNoise(float t)
        {
            return t*t*(3-2*t);
        }
        
        inline size_t WorldGrid::coordToIndex(int x, int y) const 
        {
            return (static_cast<size_t>(y) * Config::MAP_WIDTH) + static_cast<size_t>(x);
        }

        constexpr bool WorldGrid::checkWorldBoundary(int x, int y) const
        {
            if (x >=0 && x < Config::MAP_WIDTH && y >=0 && y < Config::MAP_HEIGHT)
            {
                return true;
            }
            return false;
        }

        const Tile& WorldGrid::getTile(int x, int y) const
        {
            assert(checkWorldBoundary(x, y) && "WorldGrid::getTile: coordinates out of bounds");
            return Grid[coordToIndex(x, y)];
        }
    }
    
}