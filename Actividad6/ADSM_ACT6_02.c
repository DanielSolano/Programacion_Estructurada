#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void DerechoExamen(void);
void Multiplicar(void);
void Rango(void);
void Embarcacion(void);
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
    printf("1.- EXAMEN DE NIVELACION \n");
    printf("2.- TABLAS DE MULTIPLICAR \n");
    printf("3.- NUMEROS DENTRO DE RANGO \n");
    printf("4.- EMBARCACION FINISTERRA \n");
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
            DerechoExamen();
            break;
        case 2:
            Multiplicar();
            break;
        case 3:
            Rango();
            break;
        case 4:
            Embarcacion();
            break;
        }

    } while (op != 0);
}

//*********************
void DerechoExamen(void)
{
    //  VARIABLES LOCALES
    int i, j, prom, s_derecho, cal;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    s_derecho = 0;
    i = 1;
    j = 1;
    printf("   EXAMEN DE NIVELACION\n");
    for (i = 1; i <= 40; i++)
    {
        prom = 0;
        system("CLS");
        printf("ALUMNO %d\n", i);
        for (j = 1; j <= 5; j++, prom += cal)
        {
            printf("Calificacion unidad %d: \n", j);
            scanf("%d", &cal);
        }
        prom /= 5;
        printf("%d", prom);
        if (prom < 50)
        {
            s_derecho++;
        }
    }
    system("CLS");
    printf("La cantidad de alumnos sin derecho a examen es: %d\n", s_derecho);
    system("PAUSE");
}

//*************************
void Multiplicar(void)
{
    //  VARIALES LOCALES
    int i, j;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   TABLAS DE MULTIPLICAR\n");
    for (i = 1; i <= 10; i++)
    {
        system("CLS");
        printf("TABLA DEL %d\n", i);
        for (j = 1; j <= 10; j++)
        {
            printf("%d x %d = %d\n", i, j, (i * j));
        }
        system("PAUSE");
    }
}
//****************************
void Rango(void)
{
    //  VARIALES LOCALES
    int i, inferior, superior, n, suma, limite, numero;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   NUMEROS DENTRO DE RANGO\n");
    system("CLS");
    printf("Rango inferior: \n");
    scanf("%d", &inferior);
    printf("Rango superior: \n");
    scanf("%d", &superior);
    if (inferior >= superior)
    {
        do
        {
            system("CLS");
            printf("Ingresa un rango valido\n");
            system("PAUSE");
            printf("Rango inferior: \n");
            scanf("%d", &inferior);
            printf("Rango superior: \n");
            scanf("%d", &superior);
        } while (inferior >= superior);
    }

    limite = superior - inferior;
    system("CLS");
    printf("Cuantos numeros ingresaras: \n");
    scanf("%d", &n);
    if (n > limite)
    {
        do
        {
            system("CLS");
            printf("Ingresa una cantidad valida\n");
            system("PAUSE");
            printf("Cuantos numeros ingresaras: \n");
            scanf("%d", &n);
        } while (n > limite);
    }

    i = 0;
    numero = 0;
    suma = 0;
    for (i = 1; i <= n; i++, suma += numero)
    {
        printf("Numero %d: \n", i);
        scanf("%d", &numero);
    }
    system("CLS");
    printf("La suma de los numeros es: %d\n", suma);
    printf("La media aritmetica de los numeros es: %.2f\n", ((suma + .0) / n));
    system("PAUSE");
}
//****************************
void Embarcacion(void)
{
    //  VARIALES LOCALES
    int turistas, peso, band, ac;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   EMBARCACION FINISTERRA\n");
    band = 1;
    turistas = 0;
    ac=0;
    while (band)
    {
        printf("Ingresa tu peso turista %d: \n", ++turistas);
        scanf("%d", &peso);
        ac += peso;
        if (peso >= 805)
        {
            band = 0;
        }
        if (turistas == 10)
        {
            band = 0;
        }
    }
    
    printf("El promedio de peso de los pasajeros es: %.2f\n", (ac + .0) / (turistas + .0));

    if (turistas == 10)
    {
        printf("Se llego al maximo de pasajeros permitidos\n");
    }
    else
    {
        printf("Se llego al maximo de peso permitido en la embarcacion\n");
    }
    system("PAUSE");
}