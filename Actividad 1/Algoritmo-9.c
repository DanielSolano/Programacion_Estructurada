// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Leer 3 numeros e imprimirlos en orden ascendente
// ADSM_ACT1_9_932
#include <stdio.h>
int main()
{
    int num1,num2,num3, temp;
    printf("Numero 1: ");
    scanf("%d",&num1);
    printf("Numero 2: ");
    scanf("%d",&num2);
    printf("Numero 3: ");
    scanf("%d",&num3);

   if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("Los numeros en orden ascendente son: %d, %d, %d\n", num1, num2, num3);
}