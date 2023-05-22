/*
Escreva um programa que leia um vetor de 20 posições e escreva a posição de cada um dos elementos cujo valor seja igual a 10.
*/

#include <stdio.h>
#define TAM 10

int main(){
    int vet[TAM], i;

    //Procedimento para carregar o vetor
    for (i = 0; i < TAM; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &vet[i]);
    }

    //Procedimento para escrever o vetor
    for (i = 0; i < TAM; i++){
        printf("vet[%i]: %i\n", i, vet[i]);
    }

    //Procedimento para procurar no vetor os valores maiores do que 10
    for (i = 0; i < TAM; i++){
        if (vet[i] == 10){
            printf("Valor =10 encontrado na posicao: %i\n", i);
        }
    }
}