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
void informaBaixa(Produto[], int, int);
void escreverBaixasProdutos(Produto[], int);
void inicializaVetorBaixas(Produto[], int);

int main(){
    Produto produtos[TAM];
    carregaProdutos(produtos, TAM);
    escreveProdutos(produtos, TAM);
    informaBaixa(produtos, 0, 1);
    informaBaixa(produtos, 0, 4);
    informaBaixa(produtos, 0, 3);
    informaBaixa(produtos, 0, 1);
    informaBaixa(produtos, 0, 1);

    informaBaixa(produtos, 1, 1);
    informaBaixa(produtos, 1, 6);

    escreverBaixasProdutos(produtos, TAM);
}

// Módulo que inicializa vetor baixas
void inicializaVetorBaixas(Produto produtos[], int prod){
    int i;
    for (i=0; i<7;i++){
        produtos[prod].baixa[i] = 0;
    }
}

// Módulo informa baixas
void informaBaixa(Produto produtos[], int codigo, int dia){
    produtos[codigo].baixa[dia]++;
}

// Módulo escreve baixas
void escreverBaixasProdutos(Produto produtos[], int tam){
    int p, d;
    for (p=0; p<tam; p++){
        printf("\n\nProduto %s(codigo: %i):\n", produtos[p].descricao, produtos[p].codigo);
        for (d=0; d<7; d++){
            switch(d){
                case 0:
                    printf("\tDomingo: %i\n", produtos[p].baixa[d]);
                    break;
                case 1:
                    printf("\tSegunda: %i\n", produtos[p].baixa[d]);
                    break;
                case 2:
                    printf("\tTerca: %i\n", produtos[p].baixa[d]);
                    break;
                case 3:
                    printf("\tQuarta: %i\n", produtos[p].baixa[d]);
                    break;
                case 4:
                    printf("\tQuinta: %i\n", produtos[p].baixa[d]);
                    break;
                case 5:
                    printf("\tSexta: %i\n", produtos[p].baixa[d]);
                    break;
                case 6:
                    printf("\tSabado: %i\n", produtos[p].baixa[d]);
                    break;
            }
        }
    }
}

// Módulo carrega Produtos
void carregaProdutos(Produto produtos[], int tam){
    int i;
    // Carrega o vetor de produtos
    for (i=0; i<tam; i++){
        //printf("Informe o codigo do produto: ");
//        scanf("%i", &produtos[i].codigo);
        getc(stdin);
        produtos[i].codigo = i;
        printf("Informe a descricao do produto: ");
        scanf("%[^\n]", produtos[i].descricao);
        printf("Informe o preço do produto: ");
        scanf("%f", &produtos[i].preco);
        inicializaVetorBaixas(produtos, i);  
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