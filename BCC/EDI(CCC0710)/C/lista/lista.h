#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo{
    struct sNodo* next;
    struct sNodo* prev;
    int dado;
} Nodo;

typedef struct{
    struct sNodo* head;
    struct sNodo* tail;
    int size;
} Lista;

// Prototipação
Nodo* criaNodo(int);
Lista* criaLista();
int listaVazia(Lista*);
Nodo* inserir(Lista*, Nodo*, int);
int remover(Lista*, Nodo*);
void trataErro(int);
void escreveLista(Lista*);
Nodo* buscar(Lista*, int);
Nodo* buscarMax(Lista*); 
Nodo* buscarMin(Lista*);