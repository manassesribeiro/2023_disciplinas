#include <stdio.h>

//Declaração do registro, struct, TAD
typedef struct{
    int codigo;
    float preco;
    char descricao[100];
    int baixa[7];
} Produto;

int main(){
    Produto feijao;
    // Para carregar
    printf("Informe o codigo do produto: ");
    scanf("%i", &feijao.codigo);
    getc(stdin);
    printf("Informe a descricao do produto: ");
    scanf("%[^\n]", feijao.descricao);
    printf("Informe o preço do produto: ");
    scanf("%f", &feijao.preco);   

    // Para escrever

    printf("Codigo do produto: %i\n", feijao.codigo);
    printf("Descricao do produto: %s\n", feijao.descricao);
    printf("Codigo do produto: %.2f\n", feijao.preco);
}