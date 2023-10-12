#include "miti_2.h"

typedef struct _alumnos
{
    int Status;
    int Matricula;
    char ApPat[30];
    char ApMat[30];
    char Nombre[30];
    int Edad;
    int Sexo;
} Talum;

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
int BusquedaTalum(Talum vector[], int n, int num);
int OrdenarTalum(Talum vector[], int n);
Talum RegistroAuto();
Talum RegistroMan();
void ImprimirTalum(Talum vect[], int n);
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
    printf("1.- REGISTROS AUTOMATICOS \n");
    printf("2.- REGISTROS MANUALES \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR MATRICULA  \n");
    printf("5.- ORDENAR MATRICULA  \n");
    printf("6.- IMPRIMIR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    srand(time(NULL));
    Talum VectReg[500], temp;
    int op, j, i, apagar, buscar, encontrado, ordenado;
    i = 0;
    ordenado = 0;
    do
    {
        op = msges();
        switch (op)
        {
        case 1: // REGISTROS AUTOMATICOS
            ordenado = 0;
            system("CLS");
            for (j = 0; j < 10; j++)
            {
                temp = RegistroAuto();
                while (BusquedaTalum(VectReg, i, temp.Matricula) != -1)
                {
                    temp.Matricula = NumAleatorio(300000, 399999);
                }
                VectReg[i++] = temp;
            }
            printf("REGISTROS LLENADOS AUTOMATICAMENTE\n");
            system("PAUSE");
            break;
        case 2: // REGISTROS MANUALES
            ordenado = 0;
            temp = RegistroMan();
            while (BusquedaTalum(VectReg, i, temp.Matricula) != -1)
            {
                system("CLS");
                printf("MATRIZ DUPLICADA, INGRESE UNA NUEVA\n");
                temp.Matricula = Validar(300000, 399999);
                system("PAUSE");
            }
            VectReg[i++] = temp;
            break;
        case 3: // ELIMINAR REGISTRO
            system("CLS");
            printf("NUMERO DE REGISTRO A ELIMINAR\n");
            apagar = Validar(0, i-1);
            if (VectReg[apagar].Status == 0)
            {
                printf("REGISTRO YA APAGADO\n");
            }
            else
            {
                VectReg[apagar].Status = 0; // Cambia estatus a 0
                printf("REGISTRO %d APAGADO\n", apagar);
            }
            system("PAUSE");
            break;
        case 4: // BUSCAR MATRICULA
            system("CLS");
            printf("MATRICULA A BUSCAR\n");
            buscar = Validar(300000, 399999);

            if (ordenado == 0) // Si no esta ordenado busqueda secuencial normal
            {
                encontrado = BusquedaTalum(VectReg, i, buscar);
            }
            else // Si esta ordenado usa busqueda mejorada
            {
                encontrado = BusquedaOrdenadaTalum(VectReg, i, buscar);
            }

            if (encontrado == -1)
            {
                printf("MATRICULA NO ENCONTRADA\n");
            }
            else
            {
                printf("MATRICULA EN REGISTRO: %d\n", encontrado);
            }

            system("PAUSE");
            break;
        case 5: // ORDENAR REGISTROS
            system("CLS");
            if (ordenado == 0)
            {
                ordenado = OrdenarTalum(VectReg, i);
                printf("REGISTRO ORDENADO\n");
            }
            else
            {
                printf("REGISTRO YA ORDENADO\n");
            }
            system("PAUSE");
            break;
        case 6: // IMPRIMIR REGISTROS
            system("CLS");
            ImprimirTalum(VectReg, i);
            system("PAUSE");
            break;
        }

    } while (op != 0);
}

//*********************
Talum RegistroAuto()
{
    Talum alum;
    int i, apellido, sexo, nombres;

    i = NumAleatorio(0, 14);
    nombres = NumAleatorio(1, 2); // Numero de nombres
    sexo = NumAleatorio(1, 2);  // Genera sexo
    if (sexo == 1)   // Es hombre
    {
        if (nombres == 1)
        {
            strcpy(alum.Nombre, NombresHombre[i]); // Primer nombre
        }
        else
        {
            strcpy(alum.Nombre, NombresHombre[i]); // Primer nombre
            strcat(alum.Nombre, SegundoHombre[i]); // Anade segundo nombre
        }
    }
    else // Es mujer
    {
        if (nombres == 1)
        {
            strcpy(alum.Nombre, NombresMujer[i]); // Primer nombre
        }
        else
        {
            strcpy(alum.Nombre, NombresMujer[i]); // Primer nombre
            strcat(alum.Nombre, SegundoMujer[i]); // Anade segundo nombre
        }
    }

    alum.Status = 1;
    alum.Matricula = NumAleatorio(300000, 399999);

    apellido = NumAleatorio(0, 88);
    strcpy(alum.ApPat, Apellidos[apellido]);
    apellido = NumAleatorio(0, 88); // Genera otro numero aleatorio para el segundo apellido
    strcpy(alum.ApMat, Apellidos[apellido]);

    alum.Edad = NumAleatorio(18, 28);
    alum.Sexo = sexo;
    return alum;
}

//*********************
int BusquedaTalum(Talum vector[], int n, int num)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (vector[i].Matricula == num)
        {
            return i;
        }
    }
    return -1;
}

//*********************
Talum RegistroMan()
{
    Talum alum;
    char nombre[30], ap1[30], ap2[30];

    alum.Status = 1;

    system("CLS");
    printf("MATRICULA\n");
    alum.Matricula = Validar(300000, 399999);
    system("PAUSE");

    system("CLS");
    printf("NOMBRE\n");
    fflush(stdin);
    gets(nombre);
    ValiCadena(nombre, "NOMBRE");
    strcpy(alum.Nombre, nombre);
    system("PAUSE");

    system("CLS");
    printf("APELLIDO PATERNO\n");
    fflush(stdin);
    gets(ap1);
    ValiCadena(ap1, "APELLIDO PATERNO");
    strcpy(alum.ApPat, ap1);
    system("PAUSE");

    system("CLS");
    printf("APELLIDO MATERNO\n");
    fflush(stdin);
    gets(ap2);
    ValiCadena(ap2, "APELLIDO MATERNO");
    strcpy(alum.ApMat, ap2);
    system("PAUSE");

    system("CLS");
    printf("EDAD\n");
    alum.Edad = Validar(18, 50);
    system("PAUSE");

    system("CLS");
    printf("SEXO\n");
    alum.Sexo = Validar(1, 2);
    system("PAUSE");

    return alum;
}
//*********************
int OrdenarTalum(Talum vector[], int n)
{
    Talum temp;
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
//*********************
int BusquedaOrdenadaTalum(Talum vect[], int n, int num)
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
//*********************
void ImprimirTalum(Talum vect[], int n)
{
    int i;
    printf("MATRICULA     NOMBRES                     APELLIDO PATERNO                APELLIDO MATERNO                    EDAD       SEXO\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].Status == 1) // IMPRIME LOS REGISTROS ACTIVOS
        {
            printf("%-9d   %-30s   %-30s   %-30s   %-4d      %-6s \n", vect[i].Matricula, vect[i].Nombre, vect[i].ApPat, vect[i].ApMat, vect[i].Edad, (vect[i].Sexo == 1) ? "HOMBRE" : "MUJER");
        }
    }
}