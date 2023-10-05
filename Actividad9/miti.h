#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Validar(int inferior, int superior);
void LlenarVector(int vector[], int m, int ri, int rf, int op);
void LlenarMatrizM(int matriz[][4], int m, int n, int ri, int rf);
void LlenarMatrizR(int matriz[][4], int m, int n, int ri, int rf);
int BusquedaSec(int vector[], int n, int num);
void ImprimirVector(int vector[], int m, char msg[]);
void ImprimirMatriz(int matriz[][4], int m, int n, char msg[]);
void Ordenar(int vector[], int n);
//*********************
int Validar(int inferior, int superior) // Parametros para funcionar
{
    int num;
    char cadena[100];
    do
    {
        fflush(stdin);
        gets(cadena);       // Tomas los datos como cadena
        num = atoi(cadena); // Transforma la entrada a entero
    } while ((num < inferior) || (num > superior));
    return num;
}
//*********************
void LlenarVector(int vector[], int m, int ri, int rf, int op)
{
    int i, num, rango;
    system("CLS");
    rango = rf - ri + 1;
    if (op == 1) // Opcion rellenado automatico
    {
        for (i = 0; i < m; i++) // Le asgina un valor a cada indice del vector
        {

            do
            {
                num = rand() % rango + ri;
            } while (BusquedaSec(vector, i, num) != -1);
            vector[i] = num;
        }
    }
    else // Opcion rellenado manual
    {
        for (i = 0; i < m; i++)
        {
            printf("    Espacio [%d]\n", i + 1);
            vector[i] = Validar(30, 70); // Valida la entrada manual
        }
    }
}
//****************************
void LlenarMatrizR(int matriz[][4], int m, int n, int ri, int rf)
{
    //  VARIALES LOCALES
    int i, j, k, vect[m * n];
    LlenarVector(vect, m, n, ri, rf);
    for (i = 0, k = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matriz[i][j] = vect[k++];
        }
    }
    printf("Matriz rellenada\n");
    system("PAUSE");
}
//****************************
void LlenarMatrizM(int matriz[][4], int m, int n, int ri, int rf)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            matriz[i][j] = Validar(ri, rf);
        }
    }
    printf("Matriz rellenada\n");
    system("PAUSE");
}
//****************************
int BusquedaSec(int vector[], int n, int num)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (vector[i] == num)
        {
            return i;
        }
    }
    return -1;
}
//****************************
void ImprimirVector(int vector[], int m, char msg[])
{
    int i;
    printf("%s\n", msg);
    for (i = 0; i < m; i++)
    {
        printf("[%d] --> %d\n", i + 1, vector[i]);
    }
}
//****************************
void Ordenar(int vector[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[i])
            {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
}
//****************************
void ImprimirMatriz(int matriz[][4], int m, int n, char msg[])
{
    int i, j;
    printf("%s\n", msg);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("[%d][%d] --> %d\n", i + 1, j + 1, matriz[i][j]);
        }
    }
}
