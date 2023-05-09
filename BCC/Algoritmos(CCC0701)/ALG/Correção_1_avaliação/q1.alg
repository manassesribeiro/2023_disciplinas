/*
(2 pontos) Construa um algoritmo que, tendo como dados de entrada dois pontos quaisquer no plano 2D, P(x1,y1) e Q(x2,y2), escreva a distância d entre eles. A fórmula que efetua tal cálculo é:

*/
Algoritmo Questao1
inicio
    real x1, x2, y1, y2, d, a, b;
    leia (x1, x2, y1, y2);
    a = x2 - x1;
    b = y2 - y1;
    d = rad(pot(a,2) + pot(b,2)); //d = rad(pot((x2-x1),2) + pot((y2-y1),2)); 
    escreva(d);
fim