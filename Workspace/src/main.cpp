
#include "raylib.h"
#include "worldData.h"
#include "world.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Micahs Village");

    SetTargetFPS(60);               
    
    Universe::World world;

    while (!WindowShouldClose())    
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            

        EndDrawing();
    }

    CloseWindow();  
    return 0;
}