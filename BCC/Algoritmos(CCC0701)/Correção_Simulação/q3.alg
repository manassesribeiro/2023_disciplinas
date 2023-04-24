/*
Escreva um programa que leia uma quantidade qualquer de valores inteiros e positivos (quantidade indefinida de valores). O programa deverá parar de ler quando o usuário informar -1. Escreva os valores que são maiores do que 20 e divisíveis por 5. Também calcule e escreva a média de todos os elementos informados pelo usuário. Caso o usuário não informe nenhum valor, ou seja, digite -1 já na primeira vez, escreva uma mensagem informando ao usuário que não é possível realizar os cálculos.
*/

Algoritmo Questão3
inicio
    inteiro num, cont;
    real media;
    num = 0;
    cont = 0;
    media = 0;
    enquanto (num != -1) faça
        inicio
            leia (num);
            se (num > 0) então
                inicio
                    se (num > 20 E num mod 5 == 0) então
                        inicio
                            escreva (num);
                        fim
                    media = media + num;
                    cont = cont + 1;
                fim
            fimSe
            se (num == -1 E cont == 0) então
                inicio
                    escreva ("Sem valores para calcular");
                fim
            fimSe
        fim
    fimEnquanto
    media = media /cont;
    escreva("A média dos valores positivos informados é: " + media);
fim