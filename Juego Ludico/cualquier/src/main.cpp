#include "raylib.h"
#define JUGAR 0
#define OPCIONES 1
#define SALIR 2

void menu(void);

int main(void)
{
    int optionmenu=0;
    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "window");
    SetTargetFPS(60);        
    Texture2D menu=LoadTexture("texturas\\menuok.png");
    Texture2D car=LoadTexture("texturas\\pixel_car2.png");
    Texture2D car2=LoadTexture("texturas\\pixel_car.png");
    Texture2D sub=LoadTexture("texturas\\SUB.png");
    while (!WindowShouldClose()) 
    {
       
        if(!IsWindowFullscreen())
        {
            ToggleFullscreen();
        }

        BeginDrawing();

        
        DrawTexture(menu,0,0,WHITE);

        if(IsKeyPressed(KEY_UP))
        {
            switch(optionmenu)
            {
                case OPCIONES:
                    optionmenu=JUGAR;
                    break;
                case SALIR:
                    optionmenu=OPCIONES;
                    break;
            }
        }
        else
        {
            if(IsKeyPressed(KEY_DOWN))
            {
                switch(optionmenu)
                {
                    case JUGAR:
                        optionmenu=OPCIONES;
                        break;
                    case OPCIONES:
                        optionmenu=SALIR;
                        break;
                }
            }
        }

        DrawTexture(car, 800,300,WHITE);
        DrawTexture(sub, 190, 200,WHITE);
        DrawTexture(car2, 800, 100,WHITE);
        switch(optionmenu)
        {
            case JUGAR:
                DrawText("Mecánico Aritmético",400,70,50,WHITE);
                DrawText("Jugar",510,200,60,WHITE);
                DrawText("Opciones",510,300,40,WHITE);
                DrawText("Salir",510,400,40,WHITE);
                break;
            case OPCIONES:
                DrawText("Mecánico Aritmético",400,70,50,WHITE);
                DrawText("Jugar",510,200,40,WHITE);
                DrawText("Opciones",510,300,60,WHITE);
                DrawText("Salir",510,400,40,WHITE);
                break;
            case SALIR:
                DrawText("Mecánico Aritmético",400,70,50,WHITE);
                DrawText("Jugar",510,200,40,WHITE);
                DrawText("Opciones",510,300,40,WHITE);
                DrawText("Salir",510,400,60,WHITE);
                break;
        }
        //Original
        //DrawText("Mecánico Aritmético",400,70,50,WHITE);
        //DrawText("Jugar",510,200,40,WHITE);
        //DrawText("Opciones",510,300,40,WHITE);
        //DrawText("Salir",510,400,40,WHITE);
        
        EndDrawing();
    }
    CloseWindow();       

    return 0;
}