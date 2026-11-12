#pragma once

#include "raylib.h"
#include "world.h"
namespace Engine
{
    class Renderer
    {
        public:

        static void init();
        static void Render(const Universe::World &world, const Camera2D &camera);

        private:
    };
}