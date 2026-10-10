
#include "raylib.h"
#include "rlgl.h"
#include "raymath.h"
#include "world.h"
#include "renderer.h"

using namespace Universe::Terrain;

int main(void)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    const int32_t screenWidth = 1280;
    const int32_t screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Micahs Village");
    Camera2D camera = {};
    camera.zoom = 1.0f;

    SetTargetFPS(60);               
    
    Universe::World world;

    while (!WindowShouldClose())    
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);
            camera.target = Vector2Add(camera.target, delta);
            camera.target.x = Clamp(camera.target.x, 0.0, Config::MAP_WIDTH * Config::TILE_SIZE + 10.0f);
            camera.target.y = Clamp(camera.target.y, 0.0, Config::MAP_HEIGHT * Config::TILE_SIZE + 10.0f);
        }

        Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            camera.offset = GetMousePosition();
            camera.target = mouseWorldPos;

            float scale = 0.2f*wheel;
            camera.zoom = Clamp(expf(logf(camera.zoom)+scale),0.1f, 50.0f);
        }
        
        BeginDrawing();

            ClearBackground(WHITE);
            Engine::Renderer::Render(world,camera);
            
        EndDrawing();
    }

    CloseWindow();  
    return 0;
}