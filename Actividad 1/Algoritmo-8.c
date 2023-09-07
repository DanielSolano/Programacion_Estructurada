// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Leer 3 numeros, imprimir el intermedio
// ADSM_ACT1_8_932
#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf("Numero 1: ");
    scanf("%d",&num1);
    printf("Numero 2: ");
    scanf("%d",&num2);
    printf("Numero 3: ");
    scanf("%d",&num3);

    if ((num1 >= num2 && num1 <= num3) || (num1 <= num2 && num1 >= num3)) 
    {
        printf("Numero intermedio: %d",num1);
    } 
    else
    {
        if((num2 >= num1 && num2 <= num3) || (num2 <= num1 && num2 >= num3))
        {
            printf("El numero intermedio es: %d",num2);
        } 
        else
        {
           printf("El numero intermedio es: %d",num3);
        }
    }
        
    return 0;    
}