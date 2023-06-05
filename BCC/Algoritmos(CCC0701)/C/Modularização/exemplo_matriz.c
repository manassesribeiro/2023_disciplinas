#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define LIN 10
#define COL 10

// Prototipação
void carregaMatriz(int[][COL], int, int);
void escreveMatriz(int[][COL], int, int);

int main(){
    srand(time(NULL));
    int ma[LIN][COL];
    carregaMatriz(ma, LIN, COL);
    escreveMatriz(ma, LIN, COL);
}

void carregaMatriz(int ma[][COL], int lin, int col){
    int l, c;
    for (l=0; l<lin; l++){
        for (c=0; c<col; c++){
            ma[l][c] = rand() % 10;
        }
    }
}

void escreveMatriz(int ma[][COL], int lin, int col){
    int l, c;
    for (l=0; l<lin; l++){
        for (c=0; c<col; c++){
            printf("%i\t", ma[l][c]);
        }
        printf("\n");
    }
}
