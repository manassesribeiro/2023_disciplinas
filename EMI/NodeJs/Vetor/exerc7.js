/*
Elabore um programa que permita ler 3 notas de alunos de uma turma e os respectivos nomes, identifique qual a nota máxima e a mínima e mostre quais os respectivos nomes dos alunos que as obtiveram.
*/

const prompt = require("prompt-sync")({ sigint: true });
const TAM=2;
var nota1=[];
var nota2=[];
var nota3=[];
var nomes=[];

let min=10;
let idxMin=-1;
let max=0;
let idxMax=-1;

// procedimento para carregar o vetor N
for (let i=0; i < TAM; i++){
    nota1[i] = parseFloat(prompt("Informe a nota 1 do aluno " + i + ": "));
    nota2[i] = parseFloat(prompt("Informe a nota 2 do aluno " + i + ": "));
    nota3[i] = parseFloat(prompt("Informe a nota 3 do aluno " + i + ": "));
    nomes[i] = prompt("Informe o nome do aluno " + i + ": ");
}

//Procedimento para encontrar a menor nota nos 3 vetores
for (let i=0; i < TAM; i++){
    if (nota1[i] < min){
        min = nota1[i];
        idxMin = i;
    }
    if (nota2[i] < min){
        min = nota2[i];
        idxMin = i;
    }
    if (nota3[i] < min){
        min = nota3[i];
        idxMin = i;
    }
}

//Procedimento para encontrar a maior nota nos 3 vetores
for (let i=0; i < TAM; i++){
    if (nota1[i] > max){
        max = nota1[i];
        idxMax = i;
    }
    if (nota2[i] > max){
        max = nota2[i];
        idxMax = i;
    }
    if (nota3[i] > max){
        max = nota3[i];
        idxMax = i;
    }
}

for (let i=0; i < TAM; i++){
    console.log("Nome: " + nomes[i]);
    console.log("   Nota 1: " + nota1[i]);
    console.log("   Nota 2: " + nota2[i]);
    console.log("   Nota 3: " + nota3[i]);
    console.log("---------");
}

if (idxMin > -1){
    console.log("A menor nota é " + min + " e foi obtida pelo aluno: " + nomes[idxMin]);
}
if (idxMax > -1){
    console.log("A maior nota é " + max + " e foi obtida pelo aluno: " + nomes[idxMax]);
}