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
void emOrdem(Nodo*);

Nodo* buscar(int);
Nodo* remover(int);
void destroiABB(Nodo*);


int main(){
    ABB* abb;
    abb = criaABB();

    abb->raiz = inserir(abb->raiz, 7);
    inserir(abb->raiz, 8);
    inserir(abb->raiz, 6);
    inserir(abb->raiz, 12);
    emOrdem(abb->raiz);

    return 0;
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