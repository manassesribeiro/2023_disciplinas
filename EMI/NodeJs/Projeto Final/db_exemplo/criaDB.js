// npm install sqlite3
const sqlite3 = require('sqlite3').verbose();

//Cria a base de dados da Livraria
const db = new sqlite3.Database('livraria.db');

//Cria tabela Autor
const sqlCreateAutor = `
CREATE TABLE IF NOT EXISTS Autor (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    nome VARCHAR(100) NOT NULL
);
`;
db.run(sqlCreateAutor);


//adiciona na tabela Autor
const sqlInsertAutor = `
INSERT INTO Autor (
    nome
) values (?)
`;
const autor = ['Stephen Hawking'];
db.run(sqlInsertAutor, autor, function (erro) {
    if (erro) {
        console.log(erro);
        return;
    }
    console.log('Autor adicionado com sucesso!');
});

//consulta na tabela Autor
const sqlSelectAutor = `
SELECT * FROM Autor
`;

db.all(sqlSelectAutor, (erro, autores) => {
    if (erro) {
        console.log(erro);
        return;
    }
    console.log(autores);
});

//consulta por id na tabela Autor
const sqlSelectAutorById = `
SELECT * FROM Autor WHERE id = ?
`;
const idAutor = 1;
db.get(sqlSelectAutorById, idAutor, (erro, autor) => {
    if (erro) {
        console.log(erro);
        return;
    }
    console.log(autor);
});

//atualiza na tabela Autor
const sqlUpdateAutor = `
UPDATE Autor SET nome = ? WHERE id = ?
`;
const autorAtualizado = ['Stephen William Hawking', 1];
db.run(sqlUpdateAutor, autorAtualizado, (erro) => {
    if (erro) {
        console.log(erro);
        return;
    }
    console.log('Autor atualizado com sucesso!');
});

//remove na tabela Autor
const sqlRemoveAutor = `
DELETE FROM Autor WHERE id = ?
`;
const idAutorRemovido = 1;
db.run(sqlRemoveAutor, idAutorRemovido, (erro) => {
    if (erro) {
        console.log(erro);
        return;
    }
    console.log('Autor removido com sucesso!');
});
