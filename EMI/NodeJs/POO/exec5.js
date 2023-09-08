class Linha{
    constructor(origem, destino, data, hora, minutos, distancia){
        this._origem = origem;
        this._destino = destino;
        this._data = data;
        this._hora = hora;
        this._minutos = minutos;
        this._distancia = distancia;
        this._poltronas = [];
    }
    get origem(){
        return this._origem;
    }
    set origem(origem){
        this._origem = origem;
    }
    get destino(){
        return this._destino;
    }
    set destino(destino){
        this._destino = destino;
    }
    get data(){
        return this._data;
    }
    set data(data){
        this._data = data;
    }
    get hora(){
        return this._hora;
    }
    set hora(hora){
        this._hora = hora;
    }
    get minutos(){
        return this._minutos;
    }
    set minutos(minutos){
        this._minutos = minutos;
    }
    get distancia(){
        return this._distancia;
    }
    set distancia(distancia){
        this._distancia = distancia;
    }
    get poltronas(){
        return this._poltronas;
    }
    set poltronas(poltronas){
        this._poltronas = poltronas;
    }
}

class Passagem{
    constructor(poltrona, nome, sexo){
        this._nPassagem = Math.floor(Math.random() * 1000);        
        this._nPassagem =
        this._poltrona = poltrona;
        this._nome = nome;
        this._sexo = sexo;
    }

    get nPassagem(){
        return this._nPassagem;
    }
    set nPassagem(nPassagem){
        this._nPassagem = nPassagem;
    }
    get poltrona(){
        return this._poltrona;
    }
    set poltrona(poltrona){
        this._poltrona = poltrona;
    }
    get nome(){
        return this._nome;
    }
    set nome(nome){
        this._nome = nome;
    }
    get sexo(){
        return this._sexo;
    }
    set sexo(sexo){
        this._sexo = sexo;
    }
}

class Agencia{
    constructor (){
        this._linhas = [];

    }
    cadastrarLinha(origem, destino, data, hora, distancia){
        let h = hora.split(":");
        hora = parseInt(h[0]);
        let minutos = parseInt(h[1]);
        let linha = new Linha(origem, destino, data, hora, minutos, distancia);
        this._linhas.push(linha);
    }
    cadastrarPassagem(linha, poltrona, nome, sexo){
        let passagem = new Passagem(poltrona, nome, sexo);
        this._linhas[linha].poltronas[poltrona] = passagem;
    }
    consultarLinha(linha){
        console.log("Origem: " + this._linhas[linha].origem);
        console.log("Destino: " + this._linhas[linha].destino);
        console.log("Data: " + this._linhas[linha].data);
        console.log("Distância: " + this._linhas[linha].distancia);
    }
    consultaLinhasLotadas(){
        console.log("Linhas lotadas: ");
        for (let i = 0; i < this._linhas.length; i++){
            if (this._linhas[i].poltronas.length == 44){
                console.log("Linha: " + i);
                this.consultarLinha(i);
            } else {
                console.log("Linha: " + i + " não está lotada");
            }
        }
    }
    consultarHorarioEstimadoChegada(linha){
        let tempo = this._linhas[linha].distancia / 60;
        let horas = parseInt(tempo);
        let minutos = parseInt((tempo - horas) * 60);

        console.log("Horário estimado de chegada: " + (this._linhas[linha].hora + horas) + "h" + (this._linhas[linha].minutos + minutos) + "min");
    }
    consultaPorcentagemOcupacaoLinha(linha){
        let ocupacao = (this._linhas[linha].poltronas.length / 44) * 100;
        console.log("Porcentagem de ocupação: " + ocupacao + "%");
    }
    consultaPoltronasLivresLinha(linha){
        console.log("Poltronas livres da linha: " + linha);
        const poltronaInicial = (44 - this._linhas[linha].poltronas.length);
        for (let i = poltronaInicial; i < this._linhas[linha].poltronas.length; i++){
            console.log("Poltrona: " + i);
        }
    }
    consultaPorcentagemPassageirosMasculinos(linha){
        let masculinos = 0;
        for (let i = 0; i < this._linhas[linha].poltronas.length; i++){
            if (this._linhas[linha].poltronas[i] != null){
                if (this._linhas[linha].poltronas[i].sexo == "M"){
                    masculinos++;
                }
            }
        }
        let porcentagem = (masculinos / this._linhas[linha].poltronas.length) * 100;
        console.log("Porcentagem de passageiros masculinos: " + porcentagem + "%");
    }

    consultaPorcentagemPassageirosFeminino(linha){
        let femininos = 0;
        for (let i = 0; i < this._linhas[linha].poltronas.length; i++){
            if (this._linhas[linha].poltronas[i] != null){
                if (this._linhas[linha].poltronas[i].sexo == "F"){
                    femininos++;
                }
            }
        }
        let porcentagem = (femininos / this._linhas[linha].poltronas.length) * 100;
        console.log("Porcentagem de passageiros femininos: " + porcentagem + "%");
    }
}


Agencia1 = new Agencia();
Agencia1.cadastrarLinha("São Paulo", "Rio de Janeiro", "10/10/2021", "10:00", 400);
Agencia1.cadastrarLinha("São Paulo", "Belo Horizonte", "10/10/2021", "10:00", 500);
Agencia1.cadastrarLinha("São Paulo", "Curitiba", "10/10/2021", "10:00", 300);

Agencia1.cadastrarPassagem(0, 0, "João", "M");
Agencia1.cadastrarPassagem(0, 1, "Maria", "F");
Agencia1.cadastrarPassagem(0, 2, "José", "M");
Agencia1.cadastrarPassagem(0, 3, "Ana", "F");
Agencia1.cadastrarPassagem(0, 4, "Pedro", "M");

Agencia1.cadastrarPassagem(1, 0, "João", "M");
Agencia1.cadastrarPassagem(1, 1, "Maria", "F");
Agencia1.cadastrarPassagem(1, 2, "José", "M");
Agencia1.cadastrarPassagem(1, 3, "Ana", "F");

Agencia1.cadastrarPassagem(2, 0, "João", "M");
Agencia1.cadastrarPassagem(2, 1, "Maria", "F");
Agencia1.cadastrarPassagem(2, 2, "José", "M");
Agencia1.cadastrarPassagem(2, 3, "Ana", "F");
Agencia1.cadastrarPassagem(2, 4, "Pedro", "M");
Agencia1.cadastrarPassagem(2, 5, "Joana", "F");

Agencia1.consultarLinha(0);
Agencia1.consultarLinha(1);
Agencia1.consultarLinha(2);

Agencia1.consultaLinhasLotadas();
Agencia1.consultarHorarioEstimadoChegada(0);
Agencia1.consultaPorcentagemOcupacaoLinha(0);
Agencia1.consultaPoltronasLivresLinha(0);
Agencia1.consultaPorcentagemPassageirosMasculinos(0);
Agencia1.consultaPorcentagemPassageirosFeminino(0);

Agencia1.consultaLinhasLotadas();
Agencia1.consultarHorarioEstimadoChegada(1);
Agencia1.consultarHorarioEstimadoChegada(2);

