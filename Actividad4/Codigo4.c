// Solano Meza Angel Daniel Matr. 372453
// 03/09/2023
// Calcular salario, horas extra y pago de un trabajador segun las horas trabajadas
// ADSM_ACT4_4_932
#include<stdio.h>
#define JN 40
int main()
{
    int horas, precio, s_normal,s_extra,s_total;
    printf("Cuantas horas trabajaste?: ");
    scanf("%d",&horas);
    printf("Salario por hora: ");
    scanf("%d",&precio);

    if (horas<=JN)//Calcular jornada normal
    {
        s_normal=(horas*precio);
        s_total=s_normal;
        s_extra=0;
    }
    else
    {
        if (horas<=JN+9)//Calcular hasta 9 horas dobles
        {
            s_normal=(precio*JN);
            s_extra=(2*((horas-JN)*precio));
            s_total=s_normal+s_extra;
        }
        else //Calcular horas al doble y triples
        {
            s_normal=(precio*40);
            s_extra=(2*(9*precio))+(3*((horas-(JN+9))*precio));
            s_total=s_normal+s_extra;
        }

    }
    printf("Salario por hora: %d\nHoras trabajadas: %d\nSalario normal: %d\nSalario extra: %d\nSalario total: %d",precio,horas,s_normal,s_extra,s_total);
    return 0;
}