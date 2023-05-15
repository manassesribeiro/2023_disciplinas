/*
    Faça um programa em C que carregue e escreva um vetor de inteiros de tamanho N, onde N é 10. Além disso, o programa deverá calcular a média dos valores do vetor, escrevê-la, e escrever também os valores do vetor maiores do que a média calculada.
*/
//Diretivas de pré-processamento
#include <stdio.h>
#define N 10 // Declara uma constante N de tamanho 10

int main(){
    int vet[N], i;
    float media;

    //Procedimento para carregar o vetor
    for (i = 0; i < N; i++){
        printf("Informe o valor para vet[%i]: ", i);
        scanf("%i", &vet[i]);
    }

    //Procedimento para escrever o vetor
    for (i = 0; i < N; i++){
        printf("%i, ", vet[i]);
    }

    //Procedimento para calcular a media
    media = 0;
    for (i = 0; i < N; i++){
        media += vet[i]; //Equivalente a media = media + vet[i]
    }
    media/=N; //Equivalente a media = media / N

    printf("Media: %f\n", media);
    //Procedimento para escrever os valores do vetor que são maiores do que a media
    for (i= 0; i < N; i++){
        if (vet[i] > media)
            printf("%i, ", vet[i]);
    }
}
