// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Obtener promedio, imprimir una frase dependiendo del mismo, anidado por el falso
// ADSM_ACT1_6_932
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
    if (prom<30)
    {
        printf("Repetidor");
    }
    else
    {
        if(prom<60)
        {
            printf("Extraordinario");  
        }
        else
        {
            if (prom<70)
            {
                printf("Suficiente");
            }
            else
            {
                if(prom<80)
                {
                printf("Regular");
                
                }
                else
                {
                    if (prom<90)
                    {
                        printf("Bien");
                        
                    }
                    else
                    {
                        if(prom<98)
                        {
                            printf("Muy bien");
                            
                        
                        }
                        else
                        {
                            if(prom<=100)
                            {
                            printf("Excelente");
                            }
                            else
                            {
                            printf("Error en el promedio");
                            }
                        }
                    }
                }
            }
        }
    }
 return 0;    
}
