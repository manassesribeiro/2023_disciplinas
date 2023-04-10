Algoritmo Exec27
inicio
    real salAtual, salNovo;
    leia(salAtual);
    se (salAtual > 0 e salAtual <=300) então
        salNovo = salAtual * 1.10;
    senão se (salAtual > 300 e salAtual <=600) então
        salNovo = salAtual * 1.11;
    senão se (salAtual > 600 e salAtual <=900) então
        salNovo = salAtual * 1.12;
    senão se (salAtual > 900 e salAtual <=1500) então
        salNovo = salAtual * 1.06;
    senão se (salAtual > 1500 e salAtual <=2000) então
        salNovo = salAtual * 1.03;
    senão 
        escreva("sem aumento");
    fimse
    
    escreva(salAtual, salNovo);
fim
    
    
