/*
Ler do teclado 12 números inteiros e armazená-los em um vetor N. Em seguida, copiar os elementos pares divisíveis por 3 para o vetor X e os ímpares divisíveis por 5 para o vetor Y.
*/

#include <stdio.h>
#define TAM 12

int main(){
    int n[TAM], x[TAM], y[TAM], i, iX, iY;

    //Procedimento para carregar o vetor
    for (i = 0; i < TAM; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &n[i]);
    }

    //Procedimento para separar o vetor
    iX = iY = 0;
    for (i = 0; i < TAM; i++){
        if (n[i] % 2 == 0 && n[i] % 3 == 0){
            x[iX] = n[i];
            iX++;
        } else if (n[i] % 2 != 0 && n[i] % 5 == 0){
            y[iY] = n[i];
            iY++;
        }
    }

    //Procedimento para escrever o vetor n
    printf("\nValores no vetor 'n'\n");
    for (i = 0; i < TAM; i++){
        printf("n[%i]: %i\n", i, n[i]);
    }
    printf("\nValores no vetor 'x'\n");
    //Procedimento para escrever o vetor X
    for (i = 0; i < iX; i++){
        printf("x[%i]: %i\n", i, x[i]);
    }
    printf("\nValores no vetor 'y'\n");
    //Procedimento para escrever o vetor Y
    for (i = 0; i < iY; i++){
        printf("y[%i]: %i\n", i, y[i]);
    }
}