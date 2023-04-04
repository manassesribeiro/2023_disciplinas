#include <stdio.h>

int main(){
    int codigo;
    printf("Informe o código: ");
    scanf("%i", &codigo);
    
    switch(codigo){
        case 1:
            printf("Alimento não perecível");
            break;
        case 2:
        case 3:
        case 4:
            printf("Alimento perecível");
            break;
        case 5:
        case 6:
            printf("Vestuário");
            break;
        case 7:
            printf("Higiene pessoal");
            break;
        case 8 ... 15:
            printf("Limpeza");
            break;
        default:
            printf("Inválido");
            break;
    }
    return 0;
}
