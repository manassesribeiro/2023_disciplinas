#include "lista.c"

//Prototipação
void insereNaFila(Lista*, int);
void removeDaFila(Lista*);

// int main(){
//     Lista *fila;
//     fila = criaLista();

//     // {10, 5, 7, 22, 13, 78, 229}
//     // Para inserir elementos na FILA
//     insereNaFila(fila, 10);
//     insereNaFila(fila, 5);
//     insereNaFila(fila, 7);
//     insereNaFila(fila, 22);
//     insereNaFila(fila, 13);
//     insereNaFila(fila, 78);
//     insereNaFila(fila, 229);

//     escreveLista(fila);

//     // Para remover elementos
//     removeDaFila(fila);
//     escreveLista(fila);

//     removeDaFila(fila);
//     escreveLista(fila);

//     removeDaFila(fila);
//     escreveLista(fila);
    
//     removeDaFila(fila);
//     escreveLista(fila);

// }

void insereNaFila(Lista* fila, int dado){
    inserir(fila, fila->tail, dado);
}

void removeDaFila(Lista* fila){
    trataErro(remover(fila, NULL));
}