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
    if (pivo != NULL)
        removeElementoNaLista(lista1, pivo);

    return 0;
}


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
        return NULL; //Retorna NULL que indica que não foi possível alocar memoria

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

	if (listaVazia(lista))
		return NULL; //Retorna NULL indicando que a lista está vazia
	
	if (pivo == NULL)
		antigo = lista->head;
		lista->head = lista->head->next;

		if (lista->head == NULL)
			lista->tail = NULL;
	else
		if (pivo->next == NULL)
			return NULL; //Retorna NULL indicando que o pivô é o último elemento da lista
		
		antigo = pivo->next;
		pivo->next=pivo -> next->next
		se (elemento_pivo -> next == NULL)‏
			lista -> tail = elemento_pivo;
	fimse
		
	liberaMemoria(elemento_antigo)‏;

	atualizaTamanhoDaLista();

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
    
    while(nodo != NULL){
        if (nodo->dado == dado)
            return nodo;
        nodo = nodo->next;
    }
}
