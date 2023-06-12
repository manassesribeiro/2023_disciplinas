#include <stdio.h>

typedef struct{
    int li, ci, lf, cf;
} Roi;

// Prototipação
Roi encontraPalavra(char[]);
Roi inicializaRoi();

int main(){
    char palavra[10] = "banana";
    Roi posicaoFinal;
    posicaoFinal = encontraPalavra(palavra);
    printf("A palavra '%s' foi encontrada na posicao: (%i, %i) - (%i, %i).\n", palavra, posicaoFinal.li, posicaoFinal.ci, posicaoFinal.lf, posicaoFinal.cf);

    return 0;
}

Roi inicializaRoi(){
    Roi posicao;
    posicao.li = 0;
    posicao.lf = 0;
    posicao.ci = 0;
    posicao.cf = 0;

    return posicao;
}
Roi encontraPalavra(char palavra[]){
    Roi posicao = inicializaRoi();

    // Digamos que encontrei a palavra na posição (li=2; ci=2; lf=4; cf=3)
    posicao.li = 2;
    posicao.ci = 2;
    posicao.lf = 4;
    posicao.cf = 3;

    return posicao;
}
