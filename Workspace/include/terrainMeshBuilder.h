#pragma once
#include "raymath.h"
#include "rlgl.h"
#include "world.h"

namespace Universe::Terrain
{
    struct Vertex
    {
        Vector2 pos = {0,0};

    };

    class TerrainMeshBuilder
    {
        public:

        void buildVertexBuffer();
        

        private:
        unsigned int vbo = 0;


    };
}