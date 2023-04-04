#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** alocaMemoria(int, int);
void carregaMatriz(int**, int, int);
void escreveMatriz(int**, int, int);
void liberaMemoriaMatriz(int**, int);

int** alocaMemoria(int linhas, int colunas){
    int **ma, l;
    ma = (int**) malloc(sizeof(int*) * linhas);
    for (l=0; l < linhas; l++){
        ma[l] = (int*) malloc(sizeof(int) * colunas);
    }

    return ma;
}

void liberaMemoriaMatriz(int** ma, int linhas){
    int l;
    for (l=0; l < linhas; l++){
        free(ma[l]);
    }
    free(ma);
}

void carregaMatriz(int** ma, int linhas, int colunas){
    int l, c;

    for(l = 0; l < linhas; l++){
        for (c = 0; c < colunas; c++){
            ma[l][c] = rand() % 255;
        }
    }
}

void escreveMatriz(int** ma, int linhas, int colunas){
    int l, c;

    printf("...: Imagem :...\n");
    for(l = 0; l < linhas; l++){
        for (c = 0; c < colunas; c++){
            printf("%i\t", ma[l][c]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main(){
    srand(time(NULL));
    int** ma, L=10, C=10;
    ma = alocaMemoria(L, C);
    carregaMatriz(ma, L, C);
    escreveMatriz(ma, L, C);
    liberaMemoriaMatriz(ma, L);
    return 0;
}