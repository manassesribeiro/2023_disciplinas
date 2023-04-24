/*
Escreva um programa que leia uma quantidade qualquer de valores inteiros e positivos (quantidade indefinida de valores). O programa deverá parar de ler quando o usuário informar -1. Escreva os valores que são maiores do que 20 e divisíveis por 5. Também calcule e escreva a média de todos os elementos informados pelo usuário. Caso o usuário não informe nenhum valor, ou seja, digite -1 já na primeira vez, escreva uma mensagem informando ao usuário que não é possível realizar os cálculos.
*/

#include <stdio.h>

int main(){
    int num, cont;
    float media;
    num = 0;
    cont = 0;
    media = 0;
    while (num != -1){
        printf("Informe um número: ");
        scanf("%i", &num);

        if (num > 0){
            if (num > 20 && num % 5 == 0){
                printf("O número informado é maior do que 20 e divisível por 5: %i\n", num);
            }
                
            media = media + num;
            cont = cont + 1;
        }
        if (num == -1 && cont == 0){
                printf("Sem valores para calcular\n");
        }
    }
    media = media /cont;
    printf("A média dos valores positivos informados é: %f\n", media);

}