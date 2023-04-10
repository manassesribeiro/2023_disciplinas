
class Nodo:
    def __init__(self, dado=None) -> None:
        self.dado = dado
        self.next = None

class ListaDupla:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0

    def listaVazia(self) -> bool:
        return True if self.size == 0 else False

    def criaNovoNodo(self, dado):
        return Nodo(dado)

    def insereElementoNaLista(self, pivo=Nodo(), dado=None):
        novo = Nodo(dado)
        if novo is None:
            raise TypeError; # Retorna erro caso não consiga criar o objeto do Nodo

        if pivo is None and self.listaVazia() is not True:
            return Exception("Só pode ser pivô None na primeira inserção")

        if self.listaVazia() is True:
            self.head = novo
            self.tail = novo
        else:
            novo.next = pivo.next
            novo.prev = pivo
            if pivo.next is None:
                self.tail = novo
            else:
                pivo.next.prev = novo

            pivo.next = novo
        
        self.size+=1


    def removeElementoDaLista(self, nodo=Nodo()) -> int:
        _dado = None
        if nodo is None:
            raise Exception("Nodo não pode ser None")
        
        if self.listaVazia() is True:
            raise Exception("Lista vazia - Erro de Underflow")

        if nodo == self.head:
            self.head = nodo.next
            if self.head is None:
                self.tail = None
            else:
                nodo.next.prev = None
        else:
            nodo.prev.next = nodo.next
            if nodo.next is None:
                self.tail = nodo.prev
            else:
                nodo.next.prev = nodo.prev
        _dado = nodo.dado
        nodo = None
        self.size -= 1
        return _dado

    def percorreListaHeadTail(self):
        nodo = self.head

        if self.listaVazia() is True:
            raise Exception("Lista Vazia!")
        
        while nodo is not None:
            print("%i, " % nodo.dado)
            nodo = nodo.next


    def encontraElementoNaLista(self, dado):
        _nodo = self.head

        if self.listaVazia() is True:
            raise Exception("Fila vazia")
        
        while _nodo is not None:
            print("percorrendo: %i, " % _nodo.dado)
            if _nodo.dado == dado:
                return _nodo

            _nodo = _nodo.next
        
        return None
