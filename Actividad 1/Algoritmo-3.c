// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Leer 3 calificaciones, obtener promedio e imprimir aprobado o reprobado
// ADSM_ACT1_3_932
#include <stdio.h>
int main()
{
    int cp1, cp2, cp3, cp4, prom;
    printf("Calificacion del parcial 1: ");
    scanf("%d",&cp1);
    
    printf("Calificacion del parcial 2: ");
    scanf("%d",&cp2);
    
    printf("Calificacion del parcial 3: ");
    scanf("%d",&cp3);
    
    printf("Calificacion del parcial 4: ");
    scanf("%d",&cp4);

    prom=(cp1+cp2+cp3+cp4)/4;

    if (prom>=60)
    {
     printf("El promedio es: %d\nAprobado",prom);
    }
    else
    {
    printf("El promedio es: %d\nReprobado",prom);
    }
    
    return 0;
}