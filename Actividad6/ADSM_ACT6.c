#include <stdio.h>
#include <stdlib.h>
#define N 10
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void for_Fibonacci(void);
void while_Fibonacci(void);
void dowhile_Fibonacci(void);
void for_Factorial(void);
void while_Factorial(void);
void dowhile_Factorial(void);
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
    printf("1.- FIBONACCI FOR \n");
    printf("2.- FIBONACCI WHILE \n");
    printf("3.- FIBONACCI DO-WHILE \n");
    printf("4.- FACTORIAL FOR\n");
    printf("5.- FACTORIAL WHILE\n");
    printf("6.- FACTORIAL DO-WHILE\n");
    printf("6.- DIGITOS \n");
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
            for_Fibonacci();
            break;
        case 2:
            while_Fibonacci();
            break;
        case 3:
            dowhile_Fibonacci();
            break;
        case 4:
            for_Factorial();
            break;
        case 5:
            while_Factorial();
            break;
        case 6:
            dowhile_Factorial();
            break;
        case 7:
            Digitos();
            break;
        }

    } while (op != 0);
}

//*********************
void for_Fibonacci(void)
{
    //  VARIALES LOCALES
    int ante, sig, resul, n, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FIBONACCI FOR\n");
    ante = 0;
    sig = 1;
    resul = 1;
    printf("Cuantas veces se repetira la serie: \n");
    scanf("%d", &n);
    system("CLS");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", resul);
        resul = ante + sig;
        ante = sig;
        sig = resul;
    }
    system("PAUSE");
}

//*********************
void while_Fibonacci(void)
{
    //  VARIALES LOCALES
    int ante, sig, resul, n, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FIBONACCI WHILE\n");
    printf("Cuantas veces se repetira la serie: \n");
    scanf("%d", &n);
    i = 0;
    ante = 0;
    sig = 1;
    resul = 1;
    while (i < n)
    {
        printf("%d\n", resul);
        resul = ante + sig;
        ante = sig;
        sig = resul;
        i++;
    }
    system("PAUSE");
}

//*********************
void dowhile_Fibonacci(void)
{
    //  VARIALES LOCALES
    int ante, sig, resul, n, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FIBONACCI DO-WHILE\n");
    printf("Cuantas veces se repetira la serie: \n");
    scanf("%d", &n);
    system("CLS");
    i = 0;
    ante = 0;
    sig = 1;
    resul = 1;
    do
    {
        printf("%d\n", resul);
        resul = ante + sig;
        ante = sig;
        sig = resul;
        i++;

    } while (i < n);
    system("PAUSE");
}

//*************************
void for_Factorial(void)
{
    //  VARIALES LOCALES
    int n, fact, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n");
    printf("Factorial del numero: \n");
    scanf("%d", &n);
    fact = 1;
    if (n == 0)
    {
        printf("Factorial de 0 = 1");
    }
    for (i = 1; i <= n; i++)
    {
        fact = i * fact;
    }
    printf("Factorial de %d = %d\n", n, fact);
    system("PAUSE");
}

//*************************
void while_Factorial(void)
{

    //  VARIALES LOCALES
    int n, fact, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL WHILE\n");
    printf("Factorial del numero: \n");
    scanf("%d", &n);
    fact = 1;
    i = 1;
    if (n == 0)
    {
        printf("Factorial de 0 = 1");
    }
    while (i <= n)
    {
        fact = i * fact;
        i++;
    }
    printf("Factorial de %d = %d\n", n, fact);
    system("PAUSE");
}

//*************************
void dowhile_Factorial(void)
{

    //  VARIALES LOCALES
    int n, fact, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL DO-WHILE\n");
    printf("Factorial del numero: \n");
    scanf("%d", &n);
    fact = 1;
    i = 1;
    if (n == 0)
    {
        printf("Factorial de 0 = 1");
    }
    else
    {
        do
        {
            fact = i * fact;
            i++;
        } while (i <= n);
    }
    printf("Factorial de %d = %d\n", n, fact);
    system("PAUSE");
}

//****************************
void Digitos(void)
{
    //  VARIALES LOCALES
    int n, digitos;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    printf("Cantidad de digitos de: \n");
    scanf("%d", &n);
    
    system("PAUSE");
}