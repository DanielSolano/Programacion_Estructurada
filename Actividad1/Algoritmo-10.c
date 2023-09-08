// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Leer horas trabajadas y precio por hora, calcular el salario
// ADSM_ACT1_10_932
#include <stdio.h>
int main()
{
    int horas, precio, s_normal,s_doble,s_triple,h_doble,h_triple,s_total;
    printf("Cuantas horas trabajaste?: ");
    scanf("%d",&horas);
    printf("Salario por hora: ");
    scanf("%d",&precio);

    if (horas<=40)
    {
        s_normal=(horas*precio);
        printf("Precio por hora: %d\nHoras trabajadas: %d\nSalario: %d",precio, horas, s_normal);
    }
    else
    {
        if (horas<=49)
        {
            h_doble=horas-40;
            s_normal=(precio*40);
            s_doble=(2*(h_doble*precio));
            s_total=s_normal+s_doble;
            printf("Precio por hora: %d\nHoras trabajadas: %d\nHoras precio doble: %d\nSalario precio normal: %d\nSalario precio doble: %d\nSalario total: %d",precio, horas,h_doble, s_normal,s_doble,s_total);
        }
        else
        {
            h_doble=9;
            h_triple=horas-49;
            s_normal=(precio*40);
            s_doble=(2*(9*precio));
            s_triple=(3*(h_triple*precio));
            s_total=s_normal+s_doble+s_triple;
            printf("Precio por hora: %d\nHoras trabajadas: %d\nHoras precio doble: %d\nHoras precio triple: %d\nSalario precio normal: %d\nSalario precio doble: %d\nSalario precio triple: %d\nSalario total: %d",precio, horas,h_doble,h_triple, s_normal,s_doble,s_triple,s_total);
        }

    }
    return 0;
}