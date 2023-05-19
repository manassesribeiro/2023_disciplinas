class Pessoa{
    // Construtor
    constructor(nome, idade, profissao){
        // Atributos
        this._nome = nome;
        this._idade = idade;
        this._profissao = profissao;
    }
    // Método andar
    andar(direcao, passos){
        console.log(this._nome + " andando " + passos + " na direção " + direcao);
    }
    // Método correr
    correr(direcao, passos, velocidade){
        console.log(this._nome + " correndo: "  + passos + " na direção " +
        direcao + " na velocidade: " + velocidade);
    }
    // Método falar
    falar(mensagem){
        console.log(this._nome + " fala: " + mensagem);
    }
    // método get idade
    idade(){
        return this._idade;
    }
    // Método get profissão
    profissao(){
        return this._profissao;
    }
}

// Exemplo de instância de um objeto da classe Pessoa
const prompt = require("prompt-sync")({ sigint: true });
let nome = prompt("Informe o nome: ");
let idade = prompt("Informe a idade: ");
let profissao = prompt("Informe a profissão: ");

const pessoa1 = new Pessoa(nome, idade, profissao);

pessoa1.andar("norte", 25);
pessoa1.correr("sul", 250, "12 km/h");
pessoa1.falar("Meu nome é João, mas pode me chamar de Jhon.");

console.log("idade: " + pessoa1.idade());
console.log("profissão: %s", pessoa1.profissao());