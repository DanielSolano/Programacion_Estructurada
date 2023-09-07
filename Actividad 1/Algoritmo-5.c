// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Obtener promedio, imprimir una frase dependiendo del mismo, anidado por el verdadero
// ADSM_ACT1_5_932
#include <stdio.h>
int main()
{
    int cal1,cal2,cal3,prom;
    printf("Calificacion 1: ");
    scanf("%d",&cal1);
    printf("Calificacion 2: ");
    scanf("%d",&cal2);
    printf("Calificacion 3: ");
    scanf("%d",&cal3);
    prom=(cal1+cal2+cal3)/3;
    if (prom>=30)
    {
        if(prom>=60)
        {
          if (prom>=70)
          {
            if(prom>=80)
            {
                if (prom>=90)
                {
                    if(prom>=98)
                    {
                        if(prom>100)
                        {
                            printf("Error en el promedio");
                        }
                        else
                        {
                            printf("Excelente");
                        }
                        
                    }
                    else
                    {
                        printf("Muy bien");
                    }
                }
                else
                {
                    printf("Bien");
                }
            }
            else
            {
                printf("Regular");
            }
          }
          else
          {
            printf("Suficiente");
          }
        }
        else
        {
            printf("Extraordinario");
        }
    }
    else
    {
        printf("Repetidor");
    }
    return 0;
}