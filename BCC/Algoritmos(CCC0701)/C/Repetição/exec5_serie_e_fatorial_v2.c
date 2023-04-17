/*
    Escrever um algoritmo que lê um valor N inteiro e positivo
    e que calcula e escreve o valor de E:   
	    E = 1 +  1      1      1            1 
                --- +  ---- + ---- + ... + ----
                 1!     2!     3!           N!
*/
# include <stdio.h>
int main()
{
    int n, cont; 
    float e, fat; //variavel acumuladora
    cont = 1;
    e = 1.;
    fat = 1.0;

    printf("Informe o valor de n: ");
    scanf("%i", &n);
    
    while (cont <= n)
    {
        fat = fat * cont;
        e = e + (1 / (float) fat);
        printf("Fatorial de %i: %.4f\n", cont, fat);
        cont = cont + 1;
    }
    printf("O valor de e é: %f\n", e);
}