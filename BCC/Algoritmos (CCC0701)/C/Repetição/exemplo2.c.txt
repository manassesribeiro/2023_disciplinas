#include <stdio.h>

int main(){
    int n1, n2, soma, aux;
    soma = 0;
    printf("Informe o valor de n1:");
    scanf("%i", &n1); // comando leia para ler n1

    printf("Informe o valor de n2:");
    scanf("%i", &n2); // comando leia para ler uint32_t
    
    if(n1 > n2) {
        aux = n1;
        n1 = n2;
        n2 = aux;
    }
    
    while (n1 <= n2){
        if (n1 % 2 == 0){
            soma = soma + n1;
        }
        n1++; // n1 = n1 + 1; n1+=1
    }

    printf("O valor da soma é: %i\n", soma);
    printf("O valor do contador é: %i", n1);

    return 0;
}