/*
    Fazer um programa que calcule a tabuada de qualquer número,
    e o limite de cálculo deve ser definido pelo usuário.
*/

#include <stdio.h>

int main()
{
    //1º passo: declaração das variáveis
    int tabuada, limite, cont, result; 
    
    // 2º passo: entrada dos dados
    printf("Informe o valor da tabuada: ");
    scanf("%i", &tabuada);
    printf("Informe o limite da tabuada: ");
    scanf("%i", &limite);

    cont = 1; //inicialização do contador
    while (cont <= limite) 
    {
        result = tabuada * cont;
        printf("%i x %i: %i\n", tabuada, cont, result);
        cont = cont + 1; //incremento do passo
    }
}