class Proprietario{
    constructor(nome, endereco, cidade, estado){
        this._nome = nome;
        this._endereco = endereco;
        this._cidade = cidade;
        this._estado = estado;
    }
    get nome(){
        return this._nome;
    }
    get endereco(){
        return this._endereco
    }
    get cidade(){
        return this._cidade;
    }
    get estado(){
        return this._estado;
    }
}

class Veiculo {
    constructor(proprietario, combustivel, modelo, chassi, cor, ano, placa){
        this._proprietario = proprietario;
        this._combustivel = combustivel;
        this._modelo = modelo;
        this._chassi = chassi;
        this._cor = cor;
        this._ano = ano;
        this._placa = placa;
    }

    get proprietario(){
        return this._proprietario;
    }

    get combustivel(){
        if (this._combustivel == 1)
            return "Gasolina";
        else if (this._combustivel == 2)
            return "Alcool";
        else if (this._combustivel == 3)
            return "Diesel";
    }
    
    get modelo(){
        return this._modelo;
    }

    get chassi(){
        return this._chassi;
    }

    get cor(){
        return this._cor;
    }

    get ano(){
        return this._ano;
    }
    
    get placa(){
        return this._placa;
    }
}

const dono1 = new Proprietario("João da Silva", "Rua C, 128", "Videira", "SC");
const carro1 = new Veiculo(dono1, 1, "Onix", "ABC1234X124", "Vermelho", "2023", "ACB1234");

console.log("Proprietario: " + carro1.proprietario.nome);
console.log("\tEndereço: " + carro1.proprietario.endereco);
console.log("\tCidade/Estado: " + carro1.proprietario.cidade + "/" + carro1.proprietario.estado);

console.log("Dados do veículo")
console.log("\tModelo: " + carro1.modelo);
console.log("\tAno: " + carro1.ano);
console.log("\tCor: " + carro1.cor);
console.log("\tPlaca: " + carro1.placa);
console.log("\tCombustivel: " + carro1.combustivel);