// Solano Meza Angel Daniel Matr. 372453
// 19/09/2023
// Uso de ciclos y de validacion para problemas
// ADSM_ACT6_02_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
int Validar(char msg[], int inferior, int superior); //Funcion para las entradas sean validas
void DerechoExamen(void); // Funcion que cuenta alumnos con derecho a examen
void Multiplicar(void); //Funcion que imprime las tablas de multiplicar
void Rango(void); //Funcion que permite imprimir numeros dentro de un rango
void Embarcacion(void); //Funcion que mide los tripulantes y peso de un barco
void Recursadores(void); //Funcion que avisa si pasas o repites una materia
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
    printf("5.- RECURSADORES\n");
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
        case 5:
            Recursadores();
            break;
        }

    } while (op != 0);
}
//*********************
int Validar(char msg[], int inferior, int superior) //Parametros para funcionar
{
    int num;
    char cadena[4];
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena); //Tomas los datos como cadena
        num = atoi(cadena); //Transforma la entrada a entero

    } while ((num < inferior) || (num > superior));
    return num;
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
    for (i = 1; i <= 40; i++) //Ciclo que controla los alumnos
    {
        prom = 0;
        system("CLS");
        printf("ALUMNO %d\n", i);
        for (j = 1; j <= 5; j++, prom += cal) //Ciclo que controla los parciales y suma el promedio
        {
            printf("PARCIAL %d\n", j);
            cal = Validar("Ingresa tu calificacion: \n", 0, 100);
        }
        prom /= 5; //Saca el promedio
        if (prom < 50)
        {
            s_derecho++; // Si el promedio es menor a 50 incrementa a los alumnos sin derecho a examen
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
    for (i = 1; i <= 10; i++) //Ciclo que controla que numero de tabla se imprimira
    {
        system("CLS");
        printf("TABLA DEL %d\n", i);
        for (j = 1; j <= 10; j++) //Hace que el numero se multiplique del 1 al 10
        {
            printf("%d x %d = %d\n", i, j, (i * j)); //Hace la operacion aqui ya que no sera necesaria despues
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
    inferior = Validar("Rango inferior: \n", 0, 2147483647); //Ingresa el rango inferior
    superior = Validar("Rango superior: \n", inferior, 2147483647); //Ingresa el rango superior

    limite = superior - inferior;
    system("CLS");
    limite = Validar("Cuantos numeros ingresara?: \n", 0, limite);
    //Utilizamos los rangos para validar el numero de datos que dara el usuario
    i = 0;
    suma = 0;
    for (i = 1; i <= limite; i++, suma += numero) //Ciclo para leer el numero de datos solicitado
    {
        printf("NUMERO %d: \n", i);
        numero = Validar("Ingresa el numero: \n", inferior, superior); //Ingresa el numero dentro de rango validado
    }

    system("CLS");
    printf("La suma de los numeros es: %d\n", suma); //Imprime la suma
    printf("La media aritmetica de los numeros es: %.2f\n", ((suma + .0) / limite)); //Imprime la media
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
    ac = 0;
    while (band)
    {
        printf("TURISTA %d: \n", ++turistas);
        peso = Validar("Ingresa tu peso: \n", 0, 805);
        ac += peso;
        if (peso >= 805) //Si se llega al limite de peso sale
        {
            band = 0;
        }
        if (turistas == 10) //Si se llega a los 10 turistas sale
        {
            band = 0;
        }
    }

    printf("El promedio de peso de los pasajeros es: %.2f\n", (ac + .0) / (turistas + .0));
    //Imprime el promedio de peso de los pasajeros

    //Este if imprime la razon del porque salio
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
//****************************
void Recursadores(void) 
{
    //  VARIABLES LOCALES
    int cal, intentos, prom, band, i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   REPETIDOR O REGULAR\n");
    band = 1;
    intentos = 1;
    prom = 0;
    i = 1;
    while (band)
    {
        printf("INTENTO %d \n", intentos);
        prom = 0;
        for (i = 1; i <= 3; i++, prom += cal) //Ciclo para leer las 3 calificaciones
        {
            cal = Validar("Ingresa tu calificacion: \n", 0, 100);
        }
        prom /= 3;

        if (prom >= 60) //Si el promedio > 60 pasaste
        {
            band = 0;
            system("CLS");
            printf("Alumno aprobado \n");
            system("PAUSE");
        }
        else
        {
            if (intentos < 3) // Si los intentos no superan los 3 repites
            {
                system("CLS");
                printf("Alumno debe repetir materia\n");
                system("PAUSE");
            }
            else // Si son mas de 3 intentos es baja
            {
                system("CLS");
                printf("Alumno con baja temporal \n");
                system("PAUSE");
                band = 0;
            }
        }
        intentos++;
    }
}