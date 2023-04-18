const prompt = require("prompt-sync")({ sigint: true });
let seno, x, parcial, fat;
let cont, exp, n;

x = parseFloat(prompt('Informe o valor de x em graus: '));

//converte graus para radianos
x = x * Math.PI / 180;

seno = x;
cont = 1;
exp = 3;
while (cont <= 15){
    n = exp;

    //Inicio do calculo do fatorial
    fat = 1;
    while(n > 1){
        fat = fat * n;
        n = n - 1;
    }
    //Fim do calculo do fatorial

    parcial = Math.pow(x, exp) / fat;

    if (cont % 2 !== 0){
        seno = seno - parcial;
    } else {
        seno = seno + parcial;
    }
    exp = exp + 2;
    cont = cont + 1;
}
console.log('O valor aproximado do seno de x é: ' + seno);