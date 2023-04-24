/*
    Escrever um algoritmo que lê um valor N inteiro e positivo
    e que calcula e escreve o valor de E:   
	    E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N
*/

Algoritmo Exec5_v2
inicio
    inteiro n, cont; 
    real e, fat; //variavel acumuladora
    cont = 1;
    fat = 1;
    e = 1;
    leia (n);
    enquanto (cont <= n) faça
    inicio
        fat = fat * cont;
        e = e + (1 / fat);
        cont = cont + 1;
    fim
    escreva(e);
fim