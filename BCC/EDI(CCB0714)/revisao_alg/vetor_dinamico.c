/*Criar um vetor dinâmico de 10 posições de inteiros*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int* alocaMemoria(int);
void carregaVetor(int*);
void escreveVetor(int*);
void liberaMemoria(int*);

int main(){
    srand(time(NULL));
    int *vet;
    vet = alocaMemoria(N);
    carregaVetor(vet);
    escreveVetor(vet);
    liberaMemoria(vet);
    
    return 0;
}

int* alocaMemoria(int tam){
    //alocação dinâmica do vetor
    return (int*) malloc(sizeof(int) * tam);
}

void carregaVetor(int* vet){
    int i;
    //procedimento para carregar o vetor
    for (i = 0; i < N; i++){
        vet[i] = rand() % 100;
    }
}

void escreveVetor(int* vet){
    int i;
    //procedimento para escrever o vetor
    for (i = 0; i < N; i++){
        printf("%i, ", vet[i]);
    }
}

void liberaMemoria(int* vet){
    //liberação do valor alocado
    free(vet);
}