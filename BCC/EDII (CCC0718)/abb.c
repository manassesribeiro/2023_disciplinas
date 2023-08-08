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

Nodo* buscar(int);
Nodo* remover(int);
void destroiABB(Nodo*);


int main(){
    ABB* abb;
    abb = criaABB();

    insereNaABB(abb, 7);
    insereNaABB(abb, 8);
    insereNaABB(abb, 6);
    insereNaABB(abb, 12);
    escreveABB(abb);

    removeABB(abb);
    return 0;
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
    printf("Valores na ABB:\n");
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
    if (nodo != NULL)
        nodo->dir = NULL;
        nodo->esq = NULL;
        nodo->dado = dado;
        
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

void emOrdem(Nodo* raiz) {
    if (raiz != NULL){
        emOrdem(raiz->esq);
        printf("%i, ", raiz->dado);
        emOrdem(raiz->dir);
    }
}