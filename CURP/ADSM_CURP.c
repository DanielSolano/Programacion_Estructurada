#include "odin.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Curp(char curp[]);
void ValidarSexo(char sexo[], char msg[]);
void ValiApellidos(char cadena[], char msg[]);
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

void ValiApellidos(char cadena[], char msg[])
{
    int i;
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
            printf("NO NUMEROS, DOBLES ESPACIOS, INICIO Y FINAL DEBEN SER CARACTERES\n");
            system("PAUSE");
            system("CLS");
            printf("%s\n", msg);
            fflush(stdin);
            gets(cadena);
            Mayusculas(cadena);
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
                if (cadena[i] != ' ' && cadena[i] != -92 && cadena[i] != 46 && cadena[i] != 45 && cadena[i] != 47 && cadena[i] != 39 && cadena[i] != 154 && cadena[i] != 13) // Si no es un espacio y no contiene letras es caracter especial, excepto enie
                {
                    if (cadena[i] < 'A' || cadena[i] > 'Z')
                    {
                        error = 1;
                    }
                }
                if (cadena[i] == -92) // Si es enie la hace X
                {
                    cadena[i] = 'X';
                }
                if (cadena[i] == 47) // Si es /
                {
                    cadena[i] = 'X';
                }
                if (cadena[i] == 46) // Si es -
                {
                    cadena[i] = 'X';
                }
                if (cadena[i] == 39) // Si es '
                {
                    cadena[i] = 'X';
                }
                if (cadena[i] == 154) // Si es dierisis
                {
                    cadena[i] = 'U';
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
    char nombre1[50], nombre2[50], paterno[50], materno[50];
    char caracter, vocal, consonante;
    int i, joseMaria, lleno;

    // *********************** APELLIDO PATERNO *******************************
    do
    {
        system("CLS");
        ValiApellidos(paterno, "   APELLIDO PATERNO");
    } while (paterno[0] == '\0');

    Preposiciones(paterno);
    Preposiciones(paterno);
    Preposiciones(paterno);

    caracter = paterno[0];
    curp[0] = caracter;

    vocal = 0;
    lleno = 1;
    for (i = 1; lleno; i++)
    {
        if ((paterno[i] == 'A') || (paterno[i] == 'E') || (paterno[i] == 'I') || (paterno[i] == 'O') || (paterno[i] == 'U'))
        {
            caracter = paterno[i];
            curp[1] = caracter;
            vocal = 1;
            lleno = 0;
        }
        if (i == strlen(paterno))
        {
            lleno = 0;
        }
    }
    if (vocal == 0) // No tiene vocal intermedia
    {
        curp[1] = 'X';
    }

    consonante = 0;
    lleno = 1;
    for (i = 1; lleno; i++)
    {
        if ((paterno[i] != 'A') && (paterno[i] != 'E') && (paterno[i] != 'I') && (paterno[i] != 'O') && (paterno[i] != 'U'))
        {
            caracter = paterno[i];
            curp[13] = caracter;
            consonante = 1;
            lleno = 0;
        }
        if (i == strlen(paterno))
        {
            lleno = 0;
        }
    }
    if (consonante == 0) // No tiene consonante intermedia
    {
        curp[13] = 'X';
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
        consonante = 0;
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if ((materno[i] != 'A') && (materno[i] != 'E') && (materno[i] != 'I') && (materno[i] != 'O') && (materno[i] != 'U'))
            {
                caracter = materno[i];
                curp[14] = caracter;
                consonante = 1;
                lleno = 0;
            }
            if (i == strlen(materno))
            {
                lleno = 0;
            }
        }
        if (consonante == 0)
        {
            curp[14] = 'X';
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

    consonante = 0;
    if (strlen(nombre2) == 0) // Si no es compuesto
    {
        caracter = nombre1[0];
        curp[3] = caracter;
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if ((nombre1[i] != 'A') && (nombre1[i] != 'E') && (nombre1[i] != 'I') && (nombre1[i] != 'O') && (nombre1[i] != 'U'))
            {
                caracter = nombre1[i];
                curp[15] = caracter;
                consonante = 1;
                lleno = 0;
            }
            if (i == strlen(nombre1))
            {
                lleno = 0;
            }
        }
    }
    else // Si es compuesto
    {

        joseMaria = JoseMaria(nombre1);
        if (joseMaria) // Si es jose o maria tomamos su segundo nombre
        {

            Preposiciones(nombre2);
            Preposiciones(nombre2);
            Preposiciones(nombre2);
            caracter = nombre2[0];
            curp[3] = caracter;
            lleno = 1;
            for (i = 1; lleno; i++)
            {
                if ((nombre2[i] != 'A') && (nombre2[i] != 'E') && (nombre2[i] != 'I') && (nombre2[i] != 'O') && (nombre2[i] != 'U'))
                {
                    caracter = nombre2[i];
                    curp[15] = caracter;
                    consonante = 1;
                    lleno = 0;
                }
                if (i == strlen(nombre2))
                {
                    lleno = 0;
                }
            }
        }
        else // No es Jose o Maria usamos su primer nombre
        {
            caracter = nombre1[0];
            curp[3] = caracter;
            lleno = 1;
            for (i = 1; lleno; i++)
            {
                if ((nombre1[i] != 'A') && (nombre1[i] != 'E') && (nombre1[i] != 'I') && (nombre1[i] != 'O') && (nombre1[i] != 'U'))
                {
                    caracter = nombre1[i];
                    curp[15] = caracter;
                    consonante = 1;
                    lleno = 0;
                }
                if (i == strlen(nombre1))
                {
                    lleno = 0;
                }
            }
        }
    }
    if (consonante == 0)
    {
        curp[15] = 'X';
    }
}

int JoseMaria(char primernombre[])
{
    char JoseMaria[8][5] = {"JOSE", "JX", "J", "MARIA", "MAX", "MA", "MX", "M"};
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