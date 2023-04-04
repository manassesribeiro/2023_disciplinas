const prompt = require("prompt-sync")({ sigint: true });

let sAtual, sNovo, vlrReajuste;

sAtual = parseFloat(prompt("Informe o valor do salário Atual: "));

if (sAtual <= 300.0){
    vlrReajuste = sAtual * 0.10;
} else if (sAtual > 300.0 && sAtual <= 600.0) {
    vlrReajuste = sAtual * 0.11;
} else if (sAtual > 600.0 && sAtual <= 900.0) {
    vlrReajuste = sAtual * 0.12;
} else if (sAtual > 900.0 && sAtual <= 1500.0) {
    vlrReajuste = sAtual * 0.06;
} else if (sAtual > 1500.0 && sAtual <= 2000.0) {
    vlrReajuste = sAtual * 0.03;
} else {
    vlrReajuste = 0.0;
}

sNovo = sAtual + vlrReajuste;

console.log("Salario anterior: " + sAtual);
console.log("Valor do reajuste: " + vlrReajuste);
console.log("Valor do novo salário: " + sNovo);