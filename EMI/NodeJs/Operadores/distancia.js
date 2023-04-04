const prompt = require("prompt-sync")({ sigint: true });
let x1 = prompt("Digite o valor de x1:");
let x2 = prompt("Digite o valor de x2:");
let y1 = prompt("Digite o valor de y1:");
let y2 = prompt("Digite o valor de y2:");

let a = (x2 - x1);
let b = (y2 - y1);

let d = Math.sqrt(Math.pow(a,2) + Math.pow(b,2));

console.log("A distancia eh: " + d);