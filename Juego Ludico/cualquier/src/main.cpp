#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RANCHO 1280
#define RALTO 720
#define CAMX 640
#define CAMY 360

#define ALTOP 60
#define ANCHOP 50
#define SUELO 650
#define MAXVIDA 4
#define INVULERABILIDAD 120

#define G 0.1
#define GD 0.15

#define VX 3
#define VS -11
#define VSJ -4
#define VY -3
#define VD 6

// DROPS
#define MAXDROPVIDA 10
#define DESPAWNTIME 600
#define MAXDROPASPEED 10
#define DURACIONBUFF 300
// lvl3
#define RECVEHICULO 900

#define MAXTORRE 2
#define TORREASPEED 180
#define TORREVPROYECTIL 6
#define MAXHITTORRE 2
#define MAXOVNI 2
#define OVNISPEED 3
#define OVNILONG 150
#define OVNIAMP 15

#define MAXPLAT 4
#define MAXHIT 5
#define VATAQUE 60
#define VATAQUEBUFF 30
#define VPROYECTIL 10.0

// blank transparente

// typedef Rectangle Tplayer;

typedef Rectangle Trec;

typedef struct _velocidad
{
    float vx;
    float vy;
} Tvel;

typedef struct _hit
{
    Trec pos;
    int time;      // 7   0    1
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
    int y0;
    float v0;
    int timeDash;
    int jump;
    int jumpjump;
    int fall;
    int jet;
    int jetc;
    int x0;
    int AtkC;
    int buff = 0;
    Tvida vida;
} Tplayer;

typedef struct _tower
{
    Trec pos;
    int status;
    int direccion;
    int atkC;
    Thit hit[MAXHITTORRE];
} Ttow;

typedef struct _ovni
{
    Trec pos;
    int direccion;
    int status;
    int time;
} Tovni;

typedef struct _Elaser
{
    Trec pos;
    int status;
    int atkC;
    float grados;
    float altura;
    Trec hit;
    int time;
    int mov;
} Tlaser;

typedef struct _ASbuff
{
    Trec pos;
    int statusDraw;
    int statusFun;
    int time;
    int duracion;
} TatkSpeed;

typedef struct _corazon
{
    Trec pos;
    int status;
    int time;
} Tcora;

float velocidad(float v0, float time);
int ColisionPlat(Tplayer player, Tplat plat);
// devuelve 0
int Reposo(float &time, float &v0, int &y0, int y);

int Salto(float &time, float &v0, int &y0, int y);

// y0+v0*time+GD*time*time;
int Posicion(int y0, float v0, float time, int g);
int CheckMobColision(Trec mob, Trec hit);
int CheckPlayerColision(Trec player, Trec mob);
// int CheckPiezaColision(Trec player,Trec mob); // duplicado para probar sin daño
void LimpiaEnemigosLvl3(Ttow torre[], Tovni ovni[]);
int JetPack(float &time, float &v0, int &y0, int y, int bdown);
void InicializaProyectil(int L, int R, int Up, int Down, Tplayer player, Thit &hit);
void CalculaComponentesVelocidad(float velocidad, float grados, Tvel &v);
float Radianes(float grados);
void PosicionObieto(float vx, float vy, Trec &pos);
void Direccioniugador(int &L, int &R, int &Up, int &Down, Tplayer player);
float CalculaAngulo(Trec ang, Trec player);
void muerteLvl3(Tplayer &player, Ttow torre[], Tovni ovni[], Tpart pieza[], Tplat plat[]);
void cinemaPuzleNivel3(void);

int main()
{

    SetTargetFPS(60);
    InitWindow(RANCHO, RALTO, "juego");
    srand(time(NULL));
    int j, i, k;
    int y0Cam;

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
    int dash = 0;

    int fin = 0;

    // auxiliar
    int random;
    Trec aux;
    aux.height = 20;
    aux.width = 20;
    float grados;

    // Inicializacion ***************************************************************************************
    // Inicializacion Plataformas
    Tplat plat[MAXPLAT];
    for (i = 0; i < MAXPLAT; i++)
    {
        plat[i].pos.height = 30;
        plat[i].pos.width = 322;
        plat[i].status = 1;
        plat[i].flag = 0;
    }
    plat[0].pos.x = RANCHO - plat[1].pos.width - 300;
    plat[0].pos.y = 450;
    plat[1].pos.x = 100;
    plat[1].pos.y = 250;
    plat[2].pos.x = 800;
    plat[2].pos.y = -50;
    plat[3].pos.x = 250;
    plat[3].pos.y = -400;

    //** piezas **********************************************************************************************************************************
    Tpart pieza[3];

    for (j = 0; j < 3; j++)
    {
        pieza[j].status = 1;
        pieza[j].pos.height = 181;
        pieza[j].pos.width = 63;
        pieza[j].pos.x = plat[j + 1].pos.x + plat[j + 1].pos.width / 2 - pieza[j].pos.width / 2;
        pieza[j].pos.y = -1500;
        pieza[j].listo = 0;
    }

    int piezac = 0;
    int hitb = 0;
    // Inicializa la posicion
    Tplayer player;
    player.pos.height = ALTOP + 10;
    player.pos.width = 25;
    player.pos.x = CAMX - player.pos.width; // Posicion incial
    player.pos.y = SUELO;                   //""
    player.y0 = player.pos.y;
    player.v0 = 0;
    player.timeDash = 70;
    player.AtkC = 0;

    // vida
    player.vida.num = MAXVIDA;
    player.vida.pos.width = 25;
    player.vida.pos.height = 25;
    player.vida.pos.x = 30;
    player.vida.pos.y = 30;
    player.vida.time = 0;

    // Inicializacion enemigos
    Ttow torre[MAXTORRE];
    for (j = 0; j < MAXTORRE; j++)
    {
        torre[j].status = 0;
        torre[0].direccion = 0;
        torre[1].direccion = 1;
        torre[j].pos.x = 2000;
        torre[j].pos.y = 800;
        torre[j].pos.height = 40;
        torre[j].pos.width = 60;
        torre[j].atkC = 0;
        for (i = 0; i < MAXHITTORRE; i++)
        {
            torre[j].hit[i].status = 0;
            torre[j].hit[i].pos.x = 0;
            torre[j].hit[i].pos.y = 1500;
            torre[j].hit[i].pos.height = 20;
            torre[j].hit[i].pos.width = 20;
        }
    }

    Tovni ovni[MAXOVNI];
    for (i = 0; i < MAXOVNI; i++)
    {
        ovni[i].pos.height = 35;
        ovni[i].pos.width = 60;
        ovni[i].pos.x = 0;
        ovni[i].pos.y = 1300;
        ovni[i].status = 0;
    }
    ovni[0].direccion = 1;
    ovni[1].direccion = 0;

    Tlaser laser;
    laser.pos.height = 114;
    laser.pos.width = 168;
    laser.pos.x = player.pos.x;
    laser.pos.y = 1500;
    laser.status = 0;
    laser.atkC = 0;
    laser.mov = 1;
    laser.hit.height = 10;
    laser.hit.width = 3000;

    Thit hit[MAXHIT];
    for (i = 0; i < MAXHIT; i++)
    {
        hit[i].status = 0;
        hit[i].pos.width = RANCHO;
        hit[i].pos.height = 25;
        hit[i].pos.x = 1280;
        hit[i].pos.y = 1500;
    }

    Tcora dropVida[MAXDROPVIDA];

    for (i = 0; i < MAXDROPVIDA; i++)
    {
        dropVida[i].pos.width = 30;
        dropVida[i].pos.height = 30;
        dropVida[i].status = 0;
        dropVida[i].time = 0;
    }

    TatkSpeed dropASpeed[MAXDROPASPEED];
    for (i = 0; i < MAXDROPASPEED; i++)
    {
        dropASpeed[i].pos.width = 80;
        dropASpeed[i].pos.height = 60;
        dropASpeed[i].statusDraw = 0;
        dropASpeed[i].statusFun = 0;
        dropASpeed[i].time = 0;
        dropASpeed[i].duracion = DURACIONBUFF;
    }

    // Inicializacion camara
    Camera2D camara = {0};
    camara.target.x = 0;
    camara.target.y = 0;
    camara.offset.x = 0;
    camara.offset.y = 0;
    camara.rotation = 0;
    camara.zoom = 1;
    Vector2 org;
    Vector2 org1;
    Trec temp;

    // inicializacion para dibujado

    int framesAutom = 0;

    int framesSpeed = 8;
    int currentFrame = 0;

    int currentPersonaje = 0;
    int framesPersonaje = 0;

    int currentSalto = 0;
    int framesSalto = 0;
    /******************************************************** CARGAR TEXTURAS **************************************************************/
    Texture2D morado = LoadTexture("texturas\\ovni.png");
    Texture2D bala = LoadTexture("texturas\\balalvl3.png");
    Texture2D suelo = LoadTexture("texturas\\suelo3.png");
    Texture2D fondo = LoadTexture("texturas\\luna.png");
    Texture2D plat3 = LoadTexture("texturas\\plat3.png");
    Texture2D corazon = LoadTexture("texturas\\corazon.png");
    Texture2D laserG = LoadTexture("texturas\\laserGreen.png");
    Texture2D laserM = LoadTexture("texturas\\laserMorado.png");
    Texture2D Aspeed = LoadTexture("texturas\\AtkSpeed.png");

    Texture2D nave[3];
    nave[0] = LoadTexture("texturas\\pieza1_3.png");
    nave[1] = LoadTexture("texturas\\pieza2_3.png");
    nave[2] = LoadTexture("texturas\\pieza3_3.png");

    Texture2D towl[9];
    towl[0] = LoadTexture("texturas\\torrel270.png");
    towl[1] = LoadTexture("texturas\\torrel292.png");
    towl[2] = LoadTexture("texturas\\torrel315.png");
    towl[3] = LoadTexture("texturas\\torrel337.png");
    towl[4] = LoadTexture("texturas\\torrel0.png");
    towl[5] = LoadTexture("texturas\\torrel22.png");
    towl[6] = LoadTexture("texturas\\torrel45.png");
    towl[7] = LoadTexture("texturas\\torrel67.png");
    towl[8] = LoadTexture("texturas\\torrel90.png");
    Texture2D towr[9];
    towr[0] = LoadTexture("texturas\\torrer270.png");
    towr[1] = LoadTexture("texturas\\torrer247.png");
    towr[2] = LoadTexture("texturas\\torrer225.png");
    towr[3] = LoadTexture("texturas\\torrer192.png");
    towr[4] = LoadTexture("texturas\\torrer180.png");
    towr[5] = LoadTexture("texturas\\torrer158.png");
    towr[6] = LoadTexture("texturas\\torrer135.png");
    towr[7] = LoadTexture("texturas\\torrer112.png");
    towr[8] = LoadTexture("texturas\\torrer90.png");

    // jugador
    Texture2D jet[2];
    jet[0] = LoadTexture("texturas\\jetL.png");
    jet[1] = LoadTexture("texturas\\jetR.png");

    Texture2D hitR[3];
    hitR[0] = LoadTexture("texturas\\HitR0.png");
    hitR[1] = LoadTexture("texturas\\HitR1.png");
    hitR[2] = LoadTexture("texturas\\HitR2.png");
    Texture2D hitL[3];
    hitL[0] = LoadTexture("texturas\\HitL0.png");
    hitL[1] = LoadTexture("texturas\\HitL1.png");
    hitL[2] = LoadTexture("texturas\\HitL2.png");
    Texture2D laserRed[2];
    laserRed[1] = LoadTexture("texturas\\laserR.png");
    laserRed[0] = LoadTexture("texturas\\laserL.png");

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

    //**************************************************** CARGAR AUDIOS *******************************************************************

    InitAudioDevice();

    Sound dolor = LoadSound("sonidos/danio.wav");
    Sound RecPieza = LoadSound("sonidos/pieza.wav");
    Sound las = LoadSound("sonidos/laser.wav");
    Sound brinco = LoadSound("sonidos/salto.mp3");
    Sound sdash = LoadSound("sonidos/paso1.wav");
    Sound jetpack = LoadSound("sonidos/jetpack.mp3");
    Sound orbita = LoadSound("sonidos/oribita_nv3.mp3");
    Sound ovni_laser = LoadSound("sonidos/laser_ovni.mp3");
    Sound canion = LoadSound("sonidos/canion.mp3");
    Music musica_nv3 = LoadMusicStream("sonidos/nivel3_musica.mp3");

    SetSoundVolume(sdash, +10.0f);
    SetSoundVolume(jetpack, -0.5f);
    SetSoundVolume(orbita, -0.3f);
    SetMusicVolume(musica_nv3, -1.2);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        BeginMode2D(camara);
        time += 0.5;
        igncolision += 1;
        frameC++;
        player.timeDash++;
        player.AtkC++;
        player.vida.time++;

        torre[0].atkC++;
        torre[1].atkC++;

        //** terminar el nivel ***********************************************************************************
        if (pieza[0].status)
        {
            if (pieza[0].pos.y == SUELO - pieza[0].pos.height)
            {
                if (pieza[1].status)
                {
                    if (pieza[1].pos.y == SUELO - pieza[1].pos.height)
                    {
                        if (pieza[2].status)
                        {
                            if (pieza[2].pos.y == SUELO - pieza[2].pos.height)
                            {
                                if (!fin)
                                {
                                    time = 0;
                                }
                                fin = 1;
                                LimpiaEnemigosLvl3(torre, ovni);
                                if (time > 300)
                                {
                                    cinemaPuzleNivel3();
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
            //** reajusta posicion x ****************************************************************************************************
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

            //** reajusta posicion y ***************************************************************************************
            if (player.pos.y < -900)
            {
                player.pos.y = -900;
            }

            //** pieza **************************************************************************************************************************
            for (j = 0; j < 3; j++)
            {
                // drop
                if (pieza[j].listo)
                {
                    if (!pieza[j].status)
                    {
                        if (CheckPlayerColision(player.pos, pieza[j].pos))
                        {
                            pieza[j].status = 1;
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
                            PlaySound(RecPieza);
                            pieza[j].status = 0;
                            pieza[j].listo = 1;
                            pieza[j].pos.y = SUELO - pieza[j].pos.height;
                            piezac++;
                            switch (j)
                            {
                            case 0:
                                pieza[j].pos.x = 150;
                                break;
                            case 1:
                                pieza[j].pos.x = 213;
                                break;
                            case 2:
                                pieza[j].pos.x = 276;
                                break;
                            }
                            j = 3;
                        }
                    }
                }
            }

            // movimiento piezas
            if (frameC > 300)
            {
                if (!pieza[0].listo)
                {
                    if (pieza[0].status)
                    {
                        if (pieza[0].pos.y < plat[1].pos.y - pieza[0].pos.height)
                        {
                            pieza[0].pos.y += 4;
                        }
                        else
                        {
                            if (piezac < 1)
                            {
                                pieza[0].pos.y = plat[1].pos.y - pieza[0].pos.height;
                            }
                        }
                    }
                }
                if (frameC > 600)
                {
                    if (!pieza[1].listo)
                    {
                        if (pieza[1].status)
                        {
                            if (pieza[1].pos.y < plat[2].pos.y - pieza[1].pos.height)
                            {
                                pieza[1].pos.y += 4;
                            }
                            else
                            {
                                if (piezac < 2)
                                {
                                    pieza[1].pos.y = plat[2].pos.y - pieza[1].pos.height;
                                }
                            }
                        }
                    }

                    if (frameC > 900)
                    {
                        if (!pieza[2].listo)
                        {
                            if (pieza[2].status)
                            {
                                if (pieza[2].pos.y < plat[3].pos.y - pieza[2].pos.height)
                                {
                                    pieza[2].pos.y += 4;
                                }
                                else
                                {
                                    if (piezac < 3)
                                    {
                                        pieza[2].pos.y = plat[3].pos.y - pieza[2].pos.height;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            // enemigos

            //** torreta **************************************************************************************************************************
            for (i = 0; i < MAXTORRE; i++)
            {
                if (torre[i].status)
                {
                    // ataque
                    for (j = 0; j < MAXHITTORRE; j++)
                    {
                        if (torre[i].atkC > TORREASPEED)
                        {

                            // disparo
                            if (torre[i].hit[j].status == 0)
                            {
                                if (torre[i].direccion)
                                {
                                    torre[i].hit[j].pos.x = torre[i].pos.x;
                                    torre[i].hit[j].pos.y = torre[i].pos.y;
                                    grados = CalculaAngulo(torre[i].hit[j].pos, player.pos);
                                    CalculaComponentesVelocidad(TORREVPROYECTIL, grados, torre[i].hit[j].v);
                                    torre[i].atkC = 0;
                                    torre[i].hit[j].status = 1;
                                    j = MAXHITTORRE;
                                }
                                else
                                {
                                    torre[i].hit[j].pos.x = torre[i].pos.x + torre[i].pos.width;
                                    torre[i].hit[j].pos.y = torre[i].pos.y;
                                    grados = CalculaAngulo(torre[i].hit[j].pos, player.pos);
                                    CalculaComponentesVelocidad(TORREVPROYECTIL, grados, torre[i].hit[j].v);
                                    torre[i].atkC = 0;
                                    torre[i].hit[j].status = 1;
                                    j = MAXHITTORRE;
                                }
                            }
                        }
                        else
                        {
                            //** ataaque ** movimiento
                            if (torre[i].hit[j].status)
                            {
                                PosicionObieto(torre[i].hit[j].v.vx, torre[i].hit[j].v.vy, torre[i].hit[j].pos);

                                // si se paso del borde izquierdo
                                if (torre[i].hit[j].pos.x < 0 - torre[i].hit[j].pos.width)
                                {
                                    torre[i].hit[j].status = 0;
                                }
                                else
                                {
                                    // si se paso del borde derecho
                                    if (torre[i].hit[j].pos.x > RANCHO)
                                    {
                                        torre[i].hit[j].status = 0;
                                    }
                                }

                                // colision con jugador
                                if (player.vida.time > INVULERABILIDAD)
                                {
                                    if (CheckPlayerColision(player.pos, torre[i].hit[j].pos))
                                    {
                                        PlaySound(dolor);
                                        if (player.vida.num < 1)
                                        {
                                            piezac = 0;
                                            frameC = 0;
                                            muerteLvl3(player, torre, ovni, pieza, plat);
                                        }
                                        else
                                        {
                                            player.vida.num--;
                                            player.vida.time = 0;
                                        }
                                        j = MAXHITTORRE;
                                    }
                                }
                            }
                        }
                    }

                    // Colision con golpe (enemigo)
                    for (j = 0; j < MAXHIT; j++)
                    {
                        if (hit[j].status)
                        {
                            if (hit[j].time > 10)
                            {
                                if (CheckMobColision(torre[i].pos, hit[j].pos))
                                {
                                    torre[i].status = 0;
                                    random = rand() % 10 + 1;
                                    if (random <= 4)
                                    {
                                        random = rand() % 2;
                                        if (random)
                                        {
                                            for (k = 0; k < MAXDROPVIDA; k++)
                                            {
                                                if (!dropVida[k].status)
                                                {
                                                    dropVida[k].status = 1;
                                                    dropVida[k].time = 0;
                                                    dropVida[k].pos.x = torre[i].pos.x;
                                                    dropVida[k].pos.y = torre[i].pos.y;
                                                    k = MAXDROPVIDA;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            for (k = 0; k < MAXDROPASPEED; k++)
                                            {
                                                if (!dropASpeed[k].statusDraw)
                                                {
                                                    if (!dropASpeed[k].statusFun)
                                                    {
                                                        dropASpeed[k].statusDraw = 1;
                                                        dropASpeed[k].statusFun = 0;
                                                        dropASpeed[k].time = 0;
                                                        dropASpeed[k].pos.x = torre[i].pos.x;
                                                        dropASpeed[k].pos.y = torre[i].pos.y;
                                                        k = MAXDROPASPEED;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    // Colision con jugador (enemigo)
                    if (player.vida.time > INVULERABILIDAD)
                    {
                        if (CheckPlayerColision(player.pos, torre[i].pos))
                        {
                            PlaySound(dolor);
                            if (player.vida.num < 1)
                            {
                                piezac = 0;
                                frameC = 0;
                                muerteLvl3(player, torre, ovni, pieza, plat);
                            }
                            else
                            {
                                player.vida.num--;
                                player.vida.time = 0;
                            }
                            i = MAXTORRE;
                        }
                    }
                }
                else
                {
                    // generacion
                    random = (rand() % 300) + 1;
                    if (random == 1)
                    {
                        if (torre[i].direccion)
                        {
                            torre[i].status = 1;
                            torre[i].pos.x = RANCHO - torre[i].pos.width - 10;
                            torre[i].pos.y = 50;
                            for (j = 0; j < MAXHITTORRE; j++)
                            {
                                torre[i].hit[j].status = 0;
                            }
                        }
                        else
                        {
                            torre[i].status = 1;
                            torre[i].pos.x = 10;
                            torre[i].pos.y = 50;
                            for (j = 0; j < MAXHITTORRE; j++)
                            {
                                torre[i].hit[j].status = 0;
                            }
                        }
                    }
                }
            }

            //** ovni ************************************************************************************************************
            for (i = 0; i < MAXOVNI; i++)
            {
                // comportameinto
                if (ovni[i].status)
                {
                    ovni[i].time++;
                    // movimiento enemigo **si sale de la pantalla se elimina**
                    if (ovni[i].direccion)
                    { // movimiento
                        ovni[i].pos.x -= OVNISPEED;
                        ovni[i].pos.y += OVNIAMP * cos(2 * M_PI / OVNILONG * ovni[i].time);

                        if (ovni[i].pos.x <= 0 - ovni[i].pos.width)
                        {
                            ovni[i].status = 0;
                        }
                    }
                    else
                    {
                        // movimiento
                        ovni[i].pos.x += OVNISPEED;
                        ovni[i].pos.y += OVNIAMP * cos(2 * M_PI / OVNILONG * ovni[i].time);
                        // eliminacion
                        if (ovni[i].pos.x > RANCHO + ovni[i].pos.width)
                        {
                            ovni[i].status = 0;
                        }
                    }

                    // Colision con golpe
                    for (j = 0; j < MAXHIT; j++)
                    {
                        if (hit[j].status)
                        {
                            if (hit[i].time > 10)
                            {
                                if (CheckMobColision(ovni[i].pos, hit[j].pos))
                                {
                                    ovni[i].status = 0;
                                    random = rand() % 10 + 1;
                                    if (random <= 4)
                                    {
                                        random = rand() % 2;
                                        if (random)
                                        {
                                            for (k = 0; k < MAXDROPVIDA; k++)
                                            {
                                                if (!dropVida[k].status)
                                                {
                                                    dropVida[k].status = 1;
                                                    dropVida[k].time = 0;
                                                    dropVida[k].pos.x = ovni[i].pos.x;
                                                    dropVida[k].pos.y = ovni[i].pos.y;
                                                    k = MAXDROPVIDA;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            for (k = 0; k < MAXDROPASPEED; k++)
                                            {
                                                if (!dropASpeed[k].statusDraw)
                                                {
                                                    if (!dropASpeed[k].statusFun)
                                                    {
                                                        dropASpeed[k].statusDraw = 1;
                                                        dropASpeed[k].statusFun = 0;
                                                        dropASpeed[k].time = 0;
                                                        dropASpeed[k].pos.x = ovni[i].pos.x;
                                                        dropASpeed[k].pos.y = ovni[i].pos.y;
                                                        k = MAXDROPASPEED;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                    // Colision con iugador
                    if (ovni[i].status)
                    {

                        if (player.vida.time > INVULERABILIDAD)
                        {
                            if (CheckPlayerColision(player.pos, ovni[i].pos))
                            {
                                PlaySound(dolor);
                                if (player.vida.num < 1)
                                {
                                    piezac = 0;
                                    frameC = 0;
                                    muerteLvl3(player, torre, ovni, pieza, plat);
                                }
                                else
                                {
                                    player.vida.num--;
                                    player.vida.time = 0;
                                }
                                i = MAXOVNI;
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
                        if (ovni[i].direccion)
                        {
                            PlaySound(orbita);
                            ovni[i].status = 1;
                            ovni[i].pos.x = RANCHO;
                            ovni[i].pos.y = player.pos.y;
                            ovni[i].time = 0;
                        }
                        else
                        {
                            PlaySound(orbita);
                            ovni[i].status = 1;
                            ovni[i].pos.x = 0 - ovni[i].pos.width;
                            ovni[i].pos.y = player.pos.y;
                            ovni[i].time = 0;
                        }
                    }
                }
            }

            //** laser ****************************************************************************************************************************
            if (laser.status)
            {
                laser.atkC++;
                // movimiento enemigo **si sale de la pantalla se elimina**
                if (laser.mov)
                {
                    laser.pos.x = RANCHO - player.pos.x - player.pos.width;

                    laser.pos.y = pow(((laser.pos.x - CAMX - laser.pos.width / 2) * 0.02), 2) + SUELO - 600;
                    if (player.pos.y < 400)
                    {
                        laser.pos.y -= fabs(SUELO - player.pos.y);
                        laser.pos.y += 250;
                    }

                    if (laser.pos.x < 0)
                    {
                        laser.pos.x = 0;
                    }
                    else
                    {
                        if (laser.pos.x + laser.pos.width > RANCHO)
                        {
                            laser.pos.x = RANCHO - laser.pos.width;
                        }
                    }
                }

                //** ataque *******************************************************************************************************************
                if (laser.atkC > 240)
                {
                    if (laser.atkC < 360)
                    {
                        if (laser.atkC == 241)
                        {
                            laser.hit.x = laser.pos.x + laser.pos.width / 2;
                            laser.hit.y = laser.pos.y + laser.pos.height / 2;
                            laser.grados = CalculaAngulo(laser.pos, player.pos);
                            laser.mov = 0;
                            laser.time = 0;
                        }
                    }
                    else
                    {
                        laser.time++;
                        if (laser.time < 15)
                        {
                            for (i = 0; i < 1500; i += 10)
                            {

                                if (player.pos.x < laser.pos.x)
                                {
                                    grados = 275 + laser.grados;
                                    aux.x = laser.pos.x + tan(Radianes(grados)) * i;
                                    aux.y = laser.pos.y + i;
                                }
                                else
                                {
                                    grados = 270 - laser.grados;
                                    aux.x = laser.pos.x - tan(Radianes(grados)) * i;
                                    aux.y = laser.pos.y + i;
                                }
                                if (player.vida.time > INVULERABILIDAD)
                                {
                                    if (CheckPlayerColision(player.pos, aux))
                                    {
                                        if (player.vida.num < 1)
                                        {
                                            piezac = 0;
                                            frameC = 0;
                                            muerteLvl3(player, torre, ovni, pieza, plat);
                                        }
                                        else
                                        {
                                            player.vida.num--;
                                            player.vida.time = 0;
                                        }
                                        i = SUELO;
                                    }
                                }
                            }
                        }
                        else
                        {
                            laser.mov = 1;
                            laser.time = 0;
                            laser.atkC = 0;
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
                    laser.status = 1;
                    laser.pos.x = -laser.pos.width;
                    laser.pos.y = camara.target.y - 537;
                    laser.time = 0;
                    laser.atkC = 0;
                }
            }

            //** DROPS ************************************************************************************************************************
            for (i = 0; i < MAXDROPVIDA; i++)
            {
                if (dropVida[i].status)
                {
                    // tiempo
                    dropVida[i].time++;
                    // eliminacion
                    if (dropVida[i].time > DESPAWNTIME)
                    {
                        dropVida[i].status = 0;
                        dropVida[i].time = 0;
                    }

                    // curacion
                    if (CheckPlayerColision(player.pos, dropVida[i].pos))
                    {
                        player.vida.num++;
                        dropVida[i].status = 0;
                        dropVida[i].time = 0;
                    }
                    else
                    {
                        // movimiento
                        if (dropVida[i].pos.y < SUELO - dropVida[i].pos.height)
                        {
                            dropVida[i].pos.y += 2;
                        }
                        else
                        {
                            dropVida[i].pos.y = SUELO - dropVida[i].pos.height;
                        }
                    }
                }
            }

            for (i = 0; i < MAXDROPASPEED; i++)
            {
                if (dropASpeed[i].statusDraw)
                {
                    // tiempo
                    dropASpeed[i].time++;
                    // eliminacion
                    if (!dropASpeed[i].statusFun)
                    {
                        if (dropASpeed[i].time > DESPAWNTIME)
                        {
                            dropASpeed[i].statusDraw = 0;
                            dropASpeed[i].statusFun = 0;
                            dropASpeed[i].time = 0;
                        }
                        if (CheckPlayerColision(player.pos, dropASpeed[i].pos))
                        {
                            player.buff = 1;
                            dropASpeed[i].statusDraw = 0;
                            dropASpeed[i].statusFun = 1;
                            dropASpeed[i].time = 0;
                            dropASpeed[i].duracion = 0;
                        }
                        else
                        {
                            // movimiento
                            if (dropASpeed[i].pos.y < SUELO - dropASpeed[i].pos.height * 3)
                            {
                                dropASpeed[i].pos.y += 1;
                            }
                            else
                            {
                                dropASpeed[i].pos.y = SUELO - dropASpeed[i].pos.height * 3;
                            }
                        }
                    }
                }
                else
                {
                    if (player.buff)
                    {
                        if (dropASpeed[i].statusFun)
                        {
                            if (dropASpeed[i].duracion < DURACIONBUFF)
                            {
                                dropASpeed[i].duracion++;
                            }
                            else
                            {
                                player.buff = 0;
                                dropASpeed[i].statusFun = 0;
                                dropASpeed[i].statusDraw = 0;
                                dropASpeed[i].time = 0;
                                dropASpeed[i].duracion = 0;
                            }
                        }
                    }
                }
            }

            //** caluclar posicion y ********************************************************************************************************************************
            if (player.fall)
            {
                player.jetc++;
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

                    // jetpack *******************
                    if (!player.jet) // si no esta usando el jetpack calcula caida
                    {
                        player.pos.y = Posicion(player.y0, player.v0, time, bdown); // y=y0+v0*t+G*t^2  caida acelerada
                    }
                    else
                    {
                        player.jet = JetPack(time, player.v0, player.y0, player.pos.y, bdown); // inicializa un minisalto cuando se suelte abajo
                                                                                               // hace mas comodo el uso del jetpack
                        player.pos.y += VY;                                                    // sube con velocidad constante
                        bdown = 0;
                    }
                }
                else
                {

                    // jetpack***********
                    if (!player.jet) // si no esta usando el jetpack calcula caida
                    {
                        player.pos.y = Posicion(player.y0, player.v0, time, bdown); // y=y0+v0*t+G*t^2   //calcula caida
                    }
                    else
                    {
                        player.jet = JetPack(time, player.v0, player.y0, player.pos.y, bdown); // inicializa un minisalto cuando se suelte abajo
                                                                                               // hace mas comodo el uso del jetpack
                        player.pos.y += VY;
                    }
                }
            }

            //** colisiones ********************************************************************************************************************************
            // v=v0*2*G*t derivada de la posicion=velocidad
            // suelo
            if (player.pos.y + player.pos.height > SUELO)
            {
                player.pos.y = SUELO - player.pos.height;
                Reposo(time, player.v0, player.y0, player.pos.y);
                player.fall = 0;
                bsuelo = 1;
                player.jump = 1;
                player.jumpjump = 0;
                player.jet = 0;
            }

            // plataformas
            if (igncolision > 35)
            {
                // plataforma cuando cae
                if (velocidad(player.v0, time) > 0)
                {
                    for (j = 0; j < MAXPLAT; j++)
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
                                player.jumpjump = 0;
                                bdown = 0;
                                player.jet = 0;
                            }
                        }
                    }
                }
            }

            // si salio de la paltaforma
            for (j = 0; j < MAXPLAT; j++)
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
                            player.jump = 0;
                            player.jumpjump = 0;
                            bdown = 0;
                            player.jet = 0;
                        }
                    }
                }
            }

            //** golpe ********************************************************************************************************************************
            for (i = 0; i < MAXHIT; i++)
            {
                //** movimiento del disparo ***********************************************************************************
                if (hit[i].status)
                {
                    //** Eliminacion del proyectil *******************************************************************************
                    hit[i].time++;
                    if (hit[i].time < 25)
                    {
                        hitb = 1;
                        if (hit[i].time > 10)
                        {
                            hit[i].pos.y = player.pos.y - 18;
                            if (hit[i].direccion)
                            {
                                hit[i].pos.x = player.pos.x + player.pos.width * 3 + 3;
                            }
                            else
                            {
                                hit[i].pos.x = player.pos.x - player.pos.width * 3 - hit[i].pos.width + 17;
                            }
                        }
                    }
                    else
                    {
                        hitb = 0;
                        hit[i].status = 0;
                        hit[i].time = 0;
                        hit[i].pos.x = 1500;
                        hit[i].pos.y = -300;
                    }
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
                    player.jump == 0;
                    player.fall = 1;
                    dash = Reposo(time, player.v0, player.y0, player.pos.y);
                }
            }

            //** camara ********************************************************************************************************************************
            if (player.pos.y > 400)
            {
                camara.target.y = 0;
                camara.offset.y = 0;
            }
            else
            {
                camara.target.y = player.pos.y;
                camara.offset.y = 400;
            }

            //** intput ********************************************************************************************************************************
            // hit
            if (IsKeyPressed(KEY_X))
            {
                for (i = 0; i < MAXHIT; i++)
                {
                    Direccioniugador(lookL, lookR, lookUp, lookDown, player);
                    if (!player.buff) //** Meiora ******************************************************************************************************
                    {
                        if (player.AtkC > VATAQUE)
                        {
                            if (!hit[i].status)
                            {
                                hit[i].pos.y = player.pos.y + player.pos.height / 4;
                                Direccioniugador(lookL, lookR, lookL, lookDown, player);
                                if (lookR)
                                {
                                    hit[i].direccion = 1;
                                    hit[i].pos.x = player.pos.x + player.pos.width / 2;
                                }
                                else
                                {
                                    if (lookL)
                                    {
                                        hit[i].direccion = 0;
                                        hit[i].pos.x = player.pos.x + player.pos.width / 2 - RANCHO;
                                    }
                                }
                                hit[i].status = 1;
                                hit[i].time = 0;
                                player.AtkC = 0;
                                i = MAXHIT;
                            }
                        }
                    }
                    else
                    {
                        if (player.AtkC > VATAQUEBUFF)
                        {
                            if (!hit[i].status)
                            {
                                hit[i].pos.y = player.pos.y + player.pos.height / 4;
                                hit[i].pos.x = player.pos.x + player.pos.width / 2;
                                Direccioniugador(lookL, lookR, lookL, lookDown, player);
                                if (lookR)
                                {
                                    hit[i].direccion = 1;
                                }
                                else
                                {
                                    if (lookL)
                                    {
                                        hit[i].direccion = 0;
                                    }
                                }
                                hit[i].status = 1;
                                hit[i].time = 0;
                                player.AtkC = 0;
                                i = MAXHIT;
                            }
                        }
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
                                PlaySound(sdash);
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

            if (!dash) // right left
            {
                if (IsKeyDown(KEY_RIGHT))
                {
                    if (player.pos.x < 1280)
                    {
                        player.x0 = player.pos.x;
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
                            player.x0 = player.pos.x;
                            player.pos.x -= VX;
                            lookR = 0;
                            lookL = 1;
                        }
                    }
                }
            }

            if (!dash) // up down
            {
                if (IsKeyDown(KEY_UP))
                {
                    if (player.jump)
                    {
                        PlaySound(brinco);
                        Reposo(time, player.v0, player.y0, player.pos.y);
                        Salto(time, player.v0, player.y0, player.pos.y);
                        player.fall = 1;
                        if (player.jumpjump) //! doblesalto
                        {
                            PlaySound(brinco);
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
                        player.jetc = 0;
                        bsuelo = 0;
                        bdown = 0;
                    }
                    else
                    {
                        if (IsKeyPressed(KEY_UP))
                        {
                            PlaySound(jetpack);
                        }
                        if (player.jetc > 60)
                        {
                            player.jet = 1; // esta usando jetpack
                            c = 0;          // habilita bajar rapido
                        }
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
        }
        ClearBackground(BLANK);
        PlayMusicStream(musica_nv3);
        UpdateMusicStream(musica_nv3);
        DrawTexture(fondo, 0, -1300, WHITE);
        org.x = laser.pos.x + laser.pos.width / 2;
        org.y = laser.pos.y + laser.pos.height / 2;
        org1.x = 0;
        org1.y = 0;
        // jugador
        // jetpack
        DrawRectangleRec(player.pos, BLUE);
        Direccioniugador(lookL, lookR, lookUp, lookDown, player);
        if (lookR)
        {
            DrawTexture(jet[1], player.pos.x - 45, player.pos.y - 10, WHITE);
        }
        else
        {
            if (lookL)
            {
                DrawTexture(jet[0], player.pos.x + player.pos.width - 10, player.pos.y - 10, WHITE);
            }
            else
            {
                DrawTexture(jet[1], player.pos.x - 45, player.pos.y - 10, WHITE);
            }
        }
        if (!hitb)
        {
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
                    DrawTextureRec(salto, frameSalto, Vector2{player.pos.x - 80, player.pos.y - 50}, WHITE);
                }
                else
                {
                    if (lookR)
                    {
                        DrawTextureRec(saltoder, frameSalto, Vector2{player.pos.x - 40, player.pos.y - 50}, WHITE);
                    }
                    else
                    {
                        DrawTextureRec(saltoder, frameSalto, Vector2{player.pos.x - 40, player.pos.y - 50}, WHITE);
                    }
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
                    DrawTextureRec(caminar, framesCaminar, Vector2{player.pos.x - 40, player.pos.y - 75}, WHITE);
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
                    DrawTextureRec(caminarizq, framesCaminarizq, Vector2{player.pos.x - 80, player.pos.y - 75}, WHITE);
                }
                else
                {
                    framesPersonaje = 0;
                    if (lookL)
                    {
                        DrawTextureRec(reposoizq, framesReposoizq, Vector2{player.pos.x - 85, player.pos.y - 75}, WHITE);
                    }
                    else
                    {
                        if (lookR)
                        {
                            DrawTextureRec(reposo, framesReposo, Vector2{player.pos.x - 30, player.pos.y - 75}, WHITE);
                        }
                        else
                        {
                            DrawTextureRec(reposo, framesReposo, Vector2{player.pos.x - 30, player.pos.y - 75}, WHITE);
                        }
                    }
                }
            }
        }

        // suelo
        DrawTexture(suelo, 0, SUELO - 4, WHITE);
        // printf("\n centro jux = %f centro laser = %f\n",player.pos.x+player.pos.width/2,laser.pos.x+laser.pos.width/2);
        // laser

        if (laser.time > 1)
        {
            if (laser.time < 15)
            {
                PlaySound(ovni_laser);
                DrawTextureEx(laserRed[1], org, 360 - laser.grados, 1, WHITE);
            }
        }

        if (laser.atkC > 240)
        {
            if (laser.atkC < 360)
            {
                DrawTexture(laserG, laser.pos.x, laser.pos.y, WHITE);
            }
            else
            {
                DrawTexture(laserM, laser.pos.x, laser.pos.y, WHITE);
            }
        }
        else
        {
            DrawTexture(laserM, laser.pos.x, laser.pos.y, WHITE);
        }

        // vida
        for (i = 1; i <= player.vida.num; i++)
        {
            if (player.pos.y > 400)
            {
                player.vida.pos.y = 25;
            }
            else
            {
                player.vida.pos.y = player.pos.y - 375;
            }
            DrawTexture(corazon, player.vida.pos.x, player.vida.pos.y, WHITE);
            player.vida.pos.x += 25 + player.vida.pos.width;
        }
        player.vida.pos.x = 25;

        // plataformas
        for (j = 0; j < MAXPLAT; j++)
        {
            DrawTexture(plat3, plat[j].pos.x, plat[j].pos.y, WHITE);
        }
        // enemigos
        for (j = 0; j < MAXTORRE; j++)
        {
            if (torre[j].status)
            {
                for (i = 0; i < MAXHITTORRE; i++)
                {
                    if (torre[j].hit[i].status)
                    {
                        DrawTexture(bala, torre[j].hit[i].pos.x - 4, torre[j].hit[i].pos.y - 4, WHITE);
                        PlaySound(canion);
                    }
                }

                if (torre[j].direccion)
                {
                    grados = CalculaAngulo(torre[j].pos, player.pos);
                    if (grados <= 112)
                    {
                        DrawTexture(towr[8], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                    }
                    else
                    {
                        if (grados <= 135)
                        {
                            DrawTexture(towr[7], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                        }
                        else
                        {
                            if (grados <= 158)
                            {
                                DrawTexture(towr[6], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                            }
                            else
                            {
                                if (grados <= 180)
                                {
                                    DrawTexture(towr[5], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                }
                                else
                                {
                                    if (grados <= 192)
                                    {
                                        DrawTexture(towr[4], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                    }
                                    else
                                    {
                                        if (grados <= 225)
                                        {
                                            DrawTexture(towr[3], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                        }
                                        else
                                        {
                                            if (grados <= 247)
                                            {
                                                DrawTexture(towr[2], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                            }
                                            else
                                            {
                                                if (grados <= 270)
                                                {
                                                    DrawTexture(towr[1], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                                }
                                                else
                                                {
                                                    if (grados > 270)
                                                    {
                                                        DrawTexture(towr[0], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    grados = CalculaAngulo(torre[j].pos, player.pos) + 90;

                    if (grados > 360)
                    {
                        grados -= 360;
                    }

                    if (grados > 90)
                    {
                        if (grados <= 270)
                        {
                            if (grados <= 112)
                            {
                                DrawTexture(towl[5], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                            }
                            else
                            {
                                if (grados <= 135)
                                {
                                    DrawTexture(towl[6], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                }
                                else
                                {
                                    if (grados <= 158)
                                    {
                                        DrawTexture(towl[7], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                    }
                                    else
                                    {
                                        DrawTexture(towl[8], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (grados <= 22)
                        {
                            DrawTexture(towl[1], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                        }
                        else
                        {
                            if (grados <= 45)
                            {
                                DrawTexture(towl[2], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                            }
                            else
                            {
                                if (grados <= 67)
                                {
                                    DrawTexture(towl[3], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                }
                                else
                                {
                                    if (grados <= 90)
                                    {
                                        DrawTexture(towl[4], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                                    }
                                }
                            }
                        }
                    }
                    if (grados >= 337)
                    {
                        DrawTexture(towl[0], torre[j].pos.x - 5, torre[j].pos.y - 5, WHITE);
                    }
                }
            }
        }
        for (i = 0; i < MAXOVNI; i++)
        {
            if (ovni[i].status)
            {
                DrawTexture(morado, ovni[i].pos.x - 12.5, ovni[i].pos.y - 7.5, WHITE);
            }
        }
        // piezas
        for (j = 0; j < 3; j++)
        {
            if (pieza[j].status)
            {
                DrawTexture(nave[j], pieza[j].pos.x, pieza[j].pos.y, WHITE);
            }
        }
        // golpe
        for (i = 0; i < MAXHIT; i++)
        {
            if (hit[i].status)
            {

                if (lookR)
                {
                    if (hit[i].time < 5)
                    {
                        DrawTexture(hitR[0], player.pos.x - 15, player.pos.y - 35, WHITE);
                    }
                    else
                    {
                        if (hit[i].time < 10)
                        {
                            DrawTexture(hitR[1], player.pos.x - 25, player.pos.y - 35, WHITE);
                        }
                        else
                        {
                            PlaySound(las);
                            DrawTexture(laserRed[1], hit[i].pos.x, hit[i].pos.y - 10, WHITE);
                            DrawTexture(hitR[2], player.pos.x - 35, player.pos.y - 35, WHITE);
                        }
                    }
                }
                else
                {
                    if (lookL)
                    {
                        if (hit[i].time < 5)
                        {
                            DrawTexture(hitL[0], player.pos.x - 45, player.pos.y - 35, WHITE);
                        }
                        else
                        {
                            if (hit[i].time < 10)
                            {
                                DrawTexture(hitL[1], player.pos.x - 55, player.pos.y - 35, WHITE);
                            }
                            else
                            {
                                PlaySound(las);
                                DrawTexture(laserRed[0], hit[i].pos.x + 190, hit[i].pos.y - 10, YELLOW);
                                DrawTexture(hitL[2], player.pos.x - 60, player.pos.y - 35, WHITE);
                            }
                        }
                    }
                }
            }
        }
        // DROPS
        for (i = 0; i < MAXDROPVIDA; i++)
        {
            if (dropVida[i].status)
            {
                DrawTexture(corazon, dropVida[i].pos.x, dropVida[i].pos.y, WHITE);
            }
        }
        for (i = 0; i < MAXDROPASPEED; i++)
        {
            if (dropASpeed[i].statusDraw)
            {
                if (!dropASpeed[i].statusFun)
                {
                    DrawTexture(Aspeed, dropASpeed[i].pos.x, dropASpeed[i].pos.y, WHITE);
                }
            }
        }
        EndMode2D();
        EndDrawing();
    }

    for (i = 0; i < 9; i++)
    {
        UnloadTexture(towl[i]);
        UnloadTexture(towr[i]);
    }
    for (i = 0; i < 3; i++)
    {
        UnloadTexture(nave[i]);
    }
    UnloadTexture(jet[0]);
    UnloadTexture(jet[1]);
    UnloadTexture(morado);
    UnloadTexture(bala);
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

int CheckMobColision(Trec mob, Trec hit)
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

void LimpiaEnemigosLvl3(Ttow torre[], Tovni ovni[])
{
    int j, i;
    for (j = 0; j < MAXTORRE; j++)
    {
        torre[j].status = 0;
        for (i = 0; i < MAXHITTORRE; i++)
        {
            torre[j].hit[i].status = 0;
            torre[j].hit[i].v.vx = 0;
            torre[j].hit[i].v.vy = 0;
            if (torre[j].direccion)
            {

                torre[j].hit[i].pos.x = -500;
            }
            else
            {
                torre[j].hit[i].pos.x = 1500;
            }
        }
    }
    for (i = 0; i < MAXOVNI; i++)
    {
        ovni[i].status = 0;
    }
}

int JetPack(float &time, float &v0, int &y0, int y, int bdown)
{
    if (!bdown)
    {
        time = 0;
        v0 = VSJ;
        y0 = y;
    }
    else
    {
        Reposo(time, v0, y0, y);
    }
    return 0;
}

float Radianes(float grados)
{
    return (grados * M_PI / 180);
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

void PosicionObieto(float vx, float vy, Trec &pos)
{
    pos.x += vx;
    pos.y += vy;
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
            else
            {
                if (IsKeyDown(KEY_DOWN))
                {
                    R = 0;
                    Up = 0;
                    Down = 1;
                    L = 0;
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

float CalculaAngulo(Trec enemigo, Trec player)
{
    float difx = fabs(player.x + player.width / 2 - (enemigo.x + enemigo.width / 2));
    float dify = fabs(player.y + player.height / 2 - (enemigo.y + enemigo.height / 2));
    float a = atan2(difx, dify);
    a = a * 180 / M_PI;
    if (player.x > enemigo.x)
    {
        if (player.y > enemigo.y)
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
        if (player.y > enemigo.y)
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

void muerteLvl3(Tplayer &player, Ttow torre[], Tovni ovni[], Tpart pieza[], Tplat plat[])
{
    int j;
    player.pos.x = 400;   // Posicion incial
    player.pos.y = SUELO; //""
    player.y0 = player.pos.y;
    player.v0 = 0;
    player.timeDash = 70;
    player.vida.num = MAXVIDA;
    player.vida.time = 0;
    LimpiaEnemigosLvl3(torre, ovni);
    for (j = 0; j < 3; j++)
    {
        pieza[j].status = 1;
        pieza[j].listo = 0;
        pieza[j].pos.x = plat[j + 1].pos.x + plat[j + 1].pos.width / 2 - pieza[j].pos.width / 2;
        pieza[j].pos.y = -1500;
    }
}

void cinemaPuzleNivel3(void)
{
    while (1)
    {
        printf("\nGanaste\n");
    }
}