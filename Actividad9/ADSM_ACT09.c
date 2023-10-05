#include "miti.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
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
    printf("1.- LLENAR VECTOR \n");
    printf("2.- LLENAR MATRIZ \n");
    printf("3.- IMPRIMIR VECTOR \n");
    printf("4.- IMPRIMIR MATRIZ \n");
    printf("5.- ORDENAR VECTOR \n");
    printf("6.- BUSCAR VALOR EN EL VECTOR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    op = Validar(0, 6);
    return op;
}
//****************
void menu()
{
    int op, num, i;
    int vector[15], matriz[4][4];
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            LlenarVector(vector, 15, 100, 200, 1);
            break;
        case 2:
            LlenarMatrizR(matriz, 4, 4, 1, 16);
            break;
        case 3:
            ImprimirVector(vector, 15, "VECTOR");
            break;
        case 4:
            ImprimirMatriz(matriz, 4, 4, "MATRIZ");
            break;
        case 5:
            Ordenar(vector, 15);
            break;
        case 6:
            system("CLS");
            printf("NUMERO QUE DESEAS ENCONTRAR: \n");
            num = Validar(100, 200);
            i = BusquedaSec(vector, 15, num);
            if (i != -1)
            {
                printf("EL VALOR SE ENCUENTRA EN EL INDICE %d\n",i);
            }
            else
            {
                printf("EL VALOR NO SE ENCUENTRA EN EL VECTOR\n");
            }
            system("PAUSE");
            break;
        }

    } while (op != 0);
}
