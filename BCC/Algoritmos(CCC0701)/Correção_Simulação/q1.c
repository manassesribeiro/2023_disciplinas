/*
    Escreva um programa para calcular a área superficial de um cilindro, sendo que a fórmula para tal é:
        2 x PI x r x h,
        onde r representa o raio da base do cilindro e h representa a altura do cilindro.

        OBS: No exemplo abaixo está sendo utilizado o valor da constante PI (M_PI) da biblioteca math.h.
        Para compilar usando a biblioteca math.h é preciso incluir a flag -lm, exemplo: 
        $ gcc q1.c -lm -o q1.exe

        Também pode ser ignorada a constante da biblioteca math.h e utilizado o valor definido na linha 16.
        Para isto, basta descomentar a linha
*/

#include <stdio.h>
#include <math.h>
//#define M_PI 3.14159265358979323846

int main(){
    float r, h, area;
    printf("Informe o valor do raio: ");
    scanf("%f", &r);
    printf("Informe o valor da altura: ");
    scanf("%f", &h);

    area = (2 * M_PI * r * h);

    printf("O valor da área é: %f: ", area);
}