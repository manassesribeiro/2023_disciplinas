#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo{
    int dado;
    struct sNodo *esq;
    struct sNodo *dir;
} Nodo;

typedef struct{
    struct sNodo *raiz;
} ABB;

//Protótipo
Nodo* criaNodo(int);
Nodo* inserir(Nodo*, int);
ABB* criaABB();
void insereNaABB(ABB*, int);
void escreveABB(ABB*);
void liberaMemoriaABB(Nodo*);
void removeABB(ABB*);
void emOrdem(Nodo*);
Nodo* remover(Nodo*, int);
Nodo* menorValor(Nodo*);

Nodo* buscar(Nodo*, int);
void destroiABB(Nodo*);


int main(){
    ABB* abb;
    abb = criaABB();

    insereNaABB(abb, 12);
    insereNaABB(abb, 15);
    insereNaABB(abb, 14);
    insereNaABB(abb, 16);
    insereNaABB(abb, 10);
    insereNaABB(abb, 9);
    insereNaABB(abb, 12);
    escreveABB(abb);

    buscar(abb->raiz, 16);

    insereNaABB(abb, 13);
    insereNaABB(abb, 11);
    insereNaABB(abb, 8);
    escreveABB(abb);
    remover(abb->raiz, 10);
    escreveABB(abb);

    
//                  12
//          10          15
//       9      12   14      16
//    8    11      13

    removeABB(abb);
    return 0;
}

//bst remove
Nodo* remover(Nodo* raiz, int dado){
    if (raiz == NULL)
        return raiz;
    if (dado < raiz->dado)
        raiz->esq = remover(raiz->esq, dado);
    else if (dado > raiz->dado)
        raiz->dir = remover(raiz->dir, dado);
    else{
        if (raiz->esq == NULL){
            Nodo* temp = raiz->dir;
            free(raiz);
            return temp;
        }else if (raiz->dir == NULL){
            Nodo* temp = raiz->esq;
            free(raiz);
            return temp;
        }
        Nodo* temp = menorValor(raiz->dir);
        raiz->dado = temp->dado;
        raiz->dir = remover(raiz->dir, temp->dado);
    }
    return raiz;
}

//menor valor
Nodo* menorValor(Nodo* nodo){
    Nodo* atual = nodo;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

void removeABB(ABB* abb){
    if (abb != NULL){
        liberaMemoriaABB(abb->raiz);
        free(abb);
    }
}

void liberaMemoriaABB(Nodo* nodo) {
    if (nodo != NULL) {
        liberaMemoriaABB(nodo->esq);
        liberaMemoriaABB(nodo->dir);
        free(nodo);
    }
}
void escreveABB(ABB *abb){
    printf("\nValores na ABB:\n");
    if (abb != NULL && abb->raiz != NULL)
        emOrdem(abb->raiz);
    else
        printf("Arvore vazia!\n");
}

void insereNaABB(ABB *abb, int valor){
    if (abb != NULL)
        abb->raiz = inserir(abb->raiz, valor);
}

Nodo* criaNodo(int dado){
    Nodo* nodo;
    nodo = (Nodo*) malloc(sizeof(Nodo));
    if (nodo != NULL){
        nodo->dir = NULL;
        nodo->esq = NULL;
        nodo->dado = dado;
    }
        
    return nodo;
}

ABB* criaABB(){
    ABB *abb;
    abb = (ABB*) malloc(sizeof(ABB));
    if (abb != NULL)
        abb->raiz = NULL;

    return abb;
}

Nodo* inserir(Nodo* nodo, int dado){
    if (nodo == NULL){
        return criaNodo(dado);
    }
    
    if (dado > nodo->dado){
        nodo->dir = inserir(nodo->dir, dado);
    }else {
        nodo->esq = inserir(nodo->esq, dado);
    }

    return nodo;
}

Nodo* buscar(Nodo* nodo, int dado){
    if (dado > nodo->dado){
        buscar(nodo->dir, dado);
    } else if (dado < nodo->dado){
        buscar(nodo->esq, dado);
    } else
        printf("\nNodo com valor '%i' encontrado\n", nodo->dado);
}

void emOrdem(Nodo* raiz) {
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%i, ", raiz->dado);
        emOrdem(raiz->dir);
    }
}