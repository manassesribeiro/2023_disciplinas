/*
Faça um programa em C que carregue e escreva uma matriz de inteiros. Além disso, o programa deverá calcular a média dos valores da matriz, escrevê-la, e escrever também os valores da diagonal principal que sejam maiores do que a média calculada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 10
#define COL 10

int main(){
    srand(time(NULL));
    int ma[LIN][COL], l, c;
    float media=0;

    // Procedimento para carregar a matriz
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
//            printf("Informe o valor para ma[%i][%i]: ", l, c);
//            scanf("%i", &ma[l][c]);
            ma[l][c] = rand() % 100; // Para carregar a matriz aleatoriamente
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

    // Procedimento para calcular a média da matriz
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
            media+=ma[l][c]; // media = media + ma[l][c]
        }
    }
    media/=(LIN*COL); // media = media / (LIN * COL)
    printf("\nMedia dos valores da matriz: %.2f\n", media);

    // Procedimento para encontrar os valores da diagonal principal maiores do que a media
    printf("Valores da diagonal principal maiores do que a media:\n");
    for (l = 0; l < LIN; l++){
        if (ma[l][l] > media){
            printf("%i, ", ma[l][l]);
        }
    }
}
