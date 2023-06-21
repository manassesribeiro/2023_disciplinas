#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 32
#define M 32

typedef struct{
    int r,g,b;
} RGB;

void carregaMatrizRGB(RGB[][M]);
void escreveMatrizRGB(RGB[][M]);
void rgbToGray(RGB[][M],int[][M]);
void escreveMatrizGray(int[][M]);
    
int main()
{
    srand(time(NULL));
    RGB rgb[N][M];
    int gray[N][M];
    
    carregaMatrizRGB(rgb);
    escreveMatrizRGB(rgb);
    rgbToGray(rgb, gray);
    escreveMatrizGray(gray);
    return 0;
}

void carregaMatrizRGB(RGB img[][M]){
    int l,c;
    for (l=0; l<N; l++){
        for (c=0; c<M; c++){
            img[l][c].r = rand() % 255;
            img[l][c].g = rand() % 255;
            img[l][c].b = rand() % 255;
        }
    }
}

void rgbToGray(RGB img[][M], int gray[][M]){
    int l,c;
    for (l=0; l<N; l++){
        for (c=0; c<M; c++){
            gray[l][c] = (int) (img[l][c].g*0.59 + img[l][c].r*0.3 + img[l][c].b*0.11);
        }
    }    
}

void escreveMatrizRGB(RGB img[][M]){
    int l,c;
    printf("\n\nMatriz em RGB:\n");
    for (l=0; l<N; l++){
        for (c=0; c<M; c++){
            printf("\t(%i/%i/%i)",
                img[l][c].r, 
                img[l][c].g,
                img[l][c].b);
        }
        printf("\n");
    }
}

void escreveMatrizGray(int gray[][M]){
    int l,c;
    printf("\n\nMatriz em tons de cinza:\n");
    for (l=0; l<N; l++){
        for (c=0; c<M; c++){
            printf("\t%i", gray[l][c]);
        }
        printf("\n");
    }
}