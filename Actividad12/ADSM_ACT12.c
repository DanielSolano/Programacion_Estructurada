// Solano Meza Angel Daniel Matr. 372453
// 07/11/2023
// Uso de registros para almacenar informacion de alumnos
// ADSM_ACT12_932

#include "miti_2.h"

//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
TReg RegistroAuto();
//****  main principal  *********
int main()
{
    menu();

    return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******
int msges()
{
    int op;
    system("CLS");
    printf("   M  E   N   U \n");
    printf("1.- CARGAR ARCHIVO \n");
    printf("2.- AGREGAR REGISTROS \n");
    printf("3.- ELIMINAR REGISTRO \n");
    printf("4.- BUSCAR \n");
    printf("5.- ORDENAR \n");
    printf("6.- MOSTRAR TODO \n");
    printf("7.- GENERAR ARCHIVO \n");
    printf("8.- CANTIDAD DE REGISTROS EN ARCHIVO \n");
    printf("9.- MOSTRAR BORRADOS \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}
//****************
void menu()
{
    srand(time(NULL));
    TReg VectReg[1500], temp;
    int op, j, i, apagar, buscar, encontrado, ordenado, confirmar;
    char NombreArchivo[50];
    i = 0;
    ordenado = 0;
    do
    {
        op = msges();
        switch (op)
        {
        case 1: // CARGAR ARCHIVO
            system("CLS");
            LeerTXT(VectReg, &i, "datos.txt");
            system("PAUSE");
            break;
        case 2: // REGISTROS AUTOMATICOS
            system("CLS");
            for (j = 0; j < 10; j++)
            {
                temp = RegistroAuto();
                while (BusquedaTReg(VectReg, i, temp.key) != -1)
                {
                    temp.key = NumAleatorio(300000, 399999);
                }
                if (i <= 1500)
                {
                    VectReg[i++] = temp;
                    ordenado = 0;
                }
            }
            if (i < 1500)
            {
                printf("REGISTROS LLENADOS AUTOMATICAMENTE\n");
            }
            else
            {
                printf("500 REGISTROS OCUPADOS\n");
            }
            system("PAUSE");
            break;
        case 3: // ELIMINAR REGISTRO
            system("CLS");
            if (i == 0)
            {
                printf("INCAPAZ DE ELIMINAR REGISTROS VACIOS\n");
            }
            else
            {
                printf("MATRICULA DE REGISTRO A ELIMINAR\n");
                apagar = Validar(300000, 399999);
                if (ordenado == 0)
                {
                    encontrado = BusquedaTReg(VectReg, i, apagar);
                }
                else
                {
                    encontrado = BusquedaBinaria(VectReg, 0, i, apagar);
                }

                if (encontrado == -1)
                {
                    printf("MATRICULA NO EXISTENTE\n");
                }
                else // Encontrada
                {
                    if (VectReg[encontrado].Status == 0)
                    {
                        printf("REGISTRO YA ELIMINADO\n");
                    }
                    else
                    {
                        VectReg[encontrado].Status = 0;
                        printf("REGISTRO CON MATRICULA %d APAGADO\n", apagar);
                    }
                }
            }
            system("PAUSE");
            break;
        case 4:
            system("CLS");
            if (i == 0)
            {
                printf("INCAPAZ DE BUSCAR EN REGISTROS VACIOS\n");
            }
            else
            {
                printf("MATRICULA A BUSCAR\n");
                buscar = Validar(300000, 399999);
                if (ordenado == 0)
                {
                    encontrado = BusquedaTReg(VectReg, i, buscar);
                }
                else
                {
                    encontrado = BusquedaBinaria(VectReg, 0, i, buscar);
                }

                if (encontrado == -1)
                {
                    printf("MATRICULA NO ENCONTRADA\n");
                }
                else
                {
                    if (VectReg[encontrado].Status == 0)
                    {
                        printf("MATRICULA DE ALUMNO DESACTIVADO\n");
                    }
                    else
                    {
                        printf("DATOS DEL REGISTRO ENCONTRADO:\n\n");
                        printf("MATRICULA EN REGISTRO: %d\n", encontrado);
                        printf("MATRICULA: %d\n", VectReg[encontrado].Matricula);
                        printf("NOMBRE: %s\n", VectReg[encontrado].Nombre);
                        printf("APELLIDO PATERNO: %s\n", VectReg[encontrado].ApPat);
                        printf("APELLIDO MATERNO: %s\n", VectReg[encontrado].ApMat);
                        printf("EDAD: %d\n", VectReg[encontrado].Edad);
                        printf("SEXO: %s\n", VectReg[encontrado].Sexo);
                    }
                }
            }
            system("PAUSE");
            break;
        case 5: // ORDENAR REGISTROS
            system("CLS");
            if (i <= 1)
            {
                if (i == 0)
                {
                    printf("INCAPAZ DE ORDENAR UN REGISTRO VACIO\n");
                }
                else
                {
                    printf("UN SOLO REGISTRO ORDENADO\n");
                }
            }
            else
            {
                if (ordenado == 0)
                {
                    if (i < 500)
                    {
                        ordenado = OrdenarTReg(VectReg, i);
                        printf("REGISTROS ORDENADOS\n");
                    }
                    else
                    {
                        Quicksort(VectReg, 0, i - 1);
                        ordenado = 1;
                        printf("REGISTROS ORDENADOS POR QUICKSORT\n");
                    }
                }
                else
                {
                    printf("REGISTROS YA ORDENADOS\n");
                }
            }
            system("PAUSE");
            break;
        case 6: // IMPRIMIR REGISTROS
            system("CLS");
            if (i == 0)
            {
                printf("REGISTROS VACIOS\n");
            }
            else
            {
                ImprimirTReg(VectReg, i);
            }
            system("PAUSE");
            break;
        case 7: // Archivo de texto
            ValiCadena(NombreArchivo, "NOMBRE DEL ARCHIVO TXT");

            CrearTXT(NombreArchivo, VectReg, i);
            printf("\n");
            system("PAUSE");
            break;
        }

    } while (op != 0);
}

TReg RegistroAuto()
{
    TReg alum;
    int i, apellido, sexo, nombres;
    char NombresHombre[][15] = {"ALBERTO", "FERNANDO", "MARIO", "ALEJANDRO", "GABRIEL", "SERGIO", "CARLOS", "HECTOR", "LUIS", "ENRIQUE", "JULIO", "RODRIGO", "EDUARDO", "OSCAR", "GUSTAVO", "JUAN", "CARLOS", "LUIS", "JOSE", "MIGUEL", "PEDRO", "ANTONIO", "MANUEL", "JAVIER", "PABLO", "DAVID", "FRANCISCO", "ALEJANDRO", "DANIEL", "ANDRES"};
    char NombresMujer[][15] = {"LUCIA", "RAQUEL", "NATALIA", " BEATRIZ", "LOURDES", "CLARA", "LINDA", "GLORIA", "ADRIANA", "VALERIA", "ALICIA", "VICTORIA", " DIANA", "SILVIA", "SARA", "MARIA", "ANA", "LAURA", "CARMEN", "ISABEL", "SOFIA", "LUISA", "ELENA", "PATRICIA", "TERESA", "ROSA", "PAULA", "MARTA", "CRISTINA", "DANNA"};
    char Apellidos[][30] = {"HARO", "SOLANO", "SANDEZ", "LOPEZ", "MEZA", "PEREZ", "SANCHEZ", "FERNANDEZ", "TORRES", "RAMIREZ", "RUIZ", "GONZALEZ", "TORRES", "MORALES", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "MORALES", "CASTRO", "RIOS", "MEDINA", "VARGAS", "MENDOZA", "REYES", "BLANCO", "NAVARRO", "GUZMAN", "ROMERO", "ORTEGA", "JIMENEZ", "SOTO", "HERRERA", "DELGADO", "CASTRO", "RIOS", "MEDINA", "SILVA", "CASTRO", "RIOS", "MONTOYA", "PENA", "VIDAL", "AGUILAR", "CORDERO", "MORA", "SOSA", "ROSALES", "LUGO", "SERRANO", "CACERES", "ROBLES", "SALAZAR", "LEON", "GALLEGOS", "CORDOVA", "DEL VALLE", "NAVARRO", "PAREDES", "ZAMORA", "VALDEZ", "DURAN", "CISNEROS", "GUTIERREZ", "SALINAS", "AVILA", "RIVAS", "PIZARRO", "GUERRA", "ESPINOZA", "CALDERON", "PANTOJA", "MIRANDA", "MORALES", "ROJAS", "SEGURA", "VILLANUEVA", "ROLDAN", "BENITEZ", "LUNA", "VALENCIA", "CERVANTES", "ESCOBAR", "ZUNIGA", "BARRIOS"};
    char sexos[2][8] = {"HOMBRE", "MUJER"};
    i = NumAleatorio(0, 30);
    nombres = NumAleatorio(1, 2);
    sexo = NumAleatorio(1, 2);
    if (sexo == 1)
    {

        strcpy(alum.Nombre, NombresHombre[i]);
        strcpy(alum.Sexo, sexos[0]);
    }
    else
    {

        strcpy(alum.Nombre, NombresMujer[i]);
        strcpy(alum.Sexo, sexos[1]);
    }

    alum.Status = 1;
    alum.Matricula = NumAleatorio(300000, 399999);
    alum.key = alum.Matricula;
    apellido = NumAleatorio(0, 88);
    strcpy(alum.ApPat, Apellidos[apellido]);
    apellido = NumAleatorio(0, 88);
    strcpy(alum.ApMat, Apellidos[apellido]);
    alum.Edad = NumAleatorio(18, 27);
    return alum;
}
