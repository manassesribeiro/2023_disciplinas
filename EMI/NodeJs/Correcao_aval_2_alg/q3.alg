/*
    (3 pontos) Faça um programa em JS que leia em vetores o nome, o custo e o preço de N produtos, onde N é uma constante de tamanho 10. Ao final deverá encontrar e escrever:
    a) o nome do produto de menor custo;
    b) o nome do produto de maior preço de venda.
*/
Algoritmo Q3
inicio
    // Declaração da constante e das variáveis
    constante N 10
    character nomeProduto[N];
    real custo[N], preco[N], menorCusto, maiorPreco;
    inteiro i, iMenorCusto, iMaiorPreco;

    // Estrutura de repetição para carregar os vetores de nome, custo e preço
    para i de 0 até N-1 passo 1 faça
    inicio
        escreva("Informe o nome do produto");
        leia(nomeProduto[i]);
        escreva("Informe o custo do produto");
        leia(custo[i]);
        escreva("Informe o preço do produto");
        leia(preço[i]);
    fimPara

    // Estrutura de repetição para encontar o menor custo e o maior preço
    menorCusto = custo[0];
    maiorPreco = preco[0];
    iMenorCusto = 0;
    iMaiorPreco = 0;
    para i de 0 até N-1 passo 1 faça
    inicio
        // Encontra o menor custo e o respectivo índice
        se (custo[i] < menorCusto) então
        inicio
            menorCusto = custo[i];
            iMenorCusto = i;
        fimSe
        // Encontra o maior preço e o respectivo índice
        se (preco[i] > maiorPreco) então
        inicio
            maiorPreco = preco[i];
            iMaiorPreco = i;
        fimSe
    fimPara

    // Escreve o nome dos produtos de menor custo e maior preço, respectivamente
    escreva("Produto de menor custo: " + nomeProduto[iMenorCusto]);
    escreva("Produto de maior Preço: " + nomeProduto[iMaiorPreco]);
fim