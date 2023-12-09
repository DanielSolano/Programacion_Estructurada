#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANCHO 1280
#define RALTO 720
#define CAMY 360
#define CAMX 640

#define ALTOP 85
#define ANCHOP 50
#define SUELO 650

#define G 0.1
#define GD 0.2

#define VX 4
#define VS -11
#define VD 10

#define MAXAVE 5
#define AVESPEED 7
#define MAXEGG 8
#define MAXCAR 2
#define CARSPEED 9

#define MAXPLAT 30

// blank transparente

// typedef Rectangle Tplayer;

typedef Rectangle Thit;

typedef Rectangle Trec;

typedef struct _plataforma
{
    Trec pos;
    int status;
    int flag;
} Tplat;

typedef struct _vehiculo
{
    Trec pos;
    int status;

} Tpart;

typedef struct _jugador
{
    Trec pos;
    int y0;
    float v0;
    int timeDash;
    int jump;
    int jumpjump;
    int fall;
} Tplayer;

typedef struct _ave
{
    Trec pos;
    int status = 0;
    int right = 0;
    int left = 0;

} Tave;

typedef struct _huevo
{
    Trec pos;
    int status;
    int y0;
    int time;
} Tegg;

typedef struct _car
{
    Trec pos;
    int status;
    int movimiento;
    int time;
} Tcar;

float velocidad(float v0, float time);
int ColisionPlat(Tplayer player, Tplat plat);
// devuelve 0
int Reposo(float &time, float &v0, int &y0, int y);

int Salto(float &time, float &v0, int &y0, int y);

// y0+v0*time+GD*time*time;
int Posicion(int y0, float v0, float time, int g);

void CalculaPosEnemigo(Tave &mob);
int CheckMobColision(Trec mob, Thit hit);
int CheckPlayerColision(Trec player, Trec mob);
// int CheckPiezaColision(Trec player,Trec mob); // duplicado para probar sin daño
void DropEgg(Tave mob, Tegg &egg);
void LimpiaEnemigos(Tave ave[], Tcar car[]);

int main()
{
    SetTargetFPS(60);
    InitWindow(RANCHO, RALTO, "juego");
    srand(time(NULL));
    int j, i;
    int y0Cam;

    int framesAutom = 0;

    int framesSpeed = 8;
    int currentFrame = 0;

    int currentPersonaje = 0;
    int framesPersonaje = 0;

    int currentSalto = 0;
    int framesSalto = 0;

    // contadores
    int frameC = 0;
    float time = 0;
    int c = 0;
    int igncolision = 0;
    int hitc = 0;
    int platc = 0;
    // int caminarc=0;

    // banderas
    int bsuelo = 0;
    int bdown = 0;
    // int caminar=0;
    int lookR = 1;
    int lookL = 0;
    int lookUp = 0;
    int lookDown = 0;
    int hit = 0;
    int dash = 0;

    // auxiliar
    int random;

    // ************************************************ TEXTURAS ********************************************************************
    Texture2D pajaro = LoadTexture("texturas/pajaro.png");
    Rectangle framesPajaro = {0.0f, 0.0f, (float)pajaro.width / 6, (float)pajaro.height};

    Texture2D pajaroizq = LoadTexture("texturas/pajaroizq.png");
    Rectangle framesPajaroizq = {0.0f, 0.0f, (float)pajaroizq.width / 6, (float)pajaroizq.height};

    Texture2D huevo = LoadTexture("texturas/egg.png");
    Rectangle framesHuevo = {0.0f, 0.0f, (float)huevo.width, (float)huevo.height};

    Texture2D carro = LoadTexture("texturas/Ranger.png");
    Rectangle framesCarro = {0.0f, 0.0f, (float)carro.width, (float)carro.height};

    Texture2D carro2 = LoadTexture("texturas/Ranger.png");
    Rectangle framesCarro2 = {0.0f, 0.0f, (float)carro2.width, (float)carro2.height};

    Texture2D caminar = LoadTexture("texturas/Cyborg_run.png");
    Rectangle framesCaminar = {0.0f, 0.0f, (float)caminar.width / 6, (float)caminar.height};

    Texture2D caminarizq = LoadTexture("texturas/Cyborg_run_left.png");
    Rectangle framesCaminarizq = {0.0f, 0.0f, (float)caminarizq.width / 6, (float)caminarizq.height};

    Texture2D reposo = LoadTexture("texturas/Cyborg_idle.png");
    Rectangle framesReposo = {0.0f, 0.0f, (float)reposo.width / 4, (float)reposo.height};

    Texture2D reposoizq = LoadTexture("texturas/Cyborg_idle_left.png");
    Rectangle framesReposoizq = {0.0f, 0.0f, (float)reposoizq.width / 4, (float)reposoizq.height};

    Texture2D danio = LoadTexture("texturas/Cyborg_hurt.png");
    Rectangle framesDanio = {0.0f, 0.0f, (float)danio.width, (float)danio.height};

    Texture2D salto = LoadTexture("texturas/Cyborg_jump.png");
    Rectangle frameSalto = {0.0f, 0.0f, (float)salto.width / 4, (float)salto.height};

    Texture2D saltoder = LoadTexture("texturas/Cyborg_jumpr.png");
    Rectangle frameSaltoder = {0.0f, 0.0f, (float)saltoder.width / 4, (float)saltoder.height};

    Texture2D background = LoadTexture("texturas/fondo1.png");
    Rectangle frameBackground = {0.0f, 0.0f, (float)RANCHO, (float)RALTO};

    Texture2D ground = LoadTexture("texturas/ground.png");
    Rectangle frameGround = {0.0f, 0.0f, (float)ground.width, (float)ground.height};

    Texture2D back = LoadTexture("texturas/back1.png");
    Texture2D middle = LoadTexture("texturas/middle.png");
    Texture2D front = LoadTexture("texturas/front.png");

    Texture2D plataforma = LoadTexture("texturas/plataforma1.png");

    Texture2D piezas[3];
    Rectangle framePiezas[3] = {0.0f, 0.0f, (float)ground.width, (float)ground.height};

    piezas[0] = LoadTexture("texturas/pieza1.png");
    piezas[1] = LoadTexture("texturas/pieza2.png");
    piezas[3] = LoadTexture("texturas/pieza3.png");

    framePiezas[0] = {0.0f, 0.0f, (float)piezas[0].width, (float)piezas[0].height};
    framePiezas[1] = {0.0f, 0.0f, (float)piezas[1].width, (float)piezas[1].height};
    framePiezas[2] = {0.0f, 0.0f, (float)piezas[2].width, (float)piezas[2].height};

    // ************************************************ SONIDOS ********************************************************************

    InitAudioDevice();

    Sound dolor = LoadSound("sonidos/danio.wav");

    // Inicializacion ***************************************************************************************
    // Inicializacion Plataformas
    Tplat plat[MAXPLAT];
    plat[0].pos.x = 400;
    plat[0].status = 1;
    plat[0].flag = 0;
    plat[0].pos.width = 350;
    plat[0].pos.height = 40;
    plat[0].pos.y = (rand() % 300) + 200;
    for (j = 1; j < MAXPLAT; j++)
    {
        if (plat[j - 1].pos.x < -7200)
        {
            for (i = j + 1; i < MAXPLAT; i++)
            {
                plat[i].status = 0;
                plat[i].flag = 0;
                plat[i].pos.width = 0;
                plat[i].pos.height = 0;
                plat[i].pos.y = 0;
                plat[i].pos.x = 0;
            }
            j = MAXPLAT;
        }
        else
        {
            plat[j].status = 1;
            plat[j].flag = 0;
            plat[j].pos.width = 350;
            plat[j].pos.height = 40;
            plat[j].pos.y = (rand() % 250) + 200;
            plat[j].pos.x = plat[j - 1].pos.x - plat[j].pos.width - ((rand() % 200) + 50);
            platc++;
        }
    }

    // Inicializacion piezas
    Tpart pieza[3];
    int piezac = 0;
    random = (platc) / 3;
    for (j = 0; j < 3; j++)
    {
        pieza[j].status = 1;
        pieza[j].pos.height = 80;
        pieza[j].pos.width = 50;
        pieza[j].status = 1;
        if (j == 0)
        {
            pieza[j].pos.y = plat[platc - 1].pos.y - pieza[j].pos.height;
            pieza[j].pos.x = plat[platc - 1].pos.x + plat[platc].pos.width / 2;
        }
        else
        {
            pieza[j].pos.y = plat[platc - random * j].pos.y - pieza[j].pos.height;
            pieza[j].pos.x = plat[platc - random * j].pos.x + plat[platc - random * j].pos.width / 2;
        }
    }

    // Inicializa la posicion
    Tplayer player;
    player.pos.height = ALTOP;
    player.pos.width = ANCHOP;
    player.pos.x = 400;   // Posicion incial
    player.pos.y = SUELO; //""
    player.y0 = player.pos.y;
    player.v0 = 0;
    player.timeDash = 70;

    // Inicializacion enemigos
    Tave ave[MAXAVE];
    for (j = 0; j < MAXAVE; j++)
    {
        ave[j].status = 0;
        ave[j].right = 0;
        ave[j].left = 0;
        ave[j].pos.x = 2000;
        ave[j].pos.y = 800;
        ave[j].pos.height = 20;
        ave[j].pos.width = 40;
    }

    Tegg egg[MAXEGG];
    for (j = 0; j < MAXEGG; j++)
    {
        egg[j].status = 0;
        egg[j].pos.height = 30;
        egg[j].pos.width = 20;
        egg[j].pos.x = 0;
        egg[j].pos.y = 800;
    }

    Tcar car[MAXCAR];
    for (j = 0; j < MAXCAR; j++)
    {
        car[j].status = 0;
        car[j].pos.height = 140;
        car[j].pos.width = 315;
        car[j].pos.x = 0;
        car[j].pos.y = 800;
        car[j].movimiento = 0;
        car[j].time = 120;
    }

    Thit hithit;

    // Inicializacion camara
    Camera2D camara = {0};
    camara.target.x = player.pos.x + 30;
    camara.target.y = player.pos.y;
    camara.offset.x = 640;
    camara.offset.y = CAMY;
    camara.rotation = 0;
    camara.zoom = 1;

    float posicion = player.pos.x;

    while (!WindowShouldClose())
    {

        time += 1;
        igncolision++;
        frameC++;
        player.timeDash++;
        // **************************************************** DIBUJO *******************************************************
        BeginDrawing();

        BeginMode2D(camara);

        ClearBackground(LIGHTGRAY);

        float ancho = 700;
        for (int x = 0; x < 8; x++)
        {

            DrawTextureEx(back, Vector2{ancho, 0}, 0, 1, WHITE);
            DrawTextureEx(middle, Vector2{ancho, 0}, 0, 1, WHITE);
            DrawTextureEx(front, Vector2{ancho, 0}, 0, 1, WHITE);
            ancho -= back.width;
        }

        float piso = 2000;
        for (int x = 0; x < 2000; x++)
        {
            DrawTextureEx(ground, Vector2{piso, SUELO}, 0, 1, WHITE);
            piso -= ground.width;
        }
        //****************************************************** PIEZAS **********************************************************************
        for (j = 0; j < 3; j++)
        {
            if (CheckPlayerColision(player.pos, pieza[j].pos))
            {
                if (pieza[j].pos.x < 0)
                {
                    pieza[j].status = 0;
                    pieza[j].pos.y = SUELO - pieza[j].pos.height;
                    pieza[j].pos.x = 900;
                    piezac++;
                    switch (piezac)
                    {
                    case 1:
                        pieza[j].pos.x = 900;
                        break;
                    case 2:
                        pieza[j].pos.x = 950;
                        break;
                    case 3:
                        pieza[j].pos.x = 1000;
                        break;
                    }
                }
                else
                {
                    pieza[j].status = 1;
                }
            }
        }

        //******************************************************** AVES **************************************************************************
        for (j = 0; j < MAXAVE; j++)
        {
            // comportameinto
            if (ave[j].status)
            {
                // movimiento enemigo **si sale de la pantalla se elimina**
                if (ave[j].right)
                {
                    ave[j].pos.x -= AVESPEED;
                    if (ave[j].pos.x <= player.pos.x - 750 - ave[j].pos.width)
                    {
                        ave[j].status = 0;
                    }
                }
                else
                {
                    if (ave[j].left)
                    {
                        ave[j].pos.x += AVESPEED;
                        if (ave[j].pos.x >= player.pos.x + 750)
                        {
                            ave[j].status = 0;
                        }
                    }
                }

                // ataque enemigo ***********************************************************************************
                random = (rand() % 11) + 1;
                if (random == 1)
                {
                    if (ave[j].pos.x <= player.pos.x + player.pos.width + 200)
                    {
                        if (ave[j].pos.x >= player.pos.x - 200)
                        {
                            random = rand() % MAXEGG;
                            DropEgg(ave[j], egg[random]);
                        }
                    }
                }
                // Colision con golpe
                if (hit)
                {
                    if (CheckMobColision(ave[j].pos, hithit))
                    {
                        ave[j].status = 0;
                    }
                }

                // Colision con jugador
                if (ave[j].status)
                {
                    if (CheckPlayerColision(player.pos, ave[j].pos))
                    {
                        PlaySound(dolor);
                        DrawTextureRec(danio, framesDanio, Vector2{player.pos.x - 82, player.pos.y - 60}, WHITE);
                        player.pos.x = 400;   // Posicion incial
                        player.pos.y = SUELO; //""
                        player.y0 = player.pos.y;
                        player.v0 = 0;
                        player.timeDash = 70;
                        LimpiaEnemigos(ave, car);
                    }
                }
            }
            else
            {
                // generacion
                random = (rand() % 100) + 1;
                if (random == 1)
                {
                    ave[j].right = rand() % 2;
                    if (ave[j].right)
                    {
                        ave[j].status = 1;
                        ave[j].pos.x = player.pos.x + 610 + player.pos.width;
                        ave[j].pos.y = (rand() % 90) + 1;
                        ave[j].left = 0;
                    }
                    else
                    {
                        ave[j].status = 1;
                        ave[j].pos.x = player.pos.x - 610;
                        ave[j].pos.y = (rand() % 101) + 1;
                        ave[j].left = 1;
                    }
                }
            }
        }

        //** comportamiento huevo ********************************************************************************************************************************
        for (j = 0; j < MAXEGG; j++)
        {
            // elinacion de huevo
            if (egg[j].pos.y - egg[j].pos.height >= SUELO)
            {
                egg[j].status = 0;
                egg[j].pos.y = 800;
            }
            // caida de huevo
            if (egg[j].status)
            {
                egg[j].time += 1;
                egg[j].pos.y = Posicion(egg[j].y0, 0, egg[j].time, 0);
            }

            // Colision con golpe
            if (hit)
            {
                if (CheckMobColision(egg[j].pos, hithit))
                {
                    egg[j].status = 0;
                }
            }

            // Colision con jugador
            if (egg[j].status)
            {
                if (CheckPlayerColision(player.pos, egg[j].pos))
                {
                    PlaySound(dolor);
                    DrawTextureRec(danio, framesDanio, Vector2{player.pos.x - 82, player.pos.y - 60}, WHITE);
                    player.pos.x = 400;   // Posicion incial
                    player.pos.y = SUELO; //""
                    player.y0 = player.pos.y;
                    player.v0 = 0;
                    player.timeDash = 70;
                    LimpiaEnemigos(ave, car);
                }
            }
        }

        //** enemigo2 carro ********************************************************************************************************************************
        for (j = 0; j < MAXCAR; j++)
        {
            // comportameinto
            if (car[j].status)
            {
                // movimiento enemigo
                if (car[j].movimiento)
                {
                    car[j].pos.x += CARSPEED;
                }
                else
                {
                    car[j].time++;
                    if (car[j].time > 60)
                    {
                        car[j].movimiento = 1;
                    }
                }
                // eliminacion del enemigo
                if (car[j].pos.x >= player.pos.x + 720)
                {
                    car[j].status = 0;
                }

                // Colision con golpe
                if (hit)
                {
                    if (CheckMobColision(car[j].pos, hithit))
                    {
                        car[j].movimiento = 0;
                        car[j].time = 0;
                    }
                }

                // Colision con jugador
                if (car[j].status)
                {
                    if (CheckPlayerColision(player.pos, car[j].pos))
                    {
                        PlaySound(dolor);
                        DrawTextureRec(danio, framesDanio, Vector2{player.pos.x - 82, player.pos.y - 60}, WHITE);
                        player.pos.x = 400;   // Posicion incial
                        player.pos.y = SUELO; //""
                        player.y0 = player.pos.y;
                        player.v0 = 0;
                        player.timeDash = 70;
                        LimpiaEnemigos(ave, car);
                    }
                }
            }
            else
            {
                // generacion
                // random=GetRandomValue(1,1);
                if (player.pos.x < -60)
                {
                    car[j].status = 1;
                    car[j].movimiento = 1;
                    car[j].pos.x = player.pos.x - 610 - car[j].pos.width;
                    car[j].pos.y = SUELO - car[j].pos.height;
                }
            }
        }

        //** caluclar posicion y ********************************************************************************************************************************
        if (player.fall)
        {
            if (bdown)
            {
                if (velocidad(player.v0, time) > 0)
                {
                    if (++c == 1)
                    {
                        player.v0 = velocidad(player.v0, time); // velocidad inicial igual a velocidad actual
                        player.y0 = player.pos.y;
                        time = 1;
                    }
                }
                else
                {
                    Reposo(time, player.v0, player.y0, player.pos.y);
                }
                player.pos.y = Posicion(player.y0, player.v0, time, bdown);
            }
            else
            {
                player.pos.y = Posicion(player.y0, player.v0, time, bdown);
            }
        }

        //** colisiones ********************************************************************************************************************************
        // suelo
        if (player.pos.y + player.pos.height > SUELO)
        {
            player.pos.y = SUELO - player.pos.height;
            Reposo(time, player.v0, player.y0, player.pos.y);
            player.fall = 0;
            bsuelo = 1;
            player.jump = 1;
            player.jumpjump = 1;
        }

        // plataformas
        if (igncolision > 20)
        {
            // plataforma cuando cae
            if (velocidad(player.v0, time) > 0)
            {
                for (j = 0; j < platc; j++)
                {
                    if (plat[j].status)
                    {
                        if (ColisionPlat(player, plat[j]))
                        {
                            player.pos.y = plat[j].pos.y - player.pos.height;
                            Reposo(time, player.v0, player.y0, player.pos.y);
                            player.fall = 0;
                            plat[j].flag = 1;
                            player.jump = 1;
                            player.jumpjump = 1;
                            bdown = 0;
                        }
                    }
                }
            }
        }

        // si salio de la paltaforma
        for (j = 0; j < platc; j++)
        {
            if (plat[j].status)
            {
                if (plat[j].flag)
                {
                    if (!ColisionPlat(player, plat[j]))
                    {
                        Reposo(time, player.v0, player.y0, player.pos.y);
                        player.fall = 1;
                        plat[j].flag = 0;
                        player.jump = 1;
                        player.jumpjump = 0;
                        bdown = 0;
                    }
                }
            }
        }

        //** golpe ********************************************************************************************************************************
        if (hit)
        {
            if (lookR)
            {
                hithit.x = player.pos.x + ANCHOP - 20;
                hithit.y = player.pos.y - 20;
            }
            else
            {
                if (lookL)
                {
                    hithit.x = player.pos.x - 60;
                    hithit.y = player.pos.y - 20;
                }
            }

            if (lookUp)
            {
                hithit.x = player.pos.x - player.pos.width / 2;
                hithit.y = player.pos.y - player.pos.height;
            }
            else
            {
                if (lookDown)
                {
                    hithit.x = player.pos.x - player.pos.width / 2;
                    hithit.y = player.pos.y + player.pos.height - player.pos.height / 3;
                }
            }
            if (hitc < 50)
            {
                hitc++;
            }
            else
            {
                hitc = 0;
                hit = 0;
            }
        }

        //** dash ********************************************************************************************************************************
        if (dash)
        {
            if (player.timeDash < 20)
            {
                if (lookR)
                {
                    player.pos.x += VD;
                }
                else
                {
                    if (lookL)
                    {
                        player.pos.x -= VD;
                    }
                }
            }
            else
            {
                if (player.pos.x > -10)
                {
                    player.jump = 1;
                    player.jumpjump = 0;
                }
                else
                {
                    player.jump == 0;
                    player.jumpjump = 0;
                }
                player.fall = 1;
                dash = Reposo(time, player.v0, player.y0, player.pos.y);
            }
        }

        //** camara ********************************************************************************************************************************
        camara.target.y = player.pos.y;
        if (player.pos.y > 100)
        {
            camara.target.y = CAMY;
            camara.offset.y = CAMY;
            camara.target.x = player.pos.x + 25;
        }
        else
        {
            camara.offset.y = RANCHO / 12.5;
            camara.target.x = player.pos.x + 25;
        }

        //** intput ********************************************************************************************************************************
        if (!dash) // right left
        {
            if (IsKeyDown(KEY_RIGHT))
            {
                if (player.pos.x < 1280)
                {
                    player.pos.x += VX;
                    lookR = 1;
                    lookL = 0;
                }
            }
            else
            {
                if (IsKeyDown(KEY_LEFT))
                {
                    if (player.pos.x > plat[platc - 1].pos.x - 610)
                    {
                        player.pos.x -= VX;
                        lookR = 0;
                        lookL = 1;
                    }
                }
            }
        }

        if (!dash) // up down
        {
            if (IsKeyPressed(KEY_UP))
            {
                if (player.jump)
                {
                    Reposo(time, player.v0, player.y0, player.pos.y);
                    Salto(time, player.v0, player.y0, player.pos.y);
                    player.fall = 1;
                    if (player.jumpjump) //! doblesalto
                    {
                        player.jump = 1;
                        player.jumpjump = 0;
                    }
                    else
                    {
                        player.jump = 0;
                    }
                    for (j = 0; j < MAXPLAT; j++)
                    {
                        if (plat[j].status)
                        {
                            plat[j].flag = 0;
                        }
                    }
                    bsuelo = 0;
                    bdown = 0;
                }
            }
            else
            {
                if (IsKeyPressed(KEY_DOWN))
                {
                    for (j = 0; j < MAXPLAT; j++)
                    {
                        if (plat[j].flag)
                        {
                            // if(IsKeyPressedRepeat(KEY_DOWN))
                            {
                                player.fall = 1;
                                igncolision = 0;
                                bdown = 0;
                            }
                        }
                        else
                        {
                            bdown = 1;
                            player.fall = 1;
                            c = 0;
                        }
                    }
                }
            }
        }

        // hit
        if (IsKeyPressed(KEY_X))
        {
            if (IsKeyDown(KEY_UP))
            {
                hithit.width = ALTOP + 30;
                hithit.height = 90;
                hit = 1;
                dash = 0;
                player.fall = 1;
                lookUp = 1;
                lookDown = 0;
            }
            else
            {
                if (IsKeyDown(KEY_DOWN))
                {
                    hithit.width = ALTOP + 30;
                    hithit.height = 90;
                    hit = 1;
                    dash = 0;
                    player.fall = 1;
                    lookDown = 1;
                    lookUp = 0;
                }
                else
                {
                    hithit.width = 90;
                    hithit.height = ALTOP + 30;
                    hit = 1;
                    dash = 0;
                    player.fall = 1;
                    lookDown = 0;
                    lookUp = 0;
                }
            }
        }

        // dash KEY C
        if (player.pos.x < 1250)
        {
            if (player.pos.x > plat[platc - 1].pos.x - 590)
            {
                if (player.timeDash > 80)
                {
                    if (!dash)
                    {
                        if (IsKeyPressed(KEY_C))
                        {
                            dash = 1;
                            player.timeDash = 0;
                            Reposo(time, player.v0, player.y0, player.pos.y);
                            player.fall = 0;
                            player.jump = 0;
                            player.jumpjump = 0;
                        }
                    }
                }
            }
        }

        framesAutom++;
        if (framesAutom >= (60 / framesSpeed))
        {
            framesAutom = 0;
            currentFrame++;

            if (currentFrame > 5)
                currentFrame = 0;
            framesPajaro.x = (float)currentFrame * (float)pajaro.width / 6;
            framesPajaroizq.x = (float)currentFrame * (float)pajaroizq.width / 6;
            framesReposo.x = (float)currentFrame * (float)reposo.width / 4;
            framesReposoizq.x = (float)currentFrame * (float)reposoizq.width / 4;
        }

        if (player.fall)
        {
            framesSalto++;
            if (framesSalto >= (60 / framesSpeed))
            {
                framesSalto = 0;
                currentSalto++;

                if (currentSalto > 3)
                    currentSalto = 0;
                frameSalto.x = (float)currentSalto * (float)salto.width / 4;
                frameSaltoder.x = (float)currentSalto * (float)saltoder.width / 4;
            }
            if (lookL)
            {
                DrawTextureRec(salto, frameSalto, Vector2{player.pos.x - 80, player.pos.y - 60}, WHITE);
            }
            if (lookR)
            {
                DrawTextureRec(saltoder, frameSalto, Vector2{player.pos.x - 20, player.pos.y - 60}, WHITE);
            }
        }
        else
        {
            if (IsKeyDown(KEY_RIGHT))
            {
                framesPersonaje++;
                framesSalto = 0;
                if (framesPersonaje >= (60 / framesSpeed))
                {
                    framesPersonaje = 0;
                    currentPersonaje++;

                    if (currentPersonaje > 5)
                        currentPersonaje = 0;
                    framesCaminar.x = (float)currentPersonaje * (float)caminar.width / 6;
                }
                DrawTextureRec(caminar, framesCaminar, Vector2{player.pos.x - 20, player.pos.y - 60}, WHITE);
            }
            else if (IsKeyDown(KEY_LEFT))
            {
                framesPersonaje++;
                if (framesPersonaje >= (60 / framesSpeed))
                {
                    framesPersonaje = 0;
                    currentPersonaje++;

                    if (currentPersonaje > 5)
                        currentPersonaje = 0;
                    framesCaminarizq.x = (float)currentPersonaje * (float)caminarizq.width / 6;
                }
                DrawTextureRec(caminarizq, framesCaminarizq, Vector2{player.pos.x - 80, player.pos.y - 60}, WHITE);
            }
            else
            {
                framesPersonaje = 0;
                if (lookL)
                {
                    DrawTextureRec(reposoizq, framesReposoizq, Vector2{player.pos.x - 82, player.pos.y - 60}, WHITE);
                }
                if (lookR)
                {
                    DrawTextureRec(reposo, framesReposo, Vector2{player.pos.x - 20, player.pos.y - 60}, WHITE);
                }
            }
        }
        // plataformas
        for (j = 0; j < platc; j++)
        {
            DrawTexture(plataforma, plat[j].pos.x, plat[j].pos.y, WHITE);
        }

        // enemigos
        for (j = 0; j < MAXAVE; j++)
        {
            if (ave[j].status)
            {
                if (ave[j].left)
                {
                    DrawTextureRec(pajaro, framesPajaro, Vector2{ave[j].pos.x, ave[j].pos.y - 50}, WHITE);
                }

                if (ave[j].right)
                {
                    DrawTextureRec(pajaroizq, framesPajaro, Vector2{ave[j].pos.x, ave[j].pos.y - 50}, WHITE);
                }
            }
        }
        for (j = 0; j < MAXEGG; j++)
        {
            if (egg[j].status)
            {
                DrawTextureRec(huevo, framesHuevo, Vector2{egg[j].pos.x, egg[j].pos.y}, WHITE);
            }
        }
        for (j = 0; j < MAXCAR; j++)
        {
            if (car[j].status)
            {
                // DrawRectangle(car[j].pos.x,car[j].pos.y, car[j].pos.width, car[j].pos.y, RED);
                DrawTextureRec(carro, framesCarro, Vector2{car[j].pos.x, car[j].pos.y}, WHITE);
            }
        }
        // piezas
        for (j = 0; j < 3; j++)
        {
            if (pieza[j].status)
            {
                DrawTextureRec(piezas[j], framePiezas[j], Vector2{pieza[j].pos.x,pieza[j].pos.y}, WHITE);
            }
        }
        // golpe
        if (hit)
        {
            DrawRectangleRec(hithit, RED);
        }
        EndMode2D();
        EndDrawing();
    }

    UnloadSound(dolor);
    UnloadTexture(back);
    UnloadTexture(front);
    UnloadTexture(middle);
    UnloadTexture(ground);
    UnloadTexture(carro);
    UnloadTexture(plataforma);
    UnloadTexture(saltoder);
    UnloadTexture(salto);
    UnloadTexture(pajaroizq);
    UnloadTexture(caminar);
    UnloadTexture(caminarizq);
    UnloadTexture(reposoizq);
    UnloadTexture(huevo);
    UnloadTexture(pajaro);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}

float velocidad(float v0, float time)
{
    return (v0 + 2 * G * time);
}

int ColisionPlat(Tplayer player, Tplat plat)
{
    if (player.pos.x <= plat.pos.x + plat.pos.width) // Si esta tocando el lado derecho de la plataforma n
    {
        if (plat.pos.x <= player.pos.x + ANCHOP) // si esta tocando el lado izquierdo de la platforma n
        {
            if (player.pos.y + player.pos.height <= (plat.pos.y + 30))
            {
                if (player.pos.y + player.pos.height >= plat.pos.y)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int Reposo(float &time, float &v0, int &y0, int y)
{
    time = 0;
    v0 = 0;
    y0 = y;
    return 0;
}

int Salto(float &time, float &v0, int &y0, int y)
{
    time = 0;
    y0 = y;
    v0 = VS;
    return 0;
}

int Posicion(int y0, float v0, float time, int g)
{
    return (y0 + v0 * time + (g ? GD : G) * time * time);
}

void CalculaPosEnemigo(Tave &mob)
{
    if (mob.right)
    {
        mob.pos.x -= 6;
    }
    else
    {
        if (mob.left)
        {
            mob.pos.x += 6;
        }
    }
}

int CheckPlayerColision(Trec player, Trec mob)
{
    if (player.x < (mob.x + mob.width))
    {
        if ((player.x + player.width) > mob.x)
        {
            if (player.y < (mob.y + mob.height))
            {
                if ((player.y + player.height) > mob.y)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
/*
int CheckPiezaColision(Trec player,Trec mob) //duplicado para probar sin daño
{

    if(player.x<(mob.x+mob.width))
    {
        if((player.x+player.width)>mob.x)
        {
            if(player.y<(mob.y+mob.height))
            {
                if((player.y+player.height)>mob.y)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
}
*/
int CheckMobColision(Trec mob, Thit hit)
{
    if (mob.x < (hit.x + hit.width))
    {
        if ((mob.x + mob.width) > hit.x)
        {
            if (mob.y < (hit.y + hit.height))
            {
                if ((mob.y + mob.height) > hit.y)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void DropEgg(Tave mob, Tegg &egg)
{
    if (!egg.status)
    {
        egg.time = 0;
        egg.y0 = mob.pos.y;
        egg.pos.y = mob.pos.y;
        egg.pos.x = mob.pos.x + 14;
        egg.status = 1;
    }
}

void LimpiaEnemigos(Tave ave[], Tcar car[])
{
    int j;
    for (j = 0; j < MAXAVE; j++)
    {
        ave[j].status = 0;
    }
    for (j = 0; j < MAXCAR; j++)
    {
        car[j].status = 0;
    }
}