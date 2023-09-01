#include<stdio.h>
#define JN 40
int main()
{
    int horas, precio, s_normal,s_extra,s_total;
    printf("Cuantas horas trabajaste?: ");
    scanf("%d",&horas);
    printf("Salario por hora: ");
    scanf("%d",&precio);

    if (horas<=JN)
    {
        s_normal=(horas*precio);
        s_total=s_normal;
        s_extra=0;
    }
    else
    {
        if (horas<=JN+9)
        {
            s_normal=(precio*JN);
            s_extra=(2*((horas-JN)*precio));
            s_total=s_normal+s_extra;
        }
        else
        {
            s_normal=(precio*40);
            s_extra=(2*(9*precio))+(3*((horas-(JN+9))*precio));
            s_total=s_normal+s_extra;
        }

    }
    printf("Salario por hora: %d\nHoras trabajadas: %d\nSalario normal: %d\nSalario extra: %d\nSalario total: %d",precio,horas,s_normal,s_extra,s_total);
    return 0;
}