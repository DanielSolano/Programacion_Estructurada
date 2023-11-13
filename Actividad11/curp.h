typedef struct _nombres
{
    unsigned char ApPat[30];
    unsigned char ApMat[30];
    unsigned char Nombre1[30];
    unsigned char Nombre2[30];
    unsigned char Nombre3[30];
} TNombre;

typedef struct _nacim
{
    int anio;
    int mes;
    int dia;
    int edad;
} TNombres;

typedef struct _reg
{
    int Status;
    int key;
    int Matricula;
    TNombre Persona;
    TNombres Nacimiento;
    char Estado[20];
    char Sexo[2];
    char Curp[19];
} TReg;

//****************** PROTOTIPOS ***********************************
TReg ValidarSexo(TReg Nombres, char msg[]);
void ValiApellidos(unsigned char cadena[], char msg[]);
TReg Estados(TReg Nombres);
TReg Nombres(TReg Nombres);
void Preposiciones(char nombres[]);
TReg Sexo(TReg Nombres);
int JoseMaria(char primernombre[]);
TReg Inconvenientes(TReg Nombres);
TReg AutoCurp(TReg Nombres);
// *****************************************************************
TReg AutoCurp(TReg Nombres)
{
    int i, joseMaria, lleno, anio, mes, dia, ultimo;
    char caracter;
    char cdia[3], cmes[3], canio[3], Nombre1[30], Nombre2[30], ApPat[30], ApMat[30], comparar[4], cultimo[2];
    char estados[33][3] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DF", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "NE"};
    char inconvenientes[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    caracter = Nombres.Persona.ApPat[0];
    Nombres.Curp[0] = caracter;

    strcpy(Nombre1, Nombres.Persona.Nombre1);
    strcpy(Nombre2, Nombres.Persona.Nombre2);
    strcpy(ApPat, Nombres.Persona.ApPat);
    strcpy(ApMat, Nombres.Persona.ApMat);
    lleno = 1;
    // *********************** APELLIDO PATERNO *******************************
    for (i = 1; lleno; i++)
    {
        if ((ApPat[i] == 'A') || (ApPat[i] == 'E') || (ApPat[i] == 'I') || (ApPat[i] == 'O') || (ApPat[i] == 'U'))
        {

            caracter = ApPat[i];
            Nombres.Curp[1] = caracter;
            lleno = 0;
        }
        if (i == strlen(ApPat))
        {
            lleno = 0;
            Nombres.Curp[1] = 'X';
        }
    }
    lleno = 1;
    for (i = 1; lleno; i++)
    {

        if ((ApPat[i] != 'A') && (ApPat[i] != 'E') && (ApPat[i] != 'I') && (ApPat[i] != 'O') && (ApPat[i] != 'U'))
        {

            caracter = ApPat[i];
            Nombres.Curp[13] = caracter;
            lleno = 0;
        }
        if (i == strlen(ApPat))
        {
            lleno = 0;
            Nombres.Curp[13] = 'X';
        }
    }

    // *********************** APELLIDO MATERNO *******************************

    caracter = ApMat[0];
    Nombres.Curp[2] = caracter;
    lleno = 1;
    for (i = 1; lleno; i++)
    {

        if ((ApMat[i] != 'A') && (ApMat[i] != 'E') && (ApMat[i] != 'I') && (ApMat[i] != 'O') && (ApMat[i] != 'U'))
        {

            caracter = ApMat[i];
            Nombres.Curp[14] = caracter;
            lleno = 0;
        }

        if (i == strlen(ApMat))
        {
            lleno = 0;
            Nombres.Curp[14] = 'X';
        }
    }

    // *********************** NOMBRES *******************************

    if (strlen(Nombre2) == 0) // Si no es compuesto
    {

        caracter = Nombre1[0];
        Nombres.Curp[3] = caracter;
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if ((Nombre1[i] != 'A') && (Nombre1[i] != 'E') && (Nombre1[i] != 'I') && (Nombre1[i] != 'O') && (Nombre1[i] != 'U'))
            {

                caracter = Nombre1[i];
                Nombres.Curp[15] = caracter;
                lleno = 0;
            }
            if (i == strlen(Nombre1))
            {
                lleno = 0;
                Nombres.Curp[15] = 'X';
            }
        }
    }
    else // Si es compuesto
    {
        joseMaria = JoseMaria(Nombre1);
        if (joseMaria) // Si es jose o maria tomamos su segundo nombre
        {

            caracter = Nombre2[0];
            Nombres.Curp[3] = caracter;
            lleno = 1;
            for (i = 1; lleno; i++)
            {

                if ((Nombre2[i] != 'A') && (Nombre2[i] != 'E') && (Nombre2[i] != 'I') && (Nombre2[i] != 'O') && (Nombre2[i] != 'U'))
                {

                    caracter = Nombre2[i];
                    Nombres.Curp[15] = caracter;
                    lleno = 0;
                }
                if (i == strlen(Nombre2))
                {
                    lleno = 0;
                    Nombres.Curp[15] = 'X';
                }
            }
        }
        else // No es Jose o Maria usamos su primer nombre
        {
            caracter = Nombre1[0];
            Nombres.Curp[3] = caracter;
            lleno = 1;
            for (i = 1; lleno; i++)
            {

                if ((Nombre1[i] != 'A') && (Nombre1[i] != 'E') && (Nombre1[i] != 'I') && (Nombre1[i] != 'O') && (Nombre1[i] != 'U'))
                {

                    caracter = Nombre1[i];
                    Nombres.Curp[15] = caracter;
                    lleno = 0;
                }
                if (i == strlen(Nombre1))
                {
                    lleno = 0;
                    Nombres.Curp[15] = 'X';
                }
            }
        }
    }
    // *********************** FECHA DE NACIMIENTO *******************************

    anio = Nombres.Nacimiento.anio;
    mes = Nombres.Nacimiento.mes;
    dia = Nombres.Nacimiento.dia;
    anio = anio % 100;
    sprintf(canio, "%d", anio);
    if (anio < 10)
    {
        Nombres.Curp[4] = '0';
        Nombres.Curp[5] = canio[0];
    }
    else
    {
        Nombres.Curp[4] = canio[0];
        Nombres.Curp[5] = canio[1];
    }

    sprintf(cmes, "%d", mes);
    if (mes < 10)
    {
        Nombres.Curp[6] = '0';
        Nombres.Curp[7] = cmes[0];
    }
    else
    {
        Nombres.Curp[6] = cmes[0];
        Nombres.Curp[7] = cmes[1];
    }

    sprintf(cdia, "%d", dia);
    if (dia < 10)
    {
        Nombres.Curp[8] = '0';
        Nombres.Curp[9] = cdia[0];
    }
    else
    {
        Nombres.Curp[8] = cdia[0];
        Nombres.Curp[9] = cdia[1];
    }
    if (anio <= 23)
    {
        Nombres.Curp[16] = 'A';
    }
    else
    {
        Nombres.Curp[16] = '0';
    }

    // *********************** SEXO *******************************

    Nombres.Curp[10] = Nombres.Sexo[0];

    // *********************** ESTADO *******************************

    caracter = Nombres.Estado[0];
    Nombres.Curp[11] = caracter;
    caracter = Nombres.Estado[1];
    Nombres.Curp[12] = caracter;

    // *********************** ANTISONANTES *******************************
    strncat(comparar, Nombres.Curp, 4);
    for (i = 0; i < 81; i++)
    {
        if (strcmp(comparar, inconvenientes[i]) == 0)
        {
            Nombres.Curp[1] = 'X';
        }
    }
    ultimo = NumAleatorio(1, 5);
    sprintf(cultimo, "%d", ultimo);
    caracter = cultimo[0];
    Nombres.Curp[17] = caracter;
    Nombres.Curp[18] = '\0';
    return Nombres;
}

TReg ValidarSexo(TReg Nombres, char msg[])
{
    int error;
    error = 0;
    printf("%s\n", msg);
    fflush(stdin);
    gets(Nombres.Sexo);
    Mayusculas(Nombres.Sexo);
    do
    {
        if (error == 1)
        {
            system("CLS");
            printf("SOLO CARACTER 'H' O 'M', HOMBRE MUJER\n");
            system("PAUSE");
            fflush(stdin);
            gets(Nombres.Sexo);
            Mayusculas(Nombres.Sexo);
            error = 0;
        }
        if ((Nombres.Sexo[0] != 'M') && (Nombres.Sexo[0] != 'H'))
        {
            error = 1;
        }

    } while (error == 1);
    return Nombres;
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
                if (((cadena[i] != ' ') && (cadena[i] < 'A')) || (cadena[i] > 'Z')) // Excepeciones de caracteres especiales
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

TReg Estados(TReg Nombres)
{
    int i, estado;
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
    Nombres.Curp[11] = caracter;
    caracter = estados[estado - 1][1];
    Nombres.Curp[12] = caracter;
    strcpy(Nombres.Estado, nombres_estados[estado - 1]);
    return Nombres;
}

TReg FechaNac(TReg Nombres)
{
    int anio, mes, dia;
    char cdia[3], cmes[3], canio[3];
    system("CLS");
    printf("   ANO DE NACIMIENTO  (aaaa)\n");
    Nombres.Nacimiento.anio = Validar(1920, 2023);
    system("CLS");
    printf("    MES DE NACIMIENTO  (mm)\n");
    Nombres.Nacimiento.mes = Validar(1, 12);
    system("CLS");
    printf("    DIA DE NACIMIENTO (dd)\n");
    switch (mes)
    {
    case 1:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    case 2:
        if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
        {
            Nombres.Nacimiento.dia = Validar(1, 29);
        }
        else
        {
            Nombres.Nacimiento.dia = Validar(1, 28);
        }
        break;
    case 3:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    case 4:
        Nombres.Nacimiento.dia = Validar(1, 30);
        break;
    case 5:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    case 6:
        Nombres.Nacimiento.dia = Validar(1, 30);
        break;
    case 7:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    case 8:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    case 9:
        Nombres.Nacimiento.dia = Validar(1, 30);
        break;
    case 10:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    case 11:
        Nombres.Nacimiento.dia = Validar(1, 30);
        break;
    case 12:
        Nombres.Nacimiento.dia = Validar(1, 31);
        break;
    }

    anio = Nombres.Nacimiento.anio;
    mes = Nombres.Nacimiento.mes;
    dia = Nombres.Nacimiento.dia;

    anio = anio % 100;
    sprintf(canio, "%d", anio);
    if (anio < 10)
    {
        Nombres.Curp[4] = '0';
        Nombres.Curp[5] = canio[0];
    }
    else
    {
        Nombres.Curp[4] = canio[0];
        Nombres.Curp[5] = canio[1];
    }

    sprintf(cmes, "%d", mes);
    if (mes < 10)
    {
        Nombres.Curp[6] = '0';
        Nombres.Curp[7] = cmes[0];
    }
    else
    {
        Nombres.Curp[6] = cmes[0];
        Nombres.Curp[7] = cmes[1];
    }

    sprintf(cdia, "%d", dia);
    if (dia < 10)
    {
        Nombres.Curp[8] = '0';
        Nombres.Curp[9] = cdia[0];
    }
    else
    {
        Nombres.Curp[8] = cdia[0];
        Nombres.Curp[9] = cdia[1];
    }

    if (anio <= 23)
    {
        Nombres.Curp[16] = 'A';
    }
    else
    {
        Nombres.Curp[16] = '0';
    }
    return Nombres;
}

TReg Sexo(TReg Nombres)
{
    system("CLS");
    Nombres = ValidarSexo(Nombres, "    SEXO 'H'|'M'");
    Nombres.Curp[10] = Nombres.Sexo[0];
    return Nombres;
}

TReg Nombres(TReg Nombres)
{
    int i, joseMaria, lleno;
    char caracter;
    char Nombre1[30], Nombre2[15], Nombre3[15], ApPat[30], ApMat[30];
    // *********************** APELLIDO PATERNO *******************************
    system("CLS");
    ValiApellidos(Nombres.Persona.ApPat, "   APELLIDO PATERNO");
    strcpy(ApPat, Nombres.Persona.ApPat);

    if (strlen(ApPat) == 0)
    {
        Nombres.Curp[0] = 'X';
        Nombres.Curp[1] = 'X';
        Nombres.Curp[13] = 'X';
    }
    else
    {

        Preposiciones(ApPat);
        Preposiciones(ApPat);
        Preposiciones(ApPat);

        caracter = ApPat[0];
        Nombres.Curp[0] = caracter;
        if (ApPat[0] == 64)
        {
            Nombres.Curp[0] = 'X';
        }

        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if ((ApPat[i] == 'A') || (ApPat[i] == 'E') || (ApPat[i] == 'I') || (ApPat[i] == 'O') || (ApPat[i] == 'U'))
            {
                if (ApPat[i - 1] == 64)
                {
                    Nombres.Curp[1] = 'X';
                }
                else
                {
                    caracter = ApPat[i];
                    Nombres.Curp[1] = caracter;
                }
                lleno = 0;
            }
            if (i == strlen(ApPat))
            {
                lleno = 0;
                Nombres.Curp[1] = 'X';
            }
        }

        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if (ApPat[i] != 64)
            {
                if ((ApPat[i] != 'A') && (ApPat[i] != 'E') && (ApPat[i] != 'I') && (ApPat[i] != 'O') && (ApPat[i] != 'U'))
                {
                    if (ApPat[i - 1] == 64)
                    {
                        Nombres.Curp[13] = 'X';
                    }
                    else
                    {
                        caracter = ApPat[i];
                        Nombres.Curp[13] = caracter;
                    }
                    lleno = 0;
                }
            }
            if (i == strlen(ApPat))
            {
                lleno = 0;
                Nombres.Curp[13] = 'X';
            }
        }
    }
    // *********************** APELLIDO MATERNO *******************************

    system("CLS");
    ValiApellidos(Nombres.Persona.ApMat, "   APELLIDO MATERNO");
    strcpy(ApMat, Nombres.Persona.ApMat);

    if (strlen(ApMat) == 0) // Si no tiene apellido materno
    {
        Nombres.Curp[2] = 'X';
        Nombres.Curp[14] = 'X';
    }
    else // Tiene apellido materno
    {

        Preposiciones(ApMat);
        Preposiciones(ApMat);
        Preposiciones(ApMat);
        caracter = ApMat[0];
        Nombres.Curp[2] = caracter;
        if (ApMat[0] == 64)
        {
            Nombres.Curp[2] = 'X';
        }
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if (ApMat != 64)
            {
                if ((ApMat[i] != 'A') && (ApMat[i] != 'E') && (ApMat[i] != 'I') && (ApMat[i] != 'O') && (ApMat[i] != 'U'))
                {
                    if (ApMat[i - 1] == 64)
                    {
                        Nombres.Curp[14] = 'X';
                    }
                    else
                    {
                        caracter = ApMat[i];
                        Nombres.Curp[14] = caracter;
                    }
                    lleno = 0;
                }
            }
            if (i == strlen(ApMat))
            {
                lleno = 0;
                Nombres.Curp[14] = 'X';
            }
        }
    }

    // *********************** NOMBRES *******************************
    system("CLS");
    do
    {
        system("CLS");
        ValiApellidos(Nombres.Persona.Nombre1, "   NOMBRE 1");
    } while (Nombres.Persona.Nombre1[0] == '\0');
    strcpy(Nombre1, Nombres.Persona.Nombre1);

    Preposiciones(Nombre1);
    Preposiciones(Nombre1);
    Preposiciones(Nombre1);

    system("CLS");
    ValiApellidos(Nombres.Persona.Nombre2, "   NOMBRE 2");
    strcpy(Nombre2, Nombres.Persona.Nombre2);

    Preposiciones(Nombre2);
    Preposiciones(Nombre2);
    Preposiciones(Nombre2);

    system("CLS");
    ValiApellidos(Nombres.Persona.Nombre3, "   NOMBRE 3");
    strcpy(Nombre3, Nombres.Persona.Nombre3);

    Preposiciones(Nombre3);
    Preposiciones(Nombre3);
    Preposiciones(Nombre3);

    if (strlen(Nombre2) == 0) // Si no es compuesto
    {

        caracter = Nombre1[0];
        Nombres.Curp[3] = caracter;
        if (Nombre1[0] == 64)
        {
            Nombres.Curp[3] = 'X';
        }
        lleno = 1;
        for (i = 1; lleno; i++)
        {
            if (Nombre1[i] != 64)
            {
                if ((Nombre1[i] != 'A') && (Nombre1[i] != 'E') && (Nombre1[i] != 'I') && (Nombre1[i] != 'O') && (Nombre1[i] != 'U'))
                {
                    if (Nombre1[i - 1] == 64)
                    {
                        Nombres.Curp[15] = 'X';
                    }
                    else
                    {
                        caracter = Nombre1[i];
                        Nombres.Curp[15] = caracter;
                    }
                    lleno = 0;
                }
            }
            if (i == strlen(Nombre1))
            {
                lleno = 0;
                Nombres.Curp[15] = 'X';
            }
        }
    }
    else // Si es compuesto
    {
        joseMaria = JoseMaria(Nombre1);
        if (joseMaria) // Si es jose o maria tomamos su segundo nombre
        {
            if (strlen(Nombre3) != 0)
            {
                joseMaria = JoseMaria(Nombre2);
                if (joseMaria)
                {

                    caracter = Nombre3[0];
                    Nombres.Curp[3] = caracter;
                    if (Nombre3[0] == 64)
                    {
                        Nombres.Curp[3] = 'X';
                    }
                    lleno = 1;
                    for (i = 1; lleno; i++)
                    {
                        if (Nombre3[i] != 64)
                        {
                            if ((Nombre3[i] != 'A') && (Nombre3[i] != 'E') && (Nombre3[i] != 'I') && (Nombre3[i] != 'O') && (Nombre3[i] != 'U'))
                            {
                                if (Nombre3[i - 1] == 64)
                                {
                                    Nombres.Curp[15] = 'X';
                                }
                                else
                                {
                                    caracter = Nombre3[i];
                                    Nombres.Curp[15] = caracter;
                                }
                                lleno = 0;
                            }
                        }
                        if (i == strlen(Nombre3))
                        {
                            lleno = 0;
                            Nombres.Curp[15] = 'X';
                        }
                    }
                }
                else
                {
                    caracter = Nombre2[0];
                    Nombres.Curp[3] = caracter;
                    if (Nombre2[0] == 64)
                    {
                        Nombres.Curp[3] = 'X';
                    }
                    lleno = 1;
                    for (i = 1; lleno; i++)
                    {
                        if (Nombre2[i] != 64)
                        {
                            if ((Nombre2[i] != 'A') && (Nombre2[i] != 'E') && (Nombre2[i] != 'I') && (Nombre2[i] != 'O') && (Nombre2[i] != 'U'))
                            {
                                if (Nombre2[i - 1] == 64)
                                {
                                    Nombres.Curp[15] = 'X';
                                }
                                else
                                {
                                    caracter = Nombre2[i];
                                    Nombres.Curp[15] = caracter;
                                }
                                lleno = 0;
                            }
                        }
                        if (i == strlen(Nombre2))
                        {
                            lleno = 0;
                            Nombres.Curp[15] = 'X';
                        }
                    }
                }
            }
            else
            {
                caracter = Nombre2[0];
                Nombres.Curp[3] = caracter;
                if (Nombre2[0] == 64)
                {
                    Nombres.Curp[3] = 'X';
                }
                lleno = 1;
                for (i = 1; lleno; i++)
                {
                    if (Nombre2[i] != 64)
                    {
                        if ((Nombre2[i] != 'A') && (Nombre2[i] != 'E') && (Nombre2[i] != 'I') && (Nombre2[i] != 'O') && (Nombre2[i] != 'U'))
                        {
                            if (Nombre2[i - 1] == 64)
                            {
                                Nombres.Curp[15] = 'X';
                            }
                            else
                            {
                                caracter = Nombre2[i];
                                Nombres.Curp[15] = caracter;
                            }
                            lleno = 0;
                        }
                    }
                    if (i == strlen(Nombre2))
                    {
                        lleno = 0;
                        Nombres.Curp[15] = 'X';
                    }
                }
            }
        }
        else // No es Jose o Maria usamos su primer nombre
        {
            caracter = Nombre1[0];
            Nombres.Curp[3] = caracter;
            if (Nombre1[0] == 64)
            {
                Nombres.Curp[3] = 'X';
            }
            lleno = 1;
            for (i = 1; lleno; i++)
            {
                if (Nombre1[i] != 64)
                {
                    if ((Nombre1[i] != 'A') && (Nombre1[i] != 'E') && (Nombre1[i] != 'I') && (Nombre1[i] != 'O') && (Nombre1[i] != 'U'))
                    {
                        if (Nombre1[i - 1] == 64)
                        {
                            Nombres.Curp[15] = 'X';
                        }
                        else
                        {
                            caracter = Nombre1[i];
                            Nombres.Curp[15] = caracter;
                        }
                        lleno = 0;
                    }
                }
                if (i == strlen(Nombre1))
                {
                    lleno = 0;
                    Nombres.Curp[15] = 'X';
                }
            }
        }
    }
    return Nombres;
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

TReg Inconvenientes(TReg Nombres)
{
    char inconvenientes[81][5] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};
    char comparar[4];
    int i;
    strncat(comparar, Nombres.Curp, 4);
    for (i = 0; i < 81; i++)
    {
        if (strcmp(comparar, inconvenientes[i]) == 0)
        {
            Nombres.Curp[1] = 'X';
        }
    }
    return Nombres;
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