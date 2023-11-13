#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fa;
    char nombre[30];
    char linea[90];
    int cont = 0;
    int status = atoi(argv[2]);

    strcpy(nombre, argv[1]);

    fa = fopen(nombre, "r");
    if (fa)
    {
        while (!feof(fa))
        {
            fgets(linea, 90, fa);
            if (strlen(linea) > 10)
            {
                cont++;
            }
        }
        fclose(fa);
    }
    else
    {
        return 0;
    }

    return cont;
}