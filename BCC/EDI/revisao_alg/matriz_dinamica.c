/*Criar uma matriz dinâmica de 10 posições de inteiros*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
#define M 10

int** alocaMemoriaMatriz(int, int);
void carregaMatriz(int**, int, int);
void escreveMatriz(int**, int, int);
void liberaMemoria(int**, int);

int main(){
    srand(time(NULL));
    int** ma;
    ma = alocaMemoriaMatriz(N, M);
    carregaMatriz(ma, N, M);
    escreveMatriz(ma, N, M);
    liberaMemoria(ma, N);
    return 0;
}

int** alocaMemoriaMatriz(int linhas, int colunas){
    int** ma, lin;
    ma = (int**) malloc(sizeof(int*) * linhas);
    for (lin = 0; lin < linhas; lin++){
        ma[lin] = (int*) malloc(sizeof(int) * colunas);
    }
    return ma;
}

void liberaMemoria(int** ma, int linhas){
    int lin;
    for (lin = 0; lin < linhas; lin++){
        free(ma[lin]);
    }
    free(ma);
}

void carregaMatriz(int** ma, int linhas, int colunas){
    int l, c;

    for (l = 0; l < linhas; l++){
        for (c = 0; c < colunas; c++){
            ma[l][c] = rand() % 100;
        }
    }
}

void escreveMatriz(int** ma, int linhas, int colunas){
    int l, c;

    for (l = 0; l < linhas; l++){
        for (c = 0; c < colunas; c++){
            printf("%i\t", ma[l][c]);
        }
        printf("\n");
    }
}