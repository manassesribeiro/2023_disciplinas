#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define L 10
#define C 10

// Definição do registro
typedef struct {
    int r;
    int g;
    int b;
} RGB;

//Prototipação
void carregaMatriz(RGB[][C], int, int);
void escreveMatriz(RGB[][C], int, int);
void escreveMatrizGray(int[][C], int, int);
void rgbParaGray(RGB[][C], int[][C], int, int);


int main(){
    srand(time(NULL));
    RGB rgb[L][C];
    int gray[L][C];
    carregaMatriz(rgb, L, C);
    escreveMatriz(rgb, L, C);
    rgbParaGray(rgb, gray, L, C);
    escreveMatrizGray(gray, L, C);
    return 0;
}

void rgbParaGray(RGB matriz[][C], int gray[][C], int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            gray[i][j] = (int) ((matriz[i][j].r * 0.3)  + (matriz[i][j].g * 0.59) + (matriz[i][j].b * 0.11));
        }
    }
}

void carregaMatriz(RGB matriz[][C], int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            matriz[i][j].r = rand() % 256;
            matriz[i][j].g = rand() % 256;
            matriz[i][j].b = rand() % 256;
        }
    }
}

void escreveMatriz(RGB matriz[][C], int l, int c){
    int i, j;

    printf("\n\n...: MATRIZ RGB :...\n");
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("\t%i-%i-%i", matriz[i][j].r, matriz[i][j].g, matriz[i][j].b);
        }
        printf("\n");
    }
}

void escreveMatrizGray(int matriz[][C], int l, int c){
    int i, j;

    printf("\n\n...: MATRIZ GRAY :...\n");
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("\t%i", matriz[i][j]);
        }
        printf("\n");
    }
}
