class Usuario {
  constructor(username, nome, email, senha) {
    this.username = username;
    this.nome = nome;
    this.email = email;
    this.senha = senha;
  }
  set Username(username) {
    this.username = username;
  }
  get Username() {
    return this.username;
  }
  set Nome(nome) {
    this.nome = nome;
  }
  get Nome() {
    return this.nome;
  }
  set Email(email) {
    this.email = email;
  }
  get Email() {
    return this.email;
  }
  set Senha(senha) {
    this.senha = senha;
  }
  get Senha() {
    return this.senha;
  }
}