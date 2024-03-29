#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo{
    struct sNodo* next;
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
void inserir(Lista*, Nodo*, int);
int remover(Lista*, Nodo*);
void trataErro(int);
void escreveLista(Lista*);
Nodo* buscar(Lista*, int);
Nodo* buscarMax(Lista*); 
Nodo* buscarMin(Lista*);

Nodo* criaNodo(int dado){
    Nodo* novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL){
        novo->dado = dado;
        novo->next = NULL;
    }

    return novo;
}

Lista* criaLista(){
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL){
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
    }
    return lista;
}

int listaVazia(Lista *lista){
    if (lista->size == 0)
        return 1;

    return 0;
}

void trataErro(int erro){
    if (erro == -1)
        printf("\nLista vazia!\n");
    else if (erro == -2)
        printf("\nFim da lista!\n");
}

void inserir(Lista* lista, Nodo* elemento_pivo, int dado){
	Nodo *novo_elemento;
	novo_elemento = criaNodo(dado);

	if (elemento_pivo == NULL){
		if (listaVazia(lista))
			lista->tail = novo_elemento;

		novo_elemento->next = lista->head;
		lista->head = novo_elemento;
    } else {
		if (elemento_pivo -> next == NULL)
			lista->tail = novo_elemento;

		novo_elemento->next = elemento_pivo->next;
		elemento_pivo->next = novo_elemento;

	}
	lista->size++;
}

int remover(Lista *lista, Nodo *elemento_pivo){
	Nodo* elemento_antigo;
    int removido;
	if (listaVazia(lista))
		return -1; // Erro de lista vazia
	
	if (elemento_pivo == NULL){
		elemento_antigo = lista->head;
		lista->head = lista->head->next;

		if (lista->head == NULL)
			lista->tail = NULL;
    } else {
		if (elemento_pivo->next == NULL)
			return -2; // Erro de fim da lista
		
		elemento_antigo = elemento_pivo->next;
		elemento_pivo->next = elemento_pivo->next->next;

		if (elemento_pivo->next == NULL)
			lista->tail = elemento_pivo;
	}
	removido = elemento_antigo->dado;
	free(elemento_antigo);
	lista->size--;
    return removido;
}

void escreveLista(Lista* lista){
    Nodo *nodo;

    if (listaVazia(lista))
         trataErro(-1);
    else {
        printf("\nElementos da lista: \n");
        nodo = lista->head;
        while (nodo!=NULL){
            printf("%i, ", nodo->dado);
            nodo = nodo->next;
        }
    }
}

Nodo* buscar(Lista* lista, int dado){
    Nodo* nodo;
    nodo = lista->head;
    while(nodo != NULL){
        if (nodo->dado == dado)
            return nodo;
        nodo = nodo->next;
    }

    return NULL;
}

Nodo* buscarMax(Lista* lista){        
    Nodo *nodo, *nodoMax;
    int valor;
    if (listaVazia(lista))
        return NULL;

    nodo = lista->head;
    nodoMax = nodo;
    valor = nodo->dado;
    while(nodo != NULL){
        if (nodo->dado > valor){
            valor = nodo->dado;
            nodoMax = nodo;
        }
        nodo = nodo->next;
    }

    return nodoMax;
}

Nodo* buscarMin(Lista* lista){        
    Nodo *nodo, *nodoMax;
    int valor;
    if (listaVazia(lista))
        return NULL;

    nodo = lista->head;
    nodoMax = nodo;
    valor = nodo->dado;
    while(nodo != NULL){
        if (nodo->dado < valor){
            valor = nodo->dado;
            nodoMax = nodo;
        }
        nodo = nodo->next;
    }

    return nodoMax;
}

// int main(){
//     Lista *minhaLista;
//     minhaLista = criaLista();

//     // Para inserir elementos
//     inserir(minhaLista, NULL, 10);
//     inserir(minhaLista, minhaLista->head, 15);
//     inserir(minhaLista, minhaLista->tail, 25);
//     inserir(minhaLista, NULL, 5);
//     inserir(minhaLista, minhaLista->tail, 35);
//     escreveLista(minhaLista);

//     // Para remover elementos
//     trataErro(remover(minhaLista, minhaLista->tail));
//     trataErro(remover(minhaLista, minhaLista->head));
//     escreveLista(minhaLista);
//     trataErro(remover(minhaLista, NULL));
//     escreveLista(minhaLista);
//     trataErro(remover(minhaLista, minhaLista->head));
//     escreveLista(minhaLista);
//     trataErro(remover(minhaLista, minhaLista->head));
//     escreveLista(minhaLista);
//     trataErro(remover(minhaLista, minhaLista->head));
//     escreveLista(minhaLista);
//     trataErro(remover(minhaLista, NULL));
//     escreveLista(minhaLista);
//     trataErro(remover(minhaLista, NULL));
// }