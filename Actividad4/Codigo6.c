// Solano Meza Angel Daniel Matr. 372453
// 03/09/2023
// Cobrar metros cubicos de agua dependiendo el consumo.
// ADSM_ACT4_6_932
#include <stdio.h>
#define R1 50
#define R2 8
#define R3 10
#define R4 11
int main()
{
    int metros,subtotal;
    float total;
    printf("Cuantos m3 de agua consumiste?: ");
    scanf("%d",&metros);

    if (metros>=5) 
    {   
        if(metros>=16)
        {
            if(metros>=51) //Rango 4
            {
                subtotal=(R4*(metros-50))+488;
                total=subtotal*1.16;
            }
            else //Rango 3
            {
                subtotal=(R3*(metros-15))+138;
                total=subtotal*1.16;
            }
        }
        else //Rango 2
        {
            subtotal=(R2*(metros-4))+50;
            total=subtotal*1.16;
        }
    }
    else //Rango 1
    {
        subtotal=R1;
        total=R1*1.16;
    }
    printf("Subtotal= %d\nIVA= %.2f\nTotal= %.2f\n",subtotal,(subtotal*.16),total);
    return 0;
}