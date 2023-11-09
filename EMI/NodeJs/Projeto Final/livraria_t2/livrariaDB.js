//Importação da biblioteca sqlite3
import sqlite3 from 'sqlite3';

//Precisa indicar na definição da classe que é uma classe que será exportada
export class LivrariaDB{
    constructor(path){
        this._db = new sqlite3.Database(path);
        console.log("Criando tabela Autor");
        this.criaTabelaAutor();
        console.log("Criando tabela Editora");
        this.criaTabelaEditora();
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
}