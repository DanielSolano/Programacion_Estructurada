// Solano Meza Angel Daniel Matr. 372453
// 28/11/2023
// Uso de archivos binarios
// ADSM_ACT14_932

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
TKey Busquedas(TIndex vect[], int n, int i, int *ordenado);
void AgregarRegistro(TIndex vect[], int *i, int ordenado);
void EliminarRegistro(TIndex vect[], int *i, int ordenado);
void BuscarRegistro(TIndex vect[], int *i, int ordenado);
void MostrarNormal(void);
void MostrarOrdenado(int i, int ordenado, TIndex vect[], int movimientos);
void GenerarOrdenado(char nom[], int ordenado, TIndex vect[], int movimientos, int i);
void GenerarNormal(char nom[]);
void Empaquetar();

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
    printf("7.- GENERAR ARCHIVO TXT ORDENADO\n");
    printf("8.- GENERAR ARCHIVO TXT NORMAL\n");
    printf("9.- EMPAQUETAR \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    srand(time(NULL));
    int op, n, i = 0, ordenado = 0, movimientos = 0;
    char nom[50];
    n = ContarReg("datos");
    n *= 1.25;
    TIndex IndexReg[n];
    CrearIndices(IndexReg, &i);
    RespaldoBIN("datos");
    do
    {
        op = msges();
        switch (op)
        {
        case 1: // AGREGAR
            system("CLS");
            AgregarRegistro(IndexReg, &i, ordenado);
            movimientos++;
            ordenado = 0;
            system("PAUSE");
            break;
        case 2: // EDITAR REGISTRO
            system("CLS");
            EliminarRegistro(IndexReg, &i, ordenado);
            system("PAUSE");
            break;
        case 3: // BUSCAR REGISTRO
            system("CLS");
            BuscarRegistro(IndexReg, &i, ordenado);
            system("PAUSE");
            break;
        case 4: // ORDENAR REGISTROS
            system("CLS");
            if (ordenado == 0)
            {
                printf("INDICES ORDENADOS\n");
                ordenado = 1;
                movimientos = 0;
            }
            else
            {
                printf("INDICES YA ORDENADOS\n");
            }
            system("PAUSE");
            break;
        case 5: // ORDENAR REGISTROS
            system("CLS");
            MostrarNormal();
            system("PAUSE");
            break;
        case 6: // IMPRIMIR REGISTROS
            system("CLS");
            MostrarOrdenado(i, ordenado, IndexReg, movimientos);
            system("PAUSE");
            break;
        case 7: // GENERAR TXT
            system("CLS");
            GenerarOrdenado(nom, ordenado, IndexReg, movimientos, i);
            system("PAUSE");
            break;
        case 8: // MOSTRAR ARCHIVO TXT
            system("CLS");
            GenerarNormal(nom);
            system("PAUSE");
            break;
        case 9:
            Empaquetar();
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
    int sexo = 0, cuatro, tres, telefono;
    char puestos[][11] = {"GERENTE", "TECNICO", "EMPLEADO", "ASISTENTE", "TECNICO", "ANALISTA"};
    char NombresHombre[][15] = {" ", "ALBERTO", "FERNANDO", "MARIO", "ALEJANDRO", "GABRIEL", "SERGIO", "CARLOS", "HECTOR", "LUIS", "ENRIQUE", "JULIO", "RODRIGO", "EDUARDO", "OSCAR", "GUSTAVO", "JUAN", "CARLOS", "LUIS", "JOSE", "MIGUEL", "PEDRO", "ANTONIO", "MANUEL", "JAVIER", "PABLO", "DAVID", "FRANCISCO", "ALEJANDRO", "DANIEL", "ANDRES"};
    char NombresMujer[][15] = {" ", "LUCIA", "RAQUEL", "NATALIA", "BEATRIZ", "LOURDES", "CLARA", "LINDA", "GLORIA", "ADRIANA", "VALERIA", "ALICIA", "VICTORIA", "DIANA", "SILVIA", "SARA", "MARIA", "ANA", "LAURA", "CARMEN", "ISABEL", "SOFIA", "LUISA", "ELENA", "PATRICIA", "TERESA", "ROSA", "PAULA", "MARTA", "CRISTINA", "DANNA"};
    char Apellidos[][30] = {"HARO", "SOLANO", "SANDEZ", "LOPEZ", "MEZA", "PEREZ", "SANCHEZ", "FERNANDEZ", "TORRES", "RAMIREZ", "RUIZ", "GONZALEZ", "TORRES", "MORALES", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "MORALES", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "SILVA", "CASTRO", "RIOS", "MONTOYA", "PENA", "VIDAL", "AGUILAR", "CORDERO", "MORA", "SOSA", "ROSALES", "LUGO", "SERRANO", "CACERES", "ROBLES", "SALAZAR", "LEON", "GALLEGOS", "CORDOVA", "VALLE", "NAVARRO", "PAREDES", "ZAMORA", "VALDEZ", "DURAN", "CISNEROS", "GUTIERREZ", "SALINAS", "AVILA", "RIVAS", "PIZARRO", "GUERRA", "ESPINOZA", "CALDERON", "PANTOJA", "MIRANDA", "MORALES", "ROJAS", "SEGURA", "VILLANUEVA", "ROLDAN", "BENITEZ", "LUNA", "VALENCIA", "CERVANTES", "ESCOBAR", "ZUNIGA", "BARRIOS"};
    char Estados[33][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CIUDAD DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "NACIDO EN EL EXTRANJERO"};
    char sexos[2][8] = {"HOMBRE", "MUJER"};
    sexo = NumAleatorio(0, 1);
    if (sexo == 1)
    {

        strcpy(trabajador.name, NombresHombre[NumAleatorio(1, 29)]);
        strcpy(trabajador.LastName1, Apellidos[NumAleatorio(0, 88)]);
        strcpy(trabajador.LastName2, Apellidos[NumAleatorio(0, 88)]);
        strcpy(trabajador.sex, sexos[0]);
    }
    else
    {

        strcpy(trabajador.name, NombresMujer[NumAleatorio(1, 29)]);
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
    trabajador.status = 1;

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
    fa = fopen("datos.dat", "a+b");
    fseek(fa, 0, SEEK_END);
    fwrite(&reg, sizeof(TReg), 1, fa);
    fclose(fa);

    vect[*i].index = *i;
    vect[*i].enrollment = reg.enrollment;
    (*i)++;
    printf("REGISTRO AGREGADO\n");
}

TKey Busquedas(TIndex vect[], int n, int i, int *ordenado)
{
    TKey j;

    if (ordenado)
    {

        j = BusquedaBinaria(vect, 0, i, n);
    }
    else
    {
        j = BusquedaTIndex(vect, n, i);
    }
    return j;
}

void EliminarRegistro(TIndex vect[], int *i, int ordenado)
{
    int eliminar, encontrado, op;
    TReg reg;
    FILE *fa;
    printf("NO. DE EMPLEADO A ELIMINAR: ");
    eliminar = Validar(300000, 399999);
    encontrado = Busquedas(vect, *i, eliminar, ordenado);
    if (encontrado != -1)
    {
        fa = fopen("datos.dat", "rb");
        fseek(fa, sizeof(TReg) * vect[encontrado].index, SEEK_SET);
        fread(&reg, sizeof(TReg), 1, fa);
        fclose(fa);
        if (reg.status == 0)
        {
            printf("MATRICULA YA ELIMINADA\n");
        }
        else
        {
            printf("NOMBRE: %s\nAPELLIDOS: %s %s\nSEXO: %s \nPUESTO: %s \nESTADO: %s\nEDAD: %d\nTELEFONO: %d\n", reg.name, reg.LastName1, reg.LastName2, reg.sex, reg.JobPosition, reg.State, reg.age, reg.cellPhone);
            printf("ELIMINAR\n1-SI\n2-NO\nSELECCIONE UNA OPCION: ");
            op = Validar(1, 2);
            system("CLS");
            if (op == 1)
            {
                fa = fopen("datos.dat", "r+b");
                if (fa)
                {
                    fseek(fa, sizeof(TReg) * vect[encontrado].index, SEEK_SET);
                    fread(&reg, sizeof(TReg), 1, fa);
                    reg.status = 0;
                    fseek(fa, sizeof(TReg) * vect[encontrado].index, SEEK_SET);
                    fwrite(&reg, sizeof(TReg), 1, fa);
                    printf("REGISTRO ELIMINADO\n");
                    fclose(fa);
                }
                else
                {
                    printf("ERROR, NO ABIERTO\n");
                }
            }
            else
            {
                printf("REGISTRO NO ELIMINADO\n");
            }
        }
    }
    else
    {
        printf("MATRICULA NO ENCONTRADA\n");
    }
}

void BuscarRegistro(TIndex vect[], int *i, int ordenado)
{
    int buscar, encontrado;
    TReg reg;
    FILE *fa;
    printf("NO. DE EMPLEADO A BUSCAR: ");
    buscar = Validar(300000, 399999);
    encontrado = Busquedas(vect, *i, buscar, ordenado);
    if (encontrado != -1)
    {
        fa = fopen("datos.dat", "rb");
        fseek(fa, sizeof(TReg) * vect[encontrado].index, SEEK_SET);
        fread(&reg, sizeof(TReg), 1, fa);
        fclose(fa);
        if (reg.status == 0)
        {
            printf("MATRICULA ELIMINADA\n");
        }
        else
        {
            printf("INDICE: %d\nNOMBRE: %s\nAPELLIDOS: %s %s\nSEXO: %s \nPUESTO: %s \nESTADO: %s\nEDAD: %d\nTELEFONO: %d\n", encontrado, reg.name, reg.LastName1, reg.LastName2, reg.sex, reg.JobPosition, reg.State, reg.age, reg.cellPhone);
        }
    }
    else
    {
        printf("MATRICULA NO ENCONTRADA\n");
    }
}

int Ordenacion(TIndex vect[], int i, int movimientos)
{
    if (movimientos == 0)
    {
        Quicksort(vect, 0, i - 1);
    }
    else
    {
        if (movimientos < 3)
        {
            Burbuja(vect, i);
        }
        else
        {
            Quicksort(vect, 0, i - 1);
        }
    }
    return 1;
}

void MostrarNormal(void)
{
    FILE *fa;
    TReg reg;
    int j = 0;
    fa = fopen("datos.dat", "rb");
    while (fread(&reg, sizeof(TReg), 1, fa))
    {
        printf("%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", j++, reg.enrollment, reg.name, reg.LastName1, reg.LastName2, reg.age, reg.sex, reg.JobPosition, reg.State, reg.cellPhone);
    }
    fclose(fa);
}

void MostrarOrdenado(int i, int ordenado, TIndex vect[], int movimientos)
{
    FILE *fa;
    TReg reg;
    if (ordenado == 0)
    {
        Ordenacion(vect, i, movimientos);
    }
    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        for (int j = 0; j < i; j++)
        {
            fseek(fa, vect[j].index * sizeof(TReg), SEEK_SET);
            fread(&reg, sizeof(TReg), 1, fa);
            printf("%-9d  %-11d  %-15s  %-20s  %-17s  %-7d  %-13s  %-18s  %-13s  %d\n", vect[j].index, reg.enrollment, reg.name, reg.LastName1, reg.LastName2, reg.age, reg.sex, reg.JobPosition, reg.State, reg.cellPhone);
        }
        fclose(fa);
    }
}

void GenerarOrdenado(char nom[], int ordenado, TIndex vect[], int movimientos, int i)
{
    FILE *fa, *bin;
    TReg reg;
    NombreArch(nom);
    strcat(nom, ".txt");
    if (ordenado == 0)
    {
        Ordenacion(vect, i, movimientos);
    }
    bin = fopen("datos.dat", "rb");
    fa = fopen(nom, "w");
    for (int j = 0; j < i; j++)
    {
        fseek(bin, vect[j].index * sizeof(TReg), SEEK_SET);
        fread(&reg, sizeof(TReg), 1, bin);
        if (reg.status == 1)

        {
            fprintf(fa, "%10d || %10d || %9s || %16s || %16s || %12s || %16s || %4d || %10d\n", vect[j].index, reg.enrollment, reg.name, reg.LastName1, reg.LastName2, reg.sex, reg.JobPosition, reg.age, reg.cellPhone);
        }
    }
    fclose(fa);
    fclose(bin);
}

void GenerarNormal(char nom[])
{
    FILE *fa, *bin;
    TReg reg;
    int j = 0;
    NombreArch(nom);
    strcat(nom, ".txt");
    bin = fopen("datos.dat", "rb");
    fa = fopen(nom, "w");

    while (fread(&reg, sizeof(TReg), 1, bin))
    {
        if (reg.status == 1)
        {
            fprintf(fa, "%-10d || %10d || %9s || %16s || %16s || %12s || %16s || %16s || %4d || %10d\n", j++, reg.enrollment, reg.name, reg.LastName1, reg.LastName2, reg.sex, reg.JobPosition,reg.State, reg.age, reg.cellPhone);
        }
    }

    fclose(fa);
    fclose(bin);
}

void Empaquetar()
{
    FILE *doc = fopen("datos.dat", "rb");
    FILE *fa = fopen("datos.bak", "wb");

    TReg reg;

    if (doc)
    {
        while (fread(&reg, sizeof(TReg), 1, doc))
        {
            if (reg.status == 1)
            {
                fwrite(&reg, sizeof(TReg), 1, fa);
            }
        }
    }

    fclose(doc);
    fclose(fa);
}