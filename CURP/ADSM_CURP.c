#include "odin.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Curp(char curp[]);
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
    printf("   C U R P \n");
    printf("1.- GENERAR CURP \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    char curp[18];
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("CLS");
            Curp(curp);
            break;
        }

    } while (op != 0);
}

//*********************
void Curp(char curp[])
{
    char nombres[30], paterno[20], materno[20];
    int i;
    int DosLetras;
    fflush(stdin);
    ValiCadena(paterno, "APELLIDO PATERNO");
    DosLetras = 1;
    i = 0;
    while (DosLetras)
    {
        if (i == 0)
        {
            strcpy(curp[i], paterno[i]);
        }
        else
        {
            if ((paterno[i] == 'A') || (paterno[i] == 'E') || (paterno[i] == 'I') || (paterno[i] == 'O') || (paterno[i] == 'U'))
            {
                strcpy(curp[i], paterno[i]);
                DosLetras = 0;
            }
        }
    }

    fflush(stdin);
    ValiCadena(materno, "APELLIDO MATERNO");
    strcat(curp[2], materno[0]);

    fflush(stdin);
    ValiCadena(nombres, "APELLIDO NOMBRES");
    strcat(curp[3], nombres[0]);

    printf("%s", curp);
}
//********************* 