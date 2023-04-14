#include "../model/fila.c"
#define TAM 10
int main(){
    Lista *fila;
    fila = alocaMemoriaLista();
    int i;
    for (i= 0; i < TAM; i++){
        insereNaFila(fila, i);
    }

    printf("Elementos na fila:\n");
    mostraFila(fila);

    printf("Tamanho da fila: %i\n", tamanhoFila(fila));

    printf("Removendo da fila . . .\n");
    for (i= 0; i < TAM; i++){
        printf("%i\n", removeDaFila(fila));
    }

    printf("Elementos na fila após remoções:\n");
    mostraFila(fila);

    printf("Tamanho da fila após remoção: %i\n", tamanhoFila(fila));

    return 0;
}