#include <stdio.h>
#include <time.h>
int main()
{
    int j1, j2;
    srand(time(NULL));
    j2=rand()% 3 + 1;//El jugador 2 es controlado por la maquina
    printf("---Chichampu---\n1.-Piedra\n2.-Papel\n3.-Tijera\n");
    printf("Seleccione una opcion: ");
    scanf("%d",&j1);
    //1.-Piedra 2.-Papel 3.-Tijera
    if((j1 <= 0) && (j1 > 3))
    {
    printf("Opcion incorrecta");
    }
    else
    {
        if((j1==1 && j2==3) || (j1==2 && j2==1) || (j1==3 && j2==2))
        {
            if(j1==1)
            {
            printf("Gana jugador 1, piedra gana a tijera");
            }
            
            if(j1==2)
            {   
            printf("Gana jugador 1, papel gana a piedra");
            }
            if(j1==3)
            {
            printf("Gana jugador 1, tijera gana a papel");
            }

        }
        else
        {
            if((j2==1 && j1==3) || (j2==2 && j1==1) || (j2==3 && j1==2))
            {
            if(j2==1)
            {
                printf("Gana jugador 2, piedra gana a tijera");
            }
            if(j2==2)
            {
                printf("Gana jugador 2, papel gana a piedra");
            }
            if(j2==3)
            {
                printf("Gana jugador 2, tijera gana a papel");
            }
            }
            else
            {
            printf("Empate");
            }

        }
    }
    
    return 0;
}