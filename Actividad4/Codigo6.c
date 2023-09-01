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
            if(metros>=51)
            {
                subtotal=R4*metros;
                total=subtotal*1.16;
            }
            else
            {
                subtotal=R3*metros;
                total=subtotal*1.16;
            }
        }
        else
        {
            subtotal=R2*metros;
            total=subtotal*1.16;
        }
    }
    else
    {
        subtotal=R1;
        total=R1*1.16;
    }
    printf("Subtotal= %d\nIVA= %.2f\nTotal= %.2f\n",subtotal,(subtotal*.16),total);
    return 0;
}