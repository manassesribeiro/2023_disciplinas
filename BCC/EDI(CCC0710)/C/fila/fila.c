#include "../lista/lista.c"

// Cria um alias da Lista chamando de Fila
typedef Lista Fila;

//Prototipação
Fila* criaFila();
void insereNaFila(Fila*, int);
int removeDaFila(Fila*);
int removePrioridadeMax(Fila*);
int removePrioridadeMin(Fila*);


Fila* criaFila(){
    return criaLista();
}

void insereNaFila(Fila* fila, int dado){
    inserir(fila, fila->tail, dado);
}

int removeDaFila(Fila* fila){
    int dado = remover(fila, NULL);
    if (dado < 0)
        trataErro(dado);
    else
        return dado; 
}

int removePrioridadeMax(Fila* fila){
    Nodo* nodo;
    nodo = buscarMax(fila);
    int dado = remover(fila, nodo);
    if (dado < 0)
        trataErro(dado);
    else
        return dado; 
}

int removePrioridadeMin(Fila* fila){
    Nodo* nodo;
    nodo = buscarMin(fila);
    int dado = remover(fila, nodo);
    if (dado < 0)
        trataErro(dado);
    else
        return dado; 
}

// int main(){
//     Fila *fila;
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