#include <stdio.h>
#include <stdlib.h>
#include "../../listaEncadeadaSimples/model/listaSimples.c"

//Funções da fila
void insereNaFila(Lista*, int);
int removeDaFila(Lista*);
int filaVazia(Lista*);
int tamanhoFila(Lista*);
void mostraFila(Lista*);

void insereNaFila(Lista* fila, int dado){
    insereElementoNaLista(fila, fila->tail, dado);
}

int removeDaFila(Lista* fila){
//    return removeElementoNaLista(fila, fila->head); // Para a lista dupla
    return removeElementoNaLista(fila, NULL); // Para a lista simples
}

int filaVazia(Lista* fila){
    if (fila->size == 0)
        return 1;
    else
        return 0;
}

int tamanhoFila(Lista* fila){
    return fila->size;
}

void mostraFila(Lista* fila){
    percorreListaHeadTail(fila);
}