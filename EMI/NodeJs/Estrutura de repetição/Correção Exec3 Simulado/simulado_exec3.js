const PromptSync = require("prompt-sync");

/*
  Escreva um programa que leia uma quantidade qualquer de valores inteiros
  e positivos (quantidade indefinida de valores). O programa deverá parar
  de ler quando o usuário informar -1. Escreva os valores que são maiores do
  que 20 e divisíveis por 5. Também calcule e escreva a média de todos os
  elementos informados pelo usuário. Caso o usuário não informe nenhum valor,
  ou seja, digite -1 já na primeira vez, escreva uma mensagem informando ao
  usuário que não é possível realizar os cálculos.
*/
const prompt = require("prompt-sync")({ sigint: true });
let num, cont;
let media;
num = 0;
media = 0;
cont = 0;

while(num !== -1){
    num = parseInt(prompt("Informe um valor positivo: "));
    if (num > 0){
        if ((num > 20) && (num % 5 === 0)){
            console.log("%s é maior do que 20 e divisível por 5", num);
        }

        media = media + num;
        cont ++;
    } else if((cont === 0) && (num === -1)){
        console.log("Usuário informou -1 antes de informar um valor válido!");
    } else if (num < -1) {
        console.log("O valor %s é negativo menor do que -1!");
    } else if (num === 0) {
        console.log("O valor %s é igual a 0!");
    }
}

if (cont > 0){
    media = parseFloat(media / cont);
}

console.log("A média dos valores informados é: %s", media);