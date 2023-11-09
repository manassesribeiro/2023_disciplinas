class ItensCompra{
    constructor(livro, compra, quantidade){
        this.livro = livro;
        this.compra = compra;
        this.quantidade = quantidade;
    }
    set Livro(livro){
        this.livro = livro;
    }
    get Livro(){
        return this.livro;
    }
    set Compra(compra){
        this.compra = compra;
    }
    get Compra(){
        return this.compra;
    }
    set Quantidade(quantidade){
        this.quantidade = quantidade;
    }
    get Quantidade(){
        return this.quantidade;
    }

}