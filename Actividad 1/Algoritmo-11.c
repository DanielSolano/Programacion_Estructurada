// Solano Meza Angel Daniel Matr. 372453
// 27/08/2023
// Dependiendo del tipo de llamada y duracion calcular el precio de la misma
// ADSM_ACT1_11_932
#include <stdio.h>
#define iva 0.16
#define loc 3
#define nac 7
#define inter 9

int main()
{
    int tipo, duracion, subtotal,  m_adicional;
    float p_iva, total;
    printf("\n(1)Local\n(2)Nacional\n(3)Internacional\nSeleccione su tipo de llamada: ");
    scanf("%d",&tipo);

    if((tipo != 1) && (tipo != 2) && (tipo !=3))
    {
        printf("Tipo de llamada intexistente");
    }
    else
    {
        printf("Duracion de su llamada: ");
        scanf("%d",&duracion);
        if(tipo==1)
        {
            subtotal=loc;
            p_iva=subtotal*iva;
            total=subtotal+p_iva;
            printf("Llamada local\nSubtotal: %d\nIva (16%%): %.2f\nTotal: %.2f",subtotal,p_iva,total);
        }
        else
        {
            if (tipo==2)
            {
                if(duracion<=3)
                {
                    subtotal=nac;
                    p_iva=subtotal*iva;
                    total=p_iva+subtotal;
                printf("Llamada nacional\nSubtotal: %d\nIva (16%%): %.2f\nTotal: %.2f",subtotal,p_iva,total);

                }
                else
                {
                    m_adicional=duracion-3;
                    subtotal=nac+(m_adicional*2);
                    p_iva=subtotal*iva;
                    total=p_iva+subtotal;
                    printf("Llamada nacional\nSubtotal: %d\nIva (16%%): %.2f\nTotal: %.2f",subtotal,p_iva,total);
                }
            }
            else
            {
                if(duracion<=2)
                {
                    subtotal=inter;
                    p_iva=subtotal*iva;
                    total=subtotal+p_iva;
                    printf("Llamada internacional\nSubtotal: %d\nIva (16%%): %.2f\nTotal: %.2f",subtotal,p_iva,total);

                }
                else
                {
                m_adicional=duracion-2;
                subtotal=inter+(m_adicional*4);
                p_iva=subtotal*iva;
                total=p_iva+subtotal;
                printf("Llamada internacional\nSubtotal: %d\nIva (16%%): %.2f\nTotal: %.2f",subtotal,p_iva,total);
                }
                
            }
        }
    }
    
    return 0;
}