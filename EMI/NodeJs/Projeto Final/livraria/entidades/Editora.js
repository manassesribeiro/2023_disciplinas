class Editora{
    constructor(nome, site){
        this.nome = nome;
        this.site = site;
    }
    
    set Nome(nome){
        this.nome = nome;
    }
    get Nome(){
        return this.nome;
    }
    set Site(site){
        this.site = site;
    }
    get Site(){
        return this.site;
    }
}