/*
    Matriz dinâmica para armazenar dados de uma pessoa para IRPF
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int idade;
    int n_filhos;
    float salario;
} IRPF;

IRPF* alocaMemoria(int);
void carregaVetor(IRPF*, int);
void escreveVetor(IRPF*, int);

//Função que aloca dinamicamente a memoria retornando o ponteiro
IRPF* alocaMemoria(int tam){
    if (tam > 1)
        return (IRPF*) malloc(sizeof(IRPF) * tam);
    else{
        printf("Valor do tamanho precisa ser maior do que 1.\n");
        return NULL;
    }
}

void carregaVetor(IRPF* irpf, int tam){
    int i;
    //Carrega o vetor randomicamente
    for (i=0; i < tam; i++){
        irpf[i].idade = (int) rand() % 100;
        irpf[i].n_filhos = (int) rand() % 10;
        irpf[i].salario = rand() % 100000;
    }
}

void escreveVetor(IRPF* irpf, int tam){
    int i;

    for (i = 0; i < tam; i++){
        printf("Numero cliente: %i", i);
        printf("\tIdade: %i", irpf[i].idade);
        printf("\tNum Filhos: %i", irpf[i].n_filhos);
        printf("\tSalario: %.2f\n\n", irpf[i].salario);
    }
}

int main(){
    srand(time(NULL));
    IRPF* irpf;
    int tam;
    printf("Informe o tamanho do vetor: ");
    scanf("%i", &tam);

    irpf = alocaMemoria(tam);
    if (irpf == NULL){
        printf("Memoria nao alocada. Processo abortado!\n");
        return -1;
    }

    carregaVetor(irpf, tam);
    escreveVetor(irpf, tam);

    free(irpf);
    
    return 0;
}
