
#include "raylib.h"

int main()
{
    Texture2D sprite;
    InitWindow(800, 400, "basurita");
    sprite = LoadTexture("elefante.png");
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Funciona por favor", 100, 100, 15, BLACK);
        DrawCircle(400, 200, 50, BLACK);
        DrawTexture(sprite, 10, 10, WHITE);
        EndDrawing();
    }
}