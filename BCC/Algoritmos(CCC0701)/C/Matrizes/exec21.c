/*
    O tempo que um determinado avião gasta para percorrer o trecho entre duas  localidades distintas está disponível em uma tabela simétrica. Faça um algoritmo que leia a tabela e informe ao usuário o tempo necessário para percorrer duas cidades por ele fornecidas, até o momento que ele fornecer duas cidades iguais (origem e destino).

    Desafios:
    1) Faça um algoritmo que mostre a tabela sem repetições (apenas o triângulo superior ou o inferior).
    2) Faça um algoritmo que permita ao usuário informar várias cidades, até inserir cidades iguais, e que mostre o tempo total para cumprir todo o percurso especificado entre as cidades fornecidas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

int main(){
    srand(time(NULL));
    int ma[TAM][TAM], l, c;

    // Procedimento para carregar apenas a parte superior da matriz simétrica
    for (l = 0; l < TAM-1; l++){
        for (c = l+1; c < TAM; c++){
            ma[l][c] = rand() % 100; 
        }
    }

    // Procedimento para escrever a parte superior da matriz simétrica
    printf("\nMatriz:\n");
    for (l = 0; l < TAM; l++){
        for (c = 0; c < TAM; c++){
            if (c < l+1) {
                printf("-\t");
            } else {
                printf("%i\t", ma[l][c]);
            }
        }
        printf("\n");
    }

    // Procedimento para encontrar as distâncias
    int cidadeA, cidadeB, aux, soma=0;
    do{
        printf("Informe um percurso valido:\n");
        do {
            printf("\tInforme a cidade A entre 0 e %i: ", TAM-1);
            scanf("%i", &cidadeA);
            printf("\tInforme a cidade B entre 0 e %i: ", TAM-1);
            scanf("%i", &cidadeB);
        } while ((cidadeA > TAM-1 || cidadeA < 0) || (cidadeB > TAM-1 || cidadeB < 0));

        if (cidadeA > cidadeB){
            aux = cidadeA;
            cidadeA = cidadeB;
            cidadeB = aux;
        }
        if (cidadeA < cidadeB){
            printf("\tDistancia entre as cidades %i e %i eh a %i\n", cidadeA, cidadeB, ma[cidadeA][cidadeB]);
            soma+=ma[cidadeA][cidadeB];
        }
        if (cidadeA == cidadeB){
            printf("Distancia total do percurso eh: %i\n", soma);
        } 
    } while(cidadeA != cidadeB);
}