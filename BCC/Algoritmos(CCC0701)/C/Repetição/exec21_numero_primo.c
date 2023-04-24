/*
Faça um algoritmo para encontrar os números primos existentes entre dois números informados pelo usuário. Lembre-se de que um número primo é aquele que é divisível somente por 1 e por ele mesmo: Exemplo, 1, 2, 3, 5, etc.
*/

#include <stdio.h>
int main(){
    int n1, n2, aux, cont, primo;
    printf("Informe o valor para n1: ");
    scanf("%i", &n1);
    printf("Informe o valor para n2: ");
    scanf("%i", &n2);

    if (n1 > n2){
        aux = n1;
        n1 = n2;
        n2 = aux;
    }

    while (n1 < n2){
        primo = 1;
        cont = 2;
        while (primo && cont < n1){
            if (n1 % cont == 0){
                primo = 0;
            }
            cont = cont + 1;
        }
        if (primo){
            printf("%i, ", n1);
        }
        n1 = n1 + 1;
    }
    return 0;
}