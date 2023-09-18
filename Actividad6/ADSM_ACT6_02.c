#include <stdio.h>
#include <stdlib.h>

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Fibonacci (void);
void Factorial (void);
void Digitos (void);
//****  main principal  *********
int main()
{
   menu();

	return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
//*********************
int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- FIBONACCI \n");
  printf("2.- FACTORIAL \n");
  printf("3.- DIGITOS \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}
//****************
void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              Fibonacci();
              break;
        case 2:
              Factorial();
              break;
        case 3:
              Digitos();
              break;

      }

    }while (op != 0);


}

//*********************
void Fibonacci (void)
{
    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FIBONACCI\n"); 
    system ("PAUSE");
}

//*************************
void Factorial (void)
{

    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   FACTORIAL\n"); 
    system ("PAUSE");
}
//****************************
void Digitos (void)
{
    //  VARIALES LOCALES 
    system ("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n"); 
    system ("PAUSE");

}