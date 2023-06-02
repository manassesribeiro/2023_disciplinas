/*
Uma empresa decidiu fazer um levantamento em relação aos candidatos que se apresentarem para preenchimento de vagas no seu quadro de funcionários. Supondo que você seja o programador dessa empresa, faça um programa que leia para cada candidato a idade, o sexo (M=1 ou F=2) e a experiência no serviço (S=1 ou N=2). 

Para encerrar a entrada de dados, digite zero para a idade. Calcule e escreva: 
- número de candidatos do sexo feminino; 
- número de candidatos do sexo masculino; 
- a idade média dos homens que já têm experiência no serviço; - OK
- a porcentagem dos homens com mais de 45 anos entre o total dos homens; - OK
- número de mulheres com idade inferior a 35 anos e com experiência no serviço;
- a menor idade entre as mulheres que já têm experiência no serviço.
*/

#include <stdio.h>

float calculaMedia(int h_exp, int t_hom){
    return (h_exp / t_hom);
}

float calculaPerc45(int h_45, int t_hom){
    return (h_45 / t_hom * 100);
}

// módulo que escreve os resultados

//
void carregaCandidatos(){
    int idade, sexo, exp;
    int cont_fem=0, cont_masc=0, cont_fem_35=0, cont_masc_45=0, h_exp=0;
    float media_h_exp, p_mas_45;


    do {
        printf("Informe a idade: ");
        scanf("%i", &idade);
        printf("Informe o sexo (1 - M; 2 - F): ");
        scanf("%i", &sexo);
        printf("Informe se tem experiencia (1 - SIM; 2 - NÃO): ");
        scanf("%i", &exp);

        if (sexo == 1){
            cont_masc++;
            if (exp == 1)
                h_exp++;
            if (idade > 45){
                cont_masc_45++;
        }
        }else
            cont_fem++;  
            if (idade < 35) && (exp == 1){
                cont_fem_35++;
            }
    
        media_h_exp = calculaMedia(h_exp, cont_masc);
        p_mas_45 = calculaPerc45(cont_masc_45, cont_masc);
        
        // Encontrar a menor idade entre as mulheres que já têm experiência no serviço
        // Invocar procedimento para escrever os resultados
    } while (idade > 0);
}

// função main