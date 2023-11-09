//usar a classe infra/DB.js
// const LivrariaDB = require('../infra/LivrariaDB');


import {LivrariaDB} from '../infra/LivrariaDB.js';
import { AutorDAO } from '../dao/AutorDAO.js';
import { Autor } from '../model/Autor.js';

const db = new LivrariaDB('db/data.db');
const autorDAO = new AutorDAO(db);
// autorDAO.adiciona(new Autor('Stephen King'))
//     .then(() => console.log('Autor adicionado com sucesso!'))
//     .catch(erro => console.log(erro));

// autorDAO.adiciona(new Autor('George R. R. Martin'))
//     .then(() => console.log('Autor adicionado com sucesso!'))
//     .catch(erro => console.log(erro));

// autorDAO.lista()
//     .then(autor => console.log(autor))
//     .catch(erro => console.log(erro));

let aut;
try {
    aut = await autorDAO.buscaPorId(1);
    aut = new Autor(aut.nome);
} catch (error) {
    console.log(erro);
}
console.log(aut);


