class ConexaoSqLite{
    constructor(){
        this.sqlite3 = require('sqlite3').verbose();
        this.db = new this.sqlite3.Database('../db/livraria.db');
    }

    getConexao(){
        return this.db;
    }
    
    query(sql, params){
        return new Promise((resolve, reject) => {
            this.db.all(sql, params, (err, rows) => {
                if(err){
                    reject(err);
                }else{
                    resolve(rows);
                }
            });
        });
    }
    close(){
        return new Promise((resolve, reject) => {
            this.db.close((err) => {
                if(err){
                    reject(err);
                }else{
                    resolve();
                }
            });
        });
    }
}