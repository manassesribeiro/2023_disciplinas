class Livro{
    constructor(titulo, isbn, autor, editora, categoria, quantidade, preco){
        this.titulo = titulo;
        this.isbn = isbn;
        this.autor = autor;
        this.editora = editora;
        this.categoria = categoria;
        this.quantidade = quantidade;
        this.preco = preco;
    }   
    set Titulo(titulo){
        this.titulo = titulo;
    }
    get Titulo(){
        return this.titulo;
    }
    set ISBN(isbn){
        this.isbn = isbn;
    }
    get ISBN(){
        return this.isbn;
    }
    set Autor(autor){
        this.autor = autor;
    }
    get Autor(){
        return this.autor;
    }
    set Editora(editora){
        this.editora = editora;
    }
    get Editora(){
        return this.editora;
    }
    set Categoria(categoria){
        this.categoria = categoria;
    }
    get Categoria(){
        return this.categoria;
    }
    set Quantidade(quantidade){
        this.quantidade = quantidade;
    }
    get Quantidade(){
        return this.quantidade;
    }
    set Preco(preco){
        this.preco = preco;
    }
    get Preco(){
        return this.preco;
    }
}