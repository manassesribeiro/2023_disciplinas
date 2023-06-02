/*
    Construa um programa em C modularizado que calcule a média aritmética para 50 alunos considerando quatro notas bimestrais (n1, n2, n3, n4) e avalie se cada aluno foi aprovado (média >= 7) ou reprovado (média < 7).
*/

#include <stdio.h>
#define TAM 5
/*
Modulos:
- calcular a média(n1, n2, n3, n4) -> media - OK
- carregar notas - OK
- avaliar a media(media) -> aprovado/reprovado - OK
- escreve o resultado - OK
*/
// Módulo para calcular a média
float calculaMedia(float n1, float n2, float n3, float n4){
    return ((n1 + n2 + n3 + n4) / 4);
}

//Módulo avalia media
int avaliaMedia(float media){
    if (media >= 7)
        return 1;
    else
        return 0;
}

//Módulo escreve resultado
void escreveResultado(float media){
    if (avaliaMedia(media))
        printf("\nAluno aprovado com a media: %.2f\n", media);
    else
        printf("\nAluno reaprovado com a media: %.2f\n", media);
}

// Módulo que carrega as notas e retorna a média calculada
float carregaNotas(int i){
    float n1, n2, n3, n4;
    printf("Informe a nota 1 para o aluno %i: ", i);
    scanf("%f", &n1);
    printf("Informe a nota 2 para o aluno %i: ", i);
    scanf("%f", &n2);
    printf("Informe a nota 3 para o aluno %i: ", i);
    scanf("%f", &n3);
    printf("Informe a nota 4 para o aluno %i: ", i);
    scanf("%f", &n4);

    return calculaMedia(n1, n2, n3, n4);
}

int main(){
    float media;
    int i;
    for (i=0; i < TAM; i++){
        media = carregaNotas(i);
        escreveResultado(media);
    }
}