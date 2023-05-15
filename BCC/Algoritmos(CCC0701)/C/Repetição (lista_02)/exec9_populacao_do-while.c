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
#include <stdio.h>

int main(){
    int nFilhos, cont, contPercSal100;
    float salario, mediaSalarial, mediaNFilhos, maiorSalario,
        percAteSal100;

    cont = contPercSal100 = 0;
    mediaSalarial = mediaNFilhos = 0;
    do{
        printf("Informe o valor do salario (negativo para encerrar): ");
        scanf("%f", &salario);
        if (salario >= 0){
            //Inicialização para encontrar o maior
            if (cont == 0){
                maiorSalario = salario;
            }

            printf("Informe a quantidade de filhos: ");
            scanf("%i", &nFilhos);
            // aqui que acumula os valores
            mediaSalarial = mediaSalarial + salario;
            mediaNFilhos = mediaNFilhos + nFilhos;

            //Para encontra o maior salario
            if (salario > maiorSalario){
                maiorSalario = salario;
            }
            if (salario <= 100){
                contPercSal100 = contPercSal100 + 1;
            }
            cont = cont + 1;
        }
    } while (salario >= 0);
    //aqui que calcula as medias
    mediaSalarial = mediaSalarial / cont;
    mediaNFilhos = mediaNFilhos / cont;
    percAteSal100 = contPercSal100 / (float)cont * 100;

    printf("A media salarial da população é: %.2f\n", mediaSalarial);
    printf("A media do número de filhos da população é: %.2f\n", mediaNFilhos);
    printf("O maior salário da população é: %.2f\n",maiorSalario);
    printf("O percentual de pessoas com salário até R$ 100 é: %.2f\n",percAteSal100);

    return 0;
}