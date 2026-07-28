#pragma once

#include "worldGrid.h"

namespace Universe
{
    class World
    {
        public:
            World();

            void update();

            Terrain::WorldGrid& getGrid();
        private:
            Terrain::WorldGrid grid;
    };
}