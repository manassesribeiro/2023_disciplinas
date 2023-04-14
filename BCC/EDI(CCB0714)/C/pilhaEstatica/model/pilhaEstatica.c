#include <stdio.h>
#include <stdlib.h>

#define TAM_SIZE_STACK 10

typedef struct{
    int topo;
    int item[TAM_SIZE_STACK];
} Pilha;

Pilha* inicializaPilha();
int push(Pilha*, int);
int pop(Pilha*);
int empty(Pilha*);
int stackTop(Pilha*);
int stackSize(Pilha*);
void showStack(Pilha*);

Pilha* inicializaPilha(){
    Pilha *pilha;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = -1;
    return pilha;
}

int push(Pilha *pilha, int i){
    printf("pilha topo: %i\n", pilha->topo);
    if (stackSize(pilha) == TAM_SIZE_STACK)
        return -1; //Erro de overflow
    else
        pilha->item[++pilha->topo] = i;
}

int pop(Pilha *pilha){
    if(pilha->topo >= 0){
        return pilha->item[pilha->topo--];
    } else {
        return -2; // Erro de underflow
    }
}

int empty(Pilha *pilha){
    if(pilha->topo < 0){
        return 1;
    }else{
        return 0;
    }
}

int stackTop(Pilha *pilha){
    return pilha->item[pilha->topo];
}

int stackSize(Pilha *pilha){
    return pilha->topo + 1;
}

void showStack(Pilha *pilha){
    int i;
    for (i = (stackSize(pilha) - 1); i >= 0; i--){
        printf("%i\n", pilha->item[i]);
    }
}