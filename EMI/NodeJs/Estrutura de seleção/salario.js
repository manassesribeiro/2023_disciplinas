const prompt = require("prompt-sync")({ sigint: true });

let cpf;
let nFilhos;
let salario, sMinimo, qtdSalMin, desconto, imposto, sLiquido;

cpf = prompt("Informe o numero do CPF: ");
nFilhos = parseInt(prompt("Informe o numero de dependentes: "));
salario = parseFloat(prompt("Informe o valor do salário: "));
sMinimo = parseFloat(prompt("Informe o valor do salário mínimo: "));

qtdSalMin = salario / sMinimo;

if (nFilhos > 3)
    desconto = sMinimo * 0.05 * nFilhos;
else
    desconto = sMinimo * 0.15;

imposto = 0.00;
if (qtdSalMin >= 2 && qtdSalMin < 3){
    imposto = salario * 0.05;
} else if(qtdSalMin >= 3 && qtdSalMin < 5){
    imposto = salario * 0.10;
} else if (qtdSalMin >= 5 && qtdSalMin < 7){
    imposto = salario * 0.15;
} else {
    imposto = salario * 0.2;
}

sLiquido = salario - (imposto - desconto);

console.log("Calculo do imposto CPF: " + cpf);
console.log("\t  Salario Bruto: " + salario);
console.log("\t  Imposto Bruto: " + imposto);
console.log("\t       Desconto: " + desconto);
console.log("\tImposto Líquido: " + (imposto-desconto));
console.log("\t           -----------------");

console.log("\tSalário Líquido: " + sLiquido);