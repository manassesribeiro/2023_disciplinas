class Salario{
    constructor(salarioBruto, horasTrab, horasContratual, mes, salarioMinimo, qtdeFilhosMenores, qtdePessoasFamilia){
        this._salarioBruto = salarioBruto;
        this._horasTrab = horasTrab;
        this._mes = mes;
        this._horasContratual = horasContratual;
        this._percIR = 0.0;
        this._percEncargos = 0.0;
        this._salarioMinimo = salarioMinimo;
        this._qtdeFilhosMenores = qtdeFilhosMenores;
        this._qtdePessoasFamilia = qtdePessoasFamilia;
    }
    get irpf(){
        return this._percIR;
    }
    get encargos(){
        return this._percEncargos;
    }
    get salarioMinimo(){
        return this._salarioMinimo;
    }
    get qtdeFilhosMenores(){
        return this._qtdeFilhosMenores;
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
    get horasContratual(){
        return this._horasContratual;
    }
    qtdeHorasExtrasTrabalhadas(){
        return (this._horasTrab - this._horasContratual);
    }

    calcularValorHorasExtras(percHoraExtra){
        let _valorHora = (this._salarioBruto / this._horasContratual);
        _valorHora = _valorHora * (1 + percHoraExtra / 100);

        let _horasExtrasTrab = this.qtdeHorasExtrasTrabalhadas();
        if (_horasExtrasTrab > 0){
            return (_valorHora * _horasExtrasTrab);
        } else {
            0.0;
        }   
    }

    verificaFaixaIREncargos(remuneracao){
        if (remuneracao < 800.0){
            this._percIR = 0.0;
            this._percEncargos = 0.0;
        } else if (remuneracao >= 800.0 && remuneracao < 1600.0) {
            this._percIR = 8.0;
            this._percEncargos = 5.0;
        } else {
            this._percIR = 15.0;
            this._percEncargos = 7.0;
        }
    }

    calculaIRPF(percentualHorasExtras=20){
        let remuneracao = this.calculaRemuneracao(percentualHorasExtras)
        this.verificaFaixaIREncargos(remuneracao);
        return (remuneracao * (this._percIR / 100));
    }
    calculaEncargos(percentualHorasExtras=20){
        let remuneracao = this.calculaRemuneracao(percentualHorasExtras)
        this.verificaFaixaIREncargos(remuneracao);
        return remuneracao * (this._percEncargos / 100);
    }

    calculaRemuneracao(percentualHorasExtras=20){
        let _vlrHorasExtras = this.calcularValorHorasExtras(percentualHorasExtras);
        return (this._salarioBruto + _vlrHorasExtras);
    }

    calcularSalarioLiquido(percentualHorasExtras=20){
        let _remuneracao = this.calculaRemuneracao(percentualHorasExtras)

        let _vlrIR = this.calculaIRPF(percentualHorasExtras);
        let _vlrEncargos = this.calculaEncargos(percentualHorasExtras);

        let _salarioLiquido = _remuneracao - _vlrIR - _vlrEncargos + this.calculaSalarioFamilia(5);
        return _salarioLiquido
    }

    calculaRendaPerCapita(){
        return (this._salarioBruto / this._qtdePessoasFamilia);
    }

    calculaValorSalarioFamiliaIndividual(percentualSalarioFamilia){
        return this._salarioMinimo * percentualSalarioFamilia/100;
    }

    calculaSalarioFamilia(percentualSalarioFamilia){
        let rendaPerCapita = this.calculaRendaPerCapita();
        if (rendaPerCapita <= this._salarioMinimo){
            let valorSalarioFamiliaIndividual = this.calculaValorSalarioFamiliaIndividual(percentualSalarioFamilia);
            let salarioFamilia = (valorSalarioFamiliaIndividual * this._qtdeFilhosMenores);
            return salarioFamilia;
        } else {
            return 0.0;
        }
    }
}
const percentualHorasExtras = 50;
const percentualSalarioFamilia = 5;
const salario = new Salario(5000, 236, 220, "Junho/2023", 1320, 2, 4);
console.log("Mês de referencia: " + salario.mes);
console.log("\t(+) Salario bruto: " + salario.salarioBruto.toFixed(2));
console.log("\t(+) Valor horas extras: " + salario.calcularValorHorasExtras(percentualHorasExtras).toFixed(2));
console.log("\t(+) Valor salario familia: " + salario.calculaSalarioFamilia(percentualSalarioFamilia).toFixed(2));
console.log("\t(-) Encargos: " + salario.calculaEncargos(percentualHorasExtras).toFixed(2));
console.log("\t(-) IRPF: " + salario.calculaIRPF(percentualHorasExtras).toFixed(2));
console.log("\t(=) Valor salário líquido: " + salario.calcularSalarioLiquido().toFixed(2));