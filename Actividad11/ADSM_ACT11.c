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
    printf("5.- ORDENAR MATRICULA  \n");
    printf("6.- IMPRIMIR \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    srand(time(NULL));
    TReg VectReg[2000], temp;
    int op, j, i, apagar, buscar, encontrado, ordenado;
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
                        VectReg[encontrado].Status = 0;
                        printf("REGISTRO CON MATRICULA %d APAGADO\n", apagar);
                    }
                }
            }
            system("PAUSE");
            break;
        case 4:
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
                    ordenado = OrdenarTReg(VectReg, i);
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
                ImprimirTReg(VectReg, i);
            }
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
    int i, activos;

    printf("MATRICULA                     NOMBRES               APPAT      APMAT         FECHA NAC   EDAD   SEXO         ORIGEN                 CURP\n\n");
    for (i = 0, i < n; i < n; i++)
    {
        if (vect[i].Status != 0)
        {
            printf("%-9d   %-10s   %-10s   %-10s  %-10s   %-10s    %02d-%02d-%4d   %-4d   %-7s   %-20s   %-18s\n", vect[i].Matricula, vect[i].Persona.Nombre1, vect[i].Persona.Nombre2, vect[i].Persona.Nombre3, vect[i].Persona.ApPat, vect[i].Persona.ApMat, vect[i].Nacimiento.dia, vect[i].Nacimiento.mes, vect[i].Nacimiento.anio, vect[i].Nacimiento.edad, vect[i].Sexo, vect[i].Estado, vect[i].Curp);
            activos++;
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