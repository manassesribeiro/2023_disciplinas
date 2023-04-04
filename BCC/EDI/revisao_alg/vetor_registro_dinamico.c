/*Criar um vetor dinâmico de 10 posições de inteiros*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct {
    int idade;
    float salario;
} Pessoa;

Pessoa* alocaMemoria(int);
void carregaVetor(Pessoa*);
void escreveVetor(Pessoa*);
void liberaMemoria(Pessoa*);

int main(){
    srand(time(NULL));
    Pessoa *vet;
    vet = alocaMemoria(N);
    carregaVetor(vet);
    escreveVetor(vet);
    liberaMemoria(vet);
    
    return 0;
}

Pessoa* alocaMemoria(int tam){
    //alocação dinâmica do vetor
    return (Pessoa*) malloc(sizeof(Pessoa) * tam);
}

void carregaVetor(Pessoa* vet){
    int i;
    //procedimento para carregar o vetor
    for (i = 0; i < N; i++){
        vet[i].idade = rand() % 100;
        vet[i].salario = (rand() % 1000000)/100;
    }
}

void escreveVetor(Pessoa* vet){
    int i;
    //procedimento para escrever o vetor
    for (i = 0; i < N; i++){
        printf("Pessoa %i:\n", i+1);
        printf("\tIdade: %i\n", vet[i].idade);
        printf("\tSalario: %.2f\n\n", vet[i].salario);
    }
}

void liberaMemoria(Pessoa* vet){
    //liberação do valor alocado
    free(vet);
}