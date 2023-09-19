// Solano Meza Angel Daniel Matr. 372453
// 19/09/2023
// Uso de distintos ciclos para los mismos problemas.
// ADSM_ACT6_01_932
#include <stdio.h>
#include <stdlib.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void for_Fibonacci(void); //Funcion fibonacci con for
void while_Fibonacci(void); //Funcion fibonacci con while
void dowhile_Fibonacci(void); //Funcion fibonacci con dowhile
void for_Factorial(void); //Funcion factorial con for
void while_Factorial(void); //Funcion factorial con while
void dowhile_Factorial(void); //Funcion factorial con dowhile
void for_Digitos(void); //Funcion para contar digitos con for
void while_Digitos(void); //Funcion para contar digitos con while
void dowhile_Digitos(void); //Funcion para contar digitos con dowhile

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
    printf("7.- DIGITOS FOR\n");
    printf("8.- DIGITOS WHILE\n");
    printf("9.- DIGITOS DO-WHILE\n");
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
            for_Digitos();
            break;
        case 8:
            while_Digitos();
            break;
        case 9:
            dowhile_Digitos();
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
    ante = -1;
    sig = 1;
    printf("Cuantas veces se repetira la serie: \n");
    scanf("%d", &n);
    system("CLS");
    for (i = 0; i < n; i++)// Controla las veces que se realizara la serie
    {
        resul = ante + sig;
        ante = sig;
        sig = resul; //Se transforman las variables para poder continuar con el ciclo
        printf("%d\n", resul);
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
    ante = -1;
    sig = 1;
    resul = 1;
    system("CLS");
    while (i < n) // Controla las veces que se realizara la serie
    {
        resul = ante + sig;
        ante = sig;
        sig = resul; //Se transforman las variables para poder continuar con el ciclo
        i++;
        printf("%d\n", resul);
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
    ante = -1;
    sig = 1;
    resul = 1;
    do
    {
        resul = ante + sig;
        ante = sig;
        sig = resul; //Se transforman las variables para poder continuar con el ciclo
        i++;
        printf("%d\n", resul);

    } while (i < n); // Controla las veces que se realizara la serie
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
        printf("Factorial de 0 = 1"); //Caso base
    }
    for (i = 1; i <= n; i++)
    {
        fact = i * fact; //Se multiplica y se guarda en si mismo para obtener el factorial
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
        printf("Factorial de 0 = 1"); //Caso base
    }
    while (i <= n)
    {
        fact = i * fact; //Se multiplica y se guarda en si mismo para obtener el factorial
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
        printf("Factorial de 0 = 1"); //Caso base
    }
    else
    {
        do
        {
            fact = i * fact; //Se multiplica y se guarda en si mismo para obtener el factorial
            i++;
        } while (i <= n);
    }
    printf("Factorial de %d = %d\n", n, fact);
    system("PAUSE");
}

//****************************
void for_Digitos(void)
{
    //  VARIALES LOCALES
    int num, x, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    printf("Contar digitos del numero: \n");
    scanf("%d", &num);
    i = 0;
    x = 1;
    for (i = 0; num >= x; i++, x = x * 10) 
    {
        //Cada que entra al ciclo se agrega un digito a X
        //El numero se compara con X
        //Cada aumento de i significa que aumento un digito
    }
    printf("El numero %d tiene %d digitos \n", num, i);
    system("PAUSE");
}
//****************************
void while_Digitos(void)
{
    //  VARIALES LOCALES
    int num, x, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    printf("Contar digitos del numero: \n");
    scanf("%d", &num);
    i = 0;
    x = 1;
    while (num >= x) //El numero se compara con X
    {
        x = x * 10; //Cada que entra al ciclo se agrega un digito a X
        i++; //Cada aumento de i significa que aumento un digito
    }
    printf("El numero %d tiene %d digitos \n", num, i);
    system("PAUSE");
}
//****************************
void dowhile_Digitos(void)
{
    //  VARIALES LOCALES
    int num, x, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    printf("Contar digitos del numero: \n");
    scanf("%d", &num);
    i = 0;
    x = 1;
    do
    {
        x = x * 10; //Cada que entra al ciclo se agrega un digito a X
        i++; //Cada aumento de i significa que aumento un digito
    } while (num >= x); //El numero se compara con X

    printf("El numero %d tiene %d digitos \n", num, i);
    system("PAUSE");
}