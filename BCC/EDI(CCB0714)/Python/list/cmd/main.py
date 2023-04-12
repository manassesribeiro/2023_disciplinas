import sys
sys.path.append(".")

from list.model.doubleLinkedList import DoubleLinkedList

def main():
    lista = DoubleLinkedList()
    lista.insertNewNodo(None, 10)
    lista.insertNewNodo(lista.head, 5)
    lista.insertNewNodo(lista.tail, 7)
    lista.insertNewNodo(None, 19)
    lista.insertNewNodo(lista.head, 22)

    lista.visitNodesFromHeadToTail()

    
    try:
        _dado = lista.removeNodo(None)
    except Exception as e:
        print(e)
    else:
        print("Removido o dado: %s " % _dado)

    lista.visitNodesFromHeadToTail()
    
    _nodo = lista.findNodoInList(10)
    try:
        _dado = lista.removeNodo(_nodo)
    except Exception as e:
        print(e)
    else:
        print("Removido o dado: %s " % _dado)


main()
