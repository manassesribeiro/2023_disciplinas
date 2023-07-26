#include <stdio.h>
#include <stdio.h>
#include <time.h>
#define N 30

typedef struct{
    float minimo;
    float maximo;
    float abertura;
    float fechamento;
} Candle; //Q1

void carregaVetorCandles(Candle[], int); //Q3
void escreveVetorCandles(Candle[], int); //Q3
void calculaVetorMediaMinimoMaximo(Candle[], float[], int); //Q4
void escreveVetorMediaMinimoMaximo(Candle[], float[], int); //Q4
int encontraMenorPrecoAbertura(Candle[], int); //Q5
int encontraMaiorPrecoFechamento(Candle[], int); //Q5

int main(){
    Candle candles[N]; //Q2
    float medias[N];
}

int encontraMenorPrecoAbertura(Candle candles[], int tam){//Q5
    int i, idx;
    float menor;
    idx = 0;
    menor = candles[idx].abertura;
    for (i = 0; i < tam; i++){
        if (candles[i].abertura < menor){
            menor = candles[i].abertura;
            idx = i;
        }
    }
    return idx;
} 

int encontraMaiorPrecoFechamento(Candle candles[], int tam){ //Q5
    int i, idx;
    float maior;
    idx = 0;
    maior = candles[idx].fechamento;
    for (i = 0; i < tam; i++){
        if (candles[i].fechamento > maior){
            maior = candles[i].fechamento;
            idx = i;
        }
    }
    return idx;
}

void calculaVetorMediaMinimoMaximo(Candle candles[], float medias[], int tam){ //Q4
    int i;
    for (i = 0; i < tam; i++){
        medias[i] = (float)((candles[i].minimo + candles[i].maximo) / 2);
    }
}

void escreveVetorMediaMinimoMaximo(Candle candles[], float medias[], int tam){ //Q4
    int i;
    for (i = 0; i < tam; i++){
        printf("\n\nDia: %i\n", i);
        printf("\tMínimo: %f\n", candles[i].minimo);
        printf("\tMaximo: %f\n", candles[i].maximo);
        printf("\Media: %f\n", medias[i]);
    }
}

void carregaVetorCandles(Candle candles[], int max){ //Q3
    int i;
    for (i = 0; i < max; i++){
        if (i == 0){
            candles[i].abertura = 0;
        } else {
            candles[i].abertura = candles[i-1].fechamento;
            candles[i].fechamento  = rand() % 101;
            candles[i].minimo = rand() % 101;
            candles[i].maximo = rand() % 101;
        }
    }
}

void escreveVetorCandles(Candle candles[], int max){ //Q3
    int i;
    for (i = 0; i < max; i++){
        printf("\n\nDia: %i\n", i);
        printf("\tAbertura: %f\n", candles[i].abertura);
        printf("\tMinimo: %f\n", candles[i].minimo);
        printf("\tMaximo: %f\n", candles[i].maximo);
        printf("\tFechamento: %f\n", candles[i].fechamento);
    }
}