/*
    Escrever um algoritmo que lê um valor N inteiro e positivo
    e que calcula e escreve o valor de E:   
	    E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N
*/
# include <stdio.h>
int main()
{
    int n, cont; 
    float e; //variavel acumuladora
    cont = 1;
    e = 1.;
    printf("Informe o valor de n: ");
    scanf("%i", &n);
    
    while (cont <= n)
    {
        e = e + (1 / (float) cont);
        cont = cont + 1;
    }
    printf("O valor de e é: %f\n", e);
}