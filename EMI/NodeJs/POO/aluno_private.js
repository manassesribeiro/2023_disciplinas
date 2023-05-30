class Aluno{
    #_nome;
    #_cpf;
    #_endereco;
    #_matricula;
    constructor(nome, cpf){
        this.#_nome = nome
        this.#_cpf = cpf
    }

    get nome(){
        return this.#_nome
    }

    get cpf(){
        return this.#_cpf
    }

    // método set
    set endereco(endereco){
        this.#_endereco = endereco
    }

    // método get
    get endereco(){
        return this.#_endereco
    }

    // método set
    set matricula(matricula){
        this.#_matricula = matricula
    }

    // método get
    get matricula(){
        return this.#_matricula
    }
}

const aluno1 = new Aluno("pedro", "222.333.444-00")
aluno1.endereco = "Rua X"
aluno1.matricula = "123123"

console.log("Nome: %s", aluno1.nome)
console.log("Matricula: %s", aluno1.matricula)
console.log("CPF: %s", aluno1.cpf)
console.log("Endereço: %s", aluno1.endereco)