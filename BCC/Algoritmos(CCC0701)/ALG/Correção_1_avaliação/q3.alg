/*
(2 pontos) Faça um algoritmo que leia dois números, n1 e n2, calcule e imprima todos os números primos existentes entre n1 e n2, inclusive, sabendo que são números naturais fornecidos pelo usuário.
*/
Algoritmo Questao3
inicio
    inteiro n1, n2, aux, cont;
    lógica primo;

    leia(n1, n2);

    se (n1 > 0 E n2 > 0) então
    inicio
        se (n1 > n2) então
        inicio
            aux = n1;
            n1 = n2;
            n2 = aux;
        fimse

        enquanto (n1 <= n2) faça
        inicio
            cont = 2;
            primo = V;
            enquanto (cont < n1 E primo) faça
            inicio
                se (n1 mod cont == 0) então
                    primo = F;
                cont = cont + 1;
            fimEnquanto
            se (primo) então
                escreva(n1 + " é primo");
            n1 = n1 + 1;
        fimEnquanto
    senão
        escreva("Informe números naturais");
    fimse
fim