/*
    Q1: (3 pontos) Escreva um programa em JS que leia um vetor de 10 posições e escreva os elementos que são maiores do que 10.
*/

Algoritmo Q1
inicio
    constante TAM 10
    inteiro vet[TAM], i;

    // Procedimento para carregar o vetor
    para i de 0 até TAM-1 passo 1 faça
    inicio
        escreva("Informe um valor para vet[%i]: " % i);
        leia(vet[i]);
    fimPara

    // Procedimento para escrever os valores maiores do que 10 do vetor
    para i de 0 até TAM-1 passo 1 faça
    inicio
        se (vet[i] > 10) então
            escreva(vet[i]);
        fimSe
    fimPara
fim