class Salario{
    constructor(salario, horas, mes, horasContrato){
        this._salarioBruto = salario;
        this._horasTrab = horas;
        this._mes = mes;
        this._horasContrato = horasContrato;
        this._ir = 0.0; 
        this._encargos = 0.0;
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

    calculaSalarioLiquido(){
        let _horasExtras = this.valorHorasExtras(50);
        let _remuneracao = this._salarioBruto + _horasExtras;
        this.verificaValorIREncargos(_remuneracao);

        let _descIR = (_remuneracao * this._ir / 100);
        let _descEncargos = (_remuneracao * this._encargos / 100);
        let _salarioLiquido = _remuneracao - _descIR - _descEncargos;
        return _salarioLiquido;
    }
}


const salario = new Salario(1000, 120, "mes", 100)
let salLiquido = salario.calculaSalarioLiquido()

console.log("Salario Liquido " + salLiquido)

