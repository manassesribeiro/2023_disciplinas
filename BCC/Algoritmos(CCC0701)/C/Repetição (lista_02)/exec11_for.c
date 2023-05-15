/*
    Calcular a soma dos 100 primeiros nº naturais.
*/

#include <stdio.h>

int main(){
    int cont, soma;
    soma = 0;
    for (cont=1; cont <= 100; cont++){
        soma+=cont; // soma = soma + cont;
    }
    printf("A soma dos primeiros 100 naturais eh: %i", soma);
}