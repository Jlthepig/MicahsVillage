#include "worldGrid.h"

namespace Universe
{
    namespace Terrain
    {
        Tile WorldGrid::errorTile = { TileType::WATER, -1 }; 

        WorldGrid::WorldGrid()
        {
            Grid.resize(Config::TOTAL_TILES);
        }
        
        size_t WorldGrid::coordToIndex(int x, int y) const 
        {
            return (static_cast<size_t>(y) * Config::MAP_WIDTH) + static_cast<size_t>(x);
        }

        bool WorldGrid::checkWorldBoundry(int x, int y) const
        {
            if (x >=0 && x < Config::MAP_WIDTH && y >=0 && y < Config::MAP_HEIGHT)
            {
                return true;
            }
            return false;
        }

        const Tile& WorldGrid::getTile(int x, int y) const 
        {
            if (checkWorldBoundry(x, y))
            {
                size_t index = coordToIndex(x,y);
                return Grid[index];
            } 
            return errorTile;
        }
    }
    
}