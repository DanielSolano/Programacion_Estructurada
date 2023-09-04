// Solano Meza Angel Daniel Matr. 372453
// 03/09/2023
// Jugar chichampu con estructuras de seleccion multiple
// ADSM_ACT4_9_932
#include <stdio.h>
#include <time.h>
int main() {
    int j1, j2;

    srand(time(NULL)); 
    j2 = rand() % 3 + 1; //Genera un numero entre 1 y 3 que es la tirada de la computadora

    printf("Ingresa tu jugada (1. Piedra, 2. Papel, 3. Tijera): ");
    scanf("%d", &j1);

    if((j1 <= 0) && (j1 > 3))
    {
    printf("Opcion incorrecta");
    }
    else
    {
        //Jugador 1 es humano, jugador 2 computadora
        switch (j1) {
            case 1:
                switch (j2) {
                    case 1:
                        printf("Empate, ambos eligieron piedra");
                        break;
                    
                    case 2:
                        printf("Gana J2, J1: Piedra J2: Papel)");
                        break;
                    
                    case 3:
                        printf("Gana J1, J1: Piedra J2: Tijeras)");
                        break;
                }
                break;
            
            case 2:
                switch (j2) {
                    case 1:
                        printf("Gana J1, J1: Papel J2 Piedra)");
                        break;
                    
                    case 2:
                        printf("Empate, ambos eligieron papel");
                        break;
                    
                    case 3:
                        printf("Gana J2, J1: Papel J2: Tijeras)");
                        break;
                }
                break;
            
            case 3:
                switch (j2) {
                    case 1:
                        printf("Gana J2, J1: Tijeras J2: Piedra)");
                        break;
                    
                    case 2:
                        printf("Gana J1, J1: Tijeras J2: Papel)");
                        break;
                    
                    case 3:
                        printf("Empate, ambos eligieron papel");
                        break;
                }
                break;
        }
    }

    return 0;
}