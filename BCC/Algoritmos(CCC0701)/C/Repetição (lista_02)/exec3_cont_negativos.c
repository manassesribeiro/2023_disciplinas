/*
    Fazer um programa que retorne quantos valores digitados pelo
    usuário são negativos. O programa deverá parar a execução quando
    o usuário informar o número zero ou for informado 20 valores.
*/
#include <stdio.h>

int main()
{
    int valor, cont, contNegativos;
    cont = 0;
    contNegativos = 0;
    valor = 1;
    while(valor != 0 && cont < 20)
    {
        printf("Informe um valor (%i): ", cont+1);
        scanf("%i", &valor);

        if (valor < 0 ) //verifica se o valor é negativo
        { 
            contNegativos = contNegativos + 1; // conta os negativos encontrados
        }
        cont = cont + 1;
    }
    printf("A quantidade de negativos informado é: %i\n", contNegativos);
}