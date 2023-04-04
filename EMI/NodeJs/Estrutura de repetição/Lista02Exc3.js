/*
  Fazer um programa que retorne quantos valores digitados pelo
  usuário são negativos. O programa deverá parar a execução quando
  o usuário informar o número zero ou for informado 20 valores.
*/
const prompt = require("prompt-sync")({ sigint: true });

let valor;
let contValoresNeg;
let cont;

contValoresNeg = 0;
cont = 0;
valor = 1;

while (valor !== 0 && cont < 20){
    valor = parseInt(prompt(`Informe o valor ${cont+1}: `));
    if (valor < 0 ){
        contValoresNeg = contValoresNeg + 1;
    }
    cont = cont + 1;
}
console.log("Foram digitados %s valores negativos", contValoresNeg);