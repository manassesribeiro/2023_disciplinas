#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct{
    int topo;
    int item[TAM];
} Pilha;

/* Pilha* criaPilha(){
    Pilha* pilha;
    pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->topo = -1;
    
    return pilha;
}
 */
void push(Pilha pilha, int i){
    pilha.item[++pilha.topo] = i;
}

int pop(Pilha pilha){
    if(pilha.topo >= 0){
        return pilha.item[pilha.topo--];
    } else {
        printf("pilha vazia\n");
    }
}

int empty(Pilha pilha){
    if(pilha.topo<0){
        return 1;
    }else{
        return 0;
    }
}

int stackTop(Pilha pilha){
    return pilha.item[pilha.topo];
}


int main() {
    Pilha pilha;
//    pilha = criaPilha();
    int i=1;

    /*
        Por meio de uma pilha é possível inverter os valores de um vetor. No exemplo abaixo
        é utilizada uma pilha estática para inverter um vetor de inteiros que inicia em 1
        até o valor de TAM.
    */
    // cria um vetor com inteiros em ordem crescente de 1 a TAM
    int vet[TAM];
    for (i = 1; i <= TAM; i++){
        vet[i-1] = i;
    }

    // push na pilha (empilha) os valores do vetor
    printf("Empilhando . . .\n");
    for (i = 0; i < TAM; i++){
        printf("%i\n", vet[i]);
        push(pilha, vet[i]);
    }

    // pop da pilha (dempilha) os valores e escreve
    printf("Desempilhando . . .\n");
    for (i = 0; i < TAM; i++){
        printf("%i\n", pop(pilha));
    }

    return 0;
}