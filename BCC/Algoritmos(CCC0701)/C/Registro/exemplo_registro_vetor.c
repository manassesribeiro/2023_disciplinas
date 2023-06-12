#include <stdio.h>
#define TAM 5
//Declaração do registro, struct, TAD
typedef struct{
    int codigo;
    float preco;
    char descricao[100];
    int baixa[7];
} Produto;

int main(){
    Produto produtos[TAM];
    int i;

    // Carrega o vetor de produtos
    for (i=0; i<TAM; i++){
        printf("Informe o codigo do produto: ");
        scanf("%i", &produtos[i].codigo);
        getc(stdin);
        printf("Informe a descricao do produto: ");
        scanf("%[^\n]", produtos[i].descricao);
        printf("Informe o preço do produto: ");
        scanf("%f", &produtos[i].preco);   
    }
    // Para escrever
    for (i=0; i<TAM; i++){
        printf("Codigo do produto: %i\n", produtos[i].codigo);
        printf("\tDescricao do produto: %s\n", produtos[i].descricao);
        printf("\tCodigo do produto: %.2f\n", produtos[i].preco);
    }
}