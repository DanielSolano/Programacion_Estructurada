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
void ImprimirTalum(Talum vect[], int n);
int BusquedaBinaria(Talum vect[], int izquierda, int derecha, int num);
Talum RegistroAuto();
Talum RegistroMan();
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
            system("CLS");
            for (j = 0; j < 10; j++) // Cada iteracion llena un indice de los registros
            {
                temp = RegistroAuto();                                  // Da los datos a un alumno temporal
                while (BusquedaTalum(VectReg, i, temp.Matricula) != -1) // Comprueba que la matricula no este repetida
                {
                    temp.Matricula = NumAleatorio(300000, 399999); // Si la matricula original se encontro en el registro, genera otra hasta que no se encuentre
                }
                if (i <= 500) // Si los registros se llenaron con 500 datos ya no se le asignan mas valores
                {
                    VectReg[i++] = temp; // El alumno temporal ya validado se le asigna a los registros
                    ordenado = 0;        // Bandera que indica el vector esta desordenado
                }
            }
            if (i <= 500) // No esta lleno el registro, asignados correctamente
            {
                printf("REGISTROS LLENADOS AUTOMATICAMENTE\n");
            }
            else // Registro lleno
            {
                printf("500 REGISTROS OCUPADOS\n");
            }
            system("PAUSE");
            break;
        case 2: // REGISTROS MANUALES
            system("CLS");
            if (i <= 500)
            {
                temp = RegistroMan();                                   // Da los datos a un alumno temporal
                while (BusquedaTalum(VectReg, i, temp.Matricula) != -1) // Comprueba que la matricula no este repetida
                {
                    printf("MATRICULA DUPLICADA, INGRESE UNA NUEVA\n");
                    temp.Matricula = Validar(300000, 399999); // Si la matricula original se encontro en el registro, genera otra hasta que no se encuentre
                }
                VectReg[i++] = temp; // El alumno temporal ya validado se le asigna a los registros
                ordenado = 0;
            }
            else
            {
                printf("500 REGISTROS OCUPADOS\n");
            }
            system("PAUSE");
            break;
        case 3: // ELIMINAR REGISTRO
            system("CLS");
            if (i == 0) // No hay registros llenos para eliminar
            {
                printf("INCAPAZ DE ELIMINAR REGISTROS VACIOS\n");
            }
            else
            {
                printf("MATRICULA DE REGISTRO A ELIMINAR\n");
                apagar = Validar(300000, 399999);
                if (ordenado == 0) // Si no esta ordenado usa busqueda normal
                {
                    encontrado = BusquedaTalum(VectReg, i, apagar);
                }
                else // Si esta ordenado binaria
                {
                    encontrado = BusquedaBinaria(VectReg, 0, i, apagar);
                }

                if (encontrado == -1) // Si no existe no se puede eliminar
                {
                    printf("MATRICULA NO EXISTENTE\n");
                }
                else // Encontrada
                {
                    if (VectReg[encontrado].Status == 0) // Si ya esta eliminado no se vuelve a borrar
                    {
                        printf("REGISTRO YA ELIMINADO\n");
                    }
                    else // Se encontro y no se ha borrado, se elimina
                    {
                        VectReg[encontrado].Status = 0;
                        printf("REGISTRO CON MATRICULA %d APAGADO\n", apagar);
                    }
                }
            }
            system("PAUSE");
            break;
        case 4: // BUSCAR MATRICULA
            system("CLS");
            if (i == 0) // No hay registros llenos
            {
                printf("INCAPAZ DE BUSCAR EN REGISTROS VACIOS\n");
            }
            else
            {
                printf("MATRICULA A BUSCAR\n");
                buscar = Validar(300000, 399999);
                if (ordenado == 0) // Si no esta ordenado busqueda secuencial normal
                {
                    encontrado = BusquedaTalum(VectReg, i, buscar);
                }
                else // Si esta ordenado usa busqueda binaria
                {
                    encontrado = BusquedaBinaria(VectReg, 0, i, buscar);
                }

                if (encontrado == -1) // No se encontro la matricula
                {
                    printf("MATRICULA NO ENCONTRADA\n");
                }
                else // Se encontro
                {
                    if (VectReg[encontrado].Status == 0) // Se encontro pero tiene estatus 0
                    {
                        printf("MATRICULA DE ALUMNO DESACTIVADO EN: %d\n", encontrado);
                    }
                    else
                    {
                        printf("MATRICULA EN REGISTRO: %d\n", encontrado);
                    }
                }
            }
            system("PAUSE");
            break;
        case 5: // ORDENAR REGISTROS
            system("CLS");
            if (i <= 1)
            {
                if (i == 0) // No hay registros llenos
                {
                    printf("INCAPAZ DE ORDENAR UN REGISTRO VACIO\n");
                }
                else // Solo hay un registro, no se ordena
                {
                    printf("UN SOLO REGISTRO ORDENADO\n");
                }
            }
            else
            {
                if (ordenado == 0)
                {
                    ordenado = OrdenarTalum(VectReg, i);
                    printf("REGISTROS ORDENADOS\n");
                }
                else
                {
                    printf("REGISTROS YA ORDENADOS\n");
                }
            }
            system("PAUSE");
            break;
        case 6: // IMPRIMIR REGISTROS
            system("CLS");
            if (i == 0)
            {
                printf("REGISTROS VACIOS\n");
            }
            else
            {
                ImprimirTalum(VectReg, i);
            }
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
    sexo = NumAleatorio(1, 2);    // Genera sexo
    if (sexo == 1)                // Es hombre
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
Talum RegistroMan()
{
    Talum alum;
    char nombre[30], ap1[30], ap2[30];

    system("CLS");
    printf("ESTATUS\n");
    alum.Status = Validar(0, 1);

    system("CLS");
    printf("MATRICULA\n");
    alum.Matricula = Validar(300000, 399999);

    system("CLS");
    printf("NOMBRE\n");
    fflush(stdin);
    gets(nombre);
    ValiCadena(nombre, "NOMBRE");
    strcpy(alum.Nombre, nombre);

    system("CLS");
    printf("APELLIDO PATERNO\n");
    fflush(stdin);
    gets(ap1);
    ValiCadena(ap1, "APELLIDO PATERNO");
    strcpy(alum.ApPat, ap1);

    system("CLS");
    printf("APELLIDO MATERNO\n");
    fflush(stdin);
    gets(ap2);
    ValiCadena(ap2, "APELLIDO MATERNO");
    strcpy(alum.ApMat, ap2);

    system("CLS");
    printf("EDAD\n");
    alum.Edad = Validar(18, 50);

    system("CLS");
    printf("SEXO\n");
    alum.Sexo = Validar(1, 2);

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
    printf("ESTATUS  MATRICULA     NOMBRES                     APELLIDO PATERNO                APELLIDO MATERNO                    EDAD       SEXO\n");
    for (i = 0; i < n; i++)
    {
        printf("  %-2d      %-9d   %-30s   %-30s   %-30s   %-4d      %-6s \n", vect[i].Status, vect[i].Matricula, vect[i].Nombre, vect[i].ApPat, vect[i].ApMat, vect[i].Edad, (vect[i].Sexo == 1) ? "HOMBRE" : "MUJER");
    }
}
//*********************
int BusquedaBinaria(Talum vect[], int izquierda, int derecha, int num)
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