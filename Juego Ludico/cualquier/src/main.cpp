#include "raylib.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen
{
    MENU = 0,
    OPCIONES,
    GAMEPLAY
} GameScreen;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic screen manager");

    GameScreen currentScreen = MENU;

    // TODO: Initialize all required variables and load all required data here!

    int framesCounter = 0; // Useful to count frames

    Texture2D volumen[7];
    Texture2D dif[3];
    Texture2D fondo = LoadTexture("texturas\\menuok.png");
    volumen[0] = LoadTexture("texturas\\vol0.png");
    volumen[1] = LoadTexture("texturas\\vol1.png");
    volumen[2] = LoadTexture("texturas\\vol2.png");
    volumen[3] = LoadTexture("texturas\\vol3.png");
    volumen[4] = LoadTexture("texturas\\vol4.png");
    volumen[5] = LoadTexture("texturas\\vol5.png");
    volumen[6] = LoadTexture("texturas\\vol6.png");
    dif[0] = LoadTexture("texturas\\dif1.png");
    dif[1] = LoadTexture("texturas\\dif2.png");
    dif[2] = LoadTexture("texturas\\dif3.png");

    SetTargetFPS(60); // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
        case MENU:
        {
            // Press enter to change to GAMEPLAY screen
            if (IsKeyPressed(KEY_DOWN))
            {
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = OPCIONES;
                }
                
                if (IsKeyPressed(KEY_DOWN))
                {
                    if (IsKeyPressed(KEY_ENTER))
                    {
                        CloseWindow();
                    }
                }
            }
        }
        break;
        case OPCIONES:
        {
            // Press enter to change to GAMEPLAY screen
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = OPCIONES;
            }
        }
        break;
        case GAMEPLAY:
        {
            // TODO: Update GAMEPLAY screen variables here!

            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = MENU;
            }
        }
        break;
        default:
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        switch (currentScreen)
        {
        case MENU:
        {
            // TODO: Draw LOGO screen here!
            DrawTexture(fondo, 0, 0, WHITE);
            DrawText("Mecánico Aritmético", 265, 65, 70, WHITE);
            DrawText("Jugar", 510, 200, 60, WHITE);
            DrawText("Opciones", 510, 300, 40, WHITE);
            DrawText("Salir", 510, 400, 40, WHITE);
        }
        break;
        case OPCIONES:
        {
            // TODO: Draw TITLE screen here!
            DrawTexture(fondo, 0, 0, WHITE);
            DrawText("Opciones", 450, 65, 70, WHITE);
            DrawText("Dificultad", 510, 200, 60, WHITE);
            DrawText("Sonido", 510, 350, 40, WHITE);
            DrawText("Regresar", 510, 500, 40, WHITE);
        }
        break;
        case GAMEPLAY:
        {
            // TODO: Draw GAMEPLAY screen here!
            DrawTexture(fondo, 0, 0, WHITE);
            DrawText("PROXIMAMENTE", 450, 65, 70, WHITE);
        }
        break;
        default:
            break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!
    UnloadTexture(fondo);
    UnloadTexture(volumen[0]);
    UnloadTexture(volumen[1]);
    UnloadTexture(volumen[2]);
    UnloadTexture(volumen[3]);
    UnloadTexture(volumen[4]);
    UnloadTexture(volumen[5]);
    UnloadTexture(volumen[6]);
    UnloadTexture(dif[0]);
    UnloadTexture(dif[1]);
    UnloadTexture(dif[2]);
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}