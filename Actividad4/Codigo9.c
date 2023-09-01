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


    return 0;
}