/*
    Escrever um algoritmo que lê um valor N inteiro e positivo
    e que calcula e escreve o valor de E:   
	    E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N
*/

Algoritmo Exec4
inicio
    inteiro n, cont; 
    real e; //variavel acumuladora
    cont = 1;
    e = 1;
    leia (n);
    enquanto (cont <= n)
    inicio
        e = e + (1 / cont);
        cont = cont + 1;
    fim
    escreva(e);
fim