/*
    Fazer um programa que retorne quantos valores digitados pelo
    usuário são negativos. O programa deverá parar a execução quando
    o usuário informar o número zero ou for informado 20 valores.
*/

Algoritmo Exec3
inicio
    inteiro valor, cont, contNegativos;
    cont = 0;
    contNegativos = 0;
    valor = 1;
    enquanto(valor != 0 E cont < 20)
    inicio
        leia(valor);
        se (valor < 0 ) //verifica se o valor é negativo
        inicio 
            contNegativos = contNegativos + 1; // conta os negativos encontrados
        fim
        cont = cont + 1;
    fim
    escreva(contNegativos);
fim