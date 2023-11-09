//Abre conexao com banco de dados sqlite
const sqlite3 = require('sqlite3').verbose();
const db = new sqlite3.Database('db/data.db');

//retorna a conexao
module.exports = db;

// Path: livraria/infra/criaTabelas.js

