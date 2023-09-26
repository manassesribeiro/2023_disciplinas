class Categoria{
    constructor(id, descricao){
        this.id = id;
        this.descricao = descricao;
    }
    set Id(id){
        this.id = id;
    }
    get Id(){
        return this.id;
    }
    set Descricao(descricao){
        this.descricao = descricao;
    }
    get Descricao(){
        return this.descricao;
    }
}