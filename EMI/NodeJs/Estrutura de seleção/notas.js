//Para instalar o prompt-sync: npm install prompt-sync
const prompt = require("prompt-sync")({ sigint: true });

// 1º passo: declaração das variáveis
let n1, n2, n3, n4, media;

// 2º passo: entrada dos dados
n1 = parseFloat(prompt("Digite o valor da 1ª nota:"));
n2 = parseFloat(prompt("Digite o valor da 2ª nota:"));
n3 = parseFloat(prompt("Digite o valor da 3ª nota:"));
n4 = parseFloat(prompt("Digite o valor da 4ª nota:"));

// 3º passo: processamento da regra de negócio
media = (n1 + n2 + n3 + n4) / 4;

if (media >= 7.0){
    // 4º passo: saída do resultado
    console.log("Estudante 'Aprovado' com a media: " + media);
} else {
    // 4º passo: saída do resultado
    if (media >= 3.0){
        console.log("Estudante em 'Exame Final' com a media: " + media);
    } else {
        console.log("Estudante 'Reprovado por Nota' com a media: " + media);
    }   
}