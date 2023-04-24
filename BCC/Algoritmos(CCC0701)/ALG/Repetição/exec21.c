/*
Faça um algoritmo para encontrar os números primos existentes entre dois números informados pelo usuário. Lembre-se de que um número primo é aquele que é divisível somente por 1 e por ele mesmo: Exemplo, 1, 2, 3, 5, etc.
*/

Algoritmo Execicio21
Inicio
    inteiro n1, n2, aux, cont;
    lógica primo;
    leia(n1, n2);
    se (n1 > n2) então
    inicio
        aux = n1;
        n1 = n2;
        n2 = aux;
    fimSe
    enquanto (n1 < n2) faça
    inicio
        primo = V;
        cont = 2;
        enquanto (primo == V && cont < n1) faça
        inicio
            se (n1 % cont == 0) então
            inicio
                primo = F;
            fimSe
            cont = cont + 1;
        fimEnquanto
        se (primo) então
        inicio
            escreva(n1 + " é primo");
        n1 = n1 + 1;
    fimEnquanto
Fim