const prompt = require("prompt-sync")({ sigint: true });
let valor, media, maiorPar, menorImpar, cont;

valor = 1;
media = 0;
maiorPar = 0;
menorImpar = 9999;
cont = 0;

while(valor >= 0){
    valor = parseInt(prompt("Informe um valor: "));
    if (valor > 0){
        if (valor % 2 === 0){
            media = media + valor;
            
            if (valor > maiorPar){
                maiorPar = valor;
            }
            cont++;
        } else {
            if (valor < menorImpar){
                menorImpar = valor;
            }
        }
    }
}
media = media / cont;

console.log("A media dos pares é: " + media)
console.log("O maior par é: " + maiorPar);
console.log("O menor impar é: " + menorImpar)
