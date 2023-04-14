    /*
        Por meio de uma pilha é possível inverter os valores de um vetor. No exemplo abaixo
        é utilizada uma pilha estática para inverter um vetor de inteiros que inicia em 1
        até o valor de TAM.
    */

#include "../model/pilhaEstatica.c"
#define TAM 12
int main() {
    Pilha *pilha;
    pilha = inicializaPilha();

    int dado, i = 1;

    // cria um vetor com inteiros em ordem crescente de 1 a TAM
    int vet[TAM];
    printf("Vetor original: \n");
    for (i = 1; i <= TAM; i++){
        vet[i-1] = i;
        printf("%i, ", vet[i-1]);
    }

    // push na pilha (empilha) os valores do vetor
    printf("Empilhando . . .\n");
    for (i = 0; i < TAM; i++){
        if (push(pilha, vet[i]) == -1)
            printf("Impossível empilhar. Tamanho máximo na pilha: %i\n", stackSize(pilha));
        else
            printf("%i\n", vet[i]);

    }

    showStack(pilha);

    // pop da pilha (dempilha) os valores e escreve
    printf("Desempilhando . . .\n");
    for (i = 0; i < TAM; i++){
        dado = pop(pilha);
        if (dado == -2)
            printf("Impossível desempilhar. Erro de underflow\n");
        else
            printf("%i\n", dado);
    }

    return 0;
}