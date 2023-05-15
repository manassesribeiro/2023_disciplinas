/*
    João tem 1,50 metro e cresce 2 centímetros por ano, enquanto Zé tem 1,10 metro e cresce 3 centímetros por ano. Construa um algoritmo que calcule e imprima quantos anos serão necessários para que Zé seja maior que João.
*/

// Diretivas de pré-processamento
#include <stdio.h>
#include <math.h>

//Função principal
int main(){
    float joao, ze;
    int cont=0;
    joao = 1.5;
    ze = 1.1;

    while (joao >= ze){
        ze += 0.03;  // ze = ze + 0.03;
        joao += 0.02; // joao = joao + 0.02;
        cont += 1; // cont = cont + 1  => cont++;
    }

    printf("Ze precisa de %i anos para passar Joao e tera %.2f altura\n", cont, ze);
}




