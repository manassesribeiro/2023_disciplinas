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

Nodo* criaNodo(int dado){
    Nodo* novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL){
        novo->dado = dado;
        novo->next = NULL;
        novo->prev = NULL;
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

Nodo* inserir(Lista* lista, Nodo* pivo, int dado){
	Nodo *novo;
	novo = criaNodo(dado);
    if (novo == NULL)
        return NULL; //Tratando o erro de overflow

	if (pivo == NULL){
		if (listaVazia(lista))
			lista->tail = novo;

		novo->next = lista->head;
        lista->head->prev = novo;
		lista->head = novo;
    } else {
        novo->next = pivo->next;
        novo->prev = pivo;

        if (pivo->next == NULL)
            lista->tail = novo;
        else
            pivo->next->prev = novo;

        pivo->next = novo;
    }

    lista->size++;
}

int remover(Lista *lista, Nodo *elemento){
    int removido;
    if ((elemento != NULL) && (!listaVazia(lista))){
        if (elemento == lista->head){
            lista->head = elemento->next;
            if (lista->head == NULL)
                lista->tail = NULL;
            else
                elemento->next->prev = NULL;
        } else {
            elemento->prev->next = elemento->next;
            if (elemento->next == NULL)
                lista->tail = elemento->prev;
            else
                elemento->next->prev = elemento->prev;
        }
        removido = elemento->dado;
        free(elemento);
        lista->size--;
        return removido;
    } else
        return -1;
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

void escreveListaCaudaCabeca(Lista* lista){
    Nodo *nodo;

    if (listaVazia(lista))
         trataErro(-1);
    else {
        printf("\nElementos da lista: \n");
        nodo = lista->tail;
        while (nodo!=NULL){
            printf("%i, ", nodo->dado);
            nodo = nodo->prev;
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