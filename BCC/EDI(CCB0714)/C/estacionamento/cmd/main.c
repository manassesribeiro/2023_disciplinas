#include "../model/estacionamento.c"
#define TAM_INS 30
#define TAM_REM 20
int main(){
    Lista *principal, *espera;
    principal = alocaMemoriaLista();
    espera = alocaMemoriaLista();
    int i, carroPartiu;
    for (i= 0; i < TAM_INS; i++){
        estacionar(principal, espera, i);
    }

    printf("Estacionamento principal:\n");
    mostraFila(principal);

    printf("Lista de Espera:\n");
    mostraFila(espera);

    for (i= 0; i < TAM_REM; i++){
        printf("Carro que partiu: %i\n: ", partida(principal, espera));
    }

    printf("Estacionamento principal após partidas:\n");
    mostraFila(principal);

    printf("Lista de Espera após partidas:\n");
    mostraFila(espera);

    return 0;
}