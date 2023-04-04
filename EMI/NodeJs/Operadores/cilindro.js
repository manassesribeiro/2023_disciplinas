//Para instalar o prompt-sync: npm install prompt-sync

const prompt = require("prompt-sync")({ sigint: true });

//passo 1: declaração das variaveis
let r, h, a; 

//passo 2: entrada dos dados
r = prompt("Digite o valor do raio:");
h = prompt("Digite o valor da altura:");

//passo 3: processamento
a = 2 * Math.PI * r * h;

//passo 4: saída do resultado
console.log("O valor da area é:" + a);
