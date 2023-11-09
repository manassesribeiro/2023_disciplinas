// Para importar o módulo sqlite3
import sqlite3 from 'sqlite3';

// Precisa indicar na definição da classe que é uma classe que será exportada
export class LivrariaDB{
    constructor(path){
        this._db = new sqlite3.Database(path);
        console.log("Criando tabela Autor");
        this.criaTabelaAutor();
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
}