/*
Faça um algoritmo que escreva os números ímpares
 entre 1 e 1000.
*/
const prompt = require("prompt-sync")({ sigint: true });

let cont;
cont = 1;

while(cont <= 1000){
    if (cont % 2 == 1){
        console.log("Impar: " + cont);
    }
    cont+=1; //cont = cont + 1;
}


