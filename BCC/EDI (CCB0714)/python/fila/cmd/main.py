import sys
sys.path.append(".")

from fila.model.fila import Fila

def main():
    fila = Fila()
    fila.insereNaFila(10)
    fila.insereNaFila(12)
    fila.insereNaFila(14)
    fila.insereNaFila(16)
    fila.insereNaFila(18)

    fila.mostraFila()

    try:
        _dado = fila.removeDaFila()
    except Exception as e:
        print(e)
    else:
        print("Removido o dado da posição inicial da fila: %s " % _dado)

    fila.mostraFila()
    

main()
