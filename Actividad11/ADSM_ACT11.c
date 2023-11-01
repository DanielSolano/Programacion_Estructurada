// Solano Meza Angel Daniel Matr. 372453
// 01/11/2023
// Uso de registros para almacenar informacion de alumnos
// ADSM_ACT11_932

#include "miti_2.h"

int msges();
void menu();
int BusquedaTReg(TReg vector[], int n, int num);
int BusquedaOrdenadaTReg(TReg vector[], int n, int num);
int OrdenarTReg(TReg vector[], int n);
int BusquedaBinaria(TReg vect[], int izquierda, int derecha, int num);
TReg RegistroAuto();
TReg RegistroMan();
void ImprimirTReg(TReg vect[], int n);
void CrearTXT(char Nombre[], TReg Vect[], int n);
void Intercambio(TReg Nombres[], int i, int j);
int Particion(TReg Nombres[], int inferior, int superior);
void Quicksort(TReg Nombres[], int inferior, int superior);

int main()
{
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- REGISTROS AUTOMATICOS \n");
    printf("2.- REGISTROS MANUALES \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR MATRICULA  \n");
    printf("5.- ORDENAR REGISTROS  \n");
    printf("6.- IMPRIMIR REGISTROS \n");
    printf("7.- CREAR ARCHIVO DE TEXTO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    srand(time(NULL));
    TReg VectReg[2000], temp;
    int op, j, i, apagar, buscar, encontrado, ordenado, confirmar;
    char NombreArchivo[50];
    i = 0;
    ordenado = 0;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("CLS");
            for (j = 0; j < 100; j++)
            {
                temp = RegistroAuto();
                while (BusquedaTReg(VectReg, i, temp.Matricula) != -1)
                {
                    temp.Matricula = NumAleatorio(300000, 399999);
                }
                if (i < 2000)
                {
                    VectReg[i++] = temp;
                    ordenado = 0;
                }
            }
            if (i < 2000)
            {
                printf("REGISTROS LLENADOS AUTOMATICAMENTE\n");
            }
            else
            {
                printf("2000 REGISTROS OCUPADOS\n");
            }
            system("PAUSE");
            break;
        case 2: // REGISTROS MANUALES
            system("CLS");
            if (i <= 2000)
            {
                temp = RegistroMan();
                while (BusquedaTReg(VectReg, i, temp.Matricula) != -1)
                {
                    printf("MATRICULA DUPLICADA, INGRESE UNA NUEVA\n");
                    temp.Matricula = Validar(300000, 399999);
                }
                VectReg[i++] = temp;
                ordenado = 0;
            }
            else
            {
                printf("2000 REGISTROS OCUPADOS\n");
            }
            system("PAUSE");
            break;
        case 3: // ELIMINAR REGISTRO
            system("CLS");
            if (i == 0)
            {
                printf("INCAPAZ DE ELIMINAR REGISTROS VACIOS\n");
            }
            else
            {
                printf("MATRICULA DE REGISTRO A ELIMINAR\n");
                apagar = Validar(300000, 399999);
                if (ordenado == 0)
                {
                    encontrado = BusquedaTReg(VectReg, i, apagar);
                }
                else
                {
                    encontrado = BusquedaBinaria(VectReg, 0, i, apagar);
                }
                if (encontrado == -1)
                {
                    printf("MATRICULA NO EXISTENTE\n");
                }
                else // Encontrada
                {
                    if (VectReg[encontrado].Status == 0)
                    {
                        printf("REGISTRO YA ELIMINADO\n");
                    }
                    else
                    {
                        printf("DATOS DEL REGISTRO A ELIMINAR:\n\n");
                        printf("MATRICULA: %d\n", VectReg[encontrado].Matricula);
                        printf("NOMBRE 1: %s\n", VectReg[encontrado].Persona.Nombre1);
                        printf("NOMBRE 2: %s\n", VectReg[encontrado].Persona.Nombre2);
                        printf("NOMBRE 3: %s\n", VectReg[encontrado].Persona.Nombre3);
                        printf("APELLIDO PATERNO: %s\n", VectReg[encontrado].Persona.ApPat);
                        printf("APELLIDO MATERNO: %s\n", VectReg[encontrado].Persona.ApMat);
                        printf("FECHA DE NACIMIENTO:  %02d-%02d-%4d\n", VectReg[encontrado].Nacimiento.dia, VectReg[encontrado].Nacimiento.mes, VectReg[encontrado].Nacimiento.anio);
                        printf("EDAD: %d\n", VectReg[encontrado].Nacimiento.edad);
                        printf("SEXO: %s\n", VectReg[encontrado].Sexo);
                        printf("LUGAR DE NACIMIENTO: %s\n", VectReg[encontrado].Estado);
                        printf("CURP: %s\n", VectReg[encontrado].Curp);
                        printf("DESEA ELIMINAR EL REGISTRO: 1.SI 0.NO\n");
                        confirmar = Validar(0, 1);
                        if (confirmar == 1)
                        {
                            VectReg[encontrado].Status = 0;
                            system("CLS");
                            printf("REGISTRO ELIMINADO\n");
                            system("PAUSE");
                        }
                        else
                        {
                            system("CLS");
                            printf("REGISTRO NO ELIMINADO\n");
                            system("PAUSE");
                        }
                    }
                }
            }
            system("PAUSE");
            break;
        case 4: // Buscar
            system("CLS");
            if (i == 0)
            {
                printf("INCAPAZ DE BUSCAR EN REGISTROS VACIOS\n");
            }
            else
            {
                printf("MATRICULA A BUSCAR\n");
                buscar = Validar(300000, 399999);
                if (ordenado == 0)
                {
                    encontrado = BusquedaTReg(VectReg, i, buscar);
                }
                else
                {
                    encontrado = BusquedaBinaria(VectReg, 0, i, buscar);
                }

                if (encontrado == -1)
                {
                    printf("MATRICULA NO ENCONTRADA\n");
                }
                else
                {
                    if (VectReg[encontrado].Status == 0)
                    {
                        printf("MATRICULA DE ALUMNO DESACTIVADO\n");
                    }
                    else
                    {
                        printf("DATOS DEL REGISTRO ENCONTRADO:\n\n");
                        printf("MATRICULA EN REGISTRO: %d\n", encontrado);
                        printf("MATRICULA: %d\n", VectReg[encontrado].Matricula);
                        printf("NOMBRE 1: %s\n", VectReg[encontrado].Persona.Nombre1);
                        printf("NOMBRE 2: %s\n", VectReg[encontrado].Persona.Nombre2);
                        printf("NOMBRE 3: %s\n", VectReg[encontrado].Persona.Nombre3);
                        printf("APELLIDO PATERNO: %s\n", VectReg[encontrado].Persona.ApPat);
                        printf("APELLIDO MATERNO: %s\n", VectReg[encontrado].Persona.ApMat);
                        printf("FECHA DE NACIMIENTO:  %02d-%02d-%4d\n", VectReg[encontrado].Nacimiento.dia, VectReg[encontrado].Nacimiento.mes, VectReg[encontrado].Nacimiento.anio);
                        printf("EDAD: %d\n", VectReg[encontrado].Nacimiento.edad);
                        printf("SEXO: %s\n", VectReg[encontrado].Sexo);
                        printf("LUGAR DE NACIMIENTO: %s\n", VectReg[encontrado].Estado);
                        printf("CURP: %s\n", VectReg[encontrado].Curp);
                    }
                }
            }
            system("PAUSE");
            break;
        case 5: // ORDENAR REGISTROS
            system("CLS");
            if (i <= 1)
            {
                if (i == 0)
                {
                    printf("INCAPAZ DE ORDENAR UN REGISTRO VACIO\n");
                }
                else
                {
                    printf("UN SOLO REGISTRO ORDENADO\n");
                }
            }
            else
            {
                if (ordenado == 0)
                {
                    if (i < 500)
                    {
                        ordenado = OrdenarTReg(VectReg, i);
                        printf("REGISTROS ORDENADOS\n");
                    }
                    else
                    {
                        Quicksort(VectReg, 0, i - 1);
                        ordenado = 1;
                        printf("REGISTROS ORDENADOS POR QUICKSORT\n");
                    }
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
                ImprimirTReg(VectReg, i);
            }
            system("PAUSE");
            break;
        case 7: // Archivo de texto
            ValiCadena(NombreArchivo, "NOMBRE DEL ARCHIVO TXT");
            CrearTXT(NombreArchivo, VectReg, i);
            printf("\n");
            system("PAUSE");
            break;
        }

    } while (op != 0);
}

TReg RegistroAuto()
{
    TReg alum;
    int i, sexo, estado;
    char nombres_estados[33][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CIUDAD DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "EXTRANJERO"};
    char estados[33][3] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};
    i = NumAleatorio(0, 13);
    sexo = NumAleatorio(1, 2);
    if (sexo == 1)
    {

        strcpy(alum.Persona.Nombre1, NombresHombre[i]);
        strcpy(alum.Persona.Nombre2, SegundoHombre[i]);
        alum.Sexo[0] = 'H';
    }
    else
    {

        strcpy(alum.Persona.Nombre1, NombresMujer[i]);
        strcpy(alum.Persona.Nombre2, SegundoMujer[i]);
        alum.Sexo[0] = 'M';
    }
    alum.Status = 1;
    alum.Matricula = NumAleatorio(300000, 399999);
    strcpy(alum.Persona.ApPat, Apellidos[NumAleatorio(0, 88)]);
    strcpy(alum.Persona.ApMat, Apellidos[NumAleatorio(0, 88)]);
    alum.Nacimiento.anio = NumAleatorio(1950, 2023);
    alum.Nacimiento.mes = NumAleatorio(1, 12);
    if (alum.Nacimiento.mes == 2)
    {
        alum.Nacimiento.dia = NumAleatorio(1, 28);
    }
    else
    {
        alum.Nacimiento.dia = NumAleatorio(1, 31);
    }
    estado = NumAleatorio(0, 32);
    strcpy(alum.Estado, estados[estado]);
    strcpy(alum.Estado, nombres_estados[estado]);
    alum = AutoCurp(alum);
    if (alum.Nacimiento.anio == 2023)
    {
        if (alum.Nacimiento.mes > 10)
        {
            alum.Nacimiento.edad = 2022 - alum.Nacimiento.anio;
        }
    }
    else
    {
        alum.Nacimiento.edad = 2023 - alum.Nacimiento.anio;
    }
    return alum;
}

TReg RegistroMan()
{
    TReg alum;
    char cultimo[2];
    int ultimo;
    char caracter;
    printf("MATRICULA: ");
    alum.Matricula = Validar(300000, 399999);
    alum = Nombres(alum);
    alum = FechaNac(alum);
    alum = Sexo(alum);
    alum = Estados(alum);
    alum = Inconvenientes(alum);
    ultimo = NumAleatorio(1, 5);
    sprintf(cultimo, "%d", ultimo);
    caracter = cultimo[0];
    alum.Curp[17] = caracter;
    alum.Curp[18] = '\0';
    if (alum.Nacimiento.anio == 2023)
    {
        if (alum.Nacimiento.mes > 10)
        {
            alum.Nacimiento.edad = 2022 - alum.Nacimiento.anio;
        }
    }
    else
    {
        alum.Nacimiento.edad = 2023 - alum.Nacimiento.anio;
    }

    alum.Status = 1;

    return alum;
}

int BusquedaTReg(TReg vector[], int n, int num)
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

void ImprimirTReg(TReg vect[], int n)
{
    int i, j;

    printf("MATRICULA                     NOMBRES                  APPAT           APMAT         FECHA NAC     EDAD      SEXO           ORIGEN                    CURP\n");
    printf("______________________________________________________________________________________________________________________________________________________________________\n");
    for (i = 0, i < n; i < n; i++, j++)
    {
        if (vect[i].Status != 0)
        {
            printf("%-9d |  %-10s |  %-10s |  %-10s | %-10s  |  %-10s  |  %02d-%02d-%4d  |  %-4d  |  %-5s  |  %-20s  |  %-18s  |\n", vect[i].Matricula, vect[i].Persona.Nombre1, vect[i].Persona.Nombre2, vect[i].Persona.Nombre3, vect[i].Persona.ApPat, vect[i].Persona.ApMat, vect[i].Nacimiento.dia, vect[i].Nacimiento.mes, vect[i].Nacimiento.anio, vect[i].Nacimiento.edad, vect[i].Sexo, vect[i].Estado, vect[i].Curp);
        }
        if (j == 39)
        {
            system("pause");
            system("cls");
            printf("MATRICULA                     NOMBRES                  APPAT           APMAT         FECHA NAC     EDAD      SEXO           ORIGEN                    CURP\n");
            printf("______________________________________________________________________________________________________________________________________________________________________\n");
            j = 0;
        }
    }
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

void CrearTXT(char Nombre[], TReg vect[], int n)
{
    int i;
    FILE *archivo;

    strcat(Nombre, ".txt");
    archivo = fopen(Nombre, "w");
    fprintf(archivo, "MATRICULA                     NOMBRES                  APPAT           APMAT         FECHA NAC     EDAD      SEXO           ORIGEN                    CURP\n\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].Status != 0)
        {
            fprintf(archivo, "%-9d |  %-10s |  %-10s |  %-10s | %-10s  |  %-10s  |  %02d-%02d-%4d  |  %-4d  |  %-5s  |  %-20s  |  %-18s  |\n", vect[i].Matricula, vect[i].Persona.Nombre1, vect[i].Persona.Nombre2, vect[i].Persona.Nombre3, vect[i].Persona.ApPat, vect[i].Persona.ApMat, vect[i].Nacimiento.dia, vect[i].Nacimiento.mes, vect[i].Nacimiento.anio, vect[i].Nacimiento.edad, vect[i].Sexo, vect[i].Estado, vect[i].Curp);
        }
    }

    printf("ARCHIVO CREADO EXITOSAMENTE");
    fclose(archivo);
}

void Intercambio(TReg Nombres[], int i, int j)
{
    TReg temp;

    temp = Nombres[i];
    Nombres[i] = Nombres[j];
    Nombres[j] = temp;
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

void Quicksort(TReg Nombres[], int inferior, int superior)
{
    if (inferior < superior)
    {
        int pi = Particion(Nombres, inferior, superior);

        Quicksort(Nombres, inferior, pi - 1);
        Quicksort(Nombres, pi + 1, superior);
    }
}