#include "raylib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COLUMNAS1 3
#define RENGLONES1 3

#define RANCHO 1280
#define RALTO 720
#define CAMY 360
#define CAMX 640

#define ALTOP 85
#define ANCHOP 50
#define SUELO 650
#define MAXVIDA 3
#define INVULERABILIDAD 120

#define G 0.1
#define GD 0.15

#define VX 3
#define VS -11
#define VSi -4
#define VY 3
#define VD 7.5

#define MAXANGUILA 3
#define ANGUILASPEED 5
#define MAXSHARK 2
#define SHARKSPEED 7
#define MAXTORTUGA 2
#define TORTUGASPEED 3

#define MAXPLAT 3

#define MAXHIT 500
#define VATAQUE 40
#define VATAQUEBUFF 30
#define VPROYECTIL 10

typedef Rectangle Trec;
// blank transparente

// typedef Rectangle Tplayer;

typedef struct _tabla
{
    Trec pos;
    int num;
    char opRight[2];
    char opDown[2];
    int status;
} Ttab;

typedef struct _velocidad
{
    float vx;
    float vy;
} Tvel;

typedef struct _shark
{
    Trec pos;
    int status = 0;
    int right = 0;
    int left = 0;
    Tvel v;
} Tshark;

typedef struct _tortuga
{
    Trec pos;
    int status = 0;
    int right = 0;
    int left = 0;
} Ttortu;

typedef struct _anghit
{
    Trec pos;
    int status;
    int time;
} Tanghit;

typedef struct _anguila
{
    Trec pos;
    int status = 0;
    int right = 0;
    int left = 0;
    Tvel v;
    Tanghit hit;
} Tangui;

typedef struct _hit
{
    Trec pos;      // 7   0    1
    int status;    //
    int direccion; //--------------------->  //6   p    2
    Tvel v;        //
} Thit;            // 5   4    3

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
    int listo;
} Tpart;

typedef struct _vida
{
    Trec pos;
    int num;
    int time;
} Tvida;

typedef struct _jugador
{
    Trec pos;
    int timeDash;
    int dash;
    int x0;
    int AtkC;
    Tvida vida;
} Tplayer;

void Direccioniugador(int &l, int &r, int &up, int &down, Tplayer player);
void InicializaProyectil(int l, int r, int up, int down, Tplayer player, Thit &hit);
void CalculaComponentesVelocidad(float velocidad, float grados, Tvel &v);
float Radianes(float grados);
void PosicionObieto(float vx, float vy, Trec &pos);
int CheckMobColision(Trec mob, Thit hit);
int CheckPlayerColision(Trec player, Trec mob);
void LimpiaEnemigosLvl1(/*Tave ave[],Tcar car[]*/ Tshark shark[], Ttortu tort[], Tangui ang[]);
float CalculaAnguloAnguila(Trec ang, Trec player);
void AngElectro(Tangui &ang);
void muerteLvl1(Tplayer &player, Tshark shark[], Ttortu tort[], Tangui ang[], Tpart pieza[], Trec plat[]);
void cinemaPuzleNivel1(void);

int main()
{
    float VDDIAGONAL = VD * sin(45) / sin(90);
    SetTargetFPS(60);
    InitWindow(RANCHO, RALTO, "iuego");
    srand(time(NULL));
    int i, j;
    Tplayer player;
    player.pos.height = ALTOP;
    player.pos.width = ANCHOP;
    player.pos.x = RANCHO / 2;
    player.pos.y = SUELO - player.pos.height;
    player.dash = 0;
    player.timeDash = 0;
    player.x0 = player.pos.x;
    player.AtkC = 0;

    // vida
    player.vida.num = MAXVIDA;
    player.vida.pos.width = 25;
    player.vida.pos.height = 25;
    player.vida.pos.x = 25;
    player.vida.pos.y = 25;

    int lookR = 1;
    int lookL = 0;
    int lookUp = 0;
    int lookDown = 0;
    int fin = 0;
    int random;

    int framesAutom = 0;
    int framesPersonaje = 0;

    int framesSpeed = 8;

    int currentFrame = 0;
    int currentPersonaje = 0;

    int framesAtaque = 0;
    int currentAtaque = 0;

    // ********************************** TEXTURAS **************************************************
    Texture2D tortuga = LoadTexture("texturas/tortuga_der1.png");
    Rectangle framesTortuga = {0.0f, 0.0f, (float)tortuga.width / 6, (float)tortuga.height};

    Texture2D tortugaizq = LoadTexture("texturas/tortuga_izq.png");
    Rectangle framesTortugaizq = {0.0f, 0.0f, (float)tortugaizq.width / 6, (float)tortugaizq.height};

    Texture2D anguila = LoadTexture("texturas/anguila.png");
    Rectangle framesAnguila = {0.0f, 0.0f, (float)anguila.width / 6, (float)anguila.height};

    Texture2D anguilaizq = LoadTexture("texturas/anguila_izq.png");
    Rectangle framesAnguilaizq = {0.0f, 0.0f, (float)anguilaizq.width / 6, (float)anguilaizq.height};

    Texture2D ataque_anizq = LoadTexture("texturas/ataqueizq.png");
    Rectangle framesAtaque_anizq = {0.0f, 0.0f, (float)ataque_anizq.width / 6, (float)ataque_anizq.height};

    Texture2D ataque_ani = LoadTexture("texturas/ataqueizq.png");
    Rectangle framesAtaque_ani = {0.0f, 0.0f, (float)ataque_ani.width / 6, (float)ataque_ani.height};

    Texture2D pulpo = LoadTexture("texturas/pulpo.png");
    Rectangle framesPulpo = {0.0f, 0.0f, (float)pulpo.width / 6, (float)pulpo.height};

    Texture2D pulpoizq = LoadTexture("texturas/pulpoizq.png");
    Rectangle framesPulpoizq = {0.0f, 0.0f, (float)pulpoizq.width / 6, (float)pulpoizq.height};

    Texture2D caminar = LoadTexture("texturas/Cyborg_run.png");
    Rectangle framesCaminar = {0.0f, 0.0f, (float)caminar.width / 6, (float)caminar.height};

    Texture2D caminarizq = LoadTexture("texturas/Cyborg_run_left.png");
    Rectangle framesCaminarizq = {0.0f, 0.0f, (float)caminarizq.width / 6, (float)caminarizq.height};

    Texture2D reposo = LoadTexture("texturas/Cyborg_idle.png");
    Rectangle framesReposo = {0.0f, 0.0f, (float)reposo.width / 4, (float)reposo.height};

    Texture2D reposoizq = LoadTexture("texturas/Cyborg_idle_left.png");
    Rectangle framesReposoizq = {0.0f, 0.0f, (float)reposoizq.width / 4, (float)reposoizq.height};

    Texture2D back_nv1 = LoadTexture("texturas/back_nv1.png");
    Texture2D backmiddle_nv1 = LoadTexture("texturas/middleback_nv1.png");
    Texture2D middle_nv1 = LoadTexture("texturas/middle_mv1.png");
    Texture2D front_nv1 = LoadTexture("texturas/front_nv1.png");

    Texture2D plataforma_nv1 = LoadTexture("texturas/plataforma_nv1_1.png");

    Texture2D bullet_nv1 = LoadTexture("texturas/bullet_nv1.png");

    Texture2D corazon = LoadTexture("texturas\\corazon.png");

    Texture2D ataquesizquierdos[5];
    Texture2D ataquesderechos[5];

    ataquesizquierdos[0] = LoadTexture("texturas/HitL0.png");
    ataquesizquierdos[1] = LoadTexture("texturas/HitL1.png");
    ataquesizquierdos[2] = LoadTexture("texturas/HitL2.png");
    ataquesizquierdos[3] = LoadTexture("texturas/HitL3.png");
    ataquesizquierdos[4] = LoadTexture("texturas/HitL4.png");

    ataquesderechos[0] = LoadTexture("texturas/HitR0.png");
    ataquesderechos[1] = LoadTexture("texturas/HitR1.png");
    ataquesderechos[2] = LoadTexture("texturas/HitR2.png");
    ataquesderechos[3] = LoadTexture("texturas/HitR3.png");
    ataquesderechos[4] = LoadTexture("texturas/HitR4.png");

    Texture2D piezas_nv1[3];
    piezas_nv1[0] = LoadTexture("texturas/pieza1_nv1.png");
    piezas_nv1[1] = LoadTexture("texturas/pieza2_nv1.png");
    piezas_nv1[2] = LoadTexture("texturas/pieza3_nv1.png");

    // ************************************************ SONIDOS ********************************************************************

    InitAudioDevice();

    Sound dolor = LoadSound("sonidos/danio.wav");
    Sound brinco = LoadSound("sonidos/salto.mp3");
    Sound paso = LoadSound("sonidos/paso1.wav");
    Sound agarrar = LoadSound("sonidos/pieza.wav");
    Music musica_nv1 = LoadMusicStream("sonidos/nivel1.mp3");
    Sound sdash = LoadSound("sonidos/paso1.wav");
    Sound disparo_nv1 = LoadSound("sonidos/disparo_nv1.wav");
    Sound ludico = LoadSound("sonidos/nivel_completado.wav");
    Sound anguilasound = LoadSound("sonidos/anguilasound.wav");

    SetSoundVolume(disparo_nv1, -0.1f);
    SetSoundVolume(sdash, +10.0f);
    SetMusicVolume(musica_nv1, -1.2f);

    //** proyectil ************************************************************************************************************************
    Thit hit[MAXHIT];
    for (i = 0; i < MAXHIT; i++)
    {
        hit[i].status = 0;
        hit[i].pos.width = bullet_nv1.width;
        hit[i].pos.height = bullet_nv1.height;
        hit[i].pos.x = 1280;
        hit[i].pos.y = 1500;
    }

    //** plataformas **************************************************************************************************************************
    Trec plat[MAXPLAT];
    for (i = 0; i < MAXPLAT; i++)
    {
        plat[i].height = plataforma_nv1.height;
        plat[i].width = plataforma_nv1.width;
    }
    plat[0].x = 100;
    plat[0].y = 200;
    plat[1].x = RANCHO / 2 - plat[1].width / 2;
    plat[1].y = 400;
    plat[2].x = RANCHO - 100 - plat[2].width;
    plat[2].y = 200;

    //** piezas **********************************************************************************************************************************
    int time = 0;
    Tpart pieza[3];
    int piezac = 0;
    pieza[0].pos.height = piezas_nv1[0].height;
    pieza[0].pos.width = piezas_nv1[0].width;
    pieza[1].pos.height = piezas_nv1[1].height;
    pieza[1].pos.width = piezas_nv1[1].width;
    pieza[2].pos.height = piezas_nv1[2].height;
    pieza[2].pos.width = piezas_nv1[2].width;
    for (j = 0; j < 3; j++)
    {
        pieza[j].status = 0;
        pieza[j].status = 1;
        pieza[j].pos.x = plat[j].x + plat[j].width / 2 - pieza[j].pos.width / 2;
        pieza[j].pos.y = -300;
        pieza[j].listo = 0;
    }

    //** enemigos **********************************************************************************************************************************
    Tshark shark[MAXSHARK];
    for (i = 0; i < MAXSHARK; i++)
    {
        shark[i].status = 0;
        shark[i].right = 0;
        shark[i].left = 0;
        shark[i].pos.x = 2000;
        shark[i].pos.y = 800;
        shark[i].pos.height = 100;
        shark[i].pos.width = 120;
    }

    Ttortu tort[MAXTORTUGA];
    for (i = 0; i < MAXTORTUGA; i++)
    {
        tort[i].status = 0;
        tort[i].pos.x = 2000;
        tort[i].pos.y = 800;
        tort[i].pos.height = tortuga.height - 100;
        tort[i].pos.width = (tortuga.width / 6) - 40;
    }
    tort[0].left = 1;
    tort[0].right = 0;
    tort[1].right = 1;
    tort[1].left = 0;

    Tangui ang[MAXANGUILA];
    for (i = 0; i < MAXANGUILA; i++)
    {
        ang[i].status = 0;
        ang[i].right = 0;
        ang[i].left = 0;
        ang[i].pos.x = 2000;
        ang[i].pos.y = 800;
        ang[i].pos.height = anguila.height - 65;
        ang[i].pos.width = (anguila.width / 6) - 20;
        ang[i].hit.pos.height = ang[0].pos.height * 3;
        ang[i].hit.pos.width = ang[0].pos.width * 1.5;
        ang[i].hit.pos.y = 800;
        ang[i].hit.pos.x = 2000;
        ang[i].hit.status = 0;
        ang[i].hit.time = 0;
    }

    // Inicializacion camara
    Camera2D camara = {0};
    camara.target.x = 0;
    camara.target.y = 0;
    camara.offset.x = 0;
    camara.offset.y = 0;
    camara.rotation = 0;
    camara.zoom = 1;

    while (!WindowShouldClose())
    {
        // printf("x = %f y = %f\n",player.pos.x,player.pos.y);
        player.timeDash++;
        player.AtkC++;
        time++;
        player.vida.time++;
        BeginDrawing();

        BeginMode2D(camara);
        DrawRectangleRec(player.pos, DARKBLUE);
        DrawTexture(back_nv1, 0, 0, WHITE);
        DrawTexture(backmiddle_nv1, 0, 0, WHITE);
        DrawTexture(middle_nv1, 0, 0, WHITE);
        DrawTexture(front_nv1, 0, 0, WHITE);

        PlayMusicStream(musica_nv1);
        UpdateMusicStream(musica_nv1);

        //** terminar el nivel ***********************************************************************************
        if (pieza[0].status)
        {
            if (pieza[0].pos.y == SUELO - pieza[0].pos.height)
            {
                if (pieza[1].status)
                {
                    if (pieza[1].pos.y == SUELO - pieza[1].pos.height - 5)
                    {
                        if (pieza[2].status)
                        {
                            if (pieza[2].pos.y == SUELO - pieza[2].pos.height - 8)
                            {
                                if (!fin)
                                {
                                    PlaySound(ludico);
                                    time = 0;
                                }
                                fin = 1;
                                LimpiaEnemigosLvl1(shark, tort, ang);
                                if (time > 300)
                                {
                                    cinemaPuzleNivel1();
                                }
                                // CloseWindow();
                            }
                        }
                    }
                }
            }
        }

        if (!fin)
        {
            // reaiusta posicion si sale de limites *********************************************************************************************
            if (player.pos.y < 25)
            {
                player.pos.y = 25;
            }
            else
            {
                if (player.pos.y > SUELO - player.pos.height)
                {
                    player.pos.y = SUELO - player.pos.height;
                }
                else
                {
                    if (player.pos.x < 0)
                    {
                        player.pos.x = 0;
                    }
                    else
                    {
                        if (player.pos.x > RANCHO - player.pos.width)
                        {
                            player.pos.x = RANCHO - player.pos.width;
                        }
                    }
                }
            }

            //** piezas ****************************************************************************************************************************
            for (j = 0; j < 3; j++)
            {
                // drop
                if (!pieza[j].listo)
                {
                    if (!pieza[j].status)
                    {
                        if (CheckPlayerColision(player.pos, pieza[j].pos))
                        {
                            pieza[j].status = 1;
                            pieza[j].listo = 1;
                        }
                    }
                }

                // recolleccion
                if (!pieza[j].listo)
                {
                    if (pieza[j].status)
                    {
                        if (CheckPlayerColision(player.pos, pieza[j].pos))
                        {
                            PlaySound(agarrar);
                            pieza[j].status = 0;
                            pieza[j].pos.y = SUELO - pieza[j].pos.height;
                            piezac++;
                            printf("\npiezac = %d\n", piezac);
                            switch (piezac)
                            {
                            case 1:
                                pieza[j].pos.x = 900;
                                break;
                            case 2:
                                pieza[j].pos.x = 980;
                                pieza[j].pos.y -= 5;
                                break;
                            case 3:
                                pieza[j].pos.x = 1055;
                                pieza[j].pos.y -= 8;
                                break;
                            }
                            j = 3;
                        }
                    }
                }
            }

            // movimiento piezas
            if (time > 600)
            {
                if (!pieza[0].listo)
                {
                    if (pieza[0].pos.y < plat[0].y - pieza[0].pos.height)
                    {
                        pieza[0].pos.y += 4;
                    }
                    else
                    {
                        if (piezac < 1)
                        {
                            pieza[0].pos.y = plat[0].y - pieza[0].pos.height;
                        }
                    }
                }
                if (time > 1200)
                {
                    if (!pieza[1].listo)
                    {
                        if (pieza[1].pos.y < plat[1].y - pieza[1].pos.height)
                        {
                            pieza[1].pos.y += 4;
                        }
                        else
                        {
                            if (piezac < 2)
                            {
                                pieza[1].pos.y = plat[1].y - pieza[1].pos.height;
                            }
                        }
                    }

                    if (time > 1800)
                    {
                        if (!pieza[2].listo)
                        {
                            if (pieza[2].pos.y < plat[2].y - pieza[2].pos.height)
                            {
                                pieza[2].pos.y += 4;
                            }
                            else
                            {
                                if (piezac < 3)
                                {
                                    pieza[2].pos.y = plat[2].y - pieza[2].pos.height;
                                }
                            }
                        }
                    }
                }
            }

            //** enemigos **
            //** tiburones ******************************************************************************************************************************
            for (i = 0; i < MAXSHARK; i++)
            {
                // comportameinto
                if (shark[i].status)
                {
                    // movimiento enemigo **si sale de la pantalla se elimina**
                    if (shark[i].right)
                    { // movimiento
                        if (shark[i].pos.y < 75)
                        {
                            shark[i].pos.x -= SHARKSPEED;
                        }
                        else
                        {
                            if (shark[i].pos.y > SUELO - 50 - shark[i].pos.height)
                            {
                                shark[i].pos.x -= SHARKSPEED;
                            }
                            else
                            {
                                PosicionObieto(shark[i].v.vx, shark[i].v.vy, shark[i].pos);
                            }
                        }

                        // eliminacion
                        if (shark[i].pos.x < 0 - shark[i].pos.width)
                        {
                            shark[i].status = 0;
                        }
                    }
                    else
                    {
                        if (shark[i].left)
                        { // movimiento
                            if (shark[i].pos.y < 75)
                            {
                                shark[i].pos.x += SHARKSPEED;
                            }
                            else
                            {
                                if (shark[i].pos.y > SUELO - 50 - shark[i].pos.height)
                                {
                                    shark[i].pos.x += SHARKSPEED;
                                }
                                else
                                {
                                    PosicionObieto(shark[i].v.vx, shark[i].v.vy, shark[i].pos);
                                }
                            }
                            // eliminacion
                            if (shark[i].pos.x > RANCHO + shark[i].pos.width)
                            {
                                shark[i].status = 0;
                            }
                        }
                    }

                    // Colision con golpe
                    if (hit)
                    {
                        for (j = 0; j < MAXHIT; j++)
                        {
                            if (CheckMobColision(shark[i].pos, hit[j]))
                            {
                                shark[i].status = 0;
                            }
                        }
                    }
                    // Colision con iugador
                    if (shark[i].status)
                    {
                        if (player.vida.time > INVULERABILIDAD)
                        {
                            if (CheckPlayerColision(player.pos, shark[i].pos))
                            {
                                PlaySound(dolor);
                                if (player.vida.num < 1)
                                {
                                    piezac = 0;
                                    time = 0;
                                    muerteLvl1(player, shark, tort, ang, pieza, plat);
                                }
                                else
                                {
                                    player.vida.num--;
                                    player.vida.time = 0;
                                }
                                i = MAXSHARK;
                            }
                        }
                    }
                }
                else
                {
                    // generacion
                    random = (rand() % 50) + 1;
                    if (random == 1)
                    {
                        shark[i].right = rand() % 2;
                        random = rand() % 30;
                        if (shark[i].right)
                        {
                            shark[i].status = 1;
                            CalculaComponentesVelocidad(SHARKSPEED, float(random + 165), shark[i].v);
                            shark[i].pos.x = RANCHO;
                            shark[i].pos.y = (rand() % 550) + 50;
                            shark[i].left = 0;
                        }
                        else
                        {
                            shark[i].status = 1;
                            CalculaComponentesVelocidad(SHARKSPEED, float(random + 345), shark[i].v);
                            shark[i].pos.x = 0 - shark[i].pos.width;
                            shark[i].pos.y = (rand() % 550) + 50;
                            shark[i].left = 1;
                        }
                    }
                }
            }

            //** tortugas ******************************************************************************************************************************
            for (i = 0; i < MAXTORTUGA; i++)
            {
                // comportameinto
                if (tort[i].status)
                {
                    // movimiento enemigo **si sale de la pantalla se elimina**
                    if (tort[i].right)
                    { // movimiento
                        tort[i].pos.x -= TORTUGASPEED;
                        if (tort[i].pos.x <= 0 - tort[i].pos.height)
                        {
                            tort[i].status = 0;
                        }
                    }
                    else
                    {
                        if (tort[i].left)
                        { // movimiento
                            tort[i].pos.x += TORTUGASPEED;
                            // eliminacion
                            if (tort[i].pos.x > RANCHO + tort[i].pos.width)
                            {
                                tort[i].status = 0;
                            }
                        }
                    }

                    // Colision con golpe
                    if (hit)
                    {
                        for (j = 0; j < MAXHIT; j++)
                        {
                            if (CheckMobColision(tort[i].pos, hit[j]))
                            {
                                tort[i].status = 0;
                            }
                        }
                    }
                    // Colision con iugador
                    if (tort[i].status)
                    {
                        if (player.vida.time > INVULERABILIDAD)
                        {
                            if (CheckPlayerColision(player.pos, tort[i].pos))
                            {
                                PlaySound(dolor);
                                if (player.vida.num < 1)
                                {
                                    piezac = 0;
                                    time = 0;
                                    muerteLvl1(player, shark, tort, ang, pieza, plat);
                                }
                                else
                                {
                                    player.vida.num--;
                                    player.vida.time = 0;
                                }
                                i = MAXTORTUGA;
                            }
                        }
                    }
                }
                else
                {
                    // generacion
                    random = (rand() % 100) + 1;
                    if (random == 1)
                    {
                        if (tort[i].right)
                        {
                            tort[i].status = 1;
                            tort[i].pos.x = RANCHO;
                            tort[i].pos.y = (rand() % 550) + 50;
                        }
                        else
                        {
                            tort[i].status = 1;
                            tort[i].pos.x = 0 - tort[i].pos.width;
                            tort[i].pos.y = (rand() % 550) + 50;
                        }
                    }
                }
            }

            //** anguilas *********************************************************************************************************************************
            for (i = 0; i < MAXANGUILA; i++)
            {
                // comportameinto
                if (ang[i].status)
                {
                    // movimiento enemigo **si sale de la pantalla se elimina**
                    if (ang[i].right)
                    { // movimiento
                        if (ang[i].pos.y < 75)
                        {
                            ang[i].pos.x -= ANGUILASPEED;
                        }
                        else
                        {
                            if (ang[i].pos.y > SUELO - 50 - ang[i].pos.height)
                            {
                                ang[i].pos.x -= ANGUILASPEED;
                            }
                            else
                            {
                                PosicionObieto(ang[i].v.vx, ang[i].v.vy, ang[i].pos);
                            }
                        }

                        // eliminacion
                        if (ang[i].pos.x < 0 - ang[i].pos.width)
                        {
                            ang[i].status = 0;
                            ang[i].hit.status = 0;
                        }

                        //** generacion ataque enemigo ************************************************************************************************
                        random = (rand() % 20) + 1;
                        if (random == 1)
                        {
                            if (!ang[i].hit.status)
                            {
                                if (ang[i].pos.x <= player.pos.x + player.pos.width + 200)
                                {
                                    if (ang[i].pos.x >= player.pos.x - 200)
                                    {
                                        if (ang[i].pos.y <= player.pos.y + player.pos.height + 200)
                                        {
                                            if (ang[i].pos.y >= player.pos.y - 200)
                                            {
                                                // random=rand()%MAXANGUILAHIT;
                                                AngElectro(ang[i]);
                                            }
                                        }
                                    }
                                }
                            }
                        }

                        //** comporamiento descarga electrica ************************************************************************************
                        if (ang[i].status)
                        {
                            if (ang[i].hit.status)
                            {
                                if (ang[i].hit.time < 120)
                                {
                                    ang[i].hit.pos.y = ang[i].pos.y - ang[i].pos.height;
                                    ang[i].hit.pos.x = ang[i].pos.x - 21;
                                    ang[i].hit.time++;

                                    // colision con jugador
                                    if (player.vida.time > INVULERABILIDAD)
                                    {
                                        if (CheckPlayerColision(player.pos, ang[i].hit.pos))
                                        {
                                            PlaySound(anguilasound);
                                            if (player.vida.num < 1)
                                            {
                                                piezac = 0;
                                                time = 0;
                                                muerteLvl1(player, shark, tort, ang, pieza, plat);
                                                PlaySound(anguilasound);
                                            }
                                            else
                                            {
                                                player.vida.num--;
                                                player.vida.time = 0;
                                            }
                                            i = MAXANGUILA;
                                        }
                                    }
                                }
                                else
                                {
                                    ang[i].hit.status = 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (ang[i].left)
                        { // movimiento
                            if (ang[i].pos.y < 75)
                            {
                                ang[i].pos.x += ANGUILASPEED;
                            }
                            else
                            {
                                if (ang[i].pos.y > SUELO - 50 - ang[i].pos.height)
                                {
                                    ang[i].pos.x += ANGUILASPEED;
                                }
                                else
                                {
                                    PosicionObieto(ang[i].v.vx, ang[i].v.vy, ang[i].pos);
                                }
                            }
                            // eliminacion
                            if (ang[i].pos.x > RANCHO + ang[i].pos.width)
                            {
                                ang[i].status = 0;
                            }
                        }
                    }

                    // Colision con golpe
                    if (hit)
                    {
                        for (j = 0; j < MAXHIT; j++)
                        {
                            if (CheckMobColision(ang[i].pos, hit[j]))
                            {
                                ang[i].status = 0;
                                ang[i].hit.status = 0;
                            }
                        }
                    }

                    // Colision con iugador
                    if (ang[i].status)
                    {
                        if (player.vida.time > INVULERABILIDAD)
                        {
                            if (CheckPlayerColision(player.pos, ang[i].pos))
                            {
                                PlaySound(dolor);
                                if (player.vida.num < 1)
                                {
                                    piezac = 0;
                                    time = 0;
                                    muerteLvl1(player, shark, tort, ang, pieza, plat);
                                }
                                else
                                {
                                    player.vida.num--;
                                    player.vida.time = 0;
                                }
                                i = MAXANGUILA;
                            }
                        }
                    }
                }
                else
                {
                    // generacion
                    random = (rand() % 50) + 1;
                    if (random == 1)
                    {
                        ang[i].right = rand() % 2;
                        if (ang[i].right)
                        {
                            ang[i].status = 1;
                            ang[i].pos.x = RANCHO;
                            ang[i].pos.y = (rand() % 550) + 60;
                            CalculaComponentesVelocidad(ANGUILASPEED, CalculaAnguloAnguila(ang[i].pos, player.pos), ang[i].v);
                            ang[i].left = 0;
                        }
                        else
                        {
                            ang[i].status = 1;
                            ang[i].pos.x = 0 - ang[i].pos.width;
                            ang[i].pos.y = (rand() % 550) + 60;
                            CalculaComponentesVelocidad(ANGUILASPEED, CalculaAnguloAnguila(ang[i].pos, player.pos), ang[i].v);
                            ang[i].left = 1;
                        }
                    }
                }
            }

            //** dash **************************************************************************************************************************
            if (player.dash)
            {
                if (player.timeDash < 20)
                {
                    if (lookR)
                    {
                        if (lookUp)
                        {
                            player.pos.x += VDDIAGONAL;
                            player.pos.y -= VDDIAGONAL;
                        }
                        else
                        {
                            if (lookDown)
                            {
                                player.pos.x += VDDIAGONAL;
                                player.pos.y += VDDIAGONAL;
                            }
                            else
                            {
                                player.pos.x += VD;
                            }
                        }
                    }
                    else
                    {
                        if (lookL)
                        {
                            if (lookUp)
                            {
                                player.pos.x -= VDDIAGONAL;
                                player.pos.y -= VDDIAGONAL;
                            }
                            else
                            {
                                if (lookDown)
                                {
                                    player.pos.x -= VDDIAGONAL;
                                    player.pos.y += VDDIAGONAL;
                                }
                                else
                                {
                                    player.pos.x -= VD;
                                }
                            }
                        }
                        else
                        {
                            if (lookUp)
                            {
                                player.pos.y -= VD;
                            }
                            else
                            {
                                if (lookDown)
                                {
                                    player.pos.y += VD;
                                }
                            }
                        }
                    }
                }
                else
                {
                    lookDown = 0;
                    lookUp = 0;
                    player.dash = 0;
                }
            }

            //** hit ********************************************************************************************************************************
            for (i = 0; i < MAXHIT; i++)
            {
                //** movimiento del disparo ***********************************************************************************
                if (hit[i].status)
                {
                    PosicionObieto(hit[i].v.vx, hit[i].v.vy, hit[i].pos);

                    //** Eliminacion del proyectil *******************************************************************************
                    // si se paso del borde izquierdo
                    if (hit[i].pos.x < 0 - hit[i].pos.width)
                    {
                        hit[i].status = 0;
                    }
                    else
                    {
                        // si se paso del borde derecho
                        if (hit[i].pos.x > RANCHO)
                        {
                            hit[i].status = 0;
                        }
                    }

                    if (hit[i].pos.y < 0)
                    {
                        hit[i].status = 0;
                    }
                    else
                    {
                        if (hit[i].pos.y > RALTO)
                        {
                            hit[i].status = 0;
                        }
                    }
                }
            }

            //** input *****************************************************************************************************************************
            if (!player.dash) // right left
            {
                if (IsKeyDown(KEY_RIGHT))
                {
                    player.x0 = player.pos.x;
                    player.pos.x += VX;
                    lookR = 1;
                    lookL = 0;
                }
                else
                {
                    if (IsKeyDown(KEY_LEFT))
                    {
                        player.x0 = player.pos.x;
                        player.pos.x -= VX;
                        lookR = 1;
                        lookL = 0;
                    }
                }
            }

            if (!player.dash) // up down
            {
                if (IsKeyDown(KEY_UP))
                {
                    player.pos.y -= VY;
                }
                else
                {
                    if (IsKeyDown(KEY_DOWN))
                    {
                        player.pos.y += VY;
                    }
                }
            }

            // dash KEY C
            if (player.timeDash > 80)
            {
                if (!player.dash)
                {
                    if (IsKeyPressed(KEY_C))
                    {
                        PlaySound(sdash);
                        Direccioniugador(lookL, lookR, lookUp, lookDown, player);
                        player.dash = 1;
                        player.timeDash = 0;
                    }
                }
            }

            // hit
            if (IsKeyDown(KEY_X))
            {
                for (i = 0; i < MAXHIT; i++)
                {
                    Direccioniugador(lookL, lookR, lookUp, lookDown, player);
                    if (/*Buff*/ 1) //** Meiora ******************************************************************************************************
                    {
                        if (player.AtkC > VATAQUE)
                        {
                            if (hit[i].status == 0)
                            {
                                hit[i].status = 1;
                                player.AtkC = 0;
                                PlaySound(disparo_nv1);
                                InicializaProyectil(lookL, lookR, lookUp, lookDown, player, hit[i]);
                                CalculaComponentesVelocidad(VPROYECTIL, 45 * hit[i].direccion, hit[i].v);
                                // printf("Direccion = %d l = %d r = %d up = %d down = %d \n",hit[i].direccion,lookL,lookR,lookUp,lookDown);
                                i = MAXHIT;
                            }
                        }
                    }
                    else
                    {
                        if (player.AtkC > VATAQUEBUFF)
                        {
                            if (hit[i].status == 0)
                            {
                                hit[i].status = 1;
                                player.AtkC = 0;
                                PlaySound(disparo_nv1);
                                InicializaProyectil(lookL, lookR, lookUp, lookDown, player, hit[i]);
                                CalculaComponentesVelocidad(VPROYECTIL, 45 * hit[i].direccion, hit[i].v);
                                // printf("Direccion = %d l = %d r = %d up = %d down = %d \n",hit[i].direccion,lookL,lookR,lookUp,lookDown);
                                i = MAXHIT;
                            }
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
            framesTortuga.x = (float)currentFrame * (float)tortuga.width / 6;
            framesTortugaizq.x = (float)currentFrame * (float)tortugaizq.width / 6;
            framesAnguila.x = (float)currentFrame * (float)anguila.width / 6;
            framesAnguilaizq.x = (float)currentFrame * (float)anguilaizq.width / 6;
            framesPulpo.x = (float)currentFrame * (float)pulpo.width / 6;
            framesPulpoizq.x = (float)currentFrame * (float)pulpoizq.width / 6;
            framesReposo.x = (float)currentFrame * (float)reposo.width / 4;
            framesReposoizq.x = (float)currentFrame * (float)reposoizq.width / 4;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            lookR = 1;
            lookL = 0;
            framesPersonaje++;
            if (framesPersonaje >= (60 / framesSpeed))
            {
                framesPersonaje = 0;
                currentPersonaje++;

                if (currentPersonaje > 5)
                {
                    currentPersonaje = 0;
                    // PlaySound(paso);
                }
                framesCaminar.x = (float)currentPersonaje * (float)caminar.width / 6;
            }

            if (IsKeyDown(KEY_X))
            {
                if (IsKeyDown(KEY_DOWN))
                {
                    if (IsKeyDown(KEY_RIGHT))
                    {
                        DrawTexture(ataquesderechos[1], player.pos.x, player.pos.y - 10, WHITE);
                    }
                    else
                        DrawTexture(ataquesderechos[0], player.pos.x, player.pos.y - 10, WHITE);
                    {
                    }
                }
                else if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP))
                {
                    DrawTexture(ataquesderechos[3], player.pos.x - 5, player.pos.y - 30, WHITE);
                }
                else
                {
                    DrawTexture(ataquesderechos[2], player.pos.x, player.pos.y - 10, WHITE);
                }
            }
            else
            {
                DrawTextureRec(caminar, framesCaminar, Vector2{player.pos.x - 20, player.pos.y - 60}, WHITE);
            }
        }
        else if (IsKeyDown(KEY_LEFT))
        {
            lookR = 0;
            lookL = 1;
            framesPersonaje++;
            if (framesPersonaje >= (60 / framesSpeed))
            {
                framesPersonaje = 0;
                currentPersonaje++;

                if (currentPersonaje > 5)
                {
                    currentPersonaje = 0;
                    // PlaySound(paso);
                }
                framesCaminarizq.x = (float)currentPersonaje * (float)caminarizq.width / 6;
            }

            if (IsKeyDown(KEY_X))
            {
                if (IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT))
                {
                    DrawTexture(ataquesizquierdos[1], player.pos.x - 25, player.pos.y - 10, WHITE);
                }
                else if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP))
                {
                    DrawTexture(ataquesizquierdos[3], player.pos.x, player.pos.y - 30, WHITE);
                }
                else
                {
                    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
                    {
                        DrawTextureRec(caminarizq, framesCaminarizq, Vector2{player.pos.x - 80, player.pos.y - 60}, WHITE);
                    }
                    else
                    {
                        DrawTexture(ataquesizquierdos[2], player.pos.x - 32, player.pos.y - 10, WHITE);
                    }
                }
            }
            else
            {
                DrawTextureRec(caminarizq, framesCaminarizq, Vector2{player.pos.x - 80, player.pos.y - 60}, WHITE);
            }
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

        for (i = 0; i < MAXHIT; i++)
        {
            if (hit[i].status)
            {
                DrawTexture(bullet_nv1, hit[i].pos.x, hit[i].pos.y, WHITE);
            }
        }
        // suelo

        // vida
        for (i = 1; i <= player.vida.num; i++)
        {
            DrawTexture(corazon, player.vida.pos.x, player.vida.pos.y, WHITE);
            player.vida.pos.x += 25 + player.vida.pos.width;
        }
        player.vida.pos.x = 25;

        // enemigos
        for (i = 0; i < MAXSHARK; i++)
        {
            if (shark[i].status)
            {
                if (shark[i].right)
                {
                    // DrawRectangleRec(shark[i].pos, RED);
                    DrawTextureRec(pulpoizq, framesPulpoizq, Vector2{shark[i].pos.x - 25, shark[i].pos.y - 20}, WHITE);
                }

                if (shark[i].left)
                {
                    // DrawRectangleRec(shark[i].pos, RED);
                    DrawTextureRec(pulpo, framesPulpo, Vector2{shark[i].pos.x + 13, shark[i].pos.y - 20}, WHITE);
                }
            }
        }

        for (i = 0; i < MAXTORTUGA; i++)
        {
            if (tort[i].status)
            {
                if (tort[i].right)
                {
                    DrawTextureRec(tortugaizq, framesTortugaizq, Vector2{tort[i].pos.x - 15, tort[i].pos.y - 50}, WHITE);
                }

                if (tort[i].left)
                {
                    DrawTextureRec(tortuga, framesTortuga, Vector2{tort[i].pos.x - 15, tort[i].pos.y - 50}, WHITE);
                }
            }
        }

        for (i = 0; i < MAXANGUILA; i++)
        {
            if (ang[i].status)
            {
                if (!ang[i].hit.status)
                {
                    if (ang[i].left)
                    {
                        // DrawRectangleRec(ang[i].pos, RED);
                        DrawTextureRec(anguila, framesAnguila, Vector2{ang[i].pos.x - 5, ang[i].pos.y - 33}, WHITE);
                    }
                    if (ang[i].right)
                    {
                        // DrawRectangleRec(ang[i].pos, RED);
                        DrawTextureRec(anguilaizq, framesAnguilaizq, Vector2{ang[i].pos.x - 12, ang[i].pos.y - 33}, WHITE);
                    }
                }
                else
                {
                    if (ang[i].left)
                    {
                        framesAtaque++;
                        if (framesAtaque >= (60 / framesSpeed))
                        {
                            framesAtaque = 0;
                            currentAtaque++;

                            if (currentAtaque > 6)
                                currentAtaque = 0;
                            framesAtaque_ani.x = (float)currentAtaque * (float)ataque_ani.width / 6;
                            framesAtaque_anizq.x = (float)currentAtaque * (float)ataque_anizq.width / 6;
                        }
                        PlaySound(anguilasound);
                        DrawTextureRec(ataque_ani, framesAtaque_ani, Vector2{ang[i].hit.pos.x - 12, ang[i].pos.y - 33}, WHITE);
                    }
                    if (ang[i].right)
                    {
                        framesAtaque++;
                        if (framesAtaque >= (60 / framesSpeed))
                        {
                            framesAtaque = 0;
                            currentAtaque++;

                            if (currentAtaque > 6)
                                currentAtaque = 0;
                            framesAtaque_ani.x = (float)currentAtaque * (float)ataque_ani.width / 6;
                            framesAtaque_anizq.x = (float)currentAtaque * (float)ataque_anizq.width / 6;
                        }
                        DrawTextureRec(ataque_anizq, framesAtaque_anizq, Vector2{ang[i].hit.pos.x - 12, ang[i].pos.y - 33}, WHITE);
                    }
                }
            }
        }
        // piezas
        for (i = 0; i < 3; i++)
        {
            if (pieza[i].status)
            {
                DrawTexture(piezas_nv1[i], pieza[i].pos.x, pieza[i].pos.y, WHITE);
            }
        }
        // plataformas
        for (i = 0; i < MAXPLAT; i++)
        {
            DrawTexture(plataforma_nv1, plat[i].x, plat[i].y, WHITE);
            // DrawRectangleRec(plat[i], DARKGREEN);
        }
        EndMode2D();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}

void Direccioniugador(int &L, int &R, int &Up, int &Down, Tplayer player)
{
    if (IsKeyDown(KEY_RIGHT))
    {
        if (IsKeyDown(KEY_UP))
        {
            R = 1;
            Up = 1;
            Down = 0;
            L = 0;
        }
        else
        {
            if (IsKeyDown(KEY_DOWN))
            {
                R = 1;
                Up = 0;
                Down = 1;
                L = 0;
            }
            else
            {
                R = 1;
                Up = 0;
                Down = 0;
                L = 0;
            }
        }
    }
    else
    {
        if (IsKeyDown(KEY_LEFT))
        {
            if (IsKeyDown(KEY_UP))
            {
                R = 0;
                Up = 1;
                Down = 0;
                L = 1;
            }
            else
            {
                if (IsKeyDown(KEY_DOWN))
                {
                    R = 0;
                    Up = 0;
                    Down = 1;
                    L = 1;
                }
                else
                {
                    R = 0;
                    Up = 0;
                    Down = 0;
                    L = 1;
                }
            }
        }
        else
        {
            if (IsKeyDown(KEY_UP))
            {
                R = 0;
                Up = 1;
                Down = 0;
                L = 0;
            }
            else
            {
                if (IsKeyDown(KEY_DOWN))
                {
                    R = 0;
                    Up = 0;
                    Down = 1;
                    L = 0;
                }
                else
                {
                    if (player.x0 <= player.pos.x)
                    {
                        R = 1;
                        Up = 0;
                        Down = 0;
                        L = 0;
                    }
                    else
                    {
                        R = 0;
                        Up = 0;
                        Down = 0;
                        L = 1;
                    }
                }
            }
        }
    }
}

void InicializaProyectil(int L, int R, int Up, int Down, Tplayer player, Thit &hit)
{
    hit.pos.y = player.pos.y + player.pos.height / 4;
    hit.pos.x = player.pos.x + player.pos.width / 2;
    if (R)
    {
        if (Up)
        {
            hit.direccion = 1;
        }
        else
        {
            if (Down)
            {
                hit.direccion = 7;
            }
            else
            {
                hit.direccion = 0;
            }
        }
    }
    else
    {
        if (L)
        {
            if (Up)
            {
                hit.direccion = 3;
            }
            else
            {
                if (Down)
                {
                    hit.direccion = 5;
                }
                else
                {
                    hit.direccion = 4;
                }
            }
        }
        else
        {
            if (Up)
            {
                hit.direccion = 2;
            }
            else
            {
                if (Down)
                {
                    hit.direccion = 6;
                }
            }
        }
    }
}

void CalculaComponentesVelocidad(float velocidad, float grados, Tvel &v)
{
    if (grados >= 360)
    {
        grados -= 360;
    }

    v.vy = velocidad * sin(Radianes(grados));
    v.vx = sqrt((pow(velocidad, 2) - pow(v.vy, 2)));
    if (grados <= 90)
    {
        v.vy = -v.vy;
    }
    else
    {
        if (grados <= 180)
        {
            v.vx = -v.vx;
            v.vy = -v.vy;
        }
        else
        {
            if (grados <= 270)
            {
                v.vx = -v.vx;
                v.vy = -v.vy;
            }
            else
            {
                v.vy = -v.vy;
            }
        }
    }
}

float Radianes(float grados)
{
    return (grados * M_PI / 180);
}

void PosicionObieto(float vx, float vy, Trec &pos)
{
    pos.x += vx;
    pos.y += vy;
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

int CheckMobColision(Trec mob, Thit hit)
{
    if (mob.x < (hit.pos.x + hit.pos.width))
    {
        if ((mob.x + mob.width) > hit.pos.x)
        {
            if (mob.y < (hit.pos.y + hit.pos.height))
            {
                if ((mob.y + mob.height) > hit.pos.y)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void LimpiaEnemigosLvl1(Tshark shark[], Ttortu tort[], Tangui ang[])
{
    int i;
    for (i = 0; i < MAXSHARK; i++)
    {
        shark[i].status = 0;
    }
    for (i = 0; i < MAXTORTUGA; i++)
    {
        tort[i].status = 0;
    }
    for (i = 0; i < MAXANGUILA; i++)
    {
        ang[i].status = 0;
        ang[i].hit.status = 0;
    }
}

float CalculaAnguloAnguila(Trec ang, Trec player)
{
    float difx = fabs(player.x + player.width / 2 - ang.x);
    float dify = fabs(player.y + player.height / 2 - ang.y);
    float a = atan2(difx, dify);
    a = a * 180 / M_PI;
    if (player.x > ang.x)
    {
        if (player.y > ang.y)
        {
            return (270 + a);
        }
        else
        {
            return (90 - a);
        }
    }
    else
    {
        if (player.y > ang.y)
        {
            return (270 - a);
        }
        else
        {
            return (90 + a);
        }
    }
    return 0;
}

void AngElectro(Tangui &ang)
{
    ang.hit.pos.y = ang.pos.y - ang.pos.height;
    ang.hit.pos.x = ang.pos.x - 21;
    ang.hit.status = 1;
    ang.hit.time = 0;
}

void muerteLvl1(Tplayer &player, Tshark shark[], Ttortu tort[], Tangui ang[], Tpart pieza[], Trec plat[])
{
    int j;
    player.pos.x = 400;   // Posicion incial
    player.pos.y = SUELO; //""
    player.timeDash = 70;
    player.vida.num = MAXVIDA;
    LimpiaEnemigosLvl1(shark, tort, ang);
    for (j = 0; j < 3; j++)
    {
        pieza[j].status = 1;
        pieza[j].listo = 0;
        pieza[j].pos.x = plat[j].x + plat[j].width / 2 - pieza[j].pos.width / 2;
        pieza[j].pos.y = -300;
    }
}

void cinemaPuzleNivel1(void)
{
    int i, j;
    int random;
    Ttab tabla[RENGLONES1][COLUMNAS1];
    //+ - * /
    char operadores[4][2] = {"+", "-", "*", "/"};

    for (i = 0; i < RENGLONES1; i++)
    {
        tabla[i][COLUMNAS1].opDown[0] = '=';
        tabla[i][COLUMNAS1].opDown[1] = '\0';
    }
    for (i = 0; i < COLUMNAS1; i++)
    {
        tabla[RENGLONES1][i].opDown[0] = '=';
        tabla[RENGLONES1][i].opDown[1] = '\0';
    }

    for (i = 0; i < RENGLONES1; i++)
    {
        for (j = 0; j < COLUMNAS1; j++)
        {
            if (i == RENGLONES1 - 1)
            {
            }
            if (j = COLUMNAS1 - 1)
            {
            }
            random = rand() % 10;
            if (random % 2 == 0)
            {
                if (j < COLUMNAS1 - 1)
                {

                    tabla[i][j].status = 1;
                    tabla[i][j].num = rand() % 20;
                    if (i < RENGLONES1 - 1)
                    {
                        if (j < COLUMNAS1 - 1)
                        {
                            strcpy(tabla[i][j].opDown, operadores[rand() % 4]);
                            strcpy(tabla[i][j].opRight, operadores[rand() % 4]);
                        }
                    }
                }
            }
            else
            {
                tabla[i][j].status = 0;
                tabla[i][j].num = rand() % 20;
                if (i < RENGLONES1 - 1)
                {
                    if (j < COLUMNAS1 - 1)
                    {
                        strcpy(tabla[i][j].opDown, operadores[rand() % 4]);
                        strcpy(tabla[i][j].opRight, operadores[rand() % 4]);
                    }
                }
            }
        }
    }
    ClearBackground(WHITE);
    while (1)
    {

        printf("\nGanaste\n");
    }
}