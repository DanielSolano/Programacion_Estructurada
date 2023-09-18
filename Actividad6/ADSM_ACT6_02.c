#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void derechoExamen(void);
void Factorial(void);
void Digitos(void);
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
    printf("1.- EXAMEN DE NIVELACION \n");
    printf("2.- FACTORIAL \n");
    printf("3.- DIGITOS \n");
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
            derechoExamen();
            break;
        case 2:
            Factorial();
            break;
        case 3:
            Digitos();
            break;
        }

    } while (op != 0);
}

//*********************
void derechoExamen(void)
{
    //  VARIABLES LOCALES
    int i, j, prom, s_derecho, cal;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    s_derecho = 0;
    i = 1;
    j = 1;
    printf("   EXAMEN DE NIVELACION\n");
    for (i = 1; i <= 40; i++)
    {
        prom = 0;
        system("CLS");
        printf("ALUMNO %d\n",i); 
        for (j = 1; j <= 5; j++, prom += cal)
        {
            printf("Calificacion unidad %d: \n", j);
            scanf("%d",&cal);
        }
        prom /= 5;
        printf("%d",prom);
        if(prom<50)
        {
            s_derecho++;
        }
    }
    system("CLS");
    printf("La cantidad de alumnos sin derecho a examen es: %d\n",s_derecho);
    system("PAUSE");
}

//*************************
void Factorial(void)
{

    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n");
    system("PAUSE");
}
//****************************
void Digitos(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}