/*
    Escrever um algoritmo que lê um valor N inteiro e positivo
    e que calcula e escreve o valor de E:   
	    E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N
*/

Algoritmo Exec5
inicio
    inteiro n, cont, contFat; 
    real e, fat; //variavel acumuladora
    cont = 1;
    e = 1;
    leia (n);
    enquanto (cont <= n) faça
    inicio
        contFat = cont;
        fat = 1;
        enquanto (contFat > 1) faça
        inicio
            fat = fat * contFat;
            contFat = contFat - 1;
        fim
        escreva(fat);
        fimEnquanto 
        e = e + (1 / fat);
        cont = cont + 1;
    fim
    escreva(e);
fim