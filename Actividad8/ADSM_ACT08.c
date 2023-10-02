// Solano Meza Angel Daniel Matr. 372453
// 30/09/2023
// Utilizar vectores para crear arreglos e imprimirlos.
// ADSM_ACT8_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void LlenarVector(int vect[], int m, int ri, int rf, int op);
int Validar(char msg[], int inferior, int superior);
void Vector3(int vect3[], int vect2[], int vect[1]);
void ImprimirVector(char msg[], int vect[], int m);
void LlenarMatriz(int matriz[][4], int vect1[], int vect2[], int m, int n);
void ImprimirMatriz(int matriz[][4], int m, int n);

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
    printf("1.- LLENAR VECTOR 1 MANUALMENTE  \n");
    printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE \n");
    printf("3.- LLENAR VECTOR 3 CON VECTOR 1 Y VECTOR 2 \n");
    printf("4.- IMPRIMIR VECTORES \n");
    printf("5.- LLENA MATRIZ 4 X 4 \n");
    printf("6.- IMPRIMIR MATRIZ \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op, vector1[10], vector2[10], vector3[20], matriz[4][4];
    do
    {
        srand(time(NULL));
        op = msges();
        switch (op)
        {
        case 1:
            printf("LLENAR VECTOR 1 MANUALMENTE\n");
            LlenarVector(vector1, 10, 30, 70, 0);
            system("CLS");
            printf("Vector 1 rellenado\n");
            system("PAUSE");
            break;
        case 2:
            printf("LLENAR VECTOR 2 AUTOMATICAMENTE\n");
            LlenarVector(vector2, 10, 1, 20, 1);
            system("CLS");
            printf("Vector 2 rellenado\n");
            system("PAUSE");
            break;
        case 3:
            printf("LLENAR VECTOR 3 \n");
            Vector3(vector3, vector1, vector2);
            system("CLS");
            printf("Vector 3 rellenado\n");
            system("PAUSE");
            break;
        case 4:
            ImprimirVector("VECTOR 1", vector1, 10);
            ImprimirVector("VECTOR 2", vector2, 10);
            ImprimirVector("VECTOR 3", vector3, 20);
            break;
        case 5:
            LlenarMatriz(matriz, vector1, vector2, 4, 4);
            break;
        case 6:
            ImprimirMatriz(matriz, 4, 4);
            break;
        }

    } while (op != 0);
}

//*********************
int Validar(char msg[], int inferior, int superior) // Parametros para funcionar
{
    int num;
    char cadena[3];
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);       // Tomas los datos como cadena
        num = atoi(cadena); // Transforma la entrada a entero
    } while ((num < inferior) || (num > superior));
    return num;
}
//*********************
void LlenarVector(int vect[], int m, int ri, int rf, int op)
{
    //  VARIABLES LOCALES
    int i, j, num;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    if (op == 1) // Opcion rellenado automatico
    {
        for (i = 0; i < m; i++) // Le asgina un valor a cada indice del vector
        {
            vect[i] = (rand() % (ri - rf)) + ri;
            for (j = 0; j < i; j++) // Barre el vector hasta i comprobando que no se repita el numero
            {
                if (vect[i] == vect[j]) // Si se encuentra un numero repetido lo vuelve a generar
                {
                    vect[i] = (rand() % (ri - rf)) + ri;
                }
            }
        }
    }
    else // Opcion rellenado manual
    {
        for (i = 0; i < m; i++)
        {
            printf("    Espacio [%d]\n", i + 1);
            vect[i] = Validar("Numero entre 30 y 70\n", 30, 70); // Valida la entrada manual
        }
    }
}

//****************************
void Vector3(int vect3[], int vect2[], int vect1[])
{
    //  VARIABLES LOCALES
    int i;
    system("CLS");
    for (i = 0; i < 10; i++)
    {
        vect3[i] = vect2[i];      // Los primeros 10 espacios se llenan con el vector 2
        vect3[i + 10] = vect1[i]; // Del 10 al 20 con el vector 1
    }
    //  AQUI DESARROLLO PROGRAMA
}
//****************************
void ImprimirVector(char msg[], int vect[], int m)
{
    //  VARIALES LOCALES
    int i;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("%s\n", msg);
    for (i = 0; i < m; i++)
    {
        printf("[%d] --> %d\n", i + 1, vect[i]); // Imprime el valor del del arreglo en el indice
    }
    system("PAUSE");
}
//****************************
void LlenarMatriz(int matriz[][4], int vect1[], int vect2[], int m, int n)
{
    //  VARIALES LOCALES
    int i, j, k;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0, k = 0; i < m; i++)
    {
        for (j = 0; j < n; j++, k++)
        {
            if (k < 10) // Llena la matriz con los 10 datos del vector 1
            {
                matriz[i][j] = vect1[k];
            }
            else // Cuando se termina el vector 1 continua con el vector 2
            {
                matriz[i][j] = vect2[k - 10];
            }
        }
    }
    printf("Matriz rellenada\n");
    system("PAUSE");
}
//****************************
void ImprimirMatriz(int matriz[][4], int m, int n)
{
    //  VARIALES LOCALES
    int i, j;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   IMPRIMIR MATRIZ\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Espacio [%d][%d] --> [%d]\n", i + 1, j + 1, matriz[i][j]); // Imprime los valores del arreglo bidimensional
        }
    }
    system("PAUSE");
}