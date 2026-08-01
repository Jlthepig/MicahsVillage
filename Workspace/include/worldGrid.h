
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

            bool checkWorldBoundry(int x, int y) const;
            const Tile& getTile(int x, int y) const;
            private:
            inline size_t coordToIndex(int x, int y) const;
            std::vector<Tile> Grid;
            static Tile errorTile;
        };

    }
}