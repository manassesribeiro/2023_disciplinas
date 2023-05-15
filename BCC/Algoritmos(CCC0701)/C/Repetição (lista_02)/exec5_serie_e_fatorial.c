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
    int n, cont, contFat; 
    float e, fat; //variavel acumuladora
    cont = 1;
    e = 1.;

    printf("Informe o valor de n: ");
    scanf("%i", &n);
    
    while (cont <= n)
    {
        fat = 1.; //acumuladora
        contFat = cont;
        while (contFat > 1){
            fat = fat * contFat;
            contFat--;
        }
        printf("O fatorial de %i é: %.4f\n", cont, fat);

        e = e + (1 / (float) fat);
        cont = cont + 1;
    }
    printf("O valor de e é: %f\n", e);
}