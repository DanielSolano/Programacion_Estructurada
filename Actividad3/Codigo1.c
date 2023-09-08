#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Promedio(void);
void PPP_anidado(void);
void PPP_multiple(void);
void Mayor(void);
void Medio(void);
void Ascendentes(void);
void Zodiacal(void);
//****  main principal  *********
int main()
{
    srand(time(NULL));
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
    printf("1.- PROMEDIO \n");
    printf("2.- CHICHAMPU ANIDADO \n");
    printf("3.- CHICHAMPU SELECCION MULTIPLE \n");
    printf("4.- NUMERO MAYOR  \n");
    printf("5.- NUMERO EN MEDIO  \n");
    printf("6.- NUMEROS ASCENDENTES  \n");
    printf("7.- SIGNO ZODIACAL  \n");
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
            Promedio();
            break;
        case 2:
            PPP_anidado();
            break;
        case 3:
            PPP_multiple();
            break;
        case 4:
            Mayor();
            break;
        case 5:
            Medio();
            break;
        case 6:
            Ascendentes();
            break;
        case 7:
            Zodiacal();
            break;
        }

    } while (op != 0);
}

//*********************
void Promedio(void)
{
    //  VARIABLES LOCALES
    int c1, c2, c3;
    float prom;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   PROMEDIO\n");
    // LEEMOS 3 CALIFICACIONES
    printf("Calificacion 1: \n");
    scanf("%d", &c1);
    printf("Calificacion 2: \n");
    scanf("%d", &c2);
    printf("Calificacion 3: \n");
    scanf("%d", &c3);
    prom = (c1 + c2 + c3) / 3;
    if (prom >= 80)
    {
        if (prom >= 90)
        {
            if (prom >= 98)
            {
                if (prom > 100)
                {
                    // PROMEDIO INCORRECTO
                    printf("Error en el promedio \nPromedio: %.2f \n,prom");
                }
                else
                {
                    // ES 98
                    printf("Excelente \nPromedio: %.2f \n", prom);
                }
            }
            else
            {
                // ES 90
                printf("Muy bien \nPromedio: %.2f \n", prom);
            }
        }
        else
        {
            // ES 80
            printf("Bien \nPromedio: %.2f \n", prom);
        }
    }
    else
    {
        if (prom < 70)
        {
            if (prom < 60)
            {
                if (prom < 30)
                {
                    // REPITES
                    printf("Repetidor \nPromedio: %.2f \n", prom);
                }
                else
                {
                    // EXTRAORDINARIO
                    printf("Extraordinario \nPromedio: %.2f \n", prom);
                }
            }
            else
            {
                // ES 60
                printf("Suficiente \nPromedio: %.2f \n", prom);
            }
        }
        else
        {
            // ES 70
            printf("Regular \nPromedio: %.2f \n", prom);
        }
    }
    system("PAUSE");
}

//*************************
void PPP_anidado(void)
{

    //  VARIALES LOCALES
    int j1, j2;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   CHICHAMPU ANIDADO\n");
    j2 = rand() % 3 + 1; // El jugador 2 es controlado por la maquina
    printf("---Chichampu---\n1.-Piedra\n2.-Papel\n3.-Tijera\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &j1);
    if ((j1 <= 0) && (j1 > 3))
    {
        printf("Opcion incorrecta");
    }
    else
    {
        if ((j1 == 1 && j2 == 3) || (j1 == 2 && j2 == 1) || (j1 == 3 && j2 == 2))
        {
            if (j1 == 1)
            {
                printf("Gana jugador 1, piedra gana a tijera");
            }

            if (j1 == 2)
            {
                printf("Gana jugador 1, papel gana a piedra");
            }
            if (j1 == 3)
            {
                printf("Gana jugador 1, tijera gana a papel");
            }
        }
        else
        {
            if ((j2 == 1 && j1 == 3) || (j2 == 2 && j1 == 1) || (j2 == 3 && j1 == 2))
            {
                if (j2 == 1)
                {
                    printf("Gana jugador 2, piedra gana a tijera");
                }
                if (j2 == 2)
                {
                    printf("Gana jugador 2, papel gana a piedra");
                }
                if (j2 == 3)
                {
                    printf("Gana jugador 2, tijera gana a papel");
                }
            }
            else
            {
                printf("Empate");
            }
        }
    }
    system("PAUSE");
}
//****************************
void PPP_multiple(void)
{
    //  VARIALES LOCALES
    int j1, j2;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   CHICHAMPU SWITCH\n");
    j2 = rand() % 3 + 1; // Genera un numero entre 1 y 3 que es la tirada de la computadora

    printf("Ingresa una opcion (1. Piedra, 2. Papel, 3. Tijera): ");
    scanf("%d", &j1);

    if ((j1 <= 0) && (j1 > 3))
    {
        printf("Opcion incorrecta");
    }
    else
    {
        // Jugador 1 es humano, jugador 2 computadora
        switch (j1)
        {
        case 1:
            switch (j2)
            {
            case 1:
                printf("Empate, ambos eligieron piedra");
                break;

            case 2:
                printf("Gana J2, papel gana a piedra");
                break;

            case 3:
                printf("Gana J1, piedra gana a tijeras");
                break;
            }
            break;

        case 2:
            switch (j2)
            {
            case 1:
                printf("Gana J1, papel gana a piedra");
                break;

            case 2:
                printf("Empate, ambos eligieron papel");
                break;

            case 3:
                printf("Gana J2, tijeras gana a papel");
                break;
            }
            break;

        case 3:
            switch (j2)
            {
            case 1:
                printf("Gana J2, piedra gana a tijeras");
                break;

            case 2:
                printf("Gana J1, tijeras gana a papel)");
                break;

            case 3:
                printf("Empate, ambos eligieron papel");
                break;
            }
            break;
        }
    }
    system("PAUSE");
}
void Mayor(void)
{
    //  VARIALES LOCALES
    int n1, n2, n3;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   IDENTIFICAR AL MAYOR\n");

    system("PAUSE");
}
void Medio(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
void Ascendentes(void)
{
    //  VARIALES LOCALES
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   DIGITOS\n");
    system("PAUSE");
}
void Zodiacal(void)
{
    //  VARIALES LOCALES
    int dia, mes;
    system("CLS");
    //  AQUI DESARROLLO PROGRAMA
    printf("   ZODIACO\n");
    printf("Dia de nacimiento: \n");
    scanf("%d", &dia);
    printf("Mes de nacimiento: \n");
    scanf("%d", &mes);

    if ((dia < 0) || (dia > 31))
    {
        printf("Dia incorrecto.\n");
    }
    else
    {
        if (mes == 1)
        {
            if (dia >= 21)
            {
                printf("ACUARIO\nNo dejes de observar a tus hijos, porque alguno de ellos podria estar pasando por un momento dificil; quiza tenga problemas con sus amistades o le cueste adaptarse a una nueva situacion. Acuario, es posible que no te haya dicho nada pero te necesita. Salvo lo anterior, en el resto te ira bien.\n");
            }
            else
            {
                printf("CAPRICORNIO\nSi tu trabajo se encuentra lejos de tu hogar y pierdes mucho tiempo en el trayecto, cada vez se te hara más dificil. Ademas, el ambiente laboral no sera el más adecuado para sentirse a gusto trabajando, por eso podrias decidir buscar otro empleo. Bueno, Capricornio, por lo menos el resto de tu vida ira bien.\n");
            }
        }

        if (mes == 2)
        {
            if (dia >= 20)
            {
                printf("PISCIS\nLa relacion con tu pareja o con algun pariente esta pasando por cierta crisis. Para ti la familia es algo importante y todo lo que sucede relacionado con ella te afecta sobremanera. Tienes que aprender a equilibrar y a fortalecer el plano emocional. Tu corazon es tu mayor debilidad, pero debes aprender a conseguir independencia y libertad personal.\n");
            }
            else
            {
                printf("ACUARIO\nNo dejes de observar a tus hijos, porque alguno de ellos podria estar pasando por un momento dificil; quiza tenga problemas con sus amistades o le cueste adaptarse a una nueva situacion. Acuario, es posible que no te haya dicho nada pero te necesita. Salvo lo anterior, en el resto te ira bien.\n");
            }
        }

        if (mes == 3)
        {
            if (dia >= 21)
            {
                printf("ARIES\nSera un dia bastante variable; esta vez, seras tú quien se convertira en tu propio enemigo. El raciocinio pondra obstaculos a tu expresion personal, y asi, te mostraras demasiado introvertido-a y critico-a con todo. Aries, deberias procurar sumar a lo anterior un espiritu constructivo.\n");
            }
            else
            {
                printf("PISCIS\nLa relacion con tu pareja o con algun pariente esta pasando por cierta crisis. Para ti la familia es algo importante y todo lo que sucede relacionado con ella te afecta sobremanera. Tienes que aprender a equilibrar y a fortalecer el plano emocional. Tu corazon es tu mayor debilidad, pero debes aprender a conseguir independencia y libertad personal.\n");
            }
        }
        if (mes == 4)
        {
            if (dia >= 21)
            {
                printf("TAURO\nComo perteneces a un signo fijo, algunas de tus acciones están basadas en una personalidad y unas ideas muy fijas e inamovibles. Precisamente por eso, te cuesta un esfuerzo enorme cambiar de actitud en determinados momentos... pero hoy, no te quedará más remedio que hacerlo o tendrás problemas.\n");
            }
            else
            {
                printf("ARIES\nSera un dia bastante variable; esta vez, seras tú quien se convertira en tu propio enemigo. El raciocinio pondra obstaculos a tu expresion personal, y asi, te mostraras demasiado introvertido-a y critico-a con todo. Aries, deberias procurar sumar a lo anterior un espiritu constructivo.\n");
            }
        }
        if (mes == 5)
        {
            if (dia >= 22)
            {
                printf("GEMINIS\nLa relacion con tu padre o con algun otro miembro de la familia perteneciente al sexo masculino sera bastante tensa en el dia de hoy. Procura no discutir, porque no solamente no os entendereis, ademas empeoraras la situacion: recuerdalo. Geminis, tambien podrias tener algunos imprevistos que alteraran tus planes.\n");
            }
            else
            {
                printf("TAURO\nComo perteneces a un signo fijo, algunas de tus acciones están basadas en una personalidad y unas ideas muy fijas e inamovibles. Precisamente por eso, te cuesta un esfuerzo enorme cambiar de actitud en determinados momentos... pero hoy, no te quedará más remedio que hacerlo o tendrás problemas.\n");
            }
        }
        if (mes == 6)
        {
            if (dia >= 22)
            {
                printf("CANCER\nHoy podrias encontrarte con algunos problemas, y quiza tu mismo-a provoques algunos de ellos. Tu vision de la vida sera muy negativa y radical; te creeras en posesion de la verdad, sin tener en cuenta la opinion de las personas que te rodeen. Esto podra molestar mucho a los demas. Tienes que aprender a ser mas tolerante.\n");
            }
            else
            {
                printf("GEMINIS\nLa relacion con tu padre o con algun otro miembro de la familia perteneciente al sexo masculino sera bastante tensa en el dia de hoy. Procura no discutir, porque no solamente no os entendereis, ademas empeoraras la situacion: recuerdalo. Geminis, tambien podrias tener algunos imprevistos que alteraran tus planes.\n");
            }
        }
        if (mes == 7)
        {
            if (dia >= 23)
            {
                printf("LEO\nSi te ofrecen la oportunidad de participar en algun proyecto hoy, deberas tener mucho cuidado, aunque se trate de alguien en quien confias. El terreno economico podra darte algunos sustos, asi que te recomendamos que seas prudente. Leo, puede que una persona cercana a ti intente aprovecharse de tu buena fe.\n");
            }
            else
            {
                printf("CANCER\nHoy podrias encontrarte con algunos problemas, y quiza tu mismo-a provoques algunos de ellos. Tu vision de la vida sera muy negativa y radical; te creeras en posesion de la verdad, sin tener en cuenta la opinion de las personas que te rodeen. Esto podra molestar mucho a los demas. Tienes que aprender a ser mas tolerante.\n");
            }
        }
        if (mes == 8)
        {
            if (dia >= 24)
            {
                printf("VIRGO\nSi todavía estás disfrutando de tus vacaciones y has decido desplazarte a algun lugar hoy, podrias tener problemas en ese lugar; puede que no salga segun tus planes, algo que te desanimara bastante. A veces, es mejor no hacerse demasiadas ilusiones. Animate, no todo será tan negativo, si tu no haces que lo sea.\n");
            }
            else
            {
                printf("LEO\ni te ofrecen la oportunidad de participar en algun proyecto hoy, deberas tener mucho cuidado, aunque se trate de alguien en quien confias. El terreno economico podra darte algunos sustos, asi que te recomendamos que seas prudente. Leo, puede que una persona cercana a ti intente aprovecharse de tu buena fe.\n");
            }
        }
        if (mes == 9)
        {
            if (dia >= 24)
            {
                printf("LIBRA\nEs el tiempo de derribar muros; ¿quieres ir a algún lugar especial? Si es así, debes saber que este momento será el ideal para hacerlo. Sin embargo, si no te apetece viajar o no puedes hacerlo, tal vez ya sea hora de que cambies tus actitudes mentales. Dile adiós a ciertas ataduras del pasado para seguir un camino de mayor libertad e independencia personal.\n");
            }
            else
            {
                printf("VIRGO\nSi todavía estás disfrutando de tus vacaciones y has decido desplazarte a algun lugar hoy, podrias tener problemas en ese lugar; puede que no salga segun tus planes, algo que te desanimara bastante. A veces, es mejor no hacerse demasiadas ilusiones. Animate, no todo será tan negativo, si tu no haces que lo sea.\n");
            }
        }
        if (mes == 10)
        {
            if (dia >= 24)
            {
                printf("ESCORPIO\nSentiras hoy cierta falta de equilibrio debido a la aparicion de factores extranos que no podras controlar. Ademas, corres el riesgo de perder tu relacion con alguien importante para ti, tal vez se trate del amor. Si sucede esto, necesitaras un periodo para olvidarlo, pero el tiempo cura las heridas. A lo mejor, aun podrias cambiar esto.\n");
            }
            else
            {
                printf("LIBRA\nEs el tiempo de derribar muros; ¿quieres ir a algún lugar especial? Si es así, debes saber que este momento será el ideal para hacerlo. Sin embargo, si no te apetece viajar o no puedes hacerlo, tal vez ya sea hora de que cambies tus actitudes mentales. Dile adiós a ciertas ataduras del pasado para seguir un camino de mayor libertad e independencia personal.\n");
            }
        }
        if (mes == 11)
        {
            if (dia >= 23)
            {
                printf("SAGITARIO\nSi tienes un secreto bien guardado, hoy tu comportamiento hara sospechar a las personas que tienes mas cerca. Si tienes pareja desde hace tiempo, las tensiones se acentuaran, y si los problemas son con tus socios-as, puede que acabeis en los tribunales, porque será dificil que os pongáis de acuerdo por las buenas.\n");
            }
            else
            {
                printf("ESCORPIO\nSentiras hoy cierta falta de equilibrio debido a la aparicion de factores extranos que no podras controlar. Ademas, corres el riesgo de perder tu relacion con alguien importante para ti, tal vez se trate del amor. Si sucede esto, necesitaras un periodo para olvidarlo, pero el tiempo cura las heridas. A lo mejor, aun podrias cambiar esto.\n");
            }
        }
        if (mes == 12)
        {
            if (dia >= 22)
            {
                printf("CAPRICORNIO\nSi tu trabajo se encuentra lejos de tu hogar y pierdes mucho tiempo en el trayecto, cada vez se te hara mas dificil. Ademas, el ambiente laboral no sera el mas adecuado para sentirse a gusto trabajando, por eso podrias decidir buscar otro empleo. Bueno, Capricornio, por lo menos el resto de tu vida ira bien.\n");
            }
            else
            {
                printf("SAGITARIO\nSi tienes un secreto bien guardado, hoy tu comportamiento hara sospechar a las personas que tienes mas cerca. Si tienes pareja desde hace tiempo, las tensiones se acentuaran, y si los problemas son con tus socios-as, puede que acabeis en los tribunales, porque será dificil que os pongais de acuerdo por las buenas..\n");
            }
        }
    }

    system("PAUSE");
}