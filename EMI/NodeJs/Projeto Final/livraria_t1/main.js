// Criar um projeto Node.js com o nome livraria_t1: npm init -y
// Instalar o módulo sqlite3: npm install sqlite3
// Alterar o type do projeto para module no arquivo package.json: "type": "module"

// importa a classe livrariaDB do arquivo livrariaDB.js
import { LivrariaDB } from "./livrariaDB.js";

//Cria instância do banco de dados
const db = new LivrariaDB('livraria.sqlite3');