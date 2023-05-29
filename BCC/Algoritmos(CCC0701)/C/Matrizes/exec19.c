/* Leia uma matriz 10 x 10 que se refere respostas de 10 questões de múltipla escolha, referentes a 10 alunos. Leia também um vetor de 10 posições contendo o gabarito de respostas que podem ser a, b, c ou d. Seu programa deverá comparar as respostas de cada candidato com o gabarito e emitir um vetor Resultado, contendo a pontuação correspondente.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 10
#define COL 10

int main(){
    srand(time(NULL));
    char ma[LIN][COL], l, c;
    char q[4]={'a','b','c','d'};
    char gab[LIN];
    int resul[COL];

    // Procedimento para carregar a matriz aleatoriamente e inicializar o vetor de resultados
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
            ma[l][c] = q[rand() % 4]; 
        }
        resul[l] = 0;
    }
    // Procerimento para carregar o gabarito aleatoriamente
    for (c = 0; c < COL; c++){
        gab[c] = q[rand() % 4];
    }

    // Procedimento para verificar os acertos
    for (l = 0; l < LIN; l++){
        for (c = 0; c < COL; c++){
            if (ma[l][c] == gab[c]){
                resul[l]++;
            }
        }
    }

    // Procedimento para escrever a gabarito
    printf("\nGabarito:\n\t");
    for (c = 0; c < COL; c++){
        printf("%c ", gab[c]);
    }

    // Procedimento para escrever a matriz
    printf("\nMatriz:\n");
    for (l = 0; l < LIN; l++){
        printf("c. %i:\t", l);
        for (c = 0; c < COL; c++){
            printf("%c ", ma[l][c]);
        }
        printf("\t=\t%i\n", resul[l]);
    }
}
