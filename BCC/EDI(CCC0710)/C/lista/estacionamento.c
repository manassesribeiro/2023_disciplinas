#include "fila.c"

void estacionar(Fila*, Fila*, int);
int liberar(Fila*, Fila*, int);
void giraFila(Fila*, Nodo*);

void estacionar(Fila* principal, Fila* espera, int placa){
    if (principal->size < 10)
        insereNaFila(principal, placa);
    else
        insereNaFila(espera, placa);
        
}

int liberar (Fila* principal, Fila* espera, int placa){
    int removidoPrincipal, removidoEspera;
    
    if (listaVazia(principal))
        return -1;

    Nodo *nodoParaRemover = buscar(principal, placa);
    Nodo* head = principal->head;


    giraFila(principal, nodoParaRemover);
    removidoPrincipal = removeDaFila(principal);
    giraFila(principal, head);
    if (!listaVazia(espera)) {
        removidoEspera = removeDaFila(espera);
        insereNaFila(principal, removidoEspera);
    }
    return removidoPrincipal;
}

void giraFila(Fila* fila, Nodo* primeiro){
    Nodo* nodo;
    int removido;
    nodo = fila->head;
    do {
        removido = removeDaFila(fila);
        insereNaFila(fila, removido);
        nodo = nodo->next;
    } while(nodo != primeiro);
}

int main(){
    Fila *principal, *espera;
    int i;
    principal = criaFila();
    espera = criaFila();

    if (principal == NULL)
        printf("Problema ao alocar memória da fila principal.\n");
    if (espera == NULL)
        printf("Problema ao alocar memória da fila principal.\n");

    for (i=0; i < 10; i++){
        printf("Estacionando:  %i\n", i);
        estacionar(principal, espera, i);
    }
    escreveLista(principal);

    for (i=0; i < 10; i++){
        estacionar(principal, espera, i);
    }
    escreveLista(principal);

    for (i=0; i < 12; i++){
        liberar(principal, espera, i);
    }
    escreveLista(principal);

}