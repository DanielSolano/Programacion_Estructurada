#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
char LeerCadena(void);
void Salida1(void);
void Salida2(void);
void Salida3(void);
void Salida4(void);
void Salida5(void);
void Salida6(void);
void Salida7(void);
void Salida8(void);
void Salida9(void);
void Salida10(void);
int Validar(char msg[], int inferior, int superior);
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
    printf("1.- SALIDA 1 \n");
    printf("2.- SALIDA 2 \n");
    printf("3.- SALIDA 3 \n");
    printf("4.- SALIDA 4 \n");
    printf("5.- SALIDA 5 \n");
    printf("6.- SALIDA 6 \n");
    printf("7.- SALIDA 7 \n");
    printf("8.- SALIDA 8 \n");
    printf("9.- SALIDA 9 \n");
    printf("10.- SALIDA 10 \n");
    printf("0.- SALIR  \n");
    op = Validar("ESCOGE UNA OPCION: \n", 0, 10);
    return op;
}
//****************
void menu()
{
    int op;
    do
    {
        op = msges();
        switch (op)
        {
        case 1:
            Salida1();
            break;
        case 2:
            Salida2();
            break;
        case 3:
            Salida3();
            break;
        case 4:
            Salida4();
            break;
        case 5:
            Salida5();
            break;
        case 6:
            Salida6();
            break;
        case 7:
            Salida7();
            break;
        case 8:
            Salida8();
            break;
        case 9:
            Salida9();
            break;
        case 10:
            Salida10();
            break;
        }
    } while (op != 0);
}
//*********************
int Validar(char msg[], int inferior, int superior) // Parametros para funcionar
{
    int num;
    char cadena[3];
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(cadena);       // Tomas los datos como cadena
        num = atoi(cadena); // Transforma la entrada a entero

    } while ((num < inferior) || (num > superior));
    return num;
}
//*********************
void Salida1(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 1");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);
    system("CLS");
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
    for (j = 0; j <= i; i++) // Imprime cadena
    {
        printf("%c\n", cadena[j]);
    } 
    system("PAUSE");
}

//*************************
void Salida2(void)
{

    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 2\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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
    system("CLS");
    for (j = i; j >= 0; j--)
    {
        printf("%c", cadena[j]); // Imprime la cadena al reves
    }
    printf("\n");
    system("PAUSE");
}
//****************************
void Salida3(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 3\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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
    system("CLS");
    for (j = 0; j <= i; j++)
    {
        printf("%c\n", cadena[j]); // Imprime la cadena letra por letra hacia abajo
    }
    system("PAUSE");
}
//****************************
void Salida4(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 4\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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
    system("CLS");
    for (j = i; j >= 0; j--)
    {
        printf("%c\n", cadena[j]); // Imprime la cadena letra por letra al reves
    }
    system("PAUSE");
}
//****************************
void Salida5(void)
{
    //  VARIALES LOCALES
    int i, j, k, h;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 5\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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
    k = i;
    for (h = i; h >= 0; h--) // Controla las veces que se imprimira la cadena
    {
        j = 0;
        cadena[k] = '\0';        // Modifica el carecter vacio
        for (j = 0; j <= i; j++) // Imprime la cadena en mayuscula en el orden del usuario
        {
            printf("%c", cadena[j]);
        }
        k--;
        printf("\n");
    }
    system("PAUSE");
}
//****************************
void Salida6(void)
{
    //  VARIALES LOCALES
    int i, j, k, h;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 6\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

    for (i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a')
        {
            if (cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
    k = 0;
    for (h = i; h >= 0; h--) // Controla las veces que se imprimira la cadena
    {
        for (j = i; j >= 0; j--) // Imprime la cadena
        {
            printf("%c", cadena[j]);
        }
        cadena[k] = '\0'; // Modifica el carecter vacio
        k++;
        printf("\n");
    }
    system("PAUSE");
}
void Salida7(void)
{
    //  VARIALES LOCALES
    int i, j, k, h;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 7\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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
    k = 0;
    for (h = i; h >= 0; h--) // Controla las veces que se imprimira la cadena
    {
        j = 0;
        for (j = 0; j <= i; j++) // Imprime la cadena
        {
            printf("%c", cadena[j]);
        }
        cadena[k] = '\0'; // Modifica el carecter vacio
        k++;
        printf("\n");
    }
    system("PAUSE");
}

void Salida8(void)
{
    //  VARIALES LOCALES
    int i, j, k, h;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 8\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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
    k = i;
    for (h = i; h >= 0; h--) // Controla las veces que se imprimira la cadena
    {
        j = 0;
        cadena[k] = '\0';        // Modifica el carecter vacio
        for (j = i; j >= 0; j--) // Imprime la cadena
        {
            printf("%c", cadena[j]);
        }
        k--;
        printf("\n");
    }
    system("PAUSE");
}

void Salida9(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 9\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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

    for (j = 0; j <= i; j++)
    {
        // Si el caracter no es vocal la imprime
        if ((cadena[j] != 'A') && (cadena[j] != 'E') && (cadena[j] != 'I') && (cadena[j] != 'O') && (cadena[j] != 'U'))
        {
            printf("%c", cadena[j]);
        }
    }
    printf("\n");
    system("PAUSE");
}
void Salida10(void)
{
    //  VARIALES LOCALES
    int i, j;
    char cadena[100];
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   SALIDA 10\n");
    printf("Ingresa una frase: \n");
    fflush(stdin);
    gets(cadena);

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

    for (j = 0; j <= i; j++)
    {
        // Si el caracter es vocal lo imprime
        if ((cadena[j] == 'A') || (cadena[j] == 'E') || (cadena[j] == 'I') || (cadena[j] == 'O') || (cadena[j] == 'U'))
        {
            printf("%c", cadena[j]);
        }
    }
    printf("\n");
    system("PAUSE");
}