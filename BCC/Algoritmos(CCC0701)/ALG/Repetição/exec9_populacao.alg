/*
    9) A prefeitura de uma cidade fez uma pesquisa entre seus
    habitantes, coletando dados sobre o número de filhos e
    salário. A prefeitura deseja saber: 
        1) média do salário da população; 
        2) média do número de filhos; 
        3) maior salário; 
        4) percentual de pessoas com salário até R$100,00.

    O final da leitura de dados se dará com a entrada de um
    salário negativo.
*/
Algoritmo Exec9_populacao
inicio
    inteiro nFilhos, cont, contPercSal100;
    real salario, mediaSalarial, mediaNFilhos, maiorSalario,
        percAteSal100;

    cont = contPercSal100 = 0;
    salario = 0;
    mediaSalarial = mediaNFilhos = 0;
    enquanto (salario >= 0) faça
    inicio
        leia(salario);
        se (salario >= 0) então
        inicio
            //Inicialização para encontrar o maior
            se (cont == 0) então
            inicio
                maiorSalario = salario;
            fimSe

            leia (nFilhos);
            // aqui que acumula os valores
            mediaSalarial = mediaSalarial + salario;
            mediaNFilhos = mediaNFilhos + nFilhos;

            //Para encontra o maior salario
            se (salario > maiorSalario) então
            inicio
                maiorSalario = salario;
            fimSe

            se (salario <= 100) então
            inicio
                contPercSal100 = contPercSal100 + 1;
            fimSe

            cont = cont + 1;
        fimSe
    fimEnquanto
    //aqui que calcula as medias
    mediaSalarial = mediaSalarial / cont;
    mediaNFilhos = mediaNFilhos / cont;
    percAteSal100 = contPercSal100 / cont * 100;

    escreva(mediaSalarial);
    esceva(mediaNFilhos);
    escreva(maiorSalario);
    escreva(percAteSal100);
fim