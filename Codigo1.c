#include <stdio.h>
int main()
{
    int num1, num2, opc;
    printf("---MENU---\n1.-Suma\n2.-Resta\n3.-Multiplicacion\n4.-Division\n");
    printf("Elige una opcion: ");
    scanf("%d",&opc);
    printf("Numero 1: ");
    scanf("%d",&num1);
    printf("Numero 2: ");
    scanf("%d",&num2);
    if(opc==1)
    {
        printf("La suma es: %d",num1+num2);
    }
    else
    {
        if(opc==2)
        {
            printf("La resta es: %d",num1-num2);
        }
        else
        {
            if(opc==3)
            {
                printf("La multiplicacion es: %d",num1*num2);
            }
            else
            {
                if(opc==4)
                {
                    printf("La division es: %.2f",(num1+0.0)/(num2+0.0));
                }
                else
                {
                    printf("Opcion incorrecta");
                }
            }
        }
    }
}