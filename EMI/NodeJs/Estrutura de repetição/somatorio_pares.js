/*
Faça um algoritmo que calcule o somatório de todos os
números pares entre dois números informados pelo usuário.
*/
const prompt = require("prompt-sync")({ sigint: true });

let cont1;
let cont2;
let acm;

cont1 = parseInt(prompt("Informe o primeiro valor: "));
cont2 = parseInt(prompt("Informe o segundo valor: "));
acm = 0;

//Código para inverter o valor das variáveis
if (cont2 <= cont1){
    let aux = cont1;
    cont1 = cont2;
    cont2 = aux;
}

while (cont1 <= cont2){
    if (cont1 % 2 == 0){
        acm = acm + cont1;
    }
    cont1+=1; //cont1 = cont1 + 1;
}

console.log("Somatório dos números pares: " + acm);