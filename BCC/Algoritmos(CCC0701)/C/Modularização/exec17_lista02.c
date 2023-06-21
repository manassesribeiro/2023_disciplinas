#include <stdio.h>

int calculaHorasExtras(int, int);
float calculaVlrHorasExtras(int, int, float, float);
float calculaIR(float);
float calculaEncargos(float);
float calculaSalarioLiquido(float, int, int);

int main(){
    float bruto = 1000;
    float liquido = calculaSalarioLiquido(1000, 120, 100);

    printf("Salario bruto: %.2f - Salario liquido: %.2f\n", bruto, liquido);
}

int calculaHorasExtras(int horasTrab, int horasContrato){
    return (horasTrab - horasContrato);
}

float calculaVlrHorasExtras(int horasTrab, int horasContrato, float salario, float adicional){
    float vlrHoraExtra = (salario / horasContrato) * (1 + adicional/100);
    int horasExtras = calculaHorasExtras(horasTrab, horasContrato);
    
    if (horasExtras > 0){
        return horasExtras * vlrHoraExtra;
    } else{
        return 0.0;
    }
}

float calculaIR(float remuneracao){
    if (remuneracao < 800){
        return 0.0;
    } else if (remuneracao >=800 && remuneracao < 1600){
        return (remuneracao * 0.08);
    } else{
        return (remuneracao * 0.15);
    }
}

float calculaEncargos(float remuneracao){
    if (remuneracao < 800){
        return 0.0;
    } else if (remuneracao >=800 && remuneracao < 1600){
        return (remuneracao * 0.05);
    } else{
        return (remuneracao * 0.07);
    }
}

float calculaSalarioLiquido(float salario, int horasTrab, int horasContrato){
    float remuneracao, ir, encargos, liquido;
    remuneracao = salario + calculaVlrHorasExtras(horasTrab, horasContrato, salario, 50);
    ir = calculaIR(remuneracao);
    encargos = calculaEncargos(remuneracao);
    liquido = remuneracao - ir - encargos;
}