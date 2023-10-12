// Solano Meza Angel Daniel Matr. 372453
// 05/10/2023
// Creacion de nuestra libreria
// ADSM_ACT9_LIB_932
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "nombres.h"

int Validar(int inferior, int superior);
void LlenarVector(int vector[], int m, int ri, int rf, int op);
int BusquedaSec(int vector[], int n, int num);
void ImprimirVector(int vector[], int m, char msg[]);
void Ordenar(int vector[], int n);
int NumAleatorio(int ri, int rf);
void ValiCadena(char cadena[], char msg[]);
void Mayusculas(char cadena[]);
void DobleEspacio(char cadena[]);
int BusquedaOrdenada(int vect[], int n, int num);

//*********************
int Validar(int inferior, int superior) // Parametros para funcionar
{
    int num;
    char cadena[10];
    do
    {
        fflush(stdin);
        gets(cadena);       // Tomas los datos como cadena
        num = atoi(cadena); // Transforma la entrada a entero
    } while ((num < inferior) || (num > superior));
    return num;
}
//*********************
void VectorMatriz(int vector[], int m, int ri, int rf)
{
    int i, num, rango;
    rango = rf - ri + 1;
    for (i = 0; i < m; i++) // Le asgina un valor a cada indice del vector
    {

        do
        {
            num = rand() % rango + ri;
        } while (BusquedaSec(vector, i, num) != -1);
        vector[i] = num;
    }
}
//*********************
void LlenarVector(int vector[], int m, int ri, int rf, int op)
{
    int i, num, rango;
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
int BusquedaSec(int vector[], int n, int num)
{
    int i;
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
    system("CLS");
    int i;
    printf("    %s\n", msg);
    for (i = 0; i < m; i++)
    {
        printf("[%d] --> %d\n", i + 1, vector[i]);
    }
    system("PAUSE");
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
int NumAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}
//****************************
void ValiCadena(char cadena[], char msg[])
{
    int i;
    int error;
    error = 0;
    do
    {
        if (error == 1)
        {
            printf("%s\n", msg);
            fflush(stdin);
            gets(cadena);
            error = 0;
        }
        for (i = 0; cadena[i] != '\0'; i++)
        {
            if (cadena[i] >= '0' && cadena[i] <= '9') // Son numeros
            {
                error = 1;
            }
            if ((cadena[i] == ' ') && (cadena[i + 1] == ' ')) // Doble espacio vacio
            {
                error = 1;
            }
            if(cadena[0] == ' ')
            {
                error = 1;
            }
        }
        if (cadena[i - 1] == ' ')
        {
            error = 1;
        }
        if (error == 1)
        {
            printf("NO NUMEROS, DOBLES ESPACIOS, INICIO Y FINAL DEBEN SER CARACTERES\n");
            system("PAUSE");
            system("CLS");
        }

    } while (error == 1);
    Mayusculas(cadena);
}
//****************************
void Mayusculas(char cadena[])
{
    int i;
    for (i = 0; cadena[i] != '\0'; i++) // Convierte a mayusculas
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
}
//****************************
int BusquedaOrdenada(int vect[], int n, int num)
{
    int i;
    i = 0;
    while (i < n)
    {

        if (num >= vect[i])
        {
            if (num == vect[i])
            {
                return i;
            }
        }
        else
        {
            return -1;
        }
        i++;
    }
    return -1;
}