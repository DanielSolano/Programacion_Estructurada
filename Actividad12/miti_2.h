#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _alumnos
{
    int Status;
    int Matricula;
    int key;
    char ApPat[30];
    char ApMat[30];
    char Nombre[30];
    int Edad;
    char Sexo[9];
} TReg;

// ******************* ETIQUETAS *****************************
int Validar(int inferior, int superior);
void LlenarVector(int vector[], int m, int ri, int rf, int op);
int BusquedaSec(int vector[], int n, int num);
void ImprimirVector(int vector[], int m, char msg[]);
void Ordenar(int vector[], int n);
int NumAleatorio(int ri, int rf);
void ValiCadena(char cadena[], char msg[]);
void Mayusculas(char cadena[]);
int BusquedaOrdenada(int vect[], int n, int num);
int BusquedaTReg(TReg vector[], int n, int num);
int OrdenarTReg(TReg vector[], int n);
int BusquedaOrdenadaTReg(TReg vect[], int n, int num);
int BusquedaBinaria(TReg vect[], int izquierda, int derecha, int num);
void CrearTXT(char Nombre[], TReg vect[], int n);
void Intercambio(TReg Nombres[], int i, int j);
int Particion(TReg Nombres[], int inferior, int superior);
void Quicksort(TReg Nombres[], int inferior, int superior);
int LeerTXT(TReg vect[], int *i, char nom[]);

// ******************* FUNCIONES *****************************
int LeerTXT(TReg vect[], int *i, char nom[])
{
    strcat(nom, ".txt");
    TReg reg;
    char x[10];
    FILE *fa;
    fa = fopen(nom, "r");
    if (fa)
    {
        do
        {
            fscanf(fa, "%s %d %s %s %s %d %s", &x, &reg.Matricula, &reg.Nombre, &reg.ApPat, &reg.ApMat, &reg.Edad, &reg.Sexo);
            reg.Status = 1;
            reg.key = reg.Matricula;
            if ((*i) <= 1500)
            {
                vect[(*i)++] = reg;
            }

        } while (!feof(fa));
        fclose(fa);
        printf("ARCHIVO CARGADO CORRECTAMENTE\n");
        return 1;
    }
    else
    {
        printf("ARCHIVO NO EXISTENTE\n");
        return 0;
    }
}
void Quicksort(TReg Nombres[], int inferior, int superior)
{
    if (inferior < superior)
    {
        int pi = Particion(Nombres, inferior, superior);

        Quicksort(Nombres, inferior, pi - 1);
        Quicksort(Nombres, pi + 1, superior);
    }
}
int Particion(TReg Nombres[], int inferior, int superior)
{
    TReg Alumno;
    Alumno.Matricula = Nombres[superior].Matricula;
    int i = inferior - 1;

    for (int j = inferior; j <= superior - 1; j++)
    {
        if (Nombres[j].Matricula <= Alumno.Matricula)
        {
            i++;
            Intercambio(Nombres, i, j);
        }
    }
    Intercambio(Nombres, i + 1, superior);
    return i + 1;
}
void Intercambio(TReg Nombres[], int i, int j)
{
    TReg temp;

    temp = Nombres[i];
    Nombres[i] = Nombres[j];
    Nombres[j] = temp;
}
void CrearTXT(char Nombre[], TReg vect[], int n)
{
    int i;
    FILE *archivo;

    strcat(Nombre, ".txt");
    archivo = fopen(Nombre, "w");
    fprintf(archivo, "------------------------------------------------------------------------------------------\n");
    fprintf(archivo, "  No  | MATRICULA | NOMBRE        | APELLIDO P.  |  APELLIDO MAT.     | EDAD  | SEXO \n");
    fprintf(archivo, "------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].Status != 0)
        {
            fprintf(archivo, "%4d.-  %6d      %-10s      %-10s      %-10s          %2d      %-7s\n", i, vect[i].Matricula, vect[i].Nombre, vect[i].ApPat, vect[i].ApMat, vect[i].Edad, vect[i].Sexo);
        }
    }
    fclose(archivo);
}
int BusquedaBinaria(TReg vect[], int izquierda, int derecha, int num)
{
    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (vect[medio].Matricula == num)
        {
            return medio;
        }
        if (vect[medio].Matricula < num)
        {
            izquierda = medio + 1;
        }
        else
        {
            derecha = medio - 1;
        }
    }
    return -1;
}
int BusquedaOrdenadaTReg(TReg vect[], int n, int num)
{
    int i;
    i = 0;
    while (i < n)
    {

        if (num >= vect[i].Matricula)
        {
            if (num == vect[i].Matricula)
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
int OrdenarTReg(TReg vector[], int n)
{
    TReg temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vector[j].Matricula < vector[i].Matricula)
            {
                temp = vector[i];
                vector[i] = vector[j];
                vector[j] = temp;
            }
        }
    }
    return 1;
}
int BusquedaTReg(TReg vector[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i].key == num)
        {
            return i;
        }
    }
    return -1;
}
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
int NumAleatorio(int ri, int rf)
{
    int rango = (rf - ri + 1);

    return rand() % rango + ri;
}
void ValiCadena(char cadena[], char msg[])
{
    int i;
    int error;
    error = 0;
    printf("%s\n", msg);
    fflush(stdin);
    gets(cadena);
    Mayusculas(cadena);
    Mayusculas(cadena);
    do
    {
        if (error == 1)
        {
            printf("%s\n", msg);
            fflush(stdin);
            gets(cadena);
            Mayusculas(cadena);
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
            if (cadena[0] == ' ') // Empieza en espacio
            {
                error = 1;
            }
            if (cadena[i] != ' ') // Si no es un espacio y no contiene letras es caracter especial
            {
                if (cadena[i] < 'A' || cadena[i] > 'Z')
                {
                    error = 1;
                }
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
}
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