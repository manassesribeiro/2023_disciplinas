/*
Escreva um programa que leia as notas de duas avaliações (1a e 2a avaliações) de um estudante. Após, calcular a média aritmética simples e escrever uma mensagem que informe se o estudante está aprovado, reprovado ou em recuperação. Considere que se a nota for igual ou maior do que 6 o aluno estará aprovado, se a nota for menor do que 6 mas maior ou igual a 3 o estudante estará em recuperação, mas se a nota for menor do que 3 o estudante estará reprovado. Escrever também a média calculada.
*/

#include <stdio.h>

int main(){
    float nota1, nota2, media;
    
    printf("Informe o valor da nota 1: ");
    scanf("%f", &nota1);
    printf("Informe o valor da nota 2: ");
    scanf("%f", &nota2);

    media = (nota1 + nota2) / 2;

    if (media >= 6){
        printf("Aluno aprovado com a média: %.2f\n", media);
    } else if (media < 6 && media >= 3){
        printf("Aluno em recuperação com a média: %.2f\n", media);
    } else{
        printf("Aluno reprovado com a média: %.2f\n", media);
    }
}