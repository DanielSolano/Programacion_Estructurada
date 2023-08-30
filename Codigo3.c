#include <stdio.h>
int main()
{
    int n1,n2,n3,n4,n5,n6,mayor;
    printf("Numero 1:");
    scanf("%d",&n1);
    printf("Numero 2:");
    scanf("%d",&n2);
    printf("Numero 3:");
    scanf("%d",&n3);
    printf("Numero 4:");
    scanf("%d",&n4);
    printf("Numero 5:");
    scanf("%d",&n5);
    printf("Numero 6:");
    scanf("%d",&n6);
    mayor=n1;
    if(n2>mayor)
    {
        mayor=n2;
    }
    if(n3>mayor)
    {
        mayor=n3;
    }
    if(n4>mayor)
    {
        mayor=n4;
    }
    if(n5>mayor)
    {
        mayor=n5;
    }
    if(n6>mayor)
    {
        n6=mayor;
    }
    printf("El numero mayor es: %d",mayor);
    return 0;
}