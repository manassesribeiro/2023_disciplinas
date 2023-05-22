/*
Escreva um programa que leia um vetor de 10 posições e escreva os elementos que são maiores do que 20. Caso não haja nenhum elemento maior do que 20, mostrar uma mensagem de aviso ao usuário.
*/

#include <stdio.h>
#define TAM 10

int main(){
    int vet[TAM], i, maiorDoQue20;
    maiorDoQue20 = 0;

    //Procedimento para carregar o vetor
    for (i = 0; i < TAM; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &vet[i]);
    }

    //Procedimento para procurar no vetor o valor maior do que 20
    for (i = 0; i < TAM; i++){
        if (vet[i] > 20){
            maiorDoQue20 = 1;
            printf("%i, ", vet[i]);
        }
    }

    if (!maiorDoQue20)
        printf("Nenhum valor maior do que 20.\n");

}