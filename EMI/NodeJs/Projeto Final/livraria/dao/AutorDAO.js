import { Autor } from '../model/Autor.js';

//Cria classe DAO para Autor
export class AutorDAO {
    constructor(db, autor) {
        this._db = db;
        this._autor = autor;
    }

    lista() {
        return new Promise((resolve, reject) => {
            this._db.all(
                'SELECT * FROM Autor',
                (erro, resultados) => {
                    if (erro) return reject('Não foi possível listar os autores!');
                    return resolve(resultados);
                }
            )
        });
    }

    buscaPorId(id) {
        return new Promise((resolve, reject) => {
            this._db.get(
                `
                SELECT *
                FROM Autor
                WHERE id = ?
                `,
                [id],
                (erro, autor) => {
                    if (erro) {
                        return reject('Não foi possível encontrar o autor!');
                    }
                    return resolve(autor);
                }
            );
        });
    }

    adiciona(autor) {
        return new Promise((resolve, reject) => {
            this._db.run(`
                INSERT INTO Autor (
                    nome
                ) values (?)
                `,
                [
                    autor.nome
                ],
                function (err) {
                    if (err) {
                        console.log(err);
                        return reject('Não foi possível adicionar o autor!');
                    }
                    resolve();
                }
            )
        });
    }

    atualiza(autor) {
        return new Promise((resolve, reject) => {
            this._db.run(`
                UPDATE Autor SET
                nome = ?
                WHERE id = ?
                `,
                [
                    autor.nome,
                    autor.id
                ],
                erro => {
                    if (erro) {
                        return reject('Não foi possível atualizar o autor!');
                    }
                    resolve();
                });
        });
    }

    remove(id) {
        return new Promise((resolve, reject) => {
            this._db.run(
                `
                DELETE 
                FROM Autor
                WHERE id = ?
                `,
                [id],
                (erro) => {
                    if (erro) {
                        return reject('Não foi possível remover o autor!');
                    }
                    return resolve();
                }
            );
        });
    }
}