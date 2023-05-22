/*
Ler do teclado 12 números inteiros e armazená-los em um vetor N. Em seguida, copiar os elementos pares divisíveis por 3 para o vetor X e os ímpares divisíveis por 5 para o vetor Y.
*/

#include <stdio.h>
#define TAM 10

int main(){
    int n[TAM], i, j, aux;

    //Procedimento para carregar o vetor
    for (i = 0; i < TAM; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &n[i]);
    }

    //Procedimento para colocar em ordem
    for (i = 0; i < TAM; i++){
        for (j=1; j < TAM-1-i; j++){
            if (n[i] > n[j]){
                aux = n[i];
                n[i] = n[j];
                n[j] = aux;
            }
        }
}