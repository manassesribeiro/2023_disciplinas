#include <stdio.h>

int main(){
    char *nome;
    int idade;

    printf("Digite seu nome: ");
    scanf("%s", nome);
    printf("Digite sua idade: ");
    scanf("%i", &idade);

    printf("Nome: %s\nIdade: %i\n", nome, idade);
}