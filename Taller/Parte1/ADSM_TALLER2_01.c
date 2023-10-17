#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void LeerTXT(void);
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
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
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
            LeerTXT();
            system("PAUSE");
            break;
        }

    } while (op != 0);
}
void LeerTXT(void)
{
    char caracter;
    FILE *archivo;
    archivo = fopen("cancion.txt", "r");
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