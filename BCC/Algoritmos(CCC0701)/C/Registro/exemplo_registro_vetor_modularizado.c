#include <stdio.h>
#define TAM 2
//Declaração do registro, struct, TAD
typedef struct{
    int codigo;
    float preco;
    char descricao[100];
    int baixa[7];
} Produto;

//Prototipação
void carregaProdutos(Produto[], int);
void escreveProdutos(Produto[], int);

int main(){
    Produto produtos[TAM];
    carregaProdutos(produtos, TAM);
    escreveProdutos(produtos, TAM);
}

// Módulo carrega Produtos
void carregaProdutos(Produto produtos[], int tam){
    int i;
    // Carrega o vetor de produtos
    for (i=0; i<tam; i++){
        printf("Informe o codigo do produto: ");
        scanf("%i", &produtos[i].codigo);
        getc(stdin);
        printf("Informe a descricao do produto: ");
        scanf("%[^\n]", produtos[i].descricao);
        printf("Informe o preço do produto: ");
        scanf("%f", &produtos[i].preco);   
    }
}

//Módulo escreve Produtos
void escreveProdutos(Produto produtos[], int tam){
    int i;
    // Procedimento para escrever
    for (i=0; i<tam; i++){
        printf("Codigo do produto: %i\n", produtos[i].codigo);
        printf("\tDescricao do produto: %s\n", produtos[i].descricao);
        printf("\tCodigo do produto: %.2f\n", produtos[i].preco);
    }
}