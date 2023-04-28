/*
Escreva um programa em JS que leia um vetor de tamanho N (onde N é uma constante de tamanho 12), escreva o conteúdo de todo o vetor, além da soma de todos os elementos de índice par.
*/

const prompt = require("prompt-sync")({ sigint: true });
const N=12;
var vet=[], soma;
soma=0;

// procedimento para carregar o vetor
for (let i=0; i < N; i++){
    vet[i] = parseInt(prompt("Informe o valor para vet[" + i + "]: "));
}

// procedimento para escrever o vetor
for (let i=0; i < N; i++){
    console.log("vet[" + i + "]: " + vet[i]);
}

// procedimento para somar o vetor
for (let i = 0; i < N; i++){
    if (i > 0 && i % 2 === 0)
        soma = soma + vet[i];
}
console.log("A soma dos elementos de indice pares é: " + soma);