/*
  Escrever um algoritmo que lê um valor N inteiro e positivo
  e que calcula e escreve o valor de E:   
	   E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N
*/
const prompt = require("prompt-sync")({ sigint: true });

let n = 0;
let e;
let cont;

n = parseInt(prompt("Informe um valor: "));
if (n <= 0) {
  console.log("O valor informado precisa ser maior do que zero");
} else {
  /* E = 1 + 1 / 1 + 1 / 2 + .. + 1 / N */
  e = 1.0;
  cont = 1;
  while(cont <= n){
    e = e + (1/cont);
    cont++;
  }
  console.log("O valor de 'E' é: %s", e);
}
