const prompt = require("prompt-sync")({ sigint: true });

// cria uma constante para identificar o tamanho máximo do vetor
const TAM=10;

// declaração do vetor
var vet=[];

// procedimento para carregar o vetor
for (let i=0; i < TAM; i++){
    vet[i] = parseInt(prompt("Informe o valor para vet[" + i + "]: "));
}

// procedimento para escrever o vetor
for (let i=0; i < TAM; i++){
    console.log("vet[" + i + "]: " + vet[i]);
}