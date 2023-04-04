//Para instalar o prompt-sync: npm install prompt-sync
const prompt = require("prompt-sync")({ sigint: true });

//Passo 1: declaração das variáveis
let raio, altura, vol;

//Passo 2: entrada dos dados
raio = prompt("Digite o valor do raio:"); //comando leia
altura = prompt("Digite o valor da altura: ")

//Passo 3: processamento do cálculo
vol = ( Math.PI * Math.pow(raio, 2) * altura) / 3;

//Passo 4: saída do resultado
console.log("O volume é: " + vol);