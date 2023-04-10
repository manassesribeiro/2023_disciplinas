import sys
sys.path.append(".")

from estacionamento.model.estacionamento import Estacionamento

def main():
    estacionamento = Estacionamento(tamanhoPrincipal=10)
    for i in range(30):
        estacionamento.colocaCarro(i)

    print("Estacionamento Principal:")
    estacionamento.listaPrincipal()


    print("Fila de Espera")
    estacionamento.listaEspera()

    print("Carros retirados do estacionamento")
    for i in range(5):
        print(estacionamento.retiraCarro())

    print("Estacionamento Principal Atual")
    estacionamento.listaPrincipal()

    print("Fila de espera atual")
    estacionamento.listaEspera()

    
main()