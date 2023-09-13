#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo{
    struct sNodo* prox;
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

Nodo* criaNodo(int dado){
    Nodo* novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL){
        novo->dado = dado;
        novo->prox = NULL;
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

		novo_elemento->prox = lista->head;
		lista->head = novo_elemento;
    } else {
		if (elemento_pivo -> prox == NULL)
			lista->tail = novo_elemento;

		novo_elemento->prox = elemento_pivo->prox;
		elemento_pivo->prox = novo_elemento;

	}
	lista->size++;
}

int remover(Lista *lista, Nodo *elemento_pivo){
	Nodo* elemento_antigo;
	if (listaVazia(lista))
		return -1; // Erro de lista vazia
	
	if (elemento_pivo == NULL){
		elemento_antigo = lista->head;
		lista->head = lista->head->prox;

		if (lista->head == NULL)
			lista->tail = NULL;
    } else {
		if (elemento_pivo->prox == NULL)
			return -2; // Erro de fim da lista
		
		elemento_antigo = elemento_pivo->prox;
		elemento_pivo->prox = elemento_pivo->prox->prox;

		if (elemento_pivo->prox == NULL)
			lista->tail = elemento_pivo;
	}
		
	free(elemento_antigo);
	lista->size--;
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
            nodo = nodo->prox;
        }
    }
}