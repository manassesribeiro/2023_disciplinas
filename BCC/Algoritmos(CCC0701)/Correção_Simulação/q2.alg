/*
Escreva um programa que leia as notas de duas avaliações (1a e 2a avaliações) de um estudante. Após, calcular a média aritmética simples e escrever uma mensagem que informe se o estudante está aprovado, reprovado ou em recuperação. Considere que se a nota for igual ou maior do que 6 o aluno estará aprovado, se a nota for menor do que 6 mas maior ou igual a 3 o estudante estará em recuperação, mas se a nota for menor do que 3 o estudante estará reprovado. Escrever também a média calculada.
*/

Algoritmo Questão2
inicio
    real nota1, nota2, media;
    leia (nota1, nota2);

    media = (nota1 + nota2) / 2;

    se (media >= 6) então
        inicio
            escreva("Aluno aprovado com a média: " + media);
        fim
    senão se (media < 6 E media >= 3) então
        inicio
            escreva("Aluno em recuperação com a média: " + media);
        fim
    senão
        inicio
            escreva("Aluno reprovado com a média: " + media);
        fim
    fimSe
fim