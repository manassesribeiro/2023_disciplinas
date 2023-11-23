export class Cliente {
    constructor(nome, documento, data_nasc, endereco){
        this._nome = nome;
        this._documento = documento;
        this._data_nasc = data_nasc;
        this._endereco = endereco;
    }

    get nome(){
        return this._nome;
    }

    set nome(nome){
        this._nome = nome;
    }

    get documento(){
        return this._documento;
    }

    set documento(documento){
        this._documento = documento;
    }

    get data_nasc(){
        return this._data_nasc;
    }

    set data_nasc(data_nasc){
        this._data_nasc = data_nasc;
    }

    get endereco(){
        return this._endereco;
    }
    
    set endereco(endereco){
        this._endereco = endereco;
    }
}
