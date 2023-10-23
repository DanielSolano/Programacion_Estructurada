#include "odin.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Curp(char curp[]);
void ValidarSexo(char sexo[], char msg[]);
void ValiApellidos(unsigned char cadena[], char msg[]);
void Estados(char curp[]);
void FechaNac(char curp[]);
void Nombres(char curp[]);
void Preposiciones(char nombres[]);
void Sexo(char curp[]);
int JoseMaria(char primernombre[]);
void Inconvenientes(char curp[]);

int main()
{
    menu();

    return 0;
}

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

void menu()
{
    srand(time(NULL));
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
            system("CLS");
            printf("    TU CURP\n");
            printf("%s", curp);
            printf("\n");
            system("PAUSE");
            break;
        }

    } while (op != 0);
}

void Curp(char curp[])
{
    char cultimo[2];
    int ultimo;
    char caracter;
    Nombres(curp);
    FechaNac(curp);
    Sexo(curp);
    Estados(curp);
    Inconvenientes(curp);

    ultimo = NumAleatorio(1, 5);
    sprintf(cultimo, "%d", ultimo);
    caracter = cultimo[0];
    curp[17] = caracter;
}

void ValidarSexo(char cadena[], char msg[])
{
    int error;
    error = 0;
    printf("%s\n", msg);
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

void ValiApellidos(unsigned char cadena[], char msg[])
{
    int i;
    int error;
    error = 0;
    printf("%s\n", msg);
    fflush(stdin);
    gets(cadena);
    Mayusculas(cadena);
    if (cadena == "MAX")
    {
        cadena = "MAXX";
    }
    do
    {
        if (error == 1)
        {
            printf("NO NUMEROS, DOBLES ESPACIOS, INICIO Y FINAL DEBEN SER CARACTERES\n");
            system("PAUSE");
            system("CLS");
            printf("%s\n", msg);
            fflush(stdin);
            gets(cadena);
            Mayusculas(cadena);
            if (cadena == "MAX")
            {
                cadena = "MAXX";
            }
            error = 0;
        }
        if (cadena[0] != 13)
        {
            for (i = 0; cadena[i] != '\0'; i++)
            {
                if (cadena[i] >= '0' && cadena[i] <= '9') // Son numeros
                {
                    error = 1;
                }
                if ((cadena[i] == ' ') && (cadena[i + 1] == ' ')) // Doble espacio vacio
                {
                    error = 1;
                }
                if ((cadena[i] != ' ') && (cadena[i] < 'A') || (cadena[i] > 'Z')) // Excepeciones de caracteres especiales
                {
                    if (cadena[i] == 164) // Ñ la hace X
                    {
                        cadena[i] = 'X';
                    }
                    else
                    {
                        if (cadena[i] == 239) // Si es ´
                        {
                            cadena[i] = 64;
                        }
                        else
                        {

                            if (cadena[i] == 47) // Si es /
                            {
                                cadena[i] = 64;
                            }
                            else
                            {
                                if (cadena[i] == 46) // Si es .
                                {
                                    cadena[i] = 'X';
                                }
                                else
                                {
                                    if (cadena[i] == 39) // Si es '
                                    {
                                        cadena[i] = 64;
                                    }
                                    else
                                    {
                                        if (cadena[i] == 154) // U dierisis
                                        {
                                            cadena[i] = 'U';
                                        }
                                        else
                                        {
                                            if (cadena[i] == 153) // O dierisis
                                            {
                                                cadena[i] = 'U';
                                            }
                                            else
                                            {
                                                if (cadena[i] == 216) // I dierisis
                                                {
                                                    cadena[i] = 'U';
                                                }
                                                else
                                                {
                                                    if (cadena[i] == 211) // E dierisis
                                                    {
                                                        cadena[i] = 'U';
                                                    }
                                                    else
                                                    {
                                                        if (cadena[i] == 142) // A dierisis
                                                        {
                                                            cadena[i] = 'A';
                                                        }
                                                        else
                                                        {
                                                            if (cadena[i] == 129) // U dierisis
                                                            {
                                                                cadena[i] = 'U';
                                                            }
                                                            else
                                                            {
                                                                if (cadena[i] == 148) // O dierisis
                                                                {
                                                                    cadena[i] = 'U';
                                                                }
                                                                else
                                                                {
                                                                    if (cadena[i] == 139) // I dierisis
                                                                    {
                                                                        cadena[i] = 'U';
                                                                    }
                                                                    else
                                                                    {
                                                                        if (cadena[i] == 137) // E dierisis
                                                                        {
                                                                            cadena[i] = 'U';
                                                                        }
                                                                        else
                                                                        {
                                                                            if (cadena[i] == 132) // A dierisis
                                                                            {
                                                                                cadena[i] = 'A';
                                                                            }
                                                                            else
                                                                            {
                                                                                if (cadena[i] == 181) // A acentuada
                                                                                {
                                                                                    cadena[i] = 'A';
                                                                                }
                                                                                else
                                                                                {
                                                                                    if (cadena[i] == 144) // E acentuada
                                                                                    {
                                                                                        cadena[i] = 'E';
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if (cadena[i] == 214) // I acentuada
                                                                                        {
                                                                                            cadena[i] = 'I';
                                                                                        }
                                                                                        else
                                                                                        {
                                                                                            if (cadena[i] == 224) // O acentuada
                                                                                            {
                                                                                                cadena[i] = 'O';
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                if (cadena[i] == 233) // U acentuada
                                                                                                {
                                                                                                    cadena[i] = 'U';
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    if (cadena[i] == 160) // A acentuada
                                                                                                    {
                                                                                                        cadena[i] = 'A';
                                                                                                    }
                                                                                                    else
                                                                                                    {
                                                                                                        if (cadena[i] == 130) // E acentuada
                                                                                                        {
                                                                                                            cadena[i] = 'E';
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                            if (cadena[i] == 161) // I acentuada
                                                                                                            {
                                                                                                                cadena[i] = 'I';
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                                if (cadena[i] == 162) // O acentuada
                                                                                                                {
                                                                                                                    cadena[i] = 'O';
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                    if (cadena[i] == 163) // U acentuada
                                                                                                                    {
                                                                                                                        cadena[i] = 'U';
                                                                                                                    }
                                                                                                                    else
                                                                                                                    {
                                                                                                                        if (cadena[i] == 45)
                                                                                                                        {
                                                                                                                            cadena[i] = 64;
                                                                                                                        }
                                                                                                                        else
                                                                                                                        {
                                                                                                                            error = 1;
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (cadena[i - 1] == ' ')
            {
                error = 1;
            }
            if (cadena[0] == ' ') // Empieza en espacio
            {
                error = 1;
            }
        }
    } while (error == 1);
}

void Estados(char curp[])
{
    int estado, i;
    char caracter;
    char nombres_estados[33][30] = {"AGUASCALIENTES", "BAJA CALIFORNIA", "BAJA CALIFORNIA SUR", "CAMPECHE", "CHIAPAS", "CHIHUAHUA", "COAHUILA", "COLIMA", "CIUDAD DE MEXICO", "DURANGO", "GUANAJUATO", "GUERRERO", "HIDALGO", "JALISCO", "MEXICO", "MICHOACAN", "MORELOS", "NAYARIT", "NUEVO LEON", "OAXACA", "PUEBLA", "QUERETARO", "QUINTANA ROO", "SAN LUIS POTOSI", "SINALOA", "SONORA", "TABASCO", "TAMAULIPAS", "TLAXCALA", "VERACRUZ", "YUCATAN", "ZACATECAS", "NACIDO EN EL EXTRANJERO"};
    char estados[33][3] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};
    system("CLS");
    printf("    ESTADO DE NACIMIENTO\n");
    for (i = 0; i < 33; i++)
    {
        printf("%d.- %s\n", i + 1, nombres_estados[i]);
    }
    printf("SELECCIONA UNA OPCION: \n");
    estado = Validar(1, 33);
    caracter = estados[estado - 1][0];
    curp[11] = caracter;
    caracter = estados[estado - 1][1];
    curp[12] = caracter;
}

void FechaNac(char curp[])
{
    int anio, mes, dia;
    char cdia[3], cmes[3], canio[3];
    system("CLS");
    printf("   ANO DE NACIMIENTO  (aaaa)\n");
    anio = Validar(1920, 2023);
    system("CLS");
    printf("    MES DE NACIMIENTO  (mm)\n");
    mes = Validar(1, 12);
    system("CLS");
    printf("    DIA DE NACIMIENTO (dd)\n");
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
        else
        {
            dia = Validar(1, 28);
        }
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
    if (dia < 10)
    {
        curp[8] = '0';
        curp[9] = cdia[0];
    }
    else
    {
        curp[8] = cdia[0];
        curp[9] = cdia[1];
    }

    if (anio <= 23)
    {
        curp[16] = 'A';
    }
    else
    {
        curp[16] = '0';
    }
}

void Sexo(char curp[])
{
    char sexo[2];
    system("CLS");
    ValidarSexo(sexo, "    SEXO 'H'|'M'");
    curp[10] = sexo[0];
}

void Nombres(char curp[])
{
    char nombre1[50], nombre2[50], nombre3[50], nombre4[50], paterno[50], materno[50];
    char caracter;
    int i, joseMaria, lleno;

    // *********************** APELLIDO PATERNO *******************************

    system("CLS");
    ValiApellidos(paterno, "   APELLIDO PATERNO");

    if (strlen(paterno) == 0)
    {
        curp[0] = 'X';
        curp[1] = 'X';
        curp[13] = 'X';
    }
    else
    {

        Preposiciones(paterno);
        Preposiciones(paterno);
        Preposiciones(paterno);

        caracter = paterno[0];
        curp[0] = caracter;
        if (paterno[0] == 64)
        {
            curp[0] = 'X';
        }

        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if ((paterno[i] == 'A') || (paterno[i] == 'E') || (paterno[i] == 'I') || (paterno[i] == 'O') || (paterno[i] == 'U'))
            {
                if (paterno[i - 1] == 64)
                {
                    curp[1] = 'X';
                }
                else
                {
                    caracter = paterno[i];
                    curp[1] = caracter;
                }
                lleno = 0;
            }
            if (i == strlen(paterno))
            {
                lleno = 0;
                curp[1] = 'X';
            }
        }

        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if (paterno[i] != 64)
            {
                if ((paterno[i] != 'A') && (paterno[i] != 'E') && (paterno[i] != 'I') && (paterno[i] != 'O') && (paterno[i] != 'U'))
                {
                    if (paterno[i - 1] == 64)
                    {
                        curp[13] = 'X';
                    }
                    else
                    {
                        caracter = paterno[i];
                        curp[13] = caracter;
                    }
                    lleno = 0;
                }
            }
            if (i == strlen(paterno))
            {
                lleno = 0;
                curp[13] = 'X';
            }
        }
    }
    // *********************** APELLIDO MATERNO *******************************

    system("CLS");
    ValiApellidos(materno, "   APELLIDO MATERNO");

    if (strlen(materno) == 0) // Si no tiene apellido materno
    {
        curp[2] = 'X';
        curp[14] = 'X';
    }
    else // Tiene apellido materno
    {

        Preposiciones(materno);
        Preposiciones(materno);
        Preposiciones(materno);
        caracter = materno[0];
        curp[2] = caracter;
        if (materno[0] == 64)
        {
            curp[2] = 'X';
        }
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if (materno[i] != 64)
            {
                if ((materno[i] != 'A') && (materno[i] != 'E') && (materno[i] != 'I') && (materno[i] != 'O') && (materno[i] != 'U'))
                {
                    if (materno[i - 1] == 64)
                    {
                        curp[14] = 'X';
                    }
                    else
                    {
                        caracter = materno[i];
                        curp[14] = caracter;
                    }
                    lleno = 0;
                }
            }
            if (i == strlen(materno))
            {
                lleno = 0;
                curp[14] = 'X';
            }
        }
    }

    // *********************** NOMBRES *******************************
    do
    {
        system("CLS");
        ValiApellidos(nombre1, "   PRIMER NOMBRE");
    } while (nombre1[0] == '\0');

    Preposiciones(nombre1);
    Preposiciones(nombre1);
    Preposiciones(nombre1);

    system("CLS");
    ValiApellidos(nombre2, "   SEGUNDO NOMBRE");

    Preposiciones(nombre2);
    Preposiciones(nombre2);
    Preposiciones(nombre2);

    system("CLS");
    ValiApellidos(nombre3, "   TERCER NOMBRE");

    Preposiciones(nombre3);
    Preposiciones(nombre3);
    Preposiciones(nombre3);

    system("CLS");
    ValiApellidos(nombre4, "   CUARTO NOMBRE");
    Preposiciones(nombre4);
    Preposiciones(nombre4);
    Preposiciones(nombre4);

    if (strlen(nombre2) == 0) // Si no es compuesto
    {

        caracter = nombre1[0];
        curp[3] = caracter;
        if (nombre1[0] == 64)
        {
            curp[3] = 'X';
        }
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if (nombre1[i] != 64)
            {
                if ((nombre1[i] != 'A') && (nombre1[i] != 'E') && (nombre1[i] != 'I') && (nombre1[i] != 'O') && (nombre1[i] != 'U'))
                {
                    if (nombre1[i - 1] == 64)
                    {
                        curp[15] = 'X';
                    }
                    else
                    {
                        caracter = nombre1[i];
                        curp[15] = caracter;
                    }
                    lleno = 0;
                }
            }
            if (i == strlen(nombre1))
            {
                lleno = 0;
                curp[15] = 'X';
            }
        }
    }
    else // Si es compuesto
    {
        joseMaria = JoseMaria(nombre1);
        if (joseMaria) // Si es jose o maria tomamos su segundo nombre
        {
            system("pause");
            if (strlen(nombre3) != 0)
            {
                joseMaria = JoseMaria(nombre2);
                if (joseMaria)
                {
                    system("pause");
                    if (strlen(nombre4) != 0)
                    {
                        joseMaria = JoseMaria(nombre3);
                        if (joseMaria)
                        {
                            printf("%s", nombre4);
                            system("pause");
                            caracter = nombre4[0];
                            curp[3] = caracter;
                            if (nombre4[0] == 64)
                            {
                                curp[3] = 'X';
                            }
                            lleno = 1;
                            for (i = 1; lleno; i++)
                            {
                                if (nombre4[i] != 64)
                                {
                                    if ((nombre4[i] != 'A') && (nombre4[i] != 'E') && (nombre4[i] != 'I') && (nombre4[i] != 'O') && (nombre4[i] != 'U'))
                                    {
                                        if (nombre4[i - 1] == 64)
                                        {
                                            curp[15] = 'X';
                                        }
                                        else
                                        {
                                            caracter = nombre4[i];
                                            curp[15] = caracter;
                                        }
                                        lleno = 0;
                                    }
                                }
                                if (i == strlen(nombre4))
                                {
                                    lleno = 0;
                                    curp[15] = 'X';
                                }
                            }
                        }
                        else
                        {
                            caracter = nombre3[0];
                            curp[3] = caracter;
                            if (nombre3[0] == 64)
                            {
                                curp[3] = 'X';
                            }
                            lleno = 1;
                            for (i = 1; lleno; i++)
                            {
                                if (nombre3[i] != 64)
                                {
                                    if ((nombre3[i] != 'A') && (nombre3[i] != 'E') && (nombre3[i] != 'I') && (nombre3[i] != 'O') && (nombre3[i] != 'U'))
                                    {
                                        if (nombre3[i - 1] == 64)
                                        {
                                            curp[15] = 'X';
                                        }
                                        else
                                        {
                                            caracter = nombre3[i];
                                            curp[15] = caracter;
                                        }
                                        lleno = 0;
                                    }
                                }
                                if (i == strlen(nombre3))
                                {
                                    lleno = 0;
                                    curp[15] = 'X';
                                }
                            }
                        }
                    }
                    else
                    {
                        caracter = nombre3[0];
                        curp[3] = caracter;
                        if (nombre3[0] == 64)
                        {
                            curp[3] = 'X';
                        }
                        lleno = 1;
                        for (i = 1; lleno; i++)
                        {
                            if (nombre3[i] != 64)
                            {
                                if ((nombre3[i] != 'A') && (nombre3[i] != 'E') && (nombre3[i] != 'I') && (nombre3[i] != 'O') && (nombre3[i] != 'U'))
                                {
                                    if (nombre3[i - 1] == 64)
                                    {
                                        curp[15] = 'X';
                                    }
                                    else
                                    {
                                        caracter = nombre3[i];
                                        curp[15] = caracter;
                                    }
                                    lleno = 0;
                                }
                            }
                            if (i == strlen(nombre3))
                            {
                                lleno = 0;
                                curp[15] = 'X';
                            }
                        }
                    }
                }
                else
                {
                    caracter = nombre2[0];
                    curp[3] = caracter;
                    if (nombre2[0] == 64)
                    {
                        curp[3] = 'X';
                    }
                    lleno = 1;
                    for (i = 1; lleno; i++)
                    {
                        if (nombre2[i] != 64)
                        {
                            if ((nombre2[i] != 'A') && (nombre2[i] != 'E') && (nombre2[i] != 'I') && (nombre2[i] != 'O') && (nombre2[i] != 'U'))
                            {
                                if (nombre2[i - 1] == 64)
                                {
                                    curp[15] = 'X';
                                }
                                else
                                {
                                    caracter = nombre2[i];
                                    curp[15] = caracter;
                                }
                                lleno = 0;
                            }
                        }
                        if (i == strlen(nombre2))
                        {
                            lleno = 0;
                            curp[15] = 'X';
                        }
                    }
                }
            }
            else
            {
                caracter = nombre2[0];
                curp[3] = caracter;
                if (nombre2[0] == 64)
                {
                    curp[3] = 'X';
                }
                lleno = 1;
                for (i = 1; lleno; i++)
                {
                    if (nombre2[i] != 64)
                    {
                        if ((nombre2[i] != 'A') && (nombre2[i] != 'E') && (nombre2[i] != 'I') && (nombre2[i] != 'O') && (nombre2[i] != 'U'))
                        {
                            if (nombre2[i - 1] == 64)
                            {
                                curp[15] = 'X';
                            }
                            else
                            {
                                caracter = nombre2[i];
                                curp[15] = caracter;
                            }
                            lleno = 0;
                        }
                    }
                    if (i == strlen(nombre2))
                    {
                        lleno = 0;
                        curp[15] = 'X';
                    }
                }
            }
        }
        else // No es Jose o Maria usamos su primer nombre
        {
            caracter = nombre1[0];
            curp[3] = caracter;
            if (nombre1[0] == 64)
            {
                curp[3] = 'X';
            }
            lleno = 1;
            for (i = 1; lleno; i++)
            {
                if (nombre1[i] != 64)
                {
                    if ((nombre1[i] != 'A') && (nombre1[i] != 'E') && (nombre1[i] != 'I') && (nombre1[i] != 'O') && (nombre1[i] != 'U'))
                    {
                        if (nombre1[i - 1] == 64)
                        {
                            curp[15] = 'X';
                        }
                        else
                        {
                            caracter = nombre1[i];
                            curp[15] = caracter;
                        }
                        lleno = 0;
                    }
                }
                if (i == strlen(nombre1))
                {
                    lleno = 0;
                    curp[15] = 'X';
                }
            }
        }
    }
}

int JoseMaria(char primernombre[])
{
    char JoseMaria[8][6] = {"JOSE", "JX", "J", "MARIA", "MAX", "MA", "MX", "M"};
    int i;
    for (i = 0; i < 8; i++)
    {
        if (strcmp(primernombre, JoseMaria[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

void Inconvenientes(char curp[])
{
    char inconvenientes[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    char comparar[4];
    int i;
    strncat(comparar, curp, 4);
    for (i = 0; i < 81; i++)
    {
        if (strcmp(comparar, inconvenientes[i]) == 0)
        {
            curp[1] = 'X';
        }
    }
}

void Preposiciones(char nombres[])
{
    int i, j;

    char TresCar[10][5] = {"DAS ", "DEL ", "DER ", "DIE ", "LOS ", "LAS ", "LES ", "MAC ", "VAN ", "VON "};
    char DosCar[8][4] = {"DA ", "DE ", "DI ", "DD ", "EL ", "LA ", "LE ", "MC "};
    char UnCar[1][3] = {"Y "};

    i = 0;
    if (strncmp(nombres, UnCar[i], 2) == 0)
    {
        i = 2;
        for (j = 0; j < strlen(nombres) - 2; j++)
        {
            nombres[j] = nombres[i++];
        }
        nombres[j] = '\0';
    }

    for (i = 0; i < 10; i++)
    {
        if (strncmp(nombres, TresCar[i], 4) == 0)
        {
            i = 4;
            for (j = 0; j < strlen(nombres) - 4; j++)
            {
                nombres[j] = nombres[i++];
            }
            nombres[j] = '\0';
        }
    }

    for (i = 0; i < 8; i++)
    {
        if (strncmp(nombres, DosCar[i], 3) == 0)
        {
            i = 3;
            for (j = 0; j < strlen(nombres) - 3; j++)
            {
                nombres[j] = nombres[i++];
            }
            nombres[j] = '\0';
        }
    }
}