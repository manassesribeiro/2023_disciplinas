const prompt = require("prompt-sync")({ sigint: true });
const TAM=50;
// Declaração do vetor
var vet = []; //Não precisa especificar o tamanho do vetor

// Procedimento para carregar um vetor de 10 posições
for (let i=0; i < TAM; i++){
    vet[i] = parseInt(prompt("Informe um valor para vet["+i+"]: "));
}
// Procedimento para escrever um vetor de 10 posições
for (let i=0; i < TAM; i++){
    console.log("vet["+i+"]: "+vet[i]);
}
