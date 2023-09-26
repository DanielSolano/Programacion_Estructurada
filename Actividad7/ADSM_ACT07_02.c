// Solano Meza Angel Daniel Matr. 372453
// 25/09/2023
// Uso de funciones para modificar cadenas 
// ADSM_ACT7_02_932

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Mayusculas(char cadena[]);
void Minusculas(char cadena[]);
void Capital(char cadena[]);
int Caracteres(char cadena[]);
void Inversa(char cadena[]);
void Espacios(char cadena[]);
void Alfabetica(char cadena[]);
void Todas(char cadena[]);
void Palindromo(char cadena[]);
int Validar(char cadena[]);
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
    printf("1.- MAYUSCULAS \n");
    printf("2.- MINUSCULAS \n");
    printf("3.- CAPITAL \n");
    printf("4.- LARGO CADENA \n");
    printf("5.- CADENA INVERSA \n");
    printf("6.- SIN ESPACIOS \n");
    printf("7.- SOLO CARACTERES A - Z \n");
    printf("8.- COMBINACION DE TODOS\n");
    printf("9.- PALINDROMO\n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    int op, largo;
    char cadena[100];
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            system("CLS");
            printf("   MAYUSCULAS\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Mayusculas(cadena);
            break;
        case 2:
            system("CLS");
            printf("   MINUSCULAS\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Minusculas(cadena);
            break;
        case 3:
            system("CLS");
            printf("   CAPITAL\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Capital(cadena);
            break;
        case 4:
            system("CLS");
            printf("   LARGO CADENA\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            largo = Caracteres(cadena);
            printf("La cadena tiene %d caracteres.\n", largo);
            system("PAUSE");
            break;
        case 5:
            system("CLS");
            printf("   CADENA INVERSA\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Inversa(cadena);
            break;
        case 6:
            system("CLS");
            printf("   SIN ESPACIOS\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Espacios(cadena);
            break;
        case 7:
            system("CLS");
            printf("   SOLO CARACTERES A - Z\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Alfabetica(cadena);
            break;
        case 8:
            system("CLS");
            printf("   COMBINACION\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Todas(cadena);
            break;
        case 9:
            system("CLS");
            printf("   PALINDROMO\n");
            printf("Ingresa una sentencia:\n");
            fflush(stdin);
            gets(cadena);
            Palindromo(cadena);
            break;
        }

    } while (op != 0);
}

//*********************
void Mayusculas(char cadena[])
{
    //  VARIALES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA
    i = 0;
    for (i = 0; cadena[i] != '\0'; i++) // Convierte a mayusculas
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    for (j = 0; j <= i; j++) // Imprime la cadena
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}

//*************************
void Minusculas(char cadena[])
{

    //  VARIALES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA
    i = 0;
    for (i = 0; cadena[i] != '\0'; i++) // Convierte a minusculas
    {
        if (cadena[i] >= 'A')
        {
            if (cadena[i] <= 'Z')
            {
                cadena[i] = cadena[i] + 32;
            }
        }
    }
    for (j = 0; j <= i; j++) // Imprime la cadena
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Capital(char cadena[])
{
    //  VARIABLES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0; cadena[i] != '\0'; i++) // Cuenta los caracteres totales
    {
        if (i == 0) // Convierte a mayusculas el primer caracter
        {
            if (cadena[i] != ' ')
            {
                if (cadena[i] >= 'a')
                {
                    if (cadena[i] <= 'z')
                    {
                        cadena[i] = cadena[i] - 32;
                    }
                }
            }
            else // Si empieza con un espacio convierte la segunda letra en mayuscula
            {
                if (cadena[i + 1] >= 'a')
                {
                    if (cadena[i + 1] <= 'z')
                    {
                        cadena[i + 1] = cadena[i + 1] - 32;
                    }
                }
            }
        }
        if (cadena[i] == ' ')
        {
            i++;
            if (cadena[i] >= 'a')
            {
                if (cadena[i] <= 'z')
                {
                    cadena[i] = cadena[i] - 32;
                }
            }
        }
    }
    for (j = 0; j <= i; j++) // Imprime la cadena
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}

//****************************
int Caracteres(char cadena[])
{
    //  VARIABLES LOCALES
    int i;
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0; cadena[i] != '\0'; i++) // Cuenta caracteres
    {
    }
    return i;
}
//****************************
void Inversa(char cadena[])
{
    //  VARIABLES LOCALES
    int i, j;
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0; cadena[i] != '\0'; i++) // Cuenta caracteres
    {
    }

    for (j = i; j >= 0; j--) // Imprime la cadena inversa
    {
        printf("%c", cadena[j]);
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Espacios(char cadena[])
{
    //  VARIABLES LOCALES
    int i, j, k, h, q;
    char copia[100];
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0; cadena[i] != '\0'; i++) // Cuenta caracteres
    {
    }

    for (q = 0; q <= i; q++) // Copia la cadena orginal
    {
        copia[q] = cadena[q];
    }

    for (j = 0; j <= i; j++)
    {
        if (copia[j] == ' ') // Si hay un espacio vacio, todo el contenido se recorre un espacio a la izquierda
        {
            for (k = j; k < i; k++)
            {
                copia[k] = copia[k + 1];
            }
        }
    }

    for (h = 0; h <= i; h++) // Imprime la cadena
    {
        printf("%c", copia[h]);
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Alfabetica(char cadena[])
{
    //  VARIABLES LOCALES
    int i, j;
    char copia[100];
    //  AQUI DESARROLLO PROGRAMA
    for (i = 0, j = 0; cadena[i] != '\0'; i++, j++)
    {
        // Verifica si es caracter o espacio
        if ((cadena[i] == ' ') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            // Verfica inicio y terminacion en espacio
            if (cadena[i] != ' ' || (i > 0 && cadena[i + 1] != '\0' && cadena[i - 1] != ' '))
            {
                copia[j] = cadena[i];
                printf("%c", copia[j]);
            }
        }
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Todas(char cadena[])
{
    printf("    MAYUSCULAS\n");
    Mayusculas(cadena);
    printf("    MINUSCULAS\n");
    Minusculas(cadena);
    printf("    CAPITAL\n");
    Capital(cadena);
    printf("    SIN ESPACIOS\n");
    Espacios(cadena);
    printf("    AL REVES\n");
    Inversa(cadena);
    system("PAUSE");
}
//****************************
void Palindromo(char cadena[])
{
    //  VARIABLES LOCALES
    int largo, j, valor, i, palindromo;
    //  AQUI DESARROLLO PROGRAMA
    valor = Validar(cadena);
    if (valor == 0)
    {
        printf("Cadena valida\n");
        largo = 0;
        while (cadena[largo] != '\0')
        {
            largo++;
        }

        i = 0;
        j = largo - 1;
        palindromo = 1;
        while (i < j)
        {
            if (cadena[i] != cadena[j])
            {
                palindromo = 0;
            }
            i++;
            j--;
        }
        if (palindromo == 1)
        {
            printf("La cadena es palindromo\n");
        }
        else
        {
            printf("La cadena no es palindromo\n");
        }
        system("PAUSE");
    }
    else
    {
        printf("Cadena invalida.\n");
        system("PAUSE");
    }
}
//****************************
int Validar(char cadena[])
{
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= '0' && cadena[i] <= '9')
        {
            return 1; // Son numeros
        }
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            return 2; // Es minuscula
        }
        if (cadena[i] == ' ' && cadena[i + 1] == ' ')
        {
            return 3; // Hay doble espacio
        }
    }
    return 0;
}