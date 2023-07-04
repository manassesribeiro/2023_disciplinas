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
    
    get modelo(){return this._modelo;}

    get chassi(){return this._chassi;}

    get cor(){return this._cor;}

    get ano(){
        return this._ano;
    }
    
    get placa(){
        return this._placa;
    }
}

class AssociaVeiculoProprietario{
    constructor(){
        this._veiculos=[];
    }
    get veiculos(){
        return this._veiculos;
    }
    novoProprietario(nome, endereco, cidade, estado){
        return new Proprietario(nome, endereco, cidade, estado);
    }
    novoVeiculo(proprietario, tipoCombustivel, modelo, chassi, cor, ano, placa){
        return new Veiculo(proprietario, tipoCombustivel, modelo, chassi, cor, ano, placa);
    }
    entradaDosDados(){
        console.log("\n\nInforme os dados do Proprietário:")
        let nome = prompt("\tInforme o nome: ");
        let endereco = prompt("\tInforme o endereço: ");
        let cidade = prompt("\tInforme a cidade: ");
        let estado = prompt("\tInforme o estado: ");        
        let proprietario = this.novoProprietario(nome, endereco, cidade, estado);

        console.log("\n\nInforme os dados do Veículo:")
        let combustivel = prompt("\tInforme o tipo de combusível (1: gasolina; 2: Alcool; 3: Diesel): ");
        let modelo = prompt("\tInforme o modelo: ");
        let chassi = prompt("\tInforme o chassi: ");
        let cor = prompt("\tInforme a cor: ");        
        let ano = prompt("\tInforme o ano: ");        
        let placa = prompt("\tInforme a placa: ");        
        let veiculo = this.novoVeiculo(proprietario, combustivel, modelo, chassi, cor, ano, placa);

        this.veiculos.push(veiculo);
    }

}
const prompt = require("prompt-sync")({ sigint: true });
const veiculos = new AssociaVeiculoProprietario();
for (let i=0; i < 3; i++){
    veiculos.entradaDosDados();
}

console.log(veiculos.veiculos)