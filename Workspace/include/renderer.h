#pragma once

#include "raylib.h"
#include "world.h"
namespace Engine
{
    class Renderer
    {
        public:

        static void init();
        static void Render(const Universe::World &world, Camera2D camera);

        private:
    };
}