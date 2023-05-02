/*
Faça um programa em JS que leia a idade e a altura de 5 pessoas, armazene cada informação no seu respectivo vetor. Imprima a idade e a altura na ordem inversa a ordem lida.
*/
const prompt = require("prompt-sync")({ sigint: true });
const TAM=5;
var idade=[];
var altura=[];

// procedimento para carregar o vetor N
for (let i=0; i < TAM; i++){
    altura[i] = parseInt(prompt("Informe o valor para a altura[" + i + "]: "));
    idade[i] = parseInt(prompt("Informe o valor para o idade[" + i + "]: "));
}

// procedimento para copiar os valores para X e Y
for (let i=TAM-1; i >=0 ; i--){
    console.log("Altura[" + i + "]: " + altura[i] + " Idade[" + i + "]: " + idade[i]);
}
