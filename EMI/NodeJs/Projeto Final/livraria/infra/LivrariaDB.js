import sqlite3 from 'sqlite3';
export class LivrariaDB{
    constructor(path){
        this._db = new sqlite3.Database(path);
        console.log("Criando tabela Autor");
        this.criaTabelaAutor();
        console.log("Criando tabela Categoria");
        this.criaTabelaCategoria();
        console.log("Criando tabela Editora");
        this.criaTabelaEditora();
        console.log("Criando tabela Livro");
        this.criaTabelaLivro();
        console.log("Criando tabela Usuario");
        this.criaTabelaUsuario();
        console.log("Criando tabela Compra");
        this.criaTabelaCompra();
        console.log("Criando tabela ItensCompra");
        this.criaTabelaItensCompra();
        console.log("Criando tabela Status");
        this.criaTabelaStatus();
        console.log("Tabelas criadas com sucesso!");
        // this._db.close();
        return this._db;
    }

    criaTabelaAutor(){
        //Cria tabela Autor
        const sqlCreateAutor = `
        CREATE TABLE IF NOT EXISTS Autor (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome VARCHAR(100) NOT NULL
        );
        `;
        this._db.run(sqlCreateAutor);
    }

    criaTabelaCategoria(){
        //Cria tabela Categoria
        const sqlCreateCategoria = `
        CREATE TABLE IF NOT EXISTS Categoria (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            descricao VARCHAR(100) NOT NULL
        );
        `;
        this._db.run(sqlCreateCategoria);
    }

    criaTabelaEditora(){
        //Cria tabela Editora
        const sqlCreateEditora = `
        CREATE TABLE IF NOT EXISTS Editora (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome VARCHAR(100) NOT NULL,
            site VARCHAR(100) NOT NULL
        );
        `;
        this._db.run(sqlCreateEditora);
    }

    criaTabelaLivro(){
        //Cria tabela Livro
        const sqlCreateLivro = `
        CREATE TABLE IF NOT EXISTS Livro (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            titulo VARCHAR(100) NOT NULL,
            isbn VARCHAR(100) NOT NULL,
            autor INTEGER NOT NULL,
            editora INTEGER NOT NULL,
            categoria INTEGER NOT NULL,
            quantidade INTEGER NOT NULL,
            preco REAL NOT NULL,
            FOREIGN KEY(autor) REFERENCES Autor(id),
            FOREIGN KEY(editora) REFERENCES Editora(id),
            FOREIGN KEY(categoria) REFERENCES Categoria(id)
        );
        `;
        this._db.run(sqlCreateLivro);
    }

    criaTabelaUsuario(){
        //Cria tabela Usuario
        const sqlCreateUsuario = `
        CREATE TABLE IF NOT EXISTS Usuario (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome VARCHAR(100) NOT NULL,
            email VARCHAR(100) NOT NULL,
            senha VARCHAR(100) NOT NULL
        );
        `;
        this._db.run(sqlCreateUsuario);
    }

    criaTabelaCompra(){
        //Cria tabela Compra
        const sqlCreateCompra = `
        CREATE TABLE IF NOT EXISTS Compra (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            usuario INTEGER NOT NULL,
            status INTEGER NOT NULL,
            FOREIGN KEY(usuario) REFERENCES Usuario(id)
        );
        `;
        this._db.run(sqlCreateCompra);
    }

    criaTabelaItensCompra(){
        //Cria tabela ItensCompra
        const sqlCreateItensCompra = `
        CREATE TABLE IF NOT EXISTS ItensCompra (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            compra INTEGER NOT NULL,
            livro INTEGER NOT NULL,
            quantidade INTEGER NOT NULL,
            FOREIGN KEY(compra) REFERENCES Compra(id),
            FOREIGN KEY(livro) REFERENCES Livro(id)
        );
        `;
        this._db.run(sqlCreateItensCompra);
    }

    criaTabelaStatus(){
        //Cria tabela Status
        const sqlCreateStatus = `
        CREATE TABLE IF NOT EXISTS Status (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            descricao VARCHAR(100) NOT NULL
        );
        `;
        this._db.run(sqlCreateStatus);

        // const sqlCreateStatus = `
        // CREATE TABLE IF NOT EXISTS Status (
        //     id INTEGER PRIMARY KEY AUTOINCREMENT,
        //     descricao VARCHAR(100) NOT NULL
        // );
        // `;
        // this._db.run(sqlCreateStatus);
    }
}