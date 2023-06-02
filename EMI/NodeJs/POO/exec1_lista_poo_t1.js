class Salario{
    constructor(salarioBruto, horasTrab, horasContratual, mes){
        this._salarioBruto = salarioBruto;
        this._horasTrab = horasTrab;
        this._mes = mes;
        this._horasContratual = horasContratual;
        this._percIR = 0.0;
        this._percEncargos = 0.0;
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

    //
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

    // verifica Faixa do IR e Encargos
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

    // calcula o salário líquido
    calcularSalarioLiquido(){
        // Calcula o valor das horas extras trabalhadas
        let _vlrHorasExtras = this.calcularValorHorasExtras(50);
        // calcular a remuneração = salario bruto + horas extras
        let _remuneracao = this._salarioBruto + _vlrHorasExtras;
        
        // verifica a faixa do IR e dos Encargos
        this.verificaFaixaIREncargos(_remuneracao);
        
        //calcula os descontos de IR e Encargos
        let _vlrIR = _remuneracao * (this._percIR / 100);
        let _vlrEncargos = _remuneracao * (this._percEncargos / 100);

        let _salarioLiquido = _remuneracao - _vlrIR - _vlrEncargos;
        return _salarioLiquido
    }
}

const salario = new Salario(1000, 120, 100, "mes");
console.log("Valor horas extras: " + salario.calcularValorHorasExtras(20));
console.log("Valor salário líquido: " + salario.calcularSalarioLiquido());