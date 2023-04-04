/*
  Escrever um algoritmo que lê um valor N inteiro e positivo
  e que calcula e escreve o valor de E:   
	   E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N
*/
const prompt = require("prompt-sync")({ sigint: true });

let n, cont, e;

cont = 1; //variavel contadora
e = 1; //variavel acumuladora
n = parseInt(prompt("Informe o valor de n: "));

while(cont <= n){
  e = e + (1 / cont);
  cont++;
}

console.log("O valor de 'e' é: %s", e);