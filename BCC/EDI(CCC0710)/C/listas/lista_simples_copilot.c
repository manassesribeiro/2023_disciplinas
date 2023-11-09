//lista encadeada simples
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int info;
    struct no *prox;
}no;

typedef struct lista{
    no *inicio;
    no *fim;
}lista;

void inicializa(lista *l){
    l->inicio = NULL;
    l->fim = NULL;
}

void inserir(lista *l, int x){
    no *p = (no*)malloc(sizeof(no));
    p->info = x;
    p->prox = NULL;
    if(l->inicio == NULL){
        l->inicio = p;
        l->fim = p;
    }else{
        l->fim->prox = p;
        l->fim = p;
    }
}

void imprime(lista *l){
    no *p = l->inicio;
    while(p != NULL){
        printf("%d ", p->info);
        p = p->prox;
    }
}

void remover(lista *l, int x){
    no *p = l->inicio;
    no *ant = NULL;
    while(p != NULL && p->info != x){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        printf("Elemento nao encontrado\n");
    }else{
        if(ant == NULL){
            l->inicio = p->prox;
        }else{
            ant->prox = p->prox;
        }
        free(p);
    }
}   

int main(){
    lista l;
    inicializa(&l);
    inserir(&l, 10);
    inserir(&l, 20);
    inserir(&l, 30);
    inserir(&l, 40);
    inserir(&l, 50);
    imprime(&l);
    printf("\n");
    remover(&l, 30);
    imprime(&l);
    printf("\n");
    remover(&l, 10);
    imprime(&l);
    printf("\n");
    remover(&l, 50);
    imprime(&l);
    printf("\n");
    remover(&l, 40);
    imprime(&l);
    printf("\n");
    remover(&l, 20);
    imprime(&l);
    printf("\n");
    return 0;
}