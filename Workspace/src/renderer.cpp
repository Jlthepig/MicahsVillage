#include <algorithm>
#include <cmath>

#include "raylib.h"

#include "renderer.h"
#include "worldData.h"


using namespace Universe::Terrain;
namespace Engine
{
    void Renderer::Render(const Universe::World &world, const Camera2D &camera)
    {
            const Universe::Terrain::WorldGrid &wg = world.getGrid();
        
            ClearBackground(RAYWHITE);

            BeginMode2D(camera);
                const Vector2 viewMin = GetScreenToWorld2D({0.0f, 0.0f}, camera);
                const Vector2 viewMax = GetScreenToWorld2D({static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())}, camera);

                DrawRectangleV(viewMin, {viewMax.x - viewMin.x, viewMax.y - viewMin.y}, BLUE);

                const int startX = std::max(0, static_cast<int>(std::floor(viewMin.x / Config::TILE_SIZE)));
                const int startY = std::max(0, static_cast<int>(std::floor(viewMin.y / Config::TILE_SIZE)));
                const int endX = std::min(Config::MAP_WIDTH, static_cast<int>(viewMax.x / Config::TILE_SIZE));
                const int endY = std::min(Config::MAP_HEIGHT, static_cast<int>(viewMax.y / Config::TILE_SIZE));

                for (int y = startY; y < endY; y++)
                {   
                    for (int x = startX; x < endX; x++)
                    {
                       const Universe::Terrain::Tile &tile = wg.getTile(x, y);
                        switch (tile.type)
                        {

                        case Universe::Terrain::GRASS:
                            DrawRectangle(x * Config::TILE_SIZE, y* Config::TILE_SIZE, Config::TILE_SIZE, Config::TILE_SIZE, GREEN);
                            break;
                        case Universe::Terrain::WATER:
                            DrawRectangle(x * Config::TILE_SIZE, y* Config::TILE_SIZE, Config::TILE_SIZE, Config::TILE_SIZE, BLUE);
                            break;
                        case Universe::Terrain::SAND:
                            DrawRectangle(x * Config::TILE_SIZE, y* Config::TILE_SIZE, Config::TILE_SIZE, Config::TILE_SIZE, BEIGE);
                            break;
                        }
                    }
                }
            EndMode2D();
        
    }
}