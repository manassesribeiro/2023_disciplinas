from lista_dupla.model.lista_dupla import ListaDupla

class Fila:
    def __init__(self):
        self.fila = ListaDupla()

    def insereNaFila(self, item):
        self.fila.insereElementoNaLista(self.fila.tail, item)

    def removeDaFila(self) -> None:
        return self.fila.removeElementoDaLista(self.fila.head)

    def isEmpty(self) -> bool:
        return True if self.fila.size == 0 else False
    
    def size(self) -> int:
        return self.fila.size
    
    def mostraFila(self):
        self.fila.percorreListaHeadTail()
