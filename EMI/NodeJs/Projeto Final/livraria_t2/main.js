//Para criar o projeto digiatar no terminal: npm init -y
//Para instalar o sqlite3 digitar no terminal: npm install sqlite3

//Editar o arquivo package.json e adicionar o campo "type": "module"

// Importar a classe LivrariaDB do módulo livrariaDB.js
import {LivrariaDB} from './livrariaDB.js';

// Criar uma instância da classe LivrariaDB
const db = new LivrariaDB('data.db');