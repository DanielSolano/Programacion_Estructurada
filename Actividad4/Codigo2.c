#include <stdio.h>
int main()
{
    int opc,cm,km,pulg,pie,milla;
    printf("---MENU---\n1.-cm a pulgadas\n2.-cm a pies\n3.-Km a millas\n4.-Pulgadas a cm\n5.-pies a cm\n6.-millas a Km\n");
    printf("Seleccione una opcion: ");
    scanf("%d",&opc);
    if(opc==1)
    {
        printf("CM: ");
        scanf("%d",&cm);
        printf("Pulgadas: %f",cm/2.54);
    }
    else
    {
        if(opc==2)
        {
        printf("CM: ");
        scanf("%d",&cm);
        printf("Pies: %.2f",(cm+0.0)*48);
        }
        else
        {
            if(opc==3)
            {
                printf("Kilometros: ");
                scanf("%d",&km);
                printf("Millas: %f",km/1.609);
            }
            else
            {
                if(opc==4)
                {
                    printf("Pulgadas: ");
                    scanf("%d",&pulg);
                    printf("Centimetros: %.2f",pulg*2.54);
                }
                else
                {
                    if(opc==5)
                    {
                        printf("Pies: ");
                        scanf("%d",&pie);
                        printf("Centimetro: %f",(pie+.0)/48);
                    }
                    else
                    {
                        if(opc==6)
                        {
                            printf("Millas: ");
                            scanf("%d",&milla);
                            printf("Kilometro: %f",milla/0.609);
                        }
                        else
                        {
                            printf("Opcion incorrecta");
                        }
                    }
                }
            }
        }
    }
    return 0;
}