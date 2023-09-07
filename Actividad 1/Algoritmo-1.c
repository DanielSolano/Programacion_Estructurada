// Solano Meza Angel Daniel Matr. 372453
// 22/08/2023
// Leer 4 calificaciones, reprobatorias o aprobatorias.
// ADSM_ACT1_1_932

#include <stdio.h>
int main()
{
    int c1,c2,c3,c4, i;
    printf("Calificacion alumno 1: ");
    scanf("%d",&c1);
   
    if (c1>=60)
    {
      printf("Alumno aprobado\n");        
    }    
    if (c1<60)
    {
     printf("Alumno reprobado\n");
    }
  

    printf("Calificacion alumno 2: ");
    scanf("%d",&c2);
   
    if (c2>=60)
    {
      printf("Alumno aprobado\n");        
    }    
    if (c2<60)
    {
      printf("Alumno reprobado\n");
    } 

    printf("Calificacion alumno 3: ");
    scanf("%d",&c3);
   
    if (c3>=60)
    {
      printf("Alumno aprobado\n");        
    }    
    if (c3<60)
    {
      printf("Alumno reprobado\n");
    } 

    printf("Calificacion alumno 4: ");
    scanf("%d",&c4);
   
    if (c4>=60)
    {
      printf("Alumno aprobado\n");        
    }    
    if (c4<60)
    {
      printf("Alumno reprobado\n");
    } 
 return 0;
}