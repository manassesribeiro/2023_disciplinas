#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
#define M 15

typedef struct{
    int r, g, b;
} RGB;

void carregaMatrizRGB(RGB[][M]);
void escreveMatrizRGB(RGB[][M]);
void rgbParaGray(RGB[][M], int[][M]);
void escreveMatrizGray(int[][M]);

int main(){
    srand(time(NULL));
    RGB img_rgb[N][M];
    int gray[N][M];
    carregaMatrizRGB(img_rgb);
    escreveMatrizRGB(img_rgb);
    rgbParaGray(img_rgb, gray);
    escreveMatrizGray(gray);
    return 0;
}

void carregaMatrizRGB(RGB img_rgb[][M]){
    int i, j;

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            img_rgb[i][j].r = rand() % 255;
            img_rgb[i][j].g = rand() % 255;
            img_rgb[i][j].b = rand() % 255;
        }
    }
}

void escreveMatrizRGB(RGB img_rgb[][M]){
    int i, j;

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            printf("RGB[%i, %i]: (%i/%i/%i)\n", i, j, img_rgb[i][j].r,
               img_rgb[i][j].g, img_rgb[i][j].b);
        }
    }    
}

void rgbParaGray(RGB img_rgb[][M], int gray[][M]){
    int i, j;

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            gray[i][j] = (int) ((img_rgb[i][j].r * 0.300) + (img_rgb[i][j].g * 0.59) +
              (img_rgb[i][j].b * 0.11));
        }
    }    
}

void escreveMatrizGray(int img_gray[][M]){
    int i, j;

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            printf("Gray[%i, %i]: (%i)\n", i, j, img_gray[i][j]);
        }
    }    
}
