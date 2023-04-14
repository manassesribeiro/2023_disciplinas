#include "../model/listaSimples.c"

int main(){
    Lista* lista1;
    Nodo* pivo;

    lista1 = alocaMemoriaLista();
    insereElementoNaLista(lista1, NULL, 10);
    insereElementoNaLista(lista1, lista1->head, 5);
    insereElementoNaLista(lista1, lista1->tail, 7);
    insereElementoNaLista(lista1, NULL, 19);
    insereElementoNaLista(lista1, lista1->head, 22);

    percorreListaHeadTail(lista1);

    removeElementoNaLista(lista1, NULL);
    percorreListaHeadTail(lista1);

    pivo = encontraElementoNaLista(lista1, 10);
    if (pivo != NULL){
        removeElementoNaLista(lista1, pivo);
    }

    percorreListaHeadTail(lista1);
    return 0;
}

