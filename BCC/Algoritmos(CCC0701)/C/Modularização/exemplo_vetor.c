#include <stdio.h>
#include <stdlib.h>
#define TAM 10

//Prototipação
void escreveVetor(int[], int);
void carregaVetor(int[], int);
void alteraVetor(int[], int);
int somaVetor(int[], int);
void alteraValor(int*);

int main(){
    int vet[TAM], *vlr;
    escreveVetor(vet, TAM);
    carregaVetor(vet, TAM);
    escreveVetor(vet, TAM);
    alteraVetor(vet, TAM);
    escreveVetor(vet, TAM);
    printf("\n\nSoma do vetor: %i\n", somaVetor(vet, TAM));

    int x = 10;
    alteraValor(&x);

    printf("Valor: %i", x);

    return 0;
}

void alteraValor(int *valor){
    (*valor) *= 2; // *valor = *valor * 2;
    printf("Valor: %i\n", *valor);
}

void alteraVetor(int vet[], int tam){
    int i;
    for (i=0; i<tam; i++){
        vet[i] = vet[i] * 2;
    }
}

int somaVetor(int vet[], int tam){
    int i, soma=0;
    for (i=0; i<tam; i++){
        soma = soma + vet[i];
    }
    return soma;
}

void carregaVetor(int vet[], int tam){
    int i;
    printf("\n\n");
    for (i=0; i<tam; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &vet[i]);
    }
}

void escreveVetor(int vet[], int tam){
    int i;
    printf("\n\n");
    for (i=0; i<tam; i++){
        printf("%i, ", vet[i]);
    }
}

