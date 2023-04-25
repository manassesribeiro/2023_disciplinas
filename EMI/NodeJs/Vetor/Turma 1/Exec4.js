/*
Ler do teclado 12 números inteiros e armazená-los em um vetor N. Em seguida, copiar os elementos pares divisíveis por 3 para o vetor X e os ímpares divisíveis por 5 para o vetor Y.
*/
const prompt = require("prompt-sync")({ sigint: true });
const TAM=12;
var n=[];
var x=[];
var y=[];
let contX, contY;
contX = contY = 0;

// procedimento para carregar o vetor N
for (let i=0; i < TAM; i++){
    n[i] = parseInt(prompt("Informe o valor para n[" + i + "]: "));
}

// procedimento para copiar os valores para X e Y
for (let i=0; i < TAM; i++){
    if ((n[i] % 2 === 0) && (n[i] % 3 === 0)){
        x[contX] = n[i];
        contX+=1;
    }

    if ((n[i] % 2 === 1) && (n[i] % 5 === 0)){
        y[contY] = n[i];
        contY+=1;
    }
}

// procedimento para escrever o vetor N
console.log("Valores do vetor N");
for (let i=0; i < TAM; i++){
    console.log("n[" + i + "]: " + n[i]);
}

// procedimento para escrever o vetor X
console.log("Valores do vetor X: pares divisíveis por 3");
for (let i=0; i < contX; i++){
    console.log("x[" + i + "]: " + x[i]);
}

// procedimento para escrever o vetor Y
console.log("Valores do vetor Y: ímpares divisíveis por 5");
for (let i=0; i < contY; i++){
    console.log("y[" + i + "]: " + y[i]);
}