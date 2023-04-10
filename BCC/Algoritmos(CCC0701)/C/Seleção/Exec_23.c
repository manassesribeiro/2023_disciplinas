#include <stdio.h>

int main()
{
    int n1, n2, n3;
    printf("Informe o valor de n1: ");
    scanf("%i", &n1);   
    printf("Informe o valor de n2: ");
    scanf("%i", &n2);   
    printf("Informe o valor de n3: ");
    scanf("%i", &n3);   

    if ((n1 >= n2) && (n1 >= n3)){
        if (n2 >= n3){
            printf("%i, %i, %i\n", n3, n2, n1);
        } else {
            printf("%i, %i, %i\n", n2, n3, n1);
        }
    } else if ((n2 >= n1) && (n2 >= n3)){
        if (n1 >= n3){
            printf("%i, %i, %i\n", n3, n1, n2);
        } else {
            printf("%i, %i, %i\n", n1, n3, n2);
        }
    } else if ((n3 >= n1) && (n3 >= n2)){
        if (n1 >= n2){
            printf("%i, %i, %i\n", n2, n1, n3);
        } else {
            printf("%i, %i, %i\n", n1, n2, n3);
        }
    }
    return 0;
}
