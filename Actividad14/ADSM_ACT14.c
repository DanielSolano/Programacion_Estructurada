// Solano Meza Angel Daniel Matr. 372453
// 13/11/2023
// Uso de archivos binarios
// ADSM_ACT13_932

#define N 5000
#define AUTO 100
#include "junior.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void NombreArch(char archivo[]);
int ContarReg(char nombre[]);
int CrearIndices(TIndex vect[], int *i);
TReg AgregarAuto(void);
void RespaldoBIN(char nom[]);
TKey Busquedas(TIndex vect[], int n, int i, int ordenado);
void AgregarRegistro(TIndex vect[], int *i, int ordenado);

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
    printf("1.- AGREGAR \n");
    printf("2.- ELIMINAR  \n");
    printf("3.- BUSCAR  \n");
    printf("4.- ORDENAR \n");
    printf("5.- IMPRIMIR REGISTROS ARCHIVO ORIGINAL \n");
    printf("6.- IMPRIMIR REGISTROS ARCHIVO ORDENADO \n");
    printf("7.- GENERAR ARCHIVO TXT \n");
    printf("8.- EMPAQUETAR \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    srand(time(NULL));
    int op, n, i = 0, ordenado = 0;

    n = ContarReg("datos");
    n *= 1.25;
    TIndex IndexReg[n];
    CrearIndices(IndexReg, &i);
    RespaldoBIN("datos");
    TReg reg;
    do
    {
        op = msges();
        switch (op)
        {
        case 1: // AGREGAR
            AgregarRegistro(IndexReg, &i, ordenado);
            system("PAUSE");
            break;
        case 2: // EDITAR REGISTRO

            break;
        case 3: // ELIMINAR REGISTRO

            break;
        case 4: // ORDENAR REGISTROS

            break;
        case 5: // ORDENAR REGISTROS

            break;
        case 6: // IMPRIMIR REGISTROS

            break;
        case 7: // GENERAR TXT

            break;
        case 8: // MOSTRAR ARCHIVO TXT

            break;
        case 0:

            break;
        }
    } while (op != 0);
}

int ContarReg(char nombre[])
{
    int cont;
    char cmd[50];

    system("gcc Contador.c -o Contador");
    sprintf(cmd, "Contador.exe %s", nombre);
    cont = system(cmd);

    return cont;
}

void NombreArch(char archivo[])
{

    system("CLS");
    printf("NOMBRE DEL ARCHIVO SIN EXTENSION: \n");
    fflush(stdin);
    gets(archivo);
}

int CrearIndices(TIndex vect[], int *i)
{
    FILE *fa;
    TReg reg;
    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        while (fread(&reg, sizeof(TReg), 1, fa))
        {
            vect[(*i)].index = *i;
            vect[(*i)++].enrollment = reg.enrollment;
        }
        fclose(fa);
        return 1;
    }
    else
    {
        return 0;
    }
}

TReg AgregarAuto(void)
{
    TReg trabajador;
    int sexo, cuatro, tres, telefono;
    char numero[11];
    char puestos[][11] = {"GERENTE", "TECNICO", "EMPLEADO", "ASISTENTE", "TECNICO", "ANALISTA"};
    char NombresHombre[][15] = {" ", "ALBERTO", "FERNANDO", "MARIO", "ALEJANDRO", "GABRIEL", "SERGIO", "CARLOS", "HECTOR", "LUIS", "ENRIQUE", "JULIO", "RODRIGO", "EDUARDO", "OSCAR", "GUSTAVO", "JUAN", "CARLOS", "LUIS", "JOSE", "MIGUEL", "PEDRO", "ANTONIO", "MANUEL", "JAVIER", "PABLO", "DAVID", "FRANCISCO", "ALEJANDRO", "DANIEL", "ANDRES"};
    char NombresMujer[][15] = {" ", "LUCIA", "RAQUEL", "NATALIA", "BEATRIZ", "LOURDES", "CLARA", "LINDA", "GLORIA", "ADRIANA", "VALERIA", "ALICIA", "VICTORIA", "DIANA", "SILVIA", "SARA", "MARIA", "ANA", "LAURA", "CARMEN", "ISABEL", "SOFIA", "LUISA", "ELENA", "PATRICIA", "TERESA", "ROSA", "PAULA", "MARTA", "CRISTINA", "DANNA"};
    char Apellidos[][30] = {"HARO", "SOLANO", "SANDEZ", "LOPEZ", "MEZA", "PEREZ", "SANCHEZ", "FERNANDEZ", "TORRES", "RAMIREZ", "RUIZ", "GONZALEZ", "TORRES", "MORALES", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "MORALES", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "SILVA", "CASTRO", "RIOS", "MONTOYA", "PENA", "VIDAL", "AGUILAR", "CORDERO", "MORA", "SOSA", "ROSALES", "LUGO", "SERRANO", "CACERES", "ROBLES", "SALAZAR", "LEON", "GALLEGOS", "CORDOVA", "VALLE", "NAVARRO", "PAREDES", "ZAMORA", "VALDEZ", "DURAN", "CISNEROS", "GUTIERREZ", "SALINAS", "AVILA", "RIVAS", "PIZARRO", "GUERRA", "ESPINOZA", "CALDERON", "PANTOJA", "MIRANDA", "MORALES", "ROJAS", "SEGURA", "VILLANUEVA", "ROLDAN", "BENITEZ", "LUNA", "VALENCIA", "CERVANTES", "ESCOBAR", "ZUNIGA", "BARRIOS"};
    char Estados[33][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CIUDAD DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "NACIDO EN EL EXTRANJERO"};

    char sexos[2][8] = {"HOMBRE", "MUJER"};
    if (sexo == 1)
    {

        strcpy(trabajador.name, NombresHombre[NumAleatorio(1, 29)]);
        strcpy(trabajador.LastName1, Apellidos[NumAleatorio(0, 88)]);
        strcpy(trabajador.LastName2, Apellidos[NumAleatorio(0, 88)]);
        strcpy(trabajador.sex, sexos[0]);
    }
    else
    {

        strcpy(trabajador.name, NombresHombre[NumAleatorio(1, 29)]);
        strcpy(trabajador.LastName1, Apellidos[NumAleatorio(0, 88)]);
        strcpy(trabajador.LastName2, Apellidos[NumAleatorio(0, 88)]);
        strcpy(trabajador.sex, sexos[1]);
    }
    strcpy(trabajador.JobPosition, puestos[NumAleatorio(0, 5)]);
    strcpy(trabajador.State, Estados[NumAleatorio(0, 31)]);

    cuatro = rand() % 100 * 1000;
    tres = rand() % 1000;

    telefono = 1000000 + cuatro + tres;
    trabajador.cellPhone = telefono;

    trabajador.age = NumAleatorio(18, 65);
    trabajador.enrollment = NumAleatorio(300000, 399999);

    return trabajador;
}

void RespaldoBIN(char nom[])
{
    char archivo1[30], archivo2[30];
    FILE *fa;
    FILE *respaldo;
    TReg reg;
    strcpy(archivo1, nom);
    strcat(archivo1, ".dat");
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

void AgregarRegistro(TIndex vect[], int *i, int ordenado)
{
    TReg reg;
    FILE *fa;
    reg = AgregarAuto();

    while (Busquedas(vect, *i, reg.enrollment, ordenado) != -1)
    {
        reg.enrollment = NumAleatorio(300000, 399999);
    }
    fa = fopen("datos.tmp", "ab");
    fwrite(&reg, sizeof(TReg), 1, fa);
    fclose(fa);

    vect[*i].index = *i;
    vect[(*i)++].enrollment = reg.enrollment;
    printf("REGISTRO AGREGADO\n");
}

TKey Busquedas(TIndex vect[], int n, int i, int ordenado)
{
    TKey j;

    if (ordenado >= 1)
    {
        if (ordenado <= 5)
        {
            // BurbujaTIndex
        }
        else
        {
            if (ordenado == 1)
            {
                j = BusquedaBinaria(vect, 0, i, n);
            }
        }
    }
    else
    {
        j = BusquedaTIndex(vect, n, i);
    }
    return j;
}