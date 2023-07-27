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
RGB** alocaMemoriaMatrizRGB(int, int);
void liberaMemoriaMatrizRGB(RGB**, int);

void carregaMatriz(RGB**, int, int);
void escreveMatriz(RGB**, int, int);
void escreveMatrizGray(int[][C], int, int);
void rgbParaGray(RGB**, int[][C], int, int);


int main(){
    srand(time(NULL));
    RGB** rgb;
    rgb = alocaMemoriaMatrizRGB(L, C);
    int gray[L][C];
    carregaMatriz(rgb, L, C);
    escreveMatriz(rgb, L, C);
    rgbParaGray(rgb, gray, L, C);
    escreveMatrizGray(gray, L, C);

    liberaMemoriaMatrizRGB(rgb, L);
    return 0;
}

RGB** alocaMemoriaMatrizRGB(int l, int c){
    RGB** matriz;
    int i;
    matriz = (RGB**) malloc(sizeof(RGB*) * l);
    for (i = 0; i < l; i++){
        matriz[i] = (RGB*) malloc(sizeof(RGB) * c);
    }
    return matriz;
} 

void liberaMemoriaMatrizRGB(RGB** matriz, int l){
    int i;
    for (i=0; i < l; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void rgbParaGray(RGB** matriz, int gray[][C], int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            gray[i][j] = (int) ((matriz[i][j].r * 0.3)  + (matriz[i][j].g * 0.59) + (matriz[i][j].b * 0.11));
        }
    }
}

void carregaMatriz(RGB** matriz, int l, int c){
    int i, j;
    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            matriz[i][j].r = rand() % 256;
            matriz[i][j].g = rand() % 256;
            matriz[i][j].b = rand() % 256;
        }
    }
}

void escreveMatriz(RGB** matriz, int l, int c){
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
