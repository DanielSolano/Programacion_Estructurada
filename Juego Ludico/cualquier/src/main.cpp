

#include "raylib.h"
    //Texture2D sub=LoadTexture("texturas\\SUB.png");
    //Texture2D nave=LoadTexture("texturas\\navepix2.png");
    //Texture2D car=LoadTexture("texturas\\pixel_car2.png");
    

    //DrawTexture(sub, 190, 200,WHITE);
    //DrawTexture(nave, 500,300,WHITE);
    //DrawTexture(car, 800,300,WHITE);

#define JUGAR 0
#define OPCIONES 1
#define SALIR 2

#define DIFICULTAD 0
#define SONIDO 1
#define REGRESAR 2

#define NEWP 0
#define CONTINUAR 1

int mainMenu(void);
int opMenu(int &vol,int &diflvl,Texture2D volumen,Texture2D dif);
int juegoMenu(void);

void juego(int diflvl);

int main(void)
{
    int op,subOp,opJug;
    int diflvl=1,vol=3;

    const int screenWidth = 1280;
    const int screenHeight = 720;
    InitWindow(screenWidth, screenHeight, "window");
    SetTargetFPS(60);        

    while (!WindowShouldClose()) 
    {
       

        Music musica = LoadMusicStream("")
        Texture2D fondo=LoadTexture("texturas\\menuok.png");
        
        //Menu principal
        do
        {
            menu:
                BeginDrawing();
                DrawTexture(fondo,0,0,WHITE);
                op=mainMenu();
                EndDrawing();
        }while(op==-1);
        
    
        switch(op)
        {   
            //Menu jugar
            case JUGAR:
                do
                {
                    BeginDrawing();
                    DrawTexture(fondo,0,0,WHITE);
                    opJug=juegoMenu();
                    EndDrawing();
                }while(opJug==-1);
                

                switch(opJug)
                {
                    case NEWP:
                        goto juegoL;
                        break;
                    case CONTINUAR:
                        goto continuar;
                        break;
                    case REGRESAR:
                        goto menu;
                        break;
                }
                
                break;
            //Menu opciones
            case OPCIONES:
                Texture2D volumen[7];
                Texture2D dif[3];
                volumen[0]=LoadTexture("texturas\\vol0.png");
                volumen[1]=LoadTexture("texturas\\vol1.png");
                volumen[2]=LoadTexture("texturas\\vol2.png");
                volumen[3]=LoadTexture("texturas\\vol3.png");
                volumen[4]=LoadTexture("texturas\\vol4.png");
                volumen[5]=LoadTexture("texturas\\vol5.png");
                volumen[6]=LoadTexture("texturas\\vol6.png");
                dif[0]=LoadTexture("texturas\\dif1.png");
                dif[1]=LoadTexture("texturas\\dif2.png");
                dif[2]=LoadTexture("texturas\\dif3.png");
                do
                {
                    BeginDrawing();
                    DrawTexture(fondo,0,0,WHITE);
                    subOp=opMenu(vol,diflvl,volumen[vol],dif[diflvl]);
                    EndDrawing();

                }while(subOp!=-1);
                
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
                goto menu;
                break;
            //Salir
            case SALIR:
                CloseWindow();
                return 0;
                break;
        }

        juegoL:
        UnloadTexture(fondo);
        do
        {
            juego(diflvl);
        } while (1);

        continuar:
        UnloadTexture(fondo);
        do
        {
            juego(diflvl);
        }while(1);
        
        
    }
    CloseWindow();       

    return 0;
}

int mainMenu(void)
{
    
    static int op=0;
    int sizeTxt[3],j;
    for(j=0;j<3;j++)
    {
        if(j==op)
        {
            sizeTxt[j]=60;
        }
        else
        {
            sizeTxt[j]=40;
        }
    }

    DrawText("Mecánico Aritmético",265,65,70,WHITE);
    DrawText("Jugar",510,200,sizeTxt[0],WHITE);
    DrawText("Opciones",510,300,sizeTxt[1],WHITE);
    DrawText("Salir",510,400,sizeTxt[2],WHITE);

    if(IsKeyPressed(KEY_UP))
    {
        if(op!=JUGAR)
        {
            op--;
        }
    }
    else
    {
        if(IsKeyPressed(KEY_DOWN))
        {
            if(op!=SALIR)
            {
                op++;
            }
        }
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        return op;
    }

    return -1;
}

int opMenu(int &vol,int &diflvl,Texture2D volumen,Texture2D dif)
{
    static int op=0;
    int sizeTxt[3],j;
    for(j=0;j<3;j++)
    {
        if(j==op)
        {
            sizeTxt[j]=60;
        }
        else
        {
            sizeTxt[j]=40;
        }
    }

    DrawText("Opciones",450,65,70,WHITE);
    DrawText("Dificultad",510,200,sizeTxt[0],WHITE);
    DrawText("Sonido",510,350,sizeTxt[1],WHITE);
    DrawText("Regresar",510,500,sizeTxt[2],WHITE);

    switch(op)
    {
        case DIFICULTAD:
            DrawTexture(dif,520,-125,WHITE);

            if(IsKeyPressed(KEY_LEFT))
            {
                if(diflvl!=0)
                {
                    diflvl--;
                }
            }
            else
            {
                if(IsKeyPressed(KEY_RIGHT))
                {
                    if(diflvl!=2)
                    {
                        diflvl++;
                    }
                }
            }

            switch(diflvl)
            {
                case 0:
                    DrawText("Fácil",862,100,60,WHITE);
                    break;
                case 1:
                    DrawText("Normal",853,100,60,WHITE);
                    break;
                case 2:
                    DrawText("Difícil",856,100,60,WHITE);
                    break;
            }

            break;
      
        case SONIDO:
            DrawTexture(volumen,485,25,WHITE);
                    
            if(IsKeyPressed(KEY_LEFT))
            {
                if(vol!=0)
                {
                    vol--;
                }
            }
            else
            {
                if(IsKeyPressed(KEY_RIGHT))
                {
                    if(vol!=6)
                    {
                        vol++;
                    }
                }
            }
            
            break;

        case REGRESAR:
            if(IsKeyPressed(KEY_ENTER))
            {
                return -1;
            }
            break;
    }

    if(IsKeyPressed(KEY_UP))
    {
        if(op!=DIFICULTAD)
        {
            op--;
        }

    }
    else
    {
        if(IsKeyPressed(KEY_DOWN))
        {
            if(op!=REGRESAR)
            {
                op++;
            }
        }
    }

    return op;
}

int juegoMenu(void)
{
    static int op=0;
    int sizeTxt[3],j;
    for(j=0;j<3;j++)
    {
        if(j==op)
        {
            sizeTxt[j]=60;
        }
        else
        {
            sizeTxt[j]=40;
        }
    }

    DrawText("Mecánico Aritmético",265,65,70,WHITE);
    DrawText("Nueva Partida",450,200,sizeTxt[0],WHITE);
    DrawText("Continuar",450,300,sizeTxt[1],WHITE);
    DrawText("Regresar",450,400,sizeTxt[2],WHITE);
    

    if(IsKeyPressed(KEY_UP))
    {
        if(op!=NEWP)
        {
            op--;
        }
    }
    else
    {
        if(IsKeyPressed(KEY_DOWN))
        {
            if(op!=REGRESAR)
            {
                op++;
            }
        }
    }

    if(IsKeyPressed(KEY_ENTER))
    {
        return op;
    }

    return -1;
}

void juego(int diflvl)
{

}