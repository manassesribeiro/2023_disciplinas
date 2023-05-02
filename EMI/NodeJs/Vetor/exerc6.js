/*
Faça um programa em JS que leia dois vetores com 10 elementos cada. Gere um terceiro vetor de 20 elementos, cujos valores deverão ser compostos pelos elementos intercalados dos dois outros vetores.
*/

const prompt = require("prompt-sync")({ sigint: true });
const N=10;
var vet1=[];
var vet2=[];
var vet3=[];

// procedimento para carregar o vetor 1
for (let i=0; i < N; i++){
    vet1[i] = parseInt(prompt("Informe o valor para vet1[" + i + "]: "));
}
// procedimento para carregar o vetor 2
for (let i=0; i < N; i++){
    vet2[i] = parseInt(prompt("Informe o valor para vet2[" + i + "]: "));
}

// procedimento para intercalar os vetores
let j = 0;
for (let i=0; i < N; i++){
    vet3[j] = vet1[i];
    j++;
    vet3[j] = vet2[i];
    j++;
}

// procedimento para escrever o vetor 3
for (let i=0; i < j; i++){
    console.log("vet3[" + i + "]: " + vet3[i]);
}