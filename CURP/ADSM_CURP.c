#include "odin.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Curp(char curp[]);
void ValidarSexo(char sexo[]);
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
            printf("%s", curp);
            printf("\n");
            system("PAUSE");
            break;
        }

    } while (op != 0);
}

//*********************
void Curp(char curp[])
{
    char nombres[30], paterno[20], materno[20], cdia[3], cmes[3], canio[3], sexo[2];
    int i, anio, mes, dia;
    int lleno;
    char caracter;
    fflush(stdin);
    ValiCadena(paterno, "APELLIDO PATERNO");
    lleno = 1;
    i = 0;

    while (lleno)
    {
        if (i == 0)
        {
            caracter = paterno[i];
            curp[0] = caracter;
        }
        else
        {
            if ((paterno[i] == 'A') || (paterno[i] == 'E') || (paterno[i] == 'I') || (paterno[i] == 'O') || (paterno[i] == 'U'))
            {
                caracter = paterno[i];
                curp[1] = caracter;
                lleno = 0;
            }
        }
        i++;
    }

    fflush(stdin);
    ValiCadena(materno, "APELLIDO MATERNO");
    caracter = materno[0];
    curp[2] = caracter;

    fflush(stdin);
    ValiCadena(nombres, "NOMBRES");
    caracter = nombres[0];
    curp[3] = caracter;

    printf("ANO DE NACIMIENTO \n(aaaa)\n");
    anio = Validar(1920, 2023);
    printf("MES DE NACIMIENTO\n");
    mes = Validar(1, 12);
    printf("DIA DE NACIMIENTO\n");
    switch (mes)
    {
    case 1:
        dia = Validar(1, 31);
        break;
    case 2:
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        {
            dia = Validar(1, 29);
        }
        dia = Validar(1, 28);
        break;
    case 3:
        dia = Validar(1, 31);
        break;
    case 4:
        dia = Validar(1, 30);
        break;
    case 5:
        dia = Validar(1, 31);
        break;
    case 6:
        dia = Validar(1, 30);
        break;
    case 7:
        dia = Validar(1, 31);
        break;
    case 8:
        dia = Validar(1, 31);
        break;
    case 9:
        dia = Validar(1, 30);
        break;
    case 10:
        dia = Validar(1, 31);
        break;
    case 11:
        dia = Validar(1, 30);
        break;
    case 12:
        dia = Validar(1, 31);
        break;
    }

    anio = anio % 100;
    sprintf(canio, "%d", anio);
    if (anio < 10)
    {
        curp[4] = '0';
        curp[5] = canio[0];
    }
    else
    {
        curp[4] = canio[0];
        curp[5] = canio[1];
    }

    sprintf(cmes, "%d", mes);
    if (mes < 10)
    {
        curp[6] = '0';
        curp[7] = cmes[0];
    }
    else
    {
        curp[6] = cmes[0];
        curp[7] = cmes[1];
    }

    sprintf(cdia, "%d", dia);
    if (mes < 10)
    {
        curp[8] = '0';
        curp[9] = cdia[0];
    }
    else
    {
        curp[8] = cdia[0];
        curp[9] = cdia[1];
    }

    printf("SEXO\n'M' o 'H'\n");
    ValidarSexo(sexo);
    curp[10] = sexo[0];

    lleno = 1;
    for (i = 1; lleno; i++)
    {
        if ((paterno[i] != 'A') && (paterno[i] != 'E') && (paterno[i] != 'I') && (paterno[i] != 'O') && (paterno[i] != 'U'))
        {
            caracter = paterno[i];
            curp[13] = caracter;
            lleno = 0;
        }
    }

    lleno = 1;
    for (i = 1; lleno; i++)
    {
        if ((materno[i] != 'A') && (materno[i] != 'E') && (materno[i] != 'I') && (materno[i] != 'O') && (materno[i] != 'U'))
        {
            caracter = materno[i];
            curp[14] = caracter;
            lleno = 0;
        }
    }

    lleno = 1;
    for (i = 1; lleno; i++)
    {
        if ((nombres[i] != 'A') && (nombres[i] != 'E') && (nombres[i] != 'I') && (nombres[i] != 'O') && (nombres[i] != 'U'))
        {
            caracter = nombres[i];
            curp[15] = caracter;
            lleno = 0;
        }
    }
}
//*********************
void ValidarSexo(char cadena[])
{
    int error;
    error = 0;
    fflush(stdin);
    gets(cadena);
    Mayusculas(cadena);
    do
    {
        if (error == 1)
        {
            system("CLS");
            printf("SOLO CARACTER 'H' O 'M', HOMBRE MUJER\n");
            system("PAUSE");
            fflush(stdin);
            gets(cadena);
            Mayusculas(cadena);
            error = 0;
        }
        if ((cadena[0] != 'M') && (cadena[0] != 'H'))
        {
            error = 1;
        }

    } while (error == 1);
}