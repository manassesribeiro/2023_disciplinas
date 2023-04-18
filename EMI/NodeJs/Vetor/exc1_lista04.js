/*
    Escreva um programa em C que leia um vetor de 10 posições
    e escreva os elementos que são maiores do que 20. Caso não
    haja nenhum elemento, mostrar uma mensagem de aviso ao usuário.
*/
const prompt = require("prompt-sync")({ sigint: true });

// cria uma constante para identificar o tamanho máximo do vetor
const TAM=10;

// declaração do vetor
var vet=[];

// procedimento para carregar o vetor
for (let i=0; i < TAM; i++){
    vet[i] = parseInt(prompt("Informe o valor para vet[" + i + "]: "));
}

valorMaiorQue20 = 0;
//procedimento para escrever o vetor
for (let i=0; i < TAM; i++){
    if (vet[i] > 20) {
        valorMaiorQue20 = 1;
        console.log("vet[" + i + "]: " + vet[i]);
    }
}

if (valorMaiorQue20 === 0){
    console.log("Nenhum valor maior do que 20.")
}
