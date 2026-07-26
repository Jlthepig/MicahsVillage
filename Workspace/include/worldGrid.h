
#include "worldData.h"
#include <vector>

namespace Universe
{
    namespace Terrain
    {
        class WorldGrid
        {
            public:
            WorldGrid();

            bool checkWorldBoundry(int x, int y);
            Tile& getTile(int x, int y);
            private:
            inline size_t coordToIndex(int x, int y);
            std::vector<Tile> Grid;
            static Tile errorTile;
        };

    }
}