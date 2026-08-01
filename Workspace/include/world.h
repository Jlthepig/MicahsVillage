#pragma once

#include "worldGrid.h"

namespace Universe
{
    class World
    {
        public:
            World();

            void update();

            const Terrain::WorldGrid& getGrid() const;
        private:
            Terrain::WorldGrid grid;
    };
}