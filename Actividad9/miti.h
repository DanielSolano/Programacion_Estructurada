#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Validar(int inferior, int superior);
void LlenarVector(int vect[], int m, int ri, int rf, int op);
void LlenarMatrizM(int matriz[][4], int m, int n, int ri, int rf);
void LlenarMatrizR(int matriz[][4], int vector[], int m, int n);
int BusquedaSec(int vector[], int n, int num);
void ImprimirVector(int vector[], int m);

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
void LlenarVector(int vect[], int m, int ri, int rf, int op)
{
    //  VARIABLES LOCALES
    int i, num, rango;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    rango = rf - ri + 1;
    if (op == 1) // Opcion rellenado automatico
    {
        for (i = 0; i < m; i++) // Le asgina un valor a cada indice del vector
        {

            do
            {
                num = rand() % rango + ri;
            } while (BusquedaSec(vect, i, num) != -1);
            vect[i] = num;
        }
    }
    else // Opcion rellenado manual
    {
        for (i = 0; i < m; i++)
        {
            printf("    Espacio [%d]\n", i + 1);
            vect[i] = Validar(30, 70); // Valida la entrada manual
        }
    }
}
//****************************
void LlenarMatrizR(int matriz[][4], int vector[], int m, int n)
{
    //  VARIALES LOCALES
    int i, j, k, 
    //  AQUI DESARROLLO PROGRAMA
    
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
    //  VARIALES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA

    for (i = 0; i < n; i++)
    {
        if (vector[i] == num)
        {
            return i;
        }
    }
    return -1;
}