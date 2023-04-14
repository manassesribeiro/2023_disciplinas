/*
    Fazer um programa que calcule a tabuada de qualquer número,
    e o limite de cálculo deve ser definido pelo usuário.
*/
Algoritmo Exec2
inicio
    inteiro tabuada, limite, cont, result; //1º passo: declaração das variáveis
    leia (tabuada, limite); // 2º passo: entrada dos dados

    cont = 1; //inicialização do contador
    enquanto (cont <= limite) 
    inicio
        result = tabuada * cont;
        escreva(result);
        cont = cont + 1; //incremento do passo
    fim
fim