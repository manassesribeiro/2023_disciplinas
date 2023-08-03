/*
Dada uma matriz ma(N,M) de inteiros faça um programa em C que:
  - Carregue e escreva a matriz considerando que N e M serão duas constantes de valores 10 e 10, respectivamente;
  - Crie 2 vetores, sl(N) e mc(M), que contenham, respectivamente, as somas dos valores ímpares das linhas e a média dos valores pares das colunas da matriz ma(N,M). Escreva os vetores de maneira que o usuário consiga interpretar seu conteúdo adequadamente;
  - Calcule e escreva a diferença entre a diagonal principal e a diagonal secundária da matriz.

Atenção, para esta questão considerar o uso dos conteúdos:
  - manipulação de vetores e matrizes;
  - modularização e passagem de parâmetros;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Prototipação
int** alocaMemoriaMatriz(int, int);
int* alocaMemoriaVetorInteiro(int);
float* alocaMemoriaVetorReal(int);
void liberaMemoriaMatriz(int**, int);
void liberaMemoriaVetorInteiro(int*);
void liberaMemoriaVetorReal(float*);
void carregaMatriz(int**, int, int);
void escreveMatriz(int**, int*, float*, int, int);
int perguntaLinha();
int perguntaColuna();
void somaLinhas(int**, int*, int, int);
void mediaColunas(int**, float*, int, int);
int diferencaDiagonais(int**, int, int);

int main(){
    int **ma, *sl, n, m;
    float *mc;
    srand(time(NULL));

    n = perguntaLinha();
    m = perguntaColuna();

    ma = alocaMemoriaMatriz(n, m);
    sl = alocaMemoriaVetorInteiro(n);
    mc = alocaMemoriaVetorReal(m);
    
    if (ma == NULL || sl == NULL || mc == NULL){
        printf("Problemas ao alocar memoria.\n");
        return -1;
    }

    carregaMatriz(ma, n, m);
    somaLinhas(ma, sl, n, m);
    mediaColunas(ma, mc, n, m);
    escreveMatriz(ma, sl, mc, n, m);
    printf("\n\nDiferenca das diagonais: %i\n", diferencaDiagonais(ma, n, m));

    liberaMemoriaMatriz(ma, n);
    liberaMemoriaVetorInteiro(sl);
    liberaMemoriaVetorReal(mc);
    return 0;
}

int perguntaLinha(){
    int n;
    printf("Informe a quantidade de linhas da matriz: ");
    scanf("%i", &n);
    return n;
}

int perguntaColuna(){
    int m;
    printf("Informe a quantidade de colunas da matriz: ");
    scanf("%i", &m);
    return m;
}

int** alocaMemoriaMatriz(int n, int m){
    int **ma, i;
    ma = (int**) malloc(sizeof(int*) * n);
    for (i=0; i<n; i++){
        ma[i] = (int*) malloc(sizeof(int) * m);
    }
    return ma;
}

int* alocaMemoriaVetorInteiro(int tam){
    int *vet;
    vet = (int*) malloc(sizeof(int) * tam);
    return vet;
}
float* alocaMemoriaVetorReal(int tam){
    float *vet;
    vet = (float*) malloc(sizeof(float) * tam);
    return vet;
}

void liberaMemoriaMatriz(int **ma, int n){
    int i;
    for (i=0; i<n; i++){
        free(ma[i]);
    }
    free(ma);
}

void liberaMemoriaVetorInteiro(int *vet){
    free(vet);
}

void liberaMemoriaVetorReal(float *vet){
    free(vet);
}

void carregaMatriz(int** ma, int n, int m){
    int l, c;
    for (l=0; l<n; l++){
        for (c=0; c<m; c++){
            ma[l][c] = rand() % 10;
        }
    }
}
void escreveMatriz(int **ma, int *sl, float *mc, int n, int m){
    int l, c;
    for (l=0; l<n; l++){
        for (c=0; c<m; c++){
            printf("\t%i", ma[l][c]);
        }
        printf("\t =\t%i\n", sl[l]);
    }
    for (c=0; c<m; c++){
        printf("\t%.2f", mc[c]);
    }
}

void somaLinhas(int** ma, int* sl, int n, int m){
    int l,c;
    for (l = 0; l < n; l++){
        sl[l] = 0;
        for (c = 0; c < m; c++){
            if (ma[l][c] % 2 != 0){
                sl[l]+=ma[l][c];
            }
        }
    }
}
void mediaColunas(int** ma, float* mc, int n, int m){
    int l,c;
    for (c = 0; c < m; c++){
        mc[c] = 0;
        for (l = 0; l < n; l++){
            if (ma[l][c] % 2 == 0){
                mc[c]+=ma[l][c];
            }
        }
        mc[c] = mc[c] / m;
    }
}

int diferencaDiagonais(int **ma, int n, int m){
    int l, c, dif, somaDP, somaDS;
    somaDP = somaDS = 0;
    for (l = 0; l < n; l++){
        somaDP+=ma[l][l];
    }

    c = m-1;
    for (l = 0; l < n; l++){
        somaDS+=ma[l][c];
        c--;
    }    

    return (somaDP - somaDS);
}