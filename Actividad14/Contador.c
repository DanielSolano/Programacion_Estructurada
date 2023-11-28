#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "junior.h"

int main(int argc, char *argv[])
{
    FILE *fa;
    char nombre[30];
    int cont = 0;

    strcpy(nombre, argv[1]);
    strcat(nombre, ".dat");
    
    fa = fopen(nombre, "rb");
    if (fa)
    {
        fseek(fa, 0, SEEK_END);
        long tamanio = ftell(fa);
        cont = tamanio / sizeof(TReg);
        fclose(fa);
    }
    else
    {
        return 0;
    }

    return cont;
}