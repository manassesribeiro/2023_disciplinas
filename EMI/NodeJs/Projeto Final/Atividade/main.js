import { Cliente } from "./entity/Cliente.js";
import { ClienteDAO } from "./dao/ClienteDAO.js";
import sqlite3 from "sqlite3";

const db = new sqlite3.Database("livraria.db");
let clienteDAO = new ClienteDAO(db);

// let newClient = new Cliente("João 2", "123456789", "1999-01-01", "Rua 1");
// clienteDAO.insereCliente(newClient);
// newClient = new Cliente("Pedro 2", "123456789", "1999-01-01", "Rua 1");
// clienteDAO.insereCliente(newClient);

let lista = await clienteDAO.listaClientes();
console.log(lista);

let cliente = await clienteDAO.buscaClientePorId(4)
let dbClient = new Cliente(cliente.nome, cliente.documento, cliente.data_nasc, cliente.endereco);
console.log(dbClient);