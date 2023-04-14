#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo{
    int dado;
    struct sNodo* next;
} Nodo;

typedef struct sLista{
    struct sNodo *head;
    struct sNodo *tail;
    int size;
} Lista;

//Prototipação
Nodo* alocaMemoriaNodo();
Lista* alocaMemoriaLista();
Nodo* criaNodo(int);
Lista* criaLista();
int insereElementoNaLista(Lista*, Nodo*, int);
int removeElementoNaLista(Lista*, Nodo*);
void percorreListaHeadTail(Lista*);
Nodo* encontraElementoNaLista(Lista*, int);

//Implementação
Nodo* alocaMemoriaNodo(){
    return (Nodo*) malloc(sizeof(Nodo));
}

Lista* alocaMemoriaLista(){
    return (Lista*) malloc(sizeof(Lista));
}

Nodo* criaNodo(int dado){
    Nodo* nodo = alocaMemoriaNodo();
    if (nodo != NULL) {
        nodo->dado = dado;
        nodo->next = NULL;
    }
    return nodo;
}

Lista* criaLista(){
    Lista* lista = alocaMemoriaLista();
    if (lista != NULL){
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
    }
    return lista;
}

int insereElementoNaLista(Lista* lista, Nodo* pivo, int dado){
    Nodo* novo = criaNodo(dado);
    if (novo == NULL)
        return -1; //Retorna NULL que indica que não foi possível alocar memoria

	if (pivo == NULL){
		if (lista->size == 0)
			lista->tail = novo;

		novo->next = lista->head;
		lista->head = novo;
    } else {
		if (pivo->next == NULL)
			lista->tail = novo;

		novo->next = pivo->next;
		pivo->next = novo;
	}

	lista->size++;

    return lista->size;
}
int listaVazia(Lista* lista){
    if (lista->size == 0)
        return 1;
    else
        return 0;
}

int removeElementoNaLista(Lista* lista, Nodo* pivo){
	Nodo* antigo;
    int dado;

	if (listaVazia(lista))
		return -1; //Retorna NULL indicando que a lista está vazia
	
	if (pivo == NULL){
		antigo = lista->head;
		lista->head = lista->head->next;

		if (lista->head == NULL)
			lista->tail = NULL;
    } else{
		if (pivo->next == NULL)
			return -2; //Retorna NULL indicando que o pivô é o último elemento da lista
		
		antigo = pivo->next;
		pivo->next=pivo -> next->next;
		if (pivo -> next == NULL)
			lista -> tail = pivo;
    }
    dado = antigo->dado;
	free(antigo);
    lista->size--;
    return dado;
}

void percorreListaHeadTail(Lista* lista){
    Nodo* nodo = lista->head;

    if (nodo == NULL)
        printf("Lista vazia!\n");
    
    while(nodo != NULL){
        printf("%i, ", nodo->dado);
        nodo = nodo->next;
    }
    printf("Fim da lista!\n");
}

Nodo* encontraElementoNaLista(Lista* lista, int dado){
    Nodo* nodo = lista->head;

    if (nodo == NULL)
        return NULL;
    if (nodo->dado == dado)
        return NULL;

    while(nodo->next != NULL){
        if (nodo->next->dado == dado)
            return nodo;
        nodo = nodo->next;
    }
}
