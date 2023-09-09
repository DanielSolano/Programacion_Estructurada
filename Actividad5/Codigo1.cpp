#include <stdio.h>
#include <stdlib.h>
#define N 10
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Descendentes(void);
void Factorial(void);
void Digitos(void);
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
    printf("1.- DESCENDENTES \n");
    printf("2.- FACTORIAL \n");
    printf("3.- DIGITOS \n");
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
            Descendentes();
            break;
        case 2:
            Factorial();
            break;
        case 3:
            Digitos();
            break;
        }

    } while (op != 0);
}

//*********************
void Descendentes(void)
{
    //  VARIALES LOCALES
    int numero, i, j, temp;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DESCENDENTES\n");
    printf("Dame un numero: \n");
    scanf("%d", &numero);
    i = 0;
    temp = numero;
    system("CLS");
    for (i = numero - 1; i >= 0; i--)
    {
        printf("%d\n", temp);
        temp--;
    }
    system("PAUSE");
}

//*************************
void Factorial(void)
{

    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n");
    system("PAUSE");
}
//****************************
void Digitos(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}