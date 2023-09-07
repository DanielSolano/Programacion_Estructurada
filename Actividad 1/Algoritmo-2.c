// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Leer 2 numeros, imprimir par o no par.
// ADSM_ACT1_2_932
#include <stdio.h>
int main()
{
    int num;
    printf("Ingresa un numero: ");
    scanf("%d",&num);

    if ((num%2)==0)
    {
        printf("Si es par\n");
    }
    if ((num%2)!=0)
    {
        printf("No es par\n");
    }
    return 0;
}