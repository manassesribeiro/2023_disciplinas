
class Nodo:
    def __init__(self, data=None) -> None:
        self.data = data
        self.next = None
        self.prev = None

class DoubleLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0

    def isEmpty(self) -> bool:
        return True if self.size == 0 else False

    def newNodo(self, data):
        return Nodo(data)

    def insertNewNodo(self, pivot=Nodo(), data=None):
        new = Nodo(data)
        if new is None:
            raise TypeError # Retorna erro caso não consiga criar o objeto do Nodo

        if pivot is None and self.isEmpty() is not True:
            return Exception("'None' pivot can be used in first insertion!")

        if self.isEmpty() is True:
            self.head = new
            self.tail = new
        else:
            new.next = pivot.next
            new.prev = pivot
            if pivot.next is None:
                self.tail = new
            else:
                pivot.next.prev = new

            pivot.next = new
        
        self.size+=1


    def removeNodo(self, nodo=Nodo()) -> int:
        _data = None
        if nodo is None:
            raise Exception("Nodo cannot be 'None'")
        
        if self.isEmpty() is True:
            raise Exception("Empty List: underflow error")

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
        _data = nodo.data
        nodo = None
        self.size -= 1
        return _data

    def visitNodesFromHeadToTail(self):
        nodo = self.head

        if self.isEmpty() is True:
            raise Exception("Empty List!")
        
        while nodo is not None:
            print("%i, " % nodo.data)
            nodo = nodo.next

    def visitNodesFromTailToHead(self):
        nodo = self.tail

        if self.isEmpty() is True:
            raise Exception("Empty List!")
        
        while nodo is not None:
            print("%i" % nodo.data)
            nodo = nodo.prev

    def findNodoInList(self, data):
        _nodo = self.head

        if self.isEmpty() is True:
            raise Exception("Empty List!")
        
        while _nodo is not None:
            print("listing: %i, " % _nodo.data)
            if _nodo.data == data:
                return _nodo

            _nodo = _nodo.next
        
        return None
