/*
Escreva um programa que leia um vetor de 20 posições e escreva a posição de cada um dos elementos cujo valor seja igual a 10.
*/
const prompt = require("prompt-sync")({ sigint: true });
const TAM=20;
var vet=[];

// procedimento para carregar o vetor
for (let i=0; i < TAM; i++){
    vet[i] = parseInt(prompt("Informe o valor para vet[" + i + "]: "));
}

// procedimento para escrever o vetor
for (let i=0; i < TAM; i++){
    if (vet[i] === 10)
        console.log("Posição no vetor: " + i);
}