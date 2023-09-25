#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Mayusculas(char cadena[]);
void Minusculas(char cadena[]);
void Capital(char cadena[]);
//****  main principal  *********
int main()
{
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
    printf("1.- MAYUSCULAS \n");
    printf("2.- MINUSCULAS \n");
    printf("3.- CAPITAL \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op;
    char cadena[100];
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("CLS");
            printf("   MAYUSCULAS\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Mayusculas(cadena);
            break;
        case 2:
            system("CLS");
            printf("   MINUSCULAS\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Minusculas(cadena);
            break;
        case 3:
            system("CLS");
            printf("   CAPITAL\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Capital(cadena);
            break;
        }

    } while (op != 0);
}

//*********************
void Mayusculas(char cadena[])
{
    //  VARIALES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA
    i = 0;
    for (i = 0; cadena[i] != '\0'; i++) // Convierte a mayusculas
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    for (j = 0; j <= i; j++)
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}

//*************************
void Minusculas(char cadena[])
{

    //  VARIALES LOCALES
    int i, j, k;
    //  AQUI DESARROLLO PROGRAMA
    i = 0;
    for (i = 0; cadena[i] != '\0'; i++) // Convierte a minusculas
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                cadena[i] = cadena[i] + 32;
            }
        }
    }
    for (j = 0; j <= i; j++)
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Capital(char cadena[])
{
    //  VARIALES LOCALES
    int i, j, k;
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0; cadena[i] != '\0'; i++) // Cuenta los caracteres totales
    {
        if (i == 0) // Convierte a mayusculas el primer caracter
        {
            if (cadena[i] != ' ')
            {
                if (cadena[i] >= 'a')
                {
                    if (cadena[i] <= 'z')
                    {
                        cadena[i] = cadena[i] - 32;
                    }
                }
            }
            else
            {
                if (cadena[i + 1] >= 'a')
                {
                    if (cadena[i + 1] <= 'z')
                    {
                        cadena[i + 1] = cadena[i + 1] - 32;
                    }
                }
            }
        }
    }

    for (j = 0; j <= i; j++)
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}
