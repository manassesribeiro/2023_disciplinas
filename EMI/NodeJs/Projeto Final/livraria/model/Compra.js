class Compra{
    constructor(status, usuario){
        this.status = status;
        this.usuario = usuario;
    }
    set Status(status){
        this.status = status;
    }
    get Status(){
        return this.status;
    }
    set Usuario(usuario){
        this.usuario = usuario;
    }
    get Usuario(){
        return this.usuario;
    }
}