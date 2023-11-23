export class ClienteDAO {
    constructor(db) {
        this._db = db;
        console.log("Criando tabela Cliente");
        // verificaSeExisteTabelaCliente();
        this.criaTabelaCliente();
    }

    verificaSeExisteTabelaCliente() {
        const sqlVerificaTabelaCliente = `
        SELECT name FROM sqlite_master WHERE type='table' AND name='Cliente'
        `;
        this._db.get(sqlVerificaTabelaCliente, (err, row) => {
            if (err) {
                console.log(err);
            } else {
                if (row == undefined) {
                    console.log("Tabela Cliente não existe");
                    this.criaTabelaCliente();
                }
            }
        });
    }

    criaTabelaCliente() {
        //Cria tabela Cliente
        const sqlCreateCliente = `
        CREATE TABLE IF NOT EXISTS Cliente (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nome VARCHAR(100) NOT NULL,
            documento VARCHAR(20) NOT NULL,
            data_nasc DATE NOT NULL,
            endereco VARCHAR(100) NOT NULL
        );
        `;
        this._db.run(sqlCreateCliente);
    }

    // Insere um cliente na tabela
    insereCliente(cliente) {
        const sqlInsertCliente = `
        INSERT INTO Cliente (nome, documento, data_nasc, endereco) VALUES (?, ?, ?, ?)
        `;
        this._db.run(sqlInsertCliente, cliente.nome, cliente.documento, cliente.data_nasc, cliente.endereco);
    }

    removeCliente(id) {
        const sqlRemoveCliente = `
        DELETE FROM Cliente WHERE id = ?
        `;
        this._db.run(sqlRemoveCliente, id);
    }

    atualizaCliente(id, cliente) {
        const sqlAtualizaCliente = `
        UPDATE Cliente SET nome = ?, documento = ?, data_nasc = ?, endereco = ? WHERE id = ?
        `;
        this._db.run(sqlAtualizaCliente, cliente.nome, cliente.documento, cliente.data_nasc, cliente.endereco, id);
    }

    listaClientes() {
        const sqlListaClientes = `
        SELECT * FROM Cliente
        `;
        return new Promise((resolve, reject) => {
            this._db.all(sqlListaClientes, (err, rows) => {
                if (err) {
                    reject(err);
                } else {
                    resolve(rows);
                }
            });
        });
    }
    
    buscaClientePorId(id){
        const sqlBuscaClientePorId = `
        SELECT * FROM Cliente WHERE id = ?
        `;
        return new Promise((resolve, reject) => {
            this._db.get(sqlBuscaClientePorId, id, (err, row) => {
                if (err) {
                    reject(err);
                } else {
                    resolve(row);
                }
            });
        });
    }
}
