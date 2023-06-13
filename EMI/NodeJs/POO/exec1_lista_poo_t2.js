class Salario{
    constructor(salario, horas, mes, horasContrato, vlrSalarioMinimo, qtdeFilhosMenores, qtdePessoasFamilia){
        this._salarioBruto = salario;
        this._horasTrab = horas;
        this._mes = mes;
        this._horasContrato = horasContrato;
        this._ir = 0.0; 
        this._encargos = 0.0;
        this._vlrSalarioMinimo = vlrSalarioMinimo;
        this._qtdeFilhosMenores = qtdeFilhosMenores;
        this._qtdePessoasFamilia = qtdePessoasFamilia;
    }
    
    get vlrSalarioMinimo(){
        return this._vlrSalarioMinimo;
    }
    get qtdeFilhosMenores(){
        return this._qtdeFilhosMenores;
    }
    get qtdePessoasFamilia(){
        return this._qtdePessoasFamilia;
    }
    get salarioBruto(){
        return this._salarioBruto;
    }
    get horasTrab(){
        return this._horasTrab;
    }
    get mes(){
        return this._mes;
    }

    verificaValorIREncargos(remuneracao){
        if (remuneracao < 800){
            this._ir = 0.0;
            this._encargos = 0.00;
        } else if(remuneracao >=800 && remuneracao < 1600){
            console.log(remuneracao)
            this._ir = 8.0;
            this._encargos = 5.00;
        } else { // Faixa 3
            this._ir = 15.0;
            this._encargos = 7.00;
        }
    }

    calculaHorasExtras(){
        return (this._horasTrab - this._horasContrato);
    }

    valorHorasExtras(perHoraExtra){
        let _horasExtras = this.calculaHorasExtras();
        let _valorHora = (this._salarioBruto / this._horasContrato) * (1 + perHoraExtra / 100);
        if (_horasExtras > 0){
            return (_valorHora * _horasExtras);
        }else{
            0.0;
        }
    }

    calculaRemuneracao(percentualHorasExtras=20){
        let _horasExtras = this.valorHorasExtras(percentualHorasExtras);
        return (this._salarioBruto + _horasExtras);
    }

    calculaIRPF(remuneracao){
        this.verificaValorIREncargos(remuneracao);
        return (remuneracao * this._ir / 100);
    }

    calculaEncargos(remuneracao){
        this.verificaValorIREncargos(remuneracao);
        return (remuneracao * this._encargos / 100);
    }

    calculaSalarioLiquido(percentualHorasExtras=20, percentualSalarioFamilia=5){
        let _remuneracao = this.calculaRemuneracao(percentualHorasExtras);
        let _descIR = this.calculaIRPF(_remuneracao);
        let _descEncargos = this.calculaEncargos(_remuneracao); 
        let _salarioLiquido = _remuneracao - _descIR - _descEncargos + this.calculaSalarioFamilia(percentualSalarioFamilia);
        return _salarioLiquido;
    }

    calculaRendaPerCapita(){
        return (this._salarioBruto / this._qtdePessoasFamilia);
    }

    calculaValorSalarioFamiliaIndividual(percentualSalarioFamilia=5){
        return this._vlrSalarioMinimo * percentualSalarioFamilia / 100;
    }
    calculaSalarioFamilia(percentualSalarioFamilia=5){
        let rendaPerCapita = this.calculaRendaPerCapita();
        if (rendaPerCapita <= this._vlrSalarioMinimo){
            let salarioFamiliaIndividual = this.calculaValorSalarioFamiliaIndividual(percentualSalarioFamilia);
            return salarioFamiliaIndividual * this._qtdeFilhosMenores;
        } else {
            0.0;
        }
    }
}

// Código para instanciar a classe e invocar os métodos.
const percentualHorasExtras = 50;
const percentualSalarioFamilia = 5;
const salario = new Salario(5000, 240, "Junho/2023", 220, 1320, 2, 5);

console.log("Mês de referência: " + salario.mes);
console.log("\t(+) Salario Bruto: " + salario.salarioBruto.toFixed(2));
console.log("\t(+) Vlr Horas Extras: " + salario.valorHorasExtras(percentualHorasExtras).toFixed(2));
console.log("\t(+) Vlr Salário Família: " + salario.calculaSalarioFamilia(percentualSalarioFamilia).toFixed(2));
let remuneracao = salario.calculaRemuneracao(percentualHorasExtras);
console.log("\t(-) Encargos: " + salario.calculaEncargos(remuneracao).toFixed(2));
console.log("\t(-) IRPF: " + salario.calculaIRPF(remuneracao).toFixed(2));
console.log("\t(=) Salario Liquido " + salario.calculaSalarioLiquido(percentualHorasExtras, percentualSalarioFamilia).toFixed(2))

