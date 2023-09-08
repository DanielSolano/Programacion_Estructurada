// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Leer sexo del usuario, imprimir hombre o mujer
// ADSM_ACT1_4_932
#include <stdio.h>
int main()
{
    int sexo;
    printf("Elige tu sexo\n(1)HOMBRE/(2)MUJER\n");
    scanf("%d",&sexo);
    if (sexo==2)
    {
        printf("\nERES MUJER");
    }
    else
    {
        printf("\nERES HOMBRE");
    }
    return 0;
}