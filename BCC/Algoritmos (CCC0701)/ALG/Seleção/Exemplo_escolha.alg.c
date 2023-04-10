Algoritmo Exec_Switch_case
inicio
    inteiro codigo;
    
    escolha(codigo)
      inicio
        caso 1: escreva("Alimento não perecível");
        caso 2, 3, 4: escreva("Alimento perecível");
        caso 5,6: escreva("Vestuário");
        caso 7: escreva("Higiene pessoal");
        caso 8..15: escreva("Limpeza");
        caso contrário: escreva("Inválido");
      fim
    fimEscolha
fim
        