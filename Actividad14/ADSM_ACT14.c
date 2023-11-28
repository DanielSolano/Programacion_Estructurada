// Solano Meza Angel Daniel Matr. 372453
// 13/11/2023
// Uso de archivos binarios
// ADSM_ACT13_932

#define N 5000
#define AUTO 100
#include "junior.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void NombreArch(char archivo[]);

//****  main principal  *********
int main()
{
    menu();

    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- AGREGAR REGISTROS \n");
    printf("2.- EDITAR REGISTRO \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- IMPRIMIR \n");
    printf("7.- GENERAR ARCHIVO TXT \n");
    printf("8.- VER ARCHIVO TXT \n");
    printf("9.- CREAR ARCHIVO BINARIO \n");
    printf("10.- CARGAR ARCHIVO BINARIO \n");
    printf("11.- MOSTRAR ELIMINADOS \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    srand(time(NULL));
    int op, n;
    char dat[10];
    n = ContarReg("datos");
    n *= 1.25;
    printf("%d", n);
    system("PAUSE");
    do
    {
        op = msges();
        switch (op)
        {
        case 1: // AGREGAR

            break;
        case 2: // EDITAR REGISTRO

            break;
        case 3: // ELIMINAR REGISTRO

            break;
        case 4:

            break;
        case 5: // ORDENAR REGISTROS

            break;
        case 6: // IMPRIMIR REGISTROS

            break;
        case 7: // GENERAR TXT

            break;
        case 8: // MOSTRAR ARCHIVO TXT

            break;
        case 9: // CREAR BINARIO;

            break;
        case 10: // CARGAR BINARIO

            break;
        case 11: // MOSTRAR BORRADOS

            break;
        case 0:

            break;
        }
    } while (op != 0);
}

int ContarReg(char nombre[])
{
    int cont;
    char cmd[50];

    system("gcc Contador.c -o Contador");
    sprintf(cmd, "Contador.exe %s", nombre);
    cont = system(cmd);

    return cont;
}

void NombreArch(char archivo[])
{

    system("CLS");
    printf("NOMBRE DEL ARCHIVO SIN EXTENSION: \n");
    fflush(stdin);
    gets(archivo);
}
