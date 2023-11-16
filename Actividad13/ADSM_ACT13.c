// Solano Meza Angel Daniel Matr. 372453
// 13/11/2023
// Uso de archivos binarios
// ADSM_ACT13_932

#define N 5000
#define AUTO 100
#include "miti_2.h"
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void ImprimirApagados(TReg vect[], int n);
void ImprimirTReg(TReg vect[], int n);
void NombreArch(char archivo[]);
void CrearBorrados(TReg vect[], int n);
void ActualizarTXT(char Nombre[], TReg vect[], int n);
void CrearTXT(char Nombre[], TReg vect[], int n);
int CrearBIN(TReg vect[], int n, char nom[]);
int LeerBIN(TReg vect[], int *i, int max, char nom[]);
void MostrarTXT(char nom[]);
void RespaldoBIN(char nom[]);
TReg RegistroAuto();
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
    printf("1.- AGREGAR REGISTROS \n");
    printf("2.- EDITAR REGISTRO \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- IMPRIMIR \n");
    printf("7.- GENERAR ARCHIVO TXT \n");
    printf("8.- VER ARCHIVO TXT \n");
    printf("9.- CREAR ARCHIVO BINARIO \n");
    printf("10.- CARGAR ARCHIVO BINARIO \n");
    printf("11.- MOSTRAR ELIMINADOS \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    srand(time(NULL));
    TReg VectReg[5000], temp;
    int op, j, i, apagar, buscar, encontrado, ordenado, cargado, confirmar, creado, registros, editar, campo, sexo, puesto;
    char NombreTXT[50], Mostrar[50], NombreBIN[11] = {"datos.dll"};
    char Nombre[60];
    char puestos[6][11] = {"GERENTE", "TECNICO", "EMPLEADO", "ASISTENTE", "TECNICO", "ANALISTA"};
    char sexos[2][7] = {"HOMBRE", "MUJER"};
    i = 0;
    ordenado = 0;
    cargado = 0;
    creado = 0;
    do
    {
        op = msges();
        switch (op)
        {
        case 1: // AGREGAR
            system("CLS");
            for (j = 0; j < AUTO; j++)
            {
                temp = RegistroAuto();
                while (BusquedaTReg(VectReg, i, temp.key) != -1)
                {
                    temp.key = NumAleatorio(300000, 399999);
                }
                if (i <= N)
                {
                    VectReg[i++] = temp;
                    ordenado = 0;
                }
            }
            if (i < N)
            {
                printf("REGISTROS LLENADOS AUTOMATICAMENTE\n");
            }
            else
            {
                printf("500 REGISTROS OCUPADOS\n");
            }
            system("PAUSE");
            break;
        case 2: // EDITAR REGISTRO
            system("CLS");
            if (i == 0)
            {
                printf("REGISTROS VACIOS\n");
                system("PAUSE");
            }
            else
            {
                printf("NUMERO DE EMPLEADO A BUSCAR\n");
                buscar = Validar(1, 2000);
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
                    printf("NUMERO DE EMPLEADO NO ENCONTRADA\n");
                }
                else
                {
                    if (VectReg[encontrado].Status == 0)
                    {
                        printf("NUMERO DE EMPLEADO DE ALUMNO DESACTIVADO\n");
                    }
                    else
                    {
                        system("CLS");
                        printf("DATOS DEL REGISTRO ENCONTRADO:\n");
                        printf("EMPLEADO EN REGISTRO: %d\n", encontrado);
                        printf("NUMERO DE EMPLEADO: %d\n", VectReg[encontrado].Empleado);
                        printf("NOMBRE: %s\n", VectReg[encontrado].Nombre);
                        printf("APELLIDO PATERNO: %s\n", VectReg[encontrado].Paterno);
                        printf("APELLIDO MATERNO: %s\n", VectReg[encontrado].Materno);
                        printf("PUESTO: %s\n", VectReg[encontrado].Puesto);
                        printf("EDAD: %d\n", VectReg[encontrado].Edad);
                        printf("SEXO: %s\n", VectReg[encontrado].Sexo);
                        system("pause");
                        system("cls");
                        printf("EDITAR REGISTRO: 1.SI 0.NO\n");
                        editar = Validar(0, 1);
                        system("cls");
                        if (editar)
                        {
                            printf("---EDITAR REGISTRO---\n");
                            printf("1. NUMERO DE EMPLEADO\n");
                            printf("2. NOMBRE DE EMPLEADO\n");
                            printf("3. PUESTO\n");
                            printf("4. SEXO\n");
                            printf("5. EDAD\n");
                            printf("REGISTRO A VALIDAR: ");
                            campo = Validar(1, 5);
                            system("cls");
                            switch (campo)
                            {
                            case 1:
                                do
                                {
                                    printf("EDITAR NUMERO DE EMPLEADO\n");
                                    temp.Empleado = Validar(1, 2000);
                                    temp.key = temp.Empleado;
                                } while (BusquedaTReg(VectReg, i, temp.key) != -1);
                                VectReg[encontrado].Empleado = temp.Empleado;
                                VectReg[encontrado].key = temp.Empleado;
                                break;
                            case 2:
                                ValiCadena(Nombre, "EDITAR NOMBRE DEL EMPLEADO");
                                strcpy(VectReg[encontrado].Nombre, Nombre);
                                ValiCadena(Nombre, "EDITAR APELLIDO PATERNO DEL EMPLEADO");
                                strcpy(VectReg[encontrado].Paterno, Nombre);
                                ValiCadena(Nombre, "EDITAR APELLIDO MATERNO DEL EMPLEADO");
                                strcpy(VectReg[encontrado].Materno, Nombre);
                                break;
                            case 3:
                                printf("EDITAR PUESTO\n");
                                for (int i = 0; i < 5; i++)
                                {
                                    printf("%d.- %s\n", i, puestos[i]);
                                }
                                printf("SELECCIONA UN PUESTO \n");
                                puesto = Validar(0, 4);
                                strcpy(temp.Puesto, puestos[puesto]);
                                strcpy(VectReg[encontrado].Puesto, temp.Puesto);
                                break;
                            case 4:
                                printf("EDITAR SEXO\n");
                                printf("1. MUJER\n0. HOMBRE\n");
                                printf("SELECCIONA UN SEXO \n");
                                sexo = Validar(0, 1);
                                strcpy(VectReg[encontrado].Sexo, sexos[sexo]);
                                break;
                            case 5:
                                printf("EDITAR EDAD\n");
                                VectReg[encontrado].Edad = Validar(18, 65);
                                break;
                            }
                        }
                    }
                }
                system("PAUSE");
                break;

                break;
            case 3: // ELIMINAR REGISTRO
                system("CLS");
                if (i == 0)
                {
                    printf("INCAPAZ DE ELIMINAR REGISTROS VACIOS\n");
                }
                else
                {
                    printf("NUMERO DE EMPLEADO DE REGISTRO A ELIMINAR\n");
                    apagar = Validar(1, 2000);
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
                        printf("NUMERO DE EMPLEADO NO EXISTENTE\n");
                    }
                    else // Encontrada
                    {
                        if (VectReg[encontrado].Status == 0)
                        {
                            printf("REGISTRO YA ELIMINADO\n");
                        }
                        else
                        {
                            system("CLS");
                            printf("DATOS DEL REGISTRO ENCONTRADO:\n");
                            printf("EMPLEADO EN REGISTRO: %d\n", encontrado);
                            printf("NUMERO DE EMPLEADO: %d\n", VectReg[encontrado].Empleado);
                            printf("NOMBRE: %s\n", VectReg[encontrado].Nombre);
                            printf("APELLIDO PATERNO: %s\n", VectReg[encontrado].Paterno);
                            printf("APELLIDO MATERNO: %s\n", VectReg[encontrado].Materno);
                            printf("PUESTO: %s\n", VectReg[encontrado].Puesto);
                            printf("EDAD: %d\n", VectReg[encontrado].Edad);
                            printf("SEXO: %s\n", VectReg[encontrado].Sexo);
                            system("pause");
                            system("cls");
                            printf("DESEA ELIMINAR EL REGISTRO: 1.SI 0.NO\n");
                            confirmar = Validar(0, 1);
                            system("cls");
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
            case 4:
                system("CLS");
                if (i == 0)
                {
                    printf("REGISTROS VACIOS\n");
                    system("PAUSE");
                }
                else
                {
                    printf("NUMERO DE EMPLEADO A BUSCAR\n");
                    buscar = Validar(1, 2000);
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
                        printf("NUMERO DE EMPLEADO NO ENCONTRADA\n");
                    }
                    else
                    {
                        if (VectReg[encontrado].Status == 0)
                        {
                            printf("NUMERO DE EMPLEADO DE ALUMNO DESACTIVADO\n");
                        }
                        else
                        {
                            system("CLS");
                            printf("DATOS DEL REGISTRO ENCONTRADO:\n");
                            printf("EMPLEADO EN REGISTRO: %d\n", encontrado);
                            printf("NUMERO DE EMPLEADO: %d\n", VectReg[encontrado].Empleado);
                            printf("NOMBRE: %s\n", VectReg[encontrado].Nombre);
                            printf("APELLIDO PATERNO: %s\n", VectReg[encontrado].Paterno);
                            printf("APELLIDO MATERNO: %s\n", VectReg[encontrado].Materno);
                            printf("PUESTO: %s\n", VectReg[encontrado].Puesto);
                            printf("EDAD: %d\n", VectReg[encontrado].Edad);
                            printf("SEXO: %s\n", VectReg[encontrado].Sexo);
                            system("pause");
                            system("cls");
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
                case 7: // GENERAR TXT
                    system("CLS");
                    if (i == 0)
                    {
                        printf("REGISTROS VACIOS\n");
                    }
                    else
                    {
                        NombreArch(NombreTXT);
                        CrearTXT(NombreTXT, VectReg, i);
                        creado = 1;
                        printf("ARCHIVO CREADO EXITOSAMENTE");
                        printf("\n");
                    }
                    system("PAUSE");
                    break;
                case 8: // MOSTRAR ARCHIVO TXT
                    NombreArch(Mostrar);
                    MostrarTXT(Mostrar);
                    system("pause");
                    break;
                case 9: // CREAR BINARIO;
                    system("CLS");
                    if (creado)
                    {
                        RespaldoBIN(NombreBIN);
                        NombreArch(NombreBIN);
                        creado = CrearBIN(VectReg, i, NombreBIN);
                    }
                    else
                    {
                        NombreArch(NombreBIN);
                        creado = CrearBIN(VectReg, i, NombreBIN);
                    }

                    system("pause");
                    break;
                case 10: // CARGAR BINARIO
                    system("CLS");
                    if (cargado == 0)
                    {
                        NombreArch(NombreBIN);
                        cargado = LeerBIN(VectReg, &i, N, NombreBIN);
                    }
                    else
                    {
                        printf("ARCHIVO YA CARGADO\n");
                    }
                    system("pause");
                    break;
                case 11: // MOSTRAR BORRADOS
                    system("CLS");
                    ImprimirApagados(VectReg, i);
                    system("pause");
                    break;
                case 0:
                    if (cargado == 0)
                    {
                        if (creado)
                        {
                            ActualizarTXT(NombreTXT, VectReg, i);
                            CrearBorrados(VectReg, i);
                        }
                    }
                    else
                    {
                        ActualizarTXT(NombreTXT, VectReg, i);
                        CrearBorrados(VectReg, i);
                    }
                    break;
                }
            }
        }
    } while (op != 0);
}

TReg RegistroAuto()
{
    TReg alum;
    int i, sexo;
    char puestos[][11] = {"GERENTE", "TECNICO", "EMPLEADO", "ASISTENTE", "TECNICO", "ANALISTA"};
    char NombresHombre[][15] = {" ", "ALBERTO", "FERNANDO", "MARIO", "ALEJANDRO", "GABRIEL", "SERGIO", "CARLOS", "HECTOR", "LUIS", "ENRIQUE", "JULIO", "RODRIGO", "EDUARDO", "OSCAR", "GUSTAVO", "JUAN", "CARLOS", "LUIS", "JOSE", "MIGUEL", "PEDRO", "ANTONIO", "MANUEL", "JAVIER", "PABLO", "DAVID", "FRANCISCO", "ALEJANDRO", "DANIEL", "ANDRES"};
    char NombresMujer[][15] = {" ", "LUCIA", "RAQUEL", "NATALIA", "BEATRIZ", "LOURDES", "CLARA", "LINDA", "GLORIA", "ADRIANA", "VALERIA", "ALICIA", "VICTORIA", "DIANA", "SILVIA", "SARA", "MARIA", "ANA", "LAURA", "CARMEN", "ISABEL", "SOFIA", "LUISA", "ELENA", "PATRICIA", "TERESA", "ROSA", "PAULA", "MARTA", "CRISTINA", "DANNA"};
    char Apellidos[][30] = {"HARO", "SOLANO", "SANDEZ", "LOPEZ", "MEZA", "PEREZ", "SANCHEZ", "FERNANDEZ", "TORRES", "RAMIREZ", "RUIZ", "GONZALEZ", "TORRES", "MORALES", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "MORALES", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "SILVA", "CASTRO", "RIOS", "MONTOYA", "PENA", "VIDAL", "AGUILAR", "CORDERO", "MORA", "SOSA", "ROSALES", "LUGO", "SERRANO", "CACERES", "ROBLES", "SALAZAR", "LEON", "GALLEGOS", "CORDOVA", "DEL VALLE", "NAVARRO", "PAREDES", "ZAMORA", "VALDEZ", "DURAN", "CISNEROS", "GUTIERREZ", "SALINAS", "AVILA", "RIVAS", "PIZARRO", "GUERRA", "ESPINOZA", "CALDERON", "PANTOJA", "MIRANDA", "MORALES", "ROJAS", "SEGURA", "VILLANUEVA", "ROLDAN", "BENITEZ", "LUNA", "VALENCIA", "CERVANTES", "ESCOBAR", "ZUNIGA", "BARRIOS"};
    char sexos[2][8] = {"HOMBRE", "MUJER"};
    sexo = NumAleatorio(1, 2);
    if (sexo == 1)
    {

        strcpy(alum.Nombre, NombresHombre[NumAleatorio(1, 29)]);
        strcpy(alum.Paterno, Apellidos[NumAleatorio(0, 88)]);
        strcpy(alum.Materno, Apellidos[NumAleatorio(0, 88)]);
        strcpy(alum.Sexo, sexos[0]);
    }
    else
    {

        strcpy(alum.Nombre, NombresMujer[NumAleatorio(1, 29)]);
        strcpy(alum.Paterno, Apellidos[NumAleatorio(0, 88)]);
        strcpy(alum.Materno, Apellidos[NumAleatorio(0, 88)]);
        strcpy(alum.Sexo, sexos[1]);
    }

    strcpy(alum.Puesto, puestos[NumAleatorio(0, 5)]);
    alum.Status = 1;
    alum.Empleado = NumAleatorio(1, 2000);
    alum.key = alum.Empleado;
    alum.Edad = NumAleatorio(18, 27);
    return alum;
}

void ImprimirTReg(TReg vect[], int n)
{
    int i, j;
    j = 0;
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++, j++)
    {
        if (vect[i].Status == 1)
        {
            printf("%-10d  %-10d      %-14s %-14s %-14s     %-10d      %-13s          %-10s      \n", i, vect[i].Empleado, vect[i].Nombre, vect[i].Paterno, vect[i].Materno, vect[i].Edad, vect[i].Puesto, vect[i].Sexo);
            if (j == 39)
            {
                system("PAUSE");
                system("CLS");
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                printf("  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                j = 0;
            }
        }
    }
}

void ImprimirApagados(TReg vect[], int n)
{
    int i, j;
    j = 0;
    printf("----------------------------------------------------------------------------------------------------------------------------\n");
    printf("  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
    printf("----------------------------------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++, j++)
    {
        if (vect[i].Status == 0)
        {
            printf("%-10d  %-10d      %-14s %-14s %-14s     %-10d      %-13s          %-10s      \n", i, vect[i].Empleado, vect[i].Nombre, vect[i].Paterno, vect[i].Materno, vect[i].Edad, vect[i].Puesto, vect[i].Sexo);
            if (j == 39)
            {
                system("PAUSE");
                system("CLS");
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                printf("  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                j = 0;
            }
        }
    }
}

void NombreArch(char archivo[])
{

    system("CLS");
    printf("NOMBRE DEL ARCHIVO SIN EXTENSION: \n");
    fflush(stdin);
    gets(archivo);
}

void CrearBorrados(TReg vect[], int n)
{
    int i;
    FILE *archivo;

    archivo = fopen("eliminados.txt", "w");
    fprintf(archivo, "----------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(archivo, "  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
    fprintf(archivo, "----------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].Status == 0)
        {
            fprintf(archivo, "%-10d  %-10d      %-14s %-14s %-14s     %-10d      %-13s          %-10s      \n", i, vect[i].Empleado, vect[i].Nombre, vect[i].Paterno, vect[i].Materno, vect[i].Edad, vect[i].Puesto, vect[i].Sexo);
        }
    }

    fclose(archivo);
}

void ActualizarTXT(char Nombre[], TReg vect[], int n)
{
    int i;
    FILE *archivo;

    archivo = fopen(Nombre, "w");
    fprintf(archivo, "----------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(archivo, "  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
    fprintf(archivo, "----------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].Status != 0)
        {
            fprintf(archivo, "%-10d  %-10d      %-14s %-14s %-14s     %-10d      %-13s          %-10s      \n", i, vect[i].Empleado, vect[i].Nombre, vect[i].Paterno, vect[i].Materno, vect[i].Edad, vect[i].Puesto, vect[i].Sexo);
        }
    }

    fclose(archivo);
}

int ContarReg(char nombre[])
{
    int cont;
    char fileName[50];
    char cmd[50];

    system("gcc Contador.c -o Contador");
    sprintf(cmd, "Contador.exe %s", nombre);
    cont = system(cmd);

    return cont;
}

void CrearTXT(char Nombre[], TReg vect[], int n)
{
    int i;
    FILE *archivo;

    strcat(Nombre, ".txt");
    archivo = fopen(Nombre, "w");
    fprintf(archivo, "----------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(archivo, "  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
    fprintf(archivo, "----------------------------------------------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        if (vect[i].Status != 0)
        {
            fprintf(archivo, "%-10d  %-10d      %-14s %-14s %-14s     %-10d      %-13s          %-10s      \n", i, vect[i].Empleado, vect[i].Nombre, vect[i].Paterno, vect[i].Materno, vect[i].Edad, vect[i].Puesto, vect[i].Sexo);
        }
    }
    fclose(archivo);
}

int CrearBIN(TReg vect[], int n, char nom[])
{
    char archivo[30];
    strcpy(archivo, nom);
    TReg reg;
    int i;
    strcat(archivo, ".dll");
    FILE *fa;
    fa = fopen(archivo, "ab");
    for (i = 0; i < n; i++)
    {
        reg = vect[i];
        fwrite(&reg, sizeof(TReg), 1, fa);
    }
    fclose(fa);
    return 1;
}

int LeerBIN(TReg vect[], int *i, int max, char nom[])
{
    char archivo[30];
    FILE *fa;
    TReg reg;
    strcpy(archivo, nom);
    strcat(archivo, ".dll");
    fa = fopen(archivo, "rb");
    if (fa)
    {
        while (fread(&reg, sizeof(TReg), 1, fa))
        {
            if ((*i) <= max)
            {
                vect[(*i)++] = reg;
            }
        }
        fclose(fa);
        printf("ARCHIVO CARGADO CON EXITO\n");
        return 1;
    }
    else
    {
        printf("ERROR AL LEER EL ARCHIVO\n");
        return 0;
    }
}

void MostrarTXT(char nom[])
{
    system("cls");
    strcat(nom, ".txt");
    int i, j;
    TReg reg;
    char x[10];
    FILE *fa;
    fa = fopen(nom, "r");
    if (fa)
    {
        i = 0;
        j = 0;
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
        printf("  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
        printf("----------------------------------------------------------------------------------------------------------------------------\n");
        do
        {
            fscanf(fa, "%s %d %s %s %s %d %s %s", &x, &reg.Empleado, &reg.Nombre, &reg.Paterno, &reg.Materno, &reg.Edad, &reg.Puesto, &reg.Sexo);
            printf("%-10d  %-10d      %-14s %-14s %-14s     %-10d      %-13s          %-10s      \n", i, reg.Empleado, reg.Nombre, reg.Paterno, reg.Materno, reg.Edad, reg.Puesto, reg.Sexo);
            if (j == 39)
            {
                system("PAUSE");
                system("CLS");
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                printf("  NO. |  NO. EMPLEADO |                      NOMBRE                     |  EDAD  |           PUESTO            |   SEXO    | \n");
                printf("----------------------------------------------------------------------------------------------------------------------------\n");
                j = 0;
            }
            i++;
            j++;
        } while (!feof(fa));
        fclose(fa);
    }
    else
    {
        printf("ARCHIVO NO EXISTENTE\n");
        return 0;
    }
}

void RespaldoBIN(char nom[])
{
    char archivo1[30], archivo2[30];
    FILE *fa;
    FILE *respaldo;
    TReg reg;
    strcpy(archivo1, nom);
    strcat(archivo1, ".dll");
    fa = fopen(archivo1, "rb");
    if (fa)
    {
        strcpy(archivo2, nom);
        strcat(archivo2, ".tmp");
        respaldo = fopen(archivo2, "wb");
        while (fread(&reg, sizeof(TReg), 1, fa))
        {
            fwrite(&reg, sizeof(TReg), 1, respaldo);
        }
        fclose(fa);
        fclose(respaldo);
    }
}