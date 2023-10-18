#include "odin.h"
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void LeerTXT(FILE *archivo);
void CrearTXT(char nombres[], char paterno[], char materno[], int edad);
//****  main principal  *********
int main()
{
    menu();

    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- IMPRIMIR CANCION \n");
    printf("2.- IMPRIMIR ARTE \n");
    printf("3.- CREAR ARCHIVO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    FILE *archivo;
    char nombre[20], paterno[20], materno[20];
    int op, edad;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("CLS");
            archivo = fopen("C:\\Miti\\Universidad\\3er. Semestre\\Programacion Estructurada\\Repositorio\\Taller\\Taller2\\cancion.txt", "r");
            LeerTXT(archivo);
            system("PAUSE");
            break;
        case 2:
            system("CLS");
            archivo = fopen("C:\\Miti\\Universidad\\3er. Semestre\\Programacion Estructurada\\Repositorio\\Taller\\Taller2\\arte.txt", "r");
            LeerTXT(archivo);
            system("PAUSE");
            break;
        case 3:
            system("CLS");
            ValiCadena(nombre, "NOMBRES");
            ValiCadena(paterno, "APELLIDO PATERNO");
            ValiCadena(materno, "APELLIDO MATERNO");
            edad = Validar(18, 50);
            CrearTXT(nombre, paterno, materno, edad);
            system("PAUSE");
            break;
        }

    } while (op != 0);
}
void LeerTXT(FILE *archivo)
{
    char caracter;
    if (archivo)
    {
        do
        {
            caracter = fgetc(archivo);
            printf("%c", caracter);
        } while (!feof(archivo));
        fclose(archivo);
    }
}

void CrearTXT(char nombres[], char paterno[], char materno[], int edad)
{
    FILE *archivo;
    archivo = fopen("creado.txt", "a");
    fprintf(archivo, "\n%-30s   %-30s   %-30s   %-4d", nombres, paterno, materno, edad);
}
