#include "renderer.h"
#include "worldData.h"
#include "math.h"
#include "raylib.h"

using Universe::Terrain::Config::TILE_SIZE;

namespace Engine
{
    void Renderer::Render([[maybe_unused]]const Universe::World &world, Camera2D camera)
    {
        //const Universe::Terrain::WorldGrid &wg = world.getGrid();
        
            ClearBackground(RAYWHITE);

            Vector2 screenTopLeft = {0,0};
            Vector2 screenBottomRight = {(float)GetScreenWidth(),(float)GetScreenHeight()};
            Vector2 worldTopLeft = GetScreenToWorld2D(screenTopLeft, camera);
            Vector2 worldBottomRight = GetScreenToWorld2D(screenBottomRight, camera);

            int startX = static_cast<int>(floor(worldTopLeft.x/TILE_SIZE));
            int startY = static_cast<int>(floor(worldTopLeft.y/TILE_SIZE));
            int endX = static_cast<int>(ceil(worldBottomRight.x/TILE_SIZE));
            int endY = static_cast<int>(ceil(worldBottomRight.y/TILE_SIZE));

            BeginMode2D(camera);
                for (int y = startY; y < endY; y++)
                {   
                    for (int x = startX; x < endX; x++)
                    {
                        //Universe::Terrain::Tile tile = wg.getTile(x, y);
                        if ((x + y) % 2 == 0) DrawRectangle(x * TILE_SIZE, y* TILE_SIZE, TILE_SIZE, TILE_SIZE, GREEN);
                        else DrawRectangle(x * TILE_SIZE, y* TILE_SIZE, TILE_SIZE, TILE_SIZE, DARKGREEN);

                    }
                }
            EndMode2D();
        
    }
}