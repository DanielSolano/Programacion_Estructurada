#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
char LeerCadena(void);
void Salida1(void);
void Salida2(void);
void Salida3(void);
void Salida4(void);
void Salida5(void);
void Salida6(void);
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
    printf("1.- SALIDA 1 \n");
    printf("2.- SALIDA 2 \n");
    printf("3.- SALIDA 3 \n");
    printf("4.- SALIDA 4 \n");
    printf("5.- SALIDA 5 \n");
    printf("6.- SALIDA 6 \n");
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
            Salida1();
            break;
        case 2:
            Salida2();
            break;
        case 3:
            Salida3();
            break;
        case 4:
            Salida4();
            break;
        case 5:
            Salida5();
            break;
        case 6:
            Salida6();
            break;
        }
    } while (op != 0);
}
//*********************
void Salida1(void)
{
    //  VARIALES LOCALES
    int i;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 1");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);
    system("CLS");
    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    printf("%s\n", cadena);
    system("PAUSE");
}

//*************************
void Salida2(void)
{

    //  VARIALES LOCALES
    int i, j;
    char cadena[100], copia[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 2\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    system("CLS");
    for (j = i; j >= 0; j--)
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Salida3(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100], copia[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 3\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    system("CLS");
    for (j = 0; j <= i; j++)
    {
        printf("%c\n", cadena[j]);
    }
    system("PAUSE");
}
//****************************
void Salida4(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100], copia[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 4\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    system("CLS");
    for (j = i; j >= 0; j--)
    {
        printf("%c\n", cadena[j]);
    }
    system("PAUSE");
}
//****************************
void Salida5(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 5\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    system("CLS");
    for (j = 0; j <= i; j++)
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Salida6(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
