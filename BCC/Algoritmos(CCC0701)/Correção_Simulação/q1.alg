/*
    Escreva um programa para calcular a área superficial de um cilindro, sendo que a fórmula para tal é:
        2 x PI x r x h,
        onde r representa o raio da base do cilindro e h representa a altura do cilindro.
*/

Algoritmo Questão1
inicio
    constante PI 3.1416
    real r, h, area;
    leia (r, h);

    area = (2 * PI * r * h);

    escreva(area);
fim