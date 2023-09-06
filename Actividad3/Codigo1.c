#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Promedio(void);
void PPP_anidado(void);
void PPP_multiple(void);
void Mayor(void);
void Medio(void);
void Ascendentes(void);
void Zodiacal(void);
//****  main principal  *********
int main()
{
    srand(time(NULL));
    menu();

    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- PROMEDIO \n");
    printf("2.- CHICHAMPU ANIDADO \n");
    printf("3.- CHICHAMPU SELECCION MULTIPLE \n");
    printf("4.- NUMERO MAYOR  \n");
    printf("5.- NUMERO EN MEDIO  \n");
    printf("6.- NUMEROS ASCENDENTES  \n");
    printf("7.- SIGNO ZODIACAL  \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            Promedio();
            break;
        case 2:
            PPP_anidado();
            break;
        case 3:
            PPP_multiple();
            break;
        case 4:
            Mayor();
            break;
        case 5:
            Medio();
            break;
        case 6:
            Ascendentes();
            break;
        case 7:
            Zodiacal();
            break;
        }

    } while (op != 0);
}

//*********************
void Promedio(void)
{
    //  VARIABLES LOCALES
    int c1, c2, c3;
    float prom;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   PROMEDIO\n");
    // LEEMOS 3 CALIFICACIONES
    printf("Calificacion 1: \n");
    scanf("%d", &c1);
    printf("Calificacion 2: \n");
    scanf("%d", &c2);
    printf("Calificacion 3: \n");
    scanf("%d", &c3);
    prom = (c1 + c2 + c3) / 3;
    if (prom >= 80)
    {
        if(prom>=90)
        {
            if(prom>=98)
            {
                if(prom>100)
                {
                    //PROMEDIO INCORRECTO
                    printf("Error en el promedio \nPromedio: %.2f \n,prom");
                }
                else
                {
                    //ES 98
                    printf("Excelente \nPromedio: %.2f \n",prom);
                }
            }
            else
            {
                //ES 90
                printf("Muy bien \nPromedio: %.2f \n",prom);
            }
        }
        else
        {
            //ES 80
            printf("Bien \nPromedio: %.2f \n",prom);
        }
    }
    else
    {
        if (prom<70)
        {
           if(prom<60)
            {
                if(prom<30)
                {
                    //REPITES
                    printf("Repetidor \nPromedio: %.2f \n",prom);
                }
                else
                {
                    //EXTRAORDINARIO
                    printf("Extraordinario \nPromedio: %.2f \n",prom);
                }
            }
            else
            {
                //ES 60
                printf("Suficiente \nPromedio: %.2f \n",prom);
            } 
        }
        else
        {
            //ES 70
            printf("Regular \nPromedio: %.2f \n",prom);
        }
    }
    system("PAUSE");
}

//*************************
void PPP_anidado(void)
{

    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n");
    system("PAUSE");
}
//****************************
void PPP_multiple(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
void Mayor(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
void Medio(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
void Ascendentes(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
void Zodiacal(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}