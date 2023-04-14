#include <stdio.h>
#include <stdlib.h>
#include "../../fila/model/fila.c"

//Funções do estacionamento
void estacionar(Lista*, Lista*, int);
int partida(Lista*, Lista*);

//Implementação
void estacionar(Lista* principal, Lista* espera, int placa){
    if (tamanhoFila(principal) < 10){
        insereNaFila(principal, placa);
    } else {
        insereNaFila(espera, placa);
    }
}

int partida(Lista* principal, Lista* espera){
    int placaRemovida, placa;
    if ((tamanhoFila(principal) > 9) && (filaVazia(espera) != 1)){
        placaRemovida = removeDaFila(principal);
        placa = removeDaFila(espera);
        insereNaFila(principal, placa);
    } else {
        placaRemovida = removeDaFila(principal);
    }
    return placaRemovida;
}

