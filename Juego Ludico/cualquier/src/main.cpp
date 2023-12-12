

#include "raylib.h"
// Texture2D sub=LoadTexture("texturas\\SUB.png");
// Texture2D nave=LoadTexture("texturas\\navepix2.png");
// Texture2D car=LoadTexture("texturas\\pixel_car2.png");

// DrawTexture(sub, 190, 200,WHITE);
// DrawTexture(nave, 500,300,WHITE);
// DrawTexture(car, 800,300,WHITE);

#define JUGAR 0
#define OPCIONES 1
#define SALIR 2

#define DIFICULTAD 0
#define SONIDO 1
#define REGRESAR 2

#define NEWP 0
#define SALIRJ 1

int mainMenu(Sound seleccion);
int opMenu(int &vol, int &diflvl, Texture2D volumen, Texture2D dif, Sound seleccion, Sound barras);
int juegoMenu(Sound seleccion);

void juego(int diflvl);

int main(void)
{
    SetTargetFPS(60);

    int op, subOp, opJug;
    int diflvl = 1, vol = 3;
    const int screenWidth = 1280;
    const int screenHeight = 720;

    float scrollingBack = 0.0f;
    float scrollingBigPlanet = 0.0f;
    float scrollingFarPlanet = 0.0f;
    float scrollingRingPlanet = 0.0f;
    float scrollingSpaceStar = 0.0f;

    InitWindow(screenWidth, screenHeight, "window");
    //****************************************************** TEXTURAS ***********************************************************************
    Texture2D volumen[7];
    volumen[0] = LoadTexture("texturas\\vol0.png");
    volumen[1] = LoadTexture("texturas\\vol1.png");
    volumen[2] = LoadTexture("texturas\\vol2.png");
    volumen[3] = LoadTexture("texturas\\vol3.png");
    volumen[4] = LoadTexture("texturas\\vol4.png");
    volumen[5] = LoadTexture("texturas\\vol5.png");
    volumen[6] = LoadTexture("texturas\\vol6.png");

    Texture2D dif[3];
    dif[0] = LoadTexture("texturas\\dif1.png");
    dif[1] = LoadTexture("texturas\\dif2.png");
    dif[2] = LoadTexture("texturas\\dif3.png");

    Texture2D back = LoadTexture("texturas/parallax-space-backgound.png");
    Texture2D bigplanet = LoadTexture("texturas/parallax-space-big-planet.png");
    Texture2D farplanet = LoadTexture("texturas/parallax-space-far-planets.png");
    Texture2D ringplanet = LoadTexture("texturas/parallax-space-ring-planet.png");
    Texture2D stars = LoadTexture("texturas/parallax-space-stars.png");

    //******************************************************* AUDIOS **********************************************************************
    InitAudioDevice();
    Music musica_menu = LoadMusicStream("sonidos/musica.mp3");
    Sound barras = LoadSound("sonidos/beep.mp3");
    Sound seleccion = LoadSound("sonidos/volumen.mp3");

    //************************************************************* LOOP PRINCIPAL ****************************************************************
    while (!WindowShouldClose())
    {
        // Menu principal
        PlayMusicStream(musica_menu);
        do
        {
        menu:
            scrollingBack -= 0.01f;
            scrollingBigPlanet -= 0.025f;
            scrollingFarPlanet -= 0.05f;
            scrollingRingPlanet -= 0.055f;
            scrollingSpaceStar -= 0.01;

            if (scrollingBack <= -back.height)
                scrollingBack = 0;
            if (scrollingBigPlanet <= -bigplanet.height)
                scrollingBigPlanet = 0;
            if (scrollingFarPlanet <= -farplanet.height)
                scrollingFarPlanet = 0;
            if (scrollingRingPlanet <= -ringplanet.height)
                scrollingRingPlanet = 0;
            if (scrollingSpaceStar <= -stars.height)
                scrollingSpaceStar = 0;

            BeginDrawing();
            UpdateMusicStream(musica_menu);

            DrawTextureEx(back, (Vector2){0, scrollingBack}, 0.0f, 1.0f, WHITE);
            DrawTextureEx(back, (Vector2){0, back.height * 2 + scrollingBack}, 0.0f, 1.0f, WHITE);

            DrawTextureEx(bigplanet, (Vector2){900, scrollingBigPlanet}, 0.0f, 1.0f, WHITE);
            DrawTextureEx(bigplanet, (Vector2){900, bigplanet.height * 2 + scrollingBigPlanet}, 0.0f, 1.0f, WHITE);

            DrawTextureEx(farplanet, (Vector2){0, scrollingFarPlanet}, 0.0f, 1.0f, WHITE);
            DrawTextureEx(farplanet, (Vector2){0, farplanet.height * 2 + scrollingFarPlanet}, 0.0f, 1.0f, WHITE);

            DrawTextureEx(ringplanet, (Vector2){0, scrollingRingPlanet}, 0.0f, 1.0f, WHITE);
            DrawTextureEx(ringplanet, (Vector2){0, ringplanet.height * 2 + scrollingRingPlanet}, 0.0f, 1.0f, WHITE);

            DrawTextureEx(stars, (Vector2){0, scrollingSpaceStar}, 0.0f, 1.0f, WHITE);
            DrawTextureEx(stars, (Vector2){0, stars.height * 2 + scrollingSpaceStar}, 0.0f, 1.0f, WHITE);

            op = mainMenu(seleccion);
            EndDrawing();
        } while (op == -1);

        //******************************************** JUGAR ******************************************************************
        switch (op)
        {
        case JUGAR:
            do
            {
                BeginDrawing();
                UpdateMusicStream(musica_menu);
                scrollingBack -= 0.01f;
                scrollingBigPlanet -= 0.025f;
                scrollingFarPlanet -= 0.05f;
                scrollingRingPlanet -= 0.055f;
                scrollingSpaceStar -= 0.01;

                if (scrollingBack <= -back.height)
                    scrollingBack = 0;
                if (scrollingBigPlanet <= -bigplanet.height)
                    scrollingBigPlanet = 0;
                if (scrollingFarPlanet <= -farplanet.height)
                    scrollingFarPlanet = 0;
                if (scrollingRingPlanet <= -ringplanet.height)
                    scrollingRingPlanet = 0;
                if (scrollingSpaceStar <= -stars.height)
                    scrollingSpaceStar = 0;

                BeginDrawing();
                UpdateMusicStream(musica_menu);

                DrawTextureEx(back, (Vector2){0, scrollingBack}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(back, (Vector2){0, back.height * 2 + scrollingBack}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(bigplanet, (Vector2){900, scrollingBigPlanet}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(bigplanet, (Vector2){900, bigplanet.height * 2 + scrollingBigPlanet}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(farplanet, (Vector2){0, scrollingFarPlanet}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(farplanet, (Vector2){0, farplanet.height * 2 + scrollingFarPlanet}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(ringplanet, (Vector2){0, scrollingRingPlanet}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(ringplanet, (Vector2){0, ringplanet.height * 2 + scrollingRingPlanet}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(stars, (Vector2){0, scrollingSpaceStar}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(stars, (Vector2){0, stars.height * 2 + scrollingSpaceStar}, 0.0f, 1.0f, WHITE);

                opJug = juegoMenu(seleccion);
                EndDrawing();
            } while (opJug == -1);

            switch (opJug)
            {
            case NEWP:
                goto juegoL;
                break;
            case REGRESAR:
                UpdateMusicStream(musica_menu);
                goto menu;
                break;
            }
            break;

            //**************************** OPCIONES ******************************************************************
        case OPCIONES:
            UpdateMusicStream(musica_menu);
            do
            {
                BeginDrawing();
                UpdateMusicStream(musica_menu);
                scrollingBack -= 0.01f;
                scrollingBigPlanet -= 0.025f;
                scrollingFarPlanet -= 0.05f;
                scrollingRingPlanet -= 0.055f;
                scrollingSpaceStar -= 0.01;

                if (scrollingBack <= -back.height)
                    scrollingBack = 0;
                if (scrollingBigPlanet <= -bigplanet.height)
                    scrollingBigPlanet = 0;
                if (scrollingFarPlanet <= -farplanet.height)
                    scrollingFarPlanet = 0;
                if (scrollingRingPlanet <= -ringplanet.height)
                    scrollingRingPlanet = 0;
                if (scrollingSpaceStar <= -stars.height)
                    scrollingSpaceStar = 0;

                BeginDrawing();
                UpdateMusicStream(musica_menu);

                DrawTextureEx(back, (Vector2){0, scrollingBack}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(back, (Vector2){0, back.height * 2 + scrollingBack}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(bigplanet, (Vector2){900, scrollingBigPlanet}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(bigplanet, (Vector2){900, bigplanet.height * 2 + scrollingBigPlanet}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(farplanet, (Vector2){0, scrollingFarPlanet}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(farplanet, (Vector2){0, farplanet.height * 2 + scrollingFarPlanet}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(ringplanet, (Vector2){0, scrollingRingPlanet}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(ringplanet, (Vector2){0, ringplanet.height * 2 + scrollingRingPlanet}, 0.0f, 1.0f, WHITE);

                DrawTextureEx(stars, (Vector2){0, scrollingSpaceStar}, 0.0f, 1.0f, WHITE);
                DrawTextureEx(stars, (Vector2){0, stars.height * 2 + scrollingSpaceStar}, 0.0f, 1.0f, WHITE);
                subOp = opMenu(vol, diflvl, volumen[vol], dif[diflvl], seleccion, barras);
                EndDrawing();

            } while (subOp != -1);
            goto menu;
            break;

            //**************************** SALIR ******************************************************************
        case SALIR:
            CloseWindow();
            return 0;
            break;
        }

    juegoL:
        do
        {
            juego(diflvl);
        } while (0);

    continuar:
        do
        {
            juego(diflvl);
        } while (0);
    }

    //*********************************************************** UNLOAD ******************************************************************
    StopMusicStream(musica_menu);
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
    UnloadMusicStream(musica_menu);
    UnloadSound(seleccion);
    CloseAudioDevice();
    CloseWindow();
    //*****************************************************************************************************************************

    return 0;
}

int mainMenu(Sound seleccion)
{
    static int op = 0;
    int sizeTxt[3], j;
    int fontSize[2] = {70, 40};

    char mensajes[4][30] = {"JUGAR", "OPCIONES", "SALIR", "MECANICO ARITMETICO"};
    Rectangle fondo[4];

    fondo[3] = {170, 45, 927, 90};
    DrawRectangleRec(fondo[3], GetColor(0x03D1339));
    DrawText(mensajes[3], 200, 55, 70, WHITE);

    fondo[0] = {500, 293, 200, 50};
    DrawRectangleRec(fondo[0], GetColor(0x03D1339));
    DrawText(mensajes[0], 535, 300, 40, WHITE);

    fondo[1] = {500, 440, 200, 50};
    DrawRectangleRec(fondo[1], GetColor(0x03D1339));
    DrawText(mensajes[1], 507, 450, 37, WHITE);

    fondo[2] = {500, 590, 200, 50};
    DrawRectangleRec(fondo[2], GetColor(0x03D1339));
    DrawText(mensajes[2], 535, 598, 40, WHITE);

    for (j = 0; j < 3; j++)
    {
        if (j == op)
        {
            DrawRectangleRec(fondo[j], GetColor(0x0CB4C11));
            if (j == 0)
            {
                DrawText(mensajes[0], 535, 300, 40, WHITE);
            }
            if (j == 1)
            {
                DrawText(mensajes[1], 507, 450, 37, WHITE);
            }
            if (j == 2)
            {
                DrawText(mensajes[2], 535, 598, 40, WHITE);
            }
        }
        else
        {
            DrawRectangleRec(fondo[j], GetColor(0x03D1339));
            if (j == 0)
            {
                DrawText(mensajes[0], 535, 300, 40, WHITE);
            }
            if (j == 1)
            {
                DrawText(mensajes[1], 507, 450, 37, WHITE);
            }
            if (j == 2)
            {
                DrawText(mensajes[2], 535, 598, 40, WHITE);
            }
        }
    }

    if (IsKeyPressed(KEY_UP))
    {
        if (op != JUGAR)
        {
            op--;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_DOWN))
        {
            if (op != SALIR)
            {
                op++;
            }
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        PlaySound(seleccion);
        return op;
    }

    return -1;
}

int opMenu(int &vol, int &diflvl, Texture2D volumen, Texture2D dif, Sound seleccion, Sound barras)
{
    static int op = 0;
    int sizeTxt[3], j;
    for (j = 0; j < 3; j++)
    {
        if (j == op)
        {
            sizeTxt[j] = 60;
        }
        else
        {
            sizeTxt[j] = 40;
        }
    }

    char mensajes[4][30] = {"DIFICULTAD", "SONIDO", "REGRESAR", "OPCIONES"};
    Rectangle fondo[4];

    fondo[3] = {170, 45, 927, 90};
    DrawRectangleRec(fondo[3], GetColor(0x03D1339));
    DrawText(mensajes[3], 432, 55, 70, WHITE);

    fondo[0] = {500, 293, 200, 50};
    DrawRectangleRec(fondo[0], GetColor(0x03D1339));
    DrawText(mensajes[0], 476, 300, 40, WHITE);

    fondo[1] = {500, 440, 200, 50};
    DrawRectangleRec(fondo[1], GetColor(0x03D1339));
    DrawText(mensajes[1], 529, 450, 37, WHITE);

    fondo[2] = {500, 590, 200, 50};
    DrawRectangleRec(fondo[2], GetColor(0x03D1339));
    DrawText(mensajes[2], 490, 598, 40, WHITE);

    for (j = 0; j < 3; j++)
    {
        if (j == op)
        {
            DrawRectangleRec(fondo[j], GetColor(0x0CB4C11));
            if (j == 0)
            {
                DrawText(mensajes[0], 476, 300, 40, WHITE);
            }
            if (j == 1)
            {
                DrawText(mensajes[1], 529, 450, 37, WHITE);
            }
            if (j == 2)
            {
                DrawText(mensajes[2], 490, 598, 40, WHITE);
            }
        }
        else
        {
            DrawRectangleRec(fondo[j], GetColor(0x03D1339));
            if (j == 0)
            {
                DrawText(mensajes[0], 476, 300, 40, WHITE);
            }
            if (j == 1)
            {
                DrawText(mensajes[1], 529, 450, 37, WHITE);
            }
            if (j == 2)
            {
                DrawText(mensajes[2], 490, 598, 40, WHITE);
            }
        }
    }

    switch (op)
    {
    case DIFICULTAD:
        DrawTexture(dif, 520, -125 + 100, WHITE);

        if (IsKeyPressed(KEY_LEFT))
        {
            if (diflvl != 0)
            {
                diflvl--;
                PlaySound(barras);
            }
        }
        else
        {
            if (IsKeyPressed(KEY_RIGHT))
            {
                if (diflvl != 2)
                {
                    diflvl++;
                    PlaySound(barras);
                }
            }
        }

        switch (diflvl)
        {
        case 0:
            DrawText("FACIL", 862, 100 + 150, 40, WHITE);
            break;
        case 1:
            DrawText("NORMAL", 853, 100 + 150, 40, WHITE);
            break;
        case 2:
            DrawText("DIFICL", 856, 100 + 150, 40, WHITE);
            break;
        }

        break;

    case SONIDO:
        DrawTexture(volumen, 485, 25 + 100, WHITE);

        if (IsKeyPressed(KEY_LEFT))
        {
            if (vol != 0)
            {
                vol--;
                PlaySound(barras);
            }
        }
        else
        {
            if (IsKeyPressed(KEY_RIGHT))
            {
                if (vol != 6)
                {
                    vol++;
                    PlaySound(barras);
                }
            }
        }

        break;

    case REGRESAR:
        if (IsKeyPressed(KEY_ENTER))
        {
            PlaySound(seleccion);
            return -1;
        }
        break;
    }

    if (IsKeyPressed(KEY_UP))
    {
        if (op != DIFICULTAD)
        {
            op--;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_DOWN))
        {
            if (op != REGRESAR)
            {
                op++;
            }
        }
    }

    return op;
}

int juegoMenu(Sound seleccion)
{
    static int op = 0;
    int sizeTxt[3], j;

    char mensajes[3][30] = {"NUEVA PARTIDA", "REGRESAR", "MECANICO ARITMETICO"};
    Rectangle fondo[3];

    fondo[2] = {170, 45, 927, 90};
    DrawRectangleRec(fondo[2], GetColor(0x03D1339));
    DrawText(mensajes[2], 200, 55, 70, WHITE);

    fondo[0] = {500, 293, 200, 50};
    DrawRectangleRec(fondo[0], GetColor(0x03D1339));
    DrawText(mensajes[0], 420, 300, 40, WHITE);

    fondo[1] = {500, 440, 200, 50};
    DrawRectangleRec(fondo[1], GetColor(0x03D1339));
    DrawText(mensajes[1], 490, 450, 40, WHITE);

    for (j = 0; j < 2; j++)
    {
        if (j == op)
        {
            DrawRectangleRec(fondo[j], GetColor(0x0CB4C11));
            if (j == 0)
            {
                DrawText(mensajes[0], 420, 300, 40, WHITE);
            }
            if (j == 1)
            {
                DrawText(mensajes[1], 490, 450, 40, WHITE);
            }
        }
        else
        {
            DrawRectangleRec(fondo[j], GetColor(0x03D1339));
            if (j == 0)
            {
                DrawText(mensajes[0], 420, 300, 40, WHITE);
            }
            if (j == 1)
            {
                DrawText(mensajes[1], 490, 450, 40, WHITE);
            }
        }
    }

    if (IsKeyPressed(KEY_UP))
    {
        if (op != NEWP)
        {
            op--;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_DOWN))
        {
            if (op != SALIRJ)
            {
                op++;
            }
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        PlaySound(seleccion);
        return op;
    }

    return -1;
}

void juego(int diflvl)
{
}