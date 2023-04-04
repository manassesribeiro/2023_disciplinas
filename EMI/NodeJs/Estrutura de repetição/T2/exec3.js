/*
  Fazer um programa que retorne quantos valores digitados pelo
  usuário são negativos. O programa deverá parar a execução quando
  o usuário informar o número zero ou for informado 20 valores.
*/
const prompt = require("prompt-sync")({ sigint: true });

let valor, contValoresNeg, cont;
contValoresNeg = 0;
cont = 0;
valor = 1;

while (cont < 20 && valor !== 0){
    valor = parseInt(prompt(`Informe o valor (${cont+1}): `));
    if (valor < 0){
        contValoresNeg++;//mesma coisa do que contValoresNeg = contValoresNeg+ 1;
    }
    cont = cont + 1; //mesma coisa que cont++;
}
console.log("A quantidade de valores negativos digitado é: " + contValoresNeg);
console.log("A quantidade de valores negativos digitado é: %s", contValoresNeg);
console.log(`A quantidade de valores negativos digitado é: ${contValoresNeg}`);