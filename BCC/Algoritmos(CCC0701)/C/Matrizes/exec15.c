/* Escreva um algoritmo que lê uma matriz M(5,5) e calcula as somas:
    - da linha 4 de M.
    - da coluna 2 de M.
    - da diagonal principal.
    - da diagonal secundária.
    - de todos os elementos da matriz.
    - Escreva estas somas e a matriz.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 5
#define COL 5

int main(){
    srand(time(NULL));
    int ma[LIN][COL], l, c;
    int soma=0;
    int somaLinha4 = 0;
    int somaColuna2 = 0;
    int somaDiagPrinc = 0;
    int somaDiagSec = 0;

    // Procedimento para carregar a matriz
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
            ma[l][c] = rand() % 10; // Para carregar a matriz aleatoriamente
        }
    }

    // Procedimento para escrever a matriz
    printf("\nMatriz:\n");
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
            printf("%i\t", ma[l][c]);
        }
        printf("\n");
    }

    // Procedimento para calcular a soma apenas da linha 4 da matriz
    l = 4; //para somar apenas os elementos da linha 4
    for (c = 0; c < COL; c++){
        somaLinha4+=ma[l][c]; 
    }

    // Procedimento para calcular a soma apenas da coluna 2 da matriz
    c = 2; //para somar apenas os elementos da coluna 2
    for (l = 0; l < LIN; l++){
        somaColuna2+=ma[l][c]; 
    }

    // Procedimento para somas os valores da diagonal principal
    for (l = 0; l < LIN; l++){
        somaDiagPrinc+=ma[l][l];
    }

    // Procedimento para somas os valores da diagonal secundária
    c = COL - 1;
    for (l = 0; l < LIN; l++){
        somaDiagSec+=ma[l][c];
        c--;
    }

    // Procedimento para somas de todos os valores da matriz
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
            soma+=ma[l][c];
        }
    }

    printf("\nSoma dos valores da linha 4: %i\n", somaLinha4);
    printf("Soma dos valores da coluna 2: %i\n", somaColuna2);
    printf("Soma dos valores da diagonal principal: %i\n", somaDiagPrinc);
    printf("Soma dos valores da diagonal secundaria: %i\n", somaDiagSec);
    printf("Soma dos valores da matriz: %i\n", soma);
}
