/*
Utilizando vetores, crie um programa que organize uma quantidade qualquer de números inteiros fornecidos pelo usuário da seguinte forma: primeiro os números pares em ordem crescente e depois os números ímpares em ordem decrescente.
*/
#include <stdio.h>
#define TAM 10

int main(){
    int vet[TAM], par[TAM], impar[TAM];
    int i, j, aux, iPar, iImpar;
    iPar = iImpar = 0;

    // Procedimento para carregar o vetor vet
    for (i = 0; i < TAM; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &vet[i]);
    }

    // Procedimento para separar o vetor vet em pares e impares
    for (i = 0; i < TAM; i++){
        if (vet[i] % 2 == 0){
            par[iPar] = vet[i];
            iPar++;
        } else {
            impar[iImpar] = vet[i];
            iImpar++;
        }
    }

    // Procedimento para ordenar em ordem crescente
    for (i = 1; i < iPar; i++){
        for (j = 0; j < iPar-i; j++){
            if (par[j] > par[j+1]){
                aux = par[j];
                par[j] = par[j+1];
                par[j+1] = aux;
            }
        }
    }

    //Procedimento para escrever o vetor de pares
    printf("\nVetor de pares ordenado: \n");
    for (i = 0; i < iPar; i++){
        printf("%i, ", par[i]);
    }

    // Procedimento para ordenar os impares em ordem decrescente
    for (i = 1; i < iImpar; i++){
        for (j = 0; j < iImpar-i; j++){
            if (impar[j] < impar[j+1]){
                aux = impar[j];
                impar[j] = impar[j+1];
                impar[j+1] = aux;
            }
        }
    }

    //Procedimento para escrever o vetor de impares ordenado
    printf("\nVetor de impares ordenado: \n");
    for (i = 0; i < iImpar; i++){
        printf("%i, ", impar[i]);
    }

}