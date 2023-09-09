// Solano Meza Angel Daniel Matr. 372453
// 09/09/2023
// Numeros descendentes, suma de pares e impares, identificar mayor y menor, tabla de multiplicar
// ADSM_ACT5_932
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 35
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Descendentes(void);
void Pares(void);
void MeMa(void);
void Multiplicar(void);
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
    printf("1.- DESCENDENTES \n");
    printf("2.- PARES \n");
    printf("3.- MAYOR Y MENOR \n");
    printf("4.- TABLAS DE MULTIPLICAR \n");
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
            Pares();
            break;
        case 3:
            MeMa();
            break;
        case 4:
            Multiplicar();
            break;
        }

    } while (op != 0);
}

//*********************
void Descendentes(void)
{
    //  VARIALES LOCALES
    int numero, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DESCENDENTES\n");
    printf("Dame un numero: \n");
    scanf("%d", &numero);
    i = 0;
    system("CLS");
    for (i = numero; i > 0; i--) // Se guarda con el valor del numero para imprimirlo y decrementarlo cada iteracion
    {
        printf("%d\n", i);
    }
    system("PAUSE");
}

//*************************
void Pares(void)
{

    //  VARIALES LOCALES
    int i, numero, n_par, n_impar, par, impar;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    i = 0;
    n_par = 0;
    n_impar = 0;
    par = 0;
    impar = 0;
    printf("   PARES\n");
    for (i = 0; i < 40; i++)
    {
        numero = rand() % 201; // Genera un numero entre 0 y 200
        if (numero % 2 == 0)
        {
            // Entra si es par, aumenta al contador de par y se suma al acumulador
            n_par++;
            par = numero + par;
            printf("El numero %d es par\n", numero);
        }
        else
        {
            // Entra si es par, aumenta al contador de par y se suma al acumulador
            n_impar++;
            impar = numero + impar;
            printf("El numero %d es impar\n", numero);
        }
    }
    printf("\n%d numeros pares\n%d numeros impares\nLa suma de los numeros pares es: %d\nLa suma de los numeros impares es: %d\n", n_par, n_impar, par, impar);

    system("PAUSE");
}
//****************************
void MeMa(void)
{
    //  VARIALES LOCALES
    int mayor, menor, numero, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   MAYOR Y MENOR\n");
    numero = rand() % 101 + 100; // Genera un numero entre 100 y 200
    menor = numero;
    mayor = numero; // Utilizamos dos pivotes y comparamos con los 39 numeros restantes
    for (i = 0; i < N - 1; i++)
    {
        numero = rand() % 101 + 100;
        if (numero > mayor)
        {
            mayor = numero; // Convierte al mayor
        }
        if (numero < menor)
        {
            menor = numero; // Convierte al menor
        }
    }
    printf("El numero mayor es %d\nEl menor es %d\n", mayor, menor);
    system("PAUSE");
}
//****************************
void Multiplicar(void)
{
    //  VARIALES LOCALES
    int numero, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   TABLA DE MULTIPLICAR\n");
    printf("Desplegar tabla del: \n(Numero del 1-20)\n");
    scanf("%d", &numero);
    system("CLS");
    for (i = 1; i <= 10; i++)
    {
        // Imprime el numero x el contador, el contador incrementa cada iteracion hasta el 10
        printf("%d x %d = %d\n", numero, i, (numero * i));
    }
    system("PAUSE");
}