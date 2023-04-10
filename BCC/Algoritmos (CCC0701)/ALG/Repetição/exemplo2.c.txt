Algoritmo Exemplo2
inicio
    inteiro n1, n2, soma, aux;
    soma = 0;
    leia (n1, n2);
    
    se (n1 > n2) então
    inicio
        aux = n1;
        n1 = n2;
        n2 = aux;
    fim
    fimSe
    
    enquanto (n1 <= n2) faça
    inicio
        se (n1 mod 2 == 0) então
        inicio
            soma = soma + n1;
        fim
        fimSe
        n1 = n1 + 1;
    fim
    fimSe

    escreva(soma);
fim